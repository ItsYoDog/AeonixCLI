#include <memory.h>

#include <multibootinfo.h>
#include <stdint.h>

#define asizeof(x)((char * )( & x + 1) - (char * ) & x)

int ram_size() {
    return (mbi -> mem_lower + mbi -> mem_upper) + 513;
}

unsigned short * memsetw(unsigned short * dest, unsigned short val, int count) {
    int i;
    for (i = 0; i < count; i++) dest[i] = val;
    return dest;
}

void * sbrk(intptr_t incr) {
    uintptr_t old_break = current_break;
    current_break += incr;
    return (void * ) old_break;
}

void malloc_init() {
    last_valid_address = sbrk(0);
    managed_memory_start = last_valid_address;
    has_initialized = 1;
}

void bzero(void * s, int n) {
    char * c = s; // Can't work with void *s directly.
    int i;
    for (i = 0; i < n; ++i)
        c[i] = '\0';
}