/***********************************************************************************************************************/
/************** AUTHOR: OMAR KHALED     ********************************************************************************/
/************** DATE: 6/9/2023          ********************************************************************************/
/************** VERSION: 0.11           ********************************************************************************/
/************** FILE: RCC_config.h      ********************************************************************************/
/***********************************************************************************************************************/
#ifndef RCC_CONFIG_H_
#define RCC_CONFIG_H_

/**
 * @brief choose clock          RCC_HSI   Internal high-speed clock   8 MHz
 *                              RCC_HSE   External high-speed clock   3-25 MHz
 *                              RCC_PLL   Phase-Locked Loop
 */
#define RCC_SYSCLK                RCC_HSE
//

#ifdef RCC_SYSCLK == RCC_HSE
/**
 * @brief choose the external clock   RCC_RC   
 *                                    RCC_CRYSTAL
 */

#define RCC_HSE_CLK                  RCC_RC 


#endif  //RCC_SYSCLK_HSE
//

#ifdef RCC_SYSCLK == RCC_PLL
/**
 * @brief choose the PLL clock   RCC_PLL_HSI_DIV_2
 *                               RCC_PLL_HSE_DIV_2
 *                               RCC_PLL_HSE
 */

#define RCC_PLL_CLK                  RCC_PLL_HSE_DIV_2

#endif  //RCC_SYSCLK_PLL
//


#endif //RCC_CONFIG_H_