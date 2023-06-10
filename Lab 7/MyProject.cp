#line 1 "D:/CUFE24/3rd year/second term/Embedded Systems/Labs/Lab 7/MyProject.c"
#line 13 "D:/CUFE24/3rd year/second term/Embedded Systems/Labs/Lab 7/MyProject.c"
unsigned int period = 0;
void main() {



GPIO_Digital_Output(&GPIOE_BASE, _GPIO_PINMASK_14);


period = PWM_TIM1_Init(500);

PWM_TIM1_Set_Duty((100 / 100) * period, _PWM_NON_INVERTED, _PWM_CHANNEL4);

PWM_TIM1_Start(_PWM_CHANNEL4, &_GPIO_MODULE_TIM1_CH4_PE14);



while(1){}

}
