#define PING_PIN 7 //Use digital pin 4 for the range finder
#define LED_LIGHT_DISTANCE 5 //At this distance (in cm) or less the LED is lit up
#define READ_DELAY 1000 //Delay between readings in milliseconds
#include <Wire.h>  // inclure la bibliothèque permettant la communication par le protocole I2C
#include "rgb_lcd.h" // inclure la bibliothèque pour l'écran LCD

rgb_lcd lcd; // création d'un objet lcd
int i = 1;
long distance = 15;

void setup()
{
    Serial.begin(9600);
    lcd.begin(16, 2);   // configurer le nombre de colonnes et de lignes de l'écran LCD :
    delay(10);
}
void loop()
{
    //Set Ping Pin to OUTPUT mode
    pinMode(PING_PIN, OUTPUT); 
    //Send a HIGH signal for 2 microseconds
    digitalWrite(PING_PIN, HIGH);
    delayMicroseconds(2);
    digitalWrite(PING_PIN, LOW);

    //Now read back the distance as a time value (microseconds) using the same pin
    pinMode(PING_PIN, INPUT);
    long duration = pulseIn(PING_PIN, HIGH) / 2;

    //Output the distance to the serial monitor
    long speed = (distance * 0.01)/(duration * 0.000001);

    //Delay before the next reading
    
    
    char finalString[256];
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Vitesse: " + String(int(speed)) + "m/s");
    lcd.setCursor(3, 1);
    i += 1;
    lcd.print("Loop: " + String(i));

    delay(READ_DELAY);
}
