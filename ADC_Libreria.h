
// This is a guard condition so that contents of this file are not included
// more than once.  


#ifndef XC_ADC_H
#define	XC_ADC_H

#include <xc.h> // include processor files - each processor file is guarded.  
#include <stdint.h>

void ADC_Init(void);

uint16_t ADC_Read(char channel);

#endif	/* XC_HEADER_TEMPLATE_H */

