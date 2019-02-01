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
 *         Configuration for IoT-LAB M3
 *
 * \author
 *         Antoine Fraboulet <antoine.fraboulet.at.hikob.com>
 *         Gaëtan Harter <gaetan.harter.at.inria.fr>
 *
 */

#ifndef BOARD_CONF_H_
#define BOARD_CONF_H_

/* CFS defines */
#define XMEM_ERASE_UNIT_SIZE (64*1024L)

/* Sensors / actuators */
#define PLATFORM_HAS_LEDS    1
#define PLATFORM_HAS_LIGHT   1
#define PLATFORM_HAS_PRESSURE 1
#define PLATFORM_HAS_GYROSCOPE 1
#define PLATFORM_HAS_ACCELEROMETER 1
#define PLATFORM_HAS_MAGNETOMETER 1

#endif /* BOARD_CONF_H_ */
