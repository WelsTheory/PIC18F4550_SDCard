// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef XC_INTERRUPCION_H
#define	XC_INTERRUPCION_H

#include <xc.h> // include processor files - each processor file is guarded.  
#include <stdint.h>

void INT_Init(void);

void __interrupt(high_priority) INT0_ISR(void);
void __interrupt(low_priority) USART_RX_ISR(void);

#endif	/* XC_HEADER_TEMPLATE_H */

