

%token KW_CHAR           
%token KW_INT           
%token KW_FLOAT           

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

%token TK_IDENTIFIER     

%token LIT_INT       
%token LIT_REAL         
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





program: 	decGen
	;
	
decGen: 	dec ';' decGen
	| 		code codeGen
	|
	;
	
dec: 		type TK_IDENTIFIER '=' value
	| 		type TK_IDENTIFIER'['LIT_INT']' vector
	|		type TK_IDENTIFIER '('param')'
	;
	
param: 		type TK_IDENTIFIER ',' param
	|		type TK_IDENTIFIER
	|
	;

codeGen:	code
	|
	;

code:		KW_CODE TK_IDENTIFIER cmd
	;

cmd:		block
	|		flowCmd
	|		atrb ';'
	|		print ';'
	|		return ';'
	|		';'
	;

block:		'{' cmdList '}'
	;

cmdList:	cmd cmdList 
	|
	;

atrb:		TK_IDENTIFIER '=' exp
	|		TK_IDENTIFIER'['exp']' '=' exp
	;

print:		KW_PRINT LIT_STRING
	|		KW_PRINT exp
	;

return:		KW_RETURN exp
	;

flowCmd:	KW_IF '('exp')' cmd else
	|		KW_WHILE '('exp')' cmd
	;

else:		KW_ELSE cmd
	|
	;

exp:		'('exp')'
	|		exp '+' exp
	|		exp '-' exp
	|		exp '*' exp
	|		exp '/' exp
	|		exp '<' exp
	|		exp '>' exp
	|		exp OPERATOR_LE exp
	|		exp OPERATOR_GE exp
	|		exp OPERATOR_EQ exp
	|		exp OPERATOR_DIF exp
	|		exp '&' exp
	|		exp '|' exp
	|		exp '~' exp
	|		TK_IDENTIFIER'('args')'
	|		KW_INPUT'('type')'
	|		TK_IDENTIFIER
	|		TK_IDENTIFIER'['exp']'
	|		LIT_INT
	|		LIT_CHAR
	|		LIT_REAL
	;

args:		exp ',' args
	|		exp
	;

vector: 	value vector
	|
	;

type: 		KW_CHAR
	| 		KW_INT
	| 		KW_FLOAT
	;
	
value: 		LIT_INT
	| 		LIT_REAL
	| 		LIT_CHAR
	;

	




%%



int yyerror ()
{
	fprintf(stderr,"Syntax error at line %d.\n", getLineNumber());
	exit(3);
}



