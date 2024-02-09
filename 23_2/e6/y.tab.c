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
#line 1 "parser.y"

	#include "hash.h"
	#include "ast.h"
	#include "semantic.h"
	#include "tac.h"
	#include "asm.h"
	#include <stdlib.h>

	int yylex();
	int yyerror();
	int getLineNumber();
	extern int verifySemantic();
	extern int SemanticErrors;

	AST* root;

	tac* programTacs;

void makeRoot(AST* node)
{
	tac* newTac = createTacs(node, 0);//tacCodeGenerate(node);
	tac* tacRev = rewindTac(newTac);
	programTacs = tacRev;
	//printAllTacs(tacRev);
	//printTac(newTac);
}


#line 100 "y.tab.c"

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
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    KW_CHAR = 258,                 /* KW_CHAR  */
    KW_INT = 259,                  /* KW_INT  */
    KW_FLOAT = 260,                /* KW_FLOAT  */
    KW_CODE = 261,                 /* KW_CODE  */
    KW_IF = 262,                   /* KW_IF  */
    KW_ELSE = 263,                 /* KW_ELSE  */
    KW_WHILE = 264,                /* KW_WHILE  */
    KW_INPUT = 265,                /* KW_INPUT  */
    KW_PRINT = 266,                /* KW_PRINT  */
    KW_RETURN = 267,               /* KW_RETURN  */
    OPERATOR_LE = 268,             /* OPERATOR_LE  */
    OPERATOR_GE = 269,             /* OPERATOR_GE  */
    OPERATOR_EQ = 270,             /* OPERATOR_EQ  */
    OPERATOR_DIF = 271,            /* OPERATOR_DIF  */
    TK_IDENTIFIER = 272,           /* TK_IDENTIFIER  */
    LIT_INT = 273,                 /* LIT_INT  */
    LIT_REAL = 274,                /* LIT_REAL  */
    LIT_CHAR = 275,                /* LIT_CHAR  */
    LIT_STRING = 276,              /* LIT_STRING  */
    TOKEN_ERROR = 277              /* TOKEN_ERROR  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define KW_CHAR 258
#define KW_INT 259
#define KW_FLOAT 260
#define KW_CODE 261
#define KW_IF 262
#define KW_ELSE 263
#define KW_WHILE 264
#define KW_INPUT 265
#define KW_PRINT 266
#define KW_RETURN 267
#define OPERATOR_LE 268
#define OPERATOR_GE 269
#define OPERATOR_EQ 270
#define OPERATOR_DIF 271
#define TK_IDENTIFIER 272
#define LIT_INT 273
#define LIT_REAL 274
#define LIT_CHAR 275
#define LIT_STRING 276
#define TOKEN_ERROR 277

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 31 "parser.y"

	HASH_NODE *symbol;
	AST *ast;

#line 202 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_KW_CHAR = 3,                    /* KW_CHAR  */
  YYSYMBOL_KW_INT = 4,                     /* KW_INT  */
  YYSYMBOL_KW_FLOAT = 5,                   /* KW_FLOAT  */
  YYSYMBOL_KW_CODE = 6,                    /* KW_CODE  */
  YYSYMBOL_KW_IF = 7,                      /* KW_IF  */
  YYSYMBOL_KW_ELSE = 8,                    /* KW_ELSE  */
  YYSYMBOL_KW_WHILE = 9,                   /* KW_WHILE  */
  YYSYMBOL_KW_INPUT = 10,                  /* KW_INPUT  */
  YYSYMBOL_KW_PRINT = 11,                  /* KW_PRINT  */
  YYSYMBOL_KW_RETURN = 12,                 /* KW_RETURN  */
  YYSYMBOL_OPERATOR_LE = 13,               /* OPERATOR_LE  */
  YYSYMBOL_OPERATOR_GE = 14,               /* OPERATOR_GE  */
  YYSYMBOL_OPERATOR_EQ = 15,               /* OPERATOR_EQ  */
  YYSYMBOL_OPERATOR_DIF = 16,              /* OPERATOR_DIF  */
  YYSYMBOL_TK_IDENTIFIER = 17,             /* TK_IDENTIFIER  */
  YYSYMBOL_LIT_INT = 18,                   /* LIT_INT  */
  YYSYMBOL_LIT_REAL = 19,                  /* LIT_REAL  */
  YYSYMBOL_LIT_CHAR = 20,                  /* LIT_CHAR  */
  YYSYMBOL_LIT_STRING = 21,                /* LIT_STRING  */
  YYSYMBOL_TOKEN_ERROR = 22,               /* TOKEN_ERROR  */
  YYSYMBOL_23_ = 23,                       /* '('  */
  YYSYMBOL_24_ = 24,                       /* ')'  */
  YYSYMBOL_25_ = 25,                       /* '['  */
  YYSYMBOL_26_ = 26,                       /* ']'  */
  YYSYMBOL_27_ = 27,                       /* '{'  */
  YYSYMBOL_28_ = 28,                       /* '}'  */
  YYSYMBOL_29_ = 29,                       /* '&'  */
  YYSYMBOL_30_ = 30,                       /* '|'  */
  YYSYMBOL_31_ = 31,                       /* '~'  */
  YYSYMBOL_32_ = 32,                       /* '<'  */
  YYSYMBOL_33_ = 33,                       /* '>'  */
  YYSYMBOL_34_ = 34,                       /* '='  */
  YYSYMBOL_35_ = 35,                       /* '+'  */
  YYSYMBOL_36_ = 36,                       /* '-'  */
  YYSYMBOL_37_ = 37,                       /* '*'  */
  YYSYMBOL_38_ = 38,                       /* '/'  */
  YYSYMBOL_39_ = 39,                       /* ';'  */
  YYSYMBOL_40_ = 40,                       /* ','  */
  YYSYMBOL_YYACCEPT = 41,                  /* $accept  */
  YYSYMBOL_program = 42,                   /* program  */
  YYSYMBOL_decGen = 43,                    /* decGen  */
  YYSYMBOL_dec = 44,                       /* dec  */
  YYSYMBOL_param = 45,                     /* param  */
  YYSYMBOL_codeGen = 46,                   /* codeGen  */
  YYSYMBOL_cmd = 47,                       /* cmd  */
  YYSYMBOL_cmdStart = 48,                  /* cmdStart  */
  YYSYMBOL_block = 49,                     /* block  */
  YYSYMBOL_cmdList = 50,                   /* cmdList  */
  YYSYMBOL_atrb = 51,                      /* atrb  */
  YYSYMBOL_print = 52,                     /* print  */
  YYSYMBOL_return = 53,                    /* return  */
  YYSYMBOL_flowCmd = 54,                   /* flowCmd  */
  YYSYMBOL_exp = 55,                       /* exp  */
  YYSYMBOL_args = 56,                      /* args  */
  YYSYMBOL_vector = 57,                    /* vector  */
  YYSYMBOL_type = 58,                      /* type  */
  YYSYMBOL_value = 59,                     /* value  */
  YYSYMBOL_id = 60,                        /* id  */
  YYSYMBOL_veccall = 61,                   /* veccall  */
  YYSYMBOL_string = 62,                    /* string  */
  YYSYMBOL_int = 63                        /* int  */
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
typedef yytype_int8 yy_state_t;

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
#define YYFINAL  12
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   274

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  23
/* YYNRULES -- Number of rules.  */
#define YYNRULES  66
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  124

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   277


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    29,     2,
      23,    24,    37,    35,    40,    36,     2,    38,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    39,
      32,    34,    33,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    25,     2,    26,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    27,    30,    28,    31,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,   107,   107,   110,   111,   112,   115,   116,   117,   120,
     121,   122,   125,   126,   129,   130,   131,   132,   133,   134,
     137,   140,   143,   144,   147,   148,   151,   152,   155,   158,
     159,   160,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   186,   187,   190,   191,   194,   195,   196,
     199,   200,   201,   204,   207,   210,   213
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
  "\"end of file\"", "error", "\"invalid token\"", "KW_CHAR", "KW_INT",
  "KW_FLOAT", "KW_CODE", "KW_IF", "KW_ELSE", "KW_WHILE", "KW_INPUT",
  "KW_PRINT", "KW_RETURN", "OPERATOR_LE", "OPERATOR_GE", "OPERATOR_EQ",
  "OPERATOR_DIF", "TK_IDENTIFIER", "LIT_INT", "LIT_REAL", "LIT_CHAR",
  "LIT_STRING", "TOKEN_ERROR", "'('", "')'", "'['", "']'", "'{'", "'}'",
  "'&'", "'|'", "'~'", "'<'", "'>'", "'='", "'+'", "'-'", "'*'", "'/'",
  "';'", "','", "$accept", "program", "decGen", "dec", "param", "codeGen",
  "cmd", "cmdStart", "block", "cmdList", "atrb", "print", "return",
  "flowCmd", "exp", "args", "vector", "type", "value", "id", "veccall",
  "string", "int", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-75)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-64)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      48,   -75,   -75,   -75,   -15,    13,   -75,   -18,   -75,   -15,
     -75,     5,   -75,    48,     0,     7,     8,   228,   243,     5,
     -75,   -75,    31,   -75,    -1,     3,     4,   -75,    -5,     6,
     -75,    57,    28,    67,   243,   243,    40,   -17,   -75,   -75,
     -75,   -75,   243,   243,   195,     1,   -75,   -75,   195,     5,
      62,   -75,   -75,   -75,   -75,   243,   243,   243,    70,   -15,
     -75,    65,   -75,   -75,   -75,   -75,    91,   117,    57,   143,
     155,   243,   243,   243,   243,   243,   243,   243,   243,   243,
     243,   243,   243,   243,   -75,   -75,   169,   195,   195,   -75,
      68,    67,     5,     5,    73,   -75,    21,    21,    21,    21,
     155,   155,   199,   199,    43,    43,   -75,   -75,    63,    78,
     -75,    57,   -75,    67,   101,   -75,   -75,   243,   -75,   -75,
     -75,     5,   -75,   -75
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       5,    57,    58,    59,     0,     0,     2,     0,     4,     0,
      63,     0,     1,     5,     0,     0,     0,     0,     0,    23,
      19,    20,    13,    14,     0,     0,     0,    15,     0,     0,
       3,    11,     0,     0,     0,     0,     0,    48,    50,    52,
      51,    65,     0,     0,    27,     0,    49,    26,    28,    23,
       0,    12,    16,    17,    18,     0,     0,     0,     0,     0,
      66,     0,    60,    61,    62,     6,     0,     0,     0,     0,
      45,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    22,    21,     0,    24,    25,     8,
      10,    56,     0,     0,     0,    32,    39,    40,    41,    42,
      43,    44,    37,    38,    33,    34,    35,    36,    54,     0,
      64,    11,     7,    56,    29,    31,    47,     0,    46,     9,
      55,     0,    53,    30
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -75,   -75,    97,   -75,     2,    90,   -16,   -74,   -75,    69,
     -75,   -75,   -75,   -75,    -7,    -3,     9,   -27,    83,    -4,
     -10,   -75,   -75
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     5,     6,     7,    58,     8,    21,    22,    23,    50,
      24,    25,    26,    27,   108,   109,   112,     9,   113,    45,
      46,    47,    61
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      11,    29,    10,    49,    59,    14,   -63,    28,   -63,    29,
      44,    48,    15,    12,    16,    28,    17,    18,   114,   115,
      55,    13,    10,    31,    83,    32,    55,    66,    67,    56,
      34,    35,    19,    49,    33,    69,    70,     4,    52,    29,
      57,    94,    53,    54,    20,    28,    60,   123,    86,    87,
      88,     1,     2,     3,     4,    90,    79,    80,    81,    82,
       1,     2,     3,    68,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,    71,    72,    73,    74,
      81,    82,    29,    29,    59,    62,    63,    64,    28,    28,
      85,    91,    75,    76,    89,    77,    78,   116,    79,    80,
      81,    82,   118,   117,    71,    72,    73,    74,   111,   121,
      30,    29,    51,   119,   122,    92,    65,    28,    84,     0,
      75,    76,   120,    77,    78,     0,    79,    80,    81,    82,
      71,    72,    73,    74,     0,     0,     0,     0,     0,     0,
       0,    93,     0,     0,     0,     0,    75,    76,     0,    77,
      78,     0,    79,    80,    81,    82,    71,    72,    73,    74,
       0,     0,     0,     0,     0,     0,     0,    95,    71,    72,
      73,    74,    75,    76,     0,    77,    78,     0,    79,    80,
      81,    82,    71,    72,    73,    74,     0,    77,    78,     0,
      79,    80,    81,    82,     0,   110,     0,     0,    75,    76,
       0,    77,    78,     0,    79,    80,    81,    82,    71,    72,
      73,    74,    71,    72,    73,    74,     0,     0,     0,     0,
       0,     0,     0,     0,    75,    76,     0,    77,    78,     0,
      79,    80,    81,    82,    79,    80,    81,    82,    36,     0,
       0,     0,     0,     0,     0,    37,    38,    39,    40,    41,
       0,    42,     0,    36,     0,     0,     0,     0,     0,    43,
      37,    38,    39,    40,     0,     0,    42,     0,     0,     0,
       0,     0,     0,     0,    43
};

static const yytype_int8 yycheck[] =
{
       4,    11,    17,    19,    31,     9,    23,    11,    25,    19,
      17,    18,     7,     0,     9,    19,    11,    12,    92,    93,
      25,    39,    17,    23,    23,    25,    25,    34,    35,    34,
      23,    23,    27,    49,    34,    42,    43,     6,    39,    49,
      34,    68,    39,    39,    39,    49,    18,   121,    55,    56,
      57,     3,     4,     5,     6,    59,    35,    36,    37,    38,
       3,     4,     5,    23,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    13,    14,    15,    16,
      37,    38,    92,    93,   111,    18,    19,    20,    92,    93,
      28,    26,    29,    30,    24,    32,    33,    24,    35,    36,
      37,    38,    24,    40,    13,    14,    15,    16,    40,     8,
      13,   121,    22,   111,   117,    24,    33,   121,    49,    -1,
      29,    30,   113,    32,    33,    -1,    35,    36,    37,    38,
      13,    14,    15,    16,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    24,    -1,    -1,    -1,    -1,    29,    30,    -1,    32,
      33,    -1,    35,    36,    37,    38,    13,    14,    15,    16,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    24,    13,    14,
      15,    16,    29,    30,    -1,    32,    33,    -1,    35,    36,
      37,    38,    13,    14,    15,    16,    -1,    32,    33,    -1,
      35,    36,    37,    38,    -1,    26,    -1,    -1,    29,    30,
      -1,    32,    33,    -1,    35,    36,    37,    38,    13,    14,
      15,    16,    13,    14,    15,    16,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    29,    30,    -1,    32,    33,    -1,
      35,    36,    37,    38,    35,    36,    37,    38,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    17,    18,    19,    20,    21,
      -1,    23,    -1,    10,    -1,    -1,    -1,    -1,    -1,    31,
      17,    18,    19,    20,    -1,    -1,    23,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    31
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     6,    42,    43,    44,    46,    58,
      17,    60,     0,    39,    60,     7,     9,    11,    12,    27,
      39,    47,    48,    49,    51,    52,    53,    54,    60,    61,
      43,    23,    25,    34,    23,    23,    10,    17,    18,    19,
      20,    21,    23,    31,    55,    60,    61,    62,    55,    47,
      50,    46,    39,    39,    39,    25,    34,    34,    45,    58,
      18,    63,    18,    19,    20,    59,    55,    55,    23,    55,
      55,    13,    14,    15,    16,    29,    30,    32,    33,    35,
      36,    37,    38,    23,    50,    28,    55,    55,    55,    24,
      60,    26,    24,    24,    58,    24,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    56,
      26,    40,    57,    59,    48,    48,    24,    40,    24,    45,
      57,     8,    56,    48
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    41,    42,    43,    43,    43,    44,    44,    44,    45,
      45,    45,    46,    46,    47,    47,    47,    47,    47,    47,
      48,    49,    50,    50,    51,    51,    52,    52,    53,    54,
      54,    54,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    56,    56,    57,    57,    58,    58,    58,
      59,    59,    59,    60,    61,    62,    63
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     3,     1,     0,     4,     6,     5,     4,
       2,     0,     4,     3,     1,     1,     2,     2,     2,     1,
       1,     3,     2,     0,     3,     3,     2,     2,     2,     5,
       7,     5,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     2,     4,     4,     1,     1,
       1,     1,     1,     3,     1,     2,     0,     1,     1,     1,
       1,     1,     1,     1,     4,     1,     1
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
  case 2: /* program: decGen  */
#line 107 "parser.y"
                                                                        { root = (yyval.ast); astPrint((yyvsp[0].ast), 0); SemanticErrors = verifySemantic((yyvsp[0].ast)); makeRoot((yyvsp[0].ast));}
#line 1352 "y.tab.c"
    break;

  case 3: /* decGen: dec ';' decGen  */
#line 110 "parser.y"
                                                                { (yyval.ast) = astCreate(AST_DEC, 0, (yyvsp[-2].ast), (yyvsp[0].ast), 0, 0, getLineNumber()); }
#line 1358 "y.tab.c"
    break;

  case 4: /* decGen: codeGen  */
#line 111 "parser.y"
                                                                                { (yyval.ast) = (yyvsp[0].ast); }
#line 1364 "y.tab.c"
    break;

  case 5: /* decGen: %empty  */
#line 112 "parser.y"
                                                                                        { (yyval.ast) = 0; }
#line 1370 "y.tab.c"
    break;

  case 6: /* dec: type id '=' value  */
#line 115 "parser.y"
                                                                { (yyval.ast) = astCreate(AST_IDDEC, 0, (yyvsp[-3].ast), (yyvsp[-2].ast), (yyvsp[0].ast), 0, getLineNumber());}
#line 1376 "y.tab.c"
    break;

  case 7: /* dec: type id '[' int ']' vector  */
#line 116 "parser.y"
                                                                { (yyval.ast) = astCreate(AST_VECDEC, 0, (yyvsp[-5].ast), (yyvsp[-4].ast), (yyvsp[-2].ast), (yyvsp[0].ast), getLineNumber());}
#line 1382 "y.tab.c"
    break;

  case 8: /* dec: type id '(' param ')'  */
#line 117 "parser.y"
                                                                        { (yyval.ast) = astCreate(AST_FOODEC, 0, (yyvsp[-4].ast), (yyvsp[-3].ast), (yyvsp[-1].ast), 0, getLineNumber());}
#line 1388 "y.tab.c"
    break;

  case 9: /* param: type id ',' param  */
#line 120 "parser.y"
                                                                { (yyval.ast) = astCreate(AST_PARAM, 0, (yyvsp[-3].ast), (yyvsp[-2].ast), (yyvsp[0].ast), 0, getLineNumber());}
#line 1394 "y.tab.c"
    break;

  case 10: /* param: type id  */
#line 121 "parser.y"
                                                                                { (yyval.ast) = astCreate(AST_PARAM, 0, (yyvsp[-1].ast), (yyvsp[0].ast), 0, 0, getLineNumber());}
#line 1400 "y.tab.c"
    break;

  case 11: /* param: %empty  */
#line 122 "parser.y"
                                                                                        { (yyval.ast) = 0; }
#line 1406 "y.tab.c"
    break;

  case 12: /* codeGen: KW_CODE id cmdStart codeGen  */
#line 125 "parser.y"
                                                                                        { (yyval.ast) = astCreate(AST_CODE, 0, (yyvsp[-2].ast), (yyvsp[-1].ast), (yyvsp[0].ast), 0, getLineNumber()); }
#line 1412 "y.tab.c"
    break;

  case 13: /* codeGen: KW_CODE id cmdStart  */
#line 126 "parser.y"
                                                                                                        { (yyval.ast) = astCreate(AST_CODE, 0, (yyvsp[-1].ast), (yyvsp[0].ast), 0, 0, getLineNumber()); }
#line 1418 "y.tab.c"
    break;

  case 14: /* cmd: block  */
#line 129 "parser.y"
                                                                                { (yyval.ast) = (yyvsp[0].ast); }
#line 1424 "y.tab.c"
    break;

  case 15: /* cmd: flowCmd  */
#line 130 "parser.y"
                                                                                        { (yyval.ast) = (yyvsp[0].ast); }
#line 1430 "y.tab.c"
    break;

  case 16: /* cmd: atrb ';'  */
#line 131 "parser.y"
                                                                                        { (yyval.ast) = (yyvsp[-1].ast); }
#line 1436 "y.tab.c"
    break;

  case 17: /* cmd: print ';'  */
#line 132 "parser.y"
                                                                                        { (yyval.ast) = (yyvsp[-1].ast); }
#line 1442 "y.tab.c"
    break;

  case 18: /* cmd: return ';'  */
#line 133 "parser.y"
                                                                                        { (yyval.ast) = (yyvsp[-1].ast); }
#line 1448 "y.tab.c"
    break;

  case 19: /* cmd: ';'  */
#line 134 "parser.y"
                                                                                                { (yyval.ast) = 0; }
#line 1454 "y.tab.c"
    break;

  case 20: /* cmdStart: cmd  */
#line 137 "parser.y"
                                                                                        { (yyval.ast) = astCreate(AST_CMD, 0, (yyvsp[0].ast), 0, 0, 0, getLineNumber()); }
#line 1460 "y.tab.c"
    break;

  case 21: /* block: '{' cmdList '}'  */
#line 140 "parser.y"
                                                                        { (yyval.ast) = astCreate(AST_CMDBLOCK, 0, (yyvsp[-1].ast), 0, 0, 0, getLineNumber()); }
#line 1466 "y.tab.c"
    break;

  case 22: /* cmdList: cmd cmdList  */
#line 143 "parser.y"
                                                        { (yyval.ast) = astCreate(AST_CMD, 0, (yyvsp[-1].ast), (yyvsp[0].ast), 0, 0, getLineNumber()); }
#line 1472 "y.tab.c"
    break;

  case 23: /* cmdList: %empty  */
#line 144 "parser.y"
                                                                                { (yyval.ast) = 0;}
#line 1478 "y.tab.c"
    break;

  case 24: /* atrb: id '=' exp  */
#line 147 "parser.y"
                                                                                                        { (yyval.ast) = astCreate(AST_ATTR, 0, (yyvsp[-2].ast), (yyvsp[0].ast), 0, 0, getLineNumber()); }
#line 1484 "y.tab.c"
    break;

  case 25: /* atrb: veccall '=' exp  */
#line 148 "parser.y"
                                                                                                        { (yyval.ast) = astCreate(AST_VECATTR, 0, (yyvsp[-2].ast), (yyvsp[0].ast), 0, 0, getLineNumber()); }
#line 1490 "y.tab.c"
    break;

  case 26: /* print: KW_PRINT string  */
#line 151 "parser.y"
                                                        { (yyval.ast) = astCreate(AST_PRINT, 0, (yyvsp[0].ast), 0, 0, 0, getLineNumber()); }
#line 1496 "y.tab.c"
    break;

  case 27: /* print: KW_PRINT exp  */
#line 152 "parser.y"
                                                                { (yyval.ast) = astCreate(AST_PRINT, 0, (yyvsp[0].ast), 0, 0, 0, getLineNumber()); }
#line 1502 "y.tab.c"
    break;

  case 28: /* return: KW_RETURN exp  */
#line 155 "parser.y"
                                                        { (yyval.ast) = astCreate(AST_RETURN, 0, (yyvsp[0].ast), 0, 0, 0, getLineNumber()); }
#line 1508 "y.tab.c"
    break;

  case 29: /* flowCmd: KW_IF '(' exp ')' cmdStart  */
#line 158 "parser.y"
                                                                                        { (yyval.ast) = astCreate(AST_IF, 0, (yyvsp[-2].ast), (yyvsp[0].ast), 0, 0, getLineNumber());}
#line 1514 "y.tab.c"
    break;

  case 30: /* flowCmd: KW_IF '(' exp ')' cmdStart KW_ELSE cmdStart  */
#line 159 "parser.y"
                                                                                { (yyval.ast) = astCreate(AST_IFELSE, 0, (yyvsp[-4].ast), (yyvsp[-2].ast), (yyvsp[0].ast), 0, getLineNumber()); }
#line 1520 "y.tab.c"
    break;

  case 31: /* flowCmd: KW_WHILE '(' exp ')' cmdStart  */
#line 160 "parser.y"
                                                                                                { (yyval.ast) = astCreate(AST_WHILE, 0, (yyvsp[-2].ast), (yyvsp[0].ast), 0, 0, getLineNumber()); }
#line 1526 "y.tab.c"
    break;

  case 32: /* exp: '(' exp ')'  */
#line 163 "parser.y"
                                                                { (yyval.ast) = astCreate(AST_PRTHSIS, 0, (yyvsp[-1].ast), 0, 0, 0, getLineNumber()); }
#line 1532 "y.tab.c"
    break;

  case 33: /* exp: exp '+' exp  */
#line 164 "parser.y"
                                                                        { (yyval.ast) = astCreate(AST_ADD, 0, (yyvsp[-2].ast), (yyvsp[0].ast), 0, 0, getLineNumber()); }
#line 1538 "y.tab.c"
    break;

  case 34: /* exp: exp '-' exp  */
#line 165 "parser.y"
                                                                        { (yyval.ast) = astCreate(AST_SUB, 0, (yyvsp[-2].ast), (yyvsp[0].ast), 0, 0, getLineNumber()); }
#line 1544 "y.tab.c"
    break;

  case 35: /* exp: exp '*' exp  */
#line 166 "parser.y"
                                                                        { (yyval.ast) = astCreate(AST_MUL, 0, (yyvsp[-2].ast), (yyvsp[0].ast), 0, 0, getLineNumber()); }
#line 1550 "y.tab.c"
    break;

  case 36: /* exp: exp '/' exp  */
#line 167 "parser.y"
                                                                        { (yyval.ast) = astCreate(AST_DIV, 0, (yyvsp[-2].ast), (yyvsp[0].ast), 0, 0, getLineNumber()); }
#line 1556 "y.tab.c"
    break;

  case 37: /* exp: exp '<' exp  */
#line 168 "parser.y"
                                                                        { (yyval.ast) = astCreate(AST_LSS, 0, (yyvsp[-2].ast), (yyvsp[0].ast), 0, 0, getLineNumber()); }
#line 1562 "y.tab.c"
    break;

  case 38: /* exp: exp '>' exp  */
#line 169 "parser.y"
                                                                        { (yyval.ast) = astCreate(AST_GTR, 0, (yyvsp[-2].ast), (yyvsp[0].ast), 0, 0, getLineNumber()); }
#line 1568 "y.tab.c"
    break;

  case 39: /* exp: exp OPERATOR_LE exp  */
#line 170 "parser.y"
                                                                { (yyval.ast) = astCreate(AST_LE, 0, (yyvsp[-2].ast), (yyvsp[0].ast), 0, 0, getLineNumber()); }
#line 1574 "y.tab.c"
    break;

  case 40: /* exp: exp OPERATOR_GE exp  */
#line 171 "parser.y"
                                                                { (yyval.ast) = astCreate(AST_GE, 0, (yyvsp[-2].ast), (yyvsp[0].ast), 0, 0, getLineNumber()); }
#line 1580 "y.tab.c"
    break;

  case 41: /* exp: exp OPERATOR_EQ exp  */
#line 172 "parser.y"
                                                                { (yyval.ast) = astCreate(AST_EQ, 0, (yyvsp[-2].ast), (yyvsp[0].ast), 0, 0, getLineNumber()); }
#line 1586 "y.tab.c"
    break;

  case 42: /* exp: exp OPERATOR_DIF exp  */
#line 173 "parser.y"
                                                        { (yyval.ast) = astCreate(AST_DIF, 0, (yyvsp[-2].ast), (yyvsp[0].ast), 0, 0, getLineNumber()); }
#line 1592 "y.tab.c"
    break;

  case 43: /* exp: exp '&' exp  */
#line 174 "parser.y"
                                                                        { (yyval.ast) = astCreate(AST_AND, 0, (yyvsp[-2].ast), (yyvsp[0].ast), 0, 0, getLineNumber()); }
#line 1598 "y.tab.c"
    break;

  case 44: /* exp: exp '|' exp  */
#line 175 "parser.y"
                                                                        { (yyval.ast) = astCreate(AST_OR, 0, (yyvsp[-2].ast), (yyvsp[0].ast), 0, 0, getLineNumber()); }
#line 1604 "y.tab.c"
    break;

  case 45: /* exp: '~' exp  */
#line 176 "parser.y"
                                                                        { (yyval.ast) = astCreate(AST_NOT, 0, (yyvsp[0].ast), 0, 0, 0, getLineNumber()); }
#line 1610 "y.tab.c"
    break;

  case 46: /* exp: id '(' args ')'  */
#line 177 "parser.y"
                                                                { (yyval.ast) = astCreate(AST_FOOCALL, 0, (yyvsp[-3].ast), (yyvsp[-1].ast), 0, 0, getLineNumber());}
#line 1616 "y.tab.c"
    break;

  case 47: /* exp: KW_INPUT '(' type ')'  */
#line 178 "parser.y"
                                                                { (yyval.ast) = astCreate(AST_INPUT, 0, (yyvsp[-1].ast), 0, 0, 0, getLineNumber());}
#line 1622 "y.tab.c"
    break;

  case 48: /* exp: TK_IDENTIFIER  */
#line 179 "parser.y"
                                                                { (yyval.ast) = astCreate(AST_SYMBOL, (yyvsp[0].symbol), 0, 0, 0, 0, getLineNumber()); }
#line 1628 "y.tab.c"
    break;

  case 49: /* exp: veccall  */
#line 180 "parser.y"
                                                                        { (yyval.ast) = (yyvsp[0].ast);}
#line 1634 "y.tab.c"
    break;

  case 50: /* exp: LIT_INT  */
#line 181 "parser.y"
                                                                        { (yyval.ast) = astCreate(AST_SYMBOL, (yyvsp[0].symbol), 0, 0, 0, 0, getLineNumber()); }
#line 1640 "y.tab.c"
    break;

  case 51: /* exp: LIT_CHAR  */
#line 182 "parser.y"
                                                                        { (yyval.ast) = astCreate(AST_SYMBOL, (yyvsp[0].symbol), 0, 0, 0, 0, getLineNumber()); }
#line 1646 "y.tab.c"
    break;

  case 52: /* exp: LIT_REAL  */
#line 183 "parser.y"
                                                                        { (yyval.ast) = astCreate(AST_SYMBOL, (yyvsp[0].symbol), 0, 0, 0, 0, getLineNumber()); }
#line 1652 "y.tab.c"
    break;

  case 53: /* args: exp ',' args  */
#line 186 "parser.y"
                                                        { (yyval.ast) = astCreate(AST_ARG, 0, (yyvsp[-2].ast), (yyvsp[0].ast), 0, 0, getLineNumber()); }
#line 1658 "y.tab.c"
    break;

  case 54: /* args: exp  */
#line 187 "parser.y"
                                                                                { (yyval.ast) = astCreate(AST_ARG, 0, (yyvsp[0].ast), 0, 0, 0, getLineNumber()); }
#line 1664 "y.tab.c"
    break;

  case 55: /* vector: value vector  */
#line 190 "parser.y"
                                                        { (yyval.ast) = astCreate(AST_VECVAL, 0, (yyvsp[-1].ast), (yyvsp[0].ast), 0, 0, getLineNumber()); }
#line 1670 "y.tab.c"
    break;

  case 56: /* vector: %empty  */
#line 191 "parser.y"
                                                                                { (yyval.ast) = 0; }
#line 1676 "y.tab.c"
    break;

  case 57: /* type: KW_CHAR  */
#line 194 "parser.y"
                                                                { (yyval.ast) = astCreate(AST_KWCHAR, (yyvsp[0].symbol), 0, 0, 0, 0, getLineNumber()); }
#line 1682 "y.tab.c"
    break;

  case 58: /* type: KW_INT  */
#line 195 "parser.y"
                                                                        { (yyval.ast) = astCreate(AST_KWINT, (yyvsp[0].symbol), 0, 0, 0, 0, getLineNumber()); }
#line 1688 "y.tab.c"
    break;

  case 59: /* type: KW_FLOAT  */
#line 196 "parser.y"
                                                                        { (yyval.ast) = astCreate(AST_KWFLOAT, (yyvsp[0].symbol), 0, 0, 0, 0, getLineNumber()); }
#line 1694 "y.tab.c"
    break;

  case 60: /* value: LIT_INT  */
#line 199 "parser.y"
                                                                { (yyval.ast) = astCreate(AST_SYMBOL, (yyvsp[0].symbol), 0, 0, 0, 0, getLineNumber()); }
#line 1700 "y.tab.c"
    break;

  case 61: /* value: LIT_REAL  */
#line 200 "parser.y"
                                                                        { (yyval.ast) = astCreate(AST_SYMBOL, (yyvsp[0].symbol), 0, 0, 0, 0, getLineNumber()); }
#line 1706 "y.tab.c"
    break;

  case 62: /* value: LIT_CHAR  */
#line 201 "parser.y"
                                                                        { (yyval.ast) = astCreate(AST_SYMBOL, (yyvsp[0].symbol), 0, 0, 0, 0, getLineNumber()); }
#line 1712 "y.tab.c"
    break;

  case 63: /* id: TK_IDENTIFIER  */
#line 204 "parser.y"
                                                                { (yyval.ast) = astCreate(AST_SYMBOL, (yyvsp[0].symbol), 0, 0, 0, 0, getLineNumber()); }
#line 1718 "y.tab.c"
    break;

  case 64: /* veccall: id '[' exp ']'  */
#line 207 "parser.y"
                                                                { (yyval.ast) = astCreate(AST_VECCALL, 0, (yyvsp[-3].ast), (yyvsp[-1].ast), 0, 0, getLineNumber());}
#line 1724 "y.tab.c"
    break;

  case 65: /* string: LIT_STRING  */
#line 210 "parser.y"
                                                                { (yyval.ast) = astCreate(AST_SYMBOL, (yyvsp[0].symbol), 0, 0, 0, 0, getLineNumber());}
#line 1730 "y.tab.c"
    break;

  case 66: /* int: LIT_INT  */
#line 213 "parser.y"
                                                                { (yyval.ast) = astCreate(AST_SYMBOL, (yyvsp[0].symbol), 0, 0, 0, 0, getLineNumber());}
#line 1736 "y.tab.c"
    break;


#line 1740 "y.tab.c"

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

#line 221 "parser.y"


tac* getTACs(){
  return programTacs;
}

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



