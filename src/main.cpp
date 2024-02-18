
#include <ESP8266WiFi.h>
#include <ESPAsyncTCP.h>
#include <ESPAsyncWebServer.h>


const char* ssid = "root";
const char* password = "REPLACE_WITH_YOUR_PASSWORD";

AsyncWebServer server(80);

//for [celium](github.com/celiumAI):

const char* AUTH_TOKEN="super secret root key";


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
    return "id: " + node.id + ", name: " + node.name + ", timestamp: " + node.timestamp + ", origin: " + node.origin;
}


void setup() {
  Serial.begin(115200);
  
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }

  Serial.println("Connected!");
  Serial.println(WiFi.localIP());

  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
    // check out /docs/endpoints/root.md for more information
    String response = "<html><body><p>Hi! you have reached the root. Have a great day</p></body></html>";
    Serial.println(response);
    request->send(200, "text/plain", response);
  });



    server.on("/node", HTTP_GET, [](AsyncWebServerRequest *request) {
        // check out /docs/endpoints/node/timestamp.md for more information
        String response;
        response = nodeToString(root);
        request->send(200, "text/plain", response);
    });


    server.on("/node/id", HTTP_GET, [](AsyncWebServerRequest *request) {
        // check out /docs/endpoints/node/id.md for more information
        request->send(200, "text/plain", root.id);
    });


    server.on("/node/name", HTTP_GET, [](AsyncWebServerRequest *request) {
        // check out /docs/endpoints/node/name.md for more information
        request->send(200, "text/plain", root.name);
    });


    server.on("/node/timestamp", HTTP_GET, [](AsyncWebServerRequest *request) {
        // check out /docs/endpoints/node/timestamp.md for more information
        request->send(200, "text/plain", root.timestamp);
    });


    server.on("/node/origin", HTTP_GET, [](AsyncWebServerRequest *request) {
        // check out /docs/endpoints/node/origin.md for more information
        request->send(200, "text/plain", root.origin);
    });


  server.begin();
}

void loop() {

// nothing to see here yet

}

