/*
**************************
* @file    display_lcd - sem bibliotecas
* @brief   LCD - print nome
**************************
* Date:     21/05/2026
* Author:   Caio Vinícius Girardi
* email:    caiogirardi10@gmail.com
* Project:  LCD
* Version:  1.0
**************************
*/

#define RS 12
#define EN 11

#define D4 5
#define D5 4
#define D6 3
#define D7 2

/*
**********************
* @name   pulseEnable
* @brief  Gera o pulso no pino Enable para o LCD executar o comando.
**********************
* @input: sem entrada
* @return: sem retorno
*/
void pulseEnable()
{
  digitalWrite(EN, LOW);
  delayMicroseconds(1);

  digitalWrite(EN, HIGH);
  delayMicroseconds(1);

  digitalWrite(EN, LOW);

  delayMicroseconds(100);
}

/*
**********************
* @name   sendNibble
* @brief  Envia 4 bits de dados para o display LCD.
**********************
* @input: data - valor de 4 bits a ser enviado.
* @return: sem retorno
*/
void sendNibble(byte data)
{
  digitalWrite(D4, bitRead(data,0));
  digitalWrite(D5, bitRead(data,1));
  digitalWrite(D6, bitRead(data,2));
  digitalWrite(D7, bitRead(data,3));

  pulseEnable();
}

/*
**********************
* @name   sendByte
* @brief  Envia um byte completo para o LCD.
**********************
* @input: 
*         data - byte a ser enviado.
*         rs   - define comando (LOW) ou caractere (HIGH).
* @return: sem retorno
*/
void sendByte(byte data, bool rs)
{
  digitalWrite(RS, rs);

  // envia parte alta
  sendNibble(data >> 4);

  // envia parte baixa
  sendNibble(data & 0x0F);

  delay(2);
}

/*
**********************
* @name   setup
* @brief  Configura os pinos e inicializa o display LCD.
**********************
* @input: sem entrada
* @return: sem retorno
*/
void setup()
{
  pinMode(RS, OUTPUT);
  pinMode(EN, OUTPUT);

  pinMode(D4, OUTPUT);
  pinMode(D5, OUTPUT);
  pinMode(D6, OUTPUT);
  pinMode(D7, OUTPUT);

  delay(50);

  sendNibble(0x03);
  delay(5);

  sendNibble(0x03);
  delay(5);

  sendNibble(0x03);
  delay(5);

  sendNibble(0x02);

  // Configura display
  sendByte(0x28, LOW);

  // Liga display
  sendByte(0x0C, LOW);

  // Move cursor
  sendByte(0x06, LOW);

  // Limpa display
  sendByte(0x01, LOW);

  delay(5);

  // Caio
  sendByte('C', HIGH);
  sendByte('a', HIGH);
  sendByte('i', HIGH);
  sendByte('o', HIGH);
}

void loop()
{

}
