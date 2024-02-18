# origin

returns the origin of the node as text/plain when get requested

```cpp
    server.on("/node/origin", HTTP_GET, [](AsyncWebServerRequest *request) {
        // check out /docs/endpoints/node/origin.md for more information
        request->send(200, "text/plain", NODE_ORIGIN);
    });
```