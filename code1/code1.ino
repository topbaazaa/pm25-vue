/*  NETPIE ESP8266 basic sample                            */
/*  More information visit : https://netpie.io             */
#include <Ethernet.h>
#include <ESP8266WiFi.h>
#include <MicroGear.h>


#define APPID   <APPID>
#define KEY     <APPKEY>
#define SECRET  <APPSECRET>

#define ALIAS   "Arduino_Ethernet"
#define TargetWeb  "HTML_web"
#define DHTPIN 2
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE)

int timer = 0;
MicroGear microgear(client);

/* If a new message arrives, do this */
void onMsghandler(char *topic, uint8_t* msg, unsigned int msglen) {
    Serial.print("Incoming message --> ");
    msg[msglen] = '\0';
    Serial.println((char *)msg);
}

void onFoundgear(char *attribute, uint8_t* msg, unsigned int msglen) {
    Serial.print("Found new member --> ");
    for (int i=0; i<msglen; i++)
        Serial.print((char)msg[i]);
    Serial.println();  
}

void onLostgear(char *attribute, uint8_t* msg, unsigned int msglen) {
    Serial.print("Lost member --> ");
    for (int i=0; i<msglen; i++)
        Serial.print((char)msg[i]);
    Serial.println();
}

/* When a microgear is connected, do this */
void onConnected(char *attribute, uint8_t* msg, unsigned int msglen) {
    Serial.println("Connected to NETPIE...");
    /* Set the alias of this microgear ALIAS */
    microgear.setAlias(ALIAS);
}


void setup()
{ microgear.on(MESSAGE,onMsghandler);
 microgear.on(CONNECTED,onConnected);

 dht.begin();
 Serial.begin(115200);
 Serial.println("Starting...");
 
 while(Ethernet.begin(My_MAC_address)!=1)
 {
  Serail.print("0");
 }
 Serial.print("My IP :");
 Serial.println("Ethernet.localIF")

 microgear.resetToken();
 microgear.init(KEY,SECRET,ALLAS);
 microgaer.connect(APPID);
}
void loop()
{ if(microgear.connected())
 {
  microqear.loop();
  Serial.println("connected");
  
  float Humidity = dht.readHumidity();
  float Temp = dht.readTemperature();
  String data = "/"+String(Humidity)+"/"+String(Temp);
  char mag[128];
  data.toCharArray(mag,data.length());
  Serial.println(mag);
 
  microgear.chat(TagetWeb,mag); 
 }
}
