

# Atividade 3 - PWM para LED e Motor

## 1. Hello World Zephyr (GPIO Básico)
Fazendo uso do código de exemplo, foi possível implementar o led piscando, primeiramente com delay intervalo de 1 segundo e depois de 2 segundos.

### 1.1 Pisca Led de 1 segundo:
<img width="246" height="438" alt="Adobe Express - PiscaLed1segundo" src="https://github.com/user-attachments/assets/893e675f-21ba-41f0-a3f1-58aab73580ae" />
 
### 1.2 Pisca Led de 2 segundos: 
<img width="246" height="438" alt="PiscaLed2segundos" src="https://github.com/user-attachments/assets/9babc42b-d052-4a87-a412-25d76a83671d" />

## 2. Integração de Biblioteca PWM (pwm_z42)
A partir do código de exemplo, obteve-se a cor laranja com o uso do PWM (misturando vermelho e verde). Após isso, adicionei mudanças dentro do loop infinito para que o led piscasse a cada 1 segundo.

### 2.1 Led Laranja Fixo:
<img width="246" height="438" alt="LedLaranjaFixo" src="https://github.com/user-attachments/assets/3aacd109-7eaa-4c59-be9e-05aec1300b8d" />


### 2.2 Pisca Led Laranja:
<img width="246" height="438" alt="PiscaLedLaranja" src="https://github.com/user-attachments/assets/c911d91a-00c0-4178-ba6c-d3b190698441" />


## 3. Validação de Hardware: Ponte H
Nesta etapa, não foi necessário realizar nenhuma mudança no código, apenas um teste ligando a ponte H diretamente no power bank para assegurar o funcionamento da fonte de tensão e dos motores do carrinho. Segue abaixo vídeo mostrando o teste.
<img width="246" height="438" alt="TesteDeHardware" src="https://github.com/user-attachments/assets/6cd66ff5-fda7-46fe-9c26-debbf270d4e9" />

   
## 4. Integração Final (Controle Digital)
Foi a etapa que exigiu maior incremento do código. Para começar, foi necessário configurar 6 pinos para saída digital, que controlam o movimento do carrinho (no meu caso foram PTB0, PTB1, PTA4 e PTA5). Além disso, também é necessária a configuração de dois pinos com a função de PWM, e acabei usando PTB2 e PTB3 como sugerido no passo a passo. Para exemplificar de maneira bem clara, decidi usar uma máquina de estados que mudava a velocidade do motor, começando com 25% da potência, depois indo para 50% e finalmente chegando em 100% no último estágio. De início, fiz o teste com 1 motor, depois sincronizando os dois motores para o item 4.2. Os vídeos dos testes estão apresentados abaixo.

### 4.1 Teste Motor Único:
<img width="246" height="438" alt="TesteMotorÚnico" src="https://github.com/user-attachments/assets/72784a69-d3c4-4d54-8b32-c0f73302f7ea" />

### 4.2 Teste Bimotor:
<img width="246" height="438" alt="TesteBimotor" src="https://github.com/user-attachments/assets/a076bb68-ea89-4f7e-ad89-2b8d8391e106" />


