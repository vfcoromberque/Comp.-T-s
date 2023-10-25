int main(int argc, char **argv)
{
	int tok;
	
	if(argc < 2)
	{
		fprintf(stderr,"Call: ./a.out file_name\n");
		exit(1);
	}
	
	yyin = fopen(argv[1],"r");
	
	hashInit();
	
	while(running)
	{
		tok = yylex();
		
		if(running == 0){
			break;
		}
		
		switch(tok)
		{
			case KW_CARA: printf("KW_CARA\n"); break;
			case KW_SE: printf("KW_SE\n"); break;
			case OPERATOR_LE: printf("OPERATOR_LE\n"); break;
			case LIT_INTEIRO: printf("LIT_INTEIRO\n"); break;
			case LIT_FLOAT: printf("LIT_FLOAT\n"); break;
			case LIT_CHAR: printf("LIT_CHAR\n"); break;
			case TK_IDENTIFIER: printf("TK_IDENTIFIER\n"); break;
			case LIT_STRING: printf("LIT_STRING\n"); break;
			case TOKEN_ERROR: printf("TOKEN_ERROR\n"); break;
			default: printf("Encontrei %c\n", yytext[0]); break;
		}
	}
	printf("Main done %d linhas\n", lineNumber);
	hashPrint();
	exit(0);
}