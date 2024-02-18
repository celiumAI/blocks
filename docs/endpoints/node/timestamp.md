# timestamp

the timestamp is the oldest directly associated timestampe with a node.

in the case of the firmware running blocks, its the time when the node arduino sketch was generated before compiling

returns the timestamp of the node as text/plain when get requested

```cpp
    server.on("/node/timestamp", HTTP_GET, [](AsyncWebServerRequest *request) {
        // check out /docs/endpoints/node/timestamp.md for more information
        request->send(200, "text/plain", NODE_TIMESTAMP);
    });
```