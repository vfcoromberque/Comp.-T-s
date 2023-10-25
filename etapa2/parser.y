
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

%token TK_IDENTIFIER     

%token LIT_INTEIRO       
%token LIT_FLOAT         
%token LIT_CHAR          
%token LIT_STRING        

%token TOKEN_ERROR

%left TK_IDENTIFIER

%left '(' ')' '[' ']' '{' '}'

%left '&' '|' '~'
%left '<' '>' '='
%left OPERATOR_LE OPERATOR_GE OPERATOR_EQ OPERATOR_DIF
%left '+' '-'
%left '*' '/'





%%





programa: declarationl
	;
	
declarationl: declaration ';' declarationl
	| funct declarationl
	|
	;
	
declaration: tipo TK_IDENTIFIER '=' valor
	| tipo TK_IDENTIFIER'['LIT_INTEIRO']' valorl
	;
	
funct: tipo TK_IDENTIFIER '('param')' body
	;
	
param: tipo TK_IDENTIFIER param
	|
	;
	
lcmd: cmd ';' lcmd
	| ecmd
	|
	;

ecmd: cmd;
	
cmd:  body
	| KW_ENTAUM '{' lcmd '}' entaum
	| TK_IDENTIFIER '=' exp
	| TK_IDENTIFIER'[' exp ']' '=' exp
	| KW_ESCREVA escreva
	| enquanto
	| funct
	| KW_RETORNE exp
	|
	;
	
exp: TK_IDENTIFIER
	| TK_IDENTIFIER '[' valor ']'
	| TK_IDENTIFIER '[' TK_IDENTIFIER ']'
	| valor
	| chamada
	| KW_ENTRADA
	| exp '=' exp
	| exp '-' exp
	| exp '+' exp
	| exp '*' exp
	| exp '/' exp
	| exp '<' exp
	| exp '>' exp
	| exp OPERATOR_LE exp
	| exp OPERATOR_GE exp
	| exp OPERATOR_EQ exp
	| exp OPERATOR_DIF exp
	| exp '&' exp
	| exp '|' exp
	| exp '~' exp
	| '(' exp ')'
	;
	
entaum: se
	| KW_SENAUM lcmd se
	;
	
se: KW_SE '(' exp ')'
	;

chamada: TK_IDENTIFIER'(' in ')'
	;

in:	TK_IDENTIFIER in
	| valor in
	| 
	;
	
enquanto: '{' lcmd '}' KW_ENQUANTO '(' exp ')'
	
escreva: LIT_STRING escreva
	| exp escreva
	|
	;
	
valorl: valor valorl
	|
	;

tipo: KW_CARA
	| KW_INTE
	| KW_REAL
	;
	
valor: LIT_INTEIRO
	| LIT_FLOAT
	| LIT_CHAR
	;
	
body: '{' lcmd '}'
	|
	;






%%







int yyerror ()
{
	fprintf(stderr,"Syntax error at line %d.\n", getLineNumber());
	exit(3);
}



