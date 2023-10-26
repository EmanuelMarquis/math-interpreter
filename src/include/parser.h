// TODO: abstract mpc parser
#include "mpc.h"

typedef struct tParser Parser;

struct tParser
{
    mpc_parser_t *Arith;
    mpc_parser_t *Value;
    mpc_parser_t *Stmt;
    mpc_parser_t *EndStmt;
    mpc_parser_t *ArithOp;
};

void initParser(Parser *parser) {
    parser->Arith = mpc_new("arith");
    parser->Value = mpc_new("value");
    parser->Stmt  = mpc_new("stmt");
    parser->EndStmt = mpc_new("end_stmt");
    parser->ArithOp = mpc_new("arith_op");
}

void setGrammar(Parser *parser, char *fileName) {
    mpca_lang_contents(MPCA_LANG_DEFAULT, fileName,
        parser->Arith, 
        parser->Value, 
        parser->Stmt,
        parser->EndStmt,
        parser->ArithOp,
    NULL);
}

void closeParser(Parser *parser) {
    mpc_cleanup(5, 
        parser->Arith,
        parser->Value,
        parser->Stmt,
        parser->EndStmt,
        parser->ArithOp
    );
}