#include "Ultrasonic.h"
#include <Wire.h>  // inclure la bibliothèque permettant la communication par le protocole I2C
#include "rgb_lcd.h" // inclure la bibliothèque pour l'écran LCD

rgb_lcd lcd; // création d'un objet lcd

Ultrasonic ultrasonic(7);
void setup()
{
    Serial.begin(9600);
    lcd.begin(16, 2);   // configurer le nombre de colonnes et de lignes de l'écran LCD :
 
      // Ecrire un message sur l'écran LCD
    lcd.clear();   // effacer l'écran
    lcd.setCursor(4, 0);  // mettre le curseur à la cinquième colonne, première ligne
    lcd.print("Arduino");   // afficher "Arduino"
    lcd.setCursor(1, 1);  // mettre le curseur à la deuxième colonne, deuxième ligne
    lcd.print("au lycee Valin");   // afficher "au lycee Valin"
}
void loop()
{
    long RangeInCentimeters;
    RangeInCentimeters = ultrasonic.MeasureInCentimeters(); // two measurements should keep an interval
    Serial.print(RangeInCentimeters);//0~400cm
    Serial.println(" cm");
    delay(250);
}
