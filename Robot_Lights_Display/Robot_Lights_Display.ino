#include "FastLED.h"

// How many leds in your strip?
#define NUM_LEDS 80

// For led chips like Neopixels, which have a data line, ground, and power, you just
// need to define DATA_PIN.  For led chipsets that are SPI based (four wires - data, clock,
// ground, and power), like the LPD8806, define both DATA_PIN and CLOCK_PIN
#define DATA_PIN 11
#define CLOCK_PIN 13

#define YELLOW CRGB(255, 90, 0)
#define BLUE CRGB(0, 50, 170)

// Define the array of leds
CRGB leds[NUM_LEDS];

void setup() { 
	FastLED.addLeds<WS2801, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS);
}

void loop() {
  for (int c = 2; c > 0; c--) {
    cylon(YELLOW, BLUE);
  }
  for (int i=0 ; i < NUM_LEDS; i++) {
        leds[i] = CRGB::Red;
  }
  FastLED.show();
  delay(2000);
}


void cylon(CRGB colorOne, CRGB colorTwo) {
  for(int i = 0; i < NUM_LEDS; i++) {
		// Set the i'th led to red 
		leds[i] = colorOne;
		// Show the leds
		FastLED.show();
		// now that we've shown the leds, reset the i'th led to black
		leds[i] = colorTwo;
		// Wait a little bit before we loop around and do it again
		delay(30);
	}

	// Now go in the other direction.  
	for(int i = NUM_LEDS-1; i >= 0; i--) {
		// Set the i'th led to red 
		leds[i] = colorTwo;
		// Show the leds
		FastLED.show();
		// now that we've shown the leds, reset the i'th led to black
		leds[i] = colorOne;
		// Wait a little bit before we loop around and do it again
		delay(30);
	}
}
