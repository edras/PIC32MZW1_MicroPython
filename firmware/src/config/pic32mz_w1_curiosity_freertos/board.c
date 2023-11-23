/*
 * This file is part of the MicroPython project, http://micropython.org/
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2015 Damien P. George
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

///#include <p33Fxxxx.h>
#include "board.h"
#include "definitions.h"

/********************************************************************/
// CPU

void cpu_init(void) {
#if 0
    // set oscillator to operate at 40MHz
    // Fosc = Fin*M/(N1*N2), Fcy = Fosc/2
    // Fosc = 7.37M*40/(2*2) = 80Mhz for 7.37M input clock
    PLLFBD = 41;            // M=39
    CLKDIVbits.PLLPOST = 0; // N1=2
    CLKDIVbits.PLLPRE = 0;  // N2=2
    OSCTUN = 0;

    // initiate clock switch to FRC with PLL
    __builtin_write_OSCCONH(0x01);
    __builtin_write_OSCCONL(0x01);

    // wait for clock switch to occur
    while (OSCCONbits.COSC != 0x01) {
    }
    while (!OSCCONbits.LOCK) {
    }
    
#endif
}

/********************************************************************/
// LEDs
#if 0

#define RED_LED_TRIS _TRISC15
#define YELLOW_LED_TRIS _TRISC13
#define GREEN_LED_TRIS _TRISC14

#define RED_LED _LATC15
#define YELLOW_LED _LATC13
#define GREEN_LED _LATC14

#endif

#define LED_ON (0)
#define LED_OFF (1)

void led_init(void) {    
    TRISKCLR = (1U<<1);
    TRISKCLR = (1U<<3);    
}

void led_state(int led, int state) {
    int val = state ? LED_OFF : LED_ON;
    switch (led) {
        case 1:
            TRISKCLR = (1U<<1);
            GPIO_PinWrite(GPIO_PIN_RK1, (bool)val);
            break;
        case 2:
            TRISKCLR = (1U<<3);  
            GPIO_PinWrite(GPIO_PIN_RK3, (bool)val);;
            break;
        default:
            break;
    }
}


void led_toggle(int led) {
    switch (led) {
        case 1:
            GPIO_PinToggle(GPIO_PIN_RK1);
            break;
        case 2:
            GPIO_PinToggle(GPIO_PIN_RK3);
            break;
        default:
            break;
    }
}

/********************************************************************/
// switches
#if 0
#define SWITCH_S1_TRIS _TRISD8
#define SWITCH_S2_TRIS _TRISD9

#define SWITCH_S1 _RD8
#define SWITCH_S2 _RD9
#endif
void switch_init(void) {
    TRISASET = (1U<<10);
}

int switch_get(int sw) {   
    int val = 1;
    switch (sw) {
        case 1:
            TRISASET = (1U<<10);
            val = GPIO_PinRead(GPIO_PIN_RA10);
            break;
        default:
            break;
    }
    return val == 0;
         
}

/********************************************************************/
// UART

/*
// TODO need an irq
void uart_rx_irq(void) {
    if (c == interrupt_char) {
        MP_STATE_MAIN_THREAD(mp_pending_exception) = MP_STATE_PORT(keyboard_interrupt_obj);
    }
}
*/

void uart_init(void) {
    
#if 0
    // baudrate = F_CY / 16 (uxbrg + 1)
    // F_CY = 40MHz for us
    UART1.uxbrg = 64; // 38400 baud
    UART1.uxmode = 1 << 15; // UARTEN
    UART1.uxsta = 1 << 10;  // UTXEN
    
#endif
}

int uart_rx_any(void) {
#if 0
    return UART1.uxsta & 1; // URXDA
#endif
    return 0;
}

int uart_rx_char(void) {
#if 0
    return UART1.uxrxreg;
#endif
    return 0;
}

void uart_tx_char(int chr) {
#if 0
    while (UART1.uxsta & (1 << 9)) {
        // tx fifo is full
    }
    UART1.uxtxreg = chr;
#endif
}
