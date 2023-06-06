int toggle;
int toggle2;
void main() {

     GPIO_Digital_Output(&GPIOD_BASE,  _GPIO_PINMASK_ALL);
     GPIO_Digital_Output(&GPIOE_BASE, _GPIO_PINMASK_ALL);
	 GPIOD_ODR = 0;
	 toggle1 = 1;
	 toggle2 = 1;
     while(1)
     {
		 if(Button(&GPIOB_IDR, 0, 300, 1) && GPIOD_ODR != 15)
		 {
			 if(Button(&GPIOB_IDR, 0, 300, 1) && GPIOD_ODR != 15 && toggle1)
			 {
				GPIOD_ODR += 1;
				toggle1 = 0;
			 }
		 }
		 else 
		 {
			toggle1 = 0;
		 }
		 if(Button(&GPIOB_IDR, 1, 300, 1) && GPIOD_ODR != 0)
		 {
			 if(Button(&GPIOB_IDR, 1, 300, 1) && GPIOD_ODR != 0 && toggle2)
			 {
				GPIOD_ODR -= 1;
				toggle2 = 0;
			 }
		 }
		 else 
		 {
			toggle2 = 0;
		 }
     }

}