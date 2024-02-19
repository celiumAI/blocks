# AP+STA mode

the ap+sta mode allows us to use the d1 mini both as a station in a parent network.

but also as an access point for its own network.

we do that by simply doing both :)

to support this functionality you just need to combine the code from the [access point](./soft_ap_config.md) and [station](./station.md)

## full example

this will result in something like this:

```
#include <ESP8266WiFi.h>

const char* ssid = "YourSSID"; // The SSID (name) of the Wi-Fi network you want to connect to
const char* password = "YourPassword"; // The password of the Wi-Fi network

const char* apSSID = "D1MiniAP"; // SSID for the Access Point
const char* apPassword = "APPassword"; // Password for the Access Point

void setup() {
  Serial.begin(115200);
  
  // Set up the D1 Mini as a station and connect to a WiFi network
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  
  // Set up the D1 Mini as an Access Point
  WiFi.softAP(apSSID, apPassword);

  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);
}

void loop() {
  // Your code here, for example, handling client connections
}

```

## constituents (for generating the firmware)

```cpp
// /docs/soft_ap_config.md
// /docs/station.md
```
