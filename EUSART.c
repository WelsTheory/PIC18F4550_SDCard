
#include "EUSART.h"

void EUSART_Init(uint8_t baud)
{
    SPBRG = baud; // BAUDIOS 
    BAUDCONbits.BRG16 = 0; // 8 bits -> SPBRG
    TXSTAbits.BRGH = 0; // Low Speed
    TXSTAbits.SYNC = 0;// Asincrono
    TXSTAbits.TX9 = 0; // 8 bits
    RCSTAbits.SPEN = 1;// Habilitar Pines
    RCSTAbits.RC9 = 0; // 8 bits
    // Habilitar Transmisión
    TXSTAbits.TXEN = 1; 
    // Habilitar Recepción
    RCSTAbits.CREN = 1;
    /* INTERRUPCION RX USART */
    PIE1bits.RC1IE = 1;// HABILITO INT RX
    PIR1bits.RCIF = 0; // LIMPIAR BANDEA
    IPR1bits.RCIP = 0; // PRIORIDAD BAJA
    //PIE1bits.TX1IE;
}

void EUSART_Tx(char data)
{
    while(TXSTAbits.TRMT == 0);// FULL
    TXREG = data;
}

char EUSART_Rx(void)
{
    return RCREG;
}

void EUSART_Cadena(char *data)
{   //Hola/0
    while(*data != '\0')
    {
        EUSART_Tx(*data);
        data++;// dat = 100 -> dat 101  
    } 
}