/***********************************************************************************************************************/
/************** AUTHOR: OMAR KHALED     ********************************************************************************/
/************** DATE: 6/9/2023          ********************************************************************************/
/************** VERSION: 0.11           ********************************************************************************/
/************** FILE: RCC_program.c     ********************************************************************************/
/***********************************************************************************************************************/


/***************************************************< LIB **************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

/***************************************************< MCAL **************************************************************/

#include "RCC_private.h"
#include "RCC_interface.h"
#include "RCC_config.h"




Std_ReturnType Mcal_Rcc_InitSysClock(void){

    Std_ReturnType Local_Status = E_NOT_OK;

    #if RCC_SYSCLK == RCC_HSE

        #if RCC_HSE_CLK == RCC_RC 
            SET_BIT(RCC_CR,18);
        
        #elif RCC_HSE_CLK == RCC_CRYSTAl
            CLR_BIT(RCC_CR,18);

        #else
            #error "enter valid HSE clock"
        #endif

        SET_BIT(RCC_CR,16);
        while (!GET_BIT(RCC_CR,17));
        RCC_CFGR = 0x00000001;
        Local_Status = E_OK;

    #elif RCC_SYSCLK == RCC_HSI
        SET_BIT(RCC_CR,0);
        while (!GET_BIT(RCC_CR,1));
        RCC_CFGR = 0x00000000;
        Local_Status = E_OK;

    #elif RCC_SYSCLK == RCC_PLL
        #if RCC_PLL_CLK == RCC_PLL_HSI_DIV_2
            SET_BIT(RCC_CR,0);
            RCC_CFGR = 0b0000 0000 0000 0000 0000 0000 1000 0000;
            CLR_BIT(RCC_CFGR,16);
            Local_Status = E_OK;

        #elif RCC_PLL_CLK == RCC_PLL_HSE_DIV_2
            SET_BIT(RCC_CR,18);
            SET_BIT(RCC_CFGR,16);
            Local_Status = E_OK;

        #elif RCC_PLL_CLK == RCC_PLL_HSE
            SET_BIT(RCC_CR,18);
            SET_BIT(RCC_CFGR,16);
            SET_BIT(RCC_CFGR,17);
            Local_Status = E_OK;

        #else
            #error "enter valid PLL clock"
        #endif    

        // enable PLL after setting the clock since bit can be written only when PLL is disabled
        SET_BIT(RCC_CR,24); 
        while(!GET_BIT(RCC_CR,25));
        RCC_CFGR = 0x00000010;
        Local_Status = E_OK;

    


    #else  
        #error "enter valid clock"
    #endif



return Local_Status;

}

Std_ReturnType Mcal_Rcc_EnablePeripheral(u8 BUS_ID , u8 PERIPHERAL_ID){
Std_ReturnType Local_Status = E_NOT_OK;

switch (BUS_ID)
{
case RCC_AHB:
        SET_BIT(RCC_AHBENR,PERIPHERAL_ID);
        Local_Status = E_OK;
    break;
case RCC_APB1:
        SET_BIT(RCC_APB1ENR,PERIPHERAL_ID);
        Local_Status = E_OK;
    break;  
    case RCC_APB2:
        SET_BIT(RCC_APB2ENR,PERIPHERAL_ID);
        Local_Status = E_OK;
    break;     

default:
    Local_Status = E_NOT_OK;
    break;
}


return Local_Status;
}

Std_ReturnType Mcal_Rcc_DisablePeripheral(u8 BUS_ID , u8 PERIPHERAL_ID){

Std_ReturnType Local_Status = E_NOT_OK;

switch (BUS_ID){
case RCC_AHB:
        CLR_BIT(RCC_AHBENR,PERIPHERAL_ID);
        Local_Status = E_OK;
    break;
case RCC_APB1:
        CLR_BIT(RCC_APB1ENR,PERIPHERAL_ID);
        Local_Status = E_OK;
    break;  
    case RCC_APB2:
        CLR_BIT(RCC_APB2ENR,PERIPHERAL_ID);
        Local_Status = E_OK;
    break;     

default:
    Local_Status = E_NOT_OK;
    break;

}
return Local_Status;
}