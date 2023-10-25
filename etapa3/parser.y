%{

	#include "hash.h"
	#include "ast.h"
	int yyerror ();
	int getLineNumber();
	int yylex();
	AST *astCreate(int type, HASH_NODE *symbol, AST *s0, AST *s1, AST *s2, AST *s3);
	void astPrint(AST *node, int level);

%}

%union
{
	HASH_NODE *symbol;
	AST *ast;
}

%token KW_CARA           
%token KW_INTE           
%token KW_REAL           

%token KW_SE             
%token KW_ENTAUM         
%token KW_SENAUM         
%token KW_ENQUANTO       
%token KW_ENTRADA        
%token KW_ESCREVA        
%token KW_RETORNE        

%token OPERATOR_LE       
%token OPERATOR_GE       
%token OPERATOR_EQ       
%token OPERATOR_DIF      

%token<symbol> TK_IDENTIFIER     

%token<symbol> LIT_INTEIRO       
%token<symbol> LIT_FLOAT         
%token<symbol> LIT_CHAR          
%token<symbol> LIT_STRING        

%token TOKEN_ERROR

%type<ast> valor
%type<ast> exp
%type<ast> chamada
%type<ast> in
%type<ast> cmd
%type<ast> body
%type<ast> fixedbody
%type<ast> entaum
%type<ast> escreva
%type<ast> enquanto
%type<ast> identf
%type<ast> funct
%type<ast> tipo
%type<ast> param
%type<ast> se
%type<ast> ecmd
%type<ast> lcmd
%type<ast> declarationl
%type<ast> declaration
%type<ast> vect
%type<ast> number
%type<ast> lparam
%type<ast> valorl
%type<ast> programa
%type<ast> eq

%left TK_IDENTIFIER

%left '(' ')' '[' ']' '{' '}'

%left '&' '|' '~'
%left '<' '>' '='
%left OPERATOR_LE OPERATOR_GE OPERATOR_EQ OPERATOR_DIF
%left '+' '-'
%left '*' '/'





%%



p: programa											{ astPrint($1,0); }
	;

programa: declarationl								{ $$ = $1; }
	;
	
declarationl: declaration ';' declarationl			{ $$ = astCreate(AST_DEC_LIST,0,$1,$3,0,0); }
	| funct declarationl							{ $$ = $1; }
	|												{ $$ = 0; }
	;
	
declaration: tipo eq								{ $$ = astCreate(AST_DECLARE,0,$1,$2,0,0); }
	| tipo identf vect								{ $$ = astCreate(AST_DECLARE,0,$1,$2,$3,0); }
	;

eq: identf '=' valor								{ $$ = astCreate(AST_EQ,0,$1,$3,0,0); }
	;

vect: '['number']' valorl							{ $$ = astCreate(AST_VECT,0,$2,$4,0,0); }
	;
	
funct: tipo identf '('lparam')' body				{ $$ = astCreate(AST_FUNCT,0,$1,$2,$4,$6); }
	;

number: LIT_INTEIRO									{ $$ = astCreate(AST_SYMBOL,$1,0,0,0,0); }
	;

lparam: lparam param								{ $$ = $2; }
	|												{ $$ = 0; }
	;
	
param: tipo identf									{ $$ = astCreate(AST_PARAM,0,$1,$2,0,0); }
	|												{ $$ = 0; }
	;
	
lcmd: cmd ';' lcmd									{ $$ = $1; }
	| ecmd											{ $$ = $1; }
	|												{ $$ = 0; }
	;

ecmd: cmd											{ $$ = $1; }
	;
	
cmd:  body											{ $$ = $1; }
	| KW_ENTAUM '{' lcmd '}' entaum					{ $$ = astCreate(AST_KW_ENTAUM,0,$3,$5,0,0); }
	| exp											{ $$ = $1; }
	| KW_ESCREVA escreva							{ $$ = astCreate(AST_KW_ESCREVA,0,$2,0,0,0); }
	| fixedbody enquanto							{ $$ = astCreate(AST_BODY,0,$1,$2,0,0); }
	| funct											{ $$ = $1; }
	| KW_RETORNE exp								{ $$ = astCreate(AST_KW_RETORNE,0,$2,0,0,0); }
	|												{ $$ = 0; }
	;


	
exp: TK_IDENTIFIER									{ $$ = astCreate(AST_SYMBOL,$1,0,0,0,0); }
	| TK_IDENTIFIER '[' valor ']'					{ $$ = astCreate(AST_SYMBOL,$1,$3,0,0,0); }
	| TK_IDENTIFIER '[' identf ']'				{ $$ = astCreate(AST_SYMBOL,$1,$3,0,0,0); }
	| valor											{ $$ = $1; }
	| chamada										{ $$ = $1; }
	| KW_ENTRADA									{ $$ = astCreate(AST_KW_ENTR,0,0,0,0,0); }
	| exp '=' exp									{ $$ = astCreate(AST_EQ,0,$1,$3,0,0); }
	| exp '-' exp									{ $$ = astCreate(AST_SUB,0,$1,$3,0,0); }
	| exp '+' exp									{ $$ = astCreate(AST_ADD,0,$1,$3,0,0); }
	| exp '*' exp									{ $$ = astCreate(AST_MUL,0,$1,$3,0,0); }
	| exp '/' exp									{ $$ = astCreate(AST_DIV,0,$1,$3,0,0); }
	| exp '<' exp									{ $$ = astCreate(AST_LT,0,$1,$3,0,0); }
	| exp '>' exp									{ $$ = astCreate(AST_GT,0,$1,$3,0,0); }
	| exp OPERATOR_LE exp							{ $$ = astCreate(AST_OP_LE,0,$1,$3,0,0); }
	| exp OPERATOR_GE exp							{ $$ = astCreate(AST_OP_GE,0,$1,$3,0,0); }
	| exp OPERATOR_EQ exp							{ $$ = astCreate(AST_OP_EQ,0,$1,$3,0,0); }
	| exp OPERATOR_DIF exp							{ $$ = astCreate(AST_OP_DIF,0,$1,$3,0,0); }
	| exp '&' exp									{ $$ = astCreate(AST_AND,0,$1,$3,0,0); }
	| exp '|' exp									{ $$ = astCreate(AST_OR,0,$1,$3,0,0); }
	| '~' exp										{ $$ = astCreate(AST_NOT,0,$2,0,0,0); }
	| '(' exp ')'									{ $$ = astCreate(AST_ENCLOSING,0,$2,0,0,0); }
	;
	
entaum: se											{ $$ = $1; }
	| KW_SENAUM lcmd se								{ $$ = astCreate(AST_KW_SENAUM,0,$2,$3,0,0); }
	;
	
se: KW_SE '(' exp ')'								{ $$ = astCreate(AST_KW_SE,0,$3,0,0,0); }
	;

chamada: TK_IDENTIFIER'(' in ')'					{ $$ = astCreate(AST_SYMBOL,$1,$3,0,0,0); }
	;

in:	TK_IDENTIFIER in								{ $$ = astCreate(AST_SYMBOL,$1,$2,0,0,0); }
	| valor in										{ $$ = $1; }
	| 												{ $$ = 0; }
	;
	
enquanto: KW_ENQUANTO '(' exp ')'					{ $$ = astCreate(AST_KW_ENQUANTO,0,$3,0,0,0); }
	;
	
escreva: LIT_STRING escreva							{ $$ = astCreate(AST_SYMBOL,$1,$2,0,0,0); }
	| exp escreva									{ $$ = $1; }
	|												{ $$ = 0; }
	;
	
valorl: valor valorl								{ $$ = $1; }
	|												{ $$ = 0; }
	;

tipo: KW_CARA										{ $$ = astCreate(AST_KW_CARA,0,0,0,0,0); }
	| KW_INTE										{ $$ = astCreate(AST_KW_INTE,0,0,0,0,0); }
	| KW_REAL										{ $$ = astCreate(AST_KW_REAL,0,0,0,0,0); }
	;
	
valor: LIT_INTEIRO						{ $$ = astCreate(AST_SYMBOL,$1,0,0,0,0); }
	| LIT_FLOAT							{ $$ = astCreate(AST_SYMBOL,$1,0,0,0,0); }
	| LIT_CHAR							{ $$ = astCreate(AST_SYMBOL,$1,0,0,0,0); }
	;
	
body: '{' lcmd '}'						{ $$ = astCreate(AST_BODY,0,$2,0,0,0); }
	|									{ $$ = 0; }
	;


fixedbody: '{' lcmd '}'						{ $$ = astCreate(AST_BODY,0,$2,0,0,0); }
	;

identf: TK_IDENTIFIER						{ $$ = astCreate(AST_SYMBOL,$1,0,0,0,0); }
	;



%%







int yyerror ()
{
	fprintf(stderr,"Syntax error at line %d.\n", getLineNumber());
	exit(3);
}



