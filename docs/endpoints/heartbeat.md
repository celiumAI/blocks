# heartbeat

the /heartbeat get endpoint returns the list of active network child nodes

```cpp
    server.on("/heartbeat", HTTP_GET, [](AsyncWebServerRequest *request) {
        // check out /docs/endpoints/node/timestamp.md for more information
        String response = ""
        for (int i = 0; i < 4; i++){
            response += "id : " + child_nodes[i].id + ", ";
            response += "name : " + child_nodes[i].name+ ", ";
            response += "timestamp : " + child_nodes[i].timestamp + ", ";

            response += "origin : " + child_nodes[i].origin;

        }
        request->send(200, "text/plain", response);
    });
```