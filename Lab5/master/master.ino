#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include <string.h>

void SPI_Init(){
  DDRB |= (1<<PB3)|(1<<PB5)|(1<<PB2);
  DDRB &= ~(1<<PB4);
  PORTB |= (1<<PB2);
  SPCR =(1<<SPE)|(1<<MSTR)|(1<<SPR0); //4AKA
  SPSR &= ~(1<<SPI2X);
}

void SPI_Write(uint8_t data){

  char flush_buffer;
  SPDR = data;
  while(!(SPSR & (1<<SPIF)));
  flush_buffer = SPDR;
}

uint8_t SPI_READ(){
  SPDR=0xFF;
  while(!(SPSR & (1<<SPIF)));
  return(SPDR);
  }
uint8_t count;
uint8_t count2;
char buffer[5];

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
SPI_Init();
PORTB &= ~ (1<<PB2);
_delay_ms(1000);
count=0;
}

void loop() {
  // put your main code here, to run repeatedly:
SPI_Write(count);
_delay_ms(500);
count2 = SPI_READ();
_delay_ms(500);
Serial.println(uint8_t(count2));
count=(count+1)%101;

}
