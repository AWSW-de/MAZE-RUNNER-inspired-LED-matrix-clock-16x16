//####################################################################################################################################################

// Declarations:
byte hourval, minuteval, secondval;
byte pixelColorRed, pixelColorGreen, pixelColorBlue;
time_t getNtpTime();
time_t prevDisplay = 0; // when the digital clock was displayed
void digitalClockDisplay();
void printDigits(int digits);
void sendNTPpacket(IPAddress &address);
WiFiUDP Udp;
unsigned int localPort = 8888;  // local port to listen for UDP packets

// Wifi Manager:
WiFiServer server(80);    // Set web server port number to 80
String header;            // Variable to store the HTTP request

//####################################################################################################################################################

// Default colors:
#define COL_MAZE_RED      255, 0, 0    // Color RED
#define COL_MAZE_GREEN    0, 255, 0    // Color GREEN
#define COL_MAZE_BLUE     0, 0, 255    // Color BLUE
#define COL_MAZE_YELLOW   255, 128, 0  // Color YELLOW
#define COL_MAZE_CYAN     0, 255, 128  // Color CYAN
#define COL_MAZE_OFF      0, 0, 0      // Set LEDs OFF

//####################################################################################################################################################

// LED test color wipe:
void colorWipe(uint32_t c, uint8_t wait) {
  for (uint16_t i = 0; i < pixels.numPixels(); i++) {
    pixels.setPixelColor(i, c);
    pixels.show();
    delay(wait);
  }
}

//####################################################################################################################################################

// Random generate pixel layout:
void led_random() {
  //Serial.println("Generating random pixels... ");
  for (int i = 0; i < pixels.numPixels(); i++) {
    pixels.setPixelColor(i, pixels.Color(random(256), random(256), random(256)));
  }
}

//####################################################################################################################################################

// Run LED test:
void ledtest() {
  if (USELEDTEST == 1) {
    Serial.print("Testing LEDs... Red... ");
    colorWipe(pixels.Color(COL_MAZE_RED), 0.5); // Red
    Serial.print("Green... ");
    colorWipe(pixels.Color(COL_MAZE_GREEN), 0.5); // Green
    Serial.print("Blue... ");
    colorWipe(pixels.Color(COL_MAZE_BLUE), 0.5); // Blue
    Serial.println("Off... ");
    colorWipe(pixels.Color(COL_MAZE_OFF), 0.5);   // Off
  }
}

//####################################################################################################################################################

// Show time in serial monitor of Arduino IDE:
void digitalClockDisplay() {
  // Serial output of digital clock display of the time
  if (TIMEDATESERIAL == 1) {
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
  }
}

//####################################################################################################################################################

// Utility for digital clock display: prints preceding colon and leading 0
void printDigits(int digits) {
  Serial.print(":");
  if (digits < 10)
    Serial.print('0');
  Serial.print(digits);
}

//####################################################################################################################################################

// Get the time from the set NTP server:
time_t getNtpTime();
void digitalClockDisplay();
void printDigits(int digits);
void sendNTPpacket(IPAddress &address);
const int NTP_PACKET_SIZE = 48;           // NTP time is in the first 48 bytes of message
byte packetBuffer[NTP_PACKET_SIZE];       //buffer to hold incoming & outgoing packets

time_t getNtpTime()
{
  //showtext_time(pixels.Color(COL_MAZE_BLUE));
  IPAddress ntpServerIP; // NTP server's ip address
  while (Udp.parsePacket() > 0) ; // discard any previously received packets
  Serial.println("Transmit NTP Request");
  // get a random server from the pool
  WiFi.hostByName(ntpServerName, ntpServerIP);
  Serial.print(ntpServerName);
  Serial.print(": ");
  Serial.println(ntpServerIP);
  sendNTPpacket(ntpServerIP);
  uint32_t beginWait = millis();
  while (millis() - beginWait < 1500) {
    int size = Udp.parsePacket();
    if (size >= NTP_PACKET_SIZE) {
      //showtext_time(pixels.Color(COL_MAZE_GREEN));
      Serial.println("Receive NTP Response");
      Udp.read(packetBuffer, NTP_PACKET_SIZE);  // read packet into the buffer
      unsigned long secsSince1900;
      // convert four bytes starting at location 40 to a long integer
      secsSince1900 =  (unsigned long)packetBuffer[40] << 24;
      secsSince1900 |= (unsigned long)packetBuffer[41] << 16;
      secsSince1900 |= (unsigned long)packetBuffer[42] << 8;
      secsSince1900 |= (unsigned long)packetBuffer[43];
      return secsSince1900 - 2208988800UL + timeZone * SECS_PER_HOUR;
    }
  }
  Serial.println("No NTP Response :-(");
  showtext(1, "T", 0, pixels.Color(COL_MAZE_RED), 0, 0);
  showtext(2, "I", 0, pixels.Color(COL_MAZE_RED), 0, 0);
  showtext(3, "M", 0, pixels.Color(COL_MAZE_RED), 0, 0);
  showtext(4, "E", 0, pixels.Color(COL_MAZE_RED), 0, 0);
  delay(5000);
  ESP.restart();                                          // Restart the ESP to solve the problem !!!
  return 0; // return 0 if unable to get the time
}

//####################################################################################################################################################

// Send an NTP request to the time server at the given address:
void sendNTPpacket(IPAddress &address)
{
  // set all bytes in the buffer to 0
  memset(packetBuffer, 0, NTP_PACKET_SIZE);
  // Initialize values needed to form NTP request
  // (see URL above for details on the packets)
  packetBuffer[0] = 0b11100011;   // LI, Version, Mode
  packetBuffer[1] = 0;     // Stratum, or type of clock
  packetBuffer[2] = 6;     // Polling Interval
  packetBuffer[3] = 0xEC;  // Peer Clock Precision
  // 8 bytes of zero for Root Delay & Root Dispersion
  packetBuffer[12] = 49;
  packetBuffer[13] = 0x4E;
  packetBuffer[14] = 49;
  packetBuffer[15] = 52;
  // all NTP fields have been given values, now
  // you can send a packet requesting a timestamp:
  Udp.beginPacket(address, 123); //NTP requests are to port 123
  Udp.write(packetBuffer, NTP_PACKET_SIZE);
  Udp.endPacket();
}

//####################################################################################################################################################
