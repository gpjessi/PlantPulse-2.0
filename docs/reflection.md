# Lessons Learned

- This project taught me the importance of narrowing scope. PlantPulse began as a broad idea about smart agriculture, but focusing on a single basil plant and three core sensors (soil moisture, light, and temperature/humidity) allowed me to build a working and meaningful prototype.

- Integrating hardware with software revealed how sensitive physical systems are to calibration and environment. Sensor readings were not immediately reliable and required testing, adjustment, and validation over time.

- I learned that collecting data is only the first step. Designing a clear web interface to display sensor values in a readable and calm way was just as important as obtaining the data itself.

- Debugging the system required isolating components. Testing sensors individually before integrating Wi-Fi communication and the API helped identify issues more efficiently.

- Working with the ESP32 and real-time data emphasized the importance of timing, data smoothing, and update intervals to avoid noisy or misleading outputs.

- Documentation became a key part of the project. Maintaining organized code, diagrams, and written explanations made it easier to communicate the system’s structure and purpose to others.

- PlantPulse helped me understand how technology can support care and awareness rather than automation alone. This perspective shaped both the technical and design decisions throughout the project.
