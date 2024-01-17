#include "Ultrasonic.h"
#include <Wire.h>  // inclure la bibliothèque permettant la communication par le protocole I2C
#include "rgb_lcd.h" // inclure la bibliothèque pour l'écran LCD

rgb_lcd lcd; // création d'un objet lcd
char cm[3] = " cm";

Ultrasonic ultrasonic(7);
void setup()
{
    Serial.begin(9600);
    lcd.begin(16, 2);   // configurer le nombre de colonnes et de lignes de l'écran LCD :
}
void loop()
{
    long RangeInCentimeters;
    RangeInCentimeters = ultrasonic.MeasureInCentimeters(); // two measurements should keep an interval
    char str[128];
    sprintf(str, "%lld", RangeInCentimeters);
    strcat(str, cm);
    lcd.clear();
    lcd.setCursor(6, 0);
    lcd.print(range);
    delay(5000);
}
