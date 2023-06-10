/*
req #3
It is required to use timer 4 to generate 4 kHz PWM signals. 
Use the 4 channels of timer 4 and map them to PD12, PD13, PD14, PD15. 
The LEDs should fade from OFF to ON sequentially then from ON to OFF in the same order and so on.


*/

void main(){
unsigned int period = 0;  // variable defenition must be at the beg. of the code
int duty = 0;

// first we need to configure the GPIO pins
GPIO_Digital_Output(&GPIOD_BASE, _GPIO_PINMASK_12 | _GPIO_PINMASK_13 | _GPIO_PINMASK_14 | _GPIO_PINMASK_15);

period = PWM_TIM4_Init(4000); // initializes timer 4 in PWM mode with 4 kHz frequency

while(1){
PWM_TIM4_Set_Duty(duty, _PWM_NON_INVERTED, _PWM_CHANNEL1);
PWM_TIM4_Set_Duty(duty, _PWM_NON_INVERTED, _PWM_CHANNEL2);
PWM_TIM4_Set_Duty(duty, _PWM_NON_INVERTED, _PWM_CHANNEL3);
PWM_TIM4_Set_Duty(duty, _PWM_NON_INVERTED, _PWM_CHANNEL4);

PWM_TIM4_Start(_PWM_CHANNEL1, &_GPIO_MODULE_TIM4_CH1_PD12);
PWM_TIM4_Start(_PWM_CHANNEL2, &_GPIO_MODULE_TIM4_CH2_PD13);
PWM_TIM4_Start(_PWM_CHANNEL3, &_GPIO_MODULE_TIM4_CH3_PD14);
PWM_TIM4_Start(_PWM_CHANNEL4, &_GPIO_MODULE_TIM4_CH4_PD15);

if(duty == 0) {duty = period;}
else {duty = 0;}
Delay_us(50);  // 50 ms or what ?????
}
}



