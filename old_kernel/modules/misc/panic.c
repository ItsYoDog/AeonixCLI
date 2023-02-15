#include <screen.h>

#include <log.h>

void panic(char* reason, int errno) {
	//char* buf;
	//green_screen();
	char* kpanicmsg = "KERNEL PANIC HAS OCCURED. ERROR CODE: 0x";
	putstr("KERNEL PANIC HAS OCCURED.\n", COLOR_WHT, COLOR_GRN);
	//strcat(kpanicmsg, itoa(errno, buf, 16));
	//strcat(kpanicmsg, ".\nREASON: ");
	//strcat(kpanicmsg, reason);
	//strcat(kpanicmsg, "\nLOG:\n");
	//putstr(kpanicmsg, COLOR_WHT, COLOR_GRN);
	putstr(get_log(), COLOR_LBU, COLOR_GRN);
	while(1);
}