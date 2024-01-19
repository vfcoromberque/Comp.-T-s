%{
	#include "hash.h"
	#include "ast.h"
	#include "y.tab.h"
	int running = 1;
	int lineNumber = 1;
	int getLineNumber()
	{
		return lineNumber;
	}
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

[a-zA-Z0-9_]*[a-zA-Z_]+[a-zA-Z0-9_]*		{ yylval.symbol = hashInsert(yytext, SYMBOL_ID, 0); return TK_IDENTIFIER;}

[0-9]+						{ yylval.symbol = hashInsert(yytext, SYMBOL_LIT_INT, 0); return LIT_INT;}
([0-9]+\.[0-9]+)			{ yylval.symbol = hashInsert(yytext, SYMBOL_LIT_FLOAT, 0); return LIT_REAL;}
'.'							{ yylval.symbol = hashInsert(yytext, SYMBOL_LIT_CHAR, 0); return LIT_CHAR;}

\"(\\.|[^"])*\"             { yylval.symbol = hashInsert(yytext, SYMBOL_LIT_STRING, 0); return LIT_STRING;}


"///"						{BEGIN(COMMENT);}
"//".*

"\n"						{++lineNumber;}
[ \t,]

.							{return TOKEN_ERROR;}


<COMMENT>"\\\\\\"			{BEGIN(INITIAL);}
<COMMENT>.
<COMMENT>"\n"				{++lineNumber;}


%%

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




