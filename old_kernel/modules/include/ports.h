#ifndef __PORTS_H
#define __PORTS_H

#include <types.h>

extern unsigned char in_port_byte(unsigned short port);
extern void out_port_byte(unsigned short port, unsigned char data);

extern unsigned char inb(unsigned short port);
extern void outb(unsigned short port, unsigned char data);


extern uint16_t inw(uint16_t port);
extern void outw(uint16_t port, uint16_t val);


extern uint32_t inl(uint16_t port);
extern void outl(uint16_t port, uint32_t val);

#endif