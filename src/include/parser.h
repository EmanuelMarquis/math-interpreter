// TODO: abstract mpc parser
#include "mpc.h"

typedef struct tParser Parser;

struct tParser
{
    mpc_parser_t *Expr;
    mpc_parser_t *Prod;
    mpc_parser_t *Value;
    mpc_parser_t *Maths;
};

void initParser(Parser *parser) {
    parser->Expr  = mpc_new("expression");
    parser->Prod  = mpc_new("product");
    parser->Value = mpc_new("value");
    parser->Maths = mpc_new("maths");
}

void setGrammar(Parser *parser, char *fileName) {
    mpca_lang_contents(MPCA_LANG_DEFAULT, fileName,
        parser->Expr, parser->Prod, parser->Value, parser->Maths, NULL);
}

void closeParser(Parser *parser) {
    mpc_cleanup(4, 
        parser->Expr,
        parser->Prod, 
        parser->Value, 
        parser->Maths
    );
}