#include <FastLED.h>

#define NUM_LEDS 64
#define DATA_PIN 3

CRGB leds[NUM_LEDS];

// Heart pattern
const uint8_t heart[8][8] = {
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 1, 1, 0, 0, 1, 1, 0},
  {1, 1, 1, 1, 1, 1, 1, 1},
  {1, 1, 1, 1, 1, 1, 1, 1},
  {0, 1, 1, 1, 1, 1, 1, 0},
  {0, 0, 1, 1, 1, 1, 0, 0},
  {0, 0, 0, 1, 1, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0}
};

void setup() {
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
  FastLED.clear();
}

void loop() {
  for (int row = 0; row < 8; row++) {
    for (int col = 0; col < 8; col++) {
      if (heart[row][col] == 1) {
        leds[row * 8 + col] = CRGB::Red;
      } else {
        leds[row * 8 + col] = CRGB::Black;
      }
    }
  }
  FastLED.show();
  delay(1000); // Display the heart for 1 second
}
