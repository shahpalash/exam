/* original parser id follows */
/* yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20140715

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)
#define YYENOMEM       (-2)
#define YYEOF          0
#define YYPREFIX "yy"

#define YYPURE 0

#line 2 "parse.y"
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

#line 25 "parse.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union{int num;char *string;} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 53 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define TYPE 257
#define ID 258
#define NUMBER 259
#define MAIN 260
#define OB 261
#define CB 262
#define OCB 263
#define CCB 264
#define FOR 265
#define REOP 266
#define INCOP 267
#define WHILE 268
#define IF 269
#define ELSE 270
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    2,    2,    6,    4,    5,    5,    5,    5,    3,
    3,    3,    3,    3,    7,    1,    1,    1,    1,    1,
    1,    8,    9,   10,   10,   11,
};
static const YYINT yylen[] = {                            2,
    7,    2,    0,    0,    4,    3,    1,    3,    3,    2,
    2,    2,    2,    0,    4,    1,    1,    3,    3,    3,
    3,   11,    6,    6,    9,    3,
};
static const YYINT yydefred[] = {                         0,
    0,    0,    0,    0,    0,    4,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    2,    0,
    0,    0,    0,    0,    0,    1,   10,   11,   12,   13,
    0,    0,    5,    0,   16,   17,    0,    0,    0,    0,
    0,    0,    8,    6,    0,    0,    0,    0,   15,    0,
    0,    0,    0,    0,    0,   20,   21,    0,   26,    0,
    0,    0,   23,    0,    0,    0,    0,    0,    0,   25,
    0,   22,
};
static const YYINT yydgoto[] = {                          2,
   37,    7,   14,    8,   21,    9,   15,   16,   17,   18,
   40,
};
static const YYINT yysindex[] = {                      -257,
 -236,    0, -232, -230, -219,    0, -224, -219, -216,  -18,
 -211, -210, -209, -208, -224, -224, -224, -224,    0,  -39,
  -33, -239, -205, -204, -204,    0,    0,    0,    0,    0,
 -216, -202,    0, -203,    0,    0,  -41,   -3, -207, -201,
 -200,   16,    0,    0, -239, -239, -239, -239,    0, -196,
 -195, -198, -197,  -30,  -30,    0,    0,    8,    0, -194,
 -193, -204,    0, -192,    9, -191, -189, -190, -188,    0,
 -187,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,    0,    0, -237,    0, -185, -237,    0,    0,
    0,    0,    0,    0, -185, -185, -185, -185,    0,   10,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   17,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  -36,  -35,    0,    0,    0,    0,    0,
    0,    0,    0, -229,    0,    0,    0,    0,    0,    0,
    0,    0,
};
static const YYINT yygindex[] = {                         0,
  -32,   72,   31,    0,   50,    0,    0,    0,    0,    0,
  -25,
};
#define YYTABLESIZE 81
static const YYINT yytable[] = {                         41,
   47,   45,    1,   46,   31,   48,   18,   19,   18,   19,
   34,   47,   54,   55,   56,   57,   48,   49,   35,   36,
    3,   32,   18,   19,    3,   33,    3,    3,   24,    4,
    3,    3,    5,   10,   24,   24,   65,    6,   24,   24,
   11,   20,   22,   12,   13,   27,   28,   29,   30,   23,
   24,   25,   38,   39,   44,   26,   43,   50,   51,   34,
   52,   53,   58,   59,   60,   61,   62,   67,    7,   63,
   64,   68,   69,   70,   71,    9,   72,   66,   14,   19,
   42,
};
static const YYINT yycheck[] = {                         25,
   42,   43,  260,   45,   44,   47,   43,   43,   45,   45,
   44,   42,   45,   46,   47,   48,   47,   59,  258,  259,
  258,   61,   59,   59,  261,   59,  264,  265,  258,  262,
  268,  269,  263,  258,  264,  265,   62,  257,  268,  269,
  265,  258,   61,  268,  269,   15,   16,   17,   18,  261,
  261,  261,  258,  258,  258,  264,  259,   61,  266,   44,
  262,  262,  259,  259,  263,  263,   59,   59,   59,  264,
  264,  263,  262,  264,  263,   59,  264,  270,  264,    8,
   31,
};
#define YYFINAL 2
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 270
#define YYUNDFTOKEN 284
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,"'*'","'+'","','","'-'",0,"'/'",0,0,0,0,0,0,0,0,0,0,0,"';'",0,
"'='",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"TYPE","ID","NUMBER","MAIN","OB","CB","OCB","CCB","FOR","REOP","INCOP","WHILE",
"IF","ELSE",0,0,0,0,0,0,0,0,0,0,0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : pgm",
"pgm : MAIN OB CB OCB dec_list stmt_list CCB",
"dec_list : declare dec_list",
"dec_list :",
"$$1 :",
"declare : TYPE $$1 var ';'",
"var : var ',' ID",
"var : ID",
"var : ID '=' NUMBER",
"var : ID ',' var",
"stmt_list : astmt stmt_list",
"stmt_list : forst stmt_list",
"stmt_list : whilest stmt_list",
"stmt_list : decision stmt_list",
"stmt_list :",
"astmt : ID '=' exp ';'",
"exp : ID",
"exp : NUMBER",
"exp : exp '+' exp",
"exp : exp '-' exp",
"exp : exp '*' exp",
"exp : exp '/' exp",
"forst : FOR OB ID '=' NUMBER ';' con ';' CB OCB CCB",
"whilest : WHILE OB con CB OCB CCB",
"decision : IF OB con CB OCB CCB",
"decision : IF OB con CB OCB CCB ELSE OCB CCB",
"con : ID REOP NUMBER",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 200

typedef struct {
    unsigned stacksize;
    YYINT    *s_base;
    YYINT    *s_mark;
    YYINT    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 128 "parse.y"

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



#line 310 "y.tab.c"

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    YYINT *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return YYENOMEM;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (YYINT *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return YYENOMEM;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return YYENOMEM;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    YYERROR_CALL("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == YYEOF) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 1:
#line 44 "parse.y"
	{printf("Valid program\n");}
break;
case 3:
#line 47 "parse.y"
	{printf("Valid data dec\n");}
break;
case 4:
#line 50 "parse.y"
	{strcpy(a,yystack.l_mark[0].string);}
break;
case 6:
#line 53 "parse.y"
	{strcpy(sym[s].id,yystack.l_mark[0].string);strcpy(sym[s].type,a);sym[s].val=0;s++;}
break;
case 7:
#line 54 "parse.y"
	{strcpy(sym[s].id,yystack.l_mark[0].string);strcpy(sym[s].type,a);sym[s].val=0;s++;}
break;
case 8:
#line 55 "parse.y"
	{strcpy(sym[s].id,yystack.l_mark[-2].string);strcpy(sym[s].type,a);sym[s].val=yystack.l_mark[0].num;s++;}
break;
case 9:
#line 56 "parse.y"
	{strcpy(sym[s].id,yystack.l_mark[-2].string);strcpy(sym[s].type,a);sym[s].val=0;s++;}
break;
case 14:
#line 60 "parse.y"
	{printf("Valid stmt\n");}
break;
case 15:
#line 62 "parse.y"
	{quad_entry("=",yystack.l_mark[-1].string,"--",yystack.l_mark[-3].string);printf("valid assignment statement\n");}
break;
case 16:
#line 66 "parse.y"
	{yyval.string=yystack.l_mark[0].string;}
break;
case 17:
#line 68 "parse.y"
	{sprintf(y,"%ld",yystack.l_mark[0].num);yyval.string=y;}
break;
case 18:
#line 70 "parse.y"
	{
		sprintf(x,"%ld",temp);
		strcpy(tv,"t");
		strcat(tv,x);
		quad_entry("+",yystack.l_mark[-2].string,yystack.l_mark[0].string,tv);
		temp++;
		yyval.string=strdup(tv);
		/*quad_entry("=",tv,"--",b);*/
		
		
}
break;
case 19:
#line 83 "parse.y"
	{
 		sprintf(x,"%ld",temp);
		strcpy(tv,"t");
		strcat(tv,x);
		quad_entry("-",yystack.l_mark[-2].string,yystack.l_mark[0].string,tv);
		temp++;
		yyval.string=strdup(tv);
		}
break;
case 20:
#line 92 "parse.y"
	{
 		sprintf(x,"%ld",temp);
		strcpy(tv,"t");
		strcat(tv,x);
		quad_entry("*",yystack.l_mark[-2].string,yystack.l_mark[0].string,tv);
		temp++;
		yyval.string=strdup(tv);
		}
break;
case 21:
#line 102 "parse.y"
	{ 
		sprintf(x,"%ld",temp);
		strcpy(tv,"t");
		strcat(tv,x);
		quad_entry("/",yystack.l_mark[-2].string,yystack.l_mark[0].string,tv);
		/*quad_entry("=",tv,"--",b);*/
		temp++;
		yyval.string=strdup(tv);
		}
break;
case 22:
#line 114 "parse.y"
	{ printf("Valid for\n");}
break;
case 23:
#line 117 "parse.y"
	{ printf("Valid while\n"); }
break;
case 24:
#line 120 "parse.y"
	{ printf("Valid if\n"); }
break;
case 25:
#line 121 "parse.y"
	{ printf("Valid if and else\n"); }
break;
case 26:
#line 123 "parse.y"
	{ printf("Valid cond\n");}
break;
#line 624 "y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
            if (yydebug)
            {
                yys = yyname[YYTRANSLATE(yychar)];
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == YYEOF) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (YYINT) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    YYERROR_CALL("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
