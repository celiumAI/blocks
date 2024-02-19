
#include <ESP8266WiFi.h>
#include <ESPAsyncTCP.h>
#include <ESPAsyncWebServer.h>

AsyncWebServer server(80);

//for [celium](github.com/celiumAI):
// disabled /docs/authentication.md

struct Node {
  String id;
  String name;
  String timestamp;
  String origin;
};

Node root = {
    "rootroot-1ba0-4d33-8f9f-b93563cc936f",
    "root",
    "1708290687000",
    "m-c-frank/celium-experiments",
};

String nodeToString(Node node){
    String json = "{";
    json += "\"id\": \"" + node.id + "\", ";
    json += "\"name\": \"" + node.name + "\", ";
    json += "\"timestamp\": \"" + node.timestamp + "\", ";
    json += "\"origin\": \"" + node.origin + "\"";
    json += "}";
    return json;
}


void setup() {
  Serial.begin(9600);
  

    const char* ap_ssid = "root";
    const char* ap_password = "thereisnospoon";

    WiFi.softAP(ap_ssid, ap_password);
    IPAddress myIP = WiFi.softAPIP();
    Serial.print("AP IP address: ");
    Serial.println(myIP);



  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
    // check out /docs/endpoints/root.md for more information
    String response = "<html><body><p>Hi! you have reached the root. Have a great day</p></body></html>";
    Serial.println(response);
    request->send(200, "text/html", response);
  });


    server.on("/node", HTTP_GET, [](AsyncWebServerRequest *request) {
        // check out /docs/endpoints/node/timestamp.md for more information
        String response;
        response = nodeToString(root);
        request->send(200, "text/plain", response);
    });


  server.begin();
}

void loop() {

// nothing to see here yet

}
