#include <xc.h>
#include "SPI_libreria.h"

void SPI_Init_Master(void){
    ADCON1bits.PCFG = 0x0F;
    TRISBbits.TRISB0 =1;	// RB0 = SDI -> Entrada 
    TRISBbits.TRISB1=0;		// RB1 = SCK -> Salida
    TRISAbits.TRISA5=0;		// RA5 = SS' -> Salida
    TRISCbits.TRISC7=0;		// RC7 = SDO -> Salida
    CS = 1;                 
    PIR1bits.SPPIF = 0;     
    SSPSTATbits.BF = 0;     
    SSPSTATbits.CKE = 1;    
    SSPSTATbits.SMP = 0;    
    SSPCON1bits.SSPM = 2;   
    SSPCON1bits.CKP = 0;    
    SSPCON1bits.SSPEN = 1;  
    SSPCON1bits.SSPOV = 0;  
    SSPCON1bits.WCOL = 0;   
}

void SPI_Write(unsigned char x){
    SSPBUF=x;               
    while(!PIR1bits.SSPIF);	
    PIR1bits.SSPIF=0;		
}

unsigned char SPI_Read(){
    while(!PIR1bits.SSPIF);	
    PIR1bits.SSPIF=0;       
    return  SSPBUF;          
}


uint8_t SPI_Exchange(char data){
    SSPBUF = data;           
    while(!PIR1bits.SSPIF);	
    PIR1bits.SSPIF=0;		
    return  SSPBUF;          
}