#include <Arduino.h>  

 uint8_t value; 

void setup(){ 

  // configure PD7_PD4 as inputs(0x0F) 
  DDRD &= 0x0F; 
  PORTD |= 0xF0; 
  //configure PB3_PB0 (0x0F) 
  DDRB &= 0x0F; 

 Serial.begin(9600);

} 

 

void loop(){ 

  //Read switches 

  value = PIND; 

  //mask the values(0xF0) 

  value &= 0xF0; 

  // Shift right value >>4 

  value = value >> 4; 

  //invert the values 

 value = ~ value;
 value &= 0x0F;
 value = ~ value +1;
 value &= 0x0F;

  //Display in LED 

  PORTB = value; 

  Serial.print("Binary:"); 

  Serial.println(value,BIN); 

  Serial.print("Decimal:"); 

  Serial.println(value); 

  delay(1000); 

}
