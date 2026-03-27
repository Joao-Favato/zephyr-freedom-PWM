#include <stdio.h>
#define SIM_SCGC5 (*((volatile unsigned int*)0x40048038))
#define PORTB_PCR19 (*((volatile unsigned int*)0x4004A04C)) 
#define GPIOB_PDDR (*((volatile unsigned int*)0x400FF054))
#define GPIOB_PTOR (*((volatile unsigned int*)0x400FF04C)) 
#define GPIOB_PSOR (*((volatile unsigned int*)0x400FF044)) 
#define GPIOB_PCOR (*((volatile unsigned int*)0x400FF048)) 

void delayMs (int n) {
    vola tile int i;
    volatile int j;
    for (i = 0; i < n; i++)
    for (j = 0; j < 7000; j++) {}
}
int main()
{
    ////// Habilitar clock da porta B;
    SIM_SCGC5 |= 1 << 10;
    ///// Configurar Pino 19 (Pin Control Register)
    PORTB_PCR19 |= 1 << 8;
    ///// Direção do Pino
    GPIOB_PDDR |= 1 << 19;
    while (1){
        ///// Habilitar saída
	    GPIOB_PCOR = 1 << 19;
        ///// Função de espera
        delayMs(1000);
        ///// Desabilitar saída
	    GPIOB_PSOR = 1 << 19;    
	    ///// Função de espera
        delayMs(1000);
    }
    
}