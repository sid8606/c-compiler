#include "compiler.h"
#include "helpers/vector.h"

struct lex_process* lex_process;

static char peekc()
{
    return lex_process->function->peek_char(lex_process);
}

static void pushc(char c)
{
    return lex_process->function->push_char(lex_process, c);
}

struct token* token_read()
{
    struct token* token = NULL;

    char c =peekc();

    switch (c) {
    case EOF:
        //We have finished lexical analysis on this file
        break;
    
    default:
        compiler_error(lex_process->compiler, "Unexpected token\n");
    }

    return token;
}

int lex(struct lex_process* process)
{
    process->current_expression_count = 0;
    process->parentheses_buffer = NULL;
    lex_process = process;

    struct token* token = read_next_token();

    while (token) {
        vetcor_push(process->token_vec, token);
        token = read_next_token();
    }
    
    return 0;
}