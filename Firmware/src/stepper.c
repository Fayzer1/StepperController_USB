#include "stm32f1xx.h"

void init_stepper_ports(void)
{
    RCC->APB2ENR |= (RCC_APB2ENR_IOPBEN | RCC_APB2ENR_IOPAEN); //Enable Clocking Port A,B
    GPIOA->CRH &= ~(GPIO_CRH_CNF9 | GPIO_CRH_MODE9);   
    GPIOA->CRH &= ~(GPIO_CRH_CNF10 | GPIO_CRH_MODE10);
    GPIOA->CRH |= GPIO_CRH_MODE9;
    GPIOA->CRH |= GPIO_CRH_MODE10;

    GPIOB->CRH &= ~(GPIO_CRH_CNF14 | GPIO_CRH_MODE14); 
    GPIOB->CRH &= ~(GPIO_CRH_CNF15 | GPIO_CRH_MODE15);
    GPIOB->CRH |= GPIO_CRH_MODE14; 
    GPIOB->CRH |= GPIO_CRH_MODE15;

}

void init_tim(void)
{
    RCC->APB2ENR |= (
        RCC_APB2ENR_TIM1EN | 
        RCC_APB2ENR_IOPAEN | 
        RCC_APB2ENR_AFIOEN); //Enable RCC Timer and Port A
    // [1011]
    GPIOA->CRH &= ~(GPIO_CRH_MODE8 | GPIO_CRH_CNF8); //Reset to 0000;
    GPIOA->CRH |= GPIO_CRH_MODE8_1; //Output 2MHz
    GPIOA->CRH |= GPIO_CRH_CNF8_1;//Alternative Func Push-Pull

    //Set freq of PWM (f_APB2ENR = 64MHz) -> f_pwm = 100Hz
    TIM1->PSC = 7200-1;
    TIM1->ARR = 100-1;
    TIM1->CCR1 = 50;
    
    //Configure PWM
    TIM1->CCMR1 &= ~TIM_CCMR1_OC1M; 
    TIM1->CCMR1 |= TIM_CCMR1_OC1M_2 | TIM_CCMR1_OC1M_1; //110 - PWM mode 1
    
    TIM1->CCMR1 |= TIM_CCMR1_OC1PE; //Enable pre-load register CCR1
    TIM1->CR1 |= TIM_CR1_ARPE; //Enable ARR reg pre-load
    TIM1->CCER &= ~TIM_CCER_CC1P; //Switch Active High
    TIM1->CCER |= TIM_CCER_CC1E; //Enable output pwm to pin
    TIM1->BDTR |= TIM_BDTR_MOE; //Only for advanced timers (Main Output Enable for TIM1)

    TIM1->EGR |= TIM_EGR_UG; // Generate Update Event for 
                             //Update shadows regs: PSC ARR and CCR
    TIM1->SR &= ~ TIM_SR_UIF; // reset uif after UG;
    //TIM1->CR1 |= TIM_CR1_CEN; //Enable timer, make this in main
}

void init_t(void)
{
	RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;
	TIM3->PSC = 36000-1;
	TIM3->CR1 |= TIM_CR1_URS;
	TIM3->EGR |= TIM_EGR_UG;
	TIM3->SR &= ~ TIM_SR_UIF;
	TIM3->CR1 |= TIM_CR1_OPM;
}

void delay(uint16_t ms)
{
	TIM3->CNT = 0;
	TIM3->ARR = (ms * 2) - 1;
	TIM3->CR1 |= TIM_CR1_CEN;
	while (!(TIM3->SR & TIM_SR_UIF));
	TIM3->EGR |=  TIM_EGR_UG;
	TIM3->SR &= ~ TIM_SR_UIF;
}


// int main(void)
// {
//     // Enable Port B RCC
//     initClk();
//     init_tim();
//     init_t();
//     init_stepper_ports();
//     //Init Stepper Controller
//     GPIOB->BSRR = GPIO_BSRR_BR14; //Disable Output Stepper Controller
//     GPIOA->BSRR = GPIO_BSRR_BR9; // HALF/FULL->[1]
//     GPIOB->BSRR = GPIO_BSRR_BS15; // Co-Clock Watch [1]
//     // Reset to home position
//     GPIOA->BSRR = GPIO_BSRR_BR10; 
//     delay(100);
//     GPIOA->BSRR = GPIO_BSRR_BS10; 

//     GPIOB->BSRR = GPIO_BSRR_BS14; //Enable Output Stepper Controller
//     TIM1->CR1 |= TIM_CR1_CEN;    // Enable Clock for Stpepper

//      while (1)
//     {
//     }
// }