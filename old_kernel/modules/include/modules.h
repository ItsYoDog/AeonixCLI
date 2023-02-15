#ifndef __MODULES_H
#define __MODULES_H

#define true 1
#define false 0

typedef int bool;

int count;

typedef struct module_t {
	bool usermode;
	bool enabled;
	bool initialized;
	char* name;
	char* description;
	char** dependencies;
} module_t;

module_t modules[1024];

module_t MODULE(char* name, char* description);

void INIT(module_t module);

void DISABLE(module_t module);
void ENABLE(module_t module);

void DEPS(module_t module, char** dependencies);

#endif