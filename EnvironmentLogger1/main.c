/* --COPYRIGHT--,BSD
 * Copyright (c) 2017, Texas Instruments Incorporated
 * All rights reserved.
*/

#include "driverlib.h"
#include "userDrivers/uartA0.h"
#include "userDrivers/clocks.h"

uint16_t i;
uint8_t RXData = 0, TXData = 65;
uint8_t check = 0;

uint32_t DelayCount=0;

void main(void)
{
    // stop watchdog
    WDT_A_hold(WDT_A_BASE);

    clocks_Initialise();

    PMM_unlockLPM5(); //Disable the GPIO power-on default high-impedance

    uartA0_Initialise();
    __enable_interrupt();

    while (1)
    {

        if(TXData++>94){ // Increment TX data
            TXData = 65;
        }
        // Load data onto buffer
        EUSCI_A_UART_transmitData(EUSCI_A0_BASE,
                           TXData);

        for(DelayCount=0; DelayCount<200000; DelayCount++){

        }
    }
}

