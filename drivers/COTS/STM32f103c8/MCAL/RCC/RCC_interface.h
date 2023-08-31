/***********************************************************************************************************************/
/************** AUTHOR: OMAR KHALED     ********************************************************************************/
/************** DATE: 29/8/2023         ********************************************************************************/
/************** VERSION: 0.1            ********************************************************************************/
/************** FILE: RCC_interface.h   ********************************************************************************/
/***********************************************************************************************************************/
#ifndef RCC_interface_H_
#define RCC_interface_H_


#define RCC_AHB                 0 /**< Advanced High-performance Bus (AHB) domain. */
#define RCC_APB1                1 /**< Advanced Peripheral Bus 1 (APB1) domain. */
#define RCC_APB2                2 /**< Advanced Peripheral Bus 2 (APB2) domain. */

/**
 * @brief initiate the system clock after configuring it at RCC_CONFIG.h
 * 
 * @return character
 */
Std_ReturnType Mcal_Rcc_InitSysClock(void);

/**
 * @brief enables the choosen peripheral
 * @param BUS_ID as AHB,ABP1,ABP2
 * @param PERIPHERAL_ID open reference manual
 * @return character
 */
Std_ReturnType Mcal_Rcc_EnablePeripheral(u8 BUS_ID , u8 PERIPHERAL_ID);

/**
 * @brief disables the choosen peripheral
 * @param BUS_ID as AHB,ABP1,ABP2
 * @param PERIPHERAL_ID open reference manual
 * @return character
 */
Std_ReturnType Mcal_Rcc_DisablePeripheral(u8 BUS_ID , u8 PERIPHERAL_ID);

#endif //RCC_interface_H_