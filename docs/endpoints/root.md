# root

the root endpoint is reserved for the landing page

## landing page

this will eventually be the user interface

it will host a static html page

```cpp
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
    // check out /docs/endpoints/root.md for more information
    String response = "<html><body><p>Hi! you have reached the root. Have a great day</p></body></html>";
    Serial.println(response);
    request->send(200, "text/html", response);
  });
```