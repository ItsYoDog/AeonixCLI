#include <screen.h>

void panic(char* reason, int errno) {
	char* buf;
	green_screen();
	putstr("KERNEL PANIC HAS OCCURED.\n", COLOR_WHT, COLOR_RED);
	putstr("ERROR CODE: 0x", COLOR_LBU, COLOR_RED);
	putstr(itoa(errno, buf, 10), COLOR_LBU, COLOR_RED);
	putstr("\nREASON: ", COLOR_WHT, COLOR_RED);
	putstr(reason, COLOR_LBU, COLOR_RED);
	putstr("\n\nRestart computer to resolve problem.\n", COLOR_WHT, COLOR_RED);
	putstr("If problem persists, contact Aeonix support for further help.", COLOR_GRY, COLOR_RED);
	
	while(1);
}