// Author: Vinicius Fraga Coromberque - 00302369
// 26/10/2023

int main(int argc, char **argv)
{
    int tok;

    if (argc < 2)
    {
        fprintf(stderr, "Call: ./a.out file_name\n");
        exit(1);
    }

    yyin = fopen(argv[1], "r");

    hashInit();

    while (running)
    {
        tok = yylex();

        if (running == 0)
        {
            break;
        }

        switch (tok)
        {
        case KW_CHAR:
            printf("KW_CHAR\n");
            break;
        case KW_INT:
            printf("KW_INT\n");
            break;
        case KW_FLOAT:
            printf("KW_FLOAT\n");
            break;
        case KW_CODE:
            printf("KW_CODE\n");
            break;
        case KW_IF:
            printf("KW_IF\n");
            break;
        case KW_ELSE:
            printf("KW_ELSE\n");
            break;
        case KW_WHILE:
            printf("KW_WHILE\n");
            break;
        case KW_INPUT:
            printf("KW_INPUT\n");
            break;
        case KW_PRINT:
            printf("KW_PRINT\n");
            break;
        case KW_RETURN:
            printf("KW_RETURN\n");
            break;
        case OPERATOR_LE:
            printf("OPERATOR_LE\n");
            break;
        case OPERATOR_GE:
            printf("OPERATOR_GE\n");
            break;
        case OPERATOR_EQ:
            printf("OPERATOR_EQ\n");
            break;
        case OPERATOR_DIF:
            printf("OPERATOR_DIF\n");
            break;
        case TK_IDENTIFIER:
            printf("TK_IDENTIFIER\n");
            break;
        case LIT_INT:
            printf("LIT_INT\n");
            break;
        case LIT_REAL:
            printf("LIT_REAL\n");
            break;
        case LIT_CHAR:
            printf("LIT_CHAR\n");
            break;
        case LIT_STRING:
            printf("LIT_STRING\n");
            break;
        case TOKEN_ERROR:
            printf("TOKEN_ERROR\n");
            break;
        default:
            printf("Encontrei %c\n", yytext[0]);
            break;
        }
    }
    printf("Main done %d linhas\n", lineNumber);
    hashPrint();
    exit(0);
}