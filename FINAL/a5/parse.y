%{
#include<stdio.h>
#include<string.h>
extern FILE *yyin;

char a[10],b[10],c[10],x[10],y[10],tv[10];
int s=0;
int j,i,temp=0;
struct symbol
{
char type[30];
char id[30];
int val;
}sym[30];	

struct quadruple
{
char op[2];
char op1[30];
char op2[30];
char res[30];
}quad[30];

%}
%union{int num;char *string;}

%token<string> TYPE
%token<string> ID
%type<string> exp
%token<num> NUMBER



%start pgm
%token MAIN OB CB OCB CCB FOR REOP INCOP WHILE IF ELSE 

%left '+' '-' 
%left '*' '/'
//%nonassoc LOWER_THAN_ELSE	//for conflict of if-else whether to reduce IF or push ELSE to stack
//%nonassoc ELSE

%%

pgm: MAIN OB CB OCB dec_list stmt_list CCB {printf("Valid program\n");}
;                              

dec_list:declare dec_list |	{printf("Valid data dec\n");}
;

declare: TYPE {strcpy(a,$1);} var ';'	
;

var: var ',' ID		  {strcpy(sym[s].id,$3);strcpy(sym[s].type,a);sym[s].val=0;s++;}
	| ID 		  {strcpy(sym[s].id,$1);strcpy(sym[s].type,a);sym[s].val=0;s++;}
	| ID '=' NUMBER   {strcpy(sym[s].id,$1);strcpy(sym[s].type,a);sym[s].val=$3;s++;}
	| ID ',' var 	  {strcpy(sym[s].id,$1);strcpy(sym[s].type,a);sym[s].val=0;s++;}	

;

stmt_list:astmt stmt_list|forst stmt_list| whilest stmt_list|decision stmt_list|	{printf("Valid stmt\n");}
;
astmt:ID '=' exp ';' {quad_entry("=",$3,"--",$1);printf("valid assignment statement\n");}
;
exp: 
	
		ID {$$=$1;} 

		| NUMBER  {sprintf(y,"%ld",$1);$$=y;} 
		
	|	exp '+' exp {
		sprintf(x,"%ld",temp);
		strcpy(tv,"t");
		strcat(tv,x);
		quad_entry("+",$1,$3,tv);
		temp++;
		$$=strdup(tv);
		//quad_entry("=",tv,"--",b);
		
		
}


 | exp '-' exp {
 		sprintf(x,"%ld",temp);
		strcpy(tv,"t");
		strcat(tv,x);
		quad_entry("-",$1,$3,tv);
		temp++;
		$$=strdup(tv);
		}

 |  exp '*' exp  {
 		sprintf(x,"%ld",temp);
		strcpy(tv,"t");
		strcat(tv,x);
		quad_entry("*",$1,$3,tv);
		temp++;
		$$=strdup(tv);
		}
		
		
 |  exp '/' exp  { 
		sprintf(x,"%ld",temp);
		strcpy(tv,"t");
		strcat(tv,x);
		quad_entry("/",$1,$3,tv);
		//quad_entry("=",tv,"--",b);
		temp++;
		$$=strdup(tv);
		}
	
;

forst: FOR OB ID '=' NUMBER ';' con ';'CB OCB  CCB  { printf("Valid for\n");}
;

whilest:WHILE OB con CB OCB  CCB { printf("Valid while\n"); }
;

decision: IF OB con CB OCB  CCB { printf("Valid if\n"); }  /*%prec LOWER_THAN_ELSE*/
	| IF OB con CB OCB  CCB ELSE OCB CCB { printf("Valid if and else\n"); }
;
con: ID REOP NUMBER  { printf("Valid cond\n");}
;


%%

void main()
{
	 
  	yyin=fopen("sample.c","r");
   	
  	 yyparse();
	



printf("---------------SYMBOL TABLE----------------\n");

for(j=0;j<s;j++)
{

printf("%s              %s           %d",sym[j].type,sym[j].id,sym[j].val);
printf("\n");
 }


printf("---------------QUADRAPLE TABLE----------------\n");
printf("Operand			Op1			Op2			Res\n");

for(j=0;j<i;j++)
{

printf("%s			%s			%s			%s",quad[j].op,quad[j].op1,quad[j].op2,quad[j].res);
printf("\n");
 }
	
  	
}

void quad_entry(char operator[10],char ope1[10],char ope2[10],char result[10])
{
		strcpy(quad[i].op,operator);
		strcpy(quad[i].op1,ope1);
		strcpy(quad[i].op2,ope2);
		strcpy(quad[i].res,result);
		i++;
}

void yyerror()
{
   printf("Program is Invalid\n");
   
}



