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

#define USART_CR1 0x00
#define USART_CR2 0x04
#define USART_CR3 0x08
#define USART_BRR 0x0C
#define USART_GTPR 0x10
#define USART_RTOR 0x14
#define USART_RQR 0x18
#define USART_ISR 0x1C
#define USART_ICR 0x20
#define USART_RDR 0x24
#define USART_TDR 0x28
#define USART_PRESC 0x2C
#define USART_HWCFGR2 0x3EC
#define USART_HWCFGR1 0x3F0
#define USART_VERR 0x3F4
#define USART_IPIDR 0x3F8
#define USART_SIDR 0x3FC

#define USART_ISR_TXE BIT(7)
#define USART_ISR_RXNE BIT(5)

#define USART_REG(x) ((volatile uint32_t *)(UART_PPTR + (x)))

#ifdef CONFIG_PRINTING
void uart_drv_putchar(unsigned char c) {
	while (!(*USART_REG(USART_ISR) & USART_ISR_TXE))
		;
	*USART_REG(USART_TDR) = c;
}
#endif /* CONFIG_PRINTING */

#ifdef CONFIG_DEBUG_BUILD
unsigned char uart_drv_getchar(void) {
	while (!(*USART_REG(USART_ISR) & USART_ISR_RXNE))
		;
	return *USART_REG(USART_RDR);
}
#endif /* CONFIG_DEBUG_BUILD */
