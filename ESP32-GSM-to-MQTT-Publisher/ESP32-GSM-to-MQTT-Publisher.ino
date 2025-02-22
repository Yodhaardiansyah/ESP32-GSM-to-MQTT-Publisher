/*
 * GSM to MQTT Publisher
 * 
 * This program connects a GSM module to an MQTT server, publishes messages, 
 * and ensures stable connectivity.
 * 
 * Author: Yodha Ardiansyah
 * GitHub: https://github.com/Yodhaardiansyah
 */

// Define GSM modem model
#define TINY_GSM_MODEM_SIM800  // Change this if using a different modem

// Include necessary libraries
#include <TinyGsmClient.h>
#include <PubSubClient.h>
#include <SoftwareSerial.h>

// Define serial communication pins
SoftwareSerial SerialAT(5, 4); // RX, TX for SoftwareSerial

// Debug console setup
#define SerialMon Serial

// MQTT Server Credentials (Sensitive data hidden)
const char* mqttServer = "your_mqtt_server";  // Replace with your MQTT server
const int mqttPort = 1883;                    // Default MQTT port
const char* mqttUser = "your_mqtt_user";      // Your MQTT username
const char* mqttPassword = "your_mqtt_pass";  // Your MQTT password
const char* topic1 = "test/topic";            // Topic to publish messages

// APN Settings (Modify based on your network provider)
const char apn[]  = "your_apn";  // APN for your mobile network
const char user[] = "";          // No username required for most networks
const char pass[] = "";          // No password required for most networks

// Initialize modem and client
TinyGsm modem(SerialAT);
TinyGsmClient client(modem);
PubSubClient mqtt(client);

void setup() {
  SerialMon.begin(115200);  // Start serial monitor
  SerialAT.begin(9600);     // Start serial communication with GSM module

  delay(3000);              // Wait for GSM module to initialize
  SerialMon.println("Initializing modem...");
  modem.restart();          // Restart the modem

  // Connect to GPRS network
  SerialMon.println("Connecting to GPRS...");
  if (!modem.gprsConnect(apn, user, pass)) {
    SerialMon.println("❌ GPRS connection failed");
    while (true) {}  // Stay here if connection fails
  }
  SerialMon.println("✅ GPRS connected");

  // Setup MQTT client
  mqtt.setServer(mqttServer, mqttPort);
}

void loop() {
  if (!mqtt.connected()) {
    SerialMon.println("🔄 Connecting to MQTT...");
    if (mqtt.connect("GSMClient", mqttUser, mqttPassword)) {
      SerialMon.println("✅ Connected to MQTT");
      mqtt.publish(topic1, "Hello from GSM!");  // Publish a test message
    } else {
      SerialMon.print("⚠️ Failed to connect to MQTT. Error code: ");
      SerialMon.println(mqtt.state());
      delay(5000);  // Retry after 5 seconds
      return;
    }
  } else {
    mqtt.publish(topic1, "Hello from GSM!");  // Publish a test message
    delay(5000);  // Retry after 5 seconds
  }

  mqtt.loop();  // Maintain MQTT connection
}
