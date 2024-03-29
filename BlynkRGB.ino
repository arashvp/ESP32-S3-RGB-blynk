#include <Adafruit_NeoPixel.h>

#define PIN 38
#define NUMPIXELS 1

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
 pixels.begin();
 Serial.begin(9600); // Initialize serial communication at 9600 baud rate
}

void loop() {
 for(int i = 0; i < 256; i += 12) { // Loop through each color component
    for(int j = 0; j < 256; j += 12) { // Loop through each color component
      for(int k = 0; k < 256; k += 12) { // Loop through each color component
        pixels.clear();
        pixels.setPixelColor(0, pixels.Color(i, j, k));
        pixels.show();
        Serial.print("RGB: ");
        Serial.print(i);
        Serial.print(", ");
        Serial.print(j);
        Serial.print(", ");
        Serial.println(k);
        
        // Check if RGB values are (0, 0, 255), (0, 255, 0), or (255, 0, 0) and introduce a delay of 100ms
        if((i == 0 && j == 0 && k == 255) || (i == 0 && j == 255 && k == 0) || (i == 255 && j == 0 && k == 0)) {
          delay(1000);
        } else {
          delay(100); // Adjust delay as needed for other colors
        }
      }
    }
 }
}
