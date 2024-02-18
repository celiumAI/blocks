# name

returns the name of the node as text/plain when get requested

```cpp
    server.on("/node/name", HTTP_GET, [](AsyncWebServerRequest *request) {
        // check out /docs/endpoints/node/name.md for more information
        request->send(200, "text/plain", NODE_NAME);
    });
```