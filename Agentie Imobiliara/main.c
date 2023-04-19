#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#include "teste.h"
#include "ui.h"

int main() {
	ruleaza_toate_testele();
	run();
	_CrtDumpMemoryLeaks();
	return 0;
}