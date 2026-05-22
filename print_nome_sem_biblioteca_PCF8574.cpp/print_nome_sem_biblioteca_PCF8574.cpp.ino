/*
**************************
* @file    print_nome_sem_biblioteca_PCF8574
* @brief   Controle de LCD 16x2 utilizando
*          PCF8574 sem bibliotecas.
**************************
* Date:     21/05/2026
* Author:   Caio Vinícius Girardi
* email:    caiogirardi10@gmail.com
* Project:  LCD + PCF8574
* Version:  1.0
**************************
*/

#include <Wire.h>

#define PCF8574_ADDR 0x20

byte dataLCD = 0;

/*
**********************
* @name   writePCF
* @brief  Envia um byte para o PCF8574
*         através da comunicação I2C.
**********************
* @input:
*         data - byte enviado ao PCF.
*
* @return:
*         sem retorno.
**********************
*/
void writePCF(byte data)
{
  Wire.beginTransmission(PCF8574_ADDR);

  Wire.write(data);

  Wire.endTransmission();
}

/*
**********************
* @name   pulseEnable
* @brief  Gera o pulso de Enable necessário
*         para o LCD processar os dados.
**********************
* @input:
*         sem entrada.
*
* @return:
*         sem retorno.
**********************
*/
void pulseEnable()
{
  bitSet(dataLCD, 5);

  writePCF(dataLCD);

  delayMicroseconds(1);

  bitClear(dataLCD, 5);

  writePCF(dataLCD);

  delayMicroseconds(100);
}

/*
**********************
* @name   sendNibble
* @brief  Envia 4 bits para o display LCD
*         através do PCF8574.
**********************
* @input:
*         nibble - valor de 4 bits enviado.
*
* @return:
*         sem retorno.
**********************
*/
void sendNibble(byte nibble)
{
  // limpa P0-P3
  dataLCD &= 0xF0;

  // coloca nibble em P0-P3
  dataLCD |= (nibble & 0x0F);

  writePCF(dataLCD);

  pulseEnable();
}

/*
**********************
* @name   sendByte
* @brief  Envia um byte completo ao LCD,
*         dividindo em dois nibbles.
**********************
* @input:
*         value - byte enviado.
*         rs    - define comando (LOW)
*                 ou caractere (HIGH).
*
* @return:
*         sem retorno.
**********************
*/
void sendByte(byte value, bool rs)
{
  bitWrite(dataLCD, 4, rs);

  sendNibble(value >> 4);

  sendNibble(value & 0x0F);

  delay(2);
}

/*
**********************
* @name   command
* @brief  Envia um comando ao display LCD.
**********************
* @input:
*         value - comando enviado.
*
* @return:
*         sem retorno.
**********************
*/
void command(byte value)
{
  sendByte(value, LOW);
}

/*
**********************
* @name   writeChar
* @brief  Envia um caractere ASCII ao LCD.
**********************
* @input:
*         value - caractere enviado.
*
* @return:
*         sem retorno.
**********************
*/
void writeChar(char value)
{
  sendByte(value, HIGH);
}

/*
**********************
* @name   setup
* @brief  Inicializa comunicação I2C,
*         configura e inicializa o LCD.
**********************
* @input:
*         sem entrada.
*
* @return:
*         sem retorno.
**********************
*/
void setup()
{
  Wire.begin();

  delay(50);

  sendNibble(0x03);
  delay(5);

  sendNibble(0x03);
  delay(5);

  sendNibble(0x03);
  delay(5);

  sendNibble(0x02);
  delay(5);

  // modo 4 bits / 2 linhas
  command(0x28);

  // display ON
  command(0x0C);

  // incremento automático cursor
  command(0x06);

  // limpa display
  command(0x01);

  delay(5);

  // escreve nome
  writeChar('C');
  writeChar('a');
  writeChar('i');
  writeChar('o');
}

void loop()
{

}
