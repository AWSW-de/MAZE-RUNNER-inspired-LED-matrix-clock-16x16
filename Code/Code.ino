// ###############################################################################################################################
// #
// # Code for "MAZE RUNNER inspired LED matrix clock (16x16)" project: https://www.printables.com/de/model/227529-maze-runner-inspired-led-matrix-clock-16x16
// #
// # Code by https://github.com/AWSW-de 
// #
// # Released under license: GNU General Public License v3.0: https://github.com/AWSW-de/MAZE-RUNNER-inspired-LED-matrix-clock-16x16/blob/main/LICENSE
// #
// ###############################################################################################################################

// ###############################################################################################################################
// #
// # Code version:
// #
// ###############################################################################################################################
#define CODEVERSION "1.1.6"

//####################################################################################################################################################

// Needed libraries:
#include <ESP8266WiFi.h>
#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include <TimeLib.h>                // https://playground.arduino.cc/Code/Time/
#include <WiFiManager.h>            // https://github.com/tzapu/WiFiManager
#include <Adafruit_NeoPixel.h>      // https://github.com/adafruit/Adafruit_NeoPixel
#include "settings.h"
#include "texts.h"
#include "functions.h"

//####################################################################################################################################################

void setup() {
  Serial.begin(115200);
  pixels.begin();
  pixels.show();
  pixels.setBrightness(BRIGHTNESS);
  delay(1000);
  Serial.println(" ");
  Serial.println(" ");
  Serial.println(" ");
  Serial.println("#############################");
  Serial.print("# AWSW MAZE LED CLOCK ");
  Serial.print(CODEVERSION);
  Serial.println(" #");
  Serial.println("#############################");
  Serial.println(" ");

  // Startup LED tests and texts:
  ledtest();
  led_random();
  if (SHOWSTARTTEXTS == 1) {
    showtext(1, "A", 0, pixels.Color(COL_MAZE_NUMBER), 0, 0);
    showtext(2, "W", 0, pixels.Color(COL_MAZE_NUMBER), 0, 0);
    showtext(3, "S", 0, pixels.Color(COL_MAZE_NUMBER), 0, 0);
    showtext(4, "W", 0, pixels.Color(COL_MAZE_NUMBER), 0, 0);
    delay(1000);
    showrunner(1, "A", 100, pixels.Color(COL_MAZE_NUMBER), pixels.Color(COL_MAZE_RUNNER), 0, 0);
    showrunner(2, "W", 100, pixels.Color(COL_MAZE_NUMBER), pixels.Color(COL_MAZE_RUNNER), 0, 0);
    showrunner(3, "S", 100, pixels.Color(COL_MAZE_NUMBER), pixels.Color(COL_MAZE_RUNNER), 0, 0);
    showrunner(4, "W", 100, pixels.Color(COL_MAZE_NUMBER), pixels.Color(COL_MAZE_RUNNER), 0, 0);
    delay(1000);
    showtext(1, "M", 0, pixels.Color(COL_MAZE_NUMBER), 0, 0);
    showtext(2, "A", 0, pixels.Color(COL_MAZE_NUMBER), 0, 0);
    showtext(3, "Z", 0, pixels.Color(COL_MAZE_NUMBER), 0, 0);
    showtext(4, "E", 0, pixels.Color(COL_MAZE_NUMBER), 0, 0);
    delay(1000);
    showrunner(1, "M", 100, pixels.Color(COL_MAZE_NUMBER), pixels.Color(COL_MAZE_RUNNER), 0, 0);
    showrunner(2, "A", 100, pixels.Color(COL_MAZE_NUMBER), pixels.Color(COL_MAZE_RUNNER), 0, 0);
    showrunner(3, "Z", 100, pixels.Color(COL_MAZE_NUMBER), pixels.Color(COL_MAZE_RUNNER), 0, 0);
    showrunner(4, "E", 100, pixels.Color(COL_MAZE_NUMBER), pixels.Color(COL_MAZE_RUNNER), 0, 0);
    delay(1000);
    showtext(1, "C", 0, pixels.Color(COL_MAZE_NUMBER), 0, 0);
    showtext(2, "LO", 0, pixels.Color(COL_MAZE_NUMBER), 0, 0);
    showtext(3, "C", 0, pixels.Color(COL_MAZE_NUMBER), 0, 0);
    showtext(4, "K", 0, pixels.Color(COL_MAZE_NUMBER), 0, 0);
    delay(1000);
    showrunner(1, "C", 100, pixels.Color(COL_MAZE_NUMBER), pixels.Color(COL_MAZE_RUNNER), 0, 0);
    showrunner(2, "LO", 100, pixels.Color(COL_MAZE_NUMBER), pixels.Color(COL_MAZE_RUNNER), 0, 0);
    showrunner(3, "C", 100, pixels.Color(COL_MAZE_NUMBER), pixels.Color(COL_MAZE_RUNNER), 0, 0);
    showrunner(4, "K", 100, pixels.Color(COL_MAZE_NUMBER), pixels.Color(COL_MAZE_RUNNER), 0, 0);
    delay(1000);
  }

  // WiFi Manager:
  // Show WIFI in RED on the display to show the connect status
  showtext(1, "W", 0, pixels.Color(COL_MAZE_RED), 0, 0);
  showtext(2, "I", 0, pixels.Color(COL_MAZE_RED), 0, 0);
  showtext(3, "F", 0, pixels.Color(COL_MAZE_RED), 0, 0);
  showtext(4, "I", 0, pixels.Color(COL_MAZE_RED), 0, 0);
  delay(1000);
  Serial.println("Starting Wifi Manager");
  WiFiManager wifiManager;          // Local intialization. Once its business is done, there is no need to keep it around
  if (RESETWIFI == 1) {
    showtext(1, "W", 0, pixels.Color(COL_MAZE_BLUE), 0, 0);
    showtext(2, "I", 0, pixels.Color(COL_MAZE_BLUE), 0, 0);
    showtext(3, "F", 0, pixels.Color(COL_MAZE_BLUE), 0, 0);
    showtext(4, "I", 0, pixels.Color(COL_MAZE_BLUE), 0, 0);
    delay(1000);
    wifiManager.resetSettings();    // Deletes the stored WiFi settings! Set to 0 on top of the sketch after reset again!
  }
  wifiManager.autoConnect("MAZE LED CLOCK");
  Serial.println("Connected to WiFi");  // if you get here you have connected to the WiFi
  // Show WIFI in GREEN on the display to show the connect status
  showtext(1, "W", 0, pixels.Color(COL_MAZE_GREEN), 0, 0);
  showtext(2, "I", 0, pixels.Color(COL_MAZE_GREEN), 0, 0);
  showtext(3, "F", 0, pixels.Color(COL_MAZE_GREEN), 0, 0);
  showtext(4, "I", 0, pixels.Color(COL_MAZE_GREEN), 0, 0);
  delay(1000);
  server.begin();

  Serial.print("IP address assigned by DHCP is ");
  Serial.println(WiFi.localIP());
  Serial.println("Starting UDP");
  Udp.begin(localPort);
  Serial.print("Local port: ");
  Serial.println(Udp.localPort());
  Serial.println("waiting for sync");
  setSyncProvider(getNtpTime);
  setSyncInterval(3600);

  // Show current time and date once on startup:
  Serial.print("Current time and date: ");
  Serial.print(hour());
  printDigits(minute());
  printDigits(second());
  Serial.print(" ");
  Serial.print(day());
  Serial.print(".");
  Serial.print(month());
  Serial.print(".");
  Serial.print(year());
  Serial.println();

  if (USELETTERTEST == 1) {
    lettertest();
  }

  MAZE_CLEAR();
  led_random();
}

//####################################################################################################################################################

String CurrentHourLeft = "-";
String CurrentHourRight = "-";
String CurrentMinuteLeft = "-";
String CurrentMinuteRight = "-";

void loop() {
  // WiFi Manager Start:
  WiFiClient client = server.available();   // Listen for incoming clients
  if (client) {                             // If a new client connects,
    Serial.println("New Client.");          // print a message out in the serial port
    String currentLine = "";                // make a String to hold incoming data from the client
    while (client.connected()) {            // loop while the client's connected
      if (client.available()) {             // if there's bytes to read from the client,
        char c = client.read();             // read a byte, then
        Serial.write(c);                    // print it out the serial monitor
        header += c;
        if (c == '\n') {                    // if the byte is a newline character
          if (currentLine.length() == 0) {
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println("Connection: close");
            client.println();
            client.println("<!DOCTYPE html><html>");
            client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
            client.println("<link rel=\"icon\" href=\"data:,\">");
            client.println("<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}");
            client.println(".button { background-color: #195B6A; border: none; color: white; padding: 16px 40px;");
            client.println("text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}");
            client.println(".button2 {background-color: #77878A;}</style></head>");
            client.println("<body><h1>ESP8266 Web Server</h1>");
            client.println("</body></html>");
            client.println();
            break;
          } else { // if you got a newline, then clear currentLine
            currentLine = "";
          }
        } else if (c != '\r') {  // if you got anything else but a carriage return character,
          currentLine += c;      // add it to the end of the currentLine
        }
      }
    }
    // Clear the header variable
    header = "";
    // Close the connection
    client.stop();
    Serial.println("Client disconnected.");
    Serial.println("");
  }
  // WiFi Manager End

  if (timeStatus() != timeNotSet) {
    if (now() != prevDisplay) { //update the display only if time has changed
      prevDisplay = now();
      digitalClockDisplay();

      // Display the time:
      String My_Hour = String(hour());
      if (My_Hour.length() < 2) {
        My_Hour = "0" + My_Hour;
      }
      String My_Minute = String(minute());
      if (My_Minute.length() < 2) {
        My_Minute = "0" + My_Minute;
      }
      String My_Second = String(second());
      if (My_Second.length() < 2) {
        My_Second = "0" + My_Second;
      }

      String sub_HourLeft = My_Hour.substring(0, 1);
      String sub_HourRight = My_Hour.substring(1, 2);
      String sub_MinuteLeft = My_Minute.substring(0, 1);
      String sub_MinuteRight = My_Minute.substring(1, 2);
      String sub_SecondLeft = My_Second.substring(0, 1);
      String sub_SecondRight = My_Second.substring(1, 2);

      if ((sub_SecondLeft == "3") && (sub_SecondRight == "0")) {
        showrunner(1, sub_HourLeft, 100, pixels.Color(COL_MAZE_NUMBER), pixels.Color(COL_MAZE_RUNNER), 0, 0);
        showrunner(2, sub_HourRight, 100, pixels.Color(COL_MAZE_NUMBER), pixels.Color(COL_MAZE_RUNNER), 0, 0);
        showrunner(3, sub_MinuteLeft, 100, pixels.Color(COL_MAZE_NUMBER), pixels.Color(COL_MAZE_RUNNER), 0, 0);
        showrunner(4, sub_MinuteRight, 100, pixels.Color(COL_MAZE_NUMBER), pixels.Color(COL_MAZE_RUNNER), 0, 0);
      }

      // Generate a new random background every full hour:
      if ((sub_MinuteLeft == "0") && (sub_MinuteRight == "0") && (sub_SecondLeft == "0") && (sub_SecondRight == "0")) {
        led_random();
        showtext(1, String(sub_HourLeft), 0, pixels.Color(COL_MAZE_NUMBER), 0, 0);
        showtext(2, String(sub_HourRight), 0, pixels.Color(COL_MAZE_NUMBER), 0, 0);
        showtext(3, String(sub_MinuteLeft), 0, pixels.Color(COL_MAZE_NUMBER), 0, 0);
        showtext(4, String(sub_MinuteRight), 0, pixels.Color(COL_MAZE_NUMBER), 0, 0);
      }

      // Write the digits only when needed on a change to avoid a permanent change of their random background:
      if (CurrentHourLeft != sub_HourLeft) {
        showtext(1, String(sub_HourLeft), 0, pixels.Color(COL_MAZE_NUMBER), 0, 0);
        CurrentHourLeft = sub_HourLeft;
      }
      if (CurrentHourRight != sub_HourRight) {
        showtext(2, String(sub_HourRight), 0, pixels.Color(COL_MAZE_NUMBER), 0, 0);
        CurrentHourRight = sub_HourRight;
      }
      if (CurrentMinuteLeft != sub_MinuteLeft) {
        showtext(3, String(sub_MinuteLeft), 0, pixels.Color(COL_MAZE_NUMBER), 0, 0);
        CurrentMinuteLeft = sub_MinuteLeft;
      }
      if (CurrentMinuteRight != sub_MinuteRight) {
        showtext(4, String(sub_MinuteRight), 0, pixels.Color(COL_MAZE_NUMBER), 0, 0);
        CurrentMinuteRight = sub_MinuteRight;
      }


      // Night Mode:
      if (NIGHTMODE_USED == 1) {

        // Test the Night Mode functionality:
        /*
                Serial.print("REAL CURRENT HOUR = ");
                Serial.print(String(hour()));
                int myTestHour = 0; // Test hour value
                Serial.print(" - TEST Current myTestHour = ");
                Serial.print(String(myTestHour));
                Serial.print(" - NIGHTMODE_START = ");
                Serial.print(NIGHTMODE_START);
                Serial.print(" - NIGHTMODE_END = ");
                Serial.println(NIGHTMODE_END);
                if ((myTestHour >= NIGHTMODE_END) && (myTestHour < NIGHTMODE_START)) {       // FOR TEST WITH myTestHour VALUE ONLY
        */

        if ((hour() >= NIGHTMODE_END) && (hour() < NIGHTMODE_START)) {        // FOR REAL USE WITH REAL CURRENT TIME
          pixels.setBrightness(BRIGHTNESS);
        }
        else
        {
          pixels.setBrightness(BRIGHTNESS_OFF);
        }
      }

    }
  }

  pixels.show();
  delay(500);
}

//####################################################################################################################################################

// Testing the letters and runner for the 4 digits:
void lettertest() {
  Serial.println("Testing the letters for the 4 digits... This will take some time...");
  const String myArray [] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "C", "E", "F", "I", "K", "LO", "M", "S", "T", "W", "Z"};

  for (int i = 1; i <= 4; i++) {
    MAZE_CLEAR();
    Serial.print("Testing digit #");
    Serial.println(i);
    for (String element : myArray) {
      Serial.print("Testing letter ");
      Serial.println(element);
      MAZE_CLEAR();
      showtext(i, element, 500, pixels.Color(COL_MAZE_BLUE), 0, 0);
      showrunner(i, element, 250, pixels.Color(COL_MAZE_BLUE), pixels.Color(COL_MAZE_RED), 0, 0);
    }
  }
  Serial.println("Testing complete...");
  MAZE_CLEAR();
}

//####################################################################################################################################################
