#include <stdio.h>
#include <wiringPi.h>

//http://wiringpi.com/pins/ - Ver os valores dos pinos

#define LED_YELLOW     0   // LED Pin - wiringPi pin 0 is BCM_GPIO 17.
#define LED_GREEN      2   // LED Pin - wiringPi pin 0 is BCM_GPIO 27. 
#define LED_RED        3   // GPIO 4

int main (void)
{
  printf ("Raspberry Pi - Gertboard Blink\n") ;

  wiringPiSetup () ;

  // Configura pinos como SAIDA
  pinMode (LED_RED, OUTPUT) ;
  pinMode (LED_YELLOW, OUTPUT) ;
  pinMode (LED_GREEN, OUTPUT) ;

  // Inicialmente todos desligados
  digitalWrite (LED_RED, 0);
  digitalWrite (LED_GREEN, 0);
  digitalWrite (LED_YELLOW, 0);


  for (;;)
  {
    digitalWrite (LED_RED, 1);       // On
    delay (500);                     // mS
    digitalWrite (LED_RED, 0);       // Off
    delay (500);                     // mS
    digitalWrite (LED_YELLOW, 1);    // On
    delay (500);
    digitalWrite (LED_YELLOW, 0) ;   // Off
    delay (500);
    digitalWrite (LED_GREEN, 1) ;    // On
    delay (500);
    digitalWrite (LED_GREEN, 0) ;    // Off
    delay (500);
  }
  return 0 ;
}