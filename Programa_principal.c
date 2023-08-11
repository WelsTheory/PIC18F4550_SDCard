#include <xc.h>
#include "Configuracion.h"
#include "SPI_libreria.h"
#include "ff.h"

FATFS FatFs;// Area de trabajo
FIL Fil;// File Txt

void main(void) {
    UINT bx;
    SPI_Init_Master();
    TRISD = 0x00; //salida
    if(f_mount(&FatFs,"",1) == FR_OK)
    {
        if(f_open(&Fil,"hola.txt",FA_OPEN_ALWAYS | FA_WRITE) == FR_OK)
        {
            f_write(&Fil,"Suscribete al canal :D! ", 24, &bx);
            f_close(&Fil);
        }
    }
    while(1){
        
    }
}


