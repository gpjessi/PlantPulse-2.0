# PlantPulse-2.0
PlantPulse is a smart plant-monitoring system designed to help home growers and plant parents understand their plant’s needs in real time. Using an ESP32 microcontroller and three sensors (soil moisture, light, and temperature/humidity), the system collects environmental data and sends it to a custom web dashboard. The goal is to make plant care simple, clear, and based on real information so people can understand what their plants need.

 System Overview
PlantPulse collects environmental data from three sensors, sends it to an ESP32, and displays it on a lightweight web dashboard. Users interpret the data and take positive care actions.
Sensors → ESP32 → Web Dashboard → User → Care Action
A full system diagram is available in:
docs/System/ppsystem.png
 Features (Current)
✔ Real-time environment monitoring
Soil Moisture Sensor (V1.2)
DHT22 Temperature & Humidity Sensor
GL5516 LDR Light Sensor
✔ ESP32 firmware
Reads, processes, and formats sensor data
Sends values to dashboard
Supports future data-logging expansion
✔ Web Dashboard (HTML/CSS/JS)
Displays moisture %, temperature, humidity, and light level
Clean UI built from scratch
Ready for calibration and styling improvements
✔ Clear documentation
Agile reports
Iteration planning
System diagram
Organized, professional code structure
Repository Structure
PlantPulse-2.0/
│
├── assets/               # Images, diagrams, reference media
│   └── img/
│
├── docs/                 # Documentation for the project
│   ├── AgileReports/
│   ├── IterationPlan/
│   └── System/
│
├── src/                  # Source code for the project
│   ├── firmware/         # ESP32 / Arduino code
│   │   └── PlantPulse.ino
│   └── web/              # Dashboard HTML/CSS/JS
│
└── README.md
This structure follows best practices for collaborative and professional development.
🔧 Tech Stack
Hardware
ESP32-WROOM-32
DHT22 (Temperature & Humidity)
GL5516 LDR (Light Sensor)
Capacitive Soil Moisture Sensor v1.2
USB-to-Data Cable
Software
Arduino IDE / PlatformIO
HTML / CSS / JavaScript
Git + GitHub
Figma (for UI/UX and diagrams)
 Getting Started
1. Clone the Repository
git clone https://github.com/USERNAME/PlantPulse-2.0.git
cd PlantPulse-2.0
2. Open the Firmware
Navigate to:
src/firmware/PlantPulse.ino
Upload using Arduino IDE with the correct ESP32 board selected.
3. Open the Dashboard
Open the HTML file locally:
src/web/pp-dashboard-2.0.html
(Or your latest dashboard version.)
You'll see real-time (or simulated) sensor values in the UI.
 Project Goal
The goal of PlantPulse is to create a friendly, accessible, and affordable plant monitoring experience for everyday users — especially those living in small apartments with inconsistent light and limited growing conditions.
This project lays the foundation for:
STEM learning kits
A mobile/web app
Plug-and-play sensor kits
Affordable agritech tools for small/home growers
