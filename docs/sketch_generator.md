# sketch generator

to quickly generate the firmware for each node i wrote a simple python script

to generate the root node check out the [root node generator](./root_node.md)

the python script does nothing except look through all the documentation

and scrape it recursively for any `cpp` code block

this markdown document represents the root node for this script.

i.e. the path to this file is hardcoded in the script

and each occurence below will be replaced with the corresponding code block from the documentation:

```cpp
#include <ESP8266WiFi.h>
#include <ESPAsyncTCP.h>
#include <ESPAsyncWebServer.h>

AsyncWebServer server(80);

//for [celium](github.com/celiumAI):
// disabled /docs/authentication.md
// /docs/node_identity.md

void setup() {
  Serial.begin(9600);
  
  // /docs/ap_plus_sta.md

  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
    // check out /docs/endpoints/root.md for more information
    String response = "<html><body><p>Hi! you have reached the root. Have a great day</p></body></html>";
    Serial.println(response);
    request->send(200, "text/plain", response);
  });


  // /docs/endpoints/node.md
  // /docs/endpoints/node/id.md
  // /docs/endpoints/node/name.md
  // /docs/endpoints/node/timestamp.md
  // /docs/endpoints/node/origin.md

  server.begin();
}

void loop() {
  // /docs/loop.md
}
```