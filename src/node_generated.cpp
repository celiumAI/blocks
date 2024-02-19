
#include <ESP8266WiFi.h>
#include <ESPAsyncTCP.h>
#include <ESPAsyncWebServer.h>

AsyncWebServer server(80);

//for [celium](github.com/celiumAI):
// disabled /docs/authentication.md

struct Node {
  String id;
  String name;
  String timestamp;
  String origin;
};

Node root = {
    "randnode-1ba0-4d33-8f9f-b93563cc936f",
    "simple node",
    "1708290697000",
    "m-c-frank/celium-experiments",
};

String nodeToString(Node node){
    String json = "{";
    json += "\"id\": \"" + node.id + "\", ";
    json += "\"name\": \"" + node.name + "\", ";
    json += "\"timestamp\": \"" + node.timestamp + "\", ";
    json += "\"origin\": \"" + node.origin + "\"";
    json += "}";
    return json;
}


void setup() {
  Serial.begin(9600);
  

    const char* ap_ssid = "node";
    const char* ap_password = "thereisnospoonhere";

    WiFi.softAP(ap_ssid, ap_password);
    IPAddress myIP = WiFi.softAPIP();
    Serial.print("AP IP address: ");
    Serial.println(myIP);


const char* parent_ssid = "root";
const char* parent_password = "thereisnospoon";

WiFi.begin(parent_ssid, parent_password);

while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
}

Serial.println("");
Serial.print("Connected to ");
Serial.println(parent_ssid);
Serial.print("IP address: ");
Serial.println(WiFi.localIP());



  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
    // check out /docs/endpoints/root.md for more information
    String response = "<html><body><p>Hi! you have reached the root. Have a great day</p></body></html>";
    Serial.println(response);
    request->send(200, "text/html", response);
  });


    server.on("/node", HTTP_GET, [](AsyncWebServerRequest *request) {
        // check out /docs/endpoints/node/timestamp.md for more information
        String response;
        response = nodeToString(root);
        request->send(200, "text/plain", response);
    });


server.on("/chat", HTTP_GET, [](AsyncWebServerRequest *request) {
    // HTML content with proper C++ string concatenation
    String html = "<!DOCTYPE html><html lang=\"en\"><head><meta charset=\"UTF-8\"><title>Simple Chat Page</title>"
                  "<script>"
                  "// Initialize an array to store chat messages\n"
                  "let messages = [];\n"
                  "function sendMessage() {\n"
                  "    // Disable the send button\n"
                  "    document.getElementById('sendButton').disabled = true;\n"
                  "    // Get the message from the input field\n"
                  "    const message = document.getElementById('messageInput').value;\n"
                  "    // Check if the message is not empty\n"
                  "    if (message.trim() !== '') {\n"
                  "        // Add the message to the messages array\n"
                  "        messages.push(message);\n"
                  "        // Clear the input field for the next message\n"
                  "        document.getElementById('messageInput').value = '';\n"
                  "        // Update the chat window with the new message\n"
                  "        updateChatWindow();\n"
                  "    }\n"
                  "    // Simulate a response delay\n"
                  "    setTimeout(function() {\n"
                  "        // Here, you would typically handle the actual sending to and receiving messages from a server\n"
                  "        // Re-enable the send button\n"
                  "        document.getElementById('sendButton').disabled = false;\n"
                  "    }, 2000); // Simulate a 2-second delay for the response\n"
                  "}\n"
                  "function updateChatWindow() {\n"
                  "    // Select the chat window\n"
                  "    const chatWindow = document.getElementById('chatWindow');\n"
                  "    // Reset the chat window content\n"
                  "    chatWindow.innerHTML = '';\n"
                  "    // Loop through the messages array and display each message\n"
                  "    messages.forEach(function(message) {\n"
                  "        const messageElement = document.createElement('div');\n"
                  "        messageElement.textContent = message;\n"
                  "        chatWindow.appendChild(messageElement);\n"
                  "    });\n"
                  "}\n"
                  "</script>"
                  "</head>"
                  "<body>"
                  "<div id=\"chatWindow\" style=\"margin-bottom: 10px; border: 1px solid #ccc; padding: 10px; height: 150px; overflow-y: scroll;\">"
                  "<!-- Chat messages will appear here -->"
                  "</div>"
                  "<input type=\"text\" id=\"messageInput\" placeholder=\"Type a message...\">"
                  "<button id=\"sendButton\" onclick=\"sendMessage()\">Send</button>"
                  "</body></html>";

    // Send the HTML content in the response
    request->send(200, "text/html", html);
});


  server.begin();
}

void loop() {

// nothing to see here yet

}
