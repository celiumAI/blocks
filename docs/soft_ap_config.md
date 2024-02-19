# soft access point

for our purposes you can imagine the access point like a very minimal wifi router.

in our case we will use this functionality in the context of [AP+STA Mode](./ap_plus_sta.md) to build subnets.

## implementation

the d1 mini supports creating a soft ap

this is useful because if all else fails

as long as the d1 mini has power

we can connect to it via its own access point

```cpp
    const char* ap_ssid = "THIS_NODE_AP_SSID";
    const char* ap_password = "THIS_NODE_AP_PASSWORD";

    WiFi.softAP(ap_ssid, ap_password);
    IPAddress myIP = WiFi.softAPIP();
    Serial.print("AP IP address: ");
    Serial.println(myIP);
```