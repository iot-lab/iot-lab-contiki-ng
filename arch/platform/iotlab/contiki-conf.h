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

#ifndef CONTIKI_CONF_H_
#define CONTIKI_CONF_H_

#include <stdint.h>
/*---------------------------------------------------------------------------*/
/* Include Project Specific conf */
#ifdef PROJECT_CONF_PATH
#include PROJECT_CONF_PATH
#endif /* PROJECT_CONF_PATH */

#include "iotlab-def.h"

/* Serial line and SLIP */

#ifndef UART_CONF_ENABLE
#define UART_CONF_ENABLE            1 /**< Enable/Disable UART I/O */
#endif

#ifndef SLIP_ARCH_CONF_ENABLED
#define SLIP_ARCH_CONF_ENABLED      0 /**< Enable/Disable SLIP.
                                typically done by example that require it */
#endif

#ifndef SLIP_ARCH_CONF_UART
#define SLIP_ARCH_CONF_UART uart_print
#endif

#ifndef SLIP_ARCH_CONF_BAUDRATE
#define SLIP_ARCH_CONF_BAUDRATE 500000
#endif

#if SLIP_ARCH_CONF_BAUDRATE != 500000
#warning Only 500000 baudrate works on iotlab testbed.
#warning This warning can be ignored if you are working on a standalone board.
#endif

#endif /* CONTIKI_CONF_H_ */
