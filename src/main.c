#include <zephyr/kernel.h>             // Funções básicas do Zephyr (ex: k_msleep, k_thread, etc.)
#include <zephyr/device.h>             // API para obter e utilizar dispositivos do sistema
#include <zephyr/drivers/gpio.h>       // API para controle de pinos de entrada/saída (GPIO)
#include <pwm_z42.h>                // Biblioteca personalizada com funções de controle do TPM (Timer/PWM Module)
const struct device *gpio_b = DEVICE_DT_GET(DT_NODELABEL(gpiob));
const struct device *gpio_a = DEVICE_DT_GET(DT_NODELABEL(gpioa));
// Define o valor do registrador MOD do TPM para configurar o período do PWM
#define TPM_MODULE 1000         // Define a frequência do PWM fpwm = (TPM_CLK / (TPM_MODULE * PS))
// Valores de duty cycle correspondentes a diferentes larguras de pulso
uint16_t duty_50  = TPM_MODULE/2;       // 50% de duty cycle (meio brilho)
uint16_t duty_100  = TPM_MODULE;       // 100% de duty cycle
uint16_t duty_25  = TPM_MODULE/4;       // 25% de duty cycle


int main(void)
{
    // Inicializa o módulo TPM2 com:
    // - base do TPMx
    // - fonte de clock PLL/FLL (TPM_CLK)
    // - valor do registrador MOD
    // - tipo de clock (TPM_CLK)
    // - prescaler de 1 a 128 (PS)
    // - modo de operação EDGE_PWM
    pwm_tpm_Init(TPM2, TPM_PLLFLL, TPM_MODULE, TPM_CLK, PS_128, EDGE_PWM);


    // Inicializa o canal do TPM2 para gerar sinal PWM nas portas GPIOB_2 e GPIOB_3
    pwm_tpm_Ch_Init(TPM2, 0, TPM_PWM_H, GPIOB, 18);
    pwm_tpm_Ch_Init(TPM2, 1, TPM_PWM_H, GPIOB, 19);


   
    // Loop infinito
    for (;;)
    {
        pwm_tpm_CnV(TPM2, 0, duty_25);
        pwm_tpm_CnV(TPM2, 1, duty_50);
       k_sleep(K_MSEC(1000));
       pwm_tpm_CnV(TPM2, 0, duty_100);
       pwm_tpm_CnV(TPM2, 1, duty_100);
       k_sleep(K_MSEC(1000));
    }
    return 0;
}
    


