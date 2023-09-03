/***********************************************************************************************************************/
/************** AUTHOR: OMAR KHALED     ********************************************************************************/
/************** DATE: 31/8/2023         ********************************************************************************/
/************** VERSION: 0.1            ********************************************************************************/
/************** FILE: GPIO_interface.h  ********************************************************************************/
/***********************************************************************************************************************/

#ifndef  GPIO_INTERFACE_H_
#define  GPIO_INTERFACE_H_


/**
 * @brief port numbers
 * 
 */
#define GPIO_PORTA             0 
#define GPIO_PORTB             1 
#define GPIO_PORTC             2 
//

/**
 * @brief pin values
 * 
 */
#define GPIO_LOW               0
#define GPIO_HIGH              1

/**
 * @brief input modes
 * 
 */
#define GPIO_INPUT_ANALOG_MOD                    0b0000 /**< GPIO Input Analog Mode */
#define GPIO_INPUT_FLOATING_MOD                  0b0100 /**< GPIO Input Floating Mode */
#define GPIO_INPUT_PUSH_PULL_MOD                 0b1000 /**< GPIO Input Push-Pull Mode */
//


/**
 * @brief output modes
 * 
 */
#define GPIO_OUTPUT_PUSH_PULL_10MHZ              0b0001 /**< GPIO Output Push-Pull Mode, 10MHz */
#define GPIO_OUTPUT_OPEN_DRAIN_10MHZ             0b0101 /**< GPIO Output Open-Drain Mode, 10MHz */
#define GPIO_OUTPUT_AF_PUSH_PULL_10MHZ           0b1001 /**< GPIO Output Alternate Function Push-Pull Mode, 10MHz */
#define GPIO_OUTPUT_AF_OPEN_DRAIN_10MHZ          0b1101 /**< GPIO Output Alternate Function Open-Drain Mode, 10MHz */

#define GPIO_OUTPUT_PUSH_PULL_2MHZ               0b0010 /**< GPIO Output Push-Pull Mode, 2MHz */
#define GPIO_OUTPUT_OPEN_DRAIN_2MHZ              0b0110 /**< GPIO Output Open-Drain Mode, 2MHz */
#define GPIO_OUTPUT_AF_PUSH_PULL_2MHZ            0b1010 /**< GPIO Output Alternate Function Push-Pull Mode, 2MHz */
#define GPIO_OUTPUT_AF_OPEN_DRAIN_2MHZ           0b1110 /**< GPIO Output Alternate Function Open-Drain Mode, 2MHz */

#define GPIO_OUTPUT_PUSH_PULL_50MHZ              0b0011 /**< GPIO Output Push-Pull Mode, 50MHz */
#define GPIO_OUTPUT_OPEN_DRAIN_50MHZ             0b0111 /**< GPIO Output Open-Drain Mode, 50MHz */
#define GPIO_OUTPUT_AF_PUSH_PULL_50MHZ           0b1011 /**< GPIO Output Alternate Function Push-Pull Mode, 50MHz */
#define GPIO_OUTPUT_AF_OPEN_DRAIN_50MHZ          0b1111 /**< GPIO Output Alternate Function Open-Drain Mode, 50MHz */
//

/**
 * @brief GPIO pin numbers
 * 
 */
#define GPIO_PIN0              0
#define GPIO_PIN1              1
#define GPIO_PIN2              2
#define GPIO_PIN3              3
#define GPIO_PIN4              4
#define GPIO_PIN5              5
#define GPIO_PIN6              6
#define GPIO_PIN7              7
#define GPIO_PIN8              8
#define GPIO_PIN9              9
#define GPIO_PIN10             10
#define GPIO_PIN11             11
#define GPIO_PIN12             12
#define GPIO_PIN13             13
#define GPIO_PIN14             14
#define GPIO_PIN15             15
//


/**
 * @brief SET PIN MODE
 * 
 * @param PORTID PORTA,PORTB,PORTC
 * @param PINID PIN0,PIN1,PIN2,PIN3,PIN4,PIN5,PIN6,PIN7,PIN8,PIN9,PIN10,PIN11,PIN12,PIN13,PIN14,PIN15
 * @param PINMODE gpio input modes or output modes
 * @return Std_ReturnType 
 */
Std_ReturnType MCAL_GPIO_SetPinMode(u8 PORTID,u8 PINID,u8 PINMODE);
//

/**
 * @brief SET PIN VALUE
 * 
 * @param PORTID PORTA,PORTB,PORTC
 * @param PINID PIN0,PIN1,PIN2,PIN3,PIN4,PIN5,PIN6,PIN7,PIN8,PIN9,PIN10,PIN11,PIN12,PIN13,PIN14,PIN15
 * @param PINVALUE GPIO_LOW,GPIO_HIGH
 * @return Std_ReturnType 
 */
Std_ReturnType MCAL_GPIO_SetPinValues(u8 PORTID,u8 PINID,u8 PINVALUE);
//

/**
 * @brief GET PIN VALUE
 * 
 * @param PORTID PORTA,PORTB,PORTC
 * @param PINID PIN0,PIN1,PIN2,PIN3,PIN4,PIN5,PIN6,PIN7,PIN8,PIN9,PIN10,PIN11,PIN12,PIN13,PIN14,PIN15
 * @param PIN_RETURN_VALUE GPIO_LOW,GPIO_HIGH
 * @return Std_ReturnType 
 */
Std_ReturnType MCAL_GPIO_GetPinValues(u8 PORTID,u8 PINID,u8 *PIN_RETURN_VALUE);
//



#endif // GPIO_INTERFACE_H_