# Portable Digital Luggage Scale PCB

Custom 2-layer printed circuit board (PCB) design for a portable digital luggage scale, created using **KiCad**.

## 📌 Overview
This project integrates an Arduino microcontroller, load cell amplifier module, OLED display, and a LiPo power management circuit into a compact custom PCB layout.

---

## 🛠️ Hardware & Components
* **MCU:** Arduino Nano / Nano Every
* **Weight Sensor Interface:** HX711 Load Cell Amplifier
* **Display:** 0.96" I2C OLED Display (128x64)
* **Power Management:** 3.7V LiPo Battery, TP4056 Charger + 5V Boost Converter Module
* **Controls:** 
  * SPDT Slide Switch (Main Power On/Off)
  * Tactile Pushbutton (Tare / Zero Scale)

---

## 📐 PCB Layout & Design Highlights
* **Modular Interconnects:** Utilizes 4-pin headers/connectors for off-board modules (Display, HX711, Power) to simplify assembly and maintenance.
  
---

## 📁 Files & Repository Structure
* `Luggage_Scale.kicad_sch` – Schematic source file
* `Luggage_Scale.kicad_pcb` – PCB layout source file
* `*.gbr` – Output Gerber layers (`F.Cu`, `B.Cu`, `F.Silkscreen`, `B.Silkscreen`, `F.Mask`, `B.Mask`, `Edge.Cuts`)
* `*.drl` – Excellon drill files (`PTH` and `NPTH`)
* `Luggage_Scale-job.gbrjob` – Gerber job file

---

## 🚀 Manufacturing
Gerber and drill files are generated and ready for direct upload to PCB fabrication services (JLCPCB, PCBWay, etc.).
