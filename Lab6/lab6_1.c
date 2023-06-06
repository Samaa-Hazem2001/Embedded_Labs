void main() {

	GPIO_Digital_Input(&GPIOB_BASE, _GPIO_PINMASK_0 | _GPIO_PINMASK_1);
    GPIO_Digital_Output(&GPIOD_BASE, _GPIO_PINMASK_0 | _GPIO_PINMASK_1 | _GPIO_PINMASK_2 | _GPIO_PINMASK_3);
	GPIOD_ODR = 0xFFFF;
    GPIOE_ODR = 0xFFFF;
    while(1)
     {

      Delay_ms(500);
      GPIOD_ODR = ~GPIOD_ODR;
	  GPIOE_ODR = ~GPIOE_ODR;
     }

}