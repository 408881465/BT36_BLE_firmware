/**
 ****************************************************************************************
 *
 * @file user_custs1_def.h
 *
 * @brief Custom Server 1 (CUSTS1) profile database definitions.
 *
 * Copyright (C) 2016-2025 Renesas Electronics Corporation and/or its affiliates.
 * All rights reserved. Confidential Information.
 *
 * This software ("Software") is supplied by Renesas Electronics Corporation and/or its
 * affiliates ("Renesas"). Renesas grants you a personal, non-exclusive, non-transferable,
 * revocable, non-sub-licensable right and license to use the Software, solely if used in
 * or together with Renesas products. You may make copies of this Software, provided this
 * copyright notice and disclaimer ("Notice") is included in all such copies. Renesas
 * reserves the right to change or discontinue the Software at any time without notice.
 *
 * THE SOFTWARE IS PROVIDED "AS IS". RENESAS DISCLAIMS ALL WARRANTIES OF ANY KIND,
 * WHETHER EXPRESS, IMPLIED, OR STATUTORY, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT. TO THE
 * MAXIMUM EXTENT PERMITTED UNDER LAW, IN NO EVENT SHALL RENESAS BE LIABLE FOR ANY DIRECT,
 * INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE, EVEN IF RENESAS HAS BEEN ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGES. USE OF THIS SOFTWARE MAY BE SUBJECT TO TERMS AND CONDITIONS CONTAINED IN
 * AN ADDITIONAL AGREEMENT BETWEEN YOU AND RENESAS. IN CASE OF CONFLICT BETWEEN THE TERMS
 * OF THIS NOTICE AND ANY SUCH ADDITIONAL LICENSE AGREEMENT, THE TERMS OF THE AGREEMENT
 * SHALL TAKE PRECEDENCE. BY CONTINUING TO USE THIS SOFTWARE, YOU AGREE TO THE TERMS OF
 * THIS NOTICE.IF YOU DO NOT AGREE TO THESE TERMS, YOU ARE NOT PERMITTED TO USE THIS
 * SOFTWARE.
 *
 ****************************************************************************************
 */

#ifndef _USER_CUSTS1_DEF_H_
#define _USER_CUSTS1_DEF_H_

/**
 ****************************************************************************************
 * @defgroup USER_CONFIG
 * @ingroup USER
 * @brief Custom Server 1 (CUSTS1) profile database definitions.
 *
 * @{
 ****************************************************************************************
 */

/*
 * INCLUDE FILES
 ****************************************************************************************
 */

#include "attm_db_128.h"

/*
 * DEFINES
 ****************************************************************************************
 */

// DX-BT36 UART Service - Service UUID: 0xFFE0
#define DEF_SVC1_UUID_128                {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0xFF, 0x00, 0x00}

// DX-BT36 TX Characteristic (Notify) - UUID: 0xFFE1
#define DEF_SVC1_TX_UUID_128             {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE1, 0xFF, 0x00, 0x00}

// DX-BT36 RX Characteristic (Write) - UUID: 0xFFE2
#define DEF_SVC1_RX_UUID_128             {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE2, 0xFF, 0x00, 0x00}

// DX-BT36 CMD Characteristic (Write) - UUID: 0xFFE3
#define DEF_SVC1_CMD_UUID_128            {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE3, 0xFF, 0x00, 0x00}

#define DEF_SVC1_TX_CHAR_LEN             244
#define DEF_SVC1_RX_CHAR_LEN             244
#define DEF_SVC1_CMD_CHAR_LEN            64

#define DEF_SVC1_TX_USER_DESC            "UART TX (Notify)"
#define DEF_SVC1_RX_USER_DESC            "UART RX (Write)"
#define DEF_SVC1_CMD_USER_DESC           "AT Command"

/// DX-BT36 UART Service Characteristic enum
enum
{
    // UART Service
    SVC1_IDX_SVC = 0,

    // TX Characteristic (Notify) - Module to Phone
    SVC1_IDX_TX_CHAR,
    SVC1_IDX_TX_VAL,
    SVC1_IDX_TX_NTF_CFG,
    SVC1_IDX_TX_USER_DESC,

    // RX Characteristic (Write) - Phone to Module
    SVC1_IDX_RX_CHAR,
    SVC1_IDX_RX_VAL,
    SVC1_IDX_RX_USER_DESC,

    // CMD Characteristic (Write) - AT Commands
    SVC1_IDX_CMD_CHAR,
    SVC1_IDX_CMD_VAL,
    SVC1_IDX_CMD_USER_DESC,

    CUSTS1_IDX_NB
};

/// @} USER_CONFIG

#endif // _USER_CUSTS1_DEF_H_
