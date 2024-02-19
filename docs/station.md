# station

from what i have gathered any device connected to an access point is called a station

you can let a D1 Mini behave like a station by connecting to an access point like this:

```cpp
const char* parent_ssid = "PARENT_AP_SSID";
const char* parent_password = "PARENT_AP_PASSWORD";

WiFi.begin(parent_ssid, parent_password);

while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
}

Serial.println("");
Serial.print("Connected to ");
Serial.println(parent_ssid);
Serial.print("IP address: ");
Serial.println(WiFi.localIP());
```