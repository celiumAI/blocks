# id

returns the id of the node as text/plain when get requested

```cpp
    server.on("/node/id", HTTP_GET, [](AsyncWebServerRequest *request) {
        // check out /docs/endpoints/node/id.md for more information
        request->send(200, "text/plain", NODE_ID);
    });
```