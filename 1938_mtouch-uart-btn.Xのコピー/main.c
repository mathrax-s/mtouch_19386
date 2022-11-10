/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.7
        Device            :  PIC16F1938
        Driver Version    :  2.00
 */

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
 */

#include "mcc_generated_files/mcc.h"

/*
                         Main application
 */

//static uint8_t myTaskIsDone, myTaskStarted;
//uint32_t to;
#define TIMEOUT_VALUE 1000

void main(void) {
    int i;
    uint16_t sliderPostion[2];
    float f_slider[2];
    float ave_slider[2];
    float map_slider[2];
    // initialize the device
    SYSTEM_Initialize();

    // When using interrupts, you need to set the Global and Peripheral Interrupt Enable bits
    // Use the following macros to:

    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();

    for (i = 0; i < 10; i++) {
        LED_SetHigh();
        DELAY_milliseconds(50);
        LED_SetLow();
        DELAY_milliseconds(50);
    }

    //    LED_SetHigh();
    while (1) {
        // Add your application code

        if (MTOUCH_Service_Mainloop()) {

            /* Slider/Wheel API*/
            for (i = 0; i < 2; i++) {
                if (MTOUCH_Slider_isPositionChanged(i)) {
                    sliderPostion[i] = MTOUCH_Slider_Position_Get(i);
                    f_slider[i] = sliderPostion[i];
                }
                if (!MTOUCH_Slider_isPressed(i)) {
                    f_slider[i] = 0;
                }
                //ave_slider[i] = (ave_slider[i] * 0.8) + (f_slider[i] * 0.2);
                //map_slider[i] = (ave_slider[i] / 4096) * 100;
            }
            EUSART_Write(f_slider[0]);
            EUSART_Write(f_slider[1]);
            EUSART_Write(0xFF);
        }

    }
}

/**
 End of File
 */