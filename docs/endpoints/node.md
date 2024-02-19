# node

the /node endpoints returns basic information on the node itself as a json string

this information is actually hardcoded on the d1 mini

this includes the node_id, the node_name and the node_timestamp

```cpp
    server.on("/node", HTTP_GET, [](AsyncWebServerRequest *request) {
        // check out /docs/endpoints/node/timestamp.md for more information
        String response;
        response = nodeToString(root);
        request->send(200, "text/plain", response);
    });
```