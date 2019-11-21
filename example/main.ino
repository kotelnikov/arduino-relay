#include <Arduino.h>
#include "Relay.h"

#define RELAY1 2  // Define Ralay Pin No / Номер пина Реле

/*
Initialising of the Relay class
Relay activates by givig HIGH level to the pin
It means, that switched off state -> LOW
When initializing 1 param - Pin Nomber, second - swiched off state
Initialising sets Relay pin to the swiched off state

Инициализируем класс Relay
Реле управляемое по высокому уровню, а это значит,  
что в выключеном состоянии логический уровень - 0
При инициализации пин встает состояние 0 (LOW)
Первым параметр - ПИН, второй состояние когда выключено (LOW)
Инициализация устанавливает пин реле в состояние выключено
*/
Relay relay1(RELAY1, LOW);

void setup() {
  Serial.begin(9600);
}

void loop() {
  // Relay will be swiched on (HIGH pin state)
  // Реле включится (состояние пина HIGH)
  relay1.switchOn();
  delay(2000);

  // Relay will be swiched on (LOW pin state)
  // Реле включится (состояние пина LOW)
  relay1.switchOff();
  delay(2000);
  
  // Relay will be swiched to the opposite state
  // Реле1 переключится в противоположное состояние 
  relay1.inverse();
  delay(2000);

  // Relay will be swiched to the opposite state and then
  // after 1000 millseconds returns to initial state
  // Реле переключится в противоположное от текущего состояние 
  // на 1000 на тысячу миллискекунд, а затем вернется в исходное состояние
  relay1.touch(1000);  
  delay(2000);
    

  // The current state will be pushed to the variable "state"
  // This is not a logical state of the pin, it is exactly the state of relay
  // В переменную state запишется текущее состояние Реле 1 
  // Это не логическое состояние пина, это именно состояние реле
  bool state = relay1.getState();

  // Write variable "state" to the console
  // Выведем переменную state в консоль
  Serial.print("Состояние реле 1: ");
  Serial.println(state);
  delay(2000);
}
