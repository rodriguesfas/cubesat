#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h>
#include <ArduinoJson.h>

/**
 * setup - 
 */
void setup()
{
    Serial.begin(115200);

    /**
   * WiFi connection
   * 
   * @param your SSID 
   * @param your PASS
   */
    WiFi.begin("brisa-679421", "84bmey4i");

    // Wait for the WiFI connection completion.
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.println("Waiting for connection");
    }
}

/**
 * loop - 
 */
void loop()
{

    //Check WiFi connection status
    if (WiFi.status() == WL_CONNECTED)
    {

        StaticJsonBuffer<300> JSONbuffer; // Declaring static JSON buffer
        JsonObject &JSONencoder = JSONbuffer.createObject();

        JSONencoder["sensorType"] = "Temperature";

        JsonArray &values = JSONencoder.createNestedArray("values");
        values.add(20);
        values.add(21);
        values.add(23);

        JsonArray &timestamps = JSONencoder.createNestedArray("timestamps");
        timestamps.add("10:10");
        timestamps.add("10:20");
        timestamps.add("10:30");

        char JSONmessageBuffer[300];
        JSONencoder.prettyPrintTo(JSONmessageBuffer, sizeof(JSONmessageBuffer));
        Serial.println(JSONmessageBuffer);

        WiFiClient client;
        HTTPClient http; //Declare object of class HTTPClient

        http.begin(client, "http://3464c54dce1f.ngrok.io/postjson"); //Specify request destination
        http.addHeader("Content-Type", "application/json");          //Specify content-type header

        int httpCode = http.POST(JSONmessageBuffer); //Send the request
        String payload = http.getString();           //Get the response payload

        Serial.println(httpCode); //Print HTTP return code
        Serial.println(payload);  //Print request response payload

        http.end();
    else
    {
        Serial.println("Error in WiFi connection");
    }

    delay(30000); //Send a request every 30 seconds
}