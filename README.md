 Atividade 3 - PWM para LED e Motor
 =====================================

1. Hello World Zephyr (GPIO Básico)
Fazendo uso do código de exemplo, foi possível implementar o led piscando, primeiramente com delay intervalo de 1 segundo e depois de 2 segundos.
1.1 PiscaLed1segundo.mp4
1.2 PiscaLed2segundos.mp4

2. Integração de Biblioteca PWM (pwm_z42)
A partir do código de exemplo, obteve-se a cor laranja com o uso do PWM (misturando vermelho e verde). Após isso, adicionei mudanças dentro do loop infinito para que o led piscasse a cada 1 segundo.
2.1 LedLaranjaFixo.mp4
2.2 PiscaLedLaranja.mp4

3. Validação de Hardware: Ponte H
Nesta etapa, não foi necessário realizar nenhuma mudança no código, apenas um teste ligando a ponte H diretamente no power bank para assegurar o funcionamento da fonte de tensão e dos motores do carrinho. Segue abaixo vídeo mostrando o teste.
TesteDeHardware.mp4

4. Integração Final (Controle Digital)
Foi a etapa que exigiu maior incremento do código. Para começar, foi necessário configurar 6 pinos para saída digital, que controlam o movimento do carrinho (no meu caso foram PTB0, PTB1, PTA4 e PTA5). Além disso, também é necessária a configuração de dois pinos com a função de PWM, e acabei usando PTB2 e PTB3 como sugerido no passo a passo. Para exemplificar de maneira bem clara, decidi usar uma máquina de estados que mudava a velocidade do motor, começando com 25% da potência, depois indo para 50% e finalmente chegando em 100% no último estágio. De início, fiz o teste com 1 motor, depois sincronizando os dois motores para o item 4.2. Os vídeos dos testes estão apresentados abaixo.
4.1 TesteMotorÚnico.mp4
4.2 TesteBimotor.mp4
