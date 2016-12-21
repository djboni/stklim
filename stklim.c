/*
 Copyright 2016 Djones A. Boni

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

 http://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
 */

#include "stklim.h"

/*
 To change the stack size:
 1) Change STACK_SIZE definition.
 2) Change .stklim section start.

 Linker option to set .stklim section start:
 AVR ATmega328P (256 bytes) -Wl,-section-start=.stklim=0x800800
 */

#ifndef STACK_SIZE
/** Stack size in bytes. Should be multiple of 4. */
#define STACK_SIZE 256
#endif

#ifndef STACK_FILL_VALUE
/** Value to initialize the stack. Avoid common numbers such as 00s and FFs. */
#define STACK_FILL_VALUE 0xFA57C0DEUL
#endif

/* Number of 32bit words in the stack. */
#define STACK_SIZE_32 (STACK_SIZE / 4)

/* Stack memory. Should not be modified after initialization. */
__attribute__((section(".stklim")))
static volatile uint32_t stackMemory[STACK_SIZE_32];

/* Initialize stack with a constant 32bit value. Should not be called by the
 user. */
__attribute__((section(".init3")))
__attribute__((naked))
void stackInit(void)
{
    uint16_t i;
    for(i = 0; i < STACK_SIZE_32; ++i)
        stackMemory[i] = STACK_FILL_VALUE;
}

/** Check the number of 32bit words of the stack that was not changed. Returns
the number of words of the stack that were not used. */
uint16_t stackUsage(void)
{
    static uint16_t lower = STACK_SIZE_32;
    static uint16_t i = 0;

    if(stackMemory[i] != STACK_FILL_VALUE)
    {
        if(i < lower)
        {
            lower = i;
        }
    }

    if(++i >= lower)
    {
        i = 0;
    }

    return lower;
}
