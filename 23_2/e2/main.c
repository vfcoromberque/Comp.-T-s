// Author: Vinicius Fraga Coromberque - 00302369
// 12/11/2023

int main(int argc, char **argv)
{
    int tok;

    if (argc < 2)
    {
        fprintf(stderr, "Call: ./a.out file_name\n");
        exit(1);
    }

    yyin = fopen(argv[1], "r");
    if (yyin == 0)
    {
        fprintf(stderr, "Cannot open file %s\n", argv[1]);
        exit(2);
    }

    hashInit();

    yyparse();

    printf("Main done %d linhas\n", lineNumber);

    hashPrint();

    exit(0);
}