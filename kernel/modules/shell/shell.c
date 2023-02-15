#include <modules.h>
#include <shell.h>
#include <timer.h>
#include <ports.h>
#include <string.h>
#include <memory.h>
#include <fs.h>
#include <panic.h>
#include <screen.h>

#define NULL ((char *)0)

int cf = 1;
int dfs = 1;
void shell_init(){
	module_t modules_shell_shell = MODULE("kernel.modules.shell.shell", "User command line for the kernel (CORE)");
	char** deps;
	deps[0] = "kernel.modules.timer.timer";
	DEPS(modules_shell_shell, deps);
	INIT(modules_shell_shell);
}

void shell(char s[], int i){
	char* start = "";
	char* two = "";
	char* cmdnamee_dup = "";
	strcpy(start, s);
	strcpy(two, s);
  	char* cmdnamee = strtok(start, " ");
	strcpy(cmdnamee_dup, cmdnamee);
  if(strcmp(s, "clear")==0){
  	clear_scr();
  } else if(strcmp(s, "help")==0){ // print help information
  	available_commands();
  } else if(strcmp(s, "about")==0){ // print info about computer
  	kprintf("Aeonix.CLI-x86: a 32 bit operating system written in C, C++ and Assembly\n");
  } else if(strcmp(s, "hlt")==0){ // halt the computer
  	halt();
  } else if(strcmp(cmdnamee, "panic")==0) { // kernel panic
	  panic("Kernel panic created by `panic` command", USER_CREATED_PANIC);
  } else if(strcmp(s, "reboot")==0){ // reboot computer
  	reboot();
  } else if(strcmp(s, "unknownerror")==0){ // prints unknown error
    	kprintf("Printing unknown error:\n");
  	unknown_command(s);
  } else if(strcmp(s, "sec")==0) { // get seconds elapsed from startup
  	char *buf;
  	char *str = itoa(get_tracked_seconds(), buf, 10);
  	strcat(str, "\n");
  	kprintf(str);
  } else if(strcmp(cmdnamee, "echo")==0) { // echo message after "echo "
	kprintf(strtok(cmdnamee_dup, " "));
  } else if(strcmp(cmdnamee, "ls")==0) { // list files and kprintf it
	struct dirent *node = 0;
	int i=0;
	while ( (node = readdir_fs(fs_root, i)) != 0)
	{
		fs_node_t *fsnode = finddir_fs(fs_root, node->name);
		kprintf(node->name);
		if(((fsnode->flags&0x7) == FS_DIRECTORY)) 
		{
			kprintf("/");
		}
		kprintf("\n");
		i++;
	} 
  } else if(strcmp(cmdnamee, "cat")==0) { // read file and kprintf it
	  char buf[4096];
		fs_node_t *fsnode = finddir_fs(fs_root, strtok(cmdnamee_dup, " "));
		uint32_t sz = read_fs(fsnode, 0, 4096, buf);
		int j;
		for (j = 0; j < sz; j++)
			kprintc(buf[j]);
	  kprintf("\n");
  } else if(strcmp(cmdnamee, "\\\/")==0 || strcmp(s, "")==0) { // comment
	
  } else if(strcmp(s, "ram")==0) { // list amount of RAM installed
	char* buf;
	kprintf(itoa(ram_size(), buf, 10));
  } else { // unknown command
  	unknown_command(s);
  }

  for(int j=0; s[j]!='\0'; j++){
  	s[j]='\0';
  }
  // strcat(strcat(strcat(strcat("[", username), "("), errorcode), ")]$")
  kprintf(">");
}

void halt(){
  	kprintf("Halting system...");
  	putstr("[DONE]", COLOR_GRN, COLOR_BLK);
  	asm volatile("hlt");
}

void reboot(){
  	kprintf("Rebooting...\n");
  	//using 8042 keyboard controller to pulse the CPU's RESET Pin
  	unsigned char temp = 0x02;
  	while(temp & 0x02)
  		temp = in_port_byte(0x64);
  	out_port_byte(0x64, 0xFE);
  	asm volatile("hlt");	
}

void clear_scr(){
	clear(COLOR_WHT, COLOR_BLK);
	set_cursor_pos(0,0);
}

void available_commands() {
  kprintf("Available commands:\n");
  kprintf("`help` - Shows this screen\n");
  kprintf("`clear` - Clears the screen\n");
  kprintf("`about` - Shows information about the OS\n");
  kprintf("`hlt` - Halts the computer\n");
  kprintf("`reboot` - Reboots the computer\n");
  kprintf("`echo <message>` - Prints the message after 'echo'\n");
  kprintf("`cat <file>` - Prints the contents of the file\n");
  kprintf("`ls` - Prints a list of all files and directories in the current directory\n");
  kprintf("`panic` - Causes a user-made kernel panic\n");
  kprintf("`man` - Provides a description for modules (e.g. 'kernel.modules.ata.ata')\n");
	kprintf("'sec' - Seconds elapsed from startup\n");
	kprintf("'ram' - Shows amount of ram installed\n");
}


void unknown_command(char s[]){
	char* cmdnamee = strtok(s, " ");
	kprintf(cmdnamee);
	
  	putstr(" : command not found!\n", COLOR_RED, COLOR_BLK);
  	putstr("Type ", COLOR_GRY, COLOR_BLK);
  	putstr("\"help\" ", COLOR_YEL, COLOR_BLK);
  	putstr("for the list of available commands.\n", COLOR_GRY, COLOR_BLK);
}
