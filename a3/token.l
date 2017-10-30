/*
*/
%{
#include<stdio.h>
#include<string.h>
int line=1;
int error_count=0,k=0,token_count=0;
struct token
{
int tok_line;
char token[30];
char lexeme[30];
}tok[30];	

struct symbol
{
char id[30];
}sym[30];	

struct err_list
{
int err_l;
char error[30];
char lex[30];
}err[30];
%}

TYPE int|float|string|char|double
KEYWORD main|printf|void
IDENTIFIER [a-zA-Z][a-zA-Z0-9]*
DIGIT [0-9]+

%%

"\n" line++;
[ \t]+ ;
{TYPE} {
	tok[token_count].tok_line=line; strcpy(tok[token_count].token,"TYPE");strcpy(tok[token_count].lexeme,yytext);token_count++;
	}
{KEYWORD}  {
	tok[token_count].tok_line=line; strcpy(tok[token_count].token,"KEYW");strcpy(tok[token_count].lexeme,yytext);token_count++;
	}
{IDENTIFIER} {
	tok[token_count].tok_line=line; strcpy(tok[token_count].token,"IDFR");strcpy(tok[token_count].lexeme,yytext);token_count++;
	int f=search(yytext);
	if(f==1){strcpy(sym[k].id,yytext);k++;}
	}
{DIGIT}  {
	tok[token_count].tok_line=line; strcpy(tok[token_count].token,"DIGT");strcpy(tok[token_count].lexeme,yytext);token_count++;
	}
"#include".* {
	tok[token_count].tok_line=line; strcpy(tok[token_count].token,"HDFL");strcpy(tok[token_count].lexeme,yytext);token_count++;
	}
";" {
	tok[token_count].tok_line=line; strcpy(tok[token_count].token,"DLIM");strcpy(tok[token_count].lexeme,yytext);token_count++;
	}
"/*"([\n]*|[\t]*|(.)*)+"*/" {
	tok[token_count].tok_line=line; strcpy(tok[token_count].token,"CMNT");strcpy(tok[token_count].lexeme,yytext);token_count++;
	}
"//".* {
	tok[token_count].tok_line=line; strcpy(tok[token_count].token,"CMNT");strcpy(tok[token_count].lexeme,yytext);token_count++;
	}
[0-9]+[a-zA-Z0-9]+	{
	err[error_count].err_l=line; strcpy(err[error_count].error,"Identifier starts with digit!");strcpy(err[error_count].lex,yytext);error_count++;
	}
\"[a-zA-Z0-9]+		{
	err[error_count].err_l=line; strcpy(err[error_count].error,"Unterminated string!");strcpy(err[error_count].lex,yytext);error_count++;
	}
"/*"([\n]*|[\t]*|(.)*)+	{
	err[error_count].err_l=line; strcpy(err[error_count].error,"Unterminated comment!");strcpy(err[error_count].lex,yytext);error_count++;
	}

%%

int search(char *lexeme)
{
int n;
for(n=0;n<k;n++)
{
if(strcmp(sym[n].id,lexeme)==0)
return 0;
}
return 1;
}

void main(int argc, char ** argv)
{
	FILE *fh;
	fh=fopen(argv[1],"r");
	yyin = fh;
	yylex();
	printf("---------------TOKEN TABLE----------------\n");
	printf("Line\t\tLexeme\t\tToken\n");
	int j;
	for(j=0;j<token_count;j++)
	{
		printf("%d\t\t%s\t\t%s", tok[j].tok_line, tok[j].lexeme, tok[j].token);
		printf("\n");
	}
	printf("---------------ERROR TABLE----------------\n");
	printf("Line\t\tError\n");
	for(j=0;j<error_count;j++)
	{
		printf("%d\t\t%s\t\t%s", err[j].err_l,err[j].error,err[j].lex);
		printf("\n");
	}
	printf("---------------SYMBOL TABLE----------------\n");
	printf("Identifier\n");
	for(j=0;j<k;j++)
	{
		//sym[j].sr++;
		printf("%s",sym[j].id);
		printf("\n");
	}
}

int yywrap()
{
	return 1;
}

