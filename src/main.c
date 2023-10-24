#include <stdio.h>
#include "./include/mpc.h"

int main() {
    mpc_parser_t *Expr  = mpc_new("expression");
    mpc_parser_t *Prod  = mpc_new("product");
    mpc_parser_t *Value = mpc_new("value");
    mpc_parser_t *Maths = mpc_new("maths");

    mpca_lang_contents(MPCA_LANG_DEFAULT, "grammar.txt",
    Expr, Prod, Value, Maths, NULL);

    mpc_result_t r;

    if (mpc_parse("grammar", "1+1", Maths, &r)) {
        mpc_ast_print(r.output);
        mpc_ast_delete(r.output);
    } else {
        mpc_err_print(r.error);
        mpc_err_delete(r.error);
    }

    mpc_cleanup(4, Expr, Prod, Value, Maths);

    return 0;
}