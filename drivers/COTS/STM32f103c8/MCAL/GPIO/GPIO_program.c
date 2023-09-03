/***********************************************************************************************************************/
/************** AUTHOR: OMAR KHALED     ********************************************************************************/
/************** DATE: 31/8/2023         ********************************************************************************/
/************** VERSION: 0.1            ********************************************************************************/
/************** FILE: GPIO_program.c    ********************************************************************************/
/***********************************************************************************************************************/


/***************************************************< LIB **************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

/***************************************************< MCAL **************************************************************/

#include "GPIO_private.h"
#include "GPIO_interface.h"
#include "GPIO_config.h"


Std_ReturnType MCAL_GPIO_SetPinMode(u8 PORTID,u8 PINID,u8 PINMODE){
Std_ReturnType Local_Status = E_NOT_OK;
switch (PORTID)
{
case GPIO_PORTA:
    
    if(PINID < 8){
        GPIOA_CRL &= ~(0b1111 << (PINID * 4)); // clear the 4 bits of the pin

        GPIOA_CRL |= (PINMODE << (PINID *4)); // set the 4 bits of the pin

        Local_Status = E_OK;

    }

    else if (PINID < 16)
    {
        GPIOA_CRH &= ~(0b1111 << ((PINID - 8) * 4));

        GPIOA_CRH |= (PINMODE << ((PINID - 8) *4));

        Local_Status = E_OK;
    }

    else
    {
        Local_Status = E_NOT_OK; 
    }

    break;

case GPIO_PORTB:

if (PINID < 8)
{
    GPIOB_CRL &= ~(0b1111 << (PINID * 4)); // clear the 4 bits of the pin

    GPIOB_CRL |= (PINMODE << (PINID *4)); // set the 4 bits of the pin

    Local_Status = E_OK;
}

else if (PINID < 16)
{
    GPIOB_CRH &= ~(0b1111 << ((PINID - 8) * 4));

    GPIOB_CRH |= (PINMODE << ((PINID - 8) *4));

    Local_Status = E_OK;
}

else
{
    Local_Status = E_NOT_OK; 
}

    break;

case GPIO_PORTC:

if (PINID < 8){
    GPIOC_CRL &= ~(0b1111 << (PINID * 4)); // clear the 4 bits of the pin

    GPIOC_CRL |= (PINMODE << (PINID *4)); // set the 4 bits of the pin

    Local_Status = E_OK;
}

else if (PINID < 16)
{
    GPIOC_CRH &= ~(0b1111 << ((PINID - 8) * 4));

    GPIOC_CRH |= (PINMODE << ((PINID - 8) *4));

    Local_Status = E_OK;

}

else{
    Local_Status = E_NOT_OK;
}

    break;


default:
    Local_Status = E_NOT_OK;
    break;
}
return Local_Status;

}




Std_ReturnType MCAL_GPIO_SetPinValues(u8 PORTID,u8 PINID,u8 PINVALUE){

    Std_ReturnType Local_Status = E_NOT_OK;

    switch (PORTID)
    {
    case GPIO_PORTA: 

        switch (PINVALUE)
        {
        case GPIO_LOW:

            CLR_BIT(GPIOA_ODR,PINID); // clear the pin

            Local_Status = E_OK;

            break;

        case GPIO_HIGH:
            SET_BIT(GPIOA_ODR,PINID);

            Local_Status = E_OK;

            break;    
        
        default:
            Local_Status = E_NOT_OK;

            break;
        }

        break;

    case GPIO_PORTB:

        switch (PINVALUE)
        {
        case GPIO_LOW:

            CLR_BIT(GPIOB_ODR,PINID);

            Local_Status = E_OK;

            break;

        case GPIO_HIGH:
            SET_BIT(GPIOB_ODR,PINID);

            Local_Status = E_OK;   
        
        break;
        }
        break;

    case GPIO_PORTC:

        switch (PINVALUE)
        {
        case GPIO_LOW:

            CLR_BIT(GPIOC_ODR,PINID);

            Local_Status = E_OK;

            break;
    
        case GPIO_HIGH:
            SET_BIT(GPIOC_ODR,PINID);

            Local_Status = E_OK;
    
            break;      
        }
        break;
    
    default:
            Local_Status = E_NOT_OK;
        break;
    }

    return Local_Status;
}




Std_ReturnType MCAL_GPIO_GetPinValues(u8 PORTID,u8 PINID,u8 *PIN_RETURN_VALUE){
    Std_ReturnType Local_Status = E_NOT_OK;


    if (PIN_RETURN_VALUE != NULL)
    {
        switch (PORTID)
        {
        case GPIO_PORTA:
            *PIN_RETURN_VALUE = GET_BIT(GPIOA_IDR,PINID);
            Local_Status = E_OK;
            break;
        case GPIO_PORTB:
            *PIN_RETURN_VALUE = GET_BIT(GPIOB_IDR,PINID);
            Local_Status = E_OK;
            break;
        case GPIO_PORTC:
            *PIN_RETURN_VALUE = GET_BIT(GPIOC_IDR,PINID);
            Local_Status = E_OK;
            break;

        default:
            Local_Status = E_NOT_OK;
            break;
        }

    }
    else
    {
        Local_Status = E_NOT_OK;
    }
    return Local_Status;
}