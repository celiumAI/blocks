# heartbeat

each [node](./node_identity.md) has a heartbeat

## post

the heartbeat runs every PULSE_INTERVAL seconds

it performs a text/plain post request to a NODE_PARENT_IP

it will transmit the information in the following schema:

`id: NODE_ID`

thats it

## implementation

then keep track of the time from the last loop

if the difference in time is greater than the specified interval

then make the call again

reset the timer and so on

```cpp
const int PULSE_INTERVAL = 1;
unsigned long previousMillis = 0;
unsigned long currentMillis = 0;

void sendHeartbeat() {
    if (PULSE_INTERVAL = 0) {
        return;
    }

    currentMillis = millis();
    if (currentMillis - previousMillis >= PULSE_INTERVAL) {
        previousMillis = currentMillis;

        if (WiFi.status() == WL_CONNECTED) {
        HTTPClient http;

        http.begin(NODE_PARENT_IP);
        http.addHeader("Content-Type", "text/plain");

        int httpCode = http.POST(String("id: ") + NODE_ID);
        String payload = http.getString();

        Serial.println(httpCode);
        Serial.println(payload);

        http.end();
        }
    }
}
```