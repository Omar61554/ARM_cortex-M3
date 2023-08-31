/***********************************************************************************************************************/
/************** AUTHOR: OMAR KHALED     ********************************************************************************/
/************** DATE: 29/8/2023         ********************************************************************************/
/************** VERSION: 0.1            ********************************************************************************/
/************** FILE: RCC_config.h   ***********************************************************************************/
/***********************************************************************************************************************/
#ifndef RCC_CONFIG_H_
#define RCC_CONFIG_H_

/**
 * @brief choose clock          RCC_HSI   Internal high-speed clock   8 MHz
 *                              RCC_HSE   External high-speed clock   3-25 MHz
 *                              RCC_PLL   Phase-Locked Loop
 */
#define RCC_SYSCLK                RCC_HSE


#ifdef RCC_SYSCLK == RCC_HSE
/**
 * @brief choose the external clock   RCC_RC   
 *                                    RCC_CRYSTAL
 */

#define RCC_HSE_CLK                  RCC_RC 

#endif  //RCC_SYSCLK


#endif //RCC_CONFIG_H_