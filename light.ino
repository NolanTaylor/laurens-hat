#include <FastLED.h>

#define NUM_LEDS 37
#define DATA_PIN 5
CRGB leds[NUM_LEDS];

int button, count = 0;
bool flip = false;

void setup()
{
  Serial.begin(9600);

  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);

  pinMode(2, INPUT_PULLUP);

  light();
}

void loop()
{
  button = digitalRead(2);

  if (button == LOW && !flip)
  {
    Serial.println("yee haw");
    light();
    flip = true;
  }
  else if (button == HIGH && flip)
  {
    flip = false;
  }
}

void light()
{
  switch (count)
  {
    case 0: case0(); count++; break;
    case 1: case1(); count++; break;
    case 2: case2(); count++; break;
    case 3: case3(); count++; break;
    case 4: case4(); count = 0; break;                    
  }
}

void case0()
{
  for (int i = 0; i < 19; i++)
  {
    leds[i] = CRGB(255, 0, 0);
    leds[37 - i] = CRGB(0, 0, 255);
    delay(50);
    FastLED.show();
  }

  for (int i = 18; i < 37; i++)
  {
    leds[i] = CRGB(150, 0, 255);
    leds[36 - i] = CRGB(150, 0, 255);
    delay(50);
    FastLED.show();
  }

  for (int i = 0; i < 19; i++)
  {
    leds[i] = CRGB(0, 0, 0);
    leds[37 - i] = CRGB(0, 0, 0);
    delay(50);
    FastLED.show();
  }
}

void case1()
{
  for (int i = 0; i < 37; i++)
  {
    rainbow(i);
    
    FastLED.show();
    delay(35);
  }

  for (int i = 0; i < 37; i++)
  {
    leds[i] = CRGB(0, 0, 0);
    FastLED.show();
    delay(35);
  }

  for (int i = 36; i >= 0; i--)
  {
    rainbow(i);

    FastLED.show();
    delay(35);
  }

  for (int i = 36; i >= 0; i--)
  {
    leds[i] = CRGB(0, 0, 0);
    FastLED.show();
    delay(35);
  }
}

void case2()
{
  for (int i = 0; i < 37; i++)
  {
    leds[i] = CRGB(0, 255, 0);
    FastLED.show();
    delay(50);
  }

  for (int i = 35; i >= 0; i--)
  {
    leds[i] = CRGB(255, 0, 0);
    leds[i + 1] = CRGB(255, 255, 0);
    FastLED.show();
    delay(50);
  }

  for (int i = 1; i < 37; i++)
  {
    leds[i] = CRGB(0, 0, 255);
    leds[i - 1] = CRGB(0, 255, 0);
    FastLED.show();
    delay(50);
  }

  for (int i = 36; i >= 0; i--)
  {
    leds[i] = CRGB(0, 0, 0);
    FastLED.show();
    delay(50);
  }
}

void case3()
{
  for (int i = 0; i < 2; i++)
  {
    leds[15] = CRGB(0, 255, 255);
    leds[21] = CRGB(0, 255, 255);
    FastLED.show();
    delay(500);
    leds[15] = CRGB(0, 0, 0);
    leds[21] = CRGB(0, 0, 0);
    FastLED.show();
    delay(500);
  }

  for (int i = 0; i < 21; i++)
  {
    switch (i)
    {
      case 0: leds[i] = CRGB(0, 0, 255); leds[37 - i] = CRGB(0, 0, 255); break;
      case 1: leds[i] = CRGB(0, 50, 255); leds[37 - i] = CRGB(0, 50, 255); break;
      case 2: leds[i] = CRGB(0, 100, 255); leds[37 - i] = CRGB(0, 100, 255); break;
      case 3: leds[i] = CRGB(0, 150, 255); leds[37 - i] = CRGB(0, 150, 255); break;
      case 4: leds[i] = CRGB(0, 200, 255); leds[37 - i] = CRGB(0, 200, 255); break;
      case 5: leds[i] = CRGB(0, 255, 255); leds[37 - i] = CRGB(0, 255, 255); break;
      case 6: leds[i] = CRGB(0, 255, 200); leds[37 - i] = CRGB(0, 255, 200); break;
      case 7: leds[i] = CRGB(0, 255, 150); leds[37 - i] = CRGB(0, 255, 150); break;
      case 8: leds[i] = CRGB(0, 255, 100); leds[37 - i] = CRGB(0, 255, 100); break;
      case 9: leds[i] = CRGB(0, 255, 50); leds[37 - i] = CRGB(0, 255, 50); break;
      case 10: leds[i] = CRGB(0, 255, 0); leds[37 - i] = CRGB(0, 255, 0); break;
      case 11: leds[i] = CRGB(0, 255, 50); leds[37 - i] = CRGB(0, 255, 50); break;
      case 12: leds[i] = CRGB(0, 255, 100); leds[37 - i] = CRGB(0, 255, 100); break;
      case 13: leds[i] = CRGB(0, 255, 150); leds[37 - i] = CRGB(0, 255, 150); break;
      case 14: leds[i] = CRGB(0, 255, 200); leds[37 - i] = CRGB(0, 255, 200); break;
      case 15: leds[i] = CRGB(0, 255, 255); leds[37 - i] = CRGB(0, 255, 255); break;
      case 16: leds[i] = CRGB(0, 200, 255); leds[37 - i] = CRGB(0, 200, 255); break;
      case 17: leds[i] = CRGB(0, 150, 255); leds[37 - i] = CRGB(0, 150, 255); break;
      case 18: leds[i] = CRGB(0, 100, 255); leds[37 - i] = CRGB(0, 100, 255); break;
      case 19: leds[i] = CRGB(0, 50, 255); leds[37 - i] = CRGB(0, 50, 255); break;
      case 20: leds[i] = CRGB(0, 0, 255); leds[37 - i] = CRGB(0, 0, 255); break;
    }

    FastLED.show();
    delay(70);
  }

  delay(300);
  
  for (int i = 0; i < 37; i++)
  {
    leds[i] = CRGB(0, 0, 0);
    leds[37 - i] = CRGB(0, 0, 0);
    FastLED.show();
    delay(20);
  }
}

void case4()
{
  for (int i = 18; i < 37; i++)
  {
    leds[i] = CRGB(255, 0, 0);
    leds[37 - i] = CRGB(255, 0, 0);
    FastLED.show();
    delay(25);
  }

  for (int i = 0; i < 19; i++)
  {
    leds[i] = CRGB(255, 255, 0);
    leds[37 - i] = CRGB(255, 255, 0);
    FastLED.show();
    delay(25);
  }

  for (int i = 18; i < 37; i++)
  {
    leds[i] = CRGB(255, 70, 0);
    leds[37 - i] = CRGB(255, 70, 0);
    FastLED.show();
    delay(25);
  }

  for (int i = 18; i < 37; i++)
  {
    leds[i] = CRGB(0, 0, 0);
    leds[36 - i] = CRGB(0, 0, 0);
    FastLED.show();
    delay(25);
  }
}

void rainbow(int i)
{
    switch (i)
    {
      case 0: leds[i] = CRGB(255, 0, 0); break;
      case 1: leds[i] = CRGB(255, 50, 0); break;
      case 2: leds[i] = CRGB(255, 100, 0); break;
      case 3: leds[i] = CRGB(255, 150, 0); break;
      case 4: leds[i] = CRGB(255, 200, 0); break;
      case 5: leds[i] = CRGB(255, 255, 0); break;
      case 6: leds[i] = CRGB(200, 255, 0); break;
      case 7: leds[i] = CRGB(150, 255, 0); break;
      case 8: leds[i] = CRGB(100, 255, 0); break;
      case 9: leds[i] = CRGB(50, 255, 0); break;
      case 10: leds[i] = CRGB(0, 255, 0); break;
      case 11: leds[i] = CRGB(0, 255, 50); break;
      case 12: leds[i] = CRGB(0, 255, 100); break;
      case 13: leds[i] = CRGB(0, 255, 150); break;
      case 14: leds[i] = CRGB(0, 255, 200); break;
      case 15: leds[i] = CRGB(0, 255, 255); break;
      case 16: leds[i] = CRGB(0, 200, 255); break;
      case 17: leds[i] = CRGB(0, 150, 255); break;
      case 18: leds[i] = CRGB(0, 100, 255); break;
      case 19: leds[i] = CRGB(0, 50, 255); break;
      case 20: leds[i] = CRGB(0, 0, 255); break;
      case 21: leds[i] = CRGB(50, 0, 255); break;
      case 22: leds[i] = CRGB(100, 0, 255); break;
      case 23: leds[i] = CRGB(150, 0, 255); break;
      case 24: leds[i] = CRGB(200, 0, 255); break;
      case 25: leds[i] = CRGB(255, 0, 255); break;
      case 26: leds[i] = CRGB(255, 0, 200); break;
      case 27: leds[i] = CRGB(255, 0, 150); break;
      case 28: leds[i] = CRGB(255, 0, 100); break;
      case 29: leds[i] = CRGB(255, 0, 50); break;
      case 30: leds[i] = CRGB(255, 0, 0); break;
      case 31: leds[i] = CRGB(255, 50, 0); break;
      case 32: leds[i] = CRGB(255, 100, 0); break;
      case 33: leds[i] = CRGB(255, 150, 0); break;
      case 34: leds[i] = CRGB(255, 200, 0); break;
      case 35: leds[i] = CRGB(255, 255, 0); break;
      case 36: leds[i] = CRGB(200, 255, 0); break;
    }
}
