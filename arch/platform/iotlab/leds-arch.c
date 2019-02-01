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
 * Copyright (C) 2012 HiKoB.
 */

/**
 * \file
 *         leds-arch.c for IoT-LAB M3 and A8-M3
 * \author
 *         Clement Burin Des Roziers <clement.burin-des-roziers.at.hikob.com>
 *         Antoine Fraboulet <antoine.fraboulet.at.hikob.com>
 */

#include "platform-headers.h"
#include "dev/leds.h"

#define LED_0_PORT   gpioB
#define LED_0_PIN    GPIO_PIN_5
#define LED_1_PORT   gpioD
#define LED_1_PIN    GPIO_PIN_2
#define LED_2_PORT   gpioC
#define LED_2_PIN    GPIO_PIN_10

void platform_leds_setup(void)
{
    gpio_enable(LED_0_PORT);
    gpio_enable(LED_1_PORT);
    gpio_enable(LED_2_PORT);

    // Set output pins B10 and B12
    gpio_set_output(LED_0_PORT, LED_0_PIN);
    gpio_set_output(LED_1_PORT, LED_1_PIN);
    gpio_set_output(LED_2_PORT, LED_2_PIN);

    // Clear LEDs
    leds_arch_set(0);
}

/*
 * Contiki support
 *
 */

void leds_arch_init(void)
{
    /* Needed because called by Openlab. Already done by platform_init() */
}

leds_mask_t
leds_arch_get(void)
{
    int l0 = gpio_pin_read(LED_0_PORT, LED_0_PIN);
    int l1 = gpio_pin_read(LED_1_PORT, LED_1_PIN);
    int l2 = gpio_pin_read(LED_2_PORT, LED_2_PIN);
    /* 0 means unset, 1 means set */
    return (leds_mask_t)((l0 ? 0 : LED_0) | (l1 ? 0 : LED_1) | (l2 ? 0 : LED_2));
}

void leds_arch_set(leds_mask_t leds)
{
    if (leds & LED_0)
    {
        /* clear pin to turn LED on */
        gpio_pin_clear(LED_0_PORT, LED_0_PIN);
    }
    else
    {
        /* set pin to turn LED off */
        gpio_pin_set(LED_0_PORT, LED_0_PIN);
    }

    if (leds & LED_1)
    {
        gpio_pin_clear(LED_1_PORT, LED_1_PIN);
    }
    else
    {
        gpio_pin_set(LED_1_PORT, LED_1_PIN);
    }

    if (leds & LED_2)
    {
        gpio_pin_clear(LED_2_PORT, LED_2_PIN);
    }
    else
    {
        gpio_pin_set(LED_2_PORT, LED_2_PIN);
    }
}
