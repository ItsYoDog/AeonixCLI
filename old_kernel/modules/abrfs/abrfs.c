#include <abrfs.h>

#include <modules.h>

#include <types.h>
#include <ata.h>

sector_t from_real_sector(uint32_t data[128]) {
	sector_t sect;
	sect.magic = data[0];
	sect.offset = data[1];
	file_t f;
	f.filenamep[0] = data[2];
	f.filenamep[1] = data[3];
	for(int i=6; i<128; i++) {
		f.data[i-4] = data[i];
	}
	sect.file = f;
	return sect;
} 
uint32_t* from_vfs_sector(sector_t sect) {
	uint32_t data[128];
	data[0] = sect.magic;
	data[1] = sect.offset;
	data[2] = sect.file.filenamep[0];
	data[3] = sect.file.filenamep[1];
	for(int i=6; i<128; i++) {
		data[i] = sect.file.data[i-6];
	}
	return data;
}
unsigned char* uint2chars(uint32_t x) {
	unsigned char res[4];
	res[0] = x >> 24;
    res[1] = x >> 16;
    res[2] = x >> 8;
    res[3] = x;
	return res;
}

uint32_t chars2uint(unsigned char chars[4]) {
	return chars[0] | (chars[1] << 8) | (chars[2] << 16) | (chars[3] << 24);
}
void write_sector(sector_t sector) {
	char bwrite[512];
	uint32_t* real;
	memcpy(real, from_vfs_sector(sector), sizeof(real));

    for(int i = 0; i < 512; i+=4) {
		unsigned char chars[4];
		memcpy(chars, uint2chars(real[i/4]), 4);
        bwrite[i]   = chars[0];
		bwrite[i+1] = chars[1];
		bwrite[i+2] = chars[2];
		bwrite[i+3] = chars[3];
    }
	kprintf(bwrite);
	sect_write_atapio(sector.offset, 1, bwrite);
}

sector_t read_sector(int offset) {
	uint32_t target[128];
  	sect_read_atapio(target, offset, 1);
	
	sector_t sect = from_real_sector(target);
	return sect;
}

void abrfs_init() {
	module_t modules_abrfs_abrfs = MODULE("kernel.modules.abrfs.abrfs", "Provides a simple filesystem for the kernel (CORE)");
	char** deps;
	deps[0] = "ata";
	DEPS(modules_abrfs_abrfs, deps);
	INIT(modules_abrfs_abrfs);
}