# **ESP32 GSM to MQTT Publisher**  

This project connects a **GSM module** to an **MQTT server** using **TinyGSM** and **PubSubClient** libraries. It enables devices to publish messages to an MQTT broker over a **GPRS** network.  

---

## **📌 Features**
✅ Connects to the internet via a **GSM module (SIM800/SIM900)**  
✅ Establishes a connection with an **MQTT broker**  
✅ Publishes messages to an **MQTT topic**  
✅ Automatically **reconnects** if the connection is lost  
✅ Lightweight and optimized for **low-power devices**  

---

## **🔧 Hardware Requirements**
- **GSM Module** (SIM800, SIM900, or similar)  
- **Microcontroller** (ESP8266, ESP32, Arduino, etc.)  
- **SIM Card** (with an active data plan)  
- **Jumper Wires**  

---

## **📜 Libraries Used**
Ensure you have the following libraries installed in the **Arduino IDE**:  
1️⃣ [TinyGSM](https://github.com/vshymanskyy/TinyGSM)  
2️⃣ [PubSubClient](https://github.com/knolleary/pubsubclient)  

To install them, go to **Arduino IDE → Library Manager** and search for the libraries.  

---

## **📌 Pin Configuration**
| **GSM Module (SIM800L)** | **Microcontroller (ESP8266/Arduino)** |
|-------------------------|---------------------------------|
| VCC | 5V / 3.3V |
| GND | GND |
| TX | **D2 (GPIO 4)** |
| RX | **D1 (GPIO 5)** |

⚠️ **Note**: Some GSM modules require a **separate power source (5V/2A)**.  

---

## **⚙️ Setup Instructions**
1️⃣ **Connect** the GSM module to your microcontroller as per the pin configuration.  
2️⃣ **Install** the required libraries.  
3️⃣ **Update the code** with your:  
   - **MQTT Broker** address  
   - **APN Settings** (for mobile network access)  
4️⃣ **Upload the code** to your microcontroller.  
5️⃣ Open the **Serial Monitor** (Baud Rate: **115200**).  
6️⃣ Wait for the modem to connect and check if the message is successfully published.  

---

## **💻 Code Overview**
- The program initializes a **GSM modem**.  
- It connects to a **GPRS network**.  
- It establishes a **connection with an MQTT broker**.  
- It publishes a **test message ("Hello from GSM!")** every 5 seconds.  
- If disconnected, it **automatically retries**.  

---

## **📡 Configuration**
Modify the following in the code before uploading:  

```cpp
const char* mqttServer = "your_mqtt_server";  // Replace with your MQTT broker
const int mqttPort = 1883;                    // MQTT port (default: 1883)
const char* mqttUser = "your_mqtt_user";      // MQTT username
const char* mqttPassword = "your_mqtt_pass";  // MQTT password
const char* topic1 = "test/topic";            // MQTT topic
```

For **GPRS connection**, set the **APN details** based on your mobile network:  

```cpp
const char apn[]  = "your_apn";  // Mobile network APN
const char user[] = "";          // APN username (if required)
const char pass[] = "";          // APN password (if required)
```

---

## **📊 Expected Serial Monitor Output**
```plaintext
Initializing modem...
Connecting to GPRS...
✅ GPRS connected
🔄 Connecting to MQTT...
✅ Connected to MQTT
📡 Published: "Hello from GSM!"
📡 Published: "Hello from GSM!"
...
```

---

## **📌 Troubleshooting**
| **Issue** | **Possible Solution** |
|-----------|----------------------|
| **GSM module not responding** | Check power supply (Some modules need **5V 2A**). |
| **Cannot connect to GPRS** | Verify **SIM card is active** and **APN settings** are correct. |
| **MQTT connection failed** | Check **MQTT broker address, port, username, and password**. |
| **No messages received on MQTT** | Ensure the **topic is correctly subscribed** on the broker. |

---

## **📢 Credits**
👨‍💻 **Author**: Yodha Ardiansyah  
🔗 **GitHub**: [github.com/Yodhaardiansyah](https://github.com/Yodhaardiansyah)  
📅 **Version**: 1.0  
📖 **License**: MIT  

---
