

#include "INT.h"
#include "Configuracion.h"
#include "ADC_Libreria.h"
//#include "LCD_Libreria.h"
#include "EUSART.h"
#include <stdio.h>

extern char valor;

char datos[10];
char x = 0;

void INT_Init(void)
{
    /* INTERRUPCION EXTERNA 0 */
//    TRISBbits.RB0 = 1; // ENTRADA
//    INTCONbits.INT0IE = 1;// HABILITANDO INT0
//    INTCONbits.INT0IF = 0; // LIMPIANDO LA BANDERA
//    INTCON2bits.INTEDG0 = 0; // FLANCO DE BAJADA 1 - 0
//    /* INTERRUPCION EXTERNA 1 Y 2 */
//    INTCON3bits.INT1IE = 1;// HABILITAR INT 1 Y 2
//    INTCON3bits.INT2IE = 1;
//    INTCON2bits.INTEDG1 = 0; // FLANCO DE BAJADA 1 - 0
//    INTCON2bits.INTEDG2 = 0; // FLANCO DE BAJADA 1 - 0
//    INTCON3bits.INT1IP = 0; // BAJA PRIORIDAD
//    INTCON3bits.INT1IF = 0; //LIMPIAMOS BANDERAS
//    INTCON3bits.INT2IF = 0;
//    INTCON3bits.INT2IP = 1; // ALTA PRIORIDAD
    /* FIN */
    RCONbits.IPEN = 1; // HABILITAR PRIORIDADES
    INTCONbits.PEIE = 1; // HABILITADO INT PERIFERICOS 
                        // HABILITA PRIORIDADES BAJAS
    INTCONbits.GIE = 1; // HABILITADO INT GLOBALES
                        // HABILITA PRIORIDADES ALTAS
}

// INT0 Y INT2
void __interrupt(high_priority) INT0_ISR(void)
{
    
    INTCONbits.INT0IF = 0;
    
}

// INT1
void __interrupt(low_priority) USART_RX_ISR(void)
{
    /*valor = EUSART_Rx();
    PIR1bits.RCIF = 0;
    */
    if(x == 10)
    {
        x = 0;
    }
    if(EUSART_Rx() == '1' || EUSART_Rx() == '0')
    {
        valor = EUSART_Rx();
    }
    else
    {
        datos[x] = EUSART_Rx();//hola
        x++;// x = 10
    }
    PIR1bits.RCIF = 0;
}


