/*
 * Project: Arduino Uno LED Pixel String Controller
 * Description: 70-LED pixel string using Arduino Uno and FastLED library.
 * Author: KGA Shashmika Dilshan
 * Hardware: Arduino Uno, WS2812B LED Strip (70 LEDs)
 * Library: FastLED (Make sure to install this in Arduino IDE)
 */

#include <FastLED.h>

// --- Configuration ---
#define LED_PIN     6          // Arduino Uno එකේ 6 වෙනි පින් එක (PWM) භාවිතා කර ඇත
#define NUM_LEDS    70         // LED බල්බ ගණන
#define BRIGHTNESS  150        // එළිය (0-255 අතර අගයක් දෙන්න)
#define LED_TYPE    WS2812B    // LED වර්ගය
#define COLOR_ORDER GRB        // පැහැය නිවැරදිව ලැබීමට GRB භාවිතා කරන්න

CRGB leds[NUM_LEDS];

void setup() {
  // පද්ධතිය ආරම්භ කිරීම
  delay(1000); // ආරක්ෂාව සඳහා තත්පරයක ප්‍රමදයක්
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.setBrightness(BRIGHTNESS);
  
  Serial.begin(9600);
  Serial.println("Arduino Uno Pixel String - Online");
}

void loop() {
  // වෘත්තීය මට්ටමේ පෙනුමක් ලබා දෙන patterns කිහිපයක් පහතින්
  
  // 1. Rainbow Cycle Effect
  rainbowCycle(20);
  
  // 2. Simple Color Wipe
  colorWipe(CRGB::Red, 50);
  colorWipe(CRGB::Blue, 50);
  colorWipe(CRGB::Green, 50);
}

// --- Animation Functions ---

// දේදුන්නක වර්ණ මාරුවන රටාව
void rainbowCycle(uint8_t wait) {
  static uint8_t hue = 0;
  for(int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CHSV(hue + (i * 10), 255, 255);
  }
  FastLED.show();
  hue++;
  delay(wait);
}

// තනි වර්ණයක් මුළු පටිය පුරා ගමන් කරන රටාව
void colorWipe(CRGB color, uint8_t wait) {
  for(int i = 0; i < NUM_LEDS; i++) {
    leds[i] = color;
    FastLED.show();
    delay(wait);
  }
}
