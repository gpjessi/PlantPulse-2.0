// ==============================
// PlantPulse API 
// - Serves /api/sensordata (JSON)
// - Temperature in °F (set readTemperature(false) for °C)
// In colaboration with Chatgpt
// ==============================

#include "DHT.h"
#include <WiFi.h>
#include <WebServer.h>

const char* ssid     = "WiFi";
const char* password = "password";

#define DHTPIN   15
#define DHTTYPE  DHT22
#define LDR_PIN  34
#define SOIL_PIN 33

// --- Fixed calibration constants  ---
int soilDryValue   = 2600;   // DRY  (soilMax)
int soilWetValue   = 900;   // WET  (soilMin)
int ldrDarkValue   = 0;     // DARK (ldrMin)
int ldrBrightValue = 3797;  // BRIGHT (ldrMax)

DHT dht(DHTPIN, DHTTYPE);
WebServer server(80);

void handleAPIData() {
  // Raw sensor reads
  int soilRaw = analogRead(SOIL_PIN);
  int ldrRaw  = analogRead(LDR_PIN);

  // Read DHT (°F)
  float temperature = dht.readTemperature(true);
  float humidity    = dht.readHumidity();

  // If DHT bad, return an error (same behavior as before)
  if (isnan(temperature) || isnan(humidity)) {
    server.sendHeader("Access-Control-Allow-Origin", "*");
    server.sendHeader("Access-Control-Allow-Methods", "GET, OPTIONS");
    server.sendHeader("Access-Control-Allow-Headers", "Content-Type");
    server.send(500, "application/json", "{\"error\":\"DHT sensor failed\"}");
    return;
  }

  // Map to 0–100% (wet => high %, dark => low %)
  int soilMoisture = constrain(map(soilRaw, soilWetValue, soilDryValue, 100, 0), 0, 100);
  int lightLevel   = constrain(map(ldrRaw,  ldrDarkValue, ldrBrightValue, 0, 100), 0, 100);

  // Build JSON
  String json = "{";
  json += "\"soil_moisture\":" + String(soilMoisture) + ",";
  json += "\"light_level\":"   + String(lightLevel)   + ",";
  json += "\"temperature\":"   + String(temperature,1)+ ",";
  json += "\"humidity\":"      + String(humidity,1)   + ",";
  json += "\"raw_values\":{";
  json +=   "\"soil_raw\":" + String(soilRaw) + ",";
  json +=   "\"ldr_raw\":"  + String(ldrRaw);
  json += "}}";

  // CORS + response
  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.sendHeader("Access-Control-Allow-Methods", "GET, OPTIONS");
  server.sendHeader("Access-Control-Allow-Headers", "Content-Type");
  server.send(200, "application/json", json);

  // Debug
  Serial.println("API Request - Calibrated Data:");
  Serial.println(json);
}

void setup() {
  Serial.begin(115200);
  dht.begin();

  // ADC setup
  analogReadResolution(12);       // 0–4095
  analogSetAttenuation(ADC_11db); // ~0–3.6 V

  // Wi-Fi
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) { delay(500); Serial.print("."); }
  Serial.println("\nWiFi connected!");
  Serial.print("IP address: "); Serial.println(WiFi.localIP());

  // API route
  server.on("/api/sensordata", handleAPIData);

  // 404
  server.onNotFound([]() { server.send(404, "text/plain", "Not found"); });

  server.begin();

  // Handy URL
  Serial.print("Server started: http://");
  Serial.print(WiFi.localIP());
  Serial.println("/api/sensordata");
}

void loop() {
  server.handleClient();
}

