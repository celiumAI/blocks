# async webserver

the async server is used to display the home page but also allow for the chatting functionality

## simple arduino sketch outline

```cpp
#include <ESP8266WiFi.h>
#include <ESPAsyncTCP.h>
#include <ESPAsyncWebServer.h>


const char* ap_ssid = "THIS_NODE_AP_SSID";
const char* ap_password = "THIS_NODE_AP_PASSWORD";

AsyncWebServer server(80);

//for [celium](github.com/celiumAI):
// /docs/authentication.md
// /docs/node_identity.md

void setup() {
  Serial.begin(115200);
  
  WiFi.begin(ap_ssid, ap_password);
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


  // /docs/endpoints/node.md

  server.begin();
}

void loop() {
  // /docs/loop.md
}

```