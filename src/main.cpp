#include <WebServer.h>
#include "FS.h"
#include <WiFi.h>
#include "css.h"
//ver o estado do led atual e atualizar a pagina
const char* ssid     = "******";
const char* password = "********";
bool ledStatus = false;
bool ledStatus2 = false;
int led1 = 2;
int led2 = 15;

WebServer server(80);

void handleToggleLED();
void handleRoot() {
    server.send(200, "text/html", pag1); 
}




void setup()
{
    Serial.begin(115200);
    pinMode(led1, OUTPUT);       //set the LED pin mode
    pinMode(led2, OUTPUT);
    delay(10);

     //We start by connecting to a WiFi network

    Serial.println();
    Serial.println();
    Serial.print("Connecting to ");
    Serial.println(ssid);

    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }

    Serial.println("");
    Serial.println("WiFi connected.");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
    
    server.on("/", handleRoot);
    server.on("/toggle-led", handleToggleLED);
    server.begin();
    
}

void handleToggleLED() {
    Serial.println("Recebeu uma solicitação para ligar/desligar o LED");
    if (server.arg("id") == "1") {
        ledStatus = !ledStatus;
        digitalWrite(led1, ledStatus);
        server.send(200, "text/plain", "LED 1 state: " + String(ledStatus));
    } else if (server.arg("id") == "2") {
        ledStatus2 = !ledStatus2;
        digitalWrite(led2, ledStatus2);
        server.send(200, "text/plain", "LED 2 state: " + String(ledStatus2));
    } else {
        server.send(400, "text/plain", "Invalid LED ID");
    }
}

void loop(){
    server.handleClient();
}
