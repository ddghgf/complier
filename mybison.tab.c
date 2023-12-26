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
#line 1 "mybison.y"


    #include<stdio.h>
    #include<ctype.h>
    #include <stdlib.h>
    #include <stdarg.h>
    #include <string.h>
    int yylex();	// use flex to return token 
    void yyerror(char* s);
    extern int yylineno; //line number
    int failed = 0; // if == 0, print the tree; else print error
    int lastLine = -1;//  line number of last error
    extern int failed;
    extern char* yytext;
    extern int lastLine;
    char* print_leaf[37] = {"INT", "FLOAT", "CONST","VOID", "BREAK", "CONTINUE", "RETURN","IF", "ELSE", "WHILE", "INTCON", 
    "FLOATCON", "LT", "LE", "GT", "GE", "EQ", "NE", "ASSIGN", "PLUS", "SUB", "MUL", "DIV", "MOD", "NOT","AND", "OR", "SEMICN", 
     "COMMA", "LBRACE", "RBRACE", "LBRACK", "RBRACK", "LPARENT", "RPARENT", "Ident", "BType"};
     typedef struct Node{
        char* value;
        char* text;
        int line;
        struct Node* sonNodes;
        struct Node* broNodes;
    }Node;
    void my_yyerror(char* str);
    void preHandle(char* text, char* str);
    struct Node* createNode(char* value, char* text, int line, int num, ...);
    void printTree(Node* root, int space);
    void addBroOfSon(Node* root, Node* bro);

#line 103 "mybison.tab.c"

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

#include "mybison.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_ASSIGN = 3,                     /* "="  */
  YYSYMBOL_LT = 4,                         /* "<"  */
  YYSYMBOL_LE = 5,                         /* "<="  */
  YYSYMBOL_GT = 6,                         /* ">"  */
  YYSYMBOL_GE = 7,                         /* ">="  */
  YYSYMBOL_EQ = 8,                         /* "=="  */
  YYSYMBOL_NE = 9,                         /* "!="  */
  YYSYMBOL_PLUS = 10,                      /* "+"  */
  YYSYMBOL_SUB = 11,                       /* "-"  */
  YYSYMBOL_MUL = 12,                       /* "*"  */
  YYSYMBOL_DIV = 13,                       /* "/"  */
  YYSYMBOL_MOD = 14,                       /* "%"  */
  YYSYMBOL_NOT = 15,                       /* "!"  */
  YYSYMBOL_SEMICN = 16,                    /* ";"  */
  YYSYMBOL_COMMA = 17,                     /* ","  */
  YYSYMBOL_LBRACE = 18,                    /* "{"  */
  YYSYMBOL_RBRACE = 19,                    /* "}"  */
  YYSYMBOL_LBRACK = 20,                    /* "["  */
  YYSYMBOL_RBRACK = 21,                    /* "]"  */
  YYSYMBOL_LPARENT = 22,                   /* "("  */
  YYSYMBOL_RPARENT = 23,                   /* ")"  */
  YYSYMBOL_CONST = 24,                     /* CONST  */
  YYSYMBOL_IF = 25,                        /* IF  */
  YYSYMBOL_ELSE = 26,                      /* ELSE  */
  YYSYMBOL_WHILE = 27,                     /* WHILE  */
  YYSYMBOL_BREAK = 28,                     /* BREAK  */
  YYSYMBOL_RETURN = 29,                    /* RETURN  */
  YYSYMBOL_CONTINUE = 30,                  /* CONTINUE  */
  YYSYMBOL_AND = 31,                       /* AND  */
  YYSYMBOL_OR = 32,                        /* OR  */
  YYSYMBOL_Ident = 33,                     /* Ident  */
  YYSYMBOL_INT = 34,                       /* INT  */
  YYSYMBOL_FLOAT = 35,                     /* FLOAT  */
  YYSYMBOL_VOID = 36,                      /* VOID  */
  YYSYMBOL_INTCON = 37,                    /* INTCON  */
  YYSYMBOL_FLOATCON = 38,                  /* FLOATCON  */
  YYSYMBOL_ILLEGAL_OCTAL_CONST = 39,       /* ILLEGAL_OCTAL_CONST  */
  YYSYMBOL_ILLEGAL_HEX_CONST = 40,         /* ILLEGAL_HEX_CONST  */
  YYSYMBOL_YYACCEPT = 41,                  /* $accept  */
  YYSYMBOL_Start = 42,                     /* Start  */
  YYSYMBOL_CompUnit = 43,                  /* CompUnit  */
  YYSYMBOL_Decl = 44,                      /* Decl  */
  YYSYMBOL_ConstDecl = 45,                 /* ConstDecl  */
  YYSYMBOL_BType = 46,                     /* BType  */
  YYSYMBOL_ConstDef = 47,                  /* ConstDef  */
  YYSYMBOL_ConstExpGroup = 48,             /* ConstExpGroup  */
  YYSYMBOL_ConstInitVal = 49,              /* ConstInitVal  */
  YYSYMBOL_ConstInitValGroup = 50,         /* ConstInitValGroup  */
  YYSYMBOL_VarDecl = 51,                   /* VarDecl  */
  YYSYMBOL_VarDefGroup = 52,               /* VarDefGroup  */
  YYSYMBOL_VarDef = 53,                    /* VarDef  */
  YYSYMBOL_ArrayDef = 54,                  /* ArrayDef  */
  YYSYMBOL_InitVal = 55,                   /* InitVal  */
  YYSYMBOL_InitValGroup = 56,              /* InitValGroup  */
  YYSYMBOL_FuncDef = 57,                   /* FuncDef  */
  YYSYMBOL_FuncFParams = 58,               /* FuncFParams  */
  YYSYMBOL_FuncFParam = 59,                /* FuncFParam  */
  YYSYMBOL_Array = 60,                     /* Array  */
  YYSYMBOL_Block = 61,                     /* Block  */
  YYSYMBOL_BlockGroup = 62,                /* BlockGroup  */
  YYSYMBOL_BlockItem = 63,                 /* BlockItem  */
  YYSYMBOL_Stmt = 64,                      /* Stmt  */
  YYSYMBOL_Exp = 65,                       /* Exp  */
  YYSYMBOL_Cond = 66,                      /* Cond  */
  YYSYMBOL_LVal = 67,                      /* LVal  */
  YYSYMBOL_PrimaryExp = 68,                /* PrimaryExp  */
  YYSYMBOL_Number = 69,                    /* Number  */
  YYSYMBOL_UnaryExp = 70,                  /* UnaryExp  */
  YYSYMBOL_UnaryOp = 71,                   /* UnaryOp  */
  YYSYMBOL_FuncRParams = 72,               /* FuncRParams  */
  YYSYMBOL_MulExp = 73,                    /* MulExp  */
  YYSYMBOL_AddExp = 74,                    /* AddExp  */
  YYSYMBOL_RelExp = 75,                    /* RelExp  */
  YYSYMBOL_EqExp = 76,                     /* EqExp  */
  YYSYMBOL_LAndExp = 77,                   /* LAndExp  */
  YYSYMBOL_LOrExp = 78,                    /* LOrExp  */
  YYSYMBOL_ConstExp = 79                   /* ConstExp  */
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
typedef yytype_uint8 yy_state_t;

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
#define YYFINAL  13
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   447

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  39
/* YYNRULES -- Number of rules.  */
#define YYNRULES  115
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  200

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   295


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
      35,    36,    37,    38,    39,    40
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    87,    87,    90,    91,    92,    93,    94,    95,    97,
      98,   100,   101,   102,   103,   104,   106,   107,   108,   109,
     110,   111,   112,   114,   115,   116,   117,   119,   120,   121,
     122,   123,   124,   125,   126,   128,   129,   130,   132,   133,
     135,   136,   137,   138,   140,   141,   142,   143,   144,   145,
     146,   147,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213
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
  "\"end of file\"", "error", "\"invalid token\"", "\"=\"", "\"<\"",
  "\"<=\"", "\">\"", "\">=\"", "\"==\"", "\"!=\"", "\"+\"", "\"-\"",
  "\"*\"", "\"/\"", "\"%\"", "\"!\"", "\";\"", "\",\"", "\"{\"", "\"}\"",
  "\"[\"", "\"]\"", "\"(\"", "\")\"", "CONST", "IF", "ELSE", "WHILE",
  "BREAK", "RETURN", "CONTINUE", "AND", "OR", "Ident", "INT", "FLOAT",
  "VOID", "INTCON", "FLOATCON", "ILLEGAL_OCTAL_CONST", "ILLEGAL_HEX_CONST",
  "$accept", "Start", "CompUnit", "Decl", "ConstDecl", "BType", "ConstDef",
  "ConstExpGroup", "ConstInitVal", "ConstInitValGroup", "VarDecl",
  "VarDefGroup", "VarDef", "ArrayDef", "InitVal", "InitValGroup",
  "FuncDef", "FuncFParams", "FuncFParam", "Array", "Block", "BlockGroup",
  "BlockItem", "Stmt", "Exp", "Cond", "LVal", "PrimaryExp", "Number",
  "UnaryExp", "UnaryOp", "FuncRParams", "MulExp", "AddExp", "RelExp",
  "EqExp", "LAndExp", "LOrExp", "ConstExp", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-167)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-62)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      64,   -19,  -167,  -167,  -167,    91,    64,  -167,     3,    -6,
    -167,  -167,    54,  -167,  -167,  -167,    54,    27,    12,  -167,
      11,    95,  -167,   367,   161,    61,    19,  -167,  -167,    86,
     376,   386,    35,  -167,  -167,  -167,  -167,   326,   386,    90,
    -167,  -167,  -167,  -167,  -167,  -167,  -167,  -167,  -167,  -167,
     386,    59,   104,   105,   104,    20,   111,   102,    84,  -167,
     367,   386,    47,  -167,   336,  -167,  -167,   122,   376,   386,
    -167,  -167,    73,   144,   169,   182,   407,  -167,   386,   386,
     386,   386,   386,  -167,  -167,  -167,   233,  -167,   148,   -19,
     111,  -167,   154,  -167,  -167,    87,  -167,  -167,   156,   367,
    -167,  -167,   157,   160,  -167,  -167,    85,   202,   168,  -167,
    -167,  -167,    59,    59,  -167,  -167,   163,   164,    50,    42,
      53,  -167,    86,   112,   264,  -167,  -167,    58,   179,   166,
    -167,  -167,  -167,   376,  -167,  -167,  -167,  -167,  -167,   386,
    -167,   167,   174,   175,   386,   386,  -167,  -167,  -167,  -167,
      62,  -167,  -167,  -167,  -167,  -167,  -167,  -167,   386,   170,
    -167,  -167,  -167,  -167,  -167,   187,   104,   159,   109,   158,
     184,   188,  -167,  -167,    67,   407,   295,   386,   386,   386,
     386,   386,   386,   386,   386,   295,  -167,  -167,   192,   104,
     104,   104,   104,   159,   159,   109,   158,  -167,   295,  -167
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,    11,    12,    13,     0,     2,     5,     7,     0,
       8,     3,     0,     1,     6,     4,     0,    27,     0,    25,
       0,     0,    10,     0,     0,     0,    30,    24,    23,     0,
       0,     0,     0,     9,    91,    92,    93,     0,     0,    78,
      83,    84,    86,    85,    28,    35,    81,    87,    82,    96,
       0,   100,    76,     0,   115,     0,     0,     0,     0,    42,
       0,     0,    27,    26,     0,    15,    18,     0,     0,     0,
      36,    38,     0,     0,     0,     0,    79,    90,     0,     0,
       0,     0,     0,    31,    29,    33,     0,    40,    44,     0,
       0,    32,     0,    19,    21,     0,    16,    14,     0,     0,
      37,    80,     0,     0,    88,    94,     0,     0,     0,    97,
      98,    99,   101,   102,    59,    52,     0,     0,     0,     0,
       0,    56,     0,     0,     0,    54,    57,     0,    81,     0,
      43,    41,    34,     0,    20,    17,    39,    49,    47,     0,
      89,     0,     0,     0,     0,     0,    72,    65,    75,    67,
       0,    74,    66,    70,    53,    55,    69,    60,     0,    45,
      22,    95,    51,    48,    50,     0,   103,   108,   111,   113,
      77,     0,    73,    68,     0,    46,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    71,    58,    62,   104,
     106,   105,   107,   109,   110,   112,   114,    64,     0,    63
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -167,  -167,  -167,    70,  -167,     0,   198,  -167,   -56,  -167,
    -167,  -167,   194,  -167,   -34,  -167,   219,  -167,   137,    68,
     -54,  -167,   106,  -166,   -14,    83,   -82,  -167,  -167,   -45,
    -167,  -167,    51,   -24,    -8,    46,    48,  -167,   -13
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     5,     6,   121,     8,     9,    21,    32,    65,    95,
      10,    18,    19,    26,    44,    72,    11,    58,    59,    76,
     123,   124,   125,   126,   127,   165,    46,    47,    48,    49,
      50,   106,    51,    52,   167,   168,   169,   170,    66
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      54,    12,    87,    71,   128,    77,    54,    54,    94,    45,
     188,    55,    97,    27,    30,     2,     3,     4,    67,   197,
      16,    84,    60,    45,    73,    57,    91,    17,    28,    29,
      23,    31,   199,   109,   110,   111,   131,    54,    68,    61,
      54,    85,   128,   148,    54,    54,    45,    24,    92,    25,
      23,   146,    34,    35,   151,    69,    98,    36,   149,   156,
     103,   105,   108,   172,    38,   136,   147,    24,   186,   152,
       7,    78,    79,    80,   157,    39,    14,   160,   173,    40,
      41,    42,    43,   187,    56,    45,   122,    20,     1,    57,
      99,    13,   100,   142,   128,     2,     3,     4,     2,     3,
       4,    89,   139,   128,   133,   150,   134,    90,   140,    54,
      74,    33,    75,   153,    81,    82,   128,   181,   182,    62,
     166,   166,   -61,   -61,   122,   161,    83,   -61,   -61,    86,
     -61,   -61,   112,   113,   -61,    88,   -61,   -61,   -61,   -61,
     -61,   -61,   -61,    96,   174,   -61,   -61,   -61,   -61,   -61,
     -61,   -61,   -61,   189,   190,   191,   192,   166,   166,   166,
     166,   108,    53,   177,   178,   179,   180,   101,   129,   143,
     102,    34,    35,   193,   194,   132,    36,   135,   137,    34,
      35,   138,   158,    38,    36,   144,   145,   159,   162,   183,
      74,    38,    34,    35,    39,   163,   164,    36,    40,    41,
      42,    43,    39,   141,    38,   104,    40,    41,    42,    43,
     176,   185,    34,    35,    22,    39,   184,    36,   198,    40,
      41,    42,    43,    63,    38,    15,   130,   175,   171,   195,
     155,     0,   196,     0,     0,    39,     0,     0,     0,    40,
      41,    42,    43,    34,    35,     0,     0,     0,    36,   114,
       0,    86,   115,     0,     0,    38,     0,     1,   116,     0,
     117,   118,   119,   120,     0,     0,    39,     2,     3,     4,
      40,    41,    42,    43,    34,    35,     0,     0,     0,    36,
     114,     0,    86,   154,     0,     0,    38,     0,     1,   116,
       0,   117,   118,   119,   120,     0,     0,    39,     2,     3,
       4,    40,    41,    42,    43,    34,    35,     0,     0,     0,
      36,   114,     0,    86,     0,     0,     0,    38,     0,     0,
     116,     0,   117,   118,   119,   120,     0,     0,    39,     0,
       0,     0,    40,    41,    42,    43,    34,    35,     0,     0,
       0,    36,     0,     0,    37,    70,    34,    35,    38,     0,
       0,    36,     0,     0,    64,    93,     0,     0,    38,    39,
       0,     0,     0,    40,    41,    42,    43,     0,     0,    39,
       0,     0,     0,    40,    41,    42,    43,    34,    35,     0,
       0,     0,    36,     0,     0,    37,    34,    35,     0,    38,
       0,    36,     0,     0,    64,     0,    34,    35,    38,     0,
      39,    36,     0,     0,    40,    41,    42,    43,    38,    39,
       0,     0,     0,    40,    41,    42,    43,    34,    35,    39,
       0,     0,    36,    40,    41,    42,    43,   107,     0,    38,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      39,     0,     0,     0,    40,    41,    42,    43
};

static const yytype_int16 yycheck[] =
{
      24,     1,    56,    37,    86,    50,    30,    31,    64,    23,
     176,    24,    68,     1,     3,    34,    35,    36,    31,   185,
      17,     1,     3,    37,    38,    25,    60,    33,    16,    17,
       3,    20,   198,    78,    79,    80,    90,    61,     3,    20,
      64,    21,   124,     1,    68,    69,    60,    20,    61,    22,
       3,     1,    10,    11,     1,    20,    69,    15,    16,     1,
      74,    75,    76,     1,    22,    99,    16,    20,     1,    16,
       0,    12,    13,    14,    16,    33,     6,   133,    16,    37,
      38,    39,    40,    16,    23,    99,    86,    33,    24,    89,
      17,     0,    19,   107,   176,    34,    35,    36,    34,    35,
      36,    17,    17,   185,    17,   119,    19,    23,    23,   133,
      20,    16,    22,     1,    10,    11,   198,     8,     9,    33,
     144,   145,    10,    11,   124,   139,    21,    15,    16,    18,
      18,    19,    81,    82,    22,    33,    24,    25,    26,    27,
      28,    29,    30,    21,   158,    33,    34,    35,    36,    37,
      38,    39,    40,   177,   178,   179,   180,   181,   182,   183,
     184,   175,     1,     4,     5,     6,     7,    23,    20,     1,
       1,    10,    11,   181,   182,    21,    15,    21,    21,    10,
      11,    21,     3,    22,    15,    22,    22,    21,    21,    31,
      20,    22,    10,    11,    33,    21,    21,    15,    37,    38,
      39,    40,    33,     1,    22,    23,    37,    38,    39,    40,
      23,    23,    10,    11,    16,    33,    32,    15,    26,    37,
      38,    39,    40,    29,    22,     6,    89,   159,   145,   183,
     124,    -1,   184,    -1,    -1,    33,    -1,    -1,    -1,    37,
      38,    39,    40,    10,    11,    -1,    -1,    -1,    15,    16,
      -1,    18,    19,    -1,    -1,    22,    -1,    24,    25,    -1,
      27,    28,    29,    30,    -1,    -1,    33,    34,    35,    36,
      37,    38,    39,    40,    10,    11,    -1,    -1,    -1,    15,
      16,    -1,    18,    19,    -1,    -1,    22,    -1,    24,    25,
      -1,    27,    28,    29,    30,    -1,    -1,    33,    34,    35,
      36,    37,    38,    39,    40,    10,    11,    -1,    -1,    -1,
      15,    16,    -1,    18,    -1,    -1,    -1,    22,    -1,    -1,
      25,    -1,    27,    28,    29,    30,    -1,    -1,    33,    -1,
      -1,    -1,    37,    38,    39,    40,    10,    11,    -1,    -1,
      -1,    15,    -1,    -1,    18,    19,    10,    11,    22,    -1,
      -1,    15,    -1,    -1,    18,    19,    -1,    -1,    22,    33,
      -1,    -1,    -1,    37,    38,    39,    40,    -1,    -1,    33,
      -1,    -1,    -1,    37,    38,    39,    40,    10,    11,    -1,
      -1,    -1,    15,    -1,    -1,    18,    10,    11,    -1,    22,
      -1,    15,    -1,    -1,    18,    -1,    10,    11,    22,    -1,
      33,    15,    -1,    -1,    37,    38,    39,    40,    22,    33,
      -1,    -1,    -1,    37,    38,    39,    40,    10,    11,    33,
      -1,    -1,    15,    37,    38,    39,    40,    20,    -1,    22,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      33,    -1,    -1,    -1,    37,    38,    39,    40
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    24,    34,    35,    36,    42,    43,    44,    45,    46,
      51,    57,    46,     0,    44,    57,    17,    33,    52,    53,
      33,    47,    47,     3,    20,    22,    54,     1,    16,    17,
       3,    20,    48,    16,    10,    11,    15,    18,    22,    33,
      37,    38,    39,    40,    55,    65,    67,    68,    69,    70,
      71,    73,    74,     1,    74,    79,    23,    46,    58,    59,
       3,    20,    33,    53,    18,    49,    79,    79,     3,    20,
      19,    55,    56,    65,    20,    22,    60,    70,    12,    13,
      14,    10,    11,    21,     1,    21,    18,    61,    33,    17,
      23,    55,    79,    19,    49,    50,    21,    49,    79,    17,
      19,    23,     1,    65,    23,    65,    72,    20,    65,    70,
      70,    70,    73,    73,    16,    19,    25,    27,    28,    29,
      30,    44,    46,    61,    62,    63,    64,    65,    67,    20,
      59,    61,    21,    17,    19,    21,    55,    21,    21,    17,
      23,     1,    65,     1,    22,    22,     1,    16,     1,    16,
      65,     1,    16,     1,    19,    63,     1,    16,     3,    21,
      49,    65,    21,    21,    21,    66,    74,    75,    76,    77,
      78,    66,     1,    16,    65,    60,    23,     4,     5,     6,
       7,     8,     9,    31,    32,    23,     1,    16,    64,    74,
      74,    74,    74,    75,    75,    76,    77,    64,    26,    64
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    41,    42,    43,    43,    43,    43,    44,    44,    45,
      45,    46,    46,    46,    47,    47,    48,    48,    49,    49,
      49,    50,    50,    51,    51,    52,    52,    53,    53,    53,
      53,    53,    53,    54,    54,    55,    55,    55,    56,    56,
      57,    57,    58,    58,    59,    59,    59,    60,    60,    60,
      60,    60,    61,    61,    62,    62,    63,    63,    64,    64,
      64,    64,    64,    64,    64,    64,    64,    64,    64,    64,
      64,    64,    64,    64,    64,    64,    65,    66,    67,    67,
      68,    68,    68,    69,    69,    69,    69,    70,    70,    70,
      70,    71,    71,    71,    72,    72,    73,    73,    73,    73,
      74,    74,    74,    75,    75,    75,    75,    75,    76,    76,
      76,    77,    77,    78,    78,    79
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     2,     1,     1,     4,
       3,     1,     1,     1,     4,     3,     3,     4,     1,     2,
       3,     1,     3,     3,     3,     1,     3,     1,     3,     4,
       2,     4,     4,     3,     4,     1,     2,     3,     1,     3,
       5,     6,     1,     3,     2,     4,     5,     3,     4,     3,
       4,     4,     2,     3,     1,     2,     1,     1,     4,     1,
       2,     1,     5,     7,     5,     2,     2,     2,     3,     2,
       2,     4,     2,     3,     2,     2,     1,     1,     1,     2,
       3,     1,     1,     1,     1,     1,     1,     1,     3,     4,
       2,     1,     1,     1,     1,     3,     1,     3,     3,     3,
       1,     3,     3,     1,     3,     3,     3,     3,     1,     3,
       3,     1,     3,     1,     3,     1
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
  case 2: /* Start: CompUnit  */
#line 87 "mybison.y"
                {
    if(failed == 0) printTree((yyval.node), 0);
}
#line 1356 "mybison.tab.c"
    break;

  case 3: /* CompUnit: FuncDef  */
#line 90 "mybison.y"
                  {(yyval.node) = createNode("CompUnit", "", (yyvsp[0].node)->line, 1, (yyvsp[0].node)); }
#line 1362 "mybison.tab.c"
    break;

  case 4: /* CompUnit: CompUnit FuncDef  */
#line 91 "mybison.y"
                           {(yyval.node) = (yyvsp[-1].node); addBroOfSon((yyvsp[-1].node), (yyvsp[0].node)); }
#line 1368 "mybison.tab.c"
    break;

  case 5: /* CompUnit: Decl  */
#line 92 "mybison.y"
               {(yyval.node) = createNode("CompUnit", "", (yyvsp[0].node)->line, 1, (yyvsp[0].node)); }
#line 1374 "mybison.tab.c"
    break;

  case 6: /* CompUnit: CompUnit Decl  */
#line 93 "mybison.y"
                        {(yyval.node) = (yyvsp[-1].node); addBroOfSon((yyvsp[-1].node), (yyvsp[0].node)); }
#line 1380 "mybison.tab.c"
    break;

  case 7: /* Decl: ConstDecl  */
#line 94 "mybison.y"
                {(yyval.node) = createNode("Decl", "", (yyvsp[0].node)->line, 1, (yyvsp[0].node)); }
#line 1386 "mybison.tab.c"
    break;

  case 8: /* Decl: VarDecl  */
#line 95 "mybison.y"
              {(yyval.node) = createNode("Decl", "", (yyvsp[0].node)->line, 1, (yyvsp[0].node)); }
#line 1392 "mybison.tab.c"
    break;

  case 9: /* ConstDecl: CONST BType ConstDef ";"  */
#line 97 "mybison.y"
                                       {(yyval.node) = createNode("ConstDecl", "", (yyvsp[-3].node)->line, 3, (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node)); }
#line 1398 "mybison.tab.c"
    break;

  case 10: /* ConstDecl: ConstDecl "," ConstDef  */
#line 98 "mybison.y"
                                    {(yyval.node) = createNode("ConstDecl", "", (yyvsp[-2].node)->line, 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));}
#line 1404 "mybison.tab.c"
    break;

  case 11: /* BType: INT  */
#line 100 "mybison.y"
           {(yyval.node) = createNode("Btype", "", (yyvsp[0].node)->line, 1, (yyvsp[0].node));}
#line 1410 "mybison.tab.c"
    break;

  case 12: /* BType: FLOAT  */
#line 101 "mybison.y"
             {(yyval.node) = createNode("Btype", "", (yyvsp[0].node)->line, 1, (yyvsp[0].node));}
#line 1416 "mybison.tab.c"
    break;

  case 13: /* BType: VOID  */
#line 102 "mybison.y"
            {(yyval.node) = createNode("Btype", "", (yyvsp[0].node)->line, 1, (yyvsp[0].node));}
#line 1422 "mybison.tab.c"
    break;

  case 14: /* ConstDef: Ident ConstExpGroup "=" ConstInitVal  */
#line 103 "mybison.y"
                                                  {(yyval.node) = createNode("ConstDef", "", (yyvsp[-3].node)->line, 4, (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));}
#line 1428 "mybison.tab.c"
    break;

  case 15: /* ConstDef: Ident "=" ConstInitVal  */
#line 104 "mybison.y"
                                {(yyval.node) = createNode("ConstDef", "", (yyvsp[-2].node)->line, 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));}
#line 1434 "mybison.tab.c"
    break;

  case 17: /* ConstExpGroup: ConstExpGroup "[" ConstExp "]"  */
#line 107 "mybison.y"
                                           {(yyval.node) = (yyvsp[-3].node); addBroOfSon((yyvsp[-3].node), (yyvsp[-2].node)); addBroOfSon((yyvsp[-3].node), (yyvsp[-1].node)); addBroOfSon((yyvsp[-3].node), (yyvsp[0].node)); }
#line 1440 "mybison.tab.c"
    break;

  case 18: /* ConstInitVal: ConstExp  */
#line 108 "mybison.y"
                        {(yyval.node) = createNode("ConstInitVal", "", (yyvsp[0].node)->line, 1, (yyvsp[0].node)); }
#line 1446 "mybison.tab.c"
    break;

  case 19: /* ConstInitVal: "{" "}"  */
#line 109 "mybison.y"
                    {(yyval.node) = createNode("ConstInitVal", "", (yyvsp[-1].node)->line, 2, (yyvsp[-1].node), (yyvsp[0].node));}
#line 1452 "mybison.tab.c"
    break;

  case 20: /* ConstInitVal: "{" ConstInitValGroup "}"  */
#line 110 "mybison.y"
                                      {(yyval.node) = createNode("ConstInitVal", "", (yyvsp[-2].node)->line, 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));}
#line 1458 "mybison.tab.c"
    break;

  case 22: /* ConstInitValGroup: ConstInitValGroup "," ConstInitVal  */
#line 112 "mybison.y"
                                           {(yyval.node) = (yyvsp[-2].node); addBroOfSon((yyvsp[-2].node), (yyvsp[-1].node)); addBroOfSon((yyvsp[-2].node), (yyvsp[0].node));}
#line 1464 "mybison.tab.c"
    break;

  case 23: /* VarDecl: BType VarDefGroup ";"  */
#line 114 "mybison.y"
                                   {(yyval.node) = createNode("VarDecl", "", (yyvsp[-2].node)->line, 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));}
#line 1470 "mybison.tab.c"
    break;

  case 24: /* VarDecl: BType VarDefGroup error  */
#line 115 "mybison.y"
                              { my_yyerror("Missing \";\"\n");}
#line 1476 "mybison.tab.c"
    break;

  case 26: /* VarDefGroup: VarDefGroup "," VarDef  */
#line 117 "mybison.y"
                               {(yyval.node) = (yyvsp[-2].node); addBroOfSon((yyvsp[-2].node), (yyvsp[-1].node)); addBroOfSon((yyvsp[-2].node), (yyvsp[0].node)); }
#line 1482 "mybison.tab.c"
    break;

  case 27: /* VarDef: Ident  */
#line 119 "mybison.y"
               {(yyval.node) = createNode("VarDef", "", (yyvsp[0].node)->line, 1, (yyvsp[0].node)); }
#line 1488 "mybison.tab.c"
    break;

  case 28: /* VarDef: Ident "=" InitVal  */
#line 120 "mybison.y"
                           {(yyval.node) = createNode("VarDef", "", (yyvsp[-2].node)->line, 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));}
#line 1494 "mybison.tab.c"
    break;

  case 29: /* VarDef: Ident "[" ConstExp error  */
#line 121 "mybison.y"
                                  {(yyval.node) = createNode("ArrayVarDef", "", (yyvsp[-3].node)->line, 2, (yyvsp[-3].node), (yyvsp[-1].node)); my_yyerror("Missing \"]\"\n");}
#line 1500 "mybison.tab.c"
    break;

  case 30: /* VarDef: Ident ArrayDef  */
#line 122 "mybison.y"
                     {(yyval.node) = createNode("VarDef", "", (yyvsp[-1].node)->line, 2, (yyvsp[-1].node), (yyvsp[0].node));}
#line 1506 "mybison.tab.c"
    break;

  case 31: /* VarDef: Ident "[" error "]"  */
#line 123 "mybison.y"
                                {(yyval.node) = createNode("ArrayVarDef", "", (yyvsp[-3].node)->line, 2, (yyvsp[-3].node), (yyvsp[0].node)); my_yyerror("Missing expression inside \"[]\"\n");}
#line 1512 "mybison.tab.c"
    break;

  case 32: /* VarDef: Ident ArrayDef "=" InitVal  */
#line 124 "mybison.y"
                                    {(yyval.node) = createNode("VarDef", "", (yyvsp[-3].node)->line, 4, (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));}
#line 1518 "mybison.tab.c"
    break;

  case 34: /* ArrayDef: ArrayDef "[" ConstExp "]"  */
#line 126 "mybison.y"
                                      {(yyval.node) = (yyvsp[-3].node), addBroOfSon((yyvsp[-3].node), (yyvsp[-2].node)); addBroOfSon((yyvsp[-3].node), (yyvsp[-1].node)); addBroOfSon((yyvsp[-3].node), (yyvsp[0].node));}
#line 1524 "mybison.tab.c"
    break;

  case 35: /* InitVal: Exp  */
#line 128 "mybison.y"
              {(yyval.node) = createNode("InitVal", "", (yyvsp[0].node)->line, 1, (yyvsp[0].node)); }
#line 1530 "mybison.tab.c"
    break;

  case 36: /* InitVal: "{" "}"  */
#line 129 "mybison.y"
                    {(yyval.node) = createNode("InitVal", "", (yyvsp[-1].node)->line, 2, (yyvsp[-1].node), (yyvsp[0].node));}
#line 1536 "mybison.tab.c"
    break;

  case 37: /* InitVal: "{" InitValGroup "}"  */
#line 130 "mybison.y"
                                 {(yyval.node) = createNode("InitVal", "", (yyvsp[-2].node)->line, 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));}
#line 1542 "mybison.tab.c"
    break;

  case 39: /* InitValGroup: InitValGroup "," InitVal  */
#line 133 "mybison.y"
                                 {(yyval.node) = (yyvsp[-2].node); addBroOfSon((yyvsp[-2].node), (yyvsp[-1].node)); addBroOfSon((yyvsp[-2].node), (yyvsp[0].node)); }
#line 1548 "mybison.tab.c"
    break;

  case 40: /* FuncDef: BType Ident "(" ")" Block  */
#line 135 "mybison.y"
                                            {(yyval.node) = createNode("FuncDef", "", (yyvsp[-4].node)->line, 5, (yyvsp[-4].node), (yyvsp[-3].node),(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));}
#line 1554 "mybison.tab.c"
    break;

  case 41: /* FuncDef: BType Ident "(" FuncFParams ")" Block  */
#line 136 "mybison.y"
                                                    {(yyval.node) = createNode("FuncDef", "", (yyvsp[-5].node)->line, 6, (yyvsp[-5].node),(yyvsp[-4].node),(yyvsp[-3].node),(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));}
#line 1560 "mybison.tab.c"
    break;

  case 42: /* FuncFParams: FuncFParam  */
#line 137 "mybison.y"
                         {(yyval.node) = createNode("FuncFParams", "", (yyvsp[0].node)->line, 1, (yyvsp[0].node));}
#line 1566 "mybison.tab.c"
    break;

  case 43: /* FuncFParams: FuncFParams "," FuncFParam  */
#line 138 "mybison.y"
                                   {(yyval.node) = (yyvsp[-2].node), addBroOfSon((yyvsp[-2].node), (yyvsp[-1].node)); addBroOfSon((yyvsp[-2].node), (yyvsp[0].node));}
#line 1572 "mybison.tab.c"
    break;

  case 44: /* FuncFParam: BType Ident  */
#line 140 "mybison.y"
                        {(yyval.node) = createNode("FuncFParam", "", (yyvsp[-1].node)->line, 2, (yyvsp[-1].node),(yyvsp[0].node));}
#line 1578 "mybison.tab.c"
    break;

  case 45: /* FuncFParam: BType Ident "[" "]"  */
#line 141 "mybison.y"
                                {(yyval.node) = createNode("FuncFParam", "", (yyvsp[-3].node)->line, 4, (yyvsp[-3].node),(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));}
#line 1584 "mybison.tab.c"
    break;

  case 46: /* FuncFParam: BType Ident "[" "]" Array  */
#line 142 "mybison.y"
                                      {(yyval.node) = createNode("FuncFParam", "", (yyvsp[-4].node)->line, 5, (yyvsp[-4].node),(yyvsp[-3].node),(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));}
#line 1590 "mybison.tab.c"
    break;

  case 48: /* Array: Array "[" Exp "]"  */
#line 144 "mybison.y"
                              {(yyval.node) = (yyvsp[-3].node), addBroOfSon((yyvsp[-3].node), (yyvsp[-2].node)); addBroOfSon((yyvsp[-3].node), (yyvsp[-1].node)); addBroOfSon((yyvsp[-3].node), (yyvsp[0].node)); }
#line 1596 "mybison.tab.c"
    break;

  case 49: /* Array: "[" error "]"  */
#line 145 "mybison.y"
                         { my_yyerror("Missing  \"]\"\n");}
#line 1602 "mybison.tab.c"
    break;

  case 50: /* Array: Array Exp error "]"  */
#line 146 "mybison.y"
                            { my_yyerror("Missing  \"]\"\n");}
#line 1608 "mybison.tab.c"
    break;

  case 51: /* Array: Array "[" error "]"  */
#line 147 "mybison.y"
                               { my_yyerror("Invalid array expression: use ',' insteadof']'\n");
                                (yyval.node)=(yyvsp[-3].node);addBroOfSon((yyvsp[-3].node),(yyvsp[-2].node));
                                }
#line 1616 "mybison.tab.c"
    break;

  case 52: /* Block: "{" "}"  */
#line 150 "mybison.y"
                      {(yyval.node) = createNode("Block", "", (yyvsp[-1].node)->line, 2, (yyvsp[-1].node),(yyvsp[0].node));}
#line 1622 "mybison.tab.c"
    break;

  case 53: /* Block: "{" BlockGroup "}"  */
#line 151 "mybison.y"
                               {(yyval.node) = createNode("Block", "", (yyvsp[-2].node)->line, 3, (yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));}
#line 1628 "mybison.tab.c"
    break;

  case 55: /* BlockGroup: BlockGroup BlockItem  */
#line 153 "mybison.y"
                           {(yyval.node) = (yyvsp[-1].node); addBroOfSon((yyvsp[-1].node), (yyvsp[0].node)); }
#line 1634 "mybison.tab.c"
    break;

  case 56: /* BlockItem: Decl  */
#line 154 "mybison.y"
                 {(yyval.node) = createNode("BlockItem", "", (yyvsp[0].node)->line, 1, (yyvsp[0].node));}
#line 1640 "mybison.tab.c"
    break;

  case 57: /* BlockItem: Stmt  */
#line 155 "mybison.y"
           {(yyval.node) = createNode("BlockItem", "", (yyvsp[0].node)->line, 1, (yyvsp[0].node));}
#line 1646 "mybison.tab.c"
    break;

  case 58: /* Stmt: LVal "=" Exp ";"  */
#line 156 "mybison.y"
                               {(yyval.node) = createNode("Stmt", "", (yyvsp[-3].node)->line, 4, (yyvsp[-3].node),(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));}
#line 1652 "mybison.tab.c"
    break;

  case 59: /* Stmt: ";"  */
#line 157 "mybison.y"
                  {(yyval.node) = createNode("Stmt", "", (yyvsp[0].node)->line, 1, (yyvsp[0].node));}
#line 1658 "mybison.tab.c"
    break;

  case 60: /* Stmt: Exp ";"  */
#line 158 "mybison.y"
                     {(yyval.node) = createNode("Stmt", "", (yyvsp[-1].node)->line, 2, (yyvsp[-1].node),(yyvsp[0].node));}
#line 1664 "mybison.tab.c"
    break;

  case 61: /* Stmt: Block  */
#line 159 "mybison.y"
                {(yyval.node) = createNode("Stmt", "", (yyvsp[0].node)->line, 1, (yyvsp[0].node));}
#line 1670 "mybison.tab.c"
    break;

  case 62: /* Stmt: IF "(" Cond ")" Stmt  */
#line 160 "mybison.y"
                                       {(yyval.node) = createNode("Stmt", "", (yyvsp[-4].node)->line, 5, (yyvsp[-4].node),(yyvsp[-3].node),(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));}
#line 1676 "mybison.tab.c"
    break;

  case 63: /* Stmt: IF "(" Cond ")" Stmt ELSE Stmt  */
#line 161 "mybison.y"
                                                 {(yyval.node) = createNode("Stmt", "", (yyvsp[-6].node)->line, 7, (yyvsp[-6].node),(yyvsp[-5].node),(yyvsp[-4].node),(yyvsp[-3].node),(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));}
#line 1682 "mybison.tab.c"
    break;

  case 64: /* Stmt: WHILE "(" Cond ")" Stmt  */
#line 162 "mybison.y"
                                          {(yyval.node) = createNode("Stmt", "", (yyvsp[-4].node)->line, 5, (yyvsp[-4].node),(yyvsp[-3].node),(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));}
#line 1688 "mybison.tab.c"
    break;

  case 65: /* Stmt: BREAK ";"  */
#line 163 "mybison.y"
                       {(yyval.node) = createNode("Stmt", "", (yyvsp[-1].node)->line, 2, (yyvsp[-1].node),(yyvsp[0].node));}
#line 1694 "mybison.tab.c"
    break;

  case 66: /* Stmt: CONTINUE ";"  */
#line 164 "mybison.y"
                          {(yyval.node) = createNode("Stmt", "", (yyvsp[-1].node)->line, 2, (yyvsp[-1].node),(yyvsp[0].node));}
#line 1700 "mybison.tab.c"
    break;

  case 67: /* Stmt: RETURN ";"  */
#line 165 "mybison.y"
                        {(yyval.node) = createNode("Stmt", "", (yyvsp[-1].node)->line, 2, (yyvsp[-1].node),(yyvsp[0].node));}
#line 1706 "mybison.tab.c"
    break;

  case 68: /* Stmt: RETURN Exp ";"  */
#line 166 "mybison.y"
                            {(yyval.node) = createNode("Stmt", "", (yyvsp[-2].node)->line, 3, (yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));}
#line 1712 "mybison.tab.c"
    break;

  case 69: /* Stmt: Exp error  */
#line 167 "mybison.y"
                    {my_yyerror("Missing  \";\"\n");}
#line 1718 "mybison.tab.c"
    break;

  case 70: /* Stmt: Block error  */
#line 168 "mybison.y"
                      {my_yyerror("Missing  \";\"\n");}
#line 1724 "mybison.tab.c"
    break;

  case 71: /* Stmt: LVal "=" Exp error  */
#line 169 "mybison.y"
                                {my_yyerror("Missing  \";\"\n");}
#line 1730 "mybison.tab.c"
    break;

  case 72: /* Stmt: BREAK error  */
#line 170 "mybison.y"
                      {my_yyerror("Missing  \";\"\n");}
#line 1736 "mybison.tab.c"
    break;

  case 73: /* Stmt: RETURN Exp error  */
#line 171 "mybison.y"
                           {my_yyerror("Missing  \";\"\n");}
#line 1742 "mybison.tab.c"
    break;

  case 74: /* Stmt: CONTINUE error  */
#line 172 "mybison.y"
                         {my_yyerror("Missing  \";\"\n");}
#line 1748 "mybison.tab.c"
    break;

  case 75: /* Stmt: RETURN error  */
#line 173 "mybison.y"
                       {my_yyerror("Missing  \";\"\n");}
#line 1754 "mybison.tab.c"
    break;

  case 76: /* Exp: AddExp  */
#line 174 "mybison.y"
             {(yyval.node) = createNode("Exp", "", (yyvsp[0].node)->line, 1, (yyvsp[0].node)); }
#line 1760 "mybison.tab.c"
    break;

  case 77: /* Cond: LOrExp  */
#line 175 "mybison.y"
              {(yyval.node) = createNode("Cond", "", (yyvsp[0].node)->line, 1, (yyvsp[0].node)); }
#line 1766 "mybison.tab.c"
    break;

  case 78: /* LVal: Ident  */
#line 176 "mybison.y"
             {(yyval.node) = createNode("LVal", "", (yyvsp[0].node)->line, 1, (yyvsp[0].node));}
#line 1772 "mybison.tab.c"
    break;

  case 79: /* LVal: Ident Array  */
#line 177 "mybison.y"
                  {(yyval.node) = (yyvsp[-1].node); addBroOfSon((yyvsp[-1].node), (yyvsp[0].node)); }
#line 1778 "mybison.tab.c"
    break;

  case 80: /* PrimaryExp: "(" Exp ")"  */
#line 178 "mybison.y"
                                 {(yyval.node) = createNode("PrimaryExp", "", (yyvsp[-2].node)->line, 3, (yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));}
#line 1784 "mybison.tab.c"
    break;

  case 81: /* PrimaryExp: LVal  */
#line 179 "mybison.y"
                         {(yyval.node) = createNode("PrimaryExp", "", (yyvsp[0].node)->line, 1, (yyvsp[0].node));}
#line 1790 "mybison.tab.c"
    break;

  case 82: /* PrimaryExp: Number  */
#line 180 "mybison.y"
                         {(yyval.node) = createNode("PrimaryExp", "", (yyvsp[0].node)->line, 1, (yyvsp[0].node));}
#line 1796 "mybison.tab.c"
    break;

  case 83: /* Number: INTCON  */
#line 181 "mybison.y"
                {(yyval.node) = createNode("Number", "", (yyvsp[0].node)->line, 1, (yyvsp[0].node));}
#line 1802 "mybison.tab.c"
    break;

  case 84: /* Number: FLOATCON  */
#line 182 "mybison.y"
                  {(yyval.node) = createNode("Number", "", (yyvsp[0].node)->line, 1, (yyvsp[0].node));}
#line 1808 "mybison.tab.c"
    break;

  case 85: /* Number: ILLEGAL_HEX_CONST  */
#line 183 "mybison.y"
                           {}
#line 1814 "mybison.tab.c"
    break;

  case 86: /* Number: ILLEGAL_OCTAL_CONST  */
#line 184 "mybison.y"
                             {}
#line 1820 "mybison.tab.c"
    break;

  case 91: /* UnaryOp: "+"  */
#line 189 "mybison.y"
               {(yyval.node) = createNode("UnaryOp", "", (yyvsp[0].node)->line, 1, (yyvsp[0].node));}
#line 1826 "mybison.tab.c"
    break;

  case 92: /* UnaryOp: "-"  */
#line 190 "mybison.y"
              {(yyval.node) = createNode("UnaryOp", "", (yyvsp[0].node)->line, 1, (yyvsp[0].node));}
#line 1832 "mybison.tab.c"
    break;

  case 93: /* UnaryOp: "!"  */
#line 191 "mybison.y"
              {(yyval.node) = createNode("UnaryOp", "", (yyvsp[0].node)->line, 1, (yyvsp[0].node));}
#line 1838 "mybison.tab.c"
    break;

  case 94: /* FuncRParams: Exp  */
#line 192 "mybison.y"
                  {(yyval.node) = createNode("FuncRParams", "", (yyvsp[0].node)->line, 1, (yyvsp[0].node));}
#line 1844 "mybison.tab.c"
    break;

  case 95: /* FuncRParams: FuncRParams "," Exp  */
#line 193 "mybison.y"
                                {(yyval.node) = (yyvsp[-2].node), addBroOfSon((yyvsp[-2].node), (yyvsp[-1].node)); addBroOfSon((yyvsp[-2].node), (yyvsp[0].node)); }
#line 1850 "mybison.tab.c"
    break;

  case 96: /* MulExp: UnaryExp  */
#line 194 "mybison.y"
                  { (yyval.node) = createNode("MulExp", "", (yyvsp[0].node)->line, 1, (yyvsp[0].node));}
#line 1856 "mybison.tab.c"
    break;

  case 97: /* MulExp: MulExp "*" UnaryExp  */
#line 195 "mybison.y"
                             {(yyval.node) = createNode("MulExp", "", (yyvsp[-2].node)->line, 3, (yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));}
#line 1862 "mybison.tab.c"
    break;

  case 98: /* MulExp: MulExp "/" UnaryExp  */
#line 196 "mybison.y"
                             {(yyval.node) = createNode("MulExp", "", (yyvsp[-2].node)->line, 3, (yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));}
#line 1868 "mybison.tab.c"
    break;

  case 99: /* MulExp: MulExp "%" UnaryExp  */
#line 197 "mybison.y"
                             {(yyval.node) = createNode("MulExp", "", (yyvsp[-2].node)->line, 3, (yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));}
#line 1874 "mybison.tab.c"
    break;

  case 100: /* AddExp: MulExp  */
#line 198 "mybison.y"
                {(yyval.node) = createNode("AddExp", "", (yyvsp[0].node)->line, 1, (yyvsp[0].node));}
#line 1880 "mybison.tab.c"
    break;

  case 101: /* AddExp: AddExp "+" MulExp  */
#line 199 "mybison.y"
                            {(yyval.node) = createNode("AddExp", "", (yyvsp[-2].node)->line, 3, (yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));}
#line 1886 "mybison.tab.c"
    break;

  case 102: /* AddExp: AddExp "-" MulExp  */
#line 200 "mybison.y"
                           {(yyval.node) = createNode("AddExp", "", (yyvsp[-2].node)->line, 3, (yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));}
#line 1892 "mybison.tab.c"
    break;

  case 103: /* RelExp: AddExp  */
#line 201 "mybison.y"
                {(yyval.node) = createNode("RelExp", "", (yyvsp[0].node)->line, 1, (yyvsp[0].node));}
#line 1898 "mybison.tab.c"
    break;

  case 104: /* RelExp: RelExp "<" AddExp  */
#line 202 "mybison.y"
                          {(yyval.node) = createNode("RelExp", "", (yyvsp[-2].node)->line, 3, (yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));}
#line 1904 "mybison.tab.c"
    break;

  case 105: /* RelExp: RelExp ">" AddExp  */
#line 203 "mybison.y"
                         {(yyval.node) = createNode("RelExp", "", (yyvsp[-2].node)->line, 3, (yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));}
#line 1910 "mybison.tab.c"
    break;

  case 106: /* RelExp: RelExp "<=" AddExp  */
#line 204 "mybison.y"
                         {(yyval.node) = createNode("RelExp", "", (yyvsp[-2].node)->line, 3, (yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));}
#line 1916 "mybison.tab.c"
    break;

  case 107: /* RelExp: RelExp ">=" AddExp  */
#line 205 "mybison.y"
                         {(yyval.node) = createNode("RelExp", "", (yyvsp[-2].node)->line, 3, (yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));}
#line 1922 "mybison.tab.c"
    break;

  case 108: /* EqExp: RelExp  */
#line 206 "mybison.y"
               {(yyval.node) = createNode("EqExp", "", (yyvsp[0].node)->line, 1, (yyvsp[0].node));}
#line 1928 "mybison.tab.c"
    break;

  case 109: /* EqExp: EqExp "==" RelExp  */
#line 207 "mybison.y"
                      {(yyval.node) = createNode("EqExp", "", (yyvsp[-2].node)->line, 3, (yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));}
#line 1934 "mybison.tab.c"
    break;

  case 110: /* EqExp: EqExp "!=" RelExp  */
#line 208 "mybison.y"
                      {(yyval.node) = createNode("EqExp", "", (yyvsp[-2].node)->line, 3, (yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));}
#line 1940 "mybison.tab.c"
    break;

  case 111: /* LAndExp: EqExp  */
#line 209 "mybison.y"
                {(yyval.node) = createNode("LAndExp", "", (yyvsp[0].node)->line, 1, (yyvsp[0].node));}
#line 1946 "mybison.tab.c"
    break;

  case 112: /* LAndExp: LAndExp AND EqExp  */
#line 210 "mybison.y"
                        {(yyval.node) = createNode("LAndExp", "", (yyvsp[-2].node)->line, 3, (yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));}
#line 1952 "mybison.tab.c"
    break;

  case 113: /* LOrExp: LAndExp  */
#line 211 "mybison.y"
                 {(yyval.node) = createNode("LOrExp", "", (yyvsp[0].node)->line, 1, (yyvsp[0].node));}
#line 1958 "mybison.tab.c"
    break;

  case 114: /* LOrExp: LOrExp OR LAndExp  */
#line 212 "mybison.y"
                        {(yyval.node) = createNode("LOrExp", "", (yyvsp[-2].node)->line, 3, (yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));}
#line 1964 "mybison.tab.c"
    break;

  case 115: /* ConstExp: AddExp  */
#line 213 "mybison.y"
                  {(yyval.node) = createNode("ConstExp", "", (yyvsp[0].node)->line, 1, (yyvsp[0].node));}
#line 1970 "mybison.tab.c"
    break;


#line 1974 "mybison.tab.c"

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

#line 215 "mybison.y"


void my_yyerror(char* str){
    failed = 1;
    if(lastLine != yylineno){
        printf("\033[1;31mError Type B at Line %d : %s\033[0m", yylineno, str);
        lastLine = yylineno;
    }

}

void yyerror(char *str){
    return;
}

struct Node* createNode(char* value, char* text, int line, int num, ...){
    Node* node = (Node*)malloc(sizeof(Node));
    node->value = value;
    node->text = text;
    node->line = line;
    node->sonNodes = NULL;
    node->broNodes = NULL;
    int i;
    va_list args;
    va_start(args, num);
    for(i = 0; i < num; i++){
        Node* firstSon;
        Node* son;
        son = va_arg(args, Node*);
        if(i == 0){
            firstSon = son;
            node->sonNodes = son;
        }
        else{
            firstSon->broNodes = son;
            firstSon = son;
        }
    }
    va_end(args);
    return node;
}

void printTree(Node* root, int space){
    int i;
    for(i = 0; i < space; i++){
        printf("  ");
    }
    int flag = 0;
    for(i = 0; i < 37; i++){
        if(strcmp(root->value, print_leaf[i]) == 0){
            flag = 1;
            break;
        }
    }
    if(flag == 1){
        if(strcmp(root->value, "INTCON") == 0 || strcmp(root->value, "FLOATCON") == 0){
			char str[20];
			preHandle(root->text,str);
			printf("\033[1;32m%s:\033[0m %s\n", root->value, str);
			
	}else if(strcmp(root->value, "INT") == 0 || strcmp(root->value, "FLOAT") == 0){
			printf("\033[1;32mType:\033[0m %s\n", root->value);
	}else if(strcmp(root->value, "Ident") == 0){ 
			printf("\033[1;32mIdent:\033[0m %s\n", root->text);
	}else if(strcmp(root->value, "PLUS") == 0 || strcmp(root->value, "SUB") == 0 || strcmp(root->value, "MUL") == 0 || strcmp(root->value, "DIV") == 0 || strcmp(root->value, "MOD") == 0 ){
			printf("\033[1;32m%s:\033[0m %s\n", root->value, root->text);
	}else{
			printf("\033[1;35m%s\033[0m\n", root->value);
		}
    }else {
	printf("\033[1;35m%s\033[0m (%d)\n", root->value, root->line); 
    }
    Node* son;
    Node* bro;
    son = root->sonNodes;
    if(son != NULL){
        printTree(son, space+1);
        bro = son->broNodes;
        while(bro != NULL){
            printTree(bro, space+1);
            bro = bro->broNodes;
        }
    }
    free(root);
}

void addBroOfSon(Node* root, Node* bro){
	Node* p;
	p = root->sonNodes;
	if(p == NULL){
		root->sonNodes = bro;
		return;
	}
	while(p != NULL && p->broNodes != NULL){
		p = p->broNodes;
	}
	if(p != NULL){
		p->broNodes = bro;
	}
}

void preHandle(char* text, char* str){
	const char* prefixHex = "0x";
	const char* prefixOctal = "0";
	char* endptr;
	char decimalStr[20];
	// 如果是十六进制
	if(strncmp(text, prefixHex, strlen(prefixHex)) == 0){
		long int decimal = strtol(text+2, &endptr, 16);
		sprintf(decimalStr, "%ld", decimal);
	}else if(strncmp(text, prefixOctal, strlen(prefixOctal)) == 0){
		long int decimal = strtol(text+1, &endptr, 8);
		sprintf(decimalStr, "%ld", decimal);
	}else{
		strcpy(decimalStr, text);
	}
	strcpy(str, decimalStr);
}

int main(int argc, char** argv){
    yylineno = 1;
    extern FILE* yyin;
    if(argc == 2){
        if((yyin = fopen(argv[1], "r")) == NULL){
            printf("Can't open file %s\n", argv[1]);
            return 1;
        }
    }
    yyparse();

	fclose(yyin);
    return 0;
}

