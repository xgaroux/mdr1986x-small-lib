/*******************************************************************************
 * @file    simple_exchange.h
 * @author  GaROU (xgaroux@gmail.com)
 * @brief   Header file of simple serial exchange protocol
 ******************************************************************************/

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef SIMPLE_EXCHANGE_H
#define SIMPLE_EXCHANGE_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include <stdint.h>

/* Exported constants --------------------------------------------------------*/
#define EXCH_DATA_LENGTH            0x0C    /*!< Msg data array length.       */

#define EXCH_MSG_START              ':'     /*!< Message start of frame flag  */
#define EXCH_MSG_END                '\n'    /*!< Message end of frame flag    */

#define EXCH_OK                     0x11    /*!< Success operation result     */
#define EXCH_BUSY                   0x22    /*!< System busy result           */
#define EXCH_FAIL                   0x33    /*!< Fail operation result        */

/* Exported types ------------------------------------------------------------*/
/**
  * @brief  Exchange message structure definition.
  */
typedef struct
{
    uint8_t             start;      /*!< Start of frame symbol.               */
    uint8_t             cmd;        /*!< Command byte.                        */
    uint8_t             data[EXCH_DATA_LENGTH];   /*!< Frame data array.      */
    uint8_t             crc;        /*!< Frame checksum byte.                 */
    uint8_t             end;        /*!< End of frame symbol.                 */

} EXCH_MsgStruct;

/**
  * @brief  Exchange union definition for access data as byte array and
  *         message structure.
  */
typedef union
{
    EXCH_MsgStruct      fields;
    uint8_t             all[sizeof(EXCH_MsgStruct)];

} EXCH_MsgTypedef;

/* Exported macro ------------------------------------------------------------*/
/* Exported functions --------------------------------------------------------*/
EXCH_MsgTypedef EXCH_PrepareMsg(uint8_t cmd, const uint8_t *data, uint8_t len);
uint8_t EXCH_Crc8(const uint8_t *data, uint8_t len);
uint16_t EXCH_Crc16(const uint8_t *data, uint16_t len);

#ifdef __cplusplus
}
#endif

#endif /* SIMPLE_EXCHANGE_H */

/***************************** END OF FILE ************************************/
