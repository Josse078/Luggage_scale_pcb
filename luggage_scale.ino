#include "HX711.h"
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// Pin Definitions
#define DT_PIN   2
#define SCK_PIN  3
#define TARE_PIN 4

// OLED Setup (128x64 I2C)
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

HX711 scale;
float calibration_factor = 420.0; // Adjust for real load cell

void setup() {
  Serial.begin(115200);

  // Configure single Tare button with internal pull-up
  pinMode(TARE_PIN, INPUT_PULLUP);

  // Initialize display
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);

  // Initialize load cell
  scale.begin(DT_PIN, SCK_PIN);
  scale.set_scale(calibration_factor);
  scale.tare(); // Auto-zero on boot
}

void loop() {
  // Check Tare Button Press
  if (digitalRead(TARE_PIN) == LOW) {
    scale.tare();
    
    // Quick visual feedback on display
    display.clearDisplay();
    display.setTextSize(2);
    display.setCursor(20, 25);
    display.print("TARED!");
    display.display();
    delay(500); 
  }

  // Read Weight & Update Display
  if (scale.is_ready()) {
    float rawWeight = scale.get_units(3); // Average 3 readings
    if (rawWeight < 0) rawWeight = 0.0;   // Prevent tiny negative zero-jitter

    display.clearDisplay();
    
    // Header
    display.setTextSize(1);
    display.setCursor(0, 0);
    display.print("LUGGAGE SCALE");

    // Weight Value
    display.setTextSize(2);
    display.setCursor(0, 25);
    display.print(rawWeight, 2);

    // Unit
    display.setTextSize(2);
    display.setCursor(90, 25);
    display.print("kg");

    display.display();
  }

  delay(100);
}
