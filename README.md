# 💧 Smart Water Level Monitoring System using ESP8266, OLED & Blynk

This project is a **Smart Water Level Monitoring System** that uses an **ESP8266 (NodeMCU)** microcontroller, an **Ultrasonic Sensor**, **OLED Display**, **Buzzer**, and **Blynk IoT platform** to display and alert the user about the current water level percentage in a tank.

## 📦 Features

- Real-time water level measurement using an Ultrasonic sensor.
- OLED display to show water level percentage.
- Remote monitoring via **Blynk** app (virtual pins used: V0 for percentage, V3 for raw distance).
- Buzzer alert when water level is **too low (<10%)** or **too high (>80%)**.
- LED indication for low water level.

---

## 🧰 Components Used

| Component            | Quantity |
|----------------------|----------|
| NodeMCU ESP8266      | 1        |
| Ultrasonic Sensor (HC-SR04) | 1 |
| OLED Display (SSD1306)      | 1 |
| Buzzer               | 1        |
| LED                  | 1        |
| Resistors            | 1 (for LED) |
| Breadboard & Wires   | as needed |

---

## 📲 Blynk Configuration

- **Template ID:** `TMPL3v39NOrJl`
- **Template Name:** `distance tester`
- **Auth Token:** (Insert your Blynk auth token here)
- **Virtual Pins:**
  - `V0`: Water Level Percentage
  - `V2`: Manual override of percentage (optional)
  - `V3`: Raw distance in cm

---

## ⚙️ Circuit Pin Mapping

| ESP8266 Pin | Connected To      |
|-------------|-------------------|
| D6          | Ultrasonic Trig   |
| D7          | Ultrasonic Echo   |
| D5 (GPIO 14)| Buzzer            |
| D8 (GPIO 15)| LED               |
| I2C (D1, D2)| OLED Display (SCL, SDA) |

---

## 📏 Working Principle

- The **Ultrasonic Sensor** measures the distance from the sensor to the water surface.
- The system calculates the level of water by subtracting the distance from the tank’s total depth (`15.5 cm` in code).
- The level is converted to a percentage and displayed on:
  - OLED Screen
  - Blynk App
- A **buzzer** is activated when the level is **too low** or **too high**, and the **LED** glows if the water level is **below 10%**.

---

## 🔧 Setup Instructions

1. Connect the hardware as per the circuit diagram and pin mapping.
2. Install the required libraries in Arduino IDE:
   - Blynk
   - ESP8266WiFi
   - Adafruit GFX
   - Adafruit SSD1306
   - NewPing
3. Replace the following in the code:
   - `BLYNK_AUTH_TOKEN` with your own
   - `ssid` and `pass` with your Wi-Fi credentials
4. Upload the code to your NodeMCU ESP8266.
5. Monitor values on Serial Monitor and Blynk dashboard.

---

## 📷 Output

- 📱 Monitor the percentage live on your Blynk app.
- 📟 OLED screen displays the level percentage.
- 🔊 Buzzer alerts on unsafe levels.
- 💡 LED indicator when water is too low.

## 🛠 Author

**Vijaya Kumar G**  
📧 [LinkedIn](https://www.linkedin.com/in/vijay013/) 