/*
 
 */

%{
#include<stdio.h>
#include "tree.h"
extern FILE *yyin;
struct node * root;
%}

%union {struct node * ndptr; double value; char name[10];}

%start start
%token <ndptr> IDFR
%type <ndptr> exp
%token <value> DIGT
%left '*' '/'
%left '+' '-' 

%%
start: exp	{ root = pop();}
;
exp: exp '+' exp
{
	struct node * r = pop();
	struct node * l = pop();
	struct node * t = node_create("+", l, r);
	push(t);
}
| exp '-' exp
{
	struct node * r = pop();
	struct node * l = pop();
	struct node * t = node_create("-", l, r);
	push(t);
}
| exp '*' exp
{
	struct node * r = pop();
	struct node * l = pop();
	struct node * t = node_create("*", l, r);
	push(t);
}
| exp '/' exp
{
	struct node * r = pop();
	struct node * l = pop();
	struct node * t = node_create("/", l, r);
	push(t);
}
| '(' exp ')'
{
	$$ = $2;
}
| DIGT
{
	char ch[21];
	gcvt((double) $1, 21, ch);
	struct node * t = node_create(ch, NULL, NULL);
	push(t);
}
;
%%

void main(int argc, char ** argv)
{	 
	yyin=fopen(argv[1],"r");   	
	yyparse();
	printf("\nPreorder:\n");
	display_pre(root);	
	printf("\nInorder:\n");
	display_in(root);
	printf("\nPostorder:\n");
	display_post(root);
	printf("\n");
}
void yyerror()
{
   printf("Program is Invalid\n");  
}




