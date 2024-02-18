# node

the /node endpoints returns basic information on the node itself

this information is actually hardcoded on the d1 mini

this includes the node_id, the node_name and the node_timestamp

for the root node the string can be constructed like the following:

```cpp
    server.on("/node/timestamp", HTTP_GET, [](AsyncWebServerRequest *request) {
        // check out /docs/endpoints/node/timestamp.md for more information
        String response = "id: " + NODE_ID + ", name: " + NODE_NAME + ", timestamp: " + NODE_TIMESTAMP;
        request->send(200, "text/plain", response);
    });
```