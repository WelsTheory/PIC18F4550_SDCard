#include <xc.h>
#include "Configuracion.h"

//SPI Master
void SPI_Init_Master(void);

void SPI_Write(unsigned char);
unsigned char SPI_Read();

uint8_t SPI_Exchange(char data);

//pines
#define CS LATA5
#define SD_CS_SetLow()  LATAbits.LA5 = 0;
#define SD_CS_SetHigh() LATAbits.LA5 = 1;