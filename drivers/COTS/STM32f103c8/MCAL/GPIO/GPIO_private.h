/***********************************************************************************************************************/
/************** AUTHOR: OMAR KHALED     ********************************************************************************/
/************** DATE: 31/8/2023         ********************************************************************************/
/************** VERSION: 0.1            ********************************************************************************/
/************** FILE: GPIO_private.h    ********************************************************************************/
/***********************************************************************************************************************/

#ifndef  GPIO_PRIVATE_H_
#define  GPIO_PRIVATE_H_

#define GPIO_PORTA_ADDRESS                    0x40010800U
#define GPIO_PORTB_ADDRESS                    0x40010C00U
#define GPIO_PORTC_ADDRESS                    0x40011000U 
/**
 * @brief port A registers addresses from stm32 reference manual
 * 
 */
#define GPIOA_CRL                  (*((volatile u32*)GPIO_PORTA_ADDRESS + 0x00))
#define GPIOA_CRH                  (*((volatile u32*)GPIO_PORTA_ADDRESS + 0x04))
#define GPIOA_IDR                  (*((volatile u32*)GPIO_PORTA_ADDRESS + 0x08))
#define GPIOA_ODR                  (*((volatile u32*)GPIO_PORTA_ADDRESS + 0x0c))
#define GPIOA_BSRR                 (*((volatile u32*)GPIO_PORTA_ADDRESS + 0x10))
#define GPIOA_BRR                  (*((volatile u32*)GPIO_PORTA_ADDRESS + 0x14))
#define GPIOA_LCKR                 (*((volatile u32*)GPIO_PORTA_ADDRESS + 0x18))
#define GPIOA_CRL                  (*((volatile u32*)GPIO_PORTA_ADDRESS + 0x00))     
//

/**
 * @brief port B registers addresses
 * 
 */
#define GPIOB_CRL                  (*((volatile u32*)GPIO_PORTB_ADDRESS + 0x00))
#define GPIOB_CRH                  (*((volatile u32*)GPIO_PORTB_ADDRESS + 0x04))
#define GPIOB_IDR                  (*((volatile u32*)GPIO_PORTB_ADDRESS + 0x08))
#define GPIOB_ODR                  (*((volatile u32*)GPIO_PORTB_ADDRESS + 0x0c))
#define GPIOB_BSRR                 (*((volatile u32*)GPIO_PORTB_ADDRESS + 0x10))
#define GPIOB_BRR                  (*((volatile u32*)GPIO_PORTB_ADDRESS + 0x14))
#define GPIOB_LCKR                 (*((volatile u32*)GPIO_PORTB_ADDRESS + 0x18))
#define GPIOB_CRL                  (*((volatile u32*)GPIO_PORTB_ADDRESS + 0x00))   
//

/**
 * @brief port C registers addresses
 * 
 */
#define GPIOC_CRL                  (*((volatile u32*)GPIO_PORTC_ADDRESS + 0x00))
#define GPIOC_CRH                  (*((volatile u32*)GPIO_PORTC_ADDRESS + 0x04))
#define GPIOC_IDR                  (*((volatile u32*)GPIO_PORTC_ADDRESS + 0x08))
#define GPIOC_ODR                  (*((volatile u32*)GPIO_PORTC_ADDRESS + 0x0c))
#define GPIOC_BSRR                 (*((volatile u32*)GPIO_PORTC_ADDRESS + 0x10))
#define GPIOC_BRR                  (*((volatile u32*)GPIO_PORTC_ADDRESS + 0x14))
#define GPIOC_LCKR                 (*((volatile u32*)GPIO_PORTC_ADDRESS + 0x18))
#define GPIOC_CRL                  (*((volatile u32*)GPIO_PORTC_ADDRESS + 0x00))   
//

#define NULL                      (void *)(0x0)


#endif // GPIO_PRIVATE_H_