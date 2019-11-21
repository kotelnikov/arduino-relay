/*
    Relay.cpp - Easy management of the Relays on arduino based projects.
    Copyright (c) Alexey A. Kotelnikov (Kotelejo). All rights reserved.
  
    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 3.0 of the License, or (at your option) any later version.
    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/
#include "Relay.h"

Relay::Relay(uint8_t _pin, uint8_t _initial) :pinNumber(_pin), initialState(_initial) {
    pinMode(pinNumber, OUTPUT);
    digitalWrite(pinNumber, initialState == HIGH ? HIGH : LOW);
    currentState = false;
}
void Relay::timeout(time_t ms) {
    volatile time_t timeout = millis() + ms;
    while (millis() < timeout) {};
}
void Relay::switchOn() {
    digitalWrite(pinNumber, initialState == HIGH ? LOW : HIGH);
    currentState = true;
}
void Relay::switchOff() {
    digitalWrite(pinNumber, initialState == HIGH ? HIGH : LOW);
    currentState = false;
}
void Relay::inverse() {
    currentState ? switchOff() : switchOn();
}
void Relay::touch(time_t ms) {
    inverse();
    timeout(ms);
    inverse();
}
