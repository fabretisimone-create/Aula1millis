// #include <Arduino.h>

// #define pinLed 2

// bool estadoLed = 0;
// unsigned long tempoAnterior = 0; //hora que o bolo entrou no forno
// unsigned long intervalo = 500; // tempo que o bolo eta no forno exemplo 30 minutos

// void setup() {
//   pinMode(pinLed, OUTPUT);
// }

// void loop() {
//   unsigned long tempoAtual = millis(); //fica olhando o nquanto o bolo esta no forno

//   if (tempoAtual - tempoAnterior >= intervalo)
//   {
//     estadoLed = !estadoLed;

//     tempoAnterior = tempoAtual;
//   }

//   digitalWrite(pinLed, estadoLed);
// }

// millis
// Exercício 1
// Crie um programa que pisque 2 LEDS de forma alternada

// #include <Arduino.h>

// #define pinLed 2
// #define pinLed2 18

// bool estadoLed = 1;
// bool estadoLed2 = 0;
// unsigned long tempoAnterior = 0;
// unsigned long intervalo = 500;

// void setup() {
//   pinMode(pinLed, OUTPUT);
//   pinMode(pinLed2, OUTPUT);
// }

// void loop() {
//   unsigned long tempoAtual = millis();

//   if (tempoAtual - tempoAnterior >= intervalo)
//   {
//     estadoLed = !estadoLed;
//     estadoLed2 = !estadoLed2;

//     tempoAnterior = tempoAtual;
//   }

//   digitalWrite(pinLed, estadoLed);
//   digitalWrite(pinLed2, estadoLed2);
// }

// Exercício 2
// Crie um programa que pisque 2 LEDS
// LED 1 deve piscar a cada 500 ms
// LED 2 deve piscar a cad 2s

// #include <Arduino.h>

// #define pinLed 2
// #define pinLed2 18

// bool estadoLed = 1;
// bool estadoLed2 = 0;
// unsigned long tempoAnterior = 0;
// unsigned long intervalo = 500;
// unsigned long tempoAnterior2 = 1;
// unsigned long intervalo2 = 2000;

// void setup() {
//   pinMode(pinLed, OUTPUT);
//   pinMode(pinLed2, OUTPUT);
// }

// void loop() {
//   unsigned long tempoAtual = millis();

//   if (tempoAtual - tempoAnterior >= intervalo)
//   {
//     estadoLed = !estadoLed;

//     tempoAnterior = tempoAtual;
//   }

//   if (tempoAtual - tempoAnterior2 >= intervalo2)
//   {

//     estadoLed2 = !estadoLed2;

//     tempoAnterior2 = tempoAtual;
//   }

//   digitalWrite(pinLed, estadoLed);
//   digitalWrite(pinLed2, estadoLed2);
// }

// Exercício 3
// Crie um programa que mostra uma mensagem no Serial a cada 2s

// #include <Arduino.h>

//  unsigned long tempoAnterior = 0;
//  unsigned long intervalo = 2000;

//  void setup() {

//   Serial.begin(9600);
//  }

//  void loop() {
//   unsigned long tempoAtual = millis();

//    if (tempoAtual - tempoAnterior >= intervalo)
//    {

//      tempoAnterior = tempoAtual;
//      Serial.println("2s");
//   }

// }

// Exercício 4
// Crie um programa que ao pressionar um botão um acenda
//  e apague altomaticamente após 3s

//  #include <Arduino.h>
//  #include <Bounce2.h>

//  #define LED 2
//  #define pinBotao 32

//  Bounce bounce = Bounce();

//  bool estadoLed = false;
//  bool estadoBotao = false;

//  unsigned long tempoAnterior = 0;
//  unsigned long intervalo = 3000;

//    void setup() {
//      pinMode(LED, OUTPUT);
//      bounce.attach(pinBotao, INPUT_PULLUP);
//      digitalWrite(LED, LOW);
//      Serial.begin(9600);
//      }

// void loop() {
//    bounce.update();
//    unsigned long tempoAtual = millis();

//    if (bounce.fell())
//    {
//      estadoLed = true;
//      tempoAnterior = millis();

//      digitalWrite(LED, HIGH);

//   }
//    if (estadoLed){

//     if (tempoAtual - tempoAnterior >= intervalo){
//     estadoLed = false;
//     digitalWrite(LED, LOW);
//    }
//    }
//   }

// Exercício 5
// Crie um semaforo

#include <Arduino.h>

#define pinVermelho 18
#define pinAmarelo 16
#define pinVerde 2
#define tempoVerde 4000
#define tempoAmarelo 2000
#define tempoVermelho 6000
int estadoSemaforo = 0;

unsigned long tempoAnterior = 0;

void setup()
{

  pinMode(pinVerde, OUTPUT);
  pinMode(pinAmarelo, OUTPUT);
  pinMode(pinVermelho, OUTPUT);
  Serial.begin(115200);
}

void loop()
{
  unsigned long tempoAtual = millis();


  if (estadoSemaforo == 0 && tempoAtual - tempoAnterior >= tempoVerde)
  {
    estadoSemaforo = 1;
    tempoAnterior = tempoAtual;
  }
 
  if (estadoSemaforo == 1 && tempoAtual - tempoAnterior >= tempoAmarelo)
  {
    estadoSemaforo = 2;
    tempoAnterior = tempoAtual;
  }
 
  if (estadoSemaforo == 2 && tempoAtual - tempoAnterior >= tempoVermelho)
  {
    estadoSemaforo = 0;
    tempoAnterior = tempoAtual;
  }




    if (estadoSemaforo == 0)
  {

    digitalWrite(pinVerde, HIGH);
    digitalWrite(pinAmarelo, LOW);
    digitalWrite(pinVermelho, LOW);
  } else if (estadoSemaforo == 2)
  {
    digitalWrite(pinVerde, LOW);
    digitalWrite(pinAmarelo, LOW);
    digitalWrite(pinVermelho, HIGH);
  } else if (estadoSemaforo == 1)
  {
    digitalWrite(pinVerde, LOW);
    digitalWrite(pinAmarelo, HIGH);
    digitalWrite(pinVermelho, LOW);
  }
}
