/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 5 "gram.yy"

#include "pic.h"
#include "object.h"

//////////////////////////////////////////////////////////////////////
// PIC PARSER
// Public interface:
//
// parse_init()     [should be called only once]
// yyparse()
// parse_cleanup()  [should be called after each parse]
// define_variable(), lookup_variable()  [declared in object.h,
//                                        also used in lex.cc for `for' loops]
//
// delim_flag       [state flag read by lexer in lex.cc]
//
// The parser makes heavy use of special functions provided by the lexer,
// such as do_copy(), do_for(), copy_file_thru(), copy_rest_thru(),
// push_body(), and especially do_lookahead().  It also calls lex_warning()
// and lex_error().
//////////////////////////////////////////////////////////////////////

#undef fmod
#undef rand
#undef srand

extern "C" {
  double fmod(double, double);
  int rand();
  void srand(unsigned int);
}

// Maximum number of characters produced by printf("%g")
#define GDIGITS 14

static char sprintf_buf[1024];

direction current_direction;
position current_position;

implement_ptable(place)

PTABLE(place) top_table;

PTABLE(place) *current_table = &top_table;
saved_state *current_saved_state = 0;

object_list olist;

// external variable, used by lexer
int delim_flag = 0;

// forward references
static place *lookup_label(const char *label);
static void define_label(const char *label, const place *pl);
static void reset (const char *nm);
static void reset_all (void);
static const char * ordinal_postfix(int n);
static const char * object_type_name(object_type type);
static char * format_number(const char *form, double n);
static char * do_sprintf(const char *form, const double *v, int nv);


#line 135 "gram.cc"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_GRAM_HH_INCLUDED
# define YY_YY_GRAM_HH_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    LABEL = 258,                   /* LABEL  */
    VARIABLE = 259,                /* VARIABLE  */
    NUMBER = 260,                  /* NUMBER  */
    TEXT = 261,                    /* TEXT  */
    COMMAND_LINE = 262,            /* COMMAND_LINE  */
    DELIMITED = 263,               /* DELIMITED  */
    ORDINAL = 264,                 /* ORDINAL  */
    TH = 265,                      /* TH  */
    LEFT_ARROW_HEAD = 266,         /* LEFT_ARROW_HEAD  */
    RIGHT_ARROW_HEAD = 267,        /* RIGHT_ARROW_HEAD  */
    DOUBLE_ARROW_HEAD = 268,       /* DOUBLE_ARROW_HEAD  */
    LAST = 269,                    /* LAST  */
    UP = 270,                      /* UP  */
    DOWN = 271,                    /* DOWN  */
    LEFT = 272,                    /* LEFT  */
    RIGHT = 273,                   /* RIGHT  */
    BOX = 274,                     /* BOX  */
    CIRCLE = 275,                  /* CIRCLE  */
    ELLIPSE = 276,                 /* ELLIPSE  */
    ARC = 277,                     /* ARC  */
    LINE = 278,                    /* LINE  */
    ARROW = 279,                   /* ARROW  */
    MOVE = 280,                    /* MOVE  */
    SPLINE = 281,                  /* SPLINE  */
    HEIGHT = 282,                  /* HEIGHT  */
    RADIUS = 283,                  /* RADIUS  */
    WIDTH = 284,                   /* WIDTH  */
    DIAMETER = 285,                /* DIAMETER  */
    FROM = 286,                    /* FROM  */
    TO = 287,                      /* TO  */
    AT = 288,                      /* AT  */
    WITH = 289,                    /* WITH  */
    BY = 290,                      /* BY  */
    THEN = 291,                    /* THEN  */
    DOTTED = 292,                  /* DOTTED  */
    DASHED = 293,                  /* DASHED  */
    CHOP = 294,                    /* CHOP  */
    SAME = 295,                    /* SAME  */
    INVISIBLE = 296,               /* INVISIBLE  */
    LJUST = 297,                   /* LJUST  */
    RJUST = 298,                   /* RJUST  */
    ABOVE = 299,                   /* ABOVE  */
    BELOW = 300,                   /* BELOW  */
    OF = 301,                      /* OF  */
    THE = 302,                     /* THE  */
    WAY = 303,                     /* WAY  */
    BETWEEN = 304,                 /* BETWEEN  */
    AND = 305,                     /* AND  */
    HERE = 306,                    /* HERE  */
    DOT_N = 307,                   /* DOT_N  */
    DOT_E = 308,                   /* DOT_E  */
    DOT_W = 309,                   /* DOT_W  */
    DOT_S = 310,                   /* DOT_S  */
    DOT_NE = 311,                  /* DOT_NE  */
    DOT_SE = 312,                  /* DOT_SE  */
    DOT_NW = 313,                  /* DOT_NW  */
    DOT_SW = 314,                  /* DOT_SW  */
    DOT_C = 315,                   /* DOT_C  */
    DOT_START = 316,               /* DOT_START  */
    DOT_END = 317,                 /* DOT_END  */
    DOT_X = 318,                   /* DOT_X  */
    DOT_Y = 319,                   /* DOT_Y  */
    DOT_HT = 320,                  /* DOT_HT  */
    DOT_WID = 321,                 /* DOT_WID  */
    DOT_RAD = 322,                 /* DOT_RAD  */
    SIN = 323,                     /* SIN  */
    COS = 324,                     /* COS  */
    ATAN2 = 325,                   /* ATAN2  */
    LOG = 326,                     /* LOG  */
    EXP = 327,                     /* EXP  */
    SQRT = 328,                    /* SQRT  */
    K_MAX = 329,                   /* K_MAX  */
    K_MIN = 330,                   /* K_MIN  */
    INT = 331,                     /* INT  */
    RAND = 332,                    /* RAND  */
    SRAND = 333,                   /* SRAND  */
    COPY = 334,                    /* COPY  */
    THRU = 335,                    /* THRU  */
    TOP = 336,                     /* TOP  */
    BOTTOM = 337,                  /* BOTTOM  */
    UPPER = 338,                   /* UPPER  */
    LOWER = 339,                   /* LOWER  */
    SH = 340,                      /* SH  */
    PRINT = 341,                   /* PRINT  */
    CW = 342,                      /* CW  */
    CCW = 343,                     /* CCW  */
    FOR = 344,                     /* FOR  */
    DO = 345,                      /* DO  */
    IF = 346,                      /* IF  */
    ELSE = 347,                    /* ELSE  */
    ANDAND = 348,                  /* ANDAND  */
    OROR = 349,                    /* OROR  */
    NOTEQUAL = 350,                /* NOTEQUAL  */
    EQUALEQUAL = 351,              /* EQUALEQUAL  */
    LESSEQUAL = 352,               /* LESSEQUAL  */
    GREATEREQUAL = 353,            /* GREATEREQUAL  */
    LEFT_CORNER = 354,             /* LEFT_CORNER  */
    RIGHT_CORNER = 355,            /* RIGHT_CORNER  */
    CENTER = 356,                  /* CENTER  */
    END = 357,                     /* END  */
    START = 358,                   /* START  */
    RESET = 359,                   /* RESET  */
    UNTIL = 360,                   /* UNTIL  */
    PLOT = 361,                    /* PLOT  */
    THICKNESS = 362,               /* THICKNESS  */
    FILL = 363,                    /* FILL  */
    ALIGNED = 364,                 /* ALIGNED  */
    SPRINTF = 365,                 /* SPRINTF  */
    COMMAND = 366,                 /* COMMAND  */
    DEFINE = 367,                  /* DEFINE  */
    UNDEF = 368                    /* UNDEF  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define LABEL 258
#define VARIABLE 259
#define NUMBER 260
#define TEXT 261
#define COMMAND_LINE 262
#define DELIMITED 263
#define ORDINAL 264
#define TH 265
#define LEFT_ARROW_HEAD 266
#define RIGHT_ARROW_HEAD 267
#define DOUBLE_ARROW_HEAD 268
#define LAST 269
#define UP 270
#define DOWN 271
#define LEFT 272
#define RIGHT 273
#define BOX 274
#define CIRCLE 275
#define ELLIPSE 276
#define ARC 277
#define LINE 278
#define ARROW 279
#define MOVE 280
#define SPLINE 281
#define HEIGHT 282
#define RADIUS 283
#define WIDTH 284
#define DIAMETER 285
#define FROM 286
#define TO 287
#define AT 288
#define WITH 289
#define BY 290
#define THEN 291
#define DOTTED 292
#define DASHED 293
#define CHOP 294
#define SAME 295
#define INVISIBLE 296
#define LJUST 297
#define RJUST 298
#define ABOVE 299
#define BELOW 300
#define OF 301
#define THE 302
#define WAY 303
#define BETWEEN 304
#define AND 305
#define HERE 306
#define DOT_N 307
#define DOT_E 308
#define DOT_W 309
#define DOT_S 310
#define DOT_NE 311
#define DOT_SE 312
#define DOT_NW 313
#define DOT_SW 314
#define DOT_C 315
#define DOT_START 316
#define DOT_END 317
#define DOT_X 318
#define DOT_Y 319
#define DOT_HT 320
#define DOT_WID 321
#define DOT_RAD 322
#define SIN 323
#define COS 324
#define ATAN2 325
#define LOG 326
#define EXP 327
#define SQRT 328
#define K_MAX 329
#define K_MIN 330
#define INT 331
#define RAND 332
#define SRAND 333
#define COPY 334
#define THRU 335
#define TOP 336
#define BOTTOM 337
#define UPPER 338
#define LOWER 339
#define SH 340
#define PRINT 341
#define CW 342
#define CCW 343
#define FOR 344
#define DO 345
#define IF 346
#define ELSE 347
#define ANDAND 348
#define OROR 349
#define NOTEQUAL 350
#define EQUALEQUAL 351
#define LESSEQUAL 352
#define GREATEREQUAL 353
#define LEFT_CORNER 354
#define RIGHT_CORNER 355
#define CENTER 356
#define END 357
#define START 358
#define RESET 359
#define UNTIL 360
#define PLOT 361
#define THICKNESS 362
#define FILL 363
#define ALIGNED 364
#define SPRINTF 365
#define COMMAND 366
#define DEFINE 367
#define UNDEF 368

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 70 "gram.yy"

	char *str;
	int n;
	double x;
	struct { double x, y; } pair;
	struct { double x; char *body; } if_data;
	struct { char *str; const char *filename; int lineno; } lstr;
	struct { double *v; int nv; int maxv; } dv;
	struct { double val; int is_multiplicative; } by;
	place pl;
	object *obj;
	corner crn;
	path *pth;
	object_spec *spec;
	saved_state *pstate;
	graphics_state state;
	object_type obtype;

#line 433 "gram.cc"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_GRAM_HH_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_LABEL = 3,                      /* LABEL  */
  YYSYMBOL_VARIABLE = 4,                   /* VARIABLE  */
  YYSYMBOL_NUMBER = 5,                     /* NUMBER  */
  YYSYMBOL_TEXT = 6,                       /* TEXT  */
  YYSYMBOL_COMMAND_LINE = 7,               /* COMMAND_LINE  */
  YYSYMBOL_DELIMITED = 8,                  /* DELIMITED  */
  YYSYMBOL_ORDINAL = 9,                    /* ORDINAL  */
  YYSYMBOL_TH = 10,                        /* TH  */
  YYSYMBOL_LEFT_ARROW_HEAD = 11,           /* LEFT_ARROW_HEAD  */
  YYSYMBOL_RIGHT_ARROW_HEAD = 12,          /* RIGHT_ARROW_HEAD  */
  YYSYMBOL_DOUBLE_ARROW_HEAD = 13,         /* DOUBLE_ARROW_HEAD  */
  YYSYMBOL_LAST = 14,                      /* LAST  */
  YYSYMBOL_UP = 15,                        /* UP  */
  YYSYMBOL_DOWN = 16,                      /* DOWN  */
  YYSYMBOL_LEFT = 17,                      /* LEFT  */
  YYSYMBOL_RIGHT = 18,                     /* RIGHT  */
  YYSYMBOL_BOX = 19,                       /* BOX  */
  YYSYMBOL_CIRCLE = 20,                    /* CIRCLE  */
  YYSYMBOL_ELLIPSE = 21,                   /* ELLIPSE  */
  YYSYMBOL_ARC = 22,                       /* ARC  */
  YYSYMBOL_LINE = 23,                      /* LINE  */
  YYSYMBOL_ARROW = 24,                     /* ARROW  */
  YYSYMBOL_MOVE = 25,                      /* MOVE  */
  YYSYMBOL_SPLINE = 26,                    /* SPLINE  */
  YYSYMBOL_HEIGHT = 27,                    /* HEIGHT  */
  YYSYMBOL_RADIUS = 28,                    /* RADIUS  */
  YYSYMBOL_WIDTH = 29,                     /* WIDTH  */
  YYSYMBOL_DIAMETER = 30,                  /* DIAMETER  */
  YYSYMBOL_FROM = 31,                      /* FROM  */
  YYSYMBOL_TO = 32,                        /* TO  */
  YYSYMBOL_AT = 33,                        /* AT  */
  YYSYMBOL_WITH = 34,                      /* WITH  */
  YYSYMBOL_BY = 35,                        /* BY  */
  YYSYMBOL_THEN = 36,                      /* THEN  */
  YYSYMBOL_DOTTED = 37,                    /* DOTTED  */
  YYSYMBOL_DASHED = 38,                    /* DASHED  */
  YYSYMBOL_CHOP = 39,                      /* CHOP  */
  YYSYMBOL_SAME = 40,                      /* SAME  */
  YYSYMBOL_INVISIBLE = 41,                 /* INVISIBLE  */
  YYSYMBOL_LJUST = 42,                     /* LJUST  */
  YYSYMBOL_RJUST = 43,                     /* RJUST  */
  YYSYMBOL_ABOVE = 44,                     /* ABOVE  */
  YYSYMBOL_BELOW = 45,                     /* BELOW  */
  YYSYMBOL_OF = 46,                        /* OF  */
  YYSYMBOL_THE = 47,                       /* THE  */
  YYSYMBOL_WAY = 48,                       /* WAY  */
  YYSYMBOL_BETWEEN = 49,                   /* BETWEEN  */
  YYSYMBOL_AND = 50,                       /* AND  */
  YYSYMBOL_HERE = 51,                      /* HERE  */
  YYSYMBOL_DOT_N = 52,                     /* DOT_N  */
  YYSYMBOL_DOT_E = 53,                     /* DOT_E  */
  YYSYMBOL_DOT_W = 54,                     /* DOT_W  */
  YYSYMBOL_DOT_S = 55,                     /* DOT_S  */
  YYSYMBOL_DOT_NE = 56,                    /* DOT_NE  */
  YYSYMBOL_DOT_SE = 57,                    /* DOT_SE  */
  YYSYMBOL_DOT_NW = 58,                    /* DOT_NW  */
  YYSYMBOL_DOT_SW = 59,                    /* DOT_SW  */
  YYSYMBOL_DOT_C = 60,                     /* DOT_C  */
  YYSYMBOL_DOT_START = 61,                 /* DOT_START  */
  YYSYMBOL_DOT_END = 62,                   /* DOT_END  */
  YYSYMBOL_DOT_X = 63,                     /* DOT_X  */
  YYSYMBOL_DOT_Y = 64,                     /* DOT_Y  */
  YYSYMBOL_DOT_HT = 65,                    /* DOT_HT  */
  YYSYMBOL_DOT_WID = 66,                   /* DOT_WID  */
  YYSYMBOL_DOT_RAD = 67,                   /* DOT_RAD  */
  YYSYMBOL_SIN = 68,                       /* SIN  */
  YYSYMBOL_COS = 69,                       /* COS  */
  YYSYMBOL_ATAN2 = 70,                     /* ATAN2  */
  YYSYMBOL_LOG = 71,                       /* LOG  */
  YYSYMBOL_EXP = 72,                       /* EXP  */
  YYSYMBOL_SQRT = 73,                      /* SQRT  */
  YYSYMBOL_K_MAX = 74,                     /* K_MAX  */
  YYSYMBOL_K_MIN = 75,                     /* K_MIN  */
  YYSYMBOL_INT = 76,                       /* INT  */
  YYSYMBOL_RAND = 77,                      /* RAND  */
  YYSYMBOL_SRAND = 78,                     /* SRAND  */
  YYSYMBOL_COPY = 79,                      /* COPY  */
  YYSYMBOL_THRU = 80,                      /* THRU  */
  YYSYMBOL_TOP = 81,                       /* TOP  */
  YYSYMBOL_BOTTOM = 82,                    /* BOTTOM  */
  YYSYMBOL_UPPER = 83,                     /* UPPER  */
  YYSYMBOL_LOWER = 84,                     /* LOWER  */
  YYSYMBOL_SH = 85,                        /* SH  */
  YYSYMBOL_PRINT = 86,                     /* PRINT  */
  YYSYMBOL_CW = 87,                        /* CW  */
  YYSYMBOL_CCW = 88,                       /* CCW  */
  YYSYMBOL_FOR = 89,                       /* FOR  */
  YYSYMBOL_DO = 90,                        /* DO  */
  YYSYMBOL_IF = 91,                        /* IF  */
  YYSYMBOL_ELSE = 92,                      /* ELSE  */
  YYSYMBOL_ANDAND = 93,                    /* ANDAND  */
  YYSYMBOL_OROR = 94,                      /* OROR  */
  YYSYMBOL_NOTEQUAL = 95,                  /* NOTEQUAL  */
  YYSYMBOL_EQUALEQUAL = 96,                /* EQUALEQUAL  */
  YYSYMBOL_LESSEQUAL = 97,                 /* LESSEQUAL  */
  YYSYMBOL_GREATEREQUAL = 98,              /* GREATEREQUAL  */
  YYSYMBOL_LEFT_CORNER = 99,               /* LEFT_CORNER  */
  YYSYMBOL_RIGHT_CORNER = 100,             /* RIGHT_CORNER  */
  YYSYMBOL_CENTER = 101,                   /* CENTER  */
  YYSYMBOL_END = 102,                      /* END  */
  YYSYMBOL_START = 103,                    /* START  */
  YYSYMBOL_RESET = 104,                    /* RESET  */
  YYSYMBOL_UNTIL = 105,                    /* UNTIL  */
  YYSYMBOL_PLOT = 106,                     /* PLOT  */
  YYSYMBOL_THICKNESS = 107,                /* THICKNESS  */
  YYSYMBOL_FILL = 108,                     /* FILL  */
  YYSYMBOL_ALIGNED = 109,                  /* ALIGNED  */
  YYSYMBOL_SPRINTF = 110,                  /* SPRINTF  */
  YYSYMBOL_COMMAND = 111,                  /* COMMAND  */
  YYSYMBOL_DEFINE = 112,                   /* DEFINE  */
  YYSYMBOL_UNDEF = 113,                    /* UNDEF  */
  YYSYMBOL_114_ = 114,                     /* '('  */
  YYSYMBOL_115_ = 115,                     /* '`'  */
  YYSYMBOL_116_ = 116,                     /* ','  */
  YYSYMBOL_117_ = 117,                     /* '<'  */
  YYSYMBOL_118_ = 118,                     /* '>'  */
  YYSYMBOL_119_ = 119,                     /* '+'  */
  YYSYMBOL_120_ = 120,                     /* '-'  */
  YYSYMBOL_121_ = 121,                     /* '*'  */
  YYSYMBOL_122_ = 122,                     /* '/'  */
  YYSYMBOL_123_ = 123,                     /* '%'  */
  YYSYMBOL_124_ = 124,                     /* '!'  */
  YYSYMBOL_125_ = 125,                     /* '^'  */
  YYSYMBOL_126_ = 126,                     /* ';'  */
  YYSYMBOL_127_ = 127,                     /* '='  */
  YYSYMBOL_128_ = 128,                     /* ':'  */
  YYSYMBOL_129_ = 129,                     /* '{'  */
  YYSYMBOL_130_ = 130,                     /* '}'  */
  YYSYMBOL_131_ = 131,                     /* '['  */
  YYSYMBOL_132_ = 132,                     /* ']'  */
  YYSYMBOL_133_ = 133,                     /* ')'  */
  YYSYMBOL_134_ = 134,                     /* '.'  */
  YYSYMBOL_YYACCEPT = 135,                 /* $accept  */
  YYSYMBOL_top = 136,                      /* top  */
  YYSYMBOL_element_list = 137,             /* element_list  */
  YYSYMBOL_middle_element_list = 138,      /* middle_element_list  */
  YYSYMBOL_optional_separator = 139,       /* optional_separator  */
  YYSYMBOL_separator = 140,                /* separator  */
  YYSYMBOL_placeless_element = 141,        /* placeless_element  */
  YYSYMBOL_142_1 = 142,                    /* $@1  */
  YYSYMBOL_143_2 = 143,                    /* $@2  */
  YYSYMBOL_144_3 = 144,                    /* $@3  */
  YYSYMBOL_145_4 = 145,                    /* $@4  */
  YYSYMBOL_146_5 = 146,                    /* $@5  */
  YYSYMBOL_147_6 = 147,                    /* $@6  */
  YYSYMBOL_148_7 = 148,                    /* $@7  */
  YYSYMBOL_reset_variables = 149,          /* reset_variables  */
  YYSYMBOL_print_args = 150,               /* print_args  */
  YYSYMBOL_print_arg = 151,                /* print_arg  */
  YYSYMBOL_simple_if = 152,                /* simple_if  */
  YYSYMBOL_153_8 = 153,                    /* $@8  */
  YYSYMBOL_until = 154,                    /* until  */
  YYSYMBOL_any_expr = 155,                 /* any_expr  */
  YYSYMBOL_text_expr = 156,                /* text_expr  */
  YYSYMBOL_optional_by = 157,              /* optional_by  */
  YYSYMBOL_element = 158,                  /* element  */
  YYSYMBOL_159_9 = 159,                    /* @9  */
  YYSYMBOL_160_10 = 160,                   /* $@10  */
  YYSYMBOL_optional_element = 161,         /* optional_element  */
  YYSYMBOL_object_spec = 162,              /* object_spec  */
  YYSYMBOL_163_11 = 163,                   /* @11  */
  YYSYMBOL_text = 164,                     /* text  */
  YYSYMBOL_sprintf_args = 165,             /* sprintf_args  */
  YYSYMBOL_position = 166,                 /* position  */
  YYSYMBOL_position_not_place = 167,       /* position_not_place  */
  YYSYMBOL_between = 168,                  /* between  */
  YYSYMBOL_expr_pair = 169,                /* expr_pair  */
  YYSYMBOL_place = 170,                    /* place  */
  YYSYMBOL_label = 171,                    /* label  */
  YYSYMBOL_ordinal = 172,                  /* ordinal  */
  YYSYMBOL_optional_ordinal_last = 173,    /* optional_ordinal_last  */
  YYSYMBOL_nth_primitive = 174,            /* nth_primitive  */
  YYSYMBOL_object_type = 175,              /* object_type  */
  YYSYMBOL_label_path = 176,               /* label_path  */
  YYSYMBOL_relative_path = 177,            /* relative_path  */
  YYSYMBOL_path = 178,                     /* path  */
  YYSYMBOL_corner = 179,                   /* corner  */
  YYSYMBOL_expr = 180                      /* expr  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   2256

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  135
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  46
/* YYNRULES -- Number of rules.  */
#define YYNRULES  239
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  413

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   368


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   124,     2,     2,     2,   123,     2,     2,
     114,   133,   121,   119,   116,   120,   134,   122,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   128,   126,
     117,   127,   118,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   131,     2,   132,   125,     2,   115,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   129,     2,   130,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   265,   265,   266,   275,   280,   282,   286,   288,   292,
     293,   297,   302,   315,   317,   319,   321,   323,   328,   333,
     340,   339,   350,   358,   360,   357,   371,   373,   370,   383,
     382,   391,   400,   399,   413,   414,   419,   421,   423,   428,
     430,   451,   458,   460,   470,   469,   477,   478,   483,   485,
     490,   496,   502,   504,   506,   508,   510,   512,   514,   521,
     522,   524,   529,   544,   546,   554,   561,   567,   560,   576,
     586,   587,   592,   596,   600,   604,   609,   616,   623,   630,
     637,   642,   647,   655,   654,   681,   687,   693,   699,   705,
     725,   732,   739,   746,   753,   760,   767,   774,   781,   788,
     803,   816,   822,   829,   842,   848,   854,   860,   866,   871,
     877,   896,   916,   921,   926,   931,   936,   941,   946,   951,
     959,   970,   981,   992,  1003,  1009,  1017,  1021,  1033,  1038,
    1063,  1065,  1074,  1076,  1081,  1086,  1091,  1096,  1104,  1105,
    1109,  1111,  1116,  1118,  1124,  1130,  1136,  1145,  1156,  1160,
    1169,  1171,  1179,  1181,  1186,  1203,  1223,  1225,  1227,  1229,
    1231,  1233,  1235,  1237,  1239,  1244,  1248,  1256,  1263,  1267,
    1275,  1279,  1285,  1291,  1297,  1303,  1312,  1314,  1316,  1318,
    1320,  1322,  1324,  1326,  1328,  1330,  1332,  1334,  1336,  1338,
    1340,  1342,  1344,  1346,  1348,  1350,  1352,  1354,  1356,  1358,
    1360,  1362,  1364,  1366,  1371,  1380,  1382,  1389,  1396,  1403,
    1410,  1417,  1419,  1421,  1423,  1432,  1441,  1456,  1458,  1460,
    1470,  1480,  1495,  1505,  1515,  1525,  1527,  1529,  1531,  1533,
    1539,  1541,  1543,  1545,  1547,  1549,  1551,  1553,  1555,  1557
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "LABEL", "VARIABLE",
  "NUMBER", "TEXT", "COMMAND_LINE", "DELIMITED", "ORDINAL", "TH",
  "LEFT_ARROW_HEAD", "RIGHT_ARROW_HEAD", "DOUBLE_ARROW_HEAD", "LAST", "UP",
  "DOWN", "LEFT", "RIGHT", "BOX", "CIRCLE", "ELLIPSE", "ARC", "LINE",
  "ARROW", "MOVE", "SPLINE", "HEIGHT", "RADIUS", "WIDTH", "DIAMETER",
  "FROM", "TO", "AT", "WITH", "BY", "THEN", "DOTTED", "DASHED", "CHOP",
  "SAME", "INVISIBLE", "LJUST", "RJUST", "ABOVE", "BELOW", "OF", "THE",
  "WAY", "BETWEEN", "AND", "HERE", "DOT_N", "DOT_E", "DOT_W", "DOT_S",
  "DOT_NE", "DOT_SE", "DOT_NW", "DOT_SW", "DOT_C", "DOT_START", "DOT_END",
  "DOT_X", "DOT_Y", "DOT_HT", "DOT_WID", "DOT_RAD", "SIN", "COS", "ATAN2",
  "LOG", "EXP", "SQRT", "K_MAX", "K_MIN", "INT", "RAND", "SRAND", "COPY",
  "THRU", "TOP", "BOTTOM", "UPPER", "LOWER", "SH", "PRINT", "CW", "CCW",
  "FOR", "DO", "IF", "ELSE", "ANDAND", "OROR", "NOTEQUAL", "EQUALEQUAL",
  "LESSEQUAL", "GREATEREQUAL", "LEFT_CORNER", "RIGHT_CORNER", "CENTER",
  "END", "START", "RESET", "UNTIL", "PLOT", "THICKNESS", "FILL", "ALIGNED",
  "SPRINTF", "COMMAND", "DEFINE", "UNDEF", "'('", "'`'", "','", "'<'",
  "'>'", "'+'", "'-'", "'*'", "'/'", "'%'", "'!'", "'^'", "';'", "'='",
  "':'", "'{'", "'}'", "'['", "']'", "')'", "'.'", "$accept", "top",
  "element_list", "middle_element_list", "optional_separator", "separator",
  "placeless_element", "$@1", "$@2", "$@3", "$@4", "$@5", "$@6", "$@7",
  "reset_variables", "print_args", "print_arg", "simple_if", "$@8",
  "until", "any_expr", "text_expr", "optional_by", "element", "@9", "$@10",
  "optional_element", "object_spec", "@11", "text", "sprintf_args",
  "position", "position_not_place", "between", "expr_pair", "place",
  "label", "ordinal", "optional_ordinal_last", "nth_primitive",
  "object_type", "label_path", "relative_path", "path", "corner", "expr", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-119)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-191)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -118,  -119,    34,  -119,   677,  -106,  -119,   -74,  -100,  -119,
    -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,
    -119,  -119,  -119,     6,  -119,   899,    47,  1012,    57,  1450,
     -51,   899,  -119,  -119,  -118,  -119,     9,   -21,  -119,   786,
    -119,  -119,  -118,  1012,   -60,    32,  -119,   106,  -119,  -119,
    -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,
    -119,  -119,  -119,  -119,  -119,  -119,  -119,    15,    30,    36,
      40,    42,    43,    45,    48,    49,    63,    69,  -119,  -119,
      70,    80,  -119,  -119,  -119,  -119,  -119,  1125,  1012,  1450,
    1450,   899,  -119,  -119,   -73,  -119,  -119,   172,  2045,    54,
     267,  -119,     7,  2037,    60,  1012,  1012,   100,   -61,   -11,
     172,  2113,  -119,   629,   182,   899,  -118,  -118,  -119,   649,
    -119,   202,  -119,  -119,  -119,  -119,  1904,  1904,  1740,  1822,
    1450,  1450,  1450,  1450,  1554,  1554,  1554,   302,  1658,  -119,
    1904,  1904,  1904,  -119,  -119,  -119,  -119,  -119,  -119,  -119,
    -119,  1450,  1904,  -119,  -119,  2122,   530,  -119,  1012,  -119,
     199,  -119,  1012,  1012,  1012,  1012,  1012,  1012,  1012,  1012,
    1012,   408,  1012,  -119,  -119,  -119,  -119,  -119,  -119,  -119,
    -119,    79,   -37,    84,  2070,   213,    99,    99,  -119,  1658,
    1658,  -119,  -119,  -119,  -119,  -119,   224,  -119,  -119,  -119,
    -119,  -119,  -119,  -119,  -119,  -119,  -119,   108,  -119,  -119,
       8,   110,   196,  -119,  1450,  1450,  1450,  1450,  1450,  1450,
    1450,  1554,  1450,  1450,  1450,  1450,  1450,  1450,  1450,  1554,
    1450,  -119,    99,  -119,  1012,  1012,    20,    20,  1012,  1012,
    1450,  -119,  -119,   120,   677,   121,  -119,  -119,   246,  2122,
    2122,  2122,  2122,  2122,  2122,  2122,  2122,   -73,  2037,   -73,
     -73,  1977,   152,   267,  1977,   252,  1991,  -119,  -119,  -119,
    1238,  -119,  1353,  2122,  2122,  2122,  2122,  2122,   -74,  -100,
       2,    23,  -119,   -73,   -20,   155,  -119,   261,  -119,   137,
     138,   160,   145,   146,   147,   165,   166,   159,  -119,   163,
     168,  -119,  1554,  -119,  -119,  -119,  -119,  -119,  -119,   110,
     250,   312,   217,   376,   376,   109,   109,  2122,   -27,   327,
     109,   -83,   -83,    99,    99,    99,    99,    22,   272,   291,
    -119,   312,   209,  2131,  -119,  -119,  -119,   312,   209,  2131,
     109,   -92,  -119,  -119,  -119,  -119,   267,  1977,  1977,   187,
    -119,   304,  -119,    84,  2080,  -119,   203,  -119,  -119,  1012,
    -119,  -119,  -119,  1012,  1012,  -119,  -119,  -119,   -64,   260,
    1554,  1554,  1450,  -119,  1450,  -119,   677,  1977,  -119,  -119,
    1977,  -119,   203,   311,  -119,   185,   188,   189,  -119,  -119,
     128,   -73,   592,  2122,  -119,  -119,  -119,   190,  -119,  -119,
    -119,  -119,  -119,  -119,  1342,   235,  -119,  1450,  2122,  -119,
    2122,   318,  -119
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       7,     9,     0,     3,     2,     8,     1,     0,     0,   126,
      17,    13,    14,    15,    16,    72,    73,    74,    75,    76,
      77,    78,    79,     0,    20,     0,     0,     0,    35,     0,
       0,     0,    66,    83,     7,    69,    34,    31,     5,    62,
      80,    10,     7,     0,     0,    22,    26,     0,   147,   204,
     205,   150,   152,   189,   190,   146,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   187,   188,
       0,     0,   195,   196,   201,   203,   202,     0,     0,     0,
       0,    19,    39,    42,    43,   130,   132,   131,   142,     0,
       0,   148,     0,    41,     0,     0,     0,     0,    49,     0,
       0,    48,    36,    81,     0,    18,     7,     7,     4,     8,
      37,     0,    32,   114,   115,   116,    90,    92,    96,    94,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   103,
     104,   106,   110,   112,   113,   120,   121,   122,   123,   117,
     118,     0,   108,   125,   119,    89,     0,    11,     0,    23,
       0,    21,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   191,   193,   197,   199,   192,   194,   198,
     200,     0,     0,   132,    48,     0,   217,   239,    40,     0,
       0,   206,   207,   208,   209,   210,     0,   143,   164,   153,
     156,   157,   158,   159,   160,   161,   162,     0,   154,   155,
       0,   144,     0,   138,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    58,   239,    44,     0,     0,     0,     0,     0,     0,
       0,    82,   128,     0,     0,     0,     6,    38,     0,    91,
      93,    97,    95,    85,    86,    87,    88,    98,     0,    99,
     100,     0,     0,     0,     0,     0,   168,   170,   101,   167,
       0,   102,     0,   105,   107,   111,   124,   109,   147,   204,
     189,   190,    63,     0,    64,    65,    12,     0,    27,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   229,     0,
       0,   218,     0,   141,   151,   133,   134,   149,   163,   145,
       0,   237,   238,   236,   235,   232,   234,   140,     0,   231,
     233,   211,   212,   213,   214,   215,   216,     0,     0,     0,
      52,    53,    55,    56,    51,    50,    54,   237,    57,   238,
     231,     0,    67,    84,    33,   175,     0,     0,     0,     0,
     165,     0,   169,     0,    48,    24,    46,   219,   220,     0,
     222,   223,   224,     0,     0,   227,   228,   230,     0,     0,
       0,     0,     0,    45,     0,   127,    70,     0,   174,   173,
       0,   166,    46,     0,    28,     0,     0,     0,   135,   139,
       0,   136,    59,   129,    71,    68,   172,     0,    25,    47,
     221,   225,   226,   137,     0,     0,   171,     0,    60,    29,
      61,     0,    30
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -119,  -119,   -58,  -119,     3,   294,  -119,  -119,  -119,  -119,
    -119,  -119,  -119,  -119,  -119,   298,   -84,  -119,  -119,   -52,
      94,   -87,  -119,  -104,  -119,  -119,  -119,  -119,  -119,     5,
    -119,   -86,   175,  -119,   -44,     4,   -77,  -119,  -119,  -119,
     -95,  -119,   -53,  -119,   -80,   -25
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     2,     3,    34,   244,     5,    35,    47,   287,   382,
     160,   356,   411,   248,    36,    91,    92,    37,   329,   384,
     181,   108,   405,    38,   116,   376,   395,    39,   117,   109,
     341,    94,    95,   229,    96,   110,    98,    99,   100,   101,
     208,   266,   267,   268,   102,   111
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     103,   182,   -15,     4,   113,   209,   103,   188,     1,    40,
      48,    48,    45,   120,   155,   246,    51,    51,   197,   231,
      41,    52,    52,   -16,   374,   211,     9,    43,    44,    97,
      93,   188,   234,   235,     6,    97,    93,   118,   225,   226,
     227,   375,   228,   183,   154,   156,   189,   190,   257,   259,
     260,   104,   282,   210,    42,   189,   190,   269,   243,   245,
     198,   112,   184,   114,   186,   187,   103,   158,   199,   388,
     283,   122,   371,   200,   201,   202,   203,   204,   205,   302,
     206,   232,   189,   190,   236,   237,    46,   173,   174,   370,
     103,    97,   189,   190,   271,    97,    93,   177,   178,  -130,
    -130,   249,   250,   251,   252,   253,   254,   255,   256,   258,
     258,   258,   159,   272,   161,   273,   274,   275,   241,    97,
      93,   107,    88,    88,    40,   121,   276,   277,   -15,   162,
      30,   258,   -15,   309,   -15,   318,   233,   157,    97,    97,
      97,   189,   190,   327,   163,   305,   306,   330,   332,   -16,
     164,   336,   338,   -16,   165,   -16,   166,   167,   198,   168,
     285,    40,   169,   170,   272,   272,   346,   347,   348,   175,
     176,   200,   201,   202,   203,   204,   205,   171,   206,   179,
     180,   269,   185,   172,   269,   207,   352,   230,   242,   311,
     312,   313,   314,   315,   316,   317,   319,   320,   321,   322,
     323,   324,   325,   326,   258,   328,   247,   288,   345,   331,
     333,   349,   301,   337,   339,   340,   368,   303,   191,   192,
     193,   194,   195,   304,   228,    97,   353,   307,   223,   224,
     225,   226,   227,    97,   228,   191,   192,   193,   194,   195,
     308,   334,   335,   310,   196,   354,   403,   189,   190,    40,
     342,   377,   286,   343,   344,   350,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   299,   300,   269,   269,   355,
     357,   358,   394,   198,  -131,  -131,   359,   258,   360,   361,
     362,   363,   364,   207,   390,   391,   200,   201,   202,   203,
     204,   205,   365,   206,   378,   379,   366,   269,   369,   373,
     269,   367,   234,   380,   372,   261,    97,   381,   383,   389,
     214,   262,   216,   217,   218,   219,   263,   399,   400,    53,
      54,   401,   402,   406,   396,   409,   412,   397,   119,   115,
     398,   284,     0,     0,   240,   222,   223,   224,   225,   226,
     227,     0,   228,     0,     0,   258,   258,   392,     0,   393,
       0,     0,     0,     0,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,   214,   215,   216,   217,   218,
     219,     0,     0,   212,    97,    97,   213,     0,     0,   408,
       0,    40,   410,    78,    79,    80,    81,     0,     0,   240,
     222,   223,   224,   225,   226,   227,     0,   228,   207,     0,
       0,    82,    83,    84,    85,    86,     0,   216,   217,   218,
     219,    48,    49,    50,     9,     0,   264,    51,     0,     0,
       0,     0,    52,     0,     0,    53,    54,     0,     0,   240,
     222,   223,   224,   225,   226,   227,   265,   228,     0,     0,
       0,     0,     0,     0,     0,     0,   223,   224,   225,   226,
     227,     0,   228,   385,     0,     0,     0,   386,   387,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,     0,     0,   218,   219,     0,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,     0,     0,    78,
      79,    80,    81,   240,   222,   223,   224,   225,   226,   227,
       0,   228,     0,     0,     0,     0,     0,    82,    83,    84,
      85,    86,     0,     0,     0,     0,     0,     0,    30,     0,
       0,     0,   105,    88,     0,     0,     0,     0,    89,     0,
       0,     0,   106,   278,   279,    50,     9,    10,     0,    51,
       0,   298,     0,     0,    52,    11,    12,   280,   281,    15,
      16,    17,    18,    19,    20,    21,    22,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,     0,     0,     0,     0,     0,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    23,
       0,    78,    79,    80,    81,    24,    25,     0,     0,    26,
       0,    27,     0,     0,     0,     0,     0,   404,     0,    82,
      83,    84,    85,    86,    28,     9,    29,     0,     0,     0,
      30,    31,     0,     0,    87,    88,     0,     0,     0,     0,
      89,     0,     7,     8,    90,     9,    10,     0,     0,    32,
       0,    33,     0,     0,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,     0,     0,     0,     0,
       7,     8,     0,     9,    10,   214,   215,   216,   217,   218,
     219,     0,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,     0,     0,     0,     0,     0,   240,
     222,   223,   224,   225,   226,   227,     0,   228,     0,     0,
       0,     0,   214,   215,   216,   217,   218,   219,    23,     0,
       0,     0,     0,     0,    24,    25,     0,     0,    26,    30,
      27,     0,     0,     0,     0,     0,   240,   222,   223,   224,
     225,   226,   227,    28,   228,    29,    23,     0,     0,    30,
      31,     0,    24,    25,     0,     0,    26,     0,    27,     0,
       0,     0,     0,     0,     0,    41,     0,     0,    32,     0,
      33,    28,     0,    29,     0,     0,     0,    30,    31,    48,
      49,    50,     9,     0,     0,    51,     0,   123,   124,   125,
      52,   126,   127,   128,   129,     0,    32,     0,    33,     0,
       0,     0,     0,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,     0,     0,     0,     0,     0,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,     0,
       0,     0,     0,     0,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,     0,     0,    78,    79,    80,
      81,     0,     0,   149,   150,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    82,    83,    84,    85,    86,
       0,     0,     0,   151,   152,   153,    30,     0,     0,     0,
     105,    88,    48,    49,    50,     9,    89,     0,    51,     0,
      90,     0,     0,    52,     0,     0,    53,    54,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,     0,     0,     0,     0,     0,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,     0,     0,
      78,    79,    80,    81,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    82,    83,
      84,    85,    86,     0,     0,     0,     0,     0,     0,    30,
       0,     0,     0,    87,    88,    48,    49,    50,     9,    89,
       0,    51,     0,    90,     0,     0,    52,     0,     0,    53,
      54,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,     0,     0,     0,     0,     0,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,     0,     0,    78,    79,    80,    81,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    82,    83,    84,    85,    86,     0,     0,     0,     0,
       0,     0,    30,     0,     0,     0,   105,    88,    48,    49,
      50,     9,    89,     0,    51,     0,   106,     0,     0,    52,
       0,     0,    53,    54,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,     0,     0,
       0,     0,     0,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,     0,     0,    78,    79,    80,    81,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    82,    83,    84,    85,    86,     0,
       0,     0,     0,     0,     0,    30,     0,     0,     0,    87,
      88,    48,    49,    50,     9,    89,     0,    51,     0,   106,
       0,     0,    52,     0,     0,    53,    54,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,     0,     0,     0,     0,     0,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,     0,     0,    78,
      79,    80,    81,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    82,    83,    84,
      85,    86,     0,     0,     0,    48,    49,    50,    30,     0,
       0,    51,   270,    88,     0,     0,    52,     0,    89,    53,
      54,     0,   106,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,     0,     0,     0,     0,     0,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,     0,     0,    78,    79,    80,    81,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    82,    83,    84,    85,    86,   214,   215,   216,   217,
     218,   219,     0,    48,    49,    50,   105,    88,     0,    51,
       0,     0,    89,   407,    52,     0,    90,    53,    54,   220,
     240,   222,   223,   224,   225,   226,   227,     0,   228,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,     0,     0,     0,     0,     0,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,     0,
       0,    78,    79,    80,    81,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    82,
      83,    84,    85,    86,     0,     0,     0,    48,    49,    50,
       0,     0,     0,    51,   105,    88,     0,     0,    52,     0,
      89,    53,    54,     0,    90,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,     0,     0,     0,
       0,     0,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,     0,     0,    78,    79,    80,    81,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    82,    83,    84,    85,    86,     0,     0,
       0,    48,    49,    50,     0,     0,     0,    51,    87,    88,
       0,     0,    52,     0,    89,    53,    54,     0,    90,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,     0,     0,     0,     0,     0,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,     0,     0,    78,
      79,    80,    81,    48,    49,    50,     0,     0,     0,    51,
       0,     0,     0,     0,    52,     0,     0,    82,    83,    84,
      85,    86,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   270,    88,     0,     0,     0,     0,    89,     0,
       0,     0,    90,     0,     0,     0,  -189,     0,     0,     0,
       0,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,     0,     0,     0,     0,     0,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,     0,
       0,    78,    79,    80,    81,    48,    49,    50,     0,     0,
       0,    51,     0,     0,     0,     0,    52,     0,     0,    82,
      83,    84,    85,    86,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   105,    88,     0,     0,     0,     0,
      89,     0,     0,     0,    90,     0,     0,     0,  -190,     0,
       0,     0,     0,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,     0,     0,     0,     0,     0,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,     0,     0,    78,    79,    80,    81,    48,    49,    50,
       0,     0,     0,    51,     0,     0,     0,     0,    52,     0,
       0,    82,    83,    84,    85,    86,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   105,    88,     0,     0,
       0,     0,    89,     0,     0,     0,    90,     0,     0,     0,
       0,     0,     0,     0,     0,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,     0,     0,     0,
       0,     0,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,     0,     0,    78,    79,    80,    81,     0,
       0,     0,     0,     0,    53,    54,     0,     0,     0,     0,
       0,     0,     0,    82,    83,    84,    85,    86,    53,    54,
       0,     0,     0,     0,     0,     0,     0,     0,   105,    88,
       0,     0,     0,     0,    89,     0,     0,     0,    90,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
       0,     0,     0,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,     0,     0,     0,     0,    78,    79,
      80,    81,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    78,    79,    80,    81,    82,    83,    84,    85,
      86,     0,     0,   212,     0,     0,   213,     0,     0,     0,
      82,    83,    84,    85,    86,     0,     0,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,     0,     0,
       0,   265,     0,     0,     0,     0,   212,     0,     0,   213,
       0,     0,     0,     0,     0,   351,    78,    79,    80,    81,
     214,   215,   216,   217,   218,   219,     0,     0,     0,     0,
       0,     0,     0,     0,    82,    83,    84,    85,    86,     0,
       0,     0,     0,   220,   221,   222,   223,   224,   225,   226,
     227,     0,   228,   238,   239,   216,   217,   218,   219,     0,
       0,     0,     0,   238,   239,   216,   217,   218,   219,   196,
       0,     0,     0,     0,     0,     0,   220,   221,   222,   223,
     224,   225,   226,   227,     0,   228,   220,   240,   222,   223,
     224,   225,   226,   227,     0,   228,   238,   239,   216,   217,
     218,   219,     0,     0,     0,   214,   215,   216,   217,   218,
     219,     0,     0,     0,   238,     0,   216,   217,   218,   219,
     240,   222,   223,   224,   225,   226,   227,     0,   228,   240,
     222,   223,   224,   225,   226,   227,     0,   228,   240,   222,
     223,   224,   225,   226,   227,     0,   228
};

static const yytype_int16 yycheck[] =
{
      25,    87,     0,     0,    29,   100,    31,    91,   126,     4,
       3,     3,     6,     4,    39,   119,     9,     9,    98,   106,
     126,    14,    14,     0,   116,   102,     6,   127,   128,    25,
      25,   115,    93,    94,     0,    31,    31,    34,   121,   122,
     123,   133,   125,    87,    39,    42,   119,   120,   134,   135,
     136,     4,   156,    46,   128,   119,   120,   137,   116,   117,
       6,     4,    87,   114,    89,    90,    91,   127,    14,   133,
     156,    92,    50,    19,    20,    21,    22,    23,    24,   116,
      26,   106,   119,   120,    95,    96,    80,    17,    18,   116,
     115,    87,   119,   120,   138,    91,    91,    17,    18,   119,
     120,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,    80,   138,     8,   140,   141,   142,   113,   115,
     115,    27,   115,   115,   119,   116,   151,   152,   126,   114,
     110,   156,   130,   210,   132,   221,    36,    43,   134,   135,
     136,   119,   120,   229,   114,   189,   190,   234,   235,   126,
     114,   238,   239,   130,   114,   132,   114,   114,     6,   114,
     156,   156,   114,   114,   189,   190,    14,   262,   263,    99,
     100,    19,    20,    21,    22,    23,    24,   114,    26,    99,
     100,   261,    88,   114,   264,   131,   266,   127,     6,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,     4,     8,   261,   234,
     235,   264,   133,   238,   239,   240,   302,   133,    63,    64,
      65,    66,    67,    10,   125,   221,   270,     3,   119,   120,
     121,   122,   123,   229,   125,    63,    64,    65,    66,    67,
     132,   236,   237,    47,   134,   270,   118,   119,   120,   244,
     130,   346,   158,   132,     8,     3,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   347,   348,     8,
     133,   133,   376,     6,   119,   120,   116,   302,   133,   133,
     133,   116,   116,   131,   370,   371,    19,    20,    21,    22,
      23,    24,   133,    26,   347,   348,   133,   377,    48,     8,
     380,   133,    93,   116,    32,     3,   302,     3,   105,    49,
      93,     9,    95,    96,    97,    98,    14,     6,   133,    17,
      18,   133,   133,   133,   377,    90,     8,   380,    34,    31,
     382,   156,    -1,    -1,   117,   118,   119,   120,   121,   122,
     123,    -1,   125,    -1,    -1,   370,   371,   372,    -1,   374,
      -1,    -1,    -1,    -1,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    93,    94,    95,    96,    97,
      98,    -1,    -1,    46,   370,   371,    49,    -1,    -1,   404,
      -1,   376,   407,    81,    82,    83,    84,    -1,    -1,   117,
     118,   119,   120,   121,   122,   123,    -1,   125,   131,    -1,
      -1,    99,   100,   101,   102,   103,    -1,    95,    96,    97,
      98,     3,     4,     5,     6,    -1,   114,     9,    -1,    -1,
      -1,    -1,    14,    -1,    -1,    17,    18,    -1,    -1,   117,
     118,   119,   120,   121,   122,   123,   134,   125,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   119,   120,   121,   122,
     123,    -1,   125,   359,    -1,    -1,    -1,   363,   364,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    -1,    -1,    97,    98,    -1,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    -1,    -1,    81,
      82,    83,    84,   117,   118,   119,   120,   121,   122,   123,
      -1,   125,    -1,    -1,    -1,    -1,    -1,    99,   100,   101,
     102,   103,    -1,    -1,    -1,    -1,    -1,    -1,   110,    -1,
      -1,    -1,   114,   115,    -1,    -1,    -1,    -1,   120,    -1,
      -1,    -1,   124,     3,     4,     5,     6,     7,    -1,     9,
      -1,   133,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    -1,    -1,    -1,    -1,    -1,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      -1,    81,    82,    83,    84,    85,    86,    -1,    -1,    89,
      -1,    91,    -1,    -1,    -1,    -1,    -1,    35,    -1,    99,
     100,   101,   102,   103,   104,     6,   106,    -1,    -1,    -1,
     110,   111,    -1,    -1,   114,   115,    -1,    -1,    -1,    -1,
     120,    -1,     3,     4,   124,     6,     7,    -1,    -1,   129,
      -1,   131,    -1,    -1,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    -1,    -1,    -1,    -1,
       3,     4,    -1,     6,     7,    93,    94,    95,    96,    97,
      98,    -1,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    -1,    -1,    -1,    -1,    -1,   117,
     118,   119,   120,   121,   122,   123,    -1,   125,    -1,    -1,
      -1,    -1,    93,    94,    95,    96,    97,    98,    79,    -1,
      -1,    -1,    -1,    -1,    85,    86,    -1,    -1,    89,   110,
      91,    -1,    -1,    -1,    -1,    -1,   117,   118,   119,   120,
     121,   122,   123,   104,   125,   106,    79,    -1,    -1,   110,
     111,    -1,    85,    86,    -1,    -1,    89,    -1,    91,    -1,
      -1,    -1,    -1,    -1,    -1,   126,    -1,    -1,   129,    -1,
     131,   104,    -1,   106,    -1,    -1,    -1,   110,   111,     3,
       4,     5,     6,    -1,    -1,     9,    -1,    11,    12,    13,
      14,    15,    16,    17,    18,    -1,   129,    -1,   131,    -1,
      -1,    -1,    -1,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    -1,    -1,    -1,    -1,    -1,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    -1,
      -1,    -1,    -1,    -1,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    -1,    -1,    81,    82,    83,
      84,    -1,    -1,    87,    88,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    99,   100,   101,   102,   103,
      -1,    -1,    -1,   107,   108,   109,   110,    -1,    -1,    -1,
     114,   115,     3,     4,     5,     6,   120,    -1,     9,    -1,
     124,    -1,    -1,    14,    -1,    -1,    17,    18,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    -1,    -1,    -1,    -1,    -1,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    -1,    -1,
      81,    82,    83,    84,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,   100,
     101,   102,   103,    -1,    -1,    -1,    -1,    -1,    -1,   110,
      -1,    -1,    -1,   114,   115,     3,     4,     5,     6,   120,
      -1,     9,    -1,   124,    -1,    -1,    14,    -1,    -1,    17,
      18,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    -1,    -1,    -1,    -1,    -1,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    -1,    -1,    81,    82,    83,    84,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    99,   100,   101,   102,   103,    -1,    -1,    -1,    -1,
      -1,    -1,   110,    -1,    -1,    -1,   114,   115,     3,     4,
       5,     6,   120,    -1,     9,    -1,   124,    -1,    -1,    14,
      -1,    -1,    17,    18,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    -1,    -1,
      -1,    -1,    -1,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    -1,    -1,    81,    82,    83,    84,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    99,   100,   101,   102,   103,    -1,
      -1,    -1,    -1,    -1,    -1,   110,    -1,    -1,    -1,   114,
     115,     3,     4,     5,     6,   120,    -1,     9,    -1,   124,
      -1,    -1,    14,    -1,    -1,    17,    18,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    -1,    -1,    -1,    -1,    -1,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    -1,    -1,    81,
      82,    83,    84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,   100,   101,
     102,   103,    -1,    -1,    -1,     3,     4,     5,   110,    -1,
      -1,     9,   114,   115,    -1,    -1,    14,    -1,   120,    17,
      18,    -1,   124,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    -1,    -1,    -1,    -1,    -1,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    -1,    -1,    81,    82,    83,    84,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    99,   100,   101,   102,   103,    93,    94,    95,    96,
      97,    98,    -1,     3,     4,     5,   114,   115,    -1,     9,
      -1,    -1,   120,   121,    14,    -1,   124,    17,    18,   116,
     117,   118,   119,   120,   121,   122,   123,    -1,   125,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    -1,    -1,    -1,    -1,    -1,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    -1,
      -1,    81,    82,    83,    84,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,
     100,   101,   102,   103,    -1,    -1,    -1,     3,     4,     5,
      -1,    -1,    -1,     9,   114,   115,    -1,    -1,    14,    -1,
     120,    17,    18,    -1,   124,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    -1,    -1,    -1,
      -1,    -1,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    -1,    -1,    81,    82,    83,    84,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    99,   100,   101,   102,   103,    -1,    -1,
      -1,     3,     4,     5,    -1,    -1,    -1,     9,   114,   115,
      -1,    -1,    14,    -1,   120,    17,    18,    -1,   124,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    -1,    -1,    -1,    -1,    -1,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    -1,    -1,    81,
      82,    83,    84,     3,     4,     5,    -1,    -1,    -1,     9,
      -1,    -1,    -1,    -1,    14,    -1,    -1,    99,   100,   101,
     102,   103,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   114,   115,    -1,    -1,    -1,    -1,   120,    -1,
      -1,    -1,   124,    -1,    -1,    -1,    46,    -1,    -1,    -1,
      -1,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    -1,    -1,    -1,    -1,    -1,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    -1,
      -1,    81,    82,    83,    84,     3,     4,     5,    -1,    -1,
      -1,     9,    -1,    -1,    -1,    -1,    14,    -1,    -1,    99,
     100,   101,   102,   103,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   114,   115,    -1,    -1,    -1,    -1,
     120,    -1,    -1,    -1,   124,    -1,    -1,    -1,    46,    -1,
      -1,    -1,    -1,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    -1,    -1,    -1,    -1,    -1,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    -1,    -1,    81,    82,    83,    84,     3,     4,     5,
      -1,    -1,    -1,     9,    -1,    -1,    -1,    -1,    14,    -1,
      -1,    99,   100,   101,   102,   103,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   114,   115,    -1,    -1,
      -1,    -1,   120,    -1,    -1,    -1,   124,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    -1,    -1,    -1,
      -1,    -1,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    -1,    -1,    81,    82,    83,    84,    -1,
      -1,    -1,    -1,    -1,    17,    18,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    99,   100,   101,   102,   103,    17,    18,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   114,   115,
      -1,    -1,    -1,    -1,   120,    -1,    -1,    -1,   124,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      -1,    -1,    -1,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    -1,    -1,    -1,    -1,    81,    82,
      83,    84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    81,    82,    83,    84,    99,   100,   101,   102,
     103,    -1,    -1,    46,    -1,    -1,    49,    -1,    -1,    -1,
      99,   100,   101,   102,   103,    -1,    -1,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    -1,    -1,
      -1,   134,    -1,    -1,    -1,    -1,    46,    -1,    -1,    49,
      -1,    -1,    -1,    -1,    -1,   134,    81,    82,    83,    84,
      93,    94,    95,    96,    97,    98,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    99,   100,   101,   102,   103,    -1,
      -1,    -1,    -1,   116,   117,   118,   119,   120,   121,   122,
     123,    -1,   125,    93,    94,    95,    96,    97,    98,    -1,
      -1,    -1,    -1,    93,    94,    95,    96,    97,    98,   134,
      -1,    -1,    -1,    -1,    -1,    -1,   116,   117,   118,   119,
     120,   121,   122,   123,    -1,   125,   116,   117,   118,   119,
     120,   121,   122,   123,    -1,   125,    93,    94,    95,    96,
      97,    98,    -1,    -1,    -1,    93,    94,    95,    96,    97,
      98,    -1,    -1,    -1,    93,    -1,    95,    96,    97,    98,
     117,   118,   119,   120,   121,   122,   123,    -1,   125,   117,
     118,   119,   120,   121,   122,   123,    -1,   125,   117,   118,
     119,   120,   121,   122,   123,    -1,   125
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,   126,   136,   137,   139,   140,     0,     3,     4,     6,
       7,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    79,    85,    86,    89,    91,   104,   106,
     110,   111,   129,   131,   138,   141,   149,   152,   158,   162,
     164,   126,   128,   127,   128,     6,    80,   142,     3,     4,
       5,     9,    14,    17,    18,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    81,    82,
      83,    84,    99,   100,   101,   102,   103,   114,   115,   120,
     124,   150,   151,   164,   166,   167,   169,   170,   171,   172,
     173,   174,   179,   180,     4,   114,   124,   155,   156,   164,
     170,   180,     4,   180,   114,   150,   159,   163,   139,   140,
       4,   116,    92,    11,    12,    13,    15,    16,    17,    18,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    87,
      88,   107,   108,   109,   164,   180,   139,   155,   127,    80,
     145,     8,   114,   114,   114,   114,   114,   114,   114,   114,
     114,   114,   114,    17,    18,    99,   100,    17,    18,    99,
     100,   155,   166,   169,   180,   155,   180,   180,   151,   119,
     120,    63,    64,    65,    66,    67,   134,   179,     6,    14,
      19,    20,    21,    22,    23,    24,    26,   131,   175,   175,
      46,   171,    46,    49,    93,    94,    95,    96,    97,    98,
     116,   117,   118,   119,   120,   121,   122,   123,   125,   168,
     127,   156,   180,    36,    93,    94,    95,    96,    93,    94,
     117,   164,     6,   137,   139,   137,   158,     4,   148,   180,
     180,   180,   180,   180,   180,   180,   180,   166,   180,   166,
     166,     3,     9,    14,   114,   134,   176,   177,   178,   179,
     114,   169,   180,   180,   180,   180,   180,   180,     3,     4,
      17,    18,   158,   166,   167,   170,   155,   143,     8,   155,
     155,   155,   155,   155,   155,   155,   155,   155,   133,   155,
     155,   133,   116,   133,    10,   169,   169,     3,   132,   171,
      47,   180,   180,   180,   180,   180,   180,   180,   166,   180,
     180,   180,   180,   180,   180,   180,   180,   166,   180,   153,
     156,   180,   156,   180,   164,   164,   156,   180,   156,   180,
     180,   165,   130,   132,     8,   177,    14,   175,   175,   177,
       3,   134,   179,   169,   180,     8,   146,   133,   133,   116,
     133,   133,   133,   116,   116,   133,   133,   133,   166,    48,
     116,    50,    32,     8,   116,   133,   160,   175,   177,   177,
     116,     3,   144,   105,   154,   155,   155,   155,   133,    49,
     166,   166,   180,   180,   158,   161,   177,   177,   154,     6,
     133,   133,   133,   118,    35,   157,   133,   121,   180,    90,
     180,   147,     8
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,   135,   136,   136,   137,   138,   138,   139,   139,   140,
     140,   141,   141,   141,   141,   141,   141,   141,   141,   141,
     142,   141,   141,   143,   144,   141,   145,   146,   141,   147,
     141,   141,   148,   141,   141,   141,   149,   149,   149,   150,
     150,   151,   151,   151,   153,   152,   154,   154,   155,   155,
     156,   156,   156,   156,   156,   156,   156,   156,   156,   157,
     157,   157,   158,   158,   158,   158,   159,   160,   158,   158,
     161,   161,   162,   162,   162,   162,   162,   162,   162,   162,
     162,   162,   162,   163,   162,   162,   162,   162,   162,   162,
     162,   162,   162,   162,   162,   162,   162,   162,   162,   162,
     162,   162,   162,   162,   162,   162,   162,   162,   162,   162,
     162,   162,   162,   162,   162,   162,   162,   162,   162,   162,
     162,   162,   162,   162,   162,   162,   164,   164,   165,   165,
     166,   166,   167,   167,   167,   167,   167,   167,   168,   168,
     169,   169,   170,   170,   170,   170,   170,   171,   171,   171,
     172,   172,   173,   173,   174,   174,   175,   175,   175,   175,
     175,   175,   175,   175,   175,   176,   176,   177,   177,   177,
     178,   178,   178,   178,   178,   178,   179,   179,   179,   179,
     179,   179,   179,   179,   179,   179,   179,   179,   179,   179,
     179,   179,   179,   179,   179,   179,   179,   179,   179,   179,
     179,   179,   179,   179,   180,   180,   180,   180,   180,   180,
     180,   180,   180,   180,   180,   180,   180,   180,   180,   180,
     180,   180,   180,   180,   180,   180,   180,   180,   180,   180,
     180,   180,   180,   180,   180,   180,   180,   180,   180,   180
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     3,     1,     3,     0,     1,     1,
       2,     3,     4,     1,     1,     1,     1,     1,     2,     2,
       0,     3,     2,     0,     0,     7,     0,     0,     6,     0,
      10,     1,     0,     4,     1,     1,     2,     2,     3,     1,
       2,     1,     1,     1,     0,     5,     0,     2,     1,     1,
       3,     3,     3,     3,     3,     3,     3,     3,     2,     0,
       2,     3,     1,     4,     4,     4,     0,     0,     6,     1,
       0,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     3,     0,     4,     3,     3,     3,     3,     2,
       2,     3,     2,     3,     2,     3,     2,     3,     3,     3,
       3,     3,     3,     2,     2,     3,     2,     3,     2,     3,
       2,     3,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     3,     2,     1,     5,     0,     3,
       1,     1,     1,     3,     3,     5,     5,     6,     1,     4,
       3,     3,     1,     2,     2,     3,     1,     1,     1,     3,
       1,     3,     1,     2,     2,     2,     1,     1,     1,     1,
       1,     1,     1,     2,     1,     2,     3,     1,     1,     2,
       1,     5,     4,     3,     3,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     2,     2,     2,     1,     1,     2,     2,     2,
       2,     1,     1,     1,     1,     1,     2,     2,     2,     2,
       2,     3,     3,     3,     3,     3,     3,     2,     3,     4,
       4,     6,     4,     4,     4,     6,     6,     4,     4,     3,
       4,     3,     3,     3,     3,     3,     3,     3,     3,     2
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 3: /* top: element_list  */
#line 267 "gram.yy"
                {
		  if (olist.head)
		    print_picture(olist.head);
		}
#line 2266 "gram.cc"
    break;

  case 4: /* element_list: optional_separator middle_element_list optional_separator  */
#line 276 "gram.yy"
                { (yyval.pl) = (yyvsp[-1].pl); }
#line 2272 "gram.cc"
    break;

  case 5: /* middle_element_list: element  */
#line 281 "gram.yy"
                { (yyval.pl) = (yyvsp[0].pl); }
#line 2278 "gram.cc"
    break;

  case 6: /* middle_element_list: middle_element_list separator element  */
#line 283 "gram.yy"
                { (yyval.pl) = (yyvsp[-2].pl); }
#line 2284 "gram.cc"
    break;

  case 11: /* placeless_element: VARIABLE '=' any_expr  */
#line 298 "gram.yy"
                {
		  define_variable((yyvsp[-2].str), (yyvsp[0].x));
		  a_delete (yyvsp[-2].str);
		}
#line 2293 "gram.cc"
    break;

  case 12: /* placeless_element: VARIABLE ':' '=' any_expr  */
#line 303 "gram.yy"
                {
		  place *p = lookup_label((yyvsp[-3].str));
		  if (!p) 
		    {
		      lex_error("variable `%1' not defined", (yyvsp[-3].str));
		      YYABORT;
		    }
		  p->obj = 0;
		  p->x = (yyvsp[0].x);
		  p->y = 0.0;
		  a_delete (yyvsp[-3].str);
		}
#line 2310 "gram.cc"
    break;

  case 13: /* placeless_element: UP  */
#line 316 "gram.yy"
                { current_direction = UP_DIRECTION; }
#line 2316 "gram.cc"
    break;

  case 14: /* placeless_element: DOWN  */
#line 318 "gram.yy"
                { current_direction = DOWN_DIRECTION; }
#line 2322 "gram.cc"
    break;

  case 15: /* placeless_element: LEFT  */
#line 320 "gram.yy"
                { current_direction = LEFT_DIRECTION; }
#line 2328 "gram.cc"
    break;

  case 16: /* placeless_element: RIGHT  */
#line 322 "gram.yy"
                { current_direction = RIGHT_DIRECTION; }
#line 2334 "gram.cc"
    break;

  case 17: /* placeless_element: COMMAND_LINE  */
#line 324 "gram.yy"
                {
		  olist.append(make_command_object((yyvsp[0].lstr).str, (yyvsp[0].lstr).filename,
						   (yyvsp[0].lstr).lineno));
		}
#line 2343 "gram.cc"
    break;

  case 18: /* placeless_element: COMMAND print_args  */
#line 329 "gram.yy"
                {
		  olist.append(make_command_object((yyvsp[0].lstr).str, (yyvsp[0].lstr).filename,
						   (yyvsp[0].lstr).lineno));
		}
#line 2352 "gram.cc"
    break;

  case 19: /* placeless_element: PRINT print_args  */
#line 334 "gram.yy"
                {
		  fprintf(stderr, "%s\n", (yyvsp[0].lstr).str);
		  a_delete (yyvsp[0].lstr).str;
	          fflush(stderr);
		}
#line 2362 "gram.cc"
    break;

  case 20: /* $@1: %empty  */
#line 340 "gram.yy"
                { delim_flag = 1; }
#line 2368 "gram.cc"
    break;

  case 21: /* placeless_element: SH $@1 DELIMITED  */
#line 342 "gram.yy"
                {
		  delim_flag = 0;
		  if (safer_flag)
		    lex_error("unsafe to run command `%1'", (yyvsp[0].str));
		  else
		    system((yyvsp[0].str));
		  a_delete (yyvsp[0].str);
		}
#line 2381 "gram.cc"
    break;

  case 22: /* placeless_element: COPY TEXT  */
#line 351 "gram.yy"
                {
		  if (yychar < 0)
		    do_lookahead();
		  do_copy((yyvsp[0].lstr).str);
		  // do not delete the filename
		}
#line 2392 "gram.cc"
    break;

  case 23: /* $@2: %empty  */
#line 358 "gram.yy"
                { delim_flag = 2; }
#line 2398 "gram.cc"
    break;

  case 24: /* $@3: %empty  */
#line 360 "gram.yy"
                { delim_flag = 0; }
#line 2404 "gram.cc"
    break;

  case 25: /* placeless_element: COPY TEXT THRU $@2 DELIMITED $@3 until  */
#line 362 "gram.yy"
                {
		  if (yychar < 0)
		    do_lookahead();
		  copy_file_thru((yyvsp[-5].lstr).str, (yyvsp[-2].str), (yyvsp[0].str));
		  // do not delete the filename
		  a_delete (yyvsp[-2].str);
		  a_delete (yyvsp[0].str);
		}
#line 2417 "gram.cc"
    break;

  case 26: /* $@4: %empty  */
#line 371 "gram.yy"
                { delim_flag = 2; }
#line 2423 "gram.cc"
    break;

  case 27: /* $@5: %empty  */
#line 373 "gram.yy"
                { delim_flag = 0; }
#line 2429 "gram.cc"
    break;

  case 28: /* placeless_element: COPY THRU $@4 DELIMITED $@5 until  */
#line 375 "gram.yy"
                {
		  if (yychar < 0)
		    do_lookahead();
		  copy_rest_thru((yyvsp[-2].str), (yyvsp[0].str));
		  a_delete (yyvsp[-2].str);
		  a_delete (yyvsp[0].str);
		}
#line 2441 "gram.cc"
    break;

  case 29: /* $@6: %empty  */
#line 383 "gram.yy"
                { delim_flag = 1; }
#line 2447 "gram.cc"
    break;

  case 30: /* placeless_element: FOR VARIABLE '=' expr TO expr optional_by DO $@6 DELIMITED  */
#line 385 "gram.yy"
                {
		  delim_flag = 0;
		  if (yychar < 0)
		    do_lookahead();
		  do_for((yyvsp[-8].str), (yyvsp[-6].x), (yyvsp[-4].x), (yyvsp[-3].by).is_multiplicative, (yyvsp[-3].by).val, (yyvsp[0].str)); 
		}
#line 2458 "gram.cc"
    break;

  case 31: /* placeless_element: simple_if  */
#line 392 "gram.yy"
                {
		  if (yychar < 0)
		    do_lookahead();
		  if ((yyvsp[0].if_data).x != 0.0)
		    push_body((yyvsp[0].if_data).body);
		  a_delete (yyvsp[0].if_data).body;
		}
#line 2470 "gram.cc"
    break;

  case 32: /* $@7: %empty  */
#line 400 "gram.yy"
                { delim_flag = 1; }
#line 2476 "gram.cc"
    break;

  case 33: /* placeless_element: simple_if ELSE $@7 DELIMITED  */
#line 402 "gram.yy"
                {
		  delim_flag = 0;
		  if (yychar < 0)
		    do_lookahead();
		  if ((yyvsp[-3].if_data).x != 0.0)
		    push_body((yyvsp[-3].if_data).body);
		  else
		    push_body((yyvsp[0].str));
		  a_delete (yyvsp[-3].if_data).body;
		  a_delete (yyvsp[0].str);
		}
#line 2492 "gram.cc"
    break;

  case 35: /* placeless_element: RESET  */
#line 415 "gram.yy"
                { define_variable("scale", 1.0); }
#line 2498 "gram.cc"
    break;

  case 36: /* reset_variables: RESET VARIABLE  */
#line 420 "gram.yy"
                { reset((yyvsp[0].str)); a_delete (yyvsp[0].str); }
#line 2504 "gram.cc"
    break;

  case 37: /* reset_variables: reset_variables VARIABLE  */
#line 422 "gram.yy"
                { reset((yyvsp[0].str)); a_delete (yyvsp[0].str); }
#line 2510 "gram.cc"
    break;

  case 38: /* reset_variables: reset_variables ',' VARIABLE  */
#line 424 "gram.yy"
                { reset((yyvsp[0].str)); a_delete (yyvsp[0].str); }
#line 2516 "gram.cc"
    break;

  case 39: /* print_args: print_arg  */
#line 429 "gram.yy"
                { (yyval.lstr) = (yyvsp[0].lstr); }
#line 2522 "gram.cc"
    break;

  case 40: /* print_args: print_args print_arg  */
#line 431 "gram.yy"
                {
		  (yyval.lstr).str = new char[strlen((yyvsp[-1].lstr).str) + strlen((yyvsp[0].lstr).str) + 1];
		  strcpy((yyval.lstr).str, (yyvsp[-1].lstr).str);
		  strcat((yyval.lstr).str, (yyvsp[0].lstr).str);
		  a_delete (yyvsp[-1].lstr).str;
		  a_delete (yyvsp[0].lstr).str;
		  if ((yyvsp[-1].lstr).filename) 
		    {
		      (yyval.lstr).filename = (yyvsp[-1].lstr).filename;
		      (yyval.lstr).lineno = (yyvsp[-1].lstr).lineno;
		    }
		  else if ((yyvsp[0].lstr).filename) 
		    {
		      (yyval.lstr).filename = (yyvsp[0].lstr).filename;
		      (yyval.lstr).lineno = (yyvsp[0].lstr).lineno;
		    }
		}
#line 2544 "gram.cc"
    break;

  case 41: /* print_arg: expr  */
#line 452 "gram.yy"
                {
		  (yyval.lstr).str = new char[GDIGITS + 1];
		  sprintf((yyval.lstr).str, "%g", (yyvsp[0].x));
		  (yyval.lstr).filename = 0;
		  (yyval.lstr).lineno = 0;
		}
#line 2555 "gram.cc"
    break;

  case 42: /* print_arg: text  */
#line 459 "gram.yy"
                { (yyval.lstr) = (yyvsp[0].lstr); }
#line 2561 "gram.cc"
    break;

  case 43: /* print_arg: position  */
#line 461 "gram.yy"
                {
		  (yyval.lstr).str = new char[GDIGITS + 2 + GDIGITS + 1];
		  sprintf((yyval.lstr).str, "%g, %g", (yyvsp[0].pair).x, (yyvsp[0].pair).y);
		  (yyval.lstr).filename = 0;
		  (yyval.lstr).lineno = 0;
		}
#line 2572 "gram.cc"
    break;

  case 44: /* $@8: %empty  */
#line 470 "gram.yy"
                { delim_flag = 1; }
#line 2578 "gram.cc"
    break;

  case 45: /* simple_if: IF any_expr THEN $@8 DELIMITED  */
#line 472 "gram.yy"
                { delim_flag = 0; (yyval.if_data).x = (yyvsp[-3].x); (yyval.if_data).body = (yyvsp[0].str); }
#line 2584 "gram.cc"
    break;

  case 46: /* until: %empty  */
#line 477 "gram.yy"
                { (yyval.str) = 0; }
#line 2590 "gram.cc"
    break;

  case 47: /* until: UNTIL TEXT  */
#line 479 "gram.yy"
                { (yyval.str) = (yyvsp[0].lstr).str; }
#line 2596 "gram.cc"
    break;

  case 48: /* any_expr: expr  */
#line 484 "gram.yy"
                { (yyval.x) = (yyvsp[0].x); }
#line 2602 "gram.cc"
    break;

  case 49: /* any_expr: text_expr  */
#line 486 "gram.yy"
                { (yyval.x) = (yyvsp[0].x); }
#line 2608 "gram.cc"
    break;

  case 50: /* text_expr: text EQUALEQUAL text  */
#line 491 "gram.yy"
                {
		  (yyval.x) = strcmp((yyvsp[-2].lstr).str, (yyvsp[0].lstr).str) == 0;
		  a_delete (yyvsp[-2].lstr).str;
		  a_delete (yyvsp[0].lstr).str;
		}
#line 2618 "gram.cc"
    break;

  case 51: /* text_expr: text NOTEQUAL text  */
#line 497 "gram.yy"
                {
		  (yyval.x) = strcmp((yyvsp[-2].lstr).str, (yyvsp[0].lstr).str) != 0;
		  a_delete (yyvsp[-2].lstr).str;
		  a_delete (yyvsp[0].lstr).str;
		}
#line 2628 "gram.cc"
    break;

  case 52: /* text_expr: text_expr ANDAND text_expr  */
#line 503 "gram.yy"
                { (yyval.x) = ((yyvsp[-2].x) != 0.0 && (yyvsp[0].x) != 0.0); }
#line 2634 "gram.cc"
    break;

  case 53: /* text_expr: text_expr ANDAND expr  */
#line 505 "gram.yy"
                { (yyval.x) = ((yyvsp[-2].x) != 0.0 && (yyvsp[0].x) != 0.0); }
#line 2640 "gram.cc"
    break;

  case 54: /* text_expr: expr ANDAND text_expr  */
#line 507 "gram.yy"
                { (yyval.x) = ((yyvsp[-2].x) != 0.0 && (yyvsp[0].x) != 0.0); }
#line 2646 "gram.cc"
    break;

  case 55: /* text_expr: text_expr OROR text_expr  */
#line 509 "gram.yy"
                { (yyval.x) = ((yyvsp[-2].x) != 0.0 || (yyvsp[0].x) != 0.0); }
#line 2652 "gram.cc"
    break;

  case 56: /* text_expr: text_expr OROR expr  */
#line 511 "gram.yy"
                { (yyval.x) = ((yyvsp[-2].x) != 0.0 || (yyvsp[0].x) != 0.0); }
#line 2658 "gram.cc"
    break;

  case 57: /* text_expr: expr OROR text_expr  */
#line 513 "gram.yy"
                { (yyval.x) = ((yyvsp[-2].x) != 0.0 || (yyvsp[0].x) != 0.0); }
#line 2664 "gram.cc"
    break;

  case 58: /* text_expr: '!' text_expr  */
#line 515 "gram.yy"
                { (yyval.x) = ((yyvsp[0].x) == 0.0); }
#line 2670 "gram.cc"
    break;

  case 59: /* optional_by: %empty  */
#line 521 "gram.yy"
                { (yyval.by).val = 1.0; (yyval.by).is_multiplicative = 0; }
#line 2676 "gram.cc"
    break;

  case 60: /* optional_by: BY expr  */
#line 523 "gram.yy"
                { (yyval.by).val = (yyvsp[0].x); (yyval.by).is_multiplicative = 0; }
#line 2682 "gram.cc"
    break;

  case 61: /* optional_by: BY '*' expr  */
#line 525 "gram.yy"
                { (yyval.by).val = (yyvsp[0].x); (yyval.by).is_multiplicative = 1; }
#line 2688 "gram.cc"
    break;

  case 62: /* element: object_spec  */
#line 530 "gram.yy"
                {
		  (yyval.pl).obj = (yyvsp[0].spec)->make_object(&current_position,
					   &current_direction);
		  if ((yyval.pl).obj == 0)
		    YYABORT;
		  delete (yyvsp[0].spec);
		  if ((yyval.pl).obj)
		    olist.append((yyval.pl).obj);
		  else 
		    {
		      (yyval.pl).x = current_position.x;
		      (yyval.pl).y = current_position.y;
		    }
		}
#line 2707 "gram.cc"
    break;

  case 63: /* element: LABEL ':' optional_separator element  */
#line 545 "gram.yy"
                { (yyval.pl) = (yyvsp[0].pl); define_label((yyvsp[-3].str), & (yyval.pl)); a_delete (yyvsp[-3].str); }
#line 2713 "gram.cc"
    break;

  case 64: /* element: LABEL ':' optional_separator position_not_place  */
#line 547 "gram.yy"
                {
		  (yyval.pl).obj = 0;
		  (yyval.pl).x = (yyvsp[0].pair).x;
		  (yyval.pl).y = (yyvsp[0].pair).y;
		  define_label((yyvsp[-3].str), & (yyval.pl));
		  a_delete (yyvsp[-3].str);
		}
#line 2725 "gram.cc"
    break;

  case 65: /* element: LABEL ':' optional_separator place  */
#line 555 "gram.yy"
                {
		  (yyval.pl) = (yyvsp[0].pl);
		  define_label((yyvsp[-3].str), & (yyval.pl));
		  a_delete (yyvsp[-3].str);
		}
#line 2735 "gram.cc"
    break;

  case 66: /* @9: %empty  */
#line 561 "gram.yy"
                {
		  (yyval.state).x = current_position.x;
		  (yyval.state).y = current_position.y;
		  (yyval.state).dir = current_direction;
		}
#line 2745 "gram.cc"
    break;

  case 67: /* $@10: %empty  */
#line 567 "gram.yy"
                {
		  current_position.x = (yyvsp[-2].state).x;
		  current_position.y = (yyvsp[-2].state).y;
		  current_direction = (yyvsp[-2].state).dir;
		}
#line 2755 "gram.cc"
    break;

  case 68: /* element: '{' @9 element_list '}' $@10 optional_element  */
#line 573 "gram.yy"
                {
		  (yyval.pl) = (yyvsp[-3].pl);
		}
#line 2763 "gram.cc"
    break;

  case 69: /* element: placeless_element  */
#line 577 "gram.yy"
                {
		  (yyval.pl).obj = 0;
		  (yyval.pl).x = current_position.x;
		  (yyval.pl).y = current_position.y;
		}
#line 2773 "gram.cc"
    break;

  case 70: /* optional_element: %empty  */
#line 586 "gram.yy"
                {}
#line 2779 "gram.cc"
    break;

  case 71: /* optional_element: element  */
#line 588 "gram.yy"
                {}
#line 2785 "gram.cc"
    break;

  case 72: /* object_spec: BOX  */
#line 593 "gram.yy"
                {
		  (yyval.spec) = new object_spec(BOX_OBJECT);
		}
#line 2793 "gram.cc"
    break;

  case 73: /* object_spec: CIRCLE  */
#line 597 "gram.yy"
                {
		  (yyval.spec) = new object_spec(CIRCLE_OBJECT);
		}
#line 2801 "gram.cc"
    break;

  case 74: /* object_spec: ELLIPSE  */
#line 601 "gram.yy"
                {
		  (yyval.spec) = new object_spec(ELLIPSE_OBJECT);
		}
#line 2809 "gram.cc"
    break;

  case 75: /* object_spec: ARC  */
#line 605 "gram.yy"
                {
		  (yyval.spec) = new object_spec(ARC_OBJECT);
		  (yyval.spec)->dir = current_direction;
		}
#line 2818 "gram.cc"
    break;

  case 76: /* object_spec: LINE  */
#line 610 "gram.yy"
                {
		  (yyval.spec) = new object_spec(LINE_OBJECT);
		  lookup_variable("lineht", & (yyval.spec)->segment_height);
		  lookup_variable("linewid", & (yyval.spec)->segment_width);
		  (yyval.spec)->dir = current_direction;
		}
#line 2829 "gram.cc"
    break;

  case 77: /* object_spec: ARROW  */
#line 617 "gram.yy"
                {
		  (yyval.spec) = new object_spec(ARROW_OBJECT);
		  lookup_variable("lineht", & (yyval.spec)->segment_height);
		  lookup_variable("linewid", & (yyval.spec)->segment_width);
		  (yyval.spec)->dir = current_direction;
		}
#line 2840 "gram.cc"
    break;

  case 78: /* object_spec: MOVE  */
#line 624 "gram.yy"
                {
		  (yyval.spec) = new object_spec(MOVE_OBJECT);
		  lookup_variable("moveht", & (yyval.spec)->segment_height);
		  lookup_variable("movewid", & (yyval.spec)->segment_width);
		  (yyval.spec)->dir = current_direction;
		}
#line 2851 "gram.cc"
    break;

  case 79: /* object_spec: SPLINE  */
#line 631 "gram.yy"
                {
		  (yyval.spec) = new object_spec(SPLINE_OBJECT);
		  lookup_variable("lineht", & (yyval.spec)->segment_height);
		  lookup_variable("linewid", & (yyval.spec)->segment_width);
		  (yyval.spec)->dir = current_direction;
		}
#line 2862 "gram.cc"
    break;

  case 80: /* object_spec: text  */
#line 638 "gram.yy"
                {
		  (yyval.spec) = new object_spec(TEXT_OBJECT);
		  (yyval.spec)->text = new text_item((yyvsp[0].lstr).str, (yyvsp[0].lstr).filename, (yyvsp[0].lstr).lineno);
		}
#line 2871 "gram.cc"
    break;

  case 81: /* object_spec: PLOT expr  */
#line 643 "gram.yy"
                {
		  (yyval.spec) = new object_spec(TEXT_OBJECT);
		  (yyval.spec)->text = new text_item(format_number(0, (yyvsp[0].x)), 0, -1);
		}
#line 2880 "gram.cc"
    break;

  case 82: /* object_spec: PLOT expr text  */
#line 648 "gram.yy"
                {
		  (yyval.spec) = new object_spec(TEXT_OBJECT);
		  (yyval.spec)->text = new text_item(format_number((yyvsp[0].lstr).str, (yyvsp[-1].x)),
					   (yyvsp[0].lstr).filename, (yyvsp[0].lstr).lineno);
		  a_delete (yyvsp[0].lstr).str;
		}
#line 2891 "gram.cc"
    break;

  case 83: /* @11: %empty  */
#line 655 "gram.yy"
                {
		  saved_state *p = new saved_state;
		  (yyval.pstate) = p;
		  p->x = current_position.x;
		  p->y = current_position.y;
		  p->dir = current_direction;
		  p->tbl = current_table;
		  p->prev = current_saved_state;
		  current_position.x = 0.0;
		  current_position.y = 0.0;
		  current_table = new PTABLE(place);
		  current_saved_state = p;
		  olist.append(make_mark_object());
		}
#line 2910 "gram.cc"
    break;

  case 84: /* object_spec: '[' @11 element_list ']'  */
#line 670 "gram.yy"
                {
		  current_position.x = (yyvsp[-2].pstate)->x;
		  current_position.y = (yyvsp[-2].pstate)->y;
		  current_direction = (yyvsp[-2].pstate)->dir;
		  (yyval.spec) = new object_spec(BLOCK_OBJECT);
		  olist.wrap_up_block(& (yyval.spec)->oblist);
		  (yyval.spec)->tbl = current_table;
		  current_table = (yyvsp[-2].pstate)->tbl;
		  current_saved_state = (yyvsp[-2].pstate)->prev;
		  delete (yyvsp[-2].pstate);
		}
#line 2926 "gram.cc"
    break;

  case 85: /* object_spec: object_spec HEIGHT expr  */
#line 682 "gram.yy"
                {
		  (yyval.spec) = (yyvsp[-2].spec);
		  (yyval.spec)->height = (yyvsp[0].x);
		  (yyval.spec)->flags |= HAS_HEIGHT;
		}
#line 2936 "gram.cc"
    break;

  case 86: /* object_spec: object_spec RADIUS expr  */
#line 688 "gram.yy"
                {
		  (yyval.spec) = (yyvsp[-2].spec);
		  (yyval.spec)->radius = (yyvsp[0].x);
		  (yyval.spec)->flags |= HAS_RADIUS;
		}
#line 2946 "gram.cc"
    break;

  case 87: /* object_spec: object_spec WIDTH expr  */
#line 694 "gram.yy"
                {
		  (yyval.spec) = (yyvsp[-2].spec);
		  (yyval.spec)->width = (yyvsp[0].x);
		  (yyval.spec)->flags |= HAS_WIDTH;
		}
#line 2956 "gram.cc"
    break;

  case 88: /* object_spec: object_spec DIAMETER expr  */
#line 700 "gram.yy"
                {
		  (yyval.spec) = (yyvsp[-2].spec);
		  (yyval.spec)->radius = (yyvsp[0].x)/2.0;
		  (yyval.spec)->flags |= HAS_RADIUS;
		}
#line 2966 "gram.cc"
    break;

  case 89: /* object_spec: object_spec expr  */
#line 706 "gram.yy"
                {
		  (yyval.spec) = (yyvsp[-1].spec);
		  (yyval.spec)->flags |= HAS_SEGMENT;
		  switch ((yyval.spec)->dir) 
		    {
		    case UP_DIRECTION:
		      (yyval.spec)->segment_pos.y += (yyvsp[0].x);
		      break;
		    case DOWN_DIRECTION:
		      (yyval.spec)->segment_pos.y -= (yyvsp[0].x);
		      break;
		    case RIGHT_DIRECTION:
		      (yyval.spec)->segment_pos.x += (yyvsp[0].x);
		      break;
		    case LEFT_DIRECTION:
		      (yyval.spec)->segment_pos.x -= (yyvsp[0].x);
		      break;
		    }
		}
#line 2990 "gram.cc"
    break;

  case 90: /* object_spec: object_spec UP  */
#line 726 "gram.yy"
                {
		  (yyval.spec) = (yyvsp[-1].spec);
		  (yyval.spec)->dir = UP_DIRECTION;
		  (yyval.spec)->flags |= HAS_SEGMENT;
		  (yyval.spec)->segment_pos.y += (yyval.spec)->segment_height;
		}
#line 3001 "gram.cc"
    break;

  case 91: /* object_spec: object_spec UP expr  */
#line 733 "gram.yy"
                {
		  (yyval.spec) = (yyvsp[-2].spec);
		  (yyval.spec)->dir = UP_DIRECTION;
		  (yyval.spec)->flags |= HAS_SEGMENT;
		  (yyval.spec)->segment_pos.y += (yyvsp[0].x);
		}
#line 3012 "gram.cc"
    break;

  case 92: /* object_spec: object_spec DOWN  */
#line 740 "gram.yy"
                {
		  (yyval.spec) = (yyvsp[-1].spec);
		  (yyval.spec)->dir = DOWN_DIRECTION;
		  (yyval.spec)->flags |= HAS_SEGMENT;
		  (yyval.spec)->segment_pos.y -= (yyval.spec)->segment_height;
		}
#line 3023 "gram.cc"
    break;

  case 93: /* object_spec: object_spec DOWN expr  */
#line 747 "gram.yy"
                {
		  (yyval.spec) = (yyvsp[-2].spec);
		  (yyval.spec)->dir = DOWN_DIRECTION;
		  (yyval.spec)->flags |= HAS_SEGMENT;
		  (yyval.spec)->segment_pos.y -= (yyvsp[0].x);
		}
#line 3034 "gram.cc"
    break;

  case 94: /* object_spec: object_spec RIGHT  */
#line 754 "gram.yy"
                {
		  (yyval.spec) = (yyvsp[-1].spec);
		  (yyval.spec)->dir = RIGHT_DIRECTION;
		  (yyval.spec)->flags |= HAS_SEGMENT;
		  (yyval.spec)->segment_pos.x += (yyval.spec)->segment_width;
		}
#line 3045 "gram.cc"
    break;

  case 95: /* object_spec: object_spec RIGHT expr  */
#line 761 "gram.yy"
                {
		  (yyval.spec) = (yyvsp[-2].spec);
		  (yyval.spec)->dir = RIGHT_DIRECTION;
		  (yyval.spec)->flags |= HAS_SEGMENT;
		  (yyval.spec)->segment_pos.x += (yyvsp[0].x);
		}
#line 3056 "gram.cc"
    break;

  case 96: /* object_spec: object_spec LEFT  */
#line 768 "gram.yy"
                {
		  (yyval.spec) = (yyvsp[-1].spec);
		  (yyval.spec)->dir = LEFT_DIRECTION;
		  (yyval.spec)->flags |= HAS_SEGMENT;
		  (yyval.spec)->segment_pos.x -= (yyval.spec)->segment_width;
		}
#line 3067 "gram.cc"
    break;

  case 97: /* object_spec: object_spec LEFT expr  */
#line 775 "gram.yy"
                {
		  (yyval.spec) = (yyvsp[-2].spec);
		  (yyval.spec)->dir = LEFT_DIRECTION;
		  (yyval.spec)->flags |= HAS_SEGMENT;
		  (yyval.spec)->segment_pos.x -= (yyvsp[0].x);
		}
#line 3078 "gram.cc"
    break;

  case 98: /* object_spec: object_spec FROM position  */
#line 782 "gram.yy"
                {
		  (yyval.spec) = (yyvsp[-2].spec);
		  (yyval.spec)->flags |= HAS_FROM;
		  (yyval.spec)->from.x = (yyvsp[0].pair).x;
		  (yyval.spec)->from.y = (yyvsp[0].pair).y;
		}
#line 3089 "gram.cc"
    break;

  case 99: /* object_spec: object_spec TO position  */
#line 789 "gram.yy"
                {
		  (yyval.spec) = (yyvsp[-2].spec);
		  if ((yyval.spec)->flags & HAS_SEGMENT)
		    (yyval.spec)->segment_list = new segment((yyval.spec)->segment_pos,
						   (yyval.spec)->segment_is_absolute,
						   (yyval.spec)->segment_list);
		  (yyval.spec)->flags |= HAS_SEGMENT;
		  (yyval.spec)->segment_pos.x = (yyvsp[0].pair).x;
		  (yyval.spec)->segment_pos.y = (yyvsp[0].pair).y;
		  (yyval.spec)->segment_is_absolute = 1;
		  (yyval.spec)->flags |= HAS_TO;
		  (yyval.spec)->to.x = (yyvsp[0].pair).x;
		  (yyval.spec)->to.y = (yyvsp[0].pair).y;
		}
#line 3108 "gram.cc"
    break;

  case 100: /* object_spec: object_spec AT position  */
#line 804 "gram.yy"
                {
		  (yyval.spec) = (yyvsp[-2].spec);
		  (yyval.spec)->flags |= HAS_AT;
		  (yyval.spec)->at.x = (yyvsp[0].pair).x;
		  (yyval.spec)->at.y = (yyvsp[0].pair).y;
		  if ((yyval.spec)->type != ARC_OBJECT)
		    {
		      (yyval.spec)->flags |= HAS_FROM;
		      (yyval.spec)->from.x = (yyvsp[0].pair).x;
		      (yyval.spec)->from.y = (yyvsp[0].pair).y;
		    }
		}
#line 3125 "gram.cc"
    break;

  case 101: /* object_spec: object_spec WITH path  */
#line 817 "gram.yy"
                {
		  (yyval.spec) = (yyvsp[-2].spec);
		  (yyval.spec)->flags |= HAS_WITH;
		  (yyval.spec)->with = (yyvsp[0].pth);
		}
#line 3135 "gram.cc"
    break;

  case 102: /* object_spec: object_spec BY expr_pair  */
#line 823 "gram.yy"
                {
		  (yyval.spec) = (yyvsp[-2].spec);
		  (yyval.spec)->flags |= HAS_SEGMENT;
		  (yyval.spec)->segment_pos.x += (yyvsp[0].pair).x;
		  (yyval.spec)->segment_pos.y += (yyvsp[0].pair).y;
		}
#line 3146 "gram.cc"
    break;

  case 103: /* object_spec: object_spec THEN  */
#line 830 "gram.yy"
                {
		  (yyval.spec) = (yyvsp[-1].spec);
		  if ((yyval.spec)->flags & HAS_SEGMENT) 
		    {
		      (yyval.spec)->segment_list = new segment((yyval.spec)->segment_pos,
						     (yyval.spec)->segment_is_absolute,
						     (yyval.spec)->segment_list);
		      (yyval.spec)->flags &= ~HAS_SEGMENT;
		      (yyval.spec)->segment_pos.x = (yyval.spec)->segment_pos.y = 0.0;
		      (yyval.spec)->segment_is_absolute = 0;
		    }
		}
#line 3163 "gram.cc"
    break;

  case 104: /* object_spec: object_spec DOTTED  */
#line 843 "gram.yy"
                {
		  (yyval.spec) = (yyvsp[-1].spec);
		  (yyval.spec)->flags |= IS_DOTTED;
		  lookup_variable("dashwid", & (yyval.spec)->dash_width);
		}
#line 3173 "gram.cc"
    break;

  case 105: /* object_spec: object_spec DOTTED expr  */
#line 849 "gram.yy"
                {
		  (yyval.spec) = (yyvsp[-2].spec);
		  (yyval.spec)->flags |= IS_DOTTED;
		  (yyval.spec)->dash_width = (yyvsp[0].x);
		}
#line 3183 "gram.cc"
    break;

  case 106: /* object_spec: object_spec DASHED  */
#line 855 "gram.yy"
                {
		  (yyval.spec) = (yyvsp[-1].spec);
		  (yyval.spec)->flags |= IS_DASHED;
		  lookup_variable("dashwid", & (yyval.spec)->dash_width);
		}
#line 3193 "gram.cc"
    break;

  case 107: /* object_spec: object_spec DASHED expr  */
#line 861 "gram.yy"
                {
		  (yyval.spec) = (yyvsp[-2].spec);
		  (yyval.spec)->flags |= IS_DASHED;
		  (yyval.spec)->dash_width = (yyvsp[0].x);
		}
#line 3203 "gram.cc"
    break;

  case 108: /* object_spec: object_spec FILL  */
#line 867 "gram.yy"
                {
		  (yyval.spec) = (yyvsp[-1].spec);
		  (yyval.spec)->flags |= IS_DEFAULT_FILLED;
		}
#line 3212 "gram.cc"
    break;

  case 109: /* object_spec: object_spec FILL expr  */
#line 872 "gram.yy"
                {
		  (yyval.spec) = (yyvsp[-2].spec);
		  (yyval.spec)->flags |= IS_FILLED;
		  (yyval.spec)->fill = (yyvsp[0].x);
		}
#line 3222 "gram.cc"
    break;

  case 110: /* object_spec: object_spec CHOP  */
#line 878 "gram.yy"
                {
		  (yyval.spec) = (yyvsp[-1].spec);
		  // line chop chop means line chop 0 chop 0
		  if ((yyval.spec)->flags & IS_DEFAULT_CHOPPED) 
		    {
		      (yyval.spec)->flags |= IS_CHOPPED;
		      (yyval.spec)->flags &= ~IS_DEFAULT_CHOPPED;
		      (yyval.spec)->start_chop = (yyval.spec)->end_chop = 0.0;
		    }
		  else if ((yyval.spec)->flags & IS_CHOPPED) 
		    {
		      (yyval.spec)->end_chop = 0.0;
		    }
		  else 
		    {
		      (yyval.spec)->flags |= IS_DEFAULT_CHOPPED;
		    }
		}
#line 3245 "gram.cc"
    break;

  case 111: /* object_spec: object_spec CHOP expr  */
#line 897 "gram.yy"
                {
		  (yyval.spec) = (yyvsp[-2].spec);
		  if ((yyval.spec)->flags & IS_DEFAULT_CHOPPED) 
		    {
		      (yyval.spec)->flags |= IS_CHOPPED;
		      (yyval.spec)->flags &= ~IS_DEFAULT_CHOPPED;
		      (yyval.spec)->start_chop = 0.0;
		      (yyval.spec)->end_chop = (yyvsp[0].x);
		    }
		  else if ((yyval.spec)->flags & IS_CHOPPED) 
		    {
		      (yyval.spec)->end_chop = (yyvsp[0].x);
		    }
		  else 
		    {
		      (yyval.spec)->start_chop = (yyval.spec)->end_chop = (yyvsp[0].x);
		      (yyval.spec)->flags |= IS_CHOPPED;
		    }
		}
#line 3269 "gram.cc"
    break;

  case 112: /* object_spec: object_spec SAME  */
#line 917 "gram.yy"
                {
		  (yyval.spec) = (yyvsp[-1].spec);
		  (yyval.spec)->flags |= IS_SAME;
		}
#line 3278 "gram.cc"
    break;

  case 113: /* object_spec: object_spec INVISIBLE  */
#line 922 "gram.yy"
                {
		  (yyval.spec) = (yyvsp[-1].spec);
		  (yyval.spec)->flags |= IS_INVISIBLE;
		}
#line 3287 "gram.cc"
    break;

  case 114: /* object_spec: object_spec LEFT_ARROW_HEAD  */
#line 927 "gram.yy"
                {
		  (yyval.spec) = (yyvsp[-1].spec);
		  (yyval.spec)->flags |= HAS_LEFT_ARROW_HEAD;
		}
#line 3296 "gram.cc"
    break;

  case 115: /* object_spec: object_spec RIGHT_ARROW_HEAD  */
#line 932 "gram.yy"
                {
		  (yyval.spec) = (yyvsp[-1].spec);
		  (yyval.spec)->flags |= HAS_RIGHT_ARROW_HEAD;
		}
#line 3305 "gram.cc"
    break;

  case 116: /* object_spec: object_spec DOUBLE_ARROW_HEAD  */
#line 937 "gram.yy"
                {
		  (yyval.spec) = (yyvsp[-1].spec);
		  (yyval.spec)->flags |= (HAS_LEFT_ARROW_HEAD|HAS_RIGHT_ARROW_HEAD);
		}
#line 3314 "gram.cc"
    break;

  case 117: /* object_spec: object_spec CW  */
#line 942 "gram.yy"
                {
		  (yyval.spec) = (yyvsp[-1].spec);
		  (yyval.spec)->flags |= IS_CLOCKWISE;
		}
#line 3323 "gram.cc"
    break;

  case 118: /* object_spec: object_spec CCW  */
#line 947 "gram.yy"
                {
		  (yyval.spec) = (yyvsp[-1].spec);
		  (yyval.spec)->flags &= ~IS_CLOCKWISE;
		}
#line 3332 "gram.cc"
    break;

  case 119: /* object_spec: object_spec text  */
#line 952 "gram.yy"
                {
		  (yyval.spec) = (yyvsp[-1].spec);
		  text_item **p;
		  for (p = & (yyval.spec)->text; *p; p = &(*p)->next)
		    ;
		  *p = new text_item((yyvsp[0].lstr).str, (yyvsp[0].lstr).filename, (yyvsp[0].lstr).lineno);
		}
#line 3344 "gram.cc"
    break;

  case 120: /* object_spec: object_spec LJUST  */
#line 960 "gram.yy"
                {
		  (yyval.spec) = (yyvsp[-1].spec);
		  if ((yyval.spec)->text) 
		    {
		      text_item *p;
		      for (p = (yyval.spec)->text; p->next; p = p->next)
			;
		      p->adj.h = LEFT_ADJUST;
		    }
		}
#line 3359 "gram.cc"
    break;

  case 121: /* object_spec: object_spec RJUST  */
#line 971 "gram.yy"
                {
		  (yyval.spec) = (yyvsp[-1].spec);
		  if ((yyval.spec)->text) 
		    {
		      text_item *p;
		      for (p = (yyval.spec)->text; p->next; p = p->next)
			;
		      p->adj.h = RIGHT_ADJUST;
		    }
		}
#line 3374 "gram.cc"
    break;

  case 122: /* object_spec: object_spec ABOVE  */
#line 982 "gram.yy"
                {
		  (yyval.spec) = (yyvsp[-1].spec);
		  if ((yyval.spec)->text) 
		    {
		      text_item *p;
		      for (p = (yyval.spec)->text; p->next; p = p->next)
			;
		      p->adj.v = ABOVE_ADJUST;
		    }
		}
#line 3389 "gram.cc"
    break;

  case 123: /* object_spec: object_spec BELOW  */
#line 993 "gram.yy"
                {
		  (yyval.spec) = (yyvsp[-1].spec);
		  if ((yyval.spec)->text) 
		    {
		      text_item *p;
		      for (p = (yyval.spec)->text; p->next; p = p->next)
			;
		      p->adj.v = BELOW_ADJUST;
		    }
		}
#line 3404 "gram.cc"
    break;

  case 124: /* object_spec: object_spec THICKNESS expr  */
#line 1004 "gram.yy"
                {
		  (yyval.spec) = (yyvsp[-2].spec);
		  (yyval.spec)->flags |= HAS_THICKNESS;
		  (yyval.spec)->thickness = (yyvsp[0].x);
		}
#line 3414 "gram.cc"
    break;

  case 125: /* object_spec: object_spec ALIGNED  */
#line 1010 "gram.yy"
                {
		  (yyval.spec) = (yyvsp[-1].spec);
		  (yyval.spec)->flags |= IS_ALIGNED;
		}
#line 3423 "gram.cc"
    break;

  case 126: /* text: TEXT  */
#line 1018 "gram.yy"
                {
		  (yyval.lstr) = (yyvsp[0].lstr);
		}
#line 3431 "gram.cc"
    break;

  case 127: /* text: SPRINTF '(' TEXT sprintf_args ')'  */
#line 1022 "gram.yy"
                {
		  (yyval.lstr).filename = (yyvsp[-2].lstr).filename;
		  (yyval.lstr).lineno = (yyvsp[-2].lstr).lineno;
		  (yyval.lstr).str = do_sprintf((yyvsp[-2].lstr).str, (yyvsp[-1].dv).v, (yyvsp[-1].dv).nv);
		  a_delete (yyvsp[-1].dv).v;
		  a_delete (yyvsp[-2].lstr).str;
		}
#line 3443 "gram.cc"
    break;

  case 128: /* sprintf_args: %empty  */
#line 1033 "gram.yy"
                {
		  (yyval.dv).v = 0;
		  (yyval.dv).nv = 0;
		  (yyval.dv).maxv = 0;
		}
#line 3453 "gram.cc"
    break;

  case 129: /* sprintf_args: sprintf_args ',' expr  */
#line 1039 "gram.yy"
                {
		  (yyval.dv) = (yyvsp[-2].dv);
		  if ((yyval.dv).nv >= (yyval.dv).maxv) 
		    {
		      if ((yyval.dv).nv == 0) 
			{
			  (yyval.dv).v = new double[4];
			  (yyval.dv).maxv = 4;
			}
		      else 
			{
			  double *oldv = (yyval.dv).v;
			  (yyval.dv).maxv *= 2;
			  (yyval.dv).v = new double[(yyval.dv).maxv];
			  memcpy((yyval.dv).v, oldv, (yyval.dv).nv*sizeof(double));
			  a_delete oldv;
			}
		    }
		  (yyval.dv).v[(yyval.dv).nv] = (yyvsp[0].x);
		  (yyval.dv).nv += 1;
		}
#line 3479 "gram.cc"
    break;

  case 130: /* position: position_not_place  */
#line 1064 "gram.yy"
                { (yyval.pair) = (yyvsp[0].pair); }
#line 3485 "gram.cc"
    break;

  case 131: /* position: place  */
#line 1066 "gram.yy"
                {
		  position pos = (yyvsp[0].pl);
		  (yyval.pair).x = pos.x;
		  (yyval.pair).y = pos.y;
		}
#line 3495 "gram.cc"
    break;

  case 132: /* position_not_place: expr_pair  */
#line 1075 "gram.yy"
                { (yyval.pair) = (yyvsp[0].pair); }
#line 3501 "gram.cc"
    break;

  case 133: /* position_not_place: position '+' expr_pair  */
#line 1077 "gram.yy"
                {
		  (yyval.pair).x = (yyvsp[-2].pair).x + (yyvsp[0].pair).x;
		  (yyval.pair).y = (yyvsp[-2].pair).y + (yyvsp[0].pair).y;
		}
#line 3510 "gram.cc"
    break;

  case 134: /* position_not_place: position '-' expr_pair  */
#line 1082 "gram.yy"
                {
		  (yyval.pair).x = (yyvsp[-2].pair).x - (yyvsp[0].pair).x;
		  (yyval.pair).y = (yyvsp[-2].pair).y - (yyvsp[0].pair).y;
		}
#line 3519 "gram.cc"
    break;

  case 135: /* position_not_place: '(' position ',' position ')'  */
#line 1087 "gram.yy"
                {
		  (yyval.pair).x = (yyvsp[-3].pair).x;
		  (yyval.pair).y = (yyvsp[-1].pair).y;
		}
#line 3528 "gram.cc"
    break;

  case 136: /* position_not_place: expr between position AND position  */
#line 1092 "gram.yy"
                {
		  (yyval.pair).x = (1.0 - (yyvsp[-4].x))*(yyvsp[-2].pair).x + (yyvsp[-4].x)*(yyvsp[0].pair).x;
		  (yyval.pair).y = (1.0 - (yyvsp[-4].x))*(yyvsp[-2].pair).y + (yyvsp[-4].x)*(yyvsp[0].pair).y;
		}
#line 3537 "gram.cc"
    break;

  case 137: /* position_not_place: expr '<' position ',' position '>'  */
#line 1097 "gram.yy"
                {
		  (yyval.pair).x = (1.0 - (yyvsp[-5].x))*(yyvsp[-3].pair).x + (yyvsp[-5].x)*(yyvsp[-1].pair).x;
		  (yyval.pair).y = (1.0 - (yyvsp[-5].x))*(yyvsp[-3].pair).y + (yyvsp[-5].x)*(yyvsp[-1].pair).y;
		}
#line 3546 "gram.cc"
    break;

  case 140: /* expr_pair: expr ',' expr  */
#line 1110 "gram.yy"
                { (yyval.pair).x = (yyvsp[-2].x); (yyval.pair).y = (yyvsp[0].x); }
#line 3552 "gram.cc"
    break;

  case 141: /* expr_pair: '(' expr_pair ')'  */
#line 1112 "gram.yy"
                { (yyval.pair) = (yyvsp[-1].pair); }
#line 3558 "gram.cc"
    break;

  case 142: /* place: label  */
#line 1117 "gram.yy"
                { (yyval.pl) = (yyvsp[0].pl); }
#line 3564 "gram.cc"
    break;

  case 143: /* place: label corner  */
#line 1119 "gram.yy"
                {
		  path pth((yyvsp[0].crn));
		  if (!pth.follow((yyvsp[-1].pl), & (yyval.pl)))
		    YYABORT;
		}
#line 3574 "gram.cc"
    break;

  case 144: /* place: corner label  */
#line 1125 "gram.yy"
                {
		  path pth((yyvsp[-1].crn));
		  if (!pth.follow((yyvsp[0].pl), & (yyval.pl)))
		    YYABORT;
		}
#line 3584 "gram.cc"
    break;

  case 145: /* place: corner OF label  */
#line 1131 "gram.yy"
                {
		  path pth((yyvsp[-2].crn));
		  if (!pth.follow((yyvsp[0].pl), & (yyval.pl)))
		    YYABORT;
		}
#line 3594 "gram.cc"
    break;

  case 146: /* place: HERE  */
#line 1137 "gram.yy"
                {
		  (yyval.pl).x = current_position.x;
		  (yyval.pl).y = current_position.y;
		  (yyval.pl).obj = 0;
		}
#line 3604 "gram.cc"
    break;

  case 147: /* label: LABEL  */
#line 1146 "gram.yy"
                {
		  place *p = lookup_label((yyvsp[0].str));
		  if (!p) 
		    {
		      lex_error("there is no place `%1'", (yyvsp[0].str));
		      YYABORT;
		    }
		  (yyval.pl) = *p;
		  a_delete (yyvsp[0].str);
		}
#line 3619 "gram.cc"
    break;

  case 148: /* label: nth_primitive  */
#line 1157 "gram.yy"
                {
		  (yyval.pl).obj = (yyvsp[0].obj);
		}
#line 3627 "gram.cc"
    break;

  case 149: /* label: label '.' LABEL  */
#line 1161 "gram.yy"
                {
		  path pth((yyvsp[0].str));
		  if (!pth.follow((yyvsp[-2].pl), & (yyval.pl)))
		    YYABORT;
		}
#line 3637 "gram.cc"
    break;

  case 150: /* ordinal: ORDINAL  */
#line 1170 "gram.yy"
                { (yyval.n) = (yyvsp[0].n); }
#line 3643 "gram.cc"
    break;

  case 151: /* ordinal: '`' any_expr TH  */
#line 1172 "gram.yy"
                {
		  // XXX Check for overflow (and non-integers?).
		  (yyval.n) = (int)(yyvsp[-1].x);
		}
#line 3652 "gram.cc"
    break;

  case 152: /* optional_ordinal_last: LAST  */
#line 1180 "gram.yy"
                { (yyval.n) = 1; }
#line 3658 "gram.cc"
    break;

  case 153: /* optional_ordinal_last: ordinal LAST  */
#line 1182 "gram.yy"
                { (yyval.n) = (yyvsp[-1].n); }
#line 3664 "gram.cc"
    break;

  case 154: /* nth_primitive: ordinal object_type  */
#line 1187 "gram.yy"
                {
		  int count = 0;
		  object *p;
		  for (p = olist.head; p != 0; p = p->next)
		    if (p->type() == (yyvsp[0].obtype) && ++count == (yyvsp[-1].n)) 
		      {
			(yyval.obj) = p;
			break;
		      }
		  if (p == 0) 
		    {
		      lex_error("there is no %1%2 %3", (yyvsp[-1].n), ordinal_postfix((yyvsp[-1].n)),
				object_type_name((yyvsp[0].obtype)));
		      YYABORT;
		    }
		}
#line 3685 "gram.cc"
    break;

  case 155: /* nth_primitive: optional_ordinal_last object_type  */
#line 1204 "gram.yy"
                {
		  int count = 0;
		  object *p;
		  for (p = olist.tail; p != 0; p = p->prev)
		    if (p->type() == (yyvsp[0].obtype) && ++count == (yyvsp[-1].n)) 
		      {
			(yyval.obj) = p;
			break;
		      }
		  if (p == 0) 
		    {
		      lex_error("there is no %1%2 last %3", (yyvsp[-1].n),
				ordinal_postfix((yyvsp[-1].n)), object_type_name((yyvsp[0].obtype)));
		      YYABORT;
		    }
		}
#line 3706 "gram.cc"
    break;

  case 156: /* object_type: BOX  */
#line 1224 "gram.yy"
                { (yyval.obtype) = BOX_OBJECT; }
#line 3712 "gram.cc"
    break;

  case 157: /* object_type: CIRCLE  */
#line 1226 "gram.yy"
                { (yyval.obtype) = CIRCLE_OBJECT; }
#line 3718 "gram.cc"
    break;

  case 158: /* object_type: ELLIPSE  */
#line 1228 "gram.yy"
                { (yyval.obtype) = ELLIPSE_OBJECT; }
#line 3724 "gram.cc"
    break;

  case 159: /* object_type: ARC  */
#line 1230 "gram.yy"
                { (yyval.obtype) = ARC_OBJECT; }
#line 3730 "gram.cc"
    break;

  case 160: /* object_type: LINE  */
#line 1232 "gram.yy"
                { (yyval.obtype) = LINE_OBJECT; }
#line 3736 "gram.cc"
    break;

  case 161: /* object_type: ARROW  */
#line 1234 "gram.yy"
                { (yyval.obtype) = ARROW_OBJECT; }
#line 3742 "gram.cc"
    break;

  case 162: /* object_type: SPLINE  */
#line 1236 "gram.yy"
                { (yyval.obtype) = SPLINE_OBJECT; }
#line 3748 "gram.cc"
    break;

  case 163: /* object_type: '[' ']'  */
#line 1238 "gram.yy"
                { (yyval.obtype) = BLOCK_OBJECT; }
#line 3754 "gram.cc"
    break;

  case 164: /* object_type: TEXT  */
#line 1240 "gram.yy"
                { (yyval.obtype) = TEXT_OBJECT; }
#line 3760 "gram.cc"
    break;

  case 165: /* label_path: '.' LABEL  */
#line 1245 "gram.yy"
                {
		  (yyval.pth) = new path((yyvsp[0].str));
		}
#line 3768 "gram.cc"
    break;

  case 166: /* label_path: label_path '.' LABEL  */
#line 1249 "gram.yy"
                {
		  (yyval.pth) = (yyvsp[-2].pth);
		  (yyval.pth)->append((yyvsp[0].str));
		}
#line 3777 "gram.cc"
    break;

  case 167: /* relative_path: corner  */
#line 1257 "gram.yy"
                {
		  (yyval.pth) = new path((yyvsp[0].crn));
		}
#line 3785 "gram.cc"
    break;

  case 168: /* relative_path: label_path  */
#line 1264 "gram.yy"
                {
		  (yyval.pth) = (yyvsp[0].pth);
		}
#line 3793 "gram.cc"
    break;

  case 169: /* relative_path: label_path corner  */
#line 1268 "gram.yy"
                {
		  (yyval.pth) = (yyvsp[-1].pth);
		  (yyval.pth)->append((yyvsp[0].crn));
		}
#line 3802 "gram.cc"
    break;

  case 170: /* path: relative_path  */
#line 1276 "gram.yy"
                {
		  (yyval.pth) = (yyvsp[0].pth);
		}
#line 3810 "gram.cc"
    break;

  case 171: /* path: '(' relative_path ',' relative_path ')'  */
#line 1280 "gram.yy"
                {
		  (yyval.pth) = (yyvsp[-3].pth);
		  (yyval.pth)->set_ypath((yyvsp[-1].pth));
		}
#line 3819 "gram.cc"
    break;

  case 172: /* path: ORDINAL LAST object_type relative_path  */
#line 1286 "gram.yy"
                {
		  lex_warning("`%1%2 last %3' in `with' argument ignored",
			      (yyvsp[-3].n), ordinal_postfix((yyvsp[-3].n)), object_type_name((yyvsp[-1].obtype)));
		  (yyval.pth) = (yyvsp[0].pth);
		}
#line 3829 "gram.cc"
    break;

  case 173: /* path: LAST object_type relative_path  */
#line 1292 "gram.yy"
                {
		  lex_warning("`last %1' in `with' argument ignored",
			      object_type_name((yyvsp[-1].obtype)));
		  (yyval.pth) = (yyvsp[0].pth);
		}
#line 3839 "gram.cc"
    break;

  case 174: /* path: ORDINAL object_type relative_path  */
#line 1298 "gram.yy"
                {
		  lex_warning("`%1%2 %3' in `with' argument ignored",
			      (yyvsp[-2].n), ordinal_postfix((yyvsp[-2].n)), object_type_name((yyvsp[-1].obtype)));
		  (yyval.pth) = (yyvsp[0].pth);
		}
#line 3849 "gram.cc"
    break;

  case 175: /* path: LABEL relative_path  */
#line 1304 "gram.yy"
                {
		  lex_warning("initial `%1' in `with' argument ignored", (yyvsp[-1].str));
		  a_delete (yyvsp[-1].str);
		  (yyval.pth) = (yyvsp[0].pth);
		}
#line 3859 "gram.cc"
    break;

  case 176: /* corner: DOT_N  */
#line 1313 "gram.yy"
                { (yyval.crn) = &object::north; }
#line 3865 "gram.cc"
    break;

  case 177: /* corner: DOT_E  */
#line 1315 "gram.yy"
                { (yyval.crn) = &object::east; }
#line 3871 "gram.cc"
    break;

  case 178: /* corner: DOT_W  */
#line 1317 "gram.yy"
                { (yyval.crn) = &object::west; }
#line 3877 "gram.cc"
    break;

  case 179: /* corner: DOT_S  */
#line 1319 "gram.yy"
                { (yyval.crn) = &object::south; }
#line 3883 "gram.cc"
    break;

  case 180: /* corner: DOT_NE  */
#line 1321 "gram.yy"
                { (yyval.crn) = &object::north_east; }
#line 3889 "gram.cc"
    break;

  case 181: /* corner: DOT_SE  */
#line 1323 "gram.yy"
                { (yyval.crn) = &object:: south_east; }
#line 3895 "gram.cc"
    break;

  case 182: /* corner: DOT_NW  */
#line 1325 "gram.yy"
                { (yyval.crn) = &object::north_west; }
#line 3901 "gram.cc"
    break;

  case 183: /* corner: DOT_SW  */
#line 1327 "gram.yy"
                { (yyval.crn) = &object::south_west; }
#line 3907 "gram.cc"
    break;

  case 184: /* corner: DOT_C  */
#line 1329 "gram.yy"
                { (yyval.crn) = &object::center; }
#line 3913 "gram.cc"
    break;

  case 185: /* corner: DOT_START  */
#line 1331 "gram.yy"
                { (yyval.crn) = &object::start; }
#line 3919 "gram.cc"
    break;

  case 186: /* corner: DOT_END  */
#line 1333 "gram.yy"
                { (yyval.crn) = &object::end; }
#line 3925 "gram.cc"
    break;

  case 187: /* corner: TOP  */
#line 1335 "gram.yy"
                { (yyval.crn) = &object::north; }
#line 3931 "gram.cc"
    break;

  case 188: /* corner: BOTTOM  */
#line 1337 "gram.yy"
                { (yyval.crn) = &object::south; }
#line 3937 "gram.cc"
    break;

  case 189: /* corner: LEFT  */
#line 1339 "gram.yy"
                { (yyval.crn) = &object::west; }
#line 3943 "gram.cc"
    break;

  case 190: /* corner: RIGHT  */
#line 1341 "gram.yy"
                { (yyval.crn) = &object::east; }
#line 3949 "gram.cc"
    break;

  case 191: /* corner: UPPER LEFT  */
#line 1343 "gram.yy"
                { (yyval.crn) = &object::north_west; }
#line 3955 "gram.cc"
    break;

  case 192: /* corner: LOWER LEFT  */
#line 1345 "gram.yy"
                { (yyval.crn) = &object::south_west; }
#line 3961 "gram.cc"
    break;

  case 193: /* corner: UPPER RIGHT  */
#line 1347 "gram.yy"
                { (yyval.crn) = &object::north_east; }
#line 3967 "gram.cc"
    break;

  case 194: /* corner: LOWER RIGHT  */
#line 1349 "gram.yy"
                { (yyval.crn) = &object::south_east; }
#line 3973 "gram.cc"
    break;

  case 195: /* corner: LEFT_CORNER  */
#line 1351 "gram.yy"
                { (yyval.crn) = &object::west; }
#line 3979 "gram.cc"
    break;

  case 196: /* corner: RIGHT_CORNER  */
#line 1353 "gram.yy"
                { (yyval.crn) = &object::east; }
#line 3985 "gram.cc"
    break;

  case 197: /* corner: UPPER LEFT_CORNER  */
#line 1355 "gram.yy"
                { (yyval.crn) = &object::north_west; }
#line 3991 "gram.cc"
    break;

  case 198: /* corner: LOWER LEFT_CORNER  */
#line 1357 "gram.yy"
                { (yyval.crn) = &object::south_west; }
#line 3997 "gram.cc"
    break;

  case 199: /* corner: UPPER RIGHT_CORNER  */
#line 1359 "gram.yy"
                { (yyval.crn) = &object::north_east; }
#line 4003 "gram.cc"
    break;

  case 200: /* corner: LOWER RIGHT_CORNER  */
#line 1361 "gram.yy"
                { (yyval.crn) = &object::south_east; }
#line 4009 "gram.cc"
    break;

  case 201: /* corner: CENTER  */
#line 1363 "gram.yy"
                { (yyval.crn) = &object::center; }
#line 4015 "gram.cc"
    break;

  case 202: /* corner: START  */
#line 1365 "gram.yy"
                { (yyval.crn) = &object::start; }
#line 4021 "gram.cc"
    break;

  case 203: /* corner: END  */
#line 1367 "gram.yy"
                { (yyval.crn) = &object::end; }
#line 4027 "gram.cc"
    break;

  case 204: /* expr: VARIABLE  */
#line 1372 "gram.yy"
                {
		  if (!lookup_variable((yyvsp[0].str), & (yyval.x))) 
		    {
		      lex_error("there is no variable `%1'", (yyvsp[0].str));
		      YYABORT;
		    }
		  a_delete (yyvsp[0].str);
		}
#line 4040 "gram.cc"
    break;

  case 205: /* expr: NUMBER  */
#line 1381 "gram.yy"
                { (yyval.x) = (yyvsp[0].x); }
#line 4046 "gram.cc"
    break;

  case 206: /* expr: place DOT_X  */
#line 1383 "gram.yy"
                {
		  if ((yyvsp[-1].pl).obj != 0)
		    (yyval.x) = (yyvsp[-1].pl).obj->origin().x;
		  else
		    (yyval.x) = (yyvsp[-1].pl).x;
		}
#line 4057 "gram.cc"
    break;

  case 207: /* expr: place DOT_Y  */
#line 1390 "gram.yy"
                {
		  if ((yyvsp[-1].pl).obj != 0)
		    (yyval.x) = (yyvsp[-1].pl).obj->origin().y;
		  else
		    (yyval.x) = (yyvsp[-1].pl).y;
		}
#line 4068 "gram.cc"
    break;

  case 208: /* expr: place DOT_HT  */
#line 1397 "gram.yy"
                {
		  if ((yyvsp[-1].pl).obj != 0)
		    (yyval.x) = (yyvsp[-1].pl).obj->height();
		  else
		    (yyval.x) = 0.0;
		}
#line 4079 "gram.cc"
    break;

  case 209: /* expr: place DOT_WID  */
#line 1404 "gram.yy"
                {
		  if ((yyvsp[-1].pl).obj != 0)
		    (yyval.x) = (yyvsp[-1].pl).obj->width();
		  else
		    (yyval.x) = 0.0;
		}
#line 4090 "gram.cc"
    break;

  case 210: /* expr: place DOT_RAD  */
#line 1411 "gram.yy"
                {
		  if ((yyvsp[-1].pl).obj != 0)
		    (yyval.x) = (yyvsp[-1].pl).obj->radius();
		  else
		    (yyval.x) = 0.0;
		}
#line 4101 "gram.cc"
    break;

  case 211: /* expr: expr '+' expr  */
#line 1418 "gram.yy"
                { (yyval.x) = (yyvsp[-2].x) + (yyvsp[0].x); }
#line 4107 "gram.cc"
    break;

  case 212: /* expr: expr '-' expr  */
#line 1420 "gram.yy"
                { (yyval.x) = (yyvsp[-2].x) - (yyvsp[0].x); }
#line 4113 "gram.cc"
    break;

  case 213: /* expr: expr '*' expr  */
#line 1422 "gram.yy"
                { (yyval.x) = (yyvsp[-2].x) * (yyvsp[0].x); }
#line 4119 "gram.cc"
    break;

  case 214: /* expr: expr '/' expr  */
#line 1424 "gram.yy"
                {
		  if ((yyvsp[0].x) == 0.0) 
		    {
		      lex_error("division by zero");
		      YYABORT;
		    }
		  (yyval.x) = (yyvsp[-2].x)/(yyvsp[0].x);
		}
#line 4132 "gram.cc"
    break;

  case 215: /* expr: expr '%' expr  */
#line 1433 "gram.yy"
                {
		  if ((yyvsp[0].x) == 0.0) 
		    {
		      lex_error("modulus by zero");
		      YYABORT;
		    }
		  (yyval.x) = fmod((yyvsp[-2].x), (yyvsp[0].x));
		}
#line 4145 "gram.cc"
    break;

  case 216: /* expr: expr '^' expr  */
#line 1442 "gram.yy"
                {
		  errno = 0;
		  (yyval.x) = pow((yyvsp[-2].x), (yyvsp[0].x));
		  if (errno == EDOM) 
		    {
		      lex_error("arguments to `^' operator out of domain");
		      YYABORT;
		    }
		  if (errno == ERANGE) 
		    {
		      lex_error("result of `^' operator out of range");
		      YYABORT;
		  }
		}
#line 4164 "gram.cc"
    break;

  case 217: /* expr: '-' expr  */
#line 1457 "gram.yy"
                { (yyval.x) = -(yyvsp[0].x); }
#line 4170 "gram.cc"
    break;

  case 218: /* expr: '(' any_expr ')'  */
#line 1459 "gram.yy"
                { (yyval.x) = (yyvsp[-1].x); }
#line 4176 "gram.cc"
    break;

  case 219: /* expr: SIN '(' any_expr ')'  */
#line 1461 "gram.yy"
                {
		  errno = 0;
		  (yyval.x) = sin((yyvsp[-1].x));
		  if (errno == ERANGE) 
		    {
		      lex_error("sin result out of range");
		      YYABORT;
		    }
		}
#line 4190 "gram.cc"
    break;

  case 220: /* expr: COS '(' any_expr ')'  */
#line 1471 "gram.yy"
                {
		  errno = 0;
		  (yyval.x) = cos((yyvsp[-1].x));
		  if (errno == ERANGE) 
		    {
		      lex_error("cos result out of range");
		      YYABORT;
		    }
		}
#line 4204 "gram.cc"
    break;

  case 221: /* expr: ATAN2 '(' any_expr ',' any_expr ')'  */
#line 1481 "gram.yy"
                {
		  errno = 0;
		  (yyval.x) = atan2((yyvsp[-3].x), (yyvsp[-1].x));
		  if (errno == EDOM) 
		    {
		      lex_error("atan2 argument out of domain");
		      YYABORT;
		    }
		  if (errno == ERANGE)
		    {
		      lex_error("atan2 result out of range");
		      YYABORT;
		  }
		}
#line 4223 "gram.cc"
    break;

  case 222: /* expr: LOG '(' any_expr ')'  */
#line 1496 "gram.yy"
                {
		  errno = 0;
		  (yyval.x) = log10((yyvsp[-1].x));
		  if (errno == ERANGE) 
		    {
		      lex_error("log result out of range");
		      YYABORT;
		    }
		}
#line 4237 "gram.cc"
    break;

  case 223: /* expr: EXP '(' any_expr ')'  */
#line 1506 "gram.yy"
                {
		  errno = 0;
		  (yyval.x) = pow(10.0, (yyvsp[-1].x));
		  if (errno == ERANGE) 
		    {
		      lex_error("exp result out of range");
		      YYABORT;
		    }
		}
#line 4251 "gram.cc"
    break;

  case 224: /* expr: SQRT '(' any_expr ')'  */
#line 1516 "gram.yy"
                {
		  errno = 0;
		  (yyval.x) = sqrt((yyvsp[-1].x));
		  if (errno == EDOM) 
		    {
		      lex_error("sqrt argument out of domain");
		      YYABORT;
		    }
		}
#line 4265 "gram.cc"
    break;

  case 225: /* expr: K_MAX '(' any_expr ',' any_expr ')'  */
#line 1526 "gram.yy"
                { (yyval.x) = (yyvsp[-3].x) > (yyvsp[-1].x) ? (yyvsp[-3].x) : (yyvsp[-1].x); }
#line 4271 "gram.cc"
    break;

  case 226: /* expr: K_MIN '(' any_expr ',' any_expr ')'  */
#line 1528 "gram.yy"
                { (yyval.x) = (yyvsp[-3].x) < (yyvsp[-1].x) ? (yyvsp[-3].x) : (yyvsp[-1].x); }
#line 4277 "gram.cc"
    break;

  case 227: /* expr: INT '(' any_expr ')'  */
#line 1530 "gram.yy"
                { (yyval.x) = floor((yyvsp[-1].x)); }
#line 4283 "gram.cc"
    break;

  case 228: /* expr: RAND '(' any_expr ')'  */
#line 1532 "gram.yy"
                { (yyval.x) = 1.0 + floor(((rand()&0x7fff)/double(0x7fff))*(yyvsp[-1].x)); }
#line 4289 "gram.cc"
    break;

  case 229: /* expr: RAND '(' ')'  */
#line 1534 "gram.yy"
                {
		  // return a random number in the range [0,1)
		  // portable, but not very random
		  (yyval.x) = (rand() & 0x7fff) / double(0x8000);
		}
#line 4299 "gram.cc"
    break;

  case 230: /* expr: SRAND '(' any_expr ')'  */
#line 1540 "gram.yy"
                { (yyval.x) = 0; srand((unsigned int)(yyvsp[-1].x)); }
#line 4305 "gram.cc"
    break;

  case 231: /* expr: expr '<' expr  */
#line 1542 "gram.yy"
                { (yyval.x) = ((yyvsp[-2].x) < (yyvsp[0].x)); }
#line 4311 "gram.cc"
    break;

  case 232: /* expr: expr LESSEQUAL expr  */
#line 1544 "gram.yy"
                { (yyval.x) = ((yyvsp[-2].x) <= (yyvsp[0].x)); }
#line 4317 "gram.cc"
    break;

  case 233: /* expr: expr '>' expr  */
#line 1546 "gram.yy"
                { (yyval.x) = ((yyvsp[-2].x) > (yyvsp[0].x)); }
#line 4323 "gram.cc"
    break;

  case 234: /* expr: expr GREATEREQUAL expr  */
#line 1548 "gram.yy"
                { (yyval.x) = ((yyvsp[-2].x) >= (yyvsp[0].x)); }
#line 4329 "gram.cc"
    break;

  case 235: /* expr: expr EQUALEQUAL expr  */
#line 1550 "gram.yy"
                { (yyval.x) = ((yyvsp[-2].x) == (yyvsp[0].x)); }
#line 4335 "gram.cc"
    break;

  case 236: /* expr: expr NOTEQUAL expr  */
#line 1552 "gram.yy"
                { (yyval.x) = ((yyvsp[-2].x) != (yyvsp[0].x)); }
#line 4341 "gram.cc"
    break;

  case 237: /* expr: expr ANDAND expr  */
#line 1554 "gram.yy"
                { (yyval.x) = ((yyvsp[-2].x) != 0.0 && (yyvsp[0].x) != 0.0); }
#line 4347 "gram.cc"
    break;

  case 238: /* expr: expr OROR expr  */
#line 1556 "gram.yy"
                { (yyval.x) = ((yyvsp[-2].x) != 0.0 || (yyvsp[0].x) != 0.0); }
#line 4353 "gram.cc"
    break;

  case 239: /* expr: '!' expr  */
#line 1558 "gram.yy"
                { (yyval.x) = ((yyvsp[0].x) == 0.0); }
#line 4359 "gram.cc"
    break;


#line 4363 "gram.cc"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 1562 "gram.yy"


// bison defines const to be empty unless __STDC__ is defined, which it
// isn't under cfront

#ifdef const
#undef const
#endif

static struct 
{
  const char *name;
  double val;
  int scaled;		     // non-zero if val should be multiplied by scale
} defaults_table[] = {
  { "arcrad", .25, 1 },
  { "arrowht", .1, 1 },
  { "arrowwid", .05, 1 },
  { "circlerad", .25, 1 },
  { "boxht", .5, 1 },
  { "boxwid", .75, 1 },
  { "boxrad", 0.0, 1 },
  { "dashwid", .05, 1 },
  { "ellipseht", .5, 1 },
  { "ellipsewid", .75, 1 },
  { "moveht", .5, 1 },
  { "movewid", .5, 1 },
  { "lineht", .5, 1 },
  { "linewid", .5, 1 },
  { "textht", 0.0, 1 },
  { "textwid", 0.0, 1 },
  { "scale", 1.0, 0 },
  { "linethick", -1.0, 1 },	// in points (<0 is default); now scaled
  { "fillval", .5, 0 },
  { "arrowhead", 1.0, 0 },
  { "maxpswid", 8.5, 0 },
  { "maxpsht", 11.0, 0 },
};

static place *
lookup_label(const char *label)
{
  saved_state *state = current_saved_state;
  PTABLE(place) *tbl = current_table;
  for (;;) 
    {
      place *pl = tbl->lookup(label);
      if (pl)
	return pl;
      if (!state)
	return 0;
      tbl = state->tbl;
      state = state->prev;
    }
}

static void 
define_label(const char *label, const place *pl)
{
  place *p = new place;
  *p = *pl;
  current_table->define(label, p);
}

int
lookup_variable(const char *name, double *val)
{
  place *pl = lookup_label(name);
  if (pl) 
    {
      *val = pl->x;
      return 1;
    }
  return 0;
}

void 
define_variable(const char *name, double val)
{
  place *p = new place;
  p->obj = 0;
  p->x = val;
  p->y = 0.0;
  current_table->define(name, p);
  if (strcmp(name, "scale") == 0) 
    {
      // When the scale changes, reset all scaled pre-defined variables to
      // their default values.
      for (unsigned int i = 0; i < sizeof(defaults_table)/sizeof(defaults_table[0]); i++) 
	if (defaults_table[i].scaled)
	  define_variable(defaults_table[i].name, val*defaults_table[i].val);
    }
}

// called once only (not once per parse)

void 
parse_init (void)
{
  current_direction = RIGHT_DIRECTION;
  current_position.x = 0.0;
  current_position.y = 0.0;
  // This resets everything to its default value.
  reset_all();
}

static void 
reset (const char *nm)
{
  for (unsigned int i = 0; i < sizeof(defaults_table)/sizeof(defaults_table[0]); i++)
    if (strcmp(nm, defaults_table[i].name) == 0) 
      {
	double val = defaults_table[i].val;
	if (defaults_table[i].scaled) 
	  {
	    double scale;
	    lookup_variable("scale", &scale);
	    val *= scale;
	  }
	define_variable(defaults_table[i].name, val);
	return;
      }
  lex_error("`%1' is not a predefined variable", nm);
}

static void
reset_all (void)
{
  // We only have to explicitly reset the pre-defined variables that
  // aren't scaled because `scale' is not scaled, and changing the
  // value of `scale' will reset all the pre-defined variables that
  // are scaled.
  for (unsigned int i = 0; i < sizeof(defaults_table)/sizeof(defaults_table[0]); i++)
    if (!defaults_table[i].scaled)
      define_variable(defaults_table[i].name, defaults_table[i].val);
}

// called after each parse

void
parse_cleanup (void)
{
  while (current_saved_state != 0) 
    {
      delete current_table;
      current_table = current_saved_state->tbl;
      saved_state *tem = current_saved_state;
      current_saved_state = current_saved_state->prev;
      delete tem;
    }
  assert(current_table == &top_table);
  PTABLE_ITERATOR(place) iter(current_table);
  const char *key;
  place *pl;
  while (iter.next(&key, &pl))
    if (pl->obj != 0) 
      {
	position pos = pl->obj->origin();
	pl->obj = 0;
	pl->x = pos.x;
	pl->y = pos.y;
      }
  while (olist.head != 0) 
    {
      object *tem = olist.head;
      olist.head = olist.head->next;
      delete tem;
    }
  olist.tail = 0;
  current_direction = RIGHT_DIRECTION;
  current_position.x = 0.0;
  current_position.y = 0.0;
}

static const char *
ordinal_postfix(int n)
{
  if (n < 10 || n > 20)
    switch (n % 10) 
      {
      case 1:
	return "st";
      case 2:
	return "nd";
      case 3:
	return "rd";
      }
  return "th";
}

static const char *
object_type_name(object_type type)
{
  switch (type) 
    {
    case BOX_OBJECT:
      return "box";
    case CIRCLE_OBJECT:
      return "circle";
    case ELLIPSE_OBJECT:
      return "ellipse";
    case ARC_OBJECT:
      return "arc";
    case SPLINE_OBJECT:
      return "spline";
    case LINE_OBJECT:
      return "line";
    case ARROW_OBJECT:
      return "arrow";
    case MOVE_OBJECT:
      return "move";
    case TEXT_OBJECT:
      return "\"\"";
    case BLOCK_OBJECT:
      return "[]";
    case OTHER_OBJECT:
    case MARK_OBJECT:
    default:
      break;
    }
  return "object";
}

static char *
format_number(const char *form, double n)
{
  if (form == 0)
    form = "%g";
  else 
    {
      // this is a fairly feeble attempt at validation of the format
      int nspecs = 0;
      for (const char *p = form; *p != '\0'; p++)
	if (*p == '%') 
	  {
	    if (p[1] == '%')
	      p++;
	    else
	      nspecs++;
	  }
      if (nspecs > 1) 
	{
	  lex_error("bad format `%1'", form);
	  return strsave(form);
	}
    }
  sprintf(sprintf_buf, form, n);
  return strsave(sprintf_buf);
}

static char *
do_sprintf(const char *form, const double *v, int nv)
{
  string result;
  int i = 0;
  string one_format;
  while (*form) 
    {
      if (*form == '%') 
	{
	  one_format += *form++;
	  for (; *form != '\0' && strchr("#-+ 0123456789.", *form) != 0; form++)
	    one_format += *form;
	  if (*form == '\0' || strchr("eEfgG%", *form) == 0) 
	    {
	      lex_error("bad sprintf format");
	      result += one_format;
	      result += form;
	      break;
	    }
	  if (*form == '%') 
	    {
	      one_format += *form++;
	      one_format += '\0';
	      sprintf(sprintf_buf, one_format.contents());
	    }
	  else 
	    {
	      if (i >= nv) 
		{
		  lex_error("too few arguments to sprintf");
		  result += one_format;
		  result += form;
		  break;
		}
	      one_format += *form++;
	      one_format += '\0';
	      sprintf(sprintf_buf, one_format.contents(), v[i++]);
	    }
	  one_format.clear();
	  result += sprintf_buf;
	}
      else
	result += *form++;
    }
  result += '\0';
  return strsave(result.contents());
}
