#include <FS.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
 
const char* ssid = "A&MLuans";
const char* password = "a&mluans000408";
 
String webPage = "";
 
ESP8266WebServer server(80);
 
void handleRoot() {
  server.send(200, "text/html", webPage);
}
 
void readFile(void) {
  //Faz a leitura do arquivo HTML
  File rFile = SPIFFS.open("/outro.html","r");
  Serial.println("Lendo arquivo HTML...");
  webPage = rFile.readString();
//  while(rFile.available()) {
//    String line = rFile.readStringUntil('\n');
//    webPage += line;
//  }
  Serial.println(webPage);
  rFile.close();  
}
 
void setup() {
  Serial.begin(9600);
  SPIFFS.begin();
 
  if(SPIFFS.exists("/outro.html"))
  {
    Serial.println("\n\nfile exists!");
  }
  else Serial.println("\n\nNo File :(");
 
  readFile();
 
  WiFi.begin(ssid, password);
  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
 
  server.on("/", handleRoot);
   
  server.begin();
}
 
void loop() {
  server.handleClient();
}

/********************************************************
 * CANAL INTERNET E COISAS
 * ESP8266 - Utilizacao do SPIFFS
 * 03/2018 - Andre Michelon
 

// Bibliotecas
#include <FS.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

const char* ssid = "A&MLuans";
const char* password = "a&mluans000408";

String webPage = "";

ESP8266WebServer server(80);

void handleRoot(){
  server.send(200, "text/html", webPage);    
}

void readFile(void){
  //Faz a leitura do html
  File rFile = SPIFFS.open("/outro.html", "r");
  Serial.println("Lendo arquivo HTML...");
  webPage = rFile.readString();    
  Serial.println(webPage);
  rFile.close();
}

void setup(){
  Serial.begin(115200);

  // --- Inicializando SPIFSS ---
  Serial.println("\nInicializando SPIFSS ---------------------");
  if (SPIFFS.begin()) {
    Serial.println("Ok");
  } else {
    Serial.println("Falha");
    while(true);
  }

  if(SPIFFS.exists("/outro.html")){
    Serial.println("\n\nArquivo existente!");   

  }else{
     Serial.println("\n\nArquivo não existente!");    
  }    
  
  readFile();

  WiFi.begin(ssid, password);

  while(WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("Conectado a: ");
  Serial.print(ssid);
  Serial.println("Endereço Ip: ");
  Serial.print(WiFi.localIP());
  
  server.on("/", handleRoot);
  server.begin();
  
}

void loop() {
  server.handleClient();
}

*/

