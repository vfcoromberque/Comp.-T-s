%{
	#include "hash.h"
	#include "ast.h"
	#include "parser.tab.h"
	int running = 1;
	int lineNumber = 1;
	int getLineNumber() { return lineNumber; }
%}

%x COMMENT


%%


cara						{return KW_CARA;}
inte						{return KW_INTE;}
real						{return KW_REAL;}

se							{return KW_SE;}
entaum						{return KW_ENTAUM;}
senaum						{return KW_SENAUM;}
enquanto					{return KW_ENQUANTO;}
entrada						{return KW_ENTRADA;}
escreva						{return KW_ESCREVA;}
retorne						{return KW_RETORNE;}

[-;()\[\]{}=+*/<>&|~]		{return yytext[0];}

"<="						{return OPERATOR_LE;}
">="						{return OPERATOR_GE;}
"=="						{return OPERATOR_EQ;}
"!="						{return OPERATOR_DIF;}

[a-z._][a-z0-9._]*			{yylval.symbol = hashInsert(yytext, TK_IDENTIFIER); return TK_IDENTIFIER;}

[0-9]+						{yylval.symbol = hashInsert(yytext, LIT_INTEIRO); return LIT_INTEIRO;}
([0-9]+\.[0-9]+)			{yylval.symbol = hashInsert(yytext, LIT_FLOAT); return LIT_FLOAT;}
'.'							{yylval.symbol = hashInsert(yytext, LIT_CHAR); return LIT_CHAR;}

\"(\\.|[^"])*\"             {yylval.symbol = hashInsert(yytext, LIT_STRING); return LIT_STRING;   }


"///"						{BEGIN(COMMENT);}
"//".*

"\n"						{++lineNumber;}
[ \t,]

.							{return TOKEN_ERROR;}


<COMMENT>"\\\\\\"			{BEGIN(INITIAL);}
<COMMENT>.
<COMMENT>"\n"				{++lineNumber;}


%%

//int getLineNumber(void)
//{
//	return lineNumber;
//}

int initMe(void)
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




