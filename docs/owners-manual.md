# **PlantPulse – Owner’s Manual (v1.0)**

*A Smart Plant Monitoring System for Indoor Growers*

---

## **1\. Introduction**

Welcome to **PlantPulse**, a lightweight smart system designed to help you understand and care for your plants through real-time environmental monitoring. PlantPulse reads your plant’s **soil moisture**, **light exposure**, and **temperature/humidity** using an **ESP32 microcontroller** connected to a custom web dashboard.  
This manual will show you how to set up, operate, care for, and troubleshoot your device.

PlantPulse is designed for beginners, students, home growers, and anyone who wants a simple, gentle way to stay connected with their plants.

---

## **2\. What’s Included**

Your PlantPulse kit contains:

* **ESP32 Development Board**  
* **Capacitive Soil Moisture Sensor**  
* **GL5516 Light Dependent Resistor (LDR)**  
* **Teyleten Robot DHT22 Temperature & Humidity Sensor**  
* Jumper wires (male–female / male–male)  
* Breadboard (optional)  
* USB data cable (for power and programming)

**3\. System Overview**  
PlantPulse works by collecting data from three sensors:  
Soil Moisture Sensor- Measures the % of water in the soil  
LDR Light Sensor- Ambient light level  
DHT22- Temperature and humidity 

## **4\. Setup Instructions**

### **4.1 Before You Begin**

You will need:

* A **computer** with USB port  
* **Wi-Fi** access  
* A **plant** (recommended: basil)

---

### **4.2 Wiring Guide**

**⚠️ Important:** Double-check wiring before powering the device.

**Soil Moisture Sensor**  

* VCC → 3.3V  
* GND → GND  
* AOUT → GPIO 34

**LDR (Light Sensor)**

* One side → 3.3V  
* Other side → GPIO 35  
* 10k resistor from GPIO 35 → GND

**DHT22**

* VCC → 3.3V  
* GND → GND  
* DATA → GPIO 4

---

## **5\. Powering the Device**

You can power PlantPulse using:

* **Your computer’s USB port**  
* **A portable charger** (no code changes needed)  
* **A USB wall adapter**

---

## **6\. Using the PlantPulse Dashboard**

Once powered, PlantPulse will host a local webpage.

### **Accessing the Dashboard**

1. Open your serial monitor to find the ESP32’s **local IP address**.  
2. Type the IP address into your browser.  
3. You will see the PlantPulse dashboard with three data cards:  
   * Soil Moisture  
   * Light Level  
   * Temperature & Humidity

### **Dashboard Features**

* Real-time sensor data  
* Clean, minimal design  
* Auto-refreshing values  
* Color-coded alerts *(optional future update)*

---

## **7\. Plant Care Tips (Built-in System)**

PlantPulse gives gentle, universal guidance:

### **Soil Moisture**

* **\<30%** → Your basil likely needs water  
* **30–60%** → Healthy range  
* **\>70%** → Soil is too wet; risk of root rot

### **Light Level**

* Basil needs **6–10 hrs of light/day**  
* If light card stays low, move your plant closer to a window or add a lamp

### **Temperature**

* Ideal range: **65–85°F**  
* Avoid cold drafts or direct heat

### **Humidity**

* Ideal range: **40–60%**

---

## **8\. Maintenance & Tips**

* **Clean the moisture sensor every 2–3 weeks** to prevent soil buildup  
* Keep wires away from where you water to avoid short circuits  
* If readings look off, restart the dashboard or reset the ESP32  
* Recalibrate sensors every few months for accuracy

---

## **9\. Troubleshooting**

### **Dashboard Not Loading**

* Check the IP address  
* Reset ESP32  
* Make sure Wi-Fi credentials are correct

### **No Data on Dashboard**

* Loose wire → Recheck jumper connections  
* Sensor not powered → Verify 3.3V and GND  
* Wrong GPIO → Confirm your pins

### **Fluctuating Moisture Readings**

* Soil may be too dry or too saturated  
* Reinsert the sensor deeper  
* Wipe off soil buildup

### **LDR Reads 0 or 100 All the Time**

* Check if resistor is properly attached  
* Make sure sensor is not covered

### **DHT22 Not Responding**

* Confirm DATA pin is on GPIO 4  
* Add a slight delay in code if needed

---

## **10\. Safety Notes**

* Do not submerge the ESP32 or breadboard in water  
* Keep USB ports dry  
* Unplug PlantPulse before repotting your plant  
* Handle wires gently to avoid breaking sensor pins

