//#include <avr/io.h>
//#include <util/delay.h>
//int tog = 1;
//void setup() {
//  // put your setup code here, to run once:
//  DDRC = 1;
//  DDRB = 0;
//  PORTC = PORTC |(1<<PC0); 
//}
//
//void loop() {
//  // put your main code here, to run repeatedly:
//  if(PINB & 0x01 == 0x01)
//  {
//    _delay_ms(30);
//    if(PINB & 0x01 == 0x01)
//    {
//      if(tog == 0)//((PORTC & 0x00)== 0x00)
//      {
//        PORTC = PORTC |(1<<PC0);
//        tog = 1;  
//      }
//      else
//      {
//        PORTC = PORTC & (~(1<<PC0)); 
//        tog = 0;  
//      }
//    }
//  }
//
//  
//}
#include <avr/io.h>
#include <util/delay.h>
int toggle;

void setup() {
  // put your setup code here, to run once:
  DDRB = DDRB & (~(1<<PB0));

  DDRC = DDRC | (1<<PC0);

  PORTC = PORTC & (~(1<<PC0));
   toggle = 1;
}

void loop() {

  // put your main code here, to run repeatedly:
  
  
  if(!(PINB & (1<<PB0))){
    _delay_ms(30);
    if(!(PINB & (1<<PB0)) && toggle){
    PORTC =  ~PORTC ;
     toggle = 0;
    }
  } else {
    toggle = 1;
  }


//    if(!(PINB & (1<<PB0))){
//    PORTC |= (1<<PC0);
//  } 
  //else{
//    PORTC &= (~(1<<PC0));
//  }

  
  
  
}
