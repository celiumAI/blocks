# root node

the root node only provides a soft access point and is not a station.

the special thing about the root node is that the root endpoint is the terminating condition for any algorithm that uses parent child relations or source target relations

to quickly generate the firmware for each node i wrote a simple python script which is further explained in the [documentation](../sketch_generator.md)

to generate the root node we will use this file as the root for the script

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
  
  // /docs/soft_ap_config.md
  // /docs/station.md

  // /docs/endpoints/root.md
  // /docs/endpoints/node.md
  // /docs/endpoints/chat.md

  server.begin();
}

void loop() {
  // /docs/loop.md
}
```