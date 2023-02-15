#ifndef __ATA_H
#define __ATA_H

#include <types.h>

typedef struct file {           // 496 bytes
	uint32_t    filenamep[2];   // 8   bytes
	uint32_t       data[122];   // 432 bytes
} file_t;

typedef struct sector {         // 512 bytes
	uint32_t             magic; // 4   bytes
	uint32_t             offset;// 4   bytes
	uint32_t          label[2]; // 8   bytes
	file_t                file; // 496 bytes
} sector_t;

sector_t from_real_sector(uint32_t data[128]);
uint32_t* from_vfs_sector(sector_t sect);
unsigned char* uint2chars(uint32_t x);
uint32_t chars2uint(unsigned char chars[4]);

void write_sector(sector_t sector);
sector_t read_sector(int offset);

#endif