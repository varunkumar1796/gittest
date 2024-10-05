#include <FastLED.h>

#define LED_PIN     8
#define NUM_LEDS    64
#define BRIGHTNESS  64
#define LED_TYPE    WS2812B
#define COLOR_ORDER GRB

CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.setBrightness(BRIGHTNESS);
}

void loop() {
  for(int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB::Blue; // Set all LEDs to red
    FastLED.show();
    delay(50);
    leds[i] = CRGB::Black; // Turn off the LED
  }
}
