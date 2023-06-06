int i;
void main() {

     GPIO_Digital_Output(&GPIOD_BASE,  _GPIO_PINMASK_ALL);
     GPIO_Digital_Output(&GPIOE_BASE, _GPIO_PINMASK_ALL);
	 
      GPIOD_ODR = 0;
	  GPIOE_ODR = 0;
	 
     while(1)
     {

	  for ( i=0 ; i<4; i++){
      
	  GPIOD_ODR |= (10001<<i)|(10001<<(i+8));
      GPIOE_ODR |= (10001<<(i+8));
	  Delay_ms(100);
	
	}
	for (int i=0 ; i<4; i++){
      
	  GPIOD_ODR &= (01110<<i)&(01110<<(i+8));
      GPIOE_ODR |= (01110<<(i+8));
	  Delay_ms(100);
	
	}
     }

}