/*
 * Copyright 2014, General Dynamics C4 Systems
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */

#include <config.h>
#include <machine/io.h>
#include <plat/machine/devices_gen.h>
#include <stdint.h>
#include <util.h>

#ifdef CONFIG_PRINTING
void uart_drv_putchar(unsigned char c) {}
#endif /* CONFIG_PRINTING */

#ifdef CONFIG_DEBUG_BUILD
unsigned char uart_drv_getchar(void) { return '\0'; }
#endif /* CONFIG_DEBUG_BUILD */
