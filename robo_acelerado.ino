
#include <SoftwareSerial.h>   //Inlcui a biblioteca SoftwareSerial.h

//necessario ligar um resistor do rx do bluetooth até o gnd e um outro resistor do rx do bluetooth até o pino que foi progrmado como rx

//ENA no pino 4
//IN1 no pino 5
//IN2 no pino 6
//IN1 no pino 7
//IN2 no pino 8
//ENB no pino 9

SoftwareSerial bluetooth(10,11); //Instância a biblioteca SoftwareSerial.h

//10 = Rx e 11 = Tx

void setup()
{
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  Serial.begin(9600);
  bluetooth.begin(9600);

 
}

void loop()
{
  
  char letra; //Variável char para armazenar o caractere recebido

  if(bluetooth.available()>0) //Se algo for recebido pela serial do módulo bluetooth
  {
      letra = bluetooth.read(); //Armazena o caractere recebido na variável letra
    
      if(letra == 'F') //Se o caractere recebido for a letra 'F'
      {
      //Move o carrinho para frente
        digitalWrite(5, HIGH); 
        digitalWrite(4, 255);  //Motor com rotação máxima (0-255)
        digitalWrite(6, LOW);
        digitalWrite(7, HIGH); //Motor B desligado
        digitalWrite(9, 255);  //Motor B desligado
        digitalWrite(8, LOW); //Motor B desligado
        
      //==================
      }
    
      else if (letra == 'B') //Se o caractere recebido for a letra 'B'
      {
      //Move o carrinho para trás
        digitalWrite(5, LOW); 
        digitalWrite(4, 255);  //Motor com rotação máxima (0-255)
        digitalWrite(6, HIGH);
        digitalWrite(7, LOW); //Motor B desligado
        digitalWrite(9, 250);  //Motor B desligado
        digitalWrite(8, HIGH); //Motor B desligado
        
      //==================
      }
    
      else if(letra == 'R') //Se o caractere recebido for a letra 'R'
      {
      //Move o carrinho para direita
        digitalWrite(5, HIGH); 
        digitalWrite(4, 255);  //Motor com rotação máxima (0-255)
        digitalWrite(6, LOW);
        digitalWrite(7, LOW); //Motor B desligado
        digitalWrite(9, 255);  //Motor B desligado
        digitalWrite(8, HIGH); //Motor B desligado
      
        //==================
      }
    
      else if (letra == 'L') //Se o caractere recebido for a letra 'L'
      { 
      //Move o carrinho para esquerda
        digitalWrite(5, LOW); 
        digitalWrite(4, 255);  //Motor com rotação máxima (0-255)
        digitalWrite(6, HIGH);
        digitalWrite(7, HIGH); //Motor B desligado
        digitalWrite(9, 255);  //Motor B desligado
        digitalWrite(8, LOW); //Motor B desligado
        //delay(3000);      
      //==================
      }
    
      else if(letra == 'S') //Se o caractere recebido for a letra 'S'
      {
      //Para o carrinho
        digitalWrite(5, LOW); 
        digitalWrite(4, 0);  //Motor com rotação máxima (0-255)
        digitalWrite(6, LOW);
        digitalWrite(7, LOW); //Motor B desligado
        digitalWrite(9, 0);  //Motor B desligado
        digitalWrite(8, LOW); //Motor B desligado
        //delay(3000);      
      //==================
      }
  }
}  
    
     
 
