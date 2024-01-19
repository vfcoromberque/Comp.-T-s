%{
	#include "hash.h"
	#include "ast.h"
	#include "semantic.h"
	#include <stdlib.h>

	int yylex();
	int yyerror();
	int getLineNumber();
	extern int verifySemantic();
	extern int SemanticErrors;

	AST* root;
%}

%union
{
	HASH_NODE *symbol;
	AST *ast;
}

%token<symbol> KW_CHAR           
%token<symbol> KW_INT           
%token<symbol> KW_FLOAT           

%token KW_CODE

%token KW_IF         
%token KW_ELSE         
%token KW_WHILE       
%token KW_INPUT        
%token KW_PRINT        
%token KW_RETURN        

%token OPERATOR_LE       
%token OPERATOR_GE       
%token OPERATOR_EQ       
%token OPERATOR_DIF      

%token<symbol> TK_IDENTIFIER     

%token<symbol> LIT_INT       
%token<symbol> LIT_REAL         
%token<symbol> LIT_CHAR          
%token<symbol> LIT_STRING        

%token TOKEN_ERROR

%type<ast> exp
%type<ast> value
%type<ast> args
%type<ast> type
%type<ast> atrb
%type<ast> id
%type<ast> veccall
%type<ast> cmd
%type<ast> block
%type<ast> flowCmd
%type<ast> print
%type<ast> return
%type<ast> cmdList
%type<ast> string
%type<ast> codeGen
%type<ast> decGen
%type<ast> dec
%type<ast> int
%type<ast> param
%type<ast> vector
%type<ast> cmdStart
%type<ast> program


%left TK_IDENTIFIER

%left '(' ')' '[' ']' '{' '}'

%left '&' '|' '~'
%left '<' '>' '='
%left OPERATOR_LE OPERATOR_GE OPERATOR_EQ OPERATOR_DIF
%left '+' '-'
%left '*' '/'





%%





program: 	decGen							{ root = $$; astPrint($1, 0); SemanticErrors = verifySemantic($1);}
	;
	
decGen: 	dec ';' decGen					{ $$ = astCreate(AST_DEC, 0, $1, $3, 0, 0, getLineNumber()); }
	| 		codeGen							{ $$ = $1; }
	|										{ $$ = 0; }
	;
	
dec: 		type id '=' value				{ $$ = astCreate(AST_IDDEC, 0, $1, $2, $4, 0, getLineNumber());}
	| 		type id'['int']' vector			{ $$ = astCreate(AST_VECDEC, 0, $1, $2, $4, $6, getLineNumber());}
	|		type id '('param')'				{ $$ = astCreate(AST_FOODEC, 0, $1, $2, $4, 0, getLineNumber());}
	;
	
param: 		type id ',' param				{ $$ = astCreate(AST_PARAM, 0, $1, $2, $4, 0, getLineNumber());}
	|		type id							{ $$ = astCreate(AST_PARAM, 0, $1, $2, 0, 0, getLineNumber());}
	|										{ $$ = 0; }
	;

codeGen:	KW_CODE id cmdStart codeGen						{ $$ = astCreate(AST_CODE, 0, $2, $3, $4, 0, getLineNumber()); }
	|		KW_CODE id cmdStart								{ $$ = astCreate(AST_CODE, 0, $2, $3, 0, 0, getLineNumber()); }
	;

cmd:		block								{ $$ = $1; }
	|		flowCmd								{ $$ = $1; }
	|		atrb ';'							{ $$ = $1; }
	|		print ';'							{ $$ = $1; }
	|		return ';'							{ $$ = $1; }
	|		';'									{ $$ = 0; }
	;

cmdStart:	cmd									{ $$ = astCreate(AST_CMD, 0, $1, 0, 0, 0, getLineNumber()); }
	;

block:		'{' cmdList '}'						{ $$ = astCreate(AST_CMDBLOCK, 0, $2, 0, 0, 0, getLineNumber()); }
	;

cmdList:	cmd cmdList 				{ $$ = astCreate(AST_CMD, 0, $1, $2, 0, 0, getLineNumber()); }
	|									{ $$ = 0;}
	;

atrb:		id '=' exp										{ $$ = astCreate(AST_ATTR, 0, $1, $3, 0, 0, getLineNumber()); }
	|		veccall '=' exp									{ $$ = astCreate(AST_VECATTR, 0, $1, $3, 0, 0, getLineNumber()); }
	;

print:		KW_PRINT string				{ $$ = astCreate(AST_PRINT, 0, $2, 0, 0, 0, getLineNumber()); }
	|		KW_PRINT exp				{ $$ = astCreate(AST_PRINT, 0, $2, 0, 0, 0, getLineNumber()); }
	;

return:		KW_RETURN exp				{ $$ = astCreate(AST_RETURN, 0, $2, 0, 0, 0, getLineNumber()); }
	;

flowCmd:	KW_IF '('exp')' cmdStart						{ $$ = astCreate(AST_IF, 0, $3, $5, 0, 0, getLineNumber()); }
	|		KW_IF '('exp')' cmdStart KW_ELSE cmdStart		{ $$ = astCreate(AST_IFELSE, 0, $3, $5, $7, 0, getLineNumber()); }
	|		KW_WHILE '('exp')' cmdStart						{ $$ = astCreate(AST_WHILE, 0, $3, $5, 0, 0, getLineNumber()); }
	;

exp:		'('exp')'					{ $$ = astCreate(AST_PRTHSIS, 0, $2, 0, 0, 0, getLineNumber()); }
	|		exp '+' exp					{ $$ = astCreate(AST_ADD, 0, $1, $3, 0, 0, getLineNumber()); }
	|		exp '-' exp					{ $$ = astCreate(AST_SUB, 0, $1, $3, 0, 0, getLineNumber()); }
	|		exp '*' exp					{ $$ = astCreate(AST_MUL, 0, $1, $3, 0, 0, getLineNumber()); }
	|		exp '/' exp					{ $$ = astCreate(AST_DIV, 0, $1, $3, 0, 0, getLineNumber()); }
	|		exp '<' exp					{ $$ = astCreate(AST_LSS, 0, $1, $3, 0, 0, getLineNumber()); }
	|		exp '>' exp					{ $$ = astCreate(AST_GTR, 0, $1, $3, 0, 0, getLineNumber()); }
	|		exp OPERATOR_LE exp			{ $$ = astCreate(AST_LE, 0, $1, $3, 0, 0, getLineNumber()); }
	|		exp OPERATOR_GE exp			{ $$ = astCreate(AST_GE, 0, $1, $3, 0, 0, getLineNumber()); }
	|		exp OPERATOR_EQ exp			{ $$ = astCreate(AST_EQ, 0, $1, $3, 0, 0, getLineNumber()); }
	|		exp OPERATOR_DIF exp		{ $$ = astCreate(AST_DIF, 0, $1, $3, 0, 0, getLineNumber()); }
	|		exp '&' exp					{ $$ = astCreate(AST_AND, 0, $1, $3, 0, 0, getLineNumber()); }
	|		exp '|' exp					{ $$ = astCreate(AST_OR, 0, $1, $3, 0, 0, getLineNumber()); }
	|		'~' exp						{ $$ = astCreate(AST_NOT, 0, $2, 0, 0, 0, getLineNumber()); }
	|		id'('args')'				{ $$ = astCreate(AST_FOOCALL, 0, $1, $3, 0, 0, getLineNumber());}
	|		KW_INPUT'('type')'			{ $$ = astCreate(AST_INPUT, 0, $3, 0, 0, 0, getLineNumber());}
	|		TK_IDENTIFIER				{ $$ = astCreate(AST_SYMBOL, $1, 0, 0, 0, 0, getLineNumber()); }
	|		veccall						{ $$ = $1;}
	|		LIT_INT						{ $$ = astCreate(AST_SYMBOL, $1, 0, 0, 0, 0, getLineNumber()); }
	|		LIT_CHAR					{ $$ = astCreate(AST_SYMBOL, $1, 0, 0, 0, 0, getLineNumber()); }
	|		LIT_REAL					{ $$ = astCreate(AST_SYMBOL, $1, 0, 0, 0, 0, getLineNumber()); }
	;

args:		exp ',' args				{ $$ = astCreate(AST_ARG, 0, $1, $3, 0, 0, getLineNumber()); }
	|		exp							{ $$ = astCreate(AST_ARG, 0, $1, 0, 0, 0, getLineNumber()); }
	;

vector: 	value vector				{ $$ = astCreate(AST_VECVAL, 0, $1, $2, 0, 0, getLineNumber()); }
	|									{ $$ = 0; }
	;

type: 		KW_CHAR						{ $$ = astCreate(AST_KWCHAR, 0, 0, 0, 0, 0, getLineNumber()); }
	| 		KW_INT						{ $$ = astCreate(AST_KWINT, 0, 0, 0, 0, 0, getLineNumber()); }
	| 		KW_FLOAT					{ $$ = astCreate(AST_KWFLOAT, 0, 0, 0, 0, 0, getLineNumber()); }
	;
	
value: 		LIT_INT						{ $$ = astCreate(AST_SYMBOL, $1, 0, 0, 0, 0, getLineNumber()); }
	| 		LIT_REAL					{ $$ = astCreate(AST_SYMBOL, $1, 0, 0, 0, 0, getLineNumber()); }
	| 		LIT_CHAR					{ $$ = astCreate(AST_SYMBOL, $1, 0, 0, 0, 0, getLineNumber()); }
	;

id:			TK_IDENTIFIER				{ $$ = astCreate(AST_SYMBOL, $1, 0, 0, 0, 0, getLineNumber()); }
	;

veccall:  	id'['exp']'					{ $$ = astCreate(AST_VECCALL, 0, $1, $3, 0, 0, getLineNumber());}
	;

string: 	LIT_STRING					{ $$ = astCreate(AST_SYMBOL, $1, 0, 0, 0, 0, getLineNumber());}
	;

int: 	LIT_INT							{ $$ = astCreate(AST_SYMBOL, $1, 0, 0, 0, 0, getLineNumber());}
	;

	




%%

void checkSemantic(){
  if(SemanticErrors > 0){
    fprintf(stderr, "%d Semantic Errors in Total.\n", SemanticErrors);
    exit(4);
  }
}

AST* getRoot(){
	return root;
}

int yyerror ()
{
	fprintf(stderr,"Syntax error at line %d.\n", getLineNumber());
	exit(3);
}



