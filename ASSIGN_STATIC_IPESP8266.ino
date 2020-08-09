#include <ESP8266WiFi.h>
#include <ESP8266Ping.h>
 
const char* ssid = "dewa406";
const char* password =  "Ramesh16384";
 
IPAddress staticIP(192, 168, 0, 196);
IPAddress gateway(192, 168, 0, 1);
IPAddress subnet(255, 255, 255, 0);
IPAddress dns(192, 168, 0, 1);
    
void setup(){
  Serial.begin(9600);
 
  if (WiFi.config(staticIP, gateway, subnet, dns, dns) == false) {
    Serial.println("Configuration failed.");
  }
    
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print("Connecting...\n\n");
  }
 
  Serial.print("Local IP: ");
  Serial.println(WiFi.localIP());
  Serial.print("Subnet Mask: ");
  Serial.println(WiFi.subnetMask());
  Serial.print("Gateway IP: ");
  Serial.println(WiFi.gatewayIP());
  Serial.print("DNS 1: ");
  Serial.println(WiFi.dnsIP(0));
  Serial.print("DNS 2: ");
  Serial.println(WiFi.dnsIP(1));
   
  bool success = Ping.ping("www.google.com", 3);
  
  if(!success){
    Serial.println("\nPing failed");
    return;
  }
  
  Serial.println("\nPing successful.");
}
    
void loop(){}
