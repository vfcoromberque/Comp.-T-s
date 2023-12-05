%{
	#include "hash.h"
	#include "y.tab.h"
	int running = 1;
	int lineNumber = 1;
	int getLineNumber(void)
	{
		return lineNumber;
	}
	int yyparse();
	int yyerror();
	int yylex();
%}

%x COMMENT


%%


char						    {return KW_CHAR;}
int 						    {return KW_INT;}
float    					    {return KW_FLOAT;}

code                            {return KW_CODE;}

if							    {return KW_IF;}
else						    {return KW_ELSE;}
while						    {return KW_WHILE;}
input					        {return KW_INPUT;}
print						    {return KW_PRINT;}
return						    {return KW_RETURN;}

[-,;()\[\]{}=+*/%<>&|~]		    {return yytext[0];}

"<="						    {return OPERATOR_LE;}
">="						    {return OPERATOR_GE;}
"=="						    {return OPERATOR_EQ;}
"!="						    {return OPERATOR_DIF;}

[a-zA-Z0-9_]*[a-zA-Z_]+[a-zA-Z0-9_]*		{hashInsert(yytext, TK_IDENTIFIER); return TK_IDENTIFIER;}

[0-9]+						{hashInsert(yytext, LIT_INT); return LIT_INT;}
([0-9]+\.[0-9]+)			{hashInsert(yytext, LIT_REAL); return LIT_REAL;}
'.'							{hashInsert(yytext, LIT_CHAR); return LIT_CHAR;}

\"(\\.|[^"])*\"             {hashInsert(yytext, LIT_STRING); return LIT_STRING;}


"///"						{BEGIN(COMMENT);}
"//".*

"\n"						{++lineNumber;}
[ \t,]

.							{return TOKEN_ERROR;}


<COMMENT>"\\\\\\"			{BEGIN(INITIAL);}
<COMMENT>.
<COMMENT>"\n"				{++lineNumber;}


%%

#include "y.tab.c"
#include "main.c"
#include "hash.c"

void initMe(void)
{
	hashInit();
}

int isRunning(void)
{
	return running;
}

int yywrap(void)
{
	running = 0;
	return 1;
}




