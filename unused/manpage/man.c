#include <man.h>

#include <modules.h>

#include <screen.h>

char* man(char* module) {
	for(int i=0; i<count; i++) {
		if(strcmp(modules[i].name, module)==0) {
			return modules[i].description;
		}
	}
	return "Not found";
}

void manpage_init() {
	module_t modules_manpage_man = MODULE("kernel.modules.manpage.man", "Adds support for viewing the description/manpage of a module (CORE)");
	INIT(modules_manpage_man);
}