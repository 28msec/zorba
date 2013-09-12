/* A Bison parser, made by GNU Bison 2.6.2.  */

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
/* Line 278 of lalr1.cc  */
#line 1 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"

#define JSONIQ_PARSER
/* Line 278 of lalr1.cc  */
#line 58 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"


#include "common/common.h"

#ifdef WIN32
#pragma warning(disable: 4786)
#endif

#include "compiler/api/compilercb.h"
#include "compiler/parser/parse_constants.h"
#include "compiler/parser/parser_helpers.h"
#include "compiler/parser/xquery_driver.h"
#include "compiler/parsetree/parsenodes.h"
#include "store/api/update_consts.h"
#include "zorbatypes/decimal.h"
#include "zorbatypes/integer.h"

#define SYMTAB( n ) driver.symtab.get( (off_t)n )
#define SYMTAB_PUT( s ) driver.symtab.put( s )
#define LOC( p ) driver.createQueryLoc( p )

#define ERROR_IF_QNAME_NOT_NCNAME(qname, location)                \
  do {                                                            \
    if ( ! static_cast<QName*>(qname)->is_ncname()) {             \
      error((location), "A NCName is expected, found a QName");   \
      YYERROR;                                                    \
  }                                                               \
  } while (0);          


#define YYDEBUG 1

using namespace std;
using namespace zorba;

/* Line 278 of lalr1.cc  */
#line 101 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"


#ifdef XQUERY_PARSER
#include "compiler/parser/xquery_scanner.h"
#else
#include "compiler/parser/jsoniq_scanner.h"
#endif

#undef yylex
#ifdef XQUERY_PARSER
#define yylex driver.getXqueryLexer()->lex
#else
#define yylex driver.getJsoniqLexer()->lex
#endif


/* Line 278 of lalr1.cc  */
#line 98 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"


#include "jsoniq_parser.hpp"

/* User implementation prologue.  */
/* Line 284 of lalr1.cc  */
#line 904 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"



template<typename T> inline void release_hack( T *ref ) {
    if ( ref ) {
        RCHelper::addReference( ref );
        RCHelper::removeReference( ref );
    }
}

/* Line 284 of lalr1.cc  */
#line 117 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"


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
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_REDUCE_PRINT(Rule)
# define YY_STACK_PRINT()

#endif /* !YYDEBUG */

#define yyerrok		(yyerrstatus_ = 0)
#define yyclearin	(yychar = yyempty_)

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)


namespace zorba {
/* Line 352 of lalr1.cc  */
#line 212 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"

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
  jsoniq_parser::jsoniq_parser (xquery_driver& driver_yyarg)
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

    YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

    switch (yytype)
      {
        case 111: /* "'DECIMAL'" */
/* Line 453 of lalr1.cc  */
#line 902 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ delete ((*yyvaluep).decval); };
/* Line 453 of lalr1.cc  */
#line 318 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 126: /* "'DOUBLE'" */
/* Line 453 of lalr1.cc  */
#line 901 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ delete ((*yyvaluep).dval); };
/* Line 453 of lalr1.cc  */
#line 325 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 151: /* "'INTEGER'" */
/* Line 453 of lalr1.cc  */
#line 900 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ delete ((*yyvaluep).ival); };
/* Line 453 of lalr1.cc  */
#line 332 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 344: /* VersionDecl */
/* Line 453 of lalr1.cc  */
#line 931 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 339 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 345: /* MainModule */
/* Line 453 of lalr1.cc  */
#line 924 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 346 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 346: /* LibraryModule */
/* Line 453 of lalr1.cc  */
#line 924 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 353 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 347: /* ModuleDecl */
/* Line 453 of lalr1.cc  */
#line 924 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 360 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 348: /* SIND_DeclList */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 367 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 349: /* SIND_Decl */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 374 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 350: /* Setter */
/* Line 453 of lalr1.cc  */
#line 928 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 381 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 351: /* BoundarySpaceDecl */
/* Line 453 of lalr1.cc  */
#line 921 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 388 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 352: /* DefaultCollationDecl */
/* Line 453 of lalr1.cc  */
#line 922 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 395 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 353: /* BaseURIDecl */
/* Line 453 of lalr1.cc  */
#line 921 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 402 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 354: /* ConstructionDecl */
/* Line 453 of lalr1.cc  */
#line 921 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 409 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 355: /* OrderingModeDecl */
/* Line 453 of lalr1.cc  */
#line 926 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 416 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 356: /* EmptyOrderDecl */
/* Line 453 of lalr1.cc  */
#line 923 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 423 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 357: /* CopyNamespacesDecl */
/* Line 453 of lalr1.cc  */
#line 922 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 430 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 358: /* Import */
/* Line 453 of lalr1.cc  */
#line 923 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 437 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 359: /* SchemaImport */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 444 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 360: /* URILiteralList */
/* Line 453 of lalr1.cc  */
#line 929 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 451 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 361: /* SchemaPrefix */
/* Line 453 of lalr1.cc  */
#line 928 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 458 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 362: /* ModuleImport */
/* Line 453 of lalr1.cc  */
#line 924 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 465 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 363: /* NamespaceDecl */
/* Line 453 of lalr1.cc  */
#line 924 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 472 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 364: /* DefaultNamespaceDecl */
/* Line 453 of lalr1.cc  */
#line 922 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 479 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 365: /* VFO_DeclList */
/* Line 453 of lalr1.cc  */
#line 931 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 486 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 366: /* VFO_Decl */
/* Line 453 of lalr1.cc  */
#line 931 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 493 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 367: /* DecimalFormatDecl */
/* Line 453 of lalr1.cc  */
#line 931 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 500 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 368: /* DecimalFormatParamList */
/* Line 453 of lalr1.cc  */
#line 951 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ delete ((*yyvaluep).vstrpair); };
/* Line 453 of lalr1.cc  */
#line 507 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 369: /* DecimalFormatParam */
/* Line 453 of lalr1.cc  */
#line 951 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ delete ((*yyvaluep).strpair); };
/* Line 453 of lalr1.cc  */
#line 514 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 371: /* OptionDecl */
/* Line 453 of lalr1.cc  */
#line 925 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 521 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 372: /* FTOptionDecl */
/* Line 453 of lalr1.cc  */
#line 939 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 528 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 373: /* CtxItemDecl */
/* Line 453 of lalr1.cc  */
#line 929 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 535 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 374: /* CtxItemDecl2 */
/* Line 453 of lalr1.cc  */
#line 929 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 542 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 375: /* CtxItemDecl3 */
/* Line 453 of lalr1.cc  */
#line 929 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 549 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 376: /* CtxItemDecl4 */
/* Line 453 of lalr1.cc  */
#line 930 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 556 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 377: /* VarDecl */
/* Line 453 of lalr1.cc  */
#line 930 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 563 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 378: /* VarNameAndType */
/* Line 453 of lalr1.cc  */
#line 951 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ delete ((*yyvaluep).varnametype); };
/* Line 453 of lalr1.cc  */
#line 570 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 379: /* AnnotationList */
/* Line 453 of lalr1.cc  */
#line 920 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 577 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 380: /* Annotation */
/* Line 453 of lalr1.cc  */
#line 920 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 584 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 381: /* AnnotationLiteralList */
/* Line 453 of lalr1.cc  */
#line 920 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 591 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 382: /* FunctionDecl */
/* Line 453 of lalr1.cc  */
#line 923 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 598 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 383: /* FunctionDecl2 */
/* Line 453 of lalr1.cc  */
#line 923 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 605 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 384: /* FunctionDeclSimple */
/* Line 453 of lalr1.cc  */
#line 923 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 612 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 385: /* FunctionDeclUpdating */
/* Line 453 of lalr1.cc  */
#line 923 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 619 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 386: /* FunctionSig */
/* Line 453 of lalr1.cc  */
#line 951 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ delete ((*yyvaluep).fnsig); };
/* Line 453 of lalr1.cc  */
#line 626 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 387: /* ParamList */
/* Line 453 of lalr1.cc  */
#line 926 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 633 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 388: /* Param */
/* Line 453 of lalr1.cc  */
#line 926 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 640 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 389: /* CollectionDecl */
/* Line 453 of lalr1.cc  */
#line 929 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 647 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 391: /* IndexDecl */
/* Line 453 of lalr1.cc  */
#line 929 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 654 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 392: /* IndexKeyList */
/* Line 453 of lalr1.cc  */
#line 929 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 661 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 393: /* IndexKeySpec */
/* Line 453 of lalr1.cc  */
#line 929 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 668 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 394: /* IntegrityConstraintDecl */
/* Line 453 of lalr1.cc  */
#line 929 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 675 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 395: /* QueryBody */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 682 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 396: /* StatementsAndOptionalExprTop */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 689 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 397: /* StatementsAndOptionalExpr */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 696 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 398: /* StatementsAndExpr */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 703 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 399: /* Statements */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 710 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 400: /* Statement */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 717 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 401: /* BlockStatement */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 724 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 402: /* BlockExpr */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 731 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 403: /* EnclosedStatementsAndOptionalExpr */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 738 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 404: /* VarDeclStatement */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 745 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 407: /* AssignStatement */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 752 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 408: /* ApplyStatement */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 759 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 409: /* ExitStatement */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 766 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 410: /* WhileStatement */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 773 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 411: /* FlowCtlStatement */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 780 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 412: /* FLWORStatement */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 787 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 413: /* ReturnStatement */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 794 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 414: /* IfStatement */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 801 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 415: /* TryStatement */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 808 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 416: /* CatchListStatement */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 815 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 417: /* CatchStatement */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 822 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 418: /* VoidStatement */
/* Line 453 of lalr1.cc  */
#line 932 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 829 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 419: /* Expr */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 836 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 420: /* ExprSingle */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 843 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 421: /* ExprSimple */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 850 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 422: /* FLWORExpr */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 857 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 423: /* ReturnExpr */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 864 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 427: /* FLWORWinCond */
/* Line 453 of lalr1.cc  */
#line 930 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 871 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 428: /* WindowClause */
/* Line 453 of lalr1.cc  */
#line 923 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 878 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 429: /* CountClause */
/* Line 453 of lalr1.cc  */
#line 931 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 885 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 430: /* ForLetWinClause */
/* Line 453 of lalr1.cc  */
#line 923 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 892 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 432: /* FLWORClauseList */
/* Line 453 of lalr1.cc  */
#line 923 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 899 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 433: /* ForClause */
/* Line 453 of lalr1.cc  */
#line 923 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 906 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 435: /* VarInDeclList */
/* Line 453 of lalr1.cc  */
#line 930 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 913 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 436: /* VarInDecl */
/* Line 453 of lalr1.cc  */
#line 930 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 920 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 437: /* PositionalVar */
/* Line 453 of lalr1.cc  */
#line 926 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 438: /* FTScoreVar */
/* Line 453 of lalr1.cc  */
#line 939 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 934 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 439: /* LetClause */
/* Line 453 of lalr1.cc  */
#line 924 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 941 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 440: /* VarGetsDeclList */
/* Line 453 of lalr1.cc  */
#line 930 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 441: /* VarGetsDecl */
/* Line 453 of lalr1.cc  */
#line 930 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 955 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 442: /* WindowVarDecl */
/* Line 453 of lalr1.cc  */
#line 930 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 962 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 443: /* WindowVars */
/* Line 453 of lalr1.cc  */
#line 930 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 969 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 444: /* WindowVars3 */
/* Line 453 of lalr1.cc  */
#line 930 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 976 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 445: /* WindowVars2 */
/* Line 453 of lalr1.cc  */
#line 930 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 983 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 446: /* WhereClause */
/* Line 453 of lalr1.cc  */
#line 931 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 990 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 447: /* GroupByClause */
/* Line 453 of lalr1.cc  */
#line 925 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 997 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 448: /* GroupSpecList */
/* Line 453 of lalr1.cc  */
#line 925 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1004 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 449: /* GroupSpec */
/* Line 453 of lalr1.cc  */
#line 925 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1011 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 450: /* GroupCollationSpec */
/* Line 453 of lalr1.cc  */
#line 925 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1018 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 451: /* OrderByClause */
/* Line 453 of lalr1.cc  */
#line 925 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1025 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 452: /* OrderSpecList */
/* Line 453 of lalr1.cc  */
#line 926 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1032 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 453: /* OrderSpec */
/* Line 453 of lalr1.cc  */
#line 926 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1039 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 454: /* OrderModifier */
/* Line 453 of lalr1.cc  */
#line 925 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1046 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 455: /* OrderDirSpec */
/* Line 453 of lalr1.cc  */
#line 925 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1053 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 456: /* OrderEmptySpec */
/* Line 453 of lalr1.cc  */
#line 925 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1060 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 457: /* OrderCollationSpec */
/* Line 453 of lalr1.cc  */
#line 925 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1067 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 458: /* QuantifiedExpr */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1074 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 459: /* QVarInDeclList */
/* Line 453 of lalr1.cc  */
#line 926 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1081 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 460: /* QVarInDecl */
/* Line 453 of lalr1.cc  */
#line 926 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1088 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 461: /* SwitchExpr */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1095 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 462: /* SwitchCaseClauseList */
/* Line 453 of lalr1.cc  */
#line 932 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1102 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 463: /* SwitchCaseClause */
/* Line 453 of lalr1.cc  */
#line 932 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1109 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 464: /* SwitchCaseOperandList */
/* Line 453 of lalr1.cc  */
#line 932 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1116 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 465: /* SwitchStatement */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1123 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 468: /* TypeswitchExpr */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1130 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 469: /* TypeswitchStatement */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1137 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 470: /* CaseClauseList */
/* Line 453 of lalr1.cc  */
#line 921 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1144 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 471: /* CaseClause */
/* Line 453 of lalr1.cc  */
#line 921 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1151 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 474: /* SequenceTypeList */
/* Line 453 of lalr1.cc  */
#line 928 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1158 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 475: /* IfExpr */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1165 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 476: /* OrExpr */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1172 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 477: /* AndExpr */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1179 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 478: /* NotExpr */
/* Line 453 of lalr1.cc  */
#line 935 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1186 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 479: /* ComparisonExpr */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1193 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 481: /* FTContainsExpr */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1200 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 482: /* StringConcatExpr */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1207 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 483: /* opt_FTIgnoreOption */
/* Line 453 of lalr1.cc  */
#line 939 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1214 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 484: /* RangeExpr */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1221 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 485: /* AdditiveExpr */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1228 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 486: /* MultiplicativeExpr */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1235 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 487: /* UnionExpr */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1242 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 488: /* IntersectExceptExpr */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1249 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 489: /* InstanceofExpr */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1256 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 490: /* TreatExpr */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1263 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 491: /* CastableExpr */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1270 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 492: /* CastExpr */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1277 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 493: /* SingleType */
/* Line 453 of lalr1.cc  */
#line 928 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1284 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 494: /* UnaryExpr */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1291 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 495: /* SignList */
/* Line 453 of lalr1.cc  */
#line 928 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1298 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 496: /* ValueExpr */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1305 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 497: /* SimpleMapExpr */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1312 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 498: /* ValueComp */
/* Line 453 of lalr1.cc  */
#line 929 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1319 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 499: /* NodeComp */
/* Line 453 of lalr1.cc  */
#line 932 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1326 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 500: /* ValidateExpr */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1333 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 501: /* ExtensionExpr */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1340 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 502: /* Pragma_list */
/* Line 453 of lalr1.cc  */
#line 926 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1347 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 503: /* Pragma */
/* Line 453 of lalr1.cc  */
#line 926 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1354 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 504: /* PathExpr */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1361 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 506: /* RelativePathExpr */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1368 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 507: /* StepExpr */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1375 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 508: /* AxisStep */
/* Line 453 of lalr1.cc  */
#line 945 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1382 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 509: /* ForwardStep */
/* Line 453 of lalr1.cc  */
#line 917 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1389 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 510: /* ForwardAxis */
/* Line 453 of lalr1.cc  */
#line 917 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1396 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 511: /* AbbrevForwardStep */
/* Line 453 of lalr1.cc  */
#line 917 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1403 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 512: /* ReverseStep */
/* Line 453 of lalr1.cc  */
#line 917 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1410 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 513: /* ReverseAxis */
/* Line 453 of lalr1.cc  */
#line 917 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1417 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 514: /* NodeTest */
/* Line 453 of lalr1.cc  */
#line 917 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1424 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 515: /* NameTest */
/* Line 453 of lalr1.cc  */
#line 924 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1431 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 516: /* Wildcard */
/* Line 453 of lalr1.cc  */
#line 931 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1438 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 517: /* PostfixExpr */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1445 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 518: /* PredicateList */
/* Line 453 of lalr1.cc  */
#line 926 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1452 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 519: /* Predicate */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1459 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 520: /* PrimaryExpr */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1466 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 521: /* Literal */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1473 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 522: /* NumericLiteral */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1480 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 523: /* VarRef */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1487 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 524: /* ParenthesizedExpr */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1494 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 525: /* ContextItemExpr */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1501 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 526: /* OrderedExpr */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1508 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 527: /* UnorderedExpr */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1515 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 528: /* FunctionCall */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1522 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 529: /* ArgList */
/* Line 453 of lalr1.cc  */
#line 920 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1529 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 533: /* Constructor */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1536 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 534: /* DirectConstructor */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1543 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 535: /* DirElemConstructor */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1550 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 536: /* DirElemContentList */
/* Line 453 of lalr1.cc  */
#line 922 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1557 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 537: /* DirAttributeList */
/* Line 453 of lalr1.cc  */
#line 922 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1564 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 538: /* DirAttr */
/* Line 453 of lalr1.cc  */
#line 922 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1571 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 540: /* DirAttributeValue */
/* Line 453 of lalr1.cc  */
#line 922 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1578 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 541: /* opt_QuoteAttrContentList */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1585 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 542: /* QuoteAttrContentList */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1592 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 543: /* opt_AposAttrContentList */
/* Line 453 of lalr1.cc  */
#line 920 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1599 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 544: /* AposAttrContentList */
/* Line 453 of lalr1.cc  */
#line 920 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1606 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 545: /* QuoteAttrValueContent */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1613 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 546: /* AposAttrValueContent */
/* Line 453 of lalr1.cc  */
#line 920 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1620 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 547: /* DirElemContent */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1627 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 548: /* CommonContent */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1634 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 549: /* DirCommentConstructor */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1641 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 550: /* DirPIConstructor */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1648 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 551: /* CDataSection */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1655 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 552: /* ComputedConstructor */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1662 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 553: /* CompDocConstructor */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1669 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 554: /* CompElemConstructor */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1676 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 555: /* CompAttrConstructor */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1683 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 556: /* CompTextConstructor */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1690 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 557: /* CompCommentConstructor */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1697 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 558: /* CompPIConstructor */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1704 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 559: /* CompNamespaceConstructor */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1711 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 560: /* TypeDeclaration */
/* Line 453 of lalr1.cc  */
#line 928 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1718 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 561: /* SequenceType */
/* Line 453 of lalr1.cc  */
#line 928 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1725 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 562: /* OccurrenceIndicator */
/* Line 453 of lalr1.cc  */
#line 924 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1732 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 563: /* ItemType */
/* Line 453 of lalr1.cc  */
#line 924 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1739 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 564: /* TypeList */
/* Line 453 of lalr1.cc  */
#line 931 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1746 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 565: /* GeneralizedAtomicType */
/* Line 453 of lalr1.cc  */
#line 921 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1753 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 566: /* SimpleType */
/* Line 453 of lalr1.cc  */
#line 921 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1760 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 567: /* KindTest */
/* Line 453 of lalr1.cc  */
#line 924 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1767 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 568: /* AnyKindTest */
/* Line 453 of lalr1.cc  */
#line 920 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1774 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 570: /* DocumentTest */
/* Line 453 of lalr1.cc  */
#line 922 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1781 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 571: /* NamespaceTest */
/* Line 453 of lalr1.cc  */
#line 928 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1788 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 572: /* TextTest */
/* Line 453 of lalr1.cc  */
#line 928 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1795 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 573: /* CommentTest */
/* Line 453 of lalr1.cc  */
#line 921 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1802 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 574: /* PITest */
/* Line 453 of lalr1.cc  */
#line 926 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1809 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 575: /* AttributeTest */
/* Line 453 of lalr1.cc  */
#line 921 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1816 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 576: /* SchemaAttributeTest */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1823 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 577: /* ElementTest */
/* Line 453 of lalr1.cc  */
#line 922 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1830 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 578: /* SchemaElementTest */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1837 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 579: /* TypeName */
/* Line 453 of lalr1.cc  */
#line 928 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1844 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 580: /* TypeName_WITH_HOOK */
/* Line 453 of lalr1.cc  */
#line 928 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1851 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 581: /* StringLiteral */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1858 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 583: /* AnyFunctionTest */
/* Line 453 of lalr1.cc  */
#line 931 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1865 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 584: /* TypedFunctionTest */
/* Line 453 of lalr1.cc  */
#line 931 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1872 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 587: /* InsertExpr */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1879 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 588: /* DeleteExpr */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1886 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 589: /* ReplaceExpr */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1893 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 590: /* RenameExpr */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1900 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 591: /* TransformExpr */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1907 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 592: /* VarNameList */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1914 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 593: /* VarNameDecl */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1921 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 594: /* TryExpr */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1928 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 595: /* CatchListExpr */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1935 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 596: /* CatchExpr */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1942 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 597: /* BracedExpr */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1949 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 598: /* NameTestList */
/* Line 453 of lalr1.cc  */
#line 951 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ delete ((*yyvaluep).name_test_list); };
/* Line 453 of lalr1.cc  */
#line 1956 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 599: /* FTSelection */
/* Line 453 of lalr1.cc  */
#line 939 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1963 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 602: /* FTOr */
/* Line 453 of lalr1.cc  */
#line 939 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1970 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 603: /* FTAnd */
/* Line 453 of lalr1.cc  */
#line 939 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1977 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 604: /* FTMildNot */
/* Line 453 of lalr1.cc  */
#line 939 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1984 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 605: /* FTUnaryNot */
/* Line 453 of lalr1.cc  */
#line 939 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1991 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 606: /* FTPrimaryWithOptions */
/* Line 453 of lalr1.cc  */
#line 939 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1998 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 607: /* opt_FTMatchOptions */
/* Line 453 of lalr1.cc  */
#line 939 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2005 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 609: /* FTWeight */
/* Line 453 of lalr1.cc  */
#line 939 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2012 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 610: /* FTPrimary */
/* Line 453 of lalr1.cc  */
#line 939 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2019 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 611: /* opt_FTTimes */
/* Line 453 of lalr1.cc  */
#line 939 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2026 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 612: /* FTExtensionSelection */
/* Line 453 of lalr1.cc  */
#line 939 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2033 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 614: /* FTWords */
/* Line 453 of lalr1.cc  */
#line 939 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2040 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 615: /* FTWordsValue */
/* Line 453 of lalr1.cc  */
#line 939 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2047 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 617: /* FTAnyallOption */
/* Line 453 of lalr1.cc  */
#line 939 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2054 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 620: /* FTPosFilter */
/* Line 453 of lalr1.cc  */
#line 939 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2061 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 621: /* FTOrder */
/* Line 453 of lalr1.cc  */
#line 939 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2068 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 622: /* FTWindow */
/* Line 453 of lalr1.cc  */
#line 939 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2075 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 623: /* FTDistance */
/* Line 453 of lalr1.cc  */
#line 939 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2082 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 624: /* FTUnit */
/* Line 453 of lalr1.cc  */
#line 939 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2089 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 625: /* FTMatchOptions */
/* Line 453 of lalr1.cc  */
#line 939 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2096 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 626: /* FTMatchOption */
/* Line 453 of lalr1.cc  */
#line 939 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2103 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 627: /* FTCaseOption */
/* Line 453 of lalr1.cc  */
#line 939 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2110 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 628: /* FTDiacriticsOption */
/* Line 453 of lalr1.cc  */
#line 939 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2117 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 629: /* FTExtensionOption */
/* Line 453 of lalr1.cc  */
#line 939 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2124 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 630: /* FTStemOption */
/* Line 453 of lalr1.cc  */
#line 939 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2131 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 631: /* FTThesaurusOption */
/* Line 453 of lalr1.cc  */
#line 939 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2138 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 635: /* FTThesaurusID */
/* Line 453 of lalr1.cc  */
#line 939 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2145 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 638: /* FTStopWordOption */
/* Line 453 of lalr1.cc  */
#line 939 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2152 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 639: /* FTStopWords */
/* Line 453 of lalr1.cc  */
#line 939 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2159 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 643: /* FTStopWordsInclExcl */
/* Line 453 of lalr1.cc  */
#line 939 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2166 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 644: /* FTLanguageOption */
/* Line 453 of lalr1.cc  */
#line 939 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2173 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 645: /* FTWildCardOption */
/* Line 453 of lalr1.cc  */
#line 939 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2180 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 646: /* FTContent */
/* Line 453 of lalr1.cc  */
#line 939 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2187 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 647: /* FTTimes */
/* Line 453 of lalr1.cc  */
#line 939 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2194 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 648: /* FTRange */
/* Line 453 of lalr1.cc  */
#line 939 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2201 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 649: /* FTScope */
/* Line 453 of lalr1.cc  */
#line 939 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2208 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 650: /* FTBigUnit */
/* Line 453 of lalr1.cc  */
#line 939 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2215 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 651: /* FTIgnoreOption */
/* Line 453 of lalr1.cc  */
#line 939 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2222 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 652: /* JSONArrayConstructor */
/* Line 453 of lalr1.cc  */
#line 942 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 2229 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 653: /* JSONSimpleObjectUnion */
/* Line 453 of lalr1.cc  */
#line 942 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 2236 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 654: /* JSONAccumulatorObjectUnion */
/* Line 453 of lalr1.cc  */
#line 942 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 2243 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 655: /* JSONObjectConstructor */
/* Line 453 of lalr1.cc  */
#line 942 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 2250 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 656: /* JSONPairList */
/* Line 453 of lalr1.cc  */
#line 942 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2257 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 657: /* JSONInsertExpr */
/* Line 453 of lalr1.cc  */
#line 942 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 2264 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 658: /* JSONAppendExpr */
/* Line 453 of lalr1.cc  */
#line 942 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 2271 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 659: /* JSONDeleteExpr */
/* Line 453 of lalr1.cc  */
#line 942 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 2278 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 660: /* JSONRenameExpr */
/* Line 453 of lalr1.cc  */
#line 942 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 2285 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 661: /* JSONReplaceExpr */
/* Line 453 of lalr1.cc  */
#line 942 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 2292 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 664: /* QNAME */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 2299 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 665: /* FUNCTION_NAME */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 2306 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 666: /* EQNAME */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 2313 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
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

    /* State.  */
    int yyn;
    int yylen = 0;
    int yystate = 0;

    /* Error handling.  */
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// Semantic value of the lookahead.
    semantic_type yylval;
    /// Location of the lookahead.
    location_type yylloc;
    /// The locations where the error started and ended.
    location_type yyerror_range[3];

    /// $$.
    semantic_type yyval;
    /// @$.
    location_type yyloc;

    int yyresult;

    YYCDEBUG << "Starting parse" << std::endl;


/* User initialization code.  */
/* Line 538 of lalr1.cc  */
#line 140 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
{
    yylloc.begin.filename = yylloc.end.filename = &(driver.theFilename2);
}
/* Line 538 of lalr1.cc  */
#line 2408 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"

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

    {
      slice<location_type, location_stack_type> slice (yylocation_stack_, yylen);
      YYLLOC_DEFAULT (yyloc, slice, yylen);
    }
    YY_REDUCE_PRINT (yyn);
    switch (yyn)
      {
	  case 3:
/* Line 661 of lalr1.cc  */
#line 1052 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      }
    break;

  case 4:
/* Line 661 of lalr1.cc  */
#line 1056 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      }
    break;

  case 5:
/* Line 661 of lalr1.cc  */
#line 1060 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      }
    break;

  case 6:
/* Line 661 of lalr1.cc  */
#line 1068 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.node) = NULL;
      }
    break;

  case 7:
/* Line 661 of lalr1.cc  */
#line 1074 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.node) = NULL; YYABORT;
      }
    break;

  case 8:
/* Line 661 of lalr1.cc  */
#line 1078 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.node) = NULL; YYABORT;
      }
    break;

  case 9:
/* Line 661 of lalr1.cc  */
#line 1087 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 10:
/* Line 661 of lalr1.cc  */
#line 1093 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      MainModule* mm = dynamic_cast<MainModule*>((yysemantic_stack_[(2) - (2)].node));
      mm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 11:
/* Line 661 of lalr1.cc  */
#line 1101 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 12:
/* Line 661 of lalr1.cc  */
#line 1107 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      LibraryModule* lm = dynamic_cast<LibraryModule*>((yysemantic_stack_[(2) - (2)].node));
      lm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 13:
/* Line 661 of lalr1.cc  */
#line 1118 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), "utf-8", VersionDecl::jsoniq );
    }
    break;

  case 14:
/* Line 661 of lalr1.cc  */
#line 1123 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)), VersionDecl::jsoniq );
    }
    break;

  case 15:
/* Line 661 of lalr1.cc  */
#line 1132 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (1)].node)), NULL);

      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(3) - (3)].expr)), prolog);
    }
    break;

  case 16:
/* Line 661 of lalr1.cc  */
#line 1139 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (1)].node)));

      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(3) - (3)].expr)), prolog);
    }
    break;

  case 17:
/* Line 661 of lalr1.cc  */
#line 1146 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)),
                                  static_cast<SIND_DeclList*>((yysemantic_stack_[(5) - (1)].node)),
                                  static_cast<VFO_DeclList*>((yysemantic_stack_[(5) - (3)].node)));

      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(5) - (5)].expr)), prolog);
    }
    break;

  case 18:
/* Line 661 of lalr1.cc  */
#line 1155 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new MainModule( LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(1) - (1)].expr)), NULL );
    }
    break;

  case 19:
/* Line 661 of lalr1.cc  */
#line 1162 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].expr);
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after statement");
      YYERROR;
    }
    break;

  case 20:
/* Line 661 of lalr1.cc  */
#line 1170 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].expr);
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration");
      YYERROR;
    }
    break;

  case 21:
/* Line 661 of lalr1.cc  */
#line 1178 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(5) - (1)].node); (yyval.node) = (yysemantic_stack_[(5) - (3)].node); (yyval.node) = (yysemantic_stack_[(5) - (5)].expr);
      (yylocation_stack_[(5) - (3)]).step();
      error((yylocation_stack_[(5) - (3)]), "syntax error, missing semicolon \";\" after declaration");
      YYERROR;
    }
    break;

  case 22:
/* Line 661 of lalr1.cc  */
#line 1186 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(5) - (1)].node); (yyval.node) = (yysemantic_stack_[(5) - (3)].node); (yyval.node) = (yysemantic_stack_[(5) - (5)].expr);
      (yylocation_stack_[(5) - (1)]).step();
      error((yylocation_stack_[(5) - (1)]), "syntax error, missing semicolon \";\" after statement");
      YYERROR;
    }
    break;

  case 23:
/* Line 661 of lalr1.cc  */
#line 1197 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(1) - (1)].node)), NULL);
    }
    break;

  case 24:
/* Line 661 of lalr1.cc  */
#line 1202 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (2)].node)), NULL);

      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(3) - (1)].node)), prolog);
    }
    break;

  case 25:
/* Line 661 of lalr1.cc  */
#line 1209 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (2)].node)));

      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(3) - (1)].node)), prolog);
    }
    break;

  case 26:
/* Line 661 of lalr1.cc  */
#line 1216 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)),
                                  static_cast<SIND_DeclList*>((yysemantic_stack_[(5) - (2)].node)),
                                  static_cast<VFO_DeclList*>((yysemantic_stack_[(5) - (4)].node)));

      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(5) - (1)].node)), prolog);
    }
    break;

  case 27:
/* Line 661 of lalr1.cc  */
#line 1228 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      ERROR_IF_QNAME_NOT_NCNAME((yysemantic_stack_[(6) - (3)].expr), (yylocation_stack_[(6) - (3)]));
      (yyval.node) = new ModuleDecl( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );
      dynamic_cast<ModuleDecl*>((yyval.node))->setComment( SYMTAB((yysemantic_stack_[(6) - (1)].sval)) );
    }
    break;

  case 28:
/* Line 661 of lalr1.cc  */
#line 1238 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      SIND_DeclList *sdl = new SIND_DeclList( LOC((yyloc)) );
      sdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
      (yyval.node) = sdl;
    }
    break;

  case 29:
/* Line 661 of lalr1.cc  */
#line 1245 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      ((SIND_DeclList*)(yysemantic_stack_[(3) - (1)].node))->push_back( (yysemantic_stack_[(3) - (3)].node) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 30:
/* Line 661 of lalr1.cc  */
#line 1252 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {

      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration");
      YYERROR;
    }
    break;

  case 44:
/* Line 661 of lalr1.cc  */
#line 1287 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new BoundarySpaceDecl(LOC((yyloc)), StaticContextConsts::preserve_space);
    }
    break;

  case 45:
/* Line 661 of lalr1.cc  */
#line 1292 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new BoundarySpaceDecl(LOC((yyloc)), StaticContextConsts::strip_space);
    }
    break;

  case 46:
/* Line 661 of lalr1.cc  */
#line 1300 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DefaultCollationDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (4)].sval)) );
    }
    break;

  case 47:
/* Line 661 of lalr1.cc  */
#line 1308 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new BaseURIDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
    }
    break;

  case 48:
/* Line 661 of lalr1.cc  */
#line 1316 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new ConstructionDecl(LOC((yyloc)), StaticContextConsts::cons_preserve);
    }
    break;

  case 49:
/* Line 661 of lalr1.cc  */
#line 1321 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new ConstructionDecl(LOC((yyloc)), StaticContextConsts::cons_strip);
    }
    break;

  case 50:
/* Line 661 of lalr1.cc  */
#line 1329 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new OrderingModeDecl(LOC((yyloc)), StaticContextConsts::ordered);
    }
    break;

  case 51:
/* Line 661 of lalr1.cc  */
#line 1334 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new OrderingModeDecl(LOC((yyloc)), StaticContextConsts::unordered);
    }
    break;

  case 52:
/* Line 661 of lalr1.cc  */
#line 1342 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new EmptyOrderDecl(LOC((yyloc)), StaticContextConsts::empty_greatest);
    }
    break;

  case 53:
/* Line 661 of lalr1.cc  */
#line 1347 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new EmptyOrderDecl(LOC((yyloc)), StaticContextConsts::empty_least);
    }
    break;

  case 54:
/* Line 661 of lalr1.cc  */
#line 1355 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)), true, true);
    }
    break;

  case 55:
/* Line 661 of lalr1.cc  */
#line 1360 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)), true, false);
    }
    break;

  case 56:
/* Line 661 of lalr1.cc  */
#line 1365 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)), false, true);
    }
    break;

  case 57:
/* Line 661 of lalr1.cc  */
#line 1370 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)), false, false);
    }
    break;

  case 60:
/* Line 661 of lalr1.cc  */
#line 1383 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yyval.node);
      error((yylocation_stack_[(3) - (2)]), "syntax error, \"import\" should be followed by either \"schema\" or \"module\"");
      YYERROR;
    }
    break;

  case 61:
/* Line 661 of lalr1.cc  */
#line 1393 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SchemaImport( LOC((yyloc)), NULL, SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL );
    }
    break;

  case 62:
/* Line 661 of lalr1.cc  */
#line 1398 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(4) - (3)].node)),
                            SYMTAB((yysemantic_stack_[(4) - (4)].sval)),
                            NULL);
    }
    break;

  case 63:
/* Line 661 of lalr1.cc  */
#line 1406 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            NULL,
                            SYMTAB((yysemantic_stack_[(5) - (3)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 64:
/* Line 661 of lalr1.cc  */
#line 1414 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(6) - (3)].node)),
                            SYMTAB((yysemantic_stack_[(6) - (4)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(6) - (6)].node)));
    }
    break;

  case 65:
/* Line 661 of lalr1.cc  */
#line 1425 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      URILiteralList *ull = new URILiteralList( LOC((yyloc)));
      ull->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
      (yyval.node) = ull;
    }
    break;

  case 66:
/* Line 661 of lalr1.cc  */
#line 1432 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      if ( URILiteralList *ull = dynamic_cast<URILiteralList*>((yysemantic_stack_[(3) - (1)].node)) )
        ull->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );

      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 67:
/* Line 661 of lalr1.cc  */
#line 1443 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      ERROR_IF_QNAME_NOT_NCNAME((yysemantic_stack_[(3) - (2)].expr), (yylocation_stack_[(3) - (2)]));
      (yyval.node) = new SchemaPrefix( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)));
    }
    break;

  case 68:
/* Line 661 of lalr1.cc  */
#line 1449 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SchemaPrefix( LOC((yyloc)), true );
    }
    break;

  case 69:
/* Line 661 of lalr1.cc  */
#line 1457 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL);

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(3) - (2)].sval)));
    }
    break;

  case 70:
/* Line 661 of lalr1.cc  */
#line 1464 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      ERROR_IF_QNAME_NOT_NCNAME((yysemantic_stack_[(6) - (4)].expr), (yylocation_stack_[(6) - (4)]));
      (yyval.node) = new ModuleImport(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(6) - (4)].expr)), SYMTAB((yysemantic_stack_[(6) - (6)].sval)), NULL);
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(6) - (2)].sval)));
    }
    break;

  case 71:
/* Line 661 of lalr1.cc  */
#line 1471 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)),
                            SYMTAB((yysemantic_stack_[(5) - (3)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(5) - (2)].sval)));
    }
    break;

  case 72:
/* Line 661 of lalr1.cc  */
#line 1480 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      ERROR_IF_QNAME_NOT_NCNAME((yysemantic_stack_[(8) - (4)].expr), (yylocation_stack_[(8) - (4)]));
      (yyval.node) = new ModuleImport(LOC((yyloc)),
                            static_cast<QName*>((yysemantic_stack_[(8) - (4)].expr)),
                            SYMTAB((yysemantic_stack_[(8) - (6)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(8) - (8)].node)));

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(8) - (2)].sval)));
    }
    break;

  case 73:
/* Line 661 of lalr1.cc  */
#line 1494 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      ERROR_IF_QNAME_NOT_NCNAME((yysemantic_stack_[(5) - (3)].expr), (yylocation_stack_[(5) - (3)]));
      (yyval.node) = new NamespaceDecl( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (3)].expr)), SYMTAB((yysemantic_stack_[(5) - (5)].sval)) );
    }
    break;

  case 74:
/* Line 661 of lalr1.cc  */
#line 1503 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DefaultNamespaceDecl(LOC((yyloc)),
                                    ParseConstants::ns_element_default,
                                    SYMTAB((yysemantic_stack_[(5) - (5)].sval)));
    }
    break;

  case 75:
/* Line 661 of lalr1.cc  */
#line 1510 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DefaultNamespaceDecl(LOC((yyloc)),
                                    ParseConstants::ns_function_default,
                                    SYMTAB((yysemantic_stack_[(5) - (5)].sval)));
    }
    break;

  case 76:
/* Line 661 of lalr1.cc  */
#line 1520 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      VFO_DeclList *vdl = new VFO_DeclList( LOC((yyloc)));
      vdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
      (yyval.node) = vdl;
    }
    break;

  case 77:
/* Line 661 of lalr1.cc  */
#line 1527 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      ((VFO_DeclList*)(yysemantic_stack_[(3) - (1)].node))->push_back( (yysemantic_stack_[(3) - (3)].node) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 78:
/* Line 661 of lalr1.cc  */
#line 1534 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration");
      YYERROR;
    }
    break;

  case 87:
/* Line 661 of lalr1.cc  */
#line 1557 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DecimalFormatNode(LOC((yyloc)), (yysemantic_stack_[(4) - (4)].vstrpair));
      delete (yysemantic_stack_[(4) - (4)].vstrpair);
    }
    break;

  case 88:
/* Line 661 of lalr1.cc  */
#line 1563 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DecimalFormatNode(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), (yysemantic_stack_[(4) - (4)].vstrpair));
      delete (yysemantic_stack_[(4) - (4)].vstrpair);
    }
    break;

  case 89:
/* Line 661 of lalr1.cc  */
#line 1572 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.vstrpair) = new vector<string_pair_t>();
      (yyval.vstrpair)->push_back( *(yysemantic_stack_[(1) - (1)].strpair) );
      delete (yysemantic_stack_[(1) - (1)].strpair);
    }
    break;

  case 90:
/* Line 661 of lalr1.cc  */
#line 1579 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yysemantic_stack_[(2) - (1)].vstrpair)->push_back( *(yysemantic_stack_[(2) - (2)].strpair) );
      delete (yysemantic_stack_[(2) - (2)].strpair);
      (yyval.vstrpair) = (yysemantic_stack_[(2) - (1)].vstrpair);
    }
    break;

  case 91:
/* Line 661 of lalr1.cc  */
#line 1589 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      StringLiteral *sl = static_cast<StringLiteral*>((yysemantic_stack_[(3) - (3)].expr));
      (yyval.strpair) = new string_pair_t( (yysemantic_stack_[(3) - (1)].strval), sl->get_strval().str() );
      delete sl;
    }
    break;

  case 92:
/* Line 661 of lalr1.cc  */
#line 1598 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "decimal-separator"; }
    break;

  case 93:
/* Line 661 of lalr1.cc  */
#line 1599 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "digit"; }
    break;

  case 94:
/* Line 661 of lalr1.cc  */
#line 1600 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "grouping-separator"; }
    break;

  case 95:
/* Line 661 of lalr1.cc  */
#line 1601 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "infinity"; }
    break;

  case 96:
/* Line 661 of lalr1.cc  */
#line 1602 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "minus-sign"; }
    break;

  case 97:
/* Line 661 of lalr1.cc  */
#line 1603 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "NaN"; }
    break;

  case 98:
/* Line 661 of lalr1.cc  */
#line 1604 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "pattern-separator"; }
    break;

  case 99:
/* Line 661 of lalr1.cc  */
#line 1605 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "percent"; }
    break;

  case 100:
/* Line 661 of lalr1.cc  */
#line 1606 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "per-mille"; }
    break;

  case 101:
/* Line 661 of lalr1.cc  */
#line 1607 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "zero-digit"; }
    break;

  case 102:
/* Line 661 of lalr1.cc  */
#line 1613 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new OptionDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), SYMTAB((yysemantic_stack_[(4) - (4)].sval)));



      if (static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr))->get_localname() == "enable")
      {
        zstring opt = SYMTAB((yysemantic_stack_[(4) - (4)].sval));
        if (opt.find(":") != zstring::npos)
          opt = opt.substr(opt.find(":")+1);
        if (opt == "common-language")
          driver.enableCommonLanguage();
      }
    }
    break;

  case 103:
/* Line 661 of lalr1.cc  */
#line 1632 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new FTOptionDecl( LOC((yyloc)), dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (3)].node)) );
    }
    break;

  case 104:
/* Line 661 of lalr1.cc  */
#line 1640 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(4) - (4)].node);
    }
    break;

  case 105:
/* Line 661 of lalr1.cc  */
#line 1648 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      CtxItemDecl* d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(3) - (3)].node));
      d->theType = (yysemantic_stack_[(3) - (2)].node);
      (yyval.node) = d;
    }
    break;

  case 106:
/* Line 661 of lalr1.cc  */
#line 1655 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 107:
/* Line 661 of lalr1.cc  */
#line 1663 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      CtxItemDecl* d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(1) - (1)].node));
      d->theIsExternal = false;
      (yyval.node) = d;
    }
    break;

  case 108:
/* Line 661 of lalr1.cc  */
#line 1670 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CtxItemDecl(LOC((yyloc)), NULL);
    }
    break;

  case 109:
/* Line 661 of lalr1.cc  */
#line 1675 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 110:
/* Line 661 of lalr1.cc  */
#line 1683 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CtxItemDecl(LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 111:
/* Line 661 of lalr1.cc  */
#line 1691 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(4) - (2)].varnametype)));

      (yyval.node) = new GlobalVarDecl(LOC((yyloc)),
                             nt->theName,
                             nt->theType,
                             (yysemantic_stack_[(4) - (4)].expr),
                             nt->get_annotations(),
                             false);

      static_cast<GlobalVarDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(4) - (1)].sval)));
    }
    break;

  case 112:
/* Line 661 of lalr1.cc  */
#line 1705 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(3) - (2)].varnametype)));

      (yyval.node) = new GlobalVarDecl(LOC((yyloc)),
                             nt->theName,
                             nt->theType,
                             NULL,
                             nt->get_annotations(),
                             true);

      static_cast<GlobalVarDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(3) - (1)].sval)));
    }
    break;

  case 113:
/* Line 661 of lalr1.cc  */
#line 1719 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(5) - (2)].varnametype)));

      (yyval.node) = new GlobalVarDecl(LOC((yyloc)),
                             nt->theName,
                             nt->theType,
                             (yysemantic_stack_[(5) - (5)].expr),
                             nt->get_annotations(),
                             true);

      static_cast<GlobalVarDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(5) - (1)].sval)));
    }
    break;

  case 114:
/* Line 661 of lalr1.cc  */
#line 1736 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)), NULL, NULL);
    }
    break;

  case 115:
/* Line 661 of lalr1.cc  */
#line 1741 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)),
                              dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (4)].node)),
                              NULL);
    }
    break;

  case 116:
/* Line 661 of lalr1.cc  */
#line 1749 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(4) - (4)].expr)),
                              NULL,
                              static_cast<AnnotationListParsenode*>((yysemantic_stack_[(4) - (1)].node)));
    }
    break;

  case 117:
/* Line 661 of lalr1.cc  */
#line 1757 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(5) - (4)].expr)),
                              dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (5)].node)),
                              static_cast<AnnotationListParsenode*>((yysemantic_stack_[(5) - (1)].node)));
    }
    break;

  case 118:
/* Line 661 of lalr1.cc  */
#line 1768 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AnnotationListParsenode(LOC((yyloc)), static_cast<AnnotationParsenode*>((yysemantic_stack_[(1) - (1)].node)));
    }
    break;

  case 119:
/* Line 661 of lalr1.cc  */
#line 1773 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      static_cast<AnnotationListParsenode*>((yysemantic_stack_[(2) - (1)].node))->push_back(static_cast<AnnotationParsenode*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 120:
/* Line 661 of lalr1.cc  */
#line 1782 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))), NULL);
    }
    break;

  case 121:
/* Line 661 of lalr1.cc  */
#line 1787 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)),
                                   new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (1)].sval))),
                                   static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 122:
/* Line 661 of lalr1.cc  */
#line 1794 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), true), NULL);
    }
    break;

  case 123:
/* Line 661 of lalr1.cc  */
#line 1799 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)),
                                   new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (1)].sval)), true),
                                   static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 124:
/* Line 661 of lalr1.cc  */
#line 1809 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AnnotationLiteralListParsenode(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr));
    }
    break;

  case 125:
/* Line 661 of lalr1.cc  */
#line 1814 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(3) - (1)].node))->push_back((yysemantic_stack_[(3) - (3)].expr));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 126:
/* Line 661 of lalr1.cc  */
#line 1823 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      static_cast<FunctionDecl*>((yysemantic_stack_[(2) - (2)].node))->setComment( SYMTAB((yysemantic_stack_[(2) - (1)].sval)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 127:
/* Line 661 of lalr1.cc  */
#line 1829 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      FunctionDecl* fdecl = static_cast<FunctionDecl*>((yysemantic_stack_[(3) - (3)].node));

      fdecl->setComment( SYMTAB((yysemantic_stack_[(3) - (1)].sval)) );

      fdecl->set_annotations(static_cast<AnnotationListParsenode*>((yysemantic_stack_[(3) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
    }
    break;

  case 130:
/* Line 661 of lalr1.cc  */
#line 1848 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      exprnode* body = (yysemantic_stack_[(4) - (4)].expr);
      if (body == NULL)
        body = new BlockBody(LOC((yylocation_stack_[(4) - (4)])));

      (yyval.node) = new FunctionDecl(LOC((yyloc)),
                            static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                            &* (yysemantic_stack_[(4) - (3)].fnsig)->theParams,
                            &* (yysemantic_stack_[(4) - (3)].fnsig)->theReturnType,
                            body,
                            false,
                            false);
      delete (yysemantic_stack_[(4) - (3)].fnsig);
    }
    break;

  case 131:
/* Line 661 of lalr1.cc  */
#line 1863 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new FunctionDecl(LOC ((yyloc)),
                            static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                            (yysemantic_stack_[(4) - (3)].fnsig)->theParams.getp(),
                            (yysemantic_stack_[(4) - (3)].fnsig)->theReturnType.getp(),
                            NULL,
                            false,
                            true);
      delete (yysemantic_stack_[(4) - (3)].fnsig);
    }
    break;

  case 132:
/* Line 661 of lalr1.cc  */
#line 1878 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      exprnode* body = (yysemantic_stack_[(5) - (5)].expr);
      if (body == NULL)
        body = new BlockBody(LOC((yylocation_stack_[(5) - (5)])));

      (yyval.node) = new FunctionDecl(LOC ((yyloc)),
                            static_cast<QName*>((yysemantic_stack_[(5) - (3)].expr)),
                            (yysemantic_stack_[(5) - (4)].fnsig)->theParams.getp(),
                            (yysemantic_stack_[(5) - (4)].fnsig)->theReturnType.getp(),
                            (yysemantic_stack_[(5) - (5)].expr),
                            true,
                            false);
      delete (yysemantic_stack_[(5) - (4)].fnsig);
    }
    break;

  case 133:
/* Line 661 of lalr1.cc  */
#line 1894 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new FunctionDecl(LOC((yyloc)),
                            static_cast<QName*>((yysemantic_stack_[(5) - (3)].expr)),
                            (yysemantic_stack_[(5) - (4)].fnsig)->theParams.getp(),
                            (yysemantic_stack_[(5) - (4)].fnsig)->theReturnType.getp(),
                            NULL,
                            true,
                            true);
      delete (yysemantic_stack_[(5) - (4)].fnsig);
    }
    break;

  case 134:
/* Line 661 of lalr1.cc  */
#line 1909 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(NULL);
    }
    break;

  case 135:
/* Line 661 of lalr1.cc  */
#line 1914 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (2)].node)));
    }
    break;

  case 136:
/* Line 661 of lalr1.cc  */
#line 1919 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(NULL, dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node)));
    }
    break;

  case 137:
/* Line 661 of lalr1.cc  */
#line 1924 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(dynamic_cast<ParamList*>((yysemantic_stack_[(5) - (2)].node)), dynamic_cast<SequenceType*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 138:
/* Line 661 of lalr1.cc  */
#line 1932 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      ParamList *pl = new ParamList( LOC((yyloc)) );
      pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = pl;
    }
    break;

  case 139:
/* Line 661 of lalr1.cc  */
#line 1939 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      if ( ParamList *pl = dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (1)].node)) )
        pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(3) - (3)].node)) );

      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 140:
/* Line 661 of lalr1.cc  */
#line 1950 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL);
    }
    break;

  case 141:
/* Line 661 of lalr1.cc  */
#line 1955 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)),
                     static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                     dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 142:
/* Line 661 of lalr1.cc  */
#line 1965 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)),
                              NULL,
                              NULL);

      static_cast<CollectionDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(3) - (1)].sval)));
    }
    break;

  case 143:
/* Line 661 of lalr1.cc  */
#line 1974 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(5) - (3)].expr)),
                              0,
                              static_cast<SequenceType*>((yysemantic_stack_[(5) - (5)].node)));

      static_cast<CollectionDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(5) - (1)].sval)));
    }
    break;

  case 144:
/* Line 661 of lalr1.cc  */
#line 1983 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                               static_cast<QName*>((yysemantic_stack_[(4) - (4)].expr)),
                               static_cast<AnnotationListParsenode*>((yysemantic_stack_[(4) - (2)].node)),
                               0);

      static_cast<CollectionDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(4) - (1)].sval)));
    }
    break;

  case 145:
/* Line 661 of lalr1.cc  */
#line 1992 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                               static_cast<QName*>((yysemantic_stack_[(6) - (4)].expr)),
                               static_cast<AnnotationListParsenode*>((yysemantic_stack_[(6) - (2)].node)),
                               static_cast<SequenceType*>((yysemantic_stack_[(6) - (6)].node)));

      static_cast<CollectionDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(6) - (1)].sval)));
    }
    break;

  case 146:
/* Line 661 of lalr1.cc  */
#line 2004 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL));
    }
    break;

  case 147:
/* Line 661 of lalr1.cc  */
#line 2008 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)),
                                                    (yysemantic_stack_[(2) - (1)].node),
                                                    dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node))));
    }
    break;

  case 148:
/* Line 661 of lalr1.cc  */
#line 2014 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL));
    }
    break;

  case 149:
/* Line 661 of lalr1.cc  */
#line 2018 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)),
                                                    (yysemantic_stack_[(2) - (1)].node),
                                                    dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node))));

    }
    break;

  case 150:
/* Line 661 of lalr1.cc  */
#line 2028 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AST_IndexDecl(LOC((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(8) - (3)].expr)),
                             (yysemantic_stack_[(8) - (6)].expr),
                             dynamic_cast<IndexKeyList*>((yysemantic_stack_[(8) - (8)].node)),
                             NULL);

      static_cast<AST_IndexDecl*>((yyval.node))->setComment( SYMTAB((yysemantic_stack_[(8) - (1)].sval)) );
    }
    break;

  case 151:
/* Line 661 of lalr1.cc  */
#line 2038 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AST_IndexDecl(LOC((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(9) - (4)].expr)),
                             (yysemantic_stack_[(9) - (7)].expr),
                             dynamic_cast<IndexKeyList*>((yysemantic_stack_[(9) - (9)].node)),
                             static_cast<AnnotationListParsenode*>((yysemantic_stack_[(9) - (2)].node)));

      static_cast<AST_IndexDecl*>((yyval.node))->setComment( SYMTAB((yysemantic_stack_[(9) - (1)].sval)) );
    }
    break;

  case 152:
/* Line 661 of lalr1.cc  */
#line 2051 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      IndexKeyList* keyList = new IndexKeyList(LOC((yyloc)));
      keyList->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = keyList;
    }
    break;

  case 153:
/* Line 661 of lalr1.cc  */
#line 2057 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      dynamic_cast<IndexKeyList*>((yysemantic_stack_[(3) - (1)].node))->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 154:
/* Line 661 of lalr1.cc  */
#line 2066 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL, NULL);
    }
    break;

  case 155:
/* Line 661 of lalr1.cc  */
#line 2071 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            dynamic_cast<SequenceType*>((yysemantic_stack_[(2) - (2)].node)),
                            NULL);
    }
    break;

  case 156:
/* Line 661 of lalr1.cc  */
#line 2078 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            NULL,
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
    }
    break;

  case 157:
/* Line 661 of lalr1.cc  */
#line 2085 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(3) - (1)].expr),
                            dynamic_cast<SequenceType*>((yysemantic_stack_[(3) - (2)].node)),
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 158:
/* Line 661 of lalr1.cc  */
#line 2097 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new ICCollSimpleCheck(LOC((yyloc)),
                                 static_cast<QName*>((yysemantic_stack_[(11) - (4)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(11) - (7)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(11) - (9)].expr)),
                                 (yysemantic_stack_[(11) - (11)].expr));
    }
    break;

  case 159:
/* Line 661 of lalr1.cc  */
#line 2107 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new ICCollUniqueKeyCheck(LOC((yyloc)),
                                    static_cast<QName*>((yysemantic_stack_[(14) - (4)].expr)),
                                    static_cast<QName*>((yysemantic_stack_[(14) - (7)].expr)),
                                    static_cast<QName*>((yysemantic_stack_[(14) - (10)].expr)),
                                    (yysemantic_stack_[(14) - (14)].expr));
    }
    break;

  case 160:
/* Line 661 of lalr1.cc  */
#line 2117 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new ICCollForeachNode(LOC((yyloc)),
                                 static_cast<QName*>((yysemantic_stack_[(13) - (4)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(13) - (7)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(13) - (11)].expr)),
                                 (yysemantic_stack_[(13) - (13)].expr));
    }
    break;

  case 161:
/* Line 661 of lalr1.cc  */
#line 2128 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
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

  case 162:
/* Line 661 of lalr1.cc  */
#line 2144 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
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

  case 163:
/* Line 661 of lalr1.cc  */
#line 2164 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 164:
/* Line 661 of lalr1.cc  */
#line 2168 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 165:
/* Line 661 of lalr1.cc  */
#line 2172 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = NULL;
    }
    break;

  case 166:
/* Line 661 of lalr1.cc  */
#line 2180 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 167:
/* Line 661 of lalr1.cc  */
#line 2184 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 168:
/* Line 661 of lalr1.cc  */
#line 2188 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = NULL;
    }
    break;

  case 169:
/* Line 661 of lalr1.cc  */
#line 2196 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 170:
/* Line 661 of lalr1.cc  */
#line 2201 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      BlockBody* blk = static_cast<BlockBody*>((yysemantic_stack_[(2) - (1)].expr));

      blk->add((yysemantic_stack_[(2) - (2)].expr));

      (yyval.expr) = blk;
    }
    break;

  case 171:
/* Line 661 of lalr1.cc  */
#line 2213 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      BlockBody* blk = new BlockBody(LOC((yyloc)));
      blk->add((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = blk;
    }
    break;

  case 172:
/* Line 661 of lalr1.cc  */
#line 2220 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      BlockBody* blk = static_cast<BlockBody*>((yysemantic_stack_[(2) - (1)].expr));

      blk->add((yysemantic_stack_[(2) - (2)].expr));

      (yyval.expr) = blk;
    }
    break;

  case 173:
/* Line 661 of lalr1.cc  */
#line 2230 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(4) - (1)].expr);
      (yyval.expr) = (yysemantic_stack_[(4) - (2)].expr);
      (yyval.expr) = (yysemantic_stack_[(4) - (4)].expr);
      error((yylocation_stack_[(4) - (3)]), "syntax error, unexpected statement (missing semicolon \";\" between statements?)");
      delete (yysemantic_stack_[(4) - (1)].expr);
      delete (yysemantic_stack_[(4) - (2)].expr);
      delete (yysemantic_stack_[(4) - (4)].expr);
      YYERROR;
    }
    break;

  case 187:
/* Line 661 of lalr1.cc  */
#line 2263 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 188:
/* Line 661 of lalr1.cc  */
#line 2271 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      BlockBody* block = dynamic_cast<BlockBody*>((yysemantic_stack_[(3) - (2)].expr));


      if ((yysemantic_stack_[(3) - (2)].expr) == NULL || (block != NULL && block->isEmpty()))
      {

        driver.addCommonLanguageWarning((yylocation_stack_[(3) - (1)]), ZED(ZWST0009_EMPTY_OBJECT));
        (yyval.expr) = new JSONDirectObjectConstructor(LOC((yyloc)));
      }
      else

      if ((yysemantic_stack_[(3) - (2)].expr) == NULL)
      {
        (yyval.expr) = new BlockBody(LOC((yyloc)));
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

  case 189:
/* Line 661 of lalr1.cc  */
#line 2303 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 190:
/* Line 661 of lalr1.cc  */
#line 2311 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    }
    break;

  case 191:
/* Line 661 of lalr1.cc  */
#line 2319 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      VarDeclStmt* vdecl = static_cast<VarDeclStmt*>((yysemantic_stack_[(3) - (1)].expr));
      vdecl->add((yysemantic_stack_[(3) - (3)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 192:
/* Line 661 of lalr1.cc  */
#line 2326 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      VarDeclStmt* vdecl = new VarDeclStmt(LOC((yyloc)), NULL);
      vdecl->add((yysemantic_stack_[(2) - (2)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 193:
/* Line 661 of lalr1.cc  */
#line 2333 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      VarDeclStmt* vdecl = new VarDeclStmt(LOC((yyloc)),
                                           static_cast<AnnotationListParsenode*>((yysemantic_stack_[(3) - (1)].node)));
      vdecl->add((yysemantic_stack_[(3) - (3)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 194:
/* Line 661 of lalr1.cc  */
#line 2344 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      LocalVarDecl* vd = new LocalVarDecl(LOC((yyloc)),
                                          static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)),
                                          NULL,
                                          NULL,
                                          NULL);
      (yyval.node) = vd;
    }
    break;

  case 195:
/* Line 661 of lalr1.cc  */
#line 2353 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      LocalVarDecl* vd = new LocalVarDecl(LOC((yyloc)),
                                          static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                                          dynamic_cast<SequenceType*>((yysemantic_stack_[(3) - (3)].node)),
                                          NULL,
                                          NULL);
      (yyval.node) = vd;
    }
    break;

  case 196:
/* Line 661 of lalr1.cc  */
#line 2362 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      LocalVarDecl* vd = new LocalVarDecl(LOC((yyloc)),
                                          static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                                          NULL,
                                          (yysemantic_stack_[(4) - (4)].expr),
                                          NULL);
      (yyval.node) = vd;
    }
    break;

  case 197:
/* Line 661 of lalr1.cc  */
#line 2371 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      LocalVarDecl* vd = new LocalVarDecl(LOC((yyloc)),
                                          static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                                          dynamic_cast<SequenceType*>((yysemantic_stack_[(5) - (3)].node)),
                                          (yysemantic_stack_[(5) - (5)].expr),
                                          NULL);
      (yyval.node) = vd;
    }
    break;

  case 198:
/* Line 661 of lalr1.cc  */
#line 2384 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new AssignExpr(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)), (yysemantic_stack_[(5) - (4)].expr));
    }
    break;

  case 199:
/* Line 661 of lalr1.cc  */
#line 2392 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new ApplyExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr));
    }
    break;

  case 200:
/* Line 661 of lalr1.cc  */
#line 2400 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new ExitExpr(LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr));
    }
    break;

  case 201:
/* Line 661 of lalr1.cc  */
#line 2408 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
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

  case 202:
/* Line 661 of lalr1.cc  */
#line 2423 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement(LOC((yyloc)), FlowCtlStatement::BREAK);
    }
    break;

  case 203:
/* Line 661 of lalr1.cc  */
#line 2428 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement( LOC((yyloc)), FlowCtlStatement::CONTINUE );
    }
    break;

  case 204:
/* Line 661 of lalr1.cc  */
#line 2436 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
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

  case 205:
/* Line 661 of lalr1.cc  */
#line 2450 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
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

  case 206:
/* Line 661 of lalr1.cc  */
#line 2467 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
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

  case 207:
/* Line 661 of lalr1.cc  */
#line 2492 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new TryExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 208:
/* Line 661 of lalr1.cc  */
#line 2500 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      CatchListExpr* cle = new CatchListExpr( LOC((yyloc)) );
      cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)) );
      (yyval.expr) = cle;
    }
    break;

  case 209:
/* Line 661 of lalr1.cc  */
#line 2507 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
      if ( cle )
        cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)) );
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    }
    break;

  case 210:
/* Line 661 of lalr1.cc  */
#line 2518 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)), *(yysemantic_stack_[(3) - (2)].name_test_list), (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 211:
/* Line 661 of lalr1.cc  */
#line 2527 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new BlockBody(LOC((yyloc)));
    }
    break;

  case 212:
/* Line 661 of lalr1.cc  */
#line 2535 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 213:
/* Line 661 of lalr1.cc  */
#line 2540 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
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

  case 214:
/* Line 661 of lalr1.cc  */
#line 2553 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (1)].expr);
      (yyval.expr) = (yysemantic_stack_[(3) - (3)].expr);



      if (dynamic_cast<PathExpr*>((yysemantic_stack_[(3) - (1)].expr)) == NULL)
        error((yylocation_stack_[(3) - (2)]), "syntax error, unexpected expression (missing comma \",\" between expressions?)");
      delete (yysemantic_stack_[(3) - (1)].expr);
      delete (yysemantic_stack_[(3) - (3)].expr);
      YYERROR;
    }
    break;

  case 233:
/* Line 661 of lalr1.cc  */
#line 2600 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
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

  case 234:
/* Line 661 of lalr1.cc  */
#line 2614 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new ReturnExpr( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr) );
    }
    break;

  case 236:
/* Line 661 of lalr1.cc  */
#line 2626 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
    }
    break;

  case 237:
/* Line 661 of lalr1.cc  */
#line 2633 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.strval) = parser::the_sliding;
    }
    break;

  case 238:
/* Line 661 of lalr1.cc  */
#line 2638 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.strval) = parser::the_tumbling;
    }
    break;

  case 239:
/* Line 661 of lalr1.cc  */
#line 2646 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.strval) = parser::the_start;
    }
    break;

  case 240:
/* Line 661 of lalr1.cc  */
#line 2651 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.strval) = parser::the_end;
    }
    break;

  case 241:
/* Line 661 of lalr1.cc  */
#line 2656 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
    (yyval.strval) = parser::the_only_end;
  }
    break;

  case 242:
/* Line 661 of lalr1.cc  */
#line 2664 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new FLWORWinCond(LOC((yyloc)),
                            dynamic_cast<WindowVars*>((yysemantic_stack_[(4) - (2)].node)),
                            (yysemantic_stack_[(4) - (4)].expr),
                            (yysemantic_stack_[(4) - (1)].strval) == parser::the_start,
                            (yysemantic_stack_[(4) - (1)].strval) == parser::the_only_end);
    }
    break;

  case 243:
/* Line 661 of lalr1.cc  */
#line 2673 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new FLWORWinCond(LOC((yyloc)),
                            NULL,
                            (yysemantic_stack_[(3) - (3)].expr),
                            (yysemantic_stack_[(3) - (1)].strval) == parser::the_start,
                            (yysemantic_stack_[(3) - (1)].strval) == parser::the_only_end);
    }
    break;

  case 244:
/* Line 661 of lalr1.cc  */
#line 2685 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
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
/* Line 661 of lalr1.cc  */
#line 2695 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
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
/* Line 661 of lalr1.cc  */
#line 2708 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CountClause(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 255:
/* Line 661 of lalr1.cc  */
#line 2732 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      FLWORClauseList *fcl = new FLWORClauseList( LOC((yyloc)) );
      fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = fcl;
    }
    break;

  case 256:
/* Line 661 of lalr1.cc  */
#line 2739 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      FLWORClauseList *fcl = dynamic_cast<FLWORClauseList*>((yysemantic_stack_[(2) - (1)].node));
      fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = fcl;
    }
    break;

  case 257:
/* Line 661 of lalr1.cc  */
#line 2749 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new ForClause(LOC((yyloc)), dynamic_cast<VarInDeclList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 258:
/* Line 661 of lalr1.cc  */
#line 2754 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      error((yylocation_stack_[(3) - (2)]), "syntax error, unexpected qualified name \""
          + static_cast<VarInDeclList*>((yysemantic_stack_[(3) - (3)].node))->operator[](0)->get_var_name()->get_qname().str() + "\" (missing \"$\" sign?)");
      delete (yysemantic_stack_[(3) - (3)].node);
      YYERROR;
    }
    break;

  case 259:
/* Line 661 of lalr1.cc  */
#line 2763 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      error((yylocation_stack_[(3) - (2)]), "syntax error, unexpected qualified name \""
          + static_cast<VarInDeclList*>((yysemantic_stack_[(3) - (3)].node))->operator[](0)->get_var_name()->get_qname().str() + "\" (missing \"$\" sign?)");
      delete (yysemantic_stack_[(3) - (3)].node);
      YYERROR;
    }
    break;

  case 260:
/* Line 661 of lalr1.cc  */
#line 2772 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = NULL;
      error((yylocation_stack_[(2) - (2)]), "");
      YYERROR;
    }
    break;

  case 262:
/* Line 661 of lalr1.cc  */
#line 2786 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {

    }
    break;

  case 263:
/* Line 661 of lalr1.cc  */
#line 2794 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      VarInDeclList* vdl = new VarInDeclList( LOC((yyloc)) );
      vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = vdl;
    }
    break;

  case 264:
/* Line 661 of lalr1.cc  */
#line 2801 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      if ( VarInDeclList* vdl = dynamic_cast<VarInDeclList*>((yysemantic_stack_[(4) - (1)].node)) )
        vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
      (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
    }
    break;

  case 265:
/* Line 661 of lalr1.cc  */
#line 2809 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
      error((yylocation_stack_[(3) - (3)]), "syntax error, unexpected QName \""
          + static_cast<VarInDecl*>((yysemantic_stack_[(3) - (3)].node))->get_var_name()->get_qname().str() + "\" (missing \"$\" sign?)");
      delete (yysemantic_stack_[(3) - (1)].node);
      YYERROR;
    }
    break;

  case 266:
/* Line 661 of lalr1.cc  */
#line 2821 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
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

  case 267:
/* Line 661 of lalr1.cc  */
#line 2831 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
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

  case 268:
/* Line 661 of lalr1.cc  */
#line 2841 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
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

  case 269:
/* Line 661 of lalr1.cc  */
#line 2851 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
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

  case 270:
/* Line 661 of lalr1.cc  */
#line 2861 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
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

  case 271:
/* Line 661 of lalr1.cc  */
#line 2871 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
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

  case 272:
/* Line 661 of lalr1.cc  */
#line 2881 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
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

  case 273:
/* Line 661 of lalr1.cc  */
#line 2891 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
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

  case 274:
/* Line 661 of lalr1.cc  */
#line 2902 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                         NULL,NULL,
                         dynamic_cast<FTScoreVar*>((yysemantic_stack_[(4) - (2)].node)),
                         (yysemantic_stack_[(4) - (4)].expr),
                         false);
    }
    break;

  case 275:
/* Line 661 of lalr1.cc  */
#line 2911 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
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

  case 276:
/* Line 661 of lalr1.cc  */
#line 2921 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
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

  case 277:
/* Line 661 of lalr1.cc  */
#line 2931 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
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

  case 278:
/* Line 661 of lalr1.cc  */
#line 2947 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new PositionalVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 279:
/* Line 661 of lalr1.cc  */
#line 2956 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new FTScoreVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 280:
/* Line 661 of lalr1.cc  */
#line 2965 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new LetClause( LOC((yyloc)), dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(2) - (2)].node)) );
        }
    break;

  case 281:
/* Line 661 of lalr1.cc  */
#line 2973 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            VarGetsDeclList *vgdl = new VarGetsDeclList( LOC((yyloc)) );
            vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = vgdl;
        }
    break;

  case 282:
/* Line 661 of lalr1.cc  */
#line 2979 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            if( VarGetsDeclList *vgdl = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(3) - (1)].node)) )
                vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 283:
/* Line 661 of lalr1.cc  */
#line 2991 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                           NULL,
                           NULL,
                           (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 284:
/* Line 661 of lalr1.cc  */
#line 2999 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                           dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (3)].node)),
                           NULL,
                           (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 285:
/* Line 661 of lalr1.cc  */
#line 3009 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(3) - (1)].node))->get_var_name(),
                           NULL,
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(3) - (1)].node)),
                           (yysemantic_stack_[(3) - (3)].expr));
     }
    break;

  case 286:
/* Line 661 of lalr1.cc  */
#line 3017 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                           dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (3)].node)),
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(6) - (4)].node)),
                           (yysemantic_stack_[(6) - (6)].expr));
    }
    break;

  case 287:
/* Line 661 of lalr1.cc  */
#line 3029 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                             NULL, (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 288:
/* Line 661 of lalr1.cc  */
#line 3035 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                             dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (3)].node)),
                             (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 290:
/* Line 661 of lalr1.cc  */
#line 3048 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL, NULL);
    }
    break;

  case 291:
/* Line 661 of lalr1.cc  */
#line 3052 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_curr(static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)));
    }
    break;

  case 292:
/* Line 661 of lalr1.cc  */
#line 3060 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), dynamic_cast<PositionalVar*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL, NULL);
    }
    break;

  case 293:
/* Line 661 of lalr1.cc  */
#line 3064 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_posvar(dynamic_cast<PositionalVar*>((yysemantic_stack_[(2) - (1)].node)));
    }
    break;

  case 295:
/* Line 661 of lalr1.cc  */
#line 3073 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), static_cast<QName*>((yysemantic_stack_[(6) - (6)].expr)));
    }
    break;

  case 296:
/* Line 661 of lalr1.cc  */
#line 3077 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 297:
/* Line 661 of lalr1.cc  */
#line 3081 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)), NULL);
    }
    break;

  case 298:
/* Line 661 of lalr1.cc  */
#line 3091 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new WhereClause(LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 299:
/* Line 661 of lalr1.cc  */
#line 3099 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new GroupByClause(LOC((yyloc)), dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 300:
/* Line 661 of lalr1.cc  */
#line 3106 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      GroupSpecList* gsl = new GroupSpecList(LOC((yyloc)));
      gsl->push_back(static_cast<GroupSpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = gsl;
    }
    break;

  case 301:
/* Line 661 of lalr1.cc  */
#line 3112 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      GroupSpecList* gsl = static_cast<GroupSpecList*>((yysemantic_stack_[(3) - (1)].node));
      gsl->push_back(static_cast<GroupSpec*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = gsl;
    }
    break;

  case 302:
/* Line 661 of lalr1.cc  */
#line 3122 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)), NULL, (yysemantic_stack_[(4) - (4)].expr), NULL);
    }
    break;

  case 303:
/* Line 661 of lalr1.cc  */
#line 3126 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                         static_cast<SequenceType*>((yysemantic_stack_[(5) - (3)].node)),
                         (yysemantic_stack_[(5) - (5)].expr),
                         NULL);
    }
    break;

  case 304:
/* Line 661 of lalr1.cc  */
#line 3134 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                         static_cast<SequenceType*>((yysemantic_stack_[(6) - (3)].node)),
                         (yysemantic_stack_[(6) - (5)].expr),
                         static_cast<GroupCollationSpec*>((yysemantic_stack_[(6) - (6)].node)));
    }
    break;

  case 305:
/* Line 661 of lalr1.cc  */
#line 3142 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                         NULL,
                         (yysemantic_stack_[(5) - (4)].expr),
                         static_cast<GroupCollationSpec*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 306:
/* Line 661 of lalr1.cc  */
#line 3150 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      VarRef* varRef = dynamic_cast<VarRef*>((yysemantic_stack_[(1) - (1)].expr));
      if (varRef != NULL)
        (yyval.node) = new GroupSpec(LOC((yyloc)), varRef, NULL, NULL, NULL);
      else
        (yyval.node) = new GroupSpec(LOC((yyloc)), NULL, NULL, (yysemantic_stack_[(1) - (1)].expr), NULL);
    }
    break;

  case 307:
/* Line 661 of lalr1.cc  */
#line 3158 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      VarRef* varRef = dynamic_cast<VarRef*>((yysemantic_stack_[(2) - (1)].expr));
      if (varRef != NULL)
        (yyval.node) = new GroupSpec(LOC((yyloc)), varRef, NULL, NULL, static_cast<GroupCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
      else
        (yyval.node) = new GroupSpec(LOC((yyloc)), NULL, NULL, (yysemantic_stack_[(2) - (1)].expr), static_cast<GroupCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
    }
    break;

  case 308:
/* Line 661 of lalr1.cc  */
#line 3170 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new GroupCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
    }
    break;

  case 309:
/* Line 661 of lalr1.cc  */
#line 3178 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 310:
/* Line 661 of lalr1.cc  */
#line 3184 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(4) - (4)].node)), true
            );
        }
    break;

  case 311:
/* Line 661 of lalr1.cc  */
#line 3194 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            OrderSpecList *osl = new OrderSpecList( LOC((yyloc)) );
            osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = osl;
        }
    break;

  case 312:
/* Line 661 of lalr1.cc  */
#line 3200 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            if ( OrderSpecList* osl = dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (1)].node)) )
                osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 313:
/* Line 661 of lalr1.cc  */
#line 3210 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderSpec( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL );
        }
    break;

  case 314:
/* Line 661 of lalr1.cc  */
#line 3214 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderSpec(
                LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<OrderModifierPN*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 315:
/* Line 661 of lalr1.cc  */
#line 3224 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL
            );
        }
    break;

  case 316:
/* Line 661 of lalr1.cc  */
#line 3230 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 317:
/* Line 661 of lalr1.cc  */
#line 3236 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, NULL, dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 318:
/* Line 661 of lalr1.cc  */
#line 3242 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (2)].node)),
                NULL
            );
        }
    break;

  case 319:
/* Line 661 of lalr1.cc  */
#line 3251 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
                NULL,
                dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 320:
/* Line 661 of lalr1.cc  */
#line 3260 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                NULL,
                dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 321:
/* Line 661 of lalr1.cc  */
#line 3269 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(3) - (1)].node)),
                dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 322:
/* Line 661 of lalr1.cc  */
#line 3282 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_ascending );
        }
    break;

  case 323:
/* Line 661 of lalr1.cc  */
#line 3286 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_descending );
        }
    break;

  case 324:
/* Line 661 of lalr1.cc  */
#line 3294 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_greatest
            );
        }
    break;

  case 325:
/* Line 661 of lalr1.cc  */
#line 3300 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_least
            );
        }
    break;

  case 326:
/* Line 661 of lalr1.cc  */
#line 3310 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 327:
/* Line 661 of lalr1.cc  */
#line 3318 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new QuantifiedExpr(
                LOC((yyloc)),
                ParseConstants::quant_some,
                dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(5) - (3)].node)),
                (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 328:
/* Line 661 of lalr1.cc  */
#line 3327 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new QuantifiedExpr(
                LOC((yyloc)),
                ParseConstants::quant_every,
                dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(5) - (3)].node)),
                (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 329:
/* Line 661 of lalr1.cc  */
#line 3340 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      QVarInDeclList *qvidl = new QVarInDeclList( LOC((yyloc)) );
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = qvidl;

    }
    break;

  case 330:
/* Line 661 of lalr1.cc  */
#line 3347 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      QVarInDeclList *qvidl = dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
      (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
    }
    break;

  case 331:
/* Line 661 of lalr1.cc  */
#line 3359 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 332:
/* Line 661 of lalr1.cc  */
#line 3363 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                          dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 333:
/* Line 661 of lalr1.cc  */
#line 3375 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new SwitchExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(8) - (5)].node)), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 334:
/* Line 661 of lalr1.cc  */
#line 3382 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = new SwitchCaseClauseList(LOC((yyloc)));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = scc_list_p;
    }
    break;

  case 335:
/* Line 661 of lalr1.cc  */
#line 3388 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 336:
/* Line 661 of lalr1.cc  */
#line 3397 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SwitchCaseClause(LOC((yyloc)), dynamic_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 337:
/* Line 661 of lalr1.cc  */
#line 3404 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = new SwitchCaseOperandList(LOC((yyloc)));
      sco_list_p->push_back((yysemantic_stack_[(2) - (2)].expr));
      (yyval.node) = sco_list_p;
    }
    break;

  case 338:
/* Line 661 of lalr1.cc  */
#line 3410 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = static_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node));
      sco_list_p->push_back((yysemantic_stack_[(3) - (3)].expr));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 339:
/* Line 661 of lalr1.cc  */
#line 3421 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new SwitchExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(8) - (5)].node)), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 340:
/* Line 661 of lalr1.cc  */
#line 3428 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = new SwitchCaseClauseList(LOC((yyloc)));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = scc_list_p;
    }
    break;

  case 341:
/* Line 661 of lalr1.cc  */
#line 3434 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 342:
/* Line 661 of lalr1.cc  */
#line 3443 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SwitchCaseClause(LOC((yyloc)), dynamic_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 343:
/* Line 661 of lalr1.cc  */
#line 3452 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC((yyloc)),
                              (yysemantic_stack_[(8) - (3)].expr),
                              static_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
                              (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 344:
/* Line 661 of lalr1.cc  */
#line 3459 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
                              (yysemantic_stack_[(10) - (3)].expr),
                              static_cast<CaseClauseList*>((yysemantic_stack_[(10) - (5)].node)),
                              static_cast<QName*>((yysemantic_stack_[(10) - (8)].expr)),
                              (yysemantic_stack_[(10) - (10)].expr));
    }
    break;

  case 345:
/* Line 661 of lalr1.cc  */
#line 3470 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC((yyloc)),
                              (yysemantic_stack_[(8) - (3)].expr),
                              static_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
                              (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 346:
/* Line 661 of lalr1.cc  */
#line 3477 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
                              (yysemantic_stack_[(10) - (3)].expr),
                              static_cast<CaseClauseList*>((yysemantic_stack_[(10) - (5)].node)),
                              static_cast<QName*>((yysemantic_stack_[(10) - (8)].expr)),
                              (yysemantic_stack_[(10) - (10)].expr));
    }
    break;

  case 347:
/* Line 661 of lalr1.cc  */
#line 3489 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
      cc_list_p->push_back(static_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = cc_list_p;
    }
    break;

  case 348:
/* Line 661 of lalr1.cc  */
#line 3495 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      cc_list_p->push_back(static_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 349:
/* Line 661 of lalr1.cc  */
#line 3507 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<SequenceTypeList*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 350:
/* Line 661 of lalr1.cc  */
#line 3513 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                          static_cast<SequenceTypeList*>((yysemantic_stack_[(7) - (5)].node)),
                          (yysemantic_stack_[(7) - (7)].expr));
     }
    break;

  case 351:
/* Line 661 of lalr1.cc  */
#line 3524 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
      cc_list_p->push_back(static_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = cc_list_p;
    }
    break;

  case 352:
/* Line 661 of lalr1.cc  */
#line 3530 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      CaseClauseList* cc_list_p = static_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      cc_list_p->push_back(static_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 353:
/* Line 661 of lalr1.cc  */
#line 3541 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<SequenceTypeList*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 354:
/* Line 661 of lalr1.cc  */
#line 3547 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                          static_cast<SequenceTypeList*>((yysemantic_stack_[(7) - (5)].node)),
                          (yysemantic_stack_[(7) - (7)].expr));
     }
    break;

  case 355:
/* Line 661 of lalr1.cc  */
#line 3558 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      SequenceTypeList* seqList = new SequenceTypeList(LOC((yyloc)));
      seqList->push_back(static_cast<SequenceType*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = seqList;
    }
    break;

  case 356:
/* Line 661 of lalr1.cc  */
#line 3564 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      SequenceTypeList* seqList = static_cast<SequenceTypeList*>((yysemantic_stack_[(3) - (1)].node));
      seqList->push_back(static_cast<SequenceType*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 357:
/* Line 661 of lalr1.cc  */
#line 3575 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new IfExpr(LOC ((yyloc)), (yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (6)].expr), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 358:
/* Line 661 of lalr1.cc  */
#line 3584 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 359:
/* Line 661 of lalr1.cc  */
#line 3588 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new OrExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
    }
    break;

  case 360:
/* Line 661 of lalr1.cc  */
#line 3602 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 361:
/* Line 661 of lalr1.cc  */
#line 3612 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new AndExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 362:
/* Line 661 of lalr1.cc  */
#line 3622 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 363:
/* Line 661 of lalr1.cc  */
#line 3626 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new ComparisonExpr(
              LOC((yyloc)),
              new ValueComp( LOC((yyloc)), ParseConstants::op_val_not ),
              (yysemantic_stack_[(2) - (2)].expr),
              NULL
          );
        }
    break;

  case 364:
/* Line 661 of lalr1.cc  */
#line 3641 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 365:
/* Line 661 of lalr1.cc  */
#line 3645 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {

            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                dynamic_cast<ValueComp*>((yysemantic_stack_[(3) - (2)].node)),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 366:
/* Line 661 of lalr1.cc  */
#line 3655 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {

            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)), dynamic_cast<NodeComp*>((yysemantic_stack_[(3) - (2)].node)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 367:
/* Line 661 of lalr1.cc  */
#line 3662 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_eq ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 368:
/* Line 661 of lalr1.cc  */
#line 3671 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_ne ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 369:
/* Line 661 of lalr1.cc  */
#line 3680 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {




            driver.getJsoniqLexer()->interpretAsLessThan();

        }
    break;

  case 370:
/* Line 661 of lalr1.cc  */
#line 3689 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_lt ),
                (yysemantic_stack_[(4) - (1)].expr),
                (yysemantic_stack_[(4) - (4)].expr)
            );
        }
    break;

  case 371:
/* Line 661 of lalr1.cc  */
#line 3698 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_le ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 372:
/* Line 661 of lalr1.cc  */
#line 3707 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_gt ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 373:
/* Line 661 of lalr1.cc  */
#line 3716 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_ge ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 374:
/* Line 661 of lalr1.cc  */
#line 3729 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 375:
/* Line 661 of lalr1.cc  */
#line 3733 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new FTContainsExpr(
                LOC((yyloc)),
                (yysemantic_stack_[(5) - (1)].expr),
                dynamic_cast<FTSelection*>((yysemantic_stack_[(5) - (4)].node)),
                dynamic_cast<FTIgnoreOption*>((yysemantic_stack_[(5) - (5)].node))
            );
        }
    break;

  case 376:
/* Line 661 of lalr1.cc  */
#line 3745 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 377:
/* Line 661 of lalr1.cc  */
#line 3749 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new StringConcatExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
        }
    break;

  case 378:
/* Line 661 of lalr1.cc  */
#line 3756 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 379:
/* Line 661 of lalr1.cc  */
#line 3760 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 380:
/* Line 661 of lalr1.cc  */
#line 3767 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 381:
/* Line 661 of lalr1.cc  */
#line 3771 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new RangeExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 382:
/* Line 661 of lalr1.cc  */
#line 3780 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 383:
/* Line 661 of lalr1.cc  */
#line 3784 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_plus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 384:
/* Line 661 of lalr1.cc  */
#line 3788 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_minus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 385:
/* Line 661 of lalr1.cc  */
#line 3796 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 386:
/* Line 661 of lalr1.cc  */
#line 3800 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mul, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 387:
/* Line 661 of lalr1.cc  */
#line 3806 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_div, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 388:
/* Line 661 of lalr1.cc  */
#line 3812 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_idiv, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 389:
/* Line 661 of lalr1.cc  */
#line 3818 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mod, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 390:
/* Line 661 of lalr1.cc  */
#line 3828 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 391:
/* Line 661 of lalr1.cc  */
#line 3832 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 392:
/* Line 661 of lalr1.cc  */
#line 3836 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 393:
/* Line 661 of lalr1.cc  */
#line 3844 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 394:
/* Line 661 of lalr1.cc  */
#line 3848 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_intersect, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 395:
/* Line 661 of lalr1.cc  */
#line 3854 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_except, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 396:
/* Line 661 of lalr1.cc  */
#line 3864 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 397:
/* Line 661 of lalr1.cc  */
#line 3868 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InstanceofExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 398:
/* Line 661 of lalr1.cc  */
#line 3878 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 399:
/* Line 661 of lalr1.cc  */
#line 3882 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new TreatExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 400:
/* Line 661 of lalr1.cc  */
#line 3892 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 401:
/* Line 661 of lalr1.cc  */
#line 3896 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new CastableExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 402:
/* Line 661 of lalr1.cc  */
#line 3906 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 403:
/* Line 661 of lalr1.cc  */
#line 3910 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new CastExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 404:
/* Line 661 of lalr1.cc  */
#line 3920 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SingleType(LOC((yyloc)), dynamic_cast<SimpleType*>((yysemantic_stack_[(1) - (1)].node)), false);
    }
    break;

  case 405:
/* Line 661 of lalr1.cc  */
#line 3924 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SingleType(LOC((yyloc)), dynamic_cast<SimpleType*>((yysemantic_stack_[(2) - (1)].node)), true);
    }
    break;

  case 406:
/* Line 661 of lalr1.cc  */
#line 3933 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 407:
/* Line 661 of lalr1.cc  */
#line 3937 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new UnaryExpr( LOC((yyloc)), dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 408:
/* Line 661 of lalr1.cc  */
#line 3945 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), true );
        }
    break;

  case 409:
/* Line 661 of lalr1.cc  */
#line 3949 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), false );
        }
    break;

  case 410:
/* Line 661 of lalr1.cc  */
#line 3953 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 411:
/* Line 661 of lalr1.cc  */
#line 3957 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            if ( SignList *sl = dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)) )
                sl->negate();
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 415:
/* Line 661 of lalr1.cc  */
#line 3973 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
      }
    break;

  case 416:
/* Line 661 of lalr1.cc  */
#line 3978 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.expr) = new SimpleMapExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
      }
    break;

  case 417:
/* Line 661 of lalr1.cc  */
#line 3986 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_eq );
        }
    break;

  case 418:
/* Line 661 of lalr1.cc  */
#line 3990 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ne );
        }
    break;

  case 419:
/* Line 661 of lalr1.cc  */
#line 3994 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_lt );
        }
    break;

  case 420:
/* Line 661 of lalr1.cc  */
#line 3998 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_le );
        }
    break;

  case 421:
/* Line 661 of lalr1.cc  */
#line 4002 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_gt );
        }
    break;

  case 422:
/* Line 661 of lalr1.cc  */
#line 4006 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ge );
        }
    break;

  case 423:
/* Line 661 of lalr1.cc  */
#line 4014 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_is );
        }
    break;

  case 424:
/* Line 661 of lalr1.cc  */
#line 4018 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_precedes );
        }
    break;

  case 425:
/* Line 661 of lalr1.cc  */
#line 4022 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_follows );
        }
    break;

  case 426:
/* Line 661 of lalr1.cc  */
#line 4030 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 427:
/* Line 661 of lalr1.cc  */
#line 4034 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "lax", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 428:
/* Line 661 of lalr1.cc  */
#line 4038 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 429:
/* Line 661 of lalr1.cc  */
#line 4042 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ValidateExpr(
                LOC((yyloc)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (3)].node))->get_name(), (yysemantic_stack_[(6) - (5)].expr)
            );
            delete (yysemantic_stack_[(6) - (3)].node);
        }
    break;

  case 430:
/* Line 661 of lalr1.cc  */
#line 4053 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)), (yysemantic_stack_[(4) - (3)].expr)
            );
        }
    break;

  case 431:
/* Line 661 of lalr1.cc  */
#line 4063 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            PragmaList *pl = new PragmaList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = pl;
        }
    break;

  case 432:
/* Line 661 of lalr1.cc  */
#line 4069 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            if ( PragmaList *pl = dynamic_cast<PragmaList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 433:
/* Line 661 of lalr1.cc  */
#line 4079 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
        }
    break;

  case 434:
/* Line 661 of lalr1.cc  */
#line 4083 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) ), "" );
        }
    break;

  case 435:
/* Line 661 of lalr1.cc  */
#line 4087 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), true ), "" );
        }
    break;

  case 436:
/* Line 661 of lalr1.cc  */
#line 4093 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new PathExpr(LOC((yyloc)), ParseConstants::path_leading_lone_slash, NULL);
    }
    break;

  case 437:
/* Line 661 of lalr1.cc  */
#line 4097 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      RelativePathExpr* rpe;

      rpe = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slash, NULL, (yysemantic_stack_[(2) - (2)].expr), false);

      (yyval.expr) = new PathExpr(LOC((yyloc)),
                        ParseConstants::path_leading_slash,
                        rpe);
    }
    break;

  case 438:
/* Line 661 of lalr1.cc  */
#line 4107 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      RelativePathExpr* rpe;

      rpe = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slashslash, NULL, (yysemantic_stack_[(2) - (2)].expr), false);

      (yyval.expr) = new PathExpr(LOC((yyloc)),
                        ParseConstants::path_leading_slashslash,
                        rpe);
    }
    break;

  case 439:
/* Line 661 of lalr1.cc  */
#line 4117 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = NULL;

      RelativePathExpr* rpe = dynamic_cast<RelativePathExpr*>((yysemantic_stack_[(1) - (1)].expr));

      if (rpe != NULL &&
         ( (dynamic_cast<ContextItemExpr*>(rpe->get_step_expr()) != NULL &&
             dynamic_cast<ContextItemExpr*>(rpe->get_step_expr())->is_placeholder() &&
             dynamic_cast<AxisStep*>(rpe->get_relpath_expr()) != NULL)
           ||
             dynamic_cast<AxisStep*>(rpe->get_step_expr()) != NULL))
      {




        switch (rpe->is_jsoniq_literal())
        {
        case 0:


          break;
        case 1:

          driver.addCommonLanguageWarning((yylocation_stack_[(1) - (1)]), ZED(ZWST0009_TRUE_FALSE_NULL_KEYWORDS));
          (yyval.expr) = new NullLiteral(LOC((yyloc)));
          break;
        case 2:

          driver.addCommonLanguageWarning((yylocation_stack_[(1) - (1)]), ZED(ZWST0009_TRUE_FALSE_NULL_KEYWORDS));
          (yyval.expr) = new BooleanLiteral(LOC((yyloc)), false);
          break;
        case 3:

          driver.addCommonLanguageWarning((yylocation_stack_[(1) - (1)]), ZED(ZWST0009_TRUE_FALSE_NULL_KEYWORDS));
          (yyval.expr) = new BooleanLiteral(LOC((yyloc)), true);
          break;
        }

      }

      if ((yyval.expr) == NULL)
        (yyval.expr) = (rpe ?
              new PathExpr( LOC((yyloc)), ParseConstants::path_relative, (yysemantic_stack_[(1) - (1)].expr)) :
              (yysemantic_stack_[(1) - (1)].expr));
    }
    break;

  case 440:
/* Line 661 of lalr1.cc  */
#line 4170 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = NULL;
    }
    break;

  case 441:
/* Line 661 of lalr1.cc  */
#line 4179 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
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

  case 442:
/* Line 661 of lalr1.cc  */
#line 4189 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr), false);
    }
    break;

  case 443:
/* Line 661 of lalr1.cc  */
#line 4193 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slashslash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr), false);
    }
    break;

  case 446:
/* Line 661 of lalr1.cc  */
#line 4209 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)), dynamic_cast<ForwardStep*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 447:
/* Line 661 of lalr1.cc  */
#line 4215 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)),
                dynamic_cast<ForwardStep*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 448:
/* Line 661 of lalr1.cc  */
#line 4223 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)), dynamic_cast<ReverseStep*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 449:
/* Line 661 of lalr1.cc  */
#line 4229 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)),
                dynamic_cast<ReverseStep*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 450:
/* Line 661 of lalr1.cc  */
#line 4242 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ForwardStep(
                LOC((yyloc)), dynamic_cast<ForwardAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node)
            );
        }
    break;

  case 451:
/* Line 661 of lalr1.cc  */
#line 4248 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ForwardStep(
                LOC((yyloc)), dynamic_cast<AbbrevForwardStep*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 452:
/* Line 661 of lalr1.cc  */
#line 4259 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_child );
        }
    break;

  case 453:
/* Line 661 of lalr1.cc  */
#line 4263 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_descendant);
        }
    break;

  case 454:
/* Line 661 of lalr1.cc  */
#line 4267 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_attribute );
        }
    break;

  case 455:
/* Line 661 of lalr1.cc  */
#line 4271 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_self );
        }
    break;

  case 456:
/* Line 661 of lalr1.cc  */
#line 4275 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ForwardAxis(
                LOC((yyloc)), ParseConstants::axis_descendant_or_self
            );
        }
    break;

  case 457:
/* Line 661 of lalr1.cc  */
#line 4281 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ForwardAxis(
                LOC((yyloc)), ParseConstants::axis_following_sibling
            );
        }
    break;

  case 458:
/* Line 661 of lalr1.cc  */
#line 4287 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_following );
        }
    break;

  case 459:
/* Line 661 of lalr1.cc  */
#line 4296 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new AbbrevForwardStep( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), false );
        }
    break;

  case 460:
/* Line 661 of lalr1.cc  */
#line 4300 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new AbbrevForwardStep( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].node), true );
        }
    break;

  case 461:
/* Line 661 of lalr1.cc  */
#line 4309 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ReverseStep( LOC((yyloc)), dynamic_cast<ReverseAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node) );
        }
    break;

  case 462:
/* Line 661 of lalr1.cc  */
#line 4313 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            ReverseAxis *ra = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_parent
            );
            (yyval.node) = new ReverseStep( LOC((yyloc)), ra, NULL );
        }
    break;

  case 463:
/* Line 661 of lalr1.cc  */
#line 4325 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_parent );
        }
    break;

  case 464:
/* Line 661 of lalr1.cc  */
#line 4329 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_ancestor );
        }
    break;

  case 465:
/* Line 661 of lalr1.cc  */
#line 4333 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_preceding_sibling
            );
        }
    break;

  case 466:
/* Line 661 of lalr1.cc  */
#line 4339 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_preceding );
        }
    break;

  case 467:
/* Line 661 of lalr1.cc  */
#line 4343 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_ancestor_or_self
            );
        }
    break;

  case 470:
/* Line 661 of lalr1.cc  */
#line 4365 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 471:
/* Line 661 of lalr1.cc  */
#line 4369 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), dynamic_cast<Wildcard*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 472:
/* Line 661 of lalr1.cc  */
#line 4379 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", "", ParseConstants::wild_all, false);
    }
    break;

  case 473:
/* Line 661 of lalr1.cc  */
#line 4383 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), "", ParseConstants::wild_elem, false);
    }
    break;

  case 474:
/* Line 661 of lalr1.cc  */
#line 4387 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), "", ParseConstants::wild_elem, true);
    }
    break;

  case 475:
/* Line 661 of lalr1.cc  */
#line 4391 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", SYMTAB((yysemantic_stack_[(1) - (1)].sval)), ParseConstants::wild_prefix, false);
    }
    break;

  case 476:
/* Line 661 of lalr1.cc  */
#line 4404 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
     }
    break;

  case 477:
/* Line 661 of lalr1.cc  */
#line 4408 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new FilterExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
     }
    break;

  case 478:
/* Line 661 of lalr1.cc  */
#line 4412 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new DynamicFunctionInvocation(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), false);
     }
    break;

  case 479:
/* Line 661 of lalr1.cc  */
#line 4416 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new DynamicFunctionInvocation(LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node)), false);
     }
    break;

  case 480:
/* Line 661 of lalr1.cc  */
#line 4422 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new JSONArrayUnboxing(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr));
    }
    break;

  case 481:
/* Line 661 of lalr1.cc  */
#line 4426 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
       ERROR_IF_QNAME_NOT_NCNAME((yysemantic_stack_[(3) - (3)].expr), (yylocation_stack_[(3) - (3)]));
       StringLiteral* sl = new StringLiteral( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
       (yyval.expr) = new JSONObjectLookup(LOC((yyloc)), LOC((yylocation_stack_[(3) - (2)])), (yysemantic_stack_[(3) - (1)].expr), sl);
     }
    break;

  case 482:
/* Line 661 of lalr1.cc  */
#line 4432 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new JSONObjectLookup(LOC((yyloc)), LOC((yylocation_stack_[(4) - (2)])),
                                 (yysemantic_stack_[(4) - (1)].expr),
                                 new ParenthesizedExpr(LOC((yyloc)), NULL));
     }
    break;

  case 483:
/* Line 661 of lalr1.cc  */
#line 4438 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new JSONObjectLookup(LOC((yyloc)), LOC((yylocation_stack_[(5) - (2)])),
                                 (yysemantic_stack_[(5) - (1)].expr),
                                 new ParenthesizedExpr(LOC((yyloc)), (yysemantic_stack_[(5) - (4)].expr)));
     }
    break;

  case 484:
/* Line 661 of lalr1.cc  */
#line 4444 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.expr) = new JSONObjectLookup(LOC((yyloc)), LOC((yylocation_stack_[(3) - (2)])), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
     }
    break;

  case 485:
/* Line 661 of lalr1.cc  */
#line 4448 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new JSONObjectLookup(LOC((yyloc)), LOC((yylocation_stack_[(3) - (2)])), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
     }
    break;

  case 486:
/* Line 661 of lalr1.cc  */
#line 4457 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      PredicateList* pl = new PredicateList( LOC((yyloc)) );
      pl->push_back(dynamic_cast<exprnode*>((yysemantic_stack_[(1) - (1)].expr)));
      (yyval.node) = pl;
    }
    break;

  case 487:
/* Line 661 of lalr1.cc  */
#line 4463 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      if (PredicateList* pl = dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (1)].node)))
        pl->push_back(dynamic_cast<exprnode*>((yysemantic_stack_[(2) - (2)].expr)));

      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 488:
/* Line 661 of lalr1.cc  */
#line 4474 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 503:
/* Line 661 of lalr1.cc  */
#line 4502 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 504:
/* Line 661 of lalr1.cc  */
#line 4506 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 505:
/* Line 661 of lalr1.cc  */
#line 4514 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_decimal, *(yysemantic_stack_[(1) - (1)].decval)
            );
            delete yylval.decval;
        }
    break;

  case 506:
/* Line 661 of lalr1.cc  */
#line 4521 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_integer, *(yysemantic_stack_[(1) - (1)].ival)
            );
            delete yylval.ival;
        }
    break;

  case 507:
/* Line 661 of lalr1.cc  */
#line 4528 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_double, *(yysemantic_stack_[(1) - (1)].dval)
            );
            delete yylval.dval;
        }
    break;

  case 508:
/* Line 661 of lalr1.cc  */
#line 4539 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new VarRef(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)));
        }
    break;

  case 509:
/* Line 661 of lalr1.cc  */
#line 4547 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), NULL);
        }
    break;

  case 510:
/* Line 661 of lalr1.cc  */
#line 4551 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 511:
/* Line 661 of lalr1.cc  */
#line 4559 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {

            driver.addCommonLanguageWarning((yylocation_stack_[(1) - (1)]), ZED(ZWST0009_CONTEXT_ITEM_EXPR));
            (yyval.expr) = new ContextItemExpr( LOC((yyloc)) );
        }
    break;

  case 512:
/* Line 661 of lalr1.cc  */
#line 4570 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new OrderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 513:
/* Line 661 of lalr1.cc  */
#line 4578 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new UnorderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 514:
/* Line 661 of lalr1.cc  */
#line 4584 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new FunctionCall(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), NULL);
    }
    break;

  case 515:
/* Line 661 of lalr1.cc  */
#line 4588 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
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

  case 516:
/* Line 661 of lalr1.cc  */
#line 4610 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      ArgList* al = new ArgList(LOC((yyloc)));
      al->push_back(new ArgumentPlaceholder(LOC((yyloc))));
      (yyval.node) = al;
    }
    break;

  case 517:
/* Line 661 of lalr1.cc  */
#line 4616 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      if (ArgList* al = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node)))
        al->push_back(new ArgumentPlaceholder(LOC((yyloc))));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 518:
/* Line 661 of lalr1.cc  */
#line 4622 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      ArgList *al = new ArgList( LOC((yyloc)) );
      al->push_back( (yysemantic_stack_[(1) - (1)].expr) );
      (yyval.node) = al;
    }
    break;

  case 519:
/* Line 661 of lalr1.cc  */
#line 4628 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      if ( ArgList *al = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node)) )
        al->push_back( (yysemantic_stack_[(3) - (3)].expr) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 520:
/* Line 661 of lalr1.cc  */
#line 4638 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 521:
/* Line 661 of lalr1.cc  */
#line 4642 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 522:
/* Line 661 of lalr1.cc  */
#line 4650 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new LiteralFunctionItem(LOC ((yyloc)), dynamic_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].ival));
    }
    break;

  case 523:
/* Line 661 of lalr1.cc  */
#line 4658 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new InlineFunction(LOC((yyloc)),
                              &*(yysemantic_stack_[(3) - (2)].fnsig)->theParams,
                              &*(yysemantic_stack_[(3) - (2)].fnsig)->theReturnType,
                              (yysemantic_stack_[(3) - (3)].expr));
      delete (yysemantic_stack_[(3) - (2)].fnsig);
    }
    break;

  case 529:
/* Line 661 of lalr1.cc  */
#line 4683 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new DirElemConstructor(LOC((yyloc)),
                                  static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                                  NULL,
                                  NULL,
                                  NULL);
    }
    break;

  case 530:
/* Line 661 of lalr1.cc  */
#line 4691 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
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

  case 531:
/* Line 661 of lalr1.cc  */
#line 4708 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new DirElemConstructor(LOC((yyloc)),
                                  static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                                  NULL,
                                  dynamic_cast<DirAttributeList*>((yysemantic_stack_[(5) - (3)].node)),
                                  NULL);
    }
    break;

  case 532:
/* Line 661 of lalr1.cc  */
#line 4716 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
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

  case 533:
/* Line 661 of lalr1.cc  */
#line 4735 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
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

  case 534:
/* Line 661 of lalr1.cc  */
#line 4754 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
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

  case 535:
/* Line 661 of lalr1.cc  */
#line 4776 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      DirElemContentList *decl = new DirElemContentList( LOC((yyloc)) );
      decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(1) - (1)].expr)) );
      (yyval.node) = decl;
    }
    break;

  case 536:
/* Line 661 of lalr1.cc  */
#line 4782 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      DirElemContentList *decl = dynamic_cast<DirElemContentList*>((yysemantic_stack_[(2) - (1)].node));
      if ( decl )
        decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(2) - (2)].expr)) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 537:
/* Line 661 of lalr1.cc  */
#line 4793 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      DirAttributeList *dal = new DirAttributeList( LOC((yyloc)) );
      dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = dal;
    }
    break;

  case 538:
/* Line 661 of lalr1.cc  */
#line 4799 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      DirAttributeList *dal = dynamic_cast<DirAttributeList*>((yysemantic_stack_[(2) - (1)].node));
      if ( dal )
        dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 539:
/* Line 661 of lalr1.cc  */
#line 4810 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DirAttr(LOC((yyloc)),
                       static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                       dynamic_cast<DirAttributeValue*>((yysemantic_stack_[(6) - (6)].node)));
    }
    break;

  case 542:
/* Line 661 of lalr1.cc  */
#line 4825 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DirAttributeValue(LOC((yyloc)),
                                 dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
    }
    break;

  case 543:
/* Line 661 of lalr1.cc  */
#line 4830 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DirAttributeValue( LOC((yyloc)),
                                  dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
    }
    break;

  case 544:
/* Line 661 of lalr1.cc  */
#line 4839 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new QuoteAttrContentList( LOC((yyloc)) );
    }
    break;

  case 545:
/* Line 661 of lalr1.cc  */
#line 4843 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 546:
/* Line 661 of lalr1.cc  */
#line 4850 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
      qacl->push_back( new QuoteAttrValueContent( LOC((yyloc)), "\"" ) );
      (yyval.node) = qacl;
    }
    break;

  case 547:
/* Line 661 of lalr1.cc  */
#line 4856 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
      qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = qacl;
    }
    break;

  case 548:
/* Line 661 of lalr1.cc  */
#line 4862 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      QuoteAttrContentList* qacl = dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
      if ( qacl )
        qacl->push_back( new QuoteAttrValueContent( LOC((yyloc)), "\"" ) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 549:
/* Line 661 of lalr1.cc  */
#line 4869 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      QuoteAttrContentList *qacl = dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
      if ( qacl )
        qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 550:
/* Line 661 of lalr1.cc  */
#line 4880 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AposAttrContentList( LOC((yyloc)) );
    }
    break;

  case 551:
/* Line 661 of lalr1.cc  */
#line 4884 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 552:
/* Line 661 of lalr1.cc  */
#line 4891 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
      aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
      (yyval.node) = aacl;
    }
    break;

  case 553:
/* Line 661 of lalr1.cc  */
#line 4897 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
      aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = aacl;
    }
    break;

  case 554:
/* Line 661 of lalr1.cc  */
#line 4903 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
      if (aacl)
        aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 555:
/* Line 661 of lalr1.cc  */
#line 4910 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
      if ( aacl )
        aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 556:
/* Line 661 of lalr1.cc  */
#line 4921 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new QuoteAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
    }
    break;

  case 557:
/* Line 661 of lalr1.cc  */
#line 4925 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new QuoteAttrValueContent(LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
    }
    break;

  case 558:
/* Line 661 of lalr1.cc  */
#line 4933 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AposAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
    }
    break;

  case 559:
/* Line 661 of lalr1.cc  */
#line 4937 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AposAttrValueContent(LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
    }
    break;

  case 560:
/* Line 661 of lalr1.cc  */
#line 4945 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new DirElemContent( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr) );
    }
    break;

  case 561:
/* Line 661 of lalr1.cc  */
#line 4949 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new DirElemContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
    }
    break;

  case 562:
/* Line 661 of lalr1.cc  */
#line 4953 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      rchandle<CDataSection> cdata_h = dynamic_cast<CDataSection*>((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = new DirElemContent( LOC((yyloc)), cdata_h );
    }
    break;

  case 563:
/* Line 661 of lalr1.cc  */
#line 4958 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      rchandle<CommonContent> cont_h = dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = new DirElemContent( LOC((yyloc)), cont_h );
    }
    break;

  case 564:
/* Line 661 of lalr1.cc  */
#line 4967 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CommonContent(LOC((yyloc)), ParseConstants::cont_charref, SYMTAB((yysemantic_stack_[(1) - (1)].sval)));
    }
    break;

  case 565:
/* Line 661 of lalr1.cc  */
#line 4971 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CommonContent(LOC((yyloc)), ParseConstants::cont_escape_lbrace);
    }
    break;

  case 566:
/* Line 661 of lalr1.cc  */
#line 4975 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CommonContent(LOC((yyloc)), ParseConstants::cont_escape_rbrace);
    }
    break;

  case 567:
/* Line 661 of lalr1.cc  */
#line 4979 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CommonContent(LOC((yyloc)), new EnclosedExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr)));
    }
    break;

  case 568:
/* Line 661 of lalr1.cc  */
#line 4987 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 569:
/* Line 661 of lalr1.cc  */
#line 4992 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), "" );
    }
    break;

  case 570:
/* Line 661 of lalr1.cc  */
#line 5000 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      ERROR_IF_QNAME_NOT_NCNAME((yysemantic_stack_[(3) - (2)].expr), (yylocation_stack_[(3) - (2)]));
      (yyval.expr) = new DirPIConstructor( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)) );
    }
    break;

  case 571:
/* Line 661 of lalr1.cc  */
#line 5006 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      ERROR_IF_QNAME_NOT_NCNAME((yysemantic_stack_[(3) - (2)].expr), (yylocation_stack_[(3) - (2)]));
      (yyval.expr) = new DirPIConstructor( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
    }
    break;

  case 572:
/* Line 661 of lalr1.cc  */
#line 5015 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CDataSection( LOC((yyloc)),SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
    }
    break;

  case 573:
/* Line 661 of lalr1.cc  */
#line 5023 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 574:
/* Line 661 of lalr1.cc  */
#line 5028 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 575:
/* Line 661 of lalr1.cc  */
#line 5033 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 576:
/* Line 661 of lalr1.cc  */
#line 5038 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 577:
/* Line 661 of lalr1.cc  */
#line 5043 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 578:
/* Line 661 of lalr1.cc  */
#line 5048 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 580:
/* Line 661 of lalr1.cc  */
#line 5059 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompDocConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
    }
    break;

  case 581:
/* Line 661 of lalr1.cc  */
#line 5067 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompElemConstructor(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval))), (yysemantic_stack_[(3) - (2)].expr));
    }
    break;

  case 582:
/* Line 661 of lalr1.cc  */
#line 5071 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompElemConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
    }
    break;

  case 583:
/* Line 661 of lalr1.cc  */
#line 5077 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval))), (yysemantic_stack_[(3) - (2)].expr) );
    }
    break;

  case 584:
/* Line 661 of lalr1.cc  */
#line 5081 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
    }
    break;

  case 585:
/* Line 661 of lalr1.cc  */
#line 5089 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompTextConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
    }
    break;

  case 586:
/* Line 661 of lalr1.cc  */
#line 5097 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompCommentConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
    }
    break;

  case 587:
/* Line 661 of lalr1.cc  */
#line 5105 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompPIConstructor(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval)), (yysemantic_stack_[(3) - (2)].expr));
    }
    break;

  case 588:
/* Line 661 of lalr1.cc  */
#line 5109 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompPIConstructor(LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
    }
    break;

  case 589:
/* Line 661 of lalr1.cc  */
#line 5117 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompNamespaceConstructor(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval)), (yysemantic_stack_[(3) - (2)].expr));
    }
    break;

  case 590:
/* Line 661 of lalr1.cc  */
#line 5121 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompNamespaceConstructor(LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
    }
    break;

  case 591:
/* Line 661 of lalr1.cc  */
#line 5129 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 592:
/* Line 661 of lalr1.cc  */
#line 5137 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL );
        }
    break;

  case 593:
/* Line 661 of lalr1.cc  */
#line 5141 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new SequenceType(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node)));
        }
    break;

  case 594:
/* Line 661 of lalr1.cc  */
#line 5145 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 595:
/* Line 661 of lalr1.cc  */
#line 5151 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {

            driver.addCommonLanguageWarning((yylocation_stack_[(2) - (1)]), ZED(ZWST0009_JSONIQ_EMPTY_SEQUENCE));
            (yyval.node) = new SequenceType( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 596:
/* Line 661 of lalr1.cc  */
#line 5160 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_optionally
            );
        }
    break;

  case 597:
/* Line 661 of lalr1.cc  */
#line 5166 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_zero_or_more
            );
        }
    break;

  case 598:
/* Line 661 of lalr1.cc  */
#line 5172 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_one_or_more
            );
        }
    break;

  case 599:
/* Line 661 of lalr1.cc  */
#line 5182 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            GeneralizedAtomicType* gat = static_cast<GeneralizedAtomicType*>((yysemantic_stack_[(1) - (1)].node));
            QName* q = gat->get_qname();


            if (q->get_qname() == "item")
            {

              driver.addCommonLanguageWarning((yylocation_stack_[(1) - (1)]), ZED(ZWST0009_JSONIQ_TYPE_KEYWORDS));
              (yyval.node) = new ItemType( LOC((yyloc)), true );
            }
            else if (q->get_qname() == "array")
            {

              driver.addCommonLanguageWarning((yylocation_stack_[(1) - (1)]), ZED(ZWST0009_JSONIQ_TYPE_KEYWORDS));
              (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonArray);
            }
            else if (q->get_qname() == "object")
            {

              driver.addCommonLanguageWarning((yylocation_stack_[(1) - (1)]), ZED(ZWST0009_JSONIQ_TYPE_KEYWORDS));
              (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonObject);
            }
            else if (q->get_qname() == "json-item")
            {

              driver.addCommonLanguageWarning((yylocation_stack_[(1) - (1)]), ZED(ZWST0009_JSONIQ_TYPE_KEYWORDS));
              (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonItem);
            }
            else if (q->get_qname() == "structured-item")
            {

              driver.addCommonLanguageWarning((yylocation_stack_[(1) - (1)]), ZED(ZWST0009_JSONIQ_TYPE_KEYWORDS));
              (yyval.node) = new StructuredItemType(LOC((yyloc)));
            }
            else
            {
              (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
            }



        }
    break;

  case 600:
/* Line 661 of lalr1.cc  */
#line 5226 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 601:
/* Line 661 of lalr1.cc  */
#line 5230 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ItemType( LOC((yyloc)), true );
        }
    break;

  case 602:
/* Line 661 of lalr1.cc  */
#line 5234 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new StructuredItemType(LOC((yyloc)));
        }
    break;

  case 603:
/* Line 661 of lalr1.cc  */
#line 5238 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 604:
/* Line 661 of lalr1.cc  */
#line 5242 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 605:
/* Line 661 of lalr1.cc  */
#line 5246 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 606:
/* Line 661 of lalr1.cc  */
#line 5253 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
          TypeList* aTypeList = new TypeList(LOC ((yyloc)));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(1) - (1)].node)));
          (yyval.node) = aTypeList;
        }
    break;

  case 607:
/* Line 661 of lalr1.cc  */
#line 5259 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
          TypeList* aTypeList = dynamic_cast<TypeList *>((yysemantic_stack_[(3) - (1)].node));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
          (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 608:
/* Line 661 of lalr1.cc  */
#line 5269 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new GeneralizedAtomicType( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
    }
    break;

  case 609:
/* Line 661 of lalr1.cc  */
#line 5277 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SimpleType( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
    }
    break;

  case 610:
/* Line 661 of lalr1.cc  */
#line 5285 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 611:
/* Line 661 of lalr1.cc  */
#line 5289 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 612:
/* Line 661 of lalr1.cc  */
#line 5293 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 613:
/* Line 661 of lalr1.cc  */
#line 5297 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 614:
/* Line 661 of lalr1.cc  */
#line 5301 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 615:
/* Line 661 of lalr1.cc  */
#line 5305 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 616:
/* Line 661 of lalr1.cc  */
#line 5309 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 617:
/* Line 661 of lalr1.cc  */
#line 5313 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 618:
/* Line 661 of lalr1.cc  */
#line 5317 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 619:
/* Line 661 of lalr1.cc  */
#line 5321 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 620:
/* Line 661 of lalr1.cc  */
#line 5329 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AnyKindTest( LOC((yyloc)) );
    }
    break;

  case 621:
/* Line 661 of lalr1.cc  */
#line 5336 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = NULL;
    }
    break;

  case 622:
/* Line 661 of lalr1.cc  */
#line 5343 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DocumentTest(LOC((yyloc)));
    }
    break;

  case 623:
/* Line 661 of lalr1.cc  */
#line 5347 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DocumentTest(LOC((yyloc)), dynamic_cast<ElementTest*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 624:
/* Line 661 of lalr1.cc  */
#line 5351 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DocumentTest(LOC((yyloc)), dynamic_cast<SchemaElementTest*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 625:
/* Line 661 of lalr1.cc  */
#line 5359 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new NamespaceTest(LOC((yyloc)));
    }
    break;

  case 626:
/* Line 661 of lalr1.cc  */
#line 5366 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new TextTest(LOC((yyloc)));
    }
    break;

  case 627:
/* Line 661 of lalr1.cc  */
#line 5374 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CommentTest(LOC((yyloc)));
    }
    break;

  case 628:
/* Line 661 of lalr1.cc  */
#line 5382 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), "" );
        }
    break;

  case 629:
/* Line 661 of lalr1.cc  */
#line 5386 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            ERROR_IF_QNAME_NOT_NCNAME((yysemantic_stack_[(4) - (3)].expr), (yylocation_stack_[(4) - (3)]));
            (yyval.node) = new PITest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 630:
/* Line 661 of lalr1.cc  */
#line 5391 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 631:
/* Line 661 of lalr1.cc  */
#line 5399 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 632:
/* Line 661 of lalr1.cc  */
#line 5403 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL
            );
        }
    break;

  case 633:
/* Line 661 of lalr1.cc  */
#line 5409 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 634:
/* Line 661 of lalr1.cc  */
#line 5415 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 635:
/* Line 661 of lalr1.cc  */
#line 5419 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 636:
/* Line 661 of lalr1.cc  */
#line 5429 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new SchemaAttributeTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 637:
/* Line 661 of lalr1.cc  */
#line 5437 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ElementTest( LOC((yyloc)), NULL, NULL, true );
        }
    break;

  case 638:
/* Line 661 of lalr1.cc  */
#line 5441 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL, true
            );
        }
    break;

  case 639:
/* Line 661 of lalr1.cc  */
#line 5447 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                false
            );
        }
    break;

  case 640:
/* Line 661 of lalr1.cc  */
#line 5456 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                true
            );
        }
    break;

  case 641:
/* Line 661 of lalr1.cc  */
#line 5465 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, NULL, true
            );
        }
    break;

  case 642:
/* Line 661 of lalr1.cc  */
#line 5471 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), false
            );
        }
    break;

  case 643:
/* Line 661 of lalr1.cc  */
#line 5477 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), true
            );
        }
    break;

  case 644:
/* Line 661 of lalr1.cc  */
#line 5487 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new SchemaElementTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 645:
/* Line 661 of lalr1.cc  */
#line 5493 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 646:
/* Line 661 of lalr1.cc  */
#line 5500 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (1)].expr)), true );
        }
    break;

  case 647:
/* Line 661 of lalr1.cc  */
#line 5506 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new StringLiteral( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 648:
/* Line 661 of lalr1.cc  */
#line 5512 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 649:
/* Line 661 of lalr1.cc  */
#line 5516 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 650:
/* Line 661 of lalr1.cc  */
#line 5524 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AnyFunctionTest(LOC((yyloc)));
    }
    break;

  case 651:
/* Line 661 of lalr1.cc  */
#line 5532 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)), dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (5)].node)));
        }
    break;

  case 652:
/* Line 661 of lalr1.cc  */
#line 5536 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)),
              dynamic_cast<TypeList *>((yysemantic_stack_[(6) - (3)].node)),
              dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (6)].node)));
        }
    break;

  case 653:
/* Line 661 of lalr1.cc  */
#line 5547 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
           (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 654:
/* Line 661 of lalr1.cc  */
#line 5553 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::strict_validation
            );
        }
    break;

  case 655:
/* Line 661 of lalr1.cc  */
#line 5559 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::lax_validation
            );
        }
    break;

  case 656:
/* Line 661 of lalr1.cc  */
#line 5565 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::skip_validation
            );
        }
    break;

  case 657:
/* Line 661 of lalr1.cc  */
#line 5575 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 658:
/* Line 661 of lalr1.cc  */
#line 5579 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 659:
/* Line 661 of lalr1.cc  */
#line 5585 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 660:
/* Line 661 of lalr1.cc  */
#line 5591 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 661:
/* Line 661 of lalr1.cc  */
#line 5595 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 662:
/* Line 661 of lalr1.cc  */
#line 5601 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 663:
/* Line 661 of lalr1.cc  */
#line 5605 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 664:
/* Line 661 of lalr1.cc  */
#line 5611 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                  LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 665:
/* Line 661 of lalr1.cc  */
#line 5617 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)),
                store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 666:
/* Line 661 of lalr1.cc  */
#line 5624 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 667:
/* Line 661 of lalr1.cc  */
#line 5634 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 668:
/* Line 661 of lalr1.cc  */
#line 5639 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 669:
/* Line 661 of lalr1.cc  */
#line 5647 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::NODE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 670:
/* Line 661 of lalr1.cc  */
#line 5653 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::VALUE_OF_NODE, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 671:
/* Line 661 of lalr1.cc  */
#line 5663 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new RenameExpr( LOC ((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 672:
/* Line 661 of lalr1.cc  */
#line 5669 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      CopyVarList *cvl = dynamic_cast<CopyVarList*>((yysemantic_stack_[(7) - (3)].expr));
      (yyval.expr) = new TransformExpr( LOC((yyloc)), cvl, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr) );
    }
    break;

  case 673:
/* Line 661 of lalr1.cc  */
#line 5678 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      CopyVarList* lList = new CopyVarList(LOC((yyloc)));
      lList->push_back (dynamic_cast<VarBinding*> ((yysemantic_stack_[(1) - (1)].expr)));
      (yyval.expr) = lList;
    }
    break;

  case 674:
/* Line 661 of lalr1.cc  */
#line 5684 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      CopyVarList* lList = dynamic_cast<CopyVarList*>((yysemantic_stack_[(4) - (1)].expr));
      VarBinding* lBinding = dynamic_cast<VarBinding*>((yysemantic_stack_[(4) - (4)].expr));
      lList->push_back(lBinding);
      (yyval.expr) = lList;
    }
    break;

  case 675:
/* Line 661 of lalr1.cc  */
#line 5697 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new VarBinding(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 676:
/* Line 661 of lalr1.cc  */
#line 5703 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new TryExpr( LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 677:
/* Line 661 of lalr1.cc  */
#line 5710 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            CatchListExpr *cle = new CatchListExpr( LOC((yyloc)) );
            cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.expr) = cle;
        }
    break;

  case 678:
/* Line 661 of lalr1.cc  */
#line 5716 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
            if ( cle )
                cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
        }
    break;

  case 679:
/* Line 661 of lalr1.cc  */
#line 5726 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)), *(yysemantic_stack_[(3) - (2)].name_test_list), (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 680:
/* Line 661 of lalr1.cc  */
#line 5735 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 681:
/* Line 661 of lalr1.cc  */
#line 5743 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            CatchExpr::NameTestList *ntl = new CatchExpr::NameTestList;
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 682:
/* Line 661 of lalr1.cc  */
#line 5749 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            CatchExpr::NameTestList *ntl =
                static_cast<CatchExpr::NameTestList*>((yysemantic_stack_[(3) - (1)].name_test_list));
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 683:
/* Line 661 of lalr1.cc  */
#line 5758 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTSelection( LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), (yysemantic_stack_[(2) - (2)].pos_filter_list) );
            delete (yysemantic_stack_[(2) - (2)].pos_filter_list);
        }
    break;

  case 684:
/* Line 661 of lalr1.cc  */
#line 5766 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.pos_filter_list) = NULL;
        }
    break;

  case 685:
/* Line 661 of lalr1.cc  */
#line 5770 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.pos_filter_list) = (yysemantic_stack_[(1) - (1)].pos_filter_list);
        }
    break;

  case 686:
/* Line 661 of lalr1.cc  */
#line 5777 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.pos_filter_list) = new FTSelection::pos_filter_list_t;
            (yyval.pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 687:
/* Line 661 of lalr1.cc  */
#line 5782 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yysemantic_stack_[(2) - (1)].pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.pos_filter_list) = (yysemantic_stack_[(2) - (1)].pos_filter_list);
        }
    break;

  case 688:
/* Line 661 of lalr1.cc  */
#line 5790 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 689:
/* Line 661 of lalr1.cc  */
#line 5794 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTOr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 690:
/* Line 661 of lalr1.cc  */
#line 5801 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 691:
/* Line 661 of lalr1.cc  */
#line 5805 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTAnd( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 692:
/* Line 661 of lalr1.cc  */
#line 5812 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 693:
/* Line 661 of lalr1.cc  */
#line 5816 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTMildNot( LOC((yyloc)), (yysemantic_stack_[(4) - (1)].node), (yysemantic_stack_[(4) - (4)].node) );
        }
    break;

  case 694:
/* Line 661 of lalr1.cc  */
#line 5823 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 695:
/* Line 661 of lalr1.cc  */
#line 5827 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTUnaryNot(
                LOC((yyloc)), dynamic_cast<FTPrimaryWithOptions*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 696:
/* Line 661 of lalr1.cc  */
#line 5836 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTPrimaryWithOptions(
                LOC((yyloc)),
                dynamic_cast<FTPrimary*>((yysemantic_stack_[(3) - (1)].node)),
                dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<FTWeight*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 697:
/* Line 661 of lalr1.cc  */
#line 5848 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 698:
/* Line 661 of lalr1.cc  */
#line 5852 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 699:
/* Line 661 of lalr1.cc  */
#line 5859 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 700:
/* Line 661 of lalr1.cc  */
#line 5863 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 701:
/* Line 661 of lalr1.cc  */
#line 5871 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTWeight( LOC((yyloc)), dynamic_cast<exprnode*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 702:
/* Line 661 of lalr1.cc  */
#line 5879 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTWordsTimes(
                LOC((yyloc)),
                dynamic_cast<FTWords*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<FTTimes*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 703:
/* Line 661 of lalr1.cc  */
#line 5887 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 704:
/* Line 661 of lalr1.cc  */
#line 5891 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 705:
/* Line 661 of lalr1.cc  */
#line 5898 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 706:
/* Line 661 of lalr1.cc  */
#line 5902 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 707:
/* Line 661 of lalr1.cc  */
#line 5910 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTExtensionSelection(
                LOC((yyloc)),
                dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)),
                dynamic_cast<FTSelection*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 708:
/* Line 661 of lalr1.cc  */
#line 5921 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 709:
/* Line 661 of lalr1.cc  */
#line 5925 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 710:
/* Line 661 of lalr1.cc  */
#line 5933 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTWords(
                LOC((yyloc)),
                dynamic_cast<FTWordsValue*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<FTAnyallOption*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 711:
/* Line 661 of lalr1.cc  */
#line 5945 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), static_cast<StringLiteral*>((yysemantic_stack_[(1) - (1)].expr)), NULL
            );
        }
    break;

  case 712:
/* Line 661 of lalr1.cc  */
#line 5951 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), NULL, dynamic_cast<exprnode*>((yysemantic_stack_[(3) - (2)].expr))
            );
        }
    break;

  case 713:
/* Line 661 of lalr1.cc  */
#line 5960 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::any );
        }
    break;

  case 714:
/* Line 661 of lalr1.cc  */
#line 5964 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 715:
/* Line 661 of lalr1.cc  */
#line 5972 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 716:
/* Line 661 of lalr1.cc  */
#line 5976 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 717:
/* Line 661 of lalr1.cc  */
#line 5980 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::phrase );
        }
    break;

  case 718:
/* Line 661 of lalr1.cc  */
#line 5987 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any;
        }
    break;

  case 719:
/* Line 661 of lalr1.cc  */
#line 5991 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any_word;
        }
    break;

  case 720:
/* Line 661 of lalr1.cc  */
#line 5998 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all;
        }
    break;

  case 721:
/* Line 661 of lalr1.cc  */
#line 6002 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all_words;
        }
    break;

  case 722:
/* Line 661 of lalr1.cc  */
#line 6010 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 723:
/* Line 661 of lalr1.cc  */
#line 6014 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 724:
/* Line 661 of lalr1.cc  */
#line 6018 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 725:
/* Line 661 of lalr1.cc  */
#line 6022 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 726:
/* Line 661 of lalr1.cc  */
#line 6026 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 727:
/* Line 661 of lalr1.cc  */
#line 6034 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTOrder( LOC((yyloc)) );
        }
    break;

  case 728:
/* Line 661 of lalr1.cc  */
#line 6042 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTWindow(
                LOC((yyloc)),
                static_cast<AdditiveExpr*>((yysemantic_stack_[(3) - (2)].expr)),
                static_cast<FTUnit*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 729:
/* Line 661 of lalr1.cc  */
#line 6054 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTDistance(
                LOC((yyloc)),
                dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<FTUnit*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 730:
/* Line 661 of lalr1.cc  */
#line 6066 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::words );
        }
    break;

  case 731:
/* Line 661 of lalr1.cc  */
#line 6070 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::sentences );
        }
    break;

  case 732:
/* Line 661 of lalr1.cc  */
#line 6074 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::paragraphs );
        }
    break;

  case 733:
/* Line 661 of lalr1.cc  */
#line 6082 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            FTMatchOptions *mo = new FTMatchOptions( LOC((yyloc)) );
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = mo;
        }
    break;

  case 734:
/* Line 661 of lalr1.cc  */
#line 6088 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            FTMatchOptions *mo = dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (1)].node));
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 735:
/* Line 661 of lalr1.cc  */
#line 6098 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 736:
/* Line 661 of lalr1.cc  */
#line 6102 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 737:
/* Line 661 of lalr1.cc  */
#line 6106 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 738:
/* Line 661 of lalr1.cc  */
#line 6110 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 739:
/* Line 661 of lalr1.cc  */
#line 6114 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 740:
/* Line 661 of lalr1.cc  */
#line 6118 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 741:
/* Line 661 of lalr1.cc  */
#line 6122 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 742:
/* Line 661 of lalr1.cc  */
#line 6126 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 743:
/* Line 661 of lalr1.cc  */
#line 6134 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::sensitive );
        }
    break;

  case 744:
/* Line 661 of lalr1.cc  */
#line 6138 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::insensitive );
        }
    break;

  case 745:
/* Line 661 of lalr1.cc  */
#line 6142 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::lower );
        }
    break;

  case 746:
/* Line 661 of lalr1.cc  */
#line 6146 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::upper );
        }
    break;

  case 747:
/* Line 661 of lalr1.cc  */
#line 6154 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::sensitive
            );
        }
    break;

  case 748:
/* Line 661 of lalr1.cc  */
#line 6160 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::insensitive
            );
        }
    break;

  case 749:
/* Line 661 of lalr1.cc  */
#line 6170 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTExtensionOption(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval))
            );
        }
    break;

  case 750:
/* Line 661 of lalr1.cc  */
#line 6180 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::stemming );
        }
    break;

  case 751:
/* Line 661 of lalr1.cc  */
#line 6184 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::no_stemming );
        }
    break;

  case 752:
/* Line 661 of lalr1.cc  */
#line 6192 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
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

  case 753:
/* Line 661 of lalr1.cc  */
#line 6202 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
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

  case 754:
/* Line 661 of lalr1.cc  */
#line 6213 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTThesaurusOption( LOC((yyloc)), NULL, false, true );
        }
    break;

  case 755:
/* Line 661 of lalr1.cc  */
#line 6220 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 756:
/* Line 661 of lalr1.cc  */
#line 6224 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 757:
/* Line 661 of lalr1.cc  */
#line 6231 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.thesaurus_id_list) = NULL;
        }
    break;

  case 758:
/* Line 661 of lalr1.cc  */
#line 6235 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(2) - (2)].thesaurus_id_list);
        }
    break;

  case 759:
/* Line 661 of lalr1.cc  */
#line 6242 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.thesaurus_id_list) = new FTThesaurusOption::thesaurus_id_list_t;
            (yyval.thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 760:
/* Line 661 of lalr1.cc  */
#line 6247 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yysemantic_stack_[(3) - (1)].thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(3) - (1)].thesaurus_id_list);
        }
    break;

  case 761:
/* Line 661 of lalr1.cc  */
#line 6256 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTThesaurusID(
                LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (2)].sval)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), dynamic_cast<FTRange*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 762:
/* Line 661 of lalr1.cc  */
#line 6265 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.sval) = 0;
        }
    break;

  case 763:
/* Line 661 of lalr1.cc  */
#line 6269 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.sval) = (yysemantic_stack_[(2) - (2)].sval);
        }
    break;

  case 764:
/* Line 661 of lalr1.cc  */
#line 6276 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 765:
/* Line 661 of lalr1.cc  */
#line 6280 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 766:
/* Line 661 of lalr1.cc  */
#line 6288 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(4) - (3)].node)), (yysemantic_stack_[(4) - (4)].incl_excl_list),
                ft_stop_words_mode::with
            );
            delete (yysemantic_stack_[(4) - (4)].incl_excl_list);
        }
    break;

  case 767:
/* Line 661 of lalr1.cc  */
#line 6297 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, (yysemantic_stack_[(4) - (4)].incl_excl_list), ft_stop_words_mode::with_default
            );
            delete (yysemantic_stack_[(4) - (4)].incl_excl_list);
        }
    break;

  case 768:
/* Line 661 of lalr1.cc  */
#line 6304 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, NULL, ft_stop_words_mode::without
            );
        }
    break;

  case 769:
/* Line 661 of lalr1.cc  */
#line 6314 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), NULL );
        }
    break;

  case 770:
/* Line 661 of lalr1.cc  */
#line 6318 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), "", (yysemantic_stack_[(3) - (2)].strlist) );
        }
    break;

  case 771:
/* Line 661 of lalr1.cc  */
#line 6325 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            string_list_t *sl = new string_list_t;
            sl->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
            (yyval.strlist) = sl;
        }
    break;

  case 772:
/* Line 661 of lalr1.cc  */
#line 6331 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            if ( (yysemantic_stack_[(3) - (1)].strlist) )
                (yysemantic_stack_[(3) - (1)].strlist)->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
            (yyval.strlist) = (yysemantic_stack_[(3) - (1)].strlist);
        }
    break;

  case 773:
/* Line 661 of lalr1.cc  */
#line 6340 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.incl_excl_list) = NULL;
        }
    break;

  case 774:
/* Line 661 of lalr1.cc  */
#line 6344 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.incl_excl_list) = (yysemantic_stack_[(1) - (1)].incl_excl_list);
        }
    break;

  case 775:
/* Line 661 of lalr1.cc  */
#line 6351 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.incl_excl_list) = new FTStopWordOption::incl_excl_list_t;
            (yyval.incl_excl_list)->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 776:
/* Line 661 of lalr1.cc  */
#line 6356 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            FTStopWordOption::incl_excl_list_t *iel = (yysemantic_stack_[(2) - (1)].incl_excl_list);
            if ( !iel )
                iel = new FTStopWordOption::incl_excl_list_t;
            iel->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.incl_excl_list) = iel;
        }
    break;

  case 777:
/* Line 661 of lalr1.cc  */
#line 6368 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStopWordsInclExcl(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(2) - (2)].node)),
                ft_stop_words_unex::union_
            );
        }
    break;

  case 778:
/* Line 661 of lalr1.cc  */
#line 6376 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStopWordsInclExcl(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(2) - (2)].node)),
                ft_stop_words_unex::except
            );
        }
    break;

  case 779:
/* Line 661 of lalr1.cc  */
#line 6388 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTLanguageOption( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 780:
/* Line 661 of lalr1.cc  */
#line 6396 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::with );
        }
    break;

  case 781:
/* Line 661 of lalr1.cc  */
#line 6400 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::without );
        }
    break;

  case 782:
/* Line 661 of lalr1.cc  */
#line 6408 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_start );
        }
    break;

  case 783:
/* Line 661 of lalr1.cc  */
#line 6412 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_end );
        }
    break;

  case 784:
/* Line 661 of lalr1.cc  */
#line 6416 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::entire );
        }
    break;

  case 785:
/* Line 661 of lalr1.cc  */
#line 6424 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTTimes( LOC((yyloc)), dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)) );
        }
    break;

  case 786:
/* Line 661 of lalr1.cc  */
#line 6432 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::exactly, (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 787:
/* Line 661 of lalr1.cc  */
#line 6436 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_least, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 788:
/* Line 661 of lalr1.cc  */
#line 6440 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_most, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 789:
/* Line 661 of lalr1.cc  */
#line 6444 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::from_to, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr) );
        }
    break;

  case 790:
/* Line 661 of lalr1.cc  */
#line 6452 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTScope(
                LOC((yyloc)),
                ft_scope::same,
                dynamic_cast<FTBigUnit*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 791:
/* Line 661 of lalr1.cc  */
#line 6460 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTScope(
                LOC((yyloc)),
                ft_scope::different,
                dynamic_cast<FTBigUnit*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 792:
/* Line 661 of lalr1.cc  */
#line 6472 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::sentence );
        }
    break;

  case 793:
/* Line 661 of lalr1.cc  */
#line 6476 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::paragraph );
        }
    break;

  case 794:
/* Line 661 of lalr1.cc  */
#line 6484 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTIgnoreOption( LOC((yyloc)), static_cast<UnionExpr*>((yysemantic_stack_[(3) - (3)].expr)) );
        }
    break;

  case 795:
/* Line 661 of lalr1.cc  */
#line 6490 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONArrayConstructor( LOC((yyloc)), NULL );
        }
    break;

  case 796:
/* Line 661 of lalr1.cc  */
#line 6494 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONArrayConstructor( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 797:
/* Line 661 of lalr1.cc  */
#line 6501 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), NULL, false);
        }
    break;

  case 798:
/* Line 661 of lalr1.cc  */
#line 6505 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), false);
        }
    break;

  case 799:
/* Line 661 of lalr1.cc  */
#line 6512 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), NULL, true);
        }
    break;

  case 800:
/* Line 661 of lalr1.cc  */
#line 6516 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), true);
        }
    break;

  case 801:
/* Line 661 of lalr1.cc  */
#line 6524 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONDirectObjectConstructor(LOC((yyloc)),
                                               dynamic_cast<JSONPairList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 802:
/* Line 661 of lalr1.cc  */
#line 6534 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
          ERROR_IF_QNAME_NOT_NCNAME((yysemantic_stack_[(3) - (1)].expr), (yylocation_stack_[(3) - (1)]));


          driver.addCommonLanguageWarning((yylocation_stack_[(3) - (1)]), ZED(ZWST0009_OBJECT_KEY_NOT_QUOTED));

          StringLiteral* sl = new StringLiteral( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)) );
          JSONPairList* jpl = new JSONPairList(LOC((yyloc)));
          jpl->push_back(new JSONPairConstructor(LOC((yyloc)), sl, (yysemantic_stack_[(3) - (3)].expr)));
          (yyval.node) = jpl;
        }
    break;

  case 803:
/* Line 661 of lalr1.cc  */
#line 6548 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
          JSONPairList* jpl = new JSONPairList(LOC((yyloc)));
          jpl->push_back(new JSONPairConstructor(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)));
          (yyval.node) = jpl;
        }
    break;

  case 804:
/* Line 661 of lalr1.cc  */
#line 6554 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
          JSONPairList* jpl = dynamic_cast<JSONPairList*>((yysemantic_stack_[(5) - (1)].node));
          assert(jpl);
          jpl->push_back(new JSONPairConstructor(LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)));
          (yyval.node) = jpl;
        }
    break;

  case 805:
/* Line 661 of lalr1.cc  */
#line 6563 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
          ERROR_IF_QNAME_NOT_NCNAME((yysemantic_stack_[(5) - (3)].expr), (yylocation_stack_[(5) - (3)]));
          JSONPairList* jpl = dynamic_cast<JSONPairList*>((yysemantic_stack_[(5) - (1)].node));
          assert(jpl);
          StringLiteral* sl = new StringLiteral( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (3)].expr)) );
          jpl->push_back(new JSONPairConstructor(LOC((yyloc)), sl, (yysemantic_stack_[(5) - (5)].expr)));
          (yyval.node) = jpl;
        }
    break;

  case 806:
/* Line 661 of lalr1.cc  */
#line 6576 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONObjectInsertExpr(LOC((yyloc)),
                                        (yysemantic_stack_[(5) - (3)].expr),
                                        (yysemantic_stack_[(5) - (5)].expr));
        }
    break;

  case 807:
/* Line 661 of lalr1.cc  */
#line 6582 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
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

  case 808:
/* Line 661 of lalr1.cc  */
#line 6592 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONArrayInsertExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (5)].expr), (yysemantic_stack_[(8) - (8)].expr));
        }
    break;

  case 809:
/* Line 661 of lalr1.cc  */
#line 6599 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {

          driver.addCommonLanguageWarning((yylocation_stack_[(4) - (2)]), ZED(ZWST0009_JSON_KEYWORD_OPTIONAL));
          (yyval.expr) = new JSONObjectInsertExpr(LOC((yyloc)),
                                        (yysemantic_stack_[(4) - (2)].expr),
                                        (yysemantic_stack_[(4) - (4)].expr));
        }
    break;

  case 810:
/* Line 661 of lalr1.cc  */
#line 6607 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {

          driver.addCommonLanguageWarning((yylocation_stack_[(4) - (2)]), ZED(ZWST0009_JSON_KEYWORD_OPTIONAL));
          JSONPairList* jpl = dynamic_cast<JSONPairList*>((yysemantic_stack_[(4) - (2)].node));
          (yyval.expr) = new JSONObjectInsertExpr(
              LOC((yyloc)),
              new JSONDirectObjectConstructor(
                  LOC((yyloc)),
                  jpl),
              (yysemantic_stack_[(4) - (4)].expr));
        }
    break;

  case 811:
/* Line 661 of lalr1.cc  */
#line 6619 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {

          driver.addCommonLanguageWarning((yylocation_stack_[(7) - (2)]), ZED(ZWST0009_JSON_KEYWORD_OPTIONAL));
          (yyval.expr) = new JSONArrayInsertExpr(LOC((yyloc)), (yysemantic_stack_[(7) - (2)].expr), (yysemantic_stack_[(7) - (4)].expr), (yysemantic_stack_[(7) - (7)].expr));
        }
    break;

  case 812:
/* Line 661 of lalr1.cc  */
#line 6629 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONArrayAppendExpr(LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
        }
    break;

  case 813:
/* Line 661 of lalr1.cc  */
#line 6636 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {

          driver.addCommonLanguageWarning((yylocation_stack_[(4) - (2)]), ZED(ZWST0009_JSON_KEYWORD_OPTIONAL));
          (yyval.expr) = new JSONArrayAppendExpr(LOC((yyloc)), (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr));
        }
    break;

  case 814:
/* Line 661 of lalr1.cc  */
#line 6646 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
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

  case 815:
/* Line 661 of lalr1.cc  */
#line 6671 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {

          driver.addCommonLanguageWarning((yylocation_stack_[(2) - (2)]), ZED(ZWST0009_JSON_KEYWORD_OPTIONAL));

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

  case 816:
/* Line 661 of lalr1.cc  */
#line 6700 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
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

  case 817:
/* Line 661 of lalr1.cc  */
#line 6728 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {

          driver.addCommonLanguageWarning((yylocation_stack_[(4) - (2)]), ZED(ZWST0009_JSON_KEYWORD_OPTIONAL));

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

  case 818:
/* Line 661 of lalr1.cc  */
#line 6760 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
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

  case 819:
/* Line 661 of lalr1.cc  */
#line 6787 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {

          driver.addCommonLanguageWarning((yylocation_stack_[(6) - (2)]), ZED(ZWST0009_JSON_KEYWORD_OPTIONAL));

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

  case 820:
/* Line 661 of lalr1.cc  */
#line 6819 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonItem);
        }
    break;

  case 821:
/* Line 661 of lalr1.cc  */
#line 6823 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonArray);
        }
    break;

  case 822:
/* Line 661 of lalr1.cc  */
#line 6827 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonObject);
        }
    break;

  case 825:
/* Line 661 of lalr1.cc  */
#line 6845 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))); }
    break;

  case 826:
/* Line 661 of lalr1.cc  */
#line 6846 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("attribute"))); }
    break;

  case 827:
/* Line 661 of lalr1.cc  */
#line 6847 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("comment"))); }
    break;

  case 828:
/* Line 661 of lalr1.cc  */
#line 6848 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("document-node"))); }
    break;

  case 829:
/* Line 661 of lalr1.cc  */
#line 6849 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("namespace-node"))); }
    break;

  case 830:
/* Line 661 of lalr1.cc  */
#line 6850 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("element"))); }
    break;

  case 831:
/* Line 661 of lalr1.cc  */
#line 6851 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("item"))); }
    break;

  case 832:
/* Line 661 of lalr1.cc  */
#line 6852 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("if"))); }
    break;

  case 833:
/* Line 661 of lalr1.cc  */
#line 6853 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("node"))); }
    break;

  case 834:
/* Line 661 of lalr1.cc  */
#line 6854 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("processing-instruction"))); }
    break;

  case 835:
/* Line 661 of lalr1.cc  */
#line 6855 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema-attribute"))); }
    break;

  case 836:
/* Line 661 of lalr1.cc  */
#line 6856 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema-element"))); }
    break;

  case 837:
/* Line 661 of lalr1.cc  */
#line 6857 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("text"))); }
    break;

  case 838:
/* Line 661 of lalr1.cc  */
#line 6858 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("typeswitch"))); }
    break;

  case 839:
/* Line 661 of lalr1.cc  */
#line 6859 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("switch"))); }
    break;

  case 840:
/* Line 661 of lalr1.cc  */
#line 6860 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("empty-sequence"))); }
    break;

  case 841:
/* Line 661 of lalr1.cc  */
#line 6861 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("while"))); }
    break;

  case 842:
/* Line 661 of lalr1.cc  */
#line 6862 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("json"))); }
    break;

  case 843:
/* Line 661 of lalr1.cc  */
#line 6863 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("array"))); }
    break;

  case 844:
/* Line 661 of lalr1.cc  */
#line 6864 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("object"))); }
    break;

  case 845:
/* Line 661 of lalr1.cc  */
#line 6865 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("json-item"))); }
    break;

  case 846:
/* Line 661 of lalr1.cc  */
#line 6866 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("structured-item"))); }
    break;

  case 848:
/* Line 661 of lalr1.cc  */
#line 6871 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))); }
    break;

  case 849:
/* Line 661 of lalr1.cc  */
#line 6872 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("xquery"))); }
    break;

  case 850:
/* Line 661 of lalr1.cc  */
#line 6873 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("empty"))); }
    break;

  case 851:
/* Line 661 of lalr1.cc  */
#line 6874 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("boundary-space"))); }
    break;

  case 852:
/* Line 661 of lalr1.cc  */
#line 6875 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ft-option"))); }
    break;

  case 853:
/* Line 661 of lalr1.cc  */
#line 6876 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("base-uri"))); }
    break;

  case 854:
/* Line 661 of lalr1.cc  */
#line 6877 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lax"))); }
    break;

  case 855:
/* Line 661 of lalr1.cc  */
#line 6878 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("strict"))); }
    break;

  case 856:
/* Line 661 of lalr1.cc  */
#line 6879 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("idiv"))); }
    break;

  case 857:
/* Line 661 of lalr1.cc  */
#line 6880 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("document"))); }
    break;

  case 858:
/* Line 661 of lalr1.cc  */
#line 6881 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ftnot"))); }
    break;

  case 859:
/* Line 661 of lalr1.cc  */
#line 6882 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("not"))); }
    break;

  case 860:
/* Line 661 of lalr1.cc  */
#line 6883 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sensitive"))); }
    break;

  case 861:
/* Line 661 of lalr1.cc  */
#line 6884 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("insensitive"))); }
    break;

  case 862:
/* Line 661 of lalr1.cc  */
#line 6885 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("diacritics"))); }
    break;

  case 863:
/* Line 661 of lalr1.cc  */
#line 6886 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("without"))); }
    break;

  case 864:
/* Line 661 of lalr1.cc  */
#line 6887 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stemming"))); }
    break;

  case 865:
/* Line 661 of lalr1.cc  */
#line 6888 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("thesaurus"))); }
    break;

  case 866:
/* Line 661 of lalr1.cc  */
#line 6889 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stop"))); }
    break;

  case 867:
/* Line 661 of lalr1.cc  */
#line 6890 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("wildcards"))); }
    break;

  case 868:
/* Line 661 of lalr1.cc  */
#line 6891 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("entire"))); }
    break;

  case 869:
/* Line 661 of lalr1.cc  */
#line 6892 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("content"))); }
    break;

  case 870:
/* Line 661 of lalr1.cc  */
#line 6893 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("word"))); }
    break;

  case 871:
/* Line 661 of lalr1.cc  */
#line 6894 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("start"))); }
    break;

  case 872:
/* Line 661 of lalr1.cc  */
#line 6895 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("end"))); }
    break;

  case 873:
/* Line 661 of lalr1.cc  */
#line 6896 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("most"))); }
    break;

  case 874:
/* Line 661 of lalr1.cc  */
#line 6897 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("skip"))); }
    break;

  case 875:
/* Line 661 of lalr1.cc  */
#line 6898 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("copy"))); }
    break;

  case 876:
/* Line 661 of lalr1.cc  */
#line 6899 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("general"))); }
    break;

  case 877:
/* Line 661 of lalr1.cc  */
#line 6900 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("value"))); }
    break;

  case 878:
/* Line 661 of lalr1.cc  */
#line 6901 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("eq"))); }
    break;

  case 879:
/* Line 661 of lalr1.cc  */
#line 6902 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ne"))); }
    break;

  case 880:
/* Line 661 of lalr1.cc  */
#line 6903 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lt"))); }
    break;

  case 881:
/* Line 661 of lalr1.cc  */
#line 6904 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("le"))); }
    break;

  case 882:
/* Line 661 of lalr1.cc  */
#line 6905 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("gt"))); }
    break;

  case 883:
/* Line 661 of lalr1.cc  */
#line 6906 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ge"))); }
    break;

  case 884:
/* Line 661 of lalr1.cc  */
#line 6907 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("at"))); }
    break;

  case 885:
/* Line 661 of lalr1.cc  */
#line 6908 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("context"))); }
    break;

  case 886:
/* Line 661 of lalr1.cc  */
#line 6909 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("variable"))); }
    break;

  case 887:
/* Line 661 of lalr1.cc  */
#line 6910 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("return"))); }
    break;

  case 888:
/* Line 661 of lalr1.cc  */
#line 6911 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("for"))); }
    break;

  case 889:
/* Line 661 of lalr1.cc  */
#line 6912 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("from"))); }
    break;

  case 890:
/* Line 661 of lalr1.cc  */
#line 6913 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("allowing"))); }
    break;

  case 891:
/* Line 661 of lalr1.cc  */
#line 6914 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sliding"))); }
    break;

  case 892:
/* Line 661 of lalr1.cc  */
#line 6915 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("tumbling"))); }
    break;

  case 893:
/* Line 661 of lalr1.cc  */
#line 6916 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("previous"))); }
    break;

  case 894:
/* Line 661 of lalr1.cc  */
#line 6917 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("next"))); }
    break;

  case 895:
/* Line 661 of lalr1.cc  */
#line 6918 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("only"))); }
    break;

  case 896:
/* Line 661 of lalr1.cc  */
#line 6919 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("when"))); }
    break;

  case 897:
/* Line 661 of lalr1.cc  */
#line 6920 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("count"))); }
    break;

  case 898:
/* Line 661 of lalr1.cc  */
#line 6921 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("in"))); }
    break;

  case 899:
/* Line 661 of lalr1.cc  */
#line 6922 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("let"))); }
    break;

  case 900:
/* Line 661 of lalr1.cc  */
#line 6923 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("where"))); }
    break;

  case 901:
/* Line 661 of lalr1.cc  */
#line 6924 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("by"))); }
    break;

  case 902:
/* Line 661 of lalr1.cc  */
#line 6925 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("group"))); }
    break;

  case 903:
/* Line 661 of lalr1.cc  */
#line 6926 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("order"))); }
    break;

  case 904:
/* Line 661 of lalr1.cc  */
#line 6927 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stable"))); }
    break;

  case 905:
/* Line 661 of lalr1.cc  */
#line 6928 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ascending"))); }
    break;

  case 906:
/* Line 661 of lalr1.cc  */
#line 6929 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descending"))); }
    break;

  case 907:
/* Line 661 of lalr1.cc  */
#line 6930 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("greatest"))); }
    break;

  case 908:
/* Line 661 of lalr1.cc  */
#line 6931 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("least"))); }
    break;

  case 909:
/* Line 661 of lalr1.cc  */
#line 6932 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("collation"))); }
    break;

  case 910:
/* Line 661 of lalr1.cc  */
#line 6933 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("some"))); }
    break;

  case 911:
/* Line 661 of lalr1.cc  */
#line 6934 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("every"))); }
    break;

  case 912:
/* Line 661 of lalr1.cc  */
#line 6935 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("satisfies"))); }
    break;

  case 913:
/* Line 661 of lalr1.cc  */
#line 6936 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("case"))); }
    break;

  case 914:
/* Line 661 of lalr1.cc  */
#line 6937 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("as"))); }
    break;

  case 915:
/* Line 661 of lalr1.cc  */
#line 6938 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("then"))); }
    break;

  case 916:
/* Line 661 of lalr1.cc  */
#line 6939 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("else"))); }
    break;

  case 917:
/* Line 661 of lalr1.cc  */
#line 6940 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("or"))); }
    break;

  case 918:
/* Line 661 of lalr1.cc  */
#line 6941 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("and"))); }
    break;

  case 919:
/* Line 661 of lalr1.cc  */
#line 6942 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("instance"))); }
    break;

  case 920:
/* Line 661 of lalr1.cc  */
#line 6943 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("of"))); }
    break;

  case 921:
/* Line 661 of lalr1.cc  */
#line 6944 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("castable"))); }
    break;

  case 922:
/* Line 661 of lalr1.cc  */
#line 6945 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("to"))); }
    break;

  case 923:
/* Line 661 of lalr1.cc  */
#line 6946 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("div"))); }
    break;

  case 924:
/* Line 661 of lalr1.cc  */
#line 6947 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("mod"))); }
    break;

  case 925:
/* Line 661 of lalr1.cc  */
#line 6948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("union"))); }
    break;

  case 926:
/* Line 661 of lalr1.cc  */
#line 6949 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("intersect"))); }
    break;

  case 927:
/* Line 661 of lalr1.cc  */
#line 6950 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("except"))); }
    break;

  case 928:
/* Line 661 of lalr1.cc  */
#line 6951 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("validate"))); }
    break;

  case 929:
/* Line 661 of lalr1.cc  */
#line 6952 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("type"))); }
    break;

  case 930:
/* Line 661 of lalr1.cc  */
#line 6953 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("cast"))); }
    break;

  case 931:
/* Line 661 of lalr1.cc  */
#line 6954 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("treat"))); }
    break;

  case 932:
/* Line 661 of lalr1.cc  */
#line 6955 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("is"))); }
    break;

  case 933:
/* Line 661 of lalr1.cc  */
#line 6956 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preserve"))); }
    break;

  case 934:
/* Line 661 of lalr1.cc  */
#line 6957 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("strip"))); }
    break;

  case 935:
/* Line 661 of lalr1.cc  */
#line 6958 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("namespace"))); }
    break;

  case 936:
/* Line 661 of lalr1.cc  */
#line 6959 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("external"))); }
    break;

  case 937:
/* Line 661 of lalr1.cc  */
#line 6960 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("encoding"))); }
    break;

  case 938:
/* Line 661 of lalr1.cc  */
#line 6961 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("no-preserve"))); }
    break;

  case 939:
/* Line 661 of lalr1.cc  */
#line 6962 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("inherit"))); }
    break;

  case 940:
/* Line 661 of lalr1.cc  */
#line 6963 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("no-inherit"))); }
    break;

  case 941:
/* Line 661 of lalr1.cc  */
#line 6964 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("declare"))); }
    break;

  case 942:
/* Line 661 of lalr1.cc  */
#line 6965 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("construction"))); }
    break;

  case 943:
/* Line 661 of lalr1.cc  */
#line 6966 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ordering"))); }
    break;

  case 944:
/* Line 661 of lalr1.cc  */
#line 6967 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("default"))); }
    break;

  case 945:
/* Line 661 of lalr1.cc  */
#line 6968 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("copy-namespaces"))); }
    break;

  case 946:
/* Line 661 of lalr1.cc  */
#line 6969 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("option"))); }
    break;

  case 947:
/* Line 661 of lalr1.cc  */
#line 6970 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("version"))); }
    break;

  case 948:
/* Line 661 of lalr1.cc  */
#line 6971 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("import"))); }
    break;

  case 949:
/* Line 661 of lalr1.cc  */
#line 6972 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema"))); }
    break;

  case 950:
/* Line 661 of lalr1.cc  */
#line 6973 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("module"))); }
    break;

  case 951:
/* Line 661 of lalr1.cc  */
#line 6974 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("function"))); }
    break;

  case 952:
/* Line 661 of lalr1.cc  */
#line 6975 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("score"))); }
    break;

  case 953:
/* Line 661 of lalr1.cc  */
#line 6976 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("contains"))); }
    break;

  case 954:
/* Line 661 of lalr1.cc  */
#line 6977 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("weight"))); }
    break;

  case 955:
/* Line 661 of lalr1.cc  */
#line 6978 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("window"))); }
    break;

  case 956:
/* Line 661 of lalr1.cc  */
#line 6979 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("distance"))); }
    break;

  case 957:
/* Line 661 of lalr1.cc  */
#line 6980 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("occurs"))); }
    break;

  case 958:
/* Line 661 of lalr1.cc  */
#line 6981 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("times"))); }
    break;

  case 959:
/* Line 661 of lalr1.cc  */
#line 6982 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("same"))); }
    break;

  case 960:
/* Line 661 of lalr1.cc  */
#line 6983 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("different"))); }
    break;

  case 961:
/* Line 661 of lalr1.cc  */
#line 6984 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lowercase"))); }
    break;

  case 962:
/* Line 661 of lalr1.cc  */
#line 6985 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("uppercase"))); }
    break;

  case 963:
/* Line 661 of lalr1.cc  */
#line 6986 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("relationship"))); }
    break;

  case 964:
/* Line 661 of lalr1.cc  */
#line 6987 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("levels"))); }
    break;

  case 965:
/* Line 661 of lalr1.cc  */
#line 6988 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("language"))); }
    break;

  case 966:
/* Line 661 of lalr1.cc  */
#line 6989 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("any"))); }
    break;

  case 967:
/* Line 661 of lalr1.cc  */
#line 6990 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("all"))); }
    break;

  case 968:
/* Line 661 of lalr1.cc  */
#line 6991 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("exactly"))); }
    break;

  case 969:
/* Line 661 of lalr1.cc  */
#line 6992 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("words"))); }
    break;

  case 970:
/* Line 661 of lalr1.cc  */
#line 6993 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sentences"))); }
    break;

  case 971:
/* Line 661 of lalr1.cc  */
#line 6994 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sentence"))); }
    break;

  case 972:
/* Line 661 of lalr1.cc  */
#line 6995 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("phrase"))); }
    break;

  case 973:
/* Line 661 of lalr1.cc  */
#line 6996 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("paragraph"))); }
    break;

  case 974:
/* Line 661 of lalr1.cc  */
#line 6997 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("paragraphs"))); }
    break;

  case 975:
/* Line 661 of lalr1.cc  */
#line 6998 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("modify"))); }
    break;

  case 976:
/* Line 661 of lalr1.cc  */
#line 6999 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("first"))); }
    break;

  case 977:
/* Line 661 of lalr1.cc  */
#line 7000 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("append"))); }
    break;

  case 978:
/* Line 661 of lalr1.cc  */
#line 7001 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("insert"))); }
    break;

  case 979:
/* Line 661 of lalr1.cc  */
#line 7002 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("replace"))); }
    break;

  case 980:
/* Line 661 of lalr1.cc  */
#line 7003 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("rename"))); }
    break;

  case 981:
/* Line 661 of lalr1.cc  */
#line 7004 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("delete"))); }
    break;

  case 982:
/* Line 661 of lalr1.cc  */
#line 7005 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("before"))); }
    break;

  case 983:
/* Line 661 of lalr1.cc  */
#line 7006 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("after"))); }
    break;

  case 984:
/* Line 661 of lalr1.cc  */
#line 7007 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("revalidation"))); }
    break;

  case 985:
/* Line 661 of lalr1.cc  */
#line 7008 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("with"))); }
    break;

  case 986:
/* Line 661 of lalr1.cc  */
#line 7009 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("nodes"))); }
    break;

  case 987:
/* Line 661 of lalr1.cc  */
#line 7010 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("last"))); }
    break;

  case 988:
/* Line 661 of lalr1.cc  */
#line 7011 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("into"))); }
    break;

  case 989:
/* Line 661 of lalr1.cc  */
#line 7012 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("simple"))); }
    break;

  case 990:
/* Line 661 of lalr1.cc  */
#line 7013 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sequential"))); }
    break;

  case 991:
/* Line 661 of lalr1.cc  */
#line 7014 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("updating"))); }
    break;

  case 992:
/* Line 661 of lalr1.cc  */
#line 7015 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ordered"))); }
    break;

  case 993:
/* Line 661 of lalr1.cc  */
#line 7016 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("unordered"))); }
    break;

  case 994:
/* Line 661 of lalr1.cc  */
#line 7017 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("returning"))); }
    break;

  case 995:
/* Line 661 of lalr1.cc  */
#line 7018 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("exit"))); }
    break;

  case 996:
/* Line 661 of lalr1.cc  */
#line 7019 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("loop"))); }
    break;

  case 997:
/* Line 661 of lalr1.cc  */
#line 7020 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("break"))); }
    break;

  case 998:
/* Line 661 of lalr1.cc  */
#line 7021 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("continue"))); }
    break;

  case 999:
/* Line 661 of lalr1.cc  */
#line 7022 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("try"))); }
    break;

  case 1000:
/* Line 661 of lalr1.cc  */
#line 7023 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("catch"))); }
    break;

  case 1001:
/* Line 661 of lalr1.cc  */
#line 7024 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("using"))); }
    break;

  case 1002:
/* Line 661 of lalr1.cc  */
#line 7025 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("set"))); }
    break;

  case 1003:
/* Line 661 of lalr1.cc  */
#line 7026 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("index"))); }
    break;

  case 1004:
/* Line 661 of lalr1.cc  */
#line 7027 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("unique"))); }
    break;

  case 1005:
/* Line 661 of lalr1.cc  */
#line 7028 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("non"))); }
    break;

  case 1006:
/* Line 661 of lalr1.cc  */
#line 7029 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("on"))); }
    break;

  case 1007:
/* Line 661 of lalr1.cc  */
#line 7030 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("range"))); }
    break;

  case 1008:
/* Line 661 of lalr1.cc  */
#line 7031 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("equality"))); }
    break;

  case 1009:
/* Line 661 of lalr1.cc  */
#line 7032 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("manually"))); }
    break;

  case 1010:
/* Line 661 of lalr1.cc  */
#line 7033 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("automatically"))); }
    break;

  case 1011:
/* Line 661 of lalr1.cc  */
#line 7034 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("maintained"))); }
    break;

  case 1012:
/* Line 661 of lalr1.cc  */
#line 7035 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("decimal-format"))); }
    break;

  case 1013:
/* Line 661 of lalr1.cc  */
#line 7036 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("decimal-separator"))); }
    break;

  case 1014:
/* Line 661 of lalr1.cc  */
#line 7037 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("grouping-separator"))); }
    break;

  case 1015:
/* Line 661 of lalr1.cc  */
#line 7038 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("infinity"))); }
    break;

  case 1016:
/* Line 661 of lalr1.cc  */
#line 7039 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("minus-sign"))); }
    break;

  case 1017:
/* Line 661 of lalr1.cc  */
#line 7040 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("NaN"))); }
    break;

  case 1018:
/* Line 661 of lalr1.cc  */
#line 7041 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("percent"))); }
    break;

  case 1019:
/* Line 661 of lalr1.cc  */
#line 7042 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("per-mille"))); }
    break;

  case 1020:
/* Line 661 of lalr1.cc  */
#line 7043 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("zero-digit"))); }
    break;

  case 1021:
/* Line 661 of lalr1.cc  */
#line 7044 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("digit"))); }
    break;

  case 1022:
/* Line 661 of lalr1.cc  */
#line 7045 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("pattern-separator"))); }
    break;

  case 1023:
/* Line 661 of lalr1.cc  */
#line 7046 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("collection"))); }
    break;

  case 1024:
/* Line 661 of lalr1.cc  */
#line 7047 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("const"))); }
    break;

  case 1025:
/* Line 661 of lalr1.cc  */
#line 7048 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("append-only"))); }
    break;

  case 1026:
/* Line 661 of lalr1.cc  */
#line 7049 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("queue"))); }
    break;

  case 1027:
/* Line 661 of lalr1.cc  */
#line 7050 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("mutable"))); }
    break;

  case 1028:
/* Line 661 of lalr1.cc  */
#line 7051 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("read-only"))); }
    break;

  case 1029:
/* Line 661 of lalr1.cc  */
#line 7052 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("integrity"))); }
    break;

  case 1030:
/* Line 661 of lalr1.cc  */
#line 7053 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("constraint"))); }
    break;

  case 1031:
/* Line 661 of lalr1.cc  */
#line 7054 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("check"))); }
    break;

  case 1032:
/* Line 661 of lalr1.cc  */
#line 7055 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("key"))); }
    break;

  case 1033:
/* Line 661 of lalr1.cc  */
#line 7056 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("foreach"))); }
    break;

  case 1034:
/* Line 661 of lalr1.cc  */
#line 7057 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("foreign"))); }
    break;

  case 1035:
/* Line 661 of lalr1.cc  */
#line 7058 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("keys"))); }
    break;

  case 1036:
/* Line 661 of lalr1.cc  */
#line 7059 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ancestor"))); }
    break;

  case 1037:
/* Line 661 of lalr1.cc  */
#line 7060 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("child"))); }
    break;

  case 1038:
/* Line 661 of lalr1.cc  */
#line 7061 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descendant"))); }
    break;

  case 1039:
/* Line 661 of lalr1.cc  */
#line 7062 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("parent"))); }
    break;

  case 1040:
/* Line 661 of lalr1.cc  */
#line 7063 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preceding"))); }
    break;

  case 1041:
/* Line 661 of lalr1.cc  */
#line 7064 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("self"))); }
    break;

  case 1042:
/* Line 661 of lalr1.cc  */
#line 7065 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("following"))); }
    break;

  case 1043:
/* Line 661 of lalr1.cc  */
#line 7066 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ancestor-or-self"))); }
    break;

  case 1044:
/* Line 661 of lalr1.cc  */
#line 7067 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descendant-or-self"))); }
    break;

  case 1045:
/* Line 661 of lalr1.cc  */
#line 7068 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("following-sibling"))); }
    break;

  case 1046:
/* Line 661 of lalr1.cc  */
#line 7069 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preceding-sibling"))); }
    break;

  case 1047:
/* Line 661 of lalr1.cc  */
#line 7070 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("position"))); }
    break;

  case 1048:
/* Line 661 of lalr1.cc  */
#line 7072 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("null"))); }
    break;

  case 1049:
/* Line 661 of lalr1.cc  */
#line 7073 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("true"))); }
    break;

  case 1050:
/* Line 661 of lalr1.cc  */
#line 7074 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("false"))); }
    break;

  case 1051:
/* Line 661 of lalr1.cc  */
#line 7075 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("select"))); }
    break;

  case 1052:
/* Line 661 of lalr1.cc  */
#line 7076 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("jsoniq"))); }
    break;

  case 1053:
/* Line 661 of lalr1.cc  */
#line 7082 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), true); }
    break;


/* Line 661 of lalr1.cc  */
#line 11050 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
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
    while (yystate_stack_.height () != 1)
      {
	yydestruct_ ("Cleanup: popping",
		   yystos_[yystate_stack_[0]],
		   &yysemantic_stack_[0],
		   &yylocation_stack_[0]);
	yypop_ ();
      }

    return yyresult;
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
  const short int jsoniq_parser::yypact_ninf_ = -1566;
  const short int
  jsoniq_parser::yypact_[] =
  {
      5342, -1566, -1566, -1566, -1566,  6294,  6294,  6294,  6294, -1566,
   -1566,    23,    48, -1566,   127,   261, -1566, -1566, -1566,   476,
   -1566, -1566, -1566,   201,   298,   756,  4827,   472,   548,   840,
   -1566,   -26, -1566,   573, -1566, -1566, -1566, -1566, -1566,   829,
   -1566,   605,   619, -1566, -1566, -1566, -1566,   685, -1566,   834,
   -1566,   729,   799, -1566,   314, -1566, -1566, -1566, -1566, -1566,
   -1566, -1566, -1566, -1566, -1566, -1566, -1566, -1566, -1566,   839,
     862, -1566, -1566, -1566, -1566,   703, 15458, -1566, -1566, -1566,
     867, -1566, -1566, -1566,   876, -1566,   873,   875, -1566, -1566,
   20328, -1566, -1566, -1566, -1566, -1566, -1566, -1566, -1566,   896,
   -1566, -1566,   894,   899, -1566, -1566, -1566, -1566, -1566, -1566,
   -1566,  6294,  8822,  9138, 20328, -1566, -1566,   870, -1566, -1566,
   -1566, -1566,   874, -1566, -1566,   908, 20328, -1566, 17006,   912,
     915, -1566, -1566, -1566, -1566,   925, -1566, -1566, 13246, -1566,
   -1566, -1566, -1566, -1566, -1566,   895, -1566, -1566, -1566, -1566,
   -1566, -1566, -1566, -1566,   147, -1566,   833, -1566, -1566, -1566,
   -1566, -1566, -1566, -1566, -1566, -1566, -1566, -1566, 21238,   898,
   16090, -1566, 21540,   -78, -1566, -1566, -1566, -1566, -1566, -1566,
     934, -1566,   807,   810,   811, -1566, -1566,   900,   905, -1566,
   -1566, -1566, -1566, -1566, -1566, -1566, -1566, -1566, -1566, -1566,
   -1566,  5054, -1566, 13878, -1566, -1566, -1566, -1566, -1566, -1566,
   -1566, -1566, -1566, -1566, -1566, -1566, -1566, -1566, -1566, -1566,
   -1566, -1566, -1566, -1566, -1566, -1566, -1566, -1566, -1566, -1566,
   -1566, -1566, -1566, -1566, -1566, -1566, -1566, -1566, -1566, -1566,
   -1566, -1566, -1566, -1566, -1566, -1566, -1566, -1566, -1566, -1566,
   -1566, -1566,  9454,  9770, -1566, 14194, -1566, -1566, -1566, -1566,
   -1566,  5660,  6610,  1061, -1566,  6926, -1566, -1566,   740,    95,
   -1566, -1566, -1566, -1566, -1566, -1566, -1566, -1566, -1566, -1566,
   -1566, -1566, -1566, -1566,   101, -1566, -1566, -1566, -1566, -1566,
   -1566,   588, -1566, -1566, -1566, -1566, -1566, -1566, -1566, -1566,
    6294, -1566, -1566, -1566, -1566,    37, -1566, -1566, -1566, -1566,
   -1566, -1566, -1566, -1566, -1566,   125, -1566,   872, -1566, -1566,
   -1566,   725, -1566,   434, -1566, -1566, -1566, -1566, -1566, -1566,
   -1566,   897,   974, -1566, -1566,  1079,   814,   970,   670,   554,
     566,   700, -1566,  1021,   879,   972,   973, 11034, -1566,   880,
   -1566, -1566,    11, -1566, -1566, 13562, -1566,   789, -1566,   916,
   15458, -1566,   916, 15458, -1566, -1566, -1566,    42, -1566, -1566,
   -1566, -1566, -1566, -1566, -1566, -1566, -1566, -1566, -1566, -1566,
   -1566, -1566, -1566, -1566, -1566, -1566, -1566, -1566, -1566, -1566,
   -1566, -1566, -1566, -1566, -1566,   920, -1566, -1566, -1566, -1566,
   -1566, -1566, -1566, -1566, -1566, -1566, -1566, -1566, -1566, -1566,
   -1566, -1566, -1566, -1566, -1566, -1566, -1566, -1566, -1566, -1566,
   -1566, -1566, -1566,   794, -1566, -1566, -1566, -1566, -1566,   892,
   -1566,  6294,   902,   903,   914,  6294,    93,    93,  1052,   270,
     276,   454, 21838, 20328,   437,  1036, 20328,   931,   978,   672,
   20328,   777,   848, 20328, 20328,   791,   828,    44, -1566, -1566,
   -1566, 20328,  6294,   917,  6294,   394, 11350, 17308, 20328,   489,
     947, 11350,  1102,   374,   363, 20328,   985,   963,  1000, -1566,
     921, 11350, 17610, 20328, 20328, 20328,  6294,   923, 11350, 11350,
   20328,  6294,   957,   958, -1566, -1566, -1566, 11350, 17912,   956,
   -1566,   959, -1566, -1566, -1566, -1566,   960, -1566,   961, -1566,
   -1566, -1566, -1566, -1566,   962, -1566, -1566, -1566, -1566, -1566,
   -1566, -1566, -1566, -1566, -1566, -1566, -1566, -1566, -1566, -1566,
   -1566, -1566, -1566, -1566, -1566, -1566, -1566, -1566, -1566, -1566,
   -1566, -1566, -1566, -1566, -1566, 20328, -1566, -1566, -1566, -1566,
   -1566, -1566, -1566, -1566, -1566, -1566, -1566, -1566, -1566,   977,
   20328, -1566, -1566,   937,  5978,   993,   382,  1002,   968,   975,
     979, 20328,  6294, -1566,   976,   142, -1566,   725, -1566,   139,
    1092, 11350, 11350, -1566,   203, -1566, -1566,  1113, -1566, -1566,
   -1566, -1566, 11350,   922, -1566,  1105,   981,   984,   986,   987,
     990, 11350, 12614, 20936,    42,   794, 14510, 15142, 14826,   -18,
     340, 11350, 20936,   628, 11350,   909,   904, 20328,   940,   955,
   11350, 11350,  6294,   907, 20328, -1566, -1566,    64, -1566,    65,
   14826,   910,  6610, -1566, -1566, -1566, -1566, -1566,   127,   840,
     113,   115,  1145,  7242,  3541,  7558,  3868,   876, -1566, -1566,
     176,   876, -1566, 11350,  4500, -1566,  1032,   784,   -26,   992,
     982,   991, -1566, -1566, 11350,   819, -1566, -1566,  6294, -1566,
   -1566, -1566, -1566, -1566, -1566, -1566,   878,   883, 20328,  1044,
   11666, 11666, 11982, -1566, 11982, 11982, -1566, 11982, -1566, 11982,
   -1566, -1566, -1566, -1566, -1566, -1566, -1566, 11982, 11982,  1093,
   11982, 11982, 11982, 11982, 11982, 11982, 11982, 11982, 11982, 11982,
   11982, 11982,   930,  1074,  1081,  1082, -1566, -1566, -1566, 12930,
    6294, -1566, -1566, 13246, 13246, 11350,   916, -1566, -1566,   916,
   -1566, 16393, 10086,  8190,   916,   995,  1023,  8506, -1566, -1566,
   -1566, -1566,    13, -1566,    36, -1566, -1566, -1566, -1566, -1566,
   -1566,  1071,  1073,   472,  1155, -1566, -1566, 21838,  1355,   736,
   20328,  1024,  1026,  1355,  1052,  1062,  1056, -1566, -1566, -1566,
     473,   941,  1097,   889, 20328,  1051, 11350,  1077, 20328, 20328,
   -1566,  1063,  1013, -1566,  1020,   959,   619, -1566,  1018,  1019,
     195, -1566,   324,   335,  1103, -1566,    39, 20328,  1115,   338,
   -1566,  6294, -1566,   146, -1566, 20328,  1117,  1170, 20328,  1052,
    1119,   349, 20328, 11350,   -26, -1566,   267,  1029, -1566,  1030,
    1031,  1035,    25, -1566,    66,  1040, -1566,   151,   159,  1065,
   -1566,  1041,  6294,  6294,   375, -1566,   347,   468,   649, 11350,
      29, -1566, -1566, 11350, 11350, -1566, 11350, 11350, 11350, 11350,
   -1566, 11350, -1566, 11350, -1566, 20328,  1092, -1566,   317,   377,
     402, -1566, -1566, -1566,   406, -1566,    17, -1566, -1566,    42,
     264,   307,   306,   342, 11350, 11350,  1132,   687, 11350,   988,
   20634,   996,   114, -1566,  1085, -1566, -1566,  1038,   161,  5978,
     409, 15774,   907, -1566,  1103, -1566, -1566,   998, 11350, -1566,
     740,   750,  1201,   632, -1566, -1566,   123, -1566, -1566, -1566,
     128, -1566,   199, -1566, -1566, -1566, -1566, -1566,  4184, -1566,
   -1566, -1566, 20328,  1064, 11350, 12298, -1566, -1566, -1566, -1566,
   -1566,  1103, 20328,    28,   974, -1566, -1566, -1566, -1566, -1566,
   11982, -1566, -1566, -1566,    79, -1566,   554,   554,    20,   566,
     566,   566,   566,   700,   700, -1566, -1566, 19422, 19422, 20328,
   20328, -1566,  1054, -1566, -1566,   259, -1566, 10402, -1566, -1566,
   -1566, -1566, -1566, -1566, -1566,   478, -1566, -1566, -1566,   485,
      93, -1566, -1566,   624,   625,    53, -1566,   472, -1566, -1566,
   -1566, -1566, -1566, -1566, -1566, -1566, -1566, -1566,  1355, -1566,
    1106, 19724,  1098, 11350, -1566, -1566, -1566,  1146,  1052,  1052,
    1355, -1566,   871,  1052,   692, 20328,   679,   682,  1215, -1566,
   -1566,   954,   701, -1566, -1566, -1566, -1566, -1566, -1566, -1566,
   -1566, -1566, -1566, -1566,   473,    41,  1014,   642, 11350, -1566,
   20328,  1153,   944,  1052, -1566, -1566, -1566, -1566,  1096, 20328,
   -1566, 20328, -1566, 20026,  1123, 19422,  1134, 11350,   -41,  1107,
      45,  1146, 19422,  1135,  1160,  1072,  1060,  1127,  1052,  1100,
    1129,  1167,  1052, 11350,   -56, -1566, -1566, -1566,  1110, -1566,
   -1566, -1566, -1566,  1147, 11350, 11350,  1118, -1566,  1168,  1169,
    6294, -1566,  1086,  1087,  1121, 20328, -1566, 20328, -1566, 11350,
    1130,  1088, 11350, -1566,  1150,  1158, -1566,   182,   186,   194,
    1243, -1566,   492, -1566,   698,  1138, -1566, -1566,  1252, -1566,
     431, 11350, 11350, 11350,   626, 11350, 11350, 11350, 11350, 11350,
    1193, -1566, 11350, 11350, -1566, 11350, 11350,   355, 20936,  1178,
   11350, 11350, -1566,  7874,   137,  1048, -1566,   285, -1566, 11350,
   -1566,   134,   359,   199,  7558,  3868,  7558,  1220, -1566, -1566,
   11350,   800,  1198, -1566, 20328,  1194,  1204, -1566,   514,  1049,
   -1566, -1566,   757,    28, -1566, 11350,    79,   525,   316, -1566,
    1022,    82,  1057,  1050, -1566, -1566,   848, -1566,  1042,   677,
    1162,  1164, 18214,  1166,  1173,  1174,  1176,  1177, -1566,   673,
   -1566, -1566, -1566, -1566, -1566, -1566, -1566, -1566, -1566, -1566,
    1172, -1566, -1566, -1566, -1566, -1566,   224, 10718, -1566, -1566,
   -1566, -1566, -1566, -1566, -1566, -1566, -1566,   761, -1566,  1295,
   19724,   841, -1566, -1566, -1566, -1566, -1566, -1566, -1566, -1566,
   -1566,  1045, -1566, -1566,  1297, -1566, -1566, -1566, -1566, -1566,
     712,  1298, -1566,    96, -1566, -1566, -1566,   956,   298,   573,
     960,   605,   961,   962, -1566,  1173,  1174,  1176, -1566,   673,
     673, 12930,  1043,  1027, -1566,  1146,    41,  1108,  1151,  6294,
    1154,  1156,  1200,  1159,  1163, 20328, -1566,   530, -1566, 20328,
   -1566, 11350,  1199, 11350,  1223, 11350,   -21,  1206, -1566, -1566,
   -1566, 19422, -1566,  6294,  1052,  1245, -1566, -1566, -1566,  1052,
    1245, -1566, 11350,  1212,  6294, 20328, -1566, -1566, 11350, 11350,
     634, -1566,   414,   805, -1566, 18516,   822, -1566,   831, -1566,
    1175, -1566, -1566,  6294,  1171,  1179, -1566, 11350, -1566, -1566,
   11350, 11350,  1182,  1168,  1257, -1566,  1229, -1566,   869, -1566,
   -1566,  1357, -1566, -1566,  6294, 20328, -1566,   969, -1566, -1566,
   -1566,  6294,  1183,  1137,  1139, -1566, -1566, -1566,  1140,  1144,
   -1566, -1566, -1566,  1269, -1566,  1046, -1566, -1566, -1566,  1131,
   11350,   444, 20328,   650, -1566,  1226,  1227,  1230,  1234, -1566,
     872,   725, 15774,  1048, -1566,  7874, 15774, -1566, -1566,  1201,
     420, -1566, -1566, -1566,  1198, -1566,  1052, -1566,   877, -1566,
     630,  1283, -1566, 11350,   666,  1052, -1566, 12298, 11350,  1244,
   -1566,  1273,  1277, 11350, 20328,   890,  1319, -1566, -1566, -1566,
     425,  1210, -1566,    79,  1143, -1566, -1566,   -61, -1566,   180,
     289,  1149,    79,   180, 11982, -1566,   131, -1566, -1566, -1566,
   -1566, -1566, -1566,    79,  1251,  1120,   941,   289, -1566, -1566,
    1122,  1331, -1566, -1566, -1566, 16695,  1225, -1566,  1228,  1231,
    1232,  1233,  1238,  1240, -1566, -1566, -1566, -1566, -1566, -1566,
   -1566, -1566, -1566, -1566, -1566, -1566, -1566, -1566,  1385,    10,
    1388,    10,  1152,  1314, -1566, -1566,  1259, 20328,  1184, -1566,
   -1566, 12930, -1566,  1246, -1566, -1566, -1566, -1566, -1566, -1566,
   11350,  1284, -1566, -1566, 11350, -1566,   560, -1566, 11350,  1299,
   11350, -1566,  1304,  1321,  1353,  1052,  1245, -1566, 11350,  1266,
   -1566, -1566, -1566,   650, -1566,   414, 11350,  6294,   650,   414,
   -1566, 20328,   480, -1566, 18818,   465, -1566, 19120,   650, -1566,
   -1566,  1267, -1566, -1566, -1566, -1566, -1566, 11350,   832,  1243,
   20328,  1053, -1566,  1270,  1243, 20328, -1566,  1271, -1566, 11350,
   11350, 11350, 11350,  1141, 11350, 11350, -1566, 11350, -1566, 11350,
   11350, 11350, 11350,  7874,   526, -1566, -1566, -1566, -1566, -1566,
    1283, -1566, -1566, -1566, 11350,  1310, -1566, -1566, -1566, 11350,
   20328, 20328, -1566,   823, -1566, 11350, -1566, -1566, -1566,  1272,
   11982, -1566, -1566, -1566, -1566, -1566,    89, 11982, 11982,   610,
   -1566,  1057, -1566,   413, -1566,  1050,    79,  1305, -1566, -1566,
    1180, -1566, -1566, -1566, -1566,  1364,  1279, -1566,   511, -1566,
   -1566, -1566, -1566, -1566, -1566, -1566, -1566,    54,    54, -1566,
      10, -1566, -1566,   512, -1566,  1431,   304,  1368,  1280, 12930,
     -40,  1181,  1300, -1566, -1566, 11350, -1566, 11350,  1320, -1566,
   11350, -1566,  7874, 11350,  1052, -1566, -1566, -1566, 11350, 11350,
   -1566, -1566, -1566,  7874,  7874,  1375, 19422,  6294, 20328,   480,
   20328, 11350, 20328,   480,  7874, -1566,   534,    52,  1243, 20328,
   -1566,  1276,  1243, -1566, -1566, -1566, -1566, -1566, 11350, -1566,
   -1566, -1566, -1566,   234,   250,   254, 11350, -1566, -1566,  1194,
   11350, -1566, -1566,  1418, -1566, -1566, -1566,   566, 11982, 11982,
      20,   721, -1566, -1566, -1566, -1566, -1566, -1566, 11350, -1566,
   19422, -1566, 19422,  1381, -1566, -1566, -1566,  1447, -1566, -1566,
   -1566,  1207,  1372, -1566, -1566,  1373, -1566,   847, 20328,  1363,
    1253, 20328, 12930, -1566, -1566, 11350, -1566, -1566, -1566,  1245,
   -1566, -1566, 19422, -1566, -1566, -1566,  1390, 11350,   650, -1566,
    1391,  7874, -1566, 20328,   470,   645, -1566,  1288,  1243, -1566,
    1289, -1566,  1292,  1168,  1169,   426, -1566,  1194,  1370,    20,
      20, 11982,   429, -1566, -1566, 19422, -1566, -1566,  1368, 12930,
   -1566,  1283,  1185, 20328,  1374,  1263,  1373, -1566,   480, 19422,
    6294, 19422,   650, -1566, -1566,  1389,   587, -1566, -1566, -1566,
   -1566,  1311,   669, -1566, -1566, -1566,  1301, -1566,  7874,   836,
   -1566, -1566, 20328,    20, -1566, -1566, -1566, -1566, -1566, 11350,
    1190, 20328,  1383,  6294,   480, -1566, -1566,   480, 11350, -1566,
   -1566, -1566, -1566, -1566, -1566, -1566,  1384, -1566, -1566,  1205,
    1195, 20328, -1566, -1566, 11350,  7874, 20328,  1196, 11350,  1197,
     650, 12930, -1566, 12930,  7874, -1566,  1306,  1217, 20328,  1274,
    1392, 20328,  1202, 12930, -1566
  };

  /* YYDEFACT[S] -- default reduction number in state S.  Performed when
     YYTABLE doesn't specify something else to do.  Zero means the
     default is an error.  */
  const unsigned short int
  jsoniq_parser::yydefact_[] =
  {
       165,   473,   474,   825,   475,   168,   168,   168,     0,   848,
    1053,   120,   122,   647,   941,   950,   890,   853,   851,   827,
     942,   945,   897,   857,   828,   830,     0,   951,   832,   948,
     919,   899,   873,   829,   894,   895,   946,   943,   893,   834,
     949,   835,   836,   990,  1002,   989,   891,   910,   904,   837,
     892,   839,   838,   991,   928,   929,   896,   870,  1012,  1013,
    1014,  1015,  1016,  1017,  1018,  1019,  1020,  1021,  1022,  1036,
    1043,   918,   914,   905,   884,   826,     0,   913,   921,   930,
    1037,   909,   505,   885,   886,   944,  1038,  1044,   906,   923,
       0,   511,   462,   507,   916,   850,   907,   908,   937,   911,
     927,   936,  1042,  1045,   856,   898,   939,   506,   926,   932,
     831,   168,     0,     0,     0,   409,   924,   935,   940,   938,
     917,   903,   992,   901,   902,  1039,     0,   408,     0,  1040,
    1046,   933,   887,   912,  1051,  1041,   211,   440,     0,   472,
     934,   915,   922,   931,   925,   993,   878,   883,   882,   881,
     880,   879,   840,   900,     0,   849,  1052,   947,   871,  1048,
    1049,  1050,   983,   982,   984,   855,   854,   874,   981,   833,
     978,   986,   980,   979,   877,   920,   976,   988,   987,   975,
     875,   985,   997,   998,   995,   996,   994,   841,   999,  1000,
    1001,   967,   966,   953,   869,   862,   960,   956,   872,   868,
     968,     0,   858,   859,   852,   861,   965,   964,   961,   957,
     973,   974,   972,   963,   959,   952,   860,   971,   970,   864,
     866,   865,   958,   962,   954,   867,   955,   863,   969,  1023,
    1024,  1025,  1026,  1027,  1028,  1004,  1005,  1003,  1009,  1010,
    1011,  1006,  1007,  1008,   876,  1029,  1030,  1031,  1032,  1033,
    1034,  1035,     0,     0,   842,   977,  1047,   844,   843,   845,
     846,   165,   165,     0,     2,   165,     9,    11,    23,     0,
      28,    31,    36,    37,    38,    39,    40,    41,    42,    32,
      58,    59,    33,    34,     0,    76,    79,    80,    35,    81,
      82,     0,   118,    83,    84,    85,    86,    18,   162,   163,
     164,   171,   174,   498,   175,     0,   176,   177,   178,   179,
     180,   181,   182,   185,   186,     0,   212,   220,   215,   249,
     255,     0,   247,     0,   248,   222,   216,   184,   217,   183,
     218,   221,   358,   360,   362,   364,   374,   376,   380,   382,
     385,   390,   393,   396,   398,   400,   402,     0,   406,   413,
     412,   414,     0,   431,   415,   436,   439,   441,   444,   446,
       0,   451,   448,     0,   459,   469,   471,   445,   476,   489,
     503,   490,   491,   492,   495,   496,   493,   497,   520,   521,
     494,   524,   526,   527,   528,   525,   573,   574,   575,   576,
     577,   578,   579,   468,   619,     0,   610,   618,   617,   616,
     615,   612,   614,   611,   613,   504,    43,   223,   224,   226,
     225,   227,   219,   500,   501,   502,   499,   229,   232,   228,
     230,   231,   470,   824,   847,   941,   950,   948,  1052,     0,
     166,   167,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   126,   128,
     129,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   280,   281,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   464,   467,   454,     0,     0,   827,
     857,   830,   888,   951,   832,   899,   834,   910,   837,   839,
     838,   928,  1036,  1043,   826,  1037,   886,  1038,  1044,   911,
    1042,  1045,   935,   992,  1039,  1040,  1046,  1041,   993,   981,
     978,   980,   979,   875,   997,   998,   995,   841,   999,   889,
     859,   977,   460,   824,   452,     0,   192,   453,   456,   827,
     828,   830,   829,   834,   835,   836,   837,   826,   833,   508,
       0,   458,   457,     0,     0,   212,     0,   470,   832,   839,
     838,     0,   168,   795,   999,     0,   220,     0,   509,     0,
     540,     0,     0,   463,     0,   434,   435,     0,   466,   465,
     455,   438,     0,     0,   569,     0,     0,     0,     0,     0,
       0,     0,   986,     0,   815,     0,   833,   986,   842,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   363,   797,     0,   799,     0,
     842,     0,   165,     3,     4,     1,    10,    12,     0,     0,
       0,     0,     6,   165,     0,   165,     0,     0,   119,   172,
       0,     0,   190,     0,     0,   199,     0,     0,     0,     0,
       0,     0,   235,   236,     0,     0,   204,   233,     0,   254,
     250,   256,   251,   253,   252,   260,     0,     0,     0,     0,
       0,     0,     0,   425,     0,     0,   423,     0,   369,     0,
     424,   417,   422,   421,   420,   419,   418,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   411,   410,   407,     0,
     168,   432,   437,     0,     0,     0,   447,   486,   450,   449,
     461,     0,     0,     0,   477,     0,     0,     0,   581,   583,
     587,   589,     0,   124,     0,   823,    47,    44,    45,    48,
      49,     0,     0,     0,     0,    50,    51,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   654,   655,   656,
       0,   103,   142,     0,     0,   112,     0,     0,     0,     0,
     127,     0,     0,   627,     0,     0,     0,   622,     0,     0,
       0,   637,     0,     0,   258,   263,     0,     0,   134,     0,
     138,   168,   523,     0,    60,     0,    69,     0,     0,     0,
      61,     0,     0,     0,     0,   625,     0,     0,   628,     0,
       0,     0,     0,   329,     0,     0,   626,     0,     0,     0,
     645,     0,     0,     0,     0,   631,     0,     0,   194,     0,
       0,   188,   187,     0,     0,   801,     0,     0,     0,     0,
     508,     0,   796,     0,   510,   541,   540,   537,     0,     0,
       0,   571,   570,   433,     0,   568,     0,   667,   668,   814,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   673,     0,   202,   203,     0,     0,     0,
       0,     0,   207,   208,   259,   798,   800,     0,     0,     5,
      24,     0,    25,     0,     7,    29,     0,    15,     8,    30,
       0,    19,   941,    77,    16,    78,    20,   193,     0,   191,
     213,   214,     0,     0,     0,     0,   298,   205,   234,   237,
     238,   257,     0,     0,   359,   361,   367,   373,   372,   371,
       0,   368,   365,   366,     0,   377,   384,   383,   381,   387,
     388,   389,   386,   391,   392,   395,   394,     0,     0,     0,
       0,   416,     0,   442,   443,     0,   487,     0,   484,   485,
     481,   480,   516,   478,   518,     0,   620,   522,   514,     0,
       0,   121,   123,     0,     0,     0,   102,     0,    92,    94,
      95,    96,    97,    99,   100,   101,    93,    98,    88,    89,
       0,     0,   108,     0,   104,   106,   107,   114,     0,     0,
      87,    46,     0,     0,     0,     0,     0,     0,     0,   745,
     750,     0,     0,   746,   780,   733,   735,   736,   737,   739,
     741,   740,   738,   742,     0,     0,     0,     0,     0,   111,
       0,   144,     0,     0,   586,   580,   623,   624,     0,     0,
     641,     0,   638,     0,     0,     0,     0,     0,     0,     0,
       0,   140,     0,     0,   135,     0,     0,     0,     0,     0,
       0,    62,     0,     0,     0,   279,   285,   282,     0,   630,
     629,   636,   644,     0,     0,     0,     0,   585,     0,     0,
       0,   426,     0,     0,     0,     0,   634,     0,   632,     0,
     195,     0,     0,   803,     0,   470,   802,     0,     0,     0,
     540,   538,     0,   529,     0,     0,   512,   513,     0,    13,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     809,   810,     0,     0,   817,     0,     0,     0,     0,     0,
       0,     0,   200,     0,     0,     0,   681,     0,   209,     0,
     813,     0,     0,     0,   165,     0,   165,     0,   173,   246,
       0,   313,   309,   311,     0,   306,   299,   300,     0,     0,
     239,   240,     0,   245,   370,     0,     0,     0,     0,   711,
     378,   684,   688,   690,   692,   694,   697,   704,   705,   713,
     951,   831,     0,   840,   844,   843,   845,   846,   397,   592,
     599,   600,   603,   648,   649,   604,   605,   608,   399,   401,
     404,   609,   403,   430,   488,   482,     0,     0,   479,   515,
     125,    56,    57,    54,    55,   131,   130,     0,    90,     0,
       0,     0,   109,   110,   115,    74,    75,    52,    53,    73,
     751,     0,   754,   781,     0,   744,   743,   748,   747,   779,
       0,     0,   756,     0,   752,   755,   734,     0,     0,     0,
       0,     0,     0,     0,   621,     0,     0,     0,   143,   146,
     148,     0,     0,     0,   113,   116,     0,     0,     0,   168,
       0,     0,   645,     0,     0,     0,   265,     0,   591,     0,
     266,     0,     0,     0,     0,     0,     0,     0,   141,   136,
     139,     0,   189,     0,     0,    71,    65,    68,    67,     0,
      63,   283,     0,     0,   168,     0,   327,   331,     0,     0,
       0,   334,     0,     0,   340,     0,     0,   347,     0,   351,
       0,   428,   427,   168,     0,     0,   196,     0,   198,   328,
       0,     0,     0,     0,     0,   541,     0,   531,     0,   564,
     561,     0,   565,   566,     0,     0,   560,     0,   535,   563,
     562,     0,     0,     0,     0,   660,   661,   657,     0,     0,
     665,   666,   662,   806,   807,     0,   671,   816,   669,     0,
       0,     0,     0,     0,   675,   832,   839,   838,   999,   201,
       0,     0,     0,   676,   677,     0,     0,   210,   812,    26,
       0,    17,    21,    22,   310,   322,     0,   323,     0,   314,
     315,   316,   317,     0,   508,     0,   307,     0,     0,     0,
     241,     0,     0,     0,     0,   292,     0,   289,   294,   244,
       0,     0,   695,   708,     0,   375,   379,     0,   727,     0,
       0,     0,     0,     0,     0,   683,   685,   686,   722,   723,
     724,   726,   725,     0,     0,   699,   698,     0,   702,   706,
     720,   718,   717,   710,   714,     0,     0,   595,     0,     0,
       0,     0,     0,     0,   596,   598,   597,   593,   405,   483,
     517,   519,   133,   132,    91,   105,   768,   749,     0,   773,
       0,   773,   762,   757,   147,   149,     0,     0,     0,   117,
     145,     0,    27,     0,   642,   643,   646,   639,   640,   264,
       0,     0,   278,   270,     0,   274,     0,   268,     0,     0,
       0,   137,     0,     0,    70,     0,    64,   284,     0,     0,
     330,   332,   337,     0,   335,     0,     0,     0,     0,     0,
     341,     0,     0,   355,     0,     0,   348,     0,     0,   352,
     429,     0,   635,   633,   197,   804,   805,     0,     0,   540,
       0,     0,   572,     0,   540,     0,   536,     0,    14,     0,
       0,     0,     0,     0,     0,     0,   819,     0,   674,     0,
       0,     0,     0,     0,     0,   678,   682,   326,   324,   325,
     318,   319,   320,   312,     0,     0,   308,   301,   287,     0,
       0,     0,   243,   290,   293,     0,   712,   703,   709,     0,
       0,   782,   783,   793,   792,   791,     0,     0,     0,     0,
     784,   689,   790,     0,   687,   691,     0,     0,   696,   700,
       0,   721,   716,   719,   715,     0,     0,   606,     0,   601,
     653,   594,   822,   821,   820,   602,   769,     0,     0,   767,
     774,   775,   771,     0,   766,     0,   764,     0,     0,     0,
       0,     0,     0,   582,   267,     0,   276,     0,     0,   272,
       0,   275,     0,     0,     0,    66,   286,   588,     0,     0,
     338,   342,   336,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   584,     0,     0,   540,     0,
     567,     0,   540,   590,   658,   659,   663,   664,     0,   811,
     670,   818,   672,     0,     0,     0,     0,   679,   321,   302,
       0,   288,   296,   297,   291,   242,   707,   794,     0,     0,
     786,     0,   732,   731,   730,   729,   728,   693,     0,   785,
       0,   650,     0,     0,   778,   777,   776,     0,   770,   763,
     761,     0,   758,   759,   753,   150,   152,   154,     0,     0,
       0,     0,     0,   271,   269,     0,   277,   206,   357,    72,
     333,   339,     0,   356,   353,   349,     0,     0,     0,   343,
       0,     0,   345,     0,   550,   544,   539,     0,   540,   530,
       0,   808,     0,     0,     0,     0,   305,   303,     0,   788,
     787,     0,     0,   651,   607,     0,   772,   765,     0,     0,
     156,   155,     0,     0,     0,     0,   151,   273,     0,     0,
       0,     0,     0,   558,   552,     0,   551,   553,   559,   556,
     546,     0,   545,   547,   557,   532,     0,   533,     0,     0,
     680,   304,     0,   789,   701,   652,   760,   153,   157,     0,
       0,     0,     0,     0,     0,   346,   344,     0,     0,   543,
     554,   555,   542,   548,   549,   534,     0,   295,   158,     0,
       0,     0,   354,   350,     0,     0,     0,     0,     0,     0,
       0,     0,   160,     0,     0,   159,     0,     0,     0,     0,
       0,     0,     0,     0,   161
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  jsoniq_parser::yypgoto_[] =
  {
     -1566, -1566,  -216,  -199, -1566,  1247,  1248, -1566,  1249,  -570,
   -1566, -1566, -1566, -1566, -1566, -1566, -1566, -1566, -1566, -1566,
   -1024, -1566, -1566, -1566, -1566,  -225,  -607, -1566,   752,   -55,
   -1566, -1566, -1566, -1566, -1566,   287,   517, -1566, -1566,    -3,
    -159,  1083, -1566,  1059, -1566, -1566,  -664, -1566,   459, -1566,
     247, -1566,  -238,  -284, -1566,  -585, -1566,    12,    92,    -4,
    -260,  -179, -1566,  -902, -1566, -1566,  -465, -1566, -1566, -1566,
   -1566, -1566, -1566, -1566, -1566, -1566, -1566,   637, -1566,   -83,
    1698,     0, -1566, -1566,  -231, -1566, -1566,   353, -1566, -1566,
    -311, -1566,    16, -1566, -1566,     4,  -971,  -769,  -752, -1566,
   -1566,   716, -1566, -1566,   -72,   108, -1566, -1566, -1566,   117,
   -1278, -1566,   378,   122, -1566, -1566,   129, -1341, -1566,   980,
     226, -1566, -1566,   222, -1047, -1566, -1566,   223, -1566, -1566,
   -1289, -1276, -1566,   217, -1434, -1566, -1566,   868,  -157, -1566,
   -1566,  -567,   849, -1566, -1566,  -691,   269,  -670,   318,   302,
   -1566, -1566, -1566,   590, -1566, -1566,  1208, -1566, -1566, -1566,
   -1566, -1566,  -913,  -339,  -694, -1566,   -84, -1566, -1566, -1566,
   -1566, -1566, -1566, -1566,    -9,  -835, -1566,  -140,   631,   235,
   -1566,  -422, -1566,   820, -1566, -1566, -1566, -1566, -1566,   815,
   -1566, -1566, -1566, -1566, -1065, -1566,   206, -1566,   705,  -830,
   -1566, -1566, -1566, -1566, -1566,  -276,  -269, -1262,  -922, -1566,
   -1566, -1566, -1566, -1566, -1566, -1566, -1566, -1566, -1566, -1566,
    -791,  -906,  -235,  -895, -1566, -1566, -1566,  -726, -1566, -1566,
   -1566, -1566, -1566, -1566, -1566, -1566, -1566,  1094,  1099,  -207,
     515,  -686, -1566, -1566, -1566, -1566, -1566, -1566, -1566, -1566,
   -1566, -1566, -1566,   181, -1566, -1566,   169, -1566,   173, -1112,
   -1566, -1566, -1566,   130,   116,   -59,   393, -1566, -1566, -1566,
   -1566, -1566, -1566, -1566, -1566, -1566, -1566, -1566, -1566, -1566,
     133, -1566, -1566, -1566,   -52,   387,   540, -1566, -1566, -1566,
   -1566, -1566,   322, -1566, -1566, -1565, -1566, -1566, -1566,  -606,
   -1566,    85, -1566,   -73, -1566, -1566, -1566, -1566, -1370, -1566,
     138, -1566, -1566, -1566, -1566, -1566,  -113, -1566, -1566, -1566,
   -1566, -1566,  -959,  -396,   919,   243, -1566
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  jsoniq_parser::yydefgoto_[] =
  {
        -1,   263,   654,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
    1305,   809,   281,   282,   283,   284,   285,   286,   998,   999,
    1000,   287,   288,   289,  1004,  1005,  1006,   290,   456,   291,
     292,   742,   293,   458,   459,   460,   470,   799,   800,   294,
    1268,   295,  1755,  1756,   296,   297,   298,   563,   299,   300,
     301,   302,   303,   802,   304,   305,   546,   306,   307,   308,
     309,   310,   311,   666,   312,   313,   892,   893,   314,   315,
     316,   576,   318,   667,  1691,   679,  1172,  1173,   319,   669,
     320,   671,   577,   322,   323,   794,   795,  1425,   477,   324,
     478,   479,   933,  1426,  1427,  1428,   672,   673,  1166,  1167,
    1416,   674,  1162,  1163,  1409,  1410,  1411,  1412,   325,   822,
     823,   326,  1320,  1321,  1535,   327,  1323,  1324,   328,   329,
    1326,  1327,  1328,  1329,  1542,   330,   331,   332,   333,   334,
     940,   335,   336,  1435,   337,   338,   339,   340,   341,   342,
     343,   344,   345,  1209,   346,   347,   348,   349,   697,   698,
     350,   351,   352,   353,   354,   355,   356,   357,   358,   359,
     360,   361,   362,   363,   364,   365,   366,   367,   734,   727,
     368,   369,   370,   371,   372,   373,   374,   375,   376,   975,
     377,   378,   379,   380,   381,   382,  1357,   856,   857,   858,
    1786,  1831,  1832,  1825,  1826,  1833,  1827,  1358,  1359,   383,
     384,  1360,   385,   386,   387,   388,   389,   390,   391,   392,
    1060,  1543,  1477,  1199,  1638,  1200,  1210,   393,   394,   395,
     396,   397,   398,   399,   400,   401,   402,   403,   404,   829,
    1281,   405,  1202,  1203,  1204,  1205,   406,   407,   408,   409,
     410,   411,   882,   883,   412,  1393,  1394,  1717,  1147,  1180,
    1445,  1446,  1181,  1182,  1183,  1184,  1185,  1455,  1628,  1629,
    1186,  1458,  1187,  1609,  1188,  1189,  1463,  1464,  1634,  1632,
    1447,  1448,  1449,  1450,  1735,   771,  1025,  1026,  1027,  1028,
    1029,  1030,  1254,  1658,  1752,  1255,  1656,  1750,  1031,  1491,
    1653,  1649,  1650,  1651,  1032,  1033,  1451,  1459,  1619,  1452,
    1615,  1436,   413,   414,   415,   416,   566,   417,   418,   419,
     420,   421,  1206,  1306,   422,   423,   424
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const short int jsoniq_parser::yytable_ninf_ = -890;
  const short int
  jsoniq_parser::yytable_[] =
  {
       317,   431,   431,   431,   435,   317,   317,   317,   317,   623,
     670,   457,   948,   721,   743,   743,   321,   429,   432,   433,
    1074,   321,   321,   321,   321,   961,  1112,  1058,   604,   575,
     579,  1178,   613,  1086,   949,   950,   951,   952,   913,   915,
     649,  1322,   746,   641,  1059,   969,   625,  1100,  1310,  1356,
    1546,  1198,  1208,   644,   591,  1558,  1146,   610,   907,   911,
     914,   916,   633,   634,  1431,   642,   642,   542,   646,  1591,
    1592,    11,    12,   905,   909,  1054,  1270,   806,   810,  1758,
    1257,  1294,  1286,  1226,  1169,  1258,   785,  1630,  1312,   985,
     668,   442,  1753,   475,  1259,  1566,   642,   430,   430,   430,
     434,  1260,   642,  1261,   786,   843,  1231,   564,  1291,    13,
    1689,   317,  1262,  1693,   642,   936,   642,   937,   938,   445,
     939,   980,   941,    13,   642,  -169,   642,   321,  1518,   642,
     942,   943,   648,  1083,  1055,   642,  1056,  1083,   642,  1263,
     642,  1728,  1056,   642,   980,   651,  1784,   642,  1647,  1288,
    1118,  1488,   642,   614,    11,    12,  1299,   777,   615,  1611,
     642,  1055,   642,   731,   438,   439,   720,   440,   441,   627,
     629,   649,   653,   653,   442,   649,  -170,   642,   593,  1437,
     701,   436,   917,   642,   443,   444,   919,   642,  1057,   128,
      82,  1759,  1225,  1251,  1295,   642,   642,   702,   732,  1612,
     733,   981,   445,   430,    82,    93,   437,   446,   801,  1119,
    1252,   861,  1490,  1648,  1084,  1085,  1234,   650,  1102,    93,
    1729,   874,  1139,   476,   982,   642,    11,    12,  1437,   652,
     107,  1201,  1201,   653,  1175,   642,  1785,  1176,   476,   447,
     448,   449,   616,  1846,   107,   653,   442,   653,  1170,  1718,
     653,   642,  1438,   476,   653,   642,   443,   128,   476,   653,
     642,   317,   317,  1178,  1178,   317,   670,   653,   642,   653,
    1298,   722,  1264,  1760,   445,  1201,  1539,   321,   321,   446,
    1346,   321,  1546,  1356,   653,  1526,  1751,   643,  1171,   450,
     653,  1296,  1356,   645,   653,   913,   915,  1468,   648,  1566,
     317,  1438,   653,   653,   649,   900,  1292,   902,  1297,  1269,
    -169,   447,   448,  1157,  1509,  1154,   321,  1270,   476,   543,
    1156,  1608,  1313,  1227,   476,  1483,  1399,   854,   852,  1201,
     905,   909,   653,   543,  1066,  1468,  1201,   778,  1818,  1088,
    1439,  1440,   653,  1441,  1177,   779,   853,  1089,   650,  1143,
    1442,   728,   650,   451,   730,  1140,   464,   543,   653,  1120,
    1443,  -170,   653,   594,  1265,  1266,  1267,   653,  1011,   543,
    1342,   543,  1444,  1174,  1343,   653,   642,  1419,   642,   862,
    1048,   895,  1344,   790,   896,  1854,  1616,  1857,   803,  1439,
    1440,   490,  1441,   745,   452,  1521,   438,   439,   816,   440,
     441,  1616,  1124,   642,   745,   827,   828,   642,   927,  1443,
     642,   605,  1479,  1071,   834,   605,  1810,   444,   906,   910,
     453,  1444,  1792,   461,   901,   903,   642,   642,   454,   843,
     642,   317,  1049,   899,   918,   317,   455,   675,  1793,   785,
    1395,  1796,  1794,  1051,  1055,  1214,  1063,   321,   844,  1113,
     844,   321,  1078,   747,  1613,  1095,   465,   786,   435,   749,
     435,  1614,   317,   869,   317,   761,  1201,   762,   748,   491,
    1848,  1433,   877,  1400,   750,  1823,   731,   807,   321,  1349,
     321,   650,   435,   653,  1499,   653,   317,   435,  1121,  1122,
     844,   317,   453,  1073,   128,   873,  1356,  1396,   859,   860,
     454,   676,   321,  1123,  1201,  1839,   677,   321,   455,   864,
     653,   732,  1050,   733,   653,  1536,  1114,   653,  1511,  1841,
    1178,   450,  1179,  1052,   935,   808,  1064,   764,  1014,  1178,
    1015,  1125,  1126,   653,   653,  1096,   805,   653,   888,   890,
    1178,   492,   493,  1484,  1519,  1128,  1127,   913,   915,   913,
    1269,  1617,  1618,   678,   782,    13,   784,  1146,  1220,  1637,
    1094,  1586,  1115,  1546,   317,   731,  1617,   845,   431,  1401,
    1402,  1403,   317,   701,  1016,  1201,  1097,  1496,   825,   875,
     321,  1129,   787,   831,  1690,   451,  1217,  1116,   321,   765,
     702,  1117,  1823,  1217,  1145,  1352,  1349,  1353,  1380,  1201,
     732,   662,   733,   543,   663,  1824,   543,   755,   797,  1055,
    1606,  1840,  1235,  1236,  1844,    11,    12,  1239,   889,  1742,
    1747,   751,   317,  1595,  1347,  1354,   452,  1056,   894,   649,
     469,   462,   317,   908,   463,   457,    82,   752,   321,   963,
     964,   756,   965,   317,   317,   317,   317,  1278,   321,   965,
    1769,    93,   662,  1783,  1349,   663,  1098,  1056,  1158,   321,
     321,   321,   321,  1418,   430,  1153,  1218,   662,   317,  1363,
     663,  1364,   704,  1219,  1829,  1151,   107,   798,  1349,  1510,
    1175,  1716,   931,  1176,   321,   753,   543,  1577,  1732,   543,
    1155,  1348,  1686,   543,   903,  1733,   543,   543,  1829,  1743,
    1748,   647,   705,   128,   543,  1734,   471,  1349,  1350,  1667,
     543,   543,  1352,  1178,  1353,   706,   431,   761,   543,   762,
     317,   662,  1860,   878,   663,   543,   543,   543,   543,  1697,
    1017,   480,   962,   543,  1701,  1319,   321,  1406,  1396,  1201,
    1137,   543,  1354,  1018,  1055,  1019,  1539,  1668,  1533,   731,
     707,   908,   763,  1623,  1179,  1179,  1020,  1021,  1022,  1408,
    1023,  1055,  1024,   483,  1107,  1108,  1109,   656,   890,   708,
    1352,   657,  1353,   638,  1221,  1223,   658,   484,   709,   764,
    1773,  1830,  1133,  1152,   732,   468,   733,  -261,   543,   639,
    1222,  1224,   913,  1099,  1352,   659,  1353,   431,  1251,   639,
    1354,   317,  1351,   543,   485,  1863,  1144,  1662,   731,  1488,
    1594,  1421,   430,  1065,   543,  1252,  1422,   321,  1201,  1474,
     624,  1201,  -262,  1352,  1354,  1353,  1489,   496,   435,   435,
     701,  1001,   317,   317,  1803,  1423,  1804,   662,   710,   721,
     663,   765,  1280,   732,  1283,   733,   605,   702,   321,   321,
    1475,  -261,   711,  1354,  1056,   605,  -261,   114,   497,  1253,
     543,   498,  1828,  1834,  1368,   472,  1369,   543,  1787,  1476,
    1490,   703,  1790,   126,   473,  1002,  1424,  1421,  1349,  1350,
    1003,   701,  1422,  1389,  1216,  1732,  -262,   488,  1334,   317,
    1335,  -262,  1733,   430,   660,  1355,  1405,   661,   702,  1845,
    1482,   474,  1734,  -261,  1828,   321,  1319,  1406,  1524,   457,
    1834,   466,   662,   154,   467,   663,   801,  1407,   317,  1538,
    1056,   543,  1801,  1544,  1092,  1093,  1730,  1731,   918,  1408,
    1460,  1461,  1547,  1544,   321,   903,  1545,  1544,  -262,   664,
    1727,   736,  1055,  1228,  1421,  1548,  1696,  1272,  1245,  1422,
    1866,  1247,   737,  1462,  1406,  1228,  1273,   489,  1836,  1246,
    1201,   966,  1248,   494,   966,  1757,  1811,   775,  1397,   966,
     946,   947,   776,  1351,   543,  1240,  1241,  1242,  1349,  1350,
    1002,  1243,   723,   724,   481,  1003,   495,   482,   665,   486,
     726,   544,   487,   729,  1352,   545,  1353,   547,  1381,   548,
     987,  1237,  1238,   543,   767,   768,   769,  1588,  1589,   559,
    1587,  1179,   955,   956,  1201,   560,  1201,   543,   561,  1596,
    1179,   543,   543,   562,  1354,   581,   953,   954,   114,   582,
     567,  1179,   583,   580,  1494,  1495,   588,  1799,  1800,   589,
     543,  1744,  1745,  1522,   126,   584,  1201,   587,   543,   590,
     592,   543,   595,   617,   618,   543,  -621,   619,   621,   620,
     622,   635,  1349,  1350,   655,   680,  1560,   681,  1757,   699,
     700,   712,   725,  1351,   714,   719,   715,   738,   735,  1201,
     670,   713,   745,   757,   154,   759,   435,   739,   740,   567,
     317,  1537,  1430,  1201,  1352,  1201,  1353,   760,   543,   741,
     770,   774,   801,   804,   812,   783,   321,   813,   814,   815,
    1843,   826,   832,   833,   463,  1757,   843,   467,   482,   487,
     498,   839,   841,   605,  1354,   846,   847,   855,   114,  1675,
     863,   851,   885,   848,   543,   866,   462,   849,   865,   466,
     881,   481,   486,  1390,   126,   497,   880,   886,   904,   898,
     457,   922,  1579,   924,   317,   317,   317,  1351,   891,  1391,
    1583,   923,   925,   932,   944,   543,  1565,   957,   929,   958,
     321,   321,   321,   930,   977,   543,   959,   960,  1352,   983,
    1353,   984,  1330,   976,   154,   986,  1008,  1885,  1009,  1886,
    1013,  1012,  1035,  1034,  1036,  1038,  1040,  1043,  1044,  1894,
     543,   543,   543,   543,  1179,  1045,  1046,  1047,  1354,   623,
    1062,  1053,   114,   682,  1068,  1069,  1072,  1079,  1080,  1081,
    1090,   683,   684,  1082,   685,  1087,  1091,  1132,   126,  1141,
    1142,  1135,   686,  1138,  1153,  1160,   687,  1149,   688,  1213,
    1229,  1055,  1003,   689,   543,  1249,  1250,  1271,  1276,  1277,
    1699,  1279,  1287,  1289,   797,  1301,  1293,  1302,   543,   690,
    1303,  1304,  1307,  1308,  1309,  1314,  1315,  1318,   154,  1319,
    1325,  1331,  1332,  1340,  1337,   431,  1333,  1681,  1345,   317,
    1338,  1341,  1362,   543,   691,   692,   693,   694,   695,   696,
    1375,  1503,   543,  1361,   543,   321,   543,  1382,   543,  1392,
     763,  1415,  1678,   317,  1679,   543,  1413,  1683,  1684,  1420,
     431,  1687,  1417,  1434,   317,  1457,  1454,  1694,  1478,   321,
    1465,  1453,  1466,   927,  1469,    13,  1529,  1487,  1492,   431,
     321,  1470,  1471,   317,  1472,  1473,  1497,  1486,   543,  1498,
     543,  1501,  1504,  1502,  1505,  1551,  1506,  1507,  1514,   321,
     435,  1508,  1516,  1525,   317,  1520,  1528,   435,  1544,  1552,
    1550,   317,   754,  1559,  1562,   758,  1573,  1553,  1574,   766,
     321,   430,   772,   773,  1575,  1568,  1569,   321,  1570,  1571,
     781,   605,  1557,  1572,  1580,  1581,   793,   796,  1582,  1395,
    1406,   889,  1600,  1599,   811,  1390,  1601,  1605,  1607,  1610,
    1626,   819,   820,   821,   824,  1620,   430,   543,  1627,   830,
    1633,  1391,  1767,  1639,  1631,  1646,  1640,   837,  1652,  1641,
    1642,  1643,  1657,  1771,  1681,   430,  1644,  1774,  1645,  1655,
    1659,  1663,  1672,  1665,  1782,   543,   988,   989,   990,   991,
     992,   993,   994,   995,   996,   997,  1563,  1661,  1670,  1673,
    1674,  1677,  1695,  1567,  1720,  1700,  1703,  1726,  1777,  1740,
    1738,  1749,  1781,  1708,   838,  1251,  1739,  1741,  1754,  1765,
    1772,  1762,  1798,   543,  1761,  1789,  1805,  1806,  1807,   824,
    1808,  1809,  1813,  1859,  1814,  1819,  1821,  1835,  1837,  1842,
     850,   567,  1838,  1851,  1852,  1862,  1849,  1713,  1714,  1715,
    1865,  1869,  1871,  1876,  1877,  1890,  1878,  1887,  1881,  1883,
    1888,  1891,   636,   637,  1893,  1010,   780,   640,  1485,  1232,
     744,  1774,  1300,  1500,  1816,  1847,  1429,   567,   543,  1148,
    1077,  1724,   543,  1604,  1597,  1593,   884,   317,  1404,  1590,
     840,  1530,  1534,   796,   543,  1549,  1540,  1820,   934,   945,
    1212,   968,   979,   321,  1561,   718,  1864,  1861,   543,   788,
    1855,  1111,  1585,  1578,   789,  1584,  1284,  1737,   543,  1625,
    1432,  1736,  1621,  1456,  1256,  1493,  1654,  1746,  1522,  1624,
       0,  1622,     0,  1390,     0,     0,     0,  1853,     0,     0,
       0,  1858,     0,  1872,     0,     0,     0,   796,   543,  1391,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1872,     0,     0,     0,     0,
       0,     0,     0,  1874,  1855,   543,  1875,     0,     0,     0,
       0,     0,     0,  1795,     0,   543,     0,     0,     0,   543,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1884,
     970,     0,     0,     0,     0,  1802,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   543,     0,     0,
       0,     0,  1390,     0,     0,     0,     0,     0,     0,  1007,
       0,     0,     0,  1390,  1390,     0,     0,   317,  1391,     0,
       0,     0,     0,  1037,  1390,     0,     0,  1041,  1042,  1391,
    1391,     0,     0,   321,     0,     0,     0,     0,   543,     0,
    1391,     0,     0,     0,     0,     0,  1061,     0,     0,     0,
       0,     0,     0,     0,  1067,     0,     0,  1070,     0,     0,
       0,  1075,     0,     0,     0,     0,     0,     0,     0,     0,
     543,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1105,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1110,     0,     0,     0,     0,     0,
       0,  1390,     0,     0,   543,     0,     0,   543,     0,     0,
     543,     0,     0,     0,     0,     0,     0,  1391,     0,     0,
       0,     0,     0,   543,     0,     0,     0,     0,   543,   565,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     317,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   321,     0,  1390,     0,
       0,  1159,     0,   543,   543,     0,     0,     0,     0,     0,
       0,  1168,     0,   317,  1391,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   609,   321,
       0,     0,     0,     0,     0,  1390,  1207,  1207,  1211,  1211,
       0,     0,     0,     0,  1390,     0,     0,     0,     0,     0,
       0,  1391,     0,     0,     0,     0,     0,     0,     0,     0,
    1391,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1207,     0,     0,     0,     0,     0,     0,     0,     0,   543,
       0,   543,     0,   543,  1244,   543,     0,     0,     0,     0,
       0,     0,   543,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   631,     0,     0,     0,     0,     0,  1275,
       0,     0,     0,     0,     0,     0,     0,     0,  1282,     0,
    1282,     0,   796,     0,  1207,     0,     0,     0,     0,     0,
       0,  1207,     0,   543,     0,   543,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   543,     0,     0,   543,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   830,   543,   830,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   543,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   543,     0,
       0,     0,     0,     0,     0,     0,   543,     0,     0,     0,
       0,     0,   543,     0,   543,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1414,     0,   543,     0,     0,     0,     0,
       0,     0,     0,     0,   543,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1207,     0,     0,   543,     0,     0,     0,     0,   543,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   543,     0,     0,   543,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1207,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   796,     0,     0,     0,  1512,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1207,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   824,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1207,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     565,     0,     0,     0,  1564,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   867,
     868,   884,     0,     0,   870,   871,   872,     0,     0,   876,
       0,     0,   879,     0,     0,     0,     0,     0,   887,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   897,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1603,     0,     0,     0,     0,     0,     0,
       0,   920,   921,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   926,     0,     0,     0,   928,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1207,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1660,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   974,     0,     0,     0,   974,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1685,     0,     0,  1207,     0,     0,  1207,     0,     0,     0,
       0,     0,     0,     0,  1039,     0,     0,     0,     0,  1698,
       0,     0,     0,     0,  1702,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1076,     0,     0,     0,     0,     0,     0,     0,  1722,
    1723,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1101,     0,     0,
       0,  1103,  1104,     0,  1106,     0,     0,     0,     0,     0,
       0,   928,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1130,  1131,     0,     0,  1134,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1150,     0,     0,     0,
       0,     0,     0,     0,     0,  1207,     0,  1776,     0,  1778,
       0,  1780,     0,     0,     0,     0,   921,     0,  1788,     0,
       0,     0,  1161,  1165,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1207,
       0,  1207,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1812,     0,     0,
    1815,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1207,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1233,  1822,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1207,     0,     0,     0,     0,     0,
       0,     0,  1850,     0,     0,     0,  1274,     0,  1207,     0,
    1207,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1290,     0,     0,     0,     0,
       0,  1867,     0,     0,     0,     0,     0,     0,     0,     0,
    1870,  1311,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1316,  1317,     0,     0,     0,     0,     0,     0,
    1879,     0,     0,     0,     0,  1880,     0,  1336,     0,     0,
    1339,     0,     0,     0,     0,     0,     0,  1889,     0,     0,
    1892,     0,     0,     0,     0,     0,     0,     0,     0,  1365,
    1366,  1367,     0,  1370,  1371,  1372,  1373,  1374,     0,     0,
    1376,  1377,     0,  1378,  1379,     0,     0,     0,  1383,  1384,
       0,     0,     0,     0,     0,     0,     0,  1398,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1161,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1481,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1513,
       0,  1515,     0,  1517,     0,     0,     0,     0,     0,     0,
       0,  1523,     0,     0,     0,     0,     0,     0,     0,     0,
    1527,     0,     0,     0,     0,     0,  1531,  1532,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1554,     0,     0,  1555,  1556,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1576,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1161,     0,     0,     0,  1165,  1598,     0,     0,     0,
       0,  1602,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1664,     0,
       0,     0,  1666,     0,     0,     0,  1669,     0,  1671,     0,
       0,     0,     0,     0,     0,     0,  1676,     0,     0,     0,
       0,     0,     0,     0,  1680,  1682,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1523,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1704,  1705,  1706,
    1707,     0,  1709,  1710,     0,  1711,     0,  1712,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1719,     0,     0,     0,     0,  1721,     0,     0,
       0,     0,     0,  1725,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1763,     0,  1764,     0,     0,  1766,     0,
       0,  1768,     0,     0,     0,     0,  1770,  1682,     0,     0,
       0,     0,     0,     0,     0,  1775,     0,     0,     0,  1779,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1791,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1797,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1817,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1775,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1856,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  -165,   908,     0,     0,     0,     0,  1868,     0,     0,
       0,  1873,     1,     2,     0,     0,  1856,     3,     0,     0,
       0,     4,     5,     6,     7,     8,     9,    10,    11,    12,
       0,    13,  1873,     0,    14,   426,  1882,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,     0,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
       0,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,     0,    72,    73,    74,    75,
      76,     0,    77,    78,    79,     0,     0,    80,    81,     0,
       0,     0,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,     0,    92,     0,     0,     0,    93,     0,    94,
      95,    96,    97,     0,    98,     0,     0,     0,    99,   100,
     101,   102,   103,     0,     0,     0,     0,     0,     0,   104,
     105,   106,   107,   108,   109,   110,   111,   112,     0,   113,
     114,   115,   116,   117,     0,     0,     0,   118,   119,   120,
     121,   122,   123,   124,   125,     0,   126,     0,   127,   128,
       0,     0,   129,   130,   131,     0,     0,     0,   132,     0,
     133,   134,   135,   136,   137,   138,     0,   139,     0,   140,
       0,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,     0,     0,   152,   153,   154,     0,   155,   428,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,     0,   202,   203,   204,     0,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,     0,   253,
       0,   254,   255,   256,   257,   258,   259,   260,  -165,   908,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     1,
       2,     0,     0,     0,     3,     0,     0,     0,     4,     5,
       6,     7,     8,     9,    10,    11,    12,     0,    13,     0,
       0,   912,   426,     0,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,   427,    30,    31,
      32,    33,    34,     0,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,     0,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,     0,    72,    73,    74,    75,    76,     0,    77,
      78,    79,     0,     0,    80,    81,     0,     0,     0,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,     0,
      92,     0,     0,     0,    93,     0,    94,    95,    96,    97,
       0,    98,     0,     0,     0,    99,   100,   101,   102,   103,
       0,     0,     0,     0,     0,     0,   104,   105,   106,   107,
     108,   109,   110,   111,   112,     0,   113,   114,   115,   116,
     117,     0,     0,     0,   118,   119,   120,   121,   122,   123,
     124,   125,     0,   126,     0,   127,   128,     0,     0,   129,
     130,   131,     0,     0,     0,   132,     0,   133,   134,   135,
     136,   137,   138,     0,   139,     0,   140,     0,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,     0,
       0,   152,   153,   154,     0,   155,   428,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,     0,   202,   203,   204,     0,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   908,   253,     0,   254,   255,
     256,   257,   258,   259,   260,     1,     2,     0,     0,     0,
       3,     0,     0,     0,     4,     5,     6,     7,     8,     9,
      10,    11,    12,     0,    13,     0,     0,   425,   426,     0,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,   427,    30,    31,    32,    33,    34,     0,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,     0,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,     0,    72,
      73,    74,    75,    76,     0,    77,    78,    79,     0,     0,
      80,    81,     0,     0,     0,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,     0,    92,     0,     0,     0,
      93,     0,    94,    95,    96,    97,     0,    98,     0,     0,
       0,    99,   100,   101,   102,   103,     0,     0,     0,     0,
       0,     0,   104,   105,   106,   107,   108,   109,   110,   111,
     112,     0,   113,   114,   115,   116,   117,     0,     0,     0,
     118,   119,   120,   121,   122,   123,   124,   125,     0,   126,
       0,   127,   128,     0,     0,   129,   130,   131,     0,     0,
       0,   132,     0,   133,   134,   135,   136,   137,   138,     0,
     139,     0,   140,     0,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,     0,     0,   152,   153,   154,
       0,   155,   428,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,     0,   202,
     203,   204,     0,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   908,   253,     0,   254,   255,   256,   257,   258,   259,
     260,     1,     2,     0,     0,     0,     3,     0,     0,     0,
       4,     5,     6,     7,     8,     9,    10,     0,     0,     0,
      13,     0,     0,   425,   426,     0,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,   568,   427,
      30,    31,    32,    33,    34,     0,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,     0,
      48,    49,    50,   569,   570,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,     0,    72,    73,    74,    75,    76,
       0,    77,    78,    79,     0,     0,    80,    81,     0,     0,
       0,    82,    83,   516,    85,    86,    87,    88,    89,   571,
      91,     0,    92,     0,     0,     0,    93,     0,    94,    95,
      96,    97,     0,    98,     0,     0,     0,    99,   100,   101,
     102,   103,     0,     0,     0,     0,     0,     0,   104,   105,
     106,   107,   108,   109,   110,   572,   112,     0,   113,   114,
     115,   116,   117,     0,     0,     0,   118,   119,   120,   121,
     122,   123,   124,   125,     0,   126,     0,   127,   128,     0,
       0,   129,   130,   131,     0,     0,     0,   132,     0,   133,
     134,   135,     0,   137,   138,     0,   139,     0,   140,     0,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,     0,     0,   152,   153,   154,     0,   155,   428,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   534,   535,   536,   185,   186,   537,
     574,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,     0,   202,   203,   204,     0,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,     0,   253,     0,
     254,   255,   256,   257,   258,   259,   260,  -888,   468,     0,
    -261,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  -888,
       0,     0,     0,  -888,     0,     0,     0,  -888,  -888,     0,
       0,     0,     0,  -888,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  -261,     0,     0,  -888,     0,  -261,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    -888,     0,  -888,  -888,  -888,     0,     0,  -888,  -888,  -888,
    -888,     0,     0,     0,  -888,  -888,     0,     0,     0,     0,
       0,  -888,     0,     0,  -888,  -888,  -261,     0,     0,     0,
    -888,     0,     0,     0,     0,  -888,  -888,     0,     0,     0,
       0,  -888,     0,     0,     0,  -888,     0,     0,     0,  -888,
    -888,     0,  -888,     0,  -888,  -888,     0,     0,     0,  -888,
    -888,     0,     0,  -888,  -888,  -888,  -888,  -888,  -888,     0,
       0,  -888,     0,     0,     0,  -888,  -888,     0,     0,  -888,
       0,     0,     0,     0,  -888,     0,     0,  -888,     0,     0,
       0,     0,  -888,  -888,  -888,  -888,  -888,  -888,     0,  -888,
    -888,  -888,  -888,  -888,     0,     0,     0,     0,  -888,  -888,
    -888,     0,  -888,  -888,  -888,  -888,  -888,  -888,     0,  -888,
       0,  -888,     0,     0,     0,     0,     0,  -888,     0,     0,
       0,  -888,  -888,     0,  -889,   624,     0,  -262,     0,     0,
       0,     0,     0,     0,     0,     0,  -888,     0,  -888,     0,
    -888,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  -888,     0,     0,     0,     0,  -888,     0,     0,
    -888,     0,     0,     0,     0,     0,  -889,     0,     0,     0,
    -889,     0,     0,     0,  -889,  -889,     0,     0,     0,     0,
    -889,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  -262,     0,     0,  -889,     0,  -262,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  -888,     0,  -888,  -889,     0,  -889,
    -889,  -889,     0,     0,  -889,  -889,  -889,  -889,     0,     0,
       0,  -889,  -889,     0,     0,     0,     0,     0,  -889,     0,
       0,  -889,  -889,  -262,     0,     0,     0,  -889,     0,     0,
       0,     0,  -889,  -889,     0,     0,     0,     0,  -889,     0,
       0,     0,  -889,     0,     0,     0,  -889,  -889,     0,  -889,
       0,  -889,  -889,     0,     0,     0,  -889,  -889,     0,     0,
    -889,  -889,  -889,  -889,  -889,  -889,     0,     0,  -889,     0,
       0,     0,  -889,  -889,     0,     0,  -889,     0,     0,     0,
       0,  -889,     0,     0,  -889,     0,     0,     0,     0,  -889,
    -889,  -889,  -889,  -889,  -889,     0,  -889,  -889,  -889,  -889,
    -889,     0,     0,     0,     0,  -889,  -889,  -889,     0,  -889,
    -889,  -889,  -889,  -889,  -889,     0,  -889,     0,  -889,     0,
       0,     0,     0,     0,  -889,     0,     0,     0,  -889,  -889,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  -889,     0,  -889,     0,  -889,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  -889,
       0,     0,     0,     0,  -889,     0,     0,  -889,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     1,     2,     0,     0,     0,     3,     0,
       0,     0,     4,     5,     6,     7,     8,     9,    10,    11,
      12,  -889,    13,  -889,     0,    14,    15,     0,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,     0,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,     0,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,     0,    72,    73,    74,
      75,    76,     0,    77,    78,    79,     0,     0,    80,    81,
       0,     0,     0,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,     0,    92,     0,     0,     0,    93,     0,
      94,    95,    96,    97,     0,    98,     0,     0,     0,    99,
     100,   101,   102,   103,     0,     0,     0,     0,     0,     0,
     104,   105,   106,   107,   108,   109,   110,   111,   112,     0,
     113,   114,   115,   116,   117,     0,     0,     0,   118,   119,
     120,   121,   122,   123,   124,   125,     0,   126,     0,   127,
     128,     0,     0,   129,   130,   131,     0,     0,     0,   132,
       0,   133,   134,   135,   136,   137,   138,     0,   139,     0,
     140,     0,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,     0,     0,   152,   153,   154,     0,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,     0,   202,   203,   204,
       0,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,     0,
     253,     0,   254,   255,   256,   257,   258,   259,   260,   261,
     262,     1,     2,     0,     0,     0,     3,     0,     0,     0,
       4,     5,     6,     7,     8,     9,    10,    11,    12,     0,
      13,     0,     0,    14,    15,     0,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,     0,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,     0,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,     0,    72,    73,    74,    75,    76,
       0,    77,    78,    79,     0,     0,    80,    81,     0,     0,
       0,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,     0,    92,     0,     0,     0,    93,     0,    94,    95,
      96,    97,     0,    98,     0,     0,     0,    99,   100,   101,
     102,   103,     0,     0,     0,     0,     0,     0,   104,   105,
     106,   107,   108,   109,   110,   111,   112,     0,   113,   114,
     115,   116,   117,     0,     0,     0,   118,   119,   120,   121,
     122,   123,   124,   125,     0,   126,     0,   127,   128,     0,
       0,   129,   130,   131,     0,     0,     0,   132,     0,   133,
     134,   135,   136,   137,   138,     0,   139,     0,   140,     0,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,     0,     0,   152,   153,   154,     0,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,     0,   202,   203,   204,     0,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,     0,   253,     0,
     254,   255,   256,   257,   258,   259,   260,     0,   632,     1,
       2,     0,     0,     0,     3,     0,     0,     0,     4,     5,
       6,     7,     8,     9,    10,    11,    12,     0,    13,     0,
       0,   425,   426,     0,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,   427,    30,    31,
      32,    33,    34,     0,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,     0,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,     0,    72,    73,    74,    75,    76,     0,    77,
      78,    79,     0,     0,    80,    81,     0,     0,     0,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,     0,
      92,     0,     0,     0,    93,     0,    94,    95,    96,    97,
       0,    98,     0,     0,     0,    99,   100,   101,   102,   103,
       0,     0,     0,     0,     0,     0,   104,   105,   106,   107,
     108,   109,   110,   111,   112,     0,   113,   114,   115,   116,
     117,     0,     0,     0,   118,   119,   120,   121,   122,   123,
     124,   125,     0,   126,     0,   127,   128,     0,     0,   129,
     130,   131,     0,   842,     0,   132,     0,   133,   134,   135,
     136,   137,   138,     0,   139,     0,   140,     0,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,     0,
       0,   152,   153,   154,     0,   155,   428,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,     0,   202,   203,   204,     0,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,     0,   253,     0,   254,   255,
     256,   257,   258,   259,   260,     1,     2,     0,     0,     0,
       3,     0,     0,     0,     4,     5,     6,     7,     8,     9,
      10,    11,    12,     0,    13,     0,     0,   425,   426,     0,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,   427,    30,    31,    32,    33,    34,     0,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,     0,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,     0,    72,
      73,    74,    75,    76,     0,    77,    78,    79,     0,     0,
      80,    81,     0,     0,     0,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,     0,    92,     0,     0,     0,
      93,     0,    94,    95,    96,    97,     0,    98,     0,     0,
       0,    99,   100,   101,   102,   103,     0,     0,     0,     0,
       0,     0,   104,   105,   106,   107,   108,   109,   110,   111,
     112,     0,   113,   114,   115,   116,   117,     0,     0,     0,
     118,   119,   120,   121,   122,   123,   124,   125,     0,   126,
       0,   127,   128,     0,     0,   129,   130,   131,     0,     0,
       0,   132,     0,   133,   134,   135,   136,   137,   138,     0,
     139,     0,   140,     0,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,     0,     0,   152,   153,   154,
       0,   155,   428,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,     0,   202,
     203,   204,     0,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,     0,   253,     0,   254,   255,   256,   257,   258,   259,
     260,     1,     2,     0,     0,     0,     3,     0,     0,     0,
       4,     5,     6,     7,     8,     9,    10,    11,    12,     0,
      13,     0,     0,    14,    15,     0,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,     0,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,     0,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,     0,    72,    73,    74,    75,    76,
       0,    77,    78,    79,     0,     0,    80,    81,     0,     0,
       0,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,     0,    92,     0,     0,     0,    93,     0,    94,    95,
      96,    97,     0,    98,     0,     0,     0,    99,   100,   101,
     102,   103,     0,     0,     0,     0,     0,     0,   104,   105,
     106,   107,   108,   109,   110,   111,   112,     0,   113,   114,
     115,   116,   117,     0,     0,     0,   118,   119,   120,   121,
     122,   123,   124,   125,     0,   126,     0,   127,   128,     0,
       0,   129,   130,   131,     0,     0,     0,   132,     0,   133,
     134,   135,   136,   137,   138,     0,   139,     0,   140,     0,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,     0,     0,   152,   153,   154,     0,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,     0,   202,   203,   204,     0,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,     0,   253,     0,
     254,   255,   256,   257,   258,   259,   260,     1,     2,     0,
       0,     0,     3,     0,     0,     0,     4,     5,     6,     7,
       8,     9,    10,    11,    12,     0,    13,     0,     0,    14,
      15,     0,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,     0,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,     0,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
       0,    72,    73,    74,    75,    76,     0,    77,    78,    79,
       0,     0,    80,    81,     0,     0,     0,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,     0,    92,     0,
       0,     0,    93,     0,    94,    95,    96,    97,     0,    98,
       0,     0,     0,    99,   100,   101,   102,   103,     0,     0,
       0,     0,     0,     0,   104,   105,   106,   107,   108,   109,
     110,   111,   112,     0,   113,   114,   115,   116,   117,     0,
       0,     0,   118,   119,   120,   121,   122,   123,   124,   125,
       0,   126,     0,   127,   128,     0,     0,   129,   130,   131,
       0,     0,     0,   132,     0,   133,   134,   135,   136,   137,
     138,     0,   139,     0,   140,     0,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,     0,     0,   152,
     153,   154,     0,   155,   428,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
       0,   202,   203,   204,     0,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,     0,   253,     0,   254,   255,   256,   257,
     258,   259,   260,     1,     2,     0,     0,     0,     3,     0,
       0,     0,     4,     5,     6,     7,     8,     9,    10,    11,
      12,     0,    13,     0,     0,    14,   426,     0,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,     0,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,     0,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,     0,    72,    73,    74,
      75,    76,     0,    77,    78,    79,     0,     0,    80,    81,
       0,     0,     0,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,     0,    92,     0,     0,     0,    93,     0,
      94,    95,    96,    97,     0,    98,     0,     0,     0,    99,
     100,   101,   102,   103,     0,     0,     0,     0,     0,     0,
     104,   105,   106,   107,   108,   109,   110,   111,   112,     0,
     113,   114,   115,   116,   117,     0,     0,     0,   118,   119,
     120,   121,   122,   123,   124,   125,     0,   126,     0,   127,
     128,     0,     0,   129,   130,   131,     0,     0,     0,   132,
       0,   133,   134,   135,   136,   137,   138,     0,   139,     0,
     140,     0,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,     0,     0,   152,   153,   154,     0,   155,
     428,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,     0,   202,   203,   204,
       0,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,     0,
     253,     0,   254,   255,   256,   257,   258,   259,   260,     1,
       2,     0,     0,     0,     3,     0,     0,     0,     4,     5,
       6,     7,     8,     9,    10,    11,    12,     0,    13,     0,
       0,   912,   426,     0,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,   427,    30,    31,
      32,    33,    34,     0,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,     0,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,     0,    72,    73,    74,    75,    76,     0,    77,
      78,    79,     0,     0,    80,    81,     0,     0,     0,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,     0,
      92,     0,     0,     0,    93,     0,    94,    95,    96,    97,
       0,    98,     0,     0,     0,    99,   100,   101,   102,   103,
       0,     0,     0,     0,     0,     0,   104,   105,   106,   107,
     108,   109,   110,   111,   112,     0,   113,   114,   115,   116,
     117,     0,     0,     0,   118,   119,   120,   121,   122,   123,
     124,   125,     0,   126,     0,   127,   128,     0,     0,   129,
     130,   131,     0,     0,     0,   132,     0,   133,   134,   135,
     136,   137,   138,     0,   139,     0,   140,     0,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,     0,
       0,   152,   153,   154,     0,   155,   428,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,     0,   202,   203,   204,     0,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,     0,   253,     0,   254,   255,
     256,   257,   258,   259,   260,     1,     2,     0,     0,     0,
       3,     0,     0,     0,     4,     5,     6,     7,     8,     9,
      10,    11,    12,     0,    13,     0,     0,   425,   426,     0,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,  1385,   427,    30,    31,    32,    33,    34,     0,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,     0,    48,    49,    50,  1386,  1387,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,     0,    72,
      73,    74,    75,    76,     0,    77,    78,    79,     0,     0,
      80,    81,     0,     0,     0,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,     0,    92,     0,     0,     0,
      93,     0,    94,    95,    96,    97,     0,    98,     0,     0,
       0,    99,   100,   101,   102,   103,     0,     0,     0,     0,
       0,     0,   104,   105,   106,   107,   108,   109,   110,   111,
     112,     0,   113,   114,   115,   116,   117,     0,     0,     0,
     118,   119,   120,   121,   122,   123,   124,   125,     0,   126,
       0,   127,   128,     0,     0,   129,   130,   131,     0,     0,
       0,   132,     0,   133,   134,   135,   136,   137,   138,     0,
     139,     0,   140,     0,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,     0,     0,   152,   153,   154,
       0,   155,   428,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,  1388,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,     0,   202,
     203,   204,     0,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,     0,   253,     0,   254,   255,   256,   257,   258,   259,
     260,     1,     2,     0,     0,     0,     3,     0,     0,     0,
       4,     5,     6,     7,     8,     9,    10,     0,     0,     0,
      13,     0,     0,   425,   426,     0,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,   568,   427,
      30,    31,    32,    33,    34,     0,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,     0,
      48,    49,    50,   569,   570,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,     0,    72,    73,    74,    75,    76,
       0,    77,    78,    79,     0,     0,    80,    81,     0,     0,
       0,    82,    83,   516,    85,    86,    87,    88,    89,   571,
      91,     0,    92,     0,     0,     0,    93,     0,    94,    95,
      96,    97,     0,    98,     0,     0,     0,    99,   100,   101,
     102,   103,     0,     0,     0,     0,   972,     0,   104,   105,
     106,   107,   108,   109,   110,   572,   112,     0,   113,   114,
     115,   116,   117,     0,     0,     0,   118,   119,   120,   121,
     122,   123,   124,   125,     0,   126,     0,   127,   128,     0,
       0,   129,   130,   131,     0,     0,     0,   132,   973,   133,
     134,   135,     0,   137,   138,     0,   139,     0,   140,     0,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,     0,     0,   152,   153,   154,     0,   155,   428,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   534,   535,   536,   185,   186,   537,
     574,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,     0,   202,   203,   204,     0,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,     0,   253,     0,
     254,   255,   256,   257,   258,   259,   260,     1,     2,     0,
       0,     0,     3,     0,     0,     0,     4,     5,     6,     7,
       8,     9,    10,     0,     0,     0,    13,     0,     0,   425,
     426,     0,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,   568,   427,    30,    31,    32,    33,
      34,     0,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,     0,    48,    49,    50,   569,
     570,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
       0,    72,    73,    74,    75,    76,     0,    77,    78,    79,
       0,     0,    80,    81,     0,     0,     0,    82,    83,   516,
      85,    86,    87,    88,    89,   571,    91,     0,    92,     0,
       0,     0,    93,     0,    94,    95,    96,    97,     0,    98,
       0,     0,     0,    99,   100,   101,   102,   103,     0,     0,
       0,     0,   972,     0,   104,   105,   106,   107,   108,   109,
     110,   572,   112,     0,   113,   114,   115,   116,   117,     0,
       0,     0,   118,   119,   120,   121,   122,   123,   124,   125,
       0,   126,     0,   127,   128,     0,     0,   129,   130,   131,
       0,     0,     0,   132,   978,   133,   134,   135,     0,   137,
     138,     0,   139,     0,   140,     0,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,     0,     0,   152,
     153,   154,     0,   155,   428,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     534,   535,   536,   185,   186,   537,   574,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
       0,   202,   203,   204,     0,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,     0,   253,     0,   254,   255,   256,   257,
     258,   259,   260,     1,     2,     0,     0,     0,     3,     0,
       0,     0,     4,     5,     6,     7,     8,     9,    10,     0,
       0,     0,    13,     0,     0,   425,   426,     0,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
     568,   427,    30,    31,    32,    33,    34,     0,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,     0,    48,    49,    50,   569,   570,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,     0,    72,    73,    74,
      75,    76,     0,    77,    78,    79,     0,     0,    80,    81,
       0,     0,     0,    82,    83,   516,    85,    86,    87,    88,
      89,   571,    91,     0,    92,     0,     0,     0,    93,     0,
      94,    95,    96,    97,     0,    98,     0,     0,     0,    99,
     100,   101,   102,   103,     0,     0,     0,     0,     0,     0,
     104,   105,   106,   107,   108,   109,   110,   572,   112,     0,
     113,   114,   115,   116,   117,     0,     0,     0,   118,   119,
     120,   121,   122,   123,   124,   125,     0,   126,     0,   127,
     128,     0,     0,   129,   130,   131,     0,     0,   573,   132,
       0,   133,   134,   135,     0,   137,   138,     0,   139,     0,
     140,     0,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,     0,     0,   152,   153,   154,     0,   155,
     428,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   534,   535,   536,   185,
     186,   537,   574,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,     0,   202,   203,   204,
       0,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,     0,
     253,     0,   254,   255,   256,   257,   258,   259,   260,     1,
       2,     0,     0,     0,     3,     0,     0,     0,     4,     5,
       6,     7,     8,     9,    10,     0,     0,     0,    13,     0,
       0,   425,   426,     0,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,   568,   427,    30,    31,
      32,    33,    34,     0,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,     0,    48,    49,
      50,   569,   570,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,     0,    72,    73,    74,    75,    76,     0,    77,
      78,    79,     0,     0,    80,    81,     0,     0,     0,    82,
      83,   516,    85,    86,    87,    88,    89,   571,    91,     0,
      92,     0,     0,     0,    93,     0,    94,    95,    96,    97,
       0,    98,     0,     0,     0,    99,   100,   101,   102,   103,
       0,     0,     0,     0,     0,     0,   104,   105,   106,   107,
     108,   109,   110,   572,   112,     0,   113,   114,   115,   116,
     117,     0,     0,     0,   118,   119,   120,   121,   122,   123,
     124,   125,     0,   126,     0,   127,   128,     0,     0,   129,
     130,   131,     0,     0,     0,   132,   578,   133,   134,   135,
       0,   137,   138,     0,   139,     0,   140,     0,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,     0,
       0,   152,   153,   154,     0,   155,   428,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   534,   535,   536,   185,   186,   537,   574,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,     0,   202,   203,   204,     0,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,     0,   253,     0,   254,   255,
     256,   257,   258,   259,   260,     1,     2,     0,     0,     0,
       3,     0,     0,     0,     4,     5,     6,     7,     8,     9,
      10,     0,     0,     0,    13,     0,     0,   425,   426,     0,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,   568,   427,    30,    31,    32,    33,    34,     0,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,     0,    48,    49,    50,   569,   570,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,     0,    72,
      73,    74,    75,    76,     0,    77,    78,    79,     0,     0,
      80,    81,     0,     0,     0,    82,    83,   516,    85,    86,
      87,    88,    89,   571,    91,     0,    92,     0,     0,     0,
      93,     0,    94,    95,    96,    97,     0,    98,     0,     0,
       0,    99,   100,   101,   102,   103,     0,     0,     0,     0,
       0,     0,   104,   105,   106,   107,   108,   109,   110,   572,
     112,     0,   113,   114,   115,   116,   117,     0,     0,     0,
     118,   119,   120,   121,   122,   123,   124,   125,     0,   126,
       0,   127,   128,     0,     0,   129,   130,   131,     0,     0,
       0,   132,     0,   133,   134,   135,     0,   137,   138,     0,
     139,     0,   140,     0,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,     0,     0,   152,   153,   154,
       0,   155,   428,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   534,   535,
     536,   185,   186,   537,   574,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,     0,   202,
     203,   204,     0,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   626,   253,     0,   254,   255,   256,   257,   258,   259,
     260,     1,     2,     0,     0,     0,     3,     0,     0,     0,
       4,     5,     6,     7,     8,     9,    10,     0,     0,     0,
      13,     0,     0,   425,   426,     0,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,   568,   427,
      30,    31,    32,    33,    34,     0,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,     0,
      48,    49,    50,   569,   570,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,     0,    72,    73,    74,    75,    76,
       0,    77,    78,    79,     0,     0,    80,    81,     0,     0,
       0,    82,    83,   516,    85,    86,    87,    88,    89,   571,
      91,     0,    92,     0,     0,     0,    93,     0,    94,    95,
      96,    97,     0,    98,     0,     0,     0,    99,   100,   101,
     102,   103,     0,     0,     0,     0,     0,     0,   104,   105,
     106,   107,   108,   109,   110,   572,   112,     0,   113,   114,
     115,   116,   117,     0,     0,     0,   118,   119,   120,   121,
     122,   123,   124,   125,     0,   126,     0,   127,   128,     0,
       0,   129,   130,   131,     0,     0,     0,   132,     0,   133,
     134,   135,     0,   137,   138,     0,   139,     0,   140,     0,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,     0,     0,   152,   153,   154,     0,   155,   428,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   534,   535,   536,   185,   186,   537,
     574,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,     0,   202,   203,   204,     0,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,     0,   253,   628,
     254,   255,   256,   257,   258,   259,   260,     1,     2,     0,
       0,     0,     3,     0,     0,     0,     4,     5,     6,     7,
       8,     9,    10,     0,     0,     0,    13,     0,     0,   425,
     426,     0,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,   568,   427,    30,    31,    32,    33,
      34,     0,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,     0,    48,    49,    50,   569,
     570,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
       0,    72,    73,    74,    75,    76,     0,    77,    78,    79,
       0,     0,    80,    81,     0,     0,     0,    82,    83,   516,
      85,    86,    87,    88,    89,   571,    91,     0,    92,     0,
       0,     0,    93,     0,    94,    95,    96,    97,     0,    98,
       0,     0,     0,    99,   100,   101,   102,   103,     0,     0,
       0,     0,     0,     0,   104,   105,   106,   107,   108,   109,
     110,   572,   112,     0,   113,   114,   115,   116,   117,     0,
       0,     0,   118,   119,   120,   121,   122,   123,   124,   125,
       0,   126,     0,   127,   128,     0,     0,   129,   130,   131,
       0,     0,   971,   132,     0,   133,   134,   135,     0,   137,
     138,     0,   139,     0,   140,     0,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,     0,     0,   152,
     153,   154,     0,   155,   428,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     534,   535,   536,   185,   186,   537,   574,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
       0,   202,   203,   204,     0,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,     0,   253,     0,   254,   255,   256,   257,
     258,   259,   260,     1,     2,     0,     0,     0,     3,     0,
       0,     0,     4,     5,     6,     7,     8,     9,    10,     0,
       0,     0,    13,     0,     0,   425,   426,     0,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
     568,   427,    30,    31,    32,    33,    34,     0,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,     0,    48,    49,    50,   569,   570,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,     0,    72,    73,    74,
      75,    76,     0,    77,    78,    79,     0,     0,    80,    81,
       0,     0,     0,    82,    83,   516,    85,    86,    87,    88,
      89,   571,    91,     0,    92,     0,     0,     0,    93,     0,
      94,    95,    96,    97,     0,    98,     0,     0,     0,    99,
     100,   101,   102,   103,     0,     0,     0,     0,     0,     0,
     104,   105,   106,   107,   108,   109,   110,   572,   112,     0,
     113,   114,   115,   116,   117,     0,     0,     0,   118,   119,
     120,   121,   122,   123,   124,   125,     0,   126,     0,   127,
     128,     0,     0,   129,   130,   131,     0,     0,     0,   132,
    1215,   133,   134,   135,     0,   137,   138,     0,   139,     0,
     140,     0,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,     0,     0,   152,   153,   154,     0,   155,
     428,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   534,   535,   536,   185,
     186,   537,   574,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,     0,   202,   203,   204,
       0,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,     0,
     253,     0,   254,   255,   256,   257,   258,   259,   260,     1,
       2,     0,     0,     0,     3,     0,     0,     0,     4,     5,
       6,     7,     8,     9,    10,     0,     0,     0,    13,     0,
       0,   425,   426,     0,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,   568,   427,    30,    31,
      32,    33,    34,     0,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,     0,    48,    49,
      50,   569,   570,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,     0,    72,    73,    74,    75,    76,     0,    77,
      78,    79,     0,     0,    80,    81,     0,     0,     0,    82,
      83,   516,    85,    86,    87,    88,    89,   571,    91,     0,
      92,     0,     0,     0,    93,     0,    94,    95,    96,    97,
       0,    98,     0,     0,     0,    99,   100,   101,   102,   103,
       0,     0,     0,     0,  1480,     0,   104,   105,   106,   107,
     108,   109,   110,   572,   112,     0,   113,   114,   115,   116,
     117,     0,     0,     0,   118,   119,   120,   121,   122,   123,
     124,   125,     0,   126,     0,   127,   128,     0,     0,   129,
     130,   131,     0,     0,     0,   132,     0,   133,   134,   135,
       0,   137,   138,     0,   139,     0,   140,     0,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,     0,
       0,   152,   153,   154,     0,   155,   428,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   534,   535,   536,   185,   186,   537,   574,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,     0,   202,   203,   204,     0,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,     0,   253,     0,   254,   255,
     256,   257,   258,   259,   260,     1,     2,     0,     0,     0,
       3,     0,     0,     0,     4,     5,     6,     7,     8,     9,
      10,     0,     0,     0,    13,     0,     0,   425,   426,     0,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
     502,    27,   504,   427,    30,   505,    32,    33,    34,     0,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,   507,     0,    48,    49,    50,   509,   510,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,     0,    72,
      73,    74,    75,    76,     0,    77,    78,    79,     0,     0,
      80,    81,     0,     0,     0,    82,    83,   516,    85,    86,
      87,    88,    89,   571,    91,     0,    92,     0,     0,     0,
      93,     0,    94,    95,    96,    97,     0,    98,     0,     0,
       0,   519,   100,   101,   102,   103,     0,     0,     0,     0,
       0,     0,   104,   105,   106,   107,   108,   109,   110,   572,
     112,     0,   113,   114,   716,   116,   117,     0,     0,     0,
     118,   119,   120,   121,   122,   123,   124,   125,     0,   126,
       0,   717,   128,     0,     0,   129,   130,   131,     0,     0,
       0,   132,     0,   133,   134,   135,     0,   137,   138,     0,
     139,     0,   140,     0,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,     0,     0,   152,   153,   154,
       0,   155,   428,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   529,   169,   530,   171,   531,   532,
     174,   175,   176,   177,   178,   179,   533,   181,   534,   535,
     536,   185,   186,   537,   538,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   539,     0,   202,
     540,   204,     0,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,     0,   253,     0,   254,   541,   256,   257,   258,   259,
     260,     1,     2,     0,     0,     0,     3,     0,     0,     0,
       4,     5,     6,     7,     8,     9,    10,     0,     0,     0,
      13,     0,     0,   425,   426,     0,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,   568,   427,
      30,    31,    32,    33,    34,     0,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,     0,
      48,    49,    50,   569,   570,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,     0,    72,    73,    74,    75,    76,
       0,    77,    78,    79,     0,     0,    80,    81,     0,     0,
       0,    82,    83,   516,    85,    86,    87,    88,    89,   571,
      91,     0,    92,     0,     0,     0,    93,     0,    94,    95,
      96,    97,     0,    98,     0,     0,     0,    99,   100,   101,
     102,   103,     0,     0,     0,     0,     0,     0,   104,   105,
     106,   107,   108,   109,   110,   572,   112,     0,   113,   114,
     115,   116,   117,     0,     0,     0,   118,   119,   120,   121,
     122,   123,   124,   125,     0,   126,     0,   127,   128,     0,
       0,   129,   130,   131,     0,     0,     0,   132,     0,   133,
     134,   135,     0,   137,   138,     0,   139,     0,   140,     0,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,     0,     0,   152,   153,   154,     0,   155,   428,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   534,   535,   536,   185,   186,   537,
     574,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,     0,   202,   203,   204,     0,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,     0,   253,     0,
     254,   255,   256,   257,   258,   259,   260,     1,     2,     0,
       0,     0,     3,     0,     0,     0,     4,     5,     6,     7,
       8,     9,    10,     0,     0,     0,    13,     0,     0,   425,
     426,     0,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,   502,    27,   504,   427,    30,   505,    32,    33,
      34,     0,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,   507,     0,    48,    49,    50,   509,
     510,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
       0,    72,    73,    74,    75,    76,     0,    77,    78,    79,
       0,     0,    80,    81,     0,     0,     0,    82,    83,   516,
      85,    86,    87,    88,    89,   571,    91,     0,    92,     0,
       0,     0,    93,     0,    94,    95,    96,    97,     0,    98,
       0,     0,     0,   519,   100,   101,   102,   103,     0,     0,
       0,     0,     0,     0,   104,   105,   106,   107,   108,   109,
     110,   572,   112,     0,   113,   114,   115,   116,   117,     0,
       0,     0,   118,   119,   120,   121,   122,   123,   124,   125,
       0,   126,     0,   127,   128,     0,     0,   129,   130,   131,
       0,     0,     0,   132,     0,   133,   134,   135,     0,   137,
     138,     0,   139,     0,   140,     0,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,     0,     0,   152,
     153,   154,     0,   155,   428,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   529,   169,   530,   171,
     531,   532,   174,   175,   176,   177,   178,   179,   533,   181,
     534,   535,   536,   185,   186,   537,   538,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   539,
       0,   202,   203,   204,     0,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,     0,   253,     0,   254,   541,   256,   257,
     258,   259,   260,     1,     2,     0,     0,     0,     3,     0,
       0,     0,     4,     5,     6,     7,     8,     9,    10,     0,
       0,     0,    13,     0,     0,   425,   426,     0,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,   502,    27,
     504,   427,    30,   505,    32,    33,    34,     0,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
     507,     0,    48,    49,    50,   509,   510,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,     0,    72,    73,    74,
      75,    76,     0,    77,    78,    79,     0,     0,    80,    81,
       0,     0,     0,    82,    83,   516,    85,    86,    87,    88,
      89,   571,    91,     0,    92,     0,     0,     0,    93,     0,
      94,    95,    96,    97,     0,    98,     0,     0,     0,   519,
     100,   101,   102,   103,     0,     0,     0,     0,     0,     0,
     104,   105,   106,   107,   108,   109,   110,   572,   112,     0,
     113,   114,   115,   116,   117,     0,     0,     0,   118,   119,
     120,   121,   122,   123,   124,   125,     0,   126,     0,   127,
     128,     0,     0,   129,   130,   131,     0,     0,     0,   132,
       0,   133,   134,   135,     0,   137,   138,     0,   139,     0,
     140,     0,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,     0,     0,   152,   153,   154,     0,   155,
     428,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   529,   169,   530,   171,   531,   532,   174,   175,
     176,   177,   178,   179,   533,   181,   534,   535,   536,   185,
     186,   537,   538,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   539,     0,   202,   540,   204,
       0,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,     0,
     253,     0,   254,   541,   256,   257,   258,   259,   260,     1,
       2,     0,     0,     0,     3,     0,     0,     0,     4,     5,
       6,     7,     8,     9,    10,     0,     0,     0,    13,     0,
       0,   425,   426,     0,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,   568,   427,    30,    31,
      32,    33,    34,     0,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,     0,    48,    49,
      50,   569,   570,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,     0,    72,    73,    74,    75,    76,     0,    77,
      78,    79,     0,     0,    80,    81,     0,     0,     0,    82,
      83,   516,    85,    86,    87,    88,    89,  1164,    91,     0,
      92,     0,     0,     0,    93,     0,    94,    95,    96,    97,
       0,    98,     0,     0,     0,    99,   100,   101,   102,   103,
       0,     0,     0,     0,     0,     0,   104,   105,   106,   107,
     108,   109,   110,   572,   112,     0,   113,   114,   115,   116,
     117,     0,     0,     0,   118,   119,   120,   121,   122,   123,
     124,   125,     0,   126,     0,   127,   128,     0,     0,   129,
     130,   131,     0,     0,     0,   132,     0,   133,   134,   135,
       0,   137,   138,     0,   139,     0,   140,     0,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,     0,
       0,   152,   153,   154,     0,   155,   428,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   534,   535,   536,   185,   186,   537,   574,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,     0,   202,   203,   204,     0,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,     0,   253,     0,   254,   255,
     256,   257,   258,   259,   260,     1,     2,     0,     0,     0,
       3,     0,     0,     0,     4,     5,     6,     7,     8,     9,
      10,     0,     0,     0,    13,     0,     0,   425,   426,     0,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,   568,   427,    30,    31,    32,    33,    34,     0,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,     0,    48,    49,    50,   569,   570,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,     0,    72,
      73,    74,    75,    76,     0,    77,    78,    79,     0,     0,
      80,    81,     0,     0,     0,    82,    83,   516,    85,    86,
      87,    88,    89,   571,    91,     0,    92,     0,     0,     0,
      93,     0,    94,    95,    96,    97,     0,    98,     0,     0,
       0,    99,   100,   101,   102,   103,     0,     0,     0,     0,
       0,     0,   104,   105,   106,   107,   108,   109,   110,   572,
     112,     0,     0,   114,   115,   116,   117,     0,     0,     0,
     118,   119,   120,   121,   122,   123,   124,   125,     0,   126,
       0,   127,   128,     0,     0,   129,   130,   131,     0,     0,
       0,   132,     0,   133,   134,   135,     0,   137,   138,     0,
     139,     0,   140,     0,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,     0,     0,   152,   153,   154,
       0,   155,   428,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   534,   535,
     536,   185,   186,   537,   574,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,     0,   202,
     203,   204,     0,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,     0,   253,     0,   254,   255,   256,   257,   258,   259,
     260,     1,     2,     0,     0,     0,     3,     0,     0,     0,
       4,     5,     6,     7,     8,     9,    10,     0,     0,     0,
      13,     0,     0,   425,   426,     0,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,   502,    27,   504,   427,
      30,   505,    32,    33,    34,     0,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,   507,     0,
      48,    49,    50,   509,   510,    53,   511,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,     0,    72,    73,    74,    75,    76,
       0,    77,    78,    79,     0,     0,    80,    81,     0,     0,
       0,    82,    83,   516,    85,    86,    87,    88,    89,   571,
      91,     0,    92,     0,     0,     0,    93,     0,    94,    95,
      96,    97,     0,    98,     0,     0,     0,   519,   100,   101,
     102,   103,     0,     0,     0,     0,     0,     0,   104,   105,
     106,   107,   108,   109,   110,   572,   112,     0,   113,   114,
       0,   116,   117,     0,     0,     0,   118,   119,   120,   121,
     122,   123,   124,   125,     0,   126,     0,     0,     0,     0,
       0,   129,   130,   131,     0,     0,     0,   132,     0,   133,
     134,   135,     0,   137,   138,     0,   139,     0,   140,     0,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,     0,     0,   152,   153,   154,     0,   155,   428,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     529,   169,   530,   171,   531,   532,   174,   175,   176,   177,
     178,   179,   533,   181,   534,   535,   536,   185,   186,   537,
     538,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   539,     0,   202,   540,   204,     0,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,     0,   253,     0,
     254,   541,   256,   257,   258,   259,   260,     1,     2,     0,
       0,     0,     3,     0,     0,     0,     4,     5,     6,     7,
       8,     9,    10,     0,     0,     0,    13,     0,     0,   425,
     426,     0,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,   502,    27,   504,   427,    30,   505,    32,    33,
      34,     0,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,   507,     0,    48,    49,    50,   509,
     510,    53,   511,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
       0,    72,    73,    74,    75,    76,     0,    77,    78,    79,
       0,     0,    80,    81,     0,     0,     0,    82,    83,   516,
      85,    86,    87,    88,    89,   571,    91,     0,    92,     0,
       0,     0,    93,     0,    94,    95,    96,    97,     0,    98,
       0,     0,     0,   519,   100,   101,   102,   103,     0,     0,
       0,     0,     0,     0,   104,   105,   106,   107,   108,   109,
     110,   572,   112,     0,   113,   114,     0,   116,   117,     0,
       0,     0,   118,   119,   120,   121,   122,   123,   124,   125,
       0,   126,     0,     0,     0,     0,     0,   129,   130,   131,
       0,     0,     0,   132,     0,   133,   134,   135,     0,     0,
       0,     0,   139,     0,   140,     0,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,     0,     0,   152,
     153,   154,     0,   155,   428,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   529,   169,   530,   171,
     531,   532,   174,   175,   176,   177,   178,   179,   533,   181,
     534,   535,   536,   185,   186,   537,   538,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   539,
       0,   202,   540,   204,     0,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,     0,   253,     0,   254,   541,   256,   257,
     258,   259,   260,     1,     2,     0,     0,     0,     3,     0,
       0,     0,     4,     5,     6,     7,     8,     9,    10,     0,
       0,     0,    13,     0,     0,   425,   426,     0,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,   502,    27,
     504,   427,    30,   505,    32,    33,    34,     0,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
     507,     0,    48,    49,    50,   509,   510,    53,   511,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,     0,    72,    73,    74,
      75,    76,     0,    77,    78,    79,     0,     0,    80,    81,
       0,     0,     0,    82,    83,   516,    85,    86,    87,    88,
      89,   571,    91,     0,    92,     0,     0,     0,    93,     0,
      94,    95,    96,    97,     0,    98,     0,     0,     0,   519,
       0,   101,   102,   103,     0,     0,     0,     0,     0,     0,
     104,   105,   106,   107,     0,   109,   110,   572,   112,     0,
     113,   114,     0,   116,   117,     0,     0,     0,   118,   119,
     120,   121,   122,   123,   124,   125,     0,   126,     0,     0,
       0,     0,     0,   129,   130,   131,     0,     0,     0,   132,
       0,   133,   134,   135,     0,     0,     0,     0,   139,     0,
     140,     0,   141,     0,   143,     0,   145,   146,   147,   148,
     149,   150,   151,     0,     0,   152,   153,   154,     0,   155,
     428,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   529,   169,   530,   171,   531,   532,   174,   175,
     176,   177,   178,   179,   533,   181,   534,   535,   536,   185,
     186,   537,   538,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   539,     0,   202,   540,   204,
       0,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,     0,
     253,     0,   254,   541,   256,   257,   258,   259,   260,     1,
       2,     0,     0,     0,     3,     0,     0,     0,     4,     5,
       6,     7,     8,     9,    10,     0,     0,     0,    13,     0,
       0,   425,   426,     0,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,   502,    27,   504,   427,    30,   505,
      32,    33,    34,     0,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,   507,     0,    48,    49,
      50,   509,   510,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,     0,    72,    73,    74,    75,    76,     0,    77,
      78,    79,     0,     0,    80,    81,     0,     0,     0,    82,
      83,   516,    85,    86,    87,    88,     0,   571,    91,     0,
      92,     0,     0,     0,    93,     0,    94,    95,    96,    97,
       0,    98,     0,     0,     0,   519,     0,   101,   102,   103,
       0,     0,     0,     0,     0,     0,     0,   105,   106,   107,
       0,   109,   110,   572,     0,     0,     0,   114,     0,     0,
     117,     0,     0,     0,   118,   119,   120,   121,   122,   123,
     124,   125,     0,   126,     0,     0,   128,     0,     0,   129,
     130,   131,     0,     0,     0,   132,     0,   133,   134,   135,
       0,     0,     0,     0,     0,     0,   140,     0,   141,     0,
     143,     0,   145,   146,   147,   148,   149,   150,   151,     0,
       0,   152,   153,   154,     0,   155,   428,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   529,   169,
     530,   171,   531,   532,   174,   175,   176,   177,   178,   179,
     533,   181,   534,   535,   536,   185,   186,   537,   538,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   539,     0,   202,   203,   204,     0,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,     0,   253,     0,   254,   541,
     256,   257,   258,   259,   260,     1,     2,     0,     0,     0,
       3,     0,     0,     0,     4,     5,     6,     7,     8,     9,
      10,     0,     0,     0,    13,     0,     0,   425,   426,     0,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,   568,   427,    30,    31,    32,    33,    34,     0,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,     0,    48,    49,    50,   569,   570,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,     0,    72,
      73,    74,    75,    76,     0,    77,    78,    79,     0,     0,
      80,    81,     0,     0,     0,    82,    83,   516,    85,    86,
      87,    88,     0,   571,    91,     0,    92,     0,     0,     0,
      93,     0,    94,    95,    96,    97,     0,    98,     0,     0,
       0,    99,     0,   101,   102,   103,     0,     0,     0,     0,
       0,     0,     0,   105,   106,   107,     0,   109,   110,   572,
       0,     0,     0,   114,     0,     0,   117,     0,     0,     0,
     118,   119,   120,   121,   122,   123,   124,   125,     0,   126,
       0,     0,   128,     0,     0,   129,   130,   131,     0,     0,
       0,   132,     0,   133,   134,   135,     0,     0,     0,     0,
       0,     0,   140,     0,   141,     0,   143,     0,   145,   146,
     147,   148,   149,   150,   151,     0,     0,   152,   153,   154,
       0,   155,   428,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   534,   535,
     536,   185,   186,   537,   574,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,     0,   202,
     203,   204,     0,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,     0,   253,     0,   630,   255,   256,   257,   258,   259,
     260,     1,     2,     0,     0,     0,     3,     0,     0,     0,
       4,     5,     6,     7,     8,     9,    10,     0,     0,     0,
      13,     0,     0,   425,   426,     0,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,   568,   427,
       0,    31,    32,    33,    34,     0,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,     0,
      48,    49,    50,   569,   570,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,     0,     0,    72,    73,    74,    75,    76,
       0,    77,     0,     0,     0,     0,    80,    81,     0,     0,
       0,    82,    83,   516,    85,    86,    87,    88,     0,   571,
      91,     0,    92,     0,     0,     0,    93,     0,    94,    95,
      96,    97,     0,    98,     0,     0,     0,    99,     0,   101,
     102,   103,     0,     0,     0,     0,     0,     0,     0,   105,
     106,   107,     0,   109,   110,   572,     0,     0,  -621,   114,
       0,     0,   117,     0,     0,     0,   118,   119,   120,   121,
     122,   123,   124,   125,     0,   126,     0,     0,   128,     0,
       0,   129,   130,   131,     0,     0,     0,   132,     0,   133,
     134,   135,     0,     0,     0,     0,     0,     0,   140,     0,
     141,     0,   143,     0,   145,   146,   147,   148,   149,   150,
     151,     0,     0,   152,   153,   154,     0,   155,   428,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   534,   535,   536,   185,   186,   537,
     574,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,     0,   202,   203,   204,     0,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,     0,   253,     0,
     254,   255,   256,   257,   258,   259,   260,     1,     2,     0,
       0,     0,     3,     0,     0,     0,     4,     5,     6,     7,
       8,     9,    10,     0,     0,     0,    13,     0,     0,   425,
     426,     0,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,   568,   427,     0,    31,    32,    33,
      34,     0,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,     0,    48,    49,    50,   569,
     570,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,     0,
       0,    72,    73,    74,    75,    76,     0,    77,     0,     0,
       0,     0,    80,    81,     0,     0,     0,    82,    83,   516,
      85,    86,    87,    88,     0,   571,    91,     0,    92,     0,
       0,     0,    93,     0,    94,    95,    96,    97,     0,    98,
       0,     0,     0,    99,     0,   101,   102,   103,     0,     0,
       0,     0,     0,     0,     0,   105,   106,   107,     0,   109,
     110,   572,     0,     0,   113,   114,     0,     0,   117,     0,
       0,     0,   118,   119,   120,   121,   122,   123,   124,   125,
       0,   126,     0,     0,   128,     0,     0,   129,   130,   131,
       0,     0,     0,   132,     0,   133,   134,   135,     0,     0,
       0,     0,     0,     0,   140,     0,   141,     0,   143,     0,
     145,   146,   147,   148,   149,   150,   151,     0,     0,   152,
     153,   154,     0,   155,   428,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     534,   535,   536,   185,   186,   537,   574,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
       0,   202,   203,   204,     0,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,     0,   253,     0,   254,   255,   256,   257,
     258,   259,   260,     1,     2,     0,     0,     0,     3,     0,
       0,     0,     4,     5,     6,     7,     8,     9,    10,     0,
       0,     0,    13,     0,     0,   425,   426,     0,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
     568,   427,     0,    31,    32,    33,    34,     0,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,     0,    48,    49,    50,   569,   570,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,     0,     0,    72,    73,    74,
      75,    76,     0,    77,     0,     0,     0,     0,    80,    81,
       0,     0,     0,    82,    83,   516,    85,    86,    87,    88,
       0,   571,    91,     0,    92,     0,     0,     0,    93,     0,
      94,    95,    96,    97,     0,    98,     0,     0,     0,    99,
       0,   101,   102,   103,     0,     0,     0,     0,     0,     0,
       0,   105,   106,   107,     0,   109,   110,   572,     0,     0,
       0,   114,     0,     0,   117,     0,     0,     0,   118,   119,
     120,   121,   122,   123,   124,   125,     0,   126,     0,     0,
     128,     0,     0,   129,   130,   131,     0,     0,     0,   132,
       0,   133,   134,   135,     0,     0,     0,     0,     0,     0,
     140,     0,   141,     0,   143,     0,   145,   146,   147,   148,
     149,   150,   151,     0,     0,   152,   153,   154,     0,   155,
     428,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   534,   535,   536,   185,
     186,   537,   574,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,     0,   202,   203,   204,
       0,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,     0,
     253,     0,   254,   255,   256,   257,   258,   259,   260,     1,
       2,     0,     0,     0,     3,     0,     0,     0,     4,     0,
       0,     0,     0,     9,    10,     0,     0,     0,     0,     0,
       0,   425,   426,     0,    16,    17,    18,   499,    20,    21,
      22,   500,    24,   501,   502,   503,   504,   427,    30,   505,
      32,    33,    34,     0,    35,    36,    37,    38,   506,    40,
      41,    42,    43,    44,    45,    46,   507,     0,    48,   508,
      50,   509,   510,    53,   511,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,   512,
     513,    71,     0,    72,    73,    74,   514,     0,     0,    77,
      78,    79,     0,     0,   515,    81,     0,     0,     0,     0,
      83,   516,    85,   517,   518,    88,    89,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    94,    95,    96,    97,
       0,    98,     0,     0,     0,   519,   100,   101,   520,   521,
       0,     0,     0,     0,     0,     0,   104,   105,   106,     0,
     108,   109,   110,     0,     0,     0,     0,     0,     0,   116,
     522,     0,     0,     0,   118,   119,   120,   121,   523,   123,
     124,   524,     0,     0,     0,     0,     0,     0,     0,   525,
     526,   131,     0,     0,     0,   132,     0,   133,   134,   527,
       0,     0,     0,     0,   139,     0,   140,     0,   141,   142,
     143,   144,   528,   146,   147,   148,   149,   150,   151,     0,
       0,   152,   153,     0,     0,   155,   428,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   529,   169,
     530,   171,   531,   532,   174,   175,   176,   177,   178,   179,
     533,   181,   534,   535,   536,   185,   186,   537,   538,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   539,     0,   202,   540,   204,     0,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,     0,     0,     0,     0,   254,   541,
     256,   257,   258,   259,   260,     1,     2,     0,     0,     0,
       3,     0,     0,     0,     4,     0,     0,     0,     0,     9,
      10,     0,     0,     0,     0,     0,     0,   425,   426,     0,
      16,    17,    18,   549,    20,    21,    22,   500,   550,   551,
     502,   503,   504,   427,    30,   505,    32,   552,    34,     0,
      35,    36,    37,    38,   553,    40,   554,   555,    43,    44,
      45,    46,   507,     0,    48,   556,    50,   509,   510,    53,
     511,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,   512,   513,    71,     0,    72,
      73,    74,   557,     0,     0,    77,    78,    79,     0,     0,
     515,    81,     0,     0,     0,     0,    83,   516,    85,   517,
     518,    88,    89,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    94,    95,    96,    97,     0,    98,     0,     0,
       0,   519,   100,   101,   520,   521,     0,     0,     0,     0,
       0,     0,   104,   105,   106,     0,   108,   109,   110,     0,
       0,     0,     0,     0,     0,   116,   522,     0,     0,     0,
     118,   119,   120,   121,   523,   123,   124,   524,     0,     0,
       0,     0,     0,     0,     0,   525,   526,   131,     0,     0,
       0,   132,     0,   133,   134,   527,     0,     0,     0,     0,
     139,     0,   140,     0,   141,   142,   143,   144,   528,   146,
     147,   148,   149,   150,   151,     0,     0,   152,   153,     0,
       0,   155,   428,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   529,   558,   530,   171,   531,   532,
     174,   175,   176,   177,   178,   179,   533,   181,   534,   535,
     536,   185,   186,   537,   538,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   539,     0,   202,
     540,   204,     0,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
       0,     0,     0,     0,   254,   541,   256,   257,   258,   259,
     260,     1,     2,     0,     0,     0,     3,     0,     0,     0,
       4,     5,     6,     7,     8,     9,    10,     0,     0,     0,
      13,     0,     0,   425,   426,     0,    16,    17,    18,    19,
      20,    21,     0,    23,    24,    25,     0,    27,   568,   427,
       0,     0,    32,    33,    34,     0,     0,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,     0,
       0,    49,    50,   569,   570,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,     0,     0,     0,     0,    74,    75,    76,
       0,     0,     0,     0,     0,     0,    80,     0,     0,     0,
       0,    82,    83,   516,    85,    86,    87,    88,     0,   571,
      91,     0,    92,     0,     0,     0,    93,     0,    94,    95,
      96,    97,     0,    98,     0,     0,     0,    99,     0,   101,
     102,   103,     0,     0,     0,     0,     0,     0,     0,   105,
     106,   107,     0,   109,   110,   572,     0,     0,     0,   114,
       0,     0,   117,     0,     0,     0,   118,   119,   120,   121,
     122,   123,   124,   125,     0,   126,     0,     0,   128,     0,
       0,   129,   130,   131,     0,     0,     0,   132,     0,   133,
     134,   135,     0,     0,     0,     0,     0,     0,   140,     0,
     141,     0,   143,     0,   145,   146,   147,   148,   149,   150,
     151,     0,     0,   152,   153,   154,     0,   155,   428,   157,
     158,   159,   160,   161,     0,   163,   164,   165,   166,   167,
     168,   606,   170,   607,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   534,   535,   536,   185,   186,   537,
     574,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,     0,     0,   202,   203,   204,     0,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,     0,   253,     3,
     608,   255,   256,   257,   258,   259,   260,     0,     9,    10,
       0,     0,     0,    13,     0,     0,   425,   426,     0,    16,
      17,    18,   549,    20,    21,    22,   500,   550,   551,   502,
     503,   504,   427,    30,   505,    32,   552,    34,     0,    35,
      36,    37,    38,   553,    40,   554,   555,    43,    44,    45,
      46,   507,     0,    48,   556,    50,   509,   510,    53,   511,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,   512,   513,    71,     0,    72,    73,
      74,   557,     0,     0,    77,    78,    79,     0,     0,   515,
      81,     0,     0,     0,     0,    83,   516,    85,   517,   518,
      88,    89,   571,     0,     0,     0,     0,     0,     0,     0,
       0,    94,    95,    96,    97,     0,    98,     0,     0,     0,
     519,   100,   101,   520,   521,     0,     0,     0,     0,     0,
       0,   104,   105,   106,     0,   108,   109,   110,     0,     0,
       0,   967,     0,     0,   116,   522,     0,     0,     0,   118,
     119,   120,   121,   523,   123,   124,   524,     0,     0,     0,
       0,     0,     0,     0,   525,   526,   131,     0,     0,     0,
     132,     0,   133,   134,   527,     0,     0,     0,     0,     0,
       0,   140,     0,   141,   142,   143,   144,   528,   146,   147,
     148,   149,   150,   151,     0,     0,   152,   153,     0,     0,
     155,   428,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   529,   558,   530,   171,   531,   532,   174,
     175,   176,   177,   178,   179,   533,   181,   534,   535,   536,
     185,   186,   537,   538,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   539,     0,   202,   540,
     204,     0,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,     0,
       0,     3,     0,   254,   541,   256,   257,   258,   259,   260,
       9,    10,     0,     0,     0,     0,     0,     0,   425,   426,
       0,    16,    17,    18,   499,    20,    21,    22,   500,    24,
     501,   502,  1190,   504,   427,    30,   505,    32,    33,    34,
       0,    35,    36,    37,    38,   506,    40,    41,    42,    43,
      44,    45,    46,   507,     0,    48,   508,    50,   509,   510,
      53,   511,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,   512,   513,    71,     0,
      72,    73,    74,   514,     0,     0,    77,    78,    79,     0,
       0,   515,    81,     0,     0,     0,     0,    83,   516,    85,
     517,   518,    88,    89,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    94,    95,    96,    97,     0,    98,     0,
       0,     0,   519,   100,   101,   520,   521,     0,     0,     0,
       0,     0,     0,   104,   105,   106,     0,   108,   109,  1191,
       0,     0,     0,  1192,     0,     0,   116,   522,     0,     0,
       0,   118,   119,   120,   121,   523,   123,   124,   524,     0,
       0,     0,     0,     0,     0,     0,   525,   526,   131,     0,
       0,     0,   132,  1635,   133,   134,   527,     0,     0,     0,
       0,  1636,     0,   140,     0,   141,   142,   143,   144,   528,
     146,   147,   148,   149,   150,   151,     0,     0,  1193,   153,
       0,     0,   155,   428,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   529,   169,   530,   171,   531,
     532,   174,   175,   176,   177,   178,   179,   533,   181,   534,
     535,   536,   185,   186,   537,   538,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   539,     0,
     202,   540,   204,     0,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,     0,     0,     0,     0,   254,   541,   256,  1194,  1195,
    1196,  1197,     3,     0,   585,   586,     0,     0,     0,     0,
       0,     9,    10,     0,     0,     0,     0,     0,     0,   425,
     426,     0,    16,    17,    18,   549,    20,    21,    22,   500,
     550,   551,   502,   503,   504,   427,    30,   505,    32,   552,
      34,     0,    35,    36,    37,    38,   553,    40,   554,   555,
      43,    44,    45,    46,   507,     0,    48,   556,    50,   509,
     510,    53,   511,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,   512,   513,    71,
       0,    72,    73,    74,   557,     0,     0,    77,    78,    79,
       0,     0,   515,    81,     0,     0,     0,     0,    83,   516,
      85,   517,   518,    88,    89,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    94,    95,    96,    97,     0,    98,
       0,     0,     0,   519,   100,   101,   520,   521,     0,     0,
       0,     0,     0,     0,   104,   105,   106,     0,   108,   109,
     110,     0,     0,     0,     0,     0,     0,   116,   522,     0,
       0,     0,   118,   119,   120,   121,   523,   123,   124,   524,
       0,     0,     0,     0,     0,     0,     0,   525,   526,   131,
       0,     0,     0,   132,     0,   133,   134,   527,     0,     0,
       0,     0,     0,     0,   140,     0,   141,   142,   143,   144,
     528,   146,   147,   148,   149,   150,   151,     0,     0,   152,
     153,     0,     0,   155,   428,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   529,   558,   530,   171,
     531,   532,   174,   175,   176,   177,   178,   179,   533,   181,
     534,   535,   536,   185,   186,   537,   538,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   539,
       0,   202,   540,   204,     0,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,     0,     0,     3,     0,   254,   541,   256,   257,
     258,   259,   260,     9,    10,     0,     0,     0,     0,     0,
       0,   425,   426,     0,    16,    17,    18,   549,    20,    21,
      22,   500,   550,   551,   502,   503,   504,   427,    30,   505,
      32,   552,    34,     0,    35,    36,    37,    38,   553,    40,
     554,   555,    43,    44,    45,    46,   507,     0,    48,   556,
      50,   509,   510,    53,   511,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,   512,
     513,    71,     0,    72,    73,    74,   557,     0,     0,    77,
      78,    79,     0,     0,   515,    81,     0,     0,     0,     0,
      83,   516,    85,   517,   518,    88,    89,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    94,    95,    96,    97,
       0,    98,     0,     0,     0,   519,   100,   101,   520,   521,
       0,     0,     0,     0,     0,     0,   104,   105,   106,     0,
     108,   109,   110,     0,     0,     0,     0,     0,     0,   116,
     522,     0,     0,     0,   118,   119,   120,   121,   523,   123,
     124,   524,     0,     0,     0,     0,     0,     0,     0,   525,
     526,   131,     0,     0,     0,   132,   791,   133,   134,   527,
       0,     0,     0,     0,   792,     0,   140,     0,   141,   142,
     143,   144,   528,   146,   147,   148,   149,   150,   151,     0,
       0,   152,   153,     0,     0,   155,   428,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   529,   558,
     530,   171,   531,   532,   174,   175,   176,   177,   178,   179,
     533,   181,   534,   535,   536,   185,   186,   537,   538,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   539,     0,   202,   540,   204,     0,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,     0,     0,     3,     0,   254,   541,
     256,   257,   258,   259,   260,     9,    10,     0,     0,     0,
     817,     0,     0,   425,   426,     0,    16,    17,    18,   549,
      20,    21,    22,   500,   550,   551,   502,   503,   504,   427,
      30,   505,    32,   552,    34,     0,    35,    36,    37,    38,
     553,    40,   554,   555,    43,    44,    45,    46,   507,     0,
      48,   556,    50,   509,   510,    53,   511,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,   512,   513,    71,     0,    72,    73,    74,   557,     0,
       0,    77,    78,    79,     0,     0,   515,    81,     0,     0,
       0,     0,    83,   516,    85,   517,   518,    88,    89,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    94,    95,
      96,    97,     0,    98,     0,     0,     0,   519,   100,   101,
     520,   521,     0,     0,     0,     0,     0,     0,   104,   105,
     106,     0,   108,   109,   110,     0,     0,     0,     0,     0,
       0,   116,   522,     0,     0,     0,   118,   119,   120,   121,
     523,   123,   124,   524,     0,     0,     0,     0,     0,     0,
       0,   525,   526,   131,     0,     0,     0,   132,   818,   133,
     134,   527,     0,     0,     0,     0,     0,     0,   140,     0,
     141,   142,   143,   144,   528,   146,   147,   148,   149,   150,
     151,     0,     0,   152,   153,     0,     0,   155,   428,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     529,   558,   530,   171,   531,   532,   174,   175,   176,   177,
     178,   179,   533,   181,   534,   535,   536,   185,   186,   537,
     538,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   539,     0,   202,   540,   204,     0,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,     0,     0,     3,     0,
     254,   541,   256,   257,   258,   259,   260,     9,    10,     0,
       0,     0,     0,     0,     0,   425,   426,     0,    16,    17,
      18,   549,    20,    21,    22,   500,   550,   551,   502,   503,
     504,   427,    30,   505,    32,   552,    34,     0,    35,    36,
      37,    38,   553,    40,   554,   555,    43,    44,    45,    46,
     507,     0,    48,   556,    50,   509,   510,    53,   511,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,   512,   513,    71,     0,    72,    73,    74,
     557,     0,     0,    77,    78,    79,     0,     0,   515,    81,
       0,     0,     0,     0,    83,   516,    85,   517,   518,    88,
      89,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      94,    95,    96,    97,     0,    98,     0,     0,     0,   519,
     100,   101,   520,   521,     0,     0,     0,     0,     0,     0,
     104,   105,   106,     0,   108,   109,   110,     0,     0,     0,
       0,     0,     0,   116,   522,     0,     0,     0,   118,   119,
     120,   121,   523,   123,   124,   524,     0,     0,     0,     0,
       0,     0,     0,   525,   526,   131,     0,     0,     0,   132,
     835,   133,   134,   527,     0,     0,     0,     0,   836,     0,
     140,     0,   141,   142,   143,   144,   528,   146,   147,   148,
     149,   150,   151,     0,     0,   152,   153,     0,     0,   155,
     428,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   529,   558,   530,   171,   531,   532,   174,   175,
     176,   177,   178,   179,   533,   181,   534,   535,   536,   185,
     186,   537,   538,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   539,     0,   202,   540,   204,
       0,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,     0,     0,
       3,     0,   254,   541,   256,   257,   258,   259,   260,     9,
      10,     0,     0,     0,     0,     0,     0,   425,   426,     0,
      16,    17,    18,   499,    20,    21,    22,   500,    24,   501,
     502,  1190,   504,   427,    30,   505,    32,    33,    34,     0,
      35,    36,    37,    38,   506,    40,    41,    42,    43,    44,
      45,    46,   507,     0,    48,   508,    50,   509,   510,    53,
     511,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,   512,   513,    71,     0,    72,
      73,    74,   514,     0,     0,    77,    78,    79,     0,     0,
     515,    81,     0,     0,     0,     0,    83,   516,    85,   517,
     518,    88,    89,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    94,    95,    96,    97,     0,    98,     0,     0,
       0,   519,   100,   101,   520,   521,     0,     0,     0,     0,
       0,     0,   104,   105,   106,     0,   108,   109,  1191,     0,
       0,     0,  1230,     0,     0,   116,   522,     0,     0,     0,
     118,   119,   120,   121,   523,   123,   124,   524,     0,     0,
       0,     0,     0,     0,     0,   525,   526,   131,     0,     0,
       0,   132,  1467,   133,   134,   527,     0,     0,     0,     0,
       0,     0,   140,     0,   141,   142,   143,   144,   528,   146,
     147,   148,   149,   150,   151,     0,     0,   152,   153,     0,
       0,   155,   428,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   529,   169,   530,   171,   531,   532,
     174,   175,   176,   177,   178,   179,   533,   181,   534,   535,
     536,   185,   186,   537,   538,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   539,     0,   202,
     540,   204,     0,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
       0,     0,     3,     0,   254,   541,   256,  1194,  1195,  1196,
    1197,     9,    10,     0,     0,     0,     0,     0,     0,   425,
     426,     0,    16,    17,    18,   499,    20,    21,    22,   500,
      24,   501,   502,  1190,   504,   427,    30,   505,    32,    33,
      34,     0,    35,    36,    37,    38,   506,    40,    41,    42,
      43,    44,    45,    46,   507,     0,    48,   508,    50,   509,
     510,    53,   511,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,   512,   513,    71,
       0,    72,    73,    74,   514,     0,     0,    77,    78,    79,
       0,     0,   515,    81,     0,     0,     0,     0,    83,   516,
      85,   517,   518,    88,    89,  1541,     0,     0,     0,     0,
       0,     0,     0,     0,    94,    95,    96,    97,     0,    98,
       0,     0,     0,   519,   100,   101,   520,   521,     0,     0,
       0,     0,     0,     0,   104,   105,   106,     0,   108,   109,
    1191,     0,     0,     0,  1192,     0,     0,   116,   522,     0,
       0,     0,   118,   119,   120,   121,   523,   123,   124,   524,
       0,     0,     0,     0,     0,     0,     0,   525,   526,   131,
       0,     0,     0,   132,     0,   133,   134,   527,     0,     0,
       0,     0,     0,     0,   140,     0,   141,   142,   143,   144,
     528,   146,   147,   148,   149,   150,   151,     0,     0,  1193,
     153,     0,     0,   155,   428,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   529,   169,   530,   171,
     531,   532,   174,   175,   176,   177,   178,   179,   533,   181,
     534,   535,   536,   185,   186,   537,   538,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   539,
       0,   202,   540,   204,     0,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,     0,     0,     3,     0,   254,   541,   256,  1194,
    1195,  1196,  1197,     9,    10,     0,     0,     0,     0,     0,
       0,   425,   426,     0,    16,    17,    18,   499,    20,    21,
      22,   500,    24,   501,   502,  1190,   504,   427,    30,   505,
      32,    33,    34,     0,    35,    36,    37,    38,   506,    40,
      41,    42,    43,    44,    45,    46,   507,     0,    48,   508,
      50,   509,   510,    53,   511,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,   512,
     513,    71,     0,    72,    73,    74,   514,     0,     0,    77,
      78,    79,     0,     0,   515,    81,     0,     0,     0,     0,
      83,   516,    85,   517,   518,    88,    89,  1688,     0,     0,
       0,     0,     0,     0,     0,     0,    94,    95,    96,    97,
       0,    98,     0,     0,     0,   519,   100,   101,   520,   521,
       0,     0,     0,     0,     0,     0,   104,   105,   106,     0,
     108,   109,  1191,     0,     0,     0,  1192,     0,     0,   116,
     522,     0,     0,     0,   118,   119,   120,   121,   523,   123,
     124,   524,     0,     0,     0,     0,     0,     0,     0,   525,
     526,   131,     0,     0,     0,   132,     0,   133,   134,   527,
       0,     0,     0,     0,     0,     0,   140,     0,   141,   142,
     143,   144,   528,   146,   147,   148,   149,   150,   151,     0,
       0,  1193,   153,     0,     0,   155,   428,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   529,   169,
     530,   171,   531,   532,   174,   175,   176,   177,   178,   179,
     533,   181,   534,   535,   536,   185,   186,   537,   538,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   539,     0,   202,   540,   204,     0,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,     0,     0,     3,     0,   254,   541,
     256,  1194,  1195,  1196,  1197,     9,    10,     0,     0,     0,
       0,     0,     0,   425,   426,     0,    16,    17,    18,   499,
      20,    21,    22,   500,    24,   501,   502,  1190,   504,   427,
      30,   505,    32,    33,    34,     0,    35,    36,    37,    38,
     506,    40,    41,    42,    43,    44,    45,    46,   507,     0,
      48,   508,    50,   509,   510,    53,   511,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,   512,   513,    71,     0,    72,    73,    74,   514,     0,
       0,    77,    78,    79,     0,     0,   515,    81,     0,     0,
       0,     0,    83,   516,    85,   517,   518,    88,    89,  1692,
       0,     0,     0,     0,     0,     0,     0,     0,    94,    95,
      96,    97,     0,    98,     0,     0,     0,   519,   100,   101,
     520,   521,     0,     0,     0,     0,     0,     0,   104,   105,
     106,     0,   108,   109,  1191,     0,     0,     0,  1192,     0,
       0,   116,   522,     0,     0,     0,   118,   119,   120,   121,
     523,   123,   124,   524,     0,     0,     0,     0,     0,     0,
       0,   525,   526,   131,     0,     0,     0,   132,     0,   133,
     134,   527,     0,     0,     0,     0,     0,     0,   140,     0,
     141,   142,   143,   144,   528,   146,   147,   148,   149,   150,
     151,     0,     0,  1193,   153,     0,     0,   155,   428,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     529,   169,   530,   171,   531,   532,   174,   175,   176,   177,
     178,   179,   533,   181,   534,   535,   536,   185,   186,   537,
     538,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   539,     0,   202,   540,   204,     0,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,     0,     0,     3,     0,
     254,   541,   256,  1194,  1195,  1196,  1197,     9,    10,     0,
       0,     0,     0,     0,     0,   425,   426,     0,    16,    17,
      18,   499,    20,    21,    22,   500,    24,   501,   502,  1190,
     504,   427,    30,   505,    32,    33,    34,     0,    35,    36,
      37,    38,   506,    40,    41,    42,    43,    44,    45,    46,
     507,     0,    48,   508,    50,   509,   510,    53,   511,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,   512,   513,    71,     0,    72,    73,    74,
     514,     0,     0,    77,    78,    79,     0,     0,   515,    81,
       0,     0,     0,     0,    83,   516,    85,   517,   518,    88,
      89,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      94,    95,    96,    97,     0,    98,     0,     0,     0,   519,
     100,   101,   520,   521,     0,     0,     0,     0,     0,     0,
     104,   105,   106,     0,   108,   109,  1191,     0,     0,     0,
    1192,     0,     0,   116,   522,     0,     0,     0,   118,   119,
     120,   121,   523,   123,   124,   524,     0,     0,     0,     0,
       0,     0,     0,   525,   526,   131,     0,     0,     0,   132,
       0,   133,   134,   527,     0,     0,     0,     0,     0,     0,
     140,     0,   141,   142,   143,   144,   528,   146,   147,   148,
     149,   150,   151,     0,     0,  1193,   153,     0,     0,   155,
     428,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   529,   169,   530,   171,   531,   532,   174,   175,
     176,   177,   178,   179,   533,   181,   534,   535,   536,   185,
     186,   537,   538,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   539,     0,   202,   540,   204,
       0,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,     0,     0,
       3,     0,   254,   541,   256,  1194,  1195,  1196,  1197,     9,
      10,     0,     0,     0,     0,     0,     0,   425,   426,     0,
      16,    17,    18,   499,    20,    21,    22,   500,    24,   501,
     502,  1190,   504,   427,    30,   505,    32,    33,    34,     0,
      35,    36,    37,    38,   506,    40,    41,    42,    43,    44,
      45,    46,   507,     0,    48,   508,    50,   509,   510,    53,
     511,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,   512,   513,    71,     0,    72,
      73,    74,   514,     0,     0,    77,    78,    79,     0,     0,
     515,    81,     0,     0,     0,     0,    83,   516,    85,   517,
     518,    88,    89,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    94,    95,    96,    97,     0,    98,     0,     0,
       0,   519,   100,   101,   520,   521,     0,     0,     0,     0,
       0,     0,   104,   105,   106,     0,   108,   109,  1191,     0,
       0,     0,  1230,     0,     0,   116,   522,     0,     0,     0,
     118,   119,   120,   121,   523,   123,   124,   524,     0,     0,
       0,     0,     0,     0,     0,   525,   526,   131,     0,     0,
       0,   132,     0,   133,   134,   527,     0,     0,     0,     0,
       0,     0,   140,     0,   141,   142,   143,   144,   528,   146,
     147,   148,   149,   150,   151,     0,     0,   152,   153,     0,
       0,   155,   428,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   529,   169,   530,   171,   531,   532,
     174,   175,   176,   177,   178,   179,   533,   181,   534,   535,
     536,   185,   186,   537,   538,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   539,     0,   202,
     540,   204,     0,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
       0,     0,     3,     0,   254,   541,   256,  1194,  1195,  1196,
    1197,     9,    10,     0,     0,     0,     0,     0,     0,   425,
     426,     0,    16,    17,    18,   549,    20,    21,    22,   500,
     550,   551,   502,   503,   504,   427,    30,   505,    32,   552,
      34,     0,    35,    36,    37,    38,   553,    40,   554,   555,
      43,    44,    45,    46,   507,     0,    48,   556,    50,   509,
     510,    53,   511,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,   512,   513,    71,
       0,    72,    73,    74,   557,     0,     0,    77,    78,    79,
       0,     0,   515,    81,     0,     0,     0,     0,    83,   516,
      85,   517,   518,    88,    89,  1285,     0,     0,     0,     0,
       0,     0,     0,     0,    94,    95,    96,    97,     0,    98,
       0,     0,     0,   519,   100,   101,   520,   521,     0,     0,
       0,     0,     0,     0,   104,   105,   106,     0,   108,   109,
     110,     0,     0,     0,     0,     0,     0,   116,   522,     0,
       0,     0,   118,   119,   120,   121,   523,   123,   124,   524,
       0,     0,     0,     0,     0,     0,     0,   525,   526,   131,
       0,     0,     0,   132,     0,   133,   134,   527,     0,     0,
       0,     0,     0,     0,   140,     0,   141,   142,   143,   144,
     528,   146,   147,   148,   149,   150,   151,     0,     0,   152,
     153,     0,     0,   155,   428,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   529,   558,   530,   171,
     531,   532,   174,   175,   176,   177,   178,   179,   533,   181,
     534,   535,   536,   185,   186,   537,   538,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   539,
       0,   202,   540,   204,     0,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,     0,     0,     3,     0,   254,   541,   256,   257,
     258,   259,   260,     9,    10,     0,     0,     0,     0,     0,
       0,   425,   426,     0,    16,    17,    18,   549,    20,    21,
      22,   500,   550,   551,   502,   503,   504,   427,    30,   505,
      32,   552,    34,     0,    35,    36,    37,    38,   553,    40,
     554,   555,    43,    44,    45,    46,   507,     0,    48,   556,
      50,   509,   510,    53,   511,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,   512,
     513,    71,     0,    72,    73,    74,   557,     0,     0,    77,
      78,    79,     0,     0,   515,    81,     0,     0,     0,     0,
      83,   516,    85,   517,   518,    88,    89,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    94,    95,    96,    97,
       0,    98,     0,     0,     0,   519,   100,   101,   520,   521,
       0,     0,     0,     0,     0,     0,   104,   105,   106,     0,
     108,   109,   110,     0,     0,     0,     0,     0,     0,   116,
     522,     0,     0,     0,   118,   119,   120,   121,   523,   123,
     124,   524,     0,     0,     0,     0,     0,     0,     0,   525,
     526,   131,     0,     0,     0,   132,     0,   133,   134,   527,
       0,     0,     0,     0,     0,     0,   140,     0,   141,   142,
     143,   144,   528,   146,   147,   148,   149,   150,   151,     0,
       0,   152,   153,     0,     0,   155,   428,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   529,   558,
     530,   171,   531,   532,   174,   175,   176,   177,   178,   179,
     533,   181,   534,   535,   536,   185,   186,   537,   538,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   539,     0,   202,   540,   204,     0,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,     0,     0,     0,     0,   254,   541,
     256,   257,   258,   259,   260,     5,     6,     7,     8,     9,
      10,     0,     0,     0,    13,     0,     0,   425,   426,     0,
      16,    17,    18,   596,    20,    21,    22,    23,     0,   597,
     502,    27,     0,   427,    30,   505,    32,     0,    34,     0,
      35,    36,    37,    38,   598,    40,     0,     0,    43,    44,
      45,    46,   507,     0,    48,   599,    50,     0,     0,    53,
     511,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,   512,   513,    71,     0,    72,
      73,    74,   600,     0,     0,    77,    78,    79,     0,     0,
     515,    81,     0,     0,     0,    82,    83,   516,    85,   517,
     518,    88,    89,   571,    91,     0,     0,     0,     0,     0,
      93,     0,    94,    95,    96,    97,     0,    98,     0,     0,
       0,   519,   100,   101,   520,   521,     0,     0,     0,     0,
       0,     0,   104,   105,   106,   107,   108,   109,     0,   572,
     112,     0,   113,   114,     0,   116,   117,     0,     0,     0,
     118,   119,   120,   121,   122,   123,   124,   524,     0,   126,
       0,     0,     0,     0,     0,   525,   526,   131,     0,     0,
       0,   132,     0,   133,   134,   527,     0,     0,     0,     0,
       0,     0,   140,     0,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,     0,     0,     0,   153,   154,
       0,   155,   428,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   529,  1136,   530,   171,   531,   532,
     174,   175,   176,   177,   178,   179,   533,   181,   534,   535,
     536,   185,   186,     0,   538,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   539,     0,   202,
     540,   204,     0,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,     0,   253,     0,     0,   541,   256,     5,     6,     7,
       8,     9,    10,     0,     0,     0,    13,     0,     0,   425,
     426,     0,    16,    17,    18,   596,    20,    21,    22,    23,
       0,   597,   502,    27,     0,   427,    30,   505,    32,     0,
      34,     0,    35,    36,    37,    38,   598,    40,     0,     0,
      43,    44,    45,    46,   507,     0,    48,   599,    50,     0,
       0,    53,   511,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,   512,   513,    71,
       0,    72,    73,    74,   600,     0,     0,    77,    78,    79,
       0,     0,   515,    81,     0,     0,     0,    82,    83,   516,
      85,   517,   518,    88,    89,   571,    91,     0,     0,     0,
       0,     0,    93,     0,    94,    95,    96,    97,     0,    98,
       0,     0,     0,   519,   100,   101,   520,   521,     0,     0,
       0,     0,     0,     0,   104,   105,   106,   107,   108,   109,
       0,   572,   112,     0,   113,   114,     0,   116,   117,     0,
       0,     0,   118,   119,   120,   121,   122,   123,   124,   524,
       0,   126,     0,     0,     0,     0,     0,   525,   526,   131,
       0,     0,     0,   132,     0,   133,   134,   527,     0,     0,
       0,     0,     0,     0,   140,     0,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,     0,     0,     0,
     153,   154,     0,   155,   428,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   529,     0,   530,   171,
     531,   532,   174,   175,   176,   177,   178,   179,   533,   181,
     534,   535,   536,   185,   186,     0,   538,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   539,
       0,   202,   540,   204,     0,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,     0,   253,     0,     0,   541,   256,     5,
       6,     7,     8,     9,    10,     0,     0,     0,    13,     0,
       0,   425,   426,     0,    16,    17,    18,   596,    20,    21,
       0,    23,     0,   597,     0,    27,     0,   427,     0,     0,
      32,     0,    34,     0,     0,    36,    37,    38,   598,    40,
       0,     0,    43,    44,    45,    46,   507,     0,     0,   599,
      50,     0,     0,    53,   511,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,   512,
     513,     0,     0,     0,     0,    74,   600,     0,     0,     0,
       0,     0,     0,     0,   515,     0,     0,     0,     0,    82,
      83,   516,    85,   517,   518,    88,     0,   571,    91,     0,
       0,     0,     0,     0,    93,     0,    94,    95,    96,    97,
       0,    98,     0,     0,     0,   519,     0,   101,   520,   521,
       0,     0,     0,     0,     0,     0,     0,   105,   106,   107,
       0,   109,     0,   572,     0,     0,     0,   114,     0,     0,
     117,     0,     0,     0,   118,   119,   120,   121,   122,   123,
     124,   524,     0,   126,     0,     0,     0,     0,     0,   525,
     526,   131,     0,     0,     0,   132,     0,   133,   134,   527,
       0,     0,     0,     0,     0,     0,   140,     0,   141,     0,
     143,     0,   145,   146,   147,   148,   149,   150,   151,     0,
       0,     0,   153,   154,     0,   155,   428,   157,   158,   159,
     160,   161,     0,   163,   164,   165,   166,   167,   529,   601,
     530,   602,   531,   532,   174,   175,   176,   177,   178,   179,
     533,   181,   534,   535,   536,   185,   186,     0,   538,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,     0,     0,   202,   540,   204,     0,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,     0,   253,     0,   603,   541,
     256,     5,     6,     7,     8,     9,    10,     0,     0,     0,
      13,     0,     0,   425,   426,     0,    16,    17,    18,   596,
      20,    21,     0,    23,     0,   597,     0,    27,     0,   427,
       0,     0,    32,     0,    34,     0,     0,    36,    37,    38,
     598,    40,     0,     0,    43,    44,    45,    46,   507,     0,
       0,   599,    50,     0,     0,    53,   511,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,   512,   513,     0,     0,     0,     0,    74,   600,     0,
       0,     0,     0,     0,     0,     0,   515,     0,     0,     0,
       0,    82,    83,   516,     0,   517,   518,     0,     0,   571,
      91,     0,     0,     0,     0,     0,    93,     0,     0,     0,
      96,    97,     0,    98,     0,     0,     0,   519,     0,   101,
     520,   521,     0,     0,     0,     0,     0,     0,     0,   105,
     106,   107,     0,     0,     0,   572,     0,     0,     0,   114,
       0,     0,   117,     0,     0,     0,   118,   119,     0,     0,
     122,   123,     0,   524,     0,   126,     0,     0,     0,     0,
       0,   525,   526,   131,     0,     0,     0,     0,     0,     0,
       0,   527,     0,     0,     0,     0,     0,     0,   140,     0,
     141,     0,     0,     0,   145,   146,   147,   148,   149,   150,
     151,     0,     0,     0,     0,   154,     0,   155,   428,   157,
       0,   159,   160,   161,     0,     0,   164,   165,   166,   167,
     529,   611,   530,   171,   531,   532,   174,   175,   176,     0,
     178,   179,   533,   181,   534,   535,   536,   185,   186,     0,
     538,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,     0,     0,   202,   540,   204,     0,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,     0,   253,     0,
     612,   541,   256,     9,    10,     0,     0,     0,     0,     0,
       0,   425,   426,     0,    16,    17,    18,     0,    20,    21,
      22,   500,     0,     0,   502,   503,     0,   427,    30,   505,
      32,     0,    34,     0,    35,    36,    37,    38,     0,    40,
       0,     0,    43,    44,    45,    46,   507,     0,    48,     0,
      50,     0,     0,    53,   511,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,   512,
     513,    71,     0,    72,    73,    74,     0,     0,     0,    77,
      78,    79,     0,     0,   515,    81,     0,     0,     0,     0,
      83,   516,    85,   517,   518,    88,    89,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    94,    95,    96,    97,
       0,    98,     0,     0,     0,   519,   100,   101,   520,   521,
       0,     0,     0,     0,     0,     0,   104,   105,   106,     0,
     108,   109,     0,     0,     0,     0,     0,     0,     0,   116,
     522,     0,     0,     0,   118,   119,   120,   121,   523,   123,
     124,   524,     0,     0,     0,     0,     0,     0,     0,   525,
     526,   131,     0,     0,     0,   132,     0,   133,   134,   527,
       0,     0,     0,     0,     0,     0,   140,     0,   141,   142,
     143,   144,   528,   146,   147,   148,   149,   150,   151,     0,
       0,     0,   153,     0,     0,   155,   428,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   529,     0,
     530,   171,   531,   532,   174,   175,   176,   177,   178,   179,
     533,   181,   534,   535,   536,   185,   186,     0,   538,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   539,     0,   202,   540,   204,     0,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,     0,     0,     0,     0,     0,   541,
     256
  };

  /* YYCHECK.  */
  const short int
  jsoniq_parser::yycheck_[] =
  {
         0,     5,     6,     7,     8,     5,     6,     7,     8,   188,
     321,    14,   703,   352,   436,   437,     0,     5,     6,     7,
     811,     5,     6,     7,     8,   719,   856,   796,   168,   112,
     113,   944,   172,   824,   704,   705,   706,   707,   645,   646,
     300,  1088,   438,   268,   796,   731,   203,   838,  1072,  1114,
    1326,   957,   958,   269,   138,  1344,   891,   170,   643,   644,
     645,   646,   261,   262,  1176,     1,     1,    76,   284,  1410,
    1411,    27,    28,   643,   644,    36,  1035,   473,   474,   119,
      39,    36,  1053,   985,    56,    44,    45,  1457,   144,   753,
     321,    47,  1657,   119,    53,  1357,     1,     5,     6,     7,
       8,    60,     1,    62,    63,   123,  1001,   111,   149,    30,
    1544,   111,    71,  1547,     1,   682,     1,   684,   685,    75,
     687,   108,   689,    30,     1,     0,     1,   111,   149,     1,
     697,   698,   291,   108,    95,     1,    97,   108,     1,    98,
       1,    52,    97,     1,   108,   108,    94,     1,   138,  1055,
     133,    97,     1,   231,    27,    28,  1062,   113,   236,   220,
       1,    95,     1,   121,    37,    38,   155,    40,    41,   252,
     253,   431,   108,   108,    47,   435,     0,     1,    31,    97,
     160,   158,   647,     1,    57,    58,   651,     1,   149,   178,
     111,   231,   139,    97,   149,     1,     1,   177,   156,   260,
     158,   188,    75,   111,   111,   126,   158,    80,   155,   192,
     114,     8,   158,   203,   189,   149,  1007,   300,   189,   126,
     131,   239,   108,   279,   188,     1,    27,    28,    97,   192,
     151,   957,   958,   108,   155,     1,   184,   158,   279,   112,
     113,   114,   320,  1808,   151,   108,    47,   108,   220,  1590,
     108,     1,   170,   279,   108,     1,    57,   178,   279,   108,
       1,   261,   262,  1176,  1177,   265,   577,   108,     1,   108,
    1061,   355,   231,   313,    75,  1001,  1323,   261,   262,    80,
    1110,   265,  1558,  1348,   108,  1309,  1656,   192,   260,   162,
     108,  1060,  1357,   192,   108,   902,   903,  1192,   457,  1561,
     300,   170,   108,   108,   564,   192,  1058,   192,  1060,  1035,
     185,   112,   113,   114,  1285,   192,   300,  1276,   279,    76,
     192,  1433,  1074,   987,   279,  1227,   192,   188,   186,  1055,
     900,   901,   108,    90,   188,  1230,  1062,   293,  1772,   188,
     258,   259,   108,   261,   265,   301,   577,   188,   431,   188,
     268,   360,   435,   226,   363,   241,   155,   114,   108,    95,
     278,   185,   108,   216,   323,   324,   325,   108,   764,   126,
     188,   128,   290,   940,   188,   108,     1,  1168,     1,   176,
     185,   317,   188,   466,   319,  1819,    97,  1821,   471,   258,
     259,    77,   261,    30,   267,  1301,    37,    38,   481,    40,
      41,    97,    95,     1,    30,   488,   489,     1,   668,   278,
       1,   168,   188,   809,   497,   172,  1757,    58,   643,   644,
     293,   290,   188,   162,   640,   641,     1,     1,   301,   123,
       1,   431,   108,   632,   650,   435,   309,     3,   188,    45,
     155,  1719,   188,   108,    95,   186,   108,   431,   108,   132,
     108,   435,   185,   183,   274,   108,   158,    63,   462,   183,
     464,   281,   462,   603,   464,    45,  1192,    47,   198,   155,
    1811,   155,   612,   114,   198,     5,   121,   114,   462,     9,
     464,   564,   486,   108,  1275,   108,   486,   491,   224,   225,
     108,   491,   293,   144,   178,   608,  1561,   212,   581,   582,
     301,    67,   486,   239,  1230,  1794,    72,   491,   309,   592,
     108,   156,   188,   158,   108,   101,   199,   108,  1287,  1797,
    1433,   162,   944,   188,   681,   162,   188,   107,    55,  1442,
      57,   224,   225,   108,   108,   188,   162,   108,   621,   622,
    1453,   227,   228,  1229,  1296,   239,   239,  1154,  1155,  1156,
    1276,   262,   263,   119,   462,    30,   464,  1392,   980,  1465,
     185,  1396,   185,  1839,   564,   121,   262,   185,   572,  1154,
    1155,  1156,   572,   160,   101,  1301,   108,  1271,   486,   239,
     564,   239,   188,   491,   119,   226,   108,   185,   572,   169,
     177,   185,     5,   108,   185,   125,     9,   127,   243,  1325,
     156,   187,   158,   360,   190,   135,   363,   170,   119,    95,
     185,   185,  1008,  1009,   185,    27,    28,  1013,   622,   108,
     108,   167,   622,  1414,   132,   155,   267,    97,   624,   889,
     158,   155,   632,     1,   158,   638,   111,   183,   622,   723,
     724,   204,   725,   643,   644,   645,   646,  1043,   632,   732,
    1674,   126,   187,   119,     9,   190,   188,    97,   918,   643,
     644,   645,   646,   149,   572,    33,   188,   187,   668,   238,
     190,   240,   118,   188,    29,   900,   151,   188,     9,   149,
     155,   155,   678,   158,   668,   442,   443,   243,   275,   446,
     906,   199,   212,   450,   910,   282,   453,   454,    29,   188,
     188,   113,   148,   178,   461,   292,   158,     9,    10,   149,
     467,   468,   125,  1626,   127,   161,   720,    45,   475,    47,
     720,   187,   135,    95,   190,   482,   483,   484,   485,  1559,
     257,   158,   720,   490,  1564,   101,   720,   107,   212,  1465,
     880,   498,   155,   270,    95,   272,  1793,  1516,   114,   121,
     196,     1,    80,  1444,  1176,  1177,   283,   284,   285,   129,
     287,    95,   289,   158,   847,   848,   849,    42,   851,   203,
     125,    46,   127,    33,   150,   150,    51,   158,   212,   107,
    1686,   136,    95,    33,   156,     1,   158,     3,   545,    49,
     166,   166,  1399,   144,   125,    70,   127,   801,    97,    49,
     155,   801,   104,   560,   119,   136,   889,  1501,   121,    97,
     144,    54,   720,   801,   571,   114,    59,   801,  1544,   146,
       1,  1547,     3,   125,   155,   127,   114,   124,   832,   833,
     160,    95,   832,   833,  1740,    78,  1742,   187,   138,  1178,
     190,   169,  1049,   156,  1051,   158,   603,   177,   832,   833,
     177,    67,   152,   155,    97,   612,    72,   159,   155,   158,
     617,   158,  1784,  1785,   238,    25,   240,   624,  1698,   196,
     158,   201,  1702,   175,    34,   139,   119,    54,     9,    10,
     144,   160,    59,  1143,   967,   275,    67,   158,  1095,   889,
    1097,    72,   282,   801,   169,   197,    96,   172,   177,  1805,
     139,    61,   292,   119,  1826,   889,   101,   107,  1304,   912,
    1832,   155,   187,   215,   158,   190,   155,   117,   918,   114,
      97,   678,   201,   101,   832,   833,  1617,  1618,  1144,   129,
     253,   254,   101,   101,   918,  1151,   114,   101,   119,   214,
    1610,   147,    95,   998,    54,   114,   114,   305,   269,    59,
     114,   269,   158,   276,   107,  1010,   314,   158,  1788,   280,
    1686,   726,   280,   124,   729,  1659,  1757,   139,  1147,   734,
     701,   702,   144,   104,   731,   283,   284,   285,     9,    10,
     139,   289,   193,   194,   155,   144,   124,   158,   263,   155,
     359,   124,   158,   362,   125,   119,   127,   124,  1138,   124,
     757,   130,   131,   760,   227,   228,   229,   130,   131,    90,
    1406,  1433,   710,   711,  1740,   119,  1742,   774,   124,  1415,
    1442,   778,   779,   124,   155,   155,   708,   709,   159,   155,
     111,  1453,   124,   114,  1269,  1270,   124,  1728,  1729,   124,
     797,  1647,  1648,  1303,   175,   126,  1772,   128,   805,   124,
     155,   808,   219,   119,   247,   812,   158,   247,   158,   248,
     155,     0,     9,    10,   192,   168,   197,    93,  1762,   255,
     100,    50,   156,   104,   102,   195,   103,   185,   158,  1805,
    1391,   202,    30,    47,   215,   154,  1090,   185,   185,   170,
    1090,  1322,  1175,  1819,   125,  1821,   127,   119,   855,   185,
     252,   310,   155,     1,   119,   188,  1090,   144,   108,   188,
    1801,   188,   155,   155,   158,  1809,   123,   158,   158,   158,
     158,   144,   185,   880,   155,   123,   158,    35,   159,  1525,
      17,   155,   192,   158,   891,    30,   155,   158,   216,   155,
     236,   155,   155,  1143,   175,   155,   237,   192,     3,   239,
    1153,   119,  1383,   171,  1154,  1155,  1156,   104,   251,  1143,
    1391,   169,   171,   119,    71,   922,   197,   237,   290,    95,
    1154,  1155,  1156,   290,   151,   932,    95,    95,   125,   108,
     127,   108,  1090,   188,   215,    30,   162,  1881,   162,  1883,
     134,   129,    95,   252,   305,   144,   119,   134,   185,  1893,
     957,   958,   959,   960,  1626,   185,   188,   188,   155,  1388,
      95,   108,   159,   134,    97,    45,    97,   188,   188,   188,
     155,   142,   143,   188,   145,   185,   185,    95,   175,   144,
     192,   243,   153,   237,    33,   171,   157,   239,   159,   185,
     134,    95,   144,   164,  1001,    30,   292,   233,    95,   305,
     197,   155,   129,   119,   119,    95,   149,   185,  1015,   180,
     200,   134,   162,   134,    97,   155,   119,   149,   215,   101,
     101,   185,   185,   123,   144,  1279,   155,  1537,    35,  1279,
     192,   123,    30,  1040,   205,   206,   207,   208,   209,   210,
      97,  1279,  1049,   155,  1051,  1279,  1053,   119,  1055,   251,
      80,   107,  1533,  1303,  1535,  1062,   108,  1538,  1539,   260,
    1314,  1542,   108,   291,  1314,   273,   266,  1548,   146,  1303,
     158,   264,   158,  1583,   158,    30,  1314,    30,    30,  1333,
    1314,   158,   158,  1333,   158,   158,   293,   292,  1095,   312,
    1097,   233,   188,   192,   188,  1333,   146,   188,   149,  1333,
    1354,   188,   129,   108,  1354,   149,   144,  1361,   101,   188,
     185,  1361,   443,   134,     7,   446,    97,   188,   322,   450,
    1354,  1279,   453,   454,   243,   192,   239,  1361,   239,   239,
     461,  1138,   200,   239,   158,   158,   467,   468,   158,   155,
     107,  1395,   119,   149,   475,  1395,   119,    78,   188,   256,
     149,   482,   483,   484,   485,   256,  1314,  1164,   288,   490,
      79,  1395,  1672,   188,   292,    30,   188,   498,    30,   188,
     188,   188,   108,  1683,  1684,  1333,   188,  1687,   188,   277,
     171,   185,   128,   149,  1694,  1192,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,  1354,   263,   149,   128,
      97,   185,   185,  1361,   144,   185,   185,   185,  1689,    95,
     155,    30,  1693,   322,   545,    97,   286,   188,   188,   149,
      95,   171,    54,  1230,   293,   199,    95,    30,   271,   560,
     108,   108,   119,    94,   231,    95,    95,   199,   199,   119,
     571,   572,   200,   119,   231,   184,   311,  1580,  1581,  1582,
     199,   311,   119,   119,   299,   231,   311,   201,   312,   312,
     293,   119,   265,   265,   312,   763,   457,   268,  1231,  1002,
     437,  1781,  1063,  1276,  1762,  1809,  1173,   608,  1285,   892,
     814,  1603,  1289,  1425,  1417,  1413,   617,  1537,  1160,  1410,
     560,  1315,  1320,   624,  1301,  1328,  1323,  1778,   680,   700,
     960,   731,   737,  1537,  1348,   347,  1832,  1826,  1315,   465,
    1820,   856,  1393,  1382,   465,  1392,  1051,  1626,  1325,  1453,
    1177,  1623,  1442,  1186,  1034,  1253,  1491,  1650,  1838,  1446,
      -1,  1443,    -1,  1583,    -1,    -1,    -1,  1818,    -1,    -1,
      -1,  1822,    -1,  1853,    -1,    -1,    -1,   678,  1355,  1583,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1875,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1854,  1884,  1382,  1857,    -1,    -1,    -1,
      -1,    -1,    -1,  1716,    -1,  1392,    -1,    -1,    -1,  1396,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1880,
     731,    -1,    -1,    -1,    -1,  1738,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1424,    -1,    -1,
      -1,    -1,  1672,    -1,    -1,    -1,    -1,    -1,    -1,   760,
      -1,    -1,    -1,  1683,  1684,    -1,    -1,  1687,  1672,    -1,
      -1,    -1,    -1,   774,  1694,    -1,    -1,   778,   779,  1683,
    1684,    -1,    -1,  1687,    -1,    -1,    -1,    -1,  1465,    -1,
    1694,    -1,    -1,    -1,    -1,    -1,   797,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   805,    -1,    -1,   808,    -1,    -1,
      -1,   812,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1497,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   844,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   855,    -1,    -1,    -1,    -1,    -1,
      -1,  1781,    -1,    -1,  1541,    -1,    -1,  1544,    -1,    -1,
    1547,    -1,    -1,    -1,    -1,    -1,    -1,  1781,    -1,    -1,
      -1,    -1,    -1,  1560,    -1,    -1,    -1,    -1,  1565,   111,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1820,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1820,    -1,  1838,    -1,
      -1,   922,    -1,  1600,  1601,    -1,    -1,    -1,    -1,    -1,
      -1,   932,    -1,  1853,  1838,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   170,  1853,
      -1,    -1,    -1,    -1,    -1,  1875,   957,   958,   959,   960,
      -1,    -1,    -1,    -1,  1884,    -1,    -1,    -1,    -1,    -1,
      -1,  1875,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1884,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1001,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1686,
      -1,  1688,    -1,  1690,  1015,  1692,    -1,    -1,    -1,    -1,
      -1,    -1,  1699,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   255,    -1,    -1,    -1,    -1,    -1,  1040,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1049,    -1,
    1051,    -1,  1053,    -1,  1055,    -1,    -1,    -1,    -1,    -1,
      -1,  1062,    -1,  1740,    -1,  1742,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1758,    -1,    -1,  1761,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1095,  1772,  1097,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1783,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1805,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1813,    -1,    -1,    -1,
      -1,    -1,  1819,    -1,  1821,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1164,    -1,  1842,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1851,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1192,    -1,    -1,  1871,    -1,    -1,    -1,    -1,  1876,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1888,    -1,    -1,  1891,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1230,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1285,    -1,    -1,    -1,  1289,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1301,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1315,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1325,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     572,    -1,    -1,    -1,  1355,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   601,
     602,  1382,    -1,    -1,   606,   607,   608,    -1,    -1,   611,
      -1,    -1,   614,    -1,    -1,    -1,    -1,    -1,   620,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   630,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1424,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   653,   654,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   664,    -1,    -1,    -1,   668,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1465,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1497,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   733,    -1,    -1,    -1,   737,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1541,    -1,    -1,  1544,    -1,    -1,  1547,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   776,    -1,    -1,    -1,    -1,  1560,
      -1,    -1,    -1,    -1,  1565,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   813,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1600,
    1601,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   839,    -1,    -1,
      -1,   843,   844,    -1,   846,    -1,    -1,    -1,    -1,    -1,
      -1,   853,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   874,   875,    -1,    -1,   878,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   898,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1686,    -1,  1688,    -1,  1690,
      -1,  1692,    -1,    -1,    -1,    -1,   918,    -1,  1699,    -1,
      -1,    -1,   924,   925,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1740,
      -1,  1742,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1758,    -1,    -1,
    1761,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1772,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1003,  1783,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1805,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1813,    -1,    -1,    -1,  1038,    -1,  1819,    -1,
    1821,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1057,    -1,    -1,    -1,    -1,
      -1,  1842,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1851,  1073,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1084,  1085,    -1,    -1,    -1,    -1,    -1,    -1,
    1871,    -1,    -1,    -1,    -1,  1876,    -1,  1099,    -1,    -1,
    1102,    -1,    -1,    -1,    -1,    -1,    -1,  1888,    -1,    -1,
    1891,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1121,
    1122,  1123,    -1,  1125,  1126,  1127,  1128,  1129,    -1,    -1,
    1132,  1133,    -1,  1135,  1136,    -1,    -1,    -1,  1140,  1141,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1149,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1160,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1217,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1291,
      -1,  1293,    -1,  1295,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1303,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1312,    -1,    -1,    -1,    -1,    -1,  1318,  1319,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1337,    -1,    -1,  1340,  1341,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1380,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1413,    -1,    -1,    -1,  1417,  1418,    -1,    -1,    -1,
      -1,  1423,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1510,    -1,
      -1,    -1,  1514,    -1,    -1,    -1,  1518,    -1,  1520,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1528,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1536,  1537,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1557,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1569,  1570,  1571,
    1572,    -1,  1574,  1575,    -1,  1577,    -1,  1579,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1594,    -1,    -1,    -1,    -1,  1599,    -1,    -1,
      -1,    -1,    -1,  1605,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1665,    -1,  1667,    -1,    -1,  1670,    -1,
      -1,  1673,    -1,    -1,    -1,    -1,  1678,  1679,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1687,    -1,    -1,    -1,  1691,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1708,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1720,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1765,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1777,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1820,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     0,     1,    -1,    -1,    -1,    -1,  1849,    -1,    -1,
      -1,  1853,    11,    12,    -1,    -1,  1858,    16,    -1,    -1,
      -1,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      -1,    30,  1874,    -1,    33,    34,  1878,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    -1,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    -1,    95,    96,    97,    98,
      99,    -1,   101,   102,   103,    -1,    -1,   106,   107,    -1,
      -1,    -1,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,    -1,   122,    -1,    -1,    -1,   126,    -1,   128,
     129,   130,   131,    -1,   133,    -1,    -1,    -1,   137,   138,
     139,   140,   141,    -1,    -1,    -1,    -1,    -1,    -1,   148,
     149,   150,   151,   152,   153,   154,   155,   156,    -1,   158,
     159,   160,   161,   162,    -1,    -1,    -1,   166,   167,   168,
     169,   170,   171,   172,   173,    -1,   175,    -1,   177,   178,
      -1,    -1,   181,   182,   183,    -1,    -1,    -1,   187,    -1,
     189,   190,   191,   192,   193,   194,    -1,   196,    -1,   198,
      -1,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,    -1,    -1,   213,   214,   215,    -1,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   262,   263,    -1,   265,   266,   267,    -1,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,    -1,   318,
      -1,   320,   321,   322,   323,   324,   325,   326,     0,     1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    11,
      12,    -1,    -1,    -1,    16,    -1,    -1,    -1,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    -1,    30,    -1,
      -1,    33,    34,    -1,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    -1,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    -1,    95,    96,    97,    98,    99,    -1,   101,
     102,   103,    -1,    -1,   106,   107,    -1,    -1,    -1,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,    -1,
     122,    -1,    -1,    -1,   126,    -1,   128,   129,   130,   131,
      -1,   133,    -1,    -1,    -1,   137,   138,   139,   140,   141,
      -1,    -1,    -1,    -1,    -1,    -1,   148,   149,   150,   151,
     152,   153,   154,   155,   156,    -1,   158,   159,   160,   161,
     162,    -1,    -1,    -1,   166,   167,   168,   169,   170,   171,
     172,   173,    -1,   175,    -1,   177,   178,    -1,    -1,   181,
     182,   183,    -1,    -1,    -1,   187,    -1,   189,   190,   191,
     192,   193,   194,    -1,   196,    -1,   198,    -1,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,    -1,
      -1,   213,   214,   215,    -1,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,    -1,   265,   266,   267,    -1,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,     1,   318,    -1,   320,   321,
     322,   323,   324,   325,   326,    11,    12,    -1,    -1,    -1,
      16,    -1,    -1,    -1,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    -1,    30,    -1,    -1,    33,    34,    -1,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    -1,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    -1,    95,
      96,    97,    98,    99,    -1,   101,   102,   103,    -1,    -1,
     106,   107,    -1,    -1,    -1,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,    -1,   122,    -1,    -1,    -1,
     126,    -1,   128,   129,   130,   131,    -1,   133,    -1,    -1,
      -1,   137,   138,   139,   140,   141,    -1,    -1,    -1,    -1,
      -1,    -1,   148,   149,   150,   151,   152,   153,   154,   155,
     156,    -1,   158,   159,   160,   161,   162,    -1,    -1,    -1,
     166,   167,   168,   169,   170,   171,   172,   173,    -1,   175,
      -1,   177,   178,    -1,    -1,   181,   182,   183,    -1,    -1,
      -1,   187,    -1,   189,   190,   191,   192,   193,   194,    -1,
     196,    -1,   198,    -1,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,    -1,    -1,   213,   214,   215,
      -1,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,    -1,   265,
     266,   267,    -1,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,     1,   318,    -1,   320,   321,   322,   323,   324,   325,
     326,    11,    12,    -1,    -1,    -1,    16,    -1,    -1,    -1,
      20,    21,    22,    23,    24,    25,    26,    -1,    -1,    -1,
      30,    -1,    -1,    33,    34,    -1,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    -1,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    -1,    95,    96,    97,    98,    99,
      -1,   101,   102,   103,    -1,    -1,   106,   107,    -1,    -1,
      -1,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,    -1,   122,    -1,    -1,    -1,   126,    -1,   128,   129,
     130,   131,    -1,   133,    -1,    -1,    -1,   137,   138,   139,
     140,   141,    -1,    -1,    -1,    -1,    -1,    -1,   148,   149,
     150,   151,   152,   153,   154,   155,   156,    -1,   158,   159,
     160,   161,   162,    -1,    -1,    -1,   166,   167,   168,   169,
     170,   171,   172,   173,    -1,   175,    -1,   177,   178,    -1,
      -1,   181,   182,   183,    -1,    -1,    -1,   187,    -1,   189,
     190,   191,    -1,   193,   194,    -1,   196,    -1,   198,    -1,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,    -1,    -1,   213,   214,   215,    -1,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,    -1,   265,   266,   267,    -1,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,    -1,   318,    -1,
     320,   321,   322,   323,   324,   325,   326,     0,     1,    -1,
       3,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,
      -1,    -1,    -1,    46,    -1,    -1,    -1,    50,    51,    -1,
      -1,    -1,    -1,    56,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    67,    -1,    -1,    70,    -1,    72,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      93,    -1,    95,    96,    97,    -1,    -1,   100,   101,   102,
     103,    -1,    -1,    -1,   107,   108,    -1,    -1,    -1,    -1,
      -1,   114,    -1,    -1,   117,   118,   119,    -1,    -1,    -1,
     123,    -1,    -1,    -1,    -1,   128,   129,    -1,    -1,    -1,
      -1,   134,    -1,    -1,    -1,   138,    -1,    -1,    -1,   142,
     143,    -1,   145,    -1,   147,   148,    -1,    -1,    -1,   152,
     153,    -1,    -1,   156,   157,   158,   159,   160,   161,    -1,
      -1,   164,    -1,    -1,    -1,   168,   169,    -1,    -1,   172,
      -1,    -1,    -1,    -1,   177,    -1,    -1,   180,    -1,    -1,
      -1,    -1,   185,   186,   187,   188,   189,   190,    -1,   192,
     193,   194,   195,   196,    -1,    -1,    -1,    -1,   201,   202,
     203,    -1,   205,   206,   207,   208,   209,   210,    -1,   212,
      -1,   214,    -1,    -1,    -1,    -1,    -1,   220,    -1,    -1,
      -1,   224,   225,    -1,     0,     1,    -1,     3,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   239,    -1,   241,    -1,
     243,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   255,    -1,    -1,    -1,    -1,   260,    -1,    -1,
     263,    -1,    -1,    -1,    -1,    -1,    42,    -1,    -1,    -1,
      46,    -1,    -1,    -1,    50,    51,    -1,    -1,    -1,    -1,
      56,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    67,    -1,    -1,    70,    -1,    72,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   317,    -1,   319,    93,    -1,    95,
      96,    97,    -1,    -1,   100,   101,   102,   103,    -1,    -1,
      -1,   107,   108,    -1,    -1,    -1,    -1,    -1,   114,    -1,
      -1,   117,   118,   119,    -1,    -1,    -1,   123,    -1,    -1,
      -1,    -1,   128,   129,    -1,    -1,    -1,    -1,   134,    -1,
      -1,    -1,   138,    -1,    -1,    -1,   142,   143,    -1,   145,
      -1,   147,   148,    -1,    -1,    -1,   152,   153,    -1,    -1,
     156,   157,   158,   159,   160,   161,    -1,    -1,   164,    -1,
      -1,    -1,   168,   169,    -1,    -1,   172,    -1,    -1,    -1,
      -1,   177,    -1,    -1,   180,    -1,    -1,    -1,    -1,   185,
     186,   187,   188,   189,   190,    -1,   192,   193,   194,   195,
     196,    -1,    -1,    -1,    -1,   201,   202,   203,    -1,   205,
     206,   207,   208,   209,   210,    -1,   212,    -1,   214,    -1,
      -1,    -1,    -1,    -1,   220,    -1,    -1,    -1,   224,   225,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   239,    -1,   241,    -1,   243,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   255,
      -1,    -1,    -1,    -1,   260,    -1,    -1,   263,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    11,    12,    -1,    -1,    -1,    16,    -1,
      -1,    -1,    20,    21,    22,    23,    24,    25,    26,    27,
      28,   317,    30,   319,    -1,    33,    34,    -1,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    -1,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    -1,    95,    96,    97,
      98,    99,    -1,   101,   102,   103,    -1,    -1,   106,   107,
      -1,    -1,    -1,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,    -1,   122,    -1,    -1,    -1,   126,    -1,
     128,   129,   130,   131,    -1,   133,    -1,    -1,    -1,   137,
     138,   139,   140,   141,    -1,    -1,    -1,    -1,    -1,    -1,
     148,   149,   150,   151,   152,   153,   154,   155,   156,    -1,
     158,   159,   160,   161,   162,    -1,    -1,    -1,   166,   167,
     168,   169,   170,   171,   172,   173,    -1,   175,    -1,   177,
     178,    -1,    -1,   181,   182,   183,    -1,    -1,    -1,   187,
      -1,   189,   190,   191,   192,   193,   194,    -1,   196,    -1,
     198,    -1,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,    -1,    -1,   213,   214,   215,    -1,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,    -1,   265,   266,   267,
      -1,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,    -1,
     318,    -1,   320,   321,   322,   323,   324,   325,   326,   327,
     328,    11,    12,    -1,    -1,    -1,    16,    -1,    -1,    -1,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    -1,
      30,    -1,    -1,    33,    34,    -1,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    -1,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    -1,    95,    96,    97,    98,    99,
      -1,   101,   102,   103,    -1,    -1,   106,   107,    -1,    -1,
      -1,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,    -1,   122,    -1,    -1,    -1,   126,    -1,   128,   129,
     130,   131,    -1,   133,    -1,    -1,    -1,   137,   138,   139,
     140,   141,    -1,    -1,    -1,    -1,    -1,    -1,   148,   149,
     150,   151,   152,   153,   154,   155,   156,    -1,   158,   159,
     160,   161,   162,    -1,    -1,    -1,   166,   167,   168,   169,
     170,   171,   172,   173,    -1,   175,    -1,   177,   178,    -1,
      -1,   181,   182,   183,    -1,    -1,    -1,   187,    -1,   189,
     190,   191,   192,   193,   194,    -1,   196,    -1,   198,    -1,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,    -1,    -1,   213,   214,   215,    -1,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,    -1,   265,   266,   267,    -1,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,    -1,   318,    -1,
     320,   321,   322,   323,   324,   325,   326,    -1,   328,    11,
      12,    -1,    -1,    -1,    16,    -1,    -1,    -1,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    -1,    30,    -1,
      -1,    33,    34,    -1,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    -1,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    -1,    95,    96,    97,    98,    99,    -1,   101,
     102,   103,    -1,    -1,   106,   107,    -1,    -1,    -1,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,    -1,
     122,    -1,    -1,    -1,   126,    -1,   128,   129,   130,   131,
      -1,   133,    -1,    -1,    -1,   137,   138,   139,   140,   141,
      -1,    -1,    -1,    -1,    -1,    -1,   148,   149,   150,   151,
     152,   153,   154,   155,   156,    -1,   158,   159,   160,   161,
     162,    -1,    -1,    -1,   166,   167,   168,   169,   170,   171,
     172,   173,    -1,   175,    -1,   177,   178,    -1,    -1,   181,
     182,   183,    -1,   185,    -1,   187,    -1,   189,   190,   191,
     192,   193,   194,    -1,   196,    -1,   198,    -1,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,    -1,
      -1,   213,   214,   215,    -1,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,    -1,   265,   266,   267,    -1,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,    -1,   318,    -1,   320,   321,
     322,   323,   324,   325,   326,    11,    12,    -1,    -1,    -1,
      16,    -1,    -1,    -1,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    -1,    30,    -1,    -1,    33,    34,    -1,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    -1,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    -1,    95,
      96,    97,    98,    99,    -1,   101,   102,   103,    -1,    -1,
     106,   107,    -1,    -1,    -1,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,    -1,   122,    -1,    -1,    -1,
     126,    -1,   128,   129,   130,   131,    -1,   133,    -1,    -1,
      -1,   137,   138,   139,   140,   141,    -1,    -1,    -1,    -1,
      -1,    -1,   148,   149,   150,   151,   152,   153,   154,   155,
     156,    -1,   158,   159,   160,   161,   162,    -1,    -1,    -1,
     166,   167,   168,   169,   170,   171,   172,   173,    -1,   175,
      -1,   177,   178,    -1,    -1,   181,   182,   183,    -1,    -1,
      -1,   187,    -1,   189,   190,   191,   192,   193,   194,    -1,
     196,    -1,   198,    -1,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,    -1,    -1,   213,   214,   215,
      -1,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,    -1,   265,
     266,   267,    -1,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,    -1,   318,    -1,   320,   321,   322,   323,   324,   325,
     326,    11,    12,    -1,    -1,    -1,    16,    -1,    -1,    -1,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    -1,
      30,    -1,    -1,    33,    34,    -1,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    -1,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    -1,    95,    96,    97,    98,    99,
      -1,   101,   102,   103,    -1,    -1,   106,   107,    -1,    -1,
      -1,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,    -1,   122,    -1,    -1,    -1,   126,    -1,   128,   129,
     130,   131,    -1,   133,    -1,    -1,    -1,   137,   138,   139,
     140,   141,    -1,    -1,    -1,    -1,    -1,    -1,   148,   149,
     150,   151,   152,   153,   154,   155,   156,    -1,   158,   159,
     160,   161,   162,    -1,    -1,    -1,   166,   167,   168,   169,
     170,   171,   172,   173,    -1,   175,    -1,   177,   178,    -1,
      -1,   181,   182,   183,    -1,    -1,    -1,   187,    -1,   189,
     190,   191,   192,   193,   194,    -1,   196,    -1,   198,    -1,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,    -1,    -1,   213,   214,   215,    -1,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,    -1,   265,   266,   267,    -1,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,    -1,   318,    -1,
     320,   321,   322,   323,   324,   325,   326,    11,    12,    -1,
      -1,    -1,    16,    -1,    -1,    -1,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    -1,    30,    -1,    -1,    33,
      34,    -1,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    -1,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      -1,    95,    96,    97,    98,    99,    -1,   101,   102,   103,
      -1,    -1,   106,   107,    -1,    -1,    -1,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,    -1,   122,    -1,
      -1,    -1,   126,    -1,   128,   129,   130,   131,    -1,   133,
      -1,    -1,    -1,   137,   138,   139,   140,   141,    -1,    -1,
      -1,    -1,    -1,    -1,   148,   149,   150,   151,   152,   153,
     154,   155,   156,    -1,   158,   159,   160,   161,   162,    -1,
      -1,    -1,   166,   167,   168,   169,   170,   171,   172,   173,
      -1,   175,    -1,   177,   178,    -1,    -1,   181,   182,   183,
      -1,    -1,    -1,   187,    -1,   189,   190,   191,   192,   193,
     194,    -1,   196,    -1,   198,    -1,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,    -1,    -1,   213,
     214,   215,    -1,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   263,
      -1,   265,   266,   267,    -1,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,    -1,   318,    -1,   320,   321,   322,   323,
     324,   325,   326,    11,    12,    -1,    -1,    -1,    16,    -1,
      -1,    -1,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    -1,    30,    -1,    -1,    33,    34,    -1,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    -1,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    -1,    95,    96,    97,
      98,    99,    -1,   101,   102,   103,    -1,    -1,   106,   107,
      -1,    -1,    -1,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,    -1,   122,    -1,    -1,    -1,   126,    -1,
     128,   129,   130,   131,    -1,   133,    -1,    -1,    -1,   137,
     138,   139,   140,   141,    -1,    -1,    -1,    -1,    -1,    -1,
     148,   149,   150,   151,   152,   153,   154,   155,   156,    -1,
     158,   159,   160,   161,   162,    -1,    -1,    -1,   166,   167,
     168,   169,   170,   171,   172,   173,    -1,   175,    -1,   177,
     178,    -1,    -1,   181,   182,   183,    -1,    -1,    -1,   187,
      -1,   189,   190,   191,   192,   193,   194,    -1,   196,    -1,
     198,    -1,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,    -1,    -1,   213,   214,   215,    -1,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,    -1,   265,   266,   267,
      -1,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,    -1,
     318,    -1,   320,   321,   322,   323,   324,   325,   326,    11,
      12,    -1,    -1,    -1,    16,    -1,    -1,    -1,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    -1,    30,    -1,
      -1,    33,    34,    -1,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    -1,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    -1,    95,    96,    97,    98,    99,    -1,   101,
     102,   103,    -1,    -1,   106,   107,    -1,    -1,    -1,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,    -1,
     122,    -1,    -1,    -1,   126,    -1,   128,   129,   130,   131,
      -1,   133,    -1,    -1,    -1,   137,   138,   139,   140,   141,
      -1,    -1,    -1,    -1,    -1,    -1,   148,   149,   150,   151,
     152,   153,   154,   155,   156,    -1,   158,   159,   160,   161,
     162,    -1,    -1,    -1,   166,   167,   168,   169,   170,   171,
     172,   173,    -1,   175,    -1,   177,   178,    -1,    -1,   181,
     182,   183,    -1,    -1,    -1,   187,    -1,   189,   190,   191,
     192,   193,   194,    -1,   196,    -1,   198,    -1,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,    -1,
      -1,   213,   214,   215,    -1,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,    -1,   265,   266,   267,    -1,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,    -1,   318,    -1,   320,   321,
     322,   323,   324,   325,   326,    11,    12,    -1,    -1,    -1,
      16,    -1,    -1,    -1,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    -1,    30,    -1,    -1,    33,    34,    -1,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    -1,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    -1,    95,
      96,    97,    98,    99,    -1,   101,   102,   103,    -1,    -1,
     106,   107,    -1,    -1,    -1,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,    -1,   122,    -1,    -1,    -1,
     126,    -1,   128,   129,   130,   131,    -1,   133,    -1,    -1,
      -1,   137,   138,   139,   140,   141,    -1,    -1,    -1,    -1,
      -1,    -1,   148,   149,   150,   151,   152,   153,   154,   155,
     156,    -1,   158,   159,   160,   161,   162,    -1,    -1,    -1,
     166,   167,   168,   169,   170,   171,   172,   173,    -1,   175,
      -1,   177,   178,    -1,    -1,   181,   182,   183,    -1,    -1,
      -1,   187,    -1,   189,   190,   191,   192,   193,   194,    -1,
     196,    -1,   198,    -1,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,    -1,    -1,   213,   214,   215,
      -1,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,    -1,   265,
     266,   267,    -1,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,    -1,   318,    -1,   320,   321,   322,   323,   324,   325,
     326,    11,    12,    -1,    -1,    -1,    16,    -1,    -1,    -1,
      20,    21,    22,    23,    24,    25,    26,    -1,    -1,    -1,
      30,    -1,    -1,    33,    34,    -1,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    -1,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    -1,    95,    96,    97,    98,    99,
      -1,   101,   102,   103,    -1,    -1,   106,   107,    -1,    -1,
      -1,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,    -1,   122,    -1,    -1,    -1,   126,    -1,   128,   129,
     130,   131,    -1,   133,    -1,    -1,    -1,   137,   138,   139,
     140,   141,    -1,    -1,    -1,    -1,   146,    -1,   148,   149,
     150,   151,   152,   153,   154,   155,   156,    -1,   158,   159,
     160,   161,   162,    -1,    -1,    -1,   166,   167,   168,   169,
     170,   171,   172,   173,    -1,   175,    -1,   177,   178,    -1,
      -1,   181,   182,   183,    -1,    -1,    -1,   187,   188,   189,
     190,   191,    -1,   193,   194,    -1,   196,    -1,   198,    -1,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,    -1,    -1,   213,   214,   215,    -1,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,    -1,   265,   266,   267,    -1,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,    -1,   318,    -1,
     320,   321,   322,   323,   324,   325,   326,    11,    12,    -1,
      -1,    -1,    16,    -1,    -1,    -1,    20,    21,    22,    23,
      24,    25,    26,    -1,    -1,    -1,    30,    -1,    -1,    33,
      34,    -1,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    -1,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      -1,    95,    96,    97,    98,    99,    -1,   101,   102,   103,
      -1,    -1,   106,   107,    -1,    -1,    -1,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,    -1,   122,    -1,
      -1,    -1,   126,    -1,   128,   129,   130,   131,    -1,   133,
      -1,    -1,    -1,   137,   138,   139,   140,   141,    -1,    -1,
      -1,    -1,   146,    -1,   148,   149,   150,   151,   152,   153,
     154,   155,   156,    -1,   158,   159,   160,   161,   162,    -1,
      -1,    -1,   166,   167,   168,   169,   170,   171,   172,   173,
      -1,   175,    -1,   177,   178,    -1,    -1,   181,   182,   183,
      -1,    -1,    -1,   187,   188,   189,   190,   191,    -1,   193,
     194,    -1,   196,    -1,   198,    -1,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,    -1,    -1,   213,
     214,   215,    -1,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   263,
      -1,   265,   266,   267,    -1,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,    -1,   318,    -1,   320,   321,   322,   323,
     324,   325,   326,    11,    12,    -1,    -1,    -1,    16,    -1,
      -1,    -1,    20,    21,    22,    23,    24,    25,    26,    -1,
      -1,    -1,    30,    -1,    -1,    33,    34,    -1,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    -1,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    -1,    95,    96,    97,
      98,    99,    -1,   101,   102,   103,    -1,    -1,   106,   107,
      -1,    -1,    -1,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,    -1,   122,    -1,    -1,    -1,   126,    -1,
     128,   129,   130,   131,    -1,   133,    -1,    -1,    -1,   137,
     138,   139,   140,   141,    -1,    -1,    -1,    -1,    -1,    -1,
     148,   149,   150,   151,   152,   153,   154,   155,   156,    -1,
     158,   159,   160,   161,   162,    -1,    -1,    -1,   166,   167,
     168,   169,   170,   171,   172,   173,    -1,   175,    -1,   177,
     178,    -1,    -1,   181,   182,   183,    -1,    -1,   186,   187,
      -1,   189,   190,   191,    -1,   193,   194,    -1,   196,    -1,
     198,    -1,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,    -1,    -1,   213,   214,   215,    -1,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,    -1,   265,   266,   267,
      -1,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,    -1,
     318,    -1,   320,   321,   322,   323,   324,   325,   326,    11,
      12,    -1,    -1,    -1,    16,    -1,    -1,    -1,    20,    21,
      22,    23,    24,    25,    26,    -1,    -1,    -1,    30,    -1,
      -1,    33,    34,    -1,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    -1,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    -1,    95,    96,    97,    98,    99,    -1,   101,
     102,   103,    -1,    -1,   106,   107,    -1,    -1,    -1,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,    -1,
     122,    -1,    -1,    -1,   126,    -1,   128,   129,   130,   131,
      -1,   133,    -1,    -1,    -1,   137,   138,   139,   140,   141,
      -1,    -1,    -1,    -1,    -1,    -1,   148,   149,   150,   151,
     152,   153,   154,   155,   156,    -1,   158,   159,   160,   161,
     162,    -1,    -1,    -1,   166,   167,   168,   169,   170,   171,
     172,   173,    -1,   175,    -1,   177,   178,    -1,    -1,   181,
     182,   183,    -1,    -1,    -1,   187,   188,   189,   190,   191,
      -1,   193,   194,    -1,   196,    -1,   198,    -1,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,    -1,
      -1,   213,   214,   215,    -1,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,    -1,   265,   266,   267,    -1,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,    -1,   318,    -1,   320,   321,
     322,   323,   324,   325,   326,    11,    12,    -1,    -1,    -1,
      16,    -1,    -1,    -1,    20,    21,    22,    23,    24,    25,
      26,    -1,    -1,    -1,    30,    -1,    -1,    33,    34,    -1,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    -1,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    -1,    95,
      96,    97,    98,    99,    -1,   101,   102,   103,    -1,    -1,
     106,   107,    -1,    -1,    -1,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,    -1,   122,    -1,    -1,    -1,
     126,    -1,   128,   129,   130,   131,    -1,   133,    -1,    -1,
      -1,   137,   138,   139,   140,   141,    -1,    -1,    -1,    -1,
      -1,    -1,   148,   149,   150,   151,   152,   153,   154,   155,
     156,    -1,   158,   159,   160,   161,   162,    -1,    -1,    -1,
     166,   167,   168,   169,   170,   171,   172,   173,    -1,   175,
      -1,   177,   178,    -1,    -1,   181,   182,   183,    -1,    -1,
      -1,   187,    -1,   189,   190,   191,    -1,   193,   194,    -1,
     196,    -1,   198,    -1,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,    -1,    -1,   213,   214,   215,
      -1,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,    -1,   265,
     266,   267,    -1,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,   317,   318,    -1,   320,   321,   322,   323,   324,   325,
     326,    11,    12,    -1,    -1,    -1,    16,    -1,    -1,    -1,
      20,    21,    22,    23,    24,    25,    26,    -1,    -1,    -1,
      30,    -1,    -1,    33,    34,    -1,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    -1,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    -1,    95,    96,    97,    98,    99,
      -1,   101,   102,   103,    -1,    -1,   106,   107,    -1,    -1,
      -1,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,    -1,   122,    -1,    -1,    -1,   126,    -1,   128,   129,
     130,   131,    -1,   133,    -1,    -1,    -1,   137,   138,   139,
     140,   141,    -1,    -1,    -1,    -1,    -1,    -1,   148,   149,
     150,   151,   152,   153,   154,   155,   156,    -1,   158,   159,
     160,   161,   162,    -1,    -1,    -1,   166,   167,   168,   169,
     170,   171,   172,   173,    -1,   175,    -1,   177,   178,    -1,
      -1,   181,   182,   183,    -1,    -1,    -1,   187,    -1,   189,
     190,   191,    -1,   193,   194,    -1,   196,    -1,   198,    -1,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,    -1,    -1,   213,   214,   215,    -1,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,    -1,   265,   266,   267,    -1,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,    -1,   318,   319,
     320,   321,   322,   323,   324,   325,   326,    11,    12,    -1,
      -1,    -1,    16,    -1,    -1,    -1,    20,    21,    22,    23,
      24,    25,    26,    -1,    -1,    -1,    30,    -1,    -1,    33,
      34,    -1,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    -1,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      -1,    95,    96,    97,    98,    99,    -1,   101,   102,   103,
      -1,    -1,   106,   107,    -1,    -1,    -1,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,    -1,   122,    -1,
      -1,    -1,   126,    -1,   128,   129,   130,   131,    -1,   133,
      -1,    -1,    -1,   137,   138,   139,   140,   141,    -1,    -1,
      -1,    -1,    -1,    -1,   148,   149,   150,   151,   152,   153,
     154,   155,   156,    -1,   158,   159,   160,   161,   162,    -1,
      -1,    -1,   166,   167,   168,   169,   170,   171,   172,   173,
      -1,   175,    -1,   177,   178,    -1,    -1,   181,   182,   183,
      -1,    -1,   186,   187,    -1,   189,   190,   191,    -1,   193,
     194,    -1,   196,    -1,   198,    -1,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,    -1,    -1,   213,
     214,   215,    -1,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   263,
      -1,   265,   266,   267,    -1,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,    -1,   318,    -1,   320,   321,   322,   323,
     324,   325,   326,    11,    12,    -1,    -1,    -1,    16,    -1,
      -1,    -1,    20,    21,    22,    23,    24,    25,    26,    -1,
      -1,    -1,    30,    -1,    -1,    33,    34,    -1,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    -1,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    -1,    95,    96,    97,
      98,    99,    -1,   101,   102,   103,    -1,    -1,   106,   107,
      -1,    -1,    -1,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,    -1,   122,    -1,    -1,    -1,   126,    -1,
     128,   129,   130,   131,    -1,   133,    -1,    -1,    -1,   137,
     138,   139,   140,   141,    -1,    -1,    -1,    -1,    -1,    -1,
     148,   149,   150,   151,   152,   153,   154,   155,   156,    -1,
     158,   159,   160,   161,   162,    -1,    -1,    -1,   166,   167,
     168,   169,   170,   171,   172,   173,    -1,   175,    -1,   177,
     178,    -1,    -1,   181,   182,   183,    -1,    -1,    -1,   187,
     188,   189,   190,   191,    -1,   193,   194,    -1,   196,    -1,
     198,    -1,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,    -1,    -1,   213,   214,   215,    -1,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,    -1,   265,   266,   267,
      -1,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,    -1,
     318,    -1,   320,   321,   322,   323,   324,   325,   326,    11,
      12,    -1,    -1,    -1,    16,    -1,    -1,    -1,    20,    21,
      22,    23,    24,    25,    26,    -1,    -1,    -1,    30,    -1,
      -1,    33,    34,    -1,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    -1,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    -1,    95,    96,    97,    98,    99,    -1,   101,
     102,   103,    -1,    -1,   106,   107,    -1,    -1,    -1,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,    -1,
     122,    -1,    -1,    -1,   126,    -1,   128,   129,   130,   131,
      -1,   133,    -1,    -1,    -1,   137,   138,   139,   140,   141,
      -1,    -1,    -1,    -1,   146,    -1,   148,   149,   150,   151,
     152,   153,   154,   155,   156,    -1,   158,   159,   160,   161,
     162,    -1,    -1,    -1,   166,   167,   168,   169,   170,   171,
     172,   173,    -1,   175,    -1,   177,   178,    -1,    -1,   181,
     182,   183,    -1,    -1,    -1,   187,    -1,   189,   190,   191,
      -1,   193,   194,    -1,   196,    -1,   198,    -1,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,    -1,
      -1,   213,   214,   215,    -1,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,    -1,   265,   266,   267,    -1,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,    -1,   318,    -1,   320,   321,
     322,   323,   324,   325,   326,    11,    12,    -1,    -1,    -1,
      16,    -1,    -1,    -1,    20,    21,    22,    23,    24,    25,
      26,    -1,    -1,    -1,    30,    -1,    -1,    33,    34,    -1,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    -1,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    -1,    95,
      96,    97,    98,    99,    -1,   101,   102,   103,    -1,    -1,
     106,   107,    -1,    -1,    -1,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,    -1,   122,    -1,    -1,    -1,
     126,    -1,   128,   129,   130,   131,    -1,   133,    -1,    -1,
      -1,   137,   138,   139,   140,   141,    -1,    -1,    -1,    -1,
      -1,    -1,   148,   149,   150,   151,   152,   153,   154,   155,
     156,    -1,   158,   159,   160,   161,   162,    -1,    -1,    -1,
     166,   167,   168,   169,   170,   171,   172,   173,    -1,   175,
      -1,   177,   178,    -1,    -1,   181,   182,   183,    -1,    -1,
      -1,   187,    -1,   189,   190,   191,    -1,   193,   194,    -1,
     196,    -1,   198,    -1,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,    -1,    -1,   213,   214,   215,
      -1,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,    -1,   265,
     266,   267,    -1,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,    -1,   318,    -1,   320,   321,   322,   323,   324,   325,
     326,    11,    12,    -1,    -1,    -1,    16,    -1,    -1,    -1,
      20,    21,    22,    23,    24,    25,    26,    -1,    -1,    -1,
      30,    -1,    -1,    33,    34,    -1,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    -1,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    -1,    95,    96,    97,    98,    99,
      -1,   101,   102,   103,    -1,    -1,   106,   107,    -1,    -1,
      -1,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,    -1,   122,    -1,    -1,    -1,   126,    -1,   128,   129,
     130,   131,    -1,   133,    -1,    -1,    -1,   137,   138,   139,
     140,   141,    -1,    -1,    -1,    -1,    -1,    -1,   148,   149,
     150,   151,   152,   153,   154,   155,   156,    -1,   158,   159,
     160,   161,   162,    -1,    -1,    -1,   166,   167,   168,   169,
     170,   171,   172,   173,    -1,   175,    -1,   177,   178,    -1,
      -1,   181,   182,   183,    -1,    -1,    -1,   187,    -1,   189,
     190,   191,    -1,   193,   194,    -1,   196,    -1,   198,    -1,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,    -1,    -1,   213,   214,   215,    -1,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,    -1,   265,   266,   267,    -1,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,    -1,   318,    -1,
     320,   321,   322,   323,   324,   325,   326,    11,    12,    -1,
      -1,    -1,    16,    -1,    -1,    -1,    20,    21,    22,    23,
      24,    25,    26,    -1,    -1,    -1,    30,    -1,    -1,    33,
      34,    -1,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    -1,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      -1,    95,    96,    97,    98,    99,    -1,   101,   102,   103,
      -1,    -1,   106,   107,    -1,    -1,    -1,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,    -1,   122,    -1,
      -1,    -1,   126,    -1,   128,   129,   130,   131,    -1,   133,
      -1,    -1,    -1,   137,   138,   139,   140,   141,    -1,    -1,
      -1,    -1,    -1,    -1,   148,   149,   150,   151,   152,   153,
     154,   155,   156,    -1,   158,   159,   160,   161,   162,    -1,
      -1,    -1,   166,   167,   168,   169,   170,   171,   172,   173,
      -1,   175,    -1,   177,   178,    -1,    -1,   181,   182,   183,
      -1,    -1,    -1,   187,    -1,   189,   190,   191,    -1,   193,
     194,    -1,   196,    -1,   198,    -1,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,    -1,    -1,   213,
     214,   215,    -1,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   263,
      -1,   265,   266,   267,    -1,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,    -1,   318,    -1,   320,   321,   322,   323,
     324,   325,   326,    11,    12,    -1,    -1,    -1,    16,    -1,
      -1,    -1,    20,    21,    22,    23,    24,    25,    26,    -1,
      -1,    -1,    30,    -1,    -1,    33,    34,    -1,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    -1,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    -1,    95,    96,    97,
      98,    99,    -1,   101,   102,   103,    -1,    -1,   106,   107,
      -1,    -1,    -1,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,    -1,   122,    -1,    -1,    -1,   126,    -1,
     128,   129,   130,   131,    -1,   133,    -1,    -1,    -1,   137,
     138,   139,   140,   141,    -1,    -1,    -1,    -1,    -1,    -1,
     148,   149,   150,   151,   152,   153,   154,   155,   156,    -1,
     158,   159,   160,   161,   162,    -1,    -1,    -1,   166,   167,
     168,   169,   170,   171,   172,   173,    -1,   175,    -1,   177,
     178,    -1,    -1,   181,   182,   183,    -1,    -1,    -1,   187,
      -1,   189,   190,   191,    -1,   193,   194,    -1,   196,    -1,
     198,    -1,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,    -1,    -1,   213,   214,   215,    -1,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,    -1,   265,   266,   267,
      -1,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,    -1,
     318,    -1,   320,   321,   322,   323,   324,   325,   326,    11,
      12,    -1,    -1,    -1,    16,    -1,    -1,    -1,    20,    21,
      22,    23,    24,    25,    26,    -1,    -1,    -1,    30,    -1,
      -1,    33,    34,    -1,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    -1,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    -1,    95,    96,    97,    98,    99,    -1,   101,
     102,   103,    -1,    -1,   106,   107,    -1,    -1,    -1,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,    -1,
     122,    -1,    -1,    -1,   126,    -1,   128,   129,   130,   131,
      -1,   133,    -1,    -1,    -1,   137,   138,   139,   140,   141,
      -1,    -1,    -1,    -1,    -1,    -1,   148,   149,   150,   151,
     152,   153,   154,   155,   156,    -1,   158,   159,   160,   161,
     162,    -1,    -1,    -1,   166,   167,   168,   169,   170,   171,
     172,   173,    -1,   175,    -1,   177,   178,    -1,    -1,   181,
     182,   183,    -1,    -1,    -1,   187,    -1,   189,   190,   191,
      -1,   193,   194,    -1,   196,    -1,   198,    -1,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,    -1,
      -1,   213,   214,   215,    -1,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,    -1,   265,   266,   267,    -1,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,    -1,   318,    -1,   320,   321,
     322,   323,   324,   325,   326,    11,    12,    -1,    -1,    -1,
      16,    -1,    -1,    -1,    20,    21,    22,    23,    24,    25,
      26,    -1,    -1,    -1,    30,    -1,    -1,    33,    34,    -1,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    -1,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    -1,    95,
      96,    97,    98,    99,    -1,   101,   102,   103,    -1,    -1,
     106,   107,    -1,    -1,    -1,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,    -1,   122,    -1,    -1,    -1,
     126,    -1,   128,   129,   130,   131,    -1,   133,    -1,    -1,
      -1,   137,   138,   139,   140,   141,    -1,    -1,    -1,    -1,
      -1,    -1,   148,   149,   150,   151,   152,   153,   154,   155,
     156,    -1,    -1,   159,   160,   161,   162,    -1,    -1,    -1,
     166,   167,   168,   169,   170,   171,   172,   173,    -1,   175,
      -1,   177,   178,    -1,    -1,   181,   182,   183,    -1,    -1,
      -1,   187,    -1,   189,   190,   191,    -1,   193,   194,    -1,
     196,    -1,   198,    -1,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,    -1,    -1,   213,   214,   215,
      -1,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,    -1,   265,
     266,   267,    -1,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,    -1,   318,    -1,   320,   321,   322,   323,   324,   325,
     326,    11,    12,    -1,    -1,    -1,    16,    -1,    -1,    -1,
      20,    21,    22,    23,    24,    25,    26,    -1,    -1,    -1,
      30,    -1,    -1,    33,    34,    -1,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    -1,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    -1,    95,    96,    97,    98,    99,
      -1,   101,   102,   103,    -1,    -1,   106,   107,    -1,    -1,
      -1,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,    -1,   122,    -1,    -1,    -1,   126,    -1,   128,   129,
     130,   131,    -1,   133,    -1,    -1,    -1,   137,   138,   139,
     140,   141,    -1,    -1,    -1,    -1,    -1,    -1,   148,   149,
     150,   151,   152,   153,   154,   155,   156,    -1,   158,   159,
      -1,   161,   162,    -1,    -1,    -1,   166,   167,   168,   169,
     170,   171,   172,   173,    -1,   175,    -1,    -1,    -1,    -1,
      -1,   181,   182,   183,    -1,    -1,    -1,   187,    -1,   189,
     190,   191,    -1,   193,   194,    -1,   196,    -1,   198,    -1,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,    -1,    -1,   213,   214,   215,    -1,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,    -1,   265,   266,   267,    -1,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,    -1,   318,    -1,
     320,   321,   322,   323,   324,   325,   326,    11,    12,    -1,
      -1,    -1,    16,    -1,    -1,    -1,    20,    21,    22,    23,
      24,    25,    26,    -1,    -1,    -1,    30,    -1,    -1,    33,
      34,    -1,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    -1,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      -1,    95,    96,    97,    98,    99,    -1,   101,   102,   103,
      -1,    -1,   106,   107,    -1,    -1,    -1,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,    -1,   122,    -1,
      -1,    -1,   126,    -1,   128,   129,   130,   131,    -1,   133,
      -1,    -1,    -1,   137,   138,   139,   140,   141,    -1,    -1,
      -1,    -1,    -1,    -1,   148,   149,   150,   151,   152,   153,
     154,   155,   156,    -1,   158,   159,    -1,   161,   162,    -1,
      -1,    -1,   166,   167,   168,   169,   170,   171,   172,   173,
      -1,   175,    -1,    -1,    -1,    -1,    -1,   181,   182,   183,
      -1,    -1,    -1,   187,    -1,   189,   190,   191,    -1,    -1,
      -1,    -1,   196,    -1,   198,    -1,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,    -1,    -1,   213,
     214,   215,    -1,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   263,
      -1,   265,   266,   267,    -1,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,    -1,   318,    -1,   320,   321,   322,   323,
     324,   325,   326,    11,    12,    -1,    -1,    -1,    16,    -1,
      -1,    -1,    20,    21,    22,    23,    24,    25,    26,    -1,
      -1,    -1,    30,    -1,    -1,    33,    34,    -1,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    -1,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    -1,    95,    96,    97,
      98,    99,    -1,   101,   102,   103,    -1,    -1,   106,   107,
      -1,    -1,    -1,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,    -1,   122,    -1,    -1,    -1,   126,    -1,
     128,   129,   130,   131,    -1,   133,    -1,    -1,    -1,   137,
      -1,   139,   140,   141,    -1,    -1,    -1,    -1,    -1,    -1,
     148,   149,   150,   151,    -1,   153,   154,   155,   156,    -1,
     158,   159,    -1,   161,   162,    -1,    -1,    -1,   166,   167,
     168,   169,   170,   171,   172,   173,    -1,   175,    -1,    -1,
      -1,    -1,    -1,   181,   182,   183,    -1,    -1,    -1,   187,
      -1,   189,   190,   191,    -1,    -1,    -1,    -1,   196,    -1,
     198,    -1,   200,    -1,   202,    -1,   204,   205,   206,   207,
     208,   209,   210,    -1,    -1,   213,   214,   215,    -1,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,    -1,   265,   266,   267,
      -1,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,    -1,
     318,    -1,   320,   321,   322,   323,   324,   325,   326,    11,
      12,    -1,    -1,    -1,    16,    -1,    -1,    -1,    20,    21,
      22,    23,    24,    25,    26,    -1,    -1,    -1,    30,    -1,
      -1,    33,    34,    -1,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    -1,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    -1,    95,    96,    97,    98,    99,    -1,   101,
     102,   103,    -1,    -1,   106,   107,    -1,    -1,    -1,   111,
     112,   113,   114,   115,   116,   117,    -1,   119,   120,    -1,
     122,    -1,    -1,    -1,   126,    -1,   128,   129,   130,   131,
      -1,   133,    -1,    -1,    -1,   137,    -1,   139,   140,   141,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   149,   150,   151,
      -1,   153,   154,   155,    -1,    -1,    -1,   159,    -1,    -1,
     162,    -1,    -1,    -1,   166,   167,   168,   169,   170,   171,
     172,   173,    -1,   175,    -1,    -1,   178,    -1,    -1,   181,
     182,   183,    -1,    -1,    -1,   187,    -1,   189,   190,   191,
      -1,    -1,    -1,    -1,    -1,    -1,   198,    -1,   200,    -1,
     202,    -1,   204,   205,   206,   207,   208,   209,   210,    -1,
      -1,   213,   214,   215,    -1,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,    -1,   265,   266,   267,    -1,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,    -1,   318,    -1,   320,   321,
     322,   323,   324,   325,   326,    11,    12,    -1,    -1,    -1,
      16,    -1,    -1,    -1,    20,    21,    22,    23,    24,    25,
      26,    -1,    -1,    -1,    30,    -1,    -1,    33,    34,    -1,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    -1,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    -1,    95,
      96,    97,    98,    99,    -1,   101,   102,   103,    -1,    -1,
     106,   107,    -1,    -1,    -1,   111,   112,   113,   114,   115,
     116,   117,    -1,   119,   120,    -1,   122,    -1,    -1,    -1,
     126,    -1,   128,   129,   130,   131,    -1,   133,    -1,    -1,
      -1,   137,    -1,   139,   140,   141,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   149,   150,   151,    -1,   153,   154,   155,
      -1,    -1,    -1,   159,    -1,    -1,   162,    -1,    -1,    -1,
     166,   167,   168,   169,   170,   171,   172,   173,    -1,   175,
      -1,    -1,   178,    -1,    -1,   181,   182,   183,    -1,    -1,
      -1,   187,    -1,   189,   190,   191,    -1,    -1,    -1,    -1,
      -1,    -1,   198,    -1,   200,    -1,   202,    -1,   204,   205,
     206,   207,   208,   209,   210,    -1,    -1,   213,   214,   215,
      -1,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,    -1,   265,
     266,   267,    -1,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,    -1,   318,    -1,   320,   321,   322,   323,   324,   325,
     326,    11,    12,    -1,    -1,    -1,    16,    -1,    -1,    -1,
      20,    21,    22,    23,    24,    25,    26,    -1,    -1,    -1,
      30,    -1,    -1,    33,    34,    -1,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      -1,    51,    52,    53,    54,    -1,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    -1,    -1,    95,    96,    97,    98,    99,
      -1,   101,    -1,    -1,    -1,    -1,   106,   107,    -1,    -1,
      -1,   111,   112,   113,   114,   115,   116,   117,    -1,   119,
     120,    -1,   122,    -1,    -1,    -1,   126,    -1,   128,   129,
     130,   131,    -1,   133,    -1,    -1,    -1,   137,    -1,   139,
     140,   141,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   149,
     150,   151,    -1,   153,   154,   155,    -1,    -1,   158,   159,
      -1,    -1,   162,    -1,    -1,    -1,   166,   167,   168,   169,
     170,   171,   172,   173,    -1,   175,    -1,    -1,   178,    -1,
      -1,   181,   182,   183,    -1,    -1,    -1,   187,    -1,   189,
     190,   191,    -1,    -1,    -1,    -1,    -1,    -1,   198,    -1,
     200,    -1,   202,    -1,   204,   205,   206,   207,   208,   209,
     210,    -1,    -1,   213,   214,   215,    -1,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,    -1,   265,   266,   267,    -1,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,    -1,   318,    -1,
     320,   321,   322,   323,   324,   325,   326,    11,    12,    -1,
      -1,    -1,    16,    -1,    -1,    -1,    20,    21,    22,    23,
      24,    25,    26,    -1,    -1,    -1,    30,    -1,    -1,    33,
      34,    -1,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    -1,    51,    52,    53,
      54,    -1,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    -1,
      -1,    95,    96,    97,    98,    99,    -1,   101,    -1,    -1,
      -1,    -1,   106,   107,    -1,    -1,    -1,   111,   112,   113,
     114,   115,   116,   117,    -1,   119,   120,    -1,   122,    -1,
      -1,    -1,   126,    -1,   128,   129,   130,   131,    -1,   133,
      -1,    -1,    -1,   137,    -1,   139,   140,   141,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   149,   150,   151,    -1,   153,
     154,   155,    -1,    -1,   158,   159,    -1,    -1,   162,    -1,
      -1,    -1,   166,   167,   168,   169,   170,   171,   172,   173,
      -1,   175,    -1,    -1,   178,    -1,    -1,   181,   182,   183,
      -1,    -1,    -1,   187,    -1,   189,   190,   191,    -1,    -1,
      -1,    -1,    -1,    -1,   198,    -1,   200,    -1,   202,    -1,
     204,   205,   206,   207,   208,   209,   210,    -1,    -1,   213,
     214,   215,    -1,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   263,
      -1,   265,   266,   267,    -1,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,    -1,   318,    -1,   320,   321,   322,   323,
     324,   325,   326,    11,    12,    -1,    -1,    -1,    16,    -1,
      -1,    -1,    20,    21,    22,    23,    24,    25,    26,    -1,
      -1,    -1,    30,    -1,    -1,    33,    34,    -1,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    -1,    51,    52,    53,    54,    -1,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    -1,    -1,    95,    96,    97,
      98,    99,    -1,   101,    -1,    -1,    -1,    -1,   106,   107,
      -1,    -1,    -1,   111,   112,   113,   114,   115,   116,   117,
      -1,   119,   120,    -1,   122,    -1,    -1,    -1,   126,    -1,
     128,   129,   130,   131,    -1,   133,    -1,    -1,    -1,   137,
      -1,   139,   140,   141,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   149,   150,   151,    -1,   153,   154,   155,    -1,    -1,
      -1,   159,    -1,    -1,   162,    -1,    -1,    -1,   166,   167,
     168,   169,   170,   171,   172,   173,    -1,   175,    -1,    -1,
     178,    -1,    -1,   181,   182,   183,    -1,    -1,    -1,   187,
      -1,   189,   190,   191,    -1,    -1,    -1,    -1,    -1,    -1,
     198,    -1,   200,    -1,   202,    -1,   204,   205,   206,   207,
     208,   209,   210,    -1,    -1,   213,   214,   215,    -1,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,    -1,   265,   266,   267,
      -1,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,    -1,
     318,    -1,   320,   321,   322,   323,   324,   325,   326,    11,
      12,    -1,    -1,    -1,    16,    -1,    -1,    -1,    20,    -1,
      -1,    -1,    -1,    25,    26,    -1,    -1,    -1,    -1,    -1,
      -1,    33,    34,    -1,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    -1,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    -1,    95,    96,    97,    98,    -1,    -1,   101,
     102,   103,    -1,    -1,   106,   107,    -1,    -1,    -1,    -1,
     112,   113,   114,   115,   116,   117,   118,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   128,   129,   130,   131,
      -1,   133,    -1,    -1,    -1,   137,   138,   139,   140,   141,
      -1,    -1,    -1,    -1,    -1,    -1,   148,   149,   150,    -1,
     152,   153,   154,    -1,    -1,    -1,    -1,    -1,    -1,   161,
     162,    -1,    -1,    -1,   166,   167,   168,   169,   170,   171,
     172,   173,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   181,
     182,   183,    -1,    -1,    -1,   187,    -1,   189,   190,   191,
      -1,    -1,    -1,    -1,   196,    -1,   198,    -1,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,    -1,
      -1,   213,   214,    -1,    -1,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,    -1,   265,   266,   267,    -1,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,    -1,    -1,    -1,    -1,   320,   321,
     322,   323,   324,   325,   326,    11,    12,    -1,    -1,    -1,
      16,    -1,    -1,    -1,    20,    -1,    -1,    -1,    -1,    25,
      26,    -1,    -1,    -1,    -1,    -1,    -1,    33,    34,    -1,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    -1,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    -1,    95,
      96,    97,    98,    -1,    -1,   101,   102,   103,    -1,    -1,
     106,   107,    -1,    -1,    -1,    -1,   112,   113,   114,   115,
     116,   117,   118,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   128,   129,   130,   131,    -1,   133,    -1,    -1,
      -1,   137,   138,   139,   140,   141,    -1,    -1,    -1,    -1,
      -1,    -1,   148,   149,   150,    -1,   152,   153,   154,    -1,
      -1,    -1,    -1,    -1,    -1,   161,   162,    -1,    -1,    -1,
     166,   167,   168,   169,   170,   171,   172,   173,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   181,   182,   183,    -1,    -1,
      -1,   187,    -1,   189,   190,   191,    -1,    -1,    -1,    -1,
     196,    -1,   198,    -1,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,    -1,    -1,   213,   214,    -1,
      -1,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,    -1,   265,
     266,   267,    -1,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
      -1,    -1,    -1,    -1,   320,   321,   322,   323,   324,   325,
     326,    11,    12,    -1,    -1,    -1,    16,    -1,    -1,    -1,
      20,    21,    22,    23,    24,    25,    26,    -1,    -1,    -1,
      30,    -1,    -1,    33,    34,    -1,    36,    37,    38,    39,
      40,    41,    -1,    43,    44,    45,    -1,    47,    48,    49,
      -1,    -1,    52,    53,    54,    -1,    -1,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    -1,
      -1,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    -1,    -1,    -1,    -1,    97,    98,    99,
      -1,    -1,    -1,    -1,    -1,    -1,   106,    -1,    -1,    -1,
      -1,   111,   112,   113,   114,   115,   116,   117,    -1,   119,
     120,    -1,   122,    -1,    -1,    -1,   126,    -1,   128,   129,
     130,   131,    -1,   133,    -1,    -1,    -1,   137,    -1,   139,
     140,   141,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   149,
     150,   151,    -1,   153,   154,   155,    -1,    -1,    -1,   159,
      -1,    -1,   162,    -1,    -1,    -1,   166,   167,   168,   169,
     170,   171,   172,   173,    -1,   175,    -1,    -1,   178,    -1,
      -1,   181,   182,   183,    -1,    -1,    -1,   187,    -1,   189,
     190,   191,    -1,    -1,    -1,    -1,    -1,    -1,   198,    -1,
     200,    -1,   202,    -1,   204,   205,   206,   207,   208,   209,
     210,    -1,    -1,   213,   214,   215,    -1,   217,   218,   219,
     220,   221,   222,   223,    -1,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,    -1,    -1,   265,   266,   267,    -1,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,    -1,   318,    16,
     320,   321,   322,   323,   324,   325,   326,    -1,    25,    26,
      -1,    -1,    -1,    30,    -1,    -1,    33,    34,    -1,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    -1,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    -1,    95,    96,
      97,    98,    -1,    -1,   101,   102,   103,    -1,    -1,   106,
     107,    -1,    -1,    -1,    -1,   112,   113,   114,   115,   116,
     117,   118,   119,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   128,   129,   130,   131,    -1,   133,    -1,    -1,    -1,
     137,   138,   139,   140,   141,    -1,    -1,    -1,    -1,    -1,
      -1,   148,   149,   150,    -1,   152,   153,   154,    -1,    -1,
      -1,   158,    -1,    -1,   161,   162,    -1,    -1,    -1,   166,
     167,   168,   169,   170,   171,   172,   173,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   181,   182,   183,    -1,    -1,    -1,
     187,    -1,   189,   190,   191,    -1,    -1,    -1,    -1,    -1,
      -1,   198,    -1,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,    -1,    -1,   213,   214,    -1,    -1,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   263,    -1,   265,   266,
     267,    -1,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,    -1,
      -1,    16,    -1,   320,   321,   322,   323,   324,   325,   326,
      25,    26,    -1,    -1,    -1,    -1,    -1,    -1,    33,    34,
      -1,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      -1,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    -1,
      95,    96,    97,    98,    -1,    -1,   101,   102,   103,    -1,
      -1,   106,   107,    -1,    -1,    -1,    -1,   112,   113,   114,
     115,   116,   117,   118,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   128,   129,   130,   131,    -1,   133,    -1,
      -1,    -1,   137,   138,   139,   140,   141,    -1,    -1,    -1,
      -1,    -1,    -1,   148,   149,   150,    -1,   152,   153,   154,
      -1,    -1,    -1,   158,    -1,    -1,   161,   162,    -1,    -1,
      -1,   166,   167,   168,   169,   170,   171,   172,   173,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   181,   182,   183,    -1,
      -1,    -1,   187,   188,   189,   190,   191,    -1,    -1,    -1,
      -1,   196,    -1,   198,    -1,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,    -1,    -1,   213,   214,
      -1,    -1,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,    -1,
     265,   266,   267,    -1,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,    -1,    -1,    -1,    -1,   320,   321,   322,   323,   324,
     325,   326,    16,    -1,    18,    19,    -1,    -1,    -1,    -1,
      -1,    25,    26,    -1,    -1,    -1,    -1,    -1,    -1,    33,
      34,    -1,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    -1,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      -1,    95,    96,    97,    98,    -1,    -1,   101,   102,   103,
      -1,    -1,   106,   107,    -1,    -1,    -1,    -1,   112,   113,
     114,   115,   116,   117,   118,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   128,   129,   130,   131,    -1,   133,
      -1,    -1,    -1,   137,   138,   139,   140,   141,    -1,    -1,
      -1,    -1,    -1,    -1,   148,   149,   150,    -1,   152,   153,
     154,    -1,    -1,    -1,    -1,    -1,    -1,   161,   162,    -1,
      -1,    -1,   166,   167,   168,   169,   170,   171,   172,   173,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   181,   182,   183,
      -1,    -1,    -1,   187,    -1,   189,   190,   191,    -1,    -1,
      -1,    -1,    -1,    -1,   198,    -1,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,    -1,    -1,   213,
     214,    -1,    -1,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   263,
      -1,   265,   266,   267,    -1,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,    -1,    -1,    16,    -1,   320,   321,   322,   323,
     324,   325,   326,    25,    26,    -1,    -1,    -1,    -1,    -1,
      -1,    33,    34,    -1,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    -1,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    -1,    95,    96,    97,    98,    -1,    -1,   101,
     102,   103,    -1,    -1,   106,   107,    -1,    -1,    -1,    -1,
     112,   113,   114,   115,   116,   117,   118,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   128,   129,   130,   131,
      -1,   133,    -1,    -1,    -1,   137,   138,   139,   140,   141,
      -1,    -1,    -1,    -1,    -1,    -1,   148,   149,   150,    -1,
     152,   153,   154,    -1,    -1,    -1,    -1,    -1,    -1,   161,
     162,    -1,    -1,    -1,   166,   167,   168,   169,   170,   171,
     172,   173,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   181,
     182,   183,    -1,    -1,    -1,   187,   188,   189,   190,   191,
      -1,    -1,    -1,    -1,   196,    -1,   198,    -1,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,    -1,
      -1,   213,   214,    -1,    -1,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,    -1,   265,   266,   267,    -1,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,    -1,    -1,    16,    -1,   320,   321,
     322,   323,   324,   325,   326,    25,    26,    -1,    -1,    -1,
      30,    -1,    -1,    33,    34,    -1,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    -1,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    -1,    95,    96,    97,    98,    -1,
      -1,   101,   102,   103,    -1,    -1,   106,   107,    -1,    -1,
      -1,    -1,   112,   113,   114,   115,   116,   117,   118,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   128,   129,
     130,   131,    -1,   133,    -1,    -1,    -1,   137,   138,   139,
     140,   141,    -1,    -1,    -1,    -1,    -1,    -1,   148,   149,
     150,    -1,   152,   153,   154,    -1,    -1,    -1,    -1,    -1,
      -1,   161,   162,    -1,    -1,    -1,   166,   167,   168,   169,
     170,   171,   172,   173,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   181,   182,   183,    -1,    -1,    -1,   187,   188,   189,
     190,   191,    -1,    -1,    -1,    -1,    -1,    -1,   198,    -1,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,    -1,    -1,   213,   214,    -1,    -1,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,    -1,   265,   266,   267,    -1,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,    -1,    -1,    16,    -1,
     320,   321,   322,   323,   324,   325,   326,    25,    26,    -1,
      -1,    -1,    -1,    -1,    -1,    33,    34,    -1,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    -1,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    -1,    95,    96,    97,
      98,    -1,    -1,   101,   102,   103,    -1,    -1,   106,   107,
      -1,    -1,    -1,    -1,   112,   113,   114,   115,   116,   117,
     118,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     128,   129,   130,   131,    -1,   133,    -1,    -1,    -1,   137,
     138,   139,   140,   141,    -1,    -1,    -1,    -1,    -1,    -1,
     148,   149,   150,    -1,   152,   153,   154,    -1,    -1,    -1,
      -1,    -1,    -1,   161,   162,    -1,    -1,    -1,   166,   167,
     168,   169,   170,   171,   172,   173,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   181,   182,   183,    -1,    -1,    -1,   187,
     188,   189,   190,   191,    -1,    -1,    -1,    -1,   196,    -1,
     198,    -1,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,    -1,    -1,   213,   214,    -1,    -1,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,    -1,   265,   266,   267,
      -1,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,    -1,    -1,
      16,    -1,   320,   321,   322,   323,   324,   325,   326,    25,
      26,    -1,    -1,    -1,    -1,    -1,    -1,    33,    34,    -1,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    -1,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    -1,    95,
      96,    97,    98,    -1,    -1,   101,   102,   103,    -1,    -1,
     106,   107,    -1,    -1,    -1,    -1,   112,   113,   114,   115,
     116,   117,   118,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   128,   129,   130,   131,    -1,   133,    -1,    -1,
      -1,   137,   138,   139,   140,   141,    -1,    -1,    -1,    -1,
      -1,    -1,   148,   149,   150,    -1,   152,   153,   154,    -1,
      -1,    -1,   158,    -1,    -1,   161,   162,    -1,    -1,    -1,
     166,   167,   168,   169,   170,   171,   172,   173,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   181,   182,   183,    -1,    -1,
      -1,   187,   188,   189,   190,   191,    -1,    -1,    -1,    -1,
      -1,    -1,   198,    -1,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,    -1,    -1,   213,   214,    -1,
      -1,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,    -1,   265,
     266,   267,    -1,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
      -1,    -1,    16,    -1,   320,   321,   322,   323,   324,   325,
     326,    25,    26,    -1,    -1,    -1,    -1,    -1,    -1,    33,
      34,    -1,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    -1,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      -1,    95,    96,    97,    98,    -1,    -1,   101,   102,   103,
      -1,    -1,   106,   107,    -1,    -1,    -1,    -1,   112,   113,
     114,   115,   116,   117,   118,   119,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   128,   129,   130,   131,    -1,   133,
      -1,    -1,    -1,   137,   138,   139,   140,   141,    -1,    -1,
      -1,    -1,    -1,    -1,   148,   149,   150,    -1,   152,   153,
     154,    -1,    -1,    -1,   158,    -1,    -1,   161,   162,    -1,
      -1,    -1,   166,   167,   168,   169,   170,   171,   172,   173,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   181,   182,   183,
      -1,    -1,    -1,   187,    -1,   189,   190,   191,    -1,    -1,
      -1,    -1,    -1,    -1,   198,    -1,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,    -1,    -1,   213,
     214,    -1,    -1,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   263,
      -1,   265,   266,   267,    -1,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,    -1,    -1,    16,    -1,   320,   321,   322,   323,
     324,   325,   326,    25,    26,    -1,    -1,    -1,    -1,    -1,
      -1,    33,    34,    -1,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    -1,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    -1,    95,    96,    97,    98,    -1,    -1,   101,
     102,   103,    -1,    -1,   106,   107,    -1,    -1,    -1,    -1,
     112,   113,   114,   115,   116,   117,   118,   119,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   128,   129,   130,   131,
      -1,   133,    -1,    -1,    -1,   137,   138,   139,   140,   141,
      -1,    -1,    -1,    -1,    -1,    -1,   148,   149,   150,    -1,
     152,   153,   154,    -1,    -1,    -1,   158,    -1,    -1,   161,
     162,    -1,    -1,    -1,   166,   167,   168,   169,   170,   171,
     172,   173,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   181,
     182,   183,    -1,    -1,    -1,   187,    -1,   189,   190,   191,
      -1,    -1,    -1,    -1,    -1,    -1,   198,    -1,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,    -1,
      -1,   213,   214,    -1,    -1,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,    -1,   265,   266,   267,    -1,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,    -1,    -1,    16,    -1,   320,   321,
     322,   323,   324,   325,   326,    25,    26,    -1,    -1,    -1,
      -1,    -1,    -1,    33,    34,    -1,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    -1,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    -1,    95,    96,    97,    98,    -1,
      -1,   101,   102,   103,    -1,    -1,   106,   107,    -1,    -1,
      -1,    -1,   112,   113,   114,   115,   116,   117,   118,   119,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   128,   129,
     130,   131,    -1,   133,    -1,    -1,    -1,   137,   138,   139,
     140,   141,    -1,    -1,    -1,    -1,    -1,    -1,   148,   149,
     150,    -1,   152,   153,   154,    -1,    -1,    -1,   158,    -1,
      -1,   161,   162,    -1,    -1,    -1,   166,   167,   168,   169,
     170,   171,   172,   173,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   181,   182,   183,    -1,    -1,    -1,   187,    -1,   189,
     190,   191,    -1,    -1,    -1,    -1,    -1,    -1,   198,    -1,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,    -1,    -1,   213,   214,    -1,    -1,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,    -1,   265,   266,   267,    -1,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,    -1,    -1,    16,    -1,
     320,   321,   322,   323,   324,   325,   326,    25,    26,    -1,
      -1,    -1,    -1,    -1,    -1,    33,    34,    -1,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    -1,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    -1,    95,    96,    97,
      98,    -1,    -1,   101,   102,   103,    -1,    -1,   106,   107,
      -1,    -1,    -1,    -1,   112,   113,   114,   115,   116,   117,
     118,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     128,   129,   130,   131,    -1,   133,    -1,    -1,    -1,   137,
     138,   139,   140,   141,    -1,    -1,    -1,    -1,    -1,    -1,
     148,   149,   150,    -1,   152,   153,   154,    -1,    -1,    -1,
     158,    -1,    -1,   161,   162,    -1,    -1,    -1,   166,   167,
     168,   169,   170,   171,   172,   173,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   181,   182,   183,    -1,    -1,    -1,   187,
      -1,   189,   190,   191,    -1,    -1,    -1,    -1,    -1,    -1,
     198,    -1,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,    -1,    -1,   213,   214,    -1,    -1,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,    -1,   265,   266,   267,
      -1,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,    -1,    -1,
      16,    -1,   320,   321,   322,   323,   324,   325,   326,    25,
      26,    -1,    -1,    -1,    -1,    -1,    -1,    33,    34,    -1,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    -1,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    -1,    95,
      96,    97,    98,    -1,    -1,   101,   102,   103,    -1,    -1,
     106,   107,    -1,    -1,    -1,    -1,   112,   113,   114,   115,
     116,   117,   118,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   128,   129,   130,   131,    -1,   133,    -1,    -1,
      -1,   137,   138,   139,   140,   141,    -1,    -1,    -1,    -1,
      -1,    -1,   148,   149,   150,    -1,   152,   153,   154,    -1,
      -1,    -1,   158,    -1,    -1,   161,   162,    -1,    -1,    -1,
     166,   167,   168,   169,   170,   171,   172,   173,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   181,   182,   183,    -1,    -1,
      -1,   187,    -1,   189,   190,   191,    -1,    -1,    -1,    -1,
      -1,    -1,   198,    -1,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,    -1,    -1,   213,   214,    -1,
      -1,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,    -1,   265,
     266,   267,    -1,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
      -1,    -1,    16,    -1,   320,   321,   322,   323,   324,   325,
     326,    25,    26,    -1,    -1,    -1,    -1,    -1,    -1,    33,
      34,    -1,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    -1,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      -1,    95,    96,    97,    98,    -1,    -1,   101,   102,   103,
      -1,    -1,   106,   107,    -1,    -1,    -1,    -1,   112,   113,
     114,   115,   116,   117,   118,   119,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   128,   129,   130,   131,    -1,   133,
      -1,    -1,    -1,   137,   138,   139,   140,   141,    -1,    -1,
      -1,    -1,    -1,    -1,   148,   149,   150,    -1,   152,   153,
     154,    -1,    -1,    -1,    -1,    -1,    -1,   161,   162,    -1,
      -1,    -1,   166,   167,   168,   169,   170,   171,   172,   173,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   181,   182,   183,
      -1,    -1,    -1,   187,    -1,   189,   190,   191,    -1,    -1,
      -1,    -1,    -1,    -1,   198,    -1,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,    -1,    -1,   213,
     214,    -1,    -1,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   263,
      -1,   265,   266,   267,    -1,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,    -1,    -1,    16,    -1,   320,   321,   322,   323,
     324,   325,   326,    25,    26,    -1,    -1,    -1,    -1,    -1,
      -1,    33,    34,    -1,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    -1,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    -1,    95,    96,    97,    98,    -1,    -1,   101,
     102,   103,    -1,    -1,   106,   107,    -1,    -1,    -1,    -1,
     112,   113,   114,   115,   116,   117,   118,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   128,   129,   130,   131,
      -1,   133,    -1,    -1,    -1,   137,   138,   139,   140,   141,
      -1,    -1,    -1,    -1,    -1,    -1,   148,   149,   150,    -1,
     152,   153,   154,    -1,    -1,    -1,    -1,    -1,    -1,   161,
     162,    -1,    -1,    -1,   166,   167,   168,   169,   170,   171,
     172,   173,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   181,
     182,   183,    -1,    -1,    -1,   187,    -1,   189,   190,   191,
      -1,    -1,    -1,    -1,    -1,    -1,   198,    -1,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,    -1,
      -1,   213,   214,    -1,    -1,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,    -1,   265,   266,   267,    -1,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,    -1,    -1,    -1,    -1,   320,   321,
     322,   323,   324,   325,   326,    21,    22,    23,    24,    25,
      26,    -1,    -1,    -1,    30,    -1,    -1,    33,    34,    -1,
      36,    37,    38,    39,    40,    41,    42,    43,    -1,    45,
      46,    47,    -1,    49,    50,    51,    52,    -1,    54,    -1,
      56,    57,    58,    59,    60,    61,    -1,    -1,    64,    65,
      66,    67,    68,    -1,    70,    71,    72,    -1,    -1,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    -1,    95,
      96,    97,    98,    -1,    -1,   101,   102,   103,    -1,    -1,
     106,   107,    -1,    -1,    -1,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,    -1,    -1,    -1,    -1,    -1,
     126,    -1,   128,   129,   130,   131,    -1,   133,    -1,    -1,
      -1,   137,   138,   139,   140,   141,    -1,    -1,    -1,    -1,
      -1,    -1,   148,   149,   150,   151,   152,   153,    -1,   155,
     156,    -1,   158,   159,    -1,   161,   162,    -1,    -1,    -1,
     166,   167,   168,   169,   170,   171,   172,   173,    -1,   175,
      -1,    -1,    -1,    -1,    -1,   181,   182,   183,    -1,    -1,
      -1,   187,    -1,   189,   190,   191,    -1,    -1,    -1,    -1,
      -1,    -1,   198,    -1,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,    -1,    -1,    -1,   214,   215,
      -1,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,    -1,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,    -1,   265,
     266,   267,    -1,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,    -1,   318,    -1,    -1,   321,   322,    21,    22,    23,
      24,    25,    26,    -1,    -1,    -1,    30,    -1,    -1,    33,
      34,    -1,    36,    37,    38,    39,    40,    41,    42,    43,
      -1,    45,    46,    47,    -1,    49,    50,    51,    52,    -1,
      54,    -1,    56,    57,    58,    59,    60,    61,    -1,    -1,
      64,    65,    66,    67,    68,    -1,    70,    71,    72,    -1,
      -1,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      -1,    95,    96,    97,    98,    -1,    -1,   101,   102,   103,
      -1,    -1,   106,   107,    -1,    -1,    -1,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,    -1,    -1,    -1,
      -1,    -1,   126,    -1,   128,   129,   130,   131,    -1,   133,
      -1,    -1,    -1,   137,   138,   139,   140,   141,    -1,    -1,
      -1,    -1,    -1,    -1,   148,   149,   150,   151,   152,   153,
      -1,   155,   156,    -1,   158,   159,    -1,   161,   162,    -1,
      -1,    -1,   166,   167,   168,   169,   170,   171,   172,   173,
      -1,   175,    -1,    -1,    -1,    -1,    -1,   181,   182,   183,
      -1,    -1,    -1,   187,    -1,   189,   190,   191,    -1,    -1,
      -1,    -1,    -1,    -1,   198,    -1,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,    -1,    -1,    -1,
     214,   215,    -1,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,    -1,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,    -1,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   263,
      -1,   265,   266,   267,    -1,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,    -1,   318,    -1,    -1,   321,   322,    21,
      22,    23,    24,    25,    26,    -1,    -1,    -1,    30,    -1,
      -1,    33,    34,    -1,    36,    37,    38,    39,    40,    41,
      -1,    43,    -1,    45,    -1,    47,    -1,    49,    -1,    -1,
      52,    -1,    54,    -1,    -1,    57,    58,    59,    60,    61,
      -1,    -1,    64,    65,    66,    67,    68,    -1,    -1,    71,
      72,    -1,    -1,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    -1,    -1,    -1,    -1,    97,    98,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   106,    -1,    -1,    -1,    -1,   111,
     112,   113,   114,   115,   116,   117,    -1,   119,   120,    -1,
      -1,    -1,    -1,    -1,   126,    -1,   128,   129,   130,   131,
      -1,   133,    -1,    -1,    -1,   137,    -1,   139,   140,   141,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   149,   150,   151,
      -1,   153,    -1,   155,    -1,    -1,    -1,   159,    -1,    -1,
     162,    -1,    -1,    -1,   166,   167,   168,   169,   170,   171,
     172,   173,    -1,   175,    -1,    -1,    -1,    -1,    -1,   181,
     182,   183,    -1,    -1,    -1,   187,    -1,   189,   190,   191,
      -1,    -1,    -1,    -1,    -1,    -1,   198,    -1,   200,    -1,
     202,    -1,   204,   205,   206,   207,   208,   209,   210,    -1,
      -1,    -1,   214,   215,    -1,   217,   218,   219,   220,   221,
     222,   223,    -1,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,    -1,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,    -1,    -1,   265,   266,   267,    -1,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,    -1,   318,    -1,   320,   321,
     322,    21,    22,    23,    24,    25,    26,    -1,    -1,    -1,
      30,    -1,    -1,    33,    34,    -1,    36,    37,    38,    39,
      40,    41,    -1,    43,    -1,    45,    -1,    47,    -1,    49,
      -1,    -1,    52,    -1,    54,    -1,    -1,    57,    58,    59,
      60,    61,    -1,    -1,    64,    65,    66,    67,    68,    -1,
      -1,    71,    72,    -1,    -1,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    -1,    -1,    -1,    -1,    97,    98,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   106,    -1,    -1,    -1,
      -1,   111,   112,   113,    -1,   115,   116,    -1,    -1,   119,
     120,    -1,    -1,    -1,    -1,    -1,   126,    -1,    -1,    -1,
     130,   131,    -1,   133,    -1,    -1,    -1,   137,    -1,   139,
     140,   141,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   149,
     150,   151,    -1,    -1,    -1,   155,    -1,    -1,    -1,   159,
      -1,    -1,   162,    -1,    -1,    -1,   166,   167,    -1,    -1,
     170,   171,    -1,   173,    -1,   175,    -1,    -1,    -1,    -1,
      -1,   181,   182,   183,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   191,    -1,    -1,    -1,    -1,    -1,    -1,   198,    -1,
     200,    -1,    -1,    -1,   204,   205,   206,   207,   208,   209,
     210,    -1,    -1,    -1,    -1,   215,    -1,   217,   218,   219,
      -1,   221,   222,   223,    -1,    -1,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,    -1,
     240,   241,   242,   243,   244,   245,   246,   247,   248,    -1,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,    -1,    -1,   265,   266,   267,    -1,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,    -1,   318,    -1,
     320,   321,   322,    25,    26,    -1,    -1,    -1,    -1,    -1,
      -1,    33,    34,    -1,    36,    37,    38,    -1,    40,    41,
      42,    43,    -1,    -1,    46,    47,    -1,    49,    50,    51,
      52,    -1,    54,    -1,    56,    57,    58,    59,    -1,    61,
      -1,    -1,    64,    65,    66,    67,    68,    -1,    70,    -1,
      72,    -1,    -1,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    -1,    95,    96,    97,    -1,    -1,    -1,   101,
     102,   103,    -1,    -1,   106,   107,    -1,    -1,    -1,    -1,
     112,   113,   114,   115,   116,   117,   118,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   128,   129,   130,   131,
      -1,   133,    -1,    -1,    -1,   137,   138,   139,   140,   141,
      -1,    -1,    -1,    -1,    -1,    -1,   148,   149,   150,    -1,
     152,   153,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   161,
     162,    -1,    -1,    -1,   166,   167,   168,   169,   170,   171,
     172,   173,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   181,
     182,   183,    -1,    -1,    -1,   187,    -1,   189,   190,   191,
      -1,    -1,    -1,    -1,    -1,    -1,   198,    -1,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,    -1,
      -1,    -1,   214,    -1,    -1,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,    -1,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,    -1,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,    -1,   265,   266,   267,    -1,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,    -1,    -1,    -1,    -1,    -1,   321,
     322
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned short int
  jsoniq_parser::yystos_[] =
  {
         0,    11,    12,    16,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    30,    33,    34,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    95,    96,    97,    98,    99,   101,   102,   103,
     106,   107,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   122,   126,   128,   129,   130,   131,   133,   137,
     138,   139,   140,   141,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   158,   159,   160,   161,   162,   166,   167,
     168,   169,   170,   171,   172,   173,   175,   177,   178,   181,
     182,   183,   187,   189,   190,   191,   192,   193,   194,   196,
     198,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   213,   214,   215,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,   265,   266,   267,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,   318,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   341,   343,   344,   345,   346,   347,   348,
     349,   350,   351,   352,   353,   354,   355,   356,   357,   358,
     359,   362,   363,   364,   365,   366,   367,   371,   372,   373,
     377,   379,   380,   382,   389,   391,   394,   395,   396,   398,
     399,   400,   401,   402,   404,   405,   407,   408,   409,   410,
     411,   412,   414,   415,   418,   419,   420,   421,   422,   428,
     430,   432,   433,   434,   439,   458,   461,   465,   468,   469,
     475,   476,   477,   478,   479,   481,   482,   484,   485,   486,
     487,   488,   489,   490,   491,   492,   494,   495,   496,   497,
     500,   501,   502,   503,   504,   505,   506,   507,   508,   509,
     510,   511,   512,   513,   514,   515,   516,   517,   520,   521,
     522,   523,   524,   525,   526,   527,   528,   530,   531,   532,
     533,   534,   535,   549,   550,   552,   553,   554,   555,   556,
     557,   558,   559,   567,   568,   569,   570,   571,   572,   573,
     574,   575,   576,   577,   578,   581,   586,   587,   588,   589,
     590,   591,   594,   652,   653,   654,   655,   657,   658,   659,
     660,   661,   664,   665,   666,    33,    34,    49,   218,   397,
     398,   399,   397,   397,   398,   399,   158,   158,    37,    38,
      40,    41,    47,    57,    58,    75,    80,   112,   113,   114,
     162,   226,   267,   293,   301,   309,   378,   379,   383,   384,
     385,   162,   155,   158,   155,   158,   155,   158,     1,   158,
     386,   158,    25,    34,    61,   119,   279,   438,   440,   441,
     158,   155,   158,   158,   158,   119,   155,   158,   158,   158,
      77,   155,   227,   228,   124,   124,   124,   155,   158,    39,
      43,    45,    46,    47,    48,    51,    60,    68,    71,    73,
      74,    76,    91,    92,    98,   106,   113,   115,   116,   137,
     140,   141,   162,   170,   173,   181,   182,   191,   204,   230,
     232,   234,   235,   242,   244,   245,   246,   249,   250,   263,
     266,   321,   514,   665,   124,   119,   406,   124,   124,    39,
      44,    45,    53,    60,    62,    63,    71,    98,   231,   664,
     119,   124,   124,   397,   399,   420,   656,   664,    48,    73,
      74,   119,   155,   186,   250,   419,   421,   432,   188,   419,
     664,   155,   155,   124,   664,    18,    19,   664,   124,   124,
     124,   506,   155,    31,   216,   219,    39,    45,    60,    71,
      98,   231,   233,   320,   517,   665,   231,   233,   320,   420,
     656,   231,   320,   517,   231,   236,   320,   119,   247,   247,
     248,   158,   155,   401,     1,   478,   317,   419,   319,   419,
     320,   420,   328,   343,   343,     0,   345,   346,    33,    49,
     348,   365,     1,   192,   342,   192,   342,   113,   380,   400,
     419,   108,   192,   108,   342,   192,    42,    46,    51,    70,
     169,   172,   187,   190,   214,   263,   413,   423,   424,   429,
     430,   431,   446,   447,   451,     3,    67,    72,   119,   425,
     168,    93,   134,   142,   143,   145,   153,   157,   159,   164,
     180,   205,   206,   207,   208,   209,   210,   498,   499,   255,
     100,   160,   177,   201,   118,   148,   161,   196,   203,   212,
     138,   152,    50,   202,   102,   103,   160,   177,   496,   195,
     155,   503,   506,   193,   194,   156,   518,   519,   514,   518,
     514,   121,   156,   158,   518,   158,   147,   158,   185,   185,
     185,   185,   381,   521,   381,    30,   663,   183,   198,   183,
     198,   167,   183,   665,   664,   170,   204,    47,   664,   154,
     119,    45,    47,    80,   107,   169,   664,   227,   228,   229,
     252,   625,   664,   664,   310,   139,   144,   113,   293,   301,
     383,   664,   398,   188,   398,    45,    63,   188,   577,   578,
     419,   188,   196,   664,   435,   436,   664,   119,   188,   387,
     388,   155,   403,   419,     1,   162,   663,   114,   162,   361,
     663,   664,   119,   144,   108,   188,   419,    30,   188,   664,
     664,   664,   459,   460,   664,   398,   188,   419,   419,   579,
     664,   398,   155,   155,   419,   188,   196,   664,   664,   144,
     459,   185,   185,   123,   108,   185,   123,   158,   158,   158,
     664,   155,   186,   424,   188,    35,   537,   538,   539,   419,
     419,     8,   176,    17,   419,   216,    30,   420,   420,   517,
     420,   420,   420,   656,   239,   239,   420,   517,    95,   420,
     237,   236,   592,   593,   664,   192,   192,   420,   419,   399,
     419,   251,   416,   417,   435,   317,   319,   420,   239,   343,
     192,   342,   192,   342,     3,   349,   365,   395,     1,   349,
     365,   395,    33,   366,   395,   366,   395,   406,   342,   406,
     420,   420,   119,   169,   171,   171,   420,   400,   420,   290,
     290,   435,   119,   442,   477,   478,   481,   481,   481,   481,
     480,   481,   481,   481,    71,   482,   486,   486,   485,   487,
     487,   487,   487,   488,   488,   489,   489,   237,    95,    95,
      95,   504,   397,   506,   506,   419,   519,   158,   523,   581,
     664,   186,   146,   188,   420,   529,   188,   151,   188,   529,
     108,   188,   188,   108,   108,   386,    30,   665,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,   368,   369,
     370,    95,   139,   144,   374,   375,   376,   664,   162,   162,
     368,   663,   129,   134,    55,    57,   101,   257,   270,   272,
     283,   284,   285,   287,   289,   626,   627,   628,   629,   630,
     631,   638,   644,   645,   252,    95,   305,   664,   144,   420,
     119,   664,   664,   134,   185,   185,   188,   188,   185,   108,
     188,   108,   188,   108,    36,    95,    97,   149,   437,   438,
     560,   664,    95,   108,   188,   397,   188,   664,    97,    45,
     664,   663,    97,   144,   560,   664,   420,   441,   185,   188,
     188,   188,   188,   108,   189,   149,   560,   185,   188,   188,
     155,   185,   398,   398,   185,   108,   188,   108,   188,   144,
     560,   420,   189,   420,   420,   664,   420,   419,   419,   419,
     664,   538,   539,   132,   199,   185,   185,   185,   133,   192,
      95,   224,   225,   239,    95,   224,   225,   239,   239,   239,
     420,   420,    95,    95,   420,   243,   231,   517,   237,   108,
     241,   144,   192,   188,   419,   185,   515,   598,   417,   239,
     420,   365,    33,    33,   192,   342,   192,   114,   400,   664,
     171,   420,   452,   453,   119,   420,   448,   449,   664,    56,
     220,   260,   426,   427,   481,   155,   158,   265,   502,   521,
     599,   602,   603,   604,   605,   606,   610,   612,   614,   615,
      47,   154,   158,   213,   323,   324,   325,   326,   561,   563,
     565,   567,   582,   583,   584,   585,   662,   664,   561,   493,
     566,   664,   493,   185,   186,   188,   419,   108,   188,   188,
     521,   150,   166,   150,   166,   139,   403,   386,   369,   134,
     158,   563,   376,   420,   560,   663,   663,   130,   131,   663,
     283,   284,   285,   289,   664,   269,   280,   269,   280,    30,
     292,    97,   114,   158,   632,   635,   626,    39,    44,    53,
      60,    62,    71,    98,   231,   323,   324,   325,   390,   567,
     662,   233,   305,   314,   420,   664,    95,   305,   663,   155,
     579,   580,   664,   579,   580,   119,   436,   129,   561,   119,
     420,   149,   438,   149,    36,   149,   437,   438,   560,   561,
     388,    95,   185,   200,   134,   360,   663,   162,   134,    97,
     360,   420,   144,   438,   155,   119,   420,   420,   149,   101,
     462,   463,   464,   466,   467,   101,   470,   471,   472,   473,
     398,   185,   185,   155,   579,   579,   420,   144,   192,   420,
     123,   123,   188,   188,   188,    35,   539,   132,   199,     9,
      10,   104,   125,   127,   155,   197,   534,   536,   547,   548,
     551,   155,    30,   238,   240,   420,   420,   420,   238,   240,
     420,   420,   420,   420,   420,    97,   420,   420,   420,   420,
     243,   517,   119,   420,   420,    48,    73,    74,   250,   400,
     421,   432,   251,   595,   596,   155,   212,   401,   420,   192,
     114,   395,   395,   395,   452,    96,   107,   117,   129,   454,
     455,   456,   457,   108,   664,   107,   450,   108,   149,   560,
     260,    54,    59,    78,   119,   437,   443,   444,   445,   427,
     419,   599,   606,   155,   291,   483,   651,    97,   170,   258,
     259,   261,   268,   278,   290,   600,   601,   620,   621,   622,
     623,   646,   649,   264,   266,   607,   625,   273,   611,   647,
     253,   254,   276,   616,   617,   158,   158,   188,   563,   158,
     158,   158,   158,   158,   146,   177,   196,   562,   146,   188,
     146,   420,   139,   403,   581,   375,   292,    30,    97,   114,
     158,   639,    30,   632,   562,   562,   504,   293,   312,   560,
     390,   233,   192,   397,   188,   188,   146,   188,   188,   436,
     149,   437,   664,   420,   149,   420,   129,   420,   149,   438,
     149,   561,   400,   420,   663,   108,   360,   420,   144,   397,
     460,   420,   420,   114,   463,   464,   101,   424,   114,   464,
     467,   119,   474,   561,   101,   114,   471,   101,   114,   473,
     185,   397,   188,   188,   420,   420,   420,   200,   470,   134,
     197,   536,     7,   398,   664,   197,   547,   398,   192,   239,
     239,   239,   239,    97,   322,   243,   420,   243,   593,   424,
     158,   158,   158,   424,   598,   596,   515,   663,   130,   131,
     456,   457,   457,   453,   144,   560,   663,   449,   420,   149,
     119,   119,   420,   664,   445,    78,   185,   188,   599,   613,
     256,   220,   260,   274,   281,   650,    97,   262,   263,   648,
     256,   603,   650,   485,   620,   604,   149,   288,   608,   609,
     648,   292,   619,    79,   618,   188,   196,   561,   564,   188,
     188,   188,   188,   188,   188,   188,    30,   138,   203,   641,
     642,   643,    30,   640,   641,   277,   636,   108,   633,   171,
     664,   263,   504,   185,   420,   149,   420,   149,   437,   420,
     149,   420,   128,   128,    97,   663,   420,   185,   424,   424,
     420,   400,   420,   424,   424,   664,   212,   424,   119,   474,
     119,   424,   119,   474,   424,   185,   114,   539,   664,   197,
     185,   539,   664,   185,   420,   420,   420,   420,   322,   420,
     420,   420,   420,   419,   419,   419,   155,   597,   457,   420,
     144,   420,   664,   664,   444,   420,   185,   487,    52,   131,
     485,   485,   275,   282,   292,   624,   624,   605,   155,   286,
      95,   188,   108,   188,   639,   639,   643,   108,   188,    30,
     637,   648,   634,   635,   188,   392,   393,   504,   119,   231,
     313,   293,   171,   420,   420,   149,   420,   400,   420,   360,
     420,   400,    95,   561,   400,   420,   664,   424,   664,   420,
     664,   424,   400,   119,    94,   184,   540,   539,   664,   199,
     539,   420,   188,   188,   188,   419,   450,   420,    54,   485,
     485,   201,   419,   561,   561,    95,    30,   271,   108,   108,
     457,   560,   664,   119,   231,   664,   392,   420,   474,    95,
     424,    95,   664,     5,   135,   543,   544,   546,   548,    29,
     136,   541,   542,   545,   548,   199,   539,   199,   200,   470,
     185,   450,   119,   485,   185,   561,   635,   393,   457,   311,
     664,   119,   231,   424,   474,   400,   420,   474,   424,    94,
     135,   546,   184,   136,   545,   199,   114,   664,   420,   311,
     664,   119,   400,   420,   424,   424,   119,   299,   311,   664,
     664,   312,   420,   312,   424,   504,   504,   201,   293,   664,
     231,   119,   664,   312,   504
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
     585,   586,   587,   588,   589,   590,   591,   592,   593,   594
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned short int
  jsoniq_parser::yyr1_[] =
  {
         0,   340,   341,   341,   341,   341,   342,   342,   342,   343,
     343,   343,   343,   344,   344,   345,   345,   345,   345,   345,
     345,   345,   345,   346,   346,   346,   346,   347,   348,   348,
     348,   349,   349,   349,   349,   349,   350,   350,   350,   350,
     350,   350,   350,   350,   351,   351,   352,   353,   354,   354,
     355,   355,   356,   356,   357,   357,   357,   357,   358,   358,
     358,   359,   359,   359,   359,   360,   360,   361,   361,   362,
     362,   362,   362,   363,   364,   364,   365,   365,   365,   366,
     366,   366,   366,   366,   366,   366,   366,   367,   367,   368,
     368,   369,   370,   370,   370,   370,   370,   370,   370,   370,
     370,   370,   371,   372,   373,   374,   374,   375,   375,   375,
     376,   377,   377,   377,   378,   378,   378,   378,   379,   379,
     380,   380,   380,   380,   381,   381,   382,   382,   383,   383,
     384,   384,   385,   385,   386,   386,   386,   386,   387,   387,
     388,   388,   389,   389,   389,   389,   390,   390,   390,   390,
     391,   391,   392,   392,   393,   393,   393,   393,   394,   394,
     394,   394,   395,   396,   396,   396,   397,   397,   397,   398,
     398,   399,   399,   399,   400,   400,   400,   400,   400,   400,
     400,   400,   400,   400,   400,   400,   400,   401,   402,   403,
     404,   405,   405,   405,   406,   406,   406,   406,   407,   408,
     409,   410,   411,   411,   412,   413,   414,   415,   416,   416,
     417,   418,   419,   419,   419,   420,   420,   420,   420,   420,
     420,   421,   421,   421,   421,   421,   421,   421,   421,   421,
     421,   421,   421,   422,   423,   424,   424,   425,   425,   426,
     426,   426,   427,   427,   428,   428,   429,   430,   430,   430,
     431,   431,   431,   431,   431,   432,   432,   433,   433,   433,
     433,   434,   434,   435,   435,   435,   436,   436,   436,   436,
     436,   436,   436,   436,   436,   436,   436,   436,   437,   438,
     439,   440,   440,   441,   441,   441,   441,   442,   442,   443,
     443,   443,   444,   444,   444,   445,   445,   445,   446,   447,
     448,   448,   449,   449,   449,   449,   449,   449,   450,   451,
     451,   452,   452,   453,   453,   454,   454,   454,   454,   454,
     454,   454,   455,   455,   456,   456,   457,   458,   458,   459,
     459,   460,   460,   461,   462,   462,   463,   464,   464,   465,
     466,   466,   467,   468,   468,   469,   469,   470,   470,   471,
     471,   472,   472,   473,   473,   474,   474,   475,   476,   476,
     477,   477,   478,   478,   479,   479,   479,   479,   479,   480,
     479,   479,   479,   479,   481,   481,   482,   482,   483,   483,
     484,   484,   485,   485,   485,   486,   486,   486,   486,   486,
     487,   487,   487,   488,   488,   488,   489,   489,   490,   490,
     491,   491,   492,   492,   493,   493,   494,   494,   495,   495,
     495,   495,   496,   496,   496,   497,   497,   498,   498,   498,
     498,   498,   498,   499,   499,   499,   500,   500,   500,   500,
     501,   502,   502,   503,   503,   503,   504,   504,   504,   504,
     505,   506,   506,   506,   507,   507,   508,   508,   508,   508,
     509,   509,   510,   510,   510,   510,   510,   510,   510,   511,
     511,   512,   512,   513,   513,   513,   513,   513,   514,   514,
     515,   515,   516,   516,   516,   516,   517,   517,   517,   517,
     517,   517,   517,   517,   517,   517,   518,   518,   519,   520,
     520,   520,   520,   520,   520,   520,   520,   520,   520,   520,
     520,   520,   520,   521,   521,   522,   522,   522,   523,   524,
     524,   525,   526,   527,   528,   528,   529,   529,   529,   529,
     530,   530,   531,   532,   533,   533,   534,   534,   534,   535,
     535,   535,   535,   535,   535,   536,   536,   537,   537,   538,
     539,   539,   540,   540,   541,   541,   542,   542,   542,   542,
     543,   543,   544,   544,   544,   544,   545,   545,   546,   546,
     547,   547,   547,   547,   548,   548,   548,   548,   549,   549,
     550,   550,   551,   552,   552,   552,   552,   552,   552,   552,
     553,   554,   554,   555,   555,   556,   557,   558,   558,   559,
     559,   560,   561,   561,   561,   561,   562,   562,   562,   563,
     563,   563,   563,   563,   563,   563,   564,   564,   565,   566,
     567,   567,   567,   567,   567,   567,   567,   567,   567,   567,
     568,   569,   570,   570,   570,   571,   572,   573,   574,   574,
     574,   575,   575,   575,   575,   575,   576,   577,   577,   577,
     577,   577,   577,   577,   578,   579,   580,   581,   582,   582,
     583,   584,   584,   585,   586,   586,   586,   587,   587,   587,
     587,   587,   587,   587,   587,   587,   587,   588,   588,   589,
     589,   590,   591,   592,   592,   593,   594,   595,   595,   596,
     597,   598,   598,   599,   600,   600,   601,   601,   602,   602,
     603,   603,   604,   604,   605,   605,   606,   607,   607,   608,
     608,   609,   610,   610,   610,   611,   611,   612,   613,   613,
     614,   615,   615,   616,   616,   617,   617,   617,   618,   618,
     619,   619,   620,   620,   620,   620,   620,   621,   622,   623,
     624,   624,   624,   625,   625,   626,   626,   626,   626,   626,
     626,   626,   626,   627,   627,   627,   627,   628,   628,   629,
     630,   630,   631,   631,   631,   632,   632,   633,   633,   634,
     634,   635,   636,   636,   637,   637,   638,   638,   638,   639,
     639,   640,   640,   641,   641,   642,   642,   643,   643,   644,
     645,   645,   646,   646,   646,   647,   648,   648,   648,   648,
     649,   649,   650,   650,   651,   652,   652,   653,   653,   654,
     654,   655,   656,   656,   656,   656,   657,   657,   657,   657,
     657,   657,   658,   658,   659,   659,   660,   660,   661,   661,
     662,   662,   662,   663,   664,   664,   664,   664,   664,   664,
     664,   664,   664,   664,   664,   664,   664,   664,   664,   664,
     664,   664,   664,   664,   664,   664,   664,   665,   665,   665,
     665,   665,   665,   665,   665,   665,   665,   665,   665,   665,
     665,   665,   665,   665,   665,   665,   665,   665,   665,   665,
     665,   665,   665,   665,   665,   665,   665,   665,   665,   665,
     665,   665,   665,   665,   665,   665,   665,   665,   665,   665,
     665,   665,   665,   665,   665,   665,   665,   665,   665,   665,
     665,   665,   665,   665,   665,   665,   665,   665,   665,   665,
     665,   665,   665,   665,   665,   665,   665,   665,   665,   665,
     665,   665,   665,   665,   665,   665,   665,   665,   665,   665,
     665,   665,   665,   665,   665,   665,   665,   665,   665,   665,
     665,   665,   665,   665,   665,   665,   665,   665,   665,   665,
     665,   665,   665,   665,   665,   665,   665,   665,   665,   665,
     665,   665,   665,   665,   665,   665,   665,   665,   665,   665,
     665,   665,   665,   665,   665,   665,   665,   665,   665,   665,
     665,   665,   665,   665,   665,   665,   665,   665,   665,   665,
     665,   665,   665,   665,   665,   665,   665,   665,   665,   665,
     665,   665,   665,   665,   665,   665,   665,   665,   665,   665,
     665,   665,   665,   665,   665,   665,   665,   665,   665,   665,
     665,   665,   665,   665,   665,   665,   665,   665,   665,   665,
     665,   665,   665,   665,   665,   665,   665,   665,   665,   665,
     665,   665,   665,   665,   665,   665,   665,   665,   665,   665,
     665,   665,   665,   666
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  jsoniq_parser::yyr2_[] =
  {
         0,     2,     1,     2,     2,     3,     1,     2,     2,     1,
       2,     1,     2,     4,     6,     3,     3,     5,     1,     3,
       3,     5,     5,     1,     3,     3,     5,     6,     1,     3,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     3,     4,     3,     3,     3,
       3,     3,     5,     5,     5,     5,     5,     5,     1,     1,
       3,     3,     4,     5,     6,     1,     3,     3,     3,     3,
       6,     5,     8,     5,     5,     5,     1,     3,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     4,     4,     1,
       2,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     4,     3,     4,     3,     1,     1,     1,     2,
       2,     4,     3,     5,     3,     4,     4,     5,     1,     2,
       1,     4,     1,     4,     1,     3,     2,     3,     1,     1,
       4,     4,     5,     5,     2,     3,     4,     5,     1,     3,
       2,     3,     3,     5,     4,     6,     1,     2,     1,     2,
       8,     9,     1,     3,     1,     2,     2,     3,    11,    14,
      13,    22,     1,     1,     1,     0,     1,     1,     0,     1,
       2,     1,     2,     4,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     3,     3,
       2,     3,     2,     3,     2,     3,     4,     5,     5,     2,
       4,     5,     3,     3,     2,     2,     8,     3,     1,     2,
       3,     1,     1,     3,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     2,     1,     1,     2,     2,     1,
       1,     2,     4,     3,     5,     4,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     3,     3,     3,
       2,     1,     1,     1,     4,     3,     3,     5,     4,     6,
       4,     6,     5,     7,     4,     5,     5,     6,     3,     3,
       2,     1,     3,     4,     5,     3,     6,     4,     5,     1,
       2,     3,     1,     2,     1,     6,     3,     3,     2,     3,
       1,     3,     4,     5,     6,     5,     1,     2,     2,     3,
       4,     1,     3,     1,     2,     1,     1,     1,     2,     2,
       2,     3,     1,     1,     2,     2,     2,     5,     5,     1,
       4,     3,     4,     8,     1,     2,     3,     2,     3,     8,
       1,     2,     3,     8,    10,     8,    10,     1,     2,     4,
       7,     1,     2,     4,     7,     1,     3,     8,     1,     3,
       1,     3,     1,     2,     1,     3,     3,     3,     3,     0,
       4,     3,     3,     3,     1,     5,     1,     3,     0,     1,
       1,     3,     1,     3,     3,     1,     3,     3,     3,     3,
       1,     3,     3,     1,     3,     3,     1,     4,     1,     4,
       1,     4,     1,     4,     1,     2,     1,     2,     1,     1,
       2,     2,     1,     1,     1,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     4,     5,     5,     6,
       4,     1,     2,     3,     2,     2,     1,     2,     2,     1,
       1,     1,     3,     3,     1,     1,     1,     2,     1,     2,
       2,     1,     2,     2,     2,     2,     2,     2,     2,     1,
       2,     2,     1,     2,     2,     2,     2,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     3,     4,
       3,     3,     4,     5,     3,     3,     1,     2,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     2,
       3,     1,     4,     4,     3,     4,     1,     3,     1,     3,
       1,     1,     3,     3,     1,     1,     1,     1,     1,     4,
       8,     5,     9,     9,    10,     1,     2,     1,     2,     6,
       0,     1,     3,     3,     0,     1,     1,     1,     2,     2,
       0,     1,     1,     1,     2,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     3,     2,
       3,     3,     2,     1,     1,     1,     1,     1,     1,     1,
       4,     3,     7,     3,     7,     4,     4,     3,     7,     3,
       7,     2,     1,     2,     3,     2,     1,     1,     1,     1,
       1,     3,     3,     1,     1,     1,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     1,     3,     4,     4,     3,     3,     3,     3,     4,
       4,     3,     4,     6,     4,     6,     4,     3,     4,     6,
       6,     4,     6,     6,     4,     1,     2,     1,     1,     1,
       4,     5,     6,     3,     3,     3,     3,     5,     7,     7,
       5,     5,     5,     7,     7,     5,     5,     3,     3,     5,
       7,     5,     7,     1,     4,     3,     5,     1,     2,     3,
       3,     1,     3,     2,     0,     1,     1,     2,     1,     3,
       1,     3,     1,     4,     1,     2,     3,     0,     1,     0,
       1,     4,     2,     3,     1,     0,     1,     4,     0,     1,
       2,     1,     3,     0,     1,     2,     2,     1,     0,     1,
       0,     1,     1,     1,     1,     1,     1,     1,     3,     3,
       1,     1,     1,     2,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     2,     1,     1,     2,     2,     3,
       1,     2,     2,     5,     2,     1,     1,     0,     2,     1,
       3,     4,     0,     2,     0,     2,     4,     4,     3,     2,
       3,     1,     3,     0,     1,     1,     2,     2,     2,     2,
       1,     2,     2,     2,     2,     3,     2,     3,     3,     4,
       2,     2,     1,     1,     3,     2,     3,     2,     3,     2,
       3,     3,     3,     3,     5,     5,     5,     5,     8,     4,
       4,     7,     5,     4,     3,     2,     5,     4,     7,     6,
       3,     3,     3,     1,     1,     1,     1,     1,     1,     1,
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
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1
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
  "\"'URI'\"", "\"'declare'\"", "\"'module'\"", "\"'<blank>'\"",
  "\"'allowing'\"", "\"'base-uri'\"", "\"'boundary-space'\"",
  "\"'comment'\"", "\"'construction'\"", "\"'copy-namespaces'\"",
  "\"'count'\"", "\"'document'\"", "\"'document-node'\"", "\"'element'\"",
  "\"'for'\"", "\"'function'\"", "\"'if'\"", "\"'import'\"",
  "\"'instance'\"", "\"'let'\"", "\"'most'\"", "\"'namespace-node'\"",
  "\"'next'\"", "\"'no'\"", "\"'only'\"", "\"'option'\"", "\"'ordering'\"",
  "\"'previous'\"", "\"'processing-instruction'\"", "\"'schema'\"",
  "\"'schema-attribute'\"", "\"'schema-element'\"", "\"'sequential'\"",
  "\"'set'\"", "\"'simple'\"", "\"'sliding'\"", "\"'some'\"",
  "\"'space'\"", "\"'stable'\"", "\"'text'\"", "\"'tumbling'\"",
  "\"'switch'\"", "\"'typeswitch'\"", "\"'updating'\"", "\"'validate'\"",
  "\"'type'\"", "\"'when'\"", "\"'word'\"", "\"'decimal-format'\"",
  "\"'decimal-separator'\"", "\"'grouping-separator'\"", "\"'infinity'\"",
  "\"'minus-sign'\"", "\"'NaN'\"", "\"'percent'\"", "\"'per-mille'\"",
  "\"'zero-digit'\"", "\"'digit'\"", "\"'pattern-separator'\"",
  "\"'ancestor'\"", "\"'ancestor-or-self'\"", "\"'and'\"", "\"'''\"",
  "\"'as'\"", "\"'ascending'\"", "\"'at'\"", "\"'attribute'\"", "\"'@'\"",
  "\"'||'\"", "\"'case'\"", "\"'castable'\"", "\"'cast'\"",
  "\"'CDATA[['\"", "\"']]'\"", "\"'child'\"", "\"'collation'\"", "\"','\"",
  "\"'(:'\"", "\"':)'\"", "\"'DECIMAL'\"", "\"'context'\"",
  "\"'variable'\"", "\"'default'\"", "\"'descendant'\"",
  "\"'descendant-or-self'\"", "\"'descending'\"", "\"'div'\"", "\"'$'\"",
  "\"'$_'\"", "\"'.'\"", "\"'..'\"", "\"':'\"", "\"'::'\"", "\"'{{'\"",
  "\"'DOUBLE'\"", "\"'<double {>'\"", "\"'else'\"", "\"'empty'\"",
  "\"'greatest'\"", "\"'least'\"", "\"'/>'\"", "\"'encoding'\"", "\"'='\"",
  "\"''''\"", "\"'\\\"\\\"'\"", "\"'every'\"", "\"'except'\"",
  "\"'external'\"", "\"'following'\"", "\"'following-sibling'\"",
  "\"'follows'\"", "\"'>='\"", "\"':='\"", "\"'>'\"", "\"'?'\"", "\"'#'\"",
  "\"'idiv'\"", "\"'in'\"", "\"'inherit'\"", "\"'INTEGER'\"",
  "\"'intersect'\"", "\"'is'\"", "\"'item'\"", "\"'{'\"", "\"'['\"",
  "\"'<='\"", "\"'('\"", "\"'<'\"", "\"'-'\"", "\"'mod'\"",
  "\"'namespace'\"", "\"'nan'\"", "\"'!='\"", "\"'nodecomp'\"",
  "\"'<no inherit>'\"", "\"'<no preserve>'\"", "\"'or'\"", "\"'order'\"",
  "\"'ordered'\"", "\"'by'\"", "\"'group'\"", "\"'parent'\"", "\"'%'\"",
  "\"'<?'\"", "\"'?>'\"", "\"'+'\"", "\"'(#'\"", "\"'#)'\"", "\"'<<'\"",
  "\"'preceding'\"", "\"'preceding-sibling'\"", "\"'preserve'\"",
  "\"'\\\"'\"", "\"'}'\"", "\"']'\"", "\"'return'\"", "\"')'\"",
  "\"'satisfies'\"", "\"'select'\"", "\"'self'\"", "\"';'\"", "\"'/'\"",
  "\"'//'\"", "\"'!'\"", "\"'*'\"", "\"'</ (start tag end)'\"",
  "\"'strip'\"", "\"'> (tag end)'\"", "\"'then'\"", "\"'to'\"",
  "\"'treat'\"", "\"'union'\"", "\"'unordered'\"", "\"'eq'\"", "\"'ge'\"",
  "\"'gt'\"", "\"'le'\"", "\"'lt'\"", "\"'ne'\"", "\"'VALUECOMP'\"",
  "\"'|'\"", "\"'empty-sequence'\"", "\"'where'\"", "\"'<!--'\"",
  "\"'-->'\"", "\"'xquery'\"", "\"'jsoniq'\"", "\"'version'\"",
  "\"'start'\"", "\"'null'\"", "\"'true'\"", "\"'false'\"", "\"'after'\"",
  "\"'before'\"", "\"'revalidation'\"", "\"'strict'\"", "\"'lax'\"",
  "\"'skip'\"", "\"'delete'\"", "\"'node'\"", "\"'insert'\"",
  "\"'nodes'\"", "\"'rename'\"", "\"'replace'\"", "\"'value'\"",
  "\"'of'\"", "\"'first'\"", "\"'into'\"", "\"'last'\"", "\"'modify'\"",
  "\"'copy'\"", "\"'with'\"", "\"'break'\"", "\"'continue'\"",
  "\"'exit'\"", "\"'loop'\"", "\"'returning'\"", "\"'while'\"",
  "\"'try'\"", "\"'catch'\"", "\"'using'\"", "\"'all'\"", "\"'any'\"",
  "\"'contains'\"", "\"'content'\"", "\"'diacritics'\"", "\"'different'\"",
  "\"'distance'\"", "\"'end'\"", "\"'entire'\"", "\"'exactly'\"",
  "\"'from'\"", "\"'ftand'\"", "\"'ftnot'\"", "\"'not'\"",
  "\"'ft-option'\"", "\"'ftor'\"", "\"'insensitive'\"", "\"'language'\"",
  "\"'levels'\"", "\"'lowercase'\"", "\"'occurs'\"", "\"'paragraph'\"",
  "\"'paragraphs'\"", "\"'phrase'\"", "\"'relationship'\"", "\"'same'\"",
  "\"'score'\"", "\"'sensitive'\"", "\"'sentence'\"", "\"'sentences'\"",
  "\"'stemming'\"", "\"'stop'\"", "\"'thesaurus'\"", "\"'times'\"",
  "\"'uppercase'\"", "\"'weight'\"", "\"'wildcards'\"", "\"'window'\"",
  "\"'without'\"", "\"'words'\"", "\"'collection'\"", "\"'const'\"",
  "\"'append-only'\"", "\"'queue'\"", "\"'mutable'\"", "\"'read-only'\"",
  "\"'unique'\"", "\"'non'\"", "\"'index'\"", "\"'manually'\"",
  "\"'automatically'\"", "\"'maintained'\"", "\"'on'\"", "\"'range'\"",
  "\"'equality'\"", "\"'general'\"", "\"'integrity'\"", "\"'constraint'\"",
  "\"'check'\"", "\"'key'\"", "\"'foreach'\"", "\"'foreign'\"",
  "\"'keys'\"", "\"'{|'\"", "\"'|}'\"", "\"'{['\"", "\"']}'\"",
  "\"'json'\"", "\"'append'\"", "\"'position'\"", "\"'object'\"",
  "\"'array'\"", "\"'json-item'\"", "\"'structured-item'\"",
  "\"'BOM_UTF8'\"", "\"'#!/shebang\"", "RANGE_REDUCE",
  "SEQUENCE_TYPE_REDUCE", "ADDITIVE_REDUCE", "UNION_REDUCE",
  "INTERSECT_EXCEPT_REDUCE", "QVARINDECLLIST_REDUCE", "UNARY_PREC",
  "STEP_REDUCE", "SIMPLEMAPEXPR_REDUCE", "MULTIPLICATIVE_REDUCE",
  "JSONLOOKUPEXPR_REDUCE", "$accept", "Module", "ERROR",
  "ModuleWithoutBOM", "VersionDecl", "MainModule", "LibraryModule",
  "ModuleDecl", "SIND_DeclList", "SIND_Decl", "Setter",
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
  "FLWORExpr", "ReturnExpr", "ReturnOrSelect", "WindowType",
  "FLWORWinCondType", "FLWORWinCond", "WindowClause", "CountClause",
  "ForLetWinClause", "FLWORClause", "FLWORClauseList", "ForClause",
  "ForOrFrom", "VarInDeclList", "VarInDecl", "PositionalVar", "FTScoreVar",
  "LetClause", "VarGetsDeclList", "VarGetsDecl", "WindowVarDecl",
  "WindowVars", "WindowVars3", "WindowVars2", "WhereClause",
  "GroupByClause", "GroupSpecList", "GroupSpec", "GroupCollationSpec",
  "OrderByClause", "OrderSpecList", "OrderSpec", "OrderModifier",
  "OrderDirSpec", "OrderEmptySpec", "OrderCollationSpec", "QuantifiedExpr",
  "QVarInDeclList", "QVarInDecl", "SwitchExpr", "SwitchCaseClauseList",
  "SwitchCaseClause", "SwitchCaseOperandList", "SwitchStatement",
  "SwitchCaseStatementList", "SwitchCaseStatement", "TypeswitchExpr",
  "TypeswitchStatement", "CaseClauseList", "CaseClause",
  "CaseStatementList", "CaseStatement", "SequenceTypeList", "IfExpr",
  "OrExpr", "AndExpr", "NotExpr", "ComparisonExpr", "$@1",
  "FTContainsExpr", "StringConcatExpr", "opt_FTIgnoreOption", "RangeExpr",
  "AdditiveExpr", "MultiplicativeExpr", "UnionExpr", "IntersectExceptExpr",
  "InstanceofExpr", "TreatExpr", "CastableExpr", "CastExpr", "SingleType",
  "UnaryExpr", "SignList", "ValueExpr", "SimpleMapExpr", "ValueComp",
  "NodeComp", "ValidateExpr", "ExtensionExpr", "Pragma_list", "Pragma",
  "PathExpr", "LeadingSlash", "RelativePathExpr", "StepExpr", "AxisStep",
  "ForwardStep", "ForwardAxis", "AbbrevForwardStep", "ReverseStep",
  "ReverseAxis", "NodeTest", "NameTest", "Wildcard", "PostfixExpr",
  "PredicateList", "Predicate", "PrimaryExpr", "Literal", "NumericLiteral",
  "VarRef", "ParenthesizedExpr", "ContextItemExpr", "OrderedExpr",
  "UnorderedExpr", "FunctionCall", "ArgList", "FunctionItemExpr",
  "LiteralFunctionItem", "InlineFunction", "Constructor",
  "DirectConstructor", "DirElemConstructor", "DirElemContentList",
  "DirAttributeList", "DirAttr", "OptionalBlank", "DirAttributeValue",
  "opt_QuoteAttrContentList", "QuoteAttrContentList",
  "opt_AposAttrContentList", "AposAttrContentList",
  "QuoteAttrValueContent", "AposAttrValueContent", "DirElemContent",
  "CommonContent", "DirCommentConstructor", "DirPIConstructor",
  "CDataSection", "ComputedConstructor", "CompDocConstructor",
  "CompElemConstructor", "CompAttrConstructor", "CompTextConstructor",
  "CompCommentConstructor", "CompPIConstructor",
  "CompNamespaceConstructor", "TypeDeclaration", "SequenceType",
  "OccurrenceIndicator", "ItemType", "TypeList", "GeneralizedAtomicType",
  "SimpleType", "KindTest", "AnyKindTest", "NODE_KIND_TEST",
  "DocumentTest", "NamespaceTest", "TextTest", "CommentTest", "PITest",
  "AttributeTest", "SchemaAttributeTest", "ElementTest",
  "SchemaElementTest", "TypeName", "TypeName_WITH_HOOK", "StringLiteral",
  "FunctionTest", "AnyFunctionTest", "TypedFunctionTest",
  "ParenthesizedItemType", "RevalidationDecl", "InsertExpr", "DeleteExpr",
  "ReplaceExpr", "RenameExpr", "TransformExpr", "VarNameList",
  "VarNameDecl", "TryExpr", "CatchListExpr", "CatchExpr", "BracedExpr",
  "NameTestList", "FTSelection", "opt_FTPosFilter_list",
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
  "JSONTest", "URI_LITERAL", "QNAME", "FUNCTION_NAME", "EQNAME", YY_NULL
  };

#if YYDEBUG
  /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
  const jsoniq_parser::rhs_number_type
  jsoniq_parser::yyrhs_[] =
  {
       341,     0,    -1,   343,    -1,   327,   343,    -1,   328,   343,
      -1,   327,   328,   343,    -1,     1,    -1,     1,     3,    -1,
     342,     1,    -1,   345,    -1,   344,   345,    -1,   346,    -1,
     344,   346,    -1,   218,   219,    30,   192,    -1,   218,   219,
      30,   133,    30,   192,    -1,   348,   192,   395,    -1,   365,
     192,   395,    -1,   348,   192,   365,   192,   395,    -1,   395,
      -1,   348,   342,   395,    -1,   365,   342,   395,    -1,   348,
     192,   365,   342,   395,    -1,   348,   342,   365,   192,   395,
      -1,   347,    -1,   347,   348,   192,    -1,   347,   365,   192,
      -1,   347,   348,   192,   365,   192,    -1,    34,   162,   664,
     134,   663,   192,    -1,   349,    -1,   348,   192,   349,    -1,
     348,   342,   349,    -1,   350,    -1,   358,    -1,   363,    -1,
     364,    -1,   372,    -1,   351,    -1,   352,    -1,   353,    -1,
     354,    -1,   355,    -1,   356,    -1,   357,    -1,   586,    -1,
      33,    38,   183,    -1,    33,    38,   198,    -1,    33,   114,
     107,   663,    -1,    33,    37,   663,    -1,    33,    40,   183,
      -1,    33,    40,   198,    -1,    33,    58,   170,    -1,    33,
      58,   204,    -1,    33,   114,   169,   129,   130,    -1,    33,
     114,   169,   129,   131,    -1,    33,    41,   183,   108,   150,
      -1,    33,    41,   183,   108,   166,    -1,    33,    41,   167,
     108,   150,    -1,    33,    41,   167,   108,   166,    -1,   359,
      -1,   362,    -1,    49,    25,     1,    -1,    49,    61,   663,
      -1,    49,    61,   361,   663,    -1,    49,    61,   663,    97,
     360,    -1,    49,    61,   361,   663,    97,   360,    -1,   663,
      -1,   360,   108,   663,    -1,   162,   664,   134,    -1,   114,
      45,   162,    -1,    49,    34,   663,    -1,    49,    34,   162,
     664,   134,   663,    -1,    49,    34,   663,    97,   360,    -1,
      49,    34,   162,   664,   134,   663,    97,   360,    -1,    33,
     162,   664,   134,   663,    -1,    33,   114,    45,   162,   663,
      -1,    33,   114,    47,   162,   663,    -1,   366,    -1,   365,
     192,   366,    -1,   365,   342,   366,    -1,   367,    -1,   371,
      -1,   373,    -1,   377,    -1,   382,    -1,   389,    -1,   391,
      -1,   394,    -1,    33,   114,    80,   368,    -1,    33,    80,
     664,   368,    -1,   369,    -1,   368,   369,    -1,   370,   134,
     581,    -1,    81,    -1,    89,    -1,    82,    -1,    83,    -1,
      84,    -1,    85,    -1,    90,    -1,    86,    -1,    87,    -1,
      88,    -1,    33,    57,   664,    30,    -1,    33,   267,   625,
      -1,    33,   112,   154,   374,    -1,    95,   563,   375,    -1,
     375,    -1,   376,    -1,   139,    -1,   139,   376,    -1,   144,
     420,    -1,    33,   378,   144,   420,    -1,    33,   378,   139,
      -1,    33,   378,   139,   144,   420,    -1,   113,   119,   664,
      -1,   113,   119,   664,   560,    -1,   379,   113,   119,   664,
      -1,   379,   113,   119,   664,   560,    -1,   380,    -1,   379,
     380,    -1,    27,    -1,    27,   158,   381,   188,    -1,    28,
      -1,    28,   158,   381,   188,    -1,   521,    -1,   381,   108,
     521,    -1,    33,   383,    -1,    33,   379,   383,    -1,   384,
      -1,   385,    -1,    47,   665,   386,   403,    -1,    47,   665,
     386,   139,    -1,    75,    47,   665,   386,   403,    -1,    75,
      47,   665,   386,   139,    -1,   158,   188,    -1,   158,   387,
     188,    -1,   158,   188,    95,   561,    -1,   158,   387,   188,
      95,   561,    -1,   388,    -1,   387,   108,   388,    -1,   119,
     664,    -1,   119,   664,   560,    -1,    33,   293,   664,    -1,
      33,   293,   664,    95,   390,    -1,    33,   379,   293,   664,
      -1,    33,   379,   293,   664,    95,   390,    -1,   567,    -1,
     567,   562,    -1,   662,    -1,   662,   562,    -1,    33,   301,
     664,   305,   233,   504,   171,   392,    -1,    33,   379,   301,
     664,   305,   233,   504,   171,   392,    -1,   393,    -1,   392,
     108,   393,    -1,   504,    -1,   504,   560,    -1,   504,   457,
      -1,   504,   560,   457,    -1,    33,   309,   310,   664,   305,
     293,   664,   119,   664,   311,   420,    -1,    33,   309,   310,
     664,   305,   293,   664,   231,   119,   664,   311,   299,   312,
     504,    -1,    33,   309,   310,   664,   305,   293,   664,   313,
     231,   119,   664,   311,   420,    -1,    33,   309,   310,   664,
     314,   312,   263,   293,   664,   231,   119,   664,   312,   504,
     201,   293,   664,   231,   119,   664,   312,   504,    -1,   396,
      -1,   398,    -1,   399,    -1,    -1,   398,    -1,   399,    -1,
      -1,   419,    -1,   399,   419,    -1,   400,    -1,   399,   400,
      -1,   399,   419,   342,   400,    -1,   401,    -1,   404,    -1,
     407,    -1,   408,    -1,   409,    -1,   410,    -1,   411,    -1,
     412,    -1,   414,    -1,   469,    -1,   465,    -1,   415,    -1,
     418,    -1,   155,   399,   185,    -1,   155,   397,   185,    -1,
     155,   397,   185,    -1,   405,   192,    -1,   405,   108,   406,
      -1,   113,   406,    -1,   379,   113,   406,    -1,   119,   664,
      -1,   119,   664,   560,    -1,   119,   664,   144,   420,    -1,
     119,   664,   560,   144,   420,    -1,   119,   664,   144,   420,
     192,    -1,   421,   192,    -1,   246,   248,   420,   192,    -1,
     249,   158,   419,   188,   400,    -1,   244,   247,   192,    -1,
     245,   247,   192,    -1,   432,   413,    -1,   424,   400,    -1,
      48,   158,   419,   188,   200,   400,   128,   400,    -1,   250,
     401,   416,    -1,   417,    -1,   416,   417,    -1,   251,   598,
     401,    -1,   192,    -1,   420,    -1,   419,   108,   420,    -1,
     419,   342,   420,    -1,   422,    -1,   461,    -1,   468,    -1,
     475,    -1,   594,    -1,   421,    -1,   476,    -1,   458,    -1,
     587,    -1,   588,    -1,   590,    -1,   589,    -1,   591,    -1,
     659,    -1,   657,    -1,   660,    -1,   661,    -1,   658,    -1,
     432,   423,    -1,   424,   420,    -1,   187,    -1,   190,    -1,
      67,   290,    -1,    72,   290,    -1,   220,    -1,   260,    -1,
      56,   260,    -1,   426,   443,    78,   420,    -1,   426,    78,
     420,    -1,   434,   425,   442,   427,   427,    -1,   434,   425,
     442,   427,    -1,    42,   119,   664,    -1,   433,    -1,   439,
      -1,   428,    -1,   430,    -1,   446,    -1,   451,    -1,   447,
      -1,   429,    -1,   430,    -1,   432,   431,    -1,   434,   119,
     435,    -1,    46,     1,   435,    -1,   263,     1,   435,    -1,
     434,     3,    -1,    46,    -1,   263,    -1,   436,    -1,   435,
     108,   119,   436,    -1,   435,   108,   436,    -1,   664,   149,
     420,    -1,   664,    36,   129,   149,   420,    -1,   664,   560,
     149,   420,    -1,   664,   560,    36,   129,   149,   420,    -1,
     664,   437,   149,   420,    -1,   664,    36,   129,   437,   149,
     420,    -1,   664,   560,   437,   149,   420,    -1,   664,   560,
      36,   129,   437,   149,   420,    -1,   664,   438,   149,   420,
      -1,   664,   560,   438,   149,   420,    -1,   664,   437,   438,
     149,   420,    -1,   664,   560,   437,   438,   149,   420,    -1,
      97,   119,   664,    -1,   279,   119,   664,    -1,    51,   440,
      -1,   441,    -1,   440,   108,   441,    -1,   119,   664,   144,
     420,    -1,   119,   664,   560,   144,   420,    -1,   438,   144,
     420,    -1,   119,   664,   560,   438,   144,   420,    -1,   119,
     664,   149,   420,    -1,   119,   664,   560,   149,   420,    -1,
     444,    -1,   119,   664,    -1,   119,   664,   444,    -1,   437,
      -1,   437,   445,    -1,   445,    -1,    59,   119,   664,    54,
     119,   664,    -1,    54,   119,   664,    -1,    59,   119,   664,
      -1,   214,   420,    -1,   172,   171,   448,    -1,   449,    -1,
     448,   108,   449,    -1,   119,   664,   144,   420,    -1,   119,
     664,   560,   144,   420,    -1,   119,   664,   560,   144,   420,
     450,    -1,   119,   664,   144,   420,   450,    -1,   420,    -1,
     420,   450,    -1,   107,   663,    -1,   169,   171,   452,    -1,
      70,   169,   171,   452,    -1,   453,    -1,   452,   108,   453,
      -1,   420,    -1,   420,   454,    -1,   455,    -1,   456,    -1,
     457,    -1,   455,   456,    -1,   455,   457,    -1,   456,   457,
      -1,   455,   456,   457,    -1,    96,    -1,   117,    -1,   129,
     130,    -1,   129,   131,    -1,   107,   663,    -1,    68,   119,
     459,   189,   420,    -1,   137,   119,   459,   189,   420,    -1,
     460,    -1,   459,   108,   119,   460,    -1,   664,   149,   420,
      -1,   664,   560,   149,   420,    -1,    73,   158,   419,   188,
     462,   114,   424,   420,    -1,   463,    -1,   462,   463,    -1,
     464,   424,   420,    -1,   101,   420,    -1,   464,   101,   420,
      -1,    73,   158,   419,   188,   466,   114,   424,   400,    -1,
     467,    -1,   466,   467,    -1,   464,   424,   400,    -1,    74,
     158,   419,   188,   470,   114,   424,   420,    -1,    74,   158,
     419,   188,   470,   114,   119,   664,   424,   420,    -1,    74,
     158,   419,   188,   472,   114,   424,   400,    -1,    74,   158,
     419,   188,   470,   114,   119,   664,   424,   400,    -1,   471,
      -1,   470,   471,    -1,   101,   474,   424,   420,    -1,   101,
     119,   664,    95,   474,   424,   420,    -1,   473,    -1,   472,
     473,    -1,   101,   474,   424,   400,    -1,   101,   119,   664,
      95,   474,   424,   400,    -1,   561,    -1,   474,   212,   561,
      -1,    48,   158,   419,   188,   200,   420,   128,   420,    -1,
     477,    -1,   476,   168,   477,    -1,   478,    -1,   477,    93,
     478,    -1,   479,    -1,   266,   478,    -1,   481,    -1,   481,
     498,   481,    -1,   481,   499,   481,    -1,   481,   134,   481,
      -1,   481,   164,   481,    -1,    -1,   481,   159,   480,   481,
      -1,   481,   157,   481,    -1,   481,   145,   481,    -1,   481,
     143,   481,    -1,   482,    -1,   482,   255,    71,   599,   483,
      -1,   484,    -1,   484,   100,   482,    -1,    -1,   651,    -1,
     485,    -1,   485,   201,   485,    -1,   486,    -1,   485,   177,
     486,    -1,   485,   160,   486,    -1,   487,    -1,   486,   196,
     487,    -1,   486,   118,   487,    -1,   486,   148,   487,    -1,
     486,   161,   487,    -1,   488,    -1,   487,   203,   488,    -1,
     487,   212,   488,    -1,   489,    -1,   488,   152,   489,    -1,
     488,   138,   489,    -1,   490,    -1,   490,    50,   237,   561,
      -1,   491,    -1,   491,   202,    95,   561,    -1,   492,    -1,
     492,   102,    95,   493,    -1,   494,    -1,   494,   103,    95,
     493,    -1,   566,    -1,   566,   146,    -1,   496,    -1,   495,
     496,    -1,   177,    -1,   160,    -1,   495,   177,    -1,   495,
     160,    -1,   500,    -1,   497,    -1,   501,    -1,   504,    -1,
     497,   195,   504,    -1,   205,    -1,   210,    -1,   209,    -1,
     208,    -1,   207,    -1,   206,    -1,   153,    -1,   180,    -1,
     142,    -1,    76,   155,   398,   185,    -1,    76,   228,   155,
     398,   185,    -1,    76,   227,   155,   398,   185,    -1,    76,
      77,   579,   155,   398,   185,    -1,   502,   155,   397,   185,
      -1,   503,    -1,   502,   503,    -1,   178,   664,    17,    -1,
     178,    18,    -1,   178,    19,    -1,   505,    -1,   505,   506,
      -1,   194,   506,    -1,   506,    -1,   193,    -1,   507,    -1,
     507,   193,   506,    -1,   507,   194,   506,    -1,   508,    -1,
     517,    -1,   509,    -1,   509,   518,    -1,   512,    -1,   512,
     518,    -1,   510,   514,    -1,   511,    -1,   106,   124,    -1,
     115,   124,    -1,    98,   124,    -1,   191,   124,    -1,   116,
     124,    -1,   141,   124,    -1,   140,   124,    -1,   514,    -1,
      99,   514,    -1,   513,   514,    -1,   122,    -1,   173,   124,
      -1,    91,   124,    -1,   182,   124,    -1,   181,   124,    -1,
      92,   124,    -1,   567,    -1,   515,    -1,   664,    -1,   516,
      -1,   196,    -1,    11,    -1,    12,    -1,    20,    -1,   520,
      -1,   517,   518,    -1,   517,   158,   188,    -1,   517,   158,
     529,   188,    -1,   517,   156,   186,    -1,   517,   121,   664,
      -1,   517,   121,   158,   188,    -1,   517,   121,   158,   419,
     188,    -1,   517,   121,   523,    -1,   517,   121,   581,    -1,
     519,    -1,   518,   519,    -1,   156,   419,   186,    -1,   521,
      -1,   523,    -1,   524,    -1,   525,    -1,   528,    -1,   533,
      -1,   526,    -1,   527,    -1,   530,    -1,   402,    -1,   655,
      -1,   652,    -1,   653,    -1,   654,    -1,   522,    -1,   581,
      -1,   111,    -1,   151,    -1,   126,    -1,   119,   664,    -1,
     158,   188,    -1,   158,   419,   188,    -1,   120,    -1,   170,
     155,   419,   185,    -1,   204,   155,   419,   185,    -1,   665,
     158,   188,    -1,   665,   158,   529,   188,    -1,   146,    -1,
     529,   108,   146,    -1,   420,    -1,   529,   108,   420,    -1,
     531,    -1,   532,    -1,   665,   147,   151,    -1,    47,   386,
     403,    -1,   534,    -1,   552,    -1,   535,    -1,   549,    -1,
     550,    -1,   159,   664,   539,   132,    -1,   159,   664,   539,
     199,   197,   664,   539,   199,    -1,   159,   664,   537,   539,
     132,    -1,   159,   664,   537,   539,   199,   197,   664,   539,
     199,    -1,   159,   664,   539,   199,   536,   197,   664,   539,
     199,    -1,   159,   664,   537,   539,   199,   536,   197,   664,
     539,   199,    -1,   547,    -1,   536,   547,    -1,   538,    -1,
     537,   538,    -1,    35,   664,   539,   134,   539,   540,    -1,
      -1,    35,    -1,   184,   541,   184,    -1,    94,   543,    94,
      -1,    -1,   542,    -1,   136,    -1,   545,    -1,   542,   136,
      -1,   542,   545,    -1,    -1,   544,    -1,   135,    -1,   546,
      -1,   544,   135,    -1,   544,   546,    -1,    29,    -1,   548,
      -1,     5,    -1,   548,    -1,   534,    -1,    10,    -1,   551,
      -1,   548,    -1,     9,    -1,   125,    -1,   127,    -1,   155,
     398,   185,    -1,   215,    31,   216,    -1,   215,   216,    -1,
     175,   664,   176,    -1,   175,   664,     8,    -1,   104,     7,
      -1,   553,    -1,   554,    -1,   555,    -1,   556,    -1,   557,
      -1,   558,    -1,   559,    -1,    43,   155,   398,   185,    -1,
      21,   397,   185,    -1,    45,   155,   419,   185,   155,   397,
     185,    -1,    22,   397,   185,    -1,    98,   155,   419,   185,
     155,   397,   185,    -1,    71,   155,   398,   185,    -1,    39,
     155,   398,   185,    -1,    23,   397,   185,    -1,    60,   155,
     419,   185,   155,   397,   185,    -1,    24,   398,   185,    -1,
     162,   155,   419,   185,   155,   398,   185,    -1,    95,   561,
      -1,   563,    -1,   563,   562,    -1,   213,   158,   188,    -1,
     158,   188,    -1,   146,    -1,   196,    -1,   177,    -1,   565,
      -1,   567,    -1,   154,   158,   188,    -1,   326,   158,   188,
      -1,   582,    -1,   585,    -1,   662,    -1,   561,    -1,   564,
     108,   561,    -1,   664,    -1,   664,    -1,   570,    -1,   577,
      -1,   575,    -1,   578,    -1,   576,    -1,   574,    -1,   573,
      -1,   572,    -1,   571,    -1,   568,    -1,   569,   158,   188,
      -1,   231,    -1,    44,   158,   188,    -1,    44,   158,   577,
     188,    -1,    44,   158,   578,   188,    -1,    53,   158,   188,
      -1,    71,   158,   188,    -1,    39,   158,   188,    -1,    60,
     158,   188,    -1,    60,   158,   664,   188,    -1,    60,   158,
      30,   188,    -1,    98,   158,   188,    -1,    98,   158,   664,
     188,    -1,    98,   158,   664,   108,   579,   188,    -1,    98,
     158,   196,   188,    -1,    98,   158,   196,   108,   579,   188,
      -1,    62,   158,   664,   188,    -1,    45,   158,   188,    -1,
      45,   158,   664,   188,    -1,    45,   158,   664,   108,   579,
     188,    -1,    45,   158,   664,   108,   580,   188,    -1,    45,
     158,   196,   188,    -1,    45,   158,   196,   108,   579,   188,
      -1,    45,   158,   196,   108,   580,   188,    -1,    63,   158,
     664,   188,    -1,   664,    -1,   664,   146,    -1,    30,    -1,
     583,    -1,   584,    -1,    47,   158,   196,   188,    -1,    47,
     158,   188,    95,   561,    -1,    47,   158,   564,   188,    95,
     561,    -1,   158,   563,   188,    -1,    33,   226,   227,    -1,
      33,   226,   228,    -1,    33,   226,   229,    -1,   232,   231,
     420,   239,   420,    -1,   232,   231,   420,    95,   238,   239,
     420,    -1,   232,   231,   420,    95,   240,   239,   420,    -1,
     232,   231,   420,   224,   420,    -1,   232,   231,   420,   225,
     420,    -1,   232,   233,   420,   239,   420,    -1,   232,   233,
     420,    95,   238,   239,   420,    -1,   232,   233,   420,    95,
     240,   239,   420,    -1,   232,   233,   420,   224,   420,    -1,
     232,   233,   420,   225,   420,    -1,   230,   231,   420,    -1,
     230,   233,   420,    -1,   235,   231,   420,   243,   420,    -1,
     235,   236,   237,   231,   420,   243,   420,    -1,   234,   231,
     420,    95,   420,    -1,   242,   119,   592,   241,   420,   424,
     420,    -1,   593,    -1,   592,   108,   119,   593,    -1,   664,
     144,   420,    -1,   250,   155,   419,   185,   595,    -1,   596,
      -1,   595,   596,    -1,   251,   598,   597,    -1,   155,   419,
     185,    -1,   515,    -1,   598,   212,   515,    -1,   602,   600,
      -1,    -1,   601,    -1,   620,    -1,   601,   620,    -1,   603,
      -1,   602,   268,   603,    -1,   604,    -1,   603,   264,   604,
      -1,   605,    -1,   604,   266,   149,   605,    -1,   606,    -1,
     265,   606,    -1,   610,   607,   608,    -1,    -1,   625,    -1,
      -1,   609,    -1,   288,   155,   419,   185,    -1,   614,   611,
      -1,   158,   599,   188,    -1,   612,    -1,    -1,   647,    -1,
     502,   155,   613,   185,    -1,    -1,   599,    -1,   615,   616,
      -1,   521,    -1,   155,   419,   185,    -1,    -1,   617,    -1,
     254,   618,    -1,   253,   619,    -1,   276,    -1,    -1,    79,
      -1,    -1,   292,    -1,   621,    -1,   622,    -1,   623,    -1,
     649,    -1,   646,    -1,   170,    -1,   290,   485,   624,    -1,
     259,   648,   624,    -1,   292,    -1,   282,    -1,   275,    -1,
     252,   626,    -1,   625,   252,   626,    -1,   627,    -1,   628,
      -1,   629,    -1,   644,    -1,   630,    -1,   638,    -1,   631,
      -1,   645,    -1,   101,   280,    -1,   101,   269,    -1,   272,
      -1,   287,    -1,   257,   280,    -1,   257,   269,    -1,    57,
     664,    30,    -1,   283,    -1,    55,   283,    -1,   285,   632,
      -1,   285,   158,   632,   633,   188,    -1,    55,   285,    -1,
     635,    -1,   114,    -1,    -1,   108,   634,    -1,   635,    -1,
     634,   108,   635,    -1,    97,    30,   636,   637,    -1,    -1,
     277,    30,    -1,    -1,   648,   271,    -1,   284,   292,   639,
     641,    -1,   284,   292,   114,   641,    -1,    55,   284,   292,
      -1,    97,    30,    -1,   158,   640,   188,    -1,    30,    -1,
     640,   108,    30,    -1,    -1,   642,    -1,   643,    -1,   642,
     643,    -1,   203,   639,    -1,   138,   639,    -1,   270,    30,
      -1,   289,    -1,    55,   289,    -1,    97,   220,    -1,    97,
     260,    -1,   261,   256,    -1,   273,   648,   286,    -1,   262,
     485,    -1,    97,   131,   485,    -1,    97,    52,   485,    -1,
     263,   485,   201,   485,    -1,   278,   650,    -1,   258,   650,
      -1,   281,    -1,   274,    -1,   291,   256,   487,    -1,   156,
     186,    -1,   156,   419,   186,    -1,   316,   317,    -1,   316,
     419,   317,    -1,   318,   319,    -1,   318,   419,   319,    -1,
     155,   656,   185,    -1,   664,   123,   420,    -1,   420,   123,
     420,    -1,   656,   108,   420,   123,   420,    -1,   656,   108,
     664,   123,   420,    -1,   232,   320,   420,   239,   420,    -1,
     232,   320,   656,   239,   420,    -1,   232,   320,   420,   239,
     420,    97,   322,   420,    -1,   232,   420,   239,   420,    -1,
     232,   656,   239,   420,    -1,   232,   420,   239,   420,    97,
     322,   420,    -1,   321,   320,   420,   239,   420,    -1,   321,
     420,   239,   420,    -1,   230,   320,   517,    -1,   230,   517,
      -1,   234,   320,   517,    95,   420,    -1,   234,   517,    95,
     420,    -1,   235,   320,   236,   237,   517,   243,   420,    -1,
     235,   236,   237,   517,   243,   420,    -1,   325,   158,   188,
      -1,   324,   158,   188,    -1,   323,   158,   188,    -1,    30,
      -1,   665,    -1,    16,    -1,    98,    -1,    39,    -1,    44,
      -1,    53,    -1,    45,    -1,   154,    -1,    48,    -1,   231,
      -1,    60,    -1,    62,    -1,    63,    -1,    71,    -1,    74,
      -1,    73,    -1,   213,    -1,   249,    -1,   320,    -1,   324,
      -1,   323,    -1,   325,    -1,   326,    -1,   666,    -1,    25,
      -1,   217,    -1,   129,    -1,    38,    -1,   267,    -1,    37,
      -1,   228,    -1,   227,    -1,   148,    -1,    43,    -1,   265,
      -1,   266,    -1,   280,    -1,   269,    -1,   257,    -1,   291,
      -1,   283,    -1,   285,    -1,   284,    -1,   289,    -1,   261,
      -1,   256,    -1,    79,    -1,   220,    -1,   260,    -1,    52,
      -1,   229,    -1,   242,    -1,   308,    -1,   236,    -1,   205,
      -1,   210,    -1,   209,    -1,   208,    -1,   207,    -1,   206,
      -1,    97,    -1,   112,    -1,   113,    -1,   187,    -1,    46,
      -1,   263,    -1,    36,    -1,    67,    -1,    72,    -1,    59,
      -1,    54,    -1,    56,    -1,    78,    -1,    42,    -1,   149,
      -1,    51,    -1,   214,    -1,   171,    -1,   172,    -1,   169,
      -1,    70,    -1,    96,    -1,   117,    -1,   130,    -1,   131,
      -1,   107,    -1,    68,    -1,   137,    -1,   189,    -1,   101,
      -1,    95,    -1,   200,    -1,   128,    -1,   168,    -1,    93,
      -1,    50,    -1,   237,    -1,   102,    -1,   201,    -1,   118,
      -1,   161,    -1,   203,    -1,   152,    -1,   138,    -1,    76,
      -1,    77,    -1,   103,    -1,   202,    -1,   153,    -1,   183,
      -1,   198,    -1,   162,    -1,   139,    -1,   133,    -1,   167,
      -1,   150,    -1,   166,    -1,    33,    -1,    40,    -1,    58,
      -1,   114,    -1,    41,    -1,    57,    -1,   219,    -1,    49,
      -1,    61,    -1,    34,    -1,    47,    -1,   279,    -1,   255,
      -1,   288,    -1,   290,    -1,   259,    -1,   273,    -1,   286,
      -1,   278,    -1,   258,    -1,   272,    -1,   287,    -1,   277,
      -1,   271,    -1,   270,    -1,   254,    -1,   253,    -1,   262,
      -1,   292,    -1,   282,    -1,   281,    -1,   276,    -1,   274,
      -1,   275,    -1,   241,    -1,   238,    -1,   321,    -1,   232,
      -1,   235,    -1,   234,    -1,   230,    -1,   225,    -1,   224,
      -1,   226,    -1,   243,    -1,   233,    -1,   240,    -1,   239,
      -1,    66,    -1,    64,    -1,    75,    -1,   170,    -1,   204,
      -1,   248,    -1,   246,    -1,   247,    -1,   244,    -1,   245,
      -1,   250,    -1,   251,    -1,   252,    -1,    65,    -1,   301,
      -1,   299,    -1,   300,    -1,   305,    -1,   306,    -1,   307,
      -1,   302,    -1,   303,    -1,   304,    -1,    80,    -1,    81,
      -1,    82,    -1,    83,    -1,    84,    -1,    85,    -1,    86,
      -1,    87,    -1,    88,    -1,    89,    -1,    90,    -1,   293,
      -1,   294,    -1,   295,    -1,   296,    -1,   297,    -1,   298,
      -1,   309,    -1,   310,    -1,   311,    -1,   312,    -1,   313,
      -1,   314,    -1,   315,    -1,    91,    -1,   106,    -1,   115,
      -1,   173,    -1,   181,    -1,   191,    -1,   140,    -1,    92,
      -1,   116,    -1,   141,    -1,   182,    -1,   322,    -1,   221,
      -1,   222,    -1,   223,    -1,   190,    -1,   218,    -1,    26,
      -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned short int
  jsoniq_parser::yyprhs_[] =
  {
         0,     0,     3,     5,     8,    11,    15,    17,    20,    23,
      25,    28,    30,    33,    38,    45,    49,    53,    59,    61,
      65,    69,    75,    81,    83,    87,    91,    97,   104,   106,
     110,   114,   116,   118,   120,   122,   124,   126,   128,   130,
     132,   134,   136,   138,   140,   144,   148,   153,   157,   161,
     165,   169,   173,   179,   185,   191,   197,   203,   209,   211,
     213,   217,   221,   226,   232,   239,   241,   245,   249,   253,
     257,   264,   270,   279,   285,   291,   297,   299,   303,   307,
     309,   311,   313,   315,   317,   319,   321,   323,   328,   333,
     335,   338,   342,   344,   346,   348,   350,   352,   354,   356,
     358,   360,   362,   367,   371,   376,   380,   382,   384,   386,
     389,   392,   397,   401,   407,   411,   416,   421,   427,   429,
     432,   434,   439,   441,   446,   448,   452,   455,   459,   461,
     463,   468,   473,   479,   485,   488,   492,   497,   503,   505,
     509,   512,   516,   520,   526,   531,   538,   540,   543,   545,
     548,   557,   567,   569,   573,   575,   578,   581,   585,   597,
     612,   626,   649,   651,   653,   655,   656,   658,   660,   661,
     663,   666,   668,   671,   676,   678,   680,   682,   684,   686,
     688,   690,   692,   694,   696,   698,   700,   702,   706,   710,
     714,   717,   721,   724,   728,   731,   735,   740,   746,   752,
     755,   760,   766,   770,   774,   777,   780,   789,   793,   795,
     798,   802,   804,   806,   810,   814,   816,   818,   820,   822,
     824,   826,   828,   830,   832,   834,   836,   838,   840,   842,
     844,   846,   848,   850,   853,   856,   858,   860,   863,   866,
     868,   870,   873,   878,   882,   888,   893,   897,   899,   901,
     903,   905,   907,   909,   911,   913,   915,   918,   922,   926,
     930,   933,   935,   937,   939,   944,   948,   952,   958,   963,
     970,   975,   982,   988,   996,  1001,  1007,  1013,  1020,  1024,
    1028,  1031,  1033,  1037,  1042,  1048,  1052,  1059,  1064,  1070,
    1072,  1075,  1079,  1081,  1084,  1086,  1093,  1097,  1101,  1104,
    1108,  1110,  1114,  1119,  1125,  1132,  1138,  1140,  1143,  1146,
    1150,  1155,  1157,  1161,  1163,  1166,  1168,  1170,  1172,  1175,
    1178,  1181,  1185,  1187,  1189,  1192,  1195,  1198,  1204,  1210,
    1212,  1217,  1221,  1226,  1235,  1237,  1240,  1244,  1247,  1251,
    1260,  1262,  1265,  1269,  1278,  1289,  1298,  1309,  1311,  1314,
    1319,  1327,  1329,  1332,  1337,  1345,  1347,  1351,  1360,  1362,
    1366,  1368,  1372,  1374,  1377,  1379,  1383,  1387,  1391,  1395,
    1396,  1401,  1405,  1409,  1413,  1415,  1421,  1423,  1427,  1428,
    1430,  1432,  1436,  1438,  1442,  1446,  1448,  1452,  1456,  1460,
    1464,  1466,  1470,  1474,  1476,  1480,  1484,  1486,  1491,  1493,
    1498,  1500,  1505,  1507,  1512,  1514,  1517,  1519,  1522,  1524,
    1526,  1529,  1532,  1534,  1536,  1538,  1540,  1544,  1546,  1548,
    1550,  1552,  1554,  1556,  1558,  1560,  1562,  1567,  1573,  1579,
    1586,  1591,  1593,  1596,  1600,  1603,  1606,  1608,  1611,  1614,
    1616,  1618,  1620,  1624,  1628,  1630,  1632,  1634,  1637,  1639,
    1642,  1645,  1647,  1650,  1653,  1656,  1659,  1662,  1665,  1668,
    1670,  1673,  1676,  1678,  1681,  1684,  1687,  1690,  1693,  1695,
    1697,  1699,  1701,  1703,  1705,  1707,  1709,  1711,  1714,  1718,
    1723,  1727,  1731,  1736,  1742,  1746,  1750,  1752,  1755,  1759,
    1761,  1763,  1765,  1767,  1769,  1771,  1773,  1775,  1777,  1779,
    1781,  1783,  1785,  1787,  1789,  1791,  1793,  1795,  1797,  1800,
    1803,  1807,  1809,  1814,  1819,  1823,  1828,  1830,  1834,  1836,
    1840,  1842,  1844,  1848,  1852,  1854,  1856,  1858,  1860,  1862,
    1867,  1876,  1882,  1892,  1902,  1913,  1915,  1918,  1920,  1923,
    1930,  1931,  1933,  1937,  1941,  1942,  1944,  1946,  1948,  1951,
    1954,  1955,  1957,  1959,  1961,  1964,  1967,  1969,  1971,  1973,
    1975,  1977,  1979,  1981,  1983,  1985,  1987,  1989,  1993,  1997,
    2000,  2004,  2008,  2011,  2013,  2015,  2017,  2019,  2021,  2023,
    2025,  2030,  2034,  2042,  2046,  2054,  2059,  2064,  2068,  2076,
    2080,  2088,  2091,  2093,  2096,  2100,  2103,  2105,  2107,  2109,
    2111,  2113,  2117,  2121,  2123,  2125,  2127,  2129,  2133,  2135,
    2137,  2139,  2141,  2143,  2145,  2147,  2149,  2151,  2153,  2155,
    2157,  2161,  2163,  2167,  2172,  2177,  2181,  2185,  2189,  2193,
    2198,  2203,  2207,  2212,  2219,  2224,  2231,  2236,  2240,  2245,
    2252,  2259,  2264,  2271,  2278,  2283,  2285,  2288,  2290,  2292,
    2294,  2299,  2305,  2312,  2316,  2320,  2324,  2328,  2334,  2342,
    2350,  2356,  2362,  2368,  2376,  2384,  2390,  2396,  2400,  2404,
    2410,  2418,  2424,  2432,  2434,  2439,  2443,  2449,  2451,  2454,
    2458,  2462,  2464,  2468,  2471,  2472,  2474,  2476,  2479,  2481,
    2485,  2487,  2491,  2493,  2498,  2500,  2503,  2507,  2508,  2510,
    2511,  2513,  2518,  2521,  2525,  2527,  2528,  2530,  2535,  2536,
    2538,  2541,  2543,  2547,  2548,  2550,  2553,  2556,  2558,  2559,
    2561,  2562,  2564,  2566,  2568,  2570,  2572,  2574,  2576,  2580,
    2584,  2586,  2588,  2590,  2593,  2597,  2599,  2601,  2603,  2605,
    2607,  2609,  2611,  2613,  2616,  2619,  2621,  2623,  2626,  2629,
    2633,  2635,  2638,  2641,  2647,  2650,  2652,  2654,  2655,  2658,
    2660,  2664,  2669,  2670,  2673,  2674,  2677,  2682,  2687,  2691,
    2694,  2698,  2700,  2704,  2705,  2707,  2709,  2712,  2715,  2718,
    2721,  2723,  2726,  2729,  2732,  2735,  2739,  2742,  2746,  2750,
    2755,  2758,  2761,  2763,  2765,  2769,  2772,  2776,  2779,  2783,
    2786,  2790,  2794,  2798,  2802,  2808,  2814,  2820,  2826,  2835,
    2840,  2845,  2853,  2859,  2864,  2868,  2871,  2877,  2882,  2890,
    2897,  2901,  2905,  2909,  2911,  2913,  2915,  2917,  2919,  2921,
    2923,  2925,  2927,  2929,  2931,  2933,  2935,  2937,  2939,  2941,
    2943,  2945,  2947,  2949,  2951,  2953,  2955,  2957,  2959,  2961,
    2963,  2965,  2967,  2969,  2971,  2973,  2975,  2977,  2979,  2981,
    2983,  2985,  2987,  2989,  2991,  2993,  2995,  2997,  2999,  3001,
    3003,  3005,  3007,  3009,  3011,  3013,  3015,  3017,  3019,  3021,
    3023,  3025,  3027,  3029,  3031,  3033,  3035,  3037,  3039,  3041,
    3043,  3045,  3047,  3049,  3051,  3053,  3055,  3057,  3059,  3061,
    3063,  3065,  3067,  3069,  3071,  3073,  3075,  3077,  3079,  3081,
    3083,  3085,  3087,  3089,  3091,  3093,  3095,  3097,  3099,  3101,
    3103,  3105,  3107,  3109,  3111,  3113,  3115,  3117,  3119,  3121,
    3123,  3125,  3127,  3129,  3131,  3133,  3135,  3137,  3139,  3141,
    3143,  3145,  3147,  3149,  3151,  3153,  3155,  3157,  3159,  3161,
    3163,  3165,  3167,  3169,  3171,  3173,  3175,  3177,  3179,  3181,
    3183,  3185,  3187,  3189,  3191,  3193,  3195,  3197,  3199,  3201,
    3203,  3205,  3207,  3209,  3211,  3213,  3215,  3217,  3219,  3221,
    3223,  3225,  3227,  3229,  3231,  3233,  3235,  3237,  3239,  3241,
    3243,  3245,  3247,  3249,  3251,  3253,  3255,  3257,  3259,  3261,
    3263,  3265,  3267,  3269,  3271,  3273,  3275,  3277,  3279,  3281,
    3283,  3285,  3287,  3289,  3291,  3293,  3295,  3297,  3299,  3301,
    3303,  3305,  3307,  3309,  3311,  3313,  3315,  3317,  3319,  3321,
    3323,  3325,  3327,  3329,  3331,  3333,  3335,  3337,  3339,  3341,
    3343,  3345,  3347,  3349,  3351,  3353,  3355,  3357,  3359,  3361,
    3363,  3365,  3367,  3369
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  jsoniq_parser::yyrline_[] =
  {
         0,  1050,  1050,  1051,  1055,  1059,  1067,  1073,  1077,  1086,
    1092,  1100,  1106,  1117,  1122,  1131,  1138,  1145,  1154,  1161,
    1169,  1177,  1185,  1196,  1201,  1208,  1215,  1227,  1237,  1244,
    1251,  1263,  1264,  1265,  1266,  1267,  1272,  1273,  1274,  1275,
    1276,  1277,  1278,  1281,  1286,  1291,  1299,  1307,  1315,  1320,
    1328,  1333,  1341,  1346,  1354,  1359,  1364,  1369,  1377,  1379,
    1382,  1392,  1397,  1405,  1413,  1424,  1431,  1442,  1448,  1456,
    1463,  1470,  1479,  1493,  1502,  1509,  1519,  1526,  1533,  1544,
    1545,  1546,  1547,  1548,  1549,  1550,  1551,  1556,  1562,  1571,
    1578,  1588,  1598,  1599,  1600,  1601,  1602,  1603,  1604,  1605,
    1606,  1607,  1612,  1631,  1639,  1647,  1654,  1662,  1669,  1674,
    1682,  1690,  1704,  1718,  1735,  1740,  1748,  1756,  1767,  1772,
    1781,  1786,  1793,  1798,  1808,  1813,  1822,  1828,  1841,  1842,
    1847,  1862,  1877,  1893,  1908,  1913,  1918,  1923,  1931,  1938,
    1949,  1954,  1964,  1973,  1982,  1991,  2003,  2007,  2013,  2017,
    2027,  2037,  2050,  2056,  2065,  2070,  2077,  2084,  2095,  2105,
    2115,  2125,  2143,  2163,  2167,  2172,  2179,  2183,  2188,  2195,
    2200,  2212,  2219,  2229,  2244,  2245,  2246,  2247,  2248,  2249,
    2250,  2252,  2253,  2254,  2255,  2256,  2257,  2262,  2270,  2302,
    2310,  2318,  2325,  2332,  2343,  2352,  2361,  2370,  2383,  2391,
    2399,  2407,  2422,  2427,  2435,  2449,  2466,  2491,  2499,  2506,
    2517,  2526,  2534,  2539,  2552,  2569,  2570,  2571,  2572,  2573,
    2574,  2579,  2580,  2583,  2584,  2585,  2586,  2587,  2590,  2591,
    2592,  2593,  2594,  2599,  2613,  2621,  2624,  2632,  2637,  2645,
    2650,  2655,  2663,  2672,  2684,  2694,  2707,  2715,  2716,  2717,
    2722,  2723,  2724,  2725,  2726,  2731,  2738,  2748,  2753,  2762,
    2771,  2781,  2784,  2793,  2800,  2808,  2820,  2830,  2840,  2850,
    2860,  2870,  2880,  2890,  2901,  2910,  2920,  2930,  2946,  2955,
    2964,  2972,  2978,  2990,  2998,  3008,  3016,  3028,  3034,  3045,
    3047,  3051,  3059,  3063,  3068,  3072,  3076,  3080,  3090,  3098,
    3105,  3111,  3121,  3125,  3133,  3141,  3149,  3157,  3169,  3177,
    3183,  3193,  3199,  3209,  3213,  3223,  3229,  3235,  3241,  3250,
    3259,  3268,  3281,  3285,  3293,  3299,  3309,  3317,  3326,  3339,
    3346,  3358,  3362,  3374,  3381,  3387,  3396,  3403,  3409,  3420,
    3427,  3433,  3442,  3451,  3458,  3469,  3476,  3488,  3494,  3506,
    3512,  3523,  3529,  3540,  3546,  3557,  3563,  3574,  3583,  3587,
    3600,  3610,  3621,  3625,  3640,  3644,  3654,  3661,  3670,  3680,
    3679,  3697,  3706,  3715,  3728,  3732,  3744,  3748,  3756,  3759,
    3766,  3770,  3779,  3783,  3787,  3795,  3799,  3805,  3811,  3817,
    3827,  3831,  3835,  3843,  3847,  3853,  3863,  3867,  3877,  3881,
    3891,  3895,  3905,  3909,  3919,  3923,  3932,  3936,  3944,  3948,
    3952,  3956,  3966,  3967,  3968,  3972,  3977,  3985,  3989,  3993,
    3997,  4001,  4005,  4013,  4017,  4021,  4029,  4033,  4037,  4041,
    4052,  4062,  4068,  4078,  4082,  4086,  4092,  4096,  4106,  4116,
    4169,  4178,  4188,  4192,  4201,  4202,  4208,  4214,  4222,  4228,
    4241,  4247,  4258,  4262,  4266,  4270,  4274,  4280,  4286,  4295,
    4299,  4308,  4312,  4324,  4328,  4332,  4338,  4342,  4357,  4358,
    4364,  4368,  4378,  4382,  4386,  4390,  4402,  4407,  4411,  4415,
    4421,  4425,  4431,  4437,  4443,  4447,  4456,  4462,  4473,  4481,
    4482,  4483,  4484,  4485,  4486,  4487,  4488,  4489,  4490,  4493,
    4494,  4495,  4496,  4501,  4505,  4513,  4520,  4527,  4538,  4546,
    4550,  4558,  4569,  4577,  4583,  4587,  4609,  4615,  4621,  4627,
    4637,  4641,  4649,  4657,  4669,  4670,  4675,  4676,  4677,  4682,
    4690,  4707,  4715,  4732,  4751,  4775,  4781,  4792,  4798,  4809,
    4818,  4820,  4824,  4829,  4839,  4842,  4849,  4855,  4861,  4868,
    4880,  4883,  4890,  4896,  4902,  4909,  4920,  4924,  4932,  4936,
    4944,  4948,  4952,  4957,  4966,  4970,  4974,  4978,  4986,  4991,
    4999,  5005,  5014,  5022,  5027,  5032,  5037,  5042,  5047,  5052,
    5058,  5066,  5070,  5076,  5080,  5088,  5096,  5104,  5108,  5116,
    5120,  5128,  5136,  5140,  5144,  5150,  5159,  5165,  5171,  5181,
    5225,  5229,  5233,  5237,  5241,  5245,  5252,  5258,  5268,  5276,
    5284,  5288,  5292,  5296,  5300,  5304,  5308,  5312,  5316,  5320,
    5328,  5335,  5342,  5346,  5350,  5358,  5365,  5373,  5381,  5385,
    5390,  5398,  5402,  5408,  5414,  5418,  5428,  5436,  5440,  5446,
    5455,  5464,  5470,  5476,  5486,  5492,  5499,  5505,  5511,  5515,
    5523,  5531,  5535,  5546,  5552,  5558,  5564,  5574,  5578,  5584,
    5590,  5594,  5600,  5604,  5610,  5616,  5623,  5633,  5638,  5646,
    5652,  5662,  5668,  5677,  5683,  5696,  5702,  5709,  5715,  5725,
    5734,  5742,  5748,  5757,  5765,  5769,  5776,  5781,  5789,  5793,
    5800,  5804,  5811,  5815,  5822,  5826,  5835,  5848,  5851,  5859,
    5862,  5870,  5878,  5886,  5890,  5898,  5901,  5909,  5921,  5924,
    5932,  5944,  5950,  5960,  5963,  5971,  5975,  5979,  5987,  5990,
    5998,  6001,  6009,  6013,  6017,  6021,  6025,  6033,  6041,  6053,
    6065,  6069,  6073,  6081,  6087,  6097,  6101,  6105,  6109,  6113,
    6117,  6121,  6125,  6133,  6137,  6141,  6145,  6153,  6159,  6169,
    6179,  6183,  6191,  6201,  6212,  6219,  6223,  6231,  6234,  6241,
    6246,  6255,  6265,  6268,  6275,  6279,  6287,  6296,  6303,  6313,
    6317,  6324,  6330,  6340,  6343,  6350,  6355,  6367,  6375,  6387,
    6395,  6399,  6407,  6411,  6415,  6423,  6431,  6435,  6439,  6443,
    6451,  6459,  6471,  6475,  6483,  6489,  6493,  6500,  6504,  6511,
    6515,  6523,  6533,  6547,  6553,  6562,  6575,  6581,  6591,  6598,
    6606,  6618,  6628,  6635,  6645,  6670,  6699,  6727,  6759,  6786,
    6818,  6822,  6826,  6839,  6844,  6845,  6846,  6847,  6848,  6849,
    6850,  6851,  6852,  6853,  6854,  6855,  6856,  6857,  6858,  6859,
    6860,  6861,  6862,  6863,  6864,  6865,  6866,  6870,  6871,  6872,
    6873,  6874,  6875,  6876,  6877,  6878,  6879,  6880,  6881,  6882,
    6883,  6884,  6885,  6886,  6887,  6888,  6889,  6890,  6891,  6892,
    6893,  6894,  6895,  6896,  6897,  6898,  6899,  6900,  6901,  6902,
    6903,  6904,  6905,  6906,  6907,  6908,  6909,  6910,  6911,  6912,
    6913,  6914,  6915,  6916,  6917,  6918,  6919,  6920,  6921,  6922,
    6923,  6924,  6925,  6926,  6927,  6928,  6929,  6930,  6931,  6932,
    6933,  6934,  6935,  6936,  6937,  6938,  6939,  6940,  6941,  6942,
    6943,  6944,  6945,  6946,  6947,  6948,  6949,  6950,  6951,  6952,
    6953,  6954,  6955,  6956,  6957,  6958,  6959,  6960,  6961,  6962,
    6963,  6964,  6965,  6966,  6967,  6968,  6969,  6970,  6971,  6972,
    6973,  6974,  6975,  6976,  6977,  6978,  6979,  6980,  6981,  6982,
    6983,  6984,  6985,  6986,  6987,  6988,  6989,  6990,  6991,  6992,
    6993,  6994,  6995,  6996,  6997,  6998,  6999,  7000,  7001,  7002,
    7003,  7004,  7005,  7006,  7007,  7008,  7009,  7010,  7011,  7012,
    7013,  7014,  7015,  7016,  7017,  7018,  7019,  7020,  7021,  7022,
    7023,  7024,  7025,  7026,  7027,  7028,  7029,  7030,  7031,  7032,
    7033,  7034,  7035,  7036,  7037,  7038,  7039,  7040,  7041,  7042,
    7043,  7044,  7045,  7046,  7047,  7048,  7049,  7050,  7051,  7052,
    7053,  7054,  7055,  7056,  7057,  7058,  7059,  7060,  7061,  7062,
    7063,  7064,  7065,  7066,  7067,  7068,  7069,  7070,  7072,  7073,
    7074,  7075,  7076,  7082
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
     335,   336,   337,   338,   339
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int jsoniq_parser::yyeof_ = 0;
  const int jsoniq_parser::yylast_ = 22160;
  const int jsoniq_parser::yynnts_ = 327;
  const int jsoniq_parser::yyempty_ = -2;
  const int jsoniq_parser::yyfinal_ = 635;
  const int jsoniq_parser::yyterror_ = 1;
  const int jsoniq_parser::yyerrcode_ = 256;
  const int jsoniq_parser::yyntokens_ = 340;

  const unsigned int jsoniq_parser::yyuser_token_number_max_ = 594;
  const jsoniq_parser::token_number_type jsoniq_parser::yyundef_token_ = 2;


} // zorba
/* Line 1106 of lalr1.cc  */
#line 17580 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
/* Line 1107 of lalr1.cc  */
#line 7086 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"


namespace zorba {

static bool contains(const zstring& msg, const char* str1, const char* str2)
{
  zstring::size_type pos = msg.find(str1);

  if (pos == zstring::npos)
    return false;

  if (zstring(str2).size() == 0)
    return true;

  pos = msg.find(str2, pos);
  if (pos == zstring::npos)
    return false;

  return true;
}
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



      if ((msg.find("(missing comma \",\" between expressions?)") != string::npos &&
            ! contains(prevErr->msg, "expecting", ","))
          ||
          (msg.find("missing semicolon \";\" after") != string::npos &&
            ! contains(prevErr->msg, "expecting", ";")))
        return;
    }


    string message = msg;
    int pos;
    std::string unexpected_qname = "unexpected \"'QName'\"";
    if ((pos = message.find(unexpected_qname)) != -1)
      message = message.substr(0, pos) + "unexpected qualified name \"" + driver.symtab.get_last_qname() + "\"" + message.substr(pos+unexpected_qname.length());


    while ((pos = message.find("\"'")) != -1 || (pos = message.find("'\"")) != -1)
      message.replace(pos, 2, "\"");

    driver.set_expr(new ParseErrorNode(driver.createQueryLoc(loc), err::XPST0003, message));
  }
}

}
