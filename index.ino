#include <Wire.h>
#include "rgb_lcd.h"
rgb_lcd lcd;
int R;
int G;
int B;


void setup() {
  lcd.begin(16, 2);
  Serial.begin(9600);
}

void loop() {

  lcd.setRGB(R,G,B);
  
  int Val = analogRead(A3);
  int RGB = map(Val,0,1023, 0,100);

// On divise 100 en 6 parties pours correespondre au angles
  if(RGB <= 16.6){                     // 0 to 60°
    R = 100;
    G = RGB * 6;
    B = 0;
  }
  
  if((RGB > 16.6) && (RGB <= 33.3)){    // 60° to 120°
    R = 100 - (RGB - 16.6) * 6;
    G = 100;
    B = 0;
  }
  
  if((RGB > 33.3) && (RGB <= 50)){      // 120° to 180°
    R = 0;
    G = 100;
    B = (RGB - 33.3) * 6;
  }

  if((RGB > 50) && (RGB <= 62.3)){      // 180° to 240°
    R = 0;
    G = 100 - (RGB - 50) * 6;
    B = 100;
  }

  if((RGB > 66.6) && (RGB <= 83.3)){    // 240° to 300°
    R = (RGB - 66.6) * 6;
    G = 0;
    B = 100;
  }

  if((RGB > 83.3) && (RGB <= 100)){     // 300° to 360°
    R = 100;
    G = 0;
    B = 100 - (RGB - 86.6) * 6;
  }

  lcd.clear();
  lcd.setCursor(0, 0); lcd.print(" R:"); lcd.print(R);
                       lcd.print(" G:"); lcd.print(G);
                       lcd.print(" B:"); lcd.print(B);

  lcd.setCursor(0, 1); lcd.print("HEX : "); lcd.print(R,HEX);
                                            lcd.print(G,HEX);
                                            lcd.print(B,HEX);
  delay(100);
}
