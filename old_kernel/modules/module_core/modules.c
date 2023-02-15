#include <modules.h>

#include <screen.h>
#include <log.h>

int count = 0;

module_t MODULE(char* name, char* description) {
	module_t mod;
	mod.usermode = false;
	mod.enabled = true;
	mod.initialized = false;
	mod.name = name;
	mod.description = description;
	return mod;
}

void INIT(module_t module) {
	log("initializing module... ");
	log(module.name);
	kprintf("---initializing module ");
	kprintf(module.name);
	kprintf("\n");
	modules[count] = module;
	count++;
	module.initialized = true;
	kprintf(" \\->");
	putstr("done.\n", COLOR_GRN, COLOR_BLK);
	log("done!");
}
void DISABLE(module_t module) {
	log("disabling module... ");
	log(module.name);
	kprintf("---disabling module");
	kprintf(module.name);
	kprintf("\n");
	module.enabled = false;
	kprintf(" \\->done.\n");
	log("done!");
}
void ENABLE(module_t module) {
	log("enabling module... ");
	log(module.name);
	kprintf("---enabling module");
	kprintf(module.name);
	kprintf("\n");
	module.enabled = true;
	kprintf(" \\->done.\n");
	log("done!");
}
void DEPS(module_t module, char** dependencies) {
	log("marking dependencies of:");
	log(module.name);
	module.dependencies = dependencies;
}