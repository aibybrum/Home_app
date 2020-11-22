#include <FastLED.h>

#define LED_PIN 6
#define NUM_LEDS 172
#define LED_TYPE WS2811
#define COLOR_ORDER GRB

CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS); 
  for(int i = 0; i < NUM_LEDS; i++){
    leds[i] = CRGB::Red;
    FastLED.show();
  }
}

void loop() {

}
