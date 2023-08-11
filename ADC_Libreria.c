

#include "ADC_Libreria.h"

void ADC_Init(void)
{
    ADCON1bits.VCFG = 0b00;// VREF+ = VDD
                           // VREF- = VSS
    ADCON1bits.PCFG = 0b1110;// AN0/RA0 -> ANALOGICO
    ADCON0bits.CHS = 0;// CANAL 0 - AN0
    /* CONVERSION 8.8us 
       TAD = 0.8us
     */
    /*Tiempo Adquisicion
     * 4 * 0.8us = 3.2us > 2.45us     
     */
    ADCON2bits.ACQT = 0b010;// 4TAD
    /* Ttotal = Tadquisicion + Tconv 
     *        = 3.2uS + 11*0.8us
     *        = 3.2us + 8.8us = 12us
     */
    ADCON2bits.ADCS = 0b101;// 16*1/20MHz = 0.8uS
    ADCON2bits.ADFM = 1; // Justificado a la derecha
    ADCON0bits.ADON = 1;// ADC ON
    ADCON0bits.GODONE = 1;// Realice la conversión
}

uint16_t ADC_Read(char channel)
{
    if(channel >= 13)
    {
        channel =0;
    }
    ADCON0bits.CHS = channel;
    ADCON0bits.GODONE = 1;// Realiza la conversión
    while(ADCON0bits.GODONE == 1);// Realizando la conversión
    // Está lista la conversión
    /*
     * ADRESH + ADRESL = ADRES
     */
    return ADRES;// 16 Bits -> 10bits ADC
}