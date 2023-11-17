/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"
#define periodo 1000


#define WAIT_TIME_MS 5 
PwmOut led1(D5); //Salida PWM concentada el el LED, Mirar si el pin es compatible con PWM
AnalogIn pot(A0); //Potenciometro conectado en la entrada analogica A0



int main()
{

    float valorPotFloat;
    uint16_t valorPotUInt;
    
    printf("This is the bare metal blinky example running on Mbed OS %d.%d.%d.\n", MBED_MAJOR_VERSION, MBED_MINOR_VERSION, MBED_PATCH_VERSION);
    led1.period_us(periodo); // En este cajo elijo establecer el periodo en microsegundos.
    led1.pulsewidth_us(0); //Comienzo con un duty 0


    while (true)
    {
        valorPotFloat=pot.read(); //Este metodo da un valor entre 0 y 1
        led1.pulsewidth_us(valorPotFloat*1000); // calculo el valor de microsegundos entre 0 y 1000 
        thread_sleep_for(WAIT_TIME_MS);
        
        //Lo mismo de otra forma
        valorPotUInt=pot.read_u16(); //Este metodo da un valor entre 0 y (2^16)-1
        float duty=valorPotUInt/65536.0; // El ciclo de trabajo es un valor entre 0 y 1
        led1.write(duty); //Cambia el ciclo de trabajo de la salida 
        thread_sleep_for(WAIT_TIME_MS);
    }
}
