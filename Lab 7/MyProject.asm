_main:
;MyProject.c,14 :: 		void main() {
;MyProject.c,18 :: 		GPIO_Digital_Output(&GPIOE_BASE, _GPIO_PINMASK_14);
MOVW	R1, #16384
MOVW	R0, #lo_addr(GPIOE_BASE+0)
MOVT	R0, #hi_addr(GPIOE_BASE+0)
BL	_GPIO_Digital_Output+0
;MyProject.c,21 :: 		period = PWM_TIM1_Init(500); // initializes timer 1 in PWM mode with 500 Hz frequency
MOVW	R0, #500
BL	_PWM_TIM1_Init+0
MOVW	R1, #lo_addr(_period+0)
MOVT	R1, #hi_addr(_period+0)
STRH	R0, [R1, #0]
;MyProject.c,23 :: 		PWM_TIM1_Set_Duty((100 / 100) * period, _PWM_NON_INVERTED, _PWM_CHANNEL4);
MOVS	R2, #3
MOVS	R1, #0
BL	_PWM_TIM1_Set_Duty+0
;MyProject.c,25 :: 		PWM_TIM1_Start(_PWM_CHANNEL4, &_GPIO_MODULE_TIM1_CH4_PE14);
MOVW	R1, #lo_addr(__GPIO_MODULE_TIM1_CH4_PE14+0)
MOVT	R1, #hi_addr(__GPIO_MODULE_TIM1_CH4_PE14+0)
MOVS	R0, #3
BL	_PWM_TIM1_Start+0
;MyProject.c,29 :: 		while(1){}
L_main0:
IT	AL
BAL	L_main0
;MyProject.c,31 :: 		}
L_end_main:
L__main_end_loop:
B	L__main_end_loop
; end of _main
