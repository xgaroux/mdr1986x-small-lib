/*******************************************************************************
 * @file    system.h
 * @author  GaROU (xgaroux@gmail.com)
 * @brief   Header file of system management
 ******************************************************************************/

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef MDR1986_SYSTEM_H
#define MDR1986_SYSTEM_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include <stdint.h>

/* Exported types ------------------------------------------------------------*/
typedef enum SYS_Freq_Enum
{
    SYS_Freq_1Mhz       = 1000000,
    SYS_Freq_2Mhz       = 2000000,
    SYS_Freq_4Mhz       = 4000000,
    SYS_Freq_8Mhz       = 8000000,
    SYS_Freq_16Mhz      = 16000000,
    SYS_Freq_24Mhz      = 24000000,
    SYS_Freq_32Mhz      = 32000000,
    SYS_Freq_40Mhz      = 40000000,
    SYS_Freq_48Mhz      = 48000000,
    SYS_Freq_56Mhz      = 56000000,
    SYS_Freq_64Mhz      = 64000000,
    SYS_Freq_72Mhz      = 72000000,
    SYS_Freq_80Mhz      = 80000000,
    SYS_Freq_88Mhz      = 88000000,
    SYS_Freq_96Mhz      = 96000000,
    SYS_Freq_104Mhz     = 104000000,
    SYS_Freq_112Mhz     = 112000000,
    SYS_Freq_120Mhz     = 120000000,
    SYS_Freq_128Mhz     = 128000000,
    SYS_Freq_136Mhz     = 136000000,
    SYS_Freq_144Mhz     = 144000000

} SYS_Freq_Type;

typedef enum SYS_FreqSrc_Enum
{
    SYS_FreqSrc_Crystal,
    SYS_FreqSrc_Oscillator

} SYS_FreqSrc_Type;

typedef enum SYS_State_Enum
{
    SYS_State_Unknown,
    SYS_State_Reset,
    SYS_State_Ready,
    SYS_State_Err_Param,
    SYS_State_Err_HSE,
    SYS_State_Err_PLL,
    SYS_State_Err_CHKSUM

} SYS_State_Type;

/* Exported constants --------------------------------------------------------*/
#define SYS_HSI_FREQ                ((uint32_t)8000000)

/* Exported macro ------------------------------------------------------------*/
/* Exported functions --------------------------------------------------------*/
/* System and clock configuration functions */
void SYS_DeInit(void);
void SYS_ClkInit(SYS_Freq_Type freq, SYS_Freq_Type hse_freq, SYS_FreqSrc_Type src);

SYS_State_Type SYS_State(void);
uint32_t SYS_ChecksumVerify(uint32_t start_address);

/* Private types -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private constants ---------------------------------------------------------*/
/* Private macros ------------------------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

#ifdef __cplusplus
}
#endif

#endif /* MDR1986_SYSTEM_H */

/***************************** END OF FILE ************************************/
