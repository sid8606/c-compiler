#include "compiler.h"

struct lex_process_functions compiler_lex_fucntions = {
	.next_char = compile_process_next_char,
	.peek_char = compile_process_peek_char,
	.push_char = compile_process_push_char
};

void compiler_error(struct compile_process* compiler, const char* msg, ...)
{
	va_list args;

	va_start(args, msg);
	vfprintf(stderr, msg, args);
	va_end(args);

	fprintf(stderr, "On line%i, col %i in file %s\n", compiler->pos.line, compiler->pos.line, compiler->pos.filename);
	exit(-1);
}

void compiler_warning(struct compile_process* compiler, const char* msg, ...)
{
	va_list args;

	va_start(args, msg);
	vfprintf(stderr, msg, args);
	va_end(args);

	fprintf(stderr, "On line%i, col %i in file %s\n", compiler->pos.line, compiler->pos.line, compiler->pos.filename);
}

int compile_file(const char* filename, const char* filename_out, int flags)
{
	struct compile_process* process = compile_process_create(filename, filename_out, flags);

	if (!process) {
		return COMPILE_FAILED_WITH_ERRORS;
	}

	/*Perform lexiacal analysis*/
	struct lex_process* lex_process = lex_process_create(process, &compiler_lex_fucntions, NULL);
	if (!lex_process) {
		return COMPILE_FAILED_WITH_ERRORS;
	}

	if (lex(lex_process)!= LEXIACAL_ANALYSIS_ALL_OK) {
		return COMPILE_FAILED_WITH_ERRORS;
	}	

	/*perform parsing*/

	/*Perform code genration....*/

	return COMPILER_FILE_COMPILED_OK;
}
