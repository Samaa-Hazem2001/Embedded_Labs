#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include <string.h>

void SPI_Init(){
  DDRB &= ~((1<<PB3)|(1<<PB5)|(1<<PB2));
  DDRB |= (1<<PB4);
  SPCR |=(1<<SPE);

}

void SPI_Write(uint8_t data){

  char flush_buffer;
  SPDR = data;
  while(!(SPSR & (1<<SPIF)));
  flush_buffer = SPDR;
}

uint8_t SPI_Receive(){
  while(!(SPSR & (1<<SPIF)));
  return(SPDR);
  }
uint8_t count;
char buffer[5];
uint8_t count2;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
SPI_Init();
count2 = 0;
}

void loop() {
  // put your main code here, to run repeatedly:
count = SPI_Receive();
Serial.println(uint8_t(count));
count = uint8_t(count)+100;
_delay_ms(500);
SPI_Write(count);
_delay_ms(500);
}
