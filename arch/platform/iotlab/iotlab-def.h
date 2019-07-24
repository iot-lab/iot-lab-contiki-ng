/*
 * This file is part of HiKoB Openlab.
 *
 * HiKoB Openlab is free software: you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public License
 * as published by the Free Software Foundation, version 3.
 *
 * HiKoB Openlab is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with HiKoB Openlab. If not, see
 * <http://www.gnu.org/licenses/>.
 *
 * Copyright (C) 2011,2012 HiKoB.
 */

/**
 * \file
 *         Configuration for HiKoB OpenLab platforms
 *
 * \author
 *         Antoine Fraboulet <antoine.fraboulet.at.hikob.com>
 *         Gaëtan Harter <gaetan.harter.at.inria.fr>
 *
 */

#ifndef IOTLAB_CONF_H_
#define IOTLAB_CONF_H_

#include <stdint.h>

#include "board-def.h"

#define LEDS_CONF_GREEN       1
#define LEDS_CONF_RED         2
#define LEDS_CONF_YELLOW      4
#define LEDS_CONF_ALL   (LEDS_CONF_GREEN | LEDS_CONF_YELLOW | LEDS_CONF_RED )

// enable LEDS legacy API
#define LEDS_CONF_LEGACY_API 1

/* ---------------------------------------- */
/*
 *  Clock module and rtimer support
 *
 */

#define CLOCK_CONF_SECOND 100
typedef uint32_t  clock_time_t;
#define RTIMER_CONF_CLOCK_SIZE 2

/* ---------------------------------------- */
/*
 * Cortex M3 / ARM
 *
 */

typedef uint8_t  u8_t;
typedef uint16_t u16_t;
typedef uint32_t u32_t;
typedef int8_t   s8_t;
typedef int16_t  s16_t;
typedef int32_t  s32_t;

#define CC_BYTE_ALIGNED __attribute__ ((packed, aligned(1)))
/* Prefix for relocation sections in ELF files */
#define REL_SECT_PREFIX ".rel"

/* 1 len byte, 2 bytes CRC */
#define RADIO_PHY_OVERHEAD         3
/* 250kbps data rate. One byte = 32us */
#define RADIO_BYTE_AIR_TIME       32
/* Delay between GO signal and SFD
 * TODO: the current value is only a guess, needs actual measurement */
#define RADIO_DELAY_BEFORE_TX ((unsigned)US_TO_RTIMERTICKS(182))
/* Delay between GO signal and start listening
 * TODO: the current value is only a guess, needs actual measurement */
#define RADIO_DELAY_BEFORE_RX ((unsigned)US_TO_RTIMERTICKS(150))
/* Delay between the SFD finishes arriving and it is detected in software */
#define RADIO_DELAY_BEFORE_DETECT ((unsigned)US_TO_RTIMERTICKS(0))

/* Stack check not supported */
#define PLATFORM_CONF_SUPPORTS_STACK_CHECK  0

#define RF2XX_DEVICE rf231
#define NETSTACK_CONF_RADIO         rf2xx_driver

/* Max payload of rf2xx is 125 bytes (128 -1 for length -2 for CRC) */
#define rf2xx_driver_max_payload_len   125
#define PACKETBUF_CONF_SIZE         125
/* The rf2xx drivers do not support H/W ack */
#define CSMA_CONF_SEND_SOFT_ACK       1
/* Extra slack when waiting for ACK */
#define CSMA_CONF_ACK_WAIT_TIME            RTIMER_SECOND / 500
/* uip stats */
typedef unsigned int uip_stats_t;

#endif /* IOTLAB_CONF_H_ */
