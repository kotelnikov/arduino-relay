/*
    Relay.h - Easy management of the Relays on arduino based projects.
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
#ifndef Relay_h
#define Relay_h
#endif
#include <Arduino.h>

class Relay{
    typedef uint32_t time_t;

    // PRIVATE VARIABLES
    private:
        const uint8_t pinNumber;
        const uint8_t initialState;
        bool currentState;

    // PRIVATE FUNCTIONS
    private:
        void timeout(time_t _timeout);

    //PUBLIC FUNCTIONS
    public:
        Relay(uint8_t _pinNumber, uint8_t _defaultState = LOW);
        bool getState() { return currentState; };
        void switchOn();
        void switchOff();
        void inverse();
        void touch(time_t ms = 100);
    };
