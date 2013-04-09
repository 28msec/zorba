/* A Bison parser, made by GNU Bison 2.7.  */

/* Skeleton implementation for Bison LALR(1) parsers in C++
   
      Copyright (C) 2002-2012 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

// Take the name prefix into account.
#define yylex   zorbalex

/* First part of user declarations.  */
/* Line 279 of lalr1.cc  */
#line 88 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"


#include "common/common.h"

#ifdef WIN32
#pragma warning(disable: 4786)
#endif

#include "compiler/parsetree/parsenodes.h"
#include "compiler/parser/parse_constants.h"
#include "compiler/api/compilercb.h"
#include "store/api/update_consts.h"
#include "compiler/parser/jsoniq_driver.h"
#include "compiler/parser/parser_helpers.h"

#define SYMTAB( n ) driver.symtab.get( (off_t)n )
#define SYMTAB_PUT( s ) driver.symtab.put( s )
#define LOC( p ) driver.createQueryLoc( p )


#define YYDEBUG 1

using namespace std;
using namespace zorba;


/* Line 279 of lalr1.cc  */
#line 67 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"


#include "jsoniq_parser.hpp"

/* User implementation prologue.  */
/* Line 285 of lalr1.cc  */
#line 917 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"

// HACK to trigger rchandle release: rchandles are freed when refcount == 0
// (not <= 0); but Bison never increments the refcount, so we do it manually...
template<typename T> inline void release_hack( T *ref ) {
    if ( ref ) {
        RCHelper::addReference( ref );
        RCHelper::removeReference( ref );
    }
}
/* Line 285 of lalr1.cc  */
#line 1053 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"

#include "compiler/parser/jsoniq_scanner.h"

#undef yylex
#define yylex driver.lexer->lex


/* Line 285 of lalr1.cc  */
#line 94 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"


# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* FIXME: INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (/*CONSTCOND*/ false)
# endif


/* Suppress unused-variable warnings by "using" E.  */
#define YYUSE(e) ((void) (e))

/* Enable debugging if requested.  */
#if YYDEBUG

/* A pseudo ostream that takes yydebug_ into account.  */
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)	\
do {							\
  if (yydebug_)						\
    {							\
      *yycdebug_ << Title << ' ';			\
      yy_symbol_print_ ((Type), (Value), (Location));	\
      *yycdebug_ << std::endl;				\
    }							\
} while (false)

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug_)				\
    yy_reduce_print_ (Rule);		\
} while (false)

# define YY_STACK_PRINT()		\
do {					\
  if (yydebug_)				\
    yystack_print_ ();			\
} while (false)

#else /* !YYDEBUG */

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Type, Value, Location) YYUSE(Type)
# define YY_REDUCE_PRINT(Rule)        static_cast<void>(0)
# define YY_STACK_PRINT()             static_cast<void>(0)

#endif /* !YYDEBUG */

#define yyerrok		(yyerrstatus_ = 0)
#define yyclearin	(yychar = yyempty_)

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)


namespace zorba {
/* Line 353 of lalr1.cc  */
#line 189 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  jsoniq_parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr = "";
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              /* Fall through.  */
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }


  /// Build a parser object.
  jsoniq_parser::jsoniq_parser (jsoniq_driver& driver_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      driver (driver_yyarg)
  {
  }

  jsoniq_parser::~jsoniq_parser ()
  {
  }

#if YYDEBUG
  /*--------------------------------.
  | Print this symbol on YYOUTPUT.  |
  `--------------------------------*/

  inline void
  jsoniq_parser::yy_symbol_value_print_ (int yytype,
			   const semantic_type* yyvaluep, const location_type* yylocationp)
  {
    YYUSE (yylocationp);
    YYUSE (yyvaluep);
    std::ostream& yyo = debug_stream ();
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    switch (yytype)
      {
         default:
	  break;
      }
  }


  void
  jsoniq_parser::yy_symbol_print_ (int yytype,
			   const semantic_type* yyvaluep, const location_type* yylocationp)
  {
    *yycdebug_ << (yytype < yyntokens_ ? "token" : "nterm")
	       << ' ' << yytname_[yytype] << " ("
	       << *yylocationp << ": ";
    yy_symbol_value_print_ (yytype, yyvaluep, yylocationp);
    *yycdebug_ << ')';
  }
#endif

  void
  jsoniq_parser::yydestruct_ (const char* yymsg,
			   int yytype, semantic_type* yyvaluep, location_type* yylocationp)
  {
    YYUSE (yylocationp);
    YYUSE (yymsg);
    YYUSE (yyvaluep);

    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

    switch (yytype)
      {
        case 112: /* "'DECIMAL'" */
/* Line 455 of lalr1.cc  */
#line 915 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { delete ((*yyvaluep).decval); };
/* Line 455 of lalr1.cc  */
#line 296 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 127: /* "'DOUBLE'" */
/* Line 455 of lalr1.cc  */
#line 914 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { delete ((*yyvaluep).dval); };
/* Line 455 of lalr1.cc  */
#line 303 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 152: /* "'INTEGER'" */
/* Line 455 of lalr1.cc  */
#line 913 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { delete ((*yyvaluep).ival); };
/* Line 455 of lalr1.cc  */
#line 310 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 346: /* VersionDecl */
/* Line 455 of lalr1.cc  */
#line 932 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 317 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 347: /* MainModule */
/* Line 455 of lalr1.cc  */
#line 932 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 324 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 348: /* LibraryModule */
/* Line 455 of lalr1.cc  */
#line 932 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 331 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 349: /* ModuleDecl */
/* Line 455 of lalr1.cc  */
#line 932 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 338 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 350: /* SIND_DeclList */
/* Line 455 of lalr1.cc  */
#line 932 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 345 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 351: /* SIND_Decl */
/* Line 455 of lalr1.cc  */
#line 932 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 352 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 352: /* Setter */
/* Line 455 of lalr1.cc  */
#line 932 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 359 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 353: /* BoundarySpaceDecl */
/* Line 455 of lalr1.cc  */
#line 932 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 366 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 354: /* DefaultCollationDecl */
/* Line 455 of lalr1.cc  */
#line 932 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 373 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 355: /* BaseURIDecl */
/* Line 455 of lalr1.cc  */
#line 932 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 380 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 356: /* ConstructionDecl */
/* Line 455 of lalr1.cc  */
#line 932 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 387 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 357: /* OrderingModeDecl */
/* Line 455 of lalr1.cc  */
#line 932 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 394 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 358: /* EmptyOrderDecl */
/* Line 455 of lalr1.cc  */
#line 932 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 401 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 359: /* CopyNamespacesDecl */
/* Line 455 of lalr1.cc  */
#line 932 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 408 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 360: /* Import */
/* Line 455 of lalr1.cc  */
#line 932 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 415 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 361: /* SchemaImport */
/* Line 455 of lalr1.cc  */
#line 932 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 422 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 362: /* URILiteralList */
/* Line 455 of lalr1.cc  */
#line 932 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 429 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 363: /* SchemaPrefix */
/* Line 455 of lalr1.cc  */
#line 932 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 436 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 364: /* ModuleImport */
/* Line 455 of lalr1.cc  */
#line 932 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 443 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 365: /* NamespaceDecl */
/* Line 455 of lalr1.cc  */
#line 932 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 450 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 366: /* DefaultNamespaceDecl */
/* Line 455 of lalr1.cc  */
#line 932 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 457 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 367: /* VFO_DeclList */
/* Line 455 of lalr1.cc  */
#line 932 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 464 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 368: /* VFO_Decl */
/* Line 455 of lalr1.cc  */
#line 932 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 471 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 369: /* DecimalFormatDecl */
/* Line 455 of lalr1.cc  */
#line 932 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 478 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 370: /* DecimalFormatParamList */
/* Line 455 of lalr1.cc  */
#line 947 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { delete ((*yyvaluep).vstrpair); };
/* Line 455 of lalr1.cc  */
#line 485 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 371: /* DecimalFormatParam */
/* Line 455 of lalr1.cc  */
#line 947 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { delete ((*yyvaluep).strpair); };
/* Line 455 of lalr1.cc  */
#line 492 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 373: /* OptionDecl */
/* Line 455 of lalr1.cc  */
#line 932 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 499 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 374: /* FTOptionDecl */
/* Line 455 of lalr1.cc  */
#line 935 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 506 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 375: /* CtxItemDecl */
/* Line 455 of lalr1.cc  */
#line 932 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 513 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 376: /* CtxItemDecl2 */
/* Line 455 of lalr1.cc  */
#line 932 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 520 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 377: /* CtxItemDecl3 */
/* Line 455 of lalr1.cc  */
#line 932 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 527 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 378: /* CtxItemDecl4 */
/* Line 455 of lalr1.cc  */
#line 932 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 534 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 379: /* VarDecl */
/* Line 455 of lalr1.cc  */
#line 932 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 541 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 380: /* VarNameAndType */
/* Line 455 of lalr1.cc  */
#line 947 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { delete ((*yyvaluep).varnametype); };
/* Line 455 of lalr1.cc  */
#line 548 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 381: /* AnnotationList */
/* Line 455 of lalr1.cc  */
#line 932 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 555 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 382: /* Annotation */
/* Line 455 of lalr1.cc  */
#line 932 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 562 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 383: /* AnnotationLiteralList */
/* Line 455 of lalr1.cc  */
#line 932 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 569 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 384: /* FunctionDecl */
/* Line 455 of lalr1.cc  */
#line 932 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 576 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 385: /* FunctionDecl2 */
/* Line 455 of lalr1.cc  */
#line 932 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 583 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 386: /* FunctionDeclSimple */
/* Line 455 of lalr1.cc  */
#line 932 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 590 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 387: /* FunctionDeclUpdating */
/* Line 455 of lalr1.cc  */
#line 932 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 597 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 388: /* FunctionSig */
/* Line 455 of lalr1.cc  */
#line 947 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { delete ((*yyvaluep).fnsig); };
/* Line 455 of lalr1.cc  */
#line 604 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 389: /* ParamList */
/* Line 455 of lalr1.cc  */
#line 932 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 611 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 390: /* Param */
/* Line 455 of lalr1.cc  */
#line 932 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 618 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 391: /* CollectionDecl */
/* Line 455 of lalr1.cc  */
#line 932 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 625 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 393: /* IndexDecl */
/* Line 455 of lalr1.cc  */
#line 932 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 632 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 394: /* IndexKeyList */
/* Line 455 of lalr1.cc  */
#line 932 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 639 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 395: /* IndexKeySpec */
/* Line 455 of lalr1.cc  */
#line 932 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 646 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 396: /* IntegrityConstraintDecl */
/* Line 455 of lalr1.cc  */
#line 932 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 653 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 397: /* QueryBody */
/* Line 455 of lalr1.cc  */
#line 944 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 660 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 398: /* StatementsAndOptionalExprTop */
/* Line 455 of lalr1.cc  */
#line 944 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 667 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 399: /* StatementsAndOptionalExpr */
/* Line 455 of lalr1.cc  */
#line 944 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 674 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 400: /* StatementsAndExpr */
/* Line 455 of lalr1.cc  */
#line 944 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 681 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 401: /* Statements */
/* Line 455 of lalr1.cc  */
#line 944 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 688 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 402: /* Statement */
/* Line 455 of lalr1.cc  */
#line 944 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 695 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 403: /* BlockStatement */
/* Line 455 of lalr1.cc  */
#line 944 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 702 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 404: /* BlockExpr */
/* Line 455 of lalr1.cc  */
#line 944 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 709 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 405: /* EnclosedStatementsAndOptionalExpr */
/* Line 455 of lalr1.cc  */
#line 944 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 716 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 406: /* VarDeclStatement */
/* Line 455 of lalr1.cc  */
#line 944 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 723 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 409: /* AssignStatement */
/* Line 455 of lalr1.cc  */
#line 944 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 730 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 410: /* ApplyStatement */
/* Line 455 of lalr1.cc  */
#line 944 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 737 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 411: /* ExitStatement */
/* Line 455 of lalr1.cc  */
#line 944 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 744 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 412: /* WhileStatement */
/* Line 455 of lalr1.cc  */
#line 944 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 751 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 413: /* FlowCtlStatement */
/* Line 455 of lalr1.cc  */
#line 944 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 758 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 414: /* FLWORStatement */
/* Line 455 of lalr1.cc  */
#line 944 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 765 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 415: /* ReturnStatement */
/* Line 455 of lalr1.cc  */
#line 944 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 772 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 416: /* IfStatement */
/* Line 455 of lalr1.cc  */
#line 944 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 779 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 417: /* TryStatement */
/* Line 455 of lalr1.cc  */
#line 944 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 786 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 418: /* CatchListStatement */
/* Line 455 of lalr1.cc  */
#line 944 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 793 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 419: /* CatchStatement */
/* Line 455 of lalr1.cc  */
#line 944 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 800 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 421: /* Expr */
/* Line 455 of lalr1.cc  */
#line 944 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 807 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 422: /* ExprSingle */
/* Line 455 of lalr1.cc  */
#line 944 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 814 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 423: /* ExprSimple */
/* Line 455 of lalr1.cc  */
#line 944 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 821 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 424: /* FLWORExpr */
/* Line 455 of lalr1.cc  */
#line 944 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 828 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 425: /* ReturnExpr */
/* Line 455 of lalr1.cc  */
#line 944 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 835 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 428: /* FLWORWinCond */
/* Line 455 of lalr1.cc  */
#line 932 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 842 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 429: /* WindowClause */
/* Line 455 of lalr1.cc  */
#line 932 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 849 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 430: /* CountClause */
/* Line 455 of lalr1.cc  */
#line 932 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 856 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 431: /* ForLetWinClause */
/* Line 455 of lalr1.cc  */
#line 932 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 863 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 433: /* FLWORClauseList */
/* Line 455 of lalr1.cc  */
#line 932 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 870 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 434: /* ForClause */
/* Line 455 of lalr1.cc  */
#line 932 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 877 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 436: /* VarInDeclList */
/* Line 455 of lalr1.cc  */
#line 932 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 884 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 437: /* VarInDecl */
/* Line 455 of lalr1.cc  */
#line 932 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 891 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 438: /* PositionalVar */
/* Line 455 of lalr1.cc  */
#line 932 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 898 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 439: /* FTScoreVar */
/* Line 455 of lalr1.cc  */
#line 935 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 905 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 440: /* LetClause */
/* Line 455 of lalr1.cc  */
#line 932 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 912 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 441: /* VarGetsDeclList */
/* Line 455 of lalr1.cc  */
#line 932 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 919 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 442: /* VarGetsDecl */
/* Line 455 of lalr1.cc  */
#line 932 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 926 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 443: /* WindowVarDecl */
/* Line 455 of lalr1.cc  */
#line 932 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 933 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 444: /* WindowVars */
/* Line 455 of lalr1.cc  */
#line 932 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 940 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 445: /* WindowVars3 */
/* Line 455 of lalr1.cc  */
#line 932 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 947 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 446: /* WindowVars2 */
/* Line 455 of lalr1.cc  */
#line 932 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 954 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 447: /* WhereClause */
/* Line 455 of lalr1.cc  */
#line 932 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 961 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 448: /* GroupByClause */
/* Line 455 of lalr1.cc  */
#line 932 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 968 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 449: /* GroupSpecList */
/* Line 455 of lalr1.cc  */
#line 932 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 975 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 450: /* GroupSpec */
/* Line 455 of lalr1.cc  */
#line 932 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 982 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 451: /* GroupCollationSpec */
/* Line 455 of lalr1.cc  */
#line 932 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 989 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 452: /* OrderByClause */
/* Line 455 of lalr1.cc  */
#line 932 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 996 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 453: /* OrderSpecList */
/* Line 455 of lalr1.cc  */
#line 932 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 1003 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 454: /* OrderSpec */
/* Line 455 of lalr1.cc  */
#line 932 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 1010 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 455: /* OrderModifier */
/* Line 455 of lalr1.cc  */
#line 932 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 1017 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 456: /* OrderDirSpec */
/* Line 455 of lalr1.cc  */
#line 932 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 1024 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 457: /* OrderEmptySpec */
/* Line 455 of lalr1.cc  */
#line 932 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 1031 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 458: /* OrderCollationSpec */
/* Line 455 of lalr1.cc  */
#line 932 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 1038 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 459: /* QuantifiedExpr */
/* Line 455 of lalr1.cc  */
#line 944 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 1045 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 460: /* QVarInDeclList */
/* Line 455 of lalr1.cc  */
#line 932 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 1052 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 461: /* QVarInDecl */
/* Line 455 of lalr1.cc  */
#line 932 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 1059 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 462: /* SwitchExpr */
/* Line 455 of lalr1.cc  */
#line 944 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 1066 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 463: /* SwitchCaseClauseList */
/* Line 455 of lalr1.cc  */
#line 932 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 1073 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 464: /* SwitchCaseClause */
/* Line 455 of lalr1.cc  */
#line 932 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 1080 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 465: /* SwitchCaseOperandList */
/* Line 455 of lalr1.cc  */
#line 932 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 1087 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 466: /* SwitchStatement */
/* Line 455 of lalr1.cc  */
#line 944 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 1094 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 469: /* TypeswitchExpr */
/* Line 455 of lalr1.cc  */
#line 944 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 1101 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 470: /* TypeswitchStatement */
/* Line 455 of lalr1.cc  */
#line 944 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 1108 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 471: /* CaseClauseList */
/* Line 455 of lalr1.cc  */
#line 932 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 1115 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 472: /* CaseClause */
/* Line 455 of lalr1.cc  */
#line 932 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 1122 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 475: /* SequenceTypeList */
/* Line 455 of lalr1.cc  */
#line 932 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 1129 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 476: /* IfExpr */
/* Line 455 of lalr1.cc  */
#line 944 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 1136 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 477: /* OrExpr */
/* Line 455 of lalr1.cc  */
#line 944 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 1143 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 478: /* AndExpr */
/* Line 455 of lalr1.cc  */
#line 944 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 1150 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 479: /* NotExpr */
/* Line 455 of lalr1.cc  */
#line 944 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 1157 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 480: /* ComparisonExpr */
/* Line 455 of lalr1.cc  */
#line 944 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 1164 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 481: /* FTContainsExpr */
/* Line 455 of lalr1.cc  */
#line 944 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 1171 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 482: /* StringConcatExpr */
/* Line 455 of lalr1.cc  */
#line 944 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 1178 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 483: /* opt_FTIgnoreOption */
/* Line 455 of lalr1.cc  */
#line 935 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 1185 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 484: /* RangeExpr */
/* Line 455 of lalr1.cc  */
#line 944 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 1192 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 485: /* AdditiveExpr */
/* Line 455 of lalr1.cc  */
#line 944 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 1199 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 486: /* MultiplicativeExpr */
/* Line 455 of lalr1.cc  */
#line 944 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 1206 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 487: /* UnionExpr */
/* Line 455 of lalr1.cc  */
#line 944 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 1213 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 488: /* IntersectExceptExpr */
/* Line 455 of lalr1.cc  */
#line 944 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 1220 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 489: /* InstanceofExpr */
/* Line 455 of lalr1.cc  */
#line 944 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 1227 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 490: /* TreatExpr */
/* Line 455 of lalr1.cc  */
#line 944 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 1234 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 491: /* CastableExpr */
/* Line 455 of lalr1.cc  */
#line 944 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 1241 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 492: /* CastExpr */
/* Line 455 of lalr1.cc  */
#line 944 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 1248 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 493: /* SingleType */
/* Line 455 of lalr1.cc  */
#line 932 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 1255 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 494: /* UnaryExpr */
/* Line 455 of lalr1.cc  */
#line 944 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 1262 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 495: /* SignList */
/* Line 455 of lalr1.cc  */
#line 932 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 1269 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 496: /* ValueExpr */
/* Line 455 of lalr1.cc  */
#line 944 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 1276 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 497: /* SimpleMapExpr */
/* Line 455 of lalr1.cc  */
#line 944 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 1283 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 498: /* ValueComp */
/* Line 455 of lalr1.cc  */
#line 932 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 1290 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 499: /* ValidateExpr */
/* Line 455 of lalr1.cc  */
#line 944 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 1297 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 500: /* ExtensionExpr */
/* Line 455 of lalr1.cc  */
#line 944 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 1304 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 501: /* Pragma_list */
/* Line 455 of lalr1.cc  */
#line 932 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 1311 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 502: /* Pragma */
/* Line 455 of lalr1.cc  */
#line 932 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 1318 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 503: /* PathExpr */
/* Line 455 of lalr1.cc  */
#line 944 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 1325 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 504: /* RelativePathExpr */
/* Line 455 of lalr1.cc  */
#line 944 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 1332 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 505: /* StepExpr */
/* Line 455 of lalr1.cc  */
#line 944 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 1339 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 506: /* NameTest */
/* Line 455 of lalr1.cc  */
#line 932 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 1346 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 507: /* Wildcard */
/* Line 455 of lalr1.cc  */
#line 932 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 1353 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 508: /* FilterExpr */
/* Line 455 of lalr1.cc  */
#line 944 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 1360 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 509: /* PredicateList */
/* Line 455 of lalr1.cc  */
#line 932 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 1367 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 510: /* Predicate */
/* Line 455 of lalr1.cc  */
#line 944 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 1374 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 511: /* PrimaryExpr */
/* Line 455 of lalr1.cc  */
#line 944 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 1381 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 512: /* Literal */
/* Line 455 of lalr1.cc  */
#line 944 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 1388 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 513: /* NumericLiteral */
/* Line 455 of lalr1.cc  */
#line 944 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 1395 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 515: /* VarRef */
/* Line 455 of lalr1.cc  */
#line 944 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 1402 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 516: /* ParenthesizedExpr */
/* Line 455 of lalr1.cc  */
#line 944 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 1409 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 517: /* ContextItemExpr */
/* Line 455 of lalr1.cc  */
#line 944 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 1416 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 518: /* OrderedExpr */
/* Line 455 of lalr1.cc  */
#line 944 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 1423 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 519: /* UnorderedExpr */
/* Line 455 of lalr1.cc  */
#line 944 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 1430 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 520: /* FunctionCall */
/* Line 455 of lalr1.cc  */
#line 944 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 1437 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 521: /* ArgList */
/* Line 455 of lalr1.cc  */
#line 932 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 1444 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 525: /* Constructor */
/* Line 455 of lalr1.cc  */
#line 944 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 1451 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 526: /* DirectConstructor */
/* Line 455 of lalr1.cc  */
#line 944 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 1458 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 527: /* DirElemConstructor */
/* Line 455 of lalr1.cc  */
#line 944 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 1465 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 528: /* DirElemContentList */
/* Line 455 of lalr1.cc  */
#line 932 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 1472 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 529: /* DirAttributeList */
/* Line 455 of lalr1.cc  */
#line 932 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 1479 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 530: /* DirAttr */
/* Line 455 of lalr1.cc  */
#line 932 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 1486 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 532: /* DirAttributeValue */
/* Line 455 of lalr1.cc  */
#line 932 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 1493 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 533: /* opt_QuoteAttrContentList */
/* Line 455 of lalr1.cc  */
#line 932 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 1500 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 534: /* QuoteAttrContentList */
/* Line 455 of lalr1.cc  */
#line 932 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 1507 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 535: /* opt_AposAttrContentList */
/* Line 455 of lalr1.cc  */
#line 932 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 1514 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 536: /* AposAttrContentList */
/* Line 455 of lalr1.cc  */
#line 932 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 1521 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 537: /* QuoteAttrValueContent */
/* Line 455 of lalr1.cc  */
#line 932 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 1528 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 538: /* AposAttrValueContent */
/* Line 455 of lalr1.cc  */
#line 932 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 1535 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 539: /* DirElemContent */
/* Line 455 of lalr1.cc  */
#line 944 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 1542 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 540: /* CommonContent */
/* Line 455 of lalr1.cc  */
#line 944 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 1549 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 541: /* DirCommentConstructor */
/* Line 455 of lalr1.cc  */
#line 944 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 1556 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 542: /* DirPIConstructor */
/* Line 455 of lalr1.cc  */
#line 944 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 1563 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 543: /* CDataSection */
/* Line 455 of lalr1.cc  */
#line 944 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 1570 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 544: /* ComputedConstructor */
/* Line 455 of lalr1.cc  */
#line 944 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 1577 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 545: /* CompDocConstructor */
/* Line 455 of lalr1.cc  */
#line 944 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 1584 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 546: /* CompElemConstructor */
/* Line 455 of lalr1.cc  */
#line 944 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 1591 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 547: /* CompAttrConstructor */
/* Line 455 of lalr1.cc  */
#line 944 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 1598 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 548: /* CompTextConstructor */
/* Line 455 of lalr1.cc  */
#line 944 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 1605 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 549: /* CompCommentConstructor */
/* Line 455 of lalr1.cc  */
#line 944 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 1612 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 550: /* CompPIConstructor */
/* Line 455 of lalr1.cc  */
#line 944 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 1619 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 551: /* CompNamespaceConstructor */
/* Line 455 of lalr1.cc  */
#line 944 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 1626 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 552: /* TypeDeclaration */
/* Line 455 of lalr1.cc  */
#line 932 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 1633 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 553: /* SequenceType */
/* Line 455 of lalr1.cc  */
#line 932 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 1640 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 554: /* OccurrenceIndicator */
/* Line 455 of lalr1.cc  */
#line 932 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 1647 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 555: /* ItemType */
/* Line 455 of lalr1.cc  */
#line 932 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 1654 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 556: /* TypeList */
/* Line 455 of lalr1.cc  */
#line 932 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 1661 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 557: /* GeneralizedAtomicType */
/* Line 455 of lalr1.cc  */
#line 932 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 1668 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 558: /* SimpleType */
/* Line 455 of lalr1.cc  */
#line 932 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 1675 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 559: /* KindTest */
/* Line 455 of lalr1.cc  */
#line 932 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 1682 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 560: /* AnyKindTest */
/* Line 455 of lalr1.cc  */
#line 932 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 1689 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 561: /* DocumentTest */
/* Line 455 of lalr1.cc  */
#line 932 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 1696 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 562: /* NamespaceTest */
/* Line 455 of lalr1.cc  */
#line 932 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 1703 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 563: /* TextTest */
/* Line 455 of lalr1.cc  */
#line 932 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 1710 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 564: /* CommentTest */
/* Line 455 of lalr1.cc  */
#line 932 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 1717 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 565: /* PITest */
/* Line 455 of lalr1.cc  */
#line 932 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 1724 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 566: /* AttributeTest */
/* Line 455 of lalr1.cc  */
#line 932 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 1731 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 567: /* SchemaAttributeTest */
/* Line 455 of lalr1.cc  */
#line 932 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 1738 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 568: /* ElementTest */
/* Line 455 of lalr1.cc  */
#line 932 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 1745 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 569: /* SchemaElementTest */
/* Line 455 of lalr1.cc  */
#line 932 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 1752 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 570: /* TypeName */
/* Line 455 of lalr1.cc  */
#line 932 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 1759 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 571: /* TypeName_WITH_HOOK */
/* Line 455 of lalr1.cc  */
#line 932 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 1766 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 572: /* StringLiteral */
/* Line 455 of lalr1.cc  */
#line 944 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 1773 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 574: /* AnyFunctionTest */
/* Line 455 of lalr1.cc  */
#line 932 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 1780 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 575: /* TypedFunctionTest */
/* Line 455 of lalr1.cc  */
#line 932 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 1787 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 578: /* InsertExpr */
/* Line 455 of lalr1.cc  */
#line 944 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 1794 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 579: /* DeleteExpr */
/* Line 455 of lalr1.cc  */
#line 944 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 1801 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 580: /* ReplaceExpr */
/* Line 455 of lalr1.cc  */
#line 944 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 1808 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 581: /* RenameExpr */
/* Line 455 of lalr1.cc  */
#line 944 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 1815 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 582: /* TransformExpr */
/* Line 455 of lalr1.cc  */
#line 944 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 1822 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 583: /* VarNameList */
/* Line 455 of lalr1.cc  */
#line 944 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 1829 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 584: /* VarNameDecl */
/* Line 455 of lalr1.cc  */
#line 944 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 1836 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 585: /* TryExpr */
/* Line 455 of lalr1.cc  */
#line 944 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 1843 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 586: /* CatchListExpr */
/* Line 455 of lalr1.cc  */
#line 944 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 1850 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 587: /* CatchExpr */
/* Line 455 of lalr1.cc  */
#line 944 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 1857 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 588: /* BracedExpr */
/* Line 455 of lalr1.cc  */
#line 944 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 1864 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 589: /* NameTestList */
/* Line 455 of lalr1.cc  */
#line 947 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { delete ((*yyvaluep).name_test_list); };
/* Line 455 of lalr1.cc  */
#line 1871 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 590: /* FTSelection */
/* Line 455 of lalr1.cc  */
#line 935 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 1878 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 593: /* FTOr */
/* Line 455 of lalr1.cc  */
#line 935 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 1885 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 594: /* FTAnd */
/* Line 455 of lalr1.cc  */
#line 935 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 1892 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 595: /* FTMildNot */
/* Line 455 of lalr1.cc  */
#line 935 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 1899 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 596: /* FTUnaryNot */
/* Line 455 of lalr1.cc  */
#line 935 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 1906 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 597: /* FTPrimaryWithOptions */
/* Line 455 of lalr1.cc  */
#line 935 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 1913 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 598: /* opt_FTMatchOptions */
/* Line 455 of lalr1.cc  */
#line 935 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 1920 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 600: /* FTWeight */
/* Line 455 of lalr1.cc  */
#line 935 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 1927 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 601: /* FTPrimary */
/* Line 455 of lalr1.cc  */
#line 935 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 1934 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 602: /* opt_FTTimes */
/* Line 455 of lalr1.cc  */
#line 935 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 1941 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 603: /* FTExtensionSelection */
/* Line 455 of lalr1.cc  */
#line 935 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 1948 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 605: /* FTWords */
/* Line 455 of lalr1.cc  */
#line 935 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 1955 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 606: /* FTWordsValue */
/* Line 455 of lalr1.cc  */
#line 935 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 1962 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 608: /* FTAnyallOption */
/* Line 455 of lalr1.cc  */
#line 935 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 1969 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 611: /* FTPosFilter */
/* Line 455 of lalr1.cc  */
#line 935 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 1976 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 612: /* FTOrder */
/* Line 455 of lalr1.cc  */
#line 935 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 1983 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 613: /* FTWindow */
/* Line 455 of lalr1.cc  */
#line 935 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 1990 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 614: /* FTDistance */
/* Line 455 of lalr1.cc  */
#line 935 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 1997 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 615: /* FTUnit */
/* Line 455 of lalr1.cc  */
#line 935 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 2004 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 616: /* FTMatchOptions */
/* Line 455 of lalr1.cc  */
#line 935 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 2011 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 617: /* FTMatchOption */
/* Line 455 of lalr1.cc  */
#line 935 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 2018 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 618: /* FTCaseOption */
/* Line 455 of lalr1.cc  */
#line 935 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 2025 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 619: /* FTDiacriticsOption */
/* Line 455 of lalr1.cc  */
#line 935 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 2032 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 620: /* FTExtensionOption */
/* Line 455 of lalr1.cc  */
#line 935 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 2039 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 621: /* FTStemOption */
/* Line 455 of lalr1.cc  */
#line 935 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 2046 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 622: /* FTThesaurusOption */
/* Line 455 of lalr1.cc  */
#line 935 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 2053 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 626: /* FTThesaurusID */
/* Line 455 of lalr1.cc  */
#line 935 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 2060 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 629: /* FTStopWordOption */
/* Line 455 of lalr1.cc  */
#line 935 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 2067 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 630: /* FTStopWords */
/* Line 455 of lalr1.cc  */
#line 935 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 2074 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 634: /* FTStopWordsInclExcl */
/* Line 455 of lalr1.cc  */
#line 935 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 2081 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 635: /* FTLanguageOption */
/* Line 455 of lalr1.cc  */
#line 935 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 2088 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 636: /* FTWildCardOption */
/* Line 455 of lalr1.cc  */
#line 935 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 2095 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 637: /* FTContent */
/* Line 455 of lalr1.cc  */
#line 935 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 2102 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 638: /* FTTimes */
/* Line 455 of lalr1.cc  */
#line 935 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 2109 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 639: /* FTRange */
/* Line 455 of lalr1.cc  */
#line 935 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 2116 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 640: /* FTScope */
/* Line 455 of lalr1.cc  */
#line 935 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 2123 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 641: /* FTBigUnit */
/* Line 455 of lalr1.cc  */
#line 935 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 2130 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 642: /* FTIgnoreOption */
/* Line 455 of lalr1.cc  */
#line 935 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 2137 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 643: /* JSONArrayConstructor */
/* Line 455 of lalr1.cc  */
#line 938 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 2144 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 644: /* JSONSimpleObjectUnion */
/* Line 455 of lalr1.cc  */
#line 938 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 2151 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 645: /* JSONAccumulatorObjectUnion */
/* Line 455 of lalr1.cc  */
#line 938 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 2158 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 646: /* JSONObjectConstructor */
/* Line 455 of lalr1.cc  */
#line 938 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 2165 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 647: /* JSONPairList */
/* Line 455 of lalr1.cc  */
#line 938 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 2172 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 648: /* JSONInsertExpr */
/* Line 455 of lalr1.cc  */
#line 938 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 2179 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 649: /* JSONAppendExpr */
/* Line 455 of lalr1.cc  */
#line 938 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 2186 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 650: /* JSONDeleteExpr */
/* Line 455 of lalr1.cc  */
#line 938 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 2193 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 651: /* JSONRenameExpr */
/* Line 455 of lalr1.cc  */
#line 938 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 2200 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 652: /* JSONReplaceExpr */
/* Line 455 of lalr1.cc  */
#line 938 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 2207 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 659: /* QNAME */
/* Line 455 of lalr1.cc  */
#line 944 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 2214 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 660: /* FUNCTION_NAME */
/* Line 455 of lalr1.cc  */
#line 944 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 2221 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 661: /* EQNAME */
/* Line 455 of lalr1.cc  */
#line 944 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 2228 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;

	default:
	  break;
      }
  }

  void
  jsoniq_parser::yypop_ (unsigned int n)
  {
    yystate_stack_.pop (n);
    yysemantic_stack_.pop (n);
    yylocation_stack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  jsoniq_parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  jsoniq_parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  jsoniq_parser::debug_level_type
  jsoniq_parser::debug_level () const
  {
    return yydebug_;
  }

  void
  jsoniq_parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif

  inline bool
  jsoniq_parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  inline bool
  jsoniq_parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  jsoniq_parser::parse ()
  {
    /// Lookahead and lookahead in internal form.
    int yychar = yyempty_;
    int yytoken = 0;

    // State.
    int yyn;
    int yylen = 0;
    int yystate = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// Semantic value of the lookahead.
    static semantic_type yyval_default;
    semantic_type yylval = yyval_default;
    /// Location of the lookahead.
    location_type yylloc;
    /// The locations where the error started and ended.
    location_type yyerror_range[3];

    /// $$.
    semantic_type yyval;
    /// @$.
    location_type yyloc;

    int yyresult;

    // FIXME: This shoud be completely indented.  It is not yet to
    // avoid gratuitous conflicts when merging into the master branch.
    try
      {
    YYCDEBUG << "Starting parse" << std::endl;


/* User initialization code.  */
/* Line 545 of lalr1.cc  */
#line 133 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
{
    yylloc.begin.filename = yylloc.end.filename = &(driver.theFilename2);
}
/* Line 545 of lalr1.cc  */
#line 2328 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"

    /* Initialize the stacks.  The initial state will be pushed in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystate_stack_ = state_stack_type (0);
    yysemantic_stack_ = semantic_stack_type (0);
    yylocation_stack_ = location_stack_type (0);
    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yylloc);

    /* New state.  */
  yynewstate:
    yystate_stack_.push (yystate);
    YYCDEBUG << "Entering state " << yystate << std::endl;

    /* Accept?  */
    if (yystate == yyfinal_)
      goto yyacceptlab;

    goto yybackup;

    /* Backup.  */
  yybackup:

    /* Try to take a decision without lookahead.  */
    yyn = yypact_[yystate];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    /* Read a lookahead token.  */
    if (yychar == yyempty_)
      {
        YYCDEBUG << "Reading a token: ";
        yychar = yylex (&yylval, &yylloc);
      }

    /* Convert token to internal form.  */
    if (yychar <= yyeof_)
      {
	yychar = yytoken = yyeof_;
	YYCDEBUG << "Now at end of input." << std::endl;
      }
    else
      {
	yytoken = yytranslate_ (yychar);
	YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
      }

    /* If the proper action on seeing token YYTOKEN is to reduce or to
       detect an error, take that action.  */
    yyn += yytoken;
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yytoken)
      goto yydefault;

    /* Reduce or error.  */
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
	if (yy_table_value_is_error_ (yyn))
	  goto yyerrlab;
	yyn = -yyn;
	goto yyreduce;
      }

    /* Shift the lookahead token.  */
    YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

    /* Discard the token being shifted.  */
    yychar = yyempty_;

    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yylloc);

    /* Count tokens shifted since error; after three, turn off error
       status.  */
    if (yyerrstatus_)
      --yyerrstatus_;

    yystate = yyn;
    goto yynewstate;

  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystate];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;

  /*-----------------------------.
  | yyreduce -- Do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    /* If YYLEN is nonzero, implement the default value of the action:
       `$$ = $1'.  Otherwise, use the top of the stack.

       Otherwise, the following line sets YYVAL to garbage.
       This behavior is undocumented and Bison
       users should not rely upon it.  */
    if (yylen)
      yyval = yysemantic_stack_[yylen - 1];
    else
      yyval = yysemantic_stack_[0];

    // Compute the default @$.
    {
      slice<location_type, location_stack_type> slice (yylocation_stack_, yylen);
      YYLLOC_DEFAULT (yyloc, slice, yylen);
    }

    // Perform the reduction.
    YY_REDUCE_PRINT (yyn);
    switch (yyn)
      {
          case 3:
/* Line 670 of lalr1.cc  */
#line 1071 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      }
    break;

  case 4:
/* Line 670 of lalr1.cc  */
#line 1075 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      }
    break;

  case 5:
/* Line 670 of lalr1.cc  */
#line 1079 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      }
    break;

  case 6:
/* Line 670 of lalr1.cc  */
#line 1087 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.node) = NULL;
      }
    break;

  case 7:
/* Line 670 of lalr1.cc  */
#line 1093 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.node) = NULL; YYABORT;
      }
    break;

  case 8:
/* Line 670 of lalr1.cc  */
#line 1097 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.node) = NULL; YYABORT;
      }
    break;

  case 9:
/* Line 670 of lalr1.cc  */
#line 1106 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 10:
/* Line 670 of lalr1.cc  */
#line 1112 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      MainModule* mm = dynamic_cast<MainModule*>((yysemantic_stack_[(2) - (2)].node));
      mm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 11:
/* Line 670 of lalr1.cc  */
#line 1120 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 12:
/* Line 670 of lalr1.cc  */
#line 1126 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      LibraryModule* lm = dynamic_cast<LibraryModule*>((yysemantic_stack_[(2) - (2)].node));
      lm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 13:
/* Line 670 of lalr1.cc  */
#line 1137 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), "utf-8" );
    }
    break;

  case 14:
/* Line 670 of lalr1.cc  */
#line 1142 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );
    }
    break;

  case 15:
/* Line 670 of lalr1.cc  */
#line 1146 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), "utf-8", VersionDecl::jsoniq );
    }
    break;

  case 16:
/* Line 670 of lalr1.cc  */
#line 1151 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new VersionDecl(
        LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)), VersionDecl::jsoniq );
    }
    break;

  case 17:
/* Line 670 of lalr1.cc  */
#line 1160 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (1)].node)), NULL);

      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(3) - (3)].expr)), prolog);
    }
    break;

  case 18:
/* Line 670 of lalr1.cc  */
#line 1167 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (1)].node)));

      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(3) - (3)].expr)), prolog);
    }
    break;

  case 19:
/* Line 670 of lalr1.cc  */
#line 1174 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)),
                                  static_cast<SIND_DeclList*>((yysemantic_stack_[(5) - (1)].node)),
                                  static_cast<VFO_DeclList*>((yysemantic_stack_[(5) - (3)].node)));

      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(5) - (5)].expr)), prolog);
    }
    break;

  case 20:
/* Line 670 of lalr1.cc  */
#line 1183 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new MainModule( LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(1) - (1)].expr)), NULL );
    }
    break;

  case 21:
/* Line 670 of lalr1.cc  */
#line 1190 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].expr); // to prevent the Bison warning
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after statement.");
      YYERROR;
    }
    break;

  case 22:
/* Line 670 of lalr1.cc  */
#line 1198 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].expr); // to prevent the Bison warning
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 23:
/* Line 670 of lalr1.cc  */
#line 1206 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(5) - (1)].node); (yyval.node) = (yysemantic_stack_[(5) - (3)].node); (yyval.node) = (yysemantic_stack_[(5) - (5)].expr); // to prevent the Bison warning
      (yylocation_stack_[(5) - (3)]).step();
      error((yylocation_stack_[(5) - (3)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 24:
/* Line 670 of lalr1.cc  */
#line 1214 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(5) - (1)].node); (yyval.node) = (yysemantic_stack_[(5) - (3)].node); (yyval.node) = (yysemantic_stack_[(5) - (5)].expr); // to prevent the Bison warning
      (yylocation_stack_[(5) - (1)]).step();
      error((yylocation_stack_[(5) - (1)]), "syntax error, missing semicolon \";\" after statement.");
      YYERROR;
    }
    break;

  case 25:
/* Line 670 of lalr1.cc  */
#line 1225 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(1) - (1)].node)), NULL);
    }
    break;

  case 26:
/* Line 670 of lalr1.cc  */
#line 1230 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (2)].node)), NULL);

      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(3) - (1)].node)), prolog);
    }
    break;

  case 27:
/* Line 670 of lalr1.cc  */
#line 1237 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (2)].node)));

      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(3) - (1)].node)), prolog);
    }
    break;

  case 28:
/* Line 670 of lalr1.cc  */
#line 1244 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)),
                                  static_cast<SIND_DeclList*>((yysemantic_stack_[(5) - (2)].node)),
                                  static_cast<VFO_DeclList*>((yysemantic_stack_[(5) - (4)].node)));

      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(5) - (1)].node)), prolog);
    }
    break;

  case 29:
/* Line 670 of lalr1.cc  */
#line 1256 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new ModuleDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );

      dynamic_cast<ModuleDecl*>((yyval.node))->setComment( SYMTAB((yysemantic_stack_[(6) - (1)].sval)) );
    }
    break;

  case 30:
/* Line 670 of lalr1.cc  */
#line 1266 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      SIND_DeclList *sdl = new SIND_DeclList( LOC((yyloc)) );
      sdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
      (yyval.node) = sdl;
    }
    break;

  case 31:
/* Line 670 of lalr1.cc  */
#line 1273 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      ((SIND_DeclList*)(yysemantic_stack_[(3) - (1)].node))->push_back( (yysemantic_stack_[(3) - (3)].node) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 32:
/* Line 670 of lalr1.cc  */
#line 1280 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      // error
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].node); // to prevent the Bison warning
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 46:
/* Line 670 of lalr1.cc  */
#line 1315 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new BoundarySpaceDecl(LOC((yyloc)), StaticContextConsts::preserve_space);
    }
    break;

  case 47:
/* Line 670 of lalr1.cc  */
#line 1320 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new BoundarySpaceDecl(LOC((yyloc)), StaticContextConsts::strip_space);
    }
    break;

  case 48:
/* Line 670 of lalr1.cc  */
#line 1328 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DefaultCollationDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (4)].sval)) );
    }
    break;

  case 49:
/* Line 670 of lalr1.cc  */
#line 1336 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new BaseURIDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
    }
    break;

  case 50:
/* Line 670 of lalr1.cc  */
#line 1344 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new ConstructionDecl(LOC((yyloc)), StaticContextConsts::cons_preserve);
    }
    break;

  case 51:
/* Line 670 of lalr1.cc  */
#line 1349 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new ConstructionDecl(LOC((yyloc)), StaticContextConsts::cons_strip);
    }
    break;

  case 52:
/* Line 670 of lalr1.cc  */
#line 1357 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new OrderingModeDecl(LOC((yyloc)), StaticContextConsts::ordered);
    }
    break;

  case 53:
/* Line 670 of lalr1.cc  */
#line 1362 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new OrderingModeDecl(LOC((yyloc)), StaticContextConsts::unordered);
    }
    break;

  case 54:
/* Line 670 of lalr1.cc  */
#line 1370 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new EmptyOrderDecl(LOC((yyloc)), StaticContextConsts::empty_greatest);
    }
    break;

  case 55:
/* Line 670 of lalr1.cc  */
#line 1375 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new EmptyOrderDecl(LOC((yyloc)), StaticContextConsts::empty_least);
    }
    break;

  case 56:
/* Line 670 of lalr1.cc  */
#line 1383 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)), true, true);
    }
    break;

  case 57:
/* Line 670 of lalr1.cc  */
#line 1388 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)), true, false);
    }
    break;

  case 58:
/* Line 670 of lalr1.cc  */
#line 1393 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)), false, true);
    }
    break;

  case 59:
/* Line 670 of lalr1.cc  */
#line 1398 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)), false, false);
    }
    break;

  case 62:
/* Line 670 of lalr1.cc  */
#line 1411 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yyval.node); // to prevent the Bison warning
      error((yylocation_stack_[(3) - (2)]), "syntax error, \"import\" should be followed by either \"schema\" or \"module\".");
      YYERROR;
    }
    break;

  case 63:
/* Line 670 of lalr1.cc  */
#line 1421 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SchemaImport( LOC((yyloc)), NULL, SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL );
    }
    break;

  case 64:
/* Line 670 of lalr1.cc  */
#line 1426 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(4) - (3)].node)),
                            SYMTAB((yysemantic_stack_[(4) - (4)].sval)),
                            NULL);
    }
    break;

  case 65:
/* Line 670 of lalr1.cc  */
#line 1434 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            NULL,
                            SYMTAB((yysemantic_stack_[(5) - (3)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 66:
/* Line 670 of lalr1.cc  */
#line 1442 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(6) - (3)].node)),
                            SYMTAB((yysemantic_stack_[(6) - (4)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(6) - (6)].node)));
    }
    break;

  case 67:
/* Line 670 of lalr1.cc  */
#line 1453 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      URILiteralList *ull = new URILiteralList( LOC((yyloc)));
      ull->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
      (yyval.node) = ull;
    }
    break;

  case 68:
/* Line 670 of lalr1.cc  */
#line 1460 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      if ( URILiteralList *ull = dynamic_cast<URILiteralList*>((yysemantic_stack_[(3) - (1)].node)) )
        ull->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );

      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 69:
/* Line 670 of lalr1.cc  */
#line 1471 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SchemaPrefix( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 70:
/* Line 670 of lalr1.cc  */
#line 1476 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SchemaPrefix( LOC((yyloc)), true );
    }
    break;

  case 71:
/* Line 670 of lalr1.cc  */
#line 1484 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL);

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(3) - (2)].sval)));
    }
    break;

  case 72:
/* Line 670 of lalr1.cc  */
#line 1491 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (4)].sval)), SYMTAB((yysemantic_stack_[(6) - (6)].sval)), NULL);

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(6) - (2)].sval)));
    }
    break;

  case 73:
/* Line 670 of lalr1.cc  */
#line 1498 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)),
                            SYMTAB((yysemantic_stack_[(5) - (3)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(5) - (2)].sval)));
    }
    break;

  case 74:
/* Line 670 of lalr1.cc  */
#line 1507 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)),
                            SYMTAB((yysemantic_stack_[(8) - (4)].sval)),
                            SYMTAB((yysemantic_stack_[(8) - (6)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(8) - (8)].node)));

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(8) - (2)].sval)));
    }
    break;

  case 75:
/* Line 670 of lalr1.cc  */
#line 1520 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new NamespaceDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(5) - (3)].sval)), SYMTAB((yysemantic_stack_[(5) - (5)].sval)) );
    }
    break;

  case 76:
/* Line 670 of lalr1.cc  */
#line 1528 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DefaultNamespaceDecl(LOC((yyloc)),
                                    ParseConstants::ns_element_default,
                                    SYMTAB((yysemantic_stack_[(5) - (5)].sval)));
    }
    break;

  case 77:
/* Line 670 of lalr1.cc  */
#line 1535 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DefaultNamespaceDecl(LOC((yyloc)),
                                    ParseConstants::ns_function_default,
                                    SYMTAB((yysemantic_stack_[(5) - (5)].sval)));
    }
    break;

  case 78:
/* Line 670 of lalr1.cc  */
#line 1545 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      VFO_DeclList *vdl = new VFO_DeclList( LOC((yyloc)));
      vdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
      (yyval.node) = vdl;
    }
    break;

  case 79:
/* Line 670 of lalr1.cc  */
#line 1552 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      ((VFO_DeclList*)(yysemantic_stack_[(3) - (1)].node))->push_back( (yysemantic_stack_[(3) - (3)].node) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 80:
/* Line 670 of lalr1.cc  */
#line 1559 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].node); // to prevent the Bison warning
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 89:
/* Line 670 of lalr1.cc  */
#line 1582 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DecimalFormatNode(LOC((yyloc)), (yysemantic_stack_[(4) - (4)].vstrpair));
      delete (yysemantic_stack_[(4) - (4)].vstrpair);
    }
    break;

  case 90:
/* Line 670 of lalr1.cc  */
#line 1588 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DecimalFormatNode(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), (yysemantic_stack_[(4) - (4)].vstrpair));
      delete (yysemantic_stack_[(4) - (4)].vstrpair);
    }
    break;

  case 91:
/* Line 670 of lalr1.cc  */
#line 1597 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.vstrpair) = new vector<string_pair_t>();
      (yyval.vstrpair)->push_back( *(yysemantic_stack_[(1) - (1)].strpair) );
      delete (yysemantic_stack_[(1) - (1)].strpair);
    }
    break;

  case 92:
/* Line 670 of lalr1.cc  */
#line 1604 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yysemantic_stack_[(2) - (1)].vstrpair)->push_back( *(yysemantic_stack_[(2) - (2)].strpair) );
      delete (yysemantic_stack_[(2) - (2)].strpair);
      (yyval.vstrpair) = (yysemantic_stack_[(2) - (1)].vstrpair);
    }
    break;

  case 93:
/* Line 670 of lalr1.cc  */
#line 1614 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      StringLiteral *sl = static_cast<StringLiteral*>((yysemantic_stack_[(3) - (3)].expr));
      (yyval.strpair) = new string_pair_t( (yysemantic_stack_[(3) - (1)].strval), sl->get_strval().str() );
      delete sl;
    }
    break;

  case 94:
/* Line 670 of lalr1.cc  */
#line 1623 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "decimal-separator"; }
    break;

  case 95:
/* Line 670 of lalr1.cc  */
#line 1624 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "digit"; }
    break;

  case 96:
/* Line 670 of lalr1.cc  */
#line 1625 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "grouping-separator"; }
    break;

  case 97:
/* Line 670 of lalr1.cc  */
#line 1626 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "infinity"; }
    break;

  case 98:
/* Line 670 of lalr1.cc  */
#line 1627 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "minus-sign"; }
    break;

  case 99:
/* Line 670 of lalr1.cc  */
#line 1628 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "NaN"; }
    break;

  case 100:
/* Line 670 of lalr1.cc  */
#line 1629 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "pattern-separator"; }
    break;

  case 101:
/* Line 670 of lalr1.cc  */
#line 1630 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "percent"; }
    break;

  case 102:
/* Line 670 of lalr1.cc  */
#line 1631 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "per-mille"; }
    break;

  case 103:
/* Line 670 of lalr1.cc  */
#line 1632 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "zero-digit"; }
    break;

  case 104:
/* Line 670 of lalr1.cc  */
#line 1638 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new OptionDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), SYMTAB((yysemantic_stack_[(4) - (4)].sval)));
    }
    break;

  case 105:
/* Line 670 of lalr1.cc  */
#line 1646 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new FTOptionDecl( LOC((yyloc)), dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (3)].node)) );
    }
    break;

  case 106:
/* Line 670 of lalr1.cc  */
#line 1654 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(4) - (4)].node);
    }
    break;

  case 107:
/* Line 670 of lalr1.cc  */
#line 1662 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      CtxItemDecl* d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(3) - (3)].node));
      d->theType = (yysemantic_stack_[(3) - (2)].node);
      (yyval.node) = d;
    }
    break;

  case 108:
/* Line 670 of lalr1.cc  */
#line 1669 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 109:
/* Line 670 of lalr1.cc  */
#line 1677 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      CtxItemDecl* d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(1) - (1)].node));
      d->theIsExternal = false;
      (yyval.node) = d;
    }
    break;

  case 110:
/* Line 670 of lalr1.cc  */
#line 1684 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CtxItemDecl(LOC((yyloc)), NULL);
    }
    break;

  case 111:
/* Line 670 of lalr1.cc  */
#line 1689 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 112:
/* Line 670 of lalr1.cc  */
#line 1697 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CtxItemDecl(LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 113:
/* Line 670 of lalr1.cc  */
#line 1705 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(4) - (2)].varnametype)));

      (yyval.node) = new GlobalVarDecl(LOC((yyloc)),
                             nt->theName,
                             nt->theType,
                             (yysemantic_stack_[(4) - (4)].expr),
                             nt->get_annotations(),
                             false);  // not external

      static_cast<GlobalVarDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(4) - (1)].sval)));
    }
    break;

  case 114:
/* Line 670 of lalr1.cc  */
#line 1719 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(3) - (2)].varnametype)));

      (yyval.node) = new GlobalVarDecl(LOC((yyloc)),
                             nt->theName,
                             nt->theType,
                             NULL,   // no init expr
                             nt->get_annotations(),
                             true);  // external

      static_cast<GlobalVarDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(3) - (1)].sval)));
    }
    break;

  case 115:
/* Line 670 of lalr1.cc  */
#line 1733 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(5) - (2)].varnametype)));

      (yyval.node) = new GlobalVarDecl(LOC((yyloc)),
                             nt->theName,
                             nt->theType,
                             (yysemantic_stack_[(5) - (5)].expr),     // init expr
                             nt->get_annotations(),
                             true);  // external

      static_cast<GlobalVarDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(5) - (1)].sval)));
    }
    break;

  case 116:
/* Line 670 of lalr1.cc  */
#line 1750 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)), NULL, NULL);
    }
    break;

  case 117:
/* Line 670 of lalr1.cc  */
#line 1755 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)),
                              dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (4)].node)),
                              NULL);
    }
    break;

  case 118:
/* Line 670 of lalr1.cc  */
#line 1763 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(4) - (4)].expr)),
                              NULL,
                              static_cast<AnnotationListParsenode*>((yysemantic_stack_[(4) - (1)].node)));
    }
    break;

  case 119:
/* Line 670 of lalr1.cc  */
#line 1771 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(5) - (4)].expr)),
                              dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (5)].node)),
                              static_cast<AnnotationListParsenode*>((yysemantic_stack_[(5) - (1)].node)));
    }
    break;

  case 120:
/* Line 670 of lalr1.cc  */
#line 1782 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AnnotationListParsenode(LOC((yyloc)), static_cast<AnnotationParsenode*>((yysemantic_stack_[(1) - (1)].node)));
    }
    break;

  case 121:
/* Line 670 of lalr1.cc  */
#line 1787 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      static_cast<AnnotationListParsenode*>((yysemantic_stack_[(2) - (1)].node))->push_back(static_cast<AnnotationParsenode*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 122:
/* Line 670 of lalr1.cc  */
#line 1796 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))), NULL);
    }
    break;

  case 123:
/* Line 670 of lalr1.cc  */
#line 1801 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)),
                                   new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (1)].sval))),
                                   static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 124:
/* Line 670 of lalr1.cc  */
#line 1808 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), true), NULL);
    }
    break;

  case 125:
/* Line 670 of lalr1.cc  */
#line 1813 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)),
                                   new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (1)].sval)), true),
                                   static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 126:
/* Line 670 of lalr1.cc  */
#line 1823 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AnnotationLiteralListParsenode(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr));
    }
    break;

  case 127:
/* Line 670 of lalr1.cc  */
#line 1828 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(3) - (1)].node))->push_back((yysemantic_stack_[(3) - (3)].expr));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 128:
/* Line 670 of lalr1.cc  */
#line 1837 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      static_cast<FunctionDecl*>((yysemantic_stack_[(2) - (2)].node))->setComment( SYMTAB((yysemantic_stack_[(2) - (1)].sval)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 129:
/* Line 670 of lalr1.cc  */
#line 1843 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      FunctionDecl* fdecl = static_cast<FunctionDecl*>((yysemantic_stack_[(3) - (3)].node));

      fdecl->setComment( SYMTAB((yysemantic_stack_[(3) - (1)].sval)) );

      fdecl->set_annotations(static_cast<AnnotationListParsenode*>((yysemantic_stack_[(3) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
    }
    break;

  case 130:
/* Line 670 of lalr1.cc  */
#line 1856 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 131:
/* Line 670 of lalr1.cc  */
#line 1861 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 132:
/* Line 670 of lalr1.cc  */
#line 1869 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new FunctionDecl(LOC((yyloc)),
                            static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                            &* (yysemantic_stack_[(4) - (3)].fnsig)->theParams,
                            &* (yysemantic_stack_[(4) - (3)].fnsig)->theReturnType,
                            (yysemantic_stack_[(4) - (4)].expr),      // body
                            false,   // not explicitly updating
                            false);  // not external
      delete (yysemantic_stack_[(4) - (3)].fnsig);
    }
    break;

  case 133:
/* Line 670 of lalr1.cc  */
#line 1880 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new FunctionDecl(LOC ((yyloc)),
                            static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                            (yysemantic_stack_[(4) - (3)].fnsig)->theParams.getp(),
                            (yysemantic_stack_[(4) - (3)].fnsig)->theReturnType.getp(),
                            NULL,   // no body
                            false,   // not explicitly updating
                            true);  // external
      delete (yysemantic_stack_[(4) - (3)].fnsig);
    }
    break;

  case 134:
/* Line 670 of lalr1.cc  */
#line 1895 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new FunctionDecl(LOC ((yyloc)),
                            static_cast<QName*>((yysemantic_stack_[(5) - (3)].expr)),
                            (yysemantic_stack_[(5) - (4)].fnsig)->theParams.getp(),
                            (yysemantic_stack_[(5) - (4)].fnsig)->theReturnType.getp(),
                            (yysemantic_stack_[(5) - (5)].expr),    // body
                            true,  // updating
                            false);// not external
      delete (yysemantic_stack_[(5) - (4)].fnsig);
    }
    break;

  case 135:
/* Line 670 of lalr1.cc  */
#line 1907 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new FunctionDecl(LOC((yyloc)),
                            static_cast<QName*>((yysemantic_stack_[(5) - (3)].expr)),
                            (yysemantic_stack_[(5) - (4)].fnsig)->theParams.getp(),
                            (yysemantic_stack_[(5) - (4)].fnsig)->theReturnType.getp(),
                            NULL,  // no body
                            true,  // updating
                            true); // external
      delete (yysemantic_stack_[(5) - (4)].fnsig);
    }
    break;

  case 136:
/* Line 670 of lalr1.cc  */
#line 1922 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(NULL);
    }
    break;

  case 137:
/* Line 670 of lalr1.cc  */
#line 1927 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (2)].node)));
    }
    break;

  case 138:
/* Line 670 of lalr1.cc  */
#line 1932 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(NULL, dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node)));
    }
    break;

  case 139:
/* Line 670 of lalr1.cc  */
#line 1937 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(dynamic_cast<ParamList*>((yysemantic_stack_[(5) - (2)].node)), dynamic_cast<SequenceType*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 140:
/* Line 670 of lalr1.cc  */
#line 1945 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      ParamList *pl = new ParamList( LOC((yyloc)) );
      pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = pl;
    }
    break;

  case 141:
/* Line 670 of lalr1.cc  */
#line 1952 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      if ( ParamList *pl = dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (1)].node)) )
        pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(3) - (3)].node)) );

      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 142:
/* Line 670 of lalr1.cc  */
#line 1963 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL);
    }
    break;

  case 143:
/* Line 670 of lalr1.cc  */
#line 1968 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)),
                     static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                     dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 144:
/* Line 670 of lalr1.cc  */
#line 1978 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)),
                              NULL,
                              NULL);

      static_cast<CollectionDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(3) - (1)].sval)));
    }
    break;

  case 145:
/* Line 670 of lalr1.cc  */
#line 1987 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(5) - (3)].expr)),
                              0,
                              static_cast<SequenceType*>((yysemantic_stack_[(5) - (5)].node)));

      static_cast<CollectionDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(5) - (1)].sval)));
    }
    break;

  case 146:
/* Line 670 of lalr1.cc  */
#line 1996 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                               static_cast<QName*>((yysemantic_stack_[(4) - (4)].expr)),
                               static_cast<AnnotationListParsenode*>((yysemantic_stack_[(4) - (2)].node)),
                               0);

      static_cast<CollectionDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(4) - (1)].sval)));
    }
    break;

  case 147:
/* Line 670 of lalr1.cc  */
#line 2005 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                               static_cast<QName*>((yysemantic_stack_[(6) - (4)].expr)),
                               static_cast<AnnotationListParsenode*>((yysemantic_stack_[(6) - (2)].node)),
                               static_cast<SequenceType*>((yysemantic_stack_[(6) - (6)].node)));

      static_cast<CollectionDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(6) - (1)].sval)));
    }
    break;

  case 148:
/* Line 670 of lalr1.cc  */
#line 2017 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL));
    }
    break;

  case 149:
/* Line 670 of lalr1.cc  */
#line 2021 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)),
                                                    (yysemantic_stack_[(2) - (1)].node),
                                                    dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node))));
    }
    break;

  case 150:
/* Line 670 of lalr1.cc  */
#line 2027 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL));
    }
    break;

  case 151:
/* Line 670 of lalr1.cc  */
#line 2031 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)),
                                                    (yysemantic_stack_[(2) - (1)].node),
                                                    dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node))));

    }
    break;

  case 152:
/* Line 670 of lalr1.cc  */
#line 2041 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AST_IndexDecl(LOC((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(8) - (3)].expr)),
                             (yysemantic_stack_[(8) - (6)].expr),
                             dynamic_cast<IndexKeyList*>((yysemantic_stack_[(8) - (8)].node)),
                             NULL);

      static_cast<AST_IndexDecl*>((yyval.node))->setComment( SYMTAB((yysemantic_stack_[(8) - (1)].sval)) );
    }
    break;

  case 153:
/* Line 670 of lalr1.cc  */
#line 2051 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AST_IndexDecl(LOC((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(9) - (4)].expr)),
                             (yysemantic_stack_[(9) - (7)].expr),
                             dynamic_cast<IndexKeyList*>((yysemantic_stack_[(9) - (9)].node)),
                             static_cast<AnnotationListParsenode*>((yysemantic_stack_[(9) - (2)].node)));

      static_cast<AST_IndexDecl*>((yyval.node))->setComment( SYMTAB((yysemantic_stack_[(9) - (1)].sval)) );
    }
    break;

  case 154:
/* Line 670 of lalr1.cc  */
#line 2064 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      IndexKeyList* keyList = new IndexKeyList(LOC((yyloc)));
      keyList->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = keyList;
    }
    break;

  case 155:
/* Line 670 of lalr1.cc  */
#line 2070 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      dynamic_cast<IndexKeyList*>((yysemantic_stack_[(3) - (1)].node))->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 156:
/* Line 670 of lalr1.cc  */
#line 2079 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL, NULL);
    }
    break;

  case 157:
/* Line 670 of lalr1.cc  */
#line 2084 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            dynamic_cast<SequenceType*>((yysemantic_stack_[(2) - (2)].node)),
                            NULL);
    }
    break;

  case 158:
/* Line 670 of lalr1.cc  */
#line 2091 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            NULL,
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
    }
    break;

  case 159:
/* Line 670 of lalr1.cc  */
#line 2098 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(3) - (1)].expr),
                            dynamic_cast<SequenceType*>((yysemantic_stack_[(3) - (2)].node)),
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 160:
/* Line 670 of lalr1.cc  */
#line 2110 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new ICCollSimpleCheck(LOC((yyloc)),
                                 static_cast<QName*>((yysemantic_stack_[(11) - (4)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(11) - (7)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(11) - (9)].expr)),
                                 (yysemantic_stack_[(11) - (11)].expr));
    }
    break;

  case 161:
/* Line 670 of lalr1.cc  */
#line 2120 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new ICCollUniqueKeyCheck(LOC((yyloc)),
                                    static_cast<QName*>((yysemantic_stack_[(14) - (4)].expr)),
                                    static_cast<QName*>((yysemantic_stack_[(14) - (7)].expr)),
                                    static_cast<QName*>((yysemantic_stack_[(14) - (10)].expr)),
                                    (yysemantic_stack_[(14) - (14)].expr));
    }
    break;

  case 162:
/* Line 670 of lalr1.cc  */
#line 2130 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new ICCollForeachNode(LOC((yyloc)),
                                 static_cast<QName*>((yysemantic_stack_[(13) - (4)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(13) - (7)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(13) - (11)].expr)),
                                 (yysemantic_stack_[(13) - (13)].expr));
    }
    break;

  case 163:
/* Line 670 of lalr1.cc  */
#line 2141 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new ICForeignKey( LOC((yyloc)),
                            static_cast<QName*>((yysemantic_stack_[(22) - (4)].expr)),
                            static_cast<QName*>((yysemantic_stack_[(22) - (9)].expr)),
                            static_cast<QName*>((yysemantic_stack_[(22) - (12)].expr)),
                            (yysemantic_stack_[(22) - (14)].expr),
                            static_cast<QName*>((yysemantic_stack_[(22) - (17)].expr)),
                            static_cast<QName*>((yysemantic_stack_[(22) - (20)].expr)),
                            (yysemantic_stack_[(22) - (22)].expr));
    }
    break;

  case 164:
/* Line 670 of lalr1.cc  */
#line 2157 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      if ((yysemantic_stack_[(1) - (1)].expr) == NULL)
      {
        error((yylocation_stack_[(1) - (1)]), "syntax error, unexpected end of file, the query body should not be empty");
        YYERROR;
      }

      if (dynamic_cast<BlockBody*>((yysemantic_stack_[(1) - (1)].expr)) != NULL)
      {
        BlockBody* blk = static_cast<BlockBody*>((yysemantic_stack_[(1) - (1)].expr));
        blk->setTopLevel(true);
      }

      (yyval.expr) = new QueryBody(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr));
    }
    break;

  case 165:
/* Line 670 of lalr1.cc  */
#line 2177 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 166:
/* Line 670 of lalr1.cc  */
#line 2181 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 167:
/* Line 670 of lalr1.cc  */
#line 2185 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) =  NULL;
    }
    break;

  case 168:
/* Line 670 of lalr1.cc  */
#line 2193 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 169:
/* Line 670 of lalr1.cc  */
#line 2197 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 170:
/* Line 670 of lalr1.cc  */
#line 2201 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) =  new BlockBody(LOC((yyloc)));
    }
    break;

  case 171:
/* Line 670 of lalr1.cc  */
#line 2209 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 172:
/* Line 670 of lalr1.cc  */
#line 2214 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      BlockBody* blk = static_cast<BlockBody*>((yysemantic_stack_[(2) - (1)].expr));

      blk->add((yysemantic_stack_[(2) - (2)].expr));

      (yyval.expr) = blk;
    }
    break;

  case 173:
/* Line 670 of lalr1.cc  */
#line 2226 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      BlockBody* blk = new BlockBody(LOC((yyloc)));
      blk->add((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = blk;
    }
    break;

  case 174:
/* Line 670 of lalr1.cc  */
#line 2233 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      BlockBody* blk = static_cast<BlockBody*>((yysemantic_stack_[(2) - (1)].expr));

      blk->add((yysemantic_stack_[(2) - (2)].expr));

      (yyval.expr) = blk;
    }
    break;

  case 175:
/* Line 670 of lalr1.cc  */
#line 2243 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(4) - (1)].expr); // to prevent the Bison warning
      (yyval.expr) = (yysemantic_stack_[(4) - (2)].expr); // to prevent the Bison warning
      (yyval.expr) = (yysemantic_stack_[(4) - (4)].expr); // to prevent the Bison warning
      error((yylocation_stack_[(4) - (3)]), "syntax error, unexpected statement (missing semicolon \";\" between statements?)");
      delete (yysemantic_stack_[(4) - (1)].expr); // these need to be deleted here because the parser deallocator will skip them
      delete (yysemantic_stack_[(4) - (2)].expr);
      delete (yysemantic_stack_[(4) - (4)].expr);
      YYERROR;
    }
    break;

  case 189:
/* Line 670 of lalr1.cc  */
#line 2276 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 190:
/* Line 670 of lalr1.cc  */
#line 2284 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      BlockBody* block = dynamic_cast<BlockBody*>((yysemantic_stack_[(3) - (2)].expr));
      if ((yysemantic_stack_[(3) - (2)].expr) == NULL || (block != NULL && block->isEmpty()))
      {
        (yyval.expr) = new JSONDirectObjectConstructor(LOC((yyloc)));
      }
      else if (block == NULL)
      {
        BlockBody* blk = new BlockBody(LOC((yyloc)));
        blk->add((yysemantic_stack_[(3) - (2)].expr));
        (yyval.expr) = blk;
      }
      else
      {
        (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
      }
    }
    break;

  case 191:
/* Line 670 of lalr1.cc  */
#line 2306 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 192:
/* Line 670 of lalr1.cc  */
#line 2314 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    }
    break;

  case 193:
/* Line 670 of lalr1.cc  */
#line 2322 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      VarDeclStmt* vdecl = static_cast<VarDeclStmt*>((yysemantic_stack_[(3) - (1)].expr));
      vdecl->add((yysemantic_stack_[(3) - (3)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 194:
/* Line 670 of lalr1.cc  */
#line 2329 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      VarDeclStmt* vdecl = new VarDeclStmt(LOC((yyloc)), NULL);
      vdecl->add((yysemantic_stack_[(2) - (2)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 195:
/* Line 670 of lalr1.cc  */
#line 2336 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      VarDeclStmt* vdecl = new VarDeclStmt(LOC((yyloc)),
                                           static_cast<AnnotationListParsenode*>((yysemantic_stack_[(3) - (1)].node)));
      vdecl->add((yysemantic_stack_[(3) - (3)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 196:
/* Line 670 of lalr1.cc  */
#line 2347 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      LocalVarDecl* vd = new LocalVarDecl(LOC((yyloc)),
                                          static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)),
                                          NULL,  // no type
                                          NULL,  // no init expr
                                          NULL); // no annotations
      (yyval.node) = vd;
    }
    break;

  case 197:
/* Line 670 of lalr1.cc  */
#line 2356 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      LocalVarDecl* vd = new LocalVarDecl(LOC((yyloc)),
                                          static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                                          dynamic_cast<SequenceType*>((yysemantic_stack_[(3) - (3)].node)), // type
                                          NULL,  // no init expr
                                          NULL); // no annotations
      (yyval.node) = vd;
    }
    break;

  case 198:
/* Line 670 of lalr1.cc  */
#line 2365 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      LocalVarDecl* vd = new LocalVarDecl(LOC((yyloc)),
                                          static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                                          NULL,  // no type
                                          (yysemantic_stack_[(4) - (4)].expr),    // init expr
                                          NULL); // no annotations
      (yyval.node) = vd;
    }
    break;

  case 199:
/* Line 670 of lalr1.cc  */
#line 2374 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      LocalVarDecl* vd = new LocalVarDecl(LOC((yyloc)),
                                          static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                                          dynamic_cast<SequenceType*>((yysemantic_stack_[(5) - (3)].node)), // type
                                          (yysemantic_stack_[(5) - (5)].expr),    // init expr
                                          NULL); // no annotations
      (yyval.node) = vd;
    }
    break;

  case 200:
/* Line 670 of lalr1.cc  */
#line 2387 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new AssignExpr(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)), (yysemantic_stack_[(5) - (4)].expr));
    }
    break;

  case 201:
/* Line 670 of lalr1.cc  */
#line 2395 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new ApplyExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr));
    }
    break;

  case 202:
/* Line 670 of lalr1.cc  */
#line 2403 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new ExitExpr(LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr));
    }
    break;

  case 203:
/* Line 670 of lalr1.cc  */
#line 2411 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      BlockBody* bb = dynamic_cast<BlockBody *>((yysemantic_stack_[(5) - (5)].expr));
      if (bb == NULL)
      {
        bb = new BlockBody((yysemantic_stack_[(5) - (5)].expr)->get_location());
        bb->add((yysemantic_stack_[(5) - (5)].expr));
      }

      (yyval.expr) = new WhileExpr(LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), bb);
    }
    break;

  case 204:
/* Line 670 of lalr1.cc  */
#line 2426 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement(LOC((yyloc)), FlowCtlStatement::BREAK);
    }
    break;

  case 205:
/* Line 670 of lalr1.cc  */
#line 2431 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement( LOC((yyloc)), FlowCtlStatement::CONTINUE );
    }
    break;

  case 206:
/* Line 670 of lalr1.cc  */
#line 2439 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      ReturnExpr* re = dynamic_cast<ReturnExpr*>((yysemantic_stack_[(2) - (2)].expr));
      (yyval.expr) = new FLWORExpr(LOC((yyloc)),
                         dynamic_cast<FLWORClauseList*>((yysemantic_stack_[(2) - (1)].node)),
                         re->get_return_val(),
                         re->get_location(),
                         driver.theCompilerCB->theConfig.force_gflwor);
      delete (yysemantic_stack_[(2) - (2)].expr);
    }
    break;

  case 207:
/* Line 670 of lalr1.cc  */
#line 2453 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      exprnode* retExpr = (yysemantic_stack_[(2) - (2)].expr);

      if (dynamic_cast<VarDeclStmt*>(retExpr) != NULL)
      {
        BlockBody* blk = new BlockBody(LOC((yyloc)));
        blk->add(retExpr);
        retExpr = blk;
      }

      (yyval.expr) = new ReturnExpr(LOC((yyloc)), retExpr);
    }
    break;

  case 208:
/* Line 670 of lalr1.cc  */
#line 2470 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      exprnode* thenExpr = (yysemantic_stack_[(8) - (6)].expr);
      exprnode* elseExpr = (yysemantic_stack_[(8) - (8)].expr);

      if (dynamic_cast<VarDeclStmt*>(thenExpr) != NULL)
      {
        BlockBody* blk = new BlockBody(LOC((yyloc)));
        blk->add(thenExpr);
        thenExpr = blk;
      }

      if (dynamic_cast<VarDeclStmt*>(elseExpr) != NULL)
      {
        BlockBody* blk = new BlockBody(LOC((yyloc)));
        blk->add(elseExpr);
        elseExpr = blk;
      }

      (yyval.expr) = new IfExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), thenExpr, elseExpr);
    }
    break;

  case 209:
/* Line 670 of lalr1.cc  */
#line 2495 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new TryExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 210:
/* Line 670 of lalr1.cc  */
#line 2503 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      CatchListExpr* cle = new CatchListExpr( LOC((yyloc)) );
      cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)) );
      (yyval.expr) = cle;
    }
    break;

  case 211:
/* Line 670 of lalr1.cc  */
#line 2510 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
      if ( cle )
        cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)) );
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    }
    break;

  case 212:
/* Line 670 of lalr1.cc  */
#line 2521 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)), *(yysemantic_stack_[(3) - (2)].name_test_list), (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 213:
/* Line 670 of lalr1.cc  */
#line 2530 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new BlockBody(LOC((yyloc)));
    }
    break;

  case 214:
/* Line 670 of lalr1.cc  */
#line 2537 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 215:
/* Line 670 of lalr1.cc  */
#line 2542 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      Expr* expr = dynamic_cast<Expr*>((yysemantic_stack_[(3) - (1)].expr));
      if ( !expr )
      {
        expr = new Expr( LOC((yyloc)) );
        expr->push_back( (yysemantic_stack_[(3) - (1)].expr) );
      }
      expr->push_back( (yysemantic_stack_[(3) - (3)].expr) );
      (yyval.expr) = expr;
    }
    break;

  case 216:
/* Line 670 of lalr1.cc  */
#line 2555 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (1)].expr); // to prevent the Bison warning
      (yyval.expr) = (yysemantic_stack_[(3) - (3)].expr); // to prevent the Bison warning
      // Heuristics to improve the error message: if the $1 Expr is a QName (which in turn gets
      // promoted to a PathExpr), chances are that it's not a missing comma, so don't modify
      // the error message.
      if (dynamic_cast<PathExpr*>((yysemantic_stack_[(3) - (1)].expr)) == NULL)
        error((yylocation_stack_[(3) - (2)]), "syntax error, unexpected expression (missing comma \",\" between expressions?)");
      delete (yysemantic_stack_[(3) - (1)].expr); // these need to be deleted here because the parser deallocator will skip them
      delete (yysemantic_stack_[(3) - (3)].expr);
      YYERROR;
    }
    break;

  case 235:
/* Line 670 of lalr1.cc  */
#line 2602 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      ReturnExpr *re = dynamic_cast<ReturnExpr*>((yysemantic_stack_[(2) - (2)].expr));
      (yyval.expr) = new FLWORExpr(LOC((yyloc)),
                         dynamic_cast<FLWORClauseList*>((yysemantic_stack_[(2) - (1)].node)),
                         re->get_return_val(),
                         re->get_location(),
                         driver.theCompilerCB->theConfig.force_gflwor);
      delete (yysemantic_stack_[(2) - (2)].expr);
    }
    break;

  case 236:
/* Line 670 of lalr1.cc  */
#line 2616 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new ReturnExpr( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr) );
    }
    break;

  case 237:
/* Line 670 of lalr1.cc  */
#line 2624 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.strval) = parser::the_sliding;
    }
    break;

  case 238:
/* Line 670 of lalr1.cc  */
#line 2629 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.strval) = parser::the_tumbling;
    }
    break;

  case 239:
/* Line 670 of lalr1.cc  */
#line 2637 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.strval) = parser::the_start;
    }
    break;

  case 240:
/* Line 670 of lalr1.cc  */
#line 2642 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.strval) = parser::the_end;
    }
    break;

  case 241:
/* Line 670 of lalr1.cc  */
#line 2647 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
    (yyval.strval) = parser::the_only_end;
  }
    break;

  case 242:
/* Line 670 of lalr1.cc  */
#line 2655 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new FLWORWinCond(LOC((yyloc)),
                            dynamic_cast<WindowVars*>((yysemantic_stack_[(4) - (2)].node)),
                            (yysemantic_stack_[(4) - (4)].expr),
                            (yysemantic_stack_[(4) - (1)].strval) == parser::the_start,
                            (yysemantic_stack_[(4) - (1)].strval) == parser::the_only_end);
    }
    break;

  case 243:
/* Line 670 of lalr1.cc  */
#line 2664 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new FLWORWinCond(LOC((yyloc)),
                            NULL,
                            (yysemantic_stack_[(3) - (3)].expr),
                            (yysemantic_stack_[(3) - (1)].strval) == parser::the_start,
                            (yysemantic_stack_[(3) - (1)].strval) == parser::the_only_end);
    }
    break;

  case 244:
/* Line 670 of lalr1.cc  */
#line 2676 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new WindowClause (LOC ((yyloc)),
                             ((yysemantic_stack_[(5) - (2)].strval) == parser::the_tumbling ?
                              WindowClause::tumbling_window :
                              WindowClause::sliding_window),
                             dynamic_cast<WindowVarDecl *> ((yysemantic_stack_[(5) - (3)].node)),
                             dynamic_cast<FLWORWinCond *> ((yysemantic_stack_[(5) - (4)].node)),
                             dynamic_cast<FLWORWinCond *> ((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 245:
/* Line 670 of lalr1.cc  */
#line 2686 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new WindowClause (LOC ((yyloc)),
                             ((yysemantic_stack_[(4) - (2)].strval) == parser::the_tumbling ?
                              WindowClause::tumbling_window :
                              WindowClause::sliding_window),
                             dynamic_cast<WindowVarDecl *> ((yysemantic_stack_[(4) - (3)].node)),
                             dynamic_cast<FLWORWinCond *> ((yysemantic_stack_[(4) - (4)].node)), NULL);
    }
    break;

  case 246:
/* Line 670 of lalr1.cc  */
#line 2699 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CountClause(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 255:
/* Line 670 of lalr1.cc  */
#line 2723 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      FLWORClauseList *fcl = new FLWORClauseList( LOC((yyloc)) );
      fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = fcl;
    }
    break;

  case 256:
/* Line 670 of lalr1.cc  */
#line 2730 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      FLWORClauseList *fcl = dynamic_cast<FLWORClauseList*>((yysemantic_stack_[(2) - (1)].node));
      fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = fcl;
    }
    break;

  case 257:
/* Line 670 of lalr1.cc  */
#line 2740 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new ForClause(LOC((yyloc)), dynamic_cast<VarInDeclList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 258:
/* Line 670 of lalr1.cc  */
#line 2746 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node); // to prevent the Bison warning
      error((yylocation_stack_[(3) - (2)]), "syntax error, unexpected qualified name \""
          + static_cast<VarInDeclList*>((yysemantic_stack_[(3) - (3)].node))->operator[](0)->get_var_name()->get_qname().str() + "\" (missing \"$\" sign?)");
      delete (yysemantic_stack_[(3) - (3)].node);
      YYERROR;
    }
    break;

  case 259:
/* Line 670 of lalr1.cc  */
#line 2755 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = NULL; // to prevent the Bison warning
      error((yylocation_stack_[(2) - (2)]), ""); // the error message is already set in the driver's parseError member
      YYERROR;
    }
    break;

  case 261:
/* Line 670 of lalr1.cc  */
#line 2765 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      // this adds on shift-reduce conflict (probably with FTRange expression)
    }
    break;

  case 262:
/* Line 670 of lalr1.cc  */
#line 2773 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      VarInDeclList* vdl = new VarInDeclList( LOC((yyloc)) );
      vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = vdl;
    }
    break;

  case 263:
/* Line 670 of lalr1.cc  */
#line 2780 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      if ( VarInDeclList* vdl = dynamic_cast<VarInDeclList*>((yysemantic_stack_[(4) - (1)].node)) )
        vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
      (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
    }
    break;

  case 264:
/* Line 670 of lalr1.cc  */
#line 2788 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); // to prevent the Bison warning
      error((yylocation_stack_[(3) - (3)]), "syntax error, unexpected QName \""
          + static_cast<VarInDecl*>((yysemantic_stack_[(3) - (3)].node))->get_var_name()->get_qname().str() + "\" (missing \"$\" sign?)");
      delete (yysemantic_stack_[(3) - (1)].node);
      YYERROR;
    }
    break;

  case 265:
/* Line 670 of lalr1.cc  */
#line 2800 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)),
                         NULL,
                         NULL,
                         NULL,
                         (yysemantic_stack_[(3) - (3)].expr),
                         false);
    }
    break;

  case 266:
/* Line 670 of lalr1.cc  */
#line 2810 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(5) - (1)].expr)),
                         NULL,
                         NULL,
                         NULL,
                         (yysemantic_stack_[(5) - (5)].expr),
                         true);
    }
    break;

  case 267:
/* Line 670 of lalr1.cc  */
#line 2820 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                         dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)),
                         NULL,
                         NULL,
                         (yysemantic_stack_[(4) - (4)].expr),
                         false);
    }
    break;

  case 268:
/* Line 670 of lalr1.cc  */
#line 2830 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(6) - (1)].expr)),
                         dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (2)].node)),
                         NULL,
                         NULL,
                         (yysemantic_stack_[(6) - (6)].expr),
                         true);
    }
    break;

  case 269:
/* Line 670 of lalr1.cc  */
#line 2840 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                         NULL,
                         dynamic_cast<PositionalVar*>((yysemantic_stack_[(4) - (2)].node)),
                         NULL,
                         (yysemantic_stack_[(4) - (4)].expr),
                         false);
    }
    break;

  case 270:
/* Line 670 of lalr1.cc  */
#line 2850 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(6) - (1)].expr)),
                         NULL,
                         dynamic_cast<PositionalVar*>((yysemantic_stack_[(6) - (4)].node)),
                         NULL,
                         (yysemantic_stack_[(6) - (6)].expr),
                         true);
    }
    break;

  case 271:
/* Line 670 of lalr1.cc  */
#line 2860 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(5) - (1)].expr)),
                         dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (2)].node)),
                         dynamic_cast<PositionalVar*>((yysemantic_stack_[(5) - (3)].node)),
                         NULL,
                         (yysemantic_stack_[(5) - (5)].expr),
                         false);
    }
    break;

  case 272:
/* Line 670 of lalr1.cc  */
#line 2870 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(7) - (1)].expr)),
                         dynamic_cast<SequenceType *>((yysemantic_stack_[(7) - (2)].node)),
                         dynamic_cast<PositionalVar*>((yysemantic_stack_[(7) - (5)].node)),
                         NULL,
                         (yysemantic_stack_[(7) - (7)].expr),
                         true);
    }
    break;

  case 273:
/* Line 670 of lalr1.cc  */
#line 2881 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                         NULL,NULL,
                         dynamic_cast<FTScoreVar*>((yysemantic_stack_[(4) - (2)].node)),
                         (yysemantic_stack_[(4) - (4)].expr),
                         false);
    }
    break;

  case 274:
/* Line 670 of lalr1.cc  */
#line 2890 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(5) - (1)].expr)),
                         dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (2)].node)),
                         NULL,
                         dynamic_cast<FTScoreVar*>((yysemantic_stack_[(5) - (3)].node)),
                         (yysemantic_stack_[(5) - (5)].expr),
                         false);
    }
    break;

  case 275:
/* Line 670 of lalr1.cc  */
#line 2900 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC ((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(5) - (1)].expr)),
                         NULL,
                         dynamic_cast<PositionalVar*>((yysemantic_stack_[(5) - (2)].node)),
                         dynamic_cast<FTScoreVar*>((yysemantic_stack_[(5) - (3)].node)),
                         (yysemantic_stack_[(5) - (5)].expr),
                         false);
    }
    break;

  case 276:
/* Line 670 of lalr1.cc  */
#line 2910 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC ((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(6) - (1)].expr)),
                         dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (2)].node)),
                         dynamic_cast<PositionalVar*>((yysemantic_stack_[(6) - (3)].node)),
                         dynamic_cast<FTScoreVar*>((yysemantic_stack_[(6) - (4)].node)),
                         (yysemantic_stack_[(6) - (6)].expr),
                         false);
    }
    break;

  case 277:
/* Line 670 of lalr1.cc  */
#line 2926 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new PositionalVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 278:
/* Line 670 of lalr1.cc  */
#line 2935 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new FTScoreVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 279:
/* Line 670 of lalr1.cc  */
#line 2944 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new LetClause( LOC((yyloc)), dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(2) - (2)].node)) );
        }
    break;

  case 280:
/* Line 670 of lalr1.cc  */
#line 2952 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            VarGetsDeclList *vgdl = new VarGetsDeclList( LOC((yyloc)) );
            vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = vgdl;
        }
    break;

  case 281:
/* Line 670 of lalr1.cc  */
#line 2958 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            if( VarGetsDeclList *vgdl = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(3) - (1)].node)) )
                vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 282:
/* Line 670 of lalr1.cc  */
#line 2970 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                           NULL,
                           NULL,
                           (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 283:
/* Line 670 of lalr1.cc  */
#line 2978 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                           dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (3)].node)),
                           NULL,
                           (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 284:
/* Line 670 of lalr1.cc  */
#line 2988 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(3) - (1)].node))->get_var_name(),
                           NULL,
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(3) - (1)].node)),
                           (yysemantic_stack_[(3) - (3)].expr));
     }
    break;

  case 285:
/* Line 670 of lalr1.cc  */
#line 2996 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                           dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (3)].node)),
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(6) - (4)].node)),
                           (yysemantic_stack_[(6) - (6)].expr));
    }
    break;

  case 286:
/* Line 670 of lalr1.cc  */
#line 3008 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                             NULL, (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 287:
/* Line 670 of lalr1.cc  */
#line 3014 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                             dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (3)].node)),
                             (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 289:
/* Line 670 of lalr1.cc  */
#line 3027 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL, NULL);
    }
    break;

  case 290:
/* Line 670 of lalr1.cc  */
#line 3031 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_curr(static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)));
    }
    break;

  case 291:
/* Line 670 of lalr1.cc  */
#line 3039 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), dynamic_cast<PositionalVar*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL, NULL);
    }
    break;

  case 292:
/* Line 670 of lalr1.cc  */
#line 3043 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_posvar(dynamic_cast<PositionalVar*>((yysemantic_stack_[(2) - (1)].node)));
    }
    break;

  case 294:
/* Line 670 of lalr1.cc  */
#line 3052 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), static_cast<QName*>((yysemantic_stack_[(6) - (6)].expr)));
    }
    break;

  case 295:
/* Line 670 of lalr1.cc  */
#line 3056 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 296:
/* Line 670 of lalr1.cc  */
#line 3060 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)), NULL);
    }
    break;

  case 297:
/* Line 670 of lalr1.cc  */
#line 3070 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new WhereClause(LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 298:
/* Line 670 of lalr1.cc  */
#line 3078 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new GroupByClause(LOC((yyloc)), dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 299:
/* Line 670 of lalr1.cc  */
#line 3085 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      GroupSpecList* gsl = new GroupSpecList(LOC((yyloc)));
      gsl->push_back(static_cast<GroupSpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = gsl;
    }
    break;

  case 300:
/* Line 670 of lalr1.cc  */
#line 3091 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      GroupSpecList* gsl = static_cast<GroupSpecList*>((yysemantic_stack_[(3) - (1)].node));
      gsl->push_back(static_cast<GroupSpec*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = gsl;
    }
    break;

  case 301:
/* Line 670 of lalr1.cc  */
#line 3101 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL, NULL, NULL);
    }
    break;

  case 302:
/* Line 670 of lalr1.cc  */
#line 3105 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)), NULL, (yysemantic_stack_[(4) - (4)].expr), NULL);
    }
    break;

  case 303:
/* Line 670 of lalr1.cc  */
#line 3109 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                         static_cast<SequenceType*>((yysemantic_stack_[(5) - (3)].node)),
                         (yysemantic_stack_[(5) - (5)].expr),
                         NULL);
    }
    break;

  case 304:
/* Line 670 of lalr1.cc  */
#line 3117 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                         static_cast<SequenceType*>((yysemantic_stack_[(6) - (3)].node)),
                         (yysemantic_stack_[(6) - (5)].expr),
                         static_cast<GroupCollationSpec*>((yysemantic_stack_[(6) - (6)].node)));
    }
    break;

  case 305:
/* Line 670 of lalr1.cc  */
#line 3125 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                         NULL,
                         (yysemantic_stack_[(5) - (4)].expr),
                         static_cast<GroupCollationSpec*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 306:
/* Line 670 of lalr1.cc  */
#line 3133 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                         NULL,
                         NULL,
                         static_cast<GroupCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 307:
/* Line 670 of lalr1.cc  */
#line 3145 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new GroupCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
    }
    break;

  case 308:
/* Line 670 of lalr1.cc  */
#line 3153 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 309:
/* Line 670 of lalr1.cc  */
#line 3159 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(4) - (4)].node)), true
            );
        }
    break;

  case 310:
/* Line 670 of lalr1.cc  */
#line 3169 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            OrderSpecList *osl = new OrderSpecList( LOC((yyloc)) );
            osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = osl;
        }
    break;

  case 311:
/* Line 670 of lalr1.cc  */
#line 3175 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            if ( OrderSpecList* osl = dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (1)].node)) )
                osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 312:
/* Line 670 of lalr1.cc  */
#line 3185 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderSpec( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL );
        }
    break;

  case 313:
/* Line 670 of lalr1.cc  */
#line 3189 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderSpec(
                LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<OrderModifierPN*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 314:
/* Line 670 of lalr1.cc  */
#line 3199 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL
            );
        }
    break;

  case 315:
/* Line 670 of lalr1.cc  */
#line 3205 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 316:
/* Line 670 of lalr1.cc  */
#line 3211 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, NULL, dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 317:
/* Line 670 of lalr1.cc  */
#line 3217 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (2)].node)),
                NULL
            );
        }
    break;

  case 318:
/* Line 670 of lalr1.cc  */
#line 3226 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
                NULL,
                dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 319:
/* Line 670 of lalr1.cc  */
#line 3235 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                NULL,
                dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 320:
/* Line 670 of lalr1.cc  */
#line 3244 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(3) - (1)].node)),
                dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 321:
/* Line 670 of lalr1.cc  */
#line 3257 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_ascending );
        }
    break;

  case 322:
/* Line 670 of lalr1.cc  */
#line 3261 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_descending );
        }
    break;

  case 323:
/* Line 670 of lalr1.cc  */
#line 3269 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_greatest
            );
        }
    break;

  case 324:
/* Line 670 of lalr1.cc  */
#line 3275 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_least
            );
        }
    break;

  case 325:
/* Line 670 of lalr1.cc  */
#line 3285 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 326:
/* Line 670 of lalr1.cc  */
#line 3293 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new QuantifiedExpr(
                LOC((yyloc)),
                ParseConstants::quant_some,
                dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(5) - (3)].node)),
                (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 327:
/* Line 670 of lalr1.cc  */
#line 3302 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new QuantifiedExpr(
                LOC((yyloc)),
                ParseConstants::quant_every,
                dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(5) - (3)].node)),
                (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 328:
/* Line 670 of lalr1.cc  */
#line 3315 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      QVarInDeclList *qvidl = new QVarInDeclList( LOC((yyloc)) );
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = qvidl;

    }
    break;

  case 329:
/* Line 670 of lalr1.cc  */
#line 3322 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      QVarInDeclList *qvidl = dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
      (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
    }
    break;

  case 330:
/* Line 670 of lalr1.cc  */
#line 3334 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 331:
/* Line 670 of lalr1.cc  */
#line 3338 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                          dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 332:
/* Line 670 of lalr1.cc  */
#line 3350 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new SwitchExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(8) - (5)].node)), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 333:
/* Line 670 of lalr1.cc  */
#line 3357 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = new SwitchCaseClauseList(LOC((yyloc)));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = scc_list_p;
    }
    break;

  case 334:
/* Line 670 of lalr1.cc  */
#line 3363 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 335:
/* Line 670 of lalr1.cc  */
#line 3372 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SwitchCaseClause(LOC((yyloc)), dynamic_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 336:
/* Line 670 of lalr1.cc  */
#line 3379 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = new SwitchCaseOperandList(LOC((yyloc)));
      sco_list_p->push_back((yysemantic_stack_[(2) - (2)].expr));
      (yyval.node) = sco_list_p;
    }
    break;

  case 337:
/* Line 670 of lalr1.cc  */
#line 3385 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = static_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node));
      sco_list_p->push_back((yysemantic_stack_[(3) - (3)].expr));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 338:
/* Line 670 of lalr1.cc  */
#line 3396 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new SwitchExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(8) - (5)].node)), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 339:
/* Line 670 of lalr1.cc  */
#line 3403 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = new SwitchCaseClauseList(LOC((yyloc)));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = scc_list_p;
    }
    break;

  case 340:
/* Line 670 of lalr1.cc  */
#line 3409 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 341:
/* Line 670 of lalr1.cc  */
#line 3418 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SwitchCaseClause(LOC((yyloc)), dynamic_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 342:
/* Line 670 of lalr1.cc  */
#line 3427 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC((yyloc)),
                              (yysemantic_stack_[(8) - (3)].expr),
                              static_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
                              (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 343:
/* Line 670 of lalr1.cc  */
#line 3434 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
                              (yysemantic_stack_[(10) - (3)].expr),
                              static_cast<CaseClauseList*>((yysemantic_stack_[(10) - (5)].node)),
                              static_cast<QName*>((yysemantic_stack_[(10) - (8)].expr)),
                              (yysemantic_stack_[(10) - (10)].expr));
    }
    break;

  case 344:
/* Line 670 of lalr1.cc  */
#line 3445 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC((yyloc)),
                              (yysemantic_stack_[(8) - (3)].expr),
                              static_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
                              (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 345:
/* Line 670 of lalr1.cc  */
#line 3452 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
                              (yysemantic_stack_[(10) - (3)].expr),
                              static_cast<CaseClauseList*>((yysemantic_stack_[(10) - (5)].node)),
                              static_cast<QName*>((yysemantic_stack_[(10) - (8)].expr)),
                              (yysemantic_stack_[(10) - (10)].expr));
    }
    break;

  case 346:
/* Line 670 of lalr1.cc  */
#line 3464 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
      cc_list_p->push_back(static_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = cc_list_p;
    }
    break;

  case 347:
/* Line 670 of lalr1.cc  */
#line 3470 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      cc_list_p->push_back(static_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 348:
/* Line 670 of lalr1.cc  */
#line 3482 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<SequenceTypeList*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 349:
/* Line 670 of lalr1.cc  */
#line 3488 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                          static_cast<SequenceTypeList*>((yysemantic_stack_[(7) - (5)].node)),
                          (yysemantic_stack_[(7) - (7)].expr));
     }
    break;

  case 350:
/* Line 670 of lalr1.cc  */
#line 3499 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
      cc_list_p->push_back(static_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = cc_list_p;
    }
    break;

  case 351:
/* Line 670 of lalr1.cc  */
#line 3505 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      CaseClauseList* cc_list_p = static_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      cc_list_p->push_back(static_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 352:
/* Line 670 of lalr1.cc  */
#line 3516 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<SequenceTypeList*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 353:
/* Line 670 of lalr1.cc  */
#line 3522 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                          static_cast<SequenceTypeList*>((yysemantic_stack_[(7) - (5)].node)),
                          (yysemantic_stack_[(7) - (7)].expr));
     }
    break;

  case 354:
/* Line 670 of lalr1.cc  */
#line 3533 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      SequenceTypeList* seqList = new SequenceTypeList(LOC((yyloc)));
      seqList->push_back(static_cast<SequenceType*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = seqList;
    }
    break;

  case 355:
/* Line 670 of lalr1.cc  */
#line 3539 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      SequenceTypeList* seqList = static_cast<SequenceTypeList*>((yysemantic_stack_[(3) - (1)].node));
      seqList->push_back(static_cast<SequenceType*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 356:
/* Line 670 of lalr1.cc  */
#line 3550 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new IfExpr(LOC ((yyloc)), (yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (6)].expr), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 357:
/* Line 670 of lalr1.cc  */
#line 3559 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 358:
/* Line 670 of lalr1.cc  */
#line 3563 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new OrExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
    }
    break;

  case 359:
/* Line 670 of lalr1.cc  */
#line 3572 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 360:
/* Line 670 of lalr1.cc  */
#line 3576 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new AndExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 361:
/* Line 670 of lalr1.cc  */
#line 3583 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 362:
/* Line 670 of lalr1.cc  */
#line 3587 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new ComparisonExpr(
              LOC((yyloc)),
              new ValueComp( LOC((yyloc)), ParseConstants::op_val_not ),
              (yysemantic_stack_[(2) - (2)].expr),
              NULL
          );
        }
    break;

  case 363:
/* Line 670 of lalr1.cc  */
#line 3600 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 364:
/* Line 670 of lalr1.cc  */
#line 3604 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            /*  ::=  "eq" | "ne" | "lt" | "le" | "gt" | "ge" */
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                dynamic_cast<ValueComp*>((yysemantic_stack_[(3) - (2)].node)),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 365:
/* Line 670 of lalr1.cc  */
#line 3684 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 366:
/* Line 670 of lalr1.cc  */
#line 3688 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new FTContainsExpr(
                LOC((yyloc)),
                (yysemantic_stack_[(5) - (1)].expr),
                dynamic_cast<FTSelection*>((yysemantic_stack_[(5) - (4)].node)),
                dynamic_cast<FTIgnoreOption*>((yysemantic_stack_[(5) - (5)].node))
            );
        }
    break;

  case 367:
/* Line 670 of lalr1.cc  */
#line 3700 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 368:
/* Line 670 of lalr1.cc  */
#line 3704 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new StringConcatExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
        }
    break;

  case 369:
/* Line 670 of lalr1.cc  */
#line 3711 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 370:
/* Line 670 of lalr1.cc  */
#line 3715 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 371:
/* Line 670 of lalr1.cc  */
#line 3722 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 372:
/* Line 670 of lalr1.cc  */
#line 3726 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new RangeExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 373:
/* Line 670 of lalr1.cc  */
#line 3735 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 374:
/* Line 670 of lalr1.cc  */
#line 3739 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_plus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 375:
/* Line 670 of lalr1.cc  */
#line 3743 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_minus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 376:
/* Line 670 of lalr1.cc  */
#line 3751 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 377:
/* Line 670 of lalr1.cc  */
#line 3755 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mul, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 378:
/* Line 670 of lalr1.cc  */
#line 3761 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_div, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 379:
/* Line 670 of lalr1.cc  */
#line 3767 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_idiv, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 380:
/* Line 670 of lalr1.cc  */
#line 3773 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mod, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 381:
/* Line 670 of lalr1.cc  */
#line 3783 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 382:
/* Line 670 of lalr1.cc  */
#line 3787 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 383:
/* Line 670 of lalr1.cc  */
#line 3791 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 384:
/* Line 670 of lalr1.cc  */
#line 3799 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 385:
/* Line 670 of lalr1.cc  */
#line 3803 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_intersect, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 386:
/* Line 670 of lalr1.cc  */
#line 3809 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_except, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 387:
/* Line 670 of lalr1.cc  */
#line 3819 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 388:
/* Line 670 of lalr1.cc  */
#line 3823 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InstanceofExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 389:
/* Line 670 of lalr1.cc  */
#line 3833 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 390:
/* Line 670 of lalr1.cc  */
#line 3837 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new TreatExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 391:
/* Line 670 of lalr1.cc  */
#line 3847 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 392:
/* Line 670 of lalr1.cc  */
#line 3851 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new CastableExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 393:
/* Line 670 of lalr1.cc  */
#line 3861 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 394:
/* Line 670 of lalr1.cc  */
#line 3865 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new CastExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 395:
/* Line 670 of lalr1.cc  */
#line 3875 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SingleType(LOC((yyloc)), dynamic_cast<SimpleType*>((yysemantic_stack_[(1) - (1)].node)), false);
    }
    break;

  case 396:
/* Line 670 of lalr1.cc  */
#line 3879 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SingleType(LOC((yyloc)), dynamic_cast<SimpleType*>((yysemantic_stack_[(2) - (1)].node)), true);
    }
    break;

  case 397:
/* Line 670 of lalr1.cc  */
#line 3888 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 398:
/* Line 670 of lalr1.cc  */
#line 3892 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new UnaryExpr( LOC((yyloc)), dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 399:
/* Line 670 of lalr1.cc  */
#line 3900 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), true );
        }
    break;

  case 400:
/* Line 670 of lalr1.cc  */
#line 3904 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), false );
        }
    break;

  case 401:
/* Line 670 of lalr1.cc  */
#line 3908 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 402:
/* Line 670 of lalr1.cc  */
#line 3912 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            if ( SignList *sl = dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)) )
                sl->negate();
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 403:
/* Line 670 of lalr1.cc  */
#line 3922 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 404:
/* Line 670 of lalr1.cc  */
#line 3926 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 405:
/* Line 670 of lalr1.cc  */
#line 3930 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 406:
/* Line 670 of lalr1.cc  */
#line 3937 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
      }
    break;

  case 407:
/* Line 670 of lalr1.cc  */
#line 3942 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.expr) = new SimpleMapExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
      }
    break;

  case 408:
/* Line 670 of lalr1.cc  */
#line 3950 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_eq );
        }
    break;

  case 409:
/* Line 670 of lalr1.cc  */
#line 3954 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ne );
        }
    break;

  case 410:
/* Line 670 of lalr1.cc  */
#line 3958 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_lt );
        }
    break;

  case 411:
/* Line 670 of lalr1.cc  */
#line 3962 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_le );
        }
    break;

  case 412:
/* Line 670 of lalr1.cc  */
#line 3966 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_gt );
        }
    break;

  case 413:
/* Line 670 of lalr1.cc  */
#line 3970 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ge );
        }
    break;

  case 414:
/* Line 670 of lalr1.cc  */
#line 3994 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 415:
/* Line 670 of lalr1.cc  */
#line 3998 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "lax", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 416:
/* Line 670 of lalr1.cc  */
#line 4002 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 417:
/* Line 670 of lalr1.cc  */
#line 4006 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ValidateExpr(
                LOC((yyloc)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (3)].node))->get_name(), (yysemantic_stack_[(6) - (5)].expr)
            );
            delete (yysemantic_stack_[(6) - (3)].node);
        }
    break;

  case 418:
/* Line 670 of lalr1.cc  */
#line 4017 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(3) - (1)].node)), NULL
            );
        }
    break;

  case 419:
/* Line 670 of lalr1.cc  */
#line 4023 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)), (yysemantic_stack_[(4) - (3)].expr)
            );
        }
    break;

  case 420:
/* Line 670 of lalr1.cc  */
#line 4033 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            PragmaList *pl = new PragmaList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = pl;
        }
    break;

  case 421:
/* Line 670 of lalr1.cc  */
#line 4039 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            if ( PragmaList *pl = dynamic_cast<PragmaList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 422:
/* Line 670 of lalr1.cc  */
#line 4049 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
        }
    break;

  case 423:
/* Line 670 of lalr1.cc  */
#line 4053 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) ), "" );
        }
    break;

  case 424:
/* Line 670 of lalr1.cc  */
#line 4057 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), true ), "" );
        }
    break;

  case 425:
/* Line 670 of lalr1.cc  */
#line 4120 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      RelativePathExpr* rpe = dynamic_cast<RelativePathExpr*>((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = (!rpe ?
            (yysemantic_stack_[(1) - (1)].expr) :
            new PathExpr( LOC((yyloc)), ParseConstants::path_relative, (yysemantic_stack_[(1) - (1)].expr)));
    }
    break;

  case 426:
/* Line 670 of lalr1.cc  */
#line 4142 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      AxisStep* as = dynamic_cast<AxisStep*>((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = (as ?
            new RelativePathExpr(LOC((yyloc)),
                                 ParseConstants::st_slash,
                                 new ContextItemExpr( LOC((yyloc)), true ), (yysemantic_stack_[(1) - (1)].expr), true)
            :
            (yysemantic_stack_[(1) - (1)].expr));
    }
    break;

  case 427:
/* Line 670 of lalr1.cc  */
#line 4170 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 428:
/* Line 670 of lalr1.cc  */
#line 4334 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 429:
/* Line 670 of lalr1.cc  */
#line 4338 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), dynamic_cast<Wildcard*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 430:
/* Line 670 of lalr1.cc  */
#line 4348 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", "", ParseConstants::wild_all, false);
    }
    break;

  case 431:
/* Line 670 of lalr1.cc  */
#line 4352 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), "", ParseConstants::wild_elem, false);
    }
    break;

  case 432:
/* Line 670 of lalr1.cc  */
#line 4356 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), "", ParseConstants::wild_elem, true);
    }
    break;

  case 433:
/* Line 670 of lalr1.cc  */
#line 4360 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", SYMTAB((yysemantic_stack_[(1) - (1)].sval)), ParseConstants::wild_prefix, false);
    }
    break;

  case 434:
/* Line 670 of lalr1.cc  */
#line 4369 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
     }
    break;

  case 435:
/* Line 670 of lalr1.cc  */
#line 4373 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new FilterExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
     }
    break;

  case 436:
/* Line 670 of lalr1.cc  */
#line 4377 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new DynamicFunctionInvocation(LOC ((yyloc)), (yysemantic_stack_[(3) - (1)].expr), false);
     }
    break;

  case 437:
/* Line 670 of lalr1.cc  */
#line 4381 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new DynamicFunctionInvocation(LOC ((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node)), false);
     }
    break;

  case 438:
/* Line 670 of lalr1.cc  */
#line 4385 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
       StringLiteral* sl = new StringLiteral( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
       (yyval.expr) = new JSONObjectLookup(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), sl);
     }
    break;

  case 439:
/* Line 670 of lalr1.cc  */
#line 4390 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new JSONObjectLookup(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
     }
    break;

  case 440:
/* Line 670 of lalr1.cc  */
#line 4394 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new JSONObjectLookup(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
     }
    break;

  case 441:
/* Line 670 of lalr1.cc  */
#line 4398 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new JSONObjectLookup(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
     }
    break;

  case 442:
/* Line 670 of lalr1.cc  */
#line 4407 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            PredicateList *pl = new PredicateList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<exprnode*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.node) = pl;
        }
    break;

  case 443:
/* Line 670 of lalr1.cc  */
#line 4413 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            if ( PredicateList *pl = dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<exprnode*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 444:
/* Line 670 of lalr1.cc  */
#line 4423 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
        }
    break;

  case 445:
/* Line 670 of lalr1.cc  */
#line 4431 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 446:
/* Line 670 of lalr1.cc  */
#line 4435 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 447:
/* Line 670 of lalr1.cc  */
#line 4439 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 448:
/* Line 670 of lalr1.cc  */
#line 4443 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 449:
/* Line 670 of lalr1.cc  */
#line 4447 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 450:
/* Line 670 of lalr1.cc  */
#line 4451 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 451:
/* Line 670 of lalr1.cc  */
#line 4455 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 452:
/* Line 670 of lalr1.cc  */
#line 4459 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 453:
/* Line 670 of lalr1.cc  */
#line 4463 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 454:
/* Line 670 of lalr1.cc  */
#line 4467 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 455:
/* Line 670 of lalr1.cc  */
#line 4472 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 456:
/* Line 670 of lalr1.cc  */
#line 4476 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 457:
/* Line 670 of lalr1.cc  */
#line 4480 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 458:
/* Line 670 of lalr1.cc  */
#line 4484 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 459:
/* Line 670 of lalr1.cc  */
#line 4492 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 460:
/* Line 670 of lalr1.cc  */
#line 4496 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 461:
/* Line 670 of lalr1.cc  */
#line 4500 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 462:
/* Line 670 of lalr1.cc  */
#line 4504 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new NullLiteral(LOC((yyloc)));
        }
    break;

  case 463:
/* Line 670 of lalr1.cc  */
#line 4512 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_decimal, *(yysemantic_stack_[(1) - (1)].decval)
            );
            delete yylval.decval;
        }
    break;

  case 464:
/* Line 670 of lalr1.cc  */
#line 4519 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_integer, *(yysemantic_stack_[(1) - (1)].ival)
            );
            delete yylval.ival;
        }
    break;

  case 465:
/* Line 670 of lalr1.cc  */
#line 4526 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_double, *(yysemantic_stack_[(1) - (1)].dval)
            );
            delete yylval.dval;
        }
    break;

  case 466:
/* Line 670 of lalr1.cc  */
#line 4536 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new BooleanLiteral(LOC((yyloc)), true);
        }
    break;

  case 467:
/* Line 670 of lalr1.cc  */
#line 4540 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new BooleanLiteral(LOC((yyloc)), false);
        }
    break;

  case 468:
/* Line 670 of lalr1.cc  */
#line 4548 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new VarRef(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)));
        }
    break;

  case 469:
/* Line 670 of lalr1.cc  */
#line 4556 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), NULL);
        }
    break;

  case 470:
/* Line 670 of lalr1.cc  */
#line 4560 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 471:
/* Line 670 of lalr1.cc  */
#line 4568 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ContextItemExpr( LOC((yyloc)) );
        }
    break;

  case 472:
/* Line 670 of lalr1.cc  */
#line 4572 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ContextItemExpr( LOC((yyloc)) );
        }
    break;

  case 473:
/* Line 670 of lalr1.cc  */
#line 4580 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new OrderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 474:
/* Line 670 of lalr1.cc  */
#line 4588 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new UnorderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 475:
/* Line 670 of lalr1.cc  */
#line 4642 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new FunctionCall( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), NULL );
    }
    break;

  case 476:
/* Line 670 of lalr1.cc  */
#line 4646 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      ArgList* argList = dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node));

      if (argList->has_placeholder())
      {
        LiteralFunctionItem* lfi = 
        new LiteralFunctionItem(LOC((yyloc)),
                                dynamic_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                                new Integer(argList->size()));

        (yyval.expr) = new DynamicFunctionInvocation(LOC((yyloc)), lfi, argList, true);
      }
      else
      {
        (yyval.expr) = new FunctionCall(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)), argList);
      }
    }
    break;

  case 477:
/* Line 670 of lalr1.cc  */
#line 4668 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      ArgList *al = new ArgList( LOC((yyloc)) );
      al->push_back(new ArgumentPlaceholder(LOC((yyloc))));
      (yyval.node) = al;
    }
    break;

  case 478:
/* Line 670 of lalr1.cc  */
#line 4674 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      if ( ArgList *al = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node)) )
        al->push_back( new ArgumentPlaceholder(LOC((yyloc))) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 479:
/* Line 670 of lalr1.cc  */
#line 4680 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      ArgList *al = new ArgList( LOC((yyloc)) );
      al->push_back( (yysemantic_stack_[(1) - (1)].expr) );
      (yyval.node) = al;
    }
    break;

  case 480:
/* Line 670 of lalr1.cc  */
#line 4686 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      if ( ArgList *al = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node)) )
        al->push_back( (yysemantic_stack_[(3) - (3)].expr) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 481:
/* Line 670 of lalr1.cc  */
#line 4696 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 482:
/* Line 670 of lalr1.cc  */
#line 4700 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 483:
/* Line 670 of lalr1.cc  */
#line 4708 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new LiteralFunctionItem(LOC ((yyloc)), dynamic_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].ival));
    }
    break;

  case 484:
/* Line 670 of lalr1.cc  */
#line 4716 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new InlineFunction(LOC((yyloc)),
                              &*(yysemantic_stack_[(3) - (2)].fnsig)->theParams,
                              &*(yysemantic_stack_[(3) - (2)].fnsig)->theReturnType,
                              (yysemantic_stack_[(3) - (3)].expr));
      delete (yysemantic_stack_[(3) - (2)].fnsig);
    }
    break;

  case 485:
/* Line 670 of lalr1.cc  */
#line 4728 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 486:
/* Line 670 of lalr1.cc  */
#line 4732 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 487:
/* Line 670 of lalr1.cc  */
#line 4740 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 488:
/* Line 670 of lalr1.cc  */
#line 4744 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 489:
/* Line 670 of lalr1.cc  */
#line 4748 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 490:
/* Line 670 of lalr1.cc  */
#line 4756 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new DirElemConstructor(LOC((yyloc)),
                                  static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                                  NULL,
                                  NULL,
                                  NULL);
    }
    break;

  case 491:
/* Line 670 of lalr1.cc  */
#line 4764 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      if (static_cast<QName*>((yysemantic_stack_[(8) - (2)].expr))->get_qname() != static_cast<QName*>((yysemantic_stack_[(8) - (6)].expr))->get_qname())
      {
        error((yylocation_stack_[(8) - (5)]), "syntax error, end tag </" +
                  static_cast<QName*>((yysemantic_stack_[(8) - (6)].expr))->get_qname().str() +
                  "> does not match start tag <" +
                  static_cast<QName*>((yysemantic_stack_[(8) - (2)].expr))->get_qname().str() + ">");
        YYERROR;
      }

      (yyval.expr) = new DirElemConstructor(LOC((yyloc)),
                                  static_cast<QName*>((yysemantic_stack_[(8) - (2)].expr)),
                                  static_cast<QName*>((yysemantic_stack_[(8) - (6)].expr)),
                                  NULL,
                                  NULL);
    }
    break;

  case 492:
/* Line 670 of lalr1.cc  */
#line 4781 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new DirElemConstructor(LOC((yyloc)),
                                  static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                                  NULL,
                                  dynamic_cast<DirAttributeList*>((yysemantic_stack_[(5) - (3)].node)),
                                  NULL);
    }
    break;

  case 493:
/* Line 670 of lalr1.cc  */
#line 4789 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      if (static_cast<QName*>((yysemantic_stack_[(9) - (2)].expr))->get_qname() != static_cast<QName*>((yysemantic_stack_[(9) - (7)].expr))->get_qname())
      {
        error((yylocation_stack_[(9) - (5)]), "syntax error, end tag </" +
                  static_cast<QName*>((yysemantic_stack_[(9) - (7)].expr))->get_qname().str() +
                  "> does not match start tag <" +
                  static_cast<QName*>((yysemantic_stack_[(9) - (2)].expr))->get_qname().str() + ">");
        YYERROR;
      }

      (yyval.expr) = new DirElemConstructor(LOC((yyloc)),
                                  static_cast<QName*>((yysemantic_stack_[(9) - (2)].expr)),
                                  static_cast<QName*>((yysemantic_stack_[(9) - (7)].expr)),
                                  dynamic_cast<DirAttributeList*>((yysemantic_stack_[(9) - (3)].node)),
                                  NULL);
    }
    break;

  case 494:
/* Line 670 of lalr1.cc  */
#line 4808 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      if (static_cast<QName*>((yysemantic_stack_[(9) - (2)].expr))->get_qname() != static_cast<QName*>((yysemantic_stack_[(9) - (7)].expr))->get_qname())
      {
        error((yylocation_stack_[(9) - (5)]), "syntax error, end tag </" +
                  static_cast<QName*>((yysemantic_stack_[(9) - (7)].expr))->get_qname().str() +
                  "> does not match start tag <" +
                  static_cast<QName*>((yysemantic_stack_[(9) - (2)].expr))->get_qname().str() + ">");
        YYERROR;
      }

      (yyval.expr) = new DirElemConstructor(LOC((yyloc)),
                                  static_cast<QName*>((yysemantic_stack_[(9) - (2)].expr)),
                                  static_cast<QName*>((yysemantic_stack_[(9) - (7)].expr)),
                                  NULL,
                                  dynamic_cast<DirElemContentList*>((yysemantic_stack_[(9) - (5)].node)));
    }
    break;

  case 495:
/* Line 670 of lalr1.cc  */
#line 4827 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      if (static_cast<QName*>((yysemantic_stack_[(10) - (2)].expr))->get_qname() != static_cast<QName*>((yysemantic_stack_[(10) - (8)].expr))->get_qname())
      {
        error((yylocation_stack_[(10) - (5)]), "syntax error, end tag </" +
                  static_cast<QName*>((yysemantic_stack_[(10) - (8)].expr))->get_qname().str() +
                  "> does not match start tag <" +
                  static_cast<QName*>((yysemantic_stack_[(10) - (2)].expr))->get_qname().str() + ">");
        YYERROR;
      }

      (yyval.expr) = new DirElemConstructor(LOC((yyloc)),
                                  static_cast<QName*>((yysemantic_stack_[(10) - (2)].expr)),
                                  static_cast<QName*>((yysemantic_stack_[(10) - (8)].expr)),
                                  dynamic_cast<DirAttributeList*>((yysemantic_stack_[(10) - (3)].node)),
                                  dynamic_cast<DirElemContentList*>((yysemantic_stack_[(10) - (6)].node)));
    }
    break;

  case 496:
/* Line 670 of lalr1.cc  */
#line 4849 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      DirElemContentList *decl = new DirElemContentList( LOC((yyloc)) );
      decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(1) - (1)].expr)) );
      (yyval.node) = decl;
    }
    break;

  case 497:
/* Line 670 of lalr1.cc  */
#line 4855 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      DirElemContentList *decl = dynamic_cast<DirElemContentList*>((yysemantic_stack_[(2) - (1)].node));
      if ( decl )
        decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(2) - (2)].expr)) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 498:
/* Line 670 of lalr1.cc  */
#line 4866 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      DirAttributeList *dal = new DirAttributeList( LOC((yyloc)) );
      dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = dal;
    }
    break;

  case 499:
/* Line 670 of lalr1.cc  */
#line 4872 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      DirAttributeList *dal = dynamic_cast<DirAttributeList*>((yysemantic_stack_[(2) - (1)].node));
      if ( dal )
        dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 500:
/* Line 670 of lalr1.cc  */
#line 4883 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DirAttr(LOC((yyloc)),
                       static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                       dynamic_cast<DirAttributeValue*>((yysemantic_stack_[(6) - (6)].node)));
    }
    break;

  case 503:
/* Line 670 of lalr1.cc  */
#line 4898 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DirAttributeValue(LOC((yyloc)),
                                 dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
    }
    break;

  case 504:
/* Line 670 of lalr1.cc  */
#line 4903 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DirAttributeValue( LOC((yyloc)),
                                  dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
    }
    break;

  case 505:
/* Line 670 of lalr1.cc  */
#line 4912 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new QuoteAttrContentList( LOC((yyloc)) );
    }
    break;

  case 506:
/* Line 670 of lalr1.cc  */
#line 4916 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 507:
/* Line 670 of lalr1.cc  */
#line 4923 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
      qacl->push_back( new QuoteAttrValueContent( LOC((yyloc)), "\"" ) );
      (yyval.node) = qacl;
    }
    break;

  case 508:
/* Line 670 of lalr1.cc  */
#line 4929 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
      qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = qacl;
    }
    break;

  case 509:
/* Line 670 of lalr1.cc  */
#line 4935 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      QuoteAttrContentList* qacl = dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
      if ( qacl )
        qacl->push_back( new QuoteAttrValueContent( LOC((yyloc)), "\"" ) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 510:
/* Line 670 of lalr1.cc  */
#line 4942 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      QuoteAttrContentList *qacl = dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
      if ( qacl )
        qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 511:
/* Line 670 of lalr1.cc  */
#line 4953 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AposAttrContentList( LOC((yyloc)) );
    }
    break;

  case 512:
/* Line 670 of lalr1.cc  */
#line 4957 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 513:
/* Line 670 of lalr1.cc  */
#line 4964 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
      aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
      (yyval.node) = aacl;
    }
    break;

  case 514:
/* Line 670 of lalr1.cc  */
#line 4970 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
      aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = aacl;
    }
    break;

  case 515:
/* Line 670 of lalr1.cc  */
#line 4976 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
      if (aacl)
        aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 516:
/* Line 670 of lalr1.cc  */
#line 4983 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
      if ( aacl )
        aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 517:
/* Line 670 of lalr1.cc  */
#line 4994 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new QuoteAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
    }
    break;

  case 518:
/* Line 670 of lalr1.cc  */
#line 4998 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new QuoteAttrValueContent(LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
    }
    break;

  case 519:
/* Line 670 of lalr1.cc  */
#line 5006 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AposAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
    }
    break;

  case 520:
/* Line 670 of lalr1.cc  */
#line 5010 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AposAttrValueContent(LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
    }
    break;

  case 521:
/* Line 670 of lalr1.cc  */
#line 5018 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new DirElemContent( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr) );
    }
    break;

  case 522:
/* Line 670 of lalr1.cc  */
#line 5022 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new DirElemContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
    }
    break;

  case 523:
/* Line 670 of lalr1.cc  */
#line 5026 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      rchandle<CDataSection> cdata_h = dynamic_cast<CDataSection*>((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = new DirElemContent( LOC((yyloc)), cdata_h );
    }
    break;

  case 524:
/* Line 670 of lalr1.cc  */
#line 5031 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      rchandle<CommonContent> cont_h = dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = new DirElemContent( LOC((yyloc)), cont_h );
    }
    break;

  case 525:
/* Line 670 of lalr1.cc  */
#line 5040 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CommonContent(LOC((yyloc)), ParseConstants::cont_charref, SYMTAB((yysemantic_stack_[(1) - (1)].sval)));
    }
    break;

  case 526:
/* Line 670 of lalr1.cc  */
#line 5044 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CommonContent(LOC((yyloc)), ParseConstants::cont_escape_lbrace);
    }
    break;

  case 527:
/* Line 670 of lalr1.cc  */
#line 5048 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CommonContent(LOC((yyloc)), ParseConstants::cont_escape_rbrace);
    }
    break;

  case 528:
/* Line 670 of lalr1.cc  */
#line 5052 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CommonContent(LOC((yyloc)), new EnclosedExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr)));
    }
    break;

  case 529:
/* Line 670 of lalr1.cc  */
#line 5060 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 530:
/* Line 670 of lalr1.cc  */
#line 5065 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), "" );
    }
    break;

  case 531:
/* Line 670 of lalr1.cc  */
#line 5073 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new DirPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 532:
/* Line 670 of lalr1.cc  */
#line 5078 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new DirPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
    }
    break;

  case 533:
/* Line 670 of lalr1.cc  */
#line 5086 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CDataSection( LOC((yyloc)),SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
    }
    break;

  case 534:
/* Line 670 of lalr1.cc  */
#line 5094 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 535:
/* Line 670 of lalr1.cc  */
#line 5099 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 536:
/* Line 670 of lalr1.cc  */
#line 5104 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 537:
/* Line 670 of lalr1.cc  */
#line 5109 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 538:
/* Line 670 of lalr1.cc  */
#line 5114 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 539:
/* Line 670 of lalr1.cc  */
#line 5119 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 541:
/* Line 670 of lalr1.cc  */
#line 5130 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompDocConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
    }
    break;

  case 542:
/* Line 670 of lalr1.cc  */
#line 5138 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompElemConstructor(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval))), (yysemantic_stack_[(3) - (2)].expr));
    }
    break;

  case 543:
/* Line 670 of lalr1.cc  */
#line 5142 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompElemConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
    }
    break;

  case 544:
/* Line 670 of lalr1.cc  */
#line 5159 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval))), (yysemantic_stack_[(3) - (2)].expr) );
    }
    break;

  case 545:
/* Line 670 of lalr1.cc  */
#line 5163 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
    }
    break;

  case 546:
/* Line 670 of lalr1.cc  */
#line 5171 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompTextConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
    }
    break;

  case 547:
/* Line 670 of lalr1.cc  */
#line 5179 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompCommentConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
    }
    break;

  case 548:
/* Line 670 of lalr1.cc  */
#line 5187 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompPIConstructor(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval)), (yysemantic_stack_[(3) - (2)].expr));
    }
    break;

  case 549:
/* Line 670 of lalr1.cc  */
#line 5191 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompPIConstructor(LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
    }
    break;

  case 550:
/* Line 670 of lalr1.cc  */
#line 5199 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompNamespaceConstructor(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval)), (yysemantic_stack_[(3) - (2)].expr));
    }
    break;

  case 551:
/* Line 670 of lalr1.cc  */
#line 5203 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompNamespaceConstructor(LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
    }
    break;

  case 552:
/* Line 670 of lalr1.cc  */
#line 5211 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 553:
/* Line 670 of lalr1.cc  */
#line 5219 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL );
        }
    break;

  case 554:
/* Line 670 of lalr1.cc  */
#line 5223 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new SequenceType(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node)));
        }
    break;

  case 555:
/* Line 670 of lalr1.cc  */
#line 5227 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 556:
/* Line 670 of lalr1.cc  */
#line 5232 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 557:
/* Line 670 of lalr1.cc  */
#line 5267 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_optionally
            );
        }
    break;

  case 558:
/* Line 670 of lalr1.cc  */
#line 5273 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_zero_or_more
            );
        }
    break;

  case 559:
/* Line 670 of lalr1.cc  */
#line 5279 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_one_or_more
            );
        }
    break;

  case 560:
/* Line 670 of lalr1.cc  */
#line 5289 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 561:
/* Line 670 of lalr1.cc  */
#line 5293 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 562:
/* Line 670 of lalr1.cc  */
#line 5297 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ItemType( LOC((yyloc)), true );
        }
    break;

  case 563:
/* Line 670 of lalr1.cc  */
#line 5302 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ItemType( LOC((yyloc)), true );
        }
    break;

  case 564:
/* Line 670 of lalr1.cc  */
#line 5306 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new StructuredItemType(LOC((yyloc)));
        }
    break;

  case 565:
/* Line 670 of lalr1.cc  */
#line 5311 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new StructuredItemType(LOC((yyloc)));
        }
    break;

  case 566:
/* Line 670 of lalr1.cc  */
#line 5315 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 567:
/* Line 670 of lalr1.cc  */
#line 5319 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 568:
/* Line 670 of lalr1.cc  */
#line 5323 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 569:
/* Line 670 of lalr1.cc  */
#line 5330 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
          TypeList* aTypeList = new TypeList(LOC ((yyloc)));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(1) - (1)].node)));
          (yyval.node) = aTypeList;
        }
    break;

  case 570:
/* Line 670 of lalr1.cc  */
#line 5336 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
          TypeList* aTypeList = dynamic_cast<TypeList *>((yysemantic_stack_[(3) - (1)].node));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
          (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 571:
/* Line 670 of lalr1.cc  */
#line 5346 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new GeneralizedAtomicType( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
    }
    break;

  case 572:
/* Line 670 of lalr1.cc  */
#line 5354 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SimpleType( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
    }
    break;

  case 573:
/* Line 670 of lalr1.cc  */
#line 5362 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 574:
/* Line 670 of lalr1.cc  */
#line 5366 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 575:
/* Line 670 of lalr1.cc  */
#line 5370 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 576:
/* Line 670 of lalr1.cc  */
#line 5374 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 577:
/* Line 670 of lalr1.cc  */
#line 5378 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 578:
/* Line 670 of lalr1.cc  */
#line 5382 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 579:
/* Line 670 of lalr1.cc  */
#line 5386 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 580:
/* Line 670 of lalr1.cc  */
#line 5390 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 581:
/* Line 670 of lalr1.cc  */
#line 5394 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 582:
/* Line 670 of lalr1.cc  */
#line 5398 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 583:
/* Line 670 of lalr1.cc  */
#line 5406 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AnyKindTest( LOC((yyloc)) );
    }
    break;

  case 584:
/* Line 670 of lalr1.cc  */
#line 5414 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DocumentTest(LOC((yyloc)));
    }
    break;

  case 585:
/* Line 670 of lalr1.cc  */
#line 5418 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DocumentTest(LOC((yyloc)), dynamic_cast<ElementTest*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 586:
/* Line 670 of lalr1.cc  */
#line 5422 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DocumentTest(LOC((yyloc)), dynamic_cast<SchemaElementTest*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 587:
/* Line 670 of lalr1.cc  */
#line 5430 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new NamespaceTest(LOC((yyloc)));
    }
    break;

  case 588:
/* Line 670 of lalr1.cc  */
#line 5437 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new TextTest(LOC((yyloc)));
    }
    break;

  case 589:
/* Line 670 of lalr1.cc  */
#line 5445 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CommentTest(LOC((yyloc)));
    }
    break;

  case 590:
/* Line 670 of lalr1.cc  */
#line 5453 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), "" );
        }
    break;

  case 591:
/* Line 670 of lalr1.cc  */
#line 5457 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 592:
/* Line 670 of lalr1.cc  */
#line 5461 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 593:
/* Line 670 of lalr1.cc  */
#line 5469 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 594:
/* Line 670 of lalr1.cc  */
#line 5473 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL
            );
        }
    break;

  case 595:
/* Line 670 of lalr1.cc  */
#line 5479 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 596:
/* Line 670 of lalr1.cc  */
#line 5485 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 597:
/* Line 670 of lalr1.cc  */
#line 5489 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 598:
/* Line 670 of lalr1.cc  */
#line 5499 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new SchemaAttributeTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 599:
/* Line 670 of lalr1.cc  */
#line 5507 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ElementTest( LOC((yyloc)), NULL, NULL, true );
        }
    break;

  case 600:
/* Line 670 of lalr1.cc  */
#line 5511 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL, true
            );
        }
    break;

  case 601:
/* Line 670 of lalr1.cc  */
#line 5517 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                false
            );
        }
    break;

  case 602:
/* Line 670 of lalr1.cc  */
#line 5526 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                true
            );
        }
    break;

  case 603:
/* Line 670 of lalr1.cc  */
#line 5535 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, NULL, true
            );
        }
    break;

  case 604:
/* Line 670 of lalr1.cc  */
#line 5541 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), false
            );
        }
    break;

  case 605:
/* Line 670 of lalr1.cc  */
#line 5547 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), true
            );
        }
    break;

  case 606:
/* Line 670 of lalr1.cc  */
#line 5557 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new SchemaElementTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 607:
/* Line 670 of lalr1.cc  */
#line 5574 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 608:
/* Line 670 of lalr1.cc  */
#line 5581 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (1)].expr)), true );
        }
    break;

  case 609:
/* Line 670 of lalr1.cc  */
#line 5596 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new StringLiteral( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 610:
/* Line 670 of lalr1.cc  */
#line 5623 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 611:
/* Line 670 of lalr1.cc  */
#line 5627 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 612:
/* Line 670 of lalr1.cc  */
#line 5635 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AnyFunctionTest(LOC((yyloc)));
    }
    break;

  case 613:
/* Line 670 of lalr1.cc  */
#line 5643 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)), dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (5)].node)));
        }
    break;

  case 614:
/* Line 670 of lalr1.cc  */
#line 5647 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)),
              dynamic_cast<TypeList *>((yysemantic_stack_[(6) - (3)].node)),
              dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (6)].node)));
        }
    break;

  case 615:
/* Line 670 of lalr1.cc  */
#line 5658 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
           (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 616:
/* Line 670 of lalr1.cc  */
#line 5675 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::strict_validation
            );
        }
    break;

  case 617:
/* Line 670 of lalr1.cc  */
#line 5681 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::lax_validation
            );
        }
    break;

  case 618:
/* Line 670 of lalr1.cc  */
#line 5687 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::skip_validation
            );
        }
    break;

  case 619:
/* Line 670 of lalr1.cc  */
#line 5697 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 620:
/* Line 670 of lalr1.cc  */
#line 5701 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 621:
/* Line 670 of lalr1.cc  */
#line 5707 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 622:
/* Line 670 of lalr1.cc  */
#line 5713 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 623:
/* Line 670 of lalr1.cc  */
#line 5717 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 624:
/* Line 670 of lalr1.cc  */
#line 5723 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 625:
/* Line 670 of lalr1.cc  */
#line 5727 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 626:
/* Line 670 of lalr1.cc  */
#line 5733 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                  LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 627:
/* Line 670 of lalr1.cc  */
#line 5739 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)),
                store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 628:
/* Line 670 of lalr1.cc  */
#line 5746 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 629:
/* Line 670 of lalr1.cc  */
#line 5756 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 630:
/* Line 670 of lalr1.cc  */
#line 5761 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 631:
/* Line 670 of lalr1.cc  */
#line 5769 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::NODE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 632:
/* Line 670 of lalr1.cc  */
#line 5775 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::VALUE_OF_NODE, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 633:
/* Line 670 of lalr1.cc  */
#line 5785 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new RenameExpr( LOC ((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 634:
/* Line 670 of lalr1.cc  */
#line 5807 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      CopyVarList *cvl = dynamic_cast<CopyVarList*>((yysemantic_stack_[(7) - (3)].expr));
      (yyval.expr) = new TransformExpr( LOC((yyloc)), cvl, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr) );
    }
    break;

  case 635:
/* Line 670 of lalr1.cc  */
#line 5816 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      CopyVarList* lList = new CopyVarList(LOC((yyloc)));
      lList->push_back (dynamic_cast<VarBinding*> ((yysemantic_stack_[(1) - (1)].expr)));
      (yyval.expr) = lList;
    }
    break;

  case 636:
/* Line 670 of lalr1.cc  */
#line 5822 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      CopyVarList* lList = dynamic_cast<CopyVarList*>((yysemantic_stack_[(4) - (1)].expr));
      VarBinding* lBinding = dynamic_cast<VarBinding*>((yysemantic_stack_[(4) - (4)].expr));
      lList->push_back(lBinding);
      (yyval.expr) = lList;
    }
    break;

  case 637:
/* Line 670 of lalr1.cc  */
#line 5835 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new VarBinding(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 638:
/* Line 670 of lalr1.cc  */
#line 5849 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new TryExpr( LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 639:
/* Line 670 of lalr1.cc  */
#line 5856 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            CatchListExpr *cle = new CatchListExpr( LOC((yyloc)) );
            cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.expr) = cle;
        }
    break;

  case 640:
/* Line 670 of lalr1.cc  */
#line 5862 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
            if ( cle )
                cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
        }
    break;

  case 641:
/* Line 670 of lalr1.cc  */
#line 5872 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)), *(yysemantic_stack_[(3) - (2)].name_test_list), (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 642:
/* Line 670 of lalr1.cc  */
#line 5881 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 643:
/* Line 670 of lalr1.cc  */
#line 5889 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            CatchExpr::NameTestList *ntl = new CatchExpr::NameTestList;
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 644:
/* Line 670 of lalr1.cc  */
#line 5895 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            CatchExpr::NameTestList *ntl =
                static_cast<CatchExpr::NameTestList*>((yysemantic_stack_[(3) - (1)].name_test_list));
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 645:
/* Line 670 of lalr1.cc  */
#line 5913 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTSelection( LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), (yysemantic_stack_[(2) - (2)].pos_filter_list) );
            delete (yysemantic_stack_[(2) - (2)].pos_filter_list);
        }
    break;

  case 646:
/* Line 670 of lalr1.cc  */
#line 5921 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.pos_filter_list) = NULL;
        }
    break;

  case 647:
/* Line 670 of lalr1.cc  */
#line 5925 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.pos_filter_list) = (yysemantic_stack_[(1) - (1)].pos_filter_list);
        }
    break;

  case 648:
/* Line 670 of lalr1.cc  */
#line 5932 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.pos_filter_list) = new FTSelection::pos_filter_list_t;
            (yyval.pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 649:
/* Line 670 of lalr1.cc  */
#line 5937 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yysemantic_stack_[(2) - (1)].pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.pos_filter_list) = (yysemantic_stack_[(2) - (1)].pos_filter_list);
        }
    break;

  case 650:
/* Line 670 of lalr1.cc  */
#line 5945 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 651:
/* Line 670 of lalr1.cc  */
#line 5949 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTOr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 652:
/* Line 670 of lalr1.cc  */
#line 5956 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 653:
/* Line 670 of lalr1.cc  */
#line 5960 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTAnd( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 654:
/* Line 670 of lalr1.cc  */
#line 5967 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 655:
/* Line 670 of lalr1.cc  */
#line 5971 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTMildNot( LOC((yyloc)), (yysemantic_stack_[(4) - (1)].node), (yysemantic_stack_[(4) - (4)].node) );
        }
    break;

  case 656:
/* Line 670 of lalr1.cc  */
#line 5978 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 657:
/* Line 670 of lalr1.cc  */
#line 5982 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTUnaryNot(
                LOC((yyloc)), dynamic_cast<FTPrimaryWithOptions*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 658:
/* Line 670 of lalr1.cc  */
#line 5991 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTPrimaryWithOptions(
                LOC((yyloc)),
                dynamic_cast<FTPrimary*>((yysemantic_stack_[(3) - (1)].node)),
                dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<FTWeight*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 659:
/* Line 670 of lalr1.cc  */
#line 6003 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 660:
/* Line 670 of lalr1.cc  */
#line 6007 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 661:
/* Line 670 of lalr1.cc  */
#line 6014 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 662:
/* Line 670 of lalr1.cc  */
#line 6018 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 663:
/* Line 670 of lalr1.cc  */
#line 6026 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTWeight( LOC((yyloc)), dynamic_cast<exprnode*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 664:
/* Line 670 of lalr1.cc  */
#line 6034 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTWordsTimes(
                LOC((yyloc)),
                dynamic_cast<FTWords*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<FTTimes*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 665:
/* Line 670 of lalr1.cc  */
#line 6042 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 666:
/* Line 670 of lalr1.cc  */
#line 6046 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 667:
/* Line 670 of lalr1.cc  */
#line 6053 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 668:
/* Line 670 of lalr1.cc  */
#line 6057 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 669:
/* Line 670 of lalr1.cc  */
#line 6065 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTExtensionSelection(
                LOC((yyloc)),
                dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)),
                dynamic_cast<FTSelection*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 670:
/* Line 670 of lalr1.cc  */
#line 6076 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 671:
/* Line 670 of lalr1.cc  */
#line 6080 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 672:
/* Line 670 of lalr1.cc  */
#line 6088 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTWords(
                LOC((yyloc)),
                dynamic_cast<FTWordsValue*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<FTAnyallOption*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 673:
/* Line 670 of lalr1.cc  */
#line 6100 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), static_cast<StringLiteral*>((yysemantic_stack_[(1) - (1)].expr)), NULL
            );
        }
    break;

  case 674:
/* Line 670 of lalr1.cc  */
#line 6106 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), NULL, dynamic_cast<exprnode*>((yysemantic_stack_[(3) - (2)].expr))
            );
        }
    break;

  case 675:
/* Line 670 of lalr1.cc  */
#line 6115 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::any );
        }
    break;

  case 676:
/* Line 670 of lalr1.cc  */
#line 6119 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 677:
/* Line 670 of lalr1.cc  */
#line 6127 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 678:
/* Line 670 of lalr1.cc  */
#line 6131 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 679:
/* Line 670 of lalr1.cc  */
#line 6135 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::phrase );
        }
    break;

  case 680:
/* Line 670 of lalr1.cc  */
#line 6142 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any;
        }
    break;

  case 681:
/* Line 670 of lalr1.cc  */
#line 6146 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any_word;
        }
    break;

  case 682:
/* Line 670 of lalr1.cc  */
#line 6153 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all;
        }
    break;

  case 683:
/* Line 670 of lalr1.cc  */
#line 6157 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all_words;
        }
    break;

  case 684:
/* Line 670 of lalr1.cc  */
#line 6165 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 685:
/* Line 670 of lalr1.cc  */
#line 6169 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 686:
/* Line 670 of lalr1.cc  */
#line 6173 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 687:
/* Line 670 of lalr1.cc  */
#line 6177 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 688:
/* Line 670 of lalr1.cc  */
#line 6181 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 689:
/* Line 670 of lalr1.cc  */
#line 6189 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTOrder( LOC((yyloc)) );
        }
    break;

  case 690:
/* Line 670 of lalr1.cc  */
#line 6197 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTWindow(
                LOC((yyloc)),
                static_cast<AdditiveExpr*>((yysemantic_stack_[(3) - (2)].expr)),
                static_cast<FTUnit*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 691:
/* Line 670 of lalr1.cc  */
#line 6209 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTDistance(
                LOC((yyloc)),
                dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<FTUnit*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 692:
/* Line 670 of lalr1.cc  */
#line 6221 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::words );
        }
    break;

  case 693:
/* Line 670 of lalr1.cc  */
#line 6225 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::sentences );
        }
    break;

  case 694:
/* Line 670 of lalr1.cc  */
#line 6229 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::paragraphs );
        }
    break;

  case 695:
/* Line 670 of lalr1.cc  */
#line 6237 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            FTMatchOptions *mo = new FTMatchOptions( LOC((yyloc)) );
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = mo;
        }
    break;

  case 696:
/* Line 670 of lalr1.cc  */
#line 6243 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            FTMatchOptions *mo = dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (1)].node));
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 697:
/* Line 670 of lalr1.cc  */
#line 6253 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 698:
/* Line 670 of lalr1.cc  */
#line 6257 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 699:
/* Line 670 of lalr1.cc  */
#line 6261 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 700:
/* Line 670 of lalr1.cc  */
#line 6265 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 701:
/* Line 670 of lalr1.cc  */
#line 6269 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 702:
/* Line 670 of lalr1.cc  */
#line 6273 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 703:
/* Line 670 of lalr1.cc  */
#line 6277 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 704:
/* Line 670 of lalr1.cc  */
#line 6281 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 705:
/* Line 670 of lalr1.cc  */
#line 6289 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::sensitive );
        }
    break;

  case 706:
/* Line 670 of lalr1.cc  */
#line 6293 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::insensitive );
        }
    break;

  case 707:
/* Line 670 of lalr1.cc  */
#line 6297 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::lower );
        }
    break;

  case 708:
/* Line 670 of lalr1.cc  */
#line 6301 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::upper );
        }
    break;

  case 709:
/* Line 670 of lalr1.cc  */
#line 6309 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::sensitive
            );
        }
    break;

  case 710:
/* Line 670 of lalr1.cc  */
#line 6315 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::insensitive
            );
        }
    break;

  case 711:
/* Line 670 of lalr1.cc  */
#line 6325 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTExtensionOption(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval))
            );
        }
    break;

  case 712:
/* Line 670 of lalr1.cc  */
#line 6335 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::stemming );
        }
    break;

  case 713:
/* Line 670 of lalr1.cc  */
#line 6339 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::no_stemming );
        }
    break;

  case 714:
/* Line 670 of lalr1.cc  */
#line 6347 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            FTThesaurusOption::thesaurus_id_list_t *til = NULL;
            if ( (yysemantic_stack_[(2) - (2)].node) ) {
                til = new FTThesaurusOption::thesaurus_id_list_t;
                til->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(2) - (2)].node)) );
            }
            (yyval.node) = new FTThesaurusOption( LOC((yyloc)), til, !til );
            delete til;
        }
    break;

  case 715:
/* Line 670 of lalr1.cc  */
#line 6357 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            FTThesaurusOption::thesaurus_id_list_t *til = (yysemantic_stack_[(5) - (4)].thesaurus_id_list);
            if ( (yysemantic_stack_[(5) - (3)].node) ) {
                if ( !til )
                    til = new FTThesaurusOption::thesaurus_id_list_t;
                til->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(5) - (3)].node)) );
            }
            (yyval.node) = new FTThesaurusOption( LOC((yyloc)), til, !(yysemantic_stack_[(5) - (3)].node) );
            delete til;
        }
    break;

  case 716:
/* Line 670 of lalr1.cc  */
#line 6368 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTThesaurusOption( LOC((yyloc)), NULL, false, true );
        }
    break;

  case 717:
/* Line 670 of lalr1.cc  */
#line 6375 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 718:
/* Line 670 of lalr1.cc  */
#line 6379 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 719:
/* Line 670 of lalr1.cc  */
#line 6386 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.thesaurus_id_list) = NULL;
        }
    break;

  case 720:
/* Line 670 of lalr1.cc  */
#line 6390 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(2) - (2)].thesaurus_id_list);
        }
    break;

  case 721:
/* Line 670 of lalr1.cc  */
#line 6397 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.thesaurus_id_list) = new FTThesaurusOption::thesaurus_id_list_t;
            (yyval.thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 722:
/* Line 670 of lalr1.cc  */
#line 6402 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yysemantic_stack_[(3) - (1)].thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(3) - (1)].thesaurus_id_list);
        }
    break;

  case 723:
/* Line 670 of lalr1.cc  */
#line 6411 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTThesaurusID(
                LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (2)].sval)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), dynamic_cast<FTRange*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 724:
/* Line 670 of lalr1.cc  */
#line 6420 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.sval) = 0;
        }
    break;

  case 725:
/* Line 670 of lalr1.cc  */
#line 6424 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.sval) = (yysemantic_stack_[(2) - (2)].sval);
        }
    break;

  case 726:
/* Line 670 of lalr1.cc  */
#line 6431 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 727:
/* Line 670 of lalr1.cc  */
#line 6435 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 728:
/* Line 670 of lalr1.cc  */
#line 6443 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(4) - (3)].node)), (yysemantic_stack_[(4) - (4)].incl_excl_list),
                ft_stop_words_mode::with
            );
            delete (yysemantic_stack_[(4) - (4)].incl_excl_list);
        }
    break;

  case 729:
/* Line 670 of lalr1.cc  */
#line 6452 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, (yysemantic_stack_[(4) - (4)].incl_excl_list), ft_stop_words_mode::with_default
            );
            delete (yysemantic_stack_[(4) - (4)].incl_excl_list);
        }
    break;

  case 730:
/* Line 670 of lalr1.cc  */
#line 6459 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, NULL, ft_stop_words_mode::without
            );
        }
    break;

  case 731:
/* Line 670 of lalr1.cc  */
#line 6469 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), NULL );
        }
    break;

  case 732:
/* Line 670 of lalr1.cc  */
#line 6473 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), "", (yysemantic_stack_[(3) - (2)].strlist) );
        }
    break;

  case 733:
/* Line 670 of lalr1.cc  */
#line 6480 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            string_list_t *sl = new string_list_t;
            sl->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
            (yyval.strlist) = sl;
        }
    break;

  case 734:
/* Line 670 of lalr1.cc  */
#line 6486 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            if ( (yysemantic_stack_[(3) - (1)].strlist) )
                (yysemantic_stack_[(3) - (1)].strlist)->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
            (yyval.strlist) = (yysemantic_stack_[(3) - (1)].strlist);
        }
    break;

  case 735:
/* Line 670 of lalr1.cc  */
#line 6495 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.incl_excl_list) = NULL;
        }
    break;

  case 736:
/* Line 670 of lalr1.cc  */
#line 6499 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.incl_excl_list) = (yysemantic_stack_[(1) - (1)].incl_excl_list);
        }
    break;

  case 737:
/* Line 670 of lalr1.cc  */
#line 6506 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.incl_excl_list) = new FTStopWordOption::incl_excl_list_t;
            (yyval.incl_excl_list)->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 738:
/* Line 670 of lalr1.cc  */
#line 6511 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            FTStopWordOption::incl_excl_list_t *iel = (yysemantic_stack_[(2) - (1)].incl_excl_list);
            if ( !iel )
                iel = new FTStopWordOption::incl_excl_list_t;
            iel->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.incl_excl_list) = iel;
        }
    break;

  case 739:
/* Line 670 of lalr1.cc  */
#line 6523 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStopWordsInclExcl(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(2) - (2)].node)),
                ft_stop_words_unex::union_
            );
        }
    break;

  case 740:
/* Line 670 of lalr1.cc  */
#line 6531 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStopWordsInclExcl(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(2) - (2)].node)),
                ft_stop_words_unex::except
            );
        }
    break;

  case 741:
/* Line 670 of lalr1.cc  */
#line 6543 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTLanguageOption( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 742:
/* Line 670 of lalr1.cc  */
#line 6551 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::with );
        }
    break;

  case 743:
/* Line 670 of lalr1.cc  */
#line 6555 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::without );
        }
    break;

  case 744:
/* Line 670 of lalr1.cc  */
#line 6563 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_start );
        }
    break;

  case 745:
/* Line 670 of lalr1.cc  */
#line 6567 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_end );
        }
    break;

  case 746:
/* Line 670 of lalr1.cc  */
#line 6571 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::entire );
        }
    break;

  case 747:
/* Line 670 of lalr1.cc  */
#line 6579 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTTimes( LOC((yyloc)), dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)) );
        }
    break;

  case 748:
/* Line 670 of lalr1.cc  */
#line 6587 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::exactly, (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 749:
/* Line 670 of lalr1.cc  */
#line 6591 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_least, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 750:
/* Line 670 of lalr1.cc  */
#line 6595 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_most, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 751:
/* Line 670 of lalr1.cc  */
#line 6599 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::from_to, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr) );
        }
    break;

  case 752:
/* Line 670 of lalr1.cc  */
#line 6607 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTScope(
                LOC((yyloc)),
                ft_scope::same,
                dynamic_cast<FTBigUnit*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 753:
/* Line 670 of lalr1.cc  */
#line 6615 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTScope(
                LOC((yyloc)),
                ft_scope::different,
                dynamic_cast<FTBigUnit*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 754:
/* Line 670 of lalr1.cc  */
#line 6627 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::sentence );
        }
    break;

  case 755:
/* Line 670 of lalr1.cc  */
#line 6631 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::paragraph );
        }
    break;

  case 756:
/* Line 670 of lalr1.cc  */
#line 6639 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTIgnoreOption( LOC((yyloc)), static_cast<UnionExpr*>((yysemantic_stack_[(3) - (3)].expr)) );
        }
    break;

  case 757:
/* Line 670 of lalr1.cc  */
#line 6653 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONArrayConstructor( LOC((yyloc)), NULL );
        }
    break;

  case 758:
/* Line 670 of lalr1.cc  */
#line 6657 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONArrayConstructor( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 759:
/* Line 670 of lalr1.cc  */
#line 6664 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
          // TODO: fill in with the correct constructor
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), NULL, false);
        }
    break;

  case 760:
/* Line 670 of lalr1.cc  */
#line 6669 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
          // TODO: fill in with the correct constructor
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), false);
        }
    break;

  case 761:
/* Line 670 of lalr1.cc  */
#line 6677 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
          // TODO: fill in with the correct constructor
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), NULL, true);
        }
    break;

  case 762:
/* Line 670 of lalr1.cc  */
#line 6682 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
          // TODO: fill in with the correct constructor
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), true);
        }
    break;

  case 763:
/* Line 670 of lalr1.cc  */
#line 6691 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONDirectObjectConstructor(LOC((yyloc)),
                                               dynamic_cast<JSONPairList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 764:
/* Line 670 of lalr1.cc  */
#line 6703 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
          StringLiteral* sl = new StringLiteral( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval)) );
          JSONPairList* jpl = new JSONPairList(LOC((yyloc)));
          jpl->push_back(new JSONPairConstructor(LOC((yyloc)), sl, (yysemantic_stack_[(3) - (3)].expr)));
          (yyval.node) = jpl;
        }
    break;

  case 765:
/* Line 670 of lalr1.cc  */
#line 6710 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
          JSONPairList* jpl = new JSONPairList(LOC((yyloc)));
          jpl->push_back(new JSONPairConstructor(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)));
          (yyval.node) = jpl;
        }
    break;

  case 766:
/* Line 670 of lalr1.cc  */
#line 6716 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
          JSONPairList* jpl = dynamic_cast<JSONPairList*>((yysemantic_stack_[(5) - (1)].node));
          assert(jpl);
          jpl->push_back(new JSONPairConstructor(LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)));
          (yyval.node) = jpl;
        }
    break;

  case 767:
/* Line 670 of lalr1.cc  */
#line 6723 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
          JSONPairList* jpl = dynamic_cast<JSONPairList*>((yysemantic_stack_[(5) - (1)].node));
          assert(jpl);
          StringLiteral* sl = new StringLiteral( LOC((yyloc)), SYMTAB((yysemantic_stack_[(5) - (3)].sval)) );
          jpl->push_back(new JSONPairConstructor(LOC((yyloc)), sl, (yysemantic_stack_[(5) - (5)].expr)));
          (yyval.node) = jpl;
        }
    break;

  case 768:
/* Line 670 of lalr1.cc  */
#line 6734 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONObjectInsertExpr(LOC((yyloc)),
                                        (yysemantic_stack_[(5) - (3)].expr),
                                        (yysemantic_stack_[(5) - (5)].expr));
        }
    break;

  case 769:
/* Line 670 of lalr1.cc  */
#line 6740 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
          JSONPairList* jpl = dynamic_cast<JSONPairList*>((yysemantic_stack_[(5) - (3)].node));
          (yyval.expr) = new JSONObjectInsertExpr(
              LOC((yyloc)),
              new JSONDirectObjectConstructor(
                  LOC((yyloc)),
                  jpl),
              (yysemantic_stack_[(5) - (5)].expr));
        }
    break;

  case 770:
/* Line 670 of lalr1.cc  */
#line 6750 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONArrayInsertExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (5)].expr), (yysemantic_stack_[(8) - (8)].expr));
        }
    break;

  case 771:
/* Line 670 of lalr1.cc  */
#line 6755 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONObjectInsertExpr(LOC((yyloc)),
                                        (yysemantic_stack_[(4) - (2)].expr),
                                        (yysemantic_stack_[(4) - (4)].expr));
        }
    break;

  case 772:
/* Line 670 of lalr1.cc  */
#line 6761 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
          JSONPairList* jpl = dynamic_cast<JSONPairList*>((yysemantic_stack_[(4) - (2)].node));
          (yyval.expr) = new JSONObjectInsertExpr(
              LOC((yyloc)),
              new JSONDirectObjectConstructor(
                  LOC((yyloc)),
                  jpl),
              (yysemantic_stack_[(4) - (4)].expr));
        }
    break;

  case 773:
/* Line 670 of lalr1.cc  */
#line 6771 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONArrayInsertExpr(LOC((yyloc)), (yysemantic_stack_[(7) - (2)].expr), (yysemantic_stack_[(7) - (4)].expr), (yysemantic_stack_[(7) - (7)].expr));
        }
    break;

  case 774:
/* Line 670 of lalr1.cc  */
#line 6778 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONArrayAppendExpr(LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
        }
    break;

  case 775:
/* Line 670 of lalr1.cc  */
#line 6782 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONArrayAppendExpr(LOC((yyloc)), (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr));
        }
    break;

  case 776:
/* Line 670 of lalr1.cc  */
#line 6789 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
          rchandle<DynamicFunctionInvocation> lDynamicFunctionInvocation =
          dynamic_cast<DynamicFunctionInvocation*>((yysemantic_stack_[(3) - (3)].expr));

          if (lDynamicFunctionInvocation == NULL)
          {
            error((yylocation_stack_[(3) - (3)]), "An object invocation is expected. A filter was found instead.");
            YYERROR;
          }

          if (lDynamicFunctionInvocation->getArgList()->size() != 1)
          {
            error((yylocation_stack_[(3) - (3)]), "An object invocation with exactly one argument is expected. Zero or more than one argument were found.");
            YYERROR;
          }

          (yyval.expr) = new JSONDeleteExpr(
                LOC((yyloc)),
                lDynamicFunctionInvocation->getPrimaryExpr(),
                lDynamicFunctionInvocation->getArgList()->operator[](0));
        }
    break;

  case 777:
/* Line 670 of lalr1.cc  */
#line 6811 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
          rchandle<DynamicFunctionInvocation> lDynamicFunctionInvocation =
          dynamic_cast<DynamicFunctionInvocation*>((yysemantic_stack_[(2) - (2)].expr));

          if (lDynamicFunctionInvocation == NULL)
          {
            error((yylocation_stack_[(2) - (2)]), "An object invocation is expected. A filter was found instead.");
            YYERROR;
          }

          if (lDynamicFunctionInvocation->getArgList()->size() != 1)
          {
            error((yylocation_stack_[(2) - (2)]), "An object invocation with exactly one argument is expected. Zero or more than one argument were found.");
            YYERROR;
          }

          (yyval.expr) = new JSONDeleteExpr(
                LOC((yyloc)),
                lDynamicFunctionInvocation->getPrimaryExpr(),
                lDynamicFunctionInvocation->getArgList()->operator[](0));
        }
    break;

  case 778:
/* Line 670 of lalr1.cc  */
#line 6836 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
          rchandle<DynamicFunctionInvocation> lDynamicFunctionInvocation =
          dynamic_cast<DynamicFunctionInvocation*>((yysemantic_stack_[(5) - (3)].expr));

          if(lDynamicFunctionInvocation == NULL)
          {
            error((yylocation_stack_[(5) - (3)]), "An object invocation is expected. A filter was found instead.");
            delete (yysemantic_stack_[(5) - (5)].expr);
            YYERROR;
          }

          if (lDynamicFunctionInvocation->getArgList()->size() != 1)
          {
            error((yylocation_stack_[(5) - (3)]), "An object invocation with exactly one argument is expected. Zero or more than one argument were found.");
            delete (yysemantic_stack_[(5) - (5)].expr);
            YYERROR;
          }

          (yyval.expr) = new JSONRenameExpr(
                LOC((yyloc)),
                lDynamicFunctionInvocation->getPrimaryExpr(),
                lDynamicFunctionInvocation->getArgList()->operator[](0),
                (yysemantic_stack_[(5) - (5)].expr));
        }
    break;

  case 779:
/* Line 670 of lalr1.cc  */
#line 6861 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
          rchandle<DynamicFunctionInvocation> lDynamicFunctionInvocation =
          dynamic_cast<DynamicFunctionInvocation*>((yysemantic_stack_[(4) - (2)].expr));

          if(lDynamicFunctionInvocation == NULL)
          {
            error((yylocation_stack_[(4) - (2)]), "An object invocation is expected. A filter was found instead.");
            delete (yysemantic_stack_[(4) - (4)].expr);
            YYERROR;
          }

          if (lDynamicFunctionInvocation->getArgList()->size() != 1)
          {
            error((yylocation_stack_[(4) - (2)]), "An object invocation with exactly one argument is expected. Zero or more than one argument were found.");
            delete (yysemantic_stack_[(4) - (4)].expr);
            YYERROR;
          }

          (yyval.expr) = new JSONRenameExpr(
                LOC((yyloc)),
                lDynamicFunctionInvocation->getPrimaryExpr(),
                lDynamicFunctionInvocation->getArgList()->operator[](0),
                (yysemantic_stack_[(4) - (4)].expr));
        }
    break;

  case 780:
/* Line 670 of lalr1.cc  */
#line 6889 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
          rchandle<DynamicFunctionInvocation> lDynamicFunctionInvocation =
          dynamic_cast<DynamicFunctionInvocation*>((yysemantic_stack_[(7) - (5)].expr));

          if(lDynamicFunctionInvocation == NULL)
          {
            error((yylocation_stack_[(7) - (3)]), "An object invocation is expected. A filter was found instead.");
            delete (yysemantic_stack_[(7) - (7)].expr);
            YYERROR;
          }

          if (lDynamicFunctionInvocation->getArgList()->size() != 1)
          {
            error((yylocation_stack_[(7) - (3)]), "An object invocation with exactly one argument is expected. Zero or more than one argument were found.");
            delete (yysemantic_stack_[(7) - (7)].expr);
            YYERROR;
          }

          (yyval.expr) = new JSONReplaceExpr(
                LOC((yyloc)),
                lDynamicFunctionInvocation->getPrimaryExpr(),
                lDynamicFunctionInvocation->getArgList()->operator[](0),
                (yysemantic_stack_[(7) - (7)].expr));
        }
    break;

  case 781:
/* Line 670 of lalr1.cc  */
#line 6914 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
          rchandle<DynamicFunctionInvocation> lDynamicFunctionInvocation =
          dynamic_cast<DynamicFunctionInvocation*>((yysemantic_stack_[(6) - (4)].expr));

          if(lDynamicFunctionInvocation == NULL)
          {
            error((yylocation_stack_[(6) - (2)]), "An object invocation is expected. A filter was found instead.");
            delete (yysemantic_stack_[(6) - (6)].expr);
            YYERROR;
          }

          if (lDynamicFunctionInvocation->getArgList()->size() != 1)
          {
            error((yylocation_stack_[(6) - (2)]), "An object invocation with exactly one argument is expected. Zero or more than one argument were found.");
            delete (yysemantic_stack_[(6) - (6)].expr);
            YYERROR;
          }

          (yyval.expr) = new JSONReplaceExpr(
                LOC((yyloc)),
                lDynamicFunctionInvocation->getPrimaryExpr(),
                lDynamicFunctionInvocation->getArgList()->operator[](0),
                (yysemantic_stack_[(6) - (6)].expr));
        }
    break;

  case 782:
/* Line 670 of lalr1.cc  */
#line 6942 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 783:
/* Line 670 of lalr1.cc  */
#line 6946 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 784:
/* Line 670 of lalr1.cc  */
#line 6950 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 785:
/* Line 670 of lalr1.cc  */
#line 6957 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonItem);
        }
    break;

  case 786:
/* Line 670 of lalr1.cc  */
#line 6962 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonItem);
        }
    break;

  case 787:
/* Line 670 of lalr1.cc  */
#line 6969 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonObject);
        }
    break;

  case 788:
/* Line 670 of lalr1.cc  */
#line 6974 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonObject);
        }
    break;

  case 789:
/* Line 670 of lalr1.cc  */
#line 6981 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonArray);
        }
    break;

  case 790:
/* Line 670 of lalr1.cc  */
#line 6986 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonArray);
        }
    break;

  case 793:
/* Line 670 of lalr1.cc  */
#line 7003 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    {
          auto_ptr<QName> lQName( static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
          zstring const &tmp = lQName->get_qname();
          if ( tmp.find (':') != string::npos ) {
            error((yylocation_stack_[(1) - (1)]), "A NCName is expected, found a QName");
            YYERROR;
          }
          (yyval.sval) = SYMTAB_PUT(tmp.c_str());
        }
    break;

  case 795:
/* Line 670 of lalr1.cc  */
#line 7016 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("attribute"))); }
    break;

  case 796:
/* Line 670 of lalr1.cc  */
#line 7017 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("comment"))); }
    break;

  case 797:
/* Line 670 of lalr1.cc  */
#line 7018 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("document-node"))); }
    break;

  case 798:
/* Line 670 of lalr1.cc  */
#line 7019 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("namespace-node"))); }
    break;

  case 799:
/* Line 670 of lalr1.cc  */
#line 7020 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("element"))); }
    break;

  case 800:
/* Line 670 of lalr1.cc  */
#line 7022 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("if"))); }
    break;

  case 801:
/* Line 670 of lalr1.cc  */
#line 7023 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("node"))); }
    break;

  case 802:
/* Line 670 of lalr1.cc  */
#line 7024 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("processing-instruction"))); }
    break;

  case 803:
/* Line 670 of lalr1.cc  */
#line 7025 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema-attribute"))); }
    break;

  case 804:
/* Line 670 of lalr1.cc  */
#line 7026 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema-element"))); }
    break;

  case 805:
/* Line 670 of lalr1.cc  */
#line 7027 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("text"))); }
    break;

  case 806:
/* Line 670 of lalr1.cc  */
#line 7028 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("typeswitch"))); }
    break;

  case 807:
/* Line 670 of lalr1.cc  */
#line 7029 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("switch"))); }
    break;

  case 808:
/* Line 670 of lalr1.cc  */
#line 7030 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("empty-sequence"))); }
    break;

  case 809:
/* Line 670 of lalr1.cc  */
#line 7031 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("while"))); }
    break;

  case 811:
/* Line 670 of lalr1.cc  */
#line 7036 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))); }
    break;

  case 812:
/* Line 670 of lalr1.cc  */
#line 7037 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("xquery"))); }
    break;

  case 813:
/* Line 670 of lalr1.cc  */
#line 7038 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("empty"))); }
    break;

  case 814:
/* Line 670 of lalr1.cc  */
#line 7039 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("boundary-space"))); }
    break;

  case 815:
/* Line 670 of lalr1.cc  */
#line 7040 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ft-option"))); }
    break;

  case 816:
/* Line 670 of lalr1.cc  */
#line 7041 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("base-uri"))); }
    break;

  case 817:
/* Line 670 of lalr1.cc  */
#line 7042 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lax"))); }
    break;

  case 818:
/* Line 670 of lalr1.cc  */
#line 7043 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("strict"))); }
    break;

  case 819:
/* Line 670 of lalr1.cc  */
#line 7044 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("idiv"))); }
    break;

  case 820:
/* Line 670 of lalr1.cc  */
#line 7045 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("document"))); }
    break;

  case 821:
/* Line 670 of lalr1.cc  */
#line 7046 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ftnot"))); }
    break;

  case 822:
/* Line 670 of lalr1.cc  */
#line 7047 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("not"))); }
    break;

  case 823:
/* Line 670 of lalr1.cc  */
#line 7048 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sensitive"))); }
    break;

  case 824:
/* Line 670 of lalr1.cc  */
#line 7049 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("insensitive"))); }
    break;

  case 825:
/* Line 670 of lalr1.cc  */
#line 7050 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("diacritics"))); }
    break;

  case 826:
/* Line 670 of lalr1.cc  */
#line 7051 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("without"))); }
    break;

  case 827:
/* Line 670 of lalr1.cc  */
#line 7052 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stemming"))); }
    break;

  case 828:
/* Line 670 of lalr1.cc  */
#line 7053 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("thesaurus"))); }
    break;

  case 829:
/* Line 670 of lalr1.cc  */
#line 7054 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stop"))); }
    break;

  case 830:
/* Line 670 of lalr1.cc  */
#line 7055 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("wildcards"))); }
    break;

  case 831:
/* Line 670 of lalr1.cc  */
#line 7056 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("entire"))); }
    break;

  case 832:
/* Line 670 of lalr1.cc  */
#line 7057 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("content"))); }
    break;

  case 833:
/* Line 670 of lalr1.cc  */
#line 7058 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("word"))); }
    break;

  case 834:
/* Line 670 of lalr1.cc  */
#line 7059 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("start"))); }
    break;

  case 835:
/* Line 670 of lalr1.cc  */
#line 7060 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("end"))); }
    break;

  case 836:
/* Line 670 of lalr1.cc  */
#line 7061 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("most"))); }
    break;

  case 837:
/* Line 670 of lalr1.cc  */
#line 7062 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("skip"))); }
    break;

  case 838:
/* Line 670 of lalr1.cc  */
#line 7063 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("copy"))); }
    break;

  case 839:
/* Line 670 of lalr1.cc  */
#line 7064 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("general"))); }
    break;

  case 840:
/* Line 670 of lalr1.cc  */
#line 7065 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("value"))); }
    break;

  case 841:
/* Line 670 of lalr1.cc  */
#line 7066 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("eq"))); }
    break;

  case 842:
/* Line 670 of lalr1.cc  */
#line 7067 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ne"))); }
    break;

  case 843:
/* Line 670 of lalr1.cc  */
#line 7068 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lt"))); }
    break;

  case 844:
/* Line 670 of lalr1.cc  */
#line 7069 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("le"))); }
    break;

  case 845:
/* Line 670 of lalr1.cc  */
#line 7070 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("gt"))); }
    break;

  case 846:
/* Line 670 of lalr1.cc  */
#line 7071 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ge"))); }
    break;

  case 847:
/* Line 670 of lalr1.cc  */
#line 7072 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("at"))); }
    break;

  case 848:
/* Line 670 of lalr1.cc  */
#line 7073 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("context"))); }
    break;

  case 849:
/* Line 670 of lalr1.cc  */
#line 7074 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("variable"))); }
    break;

  case 850:
/* Line 670 of lalr1.cc  */
#line 7075 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("return"))); }
    break;

  case 851:
/* Line 670 of lalr1.cc  */
#line 7076 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("for"))); }
    break;

  case 852:
/* Line 670 of lalr1.cc  */
#line 7077 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("allowing"))); }
    break;

  case 853:
/* Line 670 of lalr1.cc  */
#line 7078 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sliding"))); }
    break;

  case 854:
/* Line 670 of lalr1.cc  */
#line 7079 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("tumbling"))); }
    break;

  case 855:
/* Line 670 of lalr1.cc  */
#line 7080 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("previous"))); }
    break;

  case 856:
/* Line 670 of lalr1.cc  */
#line 7081 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("next"))); }
    break;

  case 857:
/* Line 670 of lalr1.cc  */
#line 7082 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("only"))); }
    break;

  case 858:
/* Line 670 of lalr1.cc  */
#line 7083 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("when"))); }
    break;

  case 859:
/* Line 670 of lalr1.cc  */
#line 7084 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("count"))); }
    break;

  case 860:
/* Line 670 of lalr1.cc  */
#line 7085 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("in"))); }
    break;

  case 861:
/* Line 670 of lalr1.cc  */
#line 7086 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("let"))); }
    break;

  case 862:
/* Line 670 of lalr1.cc  */
#line 7087 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("where"))); }
    break;

  case 863:
/* Line 670 of lalr1.cc  */
#line 7088 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("by"))); }
    break;

  case 864:
/* Line 670 of lalr1.cc  */
#line 7089 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("group"))); }
    break;

  case 865:
/* Line 670 of lalr1.cc  */
#line 7090 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("order"))); }
    break;

  case 866:
/* Line 670 of lalr1.cc  */
#line 7091 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stable"))); }
    break;

  case 867:
/* Line 670 of lalr1.cc  */
#line 7092 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ascending"))); }
    break;

  case 868:
/* Line 670 of lalr1.cc  */
#line 7093 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descending"))); }
    break;

  case 869:
/* Line 670 of lalr1.cc  */
#line 7094 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("greatest"))); }
    break;

  case 870:
/* Line 670 of lalr1.cc  */
#line 7095 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("least"))); }
    break;

  case 871:
/* Line 670 of lalr1.cc  */
#line 7096 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("collation"))); }
    break;

  case 872:
/* Line 670 of lalr1.cc  */
#line 7097 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("some"))); }
    break;

  case 873:
/* Line 670 of lalr1.cc  */
#line 7098 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("every"))); }
    break;

  case 874:
/* Line 670 of lalr1.cc  */
#line 7099 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("satisfies"))); }
    break;

  case 875:
/* Line 670 of lalr1.cc  */
#line 7100 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("case"))); }
    break;

  case 876:
/* Line 670 of lalr1.cc  */
#line 7101 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("as"))); }
    break;

  case 877:
/* Line 670 of lalr1.cc  */
#line 7102 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("then"))); }
    break;

  case 878:
/* Line 670 of lalr1.cc  */
#line 7103 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("else"))); }
    break;

  case 879:
/* Line 670 of lalr1.cc  */
#line 7104 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("or"))); }
    break;

  case 880:
/* Line 670 of lalr1.cc  */
#line 7105 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("and"))); }
    break;

  case 881:
/* Line 670 of lalr1.cc  */
#line 7106 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("instance"))); }
    break;

  case 882:
/* Line 670 of lalr1.cc  */
#line 7107 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("of"))); }
    break;

  case 883:
/* Line 670 of lalr1.cc  */
#line 7108 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("castable"))); }
    break;

  case 884:
/* Line 670 of lalr1.cc  */
#line 7109 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("to"))); }
    break;

  case 885:
/* Line 670 of lalr1.cc  */
#line 7110 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("div"))); }
    break;

  case 886:
/* Line 670 of lalr1.cc  */
#line 7111 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("mod"))); }
    break;

  case 887:
/* Line 670 of lalr1.cc  */
#line 7112 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("union"))); }
    break;

  case 888:
/* Line 670 of lalr1.cc  */
#line 7113 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("intersect"))); }
    break;

  case 889:
/* Line 670 of lalr1.cc  */
#line 7114 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("except"))); }
    break;

  case 890:
/* Line 670 of lalr1.cc  */
#line 7115 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("validate"))); }
    break;

  case 891:
/* Line 670 of lalr1.cc  */
#line 7116 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("type"))); }
    break;

  case 892:
/* Line 670 of lalr1.cc  */
#line 7117 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("cast"))); }
    break;

  case 893:
/* Line 670 of lalr1.cc  */
#line 7118 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("treat"))); }
    break;

  case 894:
/* Line 670 of lalr1.cc  */
#line 7119 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("is"))); }
    break;

  case 895:
/* Line 670 of lalr1.cc  */
#line 7120 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preserve"))); }
    break;

  case 896:
/* Line 670 of lalr1.cc  */
#line 7121 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("strip"))); }
    break;

  case 897:
/* Line 670 of lalr1.cc  */
#line 7122 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("namespace"))); }
    break;

  case 898:
/* Line 670 of lalr1.cc  */
#line 7123 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("external"))); }
    break;

  case 899:
/* Line 670 of lalr1.cc  */
#line 7124 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("encoding"))); }
    break;

  case 900:
/* Line 670 of lalr1.cc  */
#line 7125 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("no-preserve"))); }
    break;

  case 901:
/* Line 670 of lalr1.cc  */
#line 7126 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("inherit"))); }
    break;

  case 902:
/* Line 670 of lalr1.cc  */
#line 7127 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("no-inherit"))); }
    break;

  case 903:
/* Line 670 of lalr1.cc  */
#line 7128 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("declare"))); }
    break;

  case 904:
/* Line 670 of lalr1.cc  */
#line 7129 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("construction"))); }
    break;

  case 905:
/* Line 670 of lalr1.cc  */
#line 7130 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ordering"))); }
    break;

  case 906:
/* Line 670 of lalr1.cc  */
#line 7131 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("default"))); }
    break;

  case 907:
/* Line 670 of lalr1.cc  */
#line 7132 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("copy-namespaces"))); }
    break;

  case 908:
/* Line 670 of lalr1.cc  */
#line 7133 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("option"))); }
    break;

  case 909:
/* Line 670 of lalr1.cc  */
#line 7134 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("version"))); }
    break;

  case 910:
/* Line 670 of lalr1.cc  */
#line 7135 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("import"))); }
    break;

  case 911:
/* Line 670 of lalr1.cc  */
#line 7136 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema"))); }
    break;

  case 912:
/* Line 670 of lalr1.cc  */
#line 7137 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("module"))); }
    break;

  case 913:
/* Line 670 of lalr1.cc  */
#line 7138 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("function"))); }
    break;

  case 914:
/* Line 670 of lalr1.cc  */
#line 7139 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("score"))); }
    break;

  case 915:
/* Line 670 of lalr1.cc  */
#line 7140 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("contains"))); }
    break;

  case 916:
/* Line 670 of lalr1.cc  */
#line 7141 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("weight"))); }
    break;

  case 917:
/* Line 670 of lalr1.cc  */
#line 7142 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("window"))); }
    break;

  case 918:
/* Line 670 of lalr1.cc  */
#line 7143 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("distance"))); }
    break;

  case 919:
/* Line 670 of lalr1.cc  */
#line 7144 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("occurs"))); }
    break;

  case 920:
/* Line 670 of lalr1.cc  */
#line 7145 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("times"))); }
    break;

  case 921:
/* Line 670 of lalr1.cc  */
#line 7146 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("same"))); }
    break;

  case 922:
/* Line 670 of lalr1.cc  */
#line 7147 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("different"))); }
    break;

  case 923:
/* Line 670 of lalr1.cc  */
#line 7148 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lowercase"))); }
    break;

  case 924:
/* Line 670 of lalr1.cc  */
#line 7149 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("uppercase"))); }
    break;

  case 925:
/* Line 670 of lalr1.cc  */
#line 7150 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("relationship"))); }
    break;

  case 926:
/* Line 670 of lalr1.cc  */
#line 7151 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("levels"))); }
    break;

  case 927:
/* Line 670 of lalr1.cc  */
#line 7152 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("language"))); }
    break;

  case 928:
/* Line 670 of lalr1.cc  */
#line 7153 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("any"))); }
    break;

  case 929:
/* Line 670 of lalr1.cc  */
#line 7154 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("all"))); }
    break;

  case 930:
/* Line 670 of lalr1.cc  */
#line 7155 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("exactly"))); }
    break;

  case 931:
/* Line 670 of lalr1.cc  */
#line 7156 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("from"))); }
    break;

  case 932:
/* Line 670 of lalr1.cc  */
#line 7157 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("words"))); }
    break;

  case 933:
/* Line 670 of lalr1.cc  */
#line 7158 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sentences"))); }
    break;

  case 934:
/* Line 670 of lalr1.cc  */
#line 7159 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sentence"))); }
    break;

  case 935:
/* Line 670 of lalr1.cc  */
#line 7160 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("phrase"))); }
    break;

  case 936:
/* Line 670 of lalr1.cc  */
#line 7161 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("paragraph"))); }
    break;

  case 937:
/* Line 670 of lalr1.cc  */
#line 7162 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("paragraphs"))); }
    break;

  case 938:
/* Line 670 of lalr1.cc  */
#line 7164 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("modify"))); }
    break;

  case 939:
/* Line 670 of lalr1.cc  */
#line 7165 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("first"))); }
    break;

  case 940:
/* Line 670 of lalr1.cc  */
#line 7167 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("before"))); }
    break;

  case 941:
/* Line 670 of lalr1.cc  */
#line 7168 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("after"))); }
    break;

  case 942:
/* Line 670 of lalr1.cc  */
#line 7169 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("revalidation"))); }
    break;

  case 943:
/* Line 670 of lalr1.cc  */
#line 7170 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("with"))); }
    break;

  case 944:
/* Line 670 of lalr1.cc  */
#line 7171 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("nodes"))); }
    break;

  case 945:
/* Line 670 of lalr1.cc  */
#line 7173 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("last"))); }
    break;

  case 946:
/* Line 670 of lalr1.cc  */
#line 7175 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("into"))); }
    break;

  case 947:
/* Line 670 of lalr1.cc  */
#line 7176 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("simple"))); }
    break;

  case 948:
/* Line 670 of lalr1.cc  */
#line 7177 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sequential"))); }
    break;

  case 949:
/* Line 670 of lalr1.cc  */
#line 7178 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("updating"))); }
    break;

  case 950:
/* Line 670 of lalr1.cc  */
#line 7179 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ordered"))); }
    break;

  case 951:
/* Line 670 of lalr1.cc  */
#line 7180 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("unordered"))); }
    break;

  case 952:
/* Line 670 of lalr1.cc  */
#line 7181 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("returning"))); }
    break;

  case 953:
/* Line 670 of lalr1.cc  */
#line 7182 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("exit"))); }
    break;

  case 954:
/* Line 670 of lalr1.cc  */
#line 7183 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("loop"))); }
    break;

  case 955:
/* Line 670 of lalr1.cc  */
#line 7184 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("break"))); }
    break;

  case 956:
/* Line 670 of lalr1.cc  */
#line 7185 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("continue"))); }
    break;

  case 957:
/* Line 670 of lalr1.cc  */
#line 7186 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("try"))); }
    break;

  case 958:
/* Line 670 of lalr1.cc  */
#line 7187 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("catch"))); }
    break;

  case 959:
/* Line 670 of lalr1.cc  */
#line 7188 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("using"))); }
    break;

  case 960:
/* Line 670 of lalr1.cc  */
#line 7189 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("set"))); }
    break;

  case 961:
/* Line 670 of lalr1.cc  */
#line 7190 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("index"))); }
    break;

  case 962:
/* Line 670 of lalr1.cc  */
#line 7191 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("unique"))); }
    break;

  case 963:
/* Line 670 of lalr1.cc  */
#line 7192 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("non"))); }
    break;

  case 964:
/* Line 670 of lalr1.cc  */
#line 7193 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("on"))); }
    break;

  case 965:
/* Line 670 of lalr1.cc  */
#line 7194 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("range"))); }
    break;

  case 966:
/* Line 670 of lalr1.cc  */
#line 7195 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("equality"))); }
    break;

  case 967:
/* Line 670 of lalr1.cc  */
#line 7196 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("manually"))); }
    break;

  case 968:
/* Line 670 of lalr1.cc  */
#line 7197 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("automatically"))); }
    break;

  case 969:
/* Line 670 of lalr1.cc  */
#line 7198 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("maintained"))); }
    break;

  case 970:
/* Line 670 of lalr1.cc  */
#line 7199 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("decimal-format"))); }
    break;

  case 971:
/* Line 670 of lalr1.cc  */
#line 7200 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("decimal-separator"))); }
    break;

  case 972:
/* Line 670 of lalr1.cc  */
#line 7201 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("grouping-separator"))); }
    break;

  case 973:
/* Line 670 of lalr1.cc  */
#line 7202 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("infinity"))); }
    break;

  case 974:
/* Line 670 of lalr1.cc  */
#line 7203 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("minus-sign"))); }
    break;

  case 975:
/* Line 670 of lalr1.cc  */
#line 7204 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("NaN"))); }
    break;

  case 976:
/* Line 670 of lalr1.cc  */
#line 7205 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("percent"))); }
    break;

  case 977:
/* Line 670 of lalr1.cc  */
#line 7206 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("per-mille"))); }
    break;

  case 978:
/* Line 670 of lalr1.cc  */
#line 7207 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("zero-digit"))); }
    break;

  case 979:
/* Line 670 of lalr1.cc  */
#line 7208 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("digit"))); }
    break;

  case 980:
/* Line 670 of lalr1.cc  */
#line 7209 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("pattern-separator"))); }
    break;

  case 981:
/* Line 670 of lalr1.cc  */
#line 7210 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("collection"))); }
    break;

  case 982:
/* Line 670 of lalr1.cc  */
#line 7211 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("const"))); }
    break;

  case 983:
/* Line 670 of lalr1.cc  */
#line 7212 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("append-only"))); }
    break;

  case 984:
/* Line 670 of lalr1.cc  */
#line 7213 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("queue"))); }
    break;

  case 985:
/* Line 670 of lalr1.cc  */
#line 7214 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("mutable"))); }
    break;

  case 986:
/* Line 670 of lalr1.cc  */
#line 7215 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("read-only"))); }
    break;

  case 987:
/* Line 670 of lalr1.cc  */
#line 7216 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("integrity"))); }
    break;

  case 988:
/* Line 670 of lalr1.cc  */
#line 7217 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("constraint"))); }
    break;

  case 989:
/* Line 670 of lalr1.cc  */
#line 7218 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("check"))); }
    break;

  case 990:
/* Line 670 of lalr1.cc  */
#line 7219 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("key"))); }
    break;

  case 991:
/* Line 670 of lalr1.cc  */
#line 7220 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("foreach"))); }
    break;

  case 992:
/* Line 670 of lalr1.cc  */
#line 7221 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("foreign"))); }
    break;

  case 993:
/* Line 670 of lalr1.cc  */
#line 7222 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("keys"))); }
    break;

  case 994:
/* Line 670 of lalr1.cc  */
#line 7223 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ancestor"))); }
    break;

  case 995:
/* Line 670 of lalr1.cc  */
#line 7224 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("child"))); }
    break;

  case 996:
/* Line 670 of lalr1.cc  */
#line 7225 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descendant"))); }
    break;

  case 997:
/* Line 670 of lalr1.cc  */
#line 7226 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("parent"))); }
    break;

  case 998:
/* Line 670 of lalr1.cc  */
#line 7227 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preceding"))); }
    break;

  case 999:
/* Line 670 of lalr1.cc  */
#line 7228 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("self"))); }
    break;

  case 1000:
/* Line 670 of lalr1.cc  */
#line 7229 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("following"))); }
    break;

  case 1001:
/* Line 670 of lalr1.cc  */
#line 7230 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ancestor-or-self"))); }
    break;

  case 1002:
/* Line 670 of lalr1.cc  */
#line 7231 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descendant-or-self"))); }
    break;

  case 1003:
/* Line 670 of lalr1.cc  */
#line 7232 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("following-sibling"))); }
    break;

  case 1004:
/* Line 670 of lalr1.cc  */
#line 7233 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preceding-sibling"))); }
    break;

  case 1005:
/* Line 670 of lalr1.cc  */
#line 7236 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("position"))); }
    break;

  case 1006:
/* Line 670 of lalr1.cc  */
#line 7245 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), true); }
    break;


/* Line 670 of lalr1.cc  */
#line 10635 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
      default:
        break;
      }

    /* User semantic actions sometimes alter yychar, and that requires
       that yytoken be updated with the new translation.  We take the
       approach of translating immediately before every use of yytoken.
       One alternative is translating here after every semantic action,
       but that translation would be missed if the semantic action
       invokes YYABORT, YYACCEPT, or YYERROR immediately after altering
       yychar.  In the case of YYABORT or YYACCEPT, an incorrect
       destructor might then be invoked immediately.  In the case of
       YYERROR, subsequent parser actions might lead to an incorrect
       destructor call or verbose syntax error message before the
       lookahead is translated.  */
    YY_SYMBOL_PRINT ("-> $$ =", yyr1_[yyn], &yyval, &yyloc);

    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();

    yysemantic_stack_.push (yyval);
    yylocation_stack_.push (yyloc);

    /* Shift the result of the reduction.  */
    yyn = yyr1_[yyn];
    yystate = yypgoto_[yyn - yyntokens_] + yystate_stack_[0];
    if (0 <= yystate && yystate <= yylast_
	&& yycheck_[yystate] == yystate_stack_[0])
      yystate = yytable_[yystate];
    else
      yystate = yydefgoto_[yyn - yyntokens_];
    goto yynewstate;

  /*------------------------------------.
  | yyerrlab -- here on detecting error |
  `------------------------------------*/
  yyerrlab:
    /* Make sure we have latest lookahead translation.  See comments at
       user semantic actions for why this is necessary.  */
    yytoken = yytranslate_ (yychar);

    /* If not already recovering from an error, report this error.  */
    if (!yyerrstatus_)
      {
	++yynerrs_;
	if (yychar == yyempty_)
	  yytoken = yyempty_;
	error (yylloc, yysyntax_error_ (yystate, yytoken));
      }

    yyerror_range[1] = yylloc;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */
        if (yychar <= yyeof_)
          {
            /* Return failure if at end of input.  */
            if (yychar == yyeof_)
              YYABORT;
          }
        else
          {
            yydestruct_ ("Error: discarding", yytoken, &yylval, &yylloc);
            yychar = yyempty_;
          }
      }

    /* Else will try to reuse lookahead token after shifting the error
       token.  */
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:

    /* Pacify compilers like GCC when the user code never invokes
       YYERROR and the label yyerrorlab therefore never appears in user
       code.  */
    if (false)
      goto yyerrorlab;

    yyerror_range[1] = yylocation_stack_[yylen - 1];
    /* Do not reclaim the symbols of the rule which action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    yystate = yystate_stack_[0];
    goto yyerrlab1;

  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;	/* Each real token shifted decrements this.  */

    for (;;)
      {
	yyn = yypact_[yystate];
	if (!yy_pact_value_is_default_ (yyn))
	{
	  yyn += yyterror_;
	  if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
	    {
	      yyn = yytable_[yyn];
	      if (0 < yyn)
		break;
	    }
	}

	/* Pop the current state because it cannot handle the error token.  */
	if (yystate_stack_.height () == 1)
	  YYABORT;

	yyerror_range[1] = yylocation_stack_[0];
	yydestruct_ ("Error: popping",
		     yystos_[yystate],
		     &yysemantic_stack_[0], &yylocation_stack_[0]);
	yypop_ ();
	yystate = yystate_stack_[0];
	YY_STACK_PRINT ();
      }

    yyerror_range[2] = yylloc;
    // Using YYLLOC is tempting, but would change the location of
    // the lookahead.  YYLOC is available though.
    YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yyloc);

    /* Shift the error token.  */
    YY_SYMBOL_PRINT ("Shifting", yystos_[yyn],
		     &yysemantic_stack_[0], &yylocation_stack_[0]);

    yystate = yyn;
    goto yynewstate;

    /* Accept.  */
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    /* Abort.  */
  yyabortlab:
    yyresult = 1;
    goto yyreturn;

  yyreturn:
    if (yychar != yyempty_)
      {
        /* Make sure we have latest lookahead translation.  See comments
           at user semantic actions for why this is necessary.  */
        yytoken = yytranslate_ (yychar);
        yydestruct_ ("Cleanup: discarding lookahead", yytoken, &yylval,
                     &yylloc);
      }

    /* Do not reclaim the symbols of the rule which action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystate_stack_.height ())
      {
        yydestruct_ ("Cleanup: popping",
                     yystos_[yystate_stack_[0]],
                     &yysemantic_stack_[0],
                     &yylocation_stack_[0]);
        yypop_ ();
      }

    return yyresult;
    }
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack"
                 << std::endl;
        // Do not try to display the values of the reclaimed symbols,
        // as their printer might throw an exception.
        if (yychar != yyempty_)
          {
            /* Make sure we have latest lookahead translation.  See
               comments at user semantic actions for why this is
               necessary.  */
            yytoken = yytranslate_ (yychar);
            yydestruct_ (YY_NULL, yytoken, &yylval, &yylloc);
          }

        while (1 < yystate_stack_.height ())
          {
            yydestruct_ (YY_NULL,
                         yystos_[yystate_stack_[0]],
                         &yysemantic_stack_[0],
                         &yylocation_stack_[0]);
            yypop_ ();
          }
        throw;
      }
  }

  // Generate an error message.
  std::string
  jsoniq_parser::yysyntax_error_ (int yystate, int yytoken)
  {
    std::string yyres;
    // Number of reported tokens (one for the "unexpected", one per
    // "expected").
    size_t yycount = 0;
    // Its maximum.
    enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
    // Arguments of yyformat.
    char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];

    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yytoken) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yychar.
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state
         merging (from LALR or IELR) and default reductions corrupt the
         expected token list.  However, the list is correct for
         canonical LR with one exception: it will still contain any
         token that will not be accepted due to an error action in a
         later state.
    */
    if (yytoken != yyempty_)
      {
        yyarg[yycount++] = yytname_[yytoken];
        int yyn = yypact_[yystate];
        if (!yy_pact_value_is_default_ (yyn))
          {
            /* Start YYX at -YYN if negative to avoid negative indexes in
               YYCHECK.  In other words, skip the first -YYN actions for
               this state because they are default actions.  */
            int yyxbegin = yyn < 0 ? -yyn : 0;
            /* Stay within bounds of both yycheck and yytname.  */
            int yychecklim = yylast_ - yyn + 1;
            int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
            for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
              if (yycheck_[yyx + yyn] == yyx && yyx != yyterror_
                  && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
                {
                  if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                    {
                      yycount = 1;
                      break;
                    }
                  else
                    yyarg[yycount++] = yytname_[yyx];
                }
          }
      }

    char const* yyformat = YY_NULL;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
        YYCASE_(0, YY_("syntax error"));
        YYCASE_(1, YY_("syntax error, unexpected %s"));
        YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    // Argument number.
    size_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += yytnamerr_ (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
  const short int jsoniq_parser::yypact_ninf_ = -1495;
  const short int
  jsoniq_parser::yypact_[] =
  {
      5037,  8375,  8375,  8375,  8375, -1495, -1495,    -2,    39, -1495,
     558,    50, -1495, -1495, -1495,   326, -1495, -1495, -1495,   396,
   -1495,   402,   742,   348,   670,   701, -1495,    79, -1495, -1495,
   -1495, -1495, -1495, -1495, -1495,   688, -1495, -1495, -1495, -1495,
   -1495, -1495, -1495,   734, -1495,   716, -1495,   704,   745, -1495,
     446, -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495,
   -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495,
   -1495,   793, -1495, -1495, -1495, -1495, -1495, -1495, -1495,   790,
   -1495, -1495, -1495, -1495, -1495, 18573, -1495, -1495, -1495, -1495,
   -1495, -1495, -1495, -1495,   837, -1495, -1495, -1495, -1495, -1495,
   -1495, -1495, -1495, -1495, -1495,  5655, 10496, 10799, 18573, -1495,
   -1495,   828, -1495, -1495, -1495, -1495,   836, -1495, -1495, -1495,
    7167, -1495,  7466, -1495, -1495, -1495, -1495, -1495, -1495, -1495,
   -1495, -1495, -1495, -1495, -1495,   855, -1495, -1495, -1495, -1495,
   -1495, -1495, -1495, -1495,    59,   747,   806, -1495, -1495, -1495,
   -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495, 14435, -1495,
    5959, -1495, 14738,   183, -1495, -1495, -1495, -1495, -1495, -1495,
     922, -1495,   817,   819,   805, -1495, -1495,   901,   914, -1495,
   -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495,
   -1495,   752, -1495, 14132, -1495, -1495, -1495, -1495, -1495, -1495,
   -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495,
   -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495,
   -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495,
   -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495,
   -1495, -1495, 11102, 11405, 11708, -1495,  5346,  7769,  1068, -1495,
    8678, -1495, -1495,   603,    88, -1495, -1495, -1495, -1495, -1495,
   -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495,    90,
   -1495, -1495, -1495, -1495, -1495, -1495,   378, -1495, -1495, -1495,
   -1495, -1495, -1495, -1495, -1495,  8375, -1495, -1495, -1495, -1495,
      37, -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495,
     387, -1495,   876, -1495, -1495, -1495,   132, -1495,   877, -1495,
   -1495, -1495, -1495, -1495, -1495, -1495,   902,   977, -1495, -1495,
     838,   822,   972,   736,   532,   775,   539, -1495,  1028,   878,
     980,   981, 13223, -1495,   888, -1495, -1495,    25, -1495, -1495,
   -1495, -1495,   766, -1495, -1495, -1495, -1495, -1495, -1495, -1495,
   -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495,
   -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495,
   -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495,
   -1495, -1495, -1495, -1495, -1495, -1495,   938,   928, -1495, -1495,
   -1495, -1495, -1495,   903, -1495,  8375,   904,   905,   906,  8375,
      73,    73,  1058,   781,   784,   785, 18865, 18573,     4,  1041,
   18573,   939,   975,    63,  7167,   811,   843, 18573, 18573,   786,
     910,    44, -1495, -1495, -1495,  7167,  8375,  8375, 12617,    36,
     942, 12617,  1098,   159,   142, 18573,   982,   955,   992, -1495,
   12617, 18573,  8375, 12617, 12617, 18573,  8375,   948,   949, 12617,
   18573, -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495,
   -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495,
   -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495,   958,
   -1495, 18573, -1495,   919,  8072,   983,   444,   984,   938,   950,
     951,   953, 18573,  5655, -1495,   957,   242, -1495,   541, -1495,
      84,  1078, 12617, 12617,   172, -1495, -1495, -1495,  1099, 12617,
     900, -1495,  1088,  1089, 12617, 12920, 15041,   766, 12617, 12920,
    6263,   243,   154, 12617, 15041,   720, 12617,   884,   887, 18573,
     932,   933, 12617, 12617,  8375,   879, -1495, -1495,    53, -1495,
      60, 12617,   890,  7769, -1495, -1495, -1495, -1495, -1495,   558,
     701,   101,   121,  1124,  8981,  3471,  9284,  3791,   790, -1495,
   -1495,   428,   790, -1495, 12617,  4425, -1495,  1008, -1495,    79,
     961,   960,   962,  8375, 12617, -1495, -1495, -1495, -1495, -1495,
   -1495, -1495, -1495, -1495, 18573, -1495,   845,   846, 18573,  1014,
   13526, 13526, -1495, -1495, -1495, -1495, -1495, -1495, 13829,  1066,
   13829, 13829, 13829, 13829, 13829, 13829, 13829, 13829, 13829, 13829,
   13829, 13829,   907,  1043,  1044,  1045, -1495, -1495, -1495, 15041,
   12011, -1495,  6565, 12617,  9890,   985, -1495,   991, 10193, -1495,
   -1495, -1495, -1495,   267, -1495,   315, -1495, -1495, -1495, -1495,
   -1495, -1495,  1035,  1037,   348,  1117, -1495, -1495, 18865,   947,
     644, 18573,   986,   987,   947,  1058,  1018,  1016, -1495, -1495,
   -1495,   319,   899,  1059,   850, 18573,  1012, 12617,  1040, 18573,
   18573, -1495,  1026,   976,   978,   432, 18573,  1070,   331, -1495,
    8375, -1495,    97, -1495,  7167,  1069,  1126,  7167,  1058,  1072,
     495, 18573, 12617,    79,   440,   277, -1495,    65,   988,   128,
     149,  1021, -1495,   994,  8375,  8375,   460,   498, 12617,   289,
   -1495, -1495, 12617,  6263, -1495, 12617, 12617, 12617, 12617, -1495,
   12617, -1495, 12617, -1495, 18573,  1078, -1495,   264,   461,   489,
   -1495, -1495, -1495,   586, -1495,    15,   342, -1495, -1495,   766,
     274,   420,   254,   257, 12617, 12617,  1082,   727, 12617,   930,
   15344,   941,    82, -1495,  1038, -1495, -1495,   989,   150,  8072,
     619,  4734,   879, -1495, -1495, -1495,   944, 12617, -1495,   603,
     857,  1151,   667, -1495, -1495,   123, -1495, -1495, -1495,   124,
   -1495,   107, -1495, -1495, -1495, -1495, -1495,  4108, -1495, -1495,
   -1495, 18573,  1015, 12617,  1071, -1495, -1495, -1495,  1080, -1495,
      45, -1495, -1495,  1080, 18573,    23,   977, -1495, -1495,    89,
   -1495,   532,   532,    17,   775,   775,   775,   775,   539,   539,
   -1495, -1495, 17109, 17109, 18573, 18573, -1495, -1495,   625, -1495,
   -1495, -1495, -1495,   357, -1495, -1495, -1495,   354, -1495, -1495,
   -1495,   361,    73, -1495, -1495,   379,   639,   815, -1495,   348,
   -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495,
     947, -1495,  1057, 17403,  1048, 12617, -1495, -1495, -1495,  1100,
    1058,  1058,   947, -1495,   842,  1058,   737, 18573,   167,   677,
    1164, -1495, -1495,   909,   740, -1495, -1495, -1495, -1495, -1495,
   -1495, -1495, -1495, -1495, -1495, -1495,   319,    67,   963,   442,
   12617, -1495, 18573,  1104,   897,  1058, -1495, -1495,  1049,  1100,
   17109,  1087,  1112,  1023,  1011,  1083,  1058,  1050,  1084,  1122,
    1058, 17109, 12617,   -45, -1495, -1495, -1495,  1073,  1095, 12617,
   12617,  1074, -1495,  1120,  1123,  8375, -1495,  1039,  1046,  1076,
   12617,  1085,  1034, 12617, -1495,  1110,  1111, -1495,   151,   153,
     166,  1192, -1495,   286, -1495,   562,  1081, -1495, -1495,  1208,
   -1495,  1209, -1495,   424, 12617, 12617, 12617,   812, 12617, 12617,
   12617, 12617, 12617,  1142, -1495, 12617, 12617, -1495, 12617, 12617,
     675, 15041,  1121, 12617, 12617, -1495,  9587,   314,   993, -1495,
   -1495, -1495, -1495, -1495, -1495,   382, -1495, -1495, 12617, -1495,
     141,    55,   107,  9284,  3791,  9284,  1163, -1495, -1495, 12617,
     650,  1137, -1495, 18573,  1138, -1495, 18281,  1118,  1130, 12617,
     -42,  1102,    47,   548,   996, -1495, -1495,   113,    23, 12617,
      89,   659,    30, -1495,   966,   212,   990,   995, -1495, -1495,
     843, -1495,   979,   698,  1101,  1105,  1107,  1108,  1113,  1114,
    1115,  1119,  1127,  1128,  1129, 15933,  1131,  1134,  1136,  1140,
    1141,  1144, -1495,   544, -1495, -1495, -1495, -1495, -1495, -1495,
   -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495,
   -1495, -1495, -1495, -1495, -1495, -1495, -1495,  1116, -1495, -1495,
   -1495, -1495, 12314, -1495, -1495, -1495, -1495, -1495, -1495, -1495,
   -1495, -1495,   816, -1495,  1224, 17403,   912, -1495, -1495, -1495,
   -1495, -1495, -1495, -1495, -1495, -1495,   968, -1495, -1495,  1229,
   -1495, -1495, -1495, -1495, -1495,   787,  1239, -1495,   750, -1495,
   -1495, -1495,  1101,  1105,  1107,  1113,  1114,  1115,  1119,  1127,
    1128,  1134, -1495,   544,   544, 15041,  1002,   964, -1495,  1100,
      67,  1036,  1086,  8375, -1495, -1495, -1495, 17109, -1495,  8375,
    1058,  1162, -1495, -1495, -1495,  1058,  1162, -1495, -1495, 12617,
    1152,  8375, 18573, -1495, -1495, 12617, 12617,   707, -1495,    34,
     875, -1495, 16227,   883, -1495,   891, -1495,  1094, -1495, -1495,
    8375, -1495, 12617, -1495, -1495, 12617, 12617,  1075,  1120,  1180,
   -1495,  1148, -1495,   648, -1495, -1495,  1278, -1495, -1495,  8375,
   18573, -1495,   715, -1495, -1495, -1495,  8375,  1096,  1125,  1061,
    1064, -1495, -1495, -1495,  1065,  1077, -1495, -1495, -1495,  1210,
   -1495,   997, -1495, -1495, -1495,  1062, 12617,   676, 18573,  1132,
   -1495,  1150,  1154,  1155,  1159, -1495,   876,   581,  4734,   993,
   -1495,  9587,  4734, -1495, -1495,  1151,   410, -1495, -1495, -1495,
    1137, -1495,  1058, -1495,   864, -1495,   335,  1203, -1495, 12617,
     658,  1071, 18573, -1495,   305, 18573, -1495, 12617,  1166, 12617,
    1189, 12617,    81,  1172, 12617,  1173, -1495,  1204,  1205, 12617,
   18573,   472,  1247, -1495, -1495, -1495,   634,  1139, -1495,    89,
    1079, -1495, -1495,   -44, -1495,   630,     1,  1090,    89,   630,
   13829, -1495,   351, -1495, -1495, -1495, -1495, -1495, -1495,    89,
    1177,  1042,   899,     1, -1495, -1495,  1047,  1248, -1495, -1495,
   -1495,  1143,   118, 17697, 15639,  1145,  6866, 18573, 18573,  1147,
   17989,  1149, -1495,  1156,  1158,  1160,  1161,  1165,  1168,  1169,
   -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495,
   -1495, -1495, -1495,  1300,   240,  1302,   240,  1056,  1232, -1495,
   -1495,  1176, 18573,  1092, -1495, -1495, 15041, -1495,  1167, -1495,
    1216,  1223,  1240,  1058,  1162, -1495, 12617,  1174, -1495, -1495,
   -1495,  1171, -1495,    51, 12617,  8375,  1175,   288, -1495, 18573,
     222, -1495, 16521,    40, -1495, 16815,  1178, -1495, -1495,  1179,
   -1495, -1495, -1495, 12617,   892,  1192, 18573,   804, -1495,  1181,
    1192, 18573, -1495,  1182, -1495, -1495, 12617, 12617, 12617, 12617,
    1030, 12617, 12617, -1495, 12617, -1495, 12617, 12617, 12617, 12617,
    9587,   419, -1495, -1495, -1495, -1495, -1495,  1203, -1495, -1495,
   -1495,  1058, 12617, -1495,  1217, -1495, -1495, 12617,  1213, -1495,
   -1495, 12617, -1495,   338, -1495, 12617,  1215, 12617, -1495, 12617,
   18573, 18573, -1495,   739, -1495, 12617, -1495, -1495, -1495,  1183,
   13829, -1495, -1495, -1495, -1495, -1495,    87, 13829, 13829,   -89,
   -1495,   990, -1495,   202, -1495,   995,    89,  1218, -1495, -1495,
    1091, -1495, -1495, -1495, -1495, -1495, -1495,  1185,  1186, -1495,
     459,   492,  1275,  1187, -1495,   509, -1495,  1191, -1495,  1193,
    1194,  1195, -1495, -1495,   545,   575, -1495, -1495, -1495, -1495,
   -1495, -1495, -1495, -1495, -1495,   491,   491, -1495,   240, -1495,
   -1495,   577, -1495,  1342,     3,  1281,  1196, 15041,   -25,  1093,
    1200, -1495,  9587, 12617,  1058, -1495, -1495, -1495, 12617, 12617,
   -1495, -1495, -1495,  9587,  9587,  1284,  8375, 17109, 18573,   514,
   18573, 12617, 18573,   580,  9587, -1495,    43,    38,  1192, 18573,
   -1495,  1188,  1192, -1495, -1495, -1495, -1495, -1495, 12617, -1495,
   -1495, -1495, -1495,   226,   235,   255, 12617, -1495, -1495, -1495,
    1274, 12617, -1495, 12617, -1495, 12617,  1241, -1495, 12617, -1495,
   -1495, -1495,  1334, -1495, -1495, -1495,   775, 13829, 13829,    17,
     780, -1495, -1495, -1495, -1495, -1495, -1495, 12617, -1495, -1495,
   -1495, 18573, -1495, 18573, -1495, 17109, -1495, 17109,  1294, -1495,
   -1495, -1495, -1495, 18573, -1495, 18573, -1495, -1495, -1495, -1495,
    1362, -1495, -1495, -1495,  1133,  1285, -1495, -1495,  1287, -1495,
     754, 18573,  1273,  1170, 18573, 15041, -1495, -1495,  1162, -1495,
   -1495, 17109, -1495, -1495, -1495,  1301, 12617,  1212, -1495,  1303,
    9587, -1495, 18573,   674,   691, -1495,  1198,  1192, -1495,  1206,
   -1495,  1202,  1120,  1123,   637, -1495,  1274, -1495, -1495, 12617,
   -1495,  1290,    17,    17, 13829,   640,  1214,  1221,  1260,  1222,
    1225, -1495, -1495, 17109,  1226,  1227, -1495, -1495,  1281, 15041,
   -1495,  1203,  1106, 18573,  1293,  1197,  1287,   729, 17109,  8375,
   17109,  1230, -1495, -1495,  1319,   770, -1495, -1495, -1495, -1495,
    1234,   733, -1495, -1495, -1495,  1228, -1495,  9587,   913, -1495,
   -1495, -1495, 18573,    17, -1495, -1495, -1495, -1495, -1495, -1495,
   -1495, -1495, -1495, -1495, -1495, -1495, 12617,  1109, 18573,  1305,
    8375,   738, -1495, -1495,   748, 12617, -1495, -1495, -1495, -1495,
   -1495, -1495, -1495,  1306, -1495, -1495,  1135,  1146, 18573, -1495,
   -1495, 12617,  9587, 18573,  1153, 12617,  1157,  1233, 15041, -1495,
   15041,  9587, -1495,  1231,  1184, 18573,  1199,  1307, 18573,  1201,
   15041, -1495
  };

  /* YYDEFACT[S] -- default reduction number in state S.  Performed when
     YYTABLE doesn't specify something else to do.  Zero means the
     default is an error.  */
  const unsigned short int
  jsoniq_parser::yydefact_[] =
  {
       167,   170,   170,   170,     0,   811,  1006,   122,   124,   609,
     903,   912,   852,   816,   814,   796,   904,   907,   859,   820,
     797,   799,   260,   913,   800,   910,   881,   861,   836,   798,
     856,   857,   908,   905,   855,   802,   911,   803,   804,   948,
     960,   947,   853,   872,   866,   805,   854,   807,   806,   949,
     890,   891,   858,   833,   970,   971,   972,   973,   974,   975,
     976,   977,   978,   979,   980,   994,  1001,   880,   876,   867,
     847,   795,   875,   883,   892,   995,   871,   463,   848,   849,
     906,   996,  1002,   868,   885,     0,   472,   471,   465,   878,
     813,   869,   870,   899,   873,   889,   898,  1000,  1003,   819,
     860,   901,   464,   888,   894,   170,     0,     0,     0,   400,
     886,   897,   902,   900,   879,   865,   950,   863,   864,   997,
       0,   399,     0,   998,  1004,   895,   850,   874,   999,   213,
     896,   877,   884,   893,   887,   951,   841,   846,   845,   844,
     843,   842,   808,   862,     0,   812,     0,   909,   834,   462,
     466,   467,   941,   940,   942,   818,   817,   837,     0,   801,
       0,   944,     0,     0,   840,   882,   939,   946,   945,   938,
     838,   943,   955,   956,   953,   954,   952,   809,   957,   958,
     959,   929,   928,   915,   832,   825,   922,   918,   835,   831,
     930,   261,   821,   822,   815,   824,   927,   926,   923,   919,
     936,   937,   935,   925,   921,   914,   823,   934,   933,   827,
     829,   828,   920,   924,   916,   830,   917,   826,   932,   981,
     982,   983,   984,   985,   986,   962,   963,   961,   967,   968,
     969,   964,   965,   966,   839,   987,   988,   989,   990,   991,
     992,   993,     0,     0,     0,  1005,   167,   167,     0,     2,
     167,     9,    11,    25,     0,    30,    33,    38,    39,    40,
      41,    42,    43,    44,    34,    60,    61,    35,    36,     0,
      78,    81,    82,    37,    83,    84,     0,   120,    85,    86,
      87,    88,    20,   164,   165,   166,   173,   176,   454,   177,
       0,   178,   179,   180,   181,   182,   183,   184,   187,   188,
       0,   214,   222,   217,   249,   255,     0,   247,     0,   248,
     224,   218,   186,   219,   185,   220,   223,   357,   359,   361,
     363,   365,   367,   371,   373,   376,   381,   384,   387,   389,
     391,   393,     0,   397,   404,   403,   405,     0,   420,   406,
     425,   426,   427,   434,   445,   459,   461,   446,   447,   448,
     451,   452,   449,   453,   481,   482,   450,   485,   487,   488,
     489,   486,   534,   535,   536,   537,   538,   539,   540,   460,
      45,   225,   226,   228,   227,   229,   221,   456,   457,   458,
     455,   231,   234,   230,   232,   233,     0,   794,   810,   903,
     912,   910,   812,     0,   168,   169,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   128,   130,   131,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   279,   280,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   194,   796,   820,   799,   851,   913,   800,   861,   802,
     872,   805,   807,   806,   890,   795,   849,   873,   897,   950,
     951,   838,   955,   956,   953,   809,   957,   931,   822,   468,
     794,     0,   792,     0,     0,   214,     0,     0,   793,   800,
     807,   806,     0,   170,   757,   957,     0,   222,     0,   469,
       0,   501,     0,     0,     0,   793,   423,   424,     0,     0,
       0,   530,     0,     0,   801,   944,     0,   777,   801,   944,
       0,     0,     0,   801,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   362,   759,     0,   761,
       0,     0,     0,   167,     3,     4,     1,    10,    12,     0,
       0,     0,     0,     6,   167,     0,   167,     0,     0,   121,
     174,     0,     0,   192,     0,     0,   201,     0,   260,     0,
       0,     0,     0,     0,     0,   261,   206,   235,   254,   250,
     256,   251,   253,   252,     0,   259,     0,     0,     0,     0,
       0,     0,   408,   413,   412,   411,   410,   409,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   402,   401,   398,     0,
       0,   421,     0,     0,     0,   435,   442,     0,     0,   542,
     544,   548,   550,     0,   126,     0,   791,    49,    46,    47,
      50,    51,     0,     0,     0,     0,    52,    53,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   616,   617,
     618,     0,   105,   144,     0,     0,   114,     0,     0,     0,
       0,   129,     0,     0,     0,     0,     0,   136,     0,   140,
     170,   484,     0,    62,     0,    71,     0,     0,     0,    63,
       0,     0,     0,     0,     0,     0,   328,     0,     0,     0,
       0,     0,   607,     0,     0,     0,     0,   196,     0,     0,
     190,   189,     0,     0,   763,     0,     0,     0,     0,   468,
       0,   758,     0,   470,   502,   501,   498,     0,     0,     0,
     532,   531,   422,     0,   529,     0,     0,   629,   630,   776,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   635,     0,   204,   205,     0,     0,     0,
       0,     0,   209,   210,   760,   762,     0,     0,     5,    26,
       0,    27,     0,     7,    31,     0,    17,     8,    32,     0,
      21,   903,    79,    18,    80,    22,   195,     0,   193,   215,
     216,     0,     0,     0,     0,   207,   236,   297,   258,   262,
       0,   237,   238,   257,     0,     0,   358,   360,   364,     0,
     368,   375,   374,   372,   378,   379,   380,   377,   382,   383,
     386,   385,     0,     0,     0,     0,   407,   418,     0,   440,
     439,   441,   438,     0,   477,   436,   479,     0,   443,   483,
     475,     0,     0,   123,   125,     0,     0,     0,   104,     0,
      94,    96,    97,    98,    99,   101,   102,   103,    95,   100,
      90,    91,     0,     0,   110,     0,   106,   108,   109,   116,
       0,     0,    89,    48,     0,     0,     0,     0,     0,     0,
       0,   707,   712,     0,     0,   708,   742,   695,   697,   698,
     699,   701,   703,   702,   700,   704,     0,     0,     0,     0,
       0,   113,     0,   146,     0,     0,   547,   541,     0,   142,
       0,     0,   137,     0,     0,     0,     0,     0,     0,    64,
       0,     0,     0,     0,   278,   284,   281,     0,     0,     0,
       0,     0,   546,     0,     0,     0,   414,     0,     0,     0,
       0,   197,     0,     0,   765,     0,     0,   764,     0,     0,
       0,   501,   499,     0,   490,     0,     0,   473,   474,     0,
      13,     0,    15,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   771,   772,     0,     0,   779,     0,   801,
       0,     0,     0,     0,     0,   202,     0,     0,     0,   431,
     432,   433,   430,   643,   429,     0,   428,   211,     0,   775,
       0,     0,     0,   167,     0,   167,     0,   175,   246,     0,
     312,   308,   310,     0,   298,   299,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   239,   240,     0,   245,     0,
       0,     0,     0,   673,   369,   646,   650,   652,   654,   656,
     659,   666,   667,   675,   796,   797,   799,   913,   798,   802,
     803,   804,   805,   795,   563,     0,   808,   801,   788,   790,
     786,   565,   388,   553,   560,   561,   582,   573,   581,   580,
     579,   578,   575,   577,   574,   576,   566,   610,   611,   567,
     568,   782,   783,   784,   571,   390,   392,   395,   572,   394,
     419,   444,     0,   437,   476,   127,    58,    59,    56,    57,
     133,   132,     0,    92,     0,     0,     0,   111,   112,   117,
      76,    77,    54,    55,    75,   713,     0,   716,   743,     0,
     706,   705,   710,   709,   741,     0,     0,   718,     0,   714,
     717,   696,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   145,   148,   150,     0,     0,     0,   115,   118,
       0,     0,     0,   170,   143,   138,   141,     0,   191,     0,
       0,    73,    67,    70,    69,     0,    65,   552,   282,     0,
       0,   170,     0,   326,   330,     0,     0,     0,   333,     0,
       0,   339,     0,     0,   346,     0,   350,     0,   416,   415,
     170,   198,     0,   200,   327,     0,     0,     0,     0,     0,
     502,     0,   492,     0,   525,   522,     0,   526,   527,     0,
       0,   521,     0,   496,   524,   523,     0,     0,     0,     0,
       0,   622,   623,   619,     0,     0,   627,   628,   624,   768,
     769,     0,   633,   778,   631,     0,     0,     0,     0,     0,
     637,   800,   807,   806,   957,   203,     0,     0,     0,   638,
     639,     0,     0,   212,   774,    28,     0,    19,    23,    24,
     309,   321,     0,   322,     0,   313,   314,   315,   316,     0,
     301,     0,     0,   264,     0,     0,   265,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   241,     0,     0,     0,
       0,   291,     0,   288,   293,   244,     0,     0,   657,   670,
       0,   366,   370,     0,   689,     0,     0,     0,     0,     0,
       0,   645,   647,   648,   684,   685,   686,   688,   687,     0,
       0,   661,   660,     0,   664,   668,   682,   680,   679,   672,
     676,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   556,     0,     0,     0,     0,     0,     0,     0,
     557,   559,   558,   554,   396,   478,   480,   135,   134,    93,
     107,   730,   711,     0,   735,     0,   735,   724,   719,   149,
     151,     0,     0,     0,   119,   147,     0,    29,     0,   139,
       0,     0,    72,     0,    66,   283,     0,     0,   329,   331,
     336,     0,   334,     0,     0,     0,     0,     0,   340,     0,
       0,   354,     0,     0,   347,     0,     0,   351,   417,     0,
     199,   766,   767,     0,     0,   501,     0,     0,   533,     0,
     501,     0,   497,     0,    14,    16,     0,     0,     0,     0,
       0,     0,     0,   781,     0,   636,     0,     0,     0,     0,
       0,     0,   640,   644,   325,   323,   324,   317,   318,   319,
     311,     0,     0,   306,     0,   300,   263,     0,     0,   277,
     269,     0,   273,     0,   267,     0,     0,     0,   286,     0,
       0,     0,   243,   289,   292,     0,   674,   665,   671,     0,
       0,   744,   745,   755,   754,   753,     0,     0,     0,     0,
     746,   651,   752,     0,   649,   653,     0,     0,   658,   662,
       0,   683,   678,   681,   677,   589,   584,     0,     0,   599,
       0,     0,     0,     0,   569,     0,   587,     0,   590,     0,
       0,     0,   588,   593,     0,     0,   562,   615,   555,   583,
     787,   789,   785,   564,   731,     0,     0,   729,   736,   737,
     733,     0,   728,     0,   726,     0,     0,     0,     0,     0,
       0,   543,     0,     0,     0,    68,   285,   549,     0,     0,
     337,   341,   335,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   545,     0,     0,   501,     0,
     528,     0,   501,   551,   620,   621,   625,   626,     0,   773,
     632,   780,   634,     0,     0,     0,     0,   641,   320,   307,
     302,     0,   266,     0,   275,     0,     0,   271,     0,   274,
     287,   295,   296,   290,   242,   669,   756,     0,     0,   748,
       0,   694,   693,   692,   691,   690,   655,     0,   747,   585,
     586,     0,   603,     0,   600,     0,   612,     0,     0,   592,
     591,   598,   606,     0,   596,     0,   594,   740,   739,   738,
       0,   732,   725,   723,     0,   720,   721,   715,   152,   154,
     156,     0,     0,     0,     0,     0,   208,   356,    74,   332,
     338,     0,   352,   348,   355,     0,     0,     0,   342,     0,
       0,   344,     0,   511,   505,   500,     0,   501,   491,     0,
     770,     0,     0,     0,     0,   305,   303,   270,   268,     0,
     276,     0,   750,   749,     0,     0,     0,     0,   607,     0,
       0,   613,   570,     0,     0,     0,   734,   727,     0,     0,
     158,   157,     0,     0,     0,     0,   153,     0,     0,     0,
       0,     0,   519,   513,     0,   512,   514,   520,   517,   507,
       0,   506,   508,   518,   493,     0,   494,     0,     0,   642,
     304,   272,     0,   751,   663,   604,   605,   608,   601,   602,
     614,   597,   595,   722,   155,   159,     0,     0,     0,     0,
       0,     0,   345,   343,     0,     0,   504,   515,   516,   503,
     509,   510,   495,     0,   294,   160,     0,     0,     0,   353,
     349,     0,     0,     0,     0,     0,     0,     0,     0,   162,
       0,     0,   161,     0,     0,     0,     0,     0,     0,     0,
       0,   163
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  jsoniq_parser::yypgoto_[] =
  {
     -1495, -1495,  -199,  -178, -1495,  1211,  1219, -1495,  1207,  -477,
   -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495,
    -893, -1495, -1495, -1495, -1495,  -186,  -494, -1495,   769,   140,
   -1495, -1495, -1495, -1495, -1495,   324,   568, -1495, -1495,    14,
    -172,  1051, -1495,  1017, -1495, -1495,  -561, -1495,   525, -1495,
     287, -1495,  -226,  -278, -1495,  -439, -1495,    16,    27,    33,
    -272,  -164, -1495,  -771, -1495, -1495,  -140, -1495, -1495, -1495,
   -1495, -1495, -1495, -1495, -1495, -1495, -1495,   680, -1495,   -95,
    1712,     0, -1495, -1495, -1495, -1495,   415, -1495, -1495,  -284,
   -1495,     5, -1495, -1495,   856,  -942,  -755,  -749, -1495, -1495,
     753, -1495, -1495,   -26,   157, -1495, -1495, -1495,   178, -1494,
   -1495,   441,   182, -1495, -1495,   187, -1208, -1495,   973,   283,
   -1495, -1495,   279,  -910, -1495, -1495,   284, -1495, -1495, -1153,
   -1134, -1495,   278, -1345, -1495, -1495,   869,  -141, -1495,   867,
     868, -1495, -1495,  -593,   416,  -564,   450,   451, -1495, -1495,
   -1495,   642, -1495, -1495,  1235, -1495, -1495, -1495, -1495,  -777,
    -316,  -599, -1495, -1495,   219, -1495,  -114, -1495,   847, -1495,
    -375, -1495, -1495,   851,   852, -1495, -1495, -1495, -1495,   848,
   -1495, -1495, -1495, -1495,  -905, -1495,   276, -1495,   755,  -709,
   -1495, -1495, -1495, -1495, -1495,  -264,  -254, -1126,  -827, -1495,
   -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495,
    -641,  -784,  -393,  -776, -1495, -1495, -1495,  -822, -1495, -1495,
   -1495, -1495, -1495, -1495, -1495, -1495,   152,   155,  -644,  -151,
    -575, -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495,
   -1495, -1495,   245, -1495, -1495,   236, -1495,   238,  -957, -1495,
   -1495, -1495,   180,   170,    -5,   462, -1495, -1495, -1495, -1495,
   -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495,   184,
   -1495, -1495, -1495,    -1,   454,   599, -1495, -1495, -1495, -1495,
   -1495,   369, -1495, -1495, -1457, -1495, -1495, -1495,  -472, -1495,
     133, -1495,   -36, -1495, -1495, -1495, -1495, -1242, -1495,   194,
   -1495, -1495, -1495, -1495, -1495,  -107, -1495, -1495, -1495, -1495,
   -1495,  -818, -1495, -1495, -1495,  -369,  -105,   252,  1190, -1495
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  jsoniq_parser::yydefgoto_[] =
  {
        -1,   248,   565,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,   264,   265,
    1161,   688,   266,   267,   268,   269,   270,   271,   860,   861,
     862,   272,   273,   274,   866,   867,   868,   275,   420,   276,
     277,   633,   278,   422,   423,   424,   430,   678,   679,   279,
    1142,   280,  1658,  1659,   281,   282,   283,   483,   284,   285,
     286,   287,   288,   681,   289,   290,   451,   291,   292,   293,
     294,   295,   296,   576,   297,   298,   762,   763,   299,   300,
     301,   497,   303,   577,   589,  1027,  1028,   304,   578,   305,
     580,   498,   307,   308,   798,   799,  1291,   437,   309,   438,
     439,   805,  1292,  1293,  1294,   581,   582,  1014,  1015,  1453,
     583,  1011,  1012,  1265,  1266,  1267,  1268,   310,   695,   696,
     311,  1177,  1178,  1393,   312,  1180,  1181,   313,   314,  1183,
    1184,  1185,  1186,  1400,   315,   316,   317,   318,   319,   320,
     321,  1301,   322,   323,   324,   325,   326,   327,   328,   329,
     330,  1086,   331,   332,   333,   334,   598,   335,   336,   337,
     338,   339,   340,   341,   993,   994,   342,   625,   626,   343,
     344,   345,   346,   347,   348,   349,   350,   351,   352,   837,
     353,   354,   355,   356,   357,   358,  1212,   725,   726,   727,
    1685,  1740,  1741,  1734,  1735,  1742,  1736,  1213,  1214,   359,
     360,  1215,   361,   362,   363,   364,   365,   366,   367,   368,
     923,  1401,  1353,  1063,  1515,  1064,  1087,  1065,  1066,  1067,
    1068,  1069,  1070,  1071,  1072,  1073,  1074,  1075,   701,  1707,
     369,  1076,  1077,  1078,  1079,   370,   371,   372,   373,   374,
     375,   752,   753,   376,  1249,  1250,  1597,   995,  1034,  1311,
    1312,  1035,  1036,  1037,  1038,  1039,  1321,  1498,  1499,  1040,
    1324,  1041,  1479,  1042,  1043,  1329,  1330,  1504,  1502,  1313,
    1314,  1315,  1316,  1624,   662,   887,   888,   889,   890,   891,
     892,  1129,  1546,  1655,  1130,  1544,  1653,   893,  1366,  1541,
    1537,  1538,  1539,   894,   895,  1317,  1325,  1489,  1318,  1485,
    1302,   377,   378,   379,   380,   486,   381,   382,   383,   384,
     385,  1080,  1081,  1082,  1083,  1162,   487,   386,   387,   388
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const short int jsoniq_parser::yytable_ninf_ = -932;
  const short int
  jsoniq_parser::yytable_[] =
  {
       302,   302,   302,   302,   302,   306,   306,   306,   306,   306,
     813,   496,   500,   560,   535,   504,   953,   393,   396,   397,
     826,   621,   579,  1179,   421,   634,   634,  1166,   394,   394,
     394,   398,  1032,   637,   395,   395,   395,   399,  1062,  1085,
     814,   815,   816,   817,   517,  1020,  1414,   831,   525,  1404,
    1211,  1021,   536,   522,   553,   555,   931,  1569,  1448,  1449,
    1573,   553,   782,   784,   685,   689,   941,   552,   544,   545,
     557,     7,     8,  1297,  1273,  1143,  1101,   774,   778,  1144,
    1024,  1500,  1017,   847,  1280,   553,  1422,  1106,  1656,   553,
     510,   553,   406,   402,   403,  1661,   404,   405,   553,  1486,
    1169,  1486,   553,     9,   559,   302,  1695,  1132,  1277,   652,
     306,   653,  1133,  1134,   408,   776,   780,   783,   785,     9,
     409,  1135,   553,   560,   553,   553,  1155,   560,  1136,   553,
    1137,  1138,   394,  1683,     7,     8,  1394,  1167,   484,  1139,
    1617,   921,   553,  1018,   654,  1018,   562,   538,   540,   959,
     553,   553,   553,  1394,   553,   406,   676,   400,   668,  1022,
    1570,   921,   564,  1682,  1134,   407,  1140,   553,  1287,   564,
    1256,   655,   636,  1288,  1170,   567,   646,  1481,   601,   568,
     730,   620,  1138,   409,   569,    77,  1299,  1621,   410,   636,
     561,   982,  1289,   564,  1622,  1019,   602,  1281,   401,   435,
      88,    77,  1750,   570,  1623,   122,   564,  1662,   960,   647,
     122,  1018,   560,   425,   579,   930,    88,  1482,   414,  1618,
     411,   412,  1006,  1395,  1684,   102,   677,   553,  1109,  1571,
     563,  1465,  1571,  1290,   656,   436,   553,   564,   436,  1598,
    1559,   102,  1201,   553,  1025,  1029,   302,   302,  1030,   559,
     302,   306,   306,  1032,  1032,   306,   553,   686,   564,   564,
     564,  1763,   564,   713,  1487,  1488,  1487,  1282,  1154,   122,
    1397,  1278,  1384,  1283,   723,   564,   511,   782,   784,  1343,
    1404,   554,   415,   556,  1026,   302,   873,   914,  1102,  1663,
     306,  1422,   774,   778,   769,   149,   150,   151,  1211,  1141,
     561,   795,  1654,   571,   561,   687,   572,  1211,  1506,   657,
    1303,   149,   150,   151,   771,   553,  1003,  1005,   933,   919,
     672,   573,   684,   416,   983,   436,  1727,   436,  1143,  1343,
    1456,  1358,  1144,   675,  1255,   564,   682,   479,   669,   934,
     986,  1197,  1478,  1198,   564,   694,   670,   574,   699,   700,
     731,   564,   770,   772,   706,  1031,  1199,   488,   553,   436,
     501,   436,   787,   601,   564,   768,   713,   712,   775,   779,
     963,   764,   505,  1379,   508,   876,   842,   877,   712,  1535,
     765,   602,  1285,  1771,  1304,  1774,   928,  -171,   553,   561,
    1394,  1058,  1059,  1060,   745,   302,   575,   954,   928,   302,
     306,   417,   739,  1018,   306,     7,     8,   728,   729,   418,
     747,  1566,   488,   743,   733,   526,  1691,   419,   786,  1202,
     527,   878,   788,   564,   842,  1692,   302,   302,  -172,   553,
     721,   306,   306,   553,  1033,  1567,  1018,  1120,   758,   760,
     911,   553,   302,  1262,  1536,  1693,   302,   306,  1121,  1303,
     807,   306,  1720,   673,   674,  1457,   652,   843,   653,   399,
     399,   553,   553,  1092,   955,  1264,   564,  1095,   929,   698,
    1092,  1305,  1306,   703,  1307,   399,   961,  1564,  1621,   399,
     943,  1308,   426,   744,   302,  1622,  1203,   560,  1605,   306,
     553,  1309,   558,   302,   971,  1623,   564,   972,   306,   964,
     965,  1110,  1111,  1310,   528,   844,  1114,   429,  1374,   782,
     784,   782,  1211,  1765,   966,  1007,   967,   832,   655,  1458,
     394,   912,  1032,  1304,   445,   828,   395,  1287,   833,  1359,
    1096,  1032,  1288,  1466,   302,   962,  1152,   564,  1251,   306,
    1748,   564,  1032,   302,  1093,  1091,  1371,  1097,   306,   564,
    1514,  1094,   427,   713,   302,   302,   302,   302,   428,   306,
     306,   306,   306,   421,  1257,  1258,  1259,   759,  1631,   564,
     564,  1204,  1205,   302,  -171,  1596,  1004,   879,   306,   915,
     772,   656,   918,  1000,   567,     7,     8,   553,   568,  1363,
     880,   921,   881,   569,   921,  1252,   402,   403,   564,   404,
     405,  1633,   446,   882,   883,   884,   406,   885,   946,   886,
    1305,  1306,   570,  1307,  1404,  -172,   407,   408,  1637,   908,
     553,   948,   949,   950,   567,   760,   553,   927,   568,  1454,
    1309,   714,  1252,   569,   409,   553,   980,   549,   553,   410,
     922,   553,  1310,   940,   921,   968,   969,   939,   956,  1632,
    1365,   604,   570,   550,  1643,  1033,  1033,  1204,  1205,   645,
     970,  1668,   649,  1219,   987,  1220,   505,  1206,   777,   663,
     664,   411,   412,   413,   447,   448,   957,   505,   610,  1732,
     302,   605,  1634,  1204,  1645,   306,  1650,   690,  1207,     9,
    1208,  1350,   611,   697,   606,   564,   913,   702,  1284,  1638,
    1204,  1002,   707,  1676,   302,   302,  1577,   394,  1606,   306,
     306,  1581,   571,   395,  1245,   572,   621,  1493,  1209,  1032,
    1738,   414,   108,  1351,  1204,  1205,   432,  1567,   564,   607,
     722,   937,   938,   697,   564,  1644,   433,   399,   399,   120,
     863,  1352,  1204,   564,   719,   488,   564,  1261,  1146,   564,
    1369,  1370,   571,  1206,   921,   572,   574,  1147,  1262,   302,
    1210,   782,  1738,   434,   306,  1646,  1451,  1651,  1263,  1680,
    1440,    77,   488,   958,  1207,  1732,  1208,  1550,   144,  1204,
    1264,   754,  1397,  1674,   864,   415,    88,   302,   787,   865,
    1098,  1382,   306,  1567,  1287,   421,   574,   622,   622,  1288,
    1207,   772,  1208,  1452,  1209,   575,   988,  1099,   108,  1176,
    1733,   102,  1090,  1204,  1205,  1029,   748,  1207,  1030,  1208,
    1206,  1476,  1391,   976,  1749,   120,   416,  1754,  1739,   431,
    1209,  1253,   623,   623,   624,   624,   800,  1018,  1126,   122,
     800,  1207,   622,  1208,   440,   575,  1416,  1209,  1126,   622,
     921,  1711,   417,  1712,   441,  1127,  1737,  1743,   777,  1207,
     418,  1208,  1262,   443,   144,  1127,  -851,  1237,   419,  1686,
    1780,  1209,   442,  1689,   505,   108,  -931,   623,   584,   624,
     585,   149,   150,   151,   623,  1363,   624,  1380,   622,  1209,
    -851,  1001,   120,  1444,  1619,  1620,  1207,   601,  1208,  1128,
    -931,  -851,  1364,   869,   444,  1483,  1777,   550,  1737,  1206,
     450,  -931,  1484,  1421,  1743,   602,  1616,   899,  1770,  1236,
    1434,   903,   904,   623,  1033,   624,  1209,  1791,   909,  1760,
    1207,   144,  1208,  1033,  1296,   302,   505,  1792,   603,   505,
     306,   601,  1567,   924,  1033,   586,  1365,  1122,  1660,   449,
     587,  1567,  1326,  1327,   642,  1100,  1357,   481,  1123,   602,
    1209,  1567,  1187,   579,   108,   488,   638,   512,   399,   640,
     643,   680,   680,  1112,  1113,  1328,   951,  1176,  1745,   608,
     639,   120,  1704,   641,   502,  1402,  1246,  1706,   609,  1709,
    1396,  1247,   503,  1405,  1402,  1445,  1446,   588,  1403,  1714,
    1103,  1715,  1579,   302,   302,   302,  1406,  1576,   306,   306,
     306,   509,  1103,   996,  1555,  1402,   421,   811,   812,  1721,
     144,  1115,  1116,  1117,  1702,  1703,   513,  1118,  1783,   850,
     851,   852,   853,   854,   855,   856,   857,   858,   859,   658,
     659,   660,   529,  1008,   592,   593,   594,   595,   596,   597,
     666,  1224,   864,  1225,   532,   667,  1023,   865,   818,   819,
     533,   820,   821,  1647,  1648,   530,  1660,   531,   546,   566,
     534,   591,   590,   600,  1084,  1084,  1088,  1088,   599,   612,
     535,   613,  1599,   614,   619,   615,   627,   628,   636,   648,
     629,   630,   631,   632,   650,   651,   661,   665,   680,   683,
     692,   693,   691,   708,   704,   705,   710,   712,   715,   716,
     717,  1753,   718,   720,   724,  1084,   732,   734,   735,   736,
    1660,  1033,   750,  1561,   751,   755,   756,   773,   791,  1119,
     767,   761,   792,   793,   804,   794,   801,   802,   809,   823,
     824,   825,   623,   839,   845,   822,   846,   848,   874,   870,
     871,   875,   896,   302,  1149,   897,   898,   900,   306,   302,
     902,   905,  1084,   906,   306,   907,   910,   916,   795,  1378,
     920,   302,   917,  1084,   978,   932,   306,   935,   975,   981,
     394,   936,   985,   984,   998,  1002,   395,  1387,  1009,  1016,
     302,  1013,  1104,   865,  1124,   306,   921,  1145,   394,  1802,
    1150,  1803,  1125,  1151,   395,  1153,  1409,   676,  1157,   302,
    1158,  1811,  1159,  1163,   306,  1172,   302,   394,  1160,  1164,
    1165,   306,  1176,   395,  1175,  1182,  1188,  1193,  1200,  1171,
    1192,  1519,  1190,  1189,  1195,  1196,  1419,  1216,  1217,  1218,
    1231,  1238,   399,  1423,   654,  1248,  1269,  1271,  1274,   399,
    1275,  1246,  1279,  1323,     9,  1319,  1247,  1286,  1300,  1362,
    1331,  1361,  1320,  1354,  1332,  1270,  1333,  1334,   800,  1367,
    1376,  1383,  1335,  1336,  1337,   480,  1413,  1373,  1338,  1377,
    1666,  1408,  1402,  1415,   759,  1418,  1339,  1340,  1341,  1424,
    1344,  1670,  1561,  1345,  1672,  1346,  1372,  1386,   480,  1347,
    1348,  1426,  1681,  1349,  1427,  1428,  1432,  1084,  1430,  1437,
     480,  1262,   480,  1438,  1439,  1251,  1461,  1429,  1425,  1463,
    1431,  1436,  1467,  1469,  1470,  1471,  1475,  1496,  1503,  1477,
    1534,  1497,  1540,  1505,  1543,  1516,  1480,  1522,  1554,  1526,
    1501,  1545,  1593,  1594,  1595,  1552,  1527,  1490,  1528,  1547,
    1529,  1530,  1553,  1588,  1551,  1531,  1549,  1084,  1532,  1533,
    1558,  1557,  1601,  1603,  1563,  1608,  1575,  1574,  1580,  1583,
    1615,  1635,  1652,  1665,  1627,  1629,  1630,  1636,  1628,  1126,
    1671,  1639,  1451,  1640,  1641,  1642,  1657,  1664,  1688,  1701,
    1713,  1699,  1716,  1723,  1718,   302,  1719,  1728,  1744,  1730,
     306,  1729,  1724,  1747,  1755,  1717,  1746,  1757,  1672,  1084,
    1752,  1756,  1758,  1768,  1776,  1759,  1761,  1762,  1766,  1775,
    1779,  1786,  1801,   872,   697,  1788,  1793,  1808,  1782,  1769,
    1360,  1807,  1107,  1804,  1084,  1794,  1156,  1375,   671,  1726,
    1246,  1764,   997,  1295,   803,  1247,   926,  1613,  1474,  1455,
    1260,  1450,   635,  1447,   709,  1388,  1392,  1772,  1795,   806,
     551,   547,  1420,  1407,  1398,   808,  1798,  1089,   810,   548,
    1800,  1443,   838,   829,   830,  1380,   841,  1781,  1805,  1417,
     952,  1778,  1710,  1435,  1507,  1442,  1441,  1508,  1491,  1495,
     754,  1626,  1625,  1298,  1322,  1131,  1494,  1368,  1789,  1542,
     996,  1694,  1649,  1492,   996,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1810,     0,     0,     0,     0,     0,
    1789,     0,     0,     0,   800,     0,     0,  1459,     0,  1772,
       0,     0,  1705,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1473,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1246,     0,     0,     0,     0,  1247,     0,     0,
       0,     0,     0,  1246,  1246,     0,   302,   618,  1247,  1247,
       0,   306,     0,     0,  1246,     0,     0,     0,     0,  1247,
       0,     0,     0,     0,     0,  1511,  1084,     0,   505,  1520,
    1521,     0,  1525,     0,     0,     0,   644,   480,     0,     0,
     480,     0,     0,     0,   480,     0,     0,   480,   480,     0,
       0,     0,     0,     0,     0,   480,     0,     0,     0,     0,
       0,     0,     0,     0,  1548,   480,     0,     0,     0,     0,
       0,   480,     0,     0,     0,   480,     0,     0,     0,     0,
     480,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1565,     0,     0,  1084,     0,     0,  1084,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1578,     0,
       0,   480,     0,  1582,     0,     0,     0,     0,     0,     0,
    1246,     0,   480,     0,     0,  1247,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   480,
       0,     0,  1611,  1612,     0,     0,     0,     0,     0,   302,
       0,     0,     0,     0,   306,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1246,     0,     0,
       0,     0,  1247,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     302,     0,     0,     0,   480,   306,     0,     0,   480,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1246,     0,     0,     0,     0,  1247,     0,     0,
       0,  1246,     0,     0,     0,     0,  1247,     0,     0,     0,
       0,     0,   480,     0,     0,     0,     0,   485,     0,  1084,
    1675,     0,  1677,     0,  1679,     0,     0,     0,     0,     0,
       0,  1687,     0,     0,     0,     0,     0,     0,   849,     0,
       0,   480,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   480,     0,     0,     0,   480,
     480,     0,     0,     0,     0,     0,   480,     0,     0,     0,
       0,     0,   521,     0,   480,     0,     0,   480,     0,     0,
       0,   480,     0,  1708,     0,  1708,     0,  1084,     0,  1084,
       0,     0,     0,     0,     0,   702,     0,   702,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1722,   480,     0,  1725,     0,     0,     0,
       0,     0,     0,  1084,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1731,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   480,     0,     0,     0,     0,   542,     0,     0,     0,
       0,     0,     0,     0,     0,  1084,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1767,     0,     0,     0,     0,
    1084,   480,  1084,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   480,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1784,     0,     0,     0,     0,     0,
       0,     0,   480,   480,   480,   480,     0,     0,     0,     0,
    1787,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1796,     0,     0,     0,     0,  1797,     0,     0,     0,     0,
       0,     0,     0,   480,     0,     0,     0,  1806,     0,     0,
    1809,     0,     0,     0,     0,     0,     0,   480,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   480,     0,     0,     0,     0,     0,     0,     0,
     480,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   480,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   480,     0,   485,   480,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   737,   738,     0,     0,
     740,   741,   742,     0,     0,   746,     0,     0,   749,     0,
       0,     0,     0,     0,   757,   480,     0,     0,     0,     0,
       0,     0,     0,   766,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   789,   790,     0,     0,
       0,     0,     0,     0,     0,   796,   797,     0,     0,     0,
       0,     0,     0,     0,     0,   480,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   836,     0,     0,     0,
     836,     0,     0,     0,     0,     0,     0,   480,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   480,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   480,     0,     0,     0,     0,     0,     0,   901,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     480,     0,     0,     0,   925,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     942,     0,     0,     0,   944,   945,     0,   947,   480,     0,
       0,     0,     0,     0,   796,     0,     0,     0,   480,     0,
       0,     0,   480,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   973,   974,     0,     0,
     977,     0,   480,     0,     0,   480,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   999,
     480,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   790,
       0,     0,     0,     0,     0,  1010,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   480,   480,     0,   480,   480,   480,     0,
     480,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   480,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1108,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   480,
       0,     0,   480,     0,     0,   480,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   480,     0,     0,     0,
       0,   480,  1148,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1168,     0,     0,     0,     0,     0,
       0,  1173,  1174,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1191,     0,     0,  1194,     0,     0,     0,     0,
     480,   480,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1221,  1222,  1223,     0,
    1226,  1227,  1228,  1229,  1230,     0,     0,  1232,  1233,     0,
    1234,  1235,     0,     0,     0,  1239,  1240,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1254,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1010,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1276,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   480,   480,     0,
     480,     0,   480,     0,     0,     0,     0,     0,     0,   480,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1356,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   480,     0,   480,     0,   480,     0,   480,     0,     0,
       0,     0,     0,   480,     0,   480,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   480,     0,     0,   480,     0,     0,     0,     0,     0,
       0,   480,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1381,   480,     0,     0,     0,     0,     0,     0,     0,
       0,  1385,     0,     0,     0,     0,     0,  1389,  1390,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   480,  1410,     0,     0,  1411,  1412,     0,
       0,     0,     0,   480,     0,     0,     0,     0,   480,     0,
     480,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   480,     0,     0,     0,     0,     0,  1433,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   480,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   480,     0,
       0,  1010,     0,   480,     0,     0,     0,     0,     0,  1460,
       0,  1462,     0,  1464,     0,   480,  1468,     0,   480,     0,
       0,  1472,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1556,     0,
       0,     0,     0,     0,     0,     0,  1560,  1562,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1381,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1584,  1585,
    1586,  1587,     0,  1589,  1590,     0,  1591,     0,  1592,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1600,     0,     0,     0,     0,  1602,
       0,     0,     0,  1604,     0,     0,     0,  1607,     0,  1609,
       0,  1610,     0,     0,     0,     0,     0,  1614,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1667,     0,     0,     0,     0,
    1669,  1562,     0,     0,     0,     0,     0,     0,  1673,     0,
       0,     0,     0,  1678,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1690,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1696,     0,  1697,     0,  1698,     0,     0,
    1700,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1673,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1751,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1773,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  -167,   777,     0,     0,     0,     0,     0,  1785,     0,
       0,     0,  1790,     0,     0,     0,     0,  1773,     0,     0,
       0,     0,     1,     2,     3,     4,     5,     6,     7,     8,
       0,     9,     0,  1790,     0,    10,   390,  1799,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,     0,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,     0,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,     0,    68,    69,    70,
      71,     0,     0,    72,    73,    74,     0,     0,    75,    76,
       0,     0,     0,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,     0,     0,     0,     0,    88,     0,
      89,    90,    91,    92,     0,    93,     0,     0,     0,    94,
      95,    96,    97,    98,     0,     0,     0,     0,     0,     0,
      99,   100,   101,   102,   103,   104,     0,   105,   106,     0,
     107,   108,   109,   110,   111,     0,     0,     0,     0,   112,
     113,   114,   115,   116,   117,   118,   119,     0,   120,     0,
     121,   122,     0,     0,   123,   124,   125,     0,     0,     0,
     126,     0,   127,   128,   129,     0,     0,     0,     0,     0,
     130,     0,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,     0,     0,   142,   143,   144,     0,   392,
       0,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,     0,   192,   193,   194,
       0,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,     0,
     243,  -167,   777,   244,   245,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     1,     2,     3,     4,     5,     6,     7,     8,
       0,     9,     0,     0,     0,   781,   390,     0,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,   391,    26,    27,    28,    29,    30,     0,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,     0,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,     0,    68,    69,    70,
      71,     0,     0,    72,    73,    74,     0,     0,    75,    76,
       0,     0,     0,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,     0,     0,     0,     0,    88,     0,
      89,    90,    91,    92,     0,    93,     0,     0,     0,    94,
      95,    96,    97,    98,     0,     0,     0,     0,     0,     0,
      99,   100,   101,   102,   103,   104,     0,   105,   106,     0,
     107,   108,   109,   110,   111,     0,     0,     0,     0,   112,
     113,   114,   115,   116,   117,   118,   119,     0,   120,     0,
     121,   122,     0,     0,   123,   124,   125,     0,     0,     0,
     126,     0,   127,   128,   129,     0,     0,     0,     0,     0,
     130,     0,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,     0,     0,   142,   143,   144,     0,   392,
       0,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,     0,   192,   193,   194,
       0,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   777,
     243,     0,     0,   244,   245,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     1,
       2,     3,     4,     5,     6,     7,     8,     0,     9,     0,
       0,     0,   389,   390,     0,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,   391,    26,
      27,    28,    29,    30,     0,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,     0,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,     0,    68,    69,    70,    71,     0,     0,
      72,    73,    74,     0,     0,    75,    76,     0,     0,     0,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,     0,     0,     0,     0,    88,     0,    89,    90,    91,
      92,     0,    93,     0,     0,     0,    94,    95,    96,    97,
      98,     0,     0,     0,     0,     0,     0,    99,   100,   101,
     102,   103,   104,     0,   105,   106,     0,   107,   108,   109,
     110,   111,     0,     0,     0,     0,   112,   113,   114,   115,
     116,   117,   118,   119,     0,   120,     0,   121,   122,     0,
       0,   123,   124,   125,     0,     0,     0,   126,     0,   127,
     128,   129,     0,     0,     0,     0,     0,   130,     0,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
       0,     0,   142,   143,   144,     0,   392,     0,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,     0,   192,   193,   194,     0,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   777,   243,     0,     0,
     244,   245,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     1,     2,     3,     4,
       5,     6,     0,     0,     0,     9,     0,     0,     0,   389,
     390,     0,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,   489,   391,    26,    27,    28,    29,
      30,     0,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,     0,    44,    45,    46,   490,
     491,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
       0,    68,    69,    70,    71,     0,     0,    72,    73,    74,
       0,     0,    75,    76,     0,     0,     0,    77,    78,   466,
      80,    81,    82,    83,    84,   492,    86,    87,     0,     0,
       0,     0,    88,     0,    89,    90,    91,    92,     0,    93,
       0,     0,     0,    94,    95,    96,    97,    98,     0,     0,
       0,     0,     0,     0,    99,   100,   101,   102,   103,   104,
       0,   493,   106,     0,   107,   108,   109,   110,   111,     0,
       0,     0,     0,   112,   113,   114,   115,   116,   117,   118,
     119,     0,   120,     0,   121,   122,     0,     0,   123,   124,
     125,     0,     0,     0,   126,     0,   127,   128,     0,     0,
       0,     0,     0,     0,   130,     0,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,     0,     0,   142,
     143,   144,     0,   392,     0,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     472,   473,   474,   175,   176,   475,   495,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
       0,   192,   193,   194,     0,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,     0,   243,   989,   990,   244,   245,     0,
       0,     0,     0,     0,   991,     0,     0,     0,     0,     5,
       6,     0,     0,     0,     0,     0,     0,     0,   389,   390,
       0,    12,    13,    14,   452,    16,    17,    18,   453,    20,
     454,   455,   456,   457,   391,    26,   458,    28,    29,    30,
       0,    31,    32,    33,    34,   459,    36,    37,    38,    39,
      40,    41,    42,   460,     0,    44,   461,    46,   462,   463,
      49,   464,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,     0,
      68,    69,    70,   465,     0,     0,    72,    73,    74,     0,
       0,    75,    76,     0,     0,     0,     0,    78,   466,    80,
      81,    82,    83,    84,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    89,    90,    91,    92,     0,    93,     0,
       0,     0,   467,    95,    96,    97,    98,     0,     0,     0,
       0,     0,     0,    99,   100,   101,     0,   103,   104,     0,
       0,     0,     0,     0,     0,     0,   110,   468,     0,     0,
       0,     0,   112,   113,   114,   115,   469,   117,   118,   119,
       0,     0,     0,     0,     0,     0,     0,   123,   124,   125,
       0,     0,     0,   126,     0,   127,   128,     0,     0,     0,
       0,   992,     0,   130,     0,   131,   132,   133,   134,   470,
     136,   137,   138,   139,   140,   141,     0,     0,   142,   143,
       0,     0,   392,     0,   147,   148,     0,     0,     0,   152,
     153,   154,   155,   156,   157,     0,   159,     0,   161,     0,
       0,   164,   165,   166,   167,   168,   169,   471,   171,   472,
     473,   474,   175,   176,   475,   476,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   477,     0,
     192,   478,   194,     0,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,     0,     0,     0,     0,     0,     0,   245,     1,     2,
       3,     4,     5,     6,     7,     8,     0,     9,     0,     0,
       0,    10,    11,     0,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,     0,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,     0,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,     0,    68,    69,    70,    71,     0,     0,    72,
      73,    74,     0,     0,    75,    76,     0,     0,     0,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
       0,     0,     0,     0,    88,     0,    89,    90,    91,    92,
       0,    93,     0,     0,     0,    94,    95,    96,    97,    98,
       0,     0,     0,     0,     0,     0,    99,   100,   101,   102,
     103,   104,     0,   105,   106,     0,   107,   108,   109,   110,
     111,     0,     0,     0,     0,   112,   113,   114,   115,   116,
     117,   118,   119,     0,   120,     0,   121,   122,     0,     0,
     123,   124,   125,     0,     0,     0,   126,     0,   127,   128,
     129,     0,     0,     0,     0,     0,   130,     0,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,     0,
       0,   142,   143,   144,     0,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,     0,   192,   193,   194,     0,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,     0,   243,     0,     0,   244,
     245,     0,     0,     0,     0,   246,   247,     1,     2,     3,
       4,     5,     6,     7,     8,     0,     9,     0,     0,     0,
      10,    11,     0,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,     0,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,     0,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,     0,    68,    69,    70,    71,     0,     0,    72,    73,
      74,     0,     0,    75,    76,     0,     0,     0,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,     0,
       0,     0,     0,    88,     0,    89,    90,    91,    92,     0,
      93,     0,     0,     0,    94,    95,    96,    97,    98,     0,
       0,     0,     0,     0,     0,    99,   100,   101,   102,   103,
     104,     0,   105,   106,     0,   107,   108,   109,   110,   111,
       0,     0,     0,     0,   112,   113,   114,   115,   116,   117,
     118,   119,     0,   120,     0,   121,   122,     0,     0,   123,
     124,   125,     0,     0,     0,   126,     0,   127,   128,   129,
       0,     0,     0,     0,     0,   130,     0,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,     0,     0,
     142,   143,   144,     0,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,     0,   192,   193,   194,     0,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,     0,   243,     0,     0,   244,   245,
       0,   482,     0,     0,     0,   543,     1,     2,     3,     4,
       5,     6,     7,     8,     0,     9,     0,     0,     0,   389,
     390,     0,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,   391,    26,    27,    28,    29,
      30,     0,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,     0,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
       0,    68,    69,    70,    71,     0,     0,    72,    73,    74,
       0,     0,    75,    76,     0,     0,     0,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,     0,     0,
       0,     0,    88,     0,    89,    90,    91,    92,     0,    93,
       0,     0,     0,    94,    95,    96,    97,    98,     0,     0,
       0,     0,     0,     0,    99,   100,   101,   102,   103,   104,
       0,   105,   106,     0,   107,   108,   109,   110,   111,     0,
       0,     0,     0,   112,   113,   114,   115,   116,   117,   118,
     119,     0,   120,     0,   121,   122,     0,     0,   123,   124,
     125,     0,     0,     0,   126,     0,   127,   128,   129,     0,
       0,     0,     0,     0,   130,     0,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,     0,     0,   142,
     143,   144,     0,   392,     0,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
       0,   192,   193,   194,     0,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,     0,   243,   482,     0,   244,   245,     0,
       1,     2,     3,     4,     5,     6,     0,     0,     0,     9,
       0,     0,     0,   389,   390,     0,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,   489,   391,
      26,    27,    28,    29,    30,     0,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,     0,
      44,    45,    46,   490,   491,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,     0,    68,    69,    70,    71,     0,
       0,    72,    73,    74,     0,     0,    75,    76,     0,     0,
       0,    77,    78,   466,    80,    81,    82,    83,    84,   492,
      86,    87,     0,     0,     0,     0,    88,     0,    89,    90,
      91,    92,     0,    93,     0,     0,     0,    94,    95,    96,
      97,    98,     0,     0,     0,     0,     0,     0,    99,   100,
     101,   102,   103,   104,     0,   493,   106,     0,   107,   108,
     109,   110,   111,     0,     0,     0,     0,   112,   113,   114,
     115,   116,   117,   118,   119,     0,   120,     0,   121,   122,
       0,     0,   123,   124,   125,     0,     0,     0,   126,     0,
     127,   128,     0,     0,     0,     0,     0,     0,   130,     0,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,     0,     0,   142,   143,   144,     0,   392,     0,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   518,   160,   519,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   472,   473,   474,   175,   176,   475,
     495,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,     0,   192,   193,   194,     0,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,     0,   243,   482,
     520,   244,   245,     0,     1,     2,     3,     4,     5,     6,
       0,     0,     0,     9,     0,     0,     0,   389,   390,     0,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,   489,   391,    26,    27,    28,    29,    30,     0,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,     0,    44,    45,    46,   490,   491,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,     0,    68,
      69,    70,    71,     0,     0,    72,    73,    74,     0,     0,
      75,    76,     0,     0,     0,    77,    78,   466,    80,    81,
      82,    83,    84,   492,    86,    87,     0,     0,     0,     0,
      88,     0,    89,    90,    91,    92,     0,    93,     0,     0,
       0,    94,    95,    96,    97,    98,     0,     0,     0,     0,
       0,     0,    99,   100,   101,   102,   103,   104,     0,   493,
     106,     0,   107,   108,   109,   110,   111,     0,     0,     0,
       0,   112,   113,   114,   115,   116,   117,   118,   119,     0,
     120,     0,   121,   122,     0,     0,   123,   124,   125,     0,
       0,     0,   126,     0,   127,   128,     0,     0,     0,     0,
       0,     0,   130,     0,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,     0,     0,   142,   143,   144,
       0,   392,     0,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   472,   473,
     474,   175,   176,   475,   495,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,     0,   192,
     193,   194,     0,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   482,   243,     0,     0,   244,   245,     0,     0,     0,
       5,     6,     0,     0,     0,     9,     0,     0,     0,   389,
     390,     0,    12,    13,    14,   452,    16,    17,    18,   453,
      20,   454,   455,   456,   457,   391,    26,   458,    28,    29,
      30,     0,    31,    32,    33,    34,   459,    36,    37,    38,
      39,    40,    41,    42,   460,     0,    44,   461,    46,   462,
     463,    49,   464,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
       0,    68,    69,    70,   465,     0,     0,    72,    73,    74,
       0,     0,    75,    76,     0,     0,     0,     0,    78,   466,
      80,    81,    82,    83,    84,   492,     0,     0,     0,     0,
       0,     0,     0,     0,    89,    90,    91,    92,     0,    93,
       0,     0,     0,   467,    95,    96,    97,    98,     0,     0,
       0,     0,     0,     0,    99,   100,   101,     0,   103,   104,
       0,     0,     0,     0,   107,     0,     0,   110,   468,     0,
       0,     0,     0,   112,   113,   114,   115,   469,   117,   118,
     119,     0,     0,     0,     0,     0,     0,     0,   123,   124,
     125,     0,     0,     0,   126,     0,   127,   128,     0,     0,
       0,     0,     0,     0,   130,     0,   131,   132,   133,   134,
     470,   136,   137,   138,   139,   140,   141,     0,     0,   142,
     143,     0,     0,   392,     0,   147,   148,     0,     0,     0,
     152,   153,   154,   155,   156,   157,     0,   159,     0,   161,
       0,     0,   164,   165,   166,   167,   168,   169,   471,   171,
     472,   473,   474,   175,   176,   475,   476,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   477,
       0,   192,   478,   194,     0,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   482,     0,     0,     0,     0,     0,   245,     0,
       0,     5,     6,     0,     0,     0,  1517,     0,     0,     0,
     389,   390,     0,    12,    13,    14,   452,    16,    17,    18,
     453,    20,   454,   455,   456,   457,   391,    26,   458,    28,
      29,    30,     0,    31,    32,    33,    34,   459,    36,    37,
      38,    39,    40,    41,    42,   460,     0,    44,   461,    46,
     462,   463,    49,   464,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,     0,    68,    69,    70,   465,     0,     0,    72,    73,
      74,     0,     0,    75,    76,     0,     0,     0,     0,    78,
     466,    80,    81,    82,    83,    84,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    89,    90,    91,    92,     0,
      93,     0,     0,     0,   467,    95,    96,    97,    98,     0,
       0,     0,     0,     0,     0,    99,   100,   101,     0,   103,
     104,     0,     0,     0,     0,     0,     0,     0,   110,   468,
       0,     0,     0,     0,   112,   113,   114,   115,   469,   117,
     118,   119,     0,     0,     0,     0,     0,     0,     0,   123,
     124,   125,     0,     0,     0,   126,  1518,   127,   128,     0,
       0,     0,     0,     0,     0,   130,     0,   131,   132,   133,
     134,   470,   136,   137,   138,   139,   140,   141,     0,     0,
     142,   143,     0,     0,   392,     0,   147,   148,     0,     0,
       0,   152,   153,   154,   155,   156,   157,     0,   159,     0,
     161,     0,     0,   164,   165,   166,   167,   168,   169,   471,
     171,   472,   473,   474,   175,   176,   475,   476,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     477,     0,   192,   478,   194,     0,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   482,     0,     0,     0,     0,     0,   245,
       0,     0,     5,     6,     0,     0,     0,     0,     0,     0,
       0,   389,   390,     0,    12,    13,    14,   452,    16,    17,
      18,   453,    20,   454,   455,   456,   457,   391,    26,   458,
      28,    29,    30,     0,    31,    32,    33,    34,   459,    36,
      37,    38,    39,    40,    41,    42,   460,     0,    44,   461,
      46,   462,   463,    49,   464,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,     0,    68,    69,    70,   465,     0,     0,    72,
      73,    74,     0,     0,    75,    76,     0,     0,     0,     0,
      78,   466,    80,    81,    82,    83,    84,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    89,    90,    91,    92,
       0,    93,     0,     0,     0,   467,    95,    96,    97,    98,
       0,     0,     0,     0,     0,     0,    99,   100,   101,     0,
     103,   104,     0,     0,     0,     0,     0,     0,     0,   110,
     468,     0,     0,     0,     0,   112,   113,   114,   115,   469,
     117,   118,   119,     0,     0,     0,     0,     0,     0,     0,
     123,   124,   125,     0,     0,     0,   126,     0,   127,   128,
       0,     0,     0,     0,     0,     0,   130,     0,   131,   132,
     133,   134,   470,   136,   137,   138,   139,   140,   141,     0,
       0,   142,   143,     0,     0,   392,     0,   147,   148,     0,
       0,     0,   152,   153,   154,   155,   156,   157,     0,   159,
       0,   161,     0,     0,   164,   165,   166,   167,   168,   169,
     471,   171,   472,   473,   474,   175,   176,   475,   476,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   477,     0,   192,   478,   194,     0,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   506,   507,     0,     0,     0,     0,
     245,     5,     6,     0,     0,     0,     0,     0,     0,     0,
     389,   390,     0,    12,    13,    14,   452,    16,    17,    18,
     453,    20,   454,   455,   456,   457,   391,    26,   458,    28,
      29,    30,     0,    31,    32,    33,    34,   459,    36,    37,
      38,    39,    40,    41,    42,   460,     0,    44,   461,    46,
     462,   463,    49,   464,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,     0,    68,    69,    70,   465,     0,     0,    72,    73,
      74,     0,     0,    75,    76,     0,     0,     0,     0,    78,
     466,    80,    81,    82,    83,    84,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    89,    90,    91,    92,     0,
      93,     0,     0,     0,   467,    95,    96,    97,    98,     0,
       0,     0,     0,     0,     0,    99,   100,   101,     0,   103,
     104,     0,     0,     0,     0,     0,     0,     0,   110,   468,
       0,     0,     0,     0,   112,   113,   114,   115,   469,   117,
     118,   119,     0,     0,     0,     0,     0,     0,     0,   123,
     124,   125,     0,     0,     0,   126,     0,   127,   128,     0,
       0,     0,     0,     0,     0,   130,     0,   131,   132,   133,
     134,   470,   136,   137,   138,   139,   140,   141,     0,     0,
     142,   143,     0,     0,   392,     0,   147,   148,     0,     0,
       0,   152,   153,   154,   155,   156,   157,     0,   159,     0,
     161,     0,     0,   164,   165,   166,   167,   168,   169,   471,
     171,   472,   473,   474,   175,   176,   475,   476,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     477,     0,   192,   478,   194,     0,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,     0,     0,     0,     0,     0,     0,   245,
       1,     2,     3,     4,     5,     6,     7,     8,     0,     9,
       0,     0,     0,    10,    11,     0,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,     0,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,     0,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,     0,    68,    69,    70,    71,     0,
       0,    72,    73,    74,     0,     0,    75,    76,     0,     0,
       0,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,     0,     0,     0,     0,    88,     0,    89,    90,
      91,    92,     0,    93,     0,     0,     0,    94,    95,    96,
      97,    98,     0,     0,     0,     0,     0,     0,    99,   100,
     101,   102,   103,   104,     0,   105,   106,     0,   107,   108,
     109,   110,   111,     0,     0,     0,     0,   112,   113,   114,
     115,   116,   117,   118,   119,     0,   120,     0,   121,   122,
       0,     0,   123,   124,   125,     0,     0,     0,   126,     0,
     127,   128,   129,     0,     0,     0,     0,     0,   130,     0,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,     0,     0,   142,   143,   144,     0,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,     0,   192,   193,   194,     0,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,     0,   243,     0,
       0,   244,   245,     1,     2,     3,     4,     5,     6,     7,
       8,     0,     9,     0,     0,     0,   389,   390,     0,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,   391,    26,    27,    28,    29,    30,     0,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,     0,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,     0,    68,    69,
      70,    71,     0,     0,    72,    73,    74,     0,     0,    75,
      76,     0,     0,     0,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,     0,     0,     0,     0,    88,
       0,    89,    90,    91,    92,     0,    93,     0,     0,     0,
      94,    95,    96,    97,    98,     0,     0,     0,     0,     0,
       0,    99,   100,   101,   102,   103,   104,     0,   105,   106,
       0,   107,   108,   109,   110,   111,     0,     0,     0,     0,
     112,   113,   114,   115,   116,   117,   118,   119,     0,   120,
       0,   121,   122,     0,     0,   123,   124,   125,     0,   711,
       0,   126,     0,   127,   128,   129,     0,     0,     0,     0,
       0,   130,     0,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,     0,     0,   142,   143,   144,     0,
     392,     0,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,     0,   192,   193,
     194,     0,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
       0,   243,     0,     0,   244,   245,     1,     2,     3,     4,
       5,     6,     7,     8,     0,     9,     0,     0,     0,   389,
     390,     0,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,   391,    26,    27,    28,    29,
      30,     0,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,     0,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
       0,    68,    69,    70,    71,     0,     0,    72,    73,    74,
       0,     0,    75,    76,     0,     0,     0,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,     0,     0,
       0,     0,    88,     0,    89,    90,    91,    92,     0,    93,
       0,     0,     0,    94,    95,    96,    97,    98,     0,     0,
       0,     0,     0,     0,    99,   100,   101,   102,   103,   104,
       0,   105,   106,     0,   107,   108,   109,   110,   111,     0,
       0,     0,     0,   112,   113,   114,   115,   116,   117,   118,
     119,     0,   120,     0,   121,   122,     0,     0,   123,   124,
     125,     0,     0,     0,   126,     0,   127,   128,   129,     0,
       0,     0,     0,     0,   130,     0,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,     0,     0,   142,
     143,   144,     0,   392,     0,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
       0,   192,   193,   194,     0,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,     0,   243,     0,     0,   244,   245,     1,
       2,     3,     4,     5,     6,     7,     8,     0,     9,     0,
       0,     0,    10,    11,     0,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,     0,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,     0,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,     0,    68,    69,    70,    71,     0,     0,
      72,    73,    74,     0,     0,    75,    76,     0,     0,     0,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,     0,     0,     0,     0,    88,     0,    89,    90,    91,
      92,     0,    93,     0,     0,     0,    94,    95,    96,    97,
      98,     0,     0,     0,     0,     0,     0,    99,   100,   101,
     102,   103,   104,     0,   105,   106,     0,   107,   108,   109,
     110,   111,     0,     0,     0,     0,   112,   113,   114,   115,
     116,   117,   118,   119,     0,   120,     0,   121,   122,     0,
       0,   123,   124,   125,     0,     0,     0,   126,     0,   127,
     128,   129,     0,     0,     0,     0,     0,   130,     0,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
       0,     0,   142,   143,   144,     0,   392,     0,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,     0,   192,   193,   194,     0,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,     0,   243,     0,     0,
     244,   245,     1,     2,     3,     4,     5,     6,     7,     8,
       0,     9,     0,     0,     0,    10,   390,     0,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,     0,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,     0,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,     0,    68,    69,    70,
      71,     0,     0,    72,    73,    74,     0,     0,    75,    76,
       0,     0,     0,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,     0,     0,     0,     0,    88,     0,
      89,    90,    91,    92,     0,    93,     0,     0,     0,    94,
      95,    96,    97,    98,     0,     0,     0,     0,     0,     0,
      99,   100,   101,   102,   103,   104,     0,   105,   106,     0,
     107,   108,   109,   110,   111,     0,     0,     0,     0,   112,
     113,   114,   115,   116,   117,   118,   119,     0,   120,     0,
     121,   122,     0,     0,   123,   124,   125,     0,     0,     0,
     126,     0,   127,   128,   129,     0,     0,     0,     0,     0,
     130,     0,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,     0,     0,   142,   143,   144,     0,   392,
       0,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,     0,   192,   193,   194,
       0,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,     0,
     243,     0,     0,   244,   245,     1,     2,     3,     4,     5,
       6,     7,     8,     0,     9,     0,     0,     0,   781,   390,
       0,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,   391,    26,    27,    28,    29,    30,
       0,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,     0,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,     0,
      68,    69,    70,    71,     0,     0,    72,    73,    74,     0,
       0,    75,    76,     0,     0,     0,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,     0,     0,     0,
       0,    88,     0,    89,    90,    91,    92,     0,    93,     0,
       0,     0,    94,    95,    96,    97,    98,     0,     0,     0,
       0,     0,     0,    99,   100,   101,   102,   103,   104,     0,
     105,   106,     0,   107,   108,   109,   110,   111,     0,     0,
       0,     0,   112,   113,   114,   115,   116,   117,   118,   119,
       0,   120,     0,   121,   122,     0,     0,   123,   124,   125,
       0,     0,     0,   126,     0,   127,   128,   129,     0,     0,
       0,     0,     0,   130,     0,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,     0,     0,   142,   143,
     144,     0,   392,     0,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,     0,
     192,   193,   194,     0,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,     0,   243,     0,     0,   244,   245,     1,     2,
       3,     4,     5,     6,     7,     8,     0,     9,     0,     0,
       0,   389,   390,     0,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,  1241,   391,    26,    27,
      28,    29,    30,     0,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,     0,    44,    45,
      46,  1242,  1243,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,     0,    68,    69,    70,    71,     0,     0,    72,
      73,    74,     0,     0,    75,    76,     0,     0,     0,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
       0,     0,     0,     0,    88,     0,    89,    90,    91,    92,
       0,    93,     0,     0,     0,    94,    95,    96,    97,    98,
       0,     0,     0,     0,     0,     0,    99,   100,   101,   102,
     103,   104,     0,   105,   106,     0,   107,   108,   109,   110,
     111,     0,     0,     0,     0,   112,   113,   114,   115,   116,
     117,   118,   119,     0,   120,     0,   121,   122,     0,     0,
     123,   124,   125,     0,     0,     0,   126,     0,   127,   128,
     129,     0,     0,     0,     0,     0,   130,     0,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,     0,
       0,   142,   143,   144,     0,   392,     0,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,  1244,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,     0,   192,   193,   194,     0,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,     0,   243,     0,     0,   244,
     245,     1,     2,     3,     4,     5,     6,     0,     0,     0,
       9,     0,     0,     0,   389,   390,     0,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,   489,
     391,    26,    27,    28,    29,    30,     0,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
       0,    44,    45,    46,   490,   491,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,     0,    68,    69,    70,    71,
       0,     0,    72,    73,    74,     0,     0,    75,    76,     0,
       0,     0,    77,    78,   466,    80,    81,    82,    83,    84,
     492,    86,    87,     0,     0,     0,     0,    88,     0,    89,
      90,    91,    92,     0,    93,     0,     0,     0,    94,    95,
      96,    97,    98,     0,     0,     0,     0,   834,     0,    99,
     100,   101,   102,   103,   104,     0,   493,   106,     0,   107,
     108,   109,   110,   111,     0,     0,     0,     0,   112,   113,
     114,   115,   116,   117,   118,   119,     0,   120,     0,   121,
     122,     0,     0,   123,   124,   125,     0,     0,     0,   126,
     835,   127,   128,     0,     0,     0,     0,     0,     0,   130,
       0,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,     0,     0,   142,   143,   144,     0,   392,     0,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   472,   473,   474,   175,   176,
     475,   495,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,     0,   192,   193,   194,     0,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,     0,   243,
       0,     0,   244,   245,     1,     2,     3,     4,     5,     6,
       0,     0,     0,     9,     0,     0,     0,   389,   390,     0,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,   489,   391,    26,    27,    28,    29,    30,     0,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,     0,    44,    45,    46,   490,   491,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,     0,    68,
      69,    70,    71,     0,     0,    72,    73,    74,     0,     0,
      75,    76,     0,     0,     0,    77,    78,   466,    80,    81,
      82,    83,    84,   492,    86,    87,     0,     0,     0,     0,
      88,     0,    89,    90,    91,    92,     0,    93,     0,     0,
       0,    94,    95,    96,    97,    98,     0,     0,     0,     0,
     834,     0,    99,   100,   101,   102,   103,   104,     0,   493,
     106,     0,   107,   108,   109,   110,   111,     0,     0,     0,
       0,   112,   113,   114,   115,   116,   117,   118,   119,     0,
     120,     0,   121,   122,     0,     0,   123,   124,   125,     0,
       0,     0,   126,   840,   127,   128,     0,     0,     0,     0,
       0,     0,   130,     0,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,     0,     0,   142,   143,   144,
       0,   392,     0,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   472,   473,
     474,   175,   176,   475,   495,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,     0,   192,
     193,   194,     0,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,     0,   243,     0,     0,   244,   245,     1,     2,     3,
       4,     5,     6,     0,     0,     0,     9,     0,     0,     0,
     389,   390,     0,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,   489,   391,    26,    27,    28,
      29,    30,     0,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,     0,    44,    45,    46,
     490,   491,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,     0,    68,    69,    70,    71,     0,     0,    72,    73,
      74,     0,     0,    75,    76,     0,     0,     0,    77,    78,
     466,    80,    81,    82,    83,    84,   492,    86,    87,     0,
       0,     0,     0,    88,     0,    89,    90,    91,    92,     0,
      93,     0,     0,     0,    94,    95,    96,    97,    98,     0,
       0,     0,     0,     0,     0,    99,   100,   101,   102,   103,
     104,     0,   493,   106,     0,   107,   108,   109,   110,   111,
       0,     0,     0,     0,   112,   113,   114,   115,   116,   117,
     118,   119,     0,   120,     0,   121,   122,     0,     0,   123,
     124,   125,     0,     0,   494,   126,     0,   127,   128,     0,
       0,     0,     0,     0,     0,   130,     0,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,     0,     0,
     142,   143,   144,     0,   392,     0,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   472,   473,   474,   175,   176,   475,   495,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,     0,   192,   193,   194,     0,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,     0,   243,     0,     0,   244,   245,
       1,     2,     3,     4,     5,     6,     0,     0,     0,     9,
       0,     0,     0,   389,   390,     0,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,   489,   391,
      26,    27,    28,    29,    30,     0,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,     0,
      44,    45,    46,   490,   491,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,     0,    68,    69,    70,    71,     0,
       0,    72,    73,    74,     0,     0,    75,    76,     0,     0,
       0,    77,    78,   466,    80,    81,    82,    83,    84,   492,
      86,    87,     0,     0,     0,     0,    88,     0,    89,    90,
      91,    92,     0,    93,     0,     0,     0,    94,    95,    96,
      97,    98,     0,     0,     0,     0,     0,     0,    99,   100,
     101,   102,   103,   104,     0,   493,   106,     0,   107,   108,
     109,   110,   111,     0,     0,     0,     0,   112,   113,   114,
     115,   116,   117,   118,   119,     0,   120,     0,   121,   122,
       0,     0,   123,   124,   125,     0,     0,     0,   126,   499,
     127,   128,     0,     0,     0,     0,     0,     0,   130,     0,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,     0,     0,   142,   143,   144,     0,   392,     0,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   472,   473,   474,   175,   176,   475,
     495,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,     0,   192,   193,   194,     0,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,     0,   243,     0,
       0,   244,   245,     1,     2,     3,     4,     5,     6,     0,
       0,     0,     9,     0,     0,     0,   389,   390,     0,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,   489,   391,    26,    27,    28,    29,    30,     0,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,     0,    44,    45,    46,   490,   491,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,     0,    68,    69,
      70,    71,     0,     0,    72,    73,    74,     0,     0,    75,
      76,     0,     0,     0,    77,    78,   466,    80,    81,    82,
      83,    84,   492,    86,    87,     0,     0,     0,     0,    88,
       0,    89,    90,    91,    92,     0,    93,     0,     0,     0,
      94,    95,    96,    97,    98,     0,     0,     0,     0,     0,
       0,    99,   100,   101,   102,   103,   104,     0,   493,   106,
       0,   107,   108,   109,   110,   111,     0,     0,     0,     0,
     112,   113,   114,   115,   116,   117,   118,   119,     0,   120,
       0,   121,   122,     0,     0,   123,   124,   125,     0,     0,
       0,   126,     0,   127,   128,     0,     0,     0,     0,     0,
       0,   130,     0,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,     0,     0,   142,   143,   144,     0,
     392,     0,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   472,   473,   474,
     175,   176,   475,   495,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,     0,   192,   193,
     194,     0,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     537,   243,     0,     0,   244,   245,     1,     2,     3,     4,
       5,     6,     0,     0,     0,     9,     0,     0,     0,   389,
     390,     0,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,   489,   391,    26,    27,    28,    29,
      30,     0,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,     0,    44,    45,    46,   490,
     491,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
       0,    68,    69,    70,    71,     0,     0,    72,    73,    74,
       0,     0,    75,    76,     0,     0,     0,    77,    78,   466,
      80,    81,    82,    83,    84,   492,    86,    87,     0,     0,
       0,     0,    88,     0,    89,    90,    91,    92,     0,    93,
       0,     0,     0,    94,    95,    96,    97,    98,     0,     0,
       0,     0,     0,     0,    99,   100,   101,   102,   103,   104,
       0,   493,   106,     0,   107,   108,   109,   110,   111,     0,
       0,     0,     0,   112,   113,   114,   115,   116,   117,   118,
     119,     0,   120,     0,   121,   122,     0,     0,   123,   124,
     125,     0,     0,     0,   126,     0,   127,   128,     0,     0,
       0,     0,     0,     0,   130,     0,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,     0,     0,   142,
     143,   144,     0,   392,     0,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     472,   473,   474,   175,   176,   475,   495,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
       0,   192,   193,   194,     0,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,     0,   243,   539,     0,   244,   245,     1,
       2,     3,     4,     5,     6,     0,     0,     0,     9,     0,
       0,     0,   389,   390,     0,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,   489,   391,    26,
      27,    28,    29,    30,     0,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,     0,    44,
      45,    46,   490,   491,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,     0,    68,    69,    70,    71,     0,     0,
      72,    73,    74,     0,     0,    75,    76,     0,     0,     0,
      77,    78,   466,    80,    81,    82,    83,    84,   492,    86,
      87,     0,     0,     0,     0,    88,     0,    89,    90,    91,
      92,     0,    93,     0,     0,     0,    94,    95,    96,    97,
      98,     0,     0,     0,     0,     0,     0,    99,   100,   101,
     102,   103,   104,     0,   493,   106,     0,   107,   108,   109,
     110,   111,     0,     0,     0,     0,   112,   113,   114,   115,
     116,   117,   118,   119,     0,   120,     0,   121,   122,     0,
       0,   123,   124,   125,     0,     0,     0,   126,     0,   127,
     128,     0,     0,     0,     0,     0,     0,   130,     0,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
       0,     0,   142,   143,   144,     0,   392,     0,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   472,   473,   474,   175,   176,   475,   495,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,     0,   192,   193,   194,     0,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,     0,   243,     0,   541,
     244,   245,     1,     2,     3,     4,     5,     6,     0,     0,
       0,     9,     0,     0,     0,   389,   390,     0,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
     489,   391,    26,    27,    28,    29,    30,     0,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,     0,    44,    45,    46,   490,   491,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,     0,    68,    69,    70,
      71,     0,     0,    72,    73,    74,     0,     0,    75,    76,
       0,     0,     0,    77,    78,   466,    80,    81,    82,    83,
      84,   492,    86,    87,     0,     0,     0,     0,    88,     0,
      89,    90,    91,    92,     0,    93,     0,     0,     0,    94,
      95,    96,    97,    98,     0,     0,     0,     0,     0,     0,
      99,   100,   101,   102,   103,   104,     0,   493,   106,     0,
     107,   108,   109,   110,   111,     0,     0,     0,     0,   112,
     113,   114,   115,   116,   117,   118,   119,     0,   120,     0,
     121,   122,     0,     0,   123,   124,   125,     0,   827,     0,
     126,     0,   127,   128,     0,     0,     0,     0,     0,     0,
     130,     0,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,     0,     0,   142,   143,   144,     0,   392,
       0,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   472,   473,   474,   175,
     176,   475,   495,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,     0,   192,   193,   194,
       0,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,     0,
     243,     0,     0,   244,   245,     1,     2,     3,     4,     5,
       6,     0,     0,     0,     9,     0,     0,     0,   389,   390,
       0,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,   489,   391,    26,    27,    28,    29,    30,
       0,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,     0,    44,    45,    46,   490,   491,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,     0,
      68,    69,    70,    71,     0,     0,    72,    73,    74,     0,
       0,    75,    76,     0,     0,     0,    77,    78,   466,    80,
      81,    82,    83,    84,   492,    86,    87,     0,     0,     0,
       0,    88,     0,    89,    90,    91,    92,     0,    93,     0,
       0,     0,    94,    95,    96,    97,    98,     0,     0,     0,
       0,  1355,     0,    99,   100,   101,   102,   103,   104,     0,
     493,   106,     0,   107,   108,   109,   110,   111,     0,     0,
       0,     0,   112,   113,   114,   115,   116,   117,   118,   119,
       0,   120,     0,   121,   122,     0,     0,   123,   124,   125,
       0,     0,     0,   126,     0,   127,   128,     0,     0,     0,
       0,     0,     0,   130,     0,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,     0,     0,   142,   143,
     144,     0,   392,     0,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   472,
     473,   474,   175,   176,   475,   495,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,     0,
     192,   193,   194,     0,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,     0,   243,     0,     0,   244,   245,     1,     2,
       3,     4,     5,     6,     0,     0,     0,     9,     0,     0,
       0,   389,   390,     0,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,   489,   391,    26,    27,
      28,    29,    30,     0,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,     0,    44,    45,
      46,   490,   491,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,     0,    68,    69,    70,    71,     0,     0,    72,
      73,    74,     0,     0,    75,    76,     0,     0,     0,    77,
      78,   466,    80,    81,    82,    83,    84,   492,    86,    87,
       0,     0,     0,     0,    88,     0,    89,    90,    91,    92,
       0,    93,     0,     0,     0,    94,    95,    96,    97,    98,
       0,     0,     0,     0,     0,     0,    99,   100,   101,   102,
     103,   104,     0,   493,   106,     0,   107,   108,   109,   110,
     111,     0,     0,     0,     0,   112,   113,   114,   115,   116,
     117,   118,   119,     0,   120,     0,   121,   122,     0,     0,
     123,   124,   125,     0,     0,     0,   126,     0,   127,   128,
       0,     0,     0,     0,     0,     0,   130,     0,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,     0,
       0,   142,   143,   144,     0,   392,     0,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   472,   473,   474,   175,   176,   475,   495,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,     0,   192,   193,   194,     0,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,     0,   243,     0,     0,   244,
     245,     1,     2,     3,     4,     5,     6,     0,     0,     0,
       9,     0,     0,     0,   389,   390,     0,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,   489,
     391,    26,    27,    28,    29,    30,     0,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
       0,    44,    45,    46,   490,   491,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,     0,    68,    69,    70,    71,
       0,     0,    72,    73,    74,     0,     0,    75,    76,     0,
       0,     0,    77,    78,   466,    80,    81,    82,    83,    84,
     492,    86,    87,     0,     0,     0,     0,    88,     0,    89,
      90,    91,    92,     0,    93,     0,     0,     0,    94,    95,
      96,    97,    98,     0,     0,     0,     0,     0,     0,    99,
     100,   101,   102,   103,   104,     0,   493,   106,     0,     0,
     108,   109,   110,   111,     0,     0,     0,     0,   112,   113,
     114,   115,   116,   117,   118,   119,     0,   120,     0,   121,
     122,     0,     0,   123,   124,   125,     0,     0,     0,   126,
       0,   127,   128,     0,     0,     0,     0,     0,     0,   130,
       0,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,     0,     0,   142,   143,   144,     0,   392,     0,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   472,   473,   474,   175,   176,
     475,   495,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,     0,   192,   193,   194,     0,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,     0,   243,
       0,     0,   244,   245,     1,     2,     3,     4,     5,     6,
       0,     0,     0,     9,     0,     0,     0,   389,   390,     0,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
     455,    23,   457,   391,    26,   458,    28,    29,    30,     0,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,   460,     0,    44,    45,    46,   462,   463,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,     0,    68,
      69,    70,    71,     0,     0,    72,    73,    74,     0,     0,
      75,    76,     0,     0,     0,    77,    78,   466,    80,    81,
      82,    83,    84,   492,    86,    87,     0,     0,     0,     0,
      88,     0,    89,    90,    91,    92,     0,    93,     0,     0,
       0,   467,    95,    96,    97,    98,     0,     0,     0,     0,
       0,     0,    99,   100,   101,   102,   103,   104,     0,   493,
     106,     0,   107,   108,   616,   110,   111,     0,     0,     0,
       0,   112,   113,   114,   115,   116,   117,   118,   119,     0,
     120,     0,   617,   122,     0,     0,   123,   124,   125,     0,
       0,     0,   126,     0,   127,   128,     0,     0,     0,     0,
       0,     0,   130,     0,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,     0,     0,   142,   143,   144,
       0,   392,     0,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,     0,   159,     0,   161,     0,     0,
     164,   165,   166,   167,   168,   169,   471,   171,   472,   473,
     474,   175,   176,   475,   476,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   477,     0,   192,
     478,   194,     0,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,     0,   243,     0,     0,     0,   245,     1,     2,     3,
       4,     5,     6,     0,     0,     0,     9,     0,     0,     0,
     389,   390,     0,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,   455,    23,   457,   391,    26,   458,    28,
      29,    30,     0,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,   460,     0,    44,    45,    46,
     462,   463,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,     0,    68,    69,    70,    71,     0,     0,    72,    73,
      74,     0,     0,    75,    76,     0,     0,     0,    77,    78,
     466,    80,    81,    82,    83,    84,   492,    86,    87,     0,
       0,     0,     0,    88,     0,    89,    90,    91,    92,     0,
      93,     0,     0,     0,   467,    95,    96,    97,    98,     0,
       0,     0,     0,     0,     0,    99,   100,   101,   102,   103,
     104,     0,   493,   106,     0,   107,   108,   109,   110,   111,
       0,     0,     0,     0,   112,   113,   114,   115,   116,   117,
     118,   119,     0,   120,     0,   121,   122,     0,     0,   123,
     124,   125,     0,     0,     0,   126,     0,   127,   128,     0,
       0,     0,     0,     0,     0,   130,     0,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,     0,     0,
     142,   143,   144,     0,   392,     0,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,     0,   159,     0,
     161,     0,     0,   164,   165,   166,   167,   168,   169,   471,
     171,   472,   473,   474,   175,   176,   475,   476,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     477,     0,   192,   193,   194,     0,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,     0,   243,     0,     0,     0,   245,
       1,     2,     3,     4,     5,     6,     0,     0,     0,     9,
       0,     0,     0,   389,   390,     0,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,   455,    23,   457,   391,
      26,   458,    28,    29,    30,     0,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,   460,     0,
      44,    45,    46,   462,   463,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,     0,    68,    69,    70,    71,     0,
       0,    72,    73,    74,     0,     0,    75,    76,     0,     0,
       0,    77,    78,   466,    80,    81,    82,    83,    84,   492,
      86,    87,     0,     0,     0,     0,    88,     0,    89,    90,
      91,    92,     0,    93,     0,     0,     0,   467,    95,    96,
      97,    98,     0,     0,     0,     0,     0,     0,    99,   100,
     101,   102,   103,   104,     0,   493,   106,     0,   107,   108,
     109,   110,   111,     0,     0,     0,     0,   112,   113,   114,
     115,   116,   117,   118,   119,     0,   120,     0,   121,   122,
       0,     0,   123,   124,   125,     0,     0,     0,   126,     0,
     127,   128,     0,     0,     0,     0,     0,     0,   130,     0,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,     0,     0,   142,   143,   144,     0,   392,     0,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
       0,   159,     0,   161,     0,     0,   164,   165,   166,   167,
     168,   169,   471,   171,   472,   473,   474,   175,   176,   475,
     476,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   477,     0,   192,   478,   194,     0,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,     0,   243,     0,
       0,     0,   245,     1,     2,     3,     4,     5,     6,     0,
       0,     0,     9,     0,     0,     0,   389,   390,     0,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,   455,
      23,   457,   391,    26,   458,    28,    29,    30,     0,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,   460,     0,    44,    45,    46,   462,   463,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,     0,    68,    69,
      70,    71,     0,     0,    72,    73,    74,     0,     0,    75,
      76,     0,     0,     0,    77,    78,   466,    80,    81,    82,
      83,    84,   492,    86,    87,     0,     0,     0,     0,    88,
       0,    89,    90,    91,    92,     0,    93,     0,     0,     0,
     467,    95,    96,    97,    98,     0,     0,     0,     0,     0,
       0,    99,   100,   101,   102,   103,   104,     0,   493,   106,
       0,     0,   108,   109,   110,   111,     0,     0,     0,     0,
     112,   113,   114,   115,   116,   117,   118,   119,     0,   120,
       0,   121,   122,     0,     0,   123,   124,   125,     0,     0,
       0,   126,     0,   127,   128,     0,     0,     0,     0,     0,
       0,   130,     0,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,     0,     0,   142,   143,   144,     0,
     392,     0,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,     0,   159,     0,   161,     0,     0,   164,
     165,   166,   167,   168,   169,   471,   171,   472,   473,   474,
     175,   176,   475,   476,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   477,     0,   192,   193,
     194,     0,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
       0,   243,     0,     0,     0,   245,     1,     2,     3,     4,
       5,     6,     0,     0,     0,     9,     0,     0,     0,   389,
     390,     0,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,   455,    23,   457,   391,    26,   458,    28,    29,
      30,     0,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,   460,     0,    44,    45,    46,   462,
     463,    49,   464,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
       0,    68,    69,    70,    71,     0,     0,    72,    73,    74,
       0,     0,    75,    76,     0,     0,     0,    77,    78,   466,
      80,    81,    82,    83,    84,   492,    86,    87,     0,     0,
       0,     0,    88,     0,    89,    90,    91,    92,     0,    93,
       0,     0,     0,   467,    95,    96,    97,    98,     0,     0,
       0,     0,     0,     0,    99,   100,   101,   102,   103,   104,
       0,   493,   106,     0,   107,   108,     0,   110,   111,     0,
       0,     0,     0,   112,   113,   114,   115,   116,   117,   118,
     119,     0,   120,     0,     0,     0,     0,     0,   123,   124,
     125,     0,     0,     0,   126,     0,   127,   128,     0,     0,
       0,     0,     0,     0,   130,     0,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,     0,     0,   142,
     143,   144,     0,   392,     0,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,     0,   514,     0,   515,
       0,     0,   164,   165,   166,   167,   168,   169,   471,   171,
     472,   473,   474,   175,   176,   475,   476,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   477,
       0,   192,   478,   194,     0,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,     0,   243,     0,   516,     0,   245,     1,
       2,     3,     4,     5,     6,     0,     0,     0,     9,     0,
       0,     0,   389,   390,     0,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,   455,    23,   457,   391,    26,
     458,    28,    29,    30,     0,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,   460,     0,    44,
      45,    46,   462,   463,    49,   464,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,     0,    68,    69,    70,    71,     0,     0,
      72,    73,    74,     0,     0,    75,    76,     0,     0,     0,
      77,    78,   466,    80,    81,    82,    83,    84,   492,    86,
      87,     0,     0,     0,     0,    88,     0,    89,    90,    91,
      92,     0,    93,     0,     0,     0,   467,    95,    96,    97,
      98,     0,     0,     0,     0,     0,     0,    99,   100,   101,
     102,   103,   104,     0,   493,   106,     0,   107,   108,     0,
     110,   111,     0,     0,     0,     0,   112,   113,   114,   115,
     116,   117,   118,   119,     0,   120,     0,     0,     0,     0,
       0,   123,   124,   125,     0,     0,     0,   126,     0,   127,
     128,     0,     0,     0,     0,     0,     0,   130,     0,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
       0,     0,   142,   143,   144,     0,   392,     0,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,     0,
     523,     0,   161,     0,     0,   164,   165,   166,   167,   168,
     169,   471,   171,   472,   473,   474,   175,   176,   475,   476,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   477,     0,   192,   478,   194,     0,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,     0,   243,     0,   524,
       0,   245,     1,     2,     3,     4,     5,     6,     0,     0,
       0,     9,     0,     0,     0,   389,   390,     0,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,   455,    23,
     457,   391,    26,   458,    28,    29,    30,     0,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
     460,     0,    44,    45,    46,   462,   463,    49,   464,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,     0,    68,    69,    70,
      71,     0,     0,    72,    73,    74,     0,     0,    75,    76,
       0,     0,     0,    77,    78,   466,    80,    81,    82,    83,
      84,   492,    86,    87,     0,     0,     0,     0,    88,     0,
      89,    90,    91,    92,     0,    93,     0,     0,     0,   467,
      95,    96,    97,    98,     0,     0,     0,     0,     0,     0,
      99,   100,   101,   102,   103,   104,     0,   493,   106,     0,
     107,   108,     0,   110,   111,     0,     0,     0,     0,   112,
     113,   114,   115,   116,   117,   118,   119,     0,   120,     0,
       0,     0,     0,     0,   123,   124,   125,     0,     0,     0,
     126,     0,   127,   128,     0,     0,     0,     0,     0,     0,
     130,     0,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,     0,     0,   142,   143,   144,     0,   392,
       0,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,     0,   159,     0,   161,     0,     0,   164,   165,
     166,   167,   168,   169,   471,   171,   472,   473,   474,   175,
     176,   475,   476,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   477,     0,   192,   478,   194,
       0,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,     0,
     243,     0,     0,     0,   245,     1,     2,     3,     4,     5,
       6,     0,     0,     0,     9,     0,     0,     0,   389,   390,
       0,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,   455,    23,   457,   391,    26,   458,    28,    29,    30,
       0,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,   460,     0,    44,    45,    46,   462,   463,
      49,   464,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,     0,
      68,    69,    70,    71,     0,     0,    72,    73,    74,     0,
       0,    75,    76,     0,     0,     0,    77,    78,   466,    80,
      81,    82,    83,    84,   492,    86,    87,     0,     0,     0,
       0,    88,     0,    89,    90,    91,    92,     0,    93,     0,
       0,     0,   467,    95,    96,    97,    98,     0,     0,     0,
       0,     0,     0,    99,   100,   101,   102,   103,   104,     0,
     493,   106,     0,   107,   108,     0,   110,   111,     0,     0,
       0,     0,   112,   113,   114,   115,   116,   117,   118,   119,
       0,   120,     0,     0,     0,     0,     0,   123,   124,   125,
       0,     0,     0,   126,     0,   127,   128,     0,     0,     0,
       0,     0,     0,   130,     0,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,     0,     0,   142,   143,
     144,     0,   392,     0,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,     0,   979,     0,   161,     0,
       0,   164,   165,   166,   167,   168,   169,   471,   171,   472,
     473,   474,   175,   176,   475,   476,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   477,     0,
     192,   478,   194,     0,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,     0,   243,     5,     6,     0,   245,     0,     0,
       0,     0,     0,   389,   390,     0,    12,    13,    14,  1044,
      16,    17,    18,   453,  1045,  1046,   455,  1047,   457,   391,
      26,   458,    28,  1048,    30,     0,    31,    32,    33,    34,
    1049,    36,  1050,  1051,    39,    40,    41,    42,   460,     0,
      44,  1052,    46,   462,   463,    49,   464,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,     0,    68,    69,    70,  1053,     0,
       0,    72,    73,    74,     0,     0,    75,    76,     0,     0,
       0,     0,    78,   466,    80,    81,    82,    83,    84,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    89,    90,
      91,    92,     0,    93,     0,     0,     0,   467,    95,    96,
      97,    98,     0,     0,     0,     0,     0,     0,    99,   100,
     101,     0,   103,   104,  1054,     0,     0,     0,  1055,     0,
       0,   110,   468,     0,     0,     0,     0,   112,   113,   114,
     115,   469,   117,   118,   119,     0,     0,     0,     0,     0,
       0,     0,   123,   124,   125,     0,     0,     0,   126,  1512,
     127,   128,     0,     0,     0,     0,  1513,     0,   130,     0,
     131,   132,   133,   134,   470,   136,   137,   138,   139,   140,
     141,     0,     0,  1056,   143,     0,     0,   392,     0,   147,
     148,     0,     0,     0,   152,   153,   154,   155,   156,   157,
       0,  1057,     0,   161,     0,     0,   164,   165,   166,   167,
     168,   169,   471,   171,   472,   473,   474,   175,   176,   475,
     476,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   477,     0,   192,   478,   194,     0,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,     0,     0,     5,     6,
       0,     0,   245,  1058,  1059,  1060,  1061,   389,   390,     0,
      12,    13,    14,  1044,    16,    17,    18,   453,  1045,  1046,
     455,  1047,   457,   391,    26,   458,    28,  1048,    30,     0,
      31,    32,    33,    34,  1049,    36,  1050,  1051,    39,    40,
      41,    42,   460,     0,    44,  1052,    46,   462,   463,    49,
     464,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,     0,    68,
      69,    70,  1053,     0,     0,    72,    73,    74,     0,     0,
      75,    76,     0,     0,     0,     0,    78,   466,    80,    81,
      82,    83,    84,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    89,    90,    91,    92,     0,    93,     0,     0,
       0,   467,    95,    96,    97,    98,     0,     0,     0,     0,
       0,     0,    99,   100,   101,     0,   103,   104,  1054,     0,
       0,     0,  1105,     0,     0,   110,   468,     0,     0,     0,
       0,   112,   113,   114,   115,   469,   117,   118,   119,     0,
       0,     0,     0,     0,     0,     0,   123,   124,   125,     0,
       0,     0,   126,  1342,   127,   128,     0,     0,     0,     0,
       0,     0,   130,     0,   131,   132,   133,   134,   470,   136,
     137,   138,   139,   140,   141,     0,     0,   142,   143,     0,
       0,   392,     0,   147,   148,     0,     0,     0,   152,   153,
     154,   155,   156,   157,     0,  1057,     0,   161,     0,     0,
     164,   165,   166,   167,   168,   169,   471,   171,   472,   473,
     474,   175,   176,   475,   476,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   477,     0,   192,
     478,   194,     0,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
       0,     0,     5,     6,     0,     0,   245,  1058,  1059,  1060,
    1061,   389,   390,     0,    12,    13,    14,  1044,    16,    17,
      18,   453,  1045,  1046,   455,  1047,   457,   391,    26,   458,
      28,  1048,    30,     0,    31,    32,    33,    34,  1049,    36,
    1050,  1051,    39,    40,    41,    42,   460,     0,    44,  1052,
      46,   462,   463,    49,   464,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,     0,    68,    69,    70,  1053,     0,     0,    72,
      73,    74,     0,     0,    75,    76,     0,     0,     0,     0,
      78,   466,    80,    81,    82,    83,    84,  1399,     0,     0,
       0,     0,     0,     0,     0,     0,    89,    90,    91,    92,
       0,    93,     0,     0,     0,   467,    95,    96,    97,    98,
       0,     0,     0,     0,     0,     0,    99,   100,   101,     0,
     103,   104,  1054,     0,     0,     0,  1055,     0,     0,   110,
     468,     0,     0,     0,     0,   112,   113,   114,   115,   469,
     117,   118,   119,     0,     0,     0,     0,     0,     0,     0,
     123,   124,   125,     0,     0,     0,   126,     0,   127,   128,
       0,     0,     0,     0,     0,     0,   130,     0,   131,   132,
     133,   134,   470,   136,   137,   138,   139,   140,   141,     0,
       0,  1056,   143,     0,     0,   392,     0,   147,   148,     0,
       0,     0,   152,   153,   154,   155,   156,   157,     0,  1057,
       0,   161,     0,     0,   164,   165,   166,   167,   168,   169,
     471,   171,   472,   473,   474,   175,   176,   475,   476,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   477,     0,   192,   478,   194,     0,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,     0,     0,     5,     6,     0,     0,
     245,  1058,  1059,  1060,  1061,   389,   390,     0,    12,    13,
      14,  1044,    16,    17,    18,   453,  1045,  1046,   455,  1047,
     457,   391,    26,   458,    28,  1048,    30,     0,    31,    32,
      33,    34,  1049,    36,  1050,  1051,    39,    40,    41,    42,
     460,     0,    44,  1052,    46,   462,   463,    49,   464,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,     0,    68,    69,    70,
    1053,     0,     0,    72,    73,    74,     0,     0,    75,    76,
       0,     0,     0,     0,    78,   466,    80,    81,    82,    83,
      84,  1568,     0,     0,     0,     0,     0,     0,     0,     0,
      89,    90,    91,    92,     0,    93,     0,     0,     0,   467,
      95,    96,    97,    98,     0,     0,     0,     0,     0,     0,
      99,   100,   101,     0,   103,   104,  1054,     0,     0,     0,
    1055,     0,     0,   110,   468,     0,     0,     0,     0,   112,
     113,   114,   115,   469,   117,   118,   119,     0,     0,     0,
       0,     0,     0,     0,   123,   124,   125,     0,     0,     0,
     126,     0,   127,   128,     0,     0,     0,     0,     0,     0,
     130,     0,   131,   132,   133,   134,   470,   136,   137,   138,
     139,   140,   141,     0,     0,  1056,   143,     0,     0,   392,
       0,   147,   148,     0,     0,     0,   152,   153,   154,   155,
     156,   157,     0,  1057,     0,   161,     0,     0,   164,   165,
     166,   167,   168,   169,   471,   171,   472,   473,   474,   175,
     176,   475,   476,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   477,     0,   192,   478,   194,
       0,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,     0,     0,
       5,     6,     0,     0,   245,  1058,  1059,  1060,  1061,   389,
     390,     0,    12,    13,    14,  1044,    16,    17,    18,   453,
    1045,  1046,   455,  1047,   457,   391,    26,   458,    28,  1048,
      30,     0,    31,    32,    33,    34,  1049,    36,  1050,  1051,
      39,    40,    41,    42,   460,     0,    44,  1052,    46,   462,
     463,    49,   464,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
       0,    68,    69,    70,  1053,     0,     0,    72,    73,    74,
       0,     0,    75,    76,     0,     0,     0,     0,    78,   466,
      80,    81,    82,    83,    84,  1572,     0,     0,     0,     0,
       0,     0,     0,     0,    89,    90,    91,    92,     0,    93,
       0,     0,     0,   467,    95,    96,    97,    98,     0,     0,
       0,     0,     0,     0,    99,   100,   101,     0,   103,   104,
    1054,     0,     0,     0,  1055,     0,     0,   110,   468,     0,
       0,     0,     0,   112,   113,   114,   115,   469,   117,   118,
     119,     0,     0,     0,     0,     0,     0,     0,   123,   124,
     125,     0,     0,     0,   126,     0,   127,   128,     0,     0,
       0,     0,     0,     0,   130,     0,   131,   132,   133,   134,
     470,   136,   137,   138,   139,   140,   141,     0,     0,  1056,
     143,     0,     0,   392,     0,   147,   148,     0,     0,     0,
     152,   153,   154,   155,   156,   157,     0,  1057,     0,   161,
       0,     0,   164,   165,   166,   167,   168,   169,   471,   171,
     472,   473,   474,   175,   176,   475,   476,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   477,
       0,   192,   478,   194,     0,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,     0,     0,     5,     6,     0,     0,   245,  1058,
    1059,  1060,  1061,   389,   390,     0,    12,    13,    14,  1044,
      16,    17,    18,   453,  1045,  1046,   455,  1047,   457,   391,
      26,   458,    28,  1048,    30,     0,    31,    32,    33,    34,
    1049,    36,  1050,  1051,    39,    40,    41,    42,   460,     0,
      44,  1052,    46,   462,   463,    49,   464,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,     0,    68,    69,    70,  1053,     0,
       0,    72,    73,    74,     0,     0,    75,    76,     0,     0,
       0,     0,    78,   466,    80,    81,    82,    83,    84,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    89,    90,
      91,    92,     0,    93,     0,     0,     0,   467,    95,    96,
      97,    98,     0,     0,     0,     0,     0,     0,    99,   100,
     101,     0,   103,   104,  1054,     0,     0,     0,  1055,     0,
       0,   110,   468,     0,     0,     0,     0,   112,   113,   114,
     115,   469,   117,   118,   119,     0,     0,     0,     0,     0,
       0,     0,   123,   124,   125,     0,     0,     0,   126,     0,
     127,   128,     0,     0,     0,     0,     0,     0,   130,     0,
     131,   132,   133,   134,   470,   136,   137,   138,   139,   140,
     141,     0,     0,  1056,   143,     0,     0,   392,     0,   147,
     148,     0,     0,     0,   152,   153,   154,   155,   156,   157,
       0,  1057,     0,   161,     0,     0,   164,   165,   166,   167,
     168,   169,   471,   171,   472,   473,   474,   175,   176,   475,
     476,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   477,     0,   192,   478,   194,     0,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,     0,     0,     5,     6,
       0,     0,   245,  1058,  1059,  1060,  1061,   389,   390,     0,
      12,    13,    14,  1044,    16,    17,    18,   453,  1045,  1046,
     455,  1047,   457,   391,    26,   458,    28,  1048,    30,     0,
      31,    32,    33,    34,  1049,    36,  1050,  1051,    39,    40,
      41,    42,   460,     0,    44,  1052,    46,   462,   463,    49,
     464,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,     0,    68,
      69,    70,  1053,     0,     0,    72,    73,    74,     0,     0,
      75,    76,     0,     0,     0,     0,    78,   466,    80,    81,
      82,    83,    84,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    89,    90,    91,    92,     0,    93,     0,     0,
       0,   467,    95,    96,    97,    98,     0,     0,     0,     0,
       0,     0,    99,   100,   101,     0,   103,   104,  1054,     0,
       0,     0,  1105,     0,     0,   110,   468,     0,     0,     0,
       0,   112,   113,   114,   115,   469,   117,   118,   119,     0,
       0,     0,     0,     0,     0,     0,   123,   124,   125,     0,
       0,     0,   126,     0,   127,   128,     0,     0,     0,     0,
       0,     0,   130,     0,   131,   132,   133,   134,   470,   136,
     137,   138,   139,   140,   141,     0,     0,   142,   143,     0,
       0,   392,     0,   147,   148,     0,     0,     0,   152,   153,
     154,   155,   156,   157,     0,  1057,     0,   161,     0,     0,
     164,   165,   166,   167,   168,   169,   471,   171,   472,   473,
     474,   175,   176,   475,   476,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   477,     0,   192,
     478,   194,     0,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
       0,     0,     5,     6,     0,     0,   245,  1058,  1059,  1060,
    1061,   389,   390,     0,    12,    13,    14,   452,    16,    17,
      18,   453,    20,   454,   455,   456,   457,   391,    26,   458,
      28,    29,    30,     0,    31,    32,    33,    34,   459,    36,
      37,    38,    39,    40,    41,    42,   460,     0,    44,   461,
      46,   462,   463,    49,   464,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,     0,    68,    69,    70,   465,     0,     0,    72,
      73,    74,     0,     0,    75,    76,     0,     0,     0,     0,
      78,   466,    80,    81,    82,    83,    84,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    89,    90,    91,    92,
       0,    93,     0,     0,     0,   467,    95,    96,    97,    98,
       0,     0,     0,     0,     0,     0,    99,   100,   101,     0,
     103,   104,     0,     0,     0,     0,     0,     0,     0,   110,
     468,     0,     0,     0,     0,   112,   113,   114,   115,   469,
     117,   118,   119,     0,     0,     0,     0,     0,     0,     0,
     123,   124,   125,     0,     0,     0,   126,  1509,   127,   128,
       0,     0,     0,     0,  1510,     0,   130,     0,   131,   132,
     133,   134,   470,   136,   137,   138,   139,   140,   141,     0,
       0,   142,   143,     0,     0,   392,     0,   147,   148,     0,
       0,     0,   152,   153,   154,   155,   156,   157,     0,   159,
       0,   161,     0,     0,   164,   165,   166,   167,   168,   169,
     471,   171,   472,   473,   474,   175,   176,   475,   476,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   477,     0,   192,   478,   194,     0,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,     5,     6,     0,     0,     0,     0,
     245,     0,     0,   389,   390,     0,    12,    13,    14,   452,
      16,    17,    18,   453,    20,   454,   455,   456,   457,   391,
      26,   458,    28,    29,    30,     0,    31,    32,    33,    34,
     459,    36,    37,    38,    39,    40,    41,    42,   460,     0,
      44,   461,    46,   462,   463,    49,   464,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,     0,    68,    69,    70,   465,     0,
       0,    72,    73,    74,     0,     0,    75,    76,     0,     0,
       0,     0,    78,   466,    80,    81,    82,    83,    84,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    89,    90,
      91,    92,     0,    93,     0,     0,     0,   467,    95,    96,
      97,    98,     0,     0,     0,     0,     0,     0,    99,   100,
     101,     0,   103,   104,     0,     0,     0,     0,     0,     0,
       0,   110,   468,     0,     0,     0,     0,   112,   113,   114,
     115,   469,   117,   118,   119,     0,     0,     0,     0,     0,
       0,     0,   123,   124,   125,     0,     0,     0,   126,  1523,
     127,   128,     0,     0,     0,     0,  1524,     0,   130,     0,
     131,   132,   133,   134,   470,   136,   137,   138,   139,   140,
     141,     0,     0,   142,   143,     0,     0,   392,     0,   147,
     148,     0,     0,     0,   152,   153,   154,   155,   156,   157,
       0,   159,     0,   161,     0,     0,   164,   165,   166,   167,
     168,   169,   471,   171,   472,   473,   474,   175,   176,   475,
     476,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   477,     0,   192,   478,   194,     0,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,     5,     6,     0,     0,
       0,     0,   245,     0,     0,   389,   390,     0,    12,    13,
      14,   452,    16,    17,    18,   453,    20,   454,   455,   456,
     457,   391,    26,   458,    28,    29,    30,     0,    31,    32,
      33,    34,   459,    36,    37,    38,    39,    40,    41,    42,
     460,     0,    44,   461,    46,   462,   463,    49,   464,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,     0,    68,    69,    70,
     465,     0,     0,    72,    73,    74,     0,     0,    75,    76,
       0,     0,     0,     0,    78,   466,    80,    81,    82,    83,
      84,  1272,     0,     0,     0,     0,     0,     0,     0,     0,
      89,    90,    91,    92,     0,    93,     0,     0,     0,   467,
      95,    96,    97,    98,     0,     0,     0,     0,     0,     0,
      99,   100,   101,     0,   103,   104,     0,     0,     0,     0,
       0,     0,     0,   110,   468,     0,     0,     0,     0,   112,
     113,   114,   115,   469,   117,   118,   119,     0,     0,     0,
       0,     0,     0,     0,   123,   124,   125,     0,     0,     0,
     126,     0,   127,   128,     0,     0,     0,     0,     0,     0,
     130,     0,   131,   132,   133,   134,   470,   136,   137,   138,
     139,   140,   141,     0,     0,   142,   143,     0,     0,   392,
       0,   147,   148,     0,     0,     0,   152,   153,   154,   155,
     156,   157,     0,   159,     0,   161,     0,     0,   164,   165,
     166,   167,   168,   169,   471,   171,   472,   473,   474,   175,
     176,   475,   476,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   477,     0,   192,   478,   194,
       0,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,     5,     6,
       0,     0,     0,     0,   245,     0,     0,   389,   390,     0,
      12,    13,    14,   452,    16,    17,    18,   453,    20,   454,
     455,   456,   457,   391,    26,   458,    28,    29,    30,     0,
      31,    32,    33,    34,   459,    36,    37,    38,    39,    40,
      41,    42,   460,     0,    44,   461,    46,   462,   463,    49,
     464,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,     0,    68,
      69,    70,   465,     0,     0,    72,    73,    74,     0,     0,
      75,    76,     0,     0,     0,     0,    78,   466,    80,    81,
      82,    83,    84,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    89,    90,    91,    92,     0,    93,     0,     0,
       0,   467,    95,    96,    97,    98,     0,     0,     0,     0,
       0,     0,    99,   100,   101,     0,   103,   104,     0,     0,
       0,     0,     0,     0,     0,   110,   468,     0,     0,     0,
       0,   112,   113,   114,   115,   469,   117,   118,   119,     0,
       0,     0,     0,     0,     0,     0,   123,   124,   125,     0,
       0,     0,   126,     0,   127,   128,     0,     0,     0,     0,
       0,     0,   130,     0,   131,   132,   133,   134,   470,   136,
     137,   138,   139,   140,   141,     0,     0,   142,   143,     0,
       0,   392,     0,   147,   148,     0,     0,     0,   152,   153,
     154,   155,   156,   157,     0,   159,     0,   161,     0,     0,
     164,   165,   166,   167,   168,   169,   471,   171,   472,   473,
     474,   175,   176,   475,   476,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   477,     0,   192,
     478,   194,     0,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
       5,     6,     0,     0,     0,     0,   245,     0,     0,   389,
     390,     0,    12,    13,    14,     0,    16,    17,    18,   453,
       0,     0,   455,   456,     0,   391,    26,   458,    28,     0,
      30,     0,    31,    32,    33,    34,     0,    36,     0,     0,
      39,    40,    41,    42,   460,     0,    44,     0,    46,     0,
       0,    49,   464,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
       0,    68,    69,    70,     0,     0,     0,    72,    73,    74,
       0,     0,    75,    76,     0,     0,     0,     0,    78,   466,
      80,    81,    82,    83,    84,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    89,    90,    91,    92,     0,    93,
       0,     0,     0,   467,    95,    96,    97,    98,     0,     0,
       0,     0,     0,     0,    99,   100,   101,     0,   103,   104,
       0,     0,     0,     0,     0,     0,     0,   110,   468,     0,
       0,     0,     0,   112,   113,   114,   115,   469,   117,   118,
     119,     0,     0,     0,     0,     0,     0,     0,   123,   124,
     125,     0,     0,     0,   126,     0,   127,   128,     0,     0,
       0,     0,     0,     0,   130,     0,   131,   132,   133,   134,
     470,   136,   137,   138,   139,   140,   141,     0,     0,     0,
     143,     0,     0,   392,     0,   147,   148,     0,     0,     0,
     152,   153,   154,   155,   156,   157,     0,     0,     0,   161,
       0,     0,   164,   165,   166,   167,   168,   169,   471,   171,
     472,   473,   474,   175,   176,     0,   476,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   477,
       0,   192,   478,   194,     0,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,     0,     0,     0,     0,     0,     0,   245
  };

  /* YYCHECK.  */
  const short int
  jsoniq_parser::yycheck_[] =
  {
         0,     1,     2,     3,     4,     0,     1,     2,     3,     4,
     603,   106,   107,   285,   178,   120,   725,     1,     2,     3,
     619,   337,   306,   933,    10,   400,   401,   920,     1,     2,
       3,     4,   809,   402,     1,     2,     3,     4,   822,   823,
     604,   605,   606,   607,   158,   800,  1199,   622,   162,  1183,
     955,   800,   193,   160,     1,   254,   697,  1402,  1266,  1267,
    1405,     1,   556,   557,   433,   434,   707,   253,   246,   247,
     269,    27,    28,  1030,  1016,   897,   847,   554,   555,   897,
      57,  1323,    37,   644,    37,     1,  1212,   863,  1545,     1,
      31,     1,    48,    38,    39,   120,    41,    42,     1,    98,
     145,    98,     1,    30,   276,   105,  1600,    40,   150,    46,
     105,    48,    45,    46,    59,   554,   555,   556,   557,    30,
      76,    54,     1,   395,     1,     1,   910,   399,    61,     1,
      63,    64,   105,    95,    27,    28,   102,   921,   105,    72,
      53,    96,     1,    98,    81,    98,   109,   242,   243,   134,
       1,     1,     1,   102,     1,    48,   120,   159,   114,   800,
     120,    96,   109,   120,    46,    58,    99,     1,    55,   109,
     115,   108,    30,    60,   923,    43,   172,   221,   161,    47,
       8,   156,    64,    76,    52,   112,   156,   276,    81,    30,
     285,   109,    79,   109,   283,   150,   179,   150,   159,   120,
     127,   112,  1696,    71,   293,   180,   109,   232,   193,   205,
     180,    98,   484,   163,   498,   150,   127,   261,   163,   132,
     113,   114,   115,   189,   186,   152,   190,     1,   869,   189,
     193,   150,   189,   120,   171,   280,     1,   109,   280,  1447,
     189,   152,   951,     1,   221,   156,   246,   247,   159,   421,
     250,   246,   247,  1030,  1031,   250,     1,   115,   109,   109,
     109,  1718,   109,   109,   263,   264,   263,  1022,   909,   180,
    1180,  1020,  1165,  1022,   190,   109,   217,   771,   772,  1055,
    1414,   193,   227,   193,   261,   285,   655,   190,   849,   314,
     285,  1417,   769,   770,   193,   222,   223,   224,  1203,   232,
     395,   573,  1544,   171,   399,   163,   174,  1212,   190,   414,
      98,   222,   223,   224,   193,     1,   193,   193,   190,   688,
     425,   189,   163,   268,   242,   280,  1671,   280,  1150,  1105,
    1272,  1102,  1150,   428,   193,   109,   431,    85,   294,   190,
     190,   190,  1299,   190,   109,   440,   302,   215,   443,   444,
     178,   109,   551,   552,   449,   266,   190,   105,     1,   280,
     108,   280,   561,   161,   109,   543,   109,   124,   554,   555,
      96,   318,   120,  1157,   122,    56,   109,    58,   124,   139,
     320,   179,  1023,  1728,   172,  1730,   109,     0,     1,   484,
     102,   324,   325,   326,   240,   395,   264,   133,   109,   399,
     395,   294,   516,    98,   399,    27,    28,   502,   503,   302,
     524,   189,   160,   520,   509,   232,   190,   310,   558,   133,
     237,   102,   562,   109,   109,   190,   426,   427,     0,     1,
     188,   426,   427,     1,   809,   213,    98,   270,   533,   534,
     109,     1,   442,   108,   204,   190,   446,   442,   281,    98,
     591,   446,  1660,   426,   427,   150,    46,   190,    48,   426,
     427,     1,     1,   109,   200,   130,   109,   842,   191,   442,
     109,   259,   260,   446,   262,   442,   134,   189,   276,   446,
     191,   269,   156,   240,   484,   283,   200,   759,   150,   484,
       1,   279,   114,   493,   240,   293,   109,   240,   493,   225,
     226,   870,   871,   291,   321,   190,   875,   159,  1149,  1003,
    1004,  1005,  1417,  1721,   240,   787,    96,   622,   108,  1274,
     493,   190,  1299,   172,    78,   620,   493,    55,   623,  1104,
     151,  1308,    60,  1282,   534,   193,   905,   109,   156,   534,
    1693,   109,  1319,   543,   190,   188,  1145,   168,   543,   109,
    1334,   190,   156,   109,   554,   555,   556,   557,   156,   554,
     555,   556,   557,   549,  1003,  1004,  1005,   534,   109,   109,
     109,     9,    10,   573,   187,   156,   775,   258,   573,   684,
     779,   171,   687,   769,    43,    27,    28,     1,    47,    98,
     271,    96,   273,    52,    96,   213,    38,    39,   109,    41,
      42,   109,   156,   284,   285,   286,    48,   288,   713,   290,
     259,   260,    71,   262,  1748,   187,    58,    59,   109,   187,
       1,   716,   717,   718,    43,   720,     1,   187,    47,  1270,
     279,   187,   213,    52,    76,     1,   750,    34,     1,    81,
     145,     1,   291,   145,    96,   225,   226,   187,   187,   190,
     159,   119,    71,    50,   109,  1030,  1031,     9,    10,   407,
     240,  1554,   410,   239,   759,   241,   414,   105,     1,   417,
     418,   113,   114,   115,   228,   229,   187,   425,   139,     5,
     680,   149,   190,     9,   109,   680,   109,   435,   126,    30,
     128,   147,   153,   441,   162,   109,   680,   445,   150,   190,
       9,    34,   450,   189,   704,   705,  1415,   680,  1463,   704,
     705,  1420,   171,   680,   986,   174,  1032,  1310,   156,  1496,
      29,   163,   160,   179,     9,    10,    25,   213,   109,   197,
     189,   704,   705,   481,   109,   190,    35,   704,   705,   177,
      96,   197,     9,   109,   492,   493,   109,    97,   306,   109,
    1143,  1144,   171,   105,    96,   174,   215,   315,   108,   759,
     198,  1255,    29,    62,   759,   190,   108,   190,   118,   189,
     189,   112,   520,   187,   126,     5,   128,  1376,   216,     9,
     130,   529,  1692,  1567,   140,   227,   127,   787,   987,   145,
     151,  1160,   787,   213,    55,   781,   215,   122,   122,    60,
     126,  1000,   128,   145,   156,   264,   187,   168,   160,   102,
     136,   152,   187,     9,    10,   156,    96,   126,   159,   128,
     105,   187,   115,    96,   187,   177,   268,   187,   137,   159,
     156,   995,   157,   157,   159,   159,   584,    98,    98,   180,
     588,   126,   122,   128,   156,   264,   198,   156,    98,   122,
      96,  1635,   294,  1637,   120,   115,  1683,  1684,     1,   126,
     302,   128,   108,   159,   216,   115,   124,   981,   310,  1578,
     137,   156,   156,  1582,   622,   160,   124,   157,     1,   159,
       3,   222,   223,   224,   157,    98,   159,  1159,   122,   156,
     148,    34,   177,  1262,  1487,  1488,   126,   161,   128,   159,
     148,   159,   115,   651,   159,   275,   136,    50,  1735,   105,
     120,   159,   282,   198,  1741,   179,  1480,   665,   189,   244,
     244,   669,   670,   157,  1299,   159,   156,   189,   676,  1713,
     126,   216,   128,  1308,  1029,   935,   684,   189,   202,   687,
     935,   161,   213,   691,  1319,    68,   159,   270,  1547,   156,
      73,   213,   254,   255,   169,   140,   140,   120,   281,   179,
     156,   213,   935,  1247,   160,   713,   185,   220,   935,   185,
     185,   156,   156,   131,   132,   277,   724,   102,  1687,   204,
     199,   177,   202,   199,   156,   102,   986,  1631,   213,  1633,
     115,   986,   156,   102,   102,   131,   132,   120,   115,  1643,
     860,  1645,   198,  1003,  1004,  1005,   115,   115,  1003,  1004,
    1005,   156,   872,   761,  1383,   102,  1002,   601,   602,  1660,
     216,   284,   285,   286,  1617,  1618,   220,   290,   115,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,   228,
     229,   230,   120,   791,   206,   207,   208,   209,   210,   211,
     140,   239,   140,   241,   249,   145,   804,   145,   608,   609,
     159,   610,   611,  1535,  1536,   248,  1665,   248,     0,   193,
     156,    94,   170,   101,   822,   823,   824,   825,   256,    51,
    1244,   203,  1451,   103,   196,   104,   148,   159,    30,    48,
     187,   187,   187,   187,   155,   120,   253,   311,   156,     1,
     145,   109,   120,   145,   156,   156,   187,   124,   124,   159,
     159,  1704,   159,   156,    36,   863,    17,   217,    30,    30,
    1719,  1496,   238,  1395,   237,   193,   193,     3,   120,   877,
     240,   252,   171,   173,   120,   173,   291,   291,    72,    96,
      96,    96,   157,   152,   109,   238,   109,    30,   130,   163,
     163,   135,   253,  1153,   902,    96,   306,   145,  1153,  1159,
     120,   135,   910,   187,  1159,   187,    96,    98,  1440,  1153,
      98,  1171,    46,   921,   244,   187,  1171,   156,    96,   238,
    1153,   187,   193,   145,   240,    34,  1153,  1171,   173,   109,
    1190,   120,   135,   145,    30,  1190,    96,   234,  1171,  1798,
      96,  1800,   293,   306,  1171,   156,  1190,   120,    96,  1209,
     187,  1810,   201,   163,  1209,   120,  1216,  1190,   135,   135,
      98,  1216,   102,  1190,   150,   102,   187,   193,    36,   156,
     145,  1336,   156,   187,   124,   124,  1209,   156,    30,    30,
      98,   120,  1209,  1216,    81,   252,   109,   109,   130,  1216,
     120,  1251,   150,   274,    30,   265,  1251,   261,   292,    30,
     159,   293,   267,   147,   159,  1013,   159,   159,  1016,    30,
     234,   109,   159,   159,   159,    85,   201,   313,   159,   193,
    1552,   187,   102,   135,  1251,     7,   159,   159,   159,   193,
     159,  1563,  1564,   159,  1566,   159,   294,   145,   108,   159,
     159,   240,  1574,   159,   240,   240,   244,  1055,    98,   159,
     120,   108,   122,   159,   159,   156,   150,   240,   193,   130,
     323,   189,   150,   150,   120,   120,    79,   150,    80,   190,
      30,   289,    30,   190,   278,   190,   257,   190,    98,   190,
     293,   109,  1437,  1438,  1439,   129,   190,   257,   190,   173,
     190,   190,   129,   323,   187,   190,   264,  1105,   190,   190,
     189,   187,   145,   150,   189,   150,   187,   189,   187,   187,
     187,    96,    30,   173,   156,   190,   190,   190,   287,    98,
      96,   190,   108,   190,   190,   190,   190,   294,   200,    55,
      96,   150,    30,   120,   109,  1395,   109,    96,   200,    96,
    1395,   189,   232,   201,   190,   272,   200,   147,  1680,  1157,
     120,   190,   190,   120,    95,   190,   190,   190,   312,   189,
     186,   312,   189,   654,  1172,   120,   120,   120,   200,   232,
    1106,   232,   864,   202,  1182,   300,   911,  1150,   421,  1665,
    1440,  1719,   762,  1028,   588,  1440,   693,  1473,  1291,  1271,
    1009,  1269,   401,  1266,   481,  1172,  1177,  1729,   312,   590,
     253,   250,  1210,  1185,  1180,   598,   313,   825,   600,   250,
     313,  1252,   625,   622,   622,  1747,   628,  1741,   294,  1203,
     725,  1735,  1633,  1238,  1332,  1249,  1248,  1332,  1308,  1319,
    1238,  1496,  1493,  1031,  1040,   896,  1312,  1128,  1770,  1366,
    1248,  1596,  1538,  1309,  1252,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   313,    -1,    -1,    -1,    -1,    -1,
    1792,    -1,    -1,    -1,  1272,    -1,    -1,  1275,    -1,  1801,
      -1,    -1,  1627,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1290,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1552,    -1,    -1,    -1,    -1,  1552,    -1,    -1,
      -1,    -1,    -1,  1563,  1564,    -1,  1566,   332,  1563,  1564,
      -1,  1566,    -1,    -1,  1574,    -1,    -1,    -1,    -1,  1574,
      -1,    -1,    -1,    -1,    -1,  1333,  1334,    -1,  1336,  1337,
    1338,    -1,  1340,    -1,    -1,    -1,   406,   407,    -1,    -1,
     410,    -1,    -1,    -1,   414,    -1,    -1,   417,   418,    -1,
      -1,    -1,    -1,    -1,    -1,   425,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1372,   435,    -1,    -1,    -1,    -1,
      -1,   441,    -1,    -1,    -1,   445,    -1,    -1,    -1,    -1,
     450,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1399,    -1,    -1,  1402,    -1,    -1,  1405,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1416,    -1,
      -1,   481,    -1,  1421,    -1,    -1,    -1,    -1,    -1,    -1,
    1680,    -1,   492,    -1,    -1,  1680,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   529,
      -1,    -1,  1470,  1471,    -1,    -1,    -1,    -1,    -1,  1729,
      -1,    -1,    -1,    -1,  1729,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1747,    -1,    -1,
      -1,    -1,  1747,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1770,    -1,    -1,    -1,   584,  1770,    -1,    -1,   588,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1792,    -1,    -1,    -1,    -1,  1792,    -1,    -1,
      -1,  1801,    -1,    -1,    -1,    -1,  1801,    -1,    -1,    -1,
      -1,    -1,   622,    -1,    -1,    -1,    -1,   105,    -1,  1567,
    1568,    -1,  1570,    -1,  1572,    -1,    -1,    -1,    -1,    -1,
      -1,  1579,    -1,    -1,    -1,    -1,    -1,    -1,   648,    -1,
      -1,   651,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   665,    -1,    -1,    -1,   669,
     670,    -1,    -1,    -1,    -1,    -1,   676,    -1,    -1,    -1,
      -1,    -1,   160,    -1,   684,    -1,    -1,   687,    -1,    -1,
      -1,   691,    -1,  1631,    -1,  1633,    -1,  1635,    -1,  1637,
      -1,    -1,    -1,    -1,    -1,  1643,    -1,  1645,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1661,   724,    -1,  1664,    -1,    -1,    -1,
      -1,    -1,    -1,  1671,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1682,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   761,    -1,    -1,    -1,    -1,   244,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1713,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1723,    -1,    -1,    -1,    -1,
    1728,   791,  1730,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   804,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1752,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   822,   823,   824,   825,    -1,    -1,    -1,    -1,
    1768,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1788,    -1,    -1,    -1,    -1,  1793,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   863,    -1,    -1,    -1,  1805,    -1,    -1,
    1808,    -1,    -1,    -1,    -1,    -1,    -1,   877,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   902,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     910,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   921,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1013,    -1,   493,  1016,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   514,   515,    -1,    -1,
     518,   519,   520,    -1,    -1,   523,    -1,    -1,   526,    -1,
      -1,    -1,    -1,    -1,   532,  1055,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   541,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   564,   565,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   573,   574,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1105,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   624,    -1,    -1,    -1,
     628,    -1,    -1,    -1,    -1,    -1,    -1,  1157,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1172,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1182,    -1,    -1,    -1,    -1,    -1,    -1,   667,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1210,    -1,    -1,    -1,   692,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     708,    -1,    -1,    -1,   712,   713,    -1,   715,  1238,    -1,
      -1,    -1,    -1,    -1,   722,    -1,    -1,    -1,  1248,    -1,
      -1,    -1,  1252,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   744,   745,    -1,    -1,
     748,    -1,  1272,    -1,    -1,  1275,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   767,
    1290,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   787,
      -1,    -1,    -1,    -1,    -1,   793,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1333,  1334,    -1,  1336,  1337,  1338,    -1,
    1340,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1372,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   865,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1399,
      -1,    -1,  1402,    -1,    -1,  1405,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1416,    -1,    -1,    -1,
      -1,  1421,   900,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   922,    -1,    -1,    -1,    -1,    -1,
      -1,   929,   930,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   940,    -1,    -1,   943,    -1,    -1,    -1,    -1,
    1470,  1471,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   964,   965,   966,    -1,
     968,   969,   970,   971,   972,    -1,    -1,   975,   976,    -1,
     978,   979,    -1,    -1,    -1,   983,   984,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     998,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1009,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1019,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1567,  1568,    -1,
    1570,    -1,  1572,    -1,    -1,    -1,    -1,    -1,    -1,  1579,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1092,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1631,    -1,  1633,    -1,  1635,    -1,  1637,    -1,    -1,
      -1,    -1,    -1,  1643,    -1,  1645,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1661,    -1,    -1,  1664,    -1,    -1,    -1,    -1,    -1,
      -1,  1671,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1159,  1682,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1169,    -1,    -1,    -1,    -1,    -1,  1175,  1176,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1713,  1192,    -1,    -1,  1195,  1196,    -1,
      -1,    -1,    -1,  1723,    -1,    -1,    -1,    -1,  1728,    -1,
    1730,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1752,    -1,    -1,    -1,    -1,    -1,  1236,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1768,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1788,    -1,
      -1,  1269,    -1,  1793,    -1,    -1,    -1,    -1,    -1,  1277,
      -1,  1279,    -1,  1281,    -1,  1805,  1284,    -1,  1808,    -1,
      -1,  1289,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1386,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1394,  1395,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1413,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1426,  1427,
    1428,  1429,    -1,  1431,  1432,    -1,  1434,    -1,  1436,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1452,    -1,    -1,    -1,    -1,  1457,
      -1,    -1,    -1,  1461,    -1,    -1,    -1,  1465,    -1,  1467,
      -1,  1469,    -1,    -1,    -1,    -1,    -1,  1475,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1553,    -1,    -1,    -1,    -1,
    1558,  1559,    -1,    -1,    -1,    -1,    -1,    -1,  1566,    -1,
      -1,    -1,    -1,  1571,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1588,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1601,    -1,  1603,    -1,  1605,    -1,    -1,
    1608,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1676,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1699,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1729,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     0,     1,    -1,    -1,    -1,    -1,    -1,  1766,    -1,
      -1,    -1,  1770,    -1,    -1,    -1,    -1,  1775,    -1,    -1,
      -1,    -1,    21,    22,    23,    24,    25,    26,    27,    28,
      -1,    30,    -1,  1791,    -1,    34,    35,  1795,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    -1,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    -1,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    -1,    96,    97,    98,
      99,    -1,    -1,   102,   103,   104,    -1,    -1,   107,   108,
      -1,    -1,    -1,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,    -1,    -1,    -1,    -1,   127,    -1,
     129,   130,   131,   132,    -1,   134,    -1,    -1,    -1,   138,
     139,   140,   141,   142,    -1,    -1,    -1,    -1,    -1,    -1,
     149,   150,   151,   152,   153,   154,    -1,   156,   157,    -1,
     159,   160,   161,   162,   163,    -1,    -1,    -1,    -1,   168,
     169,   170,   171,   172,   173,   174,   175,    -1,   177,    -1,
     179,   180,    -1,    -1,   183,   184,   185,    -1,    -1,    -1,
     189,    -1,   191,   192,   193,    -1,    -1,    -1,    -1,    -1,
     199,    -1,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,    -1,    -1,   214,   215,   216,    -1,   218,
      -1,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   262,   263,   264,    -1,   266,   267,   268,
      -1,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,   317,    -1,
     319,     0,     1,   322,   323,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    21,    22,    23,    24,    25,    26,    27,    28,
      -1,    30,    -1,    -1,    -1,    34,    35,    -1,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    -1,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    -1,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    -1,    96,    97,    98,
      99,    -1,    -1,   102,   103,   104,    -1,    -1,   107,   108,
      -1,    -1,    -1,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,    -1,    -1,    -1,    -1,   127,    -1,
     129,   130,   131,   132,    -1,   134,    -1,    -1,    -1,   138,
     139,   140,   141,   142,    -1,    -1,    -1,    -1,    -1,    -1,
     149,   150,   151,   152,   153,   154,    -1,   156,   157,    -1,
     159,   160,   161,   162,   163,    -1,    -1,    -1,    -1,   168,
     169,   170,   171,   172,   173,   174,   175,    -1,   177,    -1,
     179,   180,    -1,    -1,   183,   184,   185,    -1,    -1,    -1,
     189,    -1,   191,   192,   193,    -1,    -1,    -1,    -1,    -1,
     199,    -1,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,    -1,    -1,   214,   215,   216,    -1,   218,
      -1,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   262,   263,   264,    -1,   266,   267,   268,
      -1,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,   317,     1,
     319,    -1,    -1,   322,   323,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,
      22,    23,    24,    25,    26,    27,    28,    -1,    30,    -1,
      -1,    -1,    34,    35,    -1,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    -1,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    -1,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    -1,    96,    97,    98,    99,    -1,    -1,
     102,   103,   104,    -1,    -1,   107,   108,    -1,    -1,    -1,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,    -1,    -1,    -1,    -1,   127,    -1,   129,   130,   131,
     132,    -1,   134,    -1,    -1,    -1,   138,   139,   140,   141,
     142,    -1,    -1,    -1,    -1,    -1,    -1,   149,   150,   151,
     152,   153,   154,    -1,   156,   157,    -1,   159,   160,   161,
     162,   163,    -1,    -1,    -1,    -1,   168,   169,   170,   171,
     172,   173,   174,   175,    -1,   177,    -1,   179,   180,    -1,
      -1,   183,   184,   185,    -1,    -1,    -1,   189,    -1,   191,
     192,   193,    -1,    -1,    -1,    -1,    -1,   199,    -1,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
      -1,    -1,   214,   215,   216,    -1,   218,    -1,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,   264,    -1,   266,   267,   268,    -1,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,   317,     1,   319,    -1,    -1,
     322,   323,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    21,    22,    23,    24,
      25,    26,    -1,    -1,    -1,    30,    -1,    -1,    -1,    34,
      35,    -1,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    -1,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    -1,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      -1,    96,    97,    98,    99,    -1,    -1,   102,   103,   104,
      -1,    -1,   107,   108,    -1,    -1,    -1,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,    -1,    -1,
      -1,    -1,   127,    -1,   129,   130,   131,   132,    -1,   134,
      -1,    -1,    -1,   138,   139,   140,   141,   142,    -1,    -1,
      -1,    -1,    -1,    -1,   149,   150,   151,   152,   153,   154,
      -1,   156,   157,    -1,   159,   160,   161,   162,   163,    -1,
      -1,    -1,    -1,   168,   169,   170,   171,   172,   173,   174,
     175,    -1,   177,    -1,   179,   180,    -1,    -1,   183,   184,
     185,    -1,    -1,    -1,   189,    -1,   191,   192,    -1,    -1,
      -1,    -1,    -1,    -1,   199,    -1,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,    -1,    -1,   214,
     215,   216,    -1,   218,    -1,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
      -1,   266,   267,   268,    -1,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,    -1,   319,    11,    12,   322,   323,    -1,
      -1,    -1,    -1,    -1,    20,    -1,    -1,    -1,    -1,    25,
      26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,    35,
      -1,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      -1,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    -1,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    -1,
      96,    97,    98,    99,    -1,    -1,   102,   103,   104,    -1,
      -1,   107,   108,    -1,    -1,    -1,    -1,   113,   114,   115,
     116,   117,   118,   119,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   129,   130,   131,   132,    -1,   134,    -1,
      -1,    -1,   138,   139,   140,   141,   142,    -1,    -1,    -1,
      -1,    -1,    -1,   149,   150,   151,    -1,   153,   154,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   162,   163,    -1,    -1,
      -1,    -1,   168,   169,   170,   171,   172,   173,   174,   175,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   183,   184,   185,
      -1,    -1,    -1,   189,    -1,   191,   192,    -1,    -1,    -1,
      -1,   197,    -1,   199,    -1,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,    -1,    -1,   214,   215,
      -1,    -1,   218,    -1,   220,   221,    -1,    -1,    -1,   225,
     226,   227,   228,   229,   230,    -1,   232,    -1,   234,    -1,
      -1,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,   264,    -1,
     266,   267,   268,    -1,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,    -1,    -1,    -1,    -1,    -1,    -1,   323,    21,    22,
      23,    24,    25,    26,    27,    28,    -1,    30,    -1,    -1,
      -1,    34,    35,    -1,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    -1,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    -1,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    -1,    96,    97,    98,    99,    -1,    -1,   102,
     103,   104,    -1,    -1,   107,   108,    -1,    -1,    -1,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
      -1,    -1,    -1,    -1,   127,    -1,   129,   130,   131,   132,
      -1,   134,    -1,    -1,    -1,   138,   139,   140,   141,   142,
      -1,    -1,    -1,    -1,    -1,    -1,   149,   150,   151,   152,
     153,   154,    -1,   156,   157,    -1,   159,   160,   161,   162,
     163,    -1,    -1,    -1,    -1,   168,   169,   170,   171,   172,
     173,   174,   175,    -1,   177,    -1,   179,   180,    -1,    -1,
     183,   184,   185,    -1,    -1,    -1,   189,    -1,   191,   192,
     193,    -1,    -1,    -1,    -1,    -1,   199,    -1,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,    -1,
      -1,   214,   215,   216,    -1,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,    -1,   266,   267,   268,    -1,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,   317,    -1,   319,    -1,    -1,   322,
     323,    -1,    -1,    -1,    -1,   328,   329,    21,    22,    23,
      24,    25,    26,    27,    28,    -1,    30,    -1,    -1,    -1,
      34,    35,    -1,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    -1,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    -1,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    -1,    96,    97,    98,    99,    -1,    -1,   102,   103,
     104,    -1,    -1,   107,   108,    -1,    -1,    -1,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,    -1,
      -1,    -1,    -1,   127,    -1,   129,   130,   131,   132,    -1,
     134,    -1,    -1,    -1,   138,   139,   140,   141,   142,    -1,
      -1,    -1,    -1,    -1,    -1,   149,   150,   151,   152,   153,
     154,    -1,   156,   157,    -1,   159,   160,   161,   162,   163,
      -1,    -1,    -1,    -1,   168,   169,   170,   171,   172,   173,
     174,   175,    -1,   177,    -1,   179,   180,    -1,    -1,   183,
     184,   185,    -1,    -1,    -1,   189,    -1,   191,   192,   193,
      -1,    -1,    -1,    -1,    -1,   199,    -1,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,    -1,    -1,
     214,   215,   216,    -1,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   263,
     264,    -1,   266,   267,   268,    -1,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,   317,    -1,   319,    -1,    -1,   322,   323,
      -1,    16,    -1,    -1,    -1,   329,    21,    22,    23,    24,
      25,    26,    27,    28,    -1,    30,    -1,    -1,    -1,    34,
      35,    -1,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    -1,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    -1,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      -1,    96,    97,    98,    99,    -1,    -1,   102,   103,   104,
      -1,    -1,   107,   108,    -1,    -1,    -1,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,    -1,    -1,
      -1,    -1,   127,    -1,   129,   130,   131,   132,    -1,   134,
      -1,    -1,    -1,   138,   139,   140,   141,   142,    -1,    -1,
      -1,    -1,    -1,    -1,   149,   150,   151,   152,   153,   154,
      -1,   156,   157,    -1,   159,   160,   161,   162,   163,    -1,
      -1,    -1,    -1,   168,   169,   170,   171,   172,   173,   174,
     175,    -1,   177,    -1,   179,   180,    -1,    -1,   183,   184,
     185,    -1,    -1,    -1,   189,    -1,   191,   192,   193,    -1,
      -1,    -1,    -1,    -1,   199,    -1,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,    -1,    -1,   214,
     215,   216,    -1,   218,    -1,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
      -1,   266,   267,   268,    -1,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,    -1,   319,    16,    -1,   322,   323,    -1,
      21,    22,    23,    24,    25,    26,    -1,    -1,    -1,    30,
      -1,    -1,    -1,    34,    35,    -1,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    -1,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    -1,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    -1,    96,    97,    98,    99,    -1,
      -1,   102,   103,   104,    -1,    -1,   107,   108,    -1,    -1,
      -1,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,    -1,    -1,    -1,    -1,   127,    -1,   129,   130,
     131,   132,    -1,   134,    -1,    -1,    -1,   138,   139,   140,
     141,   142,    -1,    -1,    -1,    -1,    -1,    -1,   149,   150,
     151,   152,   153,   154,    -1,   156,   157,    -1,   159,   160,
     161,   162,   163,    -1,    -1,    -1,    -1,   168,   169,   170,
     171,   172,   173,   174,   175,    -1,   177,    -1,   179,   180,
      -1,    -1,   183,   184,   185,    -1,    -1,    -1,   189,    -1,
     191,   192,    -1,    -1,    -1,    -1,    -1,    -1,   199,    -1,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,    -1,    -1,   214,   215,   216,    -1,   218,    -1,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     261,   262,   263,   264,    -1,   266,   267,   268,    -1,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   316,   317,    -1,   319,    16,
     321,   322,   323,    -1,    21,    22,    23,    24,    25,    26,
      -1,    -1,    -1,    30,    -1,    -1,    -1,    34,    35,    -1,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    -1,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    -1,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    -1,    96,
      97,    98,    99,    -1,    -1,   102,   103,   104,    -1,    -1,
     107,   108,    -1,    -1,    -1,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,    -1,    -1,    -1,    -1,
     127,    -1,   129,   130,   131,   132,    -1,   134,    -1,    -1,
      -1,   138,   139,   140,   141,   142,    -1,    -1,    -1,    -1,
      -1,    -1,   149,   150,   151,   152,   153,   154,    -1,   156,
     157,    -1,   159,   160,   161,   162,   163,    -1,    -1,    -1,
      -1,   168,   169,   170,   171,   172,   173,   174,   175,    -1,
     177,    -1,   179,   180,    -1,    -1,   183,   184,   185,    -1,
      -1,    -1,   189,    -1,   191,   192,    -1,    -1,    -1,    -1,
      -1,    -1,   199,    -1,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,    -1,    -1,   214,   215,   216,
      -1,   218,    -1,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   263,   264,    -1,   266,
     267,   268,    -1,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,   316,
     317,    16,   319,    -1,    -1,   322,   323,    -1,    -1,    -1,
      25,    26,    -1,    -1,    -1,    30,    -1,    -1,    -1,    34,
      35,    -1,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    -1,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    -1,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      -1,    96,    97,    98,    99,    -1,    -1,   102,   103,   104,
      -1,    -1,   107,   108,    -1,    -1,    -1,    -1,   113,   114,
     115,   116,   117,   118,   119,   120,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   129,   130,   131,   132,    -1,   134,
      -1,    -1,    -1,   138,   139,   140,   141,   142,    -1,    -1,
      -1,    -1,    -1,    -1,   149,   150,   151,    -1,   153,   154,
      -1,    -1,    -1,    -1,   159,    -1,    -1,   162,   163,    -1,
      -1,    -1,    -1,   168,   169,   170,   171,   172,   173,   174,
     175,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   183,   184,
     185,    -1,    -1,    -1,   189,    -1,   191,   192,    -1,    -1,
      -1,    -1,    -1,    -1,   199,    -1,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,    -1,    -1,   214,
     215,    -1,    -1,   218,    -1,   220,   221,    -1,    -1,    -1,
     225,   226,   227,   228,   229,   230,    -1,   232,    -1,   234,
      -1,    -1,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
      -1,   266,   267,   268,    -1,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,    16,    -1,    -1,    -1,    -1,    -1,   323,    -1,
      -1,    25,    26,    -1,    -1,    -1,    30,    -1,    -1,    -1,
      34,    35,    -1,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    -1,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    -1,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    -1,    96,    97,    98,    99,    -1,    -1,   102,   103,
     104,    -1,    -1,   107,   108,    -1,    -1,    -1,    -1,   113,
     114,   115,   116,   117,   118,   119,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   129,   130,   131,   132,    -1,
     134,    -1,    -1,    -1,   138,   139,   140,   141,   142,    -1,
      -1,    -1,    -1,    -1,    -1,   149,   150,   151,    -1,   153,
     154,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   162,   163,
      -1,    -1,    -1,    -1,   168,   169,   170,   171,   172,   173,
     174,   175,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   183,
     184,   185,    -1,    -1,    -1,   189,   190,   191,   192,    -1,
      -1,    -1,    -1,    -1,    -1,   199,    -1,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,    -1,    -1,
     214,   215,    -1,    -1,   218,    -1,   220,   221,    -1,    -1,
      -1,   225,   226,   227,   228,   229,   230,    -1,   232,    -1,
     234,    -1,    -1,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   263,
     264,    -1,   266,   267,   268,    -1,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,    16,    -1,    -1,    -1,    -1,    -1,   323,
      -1,    -1,    25,    26,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    34,    35,    -1,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    -1,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    -1,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    -1,    96,    97,    98,    99,    -1,    -1,   102,
     103,   104,    -1,    -1,   107,   108,    -1,    -1,    -1,    -1,
     113,   114,   115,   116,   117,   118,   119,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   129,   130,   131,   132,
      -1,   134,    -1,    -1,    -1,   138,   139,   140,   141,   142,
      -1,    -1,    -1,    -1,    -1,    -1,   149,   150,   151,    -1,
     153,   154,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   162,
     163,    -1,    -1,    -1,    -1,   168,   169,   170,   171,   172,
     173,   174,   175,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     183,   184,   185,    -1,    -1,    -1,   189,    -1,   191,   192,
      -1,    -1,    -1,    -1,    -1,    -1,   199,    -1,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,    -1,
      -1,   214,   215,    -1,    -1,   218,    -1,   220,   221,    -1,
      -1,    -1,   225,   226,   227,   228,   229,   230,    -1,   232,
      -1,   234,    -1,    -1,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,    -1,   266,   267,   268,    -1,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,    18,    19,    -1,    -1,    -1,    -1,
     323,    25,    26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      34,    35,    -1,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    -1,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    -1,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    -1,    96,    97,    98,    99,    -1,    -1,   102,   103,
     104,    -1,    -1,   107,   108,    -1,    -1,    -1,    -1,   113,
     114,   115,   116,   117,   118,   119,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   129,   130,   131,   132,    -1,
     134,    -1,    -1,    -1,   138,   139,   140,   141,   142,    -1,
      -1,    -1,    -1,    -1,    -1,   149,   150,   151,    -1,   153,
     154,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   162,   163,
      -1,    -1,    -1,    -1,   168,   169,   170,   171,   172,   173,
     174,   175,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   183,
     184,   185,    -1,    -1,    -1,   189,    -1,   191,   192,    -1,
      -1,    -1,    -1,    -1,    -1,   199,    -1,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,    -1,    -1,
     214,   215,    -1,    -1,   218,    -1,   220,   221,    -1,    -1,
      -1,   225,   226,   227,   228,   229,   230,    -1,   232,    -1,
     234,    -1,    -1,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   263,
     264,    -1,   266,   267,   268,    -1,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,    -1,    -1,    -1,    -1,    -1,    -1,   323,
      21,    22,    23,    24,    25,    26,    27,    28,    -1,    30,
      -1,    -1,    -1,    34,    35,    -1,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    -1,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    -1,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    -1,    96,    97,    98,    99,    -1,
      -1,   102,   103,   104,    -1,    -1,   107,   108,    -1,    -1,
      -1,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,    -1,    -1,    -1,    -1,   127,    -1,   129,   130,
     131,   132,    -1,   134,    -1,    -1,    -1,   138,   139,   140,
     141,   142,    -1,    -1,    -1,    -1,    -1,    -1,   149,   150,
     151,   152,   153,   154,    -1,   156,   157,    -1,   159,   160,
     161,   162,   163,    -1,    -1,    -1,    -1,   168,   169,   170,
     171,   172,   173,   174,   175,    -1,   177,    -1,   179,   180,
      -1,    -1,   183,   184,   185,    -1,    -1,    -1,   189,    -1,
     191,   192,   193,    -1,    -1,    -1,    -1,    -1,   199,    -1,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,    -1,    -1,   214,   215,   216,    -1,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     261,   262,   263,   264,    -1,   266,   267,   268,    -1,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   316,   317,    -1,   319,    -1,
      -1,   322,   323,    21,    22,    23,    24,    25,    26,    27,
      28,    -1,    30,    -1,    -1,    -1,    34,    35,    -1,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    -1,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    -1,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    -1,    96,    97,
      98,    99,    -1,    -1,   102,   103,   104,    -1,    -1,   107,
     108,    -1,    -1,    -1,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,    -1,    -1,    -1,    -1,   127,
      -1,   129,   130,   131,   132,    -1,   134,    -1,    -1,    -1,
     138,   139,   140,   141,   142,    -1,    -1,    -1,    -1,    -1,
      -1,   149,   150,   151,   152,   153,   154,    -1,   156,   157,
      -1,   159,   160,   161,   162,   163,    -1,    -1,    -1,    -1,
     168,   169,   170,   171,   172,   173,   174,   175,    -1,   177,
      -1,   179,   180,    -1,    -1,   183,   184,   185,    -1,   187,
      -1,   189,    -1,   191,   192,   193,    -1,    -1,    -1,    -1,
      -1,   199,    -1,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,    -1,    -1,   214,   215,   216,    -1,
     218,    -1,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,   264,    -1,   266,   267,
     268,    -1,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,   317,
      -1,   319,    -1,    -1,   322,   323,    21,    22,    23,    24,
      25,    26,    27,    28,    -1,    30,    -1,    -1,    -1,    34,
      35,    -1,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    -1,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    -1,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      -1,    96,    97,    98,    99,    -1,    -1,   102,   103,   104,
      -1,    -1,   107,   108,    -1,    -1,    -1,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,    -1,    -1,
      -1,    -1,   127,    -1,   129,   130,   131,   132,    -1,   134,
      -1,    -1,    -1,   138,   139,   140,   141,   142,    -1,    -1,
      -1,    -1,    -1,    -1,   149,   150,   151,   152,   153,   154,
      -1,   156,   157,    -1,   159,   160,   161,   162,   163,    -1,
      -1,    -1,    -1,   168,   169,   170,   171,   172,   173,   174,
     175,    -1,   177,    -1,   179,   180,    -1,    -1,   183,   184,
     185,    -1,    -1,    -1,   189,    -1,   191,   192,   193,    -1,
      -1,    -1,    -1,    -1,   199,    -1,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,    -1,    -1,   214,
     215,   216,    -1,   218,    -1,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
      -1,   266,   267,   268,    -1,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,    -1,   319,    -1,    -1,   322,   323,    21,
      22,    23,    24,    25,    26,    27,    28,    -1,    30,    -1,
      -1,    -1,    34,    35,    -1,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    -1,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    -1,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    -1,    96,    97,    98,    99,    -1,    -1,
     102,   103,   104,    -1,    -1,   107,   108,    -1,    -1,    -1,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,    -1,    -1,    -1,    -1,   127,    -1,   129,   130,   131,
     132,    -1,   134,    -1,    -1,    -1,   138,   139,   140,   141,
     142,    -1,    -1,    -1,    -1,    -1,    -1,   149,   150,   151,
     152,   153,   154,    -1,   156,   157,    -1,   159,   160,   161,
     162,   163,    -1,    -1,    -1,    -1,   168,   169,   170,   171,
     172,   173,   174,   175,    -1,   177,    -1,   179,   180,    -1,
      -1,   183,   184,   185,    -1,    -1,    -1,   189,    -1,   191,
     192,   193,    -1,    -1,    -1,    -1,    -1,   199,    -1,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
      -1,    -1,   214,   215,   216,    -1,   218,    -1,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,   264,    -1,   266,   267,   268,    -1,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,   317,    -1,   319,    -1,    -1,
     322,   323,    21,    22,    23,    24,    25,    26,    27,    28,
      -1,    30,    -1,    -1,    -1,    34,    35,    -1,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    -1,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    -1,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    -1,    96,    97,    98,
      99,    -1,    -1,   102,   103,   104,    -1,    -1,   107,   108,
      -1,    -1,    -1,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,    -1,    -1,    -1,    -1,   127,    -1,
     129,   130,   131,   132,    -1,   134,    -1,    -1,    -1,   138,
     139,   140,   141,   142,    -1,    -1,    -1,    -1,    -1,    -1,
     149,   150,   151,   152,   153,   154,    -1,   156,   157,    -1,
     159,   160,   161,   162,   163,    -1,    -1,    -1,    -1,   168,
     169,   170,   171,   172,   173,   174,   175,    -1,   177,    -1,
     179,   180,    -1,    -1,   183,   184,   185,    -1,    -1,    -1,
     189,    -1,   191,   192,   193,    -1,    -1,    -1,    -1,    -1,
     199,    -1,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,    -1,    -1,   214,   215,   216,    -1,   218,
      -1,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   262,   263,   264,    -1,   266,   267,   268,
      -1,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,   317,    -1,
     319,    -1,    -1,   322,   323,    21,    22,    23,    24,    25,
      26,    27,    28,    -1,    30,    -1,    -1,    -1,    34,    35,
      -1,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      -1,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    -1,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    -1,
      96,    97,    98,    99,    -1,    -1,   102,   103,   104,    -1,
      -1,   107,   108,    -1,    -1,    -1,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,    -1,    -1,    -1,
      -1,   127,    -1,   129,   130,   131,   132,    -1,   134,    -1,
      -1,    -1,   138,   139,   140,   141,   142,    -1,    -1,    -1,
      -1,    -1,    -1,   149,   150,   151,   152,   153,   154,    -1,
     156,   157,    -1,   159,   160,   161,   162,   163,    -1,    -1,
      -1,    -1,   168,   169,   170,   171,   172,   173,   174,   175,
      -1,   177,    -1,   179,   180,    -1,    -1,   183,   184,   185,
      -1,    -1,    -1,   189,    -1,   191,   192,   193,    -1,    -1,
      -1,    -1,    -1,   199,    -1,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,    -1,    -1,   214,   215,
     216,    -1,   218,    -1,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,   264,    -1,
     266,   267,   268,    -1,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,   317,    -1,   319,    -1,    -1,   322,   323,    21,    22,
      23,    24,    25,    26,    27,    28,    -1,    30,    -1,    -1,
      -1,    34,    35,    -1,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    -1,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    -1,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    -1,    96,    97,    98,    99,    -1,    -1,   102,
     103,   104,    -1,    -1,   107,   108,    -1,    -1,    -1,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
      -1,    -1,    -1,    -1,   127,    -1,   129,   130,   131,   132,
      -1,   134,    -1,    -1,    -1,   138,   139,   140,   141,   142,
      -1,    -1,    -1,    -1,    -1,    -1,   149,   150,   151,   152,
     153,   154,    -1,   156,   157,    -1,   159,   160,   161,   162,
     163,    -1,    -1,    -1,    -1,   168,   169,   170,   171,   172,
     173,   174,   175,    -1,   177,    -1,   179,   180,    -1,    -1,
     183,   184,   185,    -1,    -1,    -1,   189,    -1,   191,   192,
     193,    -1,    -1,    -1,    -1,    -1,   199,    -1,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,    -1,
      -1,   214,   215,   216,    -1,   218,    -1,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,    -1,   266,   267,   268,    -1,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,   317,    -1,   319,    -1,    -1,   322,
     323,    21,    22,    23,    24,    25,    26,    -1,    -1,    -1,
      30,    -1,    -1,    -1,    34,    35,    -1,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    -1,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      -1,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    -1,    96,    97,    98,    99,
      -1,    -1,   102,   103,   104,    -1,    -1,   107,   108,    -1,
      -1,    -1,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,    -1,    -1,    -1,    -1,   127,    -1,   129,
     130,   131,   132,    -1,   134,    -1,    -1,    -1,   138,   139,
     140,   141,   142,    -1,    -1,    -1,    -1,   147,    -1,   149,
     150,   151,   152,   153,   154,    -1,   156,   157,    -1,   159,
     160,   161,   162,   163,    -1,    -1,    -1,    -1,   168,   169,
     170,   171,   172,   173,   174,   175,    -1,   177,    -1,   179,
     180,    -1,    -1,   183,   184,   185,    -1,    -1,    -1,   189,
     190,   191,   192,    -1,    -1,    -1,    -1,    -1,    -1,   199,
      -1,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,    -1,    -1,   214,   215,   216,    -1,   218,    -1,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,   264,    -1,   266,   267,   268,    -1,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,   317,    -1,   319,
      -1,    -1,   322,   323,    21,    22,    23,    24,    25,    26,
      -1,    -1,    -1,    30,    -1,    -1,    -1,    34,    35,    -1,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    -1,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    -1,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    -1,    96,
      97,    98,    99,    -1,    -1,   102,   103,   104,    -1,    -1,
     107,   108,    -1,    -1,    -1,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,    -1,    -1,    -1,    -1,
     127,    -1,   129,   130,   131,   132,    -1,   134,    -1,    -1,
      -1,   138,   139,   140,   141,   142,    -1,    -1,    -1,    -1,
     147,    -1,   149,   150,   151,   152,   153,   154,    -1,   156,
     157,    -1,   159,   160,   161,   162,   163,    -1,    -1,    -1,
      -1,   168,   169,   170,   171,   172,   173,   174,   175,    -1,
     177,    -1,   179,   180,    -1,    -1,   183,   184,   185,    -1,
      -1,    -1,   189,   190,   191,   192,    -1,    -1,    -1,    -1,
      -1,    -1,   199,    -1,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,    -1,    -1,   214,   215,   216,
      -1,   218,    -1,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   263,   264,    -1,   266,
     267,   268,    -1,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,   316,
     317,    -1,   319,    -1,    -1,   322,   323,    21,    22,    23,
      24,    25,    26,    -1,    -1,    -1,    30,    -1,    -1,    -1,
      34,    35,    -1,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    -1,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    -1,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    -1,    96,    97,    98,    99,    -1,    -1,   102,   103,
     104,    -1,    -1,   107,   108,    -1,    -1,    -1,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,    -1,
      -1,    -1,    -1,   127,    -1,   129,   130,   131,   132,    -1,
     134,    -1,    -1,    -1,   138,   139,   140,   141,   142,    -1,
      -1,    -1,    -1,    -1,    -1,   149,   150,   151,   152,   153,
     154,    -1,   156,   157,    -1,   159,   160,   161,   162,   163,
      -1,    -1,    -1,    -1,   168,   169,   170,   171,   172,   173,
     174,   175,    -1,   177,    -1,   179,   180,    -1,    -1,   183,
     184,   185,    -1,    -1,   188,   189,    -1,   191,   192,    -1,
      -1,    -1,    -1,    -1,    -1,   199,    -1,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,    -1,    -1,
     214,   215,   216,    -1,   218,    -1,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   263,
     264,    -1,   266,   267,   268,    -1,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,   317,    -1,   319,    -1,    -1,   322,   323,
      21,    22,    23,    24,    25,    26,    -1,    -1,    -1,    30,
      -1,    -1,    -1,    34,    35,    -1,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    -1,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    -1,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    -1,    96,    97,    98,    99,    -1,
      -1,   102,   103,   104,    -1,    -1,   107,   108,    -1,    -1,
      -1,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,    -1,    -1,    -1,    -1,   127,    -1,   129,   130,
     131,   132,    -1,   134,    -1,    -1,    -1,   138,   139,   140,
     141,   142,    -1,    -1,    -1,    -1,    -1,    -1,   149,   150,
     151,   152,   153,   154,    -1,   156,   157,    -1,   159,   160,
     161,   162,   163,    -1,    -1,    -1,    -1,   168,   169,   170,
     171,   172,   173,   174,   175,    -1,   177,    -1,   179,   180,
      -1,    -1,   183,   184,   185,    -1,    -1,    -1,   189,   190,
     191,   192,    -1,    -1,    -1,    -1,    -1,    -1,   199,    -1,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,    -1,    -1,   214,   215,   216,    -1,   218,    -1,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     261,   262,   263,   264,    -1,   266,   267,   268,    -1,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   316,   317,    -1,   319,    -1,
      -1,   322,   323,    21,    22,    23,    24,    25,    26,    -1,
      -1,    -1,    30,    -1,    -1,    -1,    34,    35,    -1,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    -1,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    -1,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    -1,    96,    97,
      98,    99,    -1,    -1,   102,   103,   104,    -1,    -1,   107,
     108,    -1,    -1,    -1,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,    -1,    -1,    -1,    -1,   127,
      -1,   129,   130,   131,   132,    -1,   134,    -1,    -1,    -1,
     138,   139,   140,   141,   142,    -1,    -1,    -1,    -1,    -1,
      -1,   149,   150,   151,   152,   153,   154,    -1,   156,   157,
      -1,   159,   160,   161,   162,   163,    -1,    -1,    -1,    -1,
     168,   169,   170,   171,   172,   173,   174,   175,    -1,   177,
      -1,   179,   180,    -1,    -1,   183,   184,   185,    -1,    -1,
      -1,   189,    -1,   191,   192,    -1,    -1,    -1,    -1,    -1,
      -1,   199,    -1,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,    -1,    -1,   214,   215,   216,    -1,
     218,    -1,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,   264,    -1,   266,   267,
     268,    -1,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,   317,
     318,   319,    -1,    -1,   322,   323,    21,    22,    23,    24,
      25,    26,    -1,    -1,    -1,    30,    -1,    -1,    -1,    34,
      35,    -1,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    -1,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    -1,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      -1,    96,    97,    98,    99,    -1,    -1,   102,   103,   104,
      -1,    -1,   107,   108,    -1,    -1,    -1,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,    -1,    -1,
      -1,    -1,   127,    -1,   129,   130,   131,   132,    -1,   134,
      -1,    -1,    -1,   138,   139,   140,   141,   142,    -1,    -1,
      -1,    -1,    -1,    -1,   149,   150,   151,   152,   153,   154,
      -1,   156,   157,    -1,   159,   160,   161,   162,   163,    -1,
      -1,    -1,    -1,   168,   169,   170,   171,   172,   173,   174,
     175,    -1,   177,    -1,   179,   180,    -1,    -1,   183,   184,
     185,    -1,    -1,    -1,   189,    -1,   191,   192,    -1,    -1,
      -1,    -1,    -1,    -1,   199,    -1,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,    -1,    -1,   214,
     215,   216,    -1,   218,    -1,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
      -1,   266,   267,   268,    -1,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,    -1,   319,   320,    -1,   322,   323,    21,
      22,    23,    24,    25,    26,    -1,    -1,    -1,    30,    -1,
      -1,    -1,    34,    35,    -1,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    -1,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    -1,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    -1,    96,    97,    98,    99,    -1,    -1,
     102,   103,   104,    -1,    -1,   107,   108,    -1,    -1,    -1,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,    -1,    -1,    -1,    -1,   127,    -1,   129,   130,   131,
     132,    -1,   134,    -1,    -1,    -1,   138,   139,   140,   141,
     142,    -1,    -1,    -1,    -1,    -1,    -1,   149,   150,   151,
     152,   153,   154,    -1,   156,   157,    -1,   159,   160,   161,
     162,   163,    -1,    -1,    -1,    -1,   168,   169,   170,   171,
     172,   173,   174,   175,    -1,   177,    -1,   179,   180,    -1,
      -1,   183,   184,   185,    -1,    -1,    -1,   189,    -1,   191,
     192,    -1,    -1,    -1,    -1,    -1,    -1,   199,    -1,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
      -1,    -1,   214,   215,   216,    -1,   218,    -1,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,   264,    -1,   266,   267,   268,    -1,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,   317,    -1,   319,    -1,   321,
     322,   323,    21,    22,    23,    24,    25,    26,    -1,    -1,
      -1,    30,    -1,    -1,    -1,    34,    35,    -1,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    -1,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    -1,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    -1,    96,    97,    98,
      99,    -1,    -1,   102,   103,   104,    -1,    -1,   107,   108,
      -1,    -1,    -1,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,    -1,    -1,    -1,    -1,   127,    -1,
     129,   130,   131,   132,    -1,   134,    -1,    -1,    -1,   138,
     139,   140,   141,   142,    -1,    -1,    -1,    -1,    -1,    -1,
     149,   150,   151,   152,   153,   154,    -1,   156,   157,    -1,
     159,   160,   161,   162,   163,    -1,    -1,    -1,    -1,   168,
     169,   170,   171,   172,   173,   174,   175,    -1,   177,    -1,
     179,   180,    -1,    -1,   183,   184,   185,    -1,   187,    -1,
     189,    -1,   191,   192,    -1,    -1,    -1,    -1,    -1,    -1,
     199,    -1,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,    -1,    -1,   214,   215,   216,    -1,   218,
      -1,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   262,   263,   264,    -1,   266,   267,   268,
      -1,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,   317,    -1,
     319,    -1,    -1,   322,   323,    21,    22,    23,    24,    25,
      26,    -1,    -1,    -1,    30,    -1,    -1,    -1,    34,    35,
      -1,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      -1,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    -1,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    -1,
      96,    97,    98,    99,    -1,    -1,   102,   103,   104,    -1,
      -1,   107,   108,    -1,    -1,    -1,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,    -1,    -1,    -1,
      -1,   127,    -1,   129,   130,   131,   132,    -1,   134,    -1,
      -1,    -1,   138,   139,   140,   141,   142,    -1,    -1,    -1,
      -1,   147,    -1,   149,   150,   151,   152,   153,   154,    -1,
     156,   157,    -1,   159,   160,   161,   162,   163,    -1,    -1,
      -1,    -1,   168,   169,   170,   171,   172,   173,   174,   175,
      -1,   177,    -1,   179,   180,    -1,    -1,   183,   184,   185,
      -1,    -1,    -1,   189,    -1,   191,   192,    -1,    -1,    -1,
      -1,    -1,    -1,   199,    -1,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,    -1,    -1,   214,   215,
     216,    -1,   218,    -1,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,   264,    -1,
     266,   267,   268,    -1,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,   317,    -1,   319,    -1,    -1,   322,   323,    21,    22,
      23,    24,    25,    26,    -1,    -1,    -1,    30,    -1,    -1,
      -1,    34,    35,    -1,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    -1,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    -1,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    -1,    96,    97,    98,    99,    -1,    -1,   102,
     103,   104,    -1,    -1,   107,   108,    -1,    -1,    -1,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
      -1,    -1,    -1,    -1,   127,    -1,   129,   130,   131,   132,
      -1,   134,    -1,    -1,    -1,   138,   139,   140,   141,   142,
      -1,    -1,    -1,    -1,    -1,    -1,   149,   150,   151,   152,
     153,   154,    -1,   156,   157,    -1,   159,   160,   161,   162,
     163,    -1,    -1,    -1,    -1,   168,   169,   170,   171,   172,
     173,   174,   175,    -1,   177,    -1,   179,   180,    -1,    -1,
     183,   184,   185,    -1,    -1,    -1,   189,    -1,   191,   192,
      -1,    -1,    -1,    -1,    -1,    -1,   199,    -1,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,    -1,
      -1,   214,   215,   216,    -1,   218,    -1,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,    -1,   266,   267,   268,    -1,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,   317,    -1,   319,    -1,    -1,   322,
     323,    21,    22,    23,    24,    25,    26,    -1,    -1,    -1,
      30,    -1,    -1,    -1,    34,    35,    -1,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    -1,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      -1,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    -1,    96,    97,    98,    99,
      -1,    -1,   102,   103,   104,    -1,    -1,   107,   108,    -1,
      -1,    -1,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,    -1,    -1,    -1,    -1,   127,    -1,   129,
     130,   131,   132,    -1,   134,    -1,    -1,    -1,   138,   139,
     140,   141,   142,    -1,    -1,    -1,    -1,    -1,    -1,   149,
     150,   151,   152,   153,   154,    -1,   156,   157,    -1,    -1,
     160,   161,   162,   163,    -1,    -1,    -1,    -1,   168,   169,
     170,   171,   172,   173,   174,   175,    -1,   177,    -1,   179,
     180,    -1,    -1,   183,   184,   185,    -1,    -1,    -1,   189,
      -1,   191,   192,    -1,    -1,    -1,    -1,    -1,    -1,   199,
      -1,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,    -1,    -1,   214,   215,   216,    -1,   218,    -1,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,   264,    -1,   266,   267,   268,    -1,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,   317,    -1,   319,
      -1,    -1,   322,   323,    21,    22,    23,    24,    25,    26,
      -1,    -1,    -1,    30,    -1,    -1,    -1,    34,    35,    -1,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    -1,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    -1,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    -1,    96,
      97,    98,    99,    -1,    -1,   102,   103,   104,    -1,    -1,
     107,   108,    -1,    -1,    -1,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,    -1,    -1,    -1,    -1,
     127,    -1,   129,   130,   131,   132,    -1,   134,    -1,    -1,
      -1,   138,   139,   140,   141,   142,    -1,    -1,    -1,    -1,
      -1,    -1,   149,   150,   151,   152,   153,   154,    -1,   156,
     157,    -1,   159,   160,   161,   162,   163,    -1,    -1,    -1,
      -1,   168,   169,   170,   171,   172,   173,   174,   175,    -1,
     177,    -1,   179,   180,    -1,    -1,   183,   184,   185,    -1,
      -1,    -1,   189,    -1,   191,   192,    -1,    -1,    -1,    -1,
      -1,    -1,   199,    -1,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,    -1,    -1,   214,   215,   216,
      -1,   218,    -1,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,    -1,   232,    -1,   234,    -1,    -1,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   263,   264,    -1,   266,
     267,   268,    -1,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,   316,
     317,    -1,   319,    -1,    -1,    -1,   323,    21,    22,    23,
      24,    25,    26,    -1,    -1,    -1,    30,    -1,    -1,    -1,
      34,    35,    -1,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    -1,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    -1,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    -1,    96,    97,    98,    99,    -1,    -1,   102,   103,
     104,    -1,    -1,   107,   108,    -1,    -1,    -1,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,    -1,
      -1,    -1,    -1,   127,    -1,   129,   130,   131,   132,    -1,
     134,    -1,    -1,    -1,   138,   139,   140,   141,   142,    -1,
      -1,    -1,    -1,    -1,    -1,   149,   150,   151,   152,   153,
     154,    -1,   156,   157,    -1,   159,   160,   161,   162,   163,
      -1,    -1,    -1,    -1,   168,   169,   170,   171,   172,   173,
     174,   175,    -1,   177,    -1,   179,   180,    -1,    -1,   183,
     184,   185,    -1,    -1,    -1,   189,    -1,   191,   192,    -1,
      -1,    -1,    -1,    -1,    -1,   199,    -1,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,    -1,    -1,
     214,   215,   216,    -1,   218,    -1,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,    -1,   232,    -1,
     234,    -1,    -1,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   263,
     264,    -1,   266,   267,   268,    -1,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,   317,    -1,   319,    -1,    -1,    -1,   323,
      21,    22,    23,    24,    25,    26,    -1,    -1,    -1,    30,
      -1,    -1,    -1,    34,    35,    -1,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    -1,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    -1,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    -1,    96,    97,    98,    99,    -1,
      -1,   102,   103,   104,    -1,    -1,   107,   108,    -1,    -1,
      -1,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,    -1,    -1,    -1,    -1,   127,    -1,   129,   130,
     131,   132,    -1,   134,    -1,    -1,    -1,   138,   139,   140,
     141,   142,    -1,    -1,    -1,    -1,    -1,    -1,   149,   150,
     151,   152,   153,   154,    -1,   156,   157,    -1,   159,   160,
     161,   162,   163,    -1,    -1,    -1,    -1,   168,   169,   170,
     171,   172,   173,   174,   175,    -1,   177,    -1,   179,   180,
      -1,    -1,   183,   184,   185,    -1,    -1,    -1,   189,    -1,
     191,   192,    -1,    -1,    -1,    -1,    -1,    -1,   199,    -1,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,    -1,    -1,   214,   215,   216,    -1,   218,    -1,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
      -1,   232,    -1,   234,    -1,    -1,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     261,   262,   263,   264,    -1,   266,   267,   268,    -1,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   316,   317,    -1,   319,    -1,
      -1,    -1,   323,    21,    22,    23,    24,    25,    26,    -1,
      -1,    -1,    30,    -1,    -1,    -1,    34,    35,    -1,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    -1,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    -1,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    -1,    96,    97,
      98,    99,    -1,    -1,   102,   103,   104,    -1,    -1,   107,
     108,    -1,    -1,    -1,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,    -1,    -1,    -1,    -1,   127,
      -1,   129,   130,   131,   132,    -1,   134,    -1,    -1,    -1,
     138,   139,   140,   141,   142,    -1,    -1,    -1,    -1,    -1,
      -1,   149,   150,   151,   152,   153,   154,    -1,   156,   157,
      -1,    -1,   160,   161,   162,   163,    -1,    -1,    -1,    -1,
     168,   169,   170,   171,   172,   173,   174,   175,    -1,   177,
      -1,   179,   180,    -1,    -1,   183,   184,   185,    -1,    -1,
      -1,   189,    -1,   191,   192,    -1,    -1,    -1,    -1,    -1,
      -1,   199,    -1,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,    -1,    -1,   214,   215,   216,    -1,
     218,    -1,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,    -1,   232,    -1,   234,    -1,    -1,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,   264,    -1,   266,   267,
     268,    -1,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,   317,
      -1,   319,    -1,    -1,    -1,   323,    21,    22,    23,    24,
      25,    26,    -1,    -1,    -1,    30,    -1,    -1,    -1,    34,
      35,    -1,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    -1,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    -1,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      -1,    96,    97,    98,    99,    -1,    -1,   102,   103,   104,
      -1,    -1,   107,   108,    -1,    -1,    -1,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,    -1,    -1,
      -1,    -1,   127,    -1,   129,   130,   131,   132,    -1,   134,
      -1,    -1,    -1,   138,   139,   140,   141,   142,    -1,    -1,
      -1,    -1,    -1,    -1,   149,   150,   151,   152,   153,   154,
      -1,   156,   157,    -1,   159,   160,    -1,   162,   163,    -1,
      -1,    -1,    -1,   168,   169,   170,   171,   172,   173,   174,
     175,    -1,   177,    -1,    -1,    -1,    -1,    -1,   183,   184,
     185,    -1,    -1,    -1,   189,    -1,   191,   192,    -1,    -1,
      -1,    -1,    -1,    -1,   199,    -1,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,    -1,    -1,   214,
     215,   216,    -1,   218,    -1,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,    -1,   232,    -1,   234,
      -1,    -1,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
      -1,   266,   267,   268,    -1,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,    -1,   319,    -1,   321,    -1,   323,    21,
      22,    23,    24,    25,    26,    -1,    -1,    -1,    30,    -1,
      -1,    -1,    34,    35,    -1,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    -1,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    -1,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    -1,    96,    97,    98,    99,    -1,    -1,
     102,   103,   104,    -1,    -1,   107,   108,    -1,    -1,    -1,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,    -1,    -1,    -1,    -1,   127,    -1,   129,   130,   131,
     132,    -1,   134,    -1,    -1,    -1,   138,   139,   140,   141,
     142,    -1,    -1,    -1,    -1,    -1,    -1,   149,   150,   151,
     152,   153,   154,    -1,   156,   157,    -1,   159,   160,    -1,
     162,   163,    -1,    -1,    -1,    -1,   168,   169,   170,   171,
     172,   173,   174,   175,    -1,   177,    -1,    -1,    -1,    -1,
      -1,   183,   184,   185,    -1,    -1,    -1,   189,    -1,   191,
     192,    -1,    -1,    -1,    -1,    -1,    -1,   199,    -1,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
      -1,    -1,   214,   215,   216,    -1,   218,    -1,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,    -1,
     232,    -1,   234,    -1,    -1,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,   264,    -1,   266,   267,   268,    -1,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,   317,    -1,   319,    -1,   321,
      -1,   323,    21,    22,    23,    24,    25,    26,    -1,    -1,
      -1,    30,    -1,    -1,    -1,    34,    35,    -1,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    -1,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    -1,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    -1,    96,    97,    98,
      99,    -1,    -1,   102,   103,   104,    -1,    -1,   107,   108,
      -1,    -1,    -1,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,    -1,    -1,    -1,    -1,   127,    -1,
     129,   130,   131,   132,    -1,   134,    -1,    -1,    -1,   138,
     139,   140,   141,   142,    -1,    -1,    -1,    -1,    -1,    -1,
     149,   150,   151,   152,   153,   154,    -1,   156,   157,    -1,
     159,   160,    -1,   162,   163,    -1,    -1,    -1,    -1,   168,
     169,   170,   171,   172,   173,   174,   175,    -1,   177,    -1,
      -1,    -1,    -1,    -1,   183,   184,   185,    -1,    -1,    -1,
     189,    -1,   191,   192,    -1,    -1,    -1,    -1,    -1,    -1,
     199,    -1,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,    -1,    -1,   214,   215,   216,    -1,   218,
      -1,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,    -1,   232,    -1,   234,    -1,    -1,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   262,   263,   264,    -1,   266,   267,   268,
      -1,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,   317,    -1,
     319,    -1,    -1,    -1,   323,    21,    22,    23,    24,    25,
      26,    -1,    -1,    -1,    30,    -1,    -1,    -1,    34,    35,
      -1,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      -1,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    -1,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    -1,
      96,    97,    98,    99,    -1,    -1,   102,   103,   104,    -1,
      -1,   107,   108,    -1,    -1,    -1,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,    -1,    -1,    -1,
      -1,   127,    -1,   129,   130,   131,   132,    -1,   134,    -1,
      -1,    -1,   138,   139,   140,   141,   142,    -1,    -1,    -1,
      -1,    -1,    -1,   149,   150,   151,   152,   153,   154,    -1,
     156,   157,    -1,   159,   160,    -1,   162,   163,    -1,    -1,
      -1,    -1,   168,   169,   170,   171,   172,   173,   174,   175,
      -1,   177,    -1,    -1,    -1,    -1,    -1,   183,   184,   185,
      -1,    -1,    -1,   189,    -1,   191,   192,    -1,    -1,    -1,
      -1,    -1,    -1,   199,    -1,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,    -1,    -1,   214,   215,
     216,    -1,   218,    -1,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,    -1,   232,    -1,   234,    -1,
      -1,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,   264,    -1,
     266,   267,   268,    -1,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,   317,    -1,   319,    25,    26,    -1,   323,    -1,    -1,
      -1,    -1,    -1,    34,    35,    -1,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    -1,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    -1,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    -1,    96,    97,    98,    99,    -1,
      -1,   102,   103,   104,    -1,    -1,   107,   108,    -1,    -1,
      -1,    -1,   113,   114,   115,   116,   117,   118,   119,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   129,   130,
     131,   132,    -1,   134,    -1,    -1,    -1,   138,   139,   140,
     141,   142,    -1,    -1,    -1,    -1,    -1,    -1,   149,   150,
     151,    -1,   153,   154,   155,    -1,    -1,    -1,   159,    -1,
      -1,   162,   163,    -1,    -1,    -1,    -1,   168,   169,   170,
     171,   172,   173,   174,   175,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   183,   184,   185,    -1,    -1,    -1,   189,   190,
     191,   192,    -1,    -1,    -1,    -1,   197,    -1,   199,    -1,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,    -1,    -1,   214,   215,    -1,    -1,   218,    -1,   220,
     221,    -1,    -1,    -1,   225,   226,   227,   228,   229,   230,
      -1,   232,    -1,   234,    -1,    -1,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     261,   262,   263,   264,    -1,   266,   267,   268,    -1,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   316,    -1,    -1,    25,    26,
      -1,    -1,   323,   324,   325,   326,   327,    34,    35,    -1,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    -1,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    -1,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    -1,    96,
      97,    98,    99,    -1,    -1,   102,   103,   104,    -1,    -1,
     107,   108,    -1,    -1,    -1,    -1,   113,   114,   115,   116,
     117,   118,   119,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   129,   130,   131,   132,    -1,   134,    -1,    -1,
      -1,   138,   139,   140,   141,   142,    -1,    -1,    -1,    -1,
      -1,    -1,   149,   150,   151,    -1,   153,   154,   155,    -1,
      -1,    -1,   159,    -1,    -1,   162,   163,    -1,    -1,    -1,
      -1,   168,   169,   170,   171,   172,   173,   174,   175,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   183,   184,   185,    -1,
      -1,    -1,   189,   190,   191,   192,    -1,    -1,    -1,    -1,
      -1,    -1,   199,    -1,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,    -1,    -1,   214,   215,    -1,
      -1,   218,    -1,   220,   221,    -1,    -1,    -1,   225,   226,
     227,   228,   229,   230,    -1,   232,    -1,   234,    -1,    -1,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   263,   264,    -1,   266,
     267,   268,    -1,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,   316,
      -1,    -1,    25,    26,    -1,    -1,   323,   324,   325,   326,
     327,    34,    35,    -1,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    -1,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    -1,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    -1,    96,    97,    98,    99,    -1,    -1,   102,
     103,   104,    -1,    -1,   107,   108,    -1,    -1,    -1,    -1,
     113,   114,   115,   116,   117,   118,   119,   120,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   129,   130,   131,   132,
      -1,   134,    -1,    -1,    -1,   138,   139,   140,   141,   142,
      -1,    -1,    -1,    -1,    -1,    -1,   149,   150,   151,    -1,
     153,   154,   155,    -1,    -1,    -1,   159,    -1,    -1,   162,
     163,    -1,    -1,    -1,    -1,   168,   169,   170,   171,   172,
     173,   174,   175,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     183,   184,   185,    -1,    -1,    -1,   189,    -1,   191,   192,
      -1,    -1,    -1,    -1,    -1,    -1,   199,    -1,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,    -1,
      -1,   214,   215,    -1,    -1,   218,    -1,   220,   221,    -1,
      -1,    -1,   225,   226,   227,   228,   229,   230,    -1,   232,
      -1,   234,    -1,    -1,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,    -1,   266,   267,   268,    -1,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,    -1,    -1,    25,    26,    -1,    -1,
     323,   324,   325,   326,   327,    34,    35,    -1,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    -1,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    -1,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    -1,    96,    97,    98,
      99,    -1,    -1,   102,   103,   104,    -1,    -1,   107,   108,
      -1,    -1,    -1,    -1,   113,   114,   115,   116,   117,   118,
     119,   120,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     129,   130,   131,   132,    -1,   134,    -1,    -1,    -1,   138,
     139,   140,   141,   142,    -1,    -1,    -1,    -1,    -1,    -1,
     149,   150,   151,    -1,   153,   154,   155,    -1,    -1,    -1,
     159,    -1,    -1,   162,   163,    -1,    -1,    -1,    -1,   168,
     169,   170,   171,   172,   173,   174,   175,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   183,   184,   185,    -1,    -1,    -1,
     189,    -1,   191,   192,    -1,    -1,    -1,    -1,    -1,    -1,
     199,    -1,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,    -1,    -1,   214,   215,    -1,    -1,   218,
      -1,   220,   221,    -1,    -1,    -1,   225,   226,   227,   228,
     229,   230,    -1,   232,    -1,   234,    -1,    -1,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   262,   263,   264,    -1,   266,   267,   268,
      -1,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,    -1,    -1,
      25,    26,    -1,    -1,   323,   324,   325,   326,   327,    34,
      35,    -1,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    -1,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    -1,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      -1,    96,    97,    98,    99,    -1,    -1,   102,   103,   104,
      -1,    -1,   107,   108,    -1,    -1,    -1,    -1,   113,   114,
     115,   116,   117,   118,   119,   120,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   129,   130,   131,   132,    -1,   134,
      -1,    -1,    -1,   138,   139,   140,   141,   142,    -1,    -1,
      -1,    -1,    -1,    -1,   149,   150,   151,    -1,   153,   154,
     155,    -1,    -1,    -1,   159,    -1,    -1,   162,   163,    -1,
      -1,    -1,    -1,   168,   169,   170,   171,   172,   173,   174,
     175,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   183,   184,
     185,    -1,    -1,    -1,   189,    -1,   191,   192,    -1,    -1,
      -1,    -1,    -1,    -1,   199,    -1,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,    -1,    -1,   214,
     215,    -1,    -1,   218,    -1,   220,   221,    -1,    -1,    -1,
     225,   226,   227,   228,   229,   230,    -1,   232,    -1,   234,
      -1,    -1,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
      -1,   266,   267,   268,    -1,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,    -1,    -1,    25,    26,    -1,    -1,   323,   324,
     325,   326,   327,    34,    35,    -1,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    -1,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    -1,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    -1,    96,    97,    98,    99,    -1,
      -1,   102,   103,   104,    -1,    -1,   107,   108,    -1,    -1,
      -1,    -1,   113,   114,   115,   116,   117,   118,   119,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   129,   130,
     131,   132,    -1,   134,    -1,    -1,    -1,   138,   139,   140,
     141,   142,    -1,    -1,    -1,    -1,    -1,    -1,   149,   150,
     151,    -1,   153,   154,   155,    -1,    -1,    -1,   159,    -1,
      -1,   162,   163,    -1,    -1,    -1,    -1,   168,   169,   170,
     171,   172,   173,   174,   175,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   183,   184,   185,    -1,    -1,    -1,   189,    -1,
     191,   192,    -1,    -1,    -1,    -1,    -1,    -1,   199,    -1,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,    -1,    -1,   214,   215,    -1,    -1,   218,    -1,   220,
     221,    -1,    -1,    -1,   225,   226,   227,   228,   229,   230,
      -1,   232,    -1,   234,    -1,    -1,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     261,   262,   263,   264,    -1,   266,   267,   268,    -1,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   316,    -1,    -1,    25,    26,
      -1,    -1,   323,   324,   325,   326,   327,    34,    35,    -1,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    -1,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    -1,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    -1,    96,
      97,    98,    99,    -1,    -1,   102,   103,   104,    -1,    -1,
     107,   108,    -1,    -1,    -1,    -1,   113,   114,   115,   116,
     117,   118,   119,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   129,   130,   131,   132,    -1,   134,    -1,    -1,
      -1,   138,   139,   140,   141,   142,    -1,    -1,    -1,    -1,
      -1,    -1,   149,   150,   151,    -1,   153,   154,   155,    -1,
      -1,    -1,   159,    -1,    -1,   162,   163,    -1,    -1,    -1,
      -1,   168,   169,   170,   171,   172,   173,   174,   175,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   183,   184,   185,    -1,
      -1,    -1,   189,    -1,   191,   192,    -1,    -1,    -1,    -1,
      -1,    -1,   199,    -1,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,    -1,    -1,   214,   215,    -1,
      -1,   218,    -1,   220,   221,    -1,    -1,    -1,   225,   226,
     227,   228,   229,   230,    -1,   232,    -1,   234,    -1,    -1,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   263,   264,    -1,   266,
     267,   268,    -1,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,   316,
      -1,    -1,    25,    26,    -1,    -1,   323,   324,   325,   326,
     327,    34,    35,    -1,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    -1,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    -1,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    -1,    96,    97,    98,    99,    -1,    -1,   102,
     103,   104,    -1,    -1,   107,   108,    -1,    -1,    -1,    -1,
     113,   114,   115,   116,   117,   118,   119,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   129,   130,   131,   132,
      -1,   134,    -1,    -1,    -1,   138,   139,   140,   141,   142,
      -1,    -1,    -1,    -1,    -1,    -1,   149,   150,   151,    -1,
     153,   154,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   162,
     163,    -1,    -1,    -1,    -1,   168,   169,   170,   171,   172,
     173,   174,   175,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     183,   184,   185,    -1,    -1,    -1,   189,   190,   191,   192,
      -1,    -1,    -1,    -1,   197,    -1,   199,    -1,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,    -1,
      -1,   214,   215,    -1,    -1,   218,    -1,   220,   221,    -1,
      -1,    -1,   225,   226,   227,   228,   229,   230,    -1,   232,
      -1,   234,    -1,    -1,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,    -1,   266,   267,   268,    -1,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,    25,    26,    -1,    -1,    -1,    -1,
     323,    -1,    -1,    34,    35,    -1,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    -1,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    -1,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    -1,    96,    97,    98,    99,    -1,
      -1,   102,   103,   104,    -1,    -1,   107,   108,    -1,    -1,
      -1,    -1,   113,   114,   115,   116,   117,   118,   119,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   129,   130,
     131,   132,    -1,   134,    -1,    -1,    -1,   138,   139,   140,
     141,   142,    -1,    -1,    -1,    -1,    -1,    -1,   149,   150,
     151,    -1,   153,   154,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   162,   163,    -1,    -1,    -1,    -1,   168,   169,   170,
     171,   172,   173,   174,   175,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   183,   184,   185,    -1,    -1,    -1,   189,   190,
     191,   192,    -1,    -1,    -1,    -1,   197,    -1,   199,    -1,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,    -1,    -1,   214,   215,    -1,    -1,   218,    -1,   220,
     221,    -1,    -1,    -1,   225,   226,   227,   228,   229,   230,
      -1,   232,    -1,   234,    -1,    -1,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     261,   262,   263,   264,    -1,   266,   267,   268,    -1,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   316,    25,    26,    -1,    -1,
      -1,    -1,   323,    -1,    -1,    34,    35,    -1,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    -1,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    -1,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    -1,    96,    97,    98,
      99,    -1,    -1,   102,   103,   104,    -1,    -1,   107,   108,
      -1,    -1,    -1,    -1,   113,   114,   115,   116,   117,   118,
     119,   120,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     129,   130,   131,   132,    -1,   134,    -1,    -1,    -1,   138,
     139,   140,   141,   142,    -1,    -1,    -1,    -1,    -1,    -1,
     149,   150,   151,    -1,   153,   154,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   162,   163,    -1,    -1,    -1,    -1,   168,
     169,   170,   171,   172,   173,   174,   175,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   183,   184,   185,    -1,    -1,    -1,
     189,    -1,   191,   192,    -1,    -1,    -1,    -1,    -1,    -1,
     199,    -1,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,    -1,    -1,   214,   215,    -1,    -1,   218,
      -1,   220,   221,    -1,    -1,    -1,   225,   226,   227,   228,
     229,   230,    -1,   232,    -1,   234,    -1,    -1,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   262,   263,   264,    -1,   266,   267,   268,
      -1,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,    25,    26,
      -1,    -1,    -1,    -1,   323,    -1,    -1,    34,    35,    -1,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    -1,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    -1,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    -1,    96,
      97,    98,    99,    -1,    -1,   102,   103,   104,    -1,    -1,
     107,   108,    -1,    -1,    -1,    -1,   113,   114,   115,   116,
     117,   118,   119,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   129,   130,   131,   132,    -1,   134,    -1,    -1,
      -1,   138,   139,   140,   141,   142,    -1,    -1,    -1,    -1,
      -1,    -1,   149,   150,   151,    -1,   153,   154,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   162,   163,    -1,    -1,    -1,
      -1,   168,   169,   170,   171,   172,   173,   174,   175,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   183,   184,   185,    -1,
      -1,    -1,   189,    -1,   191,   192,    -1,    -1,    -1,    -1,
      -1,    -1,   199,    -1,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,    -1,    -1,   214,   215,    -1,
      -1,   218,    -1,   220,   221,    -1,    -1,    -1,   225,   226,
     227,   228,   229,   230,    -1,   232,    -1,   234,    -1,    -1,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   263,   264,    -1,   266,
     267,   268,    -1,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,   316,
      25,    26,    -1,    -1,    -1,    -1,   323,    -1,    -1,    34,
      35,    -1,    37,    38,    39,    -1,    41,    42,    43,    44,
      -1,    -1,    47,    48,    -1,    50,    51,    52,    53,    -1,
      55,    -1,    57,    58,    59,    60,    -1,    62,    -1,    -1,
      65,    66,    67,    68,    69,    -1,    71,    -1,    73,    -1,
      -1,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      -1,    96,    97,    98,    -1,    -1,    -1,   102,   103,   104,
      -1,    -1,   107,   108,    -1,    -1,    -1,    -1,   113,   114,
     115,   116,   117,   118,   119,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   129,   130,   131,   132,    -1,   134,
      -1,    -1,    -1,   138,   139,   140,   141,   142,    -1,    -1,
      -1,    -1,    -1,    -1,   149,   150,   151,    -1,   153,   154,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   162,   163,    -1,
      -1,    -1,    -1,   168,   169,   170,   171,   172,   173,   174,
     175,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   183,   184,
     185,    -1,    -1,    -1,   189,    -1,   191,   192,    -1,    -1,
      -1,    -1,    -1,    -1,   199,    -1,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,    -1,    -1,    -1,
     215,    -1,    -1,   218,    -1,   220,   221,    -1,    -1,    -1,
     225,   226,   227,   228,   229,   230,    -1,    -1,    -1,   234,
      -1,    -1,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,    -1,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
      -1,   266,   267,   268,    -1,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,    -1,    -1,    -1,    -1,    -1,    -1,   323
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned short int
  jsoniq_parser::yystos_[] =
  {
         0,    21,    22,    23,    24,    25,    26,    27,    28,    30,
      34,    35,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    96,    97,
      98,    99,   102,   103,   104,   107,   108,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   127,   129,
     130,   131,   132,   134,   138,   139,   140,   141,   142,   149,
     150,   151,   152,   153,   154,   156,   157,   159,   160,   161,
     162,   163,   168,   169,   170,   171,   172,   173,   174,   175,
     177,   179,   180,   183,   184,   185,   189,   191,   192,   193,
     199,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   214,   215,   216,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   266,   267,   268,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   319,   322,   323,   328,   329,   343,   345,
     346,   347,   348,   349,   350,   351,   352,   353,   354,   355,
     356,   357,   358,   359,   360,   361,   364,   365,   366,   367,
     368,   369,   373,   374,   375,   379,   381,   382,   384,   391,
     393,   396,   397,   398,   400,   401,   402,   403,   404,   406,
     407,   409,   410,   411,   412,   413,   414,   416,   417,   420,
     421,   422,   423,   424,   429,   431,   433,   434,   435,   440,
     459,   462,   466,   469,   470,   476,   477,   478,   479,   480,
     481,   482,   484,   485,   486,   487,   488,   489,   490,   491,
     492,   494,   495,   496,   497,   499,   500,   501,   502,   503,
     504,   505,   508,   511,   512,   513,   514,   515,   516,   517,
     518,   519,   520,   522,   523,   524,   525,   526,   527,   541,
     542,   544,   545,   546,   547,   548,   549,   550,   551,   572,
     577,   578,   579,   580,   581,   582,   585,   643,   644,   645,
     646,   648,   649,   650,   651,   652,   659,   660,   661,    34,
      35,    50,   218,   399,   400,   401,   399,   399,   400,   401,
     159,   159,    38,    39,    41,    42,    48,    58,    59,    76,
      81,   113,   114,   115,   163,   227,   268,   294,   302,   310,
     380,   381,   385,   386,   387,   163,   156,   156,   156,   159,
     388,   159,    25,    35,    62,   120,   280,   439,   441,   442,
     156,   120,   156,   159,   159,    78,   156,   228,   229,   156,
     120,   408,    40,    44,    46,    47,    48,    49,    52,    61,
      69,    72,    74,    75,    77,    99,   114,   138,   163,   172,
     205,   243,   245,   246,   247,   250,   251,   264,   267,   659,
     660,   120,    16,   399,   401,   422,   647,   658,   659,    49,
      74,    75,   120,   156,   188,   251,   421,   423,   433,   190,
     421,   659,   156,   156,   658,   659,    18,    19,   659,   156,
      31,   217,   220,   220,   232,   234,   321,   508,   232,   234,
     321,   422,   647,   232,   321,   508,   232,   237,   321,   120,
     248,   248,   249,   159,   156,   403,   479,   318,   421,   320,
     421,   321,   422,   329,   345,   345,     0,   347,   348,    34,
      50,   350,   367,     1,   193,   344,   193,   344,   114,   382,
     402,   421,   109,   193,   109,   344,   193,    43,    47,    52,
      71,   171,   174,   189,   215,   264,   415,   425,   430,   431,
     432,   447,   448,   452,     1,     3,    68,    73,   120,   426,
     170,    94,   206,   207,   208,   209,   210,   211,   498,   256,
     101,   161,   179,   202,   119,   149,   162,   197,   204,   213,
     139,   153,    51,   203,   103,   104,   161,   179,   496,   196,
     156,   502,   122,   157,   159,   509,   510,   148,   159,   187,
     187,   187,   187,   383,   512,   383,    30,   657,   185,   199,
     185,   199,   169,   185,   660,   659,   172,   205,    48,   659,
     155,   120,    46,    48,    81,   108,   171,   658,   228,   229,
     230,   253,   616,   659,   659,   311,   140,   145,   114,   294,
     302,   385,   658,   400,   400,   421,   120,   190,   389,   390,
     156,   405,   421,     1,   163,   657,   115,   163,   363,   657,
     659,   120,   145,   109,   421,   460,   461,   659,   400,   421,
     421,   570,   659,   400,   156,   156,   421,   659,   145,   460,
     187,   187,   124,   109,   187,   124,   159,   159,   159,   659,
     156,   188,   189,   190,    36,   529,   530,   531,   421,   421,
       8,   178,    17,   421,   217,    30,    30,   422,   422,   508,
     422,   422,   422,   647,   240,   240,   422,   508,    96,   422,
     238,   237,   583,   584,   659,   193,   193,   422,   421,   401,
     421,   252,   418,   419,   318,   320,   422,   240,   345,   193,
     344,   193,   344,     3,   351,   367,   397,     1,   351,   367,
     397,    34,   368,   397,   368,   397,   408,   344,   408,   422,
     422,   120,   171,   173,   173,   402,   422,   422,   436,   437,
     659,   291,   291,   436,   120,   443,   478,   479,   481,    72,
     482,   486,   486,   485,   487,   487,   487,   487,   488,   488,
     489,   489,   238,    96,    96,    96,   503,   187,   421,   515,
     516,   572,   658,   421,   147,   190,   422,   521,   510,   152,
     190,   521,   109,   190,   190,   109,   109,   388,    30,   660,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
     370,   371,   372,    96,   140,   145,   376,   377,   378,   659,
     163,   163,   370,   657,   130,   135,    56,    58,   102,   258,
     271,   273,   284,   285,   286,   288,   290,   617,   618,   619,
     620,   621,   622,   629,   635,   636,   253,    96,   306,   659,
     145,   422,   120,   659,   659,   135,   187,   187,   187,   659,
      96,   109,   190,   399,   190,   658,    98,    46,   658,   657,
      98,    96,   145,   552,   659,   422,   442,   187,   109,   191,
     150,   552,   187,   190,   190,   156,   187,   400,   400,   187,
     145,   552,   422,   191,   422,   422,   658,   422,   421,   421,
     421,   659,   530,   531,   133,   200,   187,   187,   187,   134,
     193,   134,   193,    96,   225,   226,   240,    96,   225,   226,
     240,   240,   240,   422,   422,    96,    96,   422,   244,   232,
     508,   238,   109,   242,   145,   193,   190,   421,   187,    11,
      12,    20,   197,   506,   507,   589,   659,   419,   240,   422,
     367,    34,    34,   193,   344,   193,   115,   402,   659,   173,
     422,   453,   454,   120,   449,   450,   109,    37,    98,   150,
     438,   439,   552,   659,    57,   221,   261,   427,   428,   156,
     159,   266,   501,   512,   590,   593,   594,   595,   596,   597,
     601,   603,   605,   606,    40,    45,    46,    48,    54,    61,
      63,    64,    72,    99,   155,   159,   214,   232,   324,   325,
     326,   327,   553,   555,   557,   559,   560,   561,   562,   563,
     564,   565,   566,   567,   568,   569,   573,   574,   575,   576,
     653,   654,   655,   656,   659,   553,   493,   558,   659,   493,
     187,   188,   109,   190,   190,   512,   151,   168,   151,   168,
     140,   405,   388,   371,   135,   159,   555,   378,   422,   552,
     657,   657,   131,   132,   657,   284,   285,   286,   290,   659,
     270,   281,   270,   281,    30,   293,    98,   115,   159,   623,
     626,   617,    40,    45,    46,    54,    61,    63,    64,    72,
      99,   232,   392,   559,   653,   234,   306,   315,   422,   659,
      96,   306,   657,   156,   552,   553,   390,    96,   187,   201,
     135,   362,   657,   163,   135,    98,   362,   553,   422,   145,
     439,   156,   120,   422,   422,   150,   102,   463,   464,   465,
     467,   468,   102,   471,   472,   473,   474,   400,   187,   187,
     156,   422,   145,   193,   422,   124,   124,   190,   190,   190,
      36,   531,   133,   200,     9,    10,   105,   126,   128,   156,
     198,   526,   528,   539,   540,   543,   156,    30,    30,   239,
     241,   422,   422,   422,   239,   241,   422,   422,   422,   422,
     422,    98,   422,   422,   422,   422,   244,   508,   120,   422,
     422,    49,    74,    75,   251,   402,   423,   433,   252,   586,
     587,   156,   213,   403,   422,   193,   115,   397,   397,   397,
     453,    97,   108,   118,   130,   455,   456,   457,   458,   109,
     659,   109,   120,   437,   130,   120,   422,   150,   439,   150,
      37,   150,   438,   439,   150,   552,   261,    55,    60,    79,
     120,   438,   444,   445,   446,   428,   421,   590,   597,   156,
     292,   483,   642,    98,   172,   259,   260,   262,   269,   279,
     291,   591,   592,   611,   612,   613,   614,   637,   640,   265,
     267,   598,   616,   274,   602,   638,   254,   255,   277,   607,
     608,   159,   159,   159,   159,   159,   159,   159,   159,   159,
     159,   159,   190,   555,   159,   159,   159,   159,   159,   159,
     147,   179,   197,   554,   147,   147,   422,   140,   405,   572,
     377,   293,    30,    98,   115,   159,   630,    30,   623,   554,
     554,   503,   294,   313,   552,   392,   234,   193,   399,   553,
     402,   422,   657,   109,   362,   422,   145,   399,   461,   422,
     422,   115,   464,   465,   102,   189,   115,   465,   468,   120,
     475,   553,   102,   115,   472,   102,   115,   474,   187,   399,
     422,   422,   422,   201,   471,   135,   198,   528,     7,   400,
     659,   198,   539,   400,   193,   193,   240,   240,   240,   240,
      98,   323,   244,   422,   244,   584,   189,   159,   159,   159,
     189,   589,   587,   506,   657,   131,   132,   457,   458,   458,
     454,   108,   145,   451,   552,   450,   437,   150,   438,   659,
     422,   150,   422,   130,   422,   150,   439,   150,   422,   150,
     120,   120,   422,   659,   446,    79,   187,   190,   590,   604,
     257,   221,   261,   275,   282,   641,    98,   263,   264,   639,
     257,   594,   641,   485,   611,   595,   150,   289,   599,   600,
     639,   293,   610,    80,   609,   190,   190,   568,   569,   190,
     197,   659,   190,   197,   553,   556,   190,    30,   190,   658,
     659,   659,   190,   190,   197,   659,   190,   190,   190,   190,
     190,   190,   190,   190,    30,   139,   204,   632,   633,   634,
      30,   631,   632,   278,   627,   109,   624,   173,   659,   264,
     503,   187,   129,   129,    98,   657,   422,   187,   189,   189,
     422,   402,   422,   189,   189,   659,   189,   213,   120,   475,
     120,   189,   120,   475,   189,   187,   115,   531,   659,   198,
     187,   531,   659,   187,   422,   422,   422,   422,   323,   422,
     422,   422,   422,   421,   421,   421,   156,   588,   458,   657,
     422,   145,   422,   150,   422,   150,   438,   422,   150,   422,
     422,   659,   659,   445,   422,   187,   487,    53,   132,   485,
     485,   276,   283,   293,   615,   615,   596,   156,   287,   190,
     190,   109,   190,   109,   190,    96,   190,   109,   190,   190,
     190,   190,   190,   109,   190,   109,   190,   630,   630,   634,
     109,   190,    30,   628,   639,   625,   626,   190,   394,   395,
     503,   120,   232,   314,   294,   173,   402,   422,   362,   422,
     402,    96,   402,   422,   553,   659,   189,   659,   422,   659,
     189,   402,   120,    95,   186,   532,   531,   659,   200,   531,
     422,   190,   190,   190,   421,   451,   422,   422,   422,   150,
     422,    55,   485,   485,   202,   421,   570,   571,   659,   570,
     571,   553,   553,    96,   570,   570,    30,   272,   109,   109,
     458,   552,   659,   120,   232,   659,   394,   475,    96,   189,
      96,   659,     5,   136,   535,   536,   538,   540,    29,   137,
     533,   534,   537,   540,   200,   531,   200,   201,   471,   187,
     451,   422,   120,   485,   187,   190,   190,   147,   190,   190,
     553,   190,   190,   626,   395,   458,   312,   659,   120,   232,
     189,   475,   402,   422,   475,   189,    95,   136,   538,   186,
     137,   537,   200,   115,   659,   422,   312,   659,   120,   402,
     422,   189,   189,   120,   300,   312,   659,   659,   313,   422,
     313,   189,   503,   503,   202,   294,   659,   232,   120,   659,
     313,   503
  };

#if YYDEBUG
  /* TOKEN_NUMBER_[YYLEX-NUM] -- Internal symbol number corresponding
     to YYLEX-NUM.  */
  const unsigned short int
  jsoniq_parser::yytoken_number_[] =
  {
         0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,   472,   473,   474,
     475,   476,   477,   478,   479,   480,   481,   482,   483,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   493,   494,
     495,   496,   497,   498,   499,   500,   501,   502,   503,   504,
     505,   506,   507,   508,   509,   510,   511,   512,   513,   514,
     515,   516,   517,   518,   519,   520,   521,   522,   523,   524,
     525,   526,   527,   528,   529,   530,   531,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   543,   544,
     545,   546,   547,   548,   549,   550,   551,   552,   553,   554,
     555,   556,   557,   558,   559,   560,   561,   562,   563,   564,
     565,   566,   567,   568,   569,   570,   571,   572,   573,   574,
     575,   576,   577,   578,   579,   580,   581,   582,   583,   584,
     585,   586,   587,   588,   589,   590,   591,   592,   593,   594,
     595,   596
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned short int
  jsoniq_parser::yyr1_[] =
  {
         0,   342,   343,   343,   343,   343,   344,   344,   344,   345,
     345,   345,   345,   346,   346,   346,   346,   347,   347,   347,
     347,   347,   347,   347,   347,   348,   348,   348,   348,   349,
     350,   350,   350,   351,   351,   351,   351,   351,   352,   352,
     352,   352,   352,   352,   352,   352,   353,   353,   354,   355,
     356,   356,   357,   357,   358,   358,   359,   359,   359,   359,
     360,   360,   360,   361,   361,   361,   361,   362,   362,   363,
     363,   364,   364,   364,   364,   365,   366,   366,   367,   367,
     367,   368,   368,   368,   368,   368,   368,   368,   368,   369,
     369,   370,   370,   371,   372,   372,   372,   372,   372,   372,
     372,   372,   372,   372,   373,   374,   375,   376,   376,   377,
     377,   377,   378,   379,   379,   379,   380,   380,   380,   380,
     381,   381,   382,   382,   382,   382,   383,   383,   384,   384,
     385,   385,   386,   386,   387,   387,   388,   388,   388,   388,
     389,   389,   390,   390,   391,   391,   391,   391,   392,   392,
     392,   392,   393,   393,   394,   394,   395,   395,   395,   395,
     396,   396,   396,   396,   397,   398,   398,   398,   399,   399,
     399,   400,   400,   401,   401,   401,   402,   402,   402,   402,
     402,   402,   402,   402,   402,   402,   402,   402,   402,   403,
     404,   405,   406,   407,   407,   407,   408,   408,   408,   408,
     409,   410,   411,   412,   413,   413,   414,   415,   416,   417,
     418,   418,   419,   420,   421,   421,   421,   422,   422,   422,
     422,   422,   422,   423,   423,   423,   423,   423,   423,   423,
     423,   423,   423,   423,   423,   424,   425,   426,   426,   427,
     427,   427,   428,   428,   429,   429,   430,   431,   431,   431,
     432,   432,   432,   432,   432,   433,   433,   434,   434,   434,
     435,   435,   436,   436,   436,   437,   437,   437,   437,   437,
     437,   437,   437,   437,   437,   437,   437,   438,   439,   440,
     441,   441,   442,   442,   442,   442,   443,   443,   444,   444,
     444,   445,   445,   445,   446,   446,   446,   447,   448,   449,
     449,   450,   450,   450,   450,   450,   450,   451,   452,   452,
     453,   453,   454,   454,   455,   455,   455,   455,   455,   455,
     455,   456,   456,   457,   457,   458,   459,   459,   460,   460,
     461,   461,   462,   463,   463,   464,   465,   465,   466,   467,
     467,   468,   469,   469,   470,   470,   471,   471,   472,   472,
     473,   473,   474,   474,   475,   475,   476,   477,   477,   478,
     478,   479,   479,   480,   480,   481,   481,   482,   482,   483,
     483,   484,   484,   485,   485,   485,   486,   486,   486,   486,
     486,   487,   487,   487,   488,   488,   488,   489,   489,   490,
     490,   491,   491,   492,   492,   493,   493,   494,   494,   495,
     495,   495,   495,   496,   496,   496,   497,   497,   498,   498,
     498,   498,   498,   498,   499,   499,   499,   499,   500,   500,
     501,   501,   502,   502,   502,   503,   504,   505,   506,   506,
     507,   507,   507,   507,   508,   508,   508,   508,   508,   508,
     508,   508,   509,   509,   510,   511,   511,   511,   511,   511,
     511,   511,   511,   511,   511,   511,   511,   511,   511,   512,
     512,   512,   512,   513,   513,   513,   514,   514,   515,   516,
     516,   517,   517,   518,   519,   520,   520,   521,   521,   521,
     521,   522,   522,   523,   524,   525,   525,   526,   526,   526,
     527,   527,   527,   527,   527,   527,   528,   528,   529,   529,
     530,   531,   531,   532,   532,   533,   533,   534,   534,   534,
     534,   535,   535,   536,   536,   536,   536,   537,   537,   538,
     538,   539,   539,   539,   539,   540,   540,   540,   540,   541,
     541,   542,   542,   543,   544,   544,   544,   544,   544,   544,
     544,   545,   546,   546,   547,   547,   548,   549,   550,   550,
     551,   551,   552,   553,   553,   553,   553,   554,   554,   554,
     555,   555,   555,   555,   555,   555,   555,   555,   555,   556,
     556,   557,   558,   559,   559,   559,   559,   559,   559,   559,
     559,   559,   559,   560,   561,   561,   561,   562,   563,   564,
     565,   565,   565,   566,   566,   566,   566,   566,   567,   568,
     568,   568,   568,   568,   568,   568,   569,   570,   571,   572,
     573,   573,   574,   575,   575,   576,   577,   577,   577,   578,
     578,   578,   578,   578,   578,   578,   578,   578,   578,   579,
     579,   580,   580,   581,   582,   583,   583,   584,   585,   586,
     586,   587,   588,   589,   589,   590,   591,   591,   592,   592,
     593,   593,   594,   594,   595,   595,   596,   596,   597,   598,
     598,   599,   599,   600,   601,   601,   601,   602,   602,   603,
     604,   604,   605,   606,   606,   607,   607,   608,   608,   608,
     609,   609,   610,   610,   611,   611,   611,   611,   611,   612,
     613,   614,   615,   615,   615,   616,   616,   617,   617,   617,
     617,   617,   617,   617,   617,   618,   618,   618,   618,   619,
     619,   620,   621,   621,   622,   622,   622,   623,   623,   624,
     624,   625,   625,   626,   627,   627,   628,   628,   629,   629,
     629,   630,   630,   631,   631,   632,   632,   633,   633,   634,
     634,   635,   636,   636,   637,   637,   637,   638,   639,   639,
     639,   639,   640,   640,   641,   641,   642,   643,   643,   644,
     644,   645,   645,   646,   647,   647,   647,   647,   648,   648,
     648,   648,   648,   648,   649,   649,   650,   650,   651,   651,
     652,   652,   653,   653,   653,   654,   654,   655,   655,   656,
     656,   657,   658,   658,   659,   659,   659,   659,   659,   659,
     659,   659,   659,   659,   659,   659,   659,   659,   659,   659,
     660,   660,   660,   660,   660,   660,   660,   660,   660,   660,
     660,   660,   660,   660,   660,   660,   660,   660,   660,   660,
     660,   660,   660,   660,   660,   660,   660,   660,   660,   660,
     660,   660,   660,   660,   660,   660,   660,   660,   660,   660,
     660,   660,   660,   660,   660,   660,   660,   660,   660,   660,
     660,   660,   660,   660,   660,   660,   660,   660,   660,   660,
     660,   660,   660,   660,   660,   660,   660,   660,   660,   660,
     660,   660,   660,   660,   660,   660,   660,   660,   660,   660,
     660,   660,   660,   660,   660,   660,   660,   660,   660,   660,
     660,   660,   660,   660,   660,   660,   660,   660,   660,   660,
     660,   660,   660,   660,   660,   660,   660,   660,   660,   660,
     660,   660,   660,   660,   660,   660,   660,   660,   660,   660,
     660,   660,   660,   660,   660,   660,   660,   660,   660,   660,
     660,   660,   660,   660,   660,   660,   660,   660,   660,   660,
     660,   660,   660,   660,   660,   660,   660,   660,   660,   660,
     660,   660,   660,   660,   660,   660,   660,   660,   660,   660,
     660,   660,   660,   660,   660,   660,   660,   660,   660,   660,
     660,   660,   660,   660,   660,   660,   660,   660,   660,   660,
     660,   660,   660,   660,   660,   660,   660,   660,   660,   660,
     660,   660,   660,   660,   660,   660,   661
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  jsoniq_parser::yyr2_[] =
  {
         0,     2,     1,     2,     2,     3,     1,     2,     2,     1,
       2,     1,     2,     4,     6,     4,     6,     3,     3,     5,
       1,     3,     3,     5,     5,     1,     3,     3,     5,     6,
       1,     3,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     3,     4,     3,
       3,     3,     3,     3,     5,     5,     5,     5,     5,     5,
       1,     1,     3,     3,     4,     5,     6,     1,     3,     3,
       3,     3,     6,     5,     8,     5,     5,     5,     1,     3,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     4,
       4,     1,     2,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     4,     3,     4,     3,     1,     1,
       1,     2,     2,     4,     3,     5,     3,     4,     4,     5,
       1,     2,     1,     4,     1,     4,     1,     3,     2,     3,
       1,     1,     4,     4,     5,     5,     2,     3,     4,     5,
       1,     3,     2,     3,     3,     5,     4,     6,     1,     2,
       1,     2,     8,     9,     1,     3,     1,     2,     2,     3,
      11,    14,    13,    22,     1,     1,     1,     0,     1,     1,
       0,     1,     2,     1,     2,     4,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       3,     3,     2,     3,     2,     3,     2,     3,     4,     5,
       5,     2,     4,     5,     3,     3,     2,     2,     8,     3,
       1,     2,     3,     1,     1,     3,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     2,     2,     2,     1,
       1,     2,     4,     3,     5,     4,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     3,     3,     2,
       1,     1,     1,     4,     3,     3,     5,     4,     6,     4,
       6,     5,     7,     4,     5,     5,     6,     3,     3,     2,
       1,     3,     4,     5,     3,     6,     4,     5,     1,     2,
       3,     1,     2,     1,     6,     3,     3,     2,     3,     1,
       3,     2,     4,     5,     6,     5,     3,     2,     3,     4,
       1,     3,     1,     2,     1,     1,     1,     2,     2,     2,
       3,     1,     1,     2,     2,     2,     5,     5,     1,     4,
       3,     4,     8,     1,     2,     3,     2,     3,     8,     1,
       2,     3,     8,    10,     8,    10,     1,     2,     4,     7,
       1,     2,     4,     7,     1,     3,     8,     1,     3,     1,
       3,     1,     2,     1,     3,     1,     5,     1,     3,     0,
       1,     1,     3,     1,     3,     3,     1,     3,     3,     3,
       3,     1,     3,     3,     1,     3,     3,     1,     4,     1,
       4,     1,     4,     1,     4,     1,     2,     1,     2,     1,
       1,     2,     2,     1,     1,     1,     1,     3,     1,     1,
       1,     1,     1,     1,     4,     5,     5,     6,     3,     4,
       1,     2,     3,     2,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     3,     4,     3,     3,
       3,     3,     1,     2,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     2,
       3,     1,     1,     4,     4,     3,     4,     1,     3,     1,
       3,     1,     1,     3,     3,     1,     1,     1,     1,     1,
       4,     8,     5,     9,     9,    10,     1,     2,     1,     2,
       6,     0,     1,     3,     3,     0,     1,     1,     1,     2,
       2,     0,     1,     1,     1,     2,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     3,
       2,     3,     3,     2,     1,     1,     1,     1,     1,     1,
       1,     4,     3,     7,     3,     7,     4,     4,     3,     7,
       3,     7,     2,     1,     2,     3,     2,     1,     1,     1,
       1,     1,     3,     1,     3,     1,     1,     1,     1,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     3,     4,     4,     3,     3,     3,
       3,     4,     4,     3,     4,     6,     4,     6,     4,     3,
       4,     6,     6,     4,     6,     6,     4,     1,     2,     1,
       1,     1,     4,     5,     6,     3,     3,     3,     3,     5,
       7,     7,     5,     5,     5,     7,     7,     5,     5,     3,
       3,     5,     7,     5,     7,     1,     4,     3,     5,     1,
       2,     3,     3,     1,     3,     2,     0,     1,     1,     2,
       1,     3,     1,     3,     1,     4,     1,     2,     3,     0,
       1,     0,     1,     4,     2,     3,     1,     0,     1,     4,
       0,     1,     2,     1,     3,     0,     1,     2,     2,     1,
       0,     1,     0,     1,     1,     1,     1,     1,     1,     1,
       3,     3,     1,     1,     1,     2,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     2,     1,     1,     2,
       2,     3,     1,     2,     2,     5,     2,     1,     1,     0,
       2,     1,     3,     4,     0,     2,     0,     2,     4,     4,
       3,     2,     3,     1,     3,     0,     1,     1,     2,     2,
       2,     2,     1,     2,     2,     2,     2,     3,     2,     3,
       3,     4,     2,     2,     1,     1,     3,     2,     3,     2,
       3,     2,     3,     3,     3,     3,     5,     5,     5,     5,
       8,     4,     4,     7,     5,     4,     3,     2,     5,     4,
       7,     6,     1,     1,     1,     3,     1,     3,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1
  };


  /* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
     First, the terminals, then, starting at \a yyntokens_, nonterminals.  */
  const char*
  const jsoniq_parser::yytname_[] =
  {
    "\"'end of file'\"", "error", "$undefined", "\"'unrecognized'\"",
  "\"'error'\"", "\"'apos attribute content'\"", "\"'char literal'\"",
  "\"'char literal]]>'\"", "\"'char literal and pi end'\"",
  "\"'&#charref;'\"", "\"'element content'\"", "\"'pref:*'\"",
  "\"'ns:*'\"", "\"'&entity;'\"", "\"'comment literal'\"",
  "\"'pi <NCName {>'\"", "\"'NCName_sval'\"", "\"'pragma literal'\"",
  "\"'QName #)'\"", "\"'EQName #)'\"", "\"'*:QName'\"",
  "\"'element QName {'\"", "\"'attribute QName {'\"",
  "\"'processing-instruction NCName {'\"", "\"'namespace NCName {'\"",
  "\"'QName'\"", "\"'EQName'\"", "\"'%QName'\"", "\"'%EQName'\"",
  "\"'quote attribute content'\"", "\"'STRING'\"", "\"'XML comment'\"",
  "\"'URI'\"", "\"'NCName'\"", "\"'declare'\"", "\"'module'\"",
  "\"'<blank>'\"", "\"'allowing'\"", "\"'base-uri'\"",
  "\"'boundary-space'\"", "\"'comment'\"", "\"'construction'\"",
  "\"'copy-namespaces'\"", "\"'count'\"", "\"'document'\"",
  "\"'document-node'\"", "\"'element'\"", "\"'for'\"", "\"'function'\"",
  "\"'if'\"", "\"'import'\"", "\"'instance'\"", "\"'let'\"", "\"'most'\"",
  "\"'namespace-node'\"", "\"'next'\"", "\"'no'\"", "\"'only'\"",
  "\"'option'\"", "\"'ordering'\"", "\"'previous'\"",
  "\"'processing-instruction'\"", "\"'schema'\"", "\"'schema-attribute'\"",
  "\"'schema-element'\"", "\"'sequential'\"", "\"'set'\"", "\"'simple'\"",
  "\"'sliding'\"", "\"'some'\"", "\"'space'\"", "\"'stable'\"",
  "\"'text'\"", "\"'tumbling'\"", "\"'switch'\"", "\"'typeswitch'\"",
  "\"'updating'\"", "\"'validate'\"", "\"'type'\"", "\"'when'\"",
  "\"'word'\"", "\"'decimal-format'\"", "\"'decimal-separator'\"",
  "\"'grouping-separator'\"", "\"'infinity'\"", "\"'minus-sign'\"",
  "\"'NaN'\"", "\"'percent'\"", "\"'per-mille'\"", "\"'zero-digit'\"",
  "\"'digit'\"", "\"'pattern-separator'\"", "\"'ancestor'\"",
  "\"'ancestor-or-self'\"", "\"'and'\"", "\"'''\"", "\"'as'\"",
  "\"'ascending'\"", "\"'at'\"", "\"'attribute'\"", "\"'@'\"", "\"'||'\"",
  "\"'case'\"", "\"'castable'\"", "\"'cast'\"", "\"'CDATA[['\"",
  "\"']]'\"", "\"'child'\"", "\"'collation'\"", "\"','\"", "\"'(:'\"",
  "\"':)'\"", "\"'DECIMAL'\"", "\"'context'\"", "\"'variable'\"",
  "\"'default'\"", "\"'descendant'\"", "\"'descendant-or-self'\"",
  "\"'descending'\"", "\"'div'\"", "\"'$'\"", "\"'$_'\"", "\"'.'\"",
  "\"'..'\"", "\"':'\"", "\"'::'\"", "\"'{{'\"", "\"'DOUBLE'\"",
  "\"'<double {>'\"", "\"'else'\"", "\"'empty'\"", "\"'greatest'\"",
  "\"'least'\"", "\"'/>'\"", "\"'encoding'\"", "\"'='\"", "\"''''\"",
  "\"'\\\"\\\"'\"", "\"'every'\"", "\"'except'\"", "\"'external'\"",
  "\"'following'\"", "\"'following-sibling'\"", "\"'follows'\"",
  "\"'>='\"", "\"':='\"", "\"'>'\"", "\"'?'\"", "\"'#'\"", "\"'idiv'\"",
  "\"'in'\"", "\"'inherit'\"", "\"'INTEGER'\"", "\"'intersect'\"",
  "\"'is'\"", "\"'item'\"", "\"'{'\"", "\"'['\"", "\"'<='\"", "\"'('\"",
  "\"'<'\"", "\"'-'\"", "\"'mod'\"", "\"'namespace'\"", "\"'nan'\"",
  "\"'!='\"", "\"'nodecomp'\"", "\"'?""?'\"", "\"'<no inherit>'\"",
  "\"'<no preserve>'\"", "\"'or'\"", "\"'order'\"", "\"'ordered'\"",
  "\"'by'\"", "\"'group'\"", "\"'parent'\"", "\"'%'\"", "\"'<?'\"",
  "\"'?>'\"", "\"'+'\"", "\"'(#'\"", "\"'#)'\"", "\"'<<'\"",
  "\"'preceding'\"", "\"'preceding-sibling'\"", "\"'preserve'\"",
  "\"'\\\"'\"", "\"'}'\"", "\"']'\"", "\"'return'\"", "\"')'\"",
  "\"'satisfies'\"", "\"'self'\"", "\"';'\"", "\"'/'\"", "\"'//'\"",
  "\"'!'\"", "\"'*'\"", "\"'</ (start tag end)'\"", "\"'strip'\"",
  "\"'> (tag end)'\"", "\"'then'\"", "\"'to'\"", "\"'treat'\"",
  "\"'union'\"", "\"'unordered'\"", "\"'eq'\"", "\"'ge'\"", "\"'gt'\"",
  "\"'le'\"", "\"'lt'\"", "\"'ne'\"", "\"'VALUECOMP'\"", "\"'|'\"",
  "\"'empty-sequence'\"", "\"'where'\"", "\"'<!--'\"", "\"'-->'\"",
  "\"'xquery'\"", "\"'jsoniq'\"", "\"'version'\"", "\"'start'\"",
  "\"'null'\"", "\"'true'\"", "\"'false'\"", "\"'after'\"", "\"'before'\"",
  "\"'revalidation'\"", "\"'strict'\"", "\"'lax'\"", "\"'skip'\"",
  "\"'delete'\"", "\"'node'\"", "\"'insert'\"", "\"'nodes'\"",
  "\"'rename'\"", "\"'replace'\"", "\"'value'\"", "\"'of'\"",
  "\"'first'\"", "\"'into'\"", "\"'last'\"", "\"'modify'\"", "\"'copy'\"",
  "\"'with'\"", "\"'break'\"", "\"'continue'\"", "\"'exit'\"",
  "\"'loop'\"", "\"'returning'\"", "\"'while'\"", "\"'try'\"",
  "\"'catch'\"", "\"'using'\"", "\"'all'\"", "\"'any'\"", "\"'contains'\"",
  "\"'content'\"", "\"'diacritics'\"", "\"'different'\"", "\"'distance'\"",
  "\"'end'\"", "\"'entire'\"", "\"'exactly'\"", "\"'from'\"",
  "\"'ftand'\"", "\"'ftnot'\"", "\"'not'\"", "\"'ft-option'\"",
  "\"'ftor'\"", "\"'insensitive'\"", "\"'language'\"", "\"'levels'\"",
  "\"'lowercase'\"", "\"'occurs'\"", "\"'paragraph'\"", "\"'paragraphs'\"",
  "\"'phrase'\"", "\"'relationship'\"", "\"'same'\"", "\"'score'\"",
  "\"'sensitive'\"", "\"'sentence'\"", "\"'sentences'\"", "\"'stemming'\"",
  "\"'stop'\"", "\"'thesaurus'\"", "\"'times'\"", "\"'uppercase'\"",
  "\"'weight'\"", "\"'wildcards'\"", "\"'window'\"", "\"'without'\"",
  "\"'words'\"", "\"'collection'\"", "\"'const'\"", "\"'append-only'\"",
  "\"'queue'\"", "\"'mutable'\"", "\"'read-only'\"", "\"'unique'\"",
  "\"'non'\"", "\"'index'\"", "\"'manually'\"", "\"'automatically'\"",
  "\"'maintained'\"", "\"'on'\"", "\"'range'\"", "\"'equality'\"",
  "\"'general'\"", "\"'integrity'\"", "\"'constraint'\"", "\"'check'\"",
  "\"'key'\"", "\"'foreach'\"", "\"'foreign'\"", "\"'keys'\"", "\"'{|'\"",
  "\"'|}'\"", "\"'{['\"", "\"']}'\"", "\"'json'\"", "\"'append'\"",
  "\"'position'\"", "\"'object'\"", "\"'array'\"", "\"'json-item'\"",
  "\"'structured-item'\"", "\"'BOM_UTF8'\"", "\"'#!/shebang\"",
  "RANGE_REDUCE", "SEQUENCE_TYPE_REDUCE", "ADDITIVE_REDUCE",
  "UNION_REDUCE", "INTERSECT_EXCEPT_REDUCE", "QVARINDECLLIST_REDUCE",
  "COMMA_DOLLAR", "UNARY_PREC", "STEP_REDUCE", "SIMPLEMAPEXPR_REDUCE",
  "MULTIPLICATIVE_REDUCE", "JSONLOOKUPEXPR_REDUCE", "$accept", "Module",
  "ERROR", "ModuleWithoutBOM", "VersionDecl", "MainModule",
  "LibraryModule", "ModuleDecl", "SIND_DeclList", "SIND_Decl", "Setter",
  "BoundarySpaceDecl", "DefaultCollationDecl", "BaseURIDecl",
  "ConstructionDecl", "OrderingModeDecl", "EmptyOrderDecl",
  "CopyNamespacesDecl", "Import", "SchemaImport", "URILiteralList",
  "SchemaPrefix", "ModuleImport", "NamespaceDecl", "DefaultNamespaceDecl",
  "VFO_DeclList", "VFO_Decl", "DecimalFormatDecl",
  "DecimalFormatParamList", "DecimalFormatParam", "DecimalFormatParamName",
  "OptionDecl", "FTOptionDecl", "CtxItemDecl", "CtxItemDecl2",
  "CtxItemDecl3", "CtxItemDecl4", "VarDecl", "VarNameAndType",
  "AnnotationList", "Annotation", "AnnotationLiteralList", "FunctionDecl",
  "FunctionDecl2", "FunctionDeclSimple", "FunctionDeclUpdating",
  "FunctionSig", "ParamList", "Param", "CollectionDecl",
  "CollectionTypeDecl", "IndexDecl", "IndexKeyList", "IndexKeySpec",
  "IntegrityConstraintDecl", "QueryBody", "StatementsAndOptionalExprTop",
  "StatementsAndOptionalExpr", "StatementsAndExpr", "Statements",
  "Statement", "BlockStatement", "BlockExpr",
  "EnclosedStatementsAndOptionalExpr", "VarDeclStatement",
  "BlockVarDeclList", "BlockVarDecl", "AssignStatement", "ApplyStatement",
  "ExitStatement", "WhileStatement", "FlowCtlStatement", "FLWORStatement",
  "ReturnStatement", "IfStatement", "TryStatement", "CatchListStatement",
  "CatchStatement", "VoidStatement", "Expr", "ExprSingle", "ExprSimple",
  "FLWORExpr", "ReturnExpr", "WindowType", "FLWORWinCondType",
  "FLWORWinCond", "WindowClause", "CountClause", "ForLetWinClause",
  "FLWORClause", "FLWORClauseList", "ForClause", "ForOrFrom",
  "VarInDeclList", "VarInDecl", "PositionalVar", "FTScoreVar", "LetClause",
  "VarGetsDeclList", "VarGetsDecl", "WindowVarDecl", "WindowVars",
  "WindowVars3", "WindowVars2", "WhereClause", "GroupByClause",
  "GroupSpecList", "GroupSpec", "GroupCollationSpec", "OrderByClause",
  "OrderSpecList", "OrderSpec", "OrderModifier", "OrderDirSpec",
  "OrderEmptySpec", "OrderCollationSpec", "QuantifiedExpr",
  "QVarInDeclList", "QVarInDecl", "SwitchExpr", "SwitchCaseClauseList",
  "SwitchCaseClause", "SwitchCaseOperandList", "SwitchStatement",
  "SwitchCaseStatementList", "SwitchCaseStatement", "TypeswitchExpr",
  "TypeswitchStatement", "CaseClauseList", "CaseClause",
  "CaseStatementList", "CaseStatement", "SequenceTypeList", "IfExpr",
  "OrExpr", "AndExpr", "NotExpr", "ComparisonExpr", "FTContainsExpr",
  "StringConcatExpr", "opt_FTIgnoreOption", "RangeExpr", "AdditiveExpr",
  "MultiplicativeExpr", "UnionExpr", "IntersectExceptExpr",
  "InstanceofExpr", "TreatExpr", "CastableExpr", "CastExpr", "SingleType",
  "UnaryExpr", "SignList", "ValueExpr", "SimpleMapExpr", "ValueComp",
  "ValidateExpr", "ExtensionExpr", "Pragma_list", "Pragma", "PathExpr",
  "RelativePathExpr", "StepExpr", "NameTest", "Wildcard", "FilterExpr",
  "PredicateList", "Predicate", "PrimaryExpr", "Literal", "NumericLiteral",
  "BooleanLiteral", "VarRef", "ParenthesizedExpr", "ContextItemExpr",
  "OrderedExpr", "UnorderedExpr", "FunctionCall", "ArgList",
  "FunctionItemExpr", "LiteralFunctionItem", "InlineFunction",
  "Constructor", "DirectConstructor", "DirElemConstructor",
  "DirElemContentList", "DirAttributeList", "DirAttr", "OptionalBlank",
  "DirAttributeValue", "opt_QuoteAttrContentList", "QuoteAttrContentList",
  "opt_AposAttrContentList", "AposAttrContentList",
  "QuoteAttrValueContent", "AposAttrValueContent", "DirElemContent",
  "CommonContent", "DirCommentConstructor", "DirPIConstructor",
  "CDataSection", "ComputedConstructor", "CompDocConstructor",
  "CompElemConstructor", "CompAttrConstructor", "CompTextConstructor",
  "CompCommentConstructor", "CompPIConstructor",
  "CompNamespaceConstructor", "TypeDeclaration", "SequenceType",
  "OccurrenceIndicator", "ItemType", "TypeList", "GeneralizedAtomicType",
  "SimpleType", "KindTest", "AnyKindTest", "DocumentTest", "NamespaceTest",
  "TextTest", "CommentTest", "PITest", "AttributeTest",
  "SchemaAttributeTest", "ElementTest", "SchemaElementTest", "TypeName",
  "TypeName_WITH_HOOK", "StringLiteral", "FunctionTest", "AnyFunctionTest",
  "TypedFunctionTest", "ParenthesizedItemType", "RevalidationDecl",
  "InsertExpr", "DeleteExpr", "ReplaceExpr", "RenameExpr", "TransformExpr",
  "VarNameList", "VarNameDecl", "TryExpr", "CatchListExpr", "CatchExpr",
  "BracedExpr", "NameTestList", "FTSelection", "opt_FTPosFilter_list",
  "FTPosFilter_list", "FTOr", "FTAnd", "FTMildNot", "FTUnaryNot",
  "FTPrimaryWithOptions", "opt_FTMatchOptions", "opt_FTWeight", "FTWeight",
  "FTPrimary", "opt_FTTimes", "FTExtensionSelection", "opt_FTSelection",
  "FTWords", "FTWordsValue", "opt_FTAnyallOption", "FTAnyallOption",
  "opt_word", "opt_words", "FTPosFilter", "FTOrder", "FTWindow",
  "FTDistance", "FTUnit", "FTMatchOptions", "FTMatchOption",
  "FTCaseOption", "FTDiacriticsOption", "FTExtensionOption",
  "FTStemOption", "FTThesaurusOption", "FTThesaurusID_or_default",
  "opt_FTThesaurus_list", "FTThesaurus_list", "FTThesaurusID",
  "opt_relationship", "opt_levels", "FTStopWordOption", "FTStopWords",
  "STRING_LITERAL_list", "opt_FTStopWordsInclExcl_list",
  "FTStopWordsInclExcl_list", "FTStopWordsInclExcl", "FTLanguageOption",
  "FTWildCardOption", "FTContent", "FTTimes", "FTRange", "FTScope",
  "FTBigUnit", "FTIgnoreOption", "JSONArrayConstructor",
  "JSONSimpleObjectUnion", "JSONAccumulatorObjectUnion",
  "JSONObjectConstructor", "JSONPairList", "JSONInsertExpr",
  "JSONAppendExpr", "JSONDeleteExpr", "JSONRenameExpr", "JSONReplaceExpr",
  "JSONTest", "JSONItemTest", "JSONObjectTest", "JSONArrayTest",
  "URI_LITERAL", "NCNAME", "QNAME", "FUNCTION_NAME", "EQNAME", YY_NULL
  };

#if YYDEBUG
  /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
  const jsoniq_parser::rhs_number_type
  jsoniq_parser::yyrhs_[] =
  {
       343,     0,    -1,   345,    -1,   328,   345,    -1,   329,   345,
      -1,   328,   329,   345,    -1,     1,    -1,     1,     3,    -1,
     344,     1,    -1,   347,    -1,   346,   347,    -1,   348,    -1,
     346,   348,    -1,   218,   220,    30,   193,    -1,   218,   220,
      30,   134,    30,   193,    -1,   219,   220,    30,   193,    -1,
     219,   220,    30,   134,    30,   193,    -1,   350,   193,   397,
      -1,   367,   193,   397,    -1,   350,   193,   367,   193,   397,
      -1,   397,    -1,   350,   344,   397,    -1,   367,   344,   397,
      -1,   350,   193,   367,   344,   397,    -1,   350,   344,   367,
     193,   397,    -1,   349,    -1,   349,   350,   193,    -1,   349,
     367,   193,    -1,   349,   350,   193,   367,   193,    -1,    35,
     163,   658,   135,   657,   193,    -1,   351,    -1,   350,   193,
     351,    -1,   350,   344,   351,    -1,   352,    -1,   360,    -1,
     365,    -1,   366,    -1,   374,    -1,   353,    -1,   354,    -1,
     355,    -1,   356,    -1,   357,    -1,   358,    -1,   359,    -1,
     577,    -1,    34,    39,   185,    -1,    34,    39,   199,    -1,
      34,   115,   108,   657,    -1,    34,    38,   657,    -1,    34,
      41,   185,    -1,    34,    41,   199,    -1,    34,    59,   172,
      -1,    34,    59,   205,    -1,    34,   115,   171,   130,   131,
      -1,    34,   115,   171,   130,   132,    -1,    34,    42,   185,
     109,   151,    -1,    34,    42,   185,   109,   168,    -1,    34,
      42,   169,   109,   151,    -1,    34,    42,   169,   109,   168,
      -1,   361,    -1,   364,    -1,    50,    25,     1,    -1,    50,
      62,   657,    -1,    50,    62,   363,   657,    -1,    50,    62,
     657,    98,   362,    -1,    50,    62,   363,   657,    98,   362,
      -1,   657,    -1,   362,   109,   657,    -1,   163,   658,   135,
      -1,   115,    46,   163,    -1,    50,    35,   657,    -1,    50,
      35,   163,   658,   135,   657,    -1,    50,    35,   657,    98,
     362,    -1,    50,    35,   163,   658,   135,   657,    98,   362,
      -1,    34,   163,   658,   135,   657,    -1,    34,   115,    46,
     163,   657,    -1,    34,   115,    48,   163,   657,    -1,   368,
      -1,   367,   193,   368,    -1,   367,   344,   368,    -1,   369,
      -1,   373,    -1,   375,    -1,   379,    -1,   384,    -1,   391,
      -1,   393,    -1,   396,    -1,    34,   115,    81,   370,    -1,
      34,    81,   659,   370,    -1,   371,    -1,   370,   371,    -1,
     372,   135,   572,    -1,    82,    -1,    90,    -1,    83,    -1,
      84,    -1,    85,    -1,    86,    -1,    91,    -1,    87,    -1,
      88,    -1,    89,    -1,    34,    58,   659,    30,    -1,    34,
     268,   616,    -1,    34,   113,   155,   376,    -1,    96,   555,
     377,    -1,   377,    -1,   378,    -1,   140,    -1,   140,   378,
      -1,   145,   422,    -1,    34,   380,   145,   422,    -1,    34,
     380,   140,    -1,    34,   380,   140,   145,   422,    -1,   114,
     120,   659,    -1,   114,   120,   659,   552,    -1,   381,   114,
     120,   659,    -1,   381,   114,   120,   659,   552,    -1,   382,
      -1,   381,   382,    -1,    27,    -1,    27,   159,   383,   190,
      -1,    28,    -1,    28,   159,   383,   190,    -1,   512,    -1,
     383,   109,   512,    -1,    34,   385,    -1,    34,   381,   385,
      -1,   386,    -1,   387,    -1,    48,   660,   388,   405,    -1,
      48,   660,   388,   140,    -1,    76,    48,   660,   388,   405,
      -1,    76,    48,   660,   388,   140,    -1,   159,   190,    -1,
     159,   389,   190,    -1,   159,   190,    96,   553,    -1,   159,
     389,   190,    96,   553,    -1,   390,    -1,   389,   109,   390,
      -1,   120,   659,    -1,   120,   659,   552,    -1,    34,   294,
     659,    -1,    34,   294,   659,    96,   392,    -1,    34,   381,
     294,   659,    -1,    34,   381,   294,   659,    96,   392,    -1,
     559,    -1,   559,   554,    -1,   653,    -1,   653,   554,    -1,
      34,   302,   659,   306,   234,   503,   173,   394,    -1,    34,
     381,   302,   659,   306,   234,   503,   173,   394,    -1,   395,
      -1,   394,   109,   395,    -1,   503,    -1,   503,   552,    -1,
     503,   458,    -1,   503,   552,   458,    -1,    34,   310,   311,
     659,   306,   294,   659,   120,   659,   312,   422,    -1,    34,
     310,   311,   659,   306,   294,   659,   232,   120,   659,   312,
     300,   313,   503,    -1,    34,   310,   311,   659,   306,   294,
     659,   314,   232,   120,   659,   312,   422,    -1,    34,   310,
     311,   659,   315,   313,   264,   294,   659,   232,   120,   659,
     313,   503,   202,   294,   659,   232,   120,   659,   313,   503,
      -1,   398,    -1,   400,    -1,   401,    -1,    -1,   400,    -1,
     401,    -1,    -1,   421,    -1,   401,   421,    -1,   402,    -1,
     401,   402,    -1,   401,   421,   344,   402,    -1,   403,    -1,
     406,    -1,   409,    -1,   410,    -1,   411,    -1,   412,    -1,
     413,    -1,   414,    -1,   416,    -1,   470,    -1,   466,    -1,
     417,    -1,   420,    -1,   156,   401,   187,    -1,   156,   399,
     187,    -1,   156,   399,   187,    -1,   407,   193,    -1,   407,
     109,   408,    -1,   114,   408,    -1,   381,   114,   408,    -1,
     120,   659,    -1,   120,   659,   552,    -1,   120,   659,   145,
     422,    -1,   120,   659,   552,   145,   422,    -1,   120,   659,
     145,   422,   193,    -1,   423,   193,    -1,   247,   249,   422,
     193,    -1,   250,   159,   421,   190,   402,    -1,   245,   248,
     193,    -1,   246,   248,   193,    -1,   433,   415,    -1,   189,
     402,    -1,    49,   159,   421,   190,   201,   402,   129,   402,
      -1,   251,   403,   418,    -1,   419,    -1,   418,   419,    -1,
     252,   589,   403,    -1,   193,    -1,   422,    -1,   421,   109,
     422,    -1,   421,   344,   422,    -1,   424,    -1,   462,    -1,
     469,    -1,   476,    -1,   585,    -1,   423,    -1,   477,    -1,
     459,    -1,   578,    -1,   579,    -1,   581,    -1,   580,    -1,
     582,    -1,   650,    -1,   648,    -1,   651,    -1,   652,    -1,
     649,    -1,   433,   425,    -1,   189,   422,    -1,    68,   291,
      -1,    73,   291,    -1,   221,    -1,   261,    -1,    57,   261,
      -1,   427,   444,    79,   422,    -1,   427,    79,   422,    -1,
     435,   426,   443,   428,   428,    -1,   435,   426,   443,   428,
      -1,    43,   120,   659,    -1,   434,    -1,   440,    -1,   429,
      -1,   431,    -1,   447,    -1,   452,    -1,   448,    -1,   430,
      -1,   431,    -1,   433,   432,    -1,   435,   120,   436,    -1,
     435,     1,   436,    -1,   435,     3,    -1,    47,    -1,   264,
      -1,   437,    -1,   436,   109,   120,   437,    -1,   436,   109,
     437,    -1,   659,   150,   422,    -1,   659,    37,   130,   150,
     422,    -1,   659,   552,   150,   422,    -1,   659,   552,    37,
     130,   150,   422,    -1,   659,   438,   150,   422,    -1,   659,
      37,   130,   438,   150,   422,    -1,   659,   552,   438,   150,
     422,    -1,   659,   552,    37,   130,   438,   150,   422,    -1,
     659,   439,   150,   422,    -1,   659,   552,   439,   150,   422,
      -1,   659,   438,   439,   150,   422,    -1,   659,   552,   438,
     439,   150,   422,    -1,    98,   120,   659,    -1,   280,   120,
     659,    -1,    52,   441,    -1,   442,    -1,   441,   109,   442,
      -1,   120,   659,   145,   422,    -1,   120,   659,   552,   145,
     422,    -1,   439,   145,   422,    -1,   120,   659,   552,   439,
     145,   422,    -1,   120,   659,   150,   422,    -1,   120,   659,
     552,   150,   422,    -1,   445,    -1,   120,   659,    -1,   120,
     659,   445,    -1,   438,    -1,   438,   446,    -1,   446,    -1,
      60,   120,   659,    55,   120,   659,    -1,    55,   120,   659,
      -1,    60,   120,   659,    -1,   215,   422,    -1,   174,   173,
     449,    -1,   450,    -1,   449,   109,   450,    -1,   120,   659,
      -1,   120,   659,   145,   422,    -1,   120,   659,   552,   145,
     422,    -1,   120,   659,   552,   145,   422,   451,    -1,   120,
     659,   145,   422,   451,    -1,   120,   659,   451,    -1,   108,
     657,    -1,   171,   173,   453,    -1,    71,   171,   173,   453,
      -1,   454,    -1,   453,   109,   454,    -1,   422,    -1,   422,
     455,    -1,   456,    -1,   457,    -1,   458,    -1,   456,   457,
      -1,   456,   458,    -1,   457,   458,    -1,   456,   457,   458,
      -1,    97,    -1,   118,    -1,   130,   131,    -1,   130,   132,
      -1,   108,   657,    -1,    69,   120,   460,   191,   422,    -1,
     138,   120,   460,   191,   422,    -1,   461,    -1,   460,   109,
     120,   461,    -1,   659,   150,   422,    -1,   659,   552,   150,
     422,    -1,    74,   159,   421,   190,   463,   115,   189,   422,
      -1,   464,    -1,   463,   464,    -1,   465,   189,   422,    -1,
     102,   422,    -1,   465,   102,   422,    -1,    74,   159,   421,
     190,   467,   115,   189,   402,    -1,   468,    -1,   467,   468,
      -1,   465,   189,   402,    -1,    75,   159,   421,   190,   471,
     115,   189,   422,    -1,    75,   159,   421,   190,   471,   115,
     120,   659,   189,   422,    -1,    75,   159,   421,   190,   473,
     115,   189,   402,    -1,    75,   159,   421,   190,   471,   115,
     120,   659,   189,   402,    -1,   472,    -1,   471,   472,    -1,
     102,   475,   189,   422,    -1,   102,   120,   659,    96,   475,
     189,   422,    -1,   474,    -1,   473,   474,    -1,   102,   475,
     189,   402,    -1,   102,   120,   659,    96,   475,   189,   402,
      -1,   553,    -1,   475,   213,   553,    -1,    49,   159,   421,
     190,   201,   422,   129,   422,    -1,   478,    -1,   477,   170,
     478,    -1,   479,    -1,   478,    94,   479,    -1,   480,    -1,
     267,   479,    -1,   481,    -1,   481,   498,   481,    -1,   482,
      -1,   482,   256,    72,   590,   483,    -1,   484,    -1,   484,
     101,   482,    -1,    -1,   642,    -1,   485,    -1,   485,   202,
     485,    -1,   486,    -1,   485,   179,   486,    -1,   485,   161,
     486,    -1,   487,    -1,   486,   197,   487,    -1,   486,   119,
     487,    -1,   486,   149,   487,    -1,   486,   162,   487,    -1,
     488,    -1,   487,   204,   488,    -1,   487,   213,   488,    -1,
     489,    -1,   488,   153,   489,    -1,   488,   139,   489,    -1,
     490,    -1,   490,    51,   238,   553,    -1,   491,    -1,   491,
     203,    96,   553,    -1,   492,    -1,   492,   103,    96,   493,
      -1,   494,    -1,   494,   104,    96,   493,    -1,   558,    -1,
     558,   147,    -1,   496,    -1,   495,   496,    -1,   179,    -1,
     161,    -1,   495,   179,    -1,   495,   161,    -1,   499,    -1,
     497,    -1,   500,    -1,   503,    -1,   497,   196,   503,    -1,
     206,    -1,   211,    -1,   210,    -1,   209,    -1,   208,    -1,
     207,    -1,    77,   156,   400,   187,    -1,    77,   229,   156,
     400,   187,    -1,    77,   228,   156,   400,   187,    -1,    77,
      78,   570,   156,   400,   187,    -1,   501,   156,   187,    -1,
     501,   156,   421,   187,    -1,   502,    -1,   501,   502,    -1,
     180,   659,    17,    -1,   180,    18,    -1,   180,    19,    -1,
     504,    -1,   505,    -1,   508,    -1,   659,    -1,   507,    -1,
     197,    -1,    11,    -1,    12,    -1,    20,    -1,   511,    -1,
     508,   509,    -1,   508,   159,   190,    -1,   508,   159,   521,
     190,    -1,   508,   122,   658,    -1,   508,   122,   516,    -1,
     508,   122,   515,    -1,   508,   122,   572,    -1,   510,    -1,
     509,   510,    -1,   157,   421,   188,    -1,   512,    -1,   515,
      -1,   516,    -1,   517,    -1,   520,    -1,   525,    -1,   518,
      -1,   519,    -1,   522,    -1,   404,    -1,   646,    -1,   643,
      -1,   644,    -1,   645,    -1,   513,    -1,   572,    -1,   514,
      -1,   222,    -1,   112,    -1,   152,    -1,   127,    -1,   223,
      -1,   224,    -1,   120,   659,    -1,   159,   190,    -1,   159,
     421,   190,    -1,   122,    -1,   121,    -1,   172,   156,   421,
     187,    -1,   205,   156,   421,   187,    -1,   660,   159,   190,
      -1,   660,   159,   521,   190,    -1,   147,    -1,   521,   109,
     147,    -1,   422,    -1,   521,   109,   422,    -1,   523,    -1,
     524,    -1,   659,   148,   152,    -1,    48,   388,   405,    -1,
     526,    -1,   544,    -1,   527,    -1,   541,    -1,   542,    -1,
     160,   659,   531,   133,    -1,   160,   659,   531,   200,   198,
     659,   531,   200,    -1,   160,   659,   529,   531,   133,    -1,
     160,   659,   529,   531,   200,   198,   659,   531,   200,    -1,
     160,   659,   531,   200,   528,   198,   659,   531,   200,    -1,
     160,   659,   529,   531,   200,   528,   198,   659,   531,   200,
      -1,   539,    -1,   528,   539,    -1,   530,    -1,   529,   530,
      -1,    36,   659,   531,   135,   531,   532,    -1,    -1,    36,
      -1,   186,   533,   186,    -1,    95,   535,    95,    -1,    -1,
     534,    -1,   137,    -1,   537,    -1,   534,   137,    -1,   534,
     537,    -1,    -1,   536,    -1,   136,    -1,   538,    -1,   536,
     136,    -1,   536,   538,    -1,    29,    -1,   540,    -1,     5,
      -1,   540,    -1,   526,    -1,    10,    -1,   543,    -1,   540,
      -1,     9,    -1,   126,    -1,   128,    -1,   156,   400,   187,
      -1,   216,    31,   217,    -1,   216,   217,    -1,   177,   658,
     178,    -1,   177,   658,     8,    -1,   105,     7,    -1,   545,
      -1,   546,    -1,   547,    -1,   548,    -1,   549,    -1,   550,
      -1,   551,    -1,    44,   156,   400,   187,    -1,    21,   399,
     187,    -1,    46,   156,   421,   187,   156,   399,   187,    -1,
      22,   399,   187,    -1,    99,   156,   421,   187,   156,   399,
     187,    -1,    72,   156,   400,   187,    -1,    40,   156,   400,
     187,    -1,    23,   399,   187,    -1,    61,   156,   421,   187,
     156,   399,   187,    -1,    24,   400,   187,    -1,   163,   156,
     421,   187,   156,   400,   187,    -1,    96,   553,    -1,   555,
      -1,   555,   554,    -1,   214,   159,   190,    -1,   159,   190,
      -1,   147,    -1,   197,    -1,   179,    -1,   557,    -1,   559,
      -1,   155,   159,   190,    -1,   155,    -1,   327,   159,   190,
      -1,   327,    -1,   573,    -1,   576,    -1,   653,    -1,   553,
      -1,   556,   109,   553,    -1,   659,    -1,   659,    -1,   561,
      -1,   568,    -1,   566,    -1,   569,    -1,   567,    -1,   565,
      -1,   564,    -1,   563,    -1,   562,    -1,   560,    -1,   232,
     159,   190,    -1,    45,   159,   190,    -1,    45,   159,   568,
     190,    -1,    45,   159,   569,   190,    -1,    54,   159,   190,
      -1,    72,   159,   190,    -1,    40,   159,   190,    -1,    61,
     159,   190,    -1,    61,   159,   658,   190,    -1,    61,   159,
      30,   190,    -1,    99,   159,   190,    -1,    99,   159,   659,
     190,    -1,    99,   159,   659,   109,   570,   190,    -1,    99,
     159,   197,   190,    -1,    99,   159,   197,   109,   570,   190,
      -1,    63,   159,   659,   190,    -1,    46,   159,   190,    -1,
      46,   159,   659,   190,    -1,    46,   159,   659,   109,   570,
     190,    -1,    46,   159,   659,   109,   571,   190,    -1,    46,
     159,   197,   190,    -1,    46,   159,   197,   109,   570,   190,
      -1,    46,   159,   197,   109,   571,   190,    -1,    64,   159,
     659,   190,    -1,   659,    -1,   659,   147,    -1,    30,    -1,
     574,    -1,   575,    -1,    48,   159,   197,   190,    -1,    48,
     159,   190,    96,   553,    -1,    48,   159,   556,   190,    96,
     553,    -1,   159,   555,   190,    -1,    34,   227,   228,    -1,
      34,   227,   229,    -1,    34,   227,   230,    -1,   233,   232,
     422,   240,   422,    -1,   233,   232,   422,    96,   239,   240,
     422,    -1,   233,   232,   422,    96,   241,   240,   422,    -1,
     233,   232,   422,   225,   422,    -1,   233,   232,   422,   226,
     422,    -1,   233,   234,   422,   240,   422,    -1,   233,   234,
     422,    96,   239,   240,   422,    -1,   233,   234,   422,    96,
     241,   240,   422,    -1,   233,   234,   422,   225,   422,    -1,
     233,   234,   422,   226,   422,    -1,   231,   232,   422,    -1,
     231,   234,   422,    -1,   236,   232,   422,   244,   422,    -1,
     236,   237,   238,   232,   422,   244,   422,    -1,   235,   232,
     422,    96,   422,    -1,   243,   120,   583,   242,   422,   189,
     422,    -1,   584,    -1,   583,   109,   120,   584,    -1,   659,
     145,   422,    -1,   251,   156,   421,   187,   586,    -1,   587,
      -1,   586,   587,    -1,   252,   589,   588,    -1,   156,   421,
     187,    -1,   506,    -1,   589,   213,   506,    -1,   593,   591,
      -1,    -1,   592,    -1,   611,    -1,   592,   611,    -1,   594,
      -1,   593,   269,   594,    -1,   595,    -1,   594,   265,   595,
      -1,   596,    -1,   595,   267,   150,   596,    -1,   597,    -1,
     266,   597,    -1,   601,   598,   599,    -1,    -1,   616,    -1,
      -1,   600,    -1,   289,   156,   421,   187,    -1,   605,   602,
      -1,   159,   590,   190,    -1,   603,    -1,    -1,   638,    -1,
     501,   156,   604,   187,    -1,    -1,   590,    -1,   606,   607,
      -1,   512,    -1,   156,   421,   187,    -1,    -1,   608,    -1,
     255,   609,    -1,   254,   610,    -1,   277,    -1,    -1,    80,
      -1,    -1,   293,    -1,   612,    -1,   613,    -1,   614,    -1,
     640,    -1,   637,    -1,   172,    -1,   291,   485,   615,    -1,
     260,   639,   615,    -1,   293,    -1,   283,    -1,   276,    -1,
     253,   617,    -1,   616,   253,   617,    -1,   618,    -1,   619,
      -1,   620,    -1,   635,    -1,   621,    -1,   629,    -1,   622,
      -1,   636,    -1,   102,   281,    -1,   102,   270,    -1,   273,
      -1,   288,    -1,   258,   281,    -1,   258,   270,    -1,    58,
     659,    30,    -1,   284,    -1,    56,   284,    -1,   286,   623,
      -1,   286,   159,   623,   624,   190,    -1,    56,   286,    -1,
     626,    -1,   115,    -1,    -1,   109,   625,    -1,   626,    -1,
     625,   109,   626,    -1,    98,    30,   627,   628,    -1,    -1,
     278,    30,    -1,    -1,   639,   272,    -1,   285,   293,   630,
     632,    -1,   285,   293,   115,   632,    -1,    56,   285,   293,
      -1,    98,    30,    -1,   159,   631,   190,    -1,    30,    -1,
     631,   109,    30,    -1,    -1,   633,    -1,   634,    -1,   633,
     634,    -1,   204,   630,    -1,   139,   630,    -1,   271,    30,
      -1,   290,    -1,    56,   290,    -1,    98,   221,    -1,    98,
     261,    -1,   262,   257,    -1,   274,   639,   287,    -1,   263,
     485,    -1,    98,   132,   485,    -1,    98,    53,   485,    -1,
     264,   485,   202,   485,    -1,   279,   641,    -1,   259,   641,
      -1,   282,    -1,   275,    -1,   292,   257,   487,    -1,   157,
     188,    -1,   157,   421,   188,    -1,   317,   318,    -1,   317,
     421,   318,    -1,   319,   320,    -1,   319,   421,   320,    -1,
     156,   647,   187,    -1,   658,   124,   422,    -1,   422,   124,
     422,    -1,   647,   109,   422,   124,   422,    -1,   647,   109,
     658,   124,   422,    -1,   233,   321,   422,   240,   422,    -1,
     233,   321,   647,   240,   422,    -1,   233,   321,   422,   240,
     422,    98,   323,   422,    -1,   233,   422,   240,   422,    -1,
     233,   647,   240,   422,    -1,   233,   422,   240,   422,    98,
     323,   422,    -1,   322,   321,   422,   240,   422,    -1,   322,
     422,   240,   422,    -1,   231,   321,   508,    -1,   231,   508,
      -1,   235,   321,   508,    96,   422,    -1,   235,   508,    96,
     422,    -1,   236,   321,   237,   238,   508,   244,   422,    -1,
     236,   237,   238,   508,   244,   422,    -1,   654,    -1,   655,
      -1,   656,    -1,   326,   159,   190,    -1,   326,    -1,   324,
     159,   190,    -1,   324,    -1,   325,   159,   190,    -1,   325,
      -1,    30,    -1,    16,    -1,   659,    -1,   660,    -1,    99,
      -1,    40,    -1,    45,    -1,    54,    -1,    46,    -1,    49,
      -1,   232,    -1,    61,    -1,    63,    -1,    64,    -1,    72,
      -1,    75,    -1,    74,    -1,   214,    -1,   250,    -1,   661,
      -1,    25,    -1,   218,    -1,   130,    -1,    39,    -1,   268,
      -1,    38,    -1,   229,    -1,   228,    -1,   149,    -1,    44,
      -1,   266,    -1,   267,    -1,   281,    -1,   270,    -1,   258,
      -1,   292,    -1,   284,    -1,   286,    -1,   285,    -1,   290,
      -1,   262,    -1,   257,    -1,    80,    -1,   221,    -1,   261,
      -1,    53,    -1,   230,    -1,   243,    -1,   309,    -1,   237,
      -1,   206,    -1,   211,    -1,   210,    -1,   209,    -1,   208,
      -1,   207,    -1,    98,    -1,   113,    -1,   114,    -1,   189,
      -1,    47,    -1,    37,    -1,    68,    -1,    73,    -1,    60,
      -1,    55,    -1,    57,    -1,    79,    -1,    43,    -1,   150,
      -1,    52,    -1,   215,    -1,   173,    -1,   174,    -1,   171,
      -1,    71,    -1,    97,    -1,   118,    -1,   131,    -1,   132,
      -1,   108,    -1,    69,    -1,   138,    -1,   191,    -1,   102,
      -1,    96,    -1,   201,    -1,   129,    -1,   170,    -1,    94,
      -1,    51,    -1,   238,    -1,   103,    -1,   202,    -1,   119,
      -1,   162,    -1,   204,    -1,   153,    -1,   139,    -1,    77,
      -1,    78,    -1,   104,    -1,   203,    -1,   154,    -1,   185,
      -1,   199,    -1,   163,    -1,   140,    -1,   134,    -1,   169,
      -1,   151,    -1,   168,    -1,    34,    -1,    41,    -1,    59,
      -1,   115,    -1,    42,    -1,    58,    -1,   220,    -1,    50,
      -1,    62,    -1,    35,    -1,    48,    -1,   280,    -1,   256,
      -1,   289,    -1,   291,    -1,   260,    -1,   274,    -1,   287,
      -1,   279,    -1,   259,    -1,   273,    -1,   288,    -1,   278,
      -1,   272,    -1,   271,    -1,   255,    -1,   254,    -1,   263,
      -1,   264,    -1,   293,    -1,   283,    -1,   282,    -1,   277,
      -1,   275,    -1,   276,    -1,   242,    -1,   239,    -1,   226,
      -1,   225,    -1,   227,    -1,   244,    -1,   234,    -1,   241,
      -1,   240,    -1,    67,    -1,    65,    -1,    76,    -1,   172,
      -1,   205,    -1,   249,    -1,   247,    -1,   248,    -1,   245,
      -1,   246,    -1,   251,    -1,   252,    -1,   253,    -1,    66,
      -1,   302,    -1,   300,    -1,   301,    -1,   306,    -1,   307,
      -1,   308,    -1,   303,    -1,   304,    -1,   305,    -1,    81,
      -1,    82,    -1,    83,    -1,    84,    -1,    85,    -1,    86,
      -1,    87,    -1,    88,    -1,    89,    -1,    90,    -1,    91,
      -1,   294,    -1,   295,    -1,   296,    -1,   297,    -1,   298,
      -1,   299,    -1,   310,    -1,   311,    -1,   312,    -1,   313,
      -1,   314,    -1,   315,    -1,   316,    -1,    92,    -1,   107,
      -1,   116,    -1,   175,    -1,   183,    -1,   192,    -1,   141,
      -1,    93,    -1,   117,    -1,   142,    -1,   184,    -1,   323,
      -1,    26,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned short int
  jsoniq_parser::yyprhs_[] =
  {
         0,     0,     3,     5,     8,    11,    15,    17,    20,    23,
      25,    28,    30,    33,    38,    45,    50,    57,    61,    65,
      71,    73,    77,    81,    87,    93,    95,    99,   103,   109,
     116,   118,   122,   126,   128,   130,   132,   134,   136,   138,
     140,   142,   144,   146,   148,   150,   152,   156,   160,   165,
     169,   173,   177,   181,   185,   191,   197,   203,   209,   215,
     221,   223,   225,   229,   233,   238,   244,   251,   253,   257,
     261,   265,   269,   276,   282,   291,   297,   303,   309,   311,
     315,   319,   321,   323,   325,   327,   329,   331,   333,   335,
     340,   345,   347,   350,   354,   356,   358,   360,   362,   364,
     366,   368,   370,   372,   374,   379,   383,   388,   392,   394,
     396,   398,   401,   404,   409,   413,   419,   423,   428,   433,
     439,   441,   444,   446,   451,   453,   458,   460,   464,   467,
     471,   473,   475,   480,   485,   491,   497,   500,   504,   509,
     515,   517,   521,   524,   528,   532,   538,   543,   550,   552,
     555,   557,   560,   569,   579,   581,   585,   587,   590,   593,
     597,   609,   624,   638,   661,   663,   665,   667,   668,   670,
     672,   673,   675,   678,   680,   683,   688,   690,   692,   694,
     696,   698,   700,   702,   704,   706,   708,   710,   712,   714,
     718,   722,   726,   729,   733,   736,   740,   743,   747,   752,
     758,   764,   767,   772,   778,   782,   786,   789,   792,   801,
     805,   807,   810,   814,   816,   818,   822,   826,   828,   830,
     832,   834,   836,   838,   840,   842,   844,   846,   848,   850,
     852,   854,   856,   858,   860,   862,   865,   868,   871,   874,
     876,   878,   881,   886,   890,   896,   901,   905,   907,   909,
     911,   913,   915,   917,   919,   921,   923,   926,   930,   934,
     937,   939,   941,   943,   948,   952,   956,   962,   967,   974,
     979,   986,   992,  1000,  1005,  1011,  1017,  1024,  1028,  1032,
    1035,  1037,  1041,  1046,  1052,  1056,  1063,  1068,  1074,  1076,
    1079,  1083,  1085,  1088,  1090,  1097,  1101,  1105,  1108,  1112,
    1114,  1118,  1121,  1126,  1132,  1139,  1145,  1149,  1152,  1156,
    1161,  1163,  1167,  1169,  1172,  1174,  1176,  1178,  1181,  1184,
    1187,  1191,  1193,  1195,  1198,  1201,  1204,  1210,  1216,  1218,
    1223,  1227,  1232,  1241,  1243,  1246,  1250,  1253,  1257,  1266,
    1268,  1271,  1275,  1284,  1295,  1304,  1315,  1317,  1320,  1325,
    1333,  1335,  1338,  1343,  1351,  1353,  1357,  1366,  1368,  1372,
    1374,  1378,  1380,  1383,  1385,  1389,  1391,  1397,  1399,  1403,
    1404,  1406,  1408,  1412,  1414,  1418,  1422,  1424,  1428,  1432,
    1436,  1440,  1442,  1446,  1450,  1452,  1456,  1460,  1462,  1467,
    1469,  1474,  1476,  1481,  1483,  1488,  1490,  1493,  1495,  1498,
    1500,  1502,  1505,  1508,  1510,  1512,  1514,  1516,  1520,  1522,
    1524,  1526,  1528,  1530,  1532,  1537,  1543,  1549,  1556,  1560,
    1565,  1567,  1570,  1574,  1577,  1580,  1582,  1584,  1586,  1588,
    1590,  1592,  1594,  1596,  1598,  1600,  1603,  1607,  1612,  1616,
    1620,  1624,  1628,  1630,  1633,  1637,  1639,  1641,  1643,  1645,
    1647,  1649,  1651,  1653,  1655,  1657,  1659,  1661,  1663,  1665,
    1667,  1669,  1671,  1673,  1675,  1677,  1679,  1681,  1683,  1686,
    1689,  1693,  1695,  1697,  1702,  1707,  1711,  1716,  1718,  1722,
    1724,  1728,  1730,  1732,  1736,  1740,  1742,  1744,  1746,  1748,
    1750,  1755,  1764,  1770,  1780,  1790,  1801,  1803,  1806,  1808,
    1811,  1818,  1819,  1821,  1825,  1829,  1830,  1832,  1834,  1836,
    1839,  1842,  1843,  1845,  1847,  1849,  1852,  1855,  1857,  1859,
    1861,  1863,  1865,  1867,  1869,  1871,  1873,  1875,  1877,  1881,
    1885,  1888,  1892,  1896,  1899,  1901,  1903,  1905,  1907,  1909,
    1911,  1913,  1918,  1922,  1930,  1934,  1942,  1947,  1952,  1956,
    1964,  1968,  1976,  1979,  1981,  1984,  1988,  1991,  1993,  1995,
    1997,  1999,  2001,  2005,  2007,  2011,  2013,  2015,  2017,  2019,
    2021,  2025,  2027,  2029,  2031,  2033,  2035,  2037,  2039,  2041,
    2043,  2045,  2047,  2049,  2053,  2057,  2062,  2067,  2071,  2075,
    2079,  2083,  2088,  2093,  2097,  2102,  2109,  2114,  2121,  2126,
    2130,  2135,  2142,  2149,  2154,  2161,  2168,  2173,  2175,  2178,
    2180,  2182,  2184,  2189,  2195,  2202,  2206,  2210,  2214,  2218,
    2224,  2232,  2240,  2246,  2252,  2258,  2266,  2274,  2280,  2286,
    2290,  2294,  2300,  2308,  2314,  2322,  2324,  2329,  2333,  2339,
    2341,  2344,  2348,  2352,  2354,  2358,  2361,  2362,  2364,  2366,
    2369,  2371,  2375,  2377,  2381,  2383,  2388,  2390,  2393,  2397,
    2398,  2400,  2401,  2403,  2408,  2411,  2415,  2417,  2418,  2420,
    2425,  2426,  2428,  2431,  2433,  2437,  2438,  2440,  2443,  2446,
    2448,  2449,  2451,  2452,  2454,  2456,  2458,  2460,  2462,  2464,
    2466,  2470,  2474,  2476,  2478,  2480,  2483,  2487,  2489,  2491,
    2493,  2495,  2497,  2499,  2501,  2503,  2506,  2509,  2511,  2513,
    2516,  2519,  2523,  2525,  2528,  2531,  2537,  2540,  2542,  2544,
    2545,  2548,  2550,  2554,  2559,  2560,  2563,  2564,  2567,  2572,
    2577,  2581,  2584,  2588,  2590,  2594,  2595,  2597,  2599,  2602,
    2605,  2608,  2611,  2613,  2616,  2619,  2622,  2625,  2629,  2632,
    2636,  2640,  2645,  2648,  2651,  2653,  2655,  2659,  2662,  2666,
    2669,  2673,  2676,  2680,  2684,  2688,  2692,  2698,  2704,  2710,
    2716,  2725,  2730,  2735,  2743,  2749,  2754,  2758,  2761,  2767,
    2772,  2780,  2787,  2789,  2791,  2793,  2797,  2799,  2803,  2805,
    2809,  2811,  2813,  2815,  2817,  2819,  2821,  2823,  2825,  2827,
    2829,  2831,  2833,  2835,  2837,  2839,  2841,  2843,  2845,  2847,
    2849,  2851,  2853,  2855,  2857,  2859,  2861,  2863,  2865,  2867,
    2869,  2871,  2873,  2875,  2877,  2879,  2881,  2883,  2885,  2887,
    2889,  2891,  2893,  2895,  2897,  2899,  2901,  2903,  2905,  2907,
    2909,  2911,  2913,  2915,  2917,  2919,  2921,  2923,  2925,  2927,
    2929,  2931,  2933,  2935,  2937,  2939,  2941,  2943,  2945,  2947,
    2949,  2951,  2953,  2955,  2957,  2959,  2961,  2963,  2965,  2967,
    2969,  2971,  2973,  2975,  2977,  2979,  2981,  2983,  2985,  2987,
    2989,  2991,  2993,  2995,  2997,  2999,  3001,  3003,  3005,  3007,
    3009,  3011,  3013,  3015,  3017,  3019,  3021,  3023,  3025,  3027,
    3029,  3031,  3033,  3035,  3037,  3039,  3041,  3043,  3045,  3047,
    3049,  3051,  3053,  3055,  3057,  3059,  3061,  3063,  3065,  3067,
    3069,  3071,  3073,  3075,  3077,  3079,  3081,  3083,  3085,  3087,
    3089,  3091,  3093,  3095,  3097,  3099,  3101,  3103,  3105,  3107,
    3109,  3111,  3113,  3115,  3117,  3119,  3121,  3123,  3125,  3127,
    3129,  3131,  3133,  3135,  3137,  3139,  3141,  3143,  3145,  3147,
    3149,  3151,  3153,  3155,  3157,  3159,  3161,  3163,  3165,  3167,
    3169,  3171,  3173,  3175,  3177,  3179,  3181,  3183,  3185,  3187,
    3189,  3191,  3193,  3195,  3197,  3199,  3201,  3203,  3205,  3207,
    3209,  3211,  3213,  3215,  3217,  3219,  3221,  3223,  3225,  3227,
    3229,  3231,  3233,  3235,  3237,  3239,  3241
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  jsoniq_parser::yyrline_[] =
  {
         0,  1069,  1069,  1070,  1074,  1078,  1086,  1092,  1096,  1105,
    1111,  1119,  1125,  1136,  1141,  1145,  1150,  1159,  1166,  1173,
    1182,  1189,  1197,  1205,  1213,  1224,  1229,  1236,  1243,  1255,
    1265,  1272,  1279,  1291,  1292,  1293,  1294,  1295,  1300,  1301,
    1302,  1303,  1304,  1305,  1306,  1309,  1314,  1319,  1327,  1335,
    1343,  1348,  1356,  1361,  1369,  1374,  1382,  1387,  1392,  1397,
    1405,  1407,  1410,  1420,  1425,  1433,  1441,  1452,  1459,  1470,
    1475,  1483,  1490,  1497,  1506,  1519,  1527,  1534,  1544,  1551,
    1558,  1569,  1570,  1571,  1572,  1573,  1574,  1575,  1576,  1581,
    1587,  1596,  1603,  1613,  1623,  1624,  1625,  1626,  1627,  1628,
    1629,  1630,  1631,  1632,  1637,  1645,  1653,  1661,  1668,  1676,
    1683,  1688,  1696,  1704,  1718,  1732,  1749,  1754,  1762,  1770,
    1781,  1786,  1795,  1800,  1807,  1812,  1822,  1827,  1836,  1842,
    1855,  1860,  1868,  1879,  1894,  1906,  1921,  1926,  1931,  1936,
    1944,  1951,  1962,  1967,  1977,  1986,  1995,  2004,  2016,  2020,
    2026,  2030,  2040,  2050,  2063,  2069,  2078,  2083,  2090,  2097,
    2108,  2118,  2128,  2138,  2156,  2176,  2180,  2185,  2192,  2196,
    2201,  2208,  2213,  2225,  2232,  2242,  2257,  2258,  2259,  2260,
    2261,  2262,  2263,  2265,  2266,  2267,  2268,  2269,  2270,  2275,
    2283,  2305,  2313,  2321,  2328,  2335,  2346,  2355,  2364,  2373,
    2386,  2394,  2402,  2410,  2425,  2430,  2438,  2452,  2469,  2494,
    2502,  2509,  2520,  2529,  2536,  2541,  2554,  2571,  2572,  2573,
    2574,  2575,  2576,  2581,  2582,  2585,  2586,  2587,  2588,  2589,
    2592,  2593,  2594,  2595,  2596,  2601,  2615,  2623,  2628,  2636,
    2641,  2646,  2654,  2663,  2675,  2685,  2698,  2706,  2707,  2708,
    2713,  2714,  2715,  2716,  2717,  2722,  2729,  2739,  2745,  2754,
    2763,  2764,  2772,  2779,  2787,  2799,  2809,  2819,  2829,  2839,
    2849,  2859,  2869,  2880,  2889,  2899,  2909,  2925,  2934,  2943,
    2951,  2957,  2969,  2977,  2987,  2995,  3007,  3013,  3024,  3026,
    3030,  3038,  3042,  3047,  3051,  3055,  3059,  3069,  3077,  3084,
    3090,  3100,  3104,  3108,  3116,  3124,  3132,  3144,  3152,  3158,
    3168,  3174,  3184,  3188,  3198,  3204,  3210,  3216,  3225,  3234,
    3243,  3256,  3260,  3268,  3274,  3284,  3292,  3301,  3314,  3321,
    3333,  3337,  3349,  3356,  3362,  3371,  3378,  3384,  3395,  3402,
    3408,  3417,  3426,  3433,  3444,  3451,  3463,  3469,  3481,  3487,
    3498,  3504,  3515,  3521,  3532,  3538,  3549,  3558,  3562,  3571,
    3575,  3582,  3586,  3599,  3603,  3683,  3687,  3699,  3703,  3711,
    3714,  3721,  3725,  3734,  3738,  3742,  3750,  3754,  3760,  3766,
    3772,  3782,  3786,  3790,  3798,  3802,  3808,  3818,  3822,  3832,
    3836,  3846,  3850,  3860,  3864,  3874,  3878,  3887,  3891,  3899,
    3903,  3907,  3911,  3921,  3925,  3929,  3936,  3941,  3949,  3953,
    3957,  3961,  3965,  3969,  3993,  3997,  4001,  4005,  4016,  4022,
    4032,  4038,  4048,  4052,  4056,  4119,  4141,  4169,  4333,  4337,
    4347,  4351,  4355,  4359,  4368,  4372,  4376,  4380,  4384,  4389,
    4393,  4397,  4406,  4412,  4422,  4430,  4434,  4438,  4442,  4446,
    4450,  4454,  4458,  4462,  4466,  4471,  4475,  4479,  4483,  4491,
    4495,  4499,  4503,  4511,  4518,  4525,  4535,  4539,  4547,  4555,
    4559,  4567,  4571,  4579,  4587,  4641,  4645,  4667,  4673,  4679,
    4685,  4695,  4699,  4707,  4715,  4727,  4731,  4739,  4743,  4747,
    4755,  4763,  4780,  4788,  4805,  4824,  4848,  4854,  4865,  4871,
    4882,  4891,  4893,  4897,  4902,  4912,  4915,  4922,  4928,  4934,
    4941,  4953,  4956,  4963,  4969,  4975,  4982,  4993,  4997,  5005,
    5009,  5017,  5021,  5025,  5030,  5039,  5043,  5047,  5051,  5059,
    5064,  5072,  5077,  5085,  5093,  5098,  5103,  5108,  5113,  5118,
    5123,  5129,  5137,  5141,  5158,  5162,  5170,  5178,  5186,  5190,
    5198,  5202,  5210,  5218,  5222,  5226,  5231,  5266,  5272,  5278,
    5288,  5292,  5296,  5301,  5305,  5310,  5314,  5318,  5322,  5329,
    5335,  5345,  5353,  5361,  5365,  5369,  5373,  5377,  5381,  5385,
    5389,  5393,  5397,  5405,  5413,  5417,  5421,  5429,  5436,  5444,
    5452,  5456,  5460,  5468,  5472,  5478,  5484,  5488,  5498,  5506,
    5510,  5516,  5525,  5534,  5540,  5546,  5556,  5573,  5580,  5595,
    5622,  5626,  5634,  5642,  5646,  5657,  5674,  5680,  5686,  5696,
    5700,  5706,  5712,  5716,  5722,  5726,  5732,  5738,  5745,  5755,
    5760,  5768,  5774,  5784,  5806,  5815,  5821,  5834,  5848,  5855,
    5861,  5871,  5880,  5888,  5894,  5912,  5920,  5924,  5931,  5936,
    5944,  5948,  5955,  5959,  5966,  5970,  5977,  5981,  5990,  6003,
    6006,  6014,  6017,  6025,  6033,  6041,  6045,  6053,  6056,  6064,
    6076,  6079,  6087,  6099,  6105,  6115,  6118,  6126,  6130,  6134,
    6142,  6145,  6153,  6156,  6164,  6168,  6172,  6176,  6180,  6188,
    6196,  6208,  6220,  6224,  6228,  6236,  6242,  6252,  6256,  6260,
    6264,  6268,  6272,  6276,  6280,  6288,  6292,  6296,  6300,  6308,
    6314,  6324,  6334,  6338,  6346,  6356,  6367,  6374,  6378,  6386,
    6389,  6396,  6401,  6410,  6420,  6423,  6430,  6434,  6442,  6451,
    6458,  6468,  6472,  6479,  6485,  6495,  6498,  6505,  6510,  6522,
    6530,  6542,  6550,  6554,  6562,  6566,  6570,  6578,  6586,  6590,
    6594,  6598,  6606,  6614,  6626,  6630,  6638,  6652,  6656,  6663,
    6668,  6676,  6681,  6690,  6702,  6709,  6715,  6722,  6733,  6739,
    6749,  6754,  6760,  6770,  6777,  6781,  6788,  6810,  6835,  6860,
    6888,  6913,  6941,  6945,  6949,  6956,  6961,  6968,  6973,  6980,
    6985,  6997,  7001,  7002,  7015,  7016,  7017,  7018,  7019,  7020,
    7022,  7023,  7024,  7025,  7026,  7027,  7028,  7029,  7030,  7031,
    7035,  7036,  7037,  7038,  7039,  7040,  7041,  7042,  7043,  7044,
    7045,  7046,  7047,  7048,  7049,  7050,  7051,  7052,  7053,  7054,
    7055,  7056,  7057,  7058,  7059,  7060,  7061,  7062,  7063,  7064,
    7065,  7066,  7067,  7068,  7069,  7070,  7071,  7072,  7073,  7074,
    7075,  7076,  7077,  7078,  7079,  7080,  7081,  7082,  7083,  7084,
    7085,  7086,  7087,  7088,  7089,  7090,  7091,  7092,  7093,  7094,
    7095,  7096,  7097,  7098,  7099,  7100,  7101,  7102,  7103,  7104,
    7105,  7106,  7107,  7108,  7109,  7110,  7111,  7112,  7113,  7114,
    7115,  7116,  7117,  7118,  7119,  7120,  7121,  7122,  7123,  7124,
    7125,  7126,  7127,  7128,  7129,  7130,  7131,  7132,  7133,  7134,
    7135,  7136,  7137,  7138,  7139,  7140,  7141,  7142,  7143,  7144,
    7145,  7146,  7147,  7148,  7149,  7150,  7151,  7152,  7153,  7154,
    7155,  7156,  7157,  7158,  7159,  7160,  7161,  7162,  7164,  7165,
    7167,  7168,  7169,  7170,  7171,  7173,  7175,  7176,  7177,  7178,
    7179,  7180,  7181,  7182,  7183,  7184,  7185,  7186,  7187,  7188,
    7189,  7190,  7191,  7192,  7193,  7194,  7195,  7196,  7197,  7198,
    7199,  7200,  7201,  7202,  7203,  7204,  7205,  7206,  7207,  7208,
    7209,  7210,  7211,  7212,  7213,  7214,  7215,  7216,  7217,  7218,
    7219,  7220,  7221,  7222,  7223,  7224,  7225,  7226,  7227,  7228,
    7229,  7230,  7231,  7232,  7233,  7236,  7245
  };

  // Print the state stack on the debug stream.
  void
  jsoniq_parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (state_stack_type::const_iterator i = yystate_stack_.begin ();
	 i != yystate_stack_.end (); ++i)
      *yycdebug_ << ' ' << *i;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  jsoniq_parser::yy_reduce_print_ (int yyrule)
  {
    unsigned int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    /* Print the symbols being reduced, and their result.  */
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
	       << " (line " << yylno << "):" << std::endl;
    /* The symbols being reduced.  */
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
		       yyrhs_[yyprhs_[yyrule] + yyi],
		       &(yysemantic_stack_[(yynrhs) - (yyi + 1)]),
		       &(yylocation_stack_[(yynrhs) - (yyi + 1)]));
  }
#endif // YYDEBUG

  /* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
  jsoniq_parser::token_number_type
  jsoniq_parser::yytranslate_ (int t)
  {
    static
    const token_number_type
    translate_table[] =
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int jsoniq_parser::yyeof_ = 0;
  const int jsoniq_parser::yylast_ = 19188;
  const int jsoniq_parser::yynnts_ = 320;
  const int jsoniq_parser::yyempty_ = -2;
  const int jsoniq_parser::yyfinal_ = 546;
  const int jsoniq_parser::yyterror_ = 1;
  const int jsoniq_parser::yyerrcode_ = 256;
  const int jsoniq_parser::yyntokens_ = 342;

  const unsigned int jsoniq_parser::yyuser_token_number_max_ = 596;
  const jsoniq_parser::token_number_type jsoniq_parser::yyundef_token_ = 2;


} // zorba
/* Line 1141 of lalr1.cc  */
#line 16535 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
/* Line 1142 of lalr1.cc  */
#line 7249 "/Users/pjl/src/flwor/zorba/repo/bug-1123164/zorba/src/compiler/parser/jsoniq_parser.y"


namespace zorba {

/*
 *  The error member function registers the errors to the driver.
 */
void jsoniq_parser::error(zorba::jsoniq_parser::location_type const& loc, string const& msg)
{
  if (driver.parserError != NULL)
  {
    driver.set_expr(new ParseErrorNode(driver.parserError->loc, driver.parserError->err_code, driver.parserError->msg));
  }
  else
  {
    ParseErrorNode* prevErr = dynamic_cast<ParseErrorNode*>(driver.get_expr());

    if (prevErr != NULL)
    {
      // Error message heuristics: if the current error message has the "(missing comma "," between expressions?)" text,
      // and the old message has a "','" text, then replace the old message with the new one. Unfortunately this 
      // makes the parser error messages harder to internationalize.
      if (msg.find("(missing comma \",\" between expressions?)") != string::npos
          &&
          prevErr->msg.find(zstring("\",\"")) == zstring::npos)
        return;
    }

    // Replace the first occurrence of "unexpected "'QName'"" with "unexpected qualified name %actual_qname%"
    string message = msg;
    int pos;
    std::string unexpected_qname = "unexpected \"'QName'\"";
    if ((pos = message.find(unexpected_qname)) != -1)
      message = message.substr(0, pos) + "unexpected qualified name \"" + driver.symtab.get_last_qname() + "\"" + message.substr(pos+unexpected_qname.length());

    // remove the double quoting "''" from every token description
    while ((pos = message.find("\"'")) != -1 || (pos = message.find("'\"")) != -1)
      message.replace(pos, 2, "\"");
    driver.set_expr(new ParseErrorNode(driver.createQueryLoc(loc), err::XPST0003, message));
  }
}

} // namespace zorba
