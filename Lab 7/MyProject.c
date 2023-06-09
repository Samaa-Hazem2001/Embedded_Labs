/*
Req #1
It is required to to generate a fixed non inverted 500 Hz PWM signal with 20% duty ratio
on PE14 and enable the Buzzer.
Hints:
Don�t forget to include the PWM library from library manager
To find out what timer and channel to work with you can use code assistant
Type _GPIO_MODULE_TIM
Press CTRL + SPACE
Search for PE14

*/
unsigned int period = 0;  // variable defenition must be at the beg. of the code
void main() {


// first we need to configure the GPIO pins
GPIO_Digital_Output(&GPIOE_BASE, _GPIO_PINMASK_14);


period = PWM_TIM1_Init(500); // initializes timer 1 in PWM mode with 500 Hz frequency

PWM_TIM1_Set_Duty((100 / 100) * period, _PWM_NON_INVERTED, _PWM_CHANNEL4);

PWM_TIM1_Start(_PWM_CHANNEL4, &_GPIO_MODULE_TIM1_CH4_PE14);

// To enable the Buzzer you need to push SW14.8 to ON position
// this will be done on the board itself
while(1){}

}