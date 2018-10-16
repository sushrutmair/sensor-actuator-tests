#include <FastLED.h>

#define LED_PIN                                                     6 //NANO.D6
#define NUM_LEDS                                                30
#define BRIGHTNESS                                            20
#define BLINKTIME                                                 121

//CRGB leds[NUM_LEDS];
CRGBArray<NUM_LEDS> leds;

void setup() {
  // put your setup code here, to run once:
  delay(3000);

  FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
  FastLED.setBrightness(  BRIGHTNESS );
}

void RGBChainloop()
{
  for (int i = 0; i < NUM_LEDS; i++)
  {
    leds[i] = CRGB(255, 0, 0);
    FastLED.show();
    delay(BLINKTIME);
  }

  for (int i = 0; i < NUM_LEDS; i++)
  {
    leds[i] = CRGB(0, 255, 0);
    FastLED.show();
    delay(BLINKTIME);
  }

  for (int i = 0; i < NUM_LEDS; i++)
  {
    leds[i] = CRGB(0, 0, 255);
    FastLED.show();
    delay(BLINKTIME);
  }
}

void RGBSetDemo()
{
  static uint8_t hue;
  for (int i = 0; i < NUM_LEDS / 2; i++) {
    // fade everything out
    leds.fadeToBlackBy(40);

    // let's set an led value
    leds[i] = CHSV(hue++, 255, 255);

    // now, let's first 20 leds to the top 20 leds,
    leds(NUM_LEDS / 2, NUM_LEDS - 1) = leds(NUM_LEDS / 2 - 1 , 0);
    FastLED.delay(33);
  }
}

void ColorArray()
{
  for (int i = 0; i < NUM_LEDS; i++)
  {
    leds[i] = CRGB::HotPink; FastLED.show(); delay(30);
    leds[i+1] = CRGB::Maroon; FastLED.show(); delay(30);
    leds[i+2] = CRGB::Aqua; FastLED.show(); delay(30);
    leds[i+3] = CRGB::Gray; FastLED.show(); delay(30);
  }

  for (int i = NUM_LEDS; i > 3; i--)
  {
    leds[i] = CRGB::Yellow; FastLED.show(); delay(30);
    leds[i-1] = CRGB::Lime; FastLED.show(); delay(30);
    leds[i-2] = CRGB::Teal; FastLED.show(); delay(30);
    leds[i-3] = CRGB::Purple; FastLED.show(); delay(30);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  RGBChainloop();
  delay(3000);

  RGBSetDemo();
  delay(3000);

  ColorArray();
  delay(3000);
}

