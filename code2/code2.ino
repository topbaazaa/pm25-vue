#include <DHT.h>
#include <ESP8266WiFi.h>
#include <MicroGear.h>
const char* ssid = "HUAWEIY92018";
const char* password = "topbaazaa";
#define APPID "SPM25"
#define KEY "DL8YICnosKX8eUG"
#define SECRET "aMagtkaKEh00WFRWdEEJ5bayn"
#define ALIAS "piedht"
#define FEEDID "sensorDHT22PM"
#define INTERVAL 15000 
#define T_INCREMENT 200 
#define T_RECONNECT 5000 
#define BAUD_RATE 115200 
#define MAX_TEMP 100 
#define MAX_HUMID 100
WiFiClient client;
int timer = 0;
char str[32];
#define DHTTYPE DHT22 // Define sensor type 
#define DHTPIN 2 // Define sensor pin 
DHT dht(DHTPIN, DHTTYPE, 15); //Initialize DHT sensor
int humid;
int temp;
MicroGear microgear(client);
void onMsghandler(char *topic, uint8_t* msg, unsigned int msglen) {
  Serial.print("Incoming message -- >"); msg[msglen] = '\0';
  Serial.println((char *)msg);
}
void onConnected(char *attribute, uint8_t* msg, unsigned int msglen) {
  Serial.println("Connected to NETPIE...");
  microgear.setAlias(ALIAS);
}
void setup() {
  dht.begin();
microgear.on(MESSAGE, onMsghandler);
  microgear.on(CONNECTED, onConnected);
Serial.begin(115200);
  Serial.println("Starting...");
if (WiFi.begin(ssid, password)) {
    while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      Serial.print(".");
    }
  }
Serial.println("WiFi connected");
Serial.println("IP address: ");
Serial.println(WiFi.localIP());
microgear.init(KEY, SECRET, ALIAS);
microgear.connect(APPID);
}
void loop() {
    humid = dht.readHumidity();
    temp = dht.readTemperature();
  
  if (microgear.connected()) {
    Serial.println("connected");
    microgear.loop();
    
    if (timer >= 1000) {
      sprintf(str, "%d,%d", humid, temp);
      Serial.println(str);
Serial.print("Sending -- >");
      microgear.publish("/dht", str);
      String H = "{\"humid\":";
      //microgear.writeFeed("DHT22TestingFeed","H");
String data = "{\"Humid\":"; 
      data += humid ; 
      data += ", \"Temp\":"; 
      data += temp ; 
      data += "}";  
      microgear.writeFeed(FEEDID,data);
      
      timer = 0;
    }
    else timer +=
        100;
  } else {
    Serial.println("connection lost, reconnect...");
    if (timer >= 5000) {
      microgear.connect(APPID);
      timer = 0;
    }
    else timer += 100;
  }
  delay(100);
}
