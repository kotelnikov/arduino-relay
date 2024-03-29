# Библиотека Relay

Библиотека реализующее простое управление реле или иными устройствами работающими по схожему принципу
в проектах построенных с использованием библиотек Ардуино (Arduino, ESP8266, ESP32 and other). 
Класс реле реализует простое управление состоянием реле и хранение его состояния.

## Как установить:

- **Вариант 1:** Из каталога "src" данного репозитория скопировать файлы Relay.h, Relay.cpp в папку своего проекта.
- **Вариант 2:** Создать папку Relay в каталоге, в котором храняться библиотеки Arduino, перенести 
  содержимое данного репозитория во вновь созданную папку.

## Как использовать:
   В файле скетча подключить библиотеку:
   ```cpp
   #include "Relay.h" // Если библиотека скопирована в папку скетча (первый вариант установки)
   #include <Relay.h> // Если библиотека установлена в каталг библиотек Arduino (второй вариант установки)
   ```
 
 В файле скетча инициализировать экземпляр класса Relay:
   ```cpp
   Relay relay1(2, LOW);
   // Где: первый аргумент - номер пина микроконтроллера
   //      второй аргумент - состояние пина, когда реле в выключенно (LOW или HIGH)
   // !!! При инициализации реле автоматически переводится в режим выключено !!!
   // Для того, чтобы relay1 был виден во всем скетче инициализировать экземпляр следует
   // вне функций вначале скетча, но после подключения библиотек и директив #define
   ```
 
 В файле скетча, в необходимом месте, можно использовать следующие методы:
 ```cpp
  relay1.switchOn();  // Реле включится
  
  relay1.switchOff(); // Реле выключится
  
  relay1.inverse();   // Реле изменит состояние на противоположное
  
  relay1.touch(1000); // Реле изменит состояние на противоположное на 1000мс (1сек)
  
  bool relay_state = relay1.getState() // В переменную relay_state будет записано текущее состояние реле
  ```
  В папке репозитория "examples" есть пример простого скеча.
