#include <stdio.h>
#include "./include/parser.h"

int main() {
    Parser parser;

    initParser(&parser);
    setGrammar(&parser, "grammar.txt");

    mpc_result_t r;

    if (mpc_parse_contents("readme.maths", parser.Stmt, &r)) {
        mpc_ast_print(r.output);
        mpc_ast_delete(r.output);
    } else {
        mpc_err_print(r.error);
        mpc_err_delete(r.error);
    }

    closeParser(&parser);

    return 0;
}