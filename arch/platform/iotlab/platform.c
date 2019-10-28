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
 * \file openlab-main.c
 *         Configuration for Openlab boards
 *
 * \author
 *         Antoine Fraboulet <antoine.fraboulet.at.hikob.com>
 *         Gaëtan Harter <gaetan.harter.at.inria.fr>
 *
 */

#include <string.h>

#include "platform.h"
#include "drivers/unique_id.h"

#include "contiki.h"
#include "contiki-net.h"
#include "sys/energest.h"

#include "lib/sensors.h"
#include "dev/serial-line.h"
#include "dev/uart1.h"
#include "dev/watchdog.h"
#include "drivers/unique_id.h"

#include "pwr.h"

#if SLIP_ARCH_CONF_ENABLED
#include "dev/slip.h"
#endif

/* Log configuration */
#include "sys/log.h"
#define LOG_MODULE "IoT-LAB"
#define LOG_LEVEL LOG_LEVEL_MAIN
// #define NO_DEBUG_HEADER
// #include "debug.h"

/*---------------------------------------------------------------------------*/
#if UART_CONF_ENABLE
static void
char_rx(handler_arg_t arg, uint8_t c)
{
    uart1_get_input_handler()(c);
}
#endif
/*---------------------------------------------------------------------------*/
static void
set_linkaddr(void)
{
#if LINKADDR_SIZE == 2
    uint16_t short_uid = platform_uid();
    linkaddr_node_addr.u8[0] = 0xff & (short_uid >> 8);
    linkaddr_node_addr.u8[1] = 0xff & (short_uid);
#else

#define IOTLAB_UID_ADDR 1
#if !(IOTLAB_UID_ADDR)
    /* Company 3 Bytes */
    linkaddr_node_addr.u8[0] = 0x01;
    linkaddr_node_addr.u8[1] = 0x23;
    linkaddr_node_addr.u8[2] = 0x45;

    /* Platform identifier */
    linkaddr_node_addr.u8[3] = 0x01;

    /* Generate 4 remaining bytes using uid of processor */
    // use bytes 8-11 to ensure uniqueness (tested empirically)
    int i;
    for (i = 0; i < 4; i++)
        linkaddr_node_addr.u8[i+4] = uid->uid8[i+8];

#else
    memset(&linkaddr_node_addr, 0, sizeof(linkaddr_node_addr));
    uint16_t short_uid = platform_uid();
    linkaddr_node_addr.u8[0] = 0x02;
    linkaddr_node_addr.u8[6] = 0xff & (short_uid >> 8);
    linkaddr_node_addr.u8[7] = 0xff & (short_uid);

#endif
#endif
}

/*---------------------------------------------------------------------------*/
void
platform_init_stage_one(void)
{
  /* Initialize OpenLab */
  platform_init();
}
/*---------------------------------------------------------------------------*/
void
platform_init_stage_two(void)
{
  /* Set linkaddr */
  set_linkaddr();
#if UART_CONF_ENABLE
  /*
   * init serial line
   */
  serial_line_init();
  uart_set_rx_handler(uart_print, char_rx, NULL);
  /* configure highest priority to avoid missing bytes */
  uart_set_irq_priority(uart_print, 0);
#endif
}
/*---------------------------------------------------------------------------*/
void
platform_init_stage_three(void)
{
  LOG_INFO("Target: %s, board: %s\n", CONTIKI_TARGET_STRING, CONTIKI_BOARD_STRING);
  process_start(&sensors_process, NULL);
}
/*---------------------------------------------------------------------------*/
void
platform_idle(void)
{
  ENERGEST_SWITCH(ENERGEST_TYPE_CPU, ENERGEST_TYPE_LPM);
  pwr_enter_sleep();
  ENERGEST_SWITCH(ENERGEST_TYPE_LPM, ENERGEST_TYPE_CPU);
}
