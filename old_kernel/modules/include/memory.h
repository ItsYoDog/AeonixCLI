#ifndef __MEM_H
#define __MEM_H

#include <stdint.h>

uintptr_t current_break;
int has_initialized;
void * managed_memory_start;
void * last_valid_address;
typedef struct mem_control_block {
    int is_available;
    int size;
}
mem_control_block;
mem_control_block pmcb;

int ram_size();

typedef unsigned long uintptr_t;
typedef long intptr_t;

unsigned char *memcpy(unsigned char *dest, const unsigned char *src, int count);
unsigned char *memset(unsigned char *dest, unsigned char val, int count);
unsigned short *memsetw(unsigned short *dest, unsigned short val, int count);
int memcmp(const void *s1, const void *s2, int len);

void *sbrk(intptr_t incr);

void malloc_init();

void free(void *firstbyte);
void *malloc(long numbytes);

#endif