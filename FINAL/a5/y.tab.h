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
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union{int num;char *string;} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
extern YYSTYPE yylval;
