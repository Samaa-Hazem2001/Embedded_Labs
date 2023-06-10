/*
req #2
It is required to fade PE14 LED ( and hence the Buzzer). 
Use timer 1 to output a 3.8 kHz PWM signal with a duty ration that goes from 0 to 100% 
then from 100% to zero and so on.
Hint:
Use Delay_us(time_in_microseconds) in your loop.

*/

void main(){
unsigned int period = 0;  // variable defenition must be at the beg. of the code
int duty = 0;

// first we need to configure the GPIO pins
GPIO_Digital_Output(&GPIOE_BASE, _GPIO_PINMASK_14);

period = PWM_TIM1_Init(3800); // initializes timer 1 in PWM mode with 3.8 kHz frequency

while(1){
PWM_TIM1_Set_Duty(duty, _PWM_NON_INVERTED, _PWM_CHANNEL4);

PWM_TIM1_Start(_PWM_CHANNEL4, &_GPIO_MODULE_TIM1_CH4_PE14);
if(duty == period) {duty = -1;}
duty = duty + 1;
Delay_us(50);  // 50 ms or what ?????
}

// enable the buzzer from the board

}