#include <stdio.h>
#include <compiler.h>

int main()
{
	int res = compile_file("./test.c", "./test", 0);
	if (res == COMPILER_FILE_COMPILED_OK) {
		printf("everything compiled fine\n");
	} else if (res == COMPILE_FAILED_WITH_ERRORS) {
		printf(" compile failed\n");      
	} else {
		printf("Unknown response for compile file\n");
	}

	return 0;
}
