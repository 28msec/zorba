/* A Bison parser, made by GNU Bison 2.7.12-4996.  */

/* Skeleton implementation for Bison LALR(1) parsers in C++
   
      Copyright (C) 2002-2013 Free Software Foundation, Inc.
   
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
/* Line 283 of lalr1.cc  */
#line 1 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"

#define XQUERY_PARSER
/* Line 283 of lalr1.cc  */
#line 58 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"


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

/* Line 283 of lalr1.cc  */
#line 101 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"


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


/* Line 283 of lalr1.cc  */
#line 98 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"


#include "xquery_parser.hpp"

/* User implementation prologue.  */
/* Line 289 of lalr1.cc  */
#line 785 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"

template<typename T> inline void release_hack( T *ref ) {
    if ( ref ) {
        RCHelper::addReference( ref );
        RCHelper::removeReference( ref );
    }
}

/* Line 289 of lalr1.cc  */
#line 115 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"


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
/* Line 357 of lalr1.cc  */
#line 210 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  xquery_parser::yytnamerr_ (const char *yystr)
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
  xquery_parser::xquery_parser (xquery_driver& driver_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      driver (driver_yyarg)
  {
  }

  xquery_parser::~xquery_parser ()
  {
  }

#if YYDEBUG
  /*--------------------------------.
  | Print this symbol on YYOUTPUT.  |
  `--------------------------------*/

  inline void
  xquery_parser::yy_symbol_value_print_ (int yytype,
			   const semantic_type* yyvaluep, const location_type* yylocationp)
  {
    YYUSE (yylocationp);
    YYUSE (yyvaluep);
    std::ostream& yyo = debug_stream ();
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    YYUSE (yytype);
  }


  void
  xquery_parser::yy_symbol_print_ (int yytype,
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
  xquery_parser::yydestruct_ (const char* yymsg,
			   int yytype, semantic_type* yyvaluep, location_type* yylocationp)
  {
    YYUSE (yylocationp);
    YYUSE (yymsg);
    YYUSE (yyvaluep);

    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

    switch (yytype)
    {
      case 111: /* "'DECIMAL'" */
/* Line 452 of lalr1.cc  */
#line 784 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { delete ((*yyvaluep).decval); };
/* Line 452 of lalr1.cc  */
#line 313 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 125: /* "'DOUBLE'" */
/* Line 452 of lalr1.cc  */
#line 783 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { delete ((*yyvaluep).dval); };
/* Line 452 of lalr1.cc  */
#line 320 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 150: /* "'INTEGER'" */
/* Line 452 of lalr1.cc  */
#line 782 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { delete ((*yyvaluep).ival); };
/* Line 452 of lalr1.cc  */
#line 327 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 340: /* VersionDecl */
/* Line 452 of lalr1.cc  */
#line 805 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 334 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 341: /* MainModule */
/* Line 452 of lalr1.cc  */
#line 798 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 341 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 342: /* LibraryModule */
/* Line 452 of lalr1.cc  */
#line 798 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 348 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 343: /* ModuleDecl */
/* Line 452 of lalr1.cc  */
#line 798 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 355 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 344: /* SIND_DeclList */
/* Line 452 of lalr1.cc  */
#line 801 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 362 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 345: /* SIND_Decl */
/* Line 452 of lalr1.cc  */
#line 801 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 369 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 346: /* Setter */
/* Line 452 of lalr1.cc  */
#line 802 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 376 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 347: /* BoundarySpaceDecl */
/* Line 452 of lalr1.cc  */
#line 795 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 383 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 348: /* DefaultCollationDecl */
/* Line 452 of lalr1.cc  */
#line 796 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 390 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 349: /* BaseURIDecl */
/* Line 452 of lalr1.cc  */
#line 795 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 397 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 350: /* ConstructionDecl */
/* Line 452 of lalr1.cc  */
#line 795 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 404 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 351: /* OrderingModeDecl */
/* Line 452 of lalr1.cc  */
#line 800 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 411 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 352: /* EmptyOrderDecl */
/* Line 452 of lalr1.cc  */
#line 797 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 418 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 353: /* CopyNamespacesDecl */
/* Line 452 of lalr1.cc  */
#line 796 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 425 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 354: /* Import */
/* Line 452 of lalr1.cc  */
#line 797 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 432 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 355: /* SchemaImport */
/* Line 452 of lalr1.cc  */
#line 801 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 439 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 356: /* URILiteralList */
/* Line 452 of lalr1.cc  */
#line 803 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 446 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 357: /* SchemaPrefix */
/* Line 452 of lalr1.cc  */
#line 802 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 453 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 358: /* ModuleImport */
/* Line 452 of lalr1.cc  */
#line 798 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 460 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 359: /* NamespaceDecl */
/* Line 452 of lalr1.cc  */
#line 798 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 467 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 360: /* DefaultNamespaceDecl */
/* Line 452 of lalr1.cc  */
#line 796 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 474 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 361: /* VFO_DeclList */
/* Line 452 of lalr1.cc  */
#line 805 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 481 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 362: /* VFO_Decl */
/* Line 452 of lalr1.cc  */
#line 805 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 488 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 363: /* DecimalFormatDecl */
/* Line 452 of lalr1.cc  */
#line 805 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 495 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 364: /* DecimalFormatParamList */
/* Line 452 of lalr1.cc  */
#line 812 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { delete ((*yyvaluep).vstrpair); };
/* Line 452 of lalr1.cc  */
#line 502 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 365: /* DecimalFormatParam */
/* Line 452 of lalr1.cc  */
#line 812 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { delete ((*yyvaluep).strpair); };
/* Line 452 of lalr1.cc  */
#line 509 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 367: /* OptionDecl */
/* Line 452 of lalr1.cc  */
#line 799 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 516 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 368: /* FTOptionDecl */
/* Line 452 of lalr1.cc  */
#line 808 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 523 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 369: /* CtxItemDecl */
/* Line 452 of lalr1.cc  */
#line 803 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 530 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 370: /* CtxItemDecl2 */
/* Line 452 of lalr1.cc  */
#line 803 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 537 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 371: /* CtxItemDecl3 */
/* Line 452 of lalr1.cc  */
#line 803 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 544 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 372: /* CtxItemDecl4 */
/* Line 452 of lalr1.cc  */
#line 804 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 551 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 373: /* VarDecl */
/* Line 452 of lalr1.cc  */
#line 804 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 558 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 374: /* VarNameAndType */
/* Line 452 of lalr1.cc  */
#line 812 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { delete ((*yyvaluep).varnametype); };
/* Line 452 of lalr1.cc  */
#line 565 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 375: /* AnnotationList */
/* Line 452 of lalr1.cc  */
#line 794 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 572 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 376: /* Annotation */
/* Line 452 of lalr1.cc  */
#line 794 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 579 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 377: /* AnnotationLiteralList */
/* Line 452 of lalr1.cc  */
#line 794 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 586 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 378: /* FunctionDecl */
/* Line 452 of lalr1.cc  */
#line 797 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 593 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 379: /* FunctionDecl2 */
/* Line 452 of lalr1.cc  */
#line 797 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 600 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 380: /* FunctionDeclSimple */
/* Line 452 of lalr1.cc  */
#line 797 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 607 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 381: /* FunctionDeclUpdating */
/* Line 452 of lalr1.cc  */
#line 797 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 614 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 382: /* FunctionSig */
/* Line 452 of lalr1.cc  */
#line 812 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { delete ((*yyvaluep).fnsig); };
/* Line 452 of lalr1.cc  */
#line 621 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 383: /* ParamList */
/* Line 452 of lalr1.cc  */
#line 800 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 628 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 384: /* Param */
/* Line 452 of lalr1.cc  */
#line 800 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 635 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 385: /* CollectionDecl */
/* Line 452 of lalr1.cc  */
#line 803 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 642 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 387: /* IndexDecl */
/* Line 452 of lalr1.cc  */
#line 803 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 649 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 388: /* IndexKeyList */
/* Line 452 of lalr1.cc  */
#line 803 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 656 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 389: /* IndexKeySpec */
/* Line 452 of lalr1.cc  */
#line 803 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 663 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 390: /* IntegrityConstraintDecl */
/* Line 452 of lalr1.cc  */
#line 803 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 670 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 391: /* QueryBody */
/* Line 452 of lalr1.cc  */
#line 811 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 452 of lalr1.cc  */
#line 677 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 392: /* StatementsAndOptionalExprTop */
/* Line 452 of lalr1.cc  */
#line 811 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 452 of lalr1.cc  */
#line 684 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 393: /* StatementsAndOptionalExpr */
/* Line 452 of lalr1.cc  */
#line 811 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 452 of lalr1.cc  */
#line 691 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 394: /* StatementsAndExpr */
/* Line 452 of lalr1.cc  */
#line 811 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 452 of lalr1.cc  */
#line 698 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 395: /* Statements */
/* Line 452 of lalr1.cc  */
#line 811 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 452 of lalr1.cc  */
#line 705 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 396: /* Statement */
/* Line 452 of lalr1.cc  */
#line 811 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 452 of lalr1.cc  */
#line 712 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 397: /* BlockStatement */
/* Line 452 of lalr1.cc  */
#line 811 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 452 of lalr1.cc  */
#line 719 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 398: /* BlockExpr */
/* Line 452 of lalr1.cc  */
#line 811 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 452 of lalr1.cc  */
#line 726 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 399: /* EnclosedStatementsAndOptionalExpr */
/* Line 452 of lalr1.cc  */
#line 811 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 452 of lalr1.cc  */
#line 733 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 400: /* VarDeclStatement */
/* Line 452 of lalr1.cc  */
#line 811 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 452 of lalr1.cc  */
#line 740 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 403: /* AssignStatement */
/* Line 452 of lalr1.cc  */
#line 811 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 452 of lalr1.cc  */
#line 747 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 404: /* ApplyStatement */
/* Line 452 of lalr1.cc  */
#line 811 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 452 of lalr1.cc  */
#line 754 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 405: /* ExitStatement */
/* Line 452 of lalr1.cc  */
#line 811 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 452 of lalr1.cc  */
#line 761 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 406: /* WhileStatement */
/* Line 452 of lalr1.cc  */
#line 811 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 452 of lalr1.cc  */
#line 768 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 407: /* FlowCtlStatement */
/* Line 452 of lalr1.cc  */
#line 811 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 452 of lalr1.cc  */
#line 775 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 408: /* FLWORStatement */
/* Line 452 of lalr1.cc  */
#line 811 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 452 of lalr1.cc  */
#line 782 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 409: /* ReturnStatement */
/* Line 452 of lalr1.cc  */
#line 811 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 452 of lalr1.cc  */
#line 789 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 410: /* IfStatement */
/* Line 452 of lalr1.cc  */
#line 811 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 452 of lalr1.cc  */
#line 796 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 411: /* TryStatement */
/* Line 452 of lalr1.cc  */
#line 811 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 452 of lalr1.cc  */
#line 803 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 412: /* CatchListStatement */
/* Line 452 of lalr1.cc  */
#line 811 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 452 of lalr1.cc  */
#line 810 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 413: /* CatchStatement */
/* Line 452 of lalr1.cc  */
#line 811 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 452 of lalr1.cc  */
#line 817 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 414: /* Expr */
/* Line 452 of lalr1.cc  */
#line 811 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 452 of lalr1.cc  */
#line 824 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 415: /* ExprSingle */
/* Line 452 of lalr1.cc  */
#line 811 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 452 of lalr1.cc  */
#line 831 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 416: /* ExprSimple */
/* Line 452 of lalr1.cc  */
#line 811 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 452 of lalr1.cc  */
#line 838 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 417: /* FLWORExpr */
/* Line 452 of lalr1.cc  */
#line 811 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 452 of lalr1.cc  */
#line 845 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 418: /* ReturnExpr */
/* Line 452 of lalr1.cc  */
#line 811 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 452 of lalr1.cc  */
#line 852 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 421: /* FLWORWinCond */
/* Line 452 of lalr1.cc  */
#line 804 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 859 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 422: /* WindowClause */
/* Line 452 of lalr1.cc  */
#line 797 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 866 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 423: /* CountClause */
/* Line 452 of lalr1.cc  */
#line 805 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 873 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 424: /* ForLetWinClause */
/* Line 452 of lalr1.cc  */
#line 797 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 880 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 426: /* FLWORClauseList */
/* Line 452 of lalr1.cc  */
#line 797 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 887 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 427: /* ForClause */
/* Line 452 of lalr1.cc  */
#line 797 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 894 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 428: /* VarInDeclList */
/* Line 452 of lalr1.cc  */
#line 804 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 901 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 429: /* VarInDecl */
/* Line 452 of lalr1.cc  */
#line 804 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 908 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 430: /* PositionalVar */
/* Line 452 of lalr1.cc  */
#line 800 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 915 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 431: /* FTScoreVar */
/* Line 452 of lalr1.cc  */
#line 808 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 922 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 432: /* LetClause */
/* Line 452 of lalr1.cc  */
#line 798 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 929 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 433: /* VarGetsDeclList */
/* Line 452 of lalr1.cc  */
#line 804 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 936 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 434: /* VarGetsDecl */
/* Line 452 of lalr1.cc  */
#line 804 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 943 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 435: /* WindowVarDecl */
/* Line 452 of lalr1.cc  */
#line 804 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 950 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 436: /* WindowVars */
/* Line 452 of lalr1.cc  */
#line 804 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 957 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 437: /* WindowVars3 */
/* Line 452 of lalr1.cc  */
#line 804 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 964 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 438: /* WindowVars2 */
/* Line 452 of lalr1.cc  */
#line 804 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 971 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 439: /* WhereClause */
/* Line 452 of lalr1.cc  */
#line 805 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 978 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 440: /* GroupByClause */
/* Line 452 of lalr1.cc  */
#line 799 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 985 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 441: /* GroupSpecList */
/* Line 452 of lalr1.cc  */
#line 799 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 992 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 442: /* GroupSpec */
/* Line 452 of lalr1.cc  */
#line 799 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 999 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 443: /* GroupCollationSpec */
/* Line 452 of lalr1.cc  */
#line 799 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 1006 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 444: /* OrderByClause */
/* Line 452 of lalr1.cc  */
#line 799 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 1013 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 445: /* OrderSpecList */
/* Line 452 of lalr1.cc  */
#line 800 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 1020 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 446: /* OrderSpec */
/* Line 452 of lalr1.cc  */
#line 800 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 1027 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 447: /* OrderModifier */
/* Line 452 of lalr1.cc  */
#line 799 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 1034 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 448: /* OrderDirSpec */
/* Line 452 of lalr1.cc  */
#line 799 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 1041 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 449: /* OrderEmptySpec */
/* Line 452 of lalr1.cc  */
#line 799 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 1048 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 450: /* OrderCollationSpec */
/* Line 452 of lalr1.cc  */
#line 799 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 1055 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 451: /* QuantifiedExpr */
/* Line 452 of lalr1.cc  */
#line 811 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 452 of lalr1.cc  */
#line 1062 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 452: /* QVarInDeclList */
/* Line 452 of lalr1.cc  */
#line 800 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 1069 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 453: /* QVarInDecl */
/* Line 452 of lalr1.cc  */
#line 800 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 1076 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 454: /* SwitchExpr */
/* Line 452 of lalr1.cc  */
#line 811 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 452 of lalr1.cc  */
#line 1083 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 455: /* SwitchCaseClauseList */
/* Line 452 of lalr1.cc  */
#line 806 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 1090 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 456: /* SwitchCaseClause */
/* Line 452 of lalr1.cc  */
#line 806 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 1097 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 457: /* SwitchCaseOperandList */
/* Line 452 of lalr1.cc  */
#line 806 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 1104 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 458: /* SwitchStatement */
/* Line 452 of lalr1.cc  */
#line 811 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 452 of lalr1.cc  */
#line 1111 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 461: /* TypeswitchExpr */
/* Line 452 of lalr1.cc  */
#line 811 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 452 of lalr1.cc  */
#line 1118 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 462: /* TypeswitchStatement */
/* Line 452 of lalr1.cc  */
#line 811 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 452 of lalr1.cc  */
#line 1125 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 463: /* CaseClauseList */
/* Line 452 of lalr1.cc  */
#line 795 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 1132 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 464: /* CaseClause */
/* Line 452 of lalr1.cc  */
#line 795 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 1139 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 467: /* SequenceTypeList */
/* Line 452 of lalr1.cc  */
#line 802 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 1146 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 468: /* IfExpr */
/* Line 452 of lalr1.cc  */
#line 811 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 452 of lalr1.cc  */
#line 1153 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 469: /* OrExpr */
/* Line 452 of lalr1.cc  */
#line 811 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 452 of lalr1.cc  */
#line 1160 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 470: /* AndExpr */
/* Line 452 of lalr1.cc  */
#line 811 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 452 of lalr1.cc  */
#line 1167 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 471: /* ComparisonExpr */
/* Line 452 of lalr1.cc  */
#line 811 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 452 of lalr1.cc  */
#line 1174 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 473: /* FTContainsExpr */
/* Line 452 of lalr1.cc  */
#line 811 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 452 of lalr1.cc  */
#line 1181 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 474: /* StringConcatExpr */
/* Line 452 of lalr1.cc  */
#line 811 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 452 of lalr1.cc  */
#line 1188 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 475: /* opt_FTIgnoreOption */
/* Line 452 of lalr1.cc  */
#line 808 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 1195 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 476: /* RangeExpr */
/* Line 452 of lalr1.cc  */
#line 811 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 452 of lalr1.cc  */
#line 1202 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 477: /* AdditiveExpr */
/* Line 452 of lalr1.cc  */
#line 811 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 452 of lalr1.cc  */
#line 1209 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 478: /* MultiplicativeExpr */
/* Line 452 of lalr1.cc  */
#line 811 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 452 of lalr1.cc  */
#line 1216 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 479: /* UnionExpr */
/* Line 452 of lalr1.cc  */
#line 811 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 452 of lalr1.cc  */
#line 1223 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 480: /* IntersectExceptExpr */
/* Line 452 of lalr1.cc  */
#line 811 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 452 of lalr1.cc  */
#line 1230 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 481: /* InstanceofExpr */
/* Line 452 of lalr1.cc  */
#line 811 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 452 of lalr1.cc  */
#line 1237 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 482: /* TreatExpr */
/* Line 452 of lalr1.cc  */
#line 811 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 452 of lalr1.cc  */
#line 1244 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 483: /* CastableExpr */
/* Line 452 of lalr1.cc  */
#line 811 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 452 of lalr1.cc  */
#line 1251 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 484: /* CastExpr */
/* Line 452 of lalr1.cc  */
#line 811 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 452 of lalr1.cc  */
#line 1258 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 485: /* SingleType */
/* Line 452 of lalr1.cc  */
#line 802 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 1265 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 486: /* UnaryExpr */
/* Line 452 of lalr1.cc  */
#line 811 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 452 of lalr1.cc  */
#line 1272 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 487: /* SignList */
/* Line 452 of lalr1.cc  */
#line 802 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 1279 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 488: /* ValueExpr */
/* Line 452 of lalr1.cc  */
#line 811 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 452 of lalr1.cc  */
#line 1286 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 489: /* SimpleMapExpr */
/* Line 452 of lalr1.cc  */
#line 811 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 452 of lalr1.cc  */
#line 1293 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 490: /* ValueComp */
/* Line 452 of lalr1.cc  */
#line 803 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 1300 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 491: /* NodeComp */
/* Line 452 of lalr1.cc  */
#line 807 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 1307 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 492: /* ValidateExpr */
/* Line 452 of lalr1.cc  */
#line 811 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 452 of lalr1.cc  */
#line 1314 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 493: /* ExtensionExpr */
/* Line 452 of lalr1.cc  */
#line 811 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 452 of lalr1.cc  */
#line 1321 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 494: /* Pragma_list */
/* Line 452 of lalr1.cc  */
#line 800 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 1328 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 495: /* Pragma */
/* Line 452 of lalr1.cc  */
#line 800 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 1335 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 496: /* PathExpr */
/* Line 452 of lalr1.cc  */
#line 811 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 452 of lalr1.cc  */
#line 1342 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 498: /* RelativePathExpr */
/* Line 452 of lalr1.cc  */
#line 811 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 452 of lalr1.cc  */
#line 1349 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 499: /* StepExpr */
/* Line 452 of lalr1.cc  */
#line 811 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 452 of lalr1.cc  */
#line 1356 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 500: /* AxisStep */
/* Line 452 of lalr1.cc  */
#line 810 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 452 of lalr1.cc  */
#line 1363 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 501: /* ForwardStep */
/* Line 452 of lalr1.cc  */
#line 793 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 1370 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 502: /* ForwardAxis */
/* Line 452 of lalr1.cc  */
#line 793 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 1377 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 503: /* AbbrevForwardStep */
/* Line 452 of lalr1.cc  */
#line 793 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 1384 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 504: /* ReverseStep */
/* Line 452 of lalr1.cc  */
#line 793 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 1391 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 505: /* ReverseAxis */
/* Line 452 of lalr1.cc  */
#line 793 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 1398 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 506: /* NodeTest */
/* Line 452 of lalr1.cc  */
#line 793 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 1405 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 507: /* NameTest */
/* Line 452 of lalr1.cc  */
#line 798 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 1412 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 508: /* Wildcard */
/* Line 452 of lalr1.cc  */
#line 805 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 1419 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 509: /* FilterExpr */
/* Line 452 of lalr1.cc  */
#line 811 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 452 of lalr1.cc  */
#line 1426 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 510: /* PredicateList */
/* Line 452 of lalr1.cc  */
#line 800 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 1433 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 511: /* Predicate */
/* Line 452 of lalr1.cc  */
#line 811 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 452 of lalr1.cc  */
#line 1440 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 512: /* PrimaryExpr */
/* Line 452 of lalr1.cc  */
#line 811 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 452 of lalr1.cc  */
#line 1447 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 513: /* Literal */
/* Line 452 of lalr1.cc  */
#line 811 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 452 of lalr1.cc  */
#line 1454 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 514: /* NumericLiteral */
/* Line 452 of lalr1.cc  */
#line 811 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 452 of lalr1.cc  */
#line 1461 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 515: /* VarRef */
/* Line 452 of lalr1.cc  */
#line 811 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 452 of lalr1.cc  */
#line 1468 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 516: /* ParenthesizedExpr */
/* Line 452 of lalr1.cc  */
#line 811 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 452 of lalr1.cc  */
#line 1475 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 517: /* ContextItemExpr */
/* Line 452 of lalr1.cc  */
#line 811 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 452 of lalr1.cc  */
#line 1482 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 518: /* OrderedExpr */
/* Line 452 of lalr1.cc  */
#line 811 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 452 of lalr1.cc  */
#line 1489 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 519: /* UnorderedExpr */
/* Line 452 of lalr1.cc  */
#line 811 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 452 of lalr1.cc  */
#line 1496 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 520: /* FunctionCall */
/* Line 452 of lalr1.cc  */
#line 811 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 452 of lalr1.cc  */
#line 1503 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 521: /* ArgList */
/* Line 452 of lalr1.cc  */
#line 794 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 1510 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 525: /* Constructor */
/* Line 452 of lalr1.cc  */
#line 811 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 452 of lalr1.cc  */
#line 1517 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 526: /* DirectConstructor */
/* Line 452 of lalr1.cc  */
#line 811 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 452 of lalr1.cc  */
#line 1524 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 527: /* DirElemConstructor */
/* Line 452 of lalr1.cc  */
#line 811 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 452 of lalr1.cc  */
#line 1531 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 528: /* DirElemContentList */
/* Line 452 of lalr1.cc  */
#line 796 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 1538 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 529: /* DirAttributeList */
/* Line 452 of lalr1.cc  */
#line 796 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 1545 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 530: /* DirAttr */
/* Line 452 of lalr1.cc  */
#line 796 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 1552 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 532: /* DirAttributeValue */
/* Line 452 of lalr1.cc  */
#line 796 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 1559 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 533: /* opt_QuoteAttrContentList */
/* Line 452 of lalr1.cc  */
#line 801 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 1566 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 534: /* QuoteAttrContentList */
/* Line 452 of lalr1.cc  */
#line 801 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 1573 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 535: /* opt_AposAttrContentList */
/* Line 452 of lalr1.cc  */
#line 794 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 1580 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 536: /* AposAttrContentList */
/* Line 452 of lalr1.cc  */
#line 794 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 1587 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 537: /* QuoteAttrValueContent */
/* Line 452 of lalr1.cc  */
#line 801 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 1594 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 538: /* AposAttrValueContent */
/* Line 452 of lalr1.cc  */
#line 794 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 1601 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 539: /* DirElemContent */
/* Line 452 of lalr1.cc  */
#line 811 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 452 of lalr1.cc  */
#line 1608 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 540: /* CommonContent */
/* Line 452 of lalr1.cc  */
#line 811 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 452 of lalr1.cc  */
#line 1615 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 541: /* DirCommentConstructor */
/* Line 452 of lalr1.cc  */
#line 811 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 452 of lalr1.cc  */
#line 1622 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 542: /* DirPIConstructor */
/* Line 452 of lalr1.cc  */
#line 811 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 452 of lalr1.cc  */
#line 1629 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 543: /* CDataSection */
/* Line 452 of lalr1.cc  */
#line 811 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 452 of lalr1.cc  */
#line 1636 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 544: /* ComputedConstructor */
/* Line 452 of lalr1.cc  */
#line 811 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 452 of lalr1.cc  */
#line 1643 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 545: /* CompDocConstructor */
/* Line 452 of lalr1.cc  */
#line 811 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 452 of lalr1.cc  */
#line 1650 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 546: /* CompElemConstructor */
/* Line 452 of lalr1.cc  */
#line 811 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 452 of lalr1.cc  */
#line 1657 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 547: /* CompAttrConstructor */
/* Line 452 of lalr1.cc  */
#line 811 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 452 of lalr1.cc  */
#line 1664 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 548: /* CompTextConstructor */
/* Line 452 of lalr1.cc  */
#line 811 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 452 of lalr1.cc  */
#line 1671 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 549: /* CompCommentConstructor */
/* Line 452 of lalr1.cc  */
#line 811 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 452 of lalr1.cc  */
#line 1678 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 550: /* CompPIConstructor */
/* Line 452 of lalr1.cc  */
#line 811 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 452 of lalr1.cc  */
#line 1685 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 551: /* CompNamespaceConstructor */
/* Line 452 of lalr1.cc  */
#line 811 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 452 of lalr1.cc  */
#line 1692 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 552: /* TypeDeclaration */
/* Line 452 of lalr1.cc  */
#line 802 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 1699 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 553: /* SequenceType */
/* Line 452 of lalr1.cc  */
#line 802 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 1706 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 554: /* OccurrenceIndicator */
/* Line 452 of lalr1.cc  */
#line 798 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 1713 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 555: /* ItemType */
/* Line 452 of lalr1.cc  */
#line 798 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 1720 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 556: /* TypeList */
/* Line 452 of lalr1.cc  */
#line 805 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 1727 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 557: /* GeneralizedAtomicType */
/* Line 452 of lalr1.cc  */
#line 795 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 1734 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 558: /* SimpleType */
/* Line 452 of lalr1.cc  */
#line 795 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 1741 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 559: /* KindTest */
/* Line 452 of lalr1.cc  */
#line 798 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 1748 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 560: /* AnyKindTest */
/* Line 452 of lalr1.cc  */
#line 794 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 1755 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 562: /* DocumentTest */
/* Line 452 of lalr1.cc  */
#line 796 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 1762 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 563: /* NamespaceTest */
/* Line 452 of lalr1.cc  */
#line 802 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 1769 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 564: /* TextTest */
/* Line 452 of lalr1.cc  */
#line 802 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 1776 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 565: /* CommentTest */
/* Line 452 of lalr1.cc  */
#line 795 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 1783 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 566: /* PITest */
/* Line 452 of lalr1.cc  */
#line 800 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 1790 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 567: /* AttributeTest */
/* Line 452 of lalr1.cc  */
#line 795 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 1797 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 568: /* SchemaAttributeTest */
/* Line 452 of lalr1.cc  */
#line 801 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 1804 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 569: /* ElementTest */
/* Line 452 of lalr1.cc  */
#line 796 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 1811 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 570: /* SchemaElementTest */
/* Line 452 of lalr1.cc  */
#line 801 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 1818 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 571: /* TypeName */
/* Line 452 of lalr1.cc  */
#line 802 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 1825 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 572: /* TypeName_WITH_HOOK */
/* Line 452 of lalr1.cc  */
#line 802 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 1832 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 573: /* StringLiteral */
/* Line 452 of lalr1.cc  */
#line 811 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 452 of lalr1.cc  */
#line 1839 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 575: /* AnyFunctionTest */
/* Line 452 of lalr1.cc  */
#line 805 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 1846 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 576: /* TypedFunctionTest */
/* Line 452 of lalr1.cc  */
#line 805 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 1853 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 579: /* InsertExpr */
/* Line 452 of lalr1.cc  */
#line 811 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 452 of lalr1.cc  */
#line 1860 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 580: /* DeleteExpr */
/* Line 452 of lalr1.cc  */
#line 811 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 452 of lalr1.cc  */
#line 1867 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 581: /* ReplaceExpr */
/* Line 452 of lalr1.cc  */
#line 811 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 452 of lalr1.cc  */
#line 1874 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 582: /* RenameExpr */
/* Line 452 of lalr1.cc  */
#line 811 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 452 of lalr1.cc  */
#line 1881 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 583: /* TransformExpr */
/* Line 452 of lalr1.cc  */
#line 811 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 452 of lalr1.cc  */
#line 1888 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 584: /* VarNameList */
/* Line 452 of lalr1.cc  */
#line 811 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 452 of lalr1.cc  */
#line 1895 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 585: /* VarNameDecl */
/* Line 452 of lalr1.cc  */
#line 811 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 452 of lalr1.cc  */
#line 1902 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 586: /* TryExpr */
/* Line 452 of lalr1.cc  */
#line 811 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 452 of lalr1.cc  */
#line 1909 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 587: /* CatchListExpr */
/* Line 452 of lalr1.cc  */
#line 811 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 452 of lalr1.cc  */
#line 1916 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 588: /* CatchExpr */
/* Line 452 of lalr1.cc  */
#line 811 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 452 of lalr1.cc  */
#line 1923 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 589: /* BracedExpr */
/* Line 452 of lalr1.cc  */
#line 811 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 452 of lalr1.cc  */
#line 1930 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 590: /* NameTestList */
/* Line 452 of lalr1.cc  */
#line 812 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { delete ((*yyvaluep).name_test_list); };
/* Line 452 of lalr1.cc  */
#line 1937 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 591: /* FTSelection */
/* Line 452 of lalr1.cc  */
#line 808 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 1944 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 594: /* FTOr */
/* Line 452 of lalr1.cc  */
#line 808 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 1951 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 595: /* FTAnd */
/* Line 452 of lalr1.cc  */
#line 808 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 1958 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 596: /* FTMildNot */
/* Line 452 of lalr1.cc  */
#line 808 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 1965 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 597: /* FTUnaryNot */
/* Line 452 of lalr1.cc  */
#line 808 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 1972 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 598: /* FTPrimaryWithOptions */
/* Line 452 of lalr1.cc  */
#line 808 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 1979 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 599: /* opt_FTMatchOptions */
/* Line 452 of lalr1.cc  */
#line 808 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 1986 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 601: /* FTWeight */
/* Line 452 of lalr1.cc  */
#line 808 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 1993 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 602: /* FTPrimary */
/* Line 452 of lalr1.cc  */
#line 808 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 2000 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 603: /* opt_FTTimes */
/* Line 452 of lalr1.cc  */
#line 808 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 2007 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 604: /* FTExtensionSelection */
/* Line 452 of lalr1.cc  */
#line 808 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 2014 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 606: /* FTWords */
/* Line 452 of lalr1.cc  */
#line 808 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 2021 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 607: /* FTWordsValue */
/* Line 452 of lalr1.cc  */
#line 808 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 2028 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 609: /* FTAnyallOption */
/* Line 452 of lalr1.cc  */
#line 808 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 2035 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 612: /* FTPosFilter */
/* Line 452 of lalr1.cc  */
#line 808 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 2042 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 613: /* FTOrder */
/* Line 452 of lalr1.cc  */
#line 808 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 2049 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 614: /* FTWindow */
/* Line 452 of lalr1.cc  */
#line 808 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 2056 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 615: /* FTDistance */
/* Line 452 of lalr1.cc  */
#line 808 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 2063 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 616: /* FTUnit */
/* Line 452 of lalr1.cc  */
#line 808 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 2070 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 617: /* FTMatchOptions */
/* Line 452 of lalr1.cc  */
#line 808 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 2077 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 618: /* FTMatchOption */
/* Line 452 of lalr1.cc  */
#line 808 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 2084 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 619: /* FTCaseOption */
/* Line 452 of lalr1.cc  */
#line 808 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 2091 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 620: /* FTDiacriticsOption */
/* Line 452 of lalr1.cc  */
#line 808 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 2098 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 621: /* FTExtensionOption */
/* Line 452 of lalr1.cc  */
#line 808 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 2105 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 622: /* FTStemOption */
/* Line 452 of lalr1.cc  */
#line 808 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 2112 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 623: /* FTThesaurusOption */
/* Line 452 of lalr1.cc  */
#line 808 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 2119 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 627: /* FTThesaurusID */
/* Line 452 of lalr1.cc  */
#line 808 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 2126 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 630: /* FTStopWordOption */
/* Line 452 of lalr1.cc  */
#line 808 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 2133 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 631: /* FTStopWords */
/* Line 452 of lalr1.cc  */
#line 808 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 2140 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 635: /* FTStopWordsInclExcl */
/* Line 452 of lalr1.cc  */
#line 808 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 2147 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 636: /* FTLanguageOption */
/* Line 452 of lalr1.cc  */
#line 808 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 2154 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 637: /* FTWildCardOption */
/* Line 452 of lalr1.cc  */
#line 808 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 2161 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 638: /* FTContent */
/* Line 452 of lalr1.cc  */
#line 808 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 2168 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 639: /* FTTimes */
/* Line 452 of lalr1.cc  */
#line 808 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 2175 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 640: /* FTRange */
/* Line 452 of lalr1.cc  */
#line 808 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 2182 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 641: /* FTScope */
/* Line 452 of lalr1.cc  */
#line 808 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 2189 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 642: /* FTBigUnit */
/* Line 452 of lalr1.cc  */
#line 808 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 2196 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 643: /* FTIgnoreOption */
/* Line 452 of lalr1.cc  */
#line 808 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 2203 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 644: /* JSONArrayConstructor */
/* Line 452 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 452 of lalr1.cc  */
#line 2210 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 645: /* JSONSimpleObjectUnion */
/* Line 452 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 452 of lalr1.cc  */
#line 2217 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 646: /* JSONAccumulatorObjectUnion */
/* Line 452 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 452 of lalr1.cc  */
#line 2224 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 647: /* JSONObjectConstructor */
/* Line 452 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 452 of lalr1.cc  */
#line 2231 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 648: /* JSONPairList */
/* Line 452 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 452 of lalr1.cc  */
#line 2238 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 649: /* JSONInsertExpr */
/* Line 452 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 452 of lalr1.cc  */
#line 2245 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 650: /* JSONAppendExpr */
/* Line 452 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 452 of lalr1.cc  */
#line 2252 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 651: /* JSONDeleteExpr */
/* Line 452 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 452 of lalr1.cc  */
#line 2259 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 652: /* JSONRenameExpr */
/* Line 452 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 452 of lalr1.cc  */
#line 2266 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 653: /* JSONReplaceExpr */
/* Line 452 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 452 of lalr1.cc  */
#line 2273 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 659: /* QNAME */
/* Line 452 of lalr1.cc  */
#line 811 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 452 of lalr1.cc  */
#line 2280 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 660: /* FUNCTION_NAME */
/* Line 452 of lalr1.cc  */
#line 811 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 452 of lalr1.cc  */
#line 2287 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;
      case 661: /* EQNAME */
/* Line 452 of lalr1.cc  */
#line 811 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 452 of lalr1.cc  */
#line 2294 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
        break;

      default:
        break;
    }
  }

  void
  xquery_parser::yypop_ (unsigned int n)
  {
    yystate_stack_.pop (n);
    yysemantic_stack_.pop (n);
    yylocation_stack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  xquery_parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  xquery_parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  xquery_parser::debug_level_type
  xquery_parser::debug_level () const
  {
    return yydebug_;
  }

  void
  xquery_parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif

  inline bool
  xquery_parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  inline bool
  xquery_parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  xquery_parser::parse ()
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
/* Line 539 of lalr1.cc  */
#line 127 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
{
    yylloc.begin.filename = yylloc.end.filename = &(driver.theFilename2);
}
/* Line 539 of lalr1.cc  */
#line 2394 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"

    /* Initialize the stacks.  The initial state will be pushed in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystate_stack_.clear ();
    yysemantic_stack_.clear ();
    yylocation_stack_.clear ();
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
/* Line 664 of lalr1.cc  */
#line 848 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      }
    break;

  case 4:
/* Line 664 of lalr1.cc  */
#line 852 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      }
    break;

  case 5:
/* Line 664 of lalr1.cc  */
#line 856 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      }
    break;

  case 6:
/* Line 664 of lalr1.cc  */
#line 862 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = NULL;
      }
    break;

  case 7:
/* Line 664 of lalr1.cc  */
#line 866 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = NULL; YYABORT;
      }
    break;

  case 8:
/* Line 664 of lalr1.cc  */
#line 870 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = NULL; YYABORT;
      }
    break;

  case 9:
/* Line 664 of lalr1.cc  */
#line 876 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 10:
/* Line 664 of lalr1.cc  */
#line 882 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      MainModule* mm = dynamic_cast<MainModule*>((yysemantic_stack_[(2) - (2)].node));
      mm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 11:
/* Line 664 of lalr1.cc  */
#line 890 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 12:
/* Line 664 of lalr1.cc  */
#line 896 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      LibraryModule* lm = dynamic_cast<LibraryModule*>((yysemantic_stack_[(2) - (2)].node));
      lm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 13:
/* Line 664 of lalr1.cc  */
#line 905 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), "utf-8" );
    }
    break;

  case 14:
/* Line 664 of lalr1.cc  */
#line 910 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );
    }
    break;

  case 15:
/* Line 664 of lalr1.cc  */
#line 916 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (1)].node)), NULL);
      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(3) - (3)].expr)), prolog);
    }
    break;

  case 16:
/* Line 664 of lalr1.cc  */
#line 922 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (1)].node)));
      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(3) - (3)].expr)), prolog);
    }
    break;

  case 17:
/* Line 664 of lalr1.cc  */
#line 928 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)),
                                  static_cast<SIND_DeclList*>((yysemantic_stack_[(5) - (1)].node)),
                                  static_cast<VFO_DeclList*>((yysemantic_stack_[(5) - (3)].node)));
      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(5) - (5)].expr)), prolog);
    }
    break;

  case 18:
/* Line 664 of lalr1.cc  */
#line 936 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new MainModule( LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(1) - (1)].expr)), NULL );
    }
    break;

  case 19:
/* Line 664 of lalr1.cc  */
#line 941 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].expr);
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after statement.");
      YYERROR;
    }
    break;

  case 20:
/* Line 664 of lalr1.cc  */
#line 949 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].expr);
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 21:
/* Line 664 of lalr1.cc  */
#line 957 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(5) - (1)].node); (yyval.node) = (yysemantic_stack_[(5) - (3)].node); (yyval.node) = (yysemantic_stack_[(5) - (5)].expr);
      (yylocation_stack_[(5) - (3)]).step();
      error((yylocation_stack_[(5) - (3)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 22:
/* Line 664 of lalr1.cc  */
#line 965 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(5) - (1)].node); (yyval.node) = (yysemantic_stack_[(5) - (3)].node); (yyval.node) = (yysemantic_stack_[(5) - (5)].expr);
      (yylocation_stack_[(5) - (1)]).step();
      error((yylocation_stack_[(5) - (1)]), "syntax error, missing semicolon \";\" after statement.");
      YYERROR;
    }
    break;

  case 23:
/* Line 664 of lalr1.cc  */
#line 974 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(1) - (1)].node)), NULL);
    }
    break;

  case 24:
/* Line 664 of lalr1.cc  */
#line 979 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (2)].node)), NULL);
      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(3) - (1)].node)), prolog);
    }
    break;

  case 25:
/* Line 664 of lalr1.cc  */
#line 985 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (2)].node)));
      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(3) - (1)].node)), prolog);
    }
    break;

  case 26:
/* Line 664 of lalr1.cc  */
#line 991 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)),
                                  static_cast<SIND_DeclList*>((yysemantic_stack_[(5) - (2)].node)),
                                  static_cast<VFO_DeclList*>((yysemantic_stack_[(5) - (4)].node)));
      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(5) - (1)].node)), prolog);
    }
    break;

  case 27:
/* Line 664 of lalr1.cc  */
#line 1000 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      ERROR_IF_QNAME_NOT_NCNAME((yysemantic_stack_[(6) - (3)].expr), (yylocation_stack_[(6) - (3)]));
      (yyval.node) = new ModuleDecl( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );
      dynamic_cast<ModuleDecl*>((yyval.node))->setComment( SYMTAB((yysemantic_stack_[(6) - (1)].sval)) );
    }
    break;

  case 28:
/* Line 664 of lalr1.cc  */
#line 1008 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      SIND_DeclList *sdl = new SIND_DeclList( LOC((yyloc)) );
      sdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
      (yyval.node) = sdl;
    }
    break;

  case 29:
/* Line 664 of lalr1.cc  */
#line 1015 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      ((SIND_DeclList*)(yysemantic_stack_[(3) - (1)].node))->push_back( (yysemantic_stack_[(3) - (3)].node) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 30:
/* Line 664 of lalr1.cc  */
#line 1021 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 44:
/* Line 664 of lalr1.cc  */
#line 1047 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new BoundarySpaceDecl(LOC((yyloc)), StaticContextConsts::preserve_space);
    }
    break;

  case 45:
/* Line 664 of lalr1.cc  */
#line 1052 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new BoundarySpaceDecl(LOC((yyloc)), StaticContextConsts::strip_space);
    }
    break;

  case 46:
/* Line 664 of lalr1.cc  */
#line 1058 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DefaultCollationDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (4)].sval)) );
    }
    break;

  case 47:
/* Line 664 of lalr1.cc  */
#line 1064 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new BaseURIDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
    }
    break;

  case 48:
/* Line 664 of lalr1.cc  */
#line 1070 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ConstructionDecl(LOC((yyloc)), StaticContextConsts::cons_preserve);
    }
    break;

  case 49:
/* Line 664 of lalr1.cc  */
#line 1075 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ConstructionDecl(LOC((yyloc)), StaticContextConsts::cons_strip);
    }
    break;

  case 50:
/* Line 664 of lalr1.cc  */
#line 1081 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new OrderingModeDecl(LOC((yyloc)), StaticContextConsts::ordered);
    }
    break;

  case 51:
/* Line 664 of lalr1.cc  */
#line 1086 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new OrderingModeDecl(LOC((yyloc)), StaticContextConsts::unordered);
    }
    break;

  case 52:
/* Line 664 of lalr1.cc  */
#line 1092 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new EmptyOrderDecl(LOC((yyloc)), StaticContextConsts::empty_greatest);
    }
    break;

  case 53:
/* Line 664 of lalr1.cc  */
#line 1097 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new EmptyOrderDecl(LOC((yyloc)), StaticContextConsts::empty_least);
    }
    break;

  case 54:
/* Line 664 of lalr1.cc  */
#line 1103 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)), true, true);
    }
    break;

  case 55:
/* Line 664 of lalr1.cc  */
#line 1108 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)), true, false);
    }
    break;

  case 56:
/* Line 664 of lalr1.cc  */
#line 1113 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)), false, true);
    }
    break;

  case 57:
/* Line 664 of lalr1.cc  */
#line 1118 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)), false, false);
    }
    break;

  case 60:
/* Line 664 of lalr1.cc  */
#line 1128 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yyval.node);
      error((yylocation_stack_[(3) - (2)]), "syntax error, \"import\" should be followed by either \"schema\" or \"module\".");
      YYERROR;
    }
    break;

  case 61:
/* Line 664 of lalr1.cc  */
#line 1136 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport( LOC((yyloc)), NULL, SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL );
    }
    break;

  case 62:
/* Line 664 of lalr1.cc  */
#line 1141 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(4) - (3)].node)),
                            SYMTAB((yysemantic_stack_[(4) - (4)].sval)),
                            NULL);
    }
    break;

  case 63:
/* Line 664 of lalr1.cc  */
#line 1149 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            NULL,
                            SYMTAB((yysemantic_stack_[(5) - (3)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 64:
/* Line 664 of lalr1.cc  */
#line 1157 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(6) - (3)].node)),
                            SYMTAB((yysemantic_stack_[(6) - (4)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(6) - (6)].node)));
    }
    break;

  case 65:
/* Line 664 of lalr1.cc  */
#line 1166 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      URILiteralList *ull = new URILiteralList( LOC((yyloc)));
      ull->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
      (yyval.node) = ull;
    }
    break;

  case 66:
/* Line 664 of lalr1.cc  */
#line 1173 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      if ( URILiteralList *ull = dynamic_cast<URILiteralList*>((yysemantic_stack_[(3) - (1)].node)) )
        ull->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 67:
/* Line 664 of lalr1.cc  */
#line 1181 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      ERROR_IF_QNAME_NOT_NCNAME((yysemantic_stack_[(3) - (2)].expr), (yylocation_stack_[(3) - (2)]));
      (yyval.node) = new SchemaPrefix( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)));
    }
    break;

  case 68:
/* Line 664 of lalr1.cc  */
#line 1187 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaPrefix( LOC((yyloc)), true );
    }
    break;

  case 69:
/* Line 664 of lalr1.cc  */
#line 1193 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL);
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(3) - (2)].sval)));
    }
    break;

  case 70:
/* Line 664 of lalr1.cc  */
#line 1199 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      ERROR_IF_QNAME_NOT_NCNAME((yysemantic_stack_[(6) - (4)].expr), (yylocation_stack_[(6) - (4)]));
      (yyval.node) = new ModuleImport(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(6) - (4)].expr)), SYMTAB((yysemantic_stack_[(6) - (6)].sval)), NULL);
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(6) - (2)].sval)));
    }
    break;

  case 71:
/* Line 664 of lalr1.cc  */
#line 1206 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)),
                            SYMTAB((yysemantic_stack_[(5) - (3)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(5) - (2)].sval)));
    }
    break;

  case 72:
/* Line 664 of lalr1.cc  */
#line 1214 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
/* Line 664 of lalr1.cc  */
#line 1225 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      ERROR_IF_QNAME_NOT_NCNAME((yysemantic_stack_[(5) - (3)].expr), (yylocation_stack_[(5) - (3)]));
      (yyval.node) = new NamespaceDecl( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (3)].expr)), SYMTAB((yysemantic_stack_[(5) - (5)].sval)) );
    }
    break;

  case 74:
/* Line 664 of lalr1.cc  */
#line 1232 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DefaultNamespaceDecl(LOC((yyloc)),
                                    ParseConstants::ns_element_default,
                                    SYMTAB((yysemantic_stack_[(5) - (5)].sval)));
    }
    break;

  case 75:
/* Line 664 of lalr1.cc  */
#line 1239 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DefaultNamespaceDecl(LOC((yyloc)),
                                    ParseConstants::ns_function_default,
                                    SYMTAB((yysemantic_stack_[(5) - (5)].sval)));
    }
    break;

  case 76:
/* Line 664 of lalr1.cc  */
#line 1247 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      VFO_DeclList *vdl = new VFO_DeclList( LOC((yyloc)));
      vdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
      (yyval.node) = vdl;
    }
    break;

  case 77:
/* Line 664 of lalr1.cc  */
#line 1254 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      ((VFO_DeclList*)(yysemantic_stack_[(3) - (1)].node))->push_back( (yysemantic_stack_[(3) - (3)].node) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 78:
/* Line 664 of lalr1.cc  */
#line 1260 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 87:
/* Line 664 of lalr1.cc  */
#line 1279 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DecimalFormatNode(LOC((yyloc)), (yysemantic_stack_[(4) - (4)].vstrpair));
      delete (yysemantic_stack_[(4) - (4)].vstrpair);
    }
    break;

  case 88:
/* Line 664 of lalr1.cc  */
#line 1285 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DecimalFormatNode(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), (yysemantic_stack_[(4) - (4)].vstrpair));
      delete (yysemantic_stack_[(4) - (4)].vstrpair);
    }
    break;

  case 89:
/* Line 664 of lalr1.cc  */
#line 1292 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.vstrpair) = new vector<string_pair_t>();
      (yyval.vstrpair)->push_back( *(yysemantic_stack_[(1) - (1)].strpair) );
      delete (yysemantic_stack_[(1) - (1)].strpair);
    }
    break;

  case 90:
/* Line 664 of lalr1.cc  */
#line 1299 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yysemantic_stack_[(2) - (1)].vstrpair)->push_back( *(yysemantic_stack_[(2) - (2)].strpair) );
      delete (yysemantic_stack_[(2) - (2)].strpair);
      (yyval.vstrpair) = (yysemantic_stack_[(2) - (1)].vstrpair);
    }
    break;

  case 91:
/* Line 664 of lalr1.cc  */
#line 1307 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      StringLiteral *sl = static_cast<StringLiteral*>((yysemantic_stack_[(3) - (3)].expr));
      (yyval.strpair) = new string_pair_t( (yysemantic_stack_[(3) - (1)].strval), sl->get_strval().str() );
      delete sl;
    }
    break;

  case 92:
/* Line 664 of lalr1.cc  */
#line 1314 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "decimal-separator"; }
    break;

  case 93:
/* Line 664 of lalr1.cc  */
#line 1315 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "digit"; }
    break;

  case 94:
/* Line 664 of lalr1.cc  */
#line 1316 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "grouping-separator"; }
    break;

  case 95:
/* Line 664 of lalr1.cc  */
#line 1317 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "infinity"; }
    break;

  case 96:
/* Line 664 of lalr1.cc  */
#line 1318 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "minus-sign"; }
    break;

  case 97:
/* Line 664 of lalr1.cc  */
#line 1319 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "NaN"; }
    break;

  case 98:
/* Line 664 of lalr1.cc  */
#line 1320 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "pattern-separator"; }
    break;

  case 99:
/* Line 664 of lalr1.cc  */
#line 1321 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "percent"; }
    break;

  case 100:
/* Line 664 of lalr1.cc  */
#line 1322 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "per-mille"; }
    break;

  case 101:
/* Line 664 of lalr1.cc  */
#line 1323 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "zero-digit"; }
    break;

  case 102:
/* Line 664 of lalr1.cc  */
#line 1327 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
/* Line 664 of lalr1.cc  */
#line 1341 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTOptionDecl( LOC((yyloc)), dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (3)].node)) );
    }
    break;

  case 104:
/* Line 664 of lalr1.cc  */
#line 1347 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(4) - (4)].node);
    }
    break;

  case 105:
/* Line 664 of lalr1.cc  */
#line 1353 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      CtxItemDecl* d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(3) - (3)].node));
      d->theType = (yysemantic_stack_[(3) - (2)].node);
      (yyval.node) = d;
    }
    break;

  case 106:
/* Line 664 of lalr1.cc  */
#line 1360 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 107:
/* Line 664 of lalr1.cc  */
#line 1366 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      CtxItemDecl* d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(1) - (1)].node));
      d->theIsExternal = false;
      (yyval.node) = d;
    }
    break;

  case 108:
/* Line 664 of lalr1.cc  */
#line 1373 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CtxItemDecl(LOC((yyloc)), NULL);
    }
    break;

  case 109:
/* Line 664 of lalr1.cc  */
#line 1378 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 110:
/* Line 664 of lalr1.cc  */
#line 1384 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CtxItemDecl(LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 111:
/* Line 664 of lalr1.cc  */
#line 1390 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
/* Line 664 of lalr1.cc  */
#line 1402 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
/* Line 664 of lalr1.cc  */
#line 1414 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
/* Line 664 of lalr1.cc  */
#line 1427 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)), NULL, NULL);
    }
    break;

  case 115:
/* Line 664 of lalr1.cc  */
#line 1432 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)),
                              dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (4)].node)),
                              NULL);
    }
    break;

  case 116:
/* Line 664 of lalr1.cc  */
#line 1440 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(4) - (4)].expr)),
                              NULL,
                              static_cast<AnnotationListParsenode*>((yysemantic_stack_[(4) - (1)].node)));
    }
    break;

  case 117:
/* Line 664 of lalr1.cc  */
#line 1448 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(5) - (4)].expr)),
                              dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (5)].node)),
                              static_cast<AnnotationListParsenode*>((yysemantic_stack_[(5) - (1)].node)));
    }
    break;

  case 118:
/* Line 664 of lalr1.cc  */
#line 1457 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationListParsenode(LOC((yyloc)), static_cast<AnnotationParsenode*>((yysemantic_stack_[(1) - (1)].node)));
    }
    break;

  case 119:
/* Line 664 of lalr1.cc  */
#line 1462 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      static_cast<AnnotationListParsenode*>((yysemantic_stack_[(2) - (1)].node))->push_back(static_cast<AnnotationParsenode*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 120:
/* Line 664 of lalr1.cc  */
#line 1469 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))), NULL);
    }
    break;

  case 121:
/* Line 664 of lalr1.cc  */
#line 1474 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)),
                                   new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (1)].sval))),
                                   static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 122:
/* Line 664 of lalr1.cc  */
#line 1481 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), true), NULL);
    }
    break;

  case 123:
/* Line 664 of lalr1.cc  */
#line 1486 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)),
                                   new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (1)].sval)), true),
                                   static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 124:
/* Line 664 of lalr1.cc  */
#line 1494 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationLiteralListParsenode(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr));
    }
    break;

  case 125:
/* Line 664 of lalr1.cc  */
#line 1499 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(3) - (1)].node))->push_back((yysemantic_stack_[(3) - (3)].expr));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 126:
/* Line 664 of lalr1.cc  */
#line 1506 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      static_cast<FunctionDecl*>((yysemantic_stack_[(2) - (2)].node))->setComment( SYMTAB((yysemantic_stack_[(2) - (1)].sval)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 127:
/* Line 664 of lalr1.cc  */
#line 1512 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      FunctionDecl* fdecl = static_cast<FunctionDecl*>((yysemantic_stack_[(3) - (3)].node));
      fdecl->setComment( SYMTAB((yysemantic_stack_[(3) - (1)].sval)) );
      fdecl->set_annotations(static_cast<AnnotationListParsenode*>((yysemantic_stack_[(3) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
    }
    break;

  case 130:
/* Line 664 of lalr1.cc  */
#line 1525 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FunctionDecl(LOC((yyloc)),
                            static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                            &* (yysemantic_stack_[(4) - (3)].fnsig)->theParams,
                            &* (yysemantic_stack_[(4) - (3)].fnsig)->theReturnType,
                            (yysemantic_stack_[(4) - (4)].expr),
                            false,
                            false);
      delete (yysemantic_stack_[(4) - (3)].fnsig);
    }
    break;

  case 131:
/* Line 664 of lalr1.cc  */
#line 1536 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
/* Line 664 of lalr1.cc  */
#line 1549 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
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
/* Line 664 of lalr1.cc  */
#line 1561 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
/* Line 664 of lalr1.cc  */
#line 1574 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(NULL);
    }
    break;

  case 135:
/* Line 664 of lalr1.cc  */
#line 1579 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (2)].node)));
    }
    break;

  case 136:
/* Line 664 of lalr1.cc  */
#line 1584 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(NULL, dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node)));
    }
    break;

  case 137:
/* Line 664 of lalr1.cc  */
#line 1589 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(dynamic_cast<ParamList*>((yysemantic_stack_[(5) - (2)].node)), dynamic_cast<SequenceType*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 138:
/* Line 664 of lalr1.cc  */
#line 1595 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      ParamList *pl = new ParamList( LOC((yyloc)) );
      pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = pl;
    }
    break;

  case 139:
/* Line 664 of lalr1.cc  */
#line 1602 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      if ( ParamList *pl = dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (1)].node)) )
        pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(3) - (3)].node)) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 140:
/* Line 664 of lalr1.cc  */
#line 1610 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL);
    }
    break;

  case 141:
/* Line 664 of lalr1.cc  */
#line 1615 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)),
                     static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                     dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 142:
/* Line 664 of lalr1.cc  */
#line 1623 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)),
                              NULL,
                              NULL);
      static_cast<CollectionDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(3) - (1)].sval)));
    }
    break;

  case 143:
/* Line 664 of lalr1.cc  */
#line 1631 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(5) - (3)].expr)),
                              0,
                              static_cast<SequenceType*>((yysemantic_stack_[(5) - (5)].node)));
      static_cast<CollectionDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(5) - (1)].sval)));
    }
    break;

  case 144:
/* Line 664 of lalr1.cc  */
#line 1639 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                               static_cast<QName*>((yysemantic_stack_[(4) - (4)].expr)),
                               static_cast<AnnotationListParsenode*>((yysemantic_stack_[(4) - (2)].node)),
                               0);
      static_cast<CollectionDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(4) - (1)].sval)));
    }
    break;

  case 145:
/* Line 664 of lalr1.cc  */
#line 1647 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                               static_cast<QName*>((yysemantic_stack_[(6) - (4)].expr)),
                               static_cast<AnnotationListParsenode*>((yysemantic_stack_[(6) - (2)].node)),
                               static_cast<SequenceType*>((yysemantic_stack_[(6) - (6)].node)));
      static_cast<CollectionDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(6) - (1)].sval)));
    }
    break;

  case 146:
/* Line 664 of lalr1.cc  */
#line 1657 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL));
    }
    break;

  case 147:
/* Line 664 of lalr1.cc  */
#line 1661 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)),
                                                    (yysemantic_stack_[(2) - (1)].node),
                                                    dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node))));
    }
    break;

  case 148:
/* Line 664 of lalr1.cc  */
#line 1667 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL));
    }
    break;

  case 149:
/* Line 664 of lalr1.cc  */
#line 1671 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)),
                                                    (yysemantic_stack_[(2) - (1)].node),
                                                    dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node))));
    }
    break;

  case 150:
/* Line 664 of lalr1.cc  */
#line 1678 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
/* Line 664 of lalr1.cc  */
#line 1687 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
/* Line 664 of lalr1.cc  */
#line 1698 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      IndexKeyList* keyList = new IndexKeyList(LOC((yyloc)));
      keyList->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = keyList;
    }
    break;

  case 153:
/* Line 664 of lalr1.cc  */
#line 1704 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<IndexKeyList*>((yysemantic_stack_[(3) - (1)].node))->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 154:
/* Line 664 of lalr1.cc  */
#line 1711 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL, NULL);
    }
    break;

  case 155:
/* Line 664 of lalr1.cc  */
#line 1716 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            dynamic_cast<SequenceType*>((yysemantic_stack_[(2) - (2)].node)),
                            NULL);
    }
    break;

  case 156:
/* Line 664 of lalr1.cc  */
#line 1723 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            NULL,
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
    }
    break;

  case 157:
/* Line 664 of lalr1.cc  */
#line 1730 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(3) - (1)].expr),
                            dynamic_cast<SequenceType*>((yysemantic_stack_[(3) - (2)].node)),
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 158:
/* Line 664 of lalr1.cc  */
#line 1740 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ICCollSimpleCheck(LOC((yyloc)),
                                 static_cast<QName*>((yysemantic_stack_[(11) - (4)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(11) - (7)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(11) - (9)].expr)),
                                 (yysemantic_stack_[(11) - (11)].expr));
    }
    break;

  case 159:
/* Line 664 of lalr1.cc  */
#line 1750 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ICCollUniqueKeyCheck(LOC((yyloc)),
                                    static_cast<QName*>((yysemantic_stack_[(14) - (4)].expr)),
                                    static_cast<QName*>((yysemantic_stack_[(14) - (7)].expr)),
                                    static_cast<QName*>((yysemantic_stack_[(14) - (10)].expr)),
                                    (yysemantic_stack_[(14) - (14)].expr));
    }
    break;

  case 160:
/* Line 664 of lalr1.cc  */
#line 1760 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ICCollForeachNode(LOC((yyloc)),
                                 static_cast<QName*>((yysemantic_stack_[(13) - (4)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(13) - (7)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(13) - (11)].expr)),
                                 (yysemantic_stack_[(13) - (13)].expr));
    }
    break;

  case 161:
/* Line 664 of lalr1.cc  */
#line 1771 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
/* Line 664 of lalr1.cc  */
#line 1784 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
/* Line 664 of lalr1.cc  */
#line 1800 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 164:
/* Line 664 of lalr1.cc  */
#line 1804 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 165:
/* Line 664 of lalr1.cc  */
#line 1808 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = NULL;
    }
    break;

  case 166:
/* Line 664 of lalr1.cc  */
#line 1814 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 167:
/* Line 664 of lalr1.cc  */
#line 1818 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 168:
/* Line 664 of lalr1.cc  */
#line 1822 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new BlockBody(LOC((yyloc)));
    }
    break;

  case 169:
/* Line 664 of lalr1.cc  */
#line 1828 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 170:
/* Line 664 of lalr1.cc  */
#line 1833 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      BlockBody* blk = static_cast<BlockBody*>((yysemantic_stack_[(2) - (1)].expr));
      blk->add((yysemantic_stack_[(2) - (2)].expr));
      (yyval.expr) = blk;
    }
    break;

  case 171:
/* Line 664 of lalr1.cc  */
#line 1841 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      BlockBody* blk = new BlockBody(LOC((yyloc)));
      blk->add((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = blk;
    }
    break;

  case 172:
/* Line 664 of lalr1.cc  */
#line 1848 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      BlockBody* blk = static_cast<BlockBody*>((yysemantic_stack_[(2) - (1)].expr));
      blk->add((yysemantic_stack_[(2) - (2)].expr));
      (yyval.expr) = blk;
    }
    break;

  case 173:
/* Line 664 of lalr1.cc  */
#line 1855 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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

  case 186:
/* Line 664 of lalr1.cc  */
#line 1882 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 187:
/* Line 664 of lalr1.cc  */
#line 1887 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      driver.addCommonLanguageWarning((yylocation_stack_[(2) - (1)]), ZED(ZWST0009_EMPTY_BLOCK));
      (yyval.expr) = new BlockBody(LOC((yyloc)));
    }
    break;

  case 188:
/* Line 664 of lalr1.cc  */
#line 1894 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      BlockBody* block = dynamic_cast<BlockBody*>((yysemantic_stack_[(3) - (2)].expr));
      if (block == NULL)
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
/* Line 664 of lalr1.cc  */
#line 1910 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 190:
/* Line 664 of lalr1.cc  */
#line 1916 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    }
    break;

  case 191:
/* Line 664 of lalr1.cc  */
#line 1922 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      VarDeclStmt* vdecl = static_cast<VarDeclStmt*>((yysemantic_stack_[(3) - (1)].expr));
      vdecl->add((yysemantic_stack_[(3) - (3)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 192:
/* Line 664 of lalr1.cc  */
#line 1929 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      VarDeclStmt* vdecl = new VarDeclStmt(LOC((yyloc)), NULL);
      vdecl->add((yysemantic_stack_[(2) - (2)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 193:
/* Line 664 of lalr1.cc  */
#line 1936 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      VarDeclStmt* vdecl = new VarDeclStmt(LOC((yyloc)),
                                           static_cast<AnnotationListParsenode*>((yysemantic_stack_[(3) - (1)].node)));
      vdecl->add((yysemantic_stack_[(3) - (3)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 194:
/* Line 664 of lalr1.cc  */
#line 1945 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
/* Line 664 of lalr1.cc  */
#line 1954 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
/* Line 664 of lalr1.cc  */
#line 1963 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
/* Line 664 of lalr1.cc  */
#line 1972 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
/* Line 664 of lalr1.cc  */
#line 1983 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new AssignExpr(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)), (yysemantic_stack_[(5) - (4)].expr));
    }
    break;

  case 199:
/* Line 664 of lalr1.cc  */
#line 1989 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ApplyExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr));
    }
    break;

  case 200:
/* Line 664 of lalr1.cc  */
#line 1995 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ExitExpr(LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr));
    }
    break;

  case 201:
/* Line 664 of lalr1.cc  */
#line 2001 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
/* Line 664 of lalr1.cc  */
#line 2013 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement(LOC((yyloc)), FlowCtlStatement::BREAK);
    }
    break;

  case 203:
/* Line 664 of lalr1.cc  */
#line 2018 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement( LOC((yyloc)), FlowCtlStatement::CONTINUE );
    }
    break;

  case 204:
/* Line 664 of lalr1.cc  */
#line 2024 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
/* Line 664 of lalr1.cc  */
#line 2036 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
/* Line 664 of lalr1.cc  */
#line 2049 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
/* Line 664 of lalr1.cc  */
#line 2069 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TryExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 208:
/* Line 664 of lalr1.cc  */
#line 2075 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      CatchListExpr* cle = new CatchListExpr( LOC((yyloc)) );
      cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)) );
      (yyval.expr) = cle;
    }
    break;

  case 209:
/* Line 664 of lalr1.cc  */
#line 2082 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
      if ( cle )
        cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)) );
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    }
    break;

  case 210:
/* Line 664 of lalr1.cc  */
#line 2091 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)), *(yysemantic_stack_[(3) - (2)].name_test_list), (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 211:
/* Line 664 of lalr1.cc  */
#line 2098 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 212:
/* Line 664 of lalr1.cc  */
#line 2103 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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

  case 213:
/* Line 664 of lalr1.cc  */
#line 2115 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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

  case 232:
/* Line 664 of lalr1.cc  */
#line 2149 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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

  case 233:
/* Line 664 of lalr1.cc  */
#line 2161 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ReturnExpr( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr) );
    }
    break;

  case 234:
/* Line 664 of lalr1.cc  */
#line 2167 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_sliding;
    }
    break;

  case 235:
/* Line 664 of lalr1.cc  */
#line 2172 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_tumbling;
    }
    break;

  case 236:
/* Line 664 of lalr1.cc  */
#line 2178 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_start;
    }
    break;

  case 237:
/* Line 664 of lalr1.cc  */
#line 2183 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_end;
    }
    break;

  case 238:
/* Line 664 of lalr1.cc  */
#line 2188 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
    (yyval.strval) = parser::the_only_end;
  }
    break;

  case 239:
/* Line 664 of lalr1.cc  */
#line 2194 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FLWORWinCond(LOC((yyloc)),
                            dynamic_cast<WindowVars*>((yysemantic_stack_[(4) - (2)].node)),
                            (yysemantic_stack_[(4) - (4)].expr),
                            (yysemantic_stack_[(4) - (1)].strval) == parser::the_start,
                            (yysemantic_stack_[(4) - (1)].strval) == parser::the_only_end);
    }
    break;

  case 240:
/* Line 664 of lalr1.cc  */
#line 2203 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FLWORWinCond(LOC((yyloc)),
                            NULL,
                            (yysemantic_stack_[(3) - (3)].expr),
                            (yysemantic_stack_[(3) - (1)].strval) == parser::the_start,
                            (yysemantic_stack_[(3) - (1)].strval) == parser::the_only_end);
    }
    break;

  case 241:
/* Line 664 of lalr1.cc  */
#line 2214 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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

  case 242:
/* Line 664 of lalr1.cc  */
#line 2226 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowClause (LOC ((yyloc)),
                             ((yysemantic_stack_[(4) - (2)].strval) == parser::the_tumbling ?
                              WindowClause::tumbling_window :
                              WindowClause::sliding_window),
                             dynamic_cast<WindowVarDecl *> ((yysemantic_stack_[(4) - (3)].node)),
                             dynamic_cast<FLWORWinCond *> ((yysemantic_stack_[(4) - (4)].node)), NULL);
    }
    break;

  case 243:
/* Line 664 of lalr1.cc  */
#line 2237 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CountClause(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 252:
/* Line 664 of lalr1.cc  */
#line 2255 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      FLWORClauseList *fcl = new FLWORClauseList( LOC((yyloc)) );
      fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = fcl;
    }
    break;

  case 253:
/* Line 664 of lalr1.cc  */
#line 2262 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      FLWORClauseList *fcl = dynamic_cast<FLWORClauseList*>((yysemantic_stack_[(2) - (1)].node));
      fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = fcl;
    }
    break;

  case 254:
/* Line 664 of lalr1.cc  */
#line 2271 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ForClause(LOC((yyloc)), dynamic_cast<VarInDeclList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 255:
/* Line 664 of lalr1.cc  */
#line 2275 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      error((yylocation_stack_[(3) - (2)]), "syntax error, unexpected qualified name \""
          + static_cast<VarInDeclList*>((yysemantic_stack_[(3) - (3)].node))->operator[](0)->get_var_name()->get_qname().str() + "\" (missing \"$\" sign?)");
      delete (yysemantic_stack_[(3) - (3)].node);
      YYERROR;
    }
    break;

  case 256:
/* Line 664 of lalr1.cc  */
#line 2285 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = NULL;
      error((yylocation_stack_[(2) - (2)]), "");
      YYERROR;
    }
    break;

  case 257:
/* Line 664 of lalr1.cc  */
#line 2293 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      VarInDeclList* vdl = new VarInDeclList( LOC((yyloc)) );
      vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = vdl;
    }
    break;

  case 258:
/* Line 664 of lalr1.cc  */
#line 2300 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      if ( VarInDeclList* vdl = dynamic_cast<VarInDeclList*>((yysemantic_stack_[(4) - (1)].node)) )
        vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
      (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
    }
    break;

  case 259:
/* Line 664 of lalr1.cc  */
#line 2307 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
      error((yylocation_stack_[(3) - (3)]), "syntax error, unexpected QName \""
          + static_cast<VarInDecl*>((yysemantic_stack_[(3) - (3)].node))->get_var_name()->get_qname().str() + "\" (missing \"$\" sign?)");
      delete (yysemantic_stack_[(3) - (1)].node);
      YYERROR;
    }
    break;

  case 260:
/* Line 664 of lalr1.cc  */
#line 2317 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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

  case 261:
/* Line 664 of lalr1.cc  */
#line 2327 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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

  case 262:
/* Line 664 of lalr1.cc  */
#line 2337 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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

  case 263:
/* Line 664 of lalr1.cc  */
#line 2347 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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

  case 264:
/* Line 664 of lalr1.cc  */
#line 2357 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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

  case 265:
/* Line 664 of lalr1.cc  */
#line 2367 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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

  case 266:
/* Line 664 of lalr1.cc  */
#line 2377 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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

  case 267:
/* Line 664 of lalr1.cc  */
#line 2387 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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

  case 268:
/* Line 664 of lalr1.cc  */
#line 2397 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                         NULL,NULL,
                         dynamic_cast<FTScoreVar*>((yysemantic_stack_[(4) - (2)].node)),
                         (yysemantic_stack_[(4) - (4)].expr),
                         false);
    }
    break;

  case 269:
/* Line 664 of lalr1.cc  */
#line 2406 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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

  case 270:
/* Line 664 of lalr1.cc  */
#line 2416 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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

  case 271:
/* Line 664 of lalr1.cc  */
#line 2426 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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

  case 272:
/* Line 664 of lalr1.cc  */
#line 2438 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new PositionalVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 273:
/* Line 664 of lalr1.cc  */
#line 2444 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTScoreVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 274:
/* Line 664 of lalr1.cc  */
#line 2450 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new LetClause( LOC((yyloc)), dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(2) - (2)].node)) );
        }
    break;

  case 275:
/* Line 664 of lalr1.cc  */
#line 2456 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            VarGetsDeclList *vgdl = new VarGetsDeclList( LOC((yyloc)) );
            vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = vgdl;
        }
    break;

  case 276:
/* Line 664 of lalr1.cc  */
#line 2462 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            if( VarGetsDeclList *vgdl = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(3) - (1)].node)) )
                vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 277:
/* Line 664 of lalr1.cc  */
#line 2470 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                           NULL,
                           NULL,
                           (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 278:
/* Line 664 of lalr1.cc  */
#line 2478 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                           dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (3)].node)),
                           NULL,
                           (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 279:
/* Line 664 of lalr1.cc  */
#line 2486 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(3) - (1)].node))->get_var_name(),
                           NULL,
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(3) - (1)].node)),
                           (yysemantic_stack_[(3) - (3)].expr));
     }
    break;

  case 280:
/* Line 664 of lalr1.cc  */
#line 2494 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                           dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (3)].node)),
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(6) - (4)].node)),
                           (yysemantic_stack_[(6) - (6)].expr));
    }
    break;

  case 281:
/* Line 664 of lalr1.cc  */
#line 2504 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                             NULL, (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 282:
/* Line 664 of lalr1.cc  */
#line 2510 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                             dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (3)].node)),
                             (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 284:
/* Line 664 of lalr1.cc  */
#line 2520 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL, NULL);
    }
    break;

  case 285:
/* Line 664 of lalr1.cc  */
#line 2524 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_curr(static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)));
    }
    break;

  case 286:
/* Line 664 of lalr1.cc  */
#line 2531 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), dynamic_cast<PositionalVar*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL, NULL);
    }
    break;

  case 287:
/* Line 664 of lalr1.cc  */
#line 2535 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_posvar(dynamic_cast<PositionalVar*>((yysemantic_stack_[(2) - (1)].node)));
    }
    break;

  case 289:
/* Line 664 of lalr1.cc  */
#line 2543 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), static_cast<QName*>((yysemantic_stack_[(6) - (6)].expr)));
    }
    break;

  case 290:
/* Line 664 of lalr1.cc  */
#line 2547 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 291:
/* Line 664 of lalr1.cc  */
#line 2551 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)), NULL);
    }
    break;

  case 292:
/* Line 664 of lalr1.cc  */
#line 2557 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WhereClause(LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 293:
/* Line 664 of lalr1.cc  */
#line 2563 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupByClause(LOC((yyloc)), dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 294:
/* Line 664 of lalr1.cc  */
#line 2569 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      GroupSpecList* gsl = new GroupSpecList(LOC((yyloc)));
      gsl->push_back(static_cast<GroupSpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = gsl;
    }
    break;

  case 295:
/* Line 664 of lalr1.cc  */
#line 2575 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      GroupSpecList* gsl = static_cast<GroupSpecList*>((yysemantic_stack_[(3) - (1)].node));
      gsl->push_back(static_cast<GroupSpec*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = gsl;
    }
    break;

  case 296:
/* Line 664 of lalr1.cc  */
#line 2583 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)), NULL, (yysemantic_stack_[(4) - (4)].expr), NULL);
    }
    break;

  case 297:
/* Line 664 of lalr1.cc  */
#line 2587 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                         static_cast<SequenceType*>((yysemantic_stack_[(5) - (3)].node)),
                         (yysemantic_stack_[(5) - (5)].expr),
                         NULL);
    }
    break;

  case 298:
/* Line 664 of lalr1.cc  */
#line 2595 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                         static_cast<SequenceType*>((yysemantic_stack_[(6) - (3)].node)),
                         (yysemantic_stack_[(6) - (5)].expr),
                         static_cast<GroupCollationSpec*>((yysemantic_stack_[(6) - (6)].node)));
    }
    break;

  case 299:
/* Line 664 of lalr1.cc  */
#line 2603 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                         NULL,
                         (yysemantic_stack_[(5) - (4)].expr),
                         static_cast<GroupCollationSpec*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 300:
/* Line 664 of lalr1.cc  */
#line 2611 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                         static_cast<VarRef*>((yysemantic_stack_[(3) - (2)].expr))->get_qname(),
                         NULL,
                         NULL,
                         static_cast<GroupCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 301:
/* Line 664 of lalr1.cc  */
#line 2619 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      VarRef* varRef = dynamic_cast<VarRef*>((yysemantic_stack_[(1) - (1)].expr));
      if (varRef != NULL)
        (yyval.node) = new GroupSpec(LOC((yyloc)), varRef, NULL, NULL, NULL);
      else
        (yyval.node) = new GroupSpec(LOC((yyloc)), NULL, NULL, (yysemantic_stack_[(1) - (1)].expr), NULL);
    }
    break;

  case 302:
/* Line 664 of lalr1.cc  */
#line 2627 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      VarRef* varRef = dynamic_cast<VarRef*>((yysemantic_stack_[(2) - (1)].expr));
      if (varRef != NULL)
        (yyval.node) = new GroupSpec(LOC((yyloc)), varRef, NULL, NULL, static_cast<GroupCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
      else
        (yyval.node) = new GroupSpec(LOC((yyloc)), NULL, NULL, (yysemantic_stack_[(2) - (1)].expr), static_cast<GroupCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
    }
    break;

  case 303:
/* Line 664 of lalr1.cc  */
#line 2637 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
    }
    break;

  case 304:
/* Line 664 of lalr1.cc  */
#line 2643 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 305:
/* Line 664 of lalr1.cc  */
#line 2649 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(4) - (4)].node)), true
            );
        }
    break;

  case 306:
/* Line 664 of lalr1.cc  */
#line 2657 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            OrderSpecList *osl = new OrderSpecList( LOC((yyloc)) );
            osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = osl;
        }
    break;

  case 307:
/* Line 664 of lalr1.cc  */
#line 2663 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            if ( OrderSpecList* osl = dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (1)].node)) )
                osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 308:
/* Line 664 of lalr1.cc  */
#line 2671 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderSpec( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL );
        }
    break;

  case 309:
/* Line 664 of lalr1.cc  */
#line 2675 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderSpec(
                LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<OrderModifierPN*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 310:
/* Line 664 of lalr1.cc  */
#line 2683 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL
            );
        }
    break;

  case 311:
/* Line 664 of lalr1.cc  */
#line 2689 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 312:
/* Line 664 of lalr1.cc  */
#line 2695 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, NULL, dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 313:
/* Line 664 of lalr1.cc  */
#line 2701 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (2)].node)),
                NULL
            );
        }
    break;

  case 314:
/* Line 664 of lalr1.cc  */
#line 2710 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
                NULL,
                dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 315:
/* Line 664 of lalr1.cc  */
#line 2719 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                NULL,
                dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 316:
/* Line 664 of lalr1.cc  */
#line 2728 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(3) - (1)].node)),
                dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 317:
/* Line 664 of lalr1.cc  */
#line 2739 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_ascending );
        }
    break;

  case 318:
/* Line 664 of lalr1.cc  */
#line 2743 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_descending );
        }
    break;

  case 319:
/* Line 664 of lalr1.cc  */
#line 2749 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_greatest
            );
        }
    break;

  case 320:
/* Line 664 of lalr1.cc  */
#line 2755 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_least
            );
        }
    break;

  case 321:
/* Line 664 of lalr1.cc  */
#line 2763 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 322:
/* Line 664 of lalr1.cc  */
#line 2769 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new QuantifiedExpr(
                LOC((yyloc)),
                ParseConstants::quant_some,
                dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(5) - (3)].node)),
                (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 323:
/* Line 664 of lalr1.cc  */
#line 2778 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new QuantifiedExpr(
                LOC((yyloc)),
                ParseConstants::quant_every,
                dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(5) - (3)].node)),
                (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 324:
/* Line 664 of lalr1.cc  */
#line 2789 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      QVarInDeclList *qvidl = new QVarInDeclList( LOC((yyloc)) );
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = qvidl;
    }
    break;

  case 325:
/* Line 664 of lalr1.cc  */
#line 2795 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      QVarInDeclList *qvidl = dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
      (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
    }
    break;

  case 326:
/* Line 664 of lalr1.cc  */
#line 2803 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 327:
/* Line 664 of lalr1.cc  */
#line 2807 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                          dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 328:
/* Line 664 of lalr1.cc  */
#line 2816 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new SwitchExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(8) - (5)].node)), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 329:
/* Line 664 of lalr1.cc  */
#line 2822 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = new SwitchCaseClauseList(LOC((yyloc)));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = scc_list_p;
    }
    break;

  case 330:
/* Line 664 of lalr1.cc  */
#line 2828 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 331:
/* Line 664 of lalr1.cc  */
#line 2836 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SwitchCaseClause(LOC((yyloc)), dynamic_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 332:
/* Line 664 of lalr1.cc  */
#line 2842 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = new SwitchCaseOperandList(LOC((yyloc)));
      sco_list_p->push_back((yysemantic_stack_[(2) - (2)].expr));
      (yyval.node) = sco_list_p;
    }
    break;

  case 333:
/* Line 664 of lalr1.cc  */
#line 2848 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = static_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node));
      sco_list_p->push_back((yysemantic_stack_[(3) - (3)].expr));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 334:
/* Line 664 of lalr1.cc  */
#line 2856 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new SwitchExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(8) - (5)].node)), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 335:
/* Line 664 of lalr1.cc  */
#line 2862 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = new SwitchCaseClauseList(LOC((yyloc)));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = scc_list_p;
    }
    break;

  case 336:
/* Line 664 of lalr1.cc  */
#line 2868 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 337:
/* Line 664 of lalr1.cc  */
#line 2876 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SwitchCaseClause(LOC((yyloc)), dynamic_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 338:
/* Line 664 of lalr1.cc  */
#line 2882 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC((yyloc)),
                              (yysemantic_stack_[(8) - (3)].expr),
                              static_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
                              (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 339:
/* Line 664 of lalr1.cc  */
#line 2889 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
                              (yysemantic_stack_[(10) - (3)].expr),
                              static_cast<CaseClauseList*>((yysemantic_stack_[(10) - (5)].node)),
                              static_cast<QName*>((yysemantic_stack_[(10) - (8)].expr)),
                              (yysemantic_stack_[(10) - (10)].expr));
    }
    break;

  case 340:
/* Line 664 of lalr1.cc  */
#line 2899 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC((yyloc)),
                              (yysemantic_stack_[(8) - (3)].expr),
                              static_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
                              (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 341:
/* Line 664 of lalr1.cc  */
#line 2906 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
                              (yysemantic_stack_[(10) - (3)].expr),
                              static_cast<CaseClauseList*>((yysemantic_stack_[(10) - (5)].node)),
                              static_cast<QName*>((yysemantic_stack_[(10) - (8)].expr)),
                              (yysemantic_stack_[(10) - (10)].expr));
    }
    break;

  case 342:
/* Line 664 of lalr1.cc  */
#line 2916 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
      cc_list_p->push_back(static_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = cc_list_p;
    }
    break;

  case 343:
/* Line 664 of lalr1.cc  */
#line 2922 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      cc_list_p->push_back(static_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 344:
/* Line 664 of lalr1.cc  */
#line 2930 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<SequenceTypeList*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 345:
/* Line 664 of lalr1.cc  */
#line 2936 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                          static_cast<SequenceTypeList*>((yysemantic_stack_[(7) - (5)].node)),
                          (yysemantic_stack_[(7) - (7)].expr));
     }
    break;

  case 346:
/* Line 664 of lalr1.cc  */
#line 2945 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
      cc_list_p->push_back(static_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = cc_list_p;
    }
    break;

  case 347:
/* Line 664 of lalr1.cc  */
#line 2951 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = static_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      cc_list_p->push_back(static_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 348:
/* Line 664 of lalr1.cc  */
#line 2959 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<SequenceTypeList*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 349:
/* Line 664 of lalr1.cc  */
#line 2965 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                          static_cast<SequenceTypeList*>((yysemantic_stack_[(7) - (5)].node)),
                          (yysemantic_stack_[(7) - (7)].expr));
     }
    break;

  case 350:
/* Line 664 of lalr1.cc  */
#line 2974 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      SequenceTypeList* seqList = new SequenceTypeList(LOC((yyloc)));
      seqList->push_back(static_cast<SequenceType*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = seqList;
    }
    break;

  case 351:
/* Line 664 of lalr1.cc  */
#line 2980 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      SequenceTypeList* seqList = static_cast<SequenceTypeList*>((yysemantic_stack_[(3) - (1)].node));
      seqList->push_back(static_cast<SequenceType*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 352:
/* Line 664 of lalr1.cc  */
#line 2988 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new IfExpr(LOC ((yyloc)), (yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (6)].expr), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 353:
/* Line 664 of lalr1.cc  */
#line 2994 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 354:
/* Line 664 of lalr1.cc  */
#line 2998 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new OrExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
    }
    break;

  case 355:
/* Line 664 of lalr1.cc  */
#line 3004 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 356:
/* Line 664 of lalr1.cc  */
#line 3009 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AndExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 357:
/* Line 664 of lalr1.cc  */
#line 3015 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 358:
/* Line 664 of lalr1.cc  */
#line 3019 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                dynamic_cast<ValueComp*>((yysemantic_stack_[(3) - (2)].node)),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 359:
/* Line 664 of lalr1.cc  */
#line 3028 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)), dynamic_cast<NodeComp*>((yysemantic_stack_[(3) - (2)].node)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 360:
/* Line 664 of lalr1.cc  */
#line 3034 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_eq ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 361:
/* Line 664 of lalr1.cc  */
#line 3043 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_ne ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 362:
/* Line 664 of lalr1.cc  */
#line 3052 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            driver.getXqueryLexer()->interpretAsLessThan();
        }
    break;

  case 363:
/* Line 664 of lalr1.cc  */
#line 3056 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_lt ),
                (yysemantic_stack_[(4) - (1)].expr),
                (yysemantic_stack_[(4) - (4)].expr)
            );
        }
    break;

  case 364:
/* Line 664 of lalr1.cc  */
#line 3065 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_le ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 365:
/* Line 664 of lalr1.cc  */
#line 3074 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_gt ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 366:
/* Line 664 of lalr1.cc  */
#line 3083 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_ge ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 367:
/* Line 664 of lalr1.cc  */
#line 3094 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 368:
/* Line 664 of lalr1.cc  */
#line 3098 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FTContainsExpr(
                LOC((yyloc)),
                (yysemantic_stack_[(5) - (1)].expr),
                dynamic_cast<FTSelection*>((yysemantic_stack_[(5) - (4)].node)),
                dynamic_cast<FTIgnoreOption*>((yysemantic_stack_[(5) - (5)].node))
            );
        }
    break;

  case 369:
/* Line 664 of lalr1.cc  */
#line 3109 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 370:
/* Line 664 of lalr1.cc  */
#line 3113 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new StringConcatExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
        }
    break;

  case 371:
/* Line 664 of lalr1.cc  */
#line 3118 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 372:
/* Line 664 of lalr1.cc  */
#line 3122 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 373:
/* Line 664 of lalr1.cc  */
#line 3128 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 374:
/* Line 664 of lalr1.cc  */
#line 3132 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RangeExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 375:
/* Line 664 of lalr1.cc  */
#line 3138 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 376:
/* Line 664 of lalr1.cc  */
#line 3142 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_plus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 377:
/* Line 664 of lalr1.cc  */
#line 3146 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_minus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 378:
/* Line 664 of lalr1.cc  */
#line 3152 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 379:
/* Line 664 of lalr1.cc  */
#line 3156 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mul, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 380:
/* Line 664 of lalr1.cc  */
#line 3162 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_div, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 381:
/* Line 664 of lalr1.cc  */
#line 3168 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_idiv, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 382:
/* Line 664 of lalr1.cc  */
#line 3174 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mod, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 383:
/* Line 664 of lalr1.cc  */
#line 3182 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 384:
/* Line 664 of lalr1.cc  */
#line 3186 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 385:
/* Line 664 of lalr1.cc  */
#line 3190 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 386:
/* Line 664 of lalr1.cc  */
#line 3196 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 387:
/* Line 664 of lalr1.cc  */
#line 3200 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_intersect, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 388:
/* Line 664 of lalr1.cc  */
#line 3206 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_except, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 389:
/* Line 664 of lalr1.cc  */
#line 3214 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 390:
/* Line 664 of lalr1.cc  */
#line 3218 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InstanceofExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 391:
/* Line 664 of lalr1.cc  */
#line 3226 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 392:
/* Line 664 of lalr1.cc  */
#line 3230 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new TreatExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 393:
/* Line 664 of lalr1.cc  */
#line 3238 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 394:
/* Line 664 of lalr1.cc  */
#line 3242 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CastableExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 395:
/* Line 664 of lalr1.cc  */
#line 3250 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 396:
/* Line 664 of lalr1.cc  */
#line 3254 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CastExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 397:
/* Line 664 of lalr1.cc  */
#line 3262 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SingleType(LOC((yyloc)), dynamic_cast<SimpleType*>((yysemantic_stack_[(1) - (1)].node)), false);
    }
    break;

  case 398:
/* Line 664 of lalr1.cc  */
#line 3266 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SingleType(LOC((yyloc)), dynamic_cast<SimpleType*>((yysemantic_stack_[(2) - (1)].node)), true);
    }
    break;

  case 399:
/* Line 664 of lalr1.cc  */
#line 3272 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 400:
/* Line 664 of lalr1.cc  */
#line 3276 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnaryExpr( LOC((yyloc)), dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 401:
/* Line 664 of lalr1.cc  */
#line 3282 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), true );
        }
    break;

  case 402:
/* Line 664 of lalr1.cc  */
#line 3286 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), false );
        }
    break;

  case 403:
/* Line 664 of lalr1.cc  */
#line 3290 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 404:
/* Line 664 of lalr1.cc  */
#line 3294 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            if ( SignList *sl = dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)) )
                sl->negate();
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 408:
/* Line 664 of lalr1.cc  */
#line 3307 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
        (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
      }
    break;

  case 409:
/* Line 664 of lalr1.cc  */
#line 3312 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
        (yyval.expr) = new SimpleMapExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
      }
    break;

  case 410:
/* Line 664 of lalr1.cc  */
#line 3318 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_eq );
        }
    break;

  case 411:
/* Line 664 of lalr1.cc  */
#line 3322 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ne );
        }
    break;

  case 412:
/* Line 664 of lalr1.cc  */
#line 3326 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_lt );
        }
    break;

  case 413:
/* Line 664 of lalr1.cc  */
#line 3330 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_le );
        }
    break;

  case 414:
/* Line 664 of lalr1.cc  */
#line 3334 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_gt );
        }
    break;

  case 415:
/* Line 664 of lalr1.cc  */
#line 3338 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ge );
        }
    break;

  case 416:
/* Line 664 of lalr1.cc  */
#line 3344 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_is );
        }
    break;

  case 417:
/* Line 664 of lalr1.cc  */
#line 3348 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_precedes );
        }
    break;

  case 418:
/* Line 664 of lalr1.cc  */
#line 3352 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_follows );
        }
    break;

  case 419:
/* Line 664 of lalr1.cc  */
#line 3358 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 420:
/* Line 664 of lalr1.cc  */
#line 3362 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "lax", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 421:
/* Line 664 of lalr1.cc  */
#line 3366 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 422:
/* Line 664 of lalr1.cc  */
#line 3370 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr(
                LOC((yyloc)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (3)].node))->get_name(), (yysemantic_stack_[(6) - (5)].expr)
            );
            delete (yysemantic_stack_[(6) - (3)].node);
        }
    break;

  case 423:
/* Line 664 of lalr1.cc  */
#line 3379 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(3) - (1)].node)), NULL
            );
        }
    break;

  case 424:
/* Line 664 of lalr1.cc  */
#line 3385 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)), (yysemantic_stack_[(4) - (3)].expr)
            );
        }
    break;

  case 425:
/* Line 664 of lalr1.cc  */
#line 3393 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            PragmaList *pl = new PragmaList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = pl;
        }
    break;

  case 426:
/* Line 664 of lalr1.cc  */
#line 3399 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            if ( PragmaList *pl = dynamic_cast<PragmaList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 427:
/* Line 664 of lalr1.cc  */
#line 3407 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
        }
    break;

  case 428:
/* Line 664 of lalr1.cc  */
#line 3411 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) ), "" );
        }
    break;

  case 429:
/* Line 664 of lalr1.cc  */
#line 3415 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), true ), "" );
        }
    break;

  case 430:
/* Line 664 of lalr1.cc  */
#line 3421 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new PathExpr(LOC((yyloc)), ParseConstants::path_leading_lone_slash, NULL);
    }
    break;

  case 431:
/* Line 664 of lalr1.cc  */
#line 3425 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      RelativePathExpr* rpe;
      rpe = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slash, NULL, (yysemantic_stack_[(2) - (2)].expr), false);
      (yyval.expr) = new PathExpr(LOC((yyloc)),
                        ParseConstants::path_leading_slash,
                        rpe);
    }
    break;

  case 432:
/* Line 664 of lalr1.cc  */
#line 3433 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      RelativePathExpr* rpe;
      rpe = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slashslash, NULL, (yysemantic_stack_[(2) - (2)].expr), false);
      (yyval.expr) = new PathExpr(LOC((yyloc)),
                        ParseConstants::path_leading_slashslash,
                        rpe);
    }
    break;

  case 433:
/* Line 664 of lalr1.cc  */
#line 3441 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      RelativePathExpr* rpe = dynamic_cast<RelativePathExpr*>((yysemantic_stack_[(1) - (1)].expr));
      if (rpe != NULL &&
          ((dynamic_cast<ContextItemExpr*>(rpe->get_step_expr()) != NULL &&
           dynamic_cast<ContextItemExpr*>(rpe->get_step_expr())->is_placeholder() &&
           dynamic_cast<AxisStep*>(rpe->get_relpath_expr()) != NULL)
           ||
           dynamic_cast<AxisStep*>(rpe->get_step_expr()) != NULL))
      {
        driver.addCommonLanguageWarning((yylocation_stack_[(1) - (1)]), ZED(ZWST0009_AXIS_STEP));
      }
      (yyval.expr) = (!rpe ?
            (yysemantic_stack_[(1) - (1)].expr) :
            new PathExpr( LOC((yyloc)), ParseConstants::path_relative, (yysemantic_stack_[(1) - (1)].expr)));
    }
    break;

  case 434:
/* Line 664 of lalr1.cc  */
#line 3459 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = NULL;
    }
    break;

  case 435:
/* Line 664 of lalr1.cc  */
#line 3465 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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

  case 436:
/* Line 664 of lalr1.cc  */
#line 3475 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr), false);
    }
    break;

  case 437:
/* Line 664 of lalr1.cc  */
#line 3479 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slashslash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr), false);
    }
    break;

  case 440:
/* Line 664 of lalr1.cc  */
#line 3489 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)), dynamic_cast<ForwardStep*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 441:
/* Line 664 of lalr1.cc  */
#line 3495 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)),
                dynamic_cast<ForwardStep*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 442:
/* Line 664 of lalr1.cc  */
#line 3503 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)), dynamic_cast<ReverseStep*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 443:
/* Line 664 of lalr1.cc  */
#line 3509 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)),
                dynamic_cast<ReverseStep*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 444:
/* Line 664 of lalr1.cc  */
#line 3519 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardStep(
                LOC((yyloc)), dynamic_cast<ForwardAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node)
            );
        }
    break;

  case 445:
/* Line 664 of lalr1.cc  */
#line 3525 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardStep(
                LOC((yyloc)), dynamic_cast<AbbrevForwardStep*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 446:
/* Line 664 of lalr1.cc  */
#line 3533 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_child );
        }
    break;

  case 447:
/* Line 664 of lalr1.cc  */
#line 3537 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_descendant);
        }
    break;

  case 448:
/* Line 664 of lalr1.cc  */
#line 3541 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_attribute );
        }
    break;

  case 449:
/* Line 664 of lalr1.cc  */
#line 3545 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_self );
        }
    break;

  case 450:
/* Line 664 of lalr1.cc  */
#line 3549 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis(
                LOC((yyloc)), ParseConstants::axis_descendant_or_self
            );
        }
    break;

  case 451:
/* Line 664 of lalr1.cc  */
#line 3555 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis(
                LOC((yyloc)), ParseConstants::axis_following_sibling
            );
        }
    break;

  case 452:
/* Line 664 of lalr1.cc  */
#line 3561 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_following );
        }
    break;

  case 453:
/* Line 664 of lalr1.cc  */
#line 3567 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AbbrevForwardStep( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), false );
        }
    break;

  case 454:
/* Line 664 of lalr1.cc  */
#line 3571 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AbbrevForwardStep( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].node), true );
        }
    break;

  case 455:
/* Line 664 of lalr1.cc  */
#line 3577 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseStep( LOC((yyloc)), dynamic_cast<ReverseAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node) );
        }
    break;

  case 456:
/* Line 664 of lalr1.cc  */
#line 3581 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            ReverseAxis *ra = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_parent
            );
            (yyval.node) = new ReverseStep( LOC((yyloc)), ra, NULL );
        }
    break;

  case 457:
/* Line 664 of lalr1.cc  */
#line 3590 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_parent );
        }
    break;

  case 458:
/* Line 664 of lalr1.cc  */
#line 3594 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_ancestor );
        }
    break;

  case 459:
/* Line 664 of lalr1.cc  */
#line 3598 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_preceding_sibling
            );
        }
    break;

  case 460:
/* Line 664 of lalr1.cc  */
#line 3604 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_preceding );
        }
    break;

  case 461:
/* Line 664 of lalr1.cc  */
#line 3608 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_ancestor_or_self
            );
        }
    break;

  case 464:
/* Line 664 of lalr1.cc  */
#line 3620 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 465:
/* Line 664 of lalr1.cc  */
#line 3624 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), dynamic_cast<Wildcard*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 466:
/* Line 664 of lalr1.cc  */
#line 3630 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", "", ParseConstants::wild_all, false);
    }
    break;

  case 467:
/* Line 664 of lalr1.cc  */
#line 3634 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), "", ParseConstants::wild_elem, false);
    }
    break;

  case 468:
/* Line 664 of lalr1.cc  */
#line 3638 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), "", ParseConstants::wild_elem, true);
    }
    break;

  case 469:
/* Line 664 of lalr1.cc  */
#line 3642 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", SYMTAB((yysemantic_stack_[(1) - (1)].sval)), ParseConstants::wild_prefix, false);
    }
    break;

  case 470:
/* Line 664 of lalr1.cc  */
#line 3648 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
     }
    break;

  case 471:
/* Line 664 of lalr1.cc  */
#line 3652 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new FilterExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
     }
    break;

  case 472:
/* Line 664 of lalr1.cc  */
#line 3656 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DynamicFunctionInvocation(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), false);
     }
    break;

  case 473:
/* Line 664 of lalr1.cc  */
#line 3660 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DynamicFunctionInvocation(LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node)), false);
     }
    break;

  case 474:
/* Line 664 of lalr1.cc  */
#line 3666 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            PredicateList *pl = new PredicateList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<exprnode*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.node) = pl;
        }
    break;

  case 475:
/* Line 664 of lalr1.cc  */
#line 3672 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            if ( PredicateList *pl = dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<exprnode*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 476:
/* Line 664 of lalr1.cc  */
#line 3680 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
        }
    break;

  case 491:
/* Line 664 of lalr1.cc  */
#line 3702 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 492:
/* Line 664 of lalr1.cc  */
#line 3706 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 493:
/* Line 664 of lalr1.cc  */
#line 3712 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_decimal, *(yysemantic_stack_[(1) - (1)].decval)
            );
            delete yylval.decval;
        }
    break;

  case 494:
/* Line 664 of lalr1.cc  */
#line 3719 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_integer, *(yysemantic_stack_[(1) - (1)].ival)
            );
            delete yylval.ival;
        }
    break;

  case 495:
/* Line 664 of lalr1.cc  */
#line 3726 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_double, *(yysemantic_stack_[(1) - (1)].dval)
            );
            delete yylval.dval;
        }
    break;

  case 496:
/* Line 664 of lalr1.cc  */
#line 3735 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new VarRef(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)));
        }
    break;

  case 497:
/* Line 664 of lalr1.cc  */
#line 3741 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), NULL);
        }
    break;

  case 498:
/* Line 664 of lalr1.cc  */
#line 3745 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 499:
/* Line 664 of lalr1.cc  */
#line 3751 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            driver.addCommonLanguageWarning((yylocation_stack_[(1) - (1)]), ZED(ZWST0009_CONTEXT_ITEM_EXPR));
            (yyval.expr) = new ContextItemExpr( LOC((yyloc)) );
        }
    break;

  case 500:
/* Line 664 of lalr1.cc  */
#line 3758 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new OrderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 501:
/* Line 664 of lalr1.cc  */
#line 3764 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnorderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 502:
/* Line 664 of lalr1.cc  */
#line 3770 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FunctionCall( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), NULL );
    }
    break;

  case 503:
/* Line 664 of lalr1.cc  */
#line 3774 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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

  case 504:
/* Line 664 of lalr1.cc  */
#line 3792 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      ArgList *al = new ArgList( LOC((yyloc)) );
      al->push_back(new ArgumentPlaceholder(LOC((yyloc))));
      (yyval.node) = al;
    }
    break;

  case 505:
/* Line 664 of lalr1.cc  */
#line 3798 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      if ( ArgList *al = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node)) )
        al->push_back( new ArgumentPlaceholder(LOC((yyloc))) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 506:
/* Line 664 of lalr1.cc  */
#line 3804 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      ArgList *al = new ArgList( LOC((yyloc)) );
      al->push_back( (yysemantic_stack_[(1) - (1)].expr) );
      (yyval.node) = al;
    }
    break;

  case 507:
/* Line 664 of lalr1.cc  */
#line 3810 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      if ( ArgList *al = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node)) )
        al->push_back( (yysemantic_stack_[(3) - (3)].expr) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 508:
/* Line 664 of lalr1.cc  */
#line 3818 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 509:
/* Line 664 of lalr1.cc  */
#line 3822 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 510:
/* Line 664 of lalr1.cc  */
#line 3828 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new LiteralFunctionItem(LOC ((yyloc)), dynamic_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].ival));
    }
    break;

  case 511:
/* Line 664 of lalr1.cc  */
#line 3834 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new InlineFunction(LOC((yyloc)),
                              &*(yysemantic_stack_[(3) - (2)].fnsig)->theParams,
                              &*(yysemantic_stack_[(3) - (2)].fnsig)->theReturnType,
                              (yysemantic_stack_[(3) - (3)].expr));
      delete (yysemantic_stack_[(3) - (2)].fnsig);
    }
    break;

  case 517:
/* Line 664 of lalr1.cc  */
#line 3853 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirElemConstructor(LOC((yyloc)),
                                  static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                                  NULL,
                                  NULL,
                                  NULL);
    }
    break;

  case 518:
/* Line 664 of lalr1.cc  */
#line 3861 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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

  case 519:
/* Line 664 of lalr1.cc  */
#line 3877 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirElemConstructor(LOC((yyloc)),
                                  static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                                  NULL,
                                  dynamic_cast<DirAttributeList*>((yysemantic_stack_[(5) - (3)].node)),
                                  NULL);
    }
    break;

  case 520:
/* Line 664 of lalr1.cc  */
#line 3885 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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

  case 521:
/* Line 664 of lalr1.cc  */
#line 3903 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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

  case 522:
/* Line 664 of lalr1.cc  */
#line 3921 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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

  case 523:
/* Line 664 of lalr1.cc  */
#line 3939 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      DirElemContentList *decl = new DirElemContentList( LOC((yyloc)) );
      decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(1) - (1)].expr)) );
      (yyval.node) = decl;
    }
    break;

  case 524:
/* Line 664 of lalr1.cc  */
#line 3945 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      DirElemContentList *decl = dynamic_cast<DirElemContentList*>((yysemantic_stack_[(2) - (1)].node));
      if ( decl )
        decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(2) - (2)].expr)) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 525:
/* Line 664 of lalr1.cc  */
#line 3954 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      DirAttributeList *dal = new DirAttributeList( LOC((yyloc)) );
      dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = dal;
    }
    break;

  case 526:
/* Line 664 of lalr1.cc  */
#line 3960 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      DirAttributeList *dal = dynamic_cast<DirAttributeList*>((yysemantic_stack_[(2) - (1)].node));
      if ( dal )
        dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 527:
/* Line 664 of lalr1.cc  */
#line 3969 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DirAttr(LOC((yyloc)),
                       static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                       dynamic_cast<DirAttributeValue*>((yysemantic_stack_[(6) - (6)].node)));
    }
    break;

  case 530:
/* Line 664 of lalr1.cc  */
#line 3979 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DirAttributeValue(LOC((yyloc)),
                                 dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
    }
    break;

  case 531:
/* Line 664 of lalr1.cc  */
#line 3984 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DirAttributeValue( LOC((yyloc)),
                                  dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
    }
    break;

  case 532:
/* Line 664 of lalr1.cc  */
#line 3990 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QuoteAttrContentList( LOC((yyloc)) );
    }
    break;

  case 533:
/* Line 664 of lalr1.cc  */
#line 3994 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 534:
/* Line 664 of lalr1.cc  */
#line 4000 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
      qacl->push_back( new QuoteAttrValueContent( LOC((yyloc)), "\"" ) );
      (yyval.node) = qacl;
    }
    break;

  case 535:
/* Line 664 of lalr1.cc  */
#line 4006 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
      qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = qacl;
    }
    break;

  case 536:
/* Line 664 of lalr1.cc  */
#line 4012 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      QuoteAttrContentList* qacl = dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
      if ( qacl )
        qacl->push_back( new QuoteAttrValueContent( LOC((yyloc)), "\"" ) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 537:
/* Line 664 of lalr1.cc  */
#line 4019 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      QuoteAttrContentList *qacl = dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
      if ( qacl )
        qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 538:
/* Line 664 of lalr1.cc  */
#line 4027 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AposAttrContentList( LOC((yyloc)) );
    }
    break;

  case 539:
/* Line 664 of lalr1.cc  */
#line 4031 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 540:
/* Line 664 of lalr1.cc  */
#line 4037 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
      aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
      (yyval.node) = aacl;
    }
    break;

  case 541:
/* Line 664 of lalr1.cc  */
#line 4043 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
      aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = aacl;
    }
    break;

  case 542:
/* Line 664 of lalr1.cc  */
#line 4049 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
      if (aacl)
        aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 543:
/* Line 664 of lalr1.cc  */
#line 4056 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
      if ( aacl )
        aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 544:
/* Line 664 of lalr1.cc  */
#line 4065 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QuoteAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
    }
    break;

  case 545:
/* Line 664 of lalr1.cc  */
#line 4069 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QuoteAttrValueContent(LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
    }
    break;

  case 546:
/* Line 664 of lalr1.cc  */
#line 4075 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AposAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
    }
    break;

  case 547:
/* Line 664 of lalr1.cc  */
#line 4079 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AposAttrValueContent(LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
    }
    break;

  case 548:
/* Line 664 of lalr1.cc  */
#line 4085 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirElemContent( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr) );
    }
    break;

  case 549:
/* Line 664 of lalr1.cc  */
#line 4089 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirElemContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
    }
    break;

  case 550:
/* Line 664 of lalr1.cc  */
#line 4093 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      rchandle<CDataSection> cdata_h = dynamic_cast<CDataSection*>((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = new DirElemContent( LOC((yyloc)), cdata_h );
    }
    break;

  case 551:
/* Line 664 of lalr1.cc  */
#line 4098 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      rchandle<CommonContent> cont_h = dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = new DirElemContent( LOC((yyloc)), cont_h );
    }
    break;

  case 552:
/* Line 664 of lalr1.cc  */
#line 4105 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CommonContent(LOC((yyloc)), ParseConstants::cont_charref, SYMTAB((yysemantic_stack_[(1) - (1)].sval)));
    }
    break;

  case 553:
/* Line 664 of lalr1.cc  */
#line 4109 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CommonContent(LOC((yyloc)), ParseConstants::cont_escape_lbrace);
    }
    break;

  case 554:
/* Line 664 of lalr1.cc  */
#line 4113 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CommonContent(LOC((yyloc)), ParseConstants::cont_escape_rbrace);
    }
    break;

  case 555:
/* Line 664 of lalr1.cc  */
#line 4117 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CommonContent(LOC((yyloc)), new EnclosedExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr)));
    }
    break;

  case 556:
/* Line 664 of lalr1.cc  */
#line 4123 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 557:
/* Line 664 of lalr1.cc  */
#line 4128 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), "" );
    }
    break;

  case 558:
/* Line 664 of lalr1.cc  */
#line 4134 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      ERROR_IF_QNAME_NOT_NCNAME((yysemantic_stack_[(3) - (2)].expr), (yylocation_stack_[(3) - (2)]));
      (yyval.expr) = new DirPIConstructor( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)) );
    }
    break;

  case 559:
/* Line 664 of lalr1.cc  */
#line 4140 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      ERROR_IF_QNAME_NOT_NCNAME((yysemantic_stack_[(3) - (2)].expr), (yylocation_stack_[(3) - (2)]));
      (yyval.expr) = new DirPIConstructor( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
    }
    break;

  case 560:
/* Line 664 of lalr1.cc  */
#line 4147 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CDataSection( LOC((yyloc)),SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
    }
    break;

  case 561:
/* Line 664 of lalr1.cc  */
#line 4153 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 562:
/* Line 664 of lalr1.cc  */
#line 4158 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 563:
/* Line 664 of lalr1.cc  */
#line 4163 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 564:
/* Line 664 of lalr1.cc  */
#line 4168 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 565:
/* Line 664 of lalr1.cc  */
#line 4173 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 566:
/* Line 664 of lalr1.cc  */
#line 4178 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 568:
/* Line 664 of lalr1.cc  */
#line 4186 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CompDocConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
    }
    break;

  case 569:
/* Line 664 of lalr1.cc  */
#line 4192 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CompElemConstructor(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval))), (yysemantic_stack_[(3) - (2)].expr));
    }
    break;

  case 570:
/* Line 664 of lalr1.cc  */
#line 4196 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CompElemConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
    }
    break;

  case 571:
/* Line 664 of lalr1.cc  */
#line 4202 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval))), (yysemantic_stack_[(3) - (2)].expr) );
    }
    break;

  case 572:
/* Line 664 of lalr1.cc  */
#line 4206 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
    }
    break;

  case 573:
/* Line 664 of lalr1.cc  */
#line 4212 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CompTextConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
    }
    break;

  case 574:
/* Line 664 of lalr1.cc  */
#line 4218 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CompCommentConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
    }
    break;

  case 575:
/* Line 664 of lalr1.cc  */
#line 4224 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CompPIConstructor(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval)), (yysemantic_stack_[(3) - (2)].expr));
    }
    break;

  case 576:
/* Line 664 of lalr1.cc  */
#line 4228 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CompPIConstructor(LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
    }
    break;

  case 577:
/* Line 664 of lalr1.cc  */
#line 4234 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CompNamespaceConstructor(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval)), (yysemantic_stack_[(3) - (2)].expr));
    }
    break;

  case 578:
/* Line 664 of lalr1.cc  */
#line 4238 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CompNamespaceConstructor(LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
    }
    break;

  case 579:
/* Line 664 of lalr1.cc  */
#line 4244 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 580:
/* Line 664 of lalr1.cc  */
#line 4250 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL );
        }
    break;

  case 581:
/* Line 664 of lalr1.cc  */
#line 4254 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node)));
        }
    break;

  case 582:
/* Line 664 of lalr1.cc  */
#line 4258 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 583:
/* Line 664 of lalr1.cc  */
#line 4264 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_optionally
            );
        }
    break;

  case 584:
/* Line 664 of lalr1.cc  */
#line 4270 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_zero_or_more
            );
        }
    break;

  case 585:
/* Line 664 of lalr1.cc  */
#line 4276 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_one_or_more
            );
        }
    break;

  case 586:
/* Line 664 of lalr1.cc  */
#line 4284 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 587:
/* Line 664 of lalr1.cc  */
#line 4288 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 588:
/* Line 664 of lalr1.cc  */
#line 4292 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ItemType( LOC((yyloc)), true );
        }
    break;

  case 589:
/* Line 664 of lalr1.cc  */
#line 4296 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new StructuredItemType(LOC((yyloc)));
        }
    break;

  case 590:
/* Line 664 of lalr1.cc  */
#line 4300 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 591:
/* Line 664 of lalr1.cc  */
#line 4304 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 592:
/* Line 664 of lalr1.cc  */
#line 4308 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 593:
/* Line 664 of lalr1.cc  */
#line 4314 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
          TypeList* aTypeList = new TypeList(LOC ((yyloc)));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(1) - (1)].node)));
          (yyval.node) = aTypeList;
        }
    break;

  case 594:
/* Line 664 of lalr1.cc  */
#line 4320 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
          TypeList* aTypeList = dynamic_cast<TypeList *>((yysemantic_stack_[(3) - (1)].node));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
          (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 595:
/* Line 664 of lalr1.cc  */
#line 4328 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GeneralizedAtomicType( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
    }
    break;

  case 596:
/* Line 664 of lalr1.cc  */
#line 4334 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SimpleType( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
    }
    break;

  case 597:
/* Line 664 of lalr1.cc  */
#line 4340 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 598:
/* Line 664 of lalr1.cc  */
#line 4344 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 599:
/* Line 664 of lalr1.cc  */
#line 4348 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 600:
/* Line 664 of lalr1.cc  */
#line 4352 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 601:
/* Line 664 of lalr1.cc  */
#line 4356 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 602:
/* Line 664 of lalr1.cc  */
#line 4360 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 603:
/* Line 664 of lalr1.cc  */
#line 4364 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 604:
/* Line 664 of lalr1.cc  */
#line 4368 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 605:
/* Line 664 of lalr1.cc  */
#line 4372 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 606:
/* Line 664 of lalr1.cc  */
#line 4376 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 607:
/* Line 664 of lalr1.cc  */
#line 4382 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnyKindTest( LOC((yyloc)) );
    }
    break;

  case 608:
/* Line 664 of lalr1.cc  */
#line 4388 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = NULL;
    }
    break;

  case 609:
/* Line 664 of lalr1.cc  */
#line 4394 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DocumentTest(LOC((yyloc)));
    }
    break;

  case 610:
/* Line 664 of lalr1.cc  */
#line 4398 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DocumentTest(LOC((yyloc)), dynamic_cast<ElementTest*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 611:
/* Line 664 of lalr1.cc  */
#line 4402 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DocumentTest(LOC((yyloc)), dynamic_cast<SchemaElementTest*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 612:
/* Line 664 of lalr1.cc  */
#line 4408 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new NamespaceTest(LOC((yyloc)));
    }
    break;

  case 613:
/* Line 664 of lalr1.cc  */
#line 4413 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new TextTest(LOC((yyloc)));
    }
    break;

  case 614:
/* Line 664 of lalr1.cc  */
#line 4419 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CommentTest(LOC((yyloc)));
    }
    break;

  case 615:
/* Line 664 of lalr1.cc  */
#line 4425 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), "" );
        }
    break;

  case 616:
/* Line 664 of lalr1.cc  */
#line 4429 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            ERROR_IF_QNAME_NOT_NCNAME((yysemantic_stack_[(4) - (3)].expr), (yylocation_stack_[(4) - (3)]));
            (yyval.node) = new PITest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 617:
/* Line 664 of lalr1.cc  */
#line 4434 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 618:
/* Line 664 of lalr1.cc  */
#line 4440 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 619:
/* Line 664 of lalr1.cc  */
#line 4444 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL
            );
        }
    break;

  case 620:
/* Line 664 of lalr1.cc  */
#line 4450 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 621:
/* Line 664 of lalr1.cc  */
#line 4456 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 622:
/* Line 664 of lalr1.cc  */
#line 4460 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 623:
/* Line 664 of lalr1.cc  */
#line 4468 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaAttributeTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 624:
/* Line 664 of lalr1.cc  */
#line 4474 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest( LOC((yyloc)), NULL, NULL, true );
        }
    break;

  case 625:
/* Line 664 of lalr1.cc  */
#line 4478 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL, true
            );
        }
    break;

  case 626:
/* Line 664 of lalr1.cc  */
#line 4484 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                false
            );
        }
    break;

  case 627:
/* Line 664 of lalr1.cc  */
#line 4493 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                true
            );
        }
    break;

  case 628:
/* Line 664 of lalr1.cc  */
#line 4502 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, NULL, true
            );
        }
    break;

  case 629:
/* Line 664 of lalr1.cc  */
#line 4508 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), false
            );
        }
    break;

  case 630:
/* Line 664 of lalr1.cc  */
#line 4514 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), true
            );
        }
    break;

  case 631:
/* Line 664 of lalr1.cc  */
#line 4522 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaElementTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 632:
/* Line 664 of lalr1.cc  */
#line 4528 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 633:
/* Line 664 of lalr1.cc  */
#line 4534 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (1)].expr)), true );
        }
    break;

  case 634:
/* Line 664 of lalr1.cc  */
#line 4540 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new StringLiteral( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 635:
/* Line 664 of lalr1.cc  */
#line 4546 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 636:
/* Line 664 of lalr1.cc  */
#line 4550 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 637:
/* Line 664 of lalr1.cc  */
#line 4556 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnyFunctionTest(LOC((yyloc)));
    }
    break;

  case 638:
/* Line 664 of lalr1.cc  */
#line 4562 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)), dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (5)].node)));
        }
    break;

  case 639:
/* Line 664 of lalr1.cc  */
#line 4566 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)),
              dynamic_cast<TypeList *>((yysemantic_stack_[(6) - (3)].node)),
              dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (6)].node)));
        }
    break;

  case 640:
/* Line 664 of lalr1.cc  */
#line 4574 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
           (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 641:
/* Line 664 of lalr1.cc  */
#line 4580 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::strict_validation
            );
        }
    break;

  case 642:
/* Line 664 of lalr1.cc  */
#line 4586 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::lax_validation
            );
        }
    break;

  case 643:
/* Line 664 of lalr1.cc  */
#line 4592 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::skip_validation
            );
        }
    break;

  case 644:
/* Line 664 of lalr1.cc  */
#line 4600 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 645:
/* Line 664 of lalr1.cc  */
#line 4604 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 646:
/* Line 664 of lalr1.cc  */
#line 4610 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 647:
/* Line 664 of lalr1.cc  */
#line 4616 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 648:
/* Line 664 of lalr1.cc  */
#line 4620 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 649:
/* Line 664 of lalr1.cc  */
#line 4626 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 650:
/* Line 664 of lalr1.cc  */
#line 4630 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 651:
/* Line 664 of lalr1.cc  */
#line 4636 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                  LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 652:
/* Line 664 of lalr1.cc  */
#line 4642 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)),
                store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 653:
/* Line 664 of lalr1.cc  */
#line 4649 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 654:
/* Line 664 of lalr1.cc  */
#line 4657 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 655:
/* Line 664 of lalr1.cc  */
#line 4662 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 656:
/* Line 664 of lalr1.cc  */
#line 4668 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::NODE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 657:
/* Line 664 of lalr1.cc  */
#line 4674 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::VALUE_OF_NODE, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 658:
/* Line 664 of lalr1.cc  */
#line 4682 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RenameExpr( LOC ((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 659:
/* Line 664 of lalr1.cc  */
#line 4688 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList *cvl = dynamic_cast<CopyVarList*>((yysemantic_stack_[(7) - (3)].expr));
      (yyval.expr) = new TransformExpr( LOC((yyloc)), cvl, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr) );
    }
    break;

  case 660:
/* Line 664 of lalr1.cc  */
#line 4695 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList* lList = new CopyVarList(LOC((yyloc)));
      lList->push_back (dynamic_cast<VarBinding*> ((yysemantic_stack_[(1) - (1)].expr)));
      (yyval.expr) = lList;
    }
    break;

  case 661:
/* Line 664 of lalr1.cc  */
#line 4701 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList* lList = dynamic_cast<CopyVarList*>((yysemantic_stack_[(4) - (1)].expr));
      VarBinding* lBinding = dynamic_cast<VarBinding*>((yysemantic_stack_[(4) - (4)].expr));
      lList->push_back(lBinding);
      (yyval.expr) = lList;
    }
    break;

  case 662:
/* Line 664 of lalr1.cc  */
#line 4710 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new VarBinding(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 663:
/* Line 664 of lalr1.cc  */
#line 4716 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new TryExpr( LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 664:
/* Line 664 of lalr1.cc  */
#line 4722 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            CatchListExpr *cle = new CatchListExpr( LOC((yyloc)) );
            cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.expr) = cle;
        }
    break;

  case 665:
/* Line 664 of lalr1.cc  */
#line 4728 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
            if ( cle )
                cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
        }
    break;

  case 666:
/* Line 664 of lalr1.cc  */
#line 4737 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)), *(yysemantic_stack_[(3) - (2)].name_test_list), (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 667:
/* Line 664 of lalr1.cc  */
#line 4744 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 668:
/* Line 664 of lalr1.cc  */
#line 4750 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            CatchExpr::NameTestList *ntl = new CatchExpr::NameTestList;
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 669:
/* Line 664 of lalr1.cc  */
#line 4756 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            CatchExpr::NameTestList *ntl =
                static_cast<CatchExpr::NameTestList*>((yysemantic_stack_[(3) - (1)].name_test_list));
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 670:
/* Line 664 of lalr1.cc  */
#line 4765 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTSelection( LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), (yysemantic_stack_[(2) - (2)].pos_filter_list) );
            delete (yysemantic_stack_[(2) - (2)].pos_filter_list);
        }
    break;

  case 671:
/* Line 664 of lalr1.cc  */
#line 4772 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = NULL;
        }
    break;

  case 672:
/* Line 664 of lalr1.cc  */
#line 4776 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = (yysemantic_stack_[(1) - (1)].pos_filter_list);
        }
    break;

  case 673:
/* Line 664 of lalr1.cc  */
#line 4782 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = new FTSelection::pos_filter_list_t;
            (yyval.pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 674:
/* Line 664 of lalr1.cc  */
#line 4787 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yysemantic_stack_[(2) - (1)].pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.pos_filter_list) = (yysemantic_stack_[(2) - (1)].pos_filter_list);
        }
    break;

  case 675:
/* Line 664 of lalr1.cc  */
#line 4794 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 676:
/* Line 664 of lalr1.cc  */
#line 4798 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTOr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 677:
/* Line 664 of lalr1.cc  */
#line 4804 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 678:
/* Line 664 of lalr1.cc  */
#line 4808 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnd( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 679:
/* Line 664 of lalr1.cc  */
#line 4814 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 680:
/* Line 664 of lalr1.cc  */
#line 4818 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTMildNot( LOC((yyloc)), (yysemantic_stack_[(4) - (1)].node), (yysemantic_stack_[(4) - (4)].node) );
        }
    break;

  case 681:
/* Line 664 of lalr1.cc  */
#line 4824 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 682:
/* Line 664 of lalr1.cc  */
#line 4828 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnaryNot(
                LOC((yyloc)), dynamic_cast<FTPrimaryWithOptions*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 683:
/* Line 664 of lalr1.cc  */
#line 4836 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTPrimaryWithOptions(
                LOC((yyloc)),
                dynamic_cast<FTPrimary*>((yysemantic_stack_[(3) - (1)].node)),
                dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<FTWeight*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 684:
/* Line 664 of lalr1.cc  */
#line 4846 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 685:
/* Line 664 of lalr1.cc  */
#line 4850 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 686:
/* Line 664 of lalr1.cc  */
#line 4855 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 687:
/* Line 664 of lalr1.cc  */
#line 4859 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 688:
/* Line 664 of lalr1.cc  */
#line 4865 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWeight( LOC((yyloc)), dynamic_cast<exprnode*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 689:
/* Line 664 of lalr1.cc  */
#line 4871 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsTimes(
                LOC((yyloc)),
                dynamic_cast<FTWords*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<FTTimes*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 690:
/* Line 664 of lalr1.cc  */
#line 4879 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 691:
/* Line 664 of lalr1.cc  */
#line 4883 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 692:
/* Line 664 of lalr1.cc  */
#line 4888 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 693:
/* Line 664 of lalr1.cc  */
#line 4892 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 694:
/* Line 664 of lalr1.cc  */
#line 4898 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTExtensionSelection(
                LOC((yyloc)),
                dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)),
                dynamic_cast<FTSelection*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 695:
/* Line 664 of lalr1.cc  */
#line 4907 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 696:
/* Line 664 of lalr1.cc  */
#line 4911 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 697:
/* Line 664 of lalr1.cc  */
#line 4917 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWords(
                LOC((yyloc)),
                dynamic_cast<FTWordsValue*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<FTAnyallOption*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 698:
/* Line 664 of lalr1.cc  */
#line 4927 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), static_cast<StringLiteral*>((yysemantic_stack_[(1) - (1)].expr)), NULL
            );
        }
    break;

  case 699:
/* Line 664 of lalr1.cc  */
#line 4933 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), NULL, dynamic_cast<exprnode*>((yysemantic_stack_[(3) - (2)].expr))
            );
        }
    break;

  case 700:
/* Line 664 of lalr1.cc  */
#line 4940 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::any );
        }
    break;

  case 701:
/* Line 664 of lalr1.cc  */
#line 4944 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 702:
/* Line 664 of lalr1.cc  */
#line 4950 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 703:
/* Line 664 of lalr1.cc  */
#line 4954 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 704:
/* Line 664 of lalr1.cc  */
#line 4958 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::phrase );
        }
    break;

  case 705:
/* Line 664 of lalr1.cc  */
#line 4963 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any;
        }
    break;

  case 706:
/* Line 664 of lalr1.cc  */
#line 4967 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any_word;
        }
    break;

  case 707:
/* Line 664 of lalr1.cc  */
#line 4972 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all;
        }
    break;

  case 708:
/* Line 664 of lalr1.cc  */
#line 4976 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all_words;
        }
    break;

  case 709:
/* Line 664 of lalr1.cc  */
#line 4982 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 710:
/* Line 664 of lalr1.cc  */
#line 4986 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 711:
/* Line 664 of lalr1.cc  */
#line 4990 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 712:
/* Line 664 of lalr1.cc  */
#line 4994 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 713:
/* Line 664 of lalr1.cc  */
#line 4998 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 714:
/* Line 664 of lalr1.cc  */
#line 5004 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTOrder( LOC((yyloc)) );
        }
    break;

  case 715:
/* Line 664 of lalr1.cc  */
#line 5010 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWindow(
                LOC((yyloc)),
                static_cast<AdditiveExpr*>((yysemantic_stack_[(3) - (2)].expr)),
                static_cast<FTUnit*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 716:
/* Line 664 of lalr1.cc  */
#line 5020 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDistance(
                LOC((yyloc)),
                dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<FTUnit*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 717:
/* Line 664 of lalr1.cc  */
#line 5030 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::words );
        }
    break;

  case 718:
/* Line 664 of lalr1.cc  */
#line 5034 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::sentences );
        }
    break;

  case 719:
/* Line 664 of lalr1.cc  */
#line 5038 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::paragraphs );
        }
    break;

  case 720:
/* Line 664 of lalr1.cc  */
#line 5044 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            FTMatchOptions *mo = new FTMatchOptions( LOC((yyloc)) );
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = mo;
        }
    break;

  case 721:
/* Line 664 of lalr1.cc  */
#line 5050 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            FTMatchOptions *mo = dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (1)].node));
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 722:
/* Line 664 of lalr1.cc  */
#line 5058 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 723:
/* Line 664 of lalr1.cc  */
#line 5062 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 724:
/* Line 664 of lalr1.cc  */
#line 5066 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 725:
/* Line 664 of lalr1.cc  */
#line 5070 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 726:
/* Line 664 of lalr1.cc  */
#line 5074 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 727:
/* Line 664 of lalr1.cc  */
#line 5078 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 728:
/* Line 664 of lalr1.cc  */
#line 5082 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 729:
/* Line 664 of lalr1.cc  */
#line 5086 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 730:
/* Line 664 of lalr1.cc  */
#line 5092 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::sensitive );
        }
    break;

  case 731:
/* Line 664 of lalr1.cc  */
#line 5096 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::insensitive );
        }
    break;

  case 732:
/* Line 664 of lalr1.cc  */
#line 5100 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::lower );
        }
    break;

  case 733:
/* Line 664 of lalr1.cc  */
#line 5104 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::upper );
        }
    break;

  case 734:
/* Line 664 of lalr1.cc  */
#line 5110 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::sensitive
            );
        }
    break;

  case 735:
/* Line 664 of lalr1.cc  */
#line 5116 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::insensitive
            );
        }
    break;

  case 736:
/* Line 664 of lalr1.cc  */
#line 5124 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTExtensionOption(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval))
            );
        }
    break;

  case 737:
/* Line 664 of lalr1.cc  */
#line 5132 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::stemming );
        }
    break;

  case 738:
/* Line 664 of lalr1.cc  */
#line 5136 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::no_stemming );
        }
    break;

  case 739:
/* Line 664 of lalr1.cc  */
#line 5142 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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

  case 740:
/* Line 664 of lalr1.cc  */
#line 5152 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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

  case 741:
/* Line 664 of lalr1.cc  */
#line 5163 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTThesaurusOption( LOC((yyloc)), NULL, false, true );
        }
    break;

  case 742:
/* Line 664 of lalr1.cc  */
#line 5169 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 743:
/* Line 664 of lalr1.cc  */
#line 5173 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 744:
/* Line 664 of lalr1.cc  */
#line 5178 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = NULL;
        }
    break;

  case 745:
/* Line 664 of lalr1.cc  */
#line 5182 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(2) - (2)].thesaurus_id_list);
        }
    break;

  case 746:
/* Line 664 of lalr1.cc  */
#line 5188 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = new FTThesaurusOption::thesaurus_id_list_t;
            (yyval.thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 747:
/* Line 664 of lalr1.cc  */
#line 5193 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yysemantic_stack_[(3) - (1)].thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(3) - (1)].thesaurus_id_list);
        }
    break;

  case 748:
/* Line 664 of lalr1.cc  */
#line 5200 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTThesaurusID(
                LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (2)].sval)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), dynamic_cast<FTRange*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 749:
/* Line 664 of lalr1.cc  */
#line 5207 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.sval) = 0;
        }
    break;

  case 750:
/* Line 664 of lalr1.cc  */
#line 5211 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.sval) = (yysemantic_stack_[(2) - (2)].sval);
        }
    break;

  case 751:
/* Line 664 of lalr1.cc  */
#line 5217 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 752:
/* Line 664 of lalr1.cc  */
#line 5221 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 753:
/* Line 664 of lalr1.cc  */
#line 5227 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(4) - (3)].node)), (yysemantic_stack_[(4) - (4)].incl_excl_list),
                ft_stop_words_mode::with
            );
            delete (yysemantic_stack_[(4) - (4)].incl_excl_list);
        }
    break;

  case 754:
/* Line 664 of lalr1.cc  */
#line 5236 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, (yysemantic_stack_[(4) - (4)].incl_excl_list), ft_stop_words_mode::with_default
            );
            delete (yysemantic_stack_[(4) - (4)].incl_excl_list);
        }
    break;

  case 755:
/* Line 664 of lalr1.cc  */
#line 5243 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, NULL, ft_stop_words_mode::without
            );
        }
    break;

  case 756:
/* Line 664 of lalr1.cc  */
#line 5251 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), NULL );
        }
    break;

  case 757:
/* Line 664 of lalr1.cc  */
#line 5255 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), "", (yysemantic_stack_[(3) - (2)].strlist) );
        }
    break;

  case 758:
/* Line 664 of lalr1.cc  */
#line 5261 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            string_list_t *sl = new string_list_t;
            sl->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
            (yyval.strlist) = sl;
        }
    break;

  case 759:
/* Line 664 of lalr1.cc  */
#line 5267 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            if ( (yysemantic_stack_[(3) - (1)].strlist) )
                (yysemantic_stack_[(3) - (1)].strlist)->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
            (yyval.strlist) = (yysemantic_stack_[(3) - (1)].strlist);
        }
    break;

  case 760:
/* Line 664 of lalr1.cc  */
#line 5274 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = NULL;
        }
    break;

  case 761:
/* Line 664 of lalr1.cc  */
#line 5278 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = (yysemantic_stack_[(1) - (1)].incl_excl_list);
        }
    break;

  case 762:
/* Line 664 of lalr1.cc  */
#line 5284 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = new FTStopWordOption::incl_excl_list_t;
            (yyval.incl_excl_list)->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 763:
/* Line 664 of lalr1.cc  */
#line 5289 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            FTStopWordOption::incl_excl_list_t *iel = (yysemantic_stack_[(2) - (1)].incl_excl_list);
            if ( !iel )
                iel = new FTStopWordOption::incl_excl_list_t;
            iel->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.incl_excl_list) = iel;
        }
    break;

  case 764:
/* Line 664 of lalr1.cc  */
#line 5299 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordsInclExcl(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(2) - (2)].node)),
                ft_stop_words_unex::union_
            );
        }
    break;

  case 765:
/* Line 664 of lalr1.cc  */
#line 5307 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordsInclExcl(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(2) - (2)].node)),
                ft_stop_words_unex::except
            );
        }
    break;

  case 766:
/* Line 664 of lalr1.cc  */
#line 5317 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTLanguageOption( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 767:
/* Line 664 of lalr1.cc  */
#line 5323 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::with );
        }
    break;

  case 768:
/* Line 664 of lalr1.cc  */
#line 5327 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::without );
        }
    break;

  case 769:
/* Line 664 of lalr1.cc  */
#line 5333 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_start );
        }
    break;

  case 770:
/* Line 664 of lalr1.cc  */
#line 5337 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_end );
        }
    break;

  case 771:
/* Line 664 of lalr1.cc  */
#line 5341 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::entire );
        }
    break;

  case 772:
/* Line 664 of lalr1.cc  */
#line 5347 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTTimes( LOC((yyloc)), dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)) );
        }
    break;

  case 773:
/* Line 664 of lalr1.cc  */
#line 5353 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::exactly, (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 774:
/* Line 664 of lalr1.cc  */
#line 5357 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_least, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 775:
/* Line 664 of lalr1.cc  */
#line 5361 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_most, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 776:
/* Line 664 of lalr1.cc  */
#line 5365 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::from_to, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr) );
        }
    break;

  case 777:
/* Line 664 of lalr1.cc  */
#line 5371 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTScope(
                LOC((yyloc)),
                ft_scope::same,
                dynamic_cast<FTBigUnit*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 778:
/* Line 664 of lalr1.cc  */
#line 5379 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTScope(
                LOC((yyloc)),
                ft_scope::different,
                dynamic_cast<FTBigUnit*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 779:
/* Line 664 of lalr1.cc  */
#line 5389 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::sentence );
        }
    break;

  case 780:
/* Line 664 of lalr1.cc  */
#line 5393 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::paragraph );
        }
    break;

  case 781:
/* Line 664 of lalr1.cc  */
#line 5399 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTIgnoreOption( LOC((yyloc)), static_cast<UnionExpr*>((yysemantic_stack_[(3) - (3)].expr)) );
        }
    break;

  case 782:
/* Line 664 of lalr1.cc  */
#line 5405 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONArrayConstructor( LOC((yyloc)), NULL );
        }
    break;

  case 783:
/* Line 664 of lalr1.cc  */
#line 5409 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONArrayConstructor( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 784:
/* Line 664 of lalr1.cc  */
#line 5415 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), NULL, false);
        }
    break;

  case 785:
/* Line 664 of lalr1.cc  */
#line 5419 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), false);
        }
    break;

  case 786:
/* Line 664 of lalr1.cc  */
#line 5425 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), NULL, true);
        }
    break;

  case 787:
/* Line 664 of lalr1.cc  */
#line 5429 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), true);
        }
    break;

  case 788:
/* Line 664 of lalr1.cc  */
#line 5435 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONDirectObjectConstructor(LOC((yyloc)),
                                               dynamic_cast<JSONPairList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 789:
/* Line 664 of lalr1.cc  */
#line 5442 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
          JSONPairList* jpl = new JSONPairList(LOC((yyloc)));
          jpl->push_back(new JSONPairConstructor(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)));
          (yyval.node) = jpl;
        }
    break;

  case 790:
/* Line 664 of lalr1.cc  */
#line 5448 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
          JSONPairList* jpl = dynamic_cast<JSONPairList*>((yysemantic_stack_[(5) - (1)].node));
          assert(jpl);
          jpl->push_back(new JSONPairConstructor(LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)));
          (yyval.node) = jpl;
        }
    break;

  case 791:
/* Line 664 of lalr1.cc  */
#line 5457 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONObjectInsertExpr(LOC((yyloc)),
                                        (yysemantic_stack_[(5) - (3)].expr),
                                        (yysemantic_stack_[(5) - (5)].expr));
        }
    break;

  case 792:
/* Line 664 of lalr1.cc  */
#line 5463 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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

  case 793:
/* Line 664 of lalr1.cc  */
#line 5473 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONArrayInsertExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (5)].expr), (yysemantic_stack_[(8) - (8)].expr));
        }
    break;

  case 794:
/* Line 664 of lalr1.cc  */
#line 5479 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONArrayAppendExpr(LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
        }
    break;

  case 795:
/* Line 664 of lalr1.cc  */
#line 5485 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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

  case 796:
/* Line 664 of lalr1.cc  */
#line 5506 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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

  case 797:
/* Line 664 of lalr1.cc  */
#line 5530 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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

  case 798:
/* Line 664 of lalr1.cc  */
#line 5554 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 799:
/* Line 664 of lalr1.cc  */
#line 5558 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 800:
/* Line 664 of lalr1.cc  */
#line 5562 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 801:
/* Line 664 of lalr1.cc  */
#line 5568 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonItem);
        }
    break;

  case 802:
/* Line 664 of lalr1.cc  */
#line 5574 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonObject);
        }
    break;

  case 803:
/* Line 664 of lalr1.cc  */
#line 5580 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonArray);
        }
    break;

  case 806:
/* Line 664 of lalr1.cc  */
#line 5589 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))); }
    break;

  case 807:
/* Line 664 of lalr1.cc  */
#line 5590 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("attribute"))); }
    break;

  case 808:
/* Line 664 of lalr1.cc  */
#line 5591 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("comment"))); }
    break;

  case 809:
/* Line 664 of lalr1.cc  */
#line 5592 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("document-node"))); }
    break;

  case 810:
/* Line 664 of lalr1.cc  */
#line 5593 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("namespace-node"))); }
    break;

  case 811:
/* Line 664 of lalr1.cc  */
#line 5594 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("element"))); }
    break;

  case 812:
/* Line 664 of lalr1.cc  */
#line 5595 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("item"))); }
    break;

  case 813:
/* Line 664 of lalr1.cc  */
#line 5596 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("if"))); }
    break;

  case 814:
/* Line 664 of lalr1.cc  */
#line 5597 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("node"))); }
    break;

  case 815:
/* Line 664 of lalr1.cc  */
#line 5598 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("processing-instruction"))); }
    break;

  case 816:
/* Line 664 of lalr1.cc  */
#line 5599 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema-attribute"))); }
    break;

  case 817:
/* Line 664 of lalr1.cc  */
#line 5600 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema-element"))); }
    break;

  case 818:
/* Line 664 of lalr1.cc  */
#line 5601 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("text"))); }
    break;

  case 819:
/* Line 664 of lalr1.cc  */
#line 5602 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("typeswitch"))); }
    break;

  case 820:
/* Line 664 of lalr1.cc  */
#line 5603 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("switch"))); }
    break;

  case 821:
/* Line 664 of lalr1.cc  */
#line 5604 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("empty-sequence"))); }
    break;

  case 822:
/* Line 664 of lalr1.cc  */
#line 5605 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("while"))); }
    break;

  case 824:
/* Line 664 of lalr1.cc  */
#line 5609 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))); }
    break;

  case 825:
/* Line 664 of lalr1.cc  */
#line 5610 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("xquery"))); }
    break;

  case 826:
/* Line 664 of lalr1.cc  */
#line 5611 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("empty"))); }
    break;

  case 827:
/* Line 664 of lalr1.cc  */
#line 5612 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("boundary-space"))); }
    break;

  case 828:
/* Line 664 of lalr1.cc  */
#line 5613 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ft-option"))); }
    break;

  case 829:
/* Line 664 of lalr1.cc  */
#line 5614 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("base-uri"))); }
    break;

  case 830:
/* Line 664 of lalr1.cc  */
#line 5615 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lax"))); }
    break;

  case 831:
/* Line 664 of lalr1.cc  */
#line 5616 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("strict"))); }
    break;

  case 832:
/* Line 664 of lalr1.cc  */
#line 5617 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("idiv"))); }
    break;

  case 833:
/* Line 664 of lalr1.cc  */
#line 5618 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("document"))); }
    break;

  case 834:
/* Line 664 of lalr1.cc  */
#line 5619 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ftnot"))); }
    break;

  case 835:
/* Line 664 of lalr1.cc  */
#line 5620 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("not"))); }
    break;

  case 836:
/* Line 664 of lalr1.cc  */
#line 5621 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sensitive"))); }
    break;

  case 837:
/* Line 664 of lalr1.cc  */
#line 5622 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("insensitive"))); }
    break;

  case 838:
/* Line 664 of lalr1.cc  */
#line 5623 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("diacritics"))); }
    break;

  case 839:
/* Line 664 of lalr1.cc  */
#line 5624 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("without"))); }
    break;

  case 840:
/* Line 664 of lalr1.cc  */
#line 5625 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stemming"))); }
    break;

  case 841:
/* Line 664 of lalr1.cc  */
#line 5626 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("thesaurus"))); }
    break;

  case 842:
/* Line 664 of lalr1.cc  */
#line 5627 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stop"))); }
    break;

  case 843:
/* Line 664 of lalr1.cc  */
#line 5628 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("wildcards"))); }
    break;

  case 844:
/* Line 664 of lalr1.cc  */
#line 5629 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("entire"))); }
    break;

  case 845:
/* Line 664 of lalr1.cc  */
#line 5630 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("content"))); }
    break;

  case 846:
/* Line 664 of lalr1.cc  */
#line 5631 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("word"))); }
    break;

  case 847:
/* Line 664 of lalr1.cc  */
#line 5632 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("start"))); }
    break;

  case 848:
/* Line 664 of lalr1.cc  */
#line 5633 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("end"))); }
    break;

  case 849:
/* Line 664 of lalr1.cc  */
#line 5634 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("most"))); }
    break;

  case 850:
/* Line 664 of lalr1.cc  */
#line 5635 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("skip"))); }
    break;

  case 851:
/* Line 664 of lalr1.cc  */
#line 5636 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("copy"))); }
    break;

  case 852:
/* Line 664 of lalr1.cc  */
#line 5637 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("general"))); }
    break;

  case 853:
/* Line 664 of lalr1.cc  */
#line 5638 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("value"))); }
    break;

  case 854:
/* Line 664 of lalr1.cc  */
#line 5639 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("eq"))); }
    break;

  case 855:
/* Line 664 of lalr1.cc  */
#line 5640 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ne"))); }
    break;

  case 856:
/* Line 664 of lalr1.cc  */
#line 5641 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lt"))); }
    break;

  case 857:
/* Line 664 of lalr1.cc  */
#line 5642 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("le"))); }
    break;

  case 858:
/* Line 664 of lalr1.cc  */
#line 5643 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("gt"))); }
    break;

  case 859:
/* Line 664 of lalr1.cc  */
#line 5644 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ge"))); }
    break;

  case 860:
/* Line 664 of lalr1.cc  */
#line 5645 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("at"))); }
    break;

  case 861:
/* Line 664 of lalr1.cc  */
#line 5646 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("context"))); }
    break;

  case 862:
/* Line 664 of lalr1.cc  */
#line 5647 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("variable"))); }
    break;

  case 863:
/* Line 664 of lalr1.cc  */
#line 5648 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("return"))); }
    break;

  case 864:
/* Line 664 of lalr1.cc  */
#line 5649 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("for"))); }
    break;

  case 865:
/* Line 664 of lalr1.cc  */
#line 5650 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("from"))); }
    break;

  case 866:
/* Line 664 of lalr1.cc  */
#line 5651 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("allowing"))); }
    break;

  case 867:
/* Line 664 of lalr1.cc  */
#line 5652 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sliding"))); }
    break;

  case 868:
/* Line 664 of lalr1.cc  */
#line 5653 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("tumbling"))); }
    break;

  case 869:
/* Line 664 of lalr1.cc  */
#line 5654 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("previous"))); }
    break;

  case 870:
/* Line 664 of lalr1.cc  */
#line 5655 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("next"))); }
    break;

  case 871:
/* Line 664 of lalr1.cc  */
#line 5656 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("only"))); }
    break;

  case 872:
/* Line 664 of lalr1.cc  */
#line 5657 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("when"))); }
    break;

  case 873:
/* Line 664 of lalr1.cc  */
#line 5658 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("count"))); }
    break;

  case 874:
/* Line 664 of lalr1.cc  */
#line 5659 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("in"))); }
    break;

  case 875:
/* Line 664 of lalr1.cc  */
#line 5660 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("let"))); }
    break;

  case 876:
/* Line 664 of lalr1.cc  */
#line 5661 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("where"))); }
    break;

  case 877:
/* Line 664 of lalr1.cc  */
#line 5662 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("by"))); }
    break;

  case 878:
/* Line 664 of lalr1.cc  */
#line 5663 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("group"))); }
    break;

  case 879:
/* Line 664 of lalr1.cc  */
#line 5664 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("order"))); }
    break;

  case 880:
/* Line 664 of lalr1.cc  */
#line 5665 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stable"))); }
    break;

  case 881:
/* Line 664 of lalr1.cc  */
#line 5666 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ascending"))); }
    break;

  case 882:
/* Line 664 of lalr1.cc  */
#line 5667 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descending"))); }
    break;

  case 883:
/* Line 664 of lalr1.cc  */
#line 5668 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("greatest"))); }
    break;

  case 884:
/* Line 664 of lalr1.cc  */
#line 5669 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("least"))); }
    break;

  case 885:
/* Line 664 of lalr1.cc  */
#line 5670 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("collation"))); }
    break;

  case 886:
/* Line 664 of lalr1.cc  */
#line 5671 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("some"))); }
    break;

  case 887:
/* Line 664 of lalr1.cc  */
#line 5672 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("every"))); }
    break;

  case 888:
/* Line 664 of lalr1.cc  */
#line 5673 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("satisfies"))); }
    break;

  case 889:
/* Line 664 of lalr1.cc  */
#line 5674 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("case"))); }
    break;

  case 890:
/* Line 664 of lalr1.cc  */
#line 5675 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("as"))); }
    break;

  case 891:
/* Line 664 of lalr1.cc  */
#line 5676 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("then"))); }
    break;

  case 892:
/* Line 664 of lalr1.cc  */
#line 5677 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("else"))); }
    break;

  case 893:
/* Line 664 of lalr1.cc  */
#line 5678 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("or"))); }
    break;

  case 894:
/* Line 664 of lalr1.cc  */
#line 5679 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("and"))); }
    break;

  case 895:
/* Line 664 of lalr1.cc  */
#line 5680 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("instance"))); }
    break;

  case 896:
/* Line 664 of lalr1.cc  */
#line 5681 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("of"))); }
    break;

  case 897:
/* Line 664 of lalr1.cc  */
#line 5682 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("castable"))); }
    break;

  case 898:
/* Line 664 of lalr1.cc  */
#line 5683 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("to"))); }
    break;

  case 899:
/* Line 664 of lalr1.cc  */
#line 5684 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("div"))); }
    break;

  case 900:
/* Line 664 of lalr1.cc  */
#line 5685 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("mod"))); }
    break;

  case 901:
/* Line 664 of lalr1.cc  */
#line 5686 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("union"))); }
    break;

  case 902:
/* Line 664 of lalr1.cc  */
#line 5687 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("intersect"))); }
    break;

  case 903:
/* Line 664 of lalr1.cc  */
#line 5688 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("except"))); }
    break;

  case 904:
/* Line 664 of lalr1.cc  */
#line 5689 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("validate"))); }
    break;

  case 905:
/* Line 664 of lalr1.cc  */
#line 5690 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("type"))); }
    break;

  case 906:
/* Line 664 of lalr1.cc  */
#line 5691 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("cast"))); }
    break;

  case 907:
/* Line 664 of lalr1.cc  */
#line 5692 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("treat"))); }
    break;

  case 908:
/* Line 664 of lalr1.cc  */
#line 5693 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("is"))); }
    break;

  case 909:
/* Line 664 of lalr1.cc  */
#line 5694 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preserve"))); }
    break;

  case 910:
/* Line 664 of lalr1.cc  */
#line 5695 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("strip"))); }
    break;

  case 911:
/* Line 664 of lalr1.cc  */
#line 5696 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("namespace"))); }
    break;

  case 912:
/* Line 664 of lalr1.cc  */
#line 5697 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("external"))); }
    break;

  case 913:
/* Line 664 of lalr1.cc  */
#line 5698 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("encoding"))); }
    break;

  case 914:
/* Line 664 of lalr1.cc  */
#line 5699 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("no-preserve"))); }
    break;

  case 915:
/* Line 664 of lalr1.cc  */
#line 5700 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("inherit"))); }
    break;

  case 916:
/* Line 664 of lalr1.cc  */
#line 5701 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("no-inherit"))); }
    break;

  case 917:
/* Line 664 of lalr1.cc  */
#line 5702 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("declare"))); }
    break;

  case 918:
/* Line 664 of lalr1.cc  */
#line 5703 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("construction"))); }
    break;

  case 919:
/* Line 664 of lalr1.cc  */
#line 5704 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ordering"))); }
    break;

  case 920:
/* Line 664 of lalr1.cc  */
#line 5705 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("default"))); }
    break;

  case 921:
/* Line 664 of lalr1.cc  */
#line 5706 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("copy-namespaces"))); }
    break;

  case 922:
/* Line 664 of lalr1.cc  */
#line 5707 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("option"))); }
    break;

  case 923:
/* Line 664 of lalr1.cc  */
#line 5708 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("version"))); }
    break;

  case 924:
/* Line 664 of lalr1.cc  */
#line 5709 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("import"))); }
    break;

  case 925:
/* Line 664 of lalr1.cc  */
#line 5710 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema"))); }
    break;

  case 926:
/* Line 664 of lalr1.cc  */
#line 5711 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("module"))); }
    break;

  case 927:
/* Line 664 of lalr1.cc  */
#line 5712 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("function"))); }
    break;

  case 928:
/* Line 664 of lalr1.cc  */
#line 5713 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("score"))); }
    break;

  case 929:
/* Line 664 of lalr1.cc  */
#line 5714 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("contains"))); }
    break;

  case 930:
/* Line 664 of lalr1.cc  */
#line 5715 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("weight"))); }
    break;

  case 931:
/* Line 664 of lalr1.cc  */
#line 5716 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("window"))); }
    break;

  case 932:
/* Line 664 of lalr1.cc  */
#line 5717 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("distance"))); }
    break;

  case 933:
/* Line 664 of lalr1.cc  */
#line 5718 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("occurs"))); }
    break;

  case 934:
/* Line 664 of lalr1.cc  */
#line 5719 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("times"))); }
    break;

  case 935:
/* Line 664 of lalr1.cc  */
#line 5720 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("same"))); }
    break;

  case 936:
/* Line 664 of lalr1.cc  */
#line 5721 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("different"))); }
    break;

  case 937:
/* Line 664 of lalr1.cc  */
#line 5722 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lowercase"))); }
    break;

  case 938:
/* Line 664 of lalr1.cc  */
#line 5723 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("uppercase"))); }
    break;

  case 939:
/* Line 664 of lalr1.cc  */
#line 5724 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("relationship"))); }
    break;

  case 940:
/* Line 664 of lalr1.cc  */
#line 5725 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("levels"))); }
    break;

  case 941:
/* Line 664 of lalr1.cc  */
#line 5726 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("language"))); }
    break;

  case 942:
/* Line 664 of lalr1.cc  */
#line 5727 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("any"))); }
    break;

  case 943:
/* Line 664 of lalr1.cc  */
#line 5728 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("all"))); }
    break;

  case 944:
/* Line 664 of lalr1.cc  */
#line 5729 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("exactly"))); }
    break;

  case 945:
/* Line 664 of lalr1.cc  */
#line 5730 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("words"))); }
    break;

  case 946:
/* Line 664 of lalr1.cc  */
#line 5731 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sentences"))); }
    break;

  case 947:
/* Line 664 of lalr1.cc  */
#line 5732 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sentence"))); }
    break;

  case 948:
/* Line 664 of lalr1.cc  */
#line 5733 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("phrase"))); }
    break;

  case 949:
/* Line 664 of lalr1.cc  */
#line 5734 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("paragraph"))); }
    break;

  case 950:
/* Line 664 of lalr1.cc  */
#line 5735 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("paragraphs"))); }
    break;

  case 951:
/* Line 664 of lalr1.cc  */
#line 5736 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("modify"))); }
    break;

  case 952:
/* Line 664 of lalr1.cc  */
#line 5737 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("first"))); }
    break;

  case 953:
/* Line 664 of lalr1.cc  */
#line 5738 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("replace"))); }
    break;

  case 954:
/* Line 664 of lalr1.cc  */
#line 5739 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("insert"))); }
    break;

  case 955:
/* Line 664 of lalr1.cc  */
#line 5740 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("rename"))); }
    break;

  case 956:
/* Line 664 of lalr1.cc  */
#line 5741 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("delete"))); }
    break;

  case 957:
/* Line 664 of lalr1.cc  */
#line 5742 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("before"))); }
    break;

  case 958:
/* Line 664 of lalr1.cc  */
#line 5743 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("after"))); }
    break;

  case 959:
/* Line 664 of lalr1.cc  */
#line 5744 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("revalidation"))); }
    break;

  case 960:
/* Line 664 of lalr1.cc  */
#line 5745 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("with"))); }
    break;

  case 961:
/* Line 664 of lalr1.cc  */
#line 5746 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("nodes"))); }
    break;

  case 962:
/* Line 664 of lalr1.cc  */
#line 5747 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("last"))); }
    break;

  case 963:
/* Line 664 of lalr1.cc  */
#line 5748 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("into"))); }
    break;

  case 964:
/* Line 664 of lalr1.cc  */
#line 5749 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("simple"))); }
    break;

  case 965:
/* Line 664 of lalr1.cc  */
#line 5750 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sequential"))); }
    break;

  case 966:
/* Line 664 of lalr1.cc  */
#line 5751 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("updating"))); }
    break;

  case 967:
/* Line 664 of lalr1.cc  */
#line 5752 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ordered"))); }
    break;

  case 968:
/* Line 664 of lalr1.cc  */
#line 5753 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("unordered"))); }
    break;

  case 969:
/* Line 664 of lalr1.cc  */
#line 5754 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("returning"))); }
    break;

  case 970:
/* Line 664 of lalr1.cc  */
#line 5755 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("exit"))); }
    break;

  case 971:
/* Line 664 of lalr1.cc  */
#line 5756 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("loop"))); }
    break;

  case 972:
/* Line 664 of lalr1.cc  */
#line 5757 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("break"))); }
    break;

  case 973:
/* Line 664 of lalr1.cc  */
#line 5758 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("continue"))); }
    break;

  case 974:
/* Line 664 of lalr1.cc  */
#line 5759 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("try"))); }
    break;

  case 975:
/* Line 664 of lalr1.cc  */
#line 5760 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("catch"))); }
    break;

  case 976:
/* Line 664 of lalr1.cc  */
#line 5761 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("using"))); }
    break;

  case 977:
/* Line 664 of lalr1.cc  */
#line 5762 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("set"))); }
    break;

  case 978:
/* Line 664 of lalr1.cc  */
#line 5763 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("index"))); }
    break;

  case 979:
/* Line 664 of lalr1.cc  */
#line 5764 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("unique"))); }
    break;

  case 980:
/* Line 664 of lalr1.cc  */
#line 5765 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("non"))); }
    break;

  case 981:
/* Line 664 of lalr1.cc  */
#line 5766 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("on"))); }
    break;

  case 982:
/* Line 664 of lalr1.cc  */
#line 5767 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("range"))); }
    break;

  case 983:
/* Line 664 of lalr1.cc  */
#line 5768 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("equality"))); }
    break;

  case 984:
/* Line 664 of lalr1.cc  */
#line 5769 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("manually"))); }
    break;

  case 985:
/* Line 664 of lalr1.cc  */
#line 5770 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("automatically"))); }
    break;

  case 986:
/* Line 664 of lalr1.cc  */
#line 5771 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("maintained"))); }
    break;

  case 987:
/* Line 664 of lalr1.cc  */
#line 5772 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("decimal-format"))); }
    break;

  case 988:
/* Line 664 of lalr1.cc  */
#line 5773 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("decimal-separator"))); }
    break;

  case 989:
/* Line 664 of lalr1.cc  */
#line 5774 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("grouping-separator"))); }
    break;

  case 990:
/* Line 664 of lalr1.cc  */
#line 5775 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("infinity"))); }
    break;

  case 991:
/* Line 664 of lalr1.cc  */
#line 5776 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("minus-sign"))); }
    break;

  case 992:
/* Line 664 of lalr1.cc  */
#line 5777 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("NaN"))); }
    break;

  case 993:
/* Line 664 of lalr1.cc  */
#line 5778 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("percent"))); }
    break;

  case 994:
/* Line 664 of lalr1.cc  */
#line 5779 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("per-mille"))); }
    break;

  case 995:
/* Line 664 of lalr1.cc  */
#line 5780 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("zero-digit"))); }
    break;

  case 996:
/* Line 664 of lalr1.cc  */
#line 5781 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("digit"))); }
    break;

  case 997:
/* Line 664 of lalr1.cc  */
#line 5782 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("pattern-separator"))); }
    break;

  case 998:
/* Line 664 of lalr1.cc  */
#line 5783 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("collection"))); }
    break;

  case 999:
/* Line 664 of lalr1.cc  */
#line 5784 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("const"))); }
    break;

  case 1000:
/* Line 664 of lalr1.cc  */
#line 5785 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("append-only"))); }
    break;

  case 1001:
/* Line 664 of lalr1.cc  */
#line 5786 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("queue"))); }
    break;

  case 1002:
/* Line 664 of lalr1.cc  */
#line 5787 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("mutable"))); }
    break;

  case 1003:
/* Line 664 of lalr1.cc  */
#line 5788 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("read-only"))); }
    break;

  case 1004:
/* Line 664 of lalr1.cc  */
#line 5789 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("integrity"))); }
    break;

  case 1005:
/* Line 664 of lalr1.cc  */
#line 5790 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("constraint"))); }
    break;

  case 1006:
/* Line 664 of lalr1.cc  */
#line 5791 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("check"))); }
    break;

  case 1007:
/* Line 664 of lalr1.cc  */
#line 5792 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("key"))); }
    break;

  case 1008:
/* Line 664 of lalr1.cc  */
#line 5793 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("foreach"))); }
    break;

  case 1009:
/* Line 664 of lalr1.cc  */
#line 5794 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("foreign"))); }
    break;

  case 1010:
/* Line 664 of lalr1.cc  */
#line 5795 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("keys"))); }
    break;

  case 1011:
/* Line 664 of lalr1.cc  */
#line 5796 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ancestor"))); }
    break;

  case 1012:
/* Line 664 of lalr1.cc  */
#line 5797 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("child"))); }
    break;

  case 1013:
/* Line 664 of lalr1.cc  */
#line 5798 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descendant"))); }
    break;

  case 1014:
/* Line 664 of lalr1.cc  */
#line 5799 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("parent"))); }
    break;

  case 1015:
/* Line 664 of lalr1.cc  */
#line 5800 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preceding"))); }
    break;

  case 1016:
/* Line 664 of lalr1.cc  */
#line 5801 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("self"))); }
    break;

  case 1017:
/* Line 664 of lalr1.cc  */
#line 5802 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("following"))); }
    break;

  case 1018:
/* Line 664 of lalr1.cc  */
#line 5803 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ancestor-or-self"))); }
    break;

  case 1019:
/* Line 664 of lalr1.cc  */
#line 5804 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descendant-or-self"))); }
    break;

  case 1020:
/* Line 664 of lalr1.cc  */
#line 5805 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("following-sibling"))); }
    break;

  case 1021:
/* Line 664 of lalr1.cc  */
#line 5806 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preceding-sibling"))); }
    break;

  case 1022:
/* Line 664 of lalr1.cc  */
#line 5807 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("position"))); }
    break;

  case 1023:
/* Line 664 of lalr1.cc  */
#line 5808 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("json"))); }
    break;

  case 1024:
/* Line 664 of lalr1.cc  */
#line 5809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("append"))); }
    break;

  case 1025:
/* Line 664 of lalr1.cc  */
#line 5810 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("json-item"))); }
    break;

  case 1026:
/* Line 664 of lalr1.cc  */
#line 5811 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("array"))); }
    break;

  case 1027:
/* Line 664 of lalr1.cc  */
#line 5812 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("object"))); }
    break;

  case 1028:
/* Line 664 of lalr1.cc  */
#line 5813 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("structured-item"))); }
    break;

  case 1029:
/* Line 664 of lalr1.cc  */
#line 5816 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), true); }
    break;


/* Line 664 of lalr1.cc  */
#line 10606 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
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
  xquery_parser::yysyntax_error_ (int yystate, int yytoken)
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
  const short int xquery_parser::yypact_ninf_ = -1431;
  const short int
  xquery_parser::yypact_[] =
  {
      4924, -1431, -1431, -1431, -1431,  6478,  6478,  6478,  6478, -1431,
   -1431,   247,   268, -1431,   933,   448, -1431, -1431, -1431,    38,
   -1431, -1431, -1431,   341,   548,   799,  4642,   567,   592,   791,
   -1431,    -7, -1431,   693, -1431, -1431, -1431, -1431, -1431,   808,
   -1431,   729,   746, -1431, -1431, -1431, -1431,   702, -1431,   810,
   -1431,   753,   781, -1431,   398, -1431, -1431, -1431, -1431, -1431,
   -1431, -1431, -1431, -1431, -1431, -1431, -1431, -1431, -1431,   829,
     852, -1431, -1431, -1431, -1431,   647, 12988, -1431, -1431, -1431,
     855, -1431, -1431, -1431,   839, -1431,   865,   869, -1431, -1431,
   16859, -1431, -1431, -1431, -1431, -1431, -1431, -1431, -1431,   888,
   -1431, -1431,   895,   905, -1431, -1431, -1431, -1431, -1431, -1431,
   -1431,  5548,  8958,  9268, 16859, -1431, -1431,   856, -1431, -1431,
   -1431, -1431,   876, -1431, -1431,   918, 16859, -1431, 13899,   920,
     921, -1431, -1431, -1431,   925, -1431, 12368, -1431, -1431, -1431,
   -1431, -1431, -1431,   897, -1431, -1431, -1431, -1431, -1431, -1431,
   -1431, -1431,   133,   841, -1431, -1431, -1431, -1431, -1431, -1431,
   -1431, -1431,   309,   901,   349, -1431,   -52,   -80, -1431, -1431,
   -1431, -1431, -1431, -1431,   936, -1431,   818,   821,   823, -1431,
   -1431,   903,   912, -1431, -1431, -1431, -1431, -1431, -1431, -1431,
   -1431, -1431, -1431, -1431, -1431, -1431, -1431, -1431, -1431, -1431,
   -1431, -1431, -1431, -1431, -1431, -1431, -1431, -1431, -1431, -1431,
   -1431, -1431, -1431, -1431, -1431, -1431, -1431, -1431, -1431, -1431,
   -1431, -1431, -1431, -1431, -1431, -1431, -1431, -1431, -1431, -1431,
   -1431, -1431, -1431, -1431, -1431, -1431, -1431, -1431, -1431, -1431,
   -1431, -1431, -1431, -1431, -1431, -1431,  9578,  9888, -1431,   754,
   -1431, -1431, -1431, -1431, -1431,  5236,  6788,  1067, -1431,  7098,
   -1431, -1431,   155,    87, -1431, -1431, -1431, -1431, -1431, -1431,
   -1431, -1431, -1431, -1431, -1431, -1431, -1431, -1431,    90, -1431,
   -1431, -1431, -1431, -1431, -1431,   404, -1431, -1431, -1431, -1431,
   -1431, -1431, -1431, -1431,  6478, -1431, -1431, -1431, -1431,    25,
   -1431, -1431, -1431, -1431, -1431, -1431, -1431, -1431,   124, -1431,
     879, -1431, -1431, -1431,   626, -1431, -1431, -1431, -1431, -1431,
   -1431, -1431, -1431,   904,   977, -1431,   898,   824,   974,   663,
     625,   -11,   613, -1431,  1025,   882,   981,   973, 10818, -1431,
     886, -1431, -1431,   487, -1431, -1431, 12678, -1431,   820, -1431,
     929, 12988, -1431,   929, 12988, -1431, -1431, -1431,   844, -1431,
   -1431, -1431, -1431, -1431, -1431, -1431, -1431, -1431, -1431, -1431,
   -1431, -1431, -1431, -1431, -1431, -1431, -1431, -1431, -1431, -1431,
   -1431, -1431, -1431, -1431, -1431, -1431,   928, -1431, -1431, -1431,
   -1431, -1431, -1431, -1431, -1431, -1431, -1431, -1431, -1431, -1431,
   -1431, -1431, -1431, -1431, -1431, -1431, -1431, -1431, -1431, -1431,
   -1431, -1431, -1431, -1431,   611, -1431, -1431, -1431, -1431, -1431,
     906, -1431,  6478,   907,   908,   909,  6478,   591,   591,  1058,
     676,   727,   579, 17455, 16859,    10,  1048, 16859,   943,   970,
     685, 16859,   773,   851, 16859, 16859,   794,    53,    69, -1431,
   -1431, -1431, 16859,  6478,   913,  6478,    83, 11128, 14195, 16859,
   -1431,   815,   825, 16859,   988,   418,   954, 11128,  1110,   333,
     366, 16859,   993,   972,  1005, -1431,   932, 11128, 14491, 16859,
   16859, 16859,  6478,   947, 11128, 11128, 16859,  6478,   962,   982,
   -1431, -1431, -1431, 11128, 14787,   978, -1431,   980, -1431, -1431,
   -1431, -1431,   983, -1431,   984, -1431, -1431, -1431, -1431, -1431,
     985, -1431, -1431, -1431, -1431, -1431, -1431, -1431, -1431, -1431,
   -1431, -1431, -1431, -1431, -1431, -1431, -1431, -1431, -1431, -1431,
   -1431, -1431, -1431, -1431, -1431, -1431, -1431, -1431, -1431, 16859,
   -1431, -1431, -1431, -1431, -1431, -1431, -1431, -1431, -1431, -1431,
   -1431, -1431, -1431,   995, 16859, -1431, -1431, -1431,   955,  5858,
    1026,    79,   990,   992,   994, 16859,  6478, -1431,   996,    98,
   -1431,   709, -1431,   105,  1120, 11128, 11128, -1431,   145, -1431,
   -1431,  1139, -1431, -1431, -1431, -1431, 11128,   944, -1431,  1127,
   11128, 11128, 17159, 11128, 11128, 11128, 11128, 17159, 11128,   930,
     935, 16859,   969,   976, 11128, 11128,  5548,   915, -1431,    73,
   -1431,    35, 11128,  6788, -1431, -1431, -1431, -1431, -1431,   933,
     791,    94,   103,  1159,  7408,  3380,  7718,  3701,   839, -1431,
   -1431,   201,   839, -1431, 11128,  4321, -1431,  1044,   717,    -7,
     999,   998,  1000,  6478, 11128, -1431, -1431, -1431, -1431, -1431,
   -1431, -1431, -1431, 11438, 11438, 11438, -1431, 11438, 11438, -1431,
   11438, -1431, 11438, -1431, -1431, -1431, -1431, -1431, -1431, -1431,
   11438, 11438,  1098, 11438, 11438, 11438, 11438, 11438, 11438, 11438,
   11438, 11438, 11438, 11438, 11438,   940,  1077,  1078,  1079, -1431,
   -1431, -1431, 12058, 10198, -1431, -1431, 12368, 12368, 11128,   929,
   -1431, -1431,   929, -1431,  8028,   929,  1001,  1030,  8338, -1431,
   -1431, -1431, -1431,    40, -1431,   259, -1431, -1431, -1431, -1431,
   -1431, -1431,  1073,  1074,   567,  1145, -1431, -1431, 17455,  1042,
     653, 16859,  1022,  1024,  1042,  1058,  1062,  1053, -1431, -1431,
   -1431,   173,   945,  1100,   894, 16859,  1049, 11128,  1080, 16859,
   16859, -1431,  1063,  1013, -1431,  1014,   980,   746, -1431,  1015,
    1016,   106, -1431,   287,   301,  1092, -1431,    32, -1431, -1431,
    1092, 16859,    31, 16859,  1106,   312, -1431,  6478, -1431,   138,
   -1431, 16859,  1107,  1160, 16859,  1058,  1109,   535, 16859, 11128,
      -7, -1431,   250,  1020, -1431,  1021,  1027,  1028,    47, -1431,
     539,  1029, -1431,   156,   165,  1055, -1431,  1033,  6478,  6478,
     251, -1431,   427,   453,   672, 11128,   325, -1431, -1431, 11128,
   11128, -1431, 11128, 11128, 11128, -1431, 11128, -1431, 11128, -1431,
   16859,  1120, -1431,   326,   264,   328, -1431, -1431, -1431,   334,
   -1431,   490, -1431, -1431,  1064,  1065,  1068,  1070,  1072,   844,
     611,   368,   377,     8,   -16,  1117,   476,   997,  1002,  1006,
     224, -1431,  1086, -1431, -1431,  1031,   183,  5858,   376, 13298,
     915, -1431, -1431, -1431,  1007, -1431,   155,   822,  1198,   176,
   -1431, -1431,   107, -1431, -1431, -1431,   116, -1431,    62, -1431,
   -1431, -1431, -1431, -1431,  4011, -1431, -1431, -1431, 16859,  1071,
   11128, 11748, -1431, -1431, -1431,   977, -1431, -1431, -1431, -1431,
   -1431, 11438, -1431, -1431, -1431,    72, -1431,   625,   625,   725,
     -11,   -11,   -11,   -11,   613,   613, -1431, -1431, 15971, 15971,
   16859, 16859, -1431, -1431,   399, -1431, -1431,   130, -1431, -1431,
   -1431, -1431,   455, -1431, -1431, -1431,   480,   591, -1431, -1431,
     708,   714,   738, -1431,   567, -1431, -1431, -1431, -1431, -1431,
   -1431, -1431, -1431, -1431, -1431,  1042, -1431,  1099, 16267,  1090,
   11128, -1431, -1431, -1431,  1143,  1058,  1058,  1042, -1431,   887,
    1058,   704, 16859,   622,   681,  1212, -1431, -1431,   957,   538,
   -1431, -1431, -1431, -1431, -1431, -1431, -1431, -1431, -1431, -1431,
   -1431,   173,    96,  1017,   646, 11128, -1431, 16859,  1150,   948,
    1058, -1431, -1431, -1431, -1431,  1095, 16859, -1431, 16859, -1431,
   16563,  1118, 15971,  1131, 11128,   -26,  1103,    50,   543,  1003,
   -1431, -1431,   655,    31,  1143, 15971,  1133,  1161,  1075,  1056,
    1125,  1058,  1102,  1128,  1163,  1058, 11128,   -28, -1431, -1431,
   -1431,  1111, -1431, -1431, -1431, -1431,  1148, 11128, 11128,  1121,
   -1431,  1170,  1171,  6478, -1431,  1089,  1093,  1122, 16859, -1431,
   16859, -1431, 11128,  1135,  1084, 11128, -1431,  1157,   218,   219,
     242,  1245, -1431,   397, -1431,   215,  1130, -1431, -1431,  1251,
   -1431,   771, 11128, 11128, 11128,   772, 11128, 11128, 11128, 11128,
   11128, 11128, 11128, 11128, 11128, 17159,  1166, 11128, 11128, -1431,
    8648,   125,  1043, -1431,   491, -1431, 11128,   120,   199,    62,
    7718,  3701,  7718,  1207, -1431, -1431, 11128,   812,  1181, -1431,
   16859,  1184,  1185, -1431, -1431, 11128,    72,   540,   689, -1431,
    1009,   269,  1034,  1036, -1431, -1431,   851, -1431,  1032,   664,
    1140,  1146, 16267,  1147,  1149,  1151,  1153,  1154, -1431,   635,
   -1431, -1431, -1431, -1431, -1431, -1431, -1431, -1431, -1431, -1431,
   -1431, -1431, -1431,  1155, -1431, -1431, -1431, -1431, 10508, -1431,
   -1431, -1431, -1431, -1431, -1431, -1431, -1431, -1431,   743, -1431,
    1272,   494, -1431, -1431, -1431, -1431, -1431, -1431, -1431, -1431,
   -1431,  1035, -1431, -1431,  1277, -1431, -1431, -1431, -1431, -1431,
     556,  1282, -1431,   601, -1431, -1431, -1431,   978,   548,   693,
     983,   729,   984,   985, -1431,  1149,  1151,  1153, -1431,   635,
     635, 12058,  1037,  1011, -1431,  1143,    96,  1088,  1123,  6478,
    1132,  1136,  1175,  1142,  1144, 16859, -1431,   419, -1431, 16859,
   -1431, 11128,  1174, 11128,  1199, 11128,   220,  1178, 11128,  1182,
   -1431,  1214,  1216, 11128, 16859,   892,  1258, -1431, -1431, -1431,
   -1431, -1431, -1431, 15971, -1431,  6478,  1058,  1230, -1431, -1431,
   -1431,  1058,  1230, -1431, 11128,  1196,  6478, 16859, -1431, -1431,
   11128, 11128,   570, -1431,   279,   813, -1431, 15083,   819, -1431,
     834, -1431,  1158, -1431, -1431,  6478,  1156,  1162, -1431, 11128,
   -1431, -1431, 11128,  1152,  1170,  1243, -1431,  1213, -1431,   652,
   -1431, -1431,  1338, -1431, -1431,  6478, 16859, -1431,   744, -1431,
   -1431, -1431,  6478,  1167,  1114,  1126, -1431, -1431, -1431,  1134,
    1137, -1431, -1431, -1431,  1261, -1431, -1431, -1431, -1431,  1124,
      13, 16859,  1177, -1431,  1203,  1208,  1209,  1215, -1431,   879,
     720, 13298,  1043, -1431,  6168, 13298, -1431, -1431,  1198,   396,
   -1431, -1431, -1431,  1181, -1431,  1058, -1431,   893, -1431,    82,
    1264, -1431, 11128,   739,  1058, -1431, 11748,   400,  1187, -1431,
      72,  1129, -1431, -1431,   -54, -1431,   411,   161,  1138,    72,
     411, 11438, -1431,   214, -1431, -1431, -1431, -1431, -1431, -1431,
      72,  1220,  1104,   945,   161, -1431, -1431,  1091,  1293, -1431,
   -1431, -1431, 13594,  1188,  1193,  1194,  1195,  1197,  1202,  1204,
   -1431, -1431, -1431, -1431, -1431, -1431, -1431, -1431, -1431, -1431,
   -1431, -1431, -1431,  1355,    17,  1360,    17,  1141,  1284, -1431,
   -1431,  1223, 16859,  1164, -1431, -1431, 12058, -1431,  1210, -1431,
   -1431, -1431, -1431, -1431, -1431, 11128,  1247, -1431, -1431, 11128,
   -1431,   562, -1431, 11128,  1248, 11128, -1431, 11128, 16859, 16859,
   -1431,   802, -1431, 11128, -1431,  1270,  1271,  1302,  1058,  1230,
   -1431, 11128,  1217, -1431, -1431, -1431,  1218, -1431,   311, 11128,
    6478,  1219,   369, -1431, 16859,   211, -1431, 15379,   362, -1431,
   15675,  1221, -1431, -1431,  1222, -1431, -1431, -1431, -1431, 11128,
     835,  1245, 16859,   789, -1431,  1224,  1245, 16859, -1431,  1225,
   -1431, 11128, 11128, 11128, 11128,  1087, 11128, 11128, -1431, 11128,
   11128, 11128, 11128,  8648,   502, -1431, -1431, -1431, -1431, -1431,
    1264, -1431, -1431, -1431, 11128, -1431,  1259, -1431, -1431, -1431,
   -1431, -1431,  1226, 11438, -1431, -1431, -1431, -1431, -1431,   409,
   11438, 11438,   -83, -1431,  1034, -1431,   216, -1431,  1036,    72,
    1257, -1431, -1431,  1165, -1431, -1431, -1431, -1431,  1318,  1227,
   -1431,   482, -1431, -1431, -1431, -1431, -1431, -1431, -1431, -1431,
      54,    54, -1431,    17, -1431, -1431,   489, -1431,  1385,   161,
    1319,  1231, 12058,    -9,  1172,  1249, -1431, -1431, 11128, -1431,
   11128,  1269, -1431, 11128, -1431, -1431, -1431,  1366, -1431, -1431,
    8648, 11128,  1058, -1431, -1431, -1431, 11128, 11128, -1431, -1431,
   -1431,  8648,  8648,  1327,  6478, 15971, 16859,   513, 16859, 11128,
   16859,   572,  8648, -1431,   395,   288,  1245, 16859, -1431,  1228,
    1245, -1431, -1431, -1431, -1431, -1431, 11128, -1431, -1431, -1431,
     243,   253,   271, 11128, -1431, -1431,  1184, 11128, -1431,   -11,
   11438, 11438,   725,   665, -1431, -1431, -1431, -1431, -1431, -1431,
   11128, -1431, 15971, -1431, 15971,  1328, -1431, -1431, -1431,  1394,
   -1431, -1431, -1431,  1168,  1320, -1431, -1431,  1321, -1431,   437,
   16859,  1307,  1205, 16859, 12058, -1431, -1431, 11128, -1431,  1308,
   -1431, -1431,  1230, -1431, -1431, 15971, -1431, -1431, -1431,  1336,
   11128,  1246, -1431,  1339,  8648, -1431, 16859,   474,   520, -1431,
    1238,  1245, -1431,  1239, -1431,  1240,  1170,  1171,   401, -1431,
    1184,   725,   725, 11438,   407, -1431, -1431, 15971, -1431, -1431,
    1319, 12058, -1431,  1264,  1169, 16859,  1322,  1232,  1321, -1431,
   16859,   573, 15971,  6478, 15971,  1253, -1431, -1431,  1343,   549,
   -1431, -1431, -1431, -1431,  1260,   679, -1431, -1431, -1431,  1250,
   -1431,  8648,   836, -1431, -1431,   725, -1431, -1431, -1431, -1431,
   -1431, 11128,  1173, 16859,  1323, -1431,  6478,   641, -1431, -1431,
     644, 11128, -1431, -1431, -1431, -1431, -1431, -1431, -1431,  1329,
   -1431,  1176,  1179, 16859, -1431, -1431, 11128,  8648, 16859,  1180,
   11128,  1183,  1254, 12058, -1431, 12058,  8648, -1431,  1252,  1186,
   16859,  1233,  1330, 16859,  1189, 12058, -1431
  };

  /* YYDEFACT[S] -- default reduction number in state S.  Performed when
     YYTABLE doesn't specify something else to do.  Zero means the
     default is an error.  */
  const unsigned short int
  xquery_parser::yydefact_[] =
  {
       165,   467,   468,   806,   469,   168,   168,   168,     0,   824,
    1029,   120,   122,   634,   917,   926,   866,   829,   827,   808,
     918,   921,   873,   833,   809,   811,     0,   927,   813,   924,
     895,   875,   849,   810,   870,   871,   922,   919,   869,   815,
     925,   816,   817,   965,   977,   964,   867,   886,   880,   818,
     868,   820,   819,   966,   904,   905,   872,   846,   987,   988,
     989,   990,   991,   992,   993,   994,   995,   996,   997,  1011,
    1018,   894,   890,   881,   860,   807,     0,   889,   897,   906,
    1012,   885,   493,   861,   862,   920,  1013,  1019,   882,   899,
       0,   499,   456,   495,   892,   826,   883,   884,   913,   887,
     903,   912,  1017,  1020,   832,   874,   915,   494,   902,   908,
     812,     0,     0,     0,     0,   402,   900,   911,   916,   914,
     893,   879,   967,   877,   878,  1014,     0,   401,     0,  1015,
    1021,   909,   863,   888,  1016,   434,     0,   466,   910,   891,
     898,   907,   901,   968,   854,   859,   858,   857,   856,   855,
     821,   876,     0,   825,   923,   847,   958,   957,   959,   831,
     830,   850,   956,   814,   954,   961,   955,   953,   853,   896,
     952,   963,   962,   951,   851,   960,   972,   973,   970,   971,
     969,   822,   974,   975,   976,   943,   942,   929,   845,   838,
     936,   932,   848,   844,   944,   865,   834,   835,   828,   837,
     941,   940,   937,   933,   949,   950,   948,   939,   935,   928,
     836,   947,   946,   840,   842,   841,   934,   938,   930,   843,
     931,   839,   945,   998,   999,  1000,  1001,  1002,  1003,   979,
     980,   978,   984,   985,   986,   981,   982,   983,   852,  1004,
    1005,  1006,  1007,  1008,  1009,  1010,     0,     0,  1023,  1024,
    1022,  1027,  1026,  1025,  1028,   165,   165,     0,     2,   165,
       9,    11,    23,     0,    28,    31,    36,    37,    38,    39,
      40,    41,    42,    32,    58,    59,    33,    34,     0,    76,
      79,    80,    35,    81,    82,     0,   118,    83,    84,    85,
      86,    18,   162,   163,   164,   171,   174,   486,   175,     0,
     176,   177,   178,   179,   180,   181,   182,   185,     0,   211,
     219,   214,   246,   252,     0,   244,   245,   221,   215,   184,
     216,   183,   217,   220,   353,   355,   357,   367,   369,   373,
     375,   378,   383,   386,   389,   391,   393,   395,     0,   399,
     406,   405,   407,     0,   425,   408,   430,   433,   435,   438,
     440,     0,   445,   442,     0,   453,   463,   465,   439,   470,
     477,   491,   478,   479,   480,   483,   484,   481,   485,   508,
     509,   482,   512,   514,   515,   516,   513,   561,   562,   563,
     564,   565,   566,   567,   462,   606,     0,   597,   605,   604,
     603,   602,   599,   601,   598,   600,   492,    43,   222,   223,
     225,   224,   226,   218,   488,   489,   490,   487,   228,   231,
     227,   229,   230,   464,   805,   823,   917,   926,   924,   825,
       0,   166,   167,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   126,
     128,   129,     0,     0,     0,     0,     0,     0,     0,     0,
     256,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   274,   275,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     458,   461,   448,     0,     0,   808,   833,   811,   864,   927,
     813,   875,   815,   886,   818,   820,   819,   904,  1011,  1018,
     807,  1012,   862,  1013,  1019,   887,  1017,  1020,   911,   967,
    1014,  1015,  1021,  1016,   968,   956,   954,   955,   953,   851,
     972,   973,   970,   822,   974,  1024,   454,   805,   446,     0,
     192,   447,   450,   808,   809,   811,   810,   815,   816,   817,
     818,   807,   814,   496,     0,   452,   451,   187,     0,     0,
     211,     0,   813,   820,   819,     0,   168,   782,   974,     0,
     219,     0,   497,     0,   528,     0,     0,   457,     0,   428,
     429,     0,   460,   459,   449,   432,     0,     0,   557,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   784,     0,
     786,     0,     0,   165,     3,     4,     1,    10,    12,     0,
       0,     0,     0,     6,   165,     0,   165,     0,     0,   119,
     172,     0,     0,   190,     0,     0,   199,     0,     0,     0,
       0,     0,     0,     0,     0,   204,   232,   251,   247,   253,
     248,   250,   249,     0,     0,     0,   418,     0,     0,   416,
       0,   362,     0,   417,   410,   415,   414,   413,   412,   411,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   404,
     403,   400,     0,     0,   426,   431,     0,     0,     0,   441,
     474,   444,   443,   455,     0,   471,     0,     0,     0,   569,
     571,   575,   577,     0,   124,     0,   804,    47,    44,    45,
      48,    49,     0,     0,     0,     0,    50,    51,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   641,   642,
     643,     0,   103,   142,     0,     0,   112,     0,     0,     0,
       0,   127,     0,     0,   614,     0,     0,     0,   609,     0,
       0,     0,   624,     0,     0,   255,   257,     0,   234,   235,
     254,     0,     0,     0,   134,     0,   138,   168,   511,     0,
      60,     0,    69,     0,     0,     0,    61,     0,     0,     0,
       0,   612,     0,     0,   615,     0,     0,     0,     0,   324,
       0,     0,   613,     0,     0,     0,   632,     0,     0,     0,
       0,   618,     0,     0,   194,     0,     0,   188,   186,     0,
       0,   788,     0,     0,     0,   496,     0,   783,     0,   498,
     529,   528,   525,     0,     0,     0,   559,   558,   427,     0,
     556,     0,   654,   655,     0,     0,     0,     0,     0,   795,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   660,     0,   202,   203,     0,     0,     0,     0,     0,
     207,   208,   785,   787,     0,     5,    24,     0,    25,     0,
       7,    29,     0,    15,     8,    30,     0,    19,   917,    77,
      16,    78,    20,   193,     0,   191,   212,   213,     0,     0,
       0,     0,   205,   233,   292,   354,   356,   360,   366,   365,
     364,     0,   361,   358,   359,     0,   370,   377,   376,   374,
     380,   381,   382,   379,   384,   385,   388,   387,     0,     0,
       0,     0,   409,   423,     0,   436,   437,     0,   475,   504,
     472,   506,     0,   607,   510,   502,     0,     0,   121,   123,
       0,     0,     0,   102,     0,    92,    94,    95,    96,    97,
      99,   100,   101,    93,    98,    88,    89,     0,     0,   108,
       0,   104,   106,   107,   114,     0,     0,    87,    46,     0,
       0,     0,     0,     0,     0,     0,   732,   737,     0,     0,
     733,   767,   720,   722,   723,   724,   726,   728,   727,   725,
     729,     0,     0,     0,     0,     0,   111,     0,   144,     0,
       0,   574,   568,   610,   611,     0,     0,   628,     0,   625,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     236,   237,     0,   242,   140,     0,     0,   135,     0,     0,
       0,     0,     0,     0,    62,     0,     0,     0,   273,   279,
     276,     0,   617,   616,   623,   631,     0,     0,     0,     0,
     573,     0,     0,     0,   419,     0,     0,     0,     0,   621,
       0,   619,     0,   195,     0,     0,   789,     0,     0,     0,
       0,   528,   526,     0,   517,     0,     0,   500,   501,     0,
      13,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   200,
       0,     0,     0,   668,     0,   209,     0,     0,     0,     0,
     165,     0,   165,     0,   173,   243,     0,   308,   304,   306,
       0,   301,   293,   294,   363,     0,     0,     0,     0,   698,
     371,   671,   675,   677,   679,   681,   684,   691,   692,   700,
     927,   812,     0,   821,  1027,  1026,  1025,  1028,   390,   580,
     586,   587,   590,   635,   636,   591,   592,   798,   799,   800,
     595,   392,   394,   397,   596,   396,   424,   476,     0,   473,
     503,   125,    56,    57,    54,    55,   131,   130,     0,    90,
       0,     0,   109,   110,   115,    74,    75,    52,    53,    73,
     738,     0,   741,   768,     0,   731,   730,   735,   734,   766,
       0,     0,   743,     0,   739,   742,   721,     0,     0,     0,
       0,     0,     0,     0,   608,     0,     0,     0,   143,   146,
     148,     0,     0,     0,   113,   116,     0,     0,     0,   168,
       0,     0,   632,     0,     0,     0,   259,     0,   579,     0,
     260,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     238,     0,     0,     0,     0,   286,     0,   283,   288,   241,
     141,   136,   139,     0,   189,     0,     0,    71,    65,    68,
      67,     0,    63,   277,     0,     0,   168,     0,   322,   326,
       0,     0,     0,   329,     0,     0,   335,     0,     0,   342,
       0,   346,     0,   421,   420,   168,     0,     0,   196,     0,
     198,   323,     0,     0,     0,     0,   529,     0,   519,     0,
     552,   549,     0,   553,   554,     0,     0,   548,     0,   523,
     551,   550,     0,     0,     0,     0,   647,   648,   644,     0,
       0,   652,   653,   649,   791,   792,   658,   796,   656,     0,
       0,     0,     0,   662,   813,   820,   819,   974,   201,     0,
       0,     0,   663,   664,     0,     0,   210,   794,    26,     0,
      17,    21,    22,   305,   317,     0,   318,     0,   309,   310,
     311,   312,     0,   496,     0,   302,     0,     0,     0,   682,
     695,     0,   368,   372,     0,   714,     0,     0,     0,     0,
       0,     0,   670,   672,   673,   709,   710,   711,   713,   712,
       0,     0,   686,   685,     0,   689,   693,   707,   705,   704,
     697,   701,     0,     0,     0,     0,     0,     0,     0,     0,
     583,   585,   584,   581,   398,   505,   507,   133,   132,    91,
     105,   755,   736,     0,   760,     0,   760,   749,   744,   147,
     149,     0,     0,     0,   117,   145,     0,    27,     0,   629,
     630,   633,   626,   627,   258,     0,     0,   272,   264,     0,
     268,     0,   262,     0,     0,     0,   281,     0,     0,     0,
     240,   284,   287,     0,   137,     0,     0,    70,     0,    64,
     278,     0,     0,   325,   327,   332,     0,   330,     0,     0,
       0,     0,     0,   336,     0,     0,   350,     0,     0,   343,
       0,     0,   347,   422,     0,   622,   620,   197,   790,     0,
       0,   528,     0,     0,   560,     0,   528,     0,   524,     0,
      14,     0,     0,     0,     0,     0,     0,     0,   661,     0,
       0,     0,     0,     0,     0,   665,   669,   321,   319,   320,
     313,   314,   315,   307,     0,   300,     0,   303,   295,   699,
     690,   696,     0,     0,   769,   770,   780,   779,   778,     0,
       0,     0,     0,   771,   676,   777,     0,   674,   678,     0,
       0,   683,   687,     0,   708,   703,   706,   702,     0,     0,
     593,     0,   588,   640,   582,   802,   803,   801,   589,   756,
       0,     0,   754,   761,   762,   758,     0,   753,     0,   751,
       0,     0,     0,     0,     0,     0,   570,   261,     0,   270,
       0,     0,   266,     0,   269,   282,   290,   291,   285,   239,
       0,     0,     0,    66,   280,   576,     0,     0,   333,   337,
     331,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   572,     0,     0,   528,     0,   555,     0,
     528,   578,   645,   646,   650,   651,     0,   657,   797,   659,
       0,     0,     0,     0,   666,   316,   296,     0,   694,   781,
       0,     0,   773,     0,   719,   718,   717,   716,   715,   680,
       0,   772,     0,   637,     0,     0,   765,   764,   763,     0,
     757,   750,   748,     0,   745,   746,   740,   150,   152,   154,
       0,     0,     0,     0,     0,   265,   263,     0,   271,     0,
     206,   352,    72,   328,   334,     0,   348,   344,   351,     0,
       0,     0,   338,     0,     0,   340,     0,   538,   532,   527,
       0,   528,   518,     0,   793,     0,     0,     0,     0,   299,
     297,   775,   774,     0,     0,   638,   594,     0,   759,   752,
       0,     0,   156,   155,     0,     0,     0,     0,   151,   267,
       0,     0,     0,     0,     0,     0,   546,   540,     0,   539,
     541,   547,   544,   534,     0,   533,   535,   545,   520,     0,
     521,     0,     0,   667,   298,   776,   688,   639,   747,   153,
     157,     0,     0,     0,     0,   289,     0,     0,   341,   339,
       0,     0,   531,   542,   543,   530,   536,   537,   522,     0,
     158,     0,     0,     0,   349,   345,     0,     0,     0,     0,
       0,     0,     0,     0,   160,     0,     0,   159,     0,     0,
       0,     0,     0,     0,     0,     0,   161
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yypgoto_[] =
  {
     -1431, -1431,  -228,  -186, -1431,  1191,  1201, -1431,  1190,  -531,
   -1431, -1431, -1431, -1431, -1431, -1431, -1431, -1431, -1431, -1431,
   -1021, -1431, -1431, -1431, -1431,  -237,  -575, -1431,   712,   -49,
   -1431, -1431, -1431, -1431, -1431,   262,   492, -1431, -1431,    -1,
    -162,  1038, -1431,  1019, -1431, -1431,  -658, -1431,   426, -1431,
     227, -1431,  -250,  -293, -1431,  -542, -1431,    -4,    51,     9,
    -290,  -173, -1431,  -887, -1431, -1431,   298, -1431, -1431, -1431,
   -1431, -1431, -1431, -1431, -1431, -1431, -1431,   595,   -86,  1568,
       0, -1431, -1431, -1431, -1431,   438, -1431, -1431,  -296, -1431,
      23, -1431,  1012,  -945,  -746,  -713, -1431, -1431,   680, -1431,
   -1431,    -5,   207, -1431, -1431, -1431,    91, -1339, -1431,   353,
      99, -1431, -1431,   101, -1319, -1431,   931,   195, -1431, -1431,
     196, -1042, -1431, -1431,   192, -1431, -1431, -1270, -1252, -1431,
     190, -1430, -1431, -1431,   838,   840, -1431,  -557,   826, -1431,
   -1431,  -666,   350,  -638,   345,   351, -1431, -1431, -1431,   561,
   -1431, -1431,  1192, -1431, -1431, -1431, -1431, -1431,  -848,  -331,
    -681, -1431,  -104, -1431, -1431, -1431, -1431, -1431, -1431, -1431,
     -21,  -835, -1431,  -549,   636,   267, -1431,  -390, -1431, -1431,
   -1431, -1431, -1431, -1431, -1431,   788, -1431, -1431, -1431, -1431,
   -1012, -1431,   179, -1431,   671,  -782, -1431, -1431, -1431, -1431,
   -1431,  -282,  -275, -1247, -1016, -1431, -1431, -1431, -1431, -1431,
   -1431, -1431, -1431, -1431, -1431, -1431,  -767,  -857,  -192,  -830,
   -1431, -1431, -1431,  -850, -1431, -1431, -1431, -1431, -1431, -1431,
   -1431, -1431, -1431,  1050,  1051,  -847,   493,   315, -1431, -1431,
   -1431, -1431, -1431, -1431, -1431, -1431, -1431, -1431, -1431,   157,
   -1431, -1431,   147, -1431,   149, -1072, -1431, -1431, -1431,   114,
     104,   -64,   380, -1431, -1431, -1431, -1431, -1431, -1431, -1431,
   -1431, -1431, -1431, -1431, -1431, -1431,   115, -1431, -1431, -1431,
     -57,   374,   521, -1431, -1431, -1431, -1431, -1431,   313, -1431,
   -1431, -1405, -1431, -1431, -1431,  -548, -1431,    78, -1431,   -78,
   -1431, -1431, -1431, -1431, -1338, -1431,   127, -1431, -1431, -1431,
   -1431, -1431,   934, -1431, -1431, -1431, -1431, -1431,  -949, -1431,
   -1431, -1431,  -407,  1097,   248, -1431
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yydefgoto_[] =
  {
        -1,   257,   635,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
    1277,   785,   275,   276,   277,   278,   279,   280,   965,   966,
     967,   281,   282,   283,   971,   972,   973,   284,   447,   285,
     286,   713,   287,   449,   450,   451,   466,   775,   776,   288,
    1228,   289,  1707,  1708,   290,   291,   292,   558,   293,   294,
     295,   296,   297,   778,   298,   299,   540,   300,   301,   302,
     303,   304,   305,   645,   306,   307,   870,   871,   308,   309,
     570,   311,   646,   464,  1032,  1033,   312,   647,   313,   649,
     571,   315,   765,   766,  1265,   473,   316,   474,   475,   772,
    1266,  1267,  1268,   650,   651,  1132,  1133,  1385,   652,  1128,
    1129,  1378,  1379,  1380,  1381,   317,   798,   799,   318,  1292,
    1293,  1498,   319,  1295,  1296,   320,   321,  1298,  1299,  1300,
    1301,  1505,   322,   323,   324,   325,   911,   326,   327,  1392,
     328,   329,   330,   331,   332,   333,   334,   335,   336,  1172,
     337,   338,   339,   340,   670,   671,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   705,   700,   359,   360,   361,   362,
     363,   364,   365,   366,   367,   942,   368,   369,   370,   371,
     372,   373,  1328,   831,   832,   833,  1739,  1784,  1785,  1778,
    1779,  1786,  1780,  1329,  1330,   374,   375,  1331,   376,   377,
     378,   379,   380,   381,   382,   383,  1027,  1506,  1433,  1159,
    1591,  1160,  1173,   384,   385,   386,   387,   388,   389,   390,
     391,   392,   393,   394,   395,   805,  1241,   396,  1162,  1163,
    1164,  1165,   397,   398,   399,   400,   401,   402,   860,   861,
     403,  1362,  1363,  1674,  1114,  1140,  1402,  1403,  1141,  1142,
    1143,  1144,  1145,  1412,  1581,  1582,  1146,  1415,  1147,  1562,
    1148,  1149,  1420,  1421,  1587,  1585,  1404,  1405,  1406,  1407,
    1687,   742,   992,   993,   994,   995,   996,   997,  1214,  1611,
    1704,  1215,  1609,  1702,   998,  1446,  1606,  1602,  1603,  1604,
     999,  1000,  1408,  1416,  1572,  1409,  1568,  1393,   404,   405,
     406,   407,   561,   408,   409,   410,   411,   412,  1166,  1167,
    1168,  1169,  1278,   413,   414,   415
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const short int xquery_parser::yytable_ninf_ = -865;
  const short int
  xquery_parser::yytable_[] =
  {
       310,   420,   423,   424,   630,   310,   310,   310,   310,   607,
     919,   932,   694,   448,   422,   422,   422,   426,   648,  1294,
    1047,  1025,   717,   314,  1282,   622,   569,   573,   314,   314,
     314,   314,   585,  1059,  1113,   625,   623,   714,   714,   920,
     921,   922,   923,   849,  1555,  1520,  1509,  1073,   856,  1083,
     627,   889,   891,  1230,  1026,   536,   421,   421,   421,   425,
    1551,  1552,   782,   786,  1388,  1187,   952,  1138,  1021,   614,
     615,  1158,  1171,  1327,   623,  1246,  1583,  1647,  1161,  1161,
    1651,  1528,   883,   887,   890,   892,  1254,  1029,   623,    11,
      12,   623,   820,   881,   885,   623,    11,    12,   907,   623,
     908,   909,    13,   910,   623,   912,   623,   623,   623,   433,
    1710,   310,   471,   913,   914,  1284,   433,   623,  1161,   434,
     559,   623,  1251,   629,  -169,   623,   623,  1022,   756,  1023,
     819,   623,   630,   632,   314,  1217,   630,   436,  1191,   623,
    1218,   756,   437,   634,   436,   598,   757,  1023,   947,  1219,
     599,  1443,  1229,   836,  1600,  1056,  1220,   623,  1221,   757,
     609,   611,   421,  1564,   587,  1248,   623,  1222,   698,  1240,
     704,  1243,  1161,   596,   438,   439,  1123,   884,  1271,   726,
    1024,   634,   748,    82,   623,  1161,  1684,   820,   619,  1375,
     681,   746,   453,  1685,  1223,   454,   747,    93,  1255,   682,
    1565,  -170,   623,  1686,   620,  1705,   634,  1194,   631,  1119,
    1377,  1445,   727,   634,   634,   633,  1711,  1100,  1601,   623,
     623,  1306,   107,  1307,  1320,  1321,  1135,   948,   981,  1136,
     982,  1675,   634,   634,   600,  1057,   429,   430,   634,   431,
     432,  1099,   695,   623,   623,   472,   634,   472,  1030,   128,
    1537,   623,   623,  1502,   623,   310,   310,   435,  1569,   310,
    1489,  1259,   597,   821,   634,   623,   472,  1270,  1509,   630,
     758,  1703,   623,   634,   983,   648,  1528,   624,   314,   314,
     626,  1256,   314,   827,   876,  1031,   629,  1230,  1138,  1138,
    1015,   634,   829,   878,   310,  1771,  1188,  1120,  1712,  1317,
    1464,  1438,  1161,   889,   891,   472,  1122,  1327,  -169,   634,
    1368,  1394,  1252,  1369,  1257,  1177,  1327,   314,  1561,  1322,
     837,  1224,  1424,   472,   537,  1039,   634,   634,   978,   623,
     701,  1137,  1106,   703,  1285,   623,   631,  1749,   537,  1323,
     631,  1324,  1807,  1061,  1810,   881,   885,   588,   873,   444,
     634,   634,  1062,   902,  1134,  1798,   749,   445,   634,   634,
     441,   634,   537,   716,   750,   446,  1394,   947,  1473,  1325,
    1110,   761,   634,   114,   537,   674,   537,   623,  1044,   634,
    1499,   779,  1737,  1395,   872,  -170,  1229,   882,   886,   126,
    1762,   792,   675,   877,   879,  1016,   716,  1644,   803,   804,
     623,   623,   623,   894,   427,  1313,  1314,   810,   623,  1018,
    1326,  1794,  1499,  1225,  1226,  1227,  1484,  1570,  1571,   442,
    1036,  1645,   310,  1161,   984,   428,   310,   875,   152,  1315,
    1745,    11,    12,  1056,  1051,  1067,   634,   985,  1395,   986,
    1746,   732,   634,   733,  1800,   314,   949,  1161,  1086,   314,
     987,   988,   989,   310,   990,   310,   991,  1084,  1747,  1107,
     443,  1680,   426,  1091,   426,  1500,  1396,  1397,  1454,  1398,
    1499,  1738,  1095,   631,  1017,   486,   314,  1792,   314,  1776,
     783,  1648,   310,  1320,   634,  1684,  1400,   310,  1019,   834,
     835,   426,  1685,   472,   781,   455,   426,  1637,  1401,  1037,
     839,  1466,  1686,   735,   753,   314,   755,   634,   634,   634,
     314,  1327,  1087,  1075,  1736,   634,  1023,   628,  1088,   866,
     868,  1396,  1397,  1085,  1398,  1139,  1113,   784,  1318,  1320,
    1546,  1399,  1022,   801,   590,  1068,   591,   773,   807,  1681,
    1509,  1400,  1138,  1474,  1375,   889,   891,   889,  1649,  1782,
    1451,  1138,   487,  1401,  1776,  1642,  1350,  1181,  1320,   310,
    1112,  1070,  1138,  1178,   736,  1590,   310,  1465,  1195,  1196,
      13,  1102,  1161,  1199,   593,   422,   594,   630,  1370,  1371,
    1372,  1649,   314,  1176,  1559,  1793,  1092,  1093,  1178,   314,
    1694,  1796,   935,   936,  1319,  1096,  1097,  1699,  1323,   537,
    1324,  1094,   537,  1238,  1124,   774,   310,   934,  1777,   452,
    1098,  1722,   937,   310,  1069,   867,  1556,   421,   448,   488,
     489,    13,  1089,   592,   310,   310,   310,   310,  1325,   314,
    1022,   698,   969,   704,  1022,  1211,   314,   970,  1022,  1117,
    1071,   693,  1179,   310,  1323,  1364,  1324,   314,   314,   314,
     314,    82,  1212,  1443,  1121,  1783,  1673,  1161,   879,  1023,
    1161,  1320,  1321,   595,   128,    93,   314,  1180,   637,  1695,
    1444,  1291,   638,  1323,  1325,  1324,  1700,   639,  1046,  1566,
    1090,   724,   537,  1813,  1496,   537,  1567,  1058,  1320,   537,
     107,  1258,   537,   537,  1135,  1213,   640,  1136,  1211,  1730,
     537,  1365,    82,  1325,  1502,   456,   537,   537,  1782,  1261,
    1620,   537,  1365,  1445,  1262,  1212,    93,   128,   459,   537,
     460,  1781,  1787,  1645,   465,  1621,   537,   537,   537,   537,
     732,  1138,   733,  1263,   537,  1576,  1078,  1079,  1080,  1655,
     868,   107,   537,   677,  1659,   722,  1139,  1139,   968,   467,
     683,   637,  1023,  1320,  1321,   638,  1322,   707,  1734,  1806,
     639,   723,   637,  1781,   684,   734,   638,  1022,   708,  1787,
     492,   639,   678,  1038,  1264,  1615,  1323,   310,  1324,   640,
    1430,  1111,  1645,  1645,   461,   679,   422,   537,  1728,   462,
     640,   969,   735,   889,   641,  1161,   970,   642,  1320,  1321,
     314,   493,   537,  1323,   494,  1324,  1325,   694,   310,   310,
     114,  1431,   643,   537,  1816,  1072,   468,   426,   426,   680,
    1358,   481,   674,   884,   674,   469,   126,  1826,   421,  1432,
    1827,   314,   314,  1325,  1022,  1755,   463,  1756,   644,   675,
     850,   675,  1161,  1390,  1161,   850,  1384,  1522,  1322,   537,
     476,  1645,   470,   736,  1645,  1118,  1261,  1182,   718,  1065,
    1066,  1262,   676,  1184,  1753,   152,   128,   310,  1323,  1487,
    1324,   620,   719,  1183,  1740,  1161,  1186,   641,  1743,  1185,
     642,  1437,  1554,   894,   674,  1205,   479,   448,   641,   879,
     314,   642,   777,  1322,   310,   828,  1206,   777,  1325,  1023,
    1797,   675,   114,   480,  1682,  1683,  1543,  1161,  1374,   720,
     484,  1417,  1418,  1323,  1291,  1324,  1189,   314,   126,  1375,
    1507,   644,  1161,   721,  1161,  1679,   893,  1501,  1189,  1376,
     895,  1709,   644,  1508,  1419,  1510,  1507,  1507,   485,  1527,
    1377,  1366,  1763,  1325,  1207,  1232,  1261,   114,  1511,  1654,
    1819,  1262,   490,   457,  1233,  1208,   458,   152,   539,  1789,
      11,    12,   477,   126,   482,   478,   938,   483,  1547,   938,
     429,   430,   938,   431,   432,   491,   954,  1557,   538,   537,
     433,  1200,  1201,  1202,  1657,  1485,   699,  1203,   541,   702,
     434,   435,   542,   537,   738,   739,   740,   537,   537,   698,
    1139,   704,   152,  1334,  1339,  1335,  1340,   554,   436,  1139,
     575,   696,   697,   437,  1751,  1752,  1197,  1198,   555,   537,
    1139,   537,  1548,  1549,   917,   918,   924,   925,   556,   537,
     576,   655,   537,  1709,   926,   927,   537,  1449,  1450,   656,
     657,   577,   658,   582,   583,   438,   439,   440,   584,  1387,
     659,   586,  1696,  1697,   660,   601,   661,   589,  -608,   602,
     605,   662,   603,   310,   648,   604,   606,   616,   612,   636,
     654,   653,   426,   672,   673,   685,   688,   663,   537,   692,
    1709,  1633,   686,   687,   698,   706,   314,  1795,   716,   731,
     709,   710,   711,   712,   441,   728,   730,   741,   745,   768,
     754,   664,   665,   666,   667,   668,   669,   771,   777,   769,
    1359,   780,   788,   790,  1302,   789,   808,   537,   448,   791,
     310,   310,   310,   955,   956,   957,   958,   959,   960,   961,
     962,   963,   964,  1360,   802,   454,   809,   458,   815,   817,
     478,   483,   494,   314,   314,   314,   537,   822,   819,   823,
     826,   824,  1837,   442,  1838,   830,   838,   841,   840,   863,
     869,   858,   880,   898,  1846,   859,   864,   899,   900,   915,
     901,   928,   929,   930,   931,   953,   537,   537,   537,   537,
     944,   950,   951,   975,   607,   976,   980,   553,   943,  1139,
     979,  1001,  1005,  1003,   443,  1002,  1010,  1011,  1012,  1007,
    1020,  1035,  1013,  1014,  1041,  1042,  1045,  1052,  1053,  1063,
    1639,   574,  1101,  1060,  1054,  1055,   537,  1064,   453,   457,
     444,  1109,   477,   578,   482,   581,   493,  1104,   445,  1108,
     537,  1119,  1190,   970,  1103,  1458,   446,  1105,  1022,   310,
    1116,  1126,  1209,  1210,  1231,  1236,  1247,  1237,   422,  1239,
    1249,  1253,   773,   902,  1275,   537,  1273,  1260,  1276,  1274,
    1281,  1280,   314,  1279,   537,  1286,   537,  1287,   537,  1290,
     537,  1291,  1297,  1303,  1310,   310,  1305,  1304,  1309,  1312,
    1316,  1333,  1492,   537,  1332,  1351,   310,   734,  1361,  1382,
     421,  1384,  1410,  1386,  1391,   422,  1411,  1422,   314,  1414,
    1434,  1514,    13,  1423,  1425,   310,  1426,  1442,  1427,   314,
    1428,  1429,  1447,  1457,   422,  1456,   537,  1453,   537,  1459,
    1461,  1441,  1469,  1460,  1452,   310,  1475,  1471,   314,  1462,
    1477,  1463,   310,  1478,   426,  1479,  1483,   421,  1488,  1491,
    1720,   426,  1513,  1515,  1507,  1524,  1521,  1531,   314,  1516,
    1519,  1724,  1639,   850,  1726,   314,   421,  1530,  1535,  1532,
    1540,  1536,  1735,  1539,  1359,  1541,  1542,  1533,  1579,  1364,
    1534,  1375,  1586,   867,  1560,  1592,  1525,  1584,   537,  1563,
    1593,  1594,  1595,  1529,  1596,  1599,  1580,  1360,  1573,  1597,
    1605,  1598,  1610,  1612,  1616,  1618,  1623,  1630,  1631,  1632,
     537,  1635,  1677,  1666,  1636,  1641,  1653,  1652,  1658,  1661,
    1678,  1690,  1608,  1692,  1693,  1701,  1211,  1717,  1706,  1714,
    1719,  1614,  1725,  1757,  1758,  1742,  1765,  1770,  1760,  1761,
    1766,  1772,  1773,  1759,  1774,  1788,  1790,  1812,  1791,  1811,
    1836,  1803,  1823,  1815,  1726,  1691,   977,  1818,  1828,  1843,
     617,  1839,   621,  1440,  1670,  1671,  1672,  1804,  1842,  1713,
     618,  1192,  1272,  1455,  1768,  1115,   715,   751,  1799,  1829,
    1050,  1269,  1482,  1840,  1801,   770,  1628,  1558,  1821,  1373,
    1550,  1553,  1493,  1808,  1830,   816,  1833,  1503,  1497,  1835,
    1512,   905,  1175,   537,   906,  1845,   946,   537,  1523,   916,
     310,  1485,  1082,  1817,  1814,  1439,   759,   760,  1538,  1545,
    1544,  1244,   537,  1574,  1578,  1689,  1824,  1389,  1577,  1688,
    1413,   537,  1216,   314,  1607,  1698,  1448,  1575,     0,   854,
     691,   725,     0,     0,   729,   537,     0,  1824,   737,     0,
       0,   743,   744,  1359,     0,   537,  1808,     0,     0,   752,
       0,     0,     0,     0,     0,   764,   767,     0,     0,     0,
     767,     0,     0,     0,     0,     0,  1360,     0,   787,     0,
       0,     0,     0,     0,   537,   795,   796,   797,   800,     0,
       0,     0,     0,   806,     0,     0,     0,  1748,     0,     0,
       0,   813,     0,     0,     0,     0,     0,     0,     0,   537,
       0,     0,     0,     0,  1754,     0,     0,     0,     0,   537,
       0,     0,     0,   537,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1359,     0,     0,     0,     0,     0,   814,     0,     0,     0,
       0,  1359,  1359,     0,   310,     0,     0,     0,     0,     0,
       0,   800,  1359,  1360,     0,     0,     0,     0,     0,     0,
       0,     0,   825,     0,  1360,  1360,     0,   314,     0,     0,
     537,     0,     0,     0,     0,  1360,     0,     0,     0,   560,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   862,     0,
     537,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   537,   537,     0,     0,
       0,     0,     0,     0,  1359,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   537,     0,     0,   537,     0,  1360,   537,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     537,     0,     0,   310,     0,   537,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1359,     0,     0,     0,     0,   314,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   310,     0,     0,     0,
       0,     0,     0,     0,  1360,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1359,   974,   314,
       0,     0,     0,     0,     0,     0,  1359,     0,     0,     0,
       0,     0,  1004,     0,     0,     0,  1008,  1009,     0,     0,
    1360,     0,     0,     0,     0,     0,     0,     0,     0,  1360,
       0,     0,     0,     0,     0,     0,     0,     0,  1028,     0,
    1034,     0,     0,     0,     0,     0,     0,     0,  1040,     0,
       0,  1043,     0,     0,     0,  1048,     0,     0,     0,     0,
       0,     0,     0,   537,   537,     0,   537,     0,   537,     0,
       0,     0,     0,     0,     0,   537,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1081,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     537,     0,   537,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   537,     0,
       0,   537,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   537,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   537,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1125,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   537,     0,     0,     0,     0,
       0,     0,     0,   537,     0,     0,     0,     0,   537,     0,
     537,     0,   537,     0,     0,  1170,  1170,  1174,  1174,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   537,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1170,     0,     0,     0,     0,
       0,   537,     0,     0,     0,     0,   537,     0,     0,  1204,
       0,     0,     0,     0,     0,     0,     0,     0,   537,     0,
       0,   537,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1235,     0,     0,     0,     0,     0,
       0,     0,     0,  1242,     0,  1242,     0,   767,     0,  1170,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1170,     0,   560,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   842,   843,
       0,   851,   852,   853,   855,   806,   857,   806,     0,     0,
       0,     0,   865,     0,     0,     0,     0,     0,     0,     0,
     874,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   896,   897,     0,     0,     0,     0,     0,     0,
       0,   903,   904,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1383,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1170,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   941,     0,     0,     0,   941,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1006,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   767,     0,     0,     0,  1467,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1049,     0,     0,
       0,  1481,     0,     0,     0,     0,     0,     0,     0,     0,
    1170,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1074,   800,     0,     0,  1076,  1077,     0,
       0,     0,     0,     0,  1170,     0,   903,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1526,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   862,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   897,     0,     0,     0,     0,     0,  1127,  1131,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1170,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1193,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1613,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1234,     0,  1626,  1627,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1250,     0,     0,     0,     0,     0,     0,     0,
       0,  1643,     0,     0,  1170,     0,     0,  1170,     0,     0,
       0,     0,     0,     0,  1283,     0,     0,     0,     0,  1656,
       0,     0,     0,     0,  1660,  1288,  1289,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1308,     0,     0,  1311,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1336,  1337,  1338,     0,  1341,  1342,  1343,  1344,  1345,  1346,
    1347,  1348,  1349,     0,     0,  1352,  1353,     0,     0,     0,
       0,     0,     0,     0,  1367,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1127,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1170,  1729,     0,  1731,  1436,  1733,     0,     0,
       0,     0,     0,     0,  1741,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1170,
       0,  1170,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1764,     0,     0,
    1767,     0,     0,     0,     0,     0,     0,     0,     0,  1468,
       0,  1470,  1170,  1472,     0,     0,  1476,     0,     0,     0,
       0,  1480,     0,  1775,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1486,     0,     0,     0,     0,     0,     0,
       0,     0,  1490,     0,  1170,     0,     0,     0,  1494,  1495,
       0,     0,  1802,     0,     0,     0,     0,  1805,     0,  1170,
       0,  1170,     0,     0,     0,     0,     0,  1517,     0,     0,
    1518,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1822,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1831,     0,     0,     0,     0,  1832,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1841,     0,     0,
    1844,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1127,     0,     0,     0,  1131,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1617,     0,     0,     0,  1619,     0,     0,
       0,  1622,     0,  1624,     0,  1625,     0,     0,     0,     0,
       0,  1629,     0,     0,     0,     0,     0,     0,     0,  1634,
       0,     0,     0,     0,     0,     0,     0,  1638,  1640,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1486,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1662,
    1663,  1664,  1665,     0,  1667,  1668,     0,  1669,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1676,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1715,     0,  1716,     0,
       0,  1718,     0,     0,     0,     0,     0,     0,     0,  1721,
       0,     0,     0,     0,  1723,  1640,     0,     0,     0,     0,
       0,     0,  1727,     0,     0,     0,     0,  1732,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1744,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1750,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1769,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1727,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1809,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1820,
       0,     0,     0,     0,  1825,     0,     0,     0,     0,  1809,
    -165,   884,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     1,     2,     0,  1825,     0,     3,     0,  1834,     0,
       4,     5,     6,     7,     8,     9,    10,    11,    12,     0,
      13,     0,     0,    14,   417,     0,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,     0,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,     0,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,     0,    72,    73,    74,    75,    76,
       0,    77,    78,    79,     0,     0,    80,    81,     0,     0,
       0,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,     0,     0,     0,    93,     0,    94,    95,    96,
      97,     0,    98,     0,     0,     0,    99,   100,   101,   102,
     103,     0,     0,     0,     0,     0,     0,   104,   105,   106,
     107,   108,   109,   110,   111,   112,     0,   113,   114,   115,
     116,   117,     0,     0,     0,   118,   119,   120,   121,   122,
     123,   124,   125,     0,   126,     0,   127,   128,     0,     0,
     129,   130,   131,     0,     0,     0,   132,     0,   133,   134,
       0,   135,   136,     0,   137,     0,   138,     0,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,     0,
       0,   150,   151,   152,     0,   419,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,     0,   196,
     197,   198,     0,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,     0,   247,     0,   248,   249,   250,   251,   252,   253,
     254,  -165,   884,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     1,     2,     0,     0,     0,     3,     0,     0,
       0,     4,     5,     6,     7,     8,     9,    10,    11,    12,
       0,    13,     0,     0,   888,   417,     0,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
     418,    30,    31,    32,    33,    34,     0,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
       0,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,     0,    72,    73,    74,    75,
      76,     0,    77,    78,    79,     0,     0,    80,    81,     0,
       0,     0,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,     0,     0,     0,    93,     0,    94,    95,
      96,    97,     0,    98,     0,     0,     0,    99,   100,   101,
     102,   103,     0,     0,     0,     0,     0,     0,   104,   105,
     106,   107,   108,   109,   110,   111,   112,     0,   113,   114,
     115,   116,   117,     0,     0,     0,   118,   119,   120,   121,
     122,   123,   124,   125,     0,   126,     0,   127,   128,     0,
       0,   129,   130,   131,     0,     0,     0,   132,     0,   133,
     134,     0,   135,   136,     0,   137,     0,   138,     0,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
       0,     0,   150,   151,   152,     0,   419,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,     0,
     196,   197,   198,     0,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   884,   247,     0,   248,   249,   250,   251,   252,
     253,   254,     1,     2,     0,     0,     0,     3,     0,     0,
       0,     4,     5,     6,     7,     8,     9,    10,    11,    12,
       0,    13,     0,     0,   416,   417,     0,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
     418,    30,    31,    32,    33,    34,     0,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
       0,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,     0,    72,    73,    74,    75,
      76,     0,    77,    78,    79,     0,     0,    80,    81,     0,
       0,     0,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,     0,     0,     0,    93,     0,    94,    95,
      96,    97,     0,    98,     0,     0,     0,    99,   100,   101,
     102,   103,     0,     0,     0,     0,     0,     0,   104,   105,
     106,   107,   108,   109,   110,   111,   112,     0,   113,   114,
     115,   116,   117,     0,     0,     0,   118,   119,   120,   121,
     122,   123,   124,   125,     0,   126,     0,   127,   128,     0,
       0,   129,   130,   131,     0,     0,     0,   132,     0,   133,
     134,     0,   135,   136,     0,   137,     0,   138,     0,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
       0,     0,   150,   151,   152,     0,   419,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,     0,
     196,   197,   198,     0,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   884,   247,     0,   248,   249,   250,   251,   252,
     253,   254,     1,     2,     0,     0,     0,     3,     0,     0,
       0,     4,     5,     6,     7,     8,     9,    10,     0,     0,
       0,    13,     0,     0,   416,   417,     0,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,   562,
     418,    30,    31,    32,    33,    34,     0,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
       0,    48,    49,    50,   563,   564,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,     0,    72,    73,    74,    75,
      76,     0,    77,    78,    79,     0,     0,    80,    81,     0,
       0,     0,    82,    83,   512,    85,    86,    87,    88,    89,
     565,    91,    92,     0,     0,     0,    93,     0,    94,    95,
      96,    97,     0,    98,     0,     0,     0,    99,   100,   101,
     102,   103,     0,     0,     0,     0,     0,     0,   104,   105,
     106,   107,   108,   109,   110,   566,   112,     0,   113,   114,
     115,   116,   117,     0,     0,     0,   118,   119,   120,   121,
     122,   123,   124,   125,     0,   126,     0,   127,   128,     0,
       0,   129,   130,   131,     0,     0,     0,   132,     0,   133,
     134,     0,   135,   136,     0,   137,     0,   138,     0,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
       0,     0,   150,   151,   152,     0,   419,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   530,
     531,   532,   179,   180,   533,   568,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,     0,
     196,   197,   198,     0,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,     0,   247,     0,   248,   249,   250,   251,   252,
     253,   254,  -864,   459,     0,   460,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  -864,     0,     0,     0,  -864,     0,
       0,     0,  -864,  -864,     0,     0,     0,     0,  -864,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   461,
       0,     0,  -864,     0,   462,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  -864,     0,  -864,  -864,  -864,
       0,     0,  -864,  -864,  -864,  -864,     0,     0,     0,  -864,
    -864,     0,     0,     0,     0,     0,  -864,     0,     0,  -864,
    -864,   463,     0,     0,  -864,     0,     0,     0,     0,  -864,
    -864,     0,     0,     0,     0,  -864,     0,     0,     0,  -864,
       0,     0,     0,  -864,  -864,     0,  -864,     0,  -864,  -864,
       0,     0,     0,  -864,  -864,     0,     0,  -864,  -864,  -864,
    -864,  -864,  -864,     0,     0,  -864,     0,     0,     0,  -864,
    -864,     0,     0,  -864,     0,     0,     0,     0,  -864,     0,
       0,  -864,     0,     0,     0,     0,  -864,  -864,  -864,  -864,
    -864,     0,  -864,  -864,  -864,  -864,  -864,     0,     0,     0,
       0,  -864,  -864,  -864,     0,  -864,  -864,  -864,  -864,  -864,
    -864,     0,  -864,     0,  -864,     0,     0,     0,     0,  -864,
    -864,  -864,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  -864,     0,  -864,     0,  -864,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  -864,     0,     0,     0,     0,  -864,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     1,     2,     0,     0,     0,
       3,     0,     0,     0,     4,     5,     6,     7,     8,     9,
      10,    11,    12,  -864,    13,  -864,     0,    14,    15,     0,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,     0,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,     0,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,     0,    72,
      73,    74,    75,    76,     0,    77,    78,    79,     0,     0,
      80,    81,     0,     0,     0,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,     0,     0,     0,    93,
       0,    94,    95,    96,    97,     0,    98,     0,     0,     0,
      99,   100,   101,   102,   103,     0,     0,     0,     0,     0,
       0,   104,   105,   106,   107,   108,   109,   110,   111,   112,
       0,   113,   114,   115,   116,   117,     0,     0,     0,   118,
     119,   120,   121,   122,   123,   124,   125,     0,   126,     0,
     127,   128,     0,     0,   129,   130,   131,     0,     0,     0,
     132,     0,   133,   134,     0,   135,   136,     0,   137,     0,
     138,     0,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,     0,     0,   150,   151,   152,     0,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,     0,   196,   197,   198,     0,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,     0,   247,     0,   248,   249,
     250,   251,   252,   253,   254,   255,   256,     1,     2,     0,
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
      85,    86,    87,    88,    89,    90,    91,    92,     0,     0,
       0,    93,     0,    94,    95,    96,    97,     0,    98,     0,
       0,     0,    99,   100,   101,   102,   103,     0,     0,     0,
       0,     0,     0,   104,   105,   106,   107,   108,   109,   110,
     111,   112,     0,   113,   114,   115,   116,   117,     0,     0,
       0,   118,   119,   120,   121,   122,   123,   124,   125,     0,
     126,     0,   127,   128,     0,     0,   129,   130,   131,     0,
       0,     0,   132,     0,   133,   134,     0,   135,   136,     0,
     137,     0,   138,     0,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,     0,     0,   150,   151,   152,
       0,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,     0,   196,   197,   198,     0,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,     0,   247,     0,
     248,   249,   250,   251,   252,   253,   254,     0,   613,     1,
       2,     0,     0,     0,     3,     0,     0,     0,     4,     5,
       6,     7,     8,     9,    10,    11,    12,     0,    13,     0,
       0,   416,   417,     0,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,   418,    30,    31,
      32,    33,    34,     0,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,     0,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,     0,    72,    73,    74,    75,    76,     0,    77,
      78,    79,     0,     0,    80,    81,     0,     0,     0,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
       0,     0,     0,    93,     0,    94,    95,    96,    97,     0,
      98,     0,     0,     0,    99,   100,   101,   102,   103,     0,
       0,     0,     0,     0,     0,   104,   105,   106,   107,   108,
     109,   110,   111,   112,     0,   113,   114,   115,   116,   117,
       0,     0,     0,   118,   119,   120,   121,   122,   123,   124,
     125,     0,   126,     0,   127,   128,     0,     0,   129,   130,
     131,     0,   557,     0,   132,     0,   133,   134,     0,   135,
     136,     0,   137,     0,   138,     0,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,     0,     0,   150,
     151,   152,     0,   419,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,     0,   196,   197,   198,
       0,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,     0,
     247,     0,   248,   249,   250,   251,   252,   253,   254,     1,
       2,     0,     0,     0,     3,     0,     0,     0,     4,     5,
       6,     7,     8,     9,    10,    11,    12,     0,    13,     0,
       0,   416,   417,     0,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,   418,    30,    31,
      32,    33,    34,     0,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,     0,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,     0,    72,    73,    74,    75,    76,     0,    77,
      78,    79,     0,     0,    80,    81,     0,     0,     0,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
       0,     0,     0,    93,     0,    94,    95,    96,    97,     0,
      98,     0,     0,     0,    99,   100,   101,   102,   103,     0,
       0,     0,     0,     0,     0,   104,   105,   106,   107,   108,
     109,   110,   111,   112,     0,   113,   114,   115,   116,   117,
       0,     0,     0,   118,   119,   120,   121,   122,   123,   124,
     125,     0,   126,     0,   127,   128,     0,     0,   129,   130,
     131,     0,   818,     0,   132,     0,   133,   134,     0,   135,
     136,     0,   137,     0,   138,     0,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,     0,     0,   150,
     151,   152,     0,   419,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,     0,   196,   197,   198,
       0,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,     0,
     247,     0,   248,   249,   250,   251,   252,   253,   254,     1,
       2,     0,     0,     0,     3,     0,     0,     0,     4,     5,
       6,     7,     8,     9,    10,    11,    12,     0,    13,     0,
       0,   416,   417,     0,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,  1354,   418,    30,    31,
      32,    33,    34,     0,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,     0,    48,    49,
      50,  1355,  1356,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,     0,    72,    73,    74,    75,    76,     0,    77,
      78,    79,     0,     0,    80,    81,     0,     0,     0,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
       0,     0,     0,    93,     0,    94,    95,    96,    97,     0,
      98,     0,     0,     0,    99,   100,   101,   102,   103,     0,
       0,     0,     0,     0,     0,   104,   105,   106,   107,   108,
     109,   110,   111,   112,     0,   113,   114,   115,   116,   117,
       0,     0,     0,   118,   119,   120,   121,   122,   123,   124,
     125,     0,   126,     0,   127,   128,     0,     0,   129,   130,
     131,     0,   557,     0,   132,     0,   133,   134,     0,   135,
     136,     0,   137,     0,   138,     0,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,     0,     0,   150,
     151,   152,     0,   419,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,  1357,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,     0,   196,   197,   198,
       0,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,     0,
     247,     0,   248,   249,   250,   251,   252,   253,   254,     1,
       2,     0,     0,     0,     3,     0,     0,     0,     4,     5,
       6,     7,     8,     9,    10,    11,    12,     0,    13,     0,
       0,   416,   417,     0,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,   418,    30,    31,
      32,    33,    34,     0,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,     0,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,     0,    72,    73,    74,    75,    76,     0,    77,
      78,    79,     0,     0,    80,    81,     0,     0,     0,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
       0,     0,     0,    93,     0,    94,    95,    96,    97,     0,
      98,     0,     0,     0,    99,   100,   101,   102,   103,     0,
       0,     0,     0,     0,     0,   104,   105,   106,   107,   108,
     109,   110,   111,   112,     0,   113,   114,   115,   116,   117,
       0,     0,     0,   118,   119,   120,   121,   122,   123,   124,
     125,     0,   126,     0,   127,   128,     0,     0,   129,   130,
     131,     0,     0,     0,   132,     0,   133,   134,     0,   135,
     136,     0,   137,     0,   138,     0,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,     0,     0,   150,
     151,   152,     0,   419,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,     0,   196,   197,   198,
       0,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,     0,
     247,     0,   248,   249,   250,   251,   252,   253,   254,     1,
       2,     0,     0,     0,     3,     0,     0,     0,     4,     5,
       6,     7,     8,     9,    10,    11,    12,     0,    13,     0,
       0,    14,    15,     0,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,     0,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,     0,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,     0,    72,    73,    74,    75,    76,     0,    77,
      78,    79,     0,     0,    80,    81,     0,     0,     0,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
       0,     0,     0,    93,     0,    94,    95,    96,    97,     0,
      98,     0,     0,     0,    99,   100,   101,   102,   103,     0,
       0,     0,     0,     0,     0,   104,   105,   106,   107,   108,
     109,   110,   111,   112,     0,   113,   114,   115,   116,   117,
       0,     0,     0,   118,   119,   120,   121,   122,   123,   124,
     125,     0,   126,     0,   127,   128,     0,     0,   129,   130,
     131,     0,     0,     0,   132,     0,   133,   134,     0,   135,
     136,     0,   137,     0,   138,     0,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,     0,     0,   150,
     151,   152,     0,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,     0,   196,   197,   198,
       0,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,     0,
     247,     0,   248,   249,   250,   251,   252,   253,   254,     1,
       2,     0,     0,     0,     3,     0,     0,     0,     4,     5,
       6,     7,     8,     9,    10,    11,    12,     0,    13,     0,
       0,    14,    15,     0,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,     0,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,     0,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,     0,    72,    73,    74,    75,    76,     0,    77,
      78,    79,     0,     0,    80,    81,     0,     0,     0,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
       0,     0,     0,    93,     0,    94,    95,    96,    97,     0,
      98,     0,     0,     0,    99,   100,   101,   102,   103,     0,
       0,     0,     0,     0,     0,   104,   105,   106,   107,   108,
     109,   110,   111,   112,     0,   113,   114,   115,   116,   117,
       0,     0,     0,   118,   119,   120,   121,   122,   123,   124,
     125,     0,   126,     0,   127,   128,     0,     0,   129,   130,
     131,     0,     0,     0,   132,     0,   133,   134,     0,   135,
     136,     0,   137,     0,   138,     0,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,     0,     0,   150,
     151,   152,     0,   419,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,     0,   196,   197,   198,
       0,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,     0,
     247,     0,   248,   249,   250,   251,   252,   253,   254,     1,
       2,     0,     0,     0,     3,     0,     0,     0,     4,     5,
       6,     7,     8,     9,    10,    11,    12,     0,    13,     0,
       0,    14,   417,     0,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,     0,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,     0,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,     0,    72,    73,    74,    75,    76,     0,    77,
      78,    79,     0,     0,    80,    81,     0,     0,     0,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
       0,     0,     0,    93,     0,    94,    95,    96,    97,     0,
      98,     0,     0,     0,    99,   100,   101,   102,   103,     0,
       0,     0,     0,     0,     0,   104,   105,   106,   107,   108,
     109,   110,   111,   112,     0,   113,   114,   115,   116,   117,
       0,     0,     0,   118,   119,   120,   121,   122,   123,   124,
     125,     0,   126,     0,   127,   128,     0,     0,   129,   130,
     131,     0,     0,     0,   132,     0,   133,   134,     0,   135,
     136,     0,   137,     0,   138,     0,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,     0,     0,   150,
     151,   152,     0,   419,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,     0,   196,   197,   198,
       0,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,     0,
     247,     0,   248,   249,   250,   251,   252,   253,   254,     1,
       2,     0,     0,     0,     3,     0,     0,     0,     4,     5,
       6,     7,     8,     9,    10,    11,    12,     0,    13,     0,
       0,   888,   417,     0,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,   418,    30,    31,
      32,    33,    34,     0,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,     0,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,     0,    72,    73,    74,    75,    76,     0,    77,
      78,    79,     0,     0,    80,    81,     0,     0,     0,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
       0,     0,     0,    93,     0,    94,    95,    96,    97,     0,
      98,     0,     0,     0,    99,   100,   101,   102,   103,     0,
       0,     0,     0,     0,     0,   104,   105,   106,   107,   108,
     109,   110,   111,   112,     0,   113,   114,   115,   116,   117,
       0,     0,     0,   118,   119,   120,   121,   122,   123,   124,
     125,     0,   126,     0,   127,   128,     0,     0,   129,   130,
     131,     0,     0,     0,   132,     0,   133,   134,     0,   135,
     136,     0,   137,     0,   138,     0,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,     0,     0,   150,
     151,   152,     0,   419,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,     0,   196,   197,   198,
       0,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,     0,
     247,     0,   248,   249,   250,   251,   252,   253,   254,     1,
       2,     0,     0,     0,     3,     0,     0,     0,     4,     5,
       6,     7,     8,     9,    10,     0,     0,     0,    13,     0,
       0,   416,   417,     0,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,   562,   418,    30,    31,
      32,    33,    34,     0,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,     0,    48,    49,
      50,   563,   564,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,     0,    72,    73,    74,    75,    76,     0,    77,
      78,    79,     0,     0,    80,    81,     0,     0,     0,    82,
      83,   512,    85,    86,    87,    88,    89,   565,    91,    92,
       0,     0,     0,    93,     0,    94,    95,    96,    97,     0,
      98,     0,     0,     0,    99,   100,   101,   102,   103,     0,
       0,     0,     0,   939,     0,   104,   105,   106,   107,   108,
     109,   110,   566,   112,     0,   113,   114,   115,   116,   117,
       0,     0,     0,   118,   119,   120,   121,   122,   123,   124,
     125,     0,   126,     0,   127,   128,     0,     0,   129,   130,
     131,     0,     0,     0,   132,   940,   133,   134,     0,   135,
     136,     0,   137,     0,   138,     0,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,     0,     0,   150,
     151,   152,     0,   419,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   530,   531,   532,   179,
     180,   533,   568,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,     0,   196,   197,   198,
       0,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,     0,
     247,     0,   248,   249,   250,   251,   252,   253,   254,     1,
       2,     0,     0,     0,     3,     0,     0,     0,     4,     5,
       6,     7,     8,     9,    10,     0,     0,     0,    13,     0,
       0,   416,   417,     0,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,   562,   418,    30,    31,
      32,    33,    34,     0,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,     0,    48,    49,
      50,   563,   564,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,     0,    72,    73,    74,    75,    76,     0,    77,
      78,    79,     0,     0,    80,    81,     0,     0,     0,    82,
      83,   512,    85,    86,    87,    88,    89,   565,    91,    92,
       0,     0,     0,    93,     0,    94,    95,    96,    97,     0,
      98,     0,     0,     0,    99,   100,   101,   102,   103,     0,
       0,     0,     0,   939,     0,   104,   105,   106,   107,   108,
     109,   110,   566,   112,     0,   113,   114,   115,   116,   117,
       0,     0,     0,   118,   119,   120,   121,   122,   123,   124,
     125,     0,   126,     0,   127,   128,     0,     0,   129,   130,
     131,     0,     0,     0,   132,   945,   133,   134,     0,   135,
     136,     0,   137,     0,   138,     0,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,     0,     0,   150,
     151,   152,     0,   419,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   530,   531,   532,   179,
     180,   533,   568,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,     0,   196,   197,   198,
       0,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,     0,
     247,     0,   248,   249,   250,   251,   252,   253,   254,     1,
       2,     0,     0,     0,     3,     0,     0,     0,     4,     5,
       6,     7,     8,     9,    10,    11,    12,     0,    13,     0,
       0,   416,   417,     0,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,  1354,   418,    30,    31,
      32,    33,    34,     0,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,     0,    48,    49,
      50,  1355,  1356,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,     0,    72,    73,    74,    75,    76,     0,    77,
      78,    79,     0,     0,    80,    81,     0,     0,     0,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
       0,     0,     0,    93,     0,    94,    95,    96,    97,     0,
      98,     0,     0,     0,    99,   100,   101,   102,   103,     0,
       0,     0,     0,     0,     0,   104,   105,   106,   107,   108,
     109,   110,   111,   112,     0,   113,   114,   115,   116,   117,
       0,     0,     0,   118,   119,   120,   121,   122,   123,   124,
     125,     0,   126,     0,   127,   128,     0,     0,   129,   130,
     131,     0,     0,     0,   132,     0,   133,   134,     0,   135,
     136,     0,   137,     0,   138,     0,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,     0,     0,   150,
     151,   152,     0,   419,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,  1357,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,     0,   196,   197,   198,
       0,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,     0,
     247,     0,   248,   249,   250,   251,   252,   253,   254,     1,
       2,     0,     0,     0,     3,     0,     0,     0,     4,     5,
       6,     7,     8,     9,    10,     0,     0,     0,    13,     0,
       0,   416,   417,     0,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,   562,   418,    30,    31,
      32,    33,    34,     0,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,     0,    48,    49,
      50,   563,   564,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,     0,    72,    73,    74,    75,    76,     0,    77,
      78,    79,     0,     0,    80,    81,     0,     0,     0,    82,
      83,   512,    85,    86,    87,    88,    89,   565,    91,    92,
       0,     0,     0,    93,     0,    94,    95,    96,    97,     0,
      98,     0,     0,     0,    99,   100,   101,   102,   103,     0,
       0,     0,     0,     0,     0,   104,   105,   106,   107,   108,
     109,   110,   566,   112,     0,   113,   114,   115,   116,   117,
       0,     0,     0,   118,   119,   120,   121,   122,   123,   124,
     125,     0,   126,     0,   127,   128,     0,     0,   129,   130,
     131,     0,     0,   567,   132,     0,   133,   134,     0,   135,
     136,     0,   137,     0,   138,     0,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,     0,     0,   150,
     151,   152,     0,   419,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   530,   531,   532,   179,
     180,   533,   568,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,     0,   196,   197,   198,
       0,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,     0,
     247,     0,   248,   249,   250,   251,   252,   253,   254,     1,
       2,     0,     0,     0,     3,     0,     0,     0,     4,     5,
       6,     7,     8,     9,    10,     0,     0,     0,    13,     0,
       0,   416,   417,     0,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,   562,   418,    30,    31,
      32,    33,    34,     0,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,     0,    48,    49,
      50,   563,   564,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,     0,    72,    73,    74,    75,    76,     0,    77,
      78,    79,     0,     0,    80,    81,     0,     0,     0,    82,
      83,   512,    85,    86,    87,    88,    89,   565,    91,    92,
       0,     0,     0,    93,     0,    94,    95,    96,    97,     0,
      98,     0,     0,     0,    99,   100,   101,   102,   103,     0,
       0,     0,     0,     0,     0,   104,   105,   106,   107,   108,
     109,   110,   566,   112,     0,   113,   114,   115,   116,   117,
       0,     0,     0,   118,   119,   120,   121,   122,   123,   124,
     125,     0,   126,     0,   127,   128,     0,     0,   129,   130,
     131,     0,     0,     0,   132,   572,   133,   134,     0,   135,
     136,     0,   137,     0,   138,     0,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,     0,     0,   150,
     151,   152,     0,   419,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   530,   531,   532,   179,
     180,   533,   568,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,     0,   196,   197,   198,
       0,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,     0,
     247,     0,   248,   249,   250,   251,   252,   253,   254,     1,
       2,     0,     0,     0,     3,     0,     0,     0,     4,     5,
       6,     7,     8,     9,    10,     0,     0,     0,    13,     0,
       0,   416,   417,     0,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,   562,   418,    30,    31,
      32,    33,    34,     0,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,     0,    48,    49,
      50,   563,   564,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,     0,    72,    73,    74,    75,    76,     0,    77,
      78,    79,     0,     0,    80,    81,     0,     0,     0,    82,
      83,   512,    85,    86,    87,    88,    89,   565,    91,    92,
       0,     0,     0,    93,     0,    94,    95,    96,    97,     0,
      98,     0,     0,     0,    99,   100,   101,   102,   103,     0,
       0,     0,     0,     0,     0,   104,   105,   106,   107,   108,
     109,   110,   566,   112,     0,   113,   114,   115,   116,   117,
       0,     0,     0,   118,   119,   120,   121,   122,   123,   124,
     125,     0,   126,     0,   127,   128,     0,     0,   129,   130,
     131,     0,     0,     0,   132,     0,   133,   134,     0,   135,
     136,     0,   137,     0,   138,     0,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,     0,     0,   150,
     151,   152,     0,   419,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   530,   531,   532,   179,
     180,   533,   568,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,     0,   196,   197,   198,
       0,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   608,
     247,     0,   248,   249,   250,   251,   252,   253,   254,     1,
       2,     0,     0,     0,     3,     0,     0,     0,     4,     5,
       6,     7,     8,     9,    10,     0,     0,     0,    13,     0,
       0,   416,   417,     0,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,   562,   418,    30,    31,
      32,    33,    34,     0,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,     0,    48,    49,
      50,   563,   564,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,     0,    72,    73,    74,    75,    76,     0,    77,
      78,    79,     0,     0,    80,    81,     0,     0,     0,    82,
      83,   512,    85,    86,    87,    88,    89,   565,    91,    92,
       0,     0,     0,    93,     0,    94,    95,    96,    97,     0,
      98,     0,     0,     0,    99,   100,   101,   102,   103,     0,
       0,     0,     0,     0,     0,   104,   105,   106,   107,   108,
     109,   110,   566,   112,     0,   113,   114,   115,   116,   117,
       0,     0,     0,   118,   119,   120,   121,   122,   123,   124,
     125,     0,   126,     0,   127,   128,     0,     0,   129,   130,
     131,     0,     0,     0,   132,     0,   133,   134,     0,   135,
     136,     0,   137,     0,   138,     0,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,     0,     0,   150,
     151,   152,     0,   419,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   530,   531,   532,   179,
     180,   533,   568,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,     0,   196,   197,   198,
       0,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,     0,
     247,   610,   248,   249,   250,   251,   252,   253,   254,     1,
       2,     0,     0,     0,     3,     0,     0,     0,     4,     5,
       6,     7,     8,     9,    10,     0,     0,     0,    13,     0,
       0,   416,   417,     0,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,   562,   418,    30,    31,
      32,    33,    34,     0,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,     0,    48,    49,
      50,   563,   564,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,     0,    72,    73,    74,    75,    76,     0,    77,
      78,    79,     0,     0,    80,    81,     0,     0,     0,    82,
      83,   512,    85,    86,    87,    88,    89,   565,    91,    92,
       0,     0,     0,    93,     0,    94,    95,    96,    97,     0,
      98,     0,     0,     0,    99,   100,   101,   102,   103,     0,
       0,     0,     0,     0,     0,   104,   105,   106,   107,   108,
     109,   110,   566,   112,     0,   113,   114,   115,   116,   117,
       0,     0,     0,   118,   119,   120,   121,   122,   123,   124,
     125,     0,   126,     0,   127,   128,     0,     0,   129,   130,
     131,     0,   933,     0,   132,     0,   133,   134,     0,   135,
     136,     0,   137,     0,   138,     0,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,     0,     0,   150,
     151,   152,     0,   419,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   530,   531,   532,   179,
     180,   533,   568,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,     0,   196,   197,   198,
       0,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,     0,
     247,     0,   248,   249,   250,   251,   252,   253,   254,     1,
       2,     0,     0,     0,     3,     0,     0,     0,     4,     5,
       6,     7,     8,     9,    10,     0,     0,     0,    13,     0,
       0,   416,   417,     0,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,   562,   418,    30,    31,
      32,    33,    34,     0,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,     0,    48,    49,
      50,   563,   564,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,     0,    72,    73,    74,    75,    76,     0,    77,
      78,    79,     0,     0,    80,    81,     0,     0,     0,    82,
      83,   512,    85,    86,    87,    88,    89,   565,    91,    92,
       0,     0,     0,    93,     0,    94,    95,    96,    97,     0,
      98,     0,     0,     0,    99,   100,   101,   102,   103,     0,
       0,     0,     0,  1435,     0,   104,   105,   106,   107,   108,
     109,   110,   566,   112,     0,   113,   114,   115,   116,   117,
       0,     0,     0,   118,   119,   120,   121,   122,   123,   124,
     125,     0,   126,     0,   127,   128,     0,     0,   129,   130,
     131,     0,     0,     0,   132,     0,   133,   134,     0,   135,
     136,     0,   137,     0,   138,     0,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,     0,     0,   150,
     151,   152,     0,   419,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   530,   531,   532,   179,
     180,   533,   568,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,     0,   196,   197,   198,
       0,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,     0,
     247,     0,   248,   249,   250,   251,   252,   253,   254,     1,
       2,     0,     0,     0,     3,     0,     0,     0,     4,     5,
       6,     7,     8,     9,    10,     0,     0,     0,    13,     0,
       0,   416,   417,     0,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,   498,    27,   500,   418,    30,   501,
      32,    33,    34,     0,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,   503,     0,    48,    49,
      50,   505,   506,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,     0,    72,    73,    74,    75,    76,     0,    77,
      78,    79,     0,     0,    80,    81,     0,     0,     0,    82,
      83,   512,    85,    86,    87,    88,    89,   565,    91,    92,
       0,     0,     0,    93,     0,    94,    95,    96,    97,     0,
      98,     0,     0,     0,   515,   100,   101,   102,   103,     0,
       0,     0,     0,     0,     0,   104,   105,   106,   107,   108,
     109,   110,   566,   112,     0,   113,   114,   689,   116,   117,
       0,     0,     0,   118,   119,   120,   121,   122,   123,   124,
     125,     0,   126,     0,   690,   128,     0,     0,   129,   130,
     131,     0,     0,     0,   132,     0,   133,   134,     0,   135,
     136,     0,   137,     0,   138,     0,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,     0,     0,   150,
     151,   152,     0,   419,   154,   155,   156,   157,   158,   159,
     160,   161,   525,   163,   526,   165,   527,   528,   168,   169,
     170,   171,   172,   173,   529,   175,   530,   531,   532,   179,
     180,   533,   534,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,     0,   196,   197,   198,
       0,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,     0,
     247,     0,   248,   535,   250,   251,   252,   253,   254,     1,
       2,     0,     0,     0,     3,     0,     0,     0,     4,     5,
       6,     7,     8,     9,    10,     0,     0,     0,    13,     0,
       0,   416,   417,     0,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,   562,   418,    30,    31,
      32,    33,    34,     0,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,     0,    48,    49,
      50,   563,   564,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,     0,    72,    73,    74,    75,    76,     0,    77,
      78,    79,     0,     0,    80,    81,     0,     0,     0,    82,
      83,   512,    85,    86,    87,    88,    89,   565,    91,    92,
       0,     0,     0,    93,     0,    94,    95,    96,    97,     0,
      98,     0,     0,     0,    99,   100,   101,   102,   103,     0,
       0,     0,     0,     0,     0,   104,   105,   106,   107,   108,
     109,   110,   566,   112,     0,   113,   114,   115,   116,   117,
       0,     0,     0,   118,   119,   120,   121,   122,   123,   124,
     125,     0,   126,     0,   127,   128,     0,     0,   129,   130,
     131,     0,     0,     0,   132,     0,   133,   134,     0,   135,
     136,     0,   137,     0,   138,     0,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,     0,     0,   150,
     151,   152,     0,   419,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   530,   531,   532,   179,
     180,   533,   568,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,     0,   196,   197,   198,
       0,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,     0,
     247,     0,   248,   249,   250,   251,   252,   253,   254,     1,
       2,     0,     0,     0,     3,     0,     0,     0,     4,     5,
       6,     7,     8,     9,    10,     0,     0,     0,    13,     0,
       0,   416,   417,     0,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,   498,    27,   500,   418,    30,   501,
      32,    33,    34,     0,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,   503,     0,    48,    49,
      50,   505,   506,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,     0,    72,    73,    74,    75,    76,     0,    77,
      78,    79,     0,     0,    80,    81,     0,     0,     0,    82,
      83,   512,    85,    86,    87,    88,    89,   565,    91,    92,
       0,     0,     0,    93,     0,    94,    95,    96,    97,     0,
      98,     0,     0,     0,   515,   100,   101,   102,   103,     0,
       0,     0,     0,     0,     0,   104,   105,   106,   107,   108,
     109,   110,   566,   112,     0,   113,   114,   115,   116,   117,
       0,     0,     0,   118,   119,   120,   121,   122,   123,   124,
     125,     0,   126,     0,   127,   128,     0,     0,   129,   130,
     131,     0,     0,     0,   132,     0,   133,   134,     0,   135,
     136,     0,   137,     0,   138,     0,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,     0,     0,   150,
     151,   152,     0,   419,   154,   155,   156,   157,   158,   159,
     160,   161,   525,   163,   526,   165,   527,   528,   168,   169,
     170,   171,   172,   173,   529,   175,   530,   531,   532,   179,
     180,   533,   534,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,     0,   196,   197,   198,
       0,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,     0,
     247,     0,   248,   535,   250,   251,   252,   253,   254,     1,
       2,     0,     0,     0,     3,     0,     0,     0,     4,     5,
       6,     7,     8,     9,    10,     0,     0,     0,    13,     0,
       0,   416,   417,     0,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,   562,   418,    30,    31,
      32,    33,    34,     0,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,     0,    48,    49,
      50,   563,   564,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,     0,    72,    73,    74,    75,    76,     0,    77,
      78,    79,     0,     0,    80,    81,     0,     0,     0,    82,
      83,   512,    85,    86,    87,    88,    89,  1130,    91,    92,
       0,     0,     0,    93,     0,    94,    95,    96,    97,     0,
      98,     0,     0,     0,    99,   100,   101,   102,   103,     0,
       0,     0,     0,     0,     0,   104,   105,   106,   107,   108,
     109,   110,   566,   112,     0,   113,   114,   115,   116,   117,
       0,     0,     0,   118,   119,   120,   121,   122,   123,   124,
     125,     0,   126,     0,   127,   128,     0,     0,   129,   130,
     131,     0,     0,     0,   132,     0,   133,   134,     0,   135,
     136,     0,   137,     0,   138,     0,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,     0,     0,   150,
     151,   152,     0,   419,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   530,   531,   532,   179,
     180,   533,   568,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,     0,   196,   197,   198,
       0,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,     0,
     247,     0,   248,   249,   250,   251,   252,   253,   254,     1,
       2,     0,     0,     0,     3,     0,     0,     0,     4,     5,
       6,     7,     8,     9,    10,     0,     0,     0,    13,     0,
       0,   416,   417,     0,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,   498,    27,   500,   418,    30,   501,
      32,    33,    34,     0,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,   503,     0,    48,    49,
      50,   505,   506,    53,   507,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,     0,    72,    73,    74,    75,    76,     0,    77,
      78,    79,     0,     0,    80,    81,     0,     0,     0,    82,
      83,   512,    85,    86,    87,    88,    89,   565,    91,    92,
       0,     0,     0,    93,     0,    94,    95,    96,    97,     0,
      98,     0,     0,     0,   515,   100,   101,   102,   103,     0,
       0,     0,     0,     0,     0,   104,   105,   106,   107,   108,
     109,   110,   566,   112,     0,   113,   114,     0,   116,   117,
       0,     0,     0,   118,   119,   120,   121,   122,   123,   124,
     125,     0,   126,     0,     0,     0,     0,     0,   129,   130,
     131,     0,     0,     0,   132,     0,   133,   134,     0,   135,
     136,     0,   137,     0,   138,     0,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,     0,     0,   150,
     151,   152,     0,   419,   154,   155,   156,   157,   158,   159,
     160,   161,   525,   163,   526,   165,   527,   528,   168,   169,
     170,   171,   172,   173,   529,   175,   530,   531,   532,   179,
     180,   533,   534,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,     0,   196,   197,   198,
       0,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,     0,
     247,     0,   248,   535,   250,   251,   252,   253,   254,     1,
       2,     0,     0,     0,     3,     0,     0,     0,     4,     5,
       6,     7,     8,     9,    10,     0,     0,     0,    13,     0,
       0,   416,   417,     0,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,   498,    27,   500,   418,    30,   501,
      32,    33,    34,     0,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,   503,     0,    48,    49,
      50,   505,   506,    53,   507,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,     0,    72,    73,    74,    75,    76,     0,    77,
      78,    79,     0,     0,    80,    81,     0,     0,     0,    82,
      83,   512,    85,    86,    87,    88,    89,   565,    91,    92,
       0,     0,     0,    93,     0,    94,    95,    96,    97,     0,
      98,     0,     0,     0,   515,   100,   101,   102,   103,     0,
       0,     0,     0,     0,     0,   104,   105,   106,   107,   108,
     109,   110,   566,   112,     0,   113,   114,     0,   116,   117,
       0,     0,     0,   118,   119,   120,   121,   122,   123,   124,
     125,     0,   126,     0,     0,     0,     0,     0,   129,   130,
     131,     0,     0,     0,   132,     0,   133,   134,     0,     0,
       0,     0,   137,     0,   138,     0,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,     0,     0,   150,
     151,   152,     0,   419,   154,   155,   156,   157,   158,   159,
     160,   161,   525,   163,   526,   165,   527,   528,   168,   169,
     170,   171,   172,   173,   529,   175,   530,   531,   532,   179,
     180,   533,   534,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,     0,   196,   197,   198,
       0,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,     0,
     247,     0,   248,   535,   250,   251,   252,   253,   254,     1,
       2,     0,     0,     0,     3,     0,     0,     0,     4,     5,
       6,     7,     8,     9,    10,     0,     0,     0,    13,     0,
       0,   416,   417,     0,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,   498,    27,   500,   418,    30,   501,
      32,    33,    34,     0,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,   503,     0,    48,    49,
      50,   505,   506,    53,   507,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,     0,    72,    73,    74,    75,    76,     0,    77,
      78,    79,     0,     0,    80,    81,     0,     0,     0,    82,
      83,   512,    85,    86,    87,    88,    89,   565,    91,    92,
       0,     0,     0,    93,     0,    94,    95,    96,    97,     0,
      98,     0,     0,     0,   515,     0,   101,   102,   103,     0,
       0,     0,     0,     0,     0,   104,   105,   106,   107,     0,
     109,   110,   566,   112,     0,   113,   114,     0,   116,   117,
       0,     0,     0,   118,   119,   120,   121,   122,   123,   124,
     125,     0,   126,     0,     0,     0,     0,     0,   129,   130,
     131,     0,     0,     0,   132,     0,   133,   134,     0,     0,
       0,     0,   137,     0,   138,     0,   139,     0,   141,     0,
     143,   144,   145,   146,   147,   148,   149,     0,     0,   150,
     151,   152,     0,   419,   154,   155,   156,   157,   158,   159,
     160,   161,   525,   163,   526,   165,   527,   528,   168,   169,
     170,   171,   172,   173,   529,   175,   530,   531,   532,   179,
     180,   533,   534,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,     0,   196,   197,   198,
       0,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,     0,
     247,     0,   248,   535,   250,   251,   252,   253,   254,     1,
       2,     0,     0,     0,     3,     0,     0,     0,     4,     0,
       0,     0,     0,     9,    10,     0,     0,     0,     0,     0,
       0,   416,   417,     0,    16,    17,    18,   495,    20,    21,
      22,   496,    24,   497,   498,   499,   500,   418,    30,   501,
      32,    33,    34,     0,    35,    36,    37,    38,   502,    40,
      41,    42,    43,    44,    45,    46,   503,     0,    48,   504,
      50,   505,   506,    53,   507,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,   508,
     509,    71,     0,    72,    73,    74,   510,     0,     0,    77,
      78,    79,     0,     0,   511,    81,     0,     0,     0,     0,
      83,   512,    85,   513,   514,    88,    89,     0,     0,     0,
       0,     0,     0,     0,     0,    94,    95,    96,    97,     0,
      98,     0,     0,     0,   515,   100,   101,   516,   517,     0,
       0,     0,     0,     0,     0,   104,   105,   106,     0,   108,
     109,   110,     0,     0,     0,     0,     0,     0,   116,   518,
       0,     0,     0,   118,   119,   120,   121,   519,   123,   124,
     520,     0,     0,     0,     0,     0,     0,     0,   521,   522,
     131,     0,     0,     0,   132,     0,   133,   523,     0,     0,
       0,     0,   137,     0,   138,     0,   139,   140,   141,   142,
     524,   144,   145,   146,   147,   148,   149,     0,     0,   150,
     151,     0,     0,   419,   154,   155,   156,   157,   158,   159,
     160,   161,   525,   163,   526,   165,   527,   528,   168,   169,
     170,   171,   172,   173,   529,   175,   530,   531,   532,   179,
     180,   533,   534,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,     0,   196,   197,   198,
       0,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,     0,     0,
       0,     0,   248,   535,   250,   251,   252,   253,   254,     1,
       2,     0,     0,     0,     3,     0,     0,     0,     4,     0,
       0,     0,     0,     9,    10,     0,     0,     0,     0,     0,
       0,   416,   417,     0,    16,    17,    18,   543,    20,    21,
      22,   496,   544,   545,   498,   499,   500,   418,    30,   501,
      32,   546,    34,     0,    35,    36,    37,    38,   547,    40,
     548,   549,    43,    44,    45,    46,   503,     0,    48,   550,
      50,   505,   506,    53,   507,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,   508,
     509,    71,     0,    72,    73,    74,   551,     0,     0,    77,
      78,    79,     0,     0,   511,    81,     0,     0,     0,     0,
      83,   512,    85,   513,   514,    88,    89,     0,     0,     0,
       0,     0,     0,     0,     0,    94,    95,    96,    97,     0,
      98,     0,     0,     0,   515,   100,   101,   516,   517,     0,
       0,     0,     0,     0,     0,   104,   105,   106,     0,   108,
     109,   110,     0,     0,     0,     0,     0,     0,   116,   518,
       0,     0,     0,   118,   119,   120,   121,   519,   123,   124,
     520,     0,     0,     0,     0,     0,     0,     0,   521,   522,
     131,     0,     0,     0,   132,     0,   133,   523,     0,     0,
       0,     0,   137,     0,   138,     0,   139,   140,   141,   142,
     524,   144,   145,   146,   147,   148,   149,     0,     0,   150,
     151,     0,     0,   419,   154,   155,   156,   157,   158,   159,
     160,   161,   525,   552,   526,   165,   527,   528,   168,   169,
     170,   171,   172,   173,   529,   175,   530,   531,   532,   179,
     180,   533,   534,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,     0,   196,   197,   198,
       0,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,     0,     0,
       3,     0,   248,   535,   250,   251,   252,   253,   254,     9,
      10,     0,     0,     0,     0,     0,     0,   416,   417,     0,
      16,    17,    18,   495,    20,    21,    22,   496,    24,   497,
     498,  1150,   500,   418,    30,   501,    32,    33,    34,     0,
      35,    36,    37,    38,   502,    40,    41,    42,    43,    44,
      45,    46,   503,     0,    48,   504,    50,   505,   506,    53,
     507,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,   508,   509,    71,     0,    72,
      73,    74,   510,     0,     0,    77,    78,    79,     0,     0,
     511,    81,     0,     0,     0,     0,    83,   512,    85,   513,
     514,    88,    89,     0,     0,     0,     0,     0,     0,     0,
       0,    94,    95,    96,    97,     0,    98,     0,     0,     0,
     515,   100,   101,   516,   517,     0,     0,     0,     0,     0,
       0,   104,   105,   106,     0,   108,   109,  1151,     0,     0,
       0,  1152,     0,     0,   116,   518,     0,     0,     0,   118,
     119,   120,   121,   519,   123,   124,   520,     0,     0,     0,
       0,     0,     0,     0,   521,   522,   131,     0,     0,     0,
     132,  1588,   133,   523,     0,     0,     0,     0,  1589,     0,
     138,     0,   139,   140,   141,   142,   524,   144,   145,   146,
     147,   148,   149,     0,     0,  1153,   151,     0,     0,   419,
     154,   155,   156,   157,   158,   159,   160,   161,   525,   163,
     526,   165,   527,   528,   168,   169,   170,   171,   172,   173,
     529,   175,   530,   531,   532,   179,   180,   533,   534,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,     0,   196,   197,   198,     0,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,     0,     0,     0,     0,   248,   535,
     250,  1154,  1155,  1156,  1157,     3,     0,   579,   580,     0,
       0,     0,     0,     0,     9,    10,     0,     0,     0,     0,
       0,     0,   416,   417,     0,    16,    17,    18,   543,    20,
      21,    22,   496,   544,   545,   498,   499,   500,   418,    30,
     501,    32,   546,    34,     0,    35,    36,    37,    38,   547,
      40,   548,   549,    43,    44,    45,    46,   503,     0,    48,
     550,    50,   505,   506,    53,   507,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
     508,   509,    71,     0,    72,    73,    74,   551,     0,     0,
      77,    78,    79,     0,     0,   511,    81,     0,     0,     0,
       0,    83,   512,    85,   513,   514,    88,    89,     0,     0,
       0,     0,     0,     0,     0,     0,    94,    95,    96,    97,
       0,    98,     0,     0,     0,   515,   100,   101,   516,   517,
       0,     0,     0,     0,     0,     0,   104,   105,   106,     0,
     108,   109,   110,     0,     0,     0,     0,     0,     0,   116,
     518,     0,     0,     0,   118,   119,   120,   121,   519,   123,
     124,   520,     0,     0,     0,     0,     0,     0,     0,   521,
     522,   131,     0,     0,     0,   132,     0,   133,   523,     0,
       0,     0,     0,     0,     0,   138,     0,   139,   140,   141,
     142,   524,   144,   145,   146,   147,   148,   149,     0,     0,
     150,   151,     0,     0,   419,   154,   155,   156,   157,   158,
     159,   160,   161,   525,   552,   526,   165,   527,   528,   168,
     169,   170,   171,   172,   173,   529,   175,   530,   531,   532,
     179,   180,   533,   534,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,     0,   196,   197,
     198,     0,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,     0,
       0,     3,     0,   248,   535,   250,   251,   252,   253,   254,
       9,    10,     0,     0,     0,     0,     0,     0,   416,   417,
       0,    16,    17,    18,   543,    20,    21,    22,   496,   544,
     545,   498,   499,   500,   418,    30,   501,    32,   546,    34,
       0,    35,    36,    37,    38,   547,    40,   548,   549,    43,
      44,    45,    46,   503,     0,    48,   550,    50,   505,   506,
      53,   507,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,   508,   509,    71,     0,
      72,    73,    74,   551,     0,     0,    77,    78,    79,     0,
       0,   511,    81,     0,     0,     0,     0,    83,   512,    85,
     513,   514,    88,    89,     0,     0,     0,     0,     0,     0,
       0,     0,    94,    95,    96,    97,     0,    98,     0,     0,
       0,   515,   100,   101,   516,   517,     0,     0,     0,     0,
       0,     0,   104,   105,   106,     0,   108,   109,   110,     0,
       0,     0,     0,     0,     0,   116,   518,     0,     0,     0,
     118,   119,   120,   121,   519,   123,   124,   520,     0,     0,
       0,     0,     0,     0,     0,   521,   522,   131,     0,     0,
       0,   132,   762,   133,   523,     0,     0,     0,     0,   763,
       0,   138,     0,   139,   140,   141,   142,   524,   144,   145,
     146,   147,   148,   149,     0,     0,   150,   151,     0,     0,
     419,   154,   155,   156,   157,   158,   159,   160,   161,   525,
     552,   526,   165,   527,   528,   168,   169,   170,   171,   172,
     173,   529,   175,   530,   531,   532,   179,   180,   533,   534,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,     0,   196,   197,   198,     0,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,     0,     0,     3,     0,   248,
     535,   250,   251,   252,   253,   254,     9,    10,     0,     0,
       0,   793,     0,     0,   416,   417,     0,    16,    17,    18,
     543,    20,    21,    22,   496,   544,   545,   498,   499,   500,
     418,    30,   501,    32,   546,    34,     0,    35,    36,    37,
      38,   547,    40,   548,   549,    43,    44,    45,    46,   503,
       0,    48,   550,    50,   505,   506,    53,   507,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,   508,   509,    71,     0,    72,    73,    74,   551,
       0,     0,    77,    78,    79,     0,     0,   511,    81,     0,
       0,     0,     0,    83,   512,    85,   513,   514,    88,    89,
       0,     0,     0,     0,     0,     0,     0,     0,    94,    95,
      96,    97,     0,    98,     0,     0,     0,   515,   100,   101,
     516,   517,     0,     0,     0,     0,     0,     0,   104,   105,
     106,     0,   108,   109,   110,     0,     0,     0,     0,     0,
       0,   116,   518,     0,     0,     0,   118,   119,   120,   121,
     519,   123,   124,   520,     0,     0,     0,     0,     0,     0,
       0,   521,   522,   131,     0,     0,     0,   132,   794,   133,
     523,     0,     0,     0,     0,     0,     0,   138,     0,   139,
     140,   141,   142,   524,   144,   145,   146,   147,   148,   149,
       0,     0,   150,   151,     0,     0,   419,   154,   155,   156,
     157,   158,   159,   160,   161,   525,   552,   526,   165,   527,
     528,   168,   169,   170,   171,   172,   173,   529,   175,   530,
     531,   532,   179,   180,   533,   534,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,     0,
     196,   197,   198,     0,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,     0,     0,     3,     0,   248,   535,   250,   251,   252,
     253,   254,     9,    10,     0,     0,     0,     0,     0,     0,
     416,   417,     0,    16,    17,    18,   543,    20,    21,    22,
     496,   544,   545,   498,   499,   500,   418,    30,   501,    32,
     546,    34,     0,    35,    36,    37,    38,   547,    40,   548,
     549,    43,    44,    45,    46,   503,     0,    48,   550,    50,
     505,   506,    53,   507,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,   508,   509,
      71,     0,    72,    73,    74,   551,     0,     0,    77,    78,
      79,     0,     0,   511,    81,     0,     0,     0,     0,    83,
     512,    85,   513,   514,    88,    89,     0,     0,     0,     0,
       0,     0,     0,     0,    94,    95,    96,    97,     0,    98,
       0,     0,     0,   515,   100,   101,   516,   517,     0,     0,
       0,     0,     0,     0,   104,   105,   106,     0,   108,   109,
     110,     0,     0,     0,     0,     0,     0,   116,   518,     0,
       0,     0,   118,   119,   120,   121,   519,   123,   124,   520,
       0,     0,     0,     0,     0,     0,     0,   521,   522,   131,
       0,     0,     0,   132,   811,   133,   523,     0,     0,     0,
       0,   812,     0,   138,     0,   139,   140,   141,   142,   524,
     144,   145,   146,   147,   148,   149,     0,     0,   150,   151,
       0,     0,   419,   154,   155,   156,   157,   158,   159,   160,
     161,   525,   552,   526,   165,   527,   528,   168,   169,   170,
     171,   172,   173,   529,   175,   530,   531,   532,   179,   180,
     533,   534,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,     0,   196,   197,   198,     0,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,     0,     0,     3,
       0,   248,   535,   250,   251,   252,   253,   254,     9,    10,
       0,     0,     0,     0,     0,     0,   416,   417,     0,    16,
      17,    18,   495,    20,    21,    22,   496,    24,   497,   498,
    1150,   500,   418,    30,   501,    32,    33,    34,     0,    35,
      36,    37,    38,   502,    40,    41,    42,    43,    44,    45,
      46,   503,     0,    48,   504,    50,   505,   506,    53,   507,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,   508,   509,    71,     0,    72,    73,
      74,   510,     0,     0,    77,    78,    79,     0,     0,   511,
      81,     0,     0,     0,     0,    83,   512,    85,   513,   514,
      88,    89,  1504,     0,     0,     0,     0,     0,     0,     0,
      94,    95,    96,    97,     0,    98,     0,     0,     0,   515,
     100,   101,   516,   517,     0,     0,     0,     0,     0,     0,
     104,   105,   106,     0,   108,   109,  1151,     0,     0,     0,
    1152,     0,     0,   116,   518,     0,     0,     0,   118,   119,
     120,   121,   519,   123,   124,   520,     0,     0,     0,     0,
       0,     0,     0,   521,   522,   131,     0,     0,     0,   132,
       0,   133,   523,     0,     0,     0,     0,     0,     0,   138,
       0,   139,   140,   141,   142,   524,   144,   145,   146,   147,
     148,   149,     0,     0,  1153,   151,     0,     0,   419,   154,
     155,   156,   157,   158,   159,   160,   161,   525,   163,   526,
     165,   527,   528,   168,   169,   170,   171,   172,   173,   529,
     175,   530,   531,   532,   179,   180,   533,   534,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,     0,   196,   197,   198,     0,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,     0,     0,     3,     0,   248,   535,   250,
    1154,  1155,  1156,  1157,     9,    10,     0,     0,     0,     0,
       0,     0,   416,   417,     0,    16,    17,    18,   495,    20,
      21,    22,   496,    24,   497,   498,  1150,   500,   418,    30,
     501,    32,    33,    34,     0,    35,    36,    37,    38,   502,
      40,    41,    42,    43,    44,    45,    46,   503,     0,    48,
     504,    50,   505,   506,    53,   507,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
     508,   509,    71,     0,    72,    73,    74,   510,     0,     0,
      77,    78,    79,     0,     0,   511,    81,     0,     0,     0,
       0,    83,   512,    85,   513,   514,    88,    89,  1646,     0,
       0,     0,     0,     0,     0,     0,    94,    95,    96,    97,
       0,    98,     0,     0,     0,   515,   100,   101,   516,   517,
       0,     0,     0,     0,     0,     0,   104,   105,   106,     0,
     108,   109,  1151,     0,     0,     0,  1152,     0,     0,   116,
     518,     0,     0,     0,   118,   119,   120,   121,   519,   123,
     124,   520,     0,     0,     0,     0,     0,     0,     0,   521,
     522,   131,     0,     0,     0,   132,     0,   133,   523,     0,
       0,     0,     0,     0,     0,   138,     0,   139,   140,   141,
     142,   524,   144,   145,   146,   147,   148,   149,     0,     0,
    1153,   151,     0,     0,   419,   154,   155,   156,   157,   158,
     159,   160,   161,   525,   163,   526,   165,   527,   528,   168,
     169,   170,   171,   172,   173,   529,   175,   530,   531,   532,
     179,   180,   533,   534,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,     0,   196,   197,
     198,     0,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,     0,
       0,     3,     0,   248,   535,   250,  1154,  1155,  1156,  1157,
       9,    10,     0,     0,     0,     0,     0,     0,   416,   417,
       0,    16,    17,    18,   495,    20,    21,    22,   496,    24,
     497,   498,  1150,   500,   418,    30,   501,    32,    33,    34,
       0,    35,    36,    37,    38,   502,    40,    41,    42,    43,
      44,    45,    46,   503,     0,    48,   504,    50,   505,   506,
      53,   507,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,   508,   509,    71,     0,
      72,    73,    74,   510,     0,     0,    77,    78,    79,     0,
       0,   511,    81,     0,     0,     0,     0,    83,   512,    85,
     513,   514,    88,    89,  1650,     0,     0,     0,     0,     0,
       0,     0,    94,    95,    96,    97,     0,    98,     0,     0,
       0,   515,   100,   101,   516,   517,     0,     0,     0,     0,
       0,     0,   104,   105,   106,     0,   108,   109,  1151,     0,
       0,     0,  1152,     0,     0,   116,   518,     0,     0,     0,
     118,   119,   120,   121,   519,   123,   124,   520,     0,     0,
       0,     0,     0,     0,     0,   521,   522,   131,     0,     0,
       0,   132,     0,   133,   523,     0,     0,     0,     0,     0,
       0,   138,     0,   139,   140,   141,   142,   524,   144,   145,
     146,   147,   148,   149,     0,     0,  1153,   151,     0,     0,
     419,   154,   155,   156,   157,   158,   159,   160,   161,   525,
     163,   526,   165,   527,   528,   168,   169,   170,   171,   172,
     173,   529,   175,   530,   531,   532,   179,   180,   533,   534,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,     0,   196,   197,   198,     0,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,     0,     0,     3,     0,   248,
     535,   250,  1154,  1155,  1156,  1157,     9,    10,     0,     0,
       0,     0,     0,     0,   416,   417,     0,    16,    17,    18,
     495,    20,    21,    22,   496,    24,   497,   498,  1150,   500,
     418,    30,   501,    32,    33,    34,     0,    35,    36,    37,
      38,   502,    40,    41,    42,    43,    44,    45,    46,   503,
       0,    48,   504,    50,   505,   506,    53,   507,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,   508,   509,    71,     0,    72,    73,    74,   510,
       0,     0,    77,    78,    79,     0,     0,   511,    81,     0,
       0,     0,     0,    83,   512,    85,   513,   514,    88,    89,
       0,     0,     0,     0,     0,     0,     0,     0,    94,    95,
      96,    97,     0,    98,     0,     0,     0,   515,   100,   101,
     516,   517,     0,     0,     0,     0,     0,     0,   104,   105,
     106,     0,   108,   109,  1151,     0,     0,     0,  1152,     0,
       0,   116,   518,     0,     0,     0,   118,   119,   120,   121,
     519,   123,   124,   520,     0,     0,     0,     0,     0,     0,
       0,   521,   522,   131,     0,     0,     0,   132,     0,   133,
     523,     0,     0,     0,     0,     0,     0,   138,     0,   139,
     140,   141,   142,   524,   144,   145,   146,   147,   148,   149,
       0,     0,  1153,   151,     0,     0,   419,   154,   155,   156,
     157,   158,   159,   160,   161,   525,   163,   526,   165,   527,
     528,   168,   169,   170,   171,   172,   173,   529,   175,   530,
     531,   532,   179,   180,   533,   534,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,     0,
     196,   197,   198,     0,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,     0,     0,     3,     0,   248,   535,   250,  1154,  1155,
    1156,  1157,     9,    10,     0,     0,     0,     0,     0,     0,
     416,   417,     0,    16,    17,    18,   495,    20,    21,    22,
     496,    24,   497,   498,  1150,   500,   418,    30,   501,    32,
      33,    34,     0,    35,    36,    37,    38,   502,    40,    41,
      42,    43,    44,    45,    46,   503,     0,    48,   504,    50,
     505,   506,    53,   507,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,   508,   509,
      71,     0,    72,    73,    74,   510,     0,     0,    77,    78,
      79,     0,     0,   511,    81,     0,     0,     0,     0,    83,
     512,    85,   513,   514,    88,    89,     0,     0,     0,     0,
       0,     0,     0,     0,    94,    95,    96,    97,     0,    98,
       0,     0,     0,   515,   100,   101,   516,   517,     0,     0,
       0,     0,     0,     0,   104,   105,   106,     0,   108,   109,
    1151,     0,     0,     0,  1152,     0,     0,   116,   518,     0,
       0,     0,   118,   119,   120,   121,   519,   123,   124,   520,
       0,     0,     0,     0,     0,     0,     0,   521,   522,   131,
       0,     0,     0,   132,     0,   133,   523,     0,     0,     0,
       0,     0,     0,   138,     0,   139,   140,   141,   142,   524,
     144,   145,   146,   147,   148,   149,     0,     0,   150,   151,
       0,     0,   419,   154,   155,   156,   157,   158,   159,   160,
     161,   525,   163,   526,   165,   527,   528,   168,   169,   170,
     171,   172,   173,   529,   175,   530,   531,   532,   179,   180,
     533,   534,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,     0,   196,   197,   198,     0,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,     0,     0,     3,
       0,   248,   535,   250,  1154,  1155,  1156,  1157,     9,    10,
       0,     0,     0,     0,     0,     0,   416,   417,     0,    16,
      17,    18,   543,    20,    21,    22,   496,   544,   545,   498,
     499,   500,   418,    30,   501,    32,   546,    34,     0,    35,
      36,    37,    38,   547,    40,   548,   549,    43,    44,    45,
      46,   503,     0,    48,   550,    50,   505,   506,    53,   507,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,   508,   509,    71,     0,    72,    73,
      74,   551,     0,     0,    77,    78,    79,     0,     0,   511,
      81,     0,     0,     0,     0,    83,   512,    85,   513,   514,
      88,    89,  1245,     0,     0,     0,     0,     0,     0,     0,
      94,    95,    96,    97,     0,    98,     0,     0,     0,   515,
     100,   101,   516,   517,     0,     0,     0,     0,     0,     0,
     104,   105,   106,     0,   108,   109,   110,     0,     0,     0,
       0,     0,     0,   116,   518,     0,     0,     0,   118,   119,
     120,   121,   519,   123,   124,   520,     0,     0,     0,     0,
       0,     0,     0,   521,   522,   131,     0,     0,     0,   132,
       0,   133,   523,     0,     0,     0,     0,     0,     0,   138,
       0,   139,   140,   141,   142,   524,   144,   145,   146,   147,
     148,   149,     0,     0,   150,   151,     0,     0,   419,   154,
     155,   156,   157,   158,   159,   160,   161,   525,   552,   526,
     165,   527,   528,   168,   169,   170,   171,   172,   173,   529,
     175,   530,   531,   532,   179,   180,   533,   534,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,     0,   196,   197,   198,     0,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,     0,     0,     3,     0,   248,   535,   250,
     251,   252,   253,   254,     9,    10,     0,     0,     0,     0,
       0,     0,   416,   417,     0,    16,    17,    18,   543,    20,
      21,    22,   496,   544,   545,   498,   499,   500,   418,    30,
     501,    32,   546,    34,     0,    35,    36,    37,    38,   547,
      40,   548,   549,    43,    44,    45,    46,   503,     0,    48,
     550,    50,   505,   506,    53,   507,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
     508,   509,    71,     0,    72,    73,    74,   551,     0,     0,
      77,    78,    79,     0,     0,   511,    81,     0,     0,     0,
       0,    83,   512,    85,   513,   514,    88,    89,     0,     0,
       0,     0,     0,     0,     0,     0,    94,    95,    96,    97,
       0,    98,     0,     0,     0,   515,   100,   101,   516,   517,
       0,     0,     0,     0,     0,     0,   104,   105,   106,     0,
     108,   109,   110,     0,     0,     0,     0,     0,     0,   116,
     518,     0,     0,     0,   118,   119,   120,   121,   519,   123,
     124,   520,     0,     0,     0,     0,     0,     0,     0,   521,
     522,   131,     0,     0,     0,   132,     0,   133,   523,     0,
       0,     0,     0,     0,     0,   138,     0,   139,   140,   141,
     142,   524,   144,   145,   146,   147,   148,   149,     0,     0,
     150,   151,     0,     0,   419,   154,   155,   156,   157,   158,
     159,   160,   161,   525,   552,   526,   165,   527,   528,   168,
     169,   170,   171,   172,   173,   529,   175,   530,   531,   532,
     179,   180,   533,   534,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,     0,   196,   197,
     198,     0,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,     0,
       0,     0,     0,   248,   535,   250,   251,   252,   253,   254,
       5,     6,     7,     8,     9,    10,     0,     0,     0,    13,
       0,     0,   416,   417,     0,    16,    17,    18,   844,    20,
      21,    22,    23,     0,   845,   498,    27,     0,   418,    30,
     501,    32,     0,    34,     0,    35,    36,    37,    38,   846,
      40,     0,     0,    43,    44,    45,    46,   503,     0,    48,
     847,    50,     0,     0,    53,   507,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
     508,   509,    71,     0,    72,    73,    74,   848,     0,     0,
      77,    78,    79,     0,     0,   511,    81,     0,     0,     0,
      82,    83,   512,    85,   513,   514,    88,    89,   565,    91,
       0,     0,     0,     0,    93,     0,    94,    95,    96,    97,
       0,    98,     0,     0,     0,   515,   100,   101,   516,   517,
       0,     0,     0,     0,     0,     0,   104,   105,   106,   107,
     108,   109,     0,   566,   112,     0,   113,   114,     0,   116,
     117,     0,     0,     0,   118,   119,   120,   121,   122,   123,
     124,   520,     0,   126,     0,     0,     0,     0,     0,   521,
     522,   131,     0,     0,     0,   132,     0,   133,   523,     0,
       0,     0,     0,     0,     0,   138,     0,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,     0,     0,
       0,   151,   152,     0,   419,   154,   155,   156,   157,   158,
     159,   160,   161,   525,     0,   526,   165,   527,   528,   168,
     169,   170,   171,   172,   173,   529,   175,   530,   531,   532,
     179,   180,     0,   534,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,     0,   196,   197,
     198,     0,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
       0,   247,     0,   248,   535,   250,   251,   252,   253,   254,
       9,    10,     0,     0,     0,     0,     0,     0,   416,   417,
       0,    16,    17,    18,     0,    20,    21,    22,   496,     0,
       0,   498,   499,     0,   418,    30,   501,    32,     0,    34,
       0,    35,    36,    37,    38,     0,    40,     0,     0,    43,
      44,    45,    46,   503,     0,    48,     0,    50,     0,     0,
      53,   507,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,   508,   509,    71,     0,
      72,    73,    74,     0,     0,     0,    77,    78,    79,     0,
       0,   511,    81,     0,     0,     0,     0,    83,   512,    85,
     513,   514,    88,    89,     0,     0,     0,     0,     0,     0,
       0,     0,    94,    95,    96,    97,     0,    98,     0,     0,
       0,   515,   100,   101,   516,   517,     0,     0,     0,     0,
       0,     0,   104,   105,   106,     0,   108,   109,     0,     0,
       0,     0,     0,     0,     0,   116,   518,     0,     0,     0,
     118,   119,   120,   121,   519,   123,   124,   520,     0,     0,
       0,     0,     0,     0,     0,   521,   522,   131,     0,     0,
       0,   132,     0,   133,   523,     0,     0,     0,     0,     0,
       0,   138,     0,   139,   140,   141,   142,   524,   144,   145,
     146,   147,   148,   149,     0,     0,     0,   151,     0,     0,
     419,   154,   155,   156,   157,   158,   159,   160,   161,   525,
       0,   526,   165,   527,   528,   168,   169,   170,   171,   172,
     173,   529,   175,   530,   531,   532,   179,   180,     0,   534,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,     0,   196,   197,   198,     0,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,     0,     0,     0,     0,   248,
     535,   250,   251,   252,   253,   254
  };

  /* YYCHECK.  */
  const short int
  xquery_parser::yycheck_[] =
  {
         0,     5,     6,     7,   294,     5,     6,     7,     8,   182,
     676,   692,   343,    14,     5,     6,     7,     8,   314,  1061,
     787,   767,   429,     0,  1045,   262,   112,   113,     5,     6,
       7,     8,   136,   800,   869,   263,     1,   427,   428,   677,
     678,   679,   680,   592,  1383,  1315,  1298,   814,   597,   831,
     278,   626,   627,  1002,   767,    76,     5,     6,     7,     8,
    1379,  1380,   469,   470,  1136,   952,   724,   915,    36,   255,
     256,   928,   929,  1085,     1,  1020,  1414,  1507,   928,   929,
    1510,  1328,   624,   625,   626,   627,    36,    56,     1,    27,
      28,     1,   108,   624,   625,     1,    27,    28,   655,     1,
     657,   658,    30,   660,     1,   662,     1,     1,     1,    47,
     119,   111,   119,   670,   671,   143,    47,     1,   968,    57,
     111,     1,   148,   285,     0,     1,     1,    95,    45,    97,
     122,     1,   422,   108,   111,    39,   426,    75,   968,     1,
      44,    45,    80,   108,    75,   225,    63,    97,   108,    53,
     230,    97,  1002,     8,   137,   108,    60,     1,    62,    63,
     246,   247,   111,   217,    31,  1022,     1,    71,   155,  1016,
     157,  1018,  1022,   225,   112,   113,   114,     1,  1035,   169,
     148,   108,   113,   111,     1,  1035,   269,   108,    33,   107,
     201,   138,   154,   276,    98,   157,   143,   125,   148,   210,
     254,     0,     1,   286,    49,  1610,   108,   974,   294,    33,
     128,   157,   202,   108,   108,   190,   225,   233,   201,     1,
       1,  1068,   150,  1070,     9,    10,   154,   187,    55,   157,
      57,  1550,   108,   108,   314,   188,    37,    38,   108,    40,
      41,   233,   346,     1,     1,   273,   108,   273,   217,   177,
     237,     1,     1,  1295,     1,   255,   256,    58,    97,   259,
    1281,  1028,   314,   184,   108,     1,   273,  1034,  1520,   559,
     187,  1609,     1,   108,   101,   571,  1523,   190,   255,   256,
     190,  1027,   259,   185,   190,   254,   448,  1236,  1136,  1137,
     184,   108,   187,   190,   294,  1725,   954,   190,   307,  1081,
    1245,  1188,  1152,   878,   879,   273,   190,  1319,   184,   108,
     190,    97,  1025,   114,  1027,   185,  1328,   294,  1390,   104,
     175,   225,  1152,   273,    76,   187,   108,   108,   735,     1,
     351,   259,   108,   354,  1047,     1,   422,  1676,    90,   124,
     426,   126,  1772,   187,  1774,   876,   877,   214,   313,   287,
     108,   108,   187,   643,   911,  1760,   287,   295,   108,   108,
     161,   108,   114,    30,   295,   303,    97,   108,   148,   154,
     187,   457,   108,   158,   126,   159,   128,     1,   785,   108,
     101,   467,    94,   169,   311,   184,  1236,   624,   625,   174,
    1709,   477,   176,   621,   622,   108,    30,   186,   484,   485,
       1,     1,     1,   631,   157,   187,   187,   493,     1,   108,
     195,  1750,   101,   317,   318,   319,  1273,   256,   257,   220,
     108,   210,   422,  1273,   251,   157,   426,   613,   213,   187,
     187,    27,    28,   108,   184,   184,   108,   264,   169,   266,
     187,    45,   108,    47,  1763,   422,   187,  1297,   184,   426,
     277,   278,   279,   453,   281,   455,   283,   131,   187,   235,
     261,    52,   453,    95,   455,   186,   252,   253,  1235,   255,
     101,   183,    95,   559,   187,    77,   453,  1747,   455,     5,
     114,   119,   482,     9,   108,   269,   272,   487,   187,   575,
     576,   482,   276,   273,   161,   154,   487,   186,   284,   187,
     586,  1247,   286,   107,   453,   482,   455,   108,   108,   108,
     487,  1523,   184,   188,   119,   108,    97,   113,   184,   605,
     606,   252,   253,   197,   255,   915,  1361,   161,   131,     9,
    1365,   262,    95,   482,   225,   108,   227,   119,   487,   130,
    1792,   272,  1390,  1256,   107,  1120,  1121,  1122,   186,    29,
    1231,  1399,   154,   284,     5,   186,  1105,   947,     9,   559,
     184,   108,  1410,   108,   168,  1422,   566,   148,   975,   976,
      30,    95,  1422,   980,   225,   566,   227,   867,  1120,  1121,
    1122,   186,   559,   184,   184,   184,   218,   219,   108,   566,
     108,   184,   696,   697,   197,   218,   219,   108,   124,   351,
     126,   233,   354,  1010,   894,   187,   606,   693,   134,   161,
     233,  1632,   698,   613,   187,   606,  1383,   566,   619,   221,
     222,    30,   132,   314,   624,   625,   626,   627,   154,   606,
      95,   155,   138,   157,    95,    97,   613,   143,    95,   876,
     187,   154,   187,   643,   124,   154,   126,   624,   625,   626,
     627,   111,   114,    97,   882,   135,   154,  1507,   886,    97,
    1510,     9,    10,   314,   177,   125,   643,   187,    42,   187,
     114,   101,    46,   124,   154,   126,   187,    51,   143,   268,
     190,   433,   434,   134,   114,   437,   275,   148,     9,   441,
     150,   148,   444,   445,   154,   157,    70,   157,    97,   186,
     452,   210,   111,   154,  1746,   157,   458,   459,    29,    54,
     148,   463,   210,   157,    59,   114,   125,   177,     1,   471,
       3,  1737,  1738,   210,   157,  1471,   478,   479,   480,   481,
      45,  1579,    47,    78,   486,  1401,   822,   823,   824,  1521,
     826,   150,   494,   118,  1526,   166,  1136,  1137,    95,   157,
     137,    42,    97,     9,    10,    46,   104,   146,   186,   186,
      51,   182,    42,  1779,   151,    80,    46,    95,   157,  1785,
     123,    51,   147,   777,   119,  1456,   124,   777,   126,    70,
     145,   867,   210,   210,    67,   160,   777,   539,  1645,    72,
      70,   138,   107,  1368,   168,  1645,   143,   171,     9,    10,
     777,   154,   554,   124,   157,   126,   154,  1138,   808,   809,
     158,   176,   186,   565,   135,   143,    25,   808,   809,   194,
    1110,   119,   159,     1,   159,    34,   174,   186,   777,   194,
     186,   808,   809,   154,    95,  1692,   119,  1694,   212,   176,
     592,   176,  1692,   154,  1694,   597,   107,   195,   104,   601,
     157,   210,    61,   168,   210,    33,    54,   149,   182,   808,
     809,    59,   199,   149,   199,   213,   177,   867,   124,  1276,
     126,    49,   196,   165,  1656,  1725,   138,   168,  1660,   165,
     171,   138,   143,  1111,   159,   263,   157,   888,   168,  1117,
     867,   171,   154,   104,   894,   186,   274,   154,   154,    97,
    1757,   176,   158,   157,  1570,  1571,   186,  1757,    96,   182,
     157,   247,   248,   124,   101,   126,   965,   894,   174,   107,
     101,   212,  1772,   196,  1774,  1563,   628,   114,   977,   117,
     632,  1612,   212,   114,   270,   101,   101,   101,   157,   195,
     128,  1114,  1709,   154,   263,   299,    54,   158,   114,   114,
     114,    59,   123,   154,   308,   274,   157,   213,   119,  1741,
      27,    28,   154,   174,   154,   157,   699,   157,  1375,   702,
      37,    38,   705,    40,    41,   123,   728,  1384,   123,   731,
      47,   277,   278,   279,   195,  1275,   350,   283,   123,   353,
      57,    58,   123,   745,   221,   222,   223,   749,   750,   155,
    1390,   157,   213,   232,   232,   234,   234,   119,    75,  1399,
     154,   191,   192,    80,  1680,  1681,   129,   130,   123,   771,
    1410,   773,   129,   130,   674,   675,   681,   682,   123,   781,
     154,   133,   784,  1714,   683,   684,   788,  1229,  1230,   141,
     142,   123,   144,   123,   123,   112,   113,   114,   123,  1135,
     152,   154,  1600,  1601,   156,   119,   158,   216,   157,   241,
     157,   163,   241,  1063,  1360,   242,   154,     0,   314,   190,
      93,   167,  1063,   249,   100,    50,   103,   179,   830,   193,
    1761,  1488,   200,   102,   155,   157,  1063,  1753,    30,   119,
     184,   184,   184,   184,   161,    47,   153,   246,   304,   284,
     187,   203,   204,   205,   206,   207,   208,   119,   154,   284,
    1110,     1,   119,   108,  1063,   143,   154,   869,  1119,   187,
    1120,  1121,  1122,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,  1110,   187,   157,   154,   157,   143,   184,
     157,   157,   157,  1120,  1121,  1122,   898,   157,   122,   157,
     154,   157,  1833,   220,  1835,    35,    17,    30,   214,   190,
     245,   231,     3,   119,  1845,   230,   190,   168,   170,    71,
     170,   231,    95,    95,    95,    30,   928,   929,   930,   931,
     150,   108,   108,   161,  1357,   161,   133,    90,   187,  1579,
     128,   246,   143,   299,   261,    95,   133,   184,   184,   119,
     108,    95,   187,   187,    97,    45,    97,   187,   187,   154,
    1500,   114,    95,   184,   187,   187,   968,   184,   154,   154,
     287,   190,   154,   126,   154,   128,   154,   225,   295,   143,
     982,    33,   133,   143,   237,  1239,   303,   231,    95,  1239,
     233,   170,    30,   286,   227,    95,   128,   299,  1239,   154,
     119,   148,   119,  1543,   198,  1007,    95,   254,   133,   184,
      97,   133,  1239,   161,  1016,   154,  1018,   119,  1020,   148,
    1022,   101,   101,   184,   190,  1275,   154,   184,   143,   122,
      35,    30,  1286,  1035,   154,   119,  1286,    80,   245,   108,
    1239,   107,   258,   108,   285,  1286,   260,   157,  1275,   267,
     145,  1305,    30,   157,   157,  1305,   157,    30,   157,  1286,
     157,   157,    30,   190,  1305,   227,  1068,   306,  1070,   187,
     145,   286,   148,   187,   287,  1325,   148,   128,  1305,   187,
     148,   187,  1332,   119,  1325,   119,    78,  1286,   108,   143,
    1630,  1332,   184,   187,   101,     7,   133,   233,  1325,   187,
     198,  1641,  1642,  1105,  1644,  1332,  1305,   190,    97,   233,
     157,   237,  1652,   186,  1364,   157,   157,   233,   148,   154,
     233,   107,    79,  1364,   187,   187,  1325,   286,  1130,   250,
     187,   187,   187,  1332,   187,    30,   282,  1364,   250,   187,
      30,   187,   108,   170,   184,   148,   148,   127,   127,    97,
    1152,   184,   143,   316,   186,   186,   184,   186,   184,   184,
     184,   154,   271,    95,   187,    30,    97,   148,   187,   170,
      54,   257,    95,    95,    30,   197,   119,   119,   108,   108,
     225,    95,   186,   265,    95,   197,   197,    94,   198,   186,
     186,   119,   119,   183,  1734,   280,   734,   197,   119,   119,
     259,   199,   262,  1191,  1540,  1541,  1542,   225,   225,   287,
     259,   969,  1036,  1236,  1714,   870,   428,   448,  1761,   293,
     790,  1033,  1265,   287,   305,   463,  1481,  1386,   305,  1126,
    1379,  1382,  1287,  1773,   305,   554,   306,  1295,  1292,   306,
    1300,   653,   931,  1245,   654,   306,   708,  1249,  1319,   673,
    1500,  1791,   831,  1785,  1779,  1190,   456,   456,  1351,  1362,
    1361,  1018,  1264,  1399,  1410,  1579,  1806,  1137,  1403,  1576,
    1146,  1273,  1001,  1500,  1446,  1603,  1213,  1400,    -1,   595,
     338,   434,    -1,    -1,   437,  1287,    -1,  1827,   441,    -1,
      -1,   444,   445,  1543,    -1,  1297,  1836,    -1,    -1,   452,
      -1,    -1,    -1,    -1,    -1,   458,   459,    -1,    -1,    -1,
     463,    -1,    -1,    -1,    -1,    -1,  1543,    -1,   471,    -1,
      -1,    -1,    -1,    -1,  1326,   478,   479,   480,   481,    -1,
      -1,    -1,    -1,   486,    -1,    -1,    -1,  1673,    -1,    -1,
      -1,   494,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1351,
      -1,    -1,    -1,    -1,  1690,    -1,    -1,    -1,    -1,  1361,
      -1,    -1,    -1,  1365,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1630,    -1,    -1,    -1,    -1,    -1,   539,    -1,    -1,    -1,
      -1,  1641,  1642,    -1,  1644,    -1,    -1,    -1,    -1,    -1,
      -1,   554,  1652,  1630,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   565,    -1,  1641,  1642,    -1,  1644,    -1,    -1,
    1422,    -1,    -1,    -1,    -1,  1652,    -1,    -1,    -1,   111,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   601,    -1,
    1452,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1478,  1479,    -1,    -1,
      -1,    -1,    -1,    -1,  1734,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1504,    -1,    -1,  1507,    -1,  1734,  1510,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1522,    -1,    -1,  1773,    -1,  1527,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1791,    -1,    -1,    -1,    -1,  1773,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1806,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1791,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1827,   731,  1806,
      -1,    -1,    -1,    -1,    -1,    -1,  1836,    -1,    -1,    -1,
      -1,    -1,   745,    -1,    -1,    -1,   749,   750,    -1,    -1,
    1827,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1836,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   771,    -1,
     773,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   781,    -1,
      -1,   784,    -1,    -1,    -1,   788,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1645,  1646,    -1,  1648,    -1,  1650,    -1,
      -1,    -1,    -1,    -1,    -1,  1657,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   830,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1692,    -1,  1694,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1710,    -1,
      -1,  1713,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1725,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1736,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   898,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1757,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1765,    -1,    -1,    -1,    -1,  1770,    -1,
    1772,    -1,  1774,    -1,    -1,   928,   929,   930,   931,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1803,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   968,    -1,    -1,    -1,    -1,
      -1,  1823,    -1,    -1,    -1,    -1,  1828,    -1,    -1,   982,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1840,    -1,
      -1,  1843,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1007,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1016,    -1,  1018,    -1,  1020,    -1,  1022,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1035,    -1,   566,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   590,   591,
      -1,   593,   594,   595,   596,  1068,   598,  1070,    -1,    -1,
      -1,    -1,   604,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     612,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   634,   635,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   643,   644,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1130,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1152,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   704,    -1,    -1,    -1,   708,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   747,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1245,    -1,    -1,    -1,  1249,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   789,    -1,    -1,
      -1,  1264,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1273,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   815,  1287,    -1,    -1,   819,   820,    -1,
      -1,    -1,    -1,    -1,  1297,    -1,   828,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1326,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1351,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   894,    -1,    -1,    -1,    -1,    -1,   900,   901,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1422,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   970,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1452,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1005,    -1,  1478,  1479,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1024,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1504,    -1,    -1,  1507,    -1,    -1,  1510,    -1,    -1,
      -1,    -1,    -1,    -1,  1046,    -1,    -1,    -1,    -1,  1522,
      -1,    -1,    -1,    -1,  1527,  1057,  1058,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1072,    -1,    -1,  1075,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1092,  1093,  1094,    -1,  1096,  1097,  1098,  1099,  1100,  1101,
    1102,  1103,  1104,    -1,    -1,  1107,  1108,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1116,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1126,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1645,  1646,    -1,  1648,  1178,  1650,    -1,    -1,
      -1,    -1,    -1,    -1,  1657,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1692,
      -1,  1694,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1710,    -1,    -1,
    1713,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1251,
      -1,  1253,  1725,  1255,    -1,    -1,  1258,    -1,    -1,    -1,
      -1,  1263,    -1,  1736,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1275,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1284,    -1,  1757,    -1,    -1,    -1,  1290,  1291,
      -1,    -1,  1765,    -1,    -1,    -1,    -1,  1770,    -1,  1772,
      -1,  1774,    -1,    -1,    -1,    -1,    -1,  1309,    -1,    -1,
    1312,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1803,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1823,    -1,    -1,    -1,    -1,  1828,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1840,    -1,    -1,
    1843,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1382,    -1,    -1,    -1,  1386,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1465,    -1,    -1,    -1,  1469,    -1,    -1,
      -1,  1473,    -1,  1475,    -1,  1477,    -1,    -1,    -1,    -1,
      -1,  1483,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1491,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1499,  1500,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1519,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1531,
    1532,  1533,  1534,    -1,  1536,  1537,    -1,  1539,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1554,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1618,    -1,  1620,    -1,
      -1,  1623,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1631,
      -1,    -1,    -1,    -1,  1636,  1637,    -1,    -1,    -1,    -1,
      -1,    -1,  1644,    -1,    -1,    -1,    -1,  1649,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1666,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1677,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1717,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1730,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1773,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1801,
      -1,    -1,    -1,    -1,  1806,    -1,    -1,    -1,    -1,  1811,
       0,     1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    11,    12,    -1,  1826,    -1,    16,    -1,  1830,    -1,
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
     120,   121,    -1,    -1,    -1,   125,    -1,   127,   128,   129,
     130,    -1,   132,    -1,    -1,    -1,   136,   137,   138,   139,
     140,    -1,    -1,    -1,    -1,    -1,    -1,   147,   148,   149,
     150,   151,   152,   153,   154,   155,    -1,   157,   158,   159,
     160,   161,    -1,    -1,    -1,   165,   166,   167,   168,   169,
     170,   171,   172,    -1,   174,    -1,   176,   177,    -1,    -1,
     180,   181,   182,    -1,    -1,    -1,   186,    -1,   188,   189,
      -1,   191,   192,    -1,   194,    -1,   196,    -1,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,    -1,
      -1,   211,   212,   213,    -1,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,    -1,   259,
     260,   261,    -1,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,    -1,   312,    -1,   314,   315,   316,   317,   318,   319,
     320,     0,     1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    11,    12,    -1,    -1,    -1,    16,    -1,    -1,
      -1,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      -1,    30,    -1,    -1,    33,    34,    -1,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    -1,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    -1,    95,    96,    97,    98,
      99,    -1,   101,   102,   103,    -1,    -1,   106,   107,    -1,
      -1,    -1,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,    -1,    -1,    -1,   125,    -1,   127,   128,
     129,   130,    -1,   132,    -1,    -1,    -1,   136,   137,   138,
     139,   140,    -1,    -1,    -1,    -1,    -1,    -1,   147,   148,
     149,   150,   151,   152,   153,   154,   155,    -1,   157,   158,
     159,   160,   161,    -1,    -1,    -1,   165,   166,   167,   168,
     169,   170,   171,   172,    -1,   174,    -1,   176,   177,    -1,
      -1,   180,   181,   182,    -1,    -1,    -1,   186,    -1,   188,
     189,    -1,   191,   192,    -1,   194,    -1,   196,    -1,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
      -1,    -1,   211,   212,   213,    -1,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,    -1,
     259,   260,   261,    -1,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,   310,     1,   312,    -1,   314,   315,   316,   317,   318,
     319,   320,    11,    12,    -1,    -1,    -1,    16,    -1,    -1,
      -1,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      -1,    30,    -1,    -1,    33,    34,    -1,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    -1,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    -1,    95,    96,    97,    98,
      99,    -1,   101,   102,   103,    -1,    -1,   106,   107,    -1,
      -1,    -1,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,    -1,    -1,    -1,   125,    -1,   127,   128,
     129,   130,    -1,   132,    -1,    -1,    -1,   136,   137,   138,
     139,   140,    -1,    -1,    -1,    -1,    -1,    -1,   147,   148,
     149,   150,   151,   152,   153,   154,   155,    -1,   157,   158,
     159,   160,   161,    -1,    -1,    -1,   165,   166,   167,   168,
     169,   170,   171,   172,    -1,   174,    -1,   176,   177,    -1,
      -1,   180,   181,   182,    -1,    -1,    -1,   186,    -1,   188,
     189,    -1,   191,   192,    -1,   194,    -1,   196,    -1,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
      -1,    -1,   211,   212,   213,    -1,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,    -1,
     259,   260,   261,    -1,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,   310,     1,   312,    -1,   314,   315,   316,   317,   318,
     319,   320,    11,    12,    -1,    -1,    -1,    16,    -1,    -1,
      -1,    20,    21,    22,    23,    24,    25,    26,    -1,    -1,
      -1,    30,    -1,    -1,    33,    34,    -1,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    -1,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    -1,    95,    96,    97,    98,
      99,    -1,   101,   102,   103,    -1,    -1,   106,   107,    -1,
      -1,    -1,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,    -1,    -1,    -1,   125,    -1,   127,   128,
     129,   130,    -1,   132,    -1,    -1,    -1,   136,   137,   138,
     139,   140,    -1,    -1,    -1,    -1,    -1,    -1,   147,   148,
     149,   150,   151,   152,   153,   154,   155,    -1,   157,   158,
     159,   160,   161,    -1,    -1,    -1,   165,   166,   167,   168,
     169,   170,   171,   172,    -1,   174,    -1,   176,   177,    -1,
      -1,   180,   181,   182,    -1,    -1,    -1,   186,    -1,   188,
     189,    -1,   191,   192,    -1,   194,    -1,   196,    -1,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
      -1,    -1,   211,   212,   213,    -1,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,    -1,
     259,   260,   261,    -1,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,   310,    -1,   312,    -1,   314,   315,   316,   317,   318,
     319,   320,     0,     1,    -1,     3,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    42,    -1,    -1,    -1,    46,    -1,
      -1,    -1,    50,    51,    -1,    -1,    -1,    -1,    56,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    67,
      -1,    -1,    70,    -1,    72,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    93,    -1,    95,    96,    97,
      -1,    -1,   100,   101,   102,   103,    -1,    -1,    -1,   107,
     108,    -1,    -1,    -1,    -1,    -1,   114,    -1,    -1,   117,
     118,   119,    -1,    -1,   122,    -1,    -1,    -1,    -1,   127,
     128,    -1,    -1,    -1,    -1,   133,    -1,    -1,    -1,   137,
      -1,    -1,    -1,   141,   142,    -1,   144,    -1,   146,   147,
      -1,    -1,    -1,   151,   152,    -1,    -1,   155,   156,   157,
     158,   159,   160,    -1,    -1,   163,    -1,    -1,    -1,   167,
     168,    -1,    -1,   171,    -1,    -1,    -1,    -1,   176,    -1,
      -1,   179,    -1,    -1,    -1,    -1,   184,   185,   186,   187,
     188,    -1,   190,   191,   192,   193,   194,    -1,    -1,    -1,
      -1,   199,   200,   201,    -1,   203,   204,   205,   206,   207,
     208,    -1,   210,    -1,   212,    -1,    -1,    -1,    -1,   217,
     218,   219,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   233,    -1,   235,    -1,   237,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   249,    -1,    -1,    -1,    -1,   254,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    11,    12,    -1,    -1,    -1,
      16,    -1,    -1,    -1,    20,    21,    22,    23,    24,    25,
      26,    27,    28,   311,    30,   313,    -1,    33,    34,    -1,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    -1,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    -1,    95,
      96,    97,    98,    99,    -1,   101,   102,   103,    -1,    -1,
     106,   107,    -1,    -1,    -1,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,    -1,    -1,    -1,   125,
      -1,   127,   128,   129,   130,    -1,   132,    -1,    -1,    -1,
     136,   137,   138,   139,   140,    -1,    -1,    -1,    -1,    -1,
      -1,   147,   148,   149,   150,   151,   152,   153,   154,   155,
      -1,   157,   158,   159,   160,   161,    -1,    -1,    -1,   165,
     166,   167,   168,   169,   170,   171,   172,    -1,   174,    -1,
     176,   177,    -1,    -1,   180,   181,   182,    -1,    -1,    -1,
     186,    -1,   188,   189,    -1,   191,   192,    -1,   194,    -1,
     196,    -1,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,    -1,    -1,   211,   212,   213,    -1,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,    -1,   259,   260,   261,    -1,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,    -1,   312,    -1,   314,   315,
     316,   317,   318,   319,   320,   321,   322,    11,    12,    -1,
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
     114,   115,   116,   117,   118,   119,   120,   121,    -1,    -1,
      -1,   125,    -1,   127,   128,   129,   130,    -1,   132,    -1,
      -1,    -1,   136,   137,   138,   139,   140,    -1,    -1,    -1,
      -1,    -1,    -1,   147,   148,   149,   150,   151,   152,   153,
     154,   155,    -1,   157,   158,   159,   160,   161,    -1,    -1,
      -1,   165,   166,   167,   168,   169,   170,   171,   172,    -1,
     174,    -1,   176,   177,    -1,    -1,   180,   181,   182,    -1,
      -1,    -1,   186,    -1,   188,   189,    -1,   191,   192,    -1,
     194,    -1,   196,    -1,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,    -1,    -1,   211,   212,   213,
      -1,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,    -1,   259,   260,   261,    -1,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,    -1,   312,    -1,
     314,   315,   316,   317,   318,   319,   320,    -1,   322,    11,
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
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
      -1,    -1,    -1,   125,    -1,   127,   128,   129,   130,    -1,
     132,    -1,    -1,    -1,   136,   137,   138,   139,   140,    -1,
      -1,    -1,    -1,    -1,    -1,   147,   148,   149,   150,   151,
     152,   153,   154,   155,    -1,   157,   158,   159,   160,   161,
      -1,    -1,    -1,   165,   166,   167,   168,   169,   170,   171,
     172,    -1,   174,    -1,   176,   177,    -1,    -1,   180,   181,
     182,    -1,   184,    -1,   186,    -1,   188,   189,    -1,   191,
     192,    -1,   194,    -1,   196,    -1,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,    -1,    -1,   211,
     212,   213,    -1,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,    -1,   259,   260,   261,
      -1,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,    -1,
     312,    -1,   314,   315,   316,   317,   318,   319,   320,    11,
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
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
      -1,    -1,    -1,   125,    -1,   127,   128,   129,   130,    -1,
     132,    -1,    -1,    -1,   136,   137,   138,   139,   140,    -1,
      -1,    -1,    -1,    -1,    -1,   147,   148,   149,   150,   151,
     152,   153,   154,   155,    -1,   157,   158,   159,   160,   161,
      -1,    -1,    -1,   165,   166,   167,   168,   169,   170,   171,
     172,    -1,   174,    -1,   176,   177,    -1,    -1,   180,   181,
     182,    -1,   184,    -1,   186,    -1,   188,   189,    -1,   191,
     192,    -1,   194,    -1,   196,    -1,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,    -1,    -1,   211,
     212,   213,    -1,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,    -1,   259,   260,   261,
      -1,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,    -1,
     312,    -1,   314,   315,   316,   317,   318,   319,   320,    11,
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
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
      -1,    -1,    -1,   125,    -1,   127,   128,   129,   130,    -1,
     132,    -1,    -1,    -1,   136,   137,   138,   139,   140,    -1,
      -1,    -1,    -1,    -1,    -1,   147,   148,   149,   150,   151,
     152,   153,   154,   155,    -1,   157,   158,   159,   160,   161,
      -1,    -1,    -1,   165,   166,   167,   168,   169,   170,   171,
     172,    -1,   174,    -1,   176,   177,    -1,    -1,   180,   181,
     182,    -1,   184,    -1,   186,    -1,   188,   189,    -1,   191,
     192,    -1,   194,    -1,   196,    -1,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,    -1,    -1,   211,
     212,   213,    -1,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,    -1,   259,   260,   261,
      -1,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,    -1,
     312,    -1,   314,   315,   316,   317,   318,   319,   320,    11,
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
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
      -1,    -1,    -1,   125,    -1,   127,   128,   129,   130,    -1,
     132,    -1,    -1,    -1,   136,   137,   138,   139,   140,    -1,
      -1,    -1,    -1,    -1,    -1,   147,   148,   149,   150,   151,
     152,   153,   154,   155,    -1,   157,   158,   159,   160,   161,
      -1,    -1,    -1,   165,   166,   167,   168,   169,   170,   171,
     172,    -1,   174,    -1,   176,   177,    -1,    -1,   180,   181,
     182,    -1,    -1,    -1,   186,    -1,   188,   189,    -1,   191,
     192,    -1,   194,    -1,   196,    -1,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,    -1,    -1,   211,
     212,   213,    -1,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,    -1,   259,   260,   261,
      -1,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,    -1,
     312,    -1,   314,   315,   316,   317,   318,   319,   320,    11,
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
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
      -1,    -1,    -1,   125,    -1,   127,   128,   129,   130,    -1,
     132,    -1,    -1,    -1,   136,   137,   138,   139,   140,    -1,
      -1,    -1,    -1,    -1,    -1,   147,   148,   149,   150,   151,
     152,   153,   154,   155,    -1,   157,   158,   159,   160,   161,
      -1,    -1,    -1,   165,   166,   167,   168,   169,   170,   171,
     172,    -1,   174,    -1,   176,   177,    -1,    -1,   180,   181,
     182,    -1,    -1,    -1,   186,    -1,   188,   189,    -1,   191,
     192,    -1,   194,    -1,   196,    -1,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,    -1,    -1,   211,
     212,   213,    -1,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,    -1,   259,   260,   261,
      -1,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,    -1,
     312,    -1,   314,   315,   316,   317,   318,   319,   320,    11,
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
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
      -1,    -1,    -1,   125,    -1,   127,   128,   129,   130,    -1,
     132,    -1,    -1,    -1,   136,   137,   138,   139,   140,    -1,
      -1,    -1,    -1,    -1,    -1,   147,   148,   149,   150,   151,
     152,   153,   154,   155,    -1,   157,   158,   159,   160,   161,
      -1,    -1,    -1,   165,   166,   167,   168,   169,   170,   171,
     172,    -1,   174,    -1,   176,   177,    -1,    -1,   180,   181,
     182,    -1,    -1,    -1,   186,    -1,   188,   189,    -1,   191,
     192,    -1,   194,    -1,   196,    -1,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,    -1,    -1,   211,
     212,   213,    -1,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,    -1,   259,   260,   261,
      -1,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,    -1,
     312,    -1,   314,   315,   316,   317,   318,   319,   320,    11,
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
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
      -1,    -1,    -1,   125,    -1,   127,   128,   129,   130,    -1,
     132,    -1,    -1,    -1,   136,   137,   138,   139,   140,    -1,
      -1,    -1,    -1,    -1,    -1,   147,   148,   149,   150,   151,
     152,   153,   154,   155,    -1,   157,   158,   159,   160,   161,
      -1,    -1,    -1,   165,   166,   167,   168,   169,   170,   171,
     172,    -1,   174,    -1,   176,   177,    -1,    -1,   180,   181,
     182,    -1,    -1,    -1,   186,    -1,   188,   189,    -1,   191,
     192,    -1,   194,    -1,   196,    -1,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,    -1,    -1,   211,
     212,   213,    -1,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,    -1,   259,   260,   261,
      -1,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,    -1,
     312,    -1,   314,   315,   316,   317,   318,   319,   320,    11,
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
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
      -1,    -1,    -1,   125,    -1,   127,   128,   129,   130,    -1,
     132,    -1,    -1,    -1,   136,   137,   138,   139,   140,    -1,
      -1,    -1,    -1,    -1,    -1,   147,   148,   149,   150,   151,
     152,   153,   154,   155,    -1,   157,   158,   159,   160,   161,
      -1,    -1,    -1,   165,   166,   167,   168,   169,   170,   171,
     172,    -1,   174,    -1,   176,   177,    -1,    -1,   180,   181,
     182,    -1,    -1,    -1,   186,    -1,   188,   189,    -1,   191,
     192,    -1,   194,    -1,   196,    -1,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,    -1,    -1,   211,
     212,   213,    -1,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,    -1,   259,   260,   261,
      -1,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,    -1,
     312,    -1,   314,   315,   316,   317,   318,   319,   320,    11,
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
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
      -1,    -1,    -1,   125,    -1,   127,   128,   129,   130,    -1,
     132,    -1,    -1,    -1,   136,   137,   138,   139,   140,    -1,
      -1,    -1,    -1,   145,    -1,   147,   148,   149,   150,   151,
     152,   153,   154,   155,    -1,   157,   158,   159,   160,   161,
      -1,    -1,    -1,   165,   166,   167,   168,   169,   170,   171,
     172,    -1,   174,    -1,   176,   177,    -1,    -1,   180,   181,
     182,    -1,    -1,    -1,   186,   187,   188,   189,    -1,   191,
     192,    -1,   194,    -1,   196,    -1,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,    -1,    -1,   211,
     212,   213,    -1,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,    -1,   259,   260,   261,
      -1,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,    -1,
     312,    -1,   314,   315,   316,   317,   318,   319,   320,    11,
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
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
      -1,    -1,    -1,   125,    -1,   127,   128,   129,   130,    -1,
     132,    -1,    -1,    -1,   136,   137,   138,   139,   140,    -1,
      -1,    -1,    -1,   145,    -1,   147,   148,   149,   150,   151,
     152,   153,   154,   155,    -1,   157,   158,   159,   160,   161,
      -1,    -1,    -1,   165,   166,   167,   168,   169,   170,   171,
     172,    -1,   174,    -1,   176,   177,    -1,    -1,   180,   181,
     182,    -1,    -1,    -1,   186,   187,   188,   189,    -1,   191,
     192,    -1,   194,    -1,   196,    -1,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,    -1,    -1,   211,
     212,   213,    -1,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,    -1,   259,   260,   261,
      -1,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,    -1,
     312,    -1,   314,   315,   316,   317,   318,   319,   320,    11,
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
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
      -1,    -1,    -1,   125,    -1,   127,   128,   129,   130,    -1,
     132,    -1,    -1,    -1,   136,   137,   138,   139,   140,    -1,
      -1,    -1,    -1,    -1,    -1,   147,   148,   149,   150,   151,
     152,   153,   154,   155,    -1,   157,   158,   159,   160,   161,
      -1,    -1,    -1,   165,   166,   167,   168,   169,   170,   171,
     172,    -1,   174,    -1,   176,   177,    -1,    -1,   180,   181,
     182,    -1,    -1,    -1,   186,    -1,   188,   189,    -1,   191,
     192,    -1,   194,    -1,   196,    -1,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,    -1,    -1,   211,
     212,   213,    -1,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,    -1,   259,   260,   261,
      -1,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,    -1,
     312,    -1,   314,   315,   316,   317,   318,   319,   320,    11,
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
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
      -1,    -1,    -1,   125,    -1,   127,   128,   129,   130,    -1,
     132,    -1,    -1,    -1,   136,   137,   138,   139,   140,    -1,
      -1,    -1,    -1,    -1,    -1,   147,   148,   149,   150,   151,
     152,   153,   154,   155,    -1,   157,   158,   159,   160,   161,
      -1,    -1,    -1,   165,   166,   167,   168,   169,   170,   171,
     172,    -1,   174,    -1,   176,   177,    -1,    -1,   180,   181,
     182,    -1,    -1,   185,   186,    -1,   188,   189,    -1,   191,
     192,    -1,   194,    -1,   196,    -1,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,    -1,    -1,   211,
     212,   213,    -1,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,    -1,   259,   260,   261,
      -1,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,    -1,
     312,    -1,   314,   315,   316,   317,   318,   319,   320,    11,
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
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
      -1,    -1,    -1,   125,    -1,   127,   128,   129,   130,    -1,
     132,    -1,    -1,    -1,   136,   137,   138,   139,   140,    -1,
      -1,    -1,    -1,    -1,    -1,   147,   148,   149,   150,   151,
     152,   153,   154,   155,    -1,   157,   158,   159,   160,   161,
      -1,    -1,    -1,   165,   166,   167,   168,   169,   170,   171,
     172,    -1,   174,    -1,   176,   177,    -1,    -1,   180,   181,
     182,    -1,    -1,    -1,   186,   187,   188,   189,    -1,   191,
     192,    -1,   194,    -1,   196,    -1,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,    -1,    -1,   211,
     212,   213,    -1,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,    -1,   259,   260,   261,
      -1,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,    -1,
     312,    -1,   314,   315,   316,   317,   318,   319,   320,    11,
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
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
      -1,    -1,    -1,   125,    -1,   127,   128,   129,   130,    -1,
     132,    -1,    -1,    -1,   136,   137,   138,   139,   140,    -1,
      -1,    -1,    -1,    -1,    -1,   147,   148,   149,   150,   151,
     152,   153,   154,   155,    -1,   157,   158,   159,   160,   161,
      -1,    -1,    -1,   165,   166,   167,   168,   169,   170,   171,
     172,    -1,   174,    -1,   176,   177,    -1,    -1,   180,   181,
     182,    -1,    -1,    -1,   186,    -1,   188,   189,    -1,   191,
     192,    -1,   194,    -1,   196,    -1,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,    -1,    -1,   211,
     212,   213,    -1,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,    -1,   259,   260,   261,
      -1,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   311,
     312,    -1,   314,   315,   316,   317,   318,   319,   320,    11,
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
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
      -1,    -1,    -1,   125,    -1,   127,   128,   129,   130,    -1,
     132,    -1,    -1,    -1,   136,   137,   138,   139,   140,    -1,
      -1,    -1,    -1,    -1,    -1,   147,   148,   149,   150,   151,
     152,   153,   154,   155,    -1,   157,   158,   159,   160,   161,
      -1,    -1,    -1,   165,   166,   167,   168,   169,   170,   171,
     172,    -1,   174,    -1,   176,   177,    -1,    -1,   180,   181,
     182,    -1,    -1,    -1,   186,    -1,   188,   189,    -1,   191,
     192,    -1,   194,    -1,   196,    -1,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,    -1,    -1,   211,
     212,   213,    -1,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,    -1,   259,   260,   261,
      -1,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,    -1,
     312,   313,   314,   315,   316,   317,   318,   319,   320,    11,
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
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
      -1,    -1,    -1,   125,    -1,   127,   128,   129,   130,    -1,
     132,    -1,    -1,    -1,   136,   137,   138,   139,   140,    -1,
      -1,    -1,    -1,    -1,    -1,   147,   148,   149,   150,   151,
     152,   153,   154,   155,    -1,   157,   158,   159,   160,   161,
      -1,    -1,    -1,   165,   166,   167,   168,   169,   170,   171,
     172,    -1,   174,    -1,   176,   177,    -1,    -1,   180,   181,
     182,    -1,   184,    -1,   186,    -1,   188,   189,    -1,   191,
     192,    -1,   194,    -1,   196,    -1,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,    -1,    -1,   211,
     212,   213,    -1,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,    -1,   259,   260,   261,
      -1,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,    -1,
     312,    -1,   314,   315,   316,   317,   318,   319,   320,    11,
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
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
      -1,    -1,    -1,   125,    -1,   127,   128,   129,   130,    -1,
     132,    -1,    -1,    -1,   136,   137,   138,   139,   140,    -1,
      -1,    -1,    -1,   145,    -1,   147,   148,   149,   150,   151,
     152,   153,   154,   155,    -1,   157,   158,   159,   160,   161,
      -1,    -1,    -1,   165,   166,   167,   168,   169,   170,   171,
     172,    -1,   174,    -1,   176,   177,    -1,    -1,   180,   181,
     182,    -1,    -1,    -1,   186,    -1,   188,   189,    -1,   191,
     192,    -1,   194,    -1,   196,    -1,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,    -1,    -1,   211,
     212,   213,    -1,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,    -1,   259,   260,   261,
      -1,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,    -1,
     312,    -1,   314,   315,   316,   317,   318,   319,   320,    11,
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
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
      -1,    -1,    -1,   125,    -1,   127,   128,   129,   130,    -1,
     132,    -1,    -1,    -1,   136,   137,   138,   139,   140,    -1,
      -1,    -1,    -1,    -1,    -1,   147,   148,   149,   150,   151,
     152,   153,   154,   155,    -1,   157,   158,   159,   160,   161,
      -1,    -1,    -1,   165,   166,   167,   168,   169,   170,   171,
     172,    -1,   174,    -1,   176,   177,    -1,    -1,   180,   181,
     182,    -1,    -1,    -1,   186,    -1,   188,   189,    -1,   191,
     192,    -1,   194,    -1,   196,    -1,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,    -1,    -1,   211,
     212,   213,    -1,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,    -1,   259,   260,   261,
      -1,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,    -1,
     312,    -1,   314,   315,   316,   317,   318,   319,   320,    11,
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
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
      -1,    -1,    -1,   125,    -1,   127,   128,   129,   130,    -1,
     132,    -1,    -1,    -1,   136,   137,   138,   139,   140,    -1,
      -1,    -1,    -1,    -1,    -1,   147,   148,   149,   150,   151,
     152,   153,   154,   155,    -1,   157,   158,   159,   160,   161,
      -1,    -1,    -1,   165,   166,   167,   168,   169,   170,   171,
     172,    -1,   174,    -1,   176,   177,    -1,    -1,   180,   181,
     182,    -1,    -1,    -1,   186,    -1,   188,   189,    -1,   191,
     192,    -1,   194,    -1,   196,    -1,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,    -1,    -1,   211,
     212,   213,    -1,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,    -1,   259,   260,   261,
      -1,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,    -1,
     312,    -1,   314,   315,   316,   317,   318,   319,   320,    11,
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
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
      -1,    -1,    -1,   125,    -1,   127,   128,   129,   130,    -1,
     132,    -1,    -1,    -1,   136,   137,   138,   139,   140,    -1,
      -1,    -1,    -1,    -1,    -1,   147,   148,   149,   150,   151,
     152,   153,   154,   155,    -1,   157,   158,   159,   160,   161,
      -1,    -1,    -1,   165,   166,   167,   168,   169,   170,   171,
     172,    -1,   174,    -1,   176,   177,    -1,    -1,   180,   181,
     182,    -1,    -1,    -1,   186,    -1,   188,   189,    -1,   191,
     192,    -1,   194,    -1,   196,    -1,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,    -1,    -1,   211,
     212,   213,    -1,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,    -1,   259,   260,   261,
      -1,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,    -1,
     312,    -1,   314,   315,   316,   317,   318,   319,   320,    11,
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
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
      -1,    -1,    -1,   125,    -1,   127,   128,   129,   130,    -1,
     132,    -1,    -1,    -1,   136,   137,   138,   139,   140,    -1,
      -1,    -1,    -1,    -1,    -1,   147,   148,   149,   150,   151,
     152,   153,   154,   155,    -1,   157,   158,   159,   160,   161,
      -1,    -1,    -1,   165,   166,   167,   168,   169,   170,   171,
     172,    -1,   174,    -1,   176,   177,    -1,    -1,   180,   181,
     182,    -1,    -1,    -1,   186,    -1,   188,   189,    -1,   191,
     192,    -1,   194,    -1,   196,    -1,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,    -1,    -1,   211,
     212,   213,    -1,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,    -1,   259,   260,   261,
      -1,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,    -1,
     312,    -1,   314,   315,   316,   317,   318,   319,   320,    11,
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
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
      -1,    -1,    -1,   125,    -1,   127,   128,   129,   130,    -1,
     132,    -1,    -1,    -1,   136,   137,   138,   139,   140,    -1,
      -1,    -1,    -1,    -1,    -1,   147,   148,   149,   150,   151,
     152,   153,   154,   155,    -1,   157,   158,    -1,   160,   161,
      -1,    -1,    -1,   165,   166,   167,   168,   169,   170,   171,
     172,    -1,   174,    -1,    -1,    -1,    -1,    -1,   180,   181,
     182,    -1,    -1,    -1,   186,    -1,   188,   189,    -1,   191,
     192,    -1,   194,    -1,   196,    -1,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,    -1,    -1,   211,
     212,   213,    -1,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,    -1,   259,   260,   261,
      -1,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,    -1,
     312,    -1,   314,   315,   316,   317,   318,   319,   320,    11,
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
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
      -1,    -1,    -1,   125,    -1,   127,   128,   129,   130,    -1,
     132,    -1,    -1,    -1,   136,   137,   138,   139,   140,    -1,
      -1,    -1,    -1,    -1,    -1,   147,   148,   149,   150,   151,
     152,   153,   154,   155,    -1,   157,   158,    -1,   160,   161,
      -1,    -1,    -1,   165,   166,   167,   168,   169,   170,   171,
     172,    -1,   174,    -1,    -1,    -1,    -1,    -1,   180,   181,
     182,    -1,    -1,    -1,   186,    -1,   188,   189,    -1,    -1,
      -1,    -1,   194,    -1,   196,    -1,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,    -1,    -1,   211,
     212,   213,    -1,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,    -1,   259,   260,   261,
      -1,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,    -1,
     312,    -1,   314,   315,   316,   317,   318,   319,   320,    11,
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
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
      -1,    -1,    -1,   125,    -1,   127,   128,   129,   130,    -1,
     132,    -1,    -1,    -1,   136,    -1,   138,   139,   140,    -1,
      -1,    -1,    -1,    -1,    -1,   147,   148,   149,   150,    -1,
     152,   153,   154,   155,    -1,   157,   158,    -1,   160,   161,
      -1,    -1,    -1,   165,   166,   167,   168,   169,   170,   171,
     172,    -1,   174,    -1,    -1,    -1,    -1,    -1,   180,   181,
     182,    -1,    -1,    -1,   186,    -1,   188,   189,    -1,    -1,
      -1,    -1,   194,    -1,   196,    -1,   198,    -1,   200,    -1,
     202,   203,   204,   205,   206,   207,   208,    -1,    -1,   211,
     212,   213,    -1,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,    -1,   259,   260,   261,
      -1,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,    -1,
     312,    -1,   314,   315,   316,   317,   318,   319,   320,    11,
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
      -1,    -1,    -1,    -1,    -1,   127,   128,   129,   130,    -1,
     132,    -1,    -1,    -1,   136,   137,   138,   139,   140,    -1,
      -1,    -1,    -1,    -1,    -1,   147,   148,   149,    -1,   151,
     152,   153,    -1,    -1,    -1,    -1,    -1,    -1,   160,   161,
      -1,    -1,    -1,   165,   166,   167,   168,   169,   170,   171,
     172,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   180,   181,
     182,    -1,    -1,    -1,   186,    -1,   188,   189,    -1,    -1,
      -1,    -1,   194,    -1,   196,    -1,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,    -1,    -1,   211,
     212,    -1,    -1,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,    -1,   259,   260,   261,
      -1,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,    -1,    -1,
      -1,    -1,   314,   315,   316,   317,   318,   319,   320,    11,
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
      -1,    -1,    -1,    -1,    -1,   127,   128,   129,   130,    -1,
     132,    -1,    -1,    -1,   136,   137,   138,   139,   140,    -1,
      -1,    -1,    -1,    -1,    -1,   147,   148,   149,    -1,   151,
     152,   153,    -1,    -1,    -1,    -1,    -1,    -1,   160,   161,
      -1,    -1,    -1,   165,   166,   167,   168,   169,   170,   171,
     172,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   180,   181,
     182,    -1,    -1,    -1,   186,    -1,   188,   189,    -1,    -1,
      -1,    -1,   194,    -1,   196,    -1,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,    -1,    -1,   211,
     212,    -1,    -1,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,    -1,   259,   260,   261,
      -1,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,    -1,    -1,
      16,    -1,   314,   315,   316,   317,   318,   319,   320,    25,
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
      -1,   127,   128,   129,   130,    -1,   132,    -1,    -1,    -1,
     136,   137,   138,   139,   140,    -1,    -1,    -1,    -1,    -1,
      -1,   147,   148,   149,    -1,   151,   152,   153,    -1,    -1,
      -1,   157,    -1,    -1,   160,   161,    -1,    -1,    -1,   165,
     166,   167,   168,   169,   170,   171,   172,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   180,   181,   182,    -1,    -1,    -1,
     186,   187,   188,   189,    -1,    -1,    -1,    -1,   194,    -1,
     196,    -1,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,    -1,    -1,   211,   212,    -1,    -1,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,    -1,   259,   260,   261,    -1,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,    -1,    -1,    -1,    -1,   314,   315,
     316,   317,   318,   319,   320,    16,    -1,    18,    19,    -1,
      -1,    -1,    -1,    -1,    25,    26,    -1,    -1,    -1,    -1,
      -1,    -1,    33,    34,    -1,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    -1,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    -1,    95,    96,    97,    98,    -1,    -1,
     101,   102,   103,    -1,    -1,   106,   107,    -1,    -1,    -1,
      -1,   112,   113,   114,   115,   116,   117,   118,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   127,   128,   129,   130,
      -1,   132,    -1,    -1,    -1,   136,   137,   138,   139,   140,
      -1,    -1,    -1,    -1,    -1,    -1,   147,   148,   149,    -1,
     151,   152,   153,    -1,    -1,    -1,    -1,    -1,    -1,   160,
     161,    -1,    -1,    -1,   165,   166,   167,   168,   169,   170,
     171,   172,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   180,
     181,   182,    -1,    -1,    -1,   186,    -1,   188,   189,    -1,
      -1,    -1,    -1,    -1,    -1,   196,    -1,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,    -1,    -1,
     211,   212,    -1,    -1,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,    -1,   259,   260,
     261,    -1,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,   309,    -1,
      -1,    16,    -1,   314,   315,   316,   317,   318,   319,   320,
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
      -1,    -1,   127,   128,   129,   130,    -1,   132,    -1,    -1,
      -1,   136,   137,   138,   139,   140,    -1,    -1,    -1,    -1,
      -1,    -1,   147,   148,   149,    -1,   151,   152,   153,    -1,
      -1,    -1,    -1,    -1,    -1,   160,   161,    -1,    -1,    -1,
     165,   166,   167,   168,   169,   170,   171,   172,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   180,   181,   182,    -1,    -1,
      -1,   186,   187,   188,   189,    -1,    -1,    -1,    -1,   194,
      -1,   196,    -1,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,    -1,    -1,   211,   212,    -1,    -1,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,    -1,   259,   260,   261,    -1,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,    -1,    -1,    16,    -1,   314,
     315,   316,   317,   318,   319,   320,    25,    26,    -1,    -1,
      -1,    30,    -1,    -1,    33,    34,    -1,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    -1,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    -1,    95,    96,    97,    98,
      -1,    -1,   101,   102,   103,    -1,    -1,   106,   107,    -1,
      -1,    -1,    -1,   112,   113,   114,   115,   116,   117,   118,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   127,   128,
     129,   130,    -1,   132,    -1,    -1,    -1,   136,   137,   138,
     139,   140,    -1,    -1,    -1,    -1,    -1,    -1,   147,   148,
     149,    -1,   151,   152,   153,    -1,    -1,    -1,    -1,    -1,
      -1,   160,   161,    -1,    -1,    -1,   165,   166,   167,   168,
     169,   170,   171,   172,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   180,   181,   182,    -1,    -1,    -1,   186,   187,   188,
     189,    -1,    -1,    -1,    -1,    -1,    -1,   196,    -1,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
      -1,    -1,   211,   212,    -1,    -1,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,    -1,
     259,   260,   261,    -1,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,    -1,    -1,    16,    -1,   314,   315,   316,   317,   318,
     319,   320,    25,    26,    -1,    -1,    -1,    -1,    -1,    -1,
      33,    34,    -1,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    -1,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    -1,    95,    96,    97,    98,    -1,    -1,   101,   102,
     103,    -1,    -1,   106,   107,    -1,    -1,    -1,    -1,   112,
     113,   114,   115,   116,   117,   118,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   127,   128,   129,   130,    -1,   132,
      -1,    -1,    -1,   136,   137,   138,   139,   140,    -1,    -1,
      -1,    -1,    -1,    -1,   147,   148,   149,    -1,   151,   152,
     153,    -1,    -1,    -1,    -1,    -1,    -1,   160,   161,    -1,
      -1,    -1,   165,   166,   167,   168,   169,   170,   171,   172,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   180,   181,   182,
      -1,    -1,    -1,   186,   187,   188,   189,    -1,    -1,    -1,
      -1,   194,    -1,   196,    -1,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,    -1,    -1,   211,   212,
      -1,    -1,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,    -1,   259,   260,   261,    -1,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,    -1,    -1,    16,
      -1,   314,   315,   316,   317,   318,   319,   320,    25,    26,
      -1,    -1,    -1,    -1,    -1,    -1,    33,    34,    -1,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    -1,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    -1,    95,    96,
      97,    98,    -1,    -1,   101,   102,   103,    -1,    -1,   106,
     107,    -1,    -1,    -1,    -1,   112,   113,   114,   115,   116,
     117,   118,   119,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     127,   128,   129,   130,    -1,   132,    -1,    -1,    -1,   136,
     137,   138,   139,   140,    -1,    -1,    -1,    -1,    -1,    -1,
     147,   148,   149,    -1,   151,   152,   153,    -1,    -1,    -1,
     157,    -1,    -1,   160,   161,    -1,    -1,    -1,   165,   166,
     167,   168,   169,   170,   171,   172,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   180,   181,   182,    -1,    -1,    -1,   186,
      -1,   188,   189,    -1,    -1,    -1,    -1,    -1,    -1,   196,
      -1,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,    -1,    -1,   211,   212,    -1,    -1,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,    -1,   259,   260,   261,    -1,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,   309,    -1,    -1,    16,    -1,   314,   315,   316,
     317,   318,   319,   320,    25,    26,    -1,    -1,    -1,    -1,
      -1,    -1,    33,    34,    -1,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    -1,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    -1,    95,    96,    97,    98,    -1,    -1,
     101,   102,   103,    -1,    -1,   106,   107,    -1,    -1,    -1,
      -1,   112,   113,   114,   115,   116,   117,   118,   119,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   127,   128,   129,   130,
      -1,   132,    -1,    -1,    -1,   136,   137,   138,   139,   140,
      -1,    -1,    -1,    -1,    -1,    -1,   147,   148,   149,    -1,
     151,   152,   153,    -1,    -1,    -1,   157,    -1,    -1,   160,
     161,    -1,    -1,    -1,   165,   166,   167,   168,   169,   170,
     171,   172,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   180,
     181,   182,    -1,    -1,    -1,   186,    -1,   188,   189,    -1,
      -1,    -1,    -1,    -1,    -1,   196,    -1,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,    -1,    -1,
     211,   212,    -1,    -1,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,    -1,   259,   260,
     261,    -1,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,   309,    -1,
      -1,    16,    -1,   314,   315,   316,   317,   318,   319,   320,
      25,    26,    -1,    -1,    -1,    -1,    -1,    -1,    33,    34,
      -1,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      -1,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    -1,
      95,    96,    97,    98,    -1,    -1,   101,   102,   103,    -1,
      -1,   106,   107,    -1,    -1,    -1,    -1,   112,   113,   114,
     115,   116,   117,   118,   119,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   127,   128,   129,   130,    -1,   132,    -1,    -1,
      -1,   136,   137,   138,   139,   140,    -1,    -1,    -1,    -1,
      -1,    -1,   147,   148,   149,    -1,   151,   152,   153,    -1,
      -1,    -1,   157,    -1,    -1,   160,   161,    -1,    -1,    -1,
     165,   166,   167,   168,   169,   170,   171,   172,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   180,   181,   182,    -1,    -1,
      -1,   186,    -1,   188,   189,    -1,    -1,    -1,    -1,    -1,
      -1,   196,    -1,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,    -1,    -1,   211,   212,    -1,    -1,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,    -1,   259,   260,   261,    -1,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,    -1,    -1,    16,    -1,   314,
     315,   316,   317,   318,   319,   320,    25,    26,    -1,    -1,
      -1,    -1,    -1,    -1,    33,    34,    -1,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    -1,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    -1,    95,    96,    97,    98,
      -1,    -1,   101,   102,   103,    -1,    -1,   106,   107,    -1,
      -1,    -1,    -1,   112,   113,   114,   115,   116,   117,   118,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   127,   128,
     129,   130,    -1,   132,    -1,    -1,    -1,   136,   137,   138,
     139,   140,    -1,    -1,    -1,    -1,    -1,    -1,   147,   148,
     149,    -1,   151,   152,   153,    -1,    -1,    -1,   157,    -1,
      -1,   160,   161,    -1,    -1,    -1,   165,   166,   167,   168,
     169,   170,   171,   172,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   180,   181,   182,    -1,    -1,    -1,   186,    -1,   188,
     189,    -1,    -1,    -1,    -1,    -1,    -1,   196,    -1,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
      -1,    -1,   211,   212,    -1,    -1,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,    -1,
     259,   260,   261,    -1,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,    -1,    -1,    16,    -1,   314,   315,   316,   317,   318,
     319,   320,    25,    26,    -1,    -1,    -1,    -1,    -1,    -1,
      33,    34,    -1,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    -1,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    -1,    95,    96,    97,    98,    -1,    -1,   101,   102,
     103,    -1,    -1,   106,   107,    -1,    -1,    -1,    -1,   112,
     113,   114,   115,   116,   117,   118,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   127,   128,   129,   130,    -1,   132,
      -1,    -1,    -1,   136,   137,   138,   139,   140,    -1,    -1,
      -1,    -1,    -1,    -1,   147,   148,   149,    -1,   151,   152,
     153,    -1,    -1,    -1,   157,    -1,    -1,   160,   161,    -1,
      -1,    -1,   165,   166,   167,   168,   169,   170,   171,   172,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   180,   181,   182,
      -1,    -1,    -1,   186,    -1,   188,   189,    -1,    -1,    -1,
      -1,    -1,    -1,   196,    -1,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,    -1,    -1,   211,   212,
      -1,    -1,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,    -1,   259,   260,   261,    -1,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,    -1,    -1,    16,
      -1,   314,   315,   316,   317,   318,   319,   320,    25,    26,
      -1,    -1,    -1,    -1,    -1,    -1,    33,    34,    -1,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    -1,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    -1,    95,    96,
      97,    98,    -1,    -1,   101,   102,   103,    -1,    -1,   106,
     107,    -1,    -1,    -1,    -1,   112,   113,   114,   115,   116,
     117,   118,   119,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     127,   128,   129,   130,    -1,   132,    -1,    -1,    -1,   136,
     137,   138,   139,   140,    -1,    -1,    -1,    -1,    -1,    -1,
     147,   148,   149,    -1,   151,   152,   153,    -1,    -1,    -1,
      -1,    -1,    -1,   160,   161,    -1,    -1,    -1,   165,   166,
     167,   168,   169,   170,   171,   172,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   180,   181,   182,    -1,    -1,    -1,   186,
      -1,   188,   189,    -1,    -1,    -1,    -1,    -1,    -1,   196,
      -1,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,    -1,    -1,   211,   212,    -1,    -1,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,    -1,   259,   260,   261,    -1,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,   309,    -1,    -1,    16,    -1,   314,   315,   316,
     317,   318,   319,   320,    25,    26,    -1,    -1,    -1,    -1,
      -1,    -1,    33,    34,    -1,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    -1,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    -1,    95,    96,    97,    98,    -1,    -1,
     101,   102,   103,    -1,    -1,   106,   107,    -1,    -1,    -1,
      -1,   112,   113,   114,   115,   116,   117,   118,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   127,   128,   129,   130,
      -1,   132,    -1,    -1,    -1,   136,   137,   138,   139,   140,
      -1,    -1,    -1,    -1,    -1,    -1,   147,   148,   149,    -1,
     151,   152,   153,    -1,    -1,    -1,    -1,    -1,    -1,   160,
     161,    -1,    -1,    -1,   165,   166,   167,   168,   169,   170,
     171,   172,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   180,
     181,   182,    -1,    -1,    -1,   186,    -1,   188,   189,    -1,
      -1,    -1,    -1,    -1,    -1,   196,    -1,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,    -1,    -1,
     211,   212,    -1,    -1,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,    -1,   259,   260,
     261,    -1,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,   309,    -1,
      -1,    -1,    -1,   314,   315,   316,   317,   318,   319,   320,
      21,    22,    23,    24,    25,    26,    -1,    -1,    -1,    30,
      -1,    -1,    33,    34,    -1,    36,    37,    38,    39,    40,
      41,    42,    43,    -1,    45,    46,    47,    -1,    49,    50,
      51,    52,    -1,    54,    -1,    56,    57,    58,    59,    60,
      61,    -1,    -1,    64,    65,    66,    67,    68,    -1,    70,
      71,    72,    -1,    -1,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    -1,    95,    96,    97,    98,    -1,    -1,
     101,   102,   103,    -1,    -1,   106,   107,    -1,    -1,    -1,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
      -1,    -1,    -1,    -1,   125,    -1,   127,   128,   129,   130,
      -1,   132,    -1,    -1,    -1,   136,   137,   138,   139,   140,
      -1,    -1,    -1,    -1,    -1,    -1,   147,   148,   149,   150,
     151,   152,    -1,   154,   155,    -1,   157,   158,    -1,   160,
     161,    -1,    -1,    -1,   165,   166,   167,   168,   169,   170,
     171,   172,    -1,   174,    -1,    -1,    -1,    -1,    -1,   180,
     181,   182,    -1,    -1,    -1,   186,    -1,   188,   189,    -1,
      -1,    -1,    -1,    -1,    -1,   196,    -1,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,    -1,    -1,
      -1,   212,   213,    -1,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,    -1,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,    -1,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,    -1,   259,   260,
     261,    -1,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,   309,   310,
      -1,   312,    -1,   314,   315,   316,   317,   318,   319,   320,
      25,    26,    -1,    -1,    -1,    -1,    -1,    -1,    33,    34,
      -1,    36,    37,    38,    -1,    40,    41,    42,    43,    -1,
      -1,    46,    47,    -1,    49,    50,    51,    52,    -1,    54,
      -1,    56,    57,    58,    59,    -1,    61,    -1,    -1,    64,
      65,    66,    67,    68,    -1,    70,    -1,    72,    -1,    -1,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    -1,
      95,    96,    97,    -1,    -1,    -1,   101,   102,   103,    -1,
      -1,   106,   107,    -1,    -1,    -1,    -1,   112,   113,   114,
     115,   116,   117,   118,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   127,   128,   129,   130,    -1,   132,    -1,    -1,
      -1,   136,   137,   138,   139,   140,    -1,    -1,    -1,    -1,
      -1,    -1,   147,   148,   149,    -1,   151,   152,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   160,   161,    -1,    -1,    -1,
     165,   166,   167,   168,   169,   170,   171,   172,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   180,   181,   182,    -1,    -1,
      -1,   186,    -1,   188,   189,    -1,    -1,    -1,    -1,    -1,
      -1,   196,    -1,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,    -1,    -1,    -1,   212,    -1,    -1,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
      -1,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,    -1,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,    -1,   259,   260,   261,    -1,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,    -1,    -1,    -1,    -1,   314,
     315,   316,   317,   318,   319,   320
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned short int
  xquery_parser::yystos_[] =
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
     119,   120,   121,   125,   127,   128,   129,   130,   132,   136,
     137,   138,   139,   140,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   157,   158,   159,   160,   161,   165,   166,
     167,   168,   169,   170,   171,   172,   174,   176,   177,   180,
     181,   182,   186,   188,   189,   191,   192,   194,   196,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     211,   212,   213,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   259,   260,   261,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   312,   314,   315,
     316,   317,   318,   319,   320,   321,   322,   337,   339,   340,
     341,   342,   343,   344,   345,   346,   347,   348,   349,   350,
     351,   352,   353,   354,   355,   358,   359,   360,   361,   362,
     363,   367,   368,   369,   373,   375,   376,   378,   385,   387,
     390,   391,   392,   394,   395,   396,   397,   398,   400,   401,
     403,   404,   405,   406,   407,   408,   410,   411,   414,   415,
     416,   417,   422,   424,   426,   427,   432,   451,   454,   458,
     461,   462,   468,   469,   470,   471,   473,   474,   476,   477,
     478,   479,   480,   481,   482,   483,   484,   486,   487,   488,
     489,   492,   493,   494,   495,   496,   497,   498,   499,   500,
     501,   502,   503,   504,   505,   506,   507,   508,   509,   512,
     513,   514,   515,   516,   517,   518,   519,   520,   522,   523,
     524,   525,   526,   527,   541,   542,   544,   545,   546,   547,
     548,   549,   550,   551,   559,   560,   561,   562,   563,   564,
     565,   566,   567,   568,   569,   570,   573,   578,   579,   580,
     581,   582,   583,   586,   644,   645,   646,   647,   649,   650,
     651,   652,   653,   659,   660,   661,    33,    34,    49,   215,
     393,   394,   395,   393,   393,   394,   395,   157,   157,    37,
      38,    40,    41,    47,    57,    58,    75,    80,   112,   113,
     114,   161,   220,   261,   287,   295,   303,   374,   375,   379,
     380,   381,   161,   154,   157,   154,   157,   154,   157,     1,
       3,    67,    72,   119,   419,   157,   382,   157,    25,    34,
      61,   119,   273,   431,   433,   434,   157,   154,   157,   157,
     157,   119,   154,   157,   157,   157,    77,   154,   221,   222,
     123,   123,   123,   154,   157,    39,    43,    45,    46,    47,
      48,    51,    60,    68,    71,    73,    74,    76,    91,    92,
      98,   106,   113,   115,   116,   136,   139,   140,   161,   169,
     172,   180,   181,   189,   202,   224,   226,   228,   229,   236,
     238,   239,   240,   243,   244,   315,   506,   660,   123,   119,
     402,   123,   123,    39,    44,    45,    53,    60,    62,    63,
      71,    98,   225,   659,   119,   123,   123,   184,   393,   395,
     415,   648,    48,    73,    74,   119,   154,   185,   244,   414,
     416,   426,   187,   414,   659,   154,   154,   123,   659,    18,
      19,   659,   123,   123,   123,   498,   154,    31,   214,   216,
     225,   227,   314,   225,   227,   314,   225,   314,   225,   230,
     314,   119,   241,   241,   242,   157,   154,   397,   311,   414,
     313,   414,   314,   322,   339,   339,     0,   341,   342,    33,
      49,   344,   361,     1,   190,   338,   190,   338,   113,   376,
     396,   414,   108,   190,   108,   338,   190,    42,    46,    51,
      70,   168,   171,   186,   212,   409,   418,   423,   424,   425,
     439,   440,   444,   167,    93,   133,   141,   142,   144,   152,
     156,   158,   163,   179,   203,   204,   205,   206,   207,   208,
     490,   491,   249,   100,   159,   176,   199,   118,   147,   160,
     194,   201,   210,   137,   151,    50,   200,   102,   103,   159,
     176,   488,   193,   154,   495,   498,   191,   192,   155,   510,
     511,   506,   510,   506,   157,   510,   157,   146,   157,   184,
     184,   184,   184,   377,   513,   377,    30,   658,   182,   196,
     182,   196,   166,   182,   660,   659,   169,   202,    47,   659,
     153,   119,    45,    47,    80,   107,   168,   659,   221,   222,
     223,   246,   617,   659,   659,   304,   138,   143,   113,   287,
     295,   379,   659,   394,   187,   394,    45,    63,   187,   569,
     570,   414,   187,   194,   659,   428,   429,   659,   284,   284,
     428,   119,   435,   119,   187,   383,   384,   154,   399,   414,
       1,   161,   658,   114,   161,   357,   658,   659,   119,   143,
     108,   187,   414,    30,   187,   659,   659,   659,   452,   453,
     659,   394,   187,   414,   414,   571,   659,   394,   154,   154,
     414,   187,   194,   659,   659,   143,   452,   184,   184,   122,
     108,   184,   157,   157,   157,   659,   154,   185,   186,   187,
      35,   529,   530,   531,   414,   414,     8,   175,    17,   414,
     214,    30,   415,   415,    39,    45,    60,    71,    98,   509,
     660,   415,   415,   415,   648,   415,   509,   415,   231,   230,
     584,   585,   659,   190,   190,   415,   414,   395,   414,   245,
     412,   413,   311,   313,   415,   339,   190,   338,   190,   338,
       3,   345,   361,   391,     1,   345,   361,   391,    33,   362,
     391,   362,   391,   402,   338,   402,   415,   415,   119,   168,
     170,   170,   396,   415,   415,   470,   471,   473,   473,   473,
     473,   472,   473,   473,   473,    71,   474,   478,   478,   477,
     479,   479,   479,   479,   480,   480,   481,   481,   231,    95,
      95,    95,   496,   184,   414,   498,   498,   414,   511,   145,
     187,   415,   521,   187,   150,   187,   521,   108,   187,   187,
     108,   108,   382,    30,   660,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,   364,   365,   366,    95,   138,
     143,   370,   371,   372,   659,   161,   161,   364,   658,   128,
     133,    55,    57,   101,   251,   264,   266,   277,   278,   279,
     281,   283,   618,   619,   620,   621,   622,   623,   630,   636,
     637,   246,    95,   299,   659,   143,   415,   119,   659,   659,
     133,   184,   184,   187,   187,   184,   108,   187,   108,   187,
     108,    36,    95,    97,   148,   430,   431,   552,   659,    56,
     217,   254,   420,   421,   659,    95,   108,   187,   393,   187,
     659,    97,    45,   659,   658,    97,   143,   552,   659,   415,
     434,   184,   187,   187,   187,   187,   108,   188,   148,   552,
     184,   187,   187,   154,   184,   394,   394,   184,   108,   187,
     108,   187,   143,   552,   415,   188,   415,   415,   414,   414,
     414,   659,   530,   531,   131,   197,   184,   184,   184,   132,
     190,    95,   218,   219,   233,    95,   218,   219,   233,   233,
     233,    95,    95,   237,   225,   231,   108,   235,   143,   190,
     187,   414,   184,   507,   590,   413,   233,   361,    33,    33,
     190,   338,   190,   114,   396,   659,   170,   415,   445,   446,
     119,   415,   441,   442,   473,   154,   157,   259,   494,   513,
     591,   594,   595,   596,   597,   598,   602,   604,   606,   607,
      47,   153,   157,   211,   317,   318,   319,   320,   553,   555,
     557,   559,   574,   575,   576,   577,   654,   655,   656,   657,
     659,   553,   485,   558,   659,   485,   184,   185,   108,   187,
     187,   513,   149,   165,   149,   165,   138,   399,   382,   365,
     133,   555,   372,   415,   552,   658,   658,   129,   130,   658,
     277,   278,   279,   283,   659,   263,   274,   263,   274,    30,
     286,    97,   114,   157,   624,   627,   618,    39,    44,    53,
      60,    62,    71,    98,   225,   317,   318,   319,   386,   559,
     654,   227,   299,   308,   415,   659,    95,   299,   658,   154,
     571,   572,   659,   571,   572,   119,   429,   128,   553,   119,
     415,   148,   431,   148,    36,   148,   430,   431,   148,   552,
     254,    54,    59,    78,   119,   430,   436,   437,   438,   421,
     552,   553,   384,    95,   184,   198,   133,   356,   658,   161,
     133,    97,   356,   415,   143,   431,   154,   119,   415,   415,
     148,   101,   455,   456,   457,   459,   460,   101,   463,   464,
     465,   466,   394,   184,   184,   154,   571,   571,   415,   143,
     190,   415,   122,   187,   187,   187,    35,   531,   131,   197,
       9,    10,   104,   124,   126,   154,   195,   526,   528,   539,
     540,   543,   154,    30,   232,   234,   415,   415,   415,   232,
     234,   415,   415,   415,   415,   415,   415,   415,   415,   415,
     509,   119,   415,   415,    48,    73,    74,   244,   396,   416,
     426,   245,   587,   588,   154,   210,   397,   415,   190,   114,
     391,   391,   391,   445,    96,   107,   117,   128,   447,   448,
     449,   450,   108,   659,   107,   443,   108,   414,   591,   598,
     154,   285,   475,   643,    97,   169,   252,   253,   255,   262,
     272,   284,   592,   593,   612,   613,   614,   615,   638,   641,
     258,   260,   599,   617,   267,   603,   639,   247,   248,   270,
     608,   609,   157,   157,   555,   157,   157,   157,   157,   157,
     145,   176,   194,   554,   145,   145,   415,   138,   399,   573,
     371,   286,    30,    97,   114,   157,   631,    30,   624,   554,
     554,   496,   287,   306,   552,   386,   227,   190,   393,   187,
     187,   145,   187,   187,   429,   148,   430,   659,   415,   148,
     415,   128,   415,   148,   431,   148,   415,   148,   119,   119,
     415,   659,   438,    78,   553,   396,   415,   658,   108,   356,
     415,   143,   393,   453,   415,   415,   114,   456,   457,   101,
     186,   114,   457,   460,   119,   467,   553,   101,   114,   464,
     101,   114,   466,   184,   393,   187,   187,   415,   415,   198,
     463,   133,   195,   528,     7,   394,   659,   195,   539,   394,
     190,   233,   233,   233,   233,    97,   237,   237,   585,   186,
     157,   157,   157,   186,   590,   588,   507,   658,   129,   130,
     449,   450,   450,   446,   143,   443,   552,   658,   442,   184,
     187,   591,   605,   250,   217,   254,   268,   275,   642,    97,
     256,   257,   640,   250,   595,   642,   477,   612,   596,   148,
     282,   600,   601,   640,   286,   611,    79,   610,   187,   194,
     553,   556,   187,   187,   187,   187,   187,   187,   187,    30,
     137,   201,   633,   634,   635,    30,   632,   633,   271,   628,
     108,   625,   170,   659,   257,   496,   184,   415,   148,   415,
     148,   430,   415,   148,   415,   415,   659,   659,   437,   415,
     127,   127,    97,   658,   415,   184,   186,   186,   415,   396,
     415,   186,   186,   659,   186,   210,   119,   467,   119,   186,
     119,   467,   186,   184,   114,   531,   659,   195,   184,   531,
     659,   184,   415,   415,   415,   415,   316,   415,   415,   415,
     414,   414,   414,   154,   589,   450,   415,   143,   184,   479,
      52,   130,   477,   477,   269,   276,   286,   616,   616,   597,
     154,   280,    95,   187,   108,   187,   631,   631,   635,   108,
     187,    30,   629,   640,   626,   627,   187,   388,   389,   496,
     119,   225,   307,   287,   170,   415,   415,   148,   415,    54,
     396,   415,   356,   415,   396,    95,   396,   415,   553,   659,
     186,   659,   415,   659,   186,   396,   119,    94,   183,   532,
     531,   659,   197,   531,   415,   187,   187,   187,   414,   443,
     415,   477,   477,   199,   414,   553,   553,    95,    30,   265,
     108,   108,   450,   552,   659,   119,   225,   659,   388,   415,
     119,   467,    95,   186,    95,   659,     5,   134,   535,   536,
     538,   540,    29,   135,   533,   534,   537,   540,   197,   531,
     197,   198,   463,   184,   443,   477,   184,   553,   627,   389,
     450,   305,   659,   119,   225,   659,   186,   467,   396,   415,
     467,   186,    94,   134,   538,   183,   135,   537,   197,   114,
     415,   305,   659,   119,   396,   415,   186,   186,   119,   293,
     305,   659,   659,   306,   415,   306,   186,   496,   496,   199,
     287,   659,   225,   119,   659,   306,   496
  };

#if YYDEBUG
  /* TOKEN_NUMBER_[YYLEX-NUM] -- Internal symbol number corresponding
     to YYLEX-NUM.  */
  const unsigned short int
  xquery_parser::yytoken_number_[] =
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
     585,   586,   587,   588,   589,   590
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned short int
  xquery_parser::yyr1_[] =
  {
         0,   336,   337,   337,   337,   337,   338,   338,   338,   339,
     339,   339,   339,   340,   340,   341,   341,   341,   341,   341,
     341,   341,   341,   342,   342,   342,   342,   343,   344,   344,
     344,   345,   345,   345,   345,   345,   346,   346,   346,   346,
     346,   346,   346,   346,   347,   347,   348,   349,   350,   350,
     351,   351,   352,   352,   353,   353,   353,   353,   354,   354,
     354,   355,   355,   355,   355,   356,   356,   357,   357,   358,
     358,   358,   358,   359,   360,   360,   361,   361,   361,   362,
     362,   362,   362,   362,   362,   362,   362,   363,   363,   364,
     364,   365,   366,   366,   366,   366,   366,   366,   366,   366,
     366,   366,   367,   368,   369,   370,   370,   371,   371,   371,
     372,   373,   373,   373,   374,   374,   374,   374,   375,   375,
     376,   376,   376,   376,   377,   377,   378,   378,   379,   379,
     380,   380,   381,   381,   382,   382,   382,   382,   383,   383,
     384,   384,   385,   385,   385,   385,   386,   386,   386,   386,
     387,   387,   388,   388,   389,   389,   389,   389,   390,   390,
     390,   390,   391,   392,   392,   392,   393,   393,   393,   394,
     394,   395,   395,   395,   396,   396,   396,   396,   396,   396,
     396,   396,   396,   396,   396,   396,   397,   397,   398,   399,
     400,   401,   401,   401,   402,   402,   402,   402,   403,   404,
     405,   406,   407,   407,   408,   409,   410,   411,   412,   412,
     413,   414,   414,   414,   415,   415,   415,   415,   415,   415,
     416,   416,   416,   416,   416,   416,   416,   416,   416,   416,
     416,   416,   417,   418,   419,   419,   420,   420,   420,   421,
     421,   422,   422,   423,   424,   424,   424,   425,   425,   425,
     425,   425,   426,   426,   427,   427,   427,   428,   428,   428,
     429,   429,   429,   429,   429,   429,   429,   429,   429,   429,
     429,   429,   430,   431,   432,   433,   433,   434,   434,   434,
     434,   435,   435,   436,   436,   436,   437,   437,   437,   438,
     438,   438,   439,   440,   441,   441,   442,   442,   442,   442,
     442,   442,   442,   443,   444,   444,   445,   445,   446,   446,
     447,   447,   447,   447,   447,   447,   447,   448,   448,   449,
     449,   450,   451,   451,   452,   452,   453,   453,   454,   455,
     455,   456,   457,   457,   458,   459,   459,   460,   461,   461,
     462,   462,   463,   463,   464,   464,   465,   465,   466,   466,
     467,   467,   468,   469,   469,   470,   470,   471,   471,   471,
     471,   471,   472,   471,   471,   471,   471,   473,   473,   474,
     474,   475,   475,   476,   476,   477,   477,   477,   478,   478,
     478,   478,   478,   479,   479,   479,   480,   480,   480,   481,
     481,   482,   482,   483,   483,   484,   484,   485,   485,   486,
     486,   487,   487,   487,   487,   488,   488,   488,   489,   489,
     490,   490,   490,   490,   490,   490,   491,   491,   491,   492,
     492,   492,   492,   493,   493,   494,   494,   495,   495,   495,
     496,   496,   496,   496,   497,   498,   498,   498,   499,   499,
     500,   500,   500,   500,   501,   501,   502,   502,   502,   502,
     502,   502,   502,   503,   503,   504,   504,   505,   505,   505,
     505,   505,   506,   506,   507,   507,   508,   508,   508,   508,
     509,   509,   509,   509,   510,   510,   511,   512,   512,   512,
     512,   512,   512,   512,   512,   512,   512,   512,   512,   512,
     512,   513,   513,   514,   514,   514,   515,   516,   516,   517,
     518,   519,   520,   520,   521,   521,   521,   521,   522,   522,
     523,   524,   525,   525,   526,   526,   526,   527,   527,   527,
     527,   527,   527,   528,   528,   529,   529,   530,   531,   531,
     532,   532,   533,   533,   534,   534,   534,   534,   535,   535,
     536,   536,   536,   536,   537,   537,   538,   538,   539,   539,
     539,   539,   540,   540,   540,   540,   541,   541,   542,   542,
     543,   544,   544,   544,   544,   544,   544,   544,   545,   546,
     546,   547,   547,   548,   549,   550,   550,   551,   551,   552,
     553,   553,   553,   554,   554,   554,   555,   555,   555,   555,
     555,   555,   555,   556,   556,   557,   558,   559,   559,   559,
     559,   559,   559,   559,   559,   559,   559,   560,   561,   562,
     562,   562,   563,   564,   565,   566,   566,   566,   567,   567,
     567,   567,   567,   568,   569,   569,   569,   569,   569,   569,
     569,   570,   571,   572,   573,   574,   574,   575,   576,   576,
     577,   578,   578,   578,   579,   579,   579,   579,   579,   579,
     579,   579,   579,   579,   580,   580,   581,   581,   582,   583,
     584,   584,   585,   586,   587,   587,   588,   589,   590,   590,
     591,   592,   592,   593,   593,   594,   594,   595,   595,   596,
     596,   597,   597,   598,   599,   599,   600,   600,   601,   602,
     602,   602,   603,   603,   604,   605,   605,   606,   607,   607,
     608,   608,   609,   609,   609,   610,   610,   611,   611,   612,
     612,   612,   612,   612,   613,   614,   615,   616,   616,   616,
     617,   617,   618,   618,   618,   618,   618,   618,   618,   618,
     619,   619,   619,   619,   620,   620,   621,   622,   622,   623,
     623,   623,   624,   624,   625,   625,   626,   626,   627,   628,
     628,   629,   629,   630,   630,   630,   631,   631,   632,   632,
     633,   633,   634,   634,   635,   635,   636,   637,   637,   638,
     638,   638,   639,   640,   640,   640,   640,   641,   641,   642,
     642,   643,   644,   644,   645,   645,   646,   646,   647,   648,
     648,   649,   649,   649,   650,   651,   652,   653,   654,   654,
     654,   655,   656,   657,   658,   659,   659,   659,   659,   659,
     659,   659,   659,   659,   659,   659,   659,   659,   659,   659,
     659,   659,   659,   660,   660,   660,   660,   660,   660,   660,
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
     660,   660,   660,   660,   660,   660,   660,   660,   660,   661
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  xquery_parser::yyr2_[] =
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
       1,     1,     1,     1,     1,     1,     3,     2,     3,     3,
       2,     3,     2,     3,     2,     3,     4,     5,     5,     2,
       4,     5,     3,     3,     2,     2,     8,     3,     1,     2,
       3,     1,     3,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     2,     2,     2,     1,     1,     2,     4,
       3,     5,     4,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     3,     3,     2,     1,     4,     3,
       3,     5,     4,     6,     4,     6,     5,     7,     4,     5,
       5,     6,     3,     3,     2,     1,     3,     4,     5,     3,
       6,     4,     5,     1,     2,     3,     1,     2,     1,     6,
       3,     3,     2,     3,     1,     3,     4,     5,     6,     5,
       3,     1,     2,     2,     3,     4,     1,     3,     1,     2,
       1,     1,     1,     2,     2,     2,     3,     1,     1,     2,
       2,     2,     5,     5,     1,     4,     3,     4,     8,     1,
       2,     3,     2,     3,     8,     1,     2,     3,     8,    10,
       8,    10,     1,     2,     4,     7,     1,     2,     4,     7,
       1,     3,     8,     1,     3,     1,     3,     1,     3,     3,
       3,     3,     0,     4,     3,     3,     3,     1,     5,     1,
       3,     0,     1,     1,     3,     1,     3,     3,     1,     3,
       3,     3,     3,     1,     3,     3,     1,     3,     3,     1,
       4,     1,     4,     1,     4,     1,     4,     1,     2,     1,
       2,     1,     1,     2,     2,     1,     1,     1,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     4,
       5,     5,     6,     3,     4,     1,     2,     3,     2,     2,
       1,     2,     2,     1,     1,     1,     3,     3,     1,     1,
       1,     2,     1,     2,     2,     1,     2,     2,     2,     2,
       2,     2,     2,     1,     2,     2,     1,     2,     2,     2,
       2,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     3,     4,     1,     2,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     2,     3,     1,
       4,     4,     3,     4,     1,     3,     1,     3,     1,     1,
       3,     3,     1,     1,     1,     1,     1,     4,     8,     5,
       9,     9,    10,     1,     2,     1,     2,     6,     0,     1,
       3,     3,     0,     1,     1,     1,     2,     2,     0,     1,
       1,     1,     2,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     3,     2,     3,     3,
       2,     1,     1,     1,     1,     1,     1,     1,     4,     3,
       7,     3,     7,     4,     4,     3,     7,     3,     7,     2,
       1,     2,     3,     1,     1,     1,     1,     1,     3,     3,
       1,     1,     1,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     1,     3,
       4,     4,     3,     3,     3,     3,     4,     4,     3,     4,
       6,     4,     6,     4,     3,     4,     6,     6,     4,     6,
       6,     4,     1,     2,     1,     1,     1,     4,     5,     6,
       3,     3,     3,     3,     5,     7,     7,     5,     5,     5,
       7,     7,     5,     5,     3,     3,     5,     7,     5,     7,
       1,     4,     3,     5,     1,     2,     3,     3,     1,     3,
       2,     0,     1,     1,     2,     1,     3,     1,     3,     1,
       4,     1,     2,     3,     0,     1,     0,     1,     4,     2,
       3,     1,     0,     1,     4,     0,     1,     2,     1,     3,
       0,     1,     2,     2,     1,     0,     1,     0,     1,     1,
       1,     1,     1,     1,     1,     3,     3,     1,     1,     1,
       2,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     2,     1,     1,     2,     2,     3,     1,     2,     2,
       5,     2,     1,     1,     0,     2,     1,     3,     4,     0,
       2,     0,     2,     4,     4,     3,     2,     3,     1,     3,
       0,     1,     1,     2,     2,     2,     2,     1,     2,     2,
       2,     2,     3,     2,     3,     3,     4,     2,     2,     1,
       1,     3,     2,     3,     2,     3,     2,     3,     3,     3,
       5,     5,     5,     8,     5,     3,     5,     7,     1,     1,
       1,     3,     3,     3,     1,     1,     1,     1,     1,     1,
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
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1
  };


  /* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
     First, the terminals, then, starting at \a yyntokens_, nonterminals.  */
  const char*
  const xquery_parser::yytname_[] =
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
  "\"'.'\"", "\"'..'\"", "\"':'\"", "\"'::'\"", "\"'{{'\"", "\"'DOUBLE'\"",
  "\"'<double {>'\"", "\"'else'\"", "\"'empty'\"", "\"'greatest'\"",
  "\"'least'\"", "\"'/>'\"", "\"'encoding'\"", "\"'='\"", "\"''''\"",
  "\"'\\\"\\\"'\"", "\"'every'\"", "\"'except'\"", "\"'external'\"",
  "\"'following'\"", "\"'following-sibling'\"", "\"'follows'\"",
  "\"'>='\"", "\"':='\"", "\"'>'\"", "\"'?'\"", "\"'#'\"", "\"'idiv'\"",
  "\"'in'\"", "\"'inherit'\"", "\"'INTEGER'\"", "\"'intersect'\"",
  "\"'is'\"", "\"'item'\"", "\"'{'\"", "\"'['\"", "\"'<='\"", "\"'('\"",
  "\"'<'\"", "\"'-'\"", "\"'mod'\"", "\"'namespace'\"", "\"'nan'\"",
  "\"'!='\"", "\"'nodecomp'\"", "\"'<no inherit>'\"",
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
  "\"'xquery'\"", "\"'version'\"", "\"'start'\"", "\"'after'\"",
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
  "INTERSECT_EXCEPT_REDUCE", "QVARINDECLLIST_REDUCE", "COMMA_DOLLAR",
  "UNARY_PREC", "STEP_REDUCE", "SIMPLEMAPEXPR_REDUCE",
  "MULTIPLICATIVE_REDUCE", "GROUPBY_VAR_REDUCE", "GROUPBY_VAR_REDUCE2",
  "$accept", "Module", "ERROR", "ModuleWithoutBOM", "VersionDecl",
  "MainModule", "LibraryModule", "ModuleDecl", "SIND_DeclList",
  "SIND_Decl", "Setter", "BoundarySpaceDecl", "DefaultCollationDecl",
  "BaseURIDecl", "ConstructionDecl", "OrderingModeDecl", "EmptyOrderDecl",
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
  "CatchStatement", "Expr", "ExprSingle", "ExprSimple", "FLWORExpr",
  "ReturnExpr", "WindowType", "FLWORWinCondType", "FLWORWinCond",
  "WindowClause", "CountClause", "ForLetWinClause", "FLWORClause",
  "FLWORClauseList", "ForClause", "VarInDeclList", "VarInDecl",
  "PositionalVar", "FTScoreVar", "LetClause", "VarGetsDeclList",
  "VarGetsDecl", "WindowVarDecl", "WindowVars", "WindowVars3",
  "WindowVars2", "WhereClause", "GroupByClause", "GroupSpecList",
  "GroupSpec", "GroupCollationSpec", "OrderByClause", "OrderSpecList",
  "OrderSpec", "OrderModifier", "OrderDirSpec", "OrderEmptySpec",
  "OrderCollationSpec", "QuantifiedExpr", "QVarInDeclList", "QVarInDecl",
  "SwitchExpr", "SwitchCaseClauseList", "SwitchCaseClause",
  "SwitchCaseOperandList", "SwitchStatement", "SwitchCaseStatementList",
  "SwitchCaseStatement", "TypeswitchExpr", "TypeswitchStatement",
  "CaseClauseList", "CaseClause", "CaseStatementList", "CaseStatement",
  "SequenceTypeList", "IfExpr", "OrExpr", "AndExpr", "ComparisonExpr",
  "$@1", "FTContainsExpr", "StringConcatExpr", "opt_FTIgnoreOption",
  "RangeExpr", "AdditiveExpr", "MultiplicativeExpr", "UnionExpr",
  "IntersectExceptExpr", "InstanceofExpr", "TreatExpr", "CastableExpr",
  "CastExpr", "SingleType", "UnaryExpr", "SignList", "ValueExpr",
  "SimpleMapExpr", "ValueComp", "NodeComp", "ValidateExpr",
  "ExtensionExpr", "Pragma_list", "Pragma", "PathExpr", "LeadingSlash",
  "RelativePathExpr", "StepExpr", "AxisStep", "ForwardStep", "ForwardAxis",
  "AbbrevForwardStep", "ReverseStep", "ReverseAxis", "NodeTest",
  "NameTest", "Wildcard", "FilterExpr", "PredicateList", "Predicate",
  "PrimaryExpr", "Literal", "NumericLiteral", "VarRef",
  "ParenthesizedExpr", "ContextItemExpr", "OrderedExpr", "UnorderedExpr",
  "FunctionCall", "ArgList", "FunctionItemExpr", "LiteralFunctionItem",
  "InlineFunction", "Constructor", "DirectConstructor",
  "DirElemConstructor", "DirElemContentList", "DirAttributeList",
  "DirAttr", "OptionalBlank", "DirAttributeValue",
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
  "JSONTest", "JSONItemTest", "JSONObjectTest", "JSONArrayTest",
  "URI_LITERAL", "QNAME", "FUNCTION_NAME", "EQNAME", YY_NULL
  };

#if YYDEBUG
  /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
  const xquery_parser::rhs_number_type
  xquery_parser::yyrhs_[] =
  {
       337,     0,    -1,   339,    -1,   321,   339,    -1,   322,   339,
      -1,   321,   322,   339,    -1,     1,    -1,     1,     3,    -1,
     338,     1,    -1,   341,    -1,   340,   341,    -1,   342,    -1,
     340,   342,    -1,   215,   216,    30,   190,    -1,   215,   216,
      30,   132,    30,   190,    -1,   344,   190,   391,    -1,   361,
     190,   391,    -1,   344,   190,   361,   190,   391,    -1,   391,
      -1,   344,   338,   391,    -1,   361,   338,   391,    -1,   344,
     190,   361,   338,   391,    -1,   344,   338,   361,   190,   391,
      -1,   343,    -1,   343,   344,   190,    -1,   343,   361,   190,
      -1,   343,   344,   190,   361,   190,    -1,    34,   161,   659,
     133,   658,   190,    -1,   345,    -1,   344,   190,   345,    -1,
     344,   338,   345,    -1,   346,    -1,   354,    -1,   359,    -1,
     360,    -1,   368,    -1,   347,    -1,   348,    -1,   349,    -1,
     350,    -1,   351,    -1,   352,    -1,   353,    -1,   578,    -1,
      33,    38,   182,    -1,    33,    38,   196,    -1,    33,   114,
     107,   658,    -1,    33,    37,   658,    -1,    33,    40,   182,
      -1,    33,    40,   196,    -1,    33,    58,   169,    -1,    33,
      58,   202,    -1,    33,   114,   168,   128,   129,    -1,    33,
     114,   168,   128,   130,    -1,    33,    41,   182,   108,   149,
      -1,    33,    41,   182,   108,   165,    -1,    33,    41,   166,
     108,   149,    -1,    33,    41,   166,   108,   165,    -1,   355,
      -1,   358,    -1,    49,    25,     1,    -1,    49,    61,   658,
      -1,    49,    61,   357,   658,    -1,    49,    61,   658,    97,
     356,    -1,    49,    61,   357,   658,    97,   356,    -1,   658,
      -1,   356,   108,   658,    -1,   161,   659,   133,    -1,   114,
      45,   161,    -1,    49,    34,   658,    -1,    49,    34,   161,
     659,   133,   658,    -1,    49,    34,   658,    97,   356,    -1,
      49,    34,   161,   659,   133,   658,    97,   356,    -1,    33,
     161,   659,   133,   658,    -1,    33,   114,    45,   161,   658,
      -1,    33,   114,    47,   161,   658,    -1,   362,    -1,   361,
     190,   362,    -1,   361,   338,   362,    -1,   363,    -1,   367,
      -1,   369,    -1,   373,    -1,   378,    -1,   385,    -1,   387,
      -1,   390,    -1,    33,   114,    80,   364,    -1,    33,    80,
     659,   364,    -1,   365,    -1,   364,   365,    -1,   366,   133,
     573,    -1,    81,    -1,    89,    -1,    82,    -1,    83,    -1,
      84,    -1,    85,    -1,    90,    -1,    86,    -1,    87,    -1,
      88,    -1,    33,    57,   659,    30,    -1,    33,   261,   617,
      -1,    33,   112,   153,   370,    -1,    95,   555,   371,    -1,
     371,    -1,   372,    -1,   138,    -1,   138,   372,    -1,   143,
     415,    -1,    33,   374,   143,   415,    -1,    33,   374,   138,
      -1,    33,   374,   138,   143,   415,    -1,   113,   119,   659,
      -1,   113,   119,   659,   552,    -1,   375,   113,   119,   659,
      -1,   375,   113,   119,   659,   552,    -1,   376,    -1,   375,
     376,    -1,    27,    -1,    27,   157,   377,   187,    -1,    28,
      -1,    28,   157,   377,   187,    -1,   513,    -1,   377,   108,
     513,    -1,    33,   379,    -1,    33,   375,   379,    -1,   380,
      -1,   381,    -1,    47,   660,   382,   399,    -1,    47,   660,
     382,   138,    -1,    75,    47,   660,   382,   399,    -1,    75,
      47,   660,   382,   138,    -1,   157,   187,    -1,   157,   383,
     187,    -1,   157,   187,    95,   553,    -1,   157,   383,   187,
      95,   553,    -1,   384,    -1,   383,   108,   384,    -1,   119,
     659,    -1,   119,   659,   552,    -1,    33,   287,   659,    -1,
      33,   287,   659,    95,   386,    -1,    33,   375,   287,   659,
      -1,    33,   375,   287,   659,    95,   386,    -1,   559,    -1,
     559,   554,    -1,   654,    -1,   654,   554,    -1,    33,   295,
     659,   299,   227,   496,   170,   388,    -1,    33,   375,   295,
     659,   299,   227,   496,   170,   388,    -1,   389,    -1,   388,
     108,   389,    -1,   496,    -1,   496,   552,    -1,   496,   450,
      -1,   496,   552,   450,    -1,    33,   303,   304,   659,   299,
     287,   659,   119,   659,   305,   415,    -1,    33,   303,   304,
     659,   299,   287,   659,   225,   119,   659,   305,   293,   306,
     496,    -1,    33,   303,   304,   659,   299,   287,   659,   307,
     225,   119,   659,   305,   415,    -1,    33,   303,   304,   659,
     308,   306,   257,   287,   659,   225,   119,   659,   306,   496,
     199,   287,   659,   225,   119,   659,   306,   496,    -1,   392,
      -1,   394,    -1,   395,    -1,    -1,   394,    -1,   395,    -1,
      -1,   414,    -1,   395,   414,    -1,   396,    -1,   395,   396,
      -1,   395,   414,   338,   396,    -1,   397,    -1,   400,    -1,
     403,    -1,   404,    -1,   405,    -1,   406,    -1,   407,    -1,
     408,    -1,   410,    -1,   462,    -1,   458,    -1,   411,    -1,
     154,   395,   184,    -1,   154,   184,    -1,   154,   393,   184,
      -1,   154,   393,   184,    -1,   401,   190,    -1,   401,   108,
     402,    -1,   113,   402,    -1,   375,   113,   402,    -1,   119,
     659,    -1,   119,   659,   552,    -1,   119,   659,   143,   415,
      -1,   119,   659,   552,   143,   415,    -1,   119,   659,   143,
     415,   190,    -1,   416,   190,    -1,   240,   242,   415,   190,
      -1,   243,   157,   414,   187,   396,    -1,   238,   241,   190,
      -1,   239,   241,   190,    -1,   426,   409,    -1,   186,   396,
      -1,    48,   157,   414,   187,   198,   396,   127,   396,    -1,
     244,   397,   412,    -1,   413,    -1,   412,   413,    -1,   245,
     590,   397,    -1,   415,    -1,   414,   108,   415,    -1,   414,
     338,   415,    -1,   417,    -1,   454,    -1,   461,    -1,   468,
      -1,   586,    -1,   416,    -1,   469,    -1,   451,    -1,   579,
      -1,   580,    -1,   582,    -1,   581,    -1,   583,    -1,   651,
      -1,   649,    -1,   652,    -1,   653,    -1,   650,    -1,   426,
     418,    -1,   186,   415,    -1,    67,   284,    -1,    72,   284,
      -1,   217,    -1,   254,    -1,    56,   254,    -1,   420,   436,
      78,   415,    -1,   420,    78,   415,    -1,    46,   419,   435,
     421,   421,    -1,    46,   419,   435,   421,    -1,    42,   119,
     659,    -1,   427,    -1,   432,    -1,   422,    -1,   424,    -1,
     439,    -1,   444,    -1,   440,    -1,   423,    -1,   424,    -1,
     426,   425,    -1,    46,   119,   428,    -1,    46,     1,   428,
      -1,    46,     3,    -1,   429,    -1,   428,   108,   119,   429,
      -1,   428,   108,   429,    -1,   659,   148,   415,    -1,   659,
      36,   128,   148,   415,    -1,   659,   552,   148,   415,    -1,
     659,   552,    36,   128,   148,   415,    -1,   659,   430,   148,
     415,    -1,   659,    36,   128,   430,   148,   415,    -1,   659,
     552,   430,   148,   415,    -1,   659,   552,    36,   128,   430,
     148,   415,    -1,   659,   431,   148,   415,    -1,   659,   552,
     431,   148,   415,    -1,   659,   430,   431,   148,   415,    -1,
     659,   552,   430,   431,   148,   415,    -1,    97,   119,   659,
      -1,   273,   119,   659,    -1,    51,   433,    -1,   434,    -1,
     433,   108,   434,    -1,   119,   659,   143,   415,    -1,   119,
     659,   552,   143,   415,    -1,   431,   143,   415,    -1,   119,
     659,   552,   431,   143,   415,    -1,   119,   659,   148,   415,
      -1,   119,   659,   552,   148,   415,    -1,   437,    -1,   119,
     659,    -1,   119,   659,   437,    -1,   430,    -1,   430,   438,
      -1,   438,    -1,    59,   119,   659,    54,   119,   659,    -1,
      54,   119,   659,    -1,    59,   119,   659,    -1,   212,   415,
      -1,   171,   170,   441,    -1,   442,    -1,   441,   108,   442,
      -1,   119,   659,   143,   415,    -1,   119,   659,   552,   143,
     415,    -1,   119,   659,   552,   143,   415,   443,    -1,   119,
     659,   143,   415,   443,    -1,   119,   659,   443,    -1,   415,
      -1,   415,   443,    -1,   107,   658,    -1,   168,   170,   445,
      -1,    70,   168,   170,   445,    -1,   446,    -1,   445,   108,
     446,    -1,   415,    -1,   415,   447,    -1,   448,    -1,   449,
      -1,   450,    -1,   448,   449,    -1,   448,   450,    -1,   449,
     450,    -1,   448,   449,   450,    -1,    96,    -1,   117,    -1,
     128,   129,    -1,   128,   130,    -1,   107,   658,    -1,    68,
     119,   452,   188,   415,    -1,   136,   119,   452,   188,   415,
      -1,   453,    -1,   452,   108,   119,   453,    -1,   659,   148,
     415,    -1,   659,   552,   148,   415,    -1,    73,   157,   414,
     187,   455,   114,   186,   415,    -1,   456,    -1,   455,   456,
      -1,   457,   186,   415,    -1,   101,   415,    -1,   457,   101,
     415,    -1,    73,   157,   414,   187,   459,   114,   186,   396,
      -1,   460,    -1,   459,   460,    -1,   457,   186,   396,    -1,
      74,   157,   414,   187,   463,   114,   186,   415,    -1,    74,
     157,   414,   187,   463,   114,   119,   659,   186,   415,    -1,
      74,   157,   414,   187,   465,   114,   186,   396,    -1,    74,
     157,   414,   187,   463,   114,   119,   659,   186,   396,    -1,
     464,    -1,   463,   464,    -1,   101,   467,   186,   415,    -1,
     101,   119,   659,    95,   467,   186,   415,    -1,   466,    -1,
     465,   466,    -1,   101,   467,   186,   396,    -1,   101,   119,
     659,    95,   467,   186,   396,    -1,   553,    -1,   467,   210,
     553,    -1,    48,   157,   414,   187,   198,   415,   127,   415,
      -1,   470,    -1,   469,   167,   470,    -1,   471,    -1,   470,
      93,   471,    -1,   473,    -1,   473,   490,   473,    -1,   473,
     491,   473,    -1,   473,   133,   473,    -1,   473,   163,   473,
      -1,    -1,   473,   158,   472,   473,    -1,   473,   156,   473,
      -1,   473,   144,   473,    -1,   473,   142,   473,    -1,   474,
      -1,   474,   249,    71,   591,   475,    -1,   476,    -1,   476,
     100,   474,    -1,    -1,   643,    -1,   477,    -1,   477,   199,
     477,    -1,   478,    -1,   477,   176,   478,    -1,   477,   159,
     478,    -1,   479,    -1,   478,   194,   479,    -1,   478,   118,
     479,    -1,   478,   147,   479,    -1,   478,   160,   479,    -1,
     480,    -1,   479,   201,   480,    -1,   479,   210,   480,    -1,
     481,    -1,   480,   151,   481,    -1,   480,   137,   481,    -1,
     482,    -1,   482,    50,   231,   553,    -1,   483,    -1,   483,
     200,    95,   553,    -1,   484,    -1,   484,   102,    95,   485,
      -1,   486,    -1,   486,   103,    95,   485,    -1,   558,    -1,
     558,   145,    -1,   488,    -1,   487,   488,    -1,   176,    -1,
     159,    -1,   487,   176,    -1,   487,   159,    -1,   492,    -1,
     489,    -1,   493,    -1,   496,    -1,   489,   193,   496,    -1,
     203,    -1,   208,    -1,   207,    -1,   206,    -1,   205,    -1,
     204,    -1,   152,    -1,   179,    -1,   141,    -1,    76,   154,
     394,   184,    -1,    76,   222,   154,   394,   184,    -1,    76,
     221,   154,   394,   184,    -1,    76,    77,   571,   154,   394,
     184,    -1,   494,   154,   184,    -1,   494,   154,   414,   184,
      -1,   495,    -1,   494,   495,    -1,   177,   659,    17,    -1,
     177,    18,    -1,   177,    19,    -1,   497,    -1,   497,   498,
      -1,   192,   498,    -1,   498,    -1,   191,    -1,   499,    -1,
     499,   191,   498,    -1,   499,   192,   498,    -1,   500,    -1,
     509,    -1,   501,    -1,   501,   510,    -1,   504,    -1,   504,
     510,    -1,   502,   506,    -1,   503,    -1,   106,   123,    -1,
     115,   123,    -1,    98,   123,    -1,   189,   123,    -1,   116,
     123,    -1,   140,   123,    -1,   139,   123,    -1,   506,    -1,
      99,   506,    -1,   505,   506,    -1,   121,    -1,   172,   123,
      -1,    91,   123,    -1,   181,   123,    -1,   180,   123,    -1,
      92,   123,    -1,   559,    -1,   507,    -1,   659,    -1,   508,
      -1,   194,    -1,    11,    -1,    12,    -1,    20,    -1,   512,
      -1,   509,   510,    -1,   509,   157,   187,    -1,   509,   157,
     521,   187,    -1,   511,    -1,   510,   511,    -1,   155,   414,
     185,    -1,   513,    -1,   515,    -1,   516,    -1,   517,    -1,
     520,    -1,   525,    -1,   518,    -1,   519,    -1,   522,    -1,
     398,    -1,   647,    -1,   644,    -1,   645,    -1,   646,    -1,
     514,    -1,   573,    -1,   111,    -1,   150,    -1,   125,    -1,
     119,   659,    -1,   157,   187,    -1,   157,   414,   187,    -1,
     120,    -1,   169,   154,   414,   184,    -1,   202,   154,   414,
     184,    -1,   660,   157,   187,    -1,   660,   157,   521,   187,
      -1,   145,    -1,   521,   108,   145,    -1,   415,    -1,   521,
     108,   415,    -1,   523,    -1,   524,    -1,   660,   146,   150,
      -1,    47,   382,   399,    -1,   526,    -1,   544,    -1,   527,
      -1,   541,    -1,   542,    -1,   158,   659,   531,   131,    -1,
     158,   659,   531,   197,   195,   659,   531,   197,    -1,   158,
     659,   529,   531,   131,    -1,   158,   659,   529,   531,   197,
     195,   659,   531,   197,    -1,   158,   659,   531,   197,   528,
     195,   659,   531,   197,    -1,   158,   659,   529,   531,   197,
     528,   195,   659,   531,   197,    -1,   539,    -1,   528,   539,
      -1,   530,    -1,   529,   530,    -1,    35,   659,   531,   133,
     531,   532,    -1,    -1,    35,    -1,   183,   533,   183,    -1,
      94,   535,    94,    -1,    -1,   534,    -1,   135,    -1,   537,
      -1,   534,   135,    -1,   534,   537,    -1,    -1,   536,    -1,
     134,    -1,   538,    -1,   536,   134,    -1,   536,   538,    -1,
      29,    -1,   540,    -1,     5,    -1,   540,    -1,   526,    -1,
      10,    -1,   543,    -1,   540,    -1,     9,    -1,   124,    -1,
     126,    -1,   154,   394,   184,    -1,   213,    31,   214,    -1,
     213,   214,    -1,   174,   659,   175,    -1,   174,   659,     8,
      -1,   104,     7,    -1,   545,    -1,   546,    -1,   547,    -1,
     548,    -1,   549,    -1,   550,    -1,   551,    -1,    43,   154,
     394,   184,    -1,    21,   393,   184,    -1,    45,   154,   414,
     184,   154,   393,   184,    -1,    22,   393,   184,    -1,    98,
     154,   414,   184,   154,   393,   184,    -1,    71,   154,   394,
     184,    -1,    39,   154,   394,   184,    -1,    23,   393,   184,
      -1,    60,   154,   414,   184,   154,   393,   184,    -1,    24,
     394,   184,    -1,   161,   154,   414,   184,   154,   394,   184,
      -1,    95,   553,    -1,   555,    -1,   555,   554,    -1,   211,
     157,   187,    -1,   145,    -1,   194,    -1,   176,    -1,   557,
      -1,   559,    -1,   153,   157,   187,    -1,   320,   157,   187,
      -1,   574,    -1,   577,    -1,   654,    -1,   553,    -1,   556,
     108,   553,    -1,   659,    -1,   659,    -1,   562,    -1,   569,
      -1,   567,    -1,   570,    -1,   568,    -1,   566,    -1,   565,
      -1,   564,    -1,   563,    -1,   560,    -1,   561,   157,   187,
      -1,   225,    -1,    44,   157,   187,    -1,    44,   157,   569,
     187,    -1,    44,   157,   570,   187,    -1,    53,   157,   187,
      -1,    71,   157,   187,    -1,    39,   157,   187,    -1,    60,
     157,   187,    -1,    60,   157,   659,   187,    -1,    60,   157,
      30,   187,    -1,    98,   157,   187,    -1,    98,   157,   659,
     187,    -1,    98,   157,   659,   108,   571,   187,    -1,    98,
     157,   194,   187,    -1,    98,   157,   194,   108,   571,   187,
      -1,    62,   157,   659,   187,    -1,    45,   157,   187,    -1,
      45,   157,   659,   187,    -1,    45,   157,   659,   108,   571,
     187,    -1,    45,   157,   659,   108,   572,   187,    -1,    45,
     157,   194,   187,    -1,    45,   157,   194,   108,   571,   187,
      -1,    45,   157,   194,   108,   572,   187,    -1,    63,   157,
     659,   187,    -1,   659,    -1,   659,   145,    -1,    30,    -1,
     575,    -1,   576,    -1,    47,   157,   194,   187,    -1,    47,
     157,   187,    95,   553,    -1,    47,   157,   556,   187,    95,
     553,    -1,   157,   555,   187,    -1,    33,   220,   221,    -1,
      33,   220,   222,    -1,    33,   220,   223,    -1,   226,   225,
     415,   233,   415,    -1,   226,   225,   415,    95,   232,   233,
     415,    -1,   226,   225,   415,    95,   234,   233,   415,    -1,
     226,   225,   415,   218,   415,    -1,   226,   225,   415,   219,
     415,    -1,   226,   227,   415,   233,   415,    -1,   226,   227,
     415,    95,   232,   233,   415,    -1,   226,   227,   415,    95,
     234,   233,   415,    -1,   226,   227,   415,   218,   415,    -1,
     226,   227,   415,   219,   415,    -1,   224,   225,   415,    -1,
     224,   227,   415,    -1,   229,   225,   415,   237,   415,    -1,
     229,   230,   231,   225,   415,   237,   415,    -1,   228,   225,
     415,    95,   415,    -1,   236,   119,   584,   235,   415,   186,
     415,    -1,   585,    -1,   584,   108,   119,   585,    -1,   659,
     143,   415,    -1,   244,   154,   414,   184,   587,    -1,   588,
      -1,   587,   588,    -1,   245,   590,   589,    -1,   154,   414,
     184,    -1,   507,    -1,   590,   210,   507,    -1,   594,   592,
      -1,    -1,   593,    -1,   612,    -1,   593,   612,    -1,   595,
      -1,   594,   262,   595,    -1,   596,    -1,   595,   258,   596,
      -1,   597,    -1,   596,   260,   148,   597,    -1,   598,    -1,
     259,   598,    -1,   602,   599,   600,    -1,    -1,   617,    -1,
      -1,   601,    -1,   282,   154,   414,   184,    -1,   606,   603,
      -1,   157,   591,   187,    -1,   604,    -1,    -1,   639,    -1,
     494,   154,   605,   184,    -1,    -1,   591,    -1,   607,   608,
      -1,   513,    -1,   154,   414,   184,    -1,    -1,   609,    -1,
     248,   610,    -1,   247,   611,    -1,   270,    -1,    -1,    79,
      -1,    -1,   286,    -1,   613,    -1,   614,    -1,   615,    -1,
     641,    -1,   638,    -1,   169,    -1,   284,   477,   616,    -1,
     253,   640,   616,    -1,   286,    -1,   276,    -1,   269,    -1,
     246,   618,    -1,   617,   246,   618,    -1,   619,    -1,   620,
      -1,   621,    -1,   636,    -1,   622,    -1,   630,    -1,   623,
      -1,   637,    -1,   101,   274,    -1,   101,   263,    -1,   266,
      -1,   281,    -1,   251,   274,    -1,   251,   263,    -1,    57,
     659,    30,    -1,   277,    -1,    55,   277,    -1,   279,   624,
      -1,   279,   157,   624,   625,   187,    -1,    55,   279,    -1,
     627,    -1,   114,    -1,    -1,   108,   626,    -1,   627,    -1,
     626,   108,   627,    -1,    97,    30,   628,   629,    -1,    -1,
     271,    30,    -1,    -1,   640,   265,    -1,   278,   286,   631,
     633,    -1,   278,   286,   114,   633,    -1,    55,   278,   286,
      -1,    97,    30,    -1,   157,   632,   187,    -1,    30,    -1,
     632,   108,    30,    -1,    -1,   634,    -1,   635,    -1,   634,
     635,    -1,   201,   631,    -1,   137,   631,    -1,   264,    30,
      -1,   283,    -1,    55,   283,    -1,    97,   217,    -1,    97,
     254,    -1,   255,   250,    -1,   267,   640,   280,    -1,   256,
     477,    -1,    97,   130,   477,    -1,    97,    52,   477,    -1,
     257,   477,   199,   477,    -1,   272,   642,    -1,   252,   642,
      -1,   275,    -1,   268,    -1,   285,   250,   479,    -1,   155,
     185,    -1,   155,   414,   185,    -1,   310,   311,    -1,   310,
     414,   311,    -1,   312,   313,    -1,   312,   414,   313,    -1,
     154,   648,   184,    -1,   415,   122,   415,    -1,   648,   108,
     415,   122,   415,    -1,   226,   314,   415,   233,   415,    -1,
     226,   314,   648,   233,   415,    -1,   226,   314,   415,   233,
     415,    97,   316,   415,    -1,   315,   314,   415,   233,   415,
      -1,   224,   314,   509,    -1,   228,   314,   509,    95,   415,
      -1,   229,   314,   230,   231,   509,   237,   415,    -1,   655,
      -1,   656,    -1,   657,    -1,   319,   157,   187,    -1,   317,
     157,   187,    -1,   318,   157,   187,    -1,    30,    -1,   660,
      -1,    16,    -1,    98,    -1,    39,    -1,    44,    -1,    53,
      -1,    45,    -1,   153,    -1,    48,    -1,   225,    -1,    60,
      -1,    62,    -1,    63,    -1,    71,    -1,    74,    -1,    73,
      -1,   211,    -1,   243,    -1,   661,    -1,    25,    -1,   215,
      -1,   128,    -1,    38,    -1,   261,    -1,    37,    -1,   222,
      -1,   221,    -1,   147,    -1,    43,    -1,   259,    -1,   260,
      -1,   274,    -1,   263,    -1,   251,    -1,   285,    -1,   277,
      -1,   279,    -1,   278,    -1,   283,    -1,   255,    -1,   250,
      -1,    79,    -1,   217,    -1,   254,    -1,    52,    -1,   223,
      -1,   236,    -1,   302,    -1,   230,    -1,   203,    -1,   208,
      -1,   207,    -1,   206,    -1,   205,    -1,   204,    -1,    97,
      -1,   112,    -1,   113,    -1,   186,    -1,    46,    -1,   257,
      -1,    36,    -1,    67,    -1,    72,    -1,    59,    -1,    54,
      -1,    56,    -1,    78,    -1,    42,    -1,   148,    -1,    51,
      -1,   212,    -1,   170,    -1,   171,    -1,   168,    -1,    70,
      -1,    96,    -1,   117,    -1,   129,    -1,   130,    -1,   107,
      -1,    68,    -1,   136,    -1,   188,    -1,   101,    -1,    95,
      -1,   198,    -1,   127,    -1,   167,    -1,    93,    -1,    50,
      -1,   231,    -1,   102,    -1,   199,    -1,   118,    -1,   160,
      -1,   201,    -1,   151,    -1,   137,    -1,    76,    -1,    77,
      -1,   103,    -1,   200,    -1,   152,    -1,   182,    -1,   196,
      -1,   161,    -1,   138,    -1,   132,    -1,   166,    -1,   149,
      -1,   165,    -1,    33,    -1,    40,    -1,    58,    -1,   114,
      -1,    41,    -1,    57,    -1,   216,    -1,    49,    -1,    61,
      -1,    34,    -1,    47,    -1,   273,    -1,   249,    -1,   282,
      -1,   284,    -1,   253,    -1,   267,    -1,   280,    -1,   272,
      -1,   252,    -1,   266,    -1,   281,    -1,   271,    -1,   265,
      -1,   264,    -1,   248,    -1,   247,    -1,   256,    -1,   286,
      -1,   276,    -1,   275,    -1,   270,    -1,   268,    -1,   269,
      -1,   235,    -1,   232,    -1,   229,    -1,   226,    -1,   228,
      -1,   224,    -1,   219,    -1,   218,    -1,   220,    -1,   237,
      -1,   227,    -1,   234,    -1,   233,    -1,    66,    -1,    64,
      -1,    75,    -1,   169,    -1,   202,    -1,   242,    -1,   240,
      -1,   241,    -1,   238,    -1,   239,    -1,   244,    -1,   245,
      -1,   246,    -1,    65,    -1,   295,    -1,   293,    -1,   294,
      -1,   299,    -1,   300,    -1,   301,    -1,   296,    -1,   297,
      -1,   298,    -1,    80,    -1,    81,    -1,    82,    -1,    83,
      -1,    84,    -1,    85,    -1,    86,    -1,    87,    -1,    88,
      -1,    89,    -1,    90,    -1,   287,    -1,   288,    -1,   289,
      -1,   290,    -1,   291,    -1,   292,    -1,   303,    -1,   304,
      -1,   305,    -1,   306,    -1,   307,    -1,   308,    -1,   309,
      -1,    91,    -1,   106,    -1,   115,    -1,   172,    -1,   180,
      -1,   189,    -1,   139,    -1,    92,    -1,   116,    -1,   140,
      -1,   181,    -1,   316,    -1,   314,    -1,   315,    -1,   319,
      -1,   318,    -1,   317,    -1,   320,    -1,    26,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned short int
  xquery_parser::yyprhs_[] =
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
     688,   690,   692,   694,   696,   698,   700,   704,   707,   711,
     715,   718,   722,   725,   729,   732,   736,   741,   747,   753,
     756,   761,   767,   771,   775,   778,   781,   790,   794,   796,
     799,   803,   805,   809,   813,   815,   817,   819,   821,   823,
     825,   827,   829,   831,   833,   835,   837,   839,   841,   843,
     845,   847,   849,   852,   855,   858,   861,   863,   865,   868,
     873,   877,   883,   888,   892,   894,   896,   898,   900,   902,
     904,   906,   908,   910,   913,   917,   921,   924,   926,   931,
     935,   939,   945,   950,   957,   962,   969,   975,   983,   988,
     994,  1000,  1007,  1011,  1015,  1018,  1020,  1024,  1029,  1035,
    1039,  1046,  1051,  1057,  1059,  1062,  1066,  1068,  1071,  1073,
    1080,  1084,  1088,  1091,  1095,  1097,  1101,  1106,  1112,  1119,
    1125,  1129,  1131,  1134,  1137,  1141,  1146,  1148,  1152,  1154,
    1157,  1159,  1161,  1163,  1166,  1169,  1172,  1176,  1178,  1180,
    1183,  1186,  1189,  1195,  1201,  1203,  1208,  1212,  1217,  1226,
    1228,  1231,  1235,  1238,  1242,  1251,  1253,  1256,  1260,  1269,
    1280,  1289,  1300,  1302,  1305,  1310,  1318,  1320,  1323,  1328,
    1336,  1338,  1342,  1351,  1353,  1357,  1359,  1363,  1365,  1369,
    1373,  1377,  1381,  1382,  1387,  1391,  1395,  1399,  1401,  1407,
    1409,  1413,  1414,  1416,  1418,  1422,  1424,  1428,  1432,  1434,
    1438,  1442,  1446,  1450,  1452,  1456,  1460,  1462,  1466,  1470,
    1472,  1477,  1479,  1484,  1486,  1491,  1493,  1498,  1500,  1503,
    1505,  1508,  1510,  1512,  1515,  1518,  1520,  1522,  1524,  1526,
    1530,  1532,  1534,  1536,  1538,  1540,  1542,  1544,  1546,  1548,
    1553,  1559,  1565,  1572,  1576,  1581,  1583,  1586,  1590,  1593,
    1596,  1598,  1601,  1604,  1606,  1608,  1610,  1614,  1618,  1620,
    1622,  1624,  1627,  1629,  1632,  1635,  1637,  1640,  1643,  1646,
    1649,  1652,  1655,  1658,  1660,  1663,  1666,  1668,  1671,  1674,
    1677,  1680,  1683,  1685,  1687,  1689,  1691,  1693,  1695,  1697,
    1699,  1701,  1704,  1708,  1713,  1715,  1718,  1722,  1724,  1726,
    1728,  1730,  1732,  1734,  1736,  1738,  1740,  1742,  1744,  1746,
    1748,  1750,  1752,  1754,  1756,  1758,  1760,  1763,  1766,  1770,
    1772,  1777,  1782,  1786,  1791,  1793,  1797,  1799,  1803,  1805,
    1807,  1811,  1815,  1817,  1819,  1821,  1823,  1825,  1830,  1839,
    1845,  1855,  1865,  1876,  1878,  1881,  1883,  1886,  1893,  1894,
    1896,  1900,  1904,  1905,  1907,  1909,  1911,  1914,  1917,  1918,
    1920,  1922,  1924,  1927,  1930,  1932,  1934,  1936,  1938,  1940,
    1942,  1944,  1946,  1948,  1950,  1952,  1956,  1960,  1963,  1967,
    1971,  1974,  1976,  1978,  1980,  1982,  1984,  1986,  1988,  1993,
    1997,  2005,  2009,  2017,  2022,  2027,  2031,  2039,  2043,  2051,
    2054,  2056,  2059,  2063,  2065,  2067,  2069,  2071,  2073,  2077,
    2081,  2083,  2085,  2087,  2089,  2093,  2095,  2097,  2099,  2101,
    2103,  2105,  2107,  2109,  2111,  2113,  2115,  2117,  2121,  2123,
    2127,  2132,  2137,  2141,  2145,  2149,  2153,  2158,  2163,  2167,
    2172,  2179,  2184,  2191,  2196,  2200,  2205,  2212,  2219,  2224,
    2231,  2238,  2243,  2245,  2248,  2250,  2252,  2254,  2259,  2265,
    2272,  2276,  2280,  2284,  2288,  2294,  2302,  2310,  2316,  2322,
    2328,  2336,  2344,  2350,  2356,  2360,  2364,  2370,  2378,  2384,
    2392,  2394,  2399,  2403,  2409,  2411,  2414,  2418,  2422,  2424,
    2428,  2431,  2432,  2434,  2436,  2439,  2441,  2445,  2447,  2451,
    2453,  2458,  2460,  2463,  2467,  2468,  2470,  2471,  2473,  2478,
    2481,  2485,  2487,  2488,  2490,  2495,  2496,  2498,  2501,  2503,
    2507,  2508,  2510,  2513,  2516,  2518,  2519,  2521,  2522,  2524,
    2526,  2528,  2530,  2532,  2534,  2536,  2540,  2544,  2546,  2548,
    2550,  2553,  2557,  2559,  2561,  2563,  2565,  2567,  2569,  2571,
    2573,  2576,  2579,  2581,  2583,  2586,  2589,  2593,  2595,  2598,
    2601,  2607,  2610,  2612,  2614,  2615,  2618,  2620,  2624,  2629,
    2630,  2633,  2634,  2637,  2642,  2647,  2651,  2654,  2658,  2660,
    2664,  2665,  2667,  2669,  2672,  2675,  2678,  2681,  2683,  2686,
    2689,  2692,  2695,  2699,  2702,  2706,  2710,  2715,  2718,  2721,
    2723,  2725,  2729,  2732,  2736,  2739,  2743,  2746,  2750,  2754,
    2758,  2764,  2770,  2776,  2785,  2791,  2795,  2801,  2809,  2811,
    2813,  2815,  2819,  2823,  2827,  2829,  2831,  2833,  2835,  2837,
    2839,  2841,  2843,  2845,  2847,  2849,  2851,  2853,  2855,  2857,
    2859,  2861,  2863,  2865,  2867,  2869,  2871,  2873,  2875,  2877,
    2879,  2881,  2883,  2885,  2887,  2889,  2891,  2893,  2895,  2897,
    2899,  2901,  2903,  2905,  2907,  2909,  2911,  2913,  2915,  2917,
    2919,  2921,  2923,  2925,  2927,  2929,  2931,  2933,  2935,  2937,
    2939,  2941,  2943,  2945,  2947,  2949,  2951,  2953,  2955,  2957,
    2959,  2961,  2963,  2965,  2967,  2969,  2971,  2973,  2975,  2977,
    2979,  2981,  2983,  2985,  2987,  2989,  2991,  2993,  2995,  2997,
    2999,  3001,  3003,  3005,  3007,  3009,  3011,  3013,  3015,  3017,
    3019,  3021,  3023,  3025,  3027,  3029,  3031,  3033,  3035,  3037,
    3039,  3041,  3043,  3045,  3047,  3049,  3051,  3053,  3055,  3057,
    3059,  3061,  3063,  3065,  3067,  3069,  3071,  3073,  3075,  3077,
    3079,  3081,  3083,  3085,  3087,  3089,  3091,  3093,  3095,  3097,
    3099,  3101,  3103,  3105,  3107,  3109,  3111,  3113,  3115,  3117,
    3119,  3121,  3123,  3125,  3127,  3129,  3131,  3133,  3135,  3137,
    3139,  3141,  3143,  3145,  3147,  3149,  3151,  3153,  3155,  3157,
    3159,  3161,  3163,  3165,  3167,  3169,  3171,  3173,  3175,  3177,
    3179,  3181,  3183,  3185,  3187,  3189,  3191,  3193,  3195,  3197,
    3199,  3201,  3203,  3205,  3207,  3209,  3211,  3213,  3215,  3217,
    3219,  3221,  3223,  3225,  3227,  3229,  3231,  3233,  3235,  3237,
    3239,  3241,  3243,  3245,  3247,  3249,  3251,  3253,  3255,  3257,
    3259,  3261,  3263,  3265,  3267,  3269,  3271,  3273,  3275,  3277
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  xquery_parser::yyrline_[] =
  {
         0,   846,   846,   847,   851,   855,   861,   865,   869,   875,
     881,   889,   895,   904,   909,   915,   921,   927,   935,   940,
     948,   956,   964,   973,   978,   984,   990,   999,  1007,  1014,
    1020,  1029,  1030,  1031,  1032,  1033,  1036,  1037,  1038,  1039,
    1040,  1041,  1042,  1043,  1046,  1051,  1057,  1063,  1069,  1074,
    1080,  1085,  1091,  1096,  1102,  1107,  1112,  1117,  1123,  1125,
    1127,  1135,  1140,  1148,  1156,  1165,  1172,  1180,  1186,  1192,
    1198,  1205,  1213,  1224,  1231,  1238,  1246,  1253,  1259,  1268,
    1269,  1270,  1271,  1272,  1273,  1274,  1275,  1278,  1284,  1291,
    1298,  1306,  1314,  1315,  1316,  1317,  1318,  1319,  1320,  1321,
    1322,  1323,  1326,  1340,  1346,  1352,  1359,  1365,  1372,  1377,
    1383,  1389,  1401,  1413,  1426,  1431,  1439,  1447,  1456,  1461,
    1468,  1473,  1480,  1485,  1493,  1498,  1505,  1511,  1520,  1521,
    1524,  1535,  1548,  1560,  1573,  1578,  1583,  1588,  1594,  1601,
    1609,  1614,  1622,  1630,  1638,  1646,  1656,  1660,  1666,  1670,
    1677,  1686,  1697,  1703,  1710,  1715,  1722,  1729,  1738,  1748,
    1758,  1768,  1783,  1799,  1803,  1808,  1813,  1817,  1822,  1827,
    1832,  1840,  1847,  1854,  1867,  1868,  1869,  1870,  1871,  1872,
    1873,  1874,  1875,  1876,  1877,  1878,  1881,  1886,  1893,  1909,
    1915,  1921,  1928,  1935,  1944,  1953,  1962,  1971,  1982,  1988,
    1994,  2000,  2012,  2017,  2023,  2035,  2048,  2068,  2074,  2081,
    2090,  2097,  2102,  2114,  2126,  2127,  2128,  2129,  2130,  2131,
    2134,  2135,  2136,  2137,  2138,  2139,  2140,  2141,  2142,  2143,
    2144,  2145,  2148,  2160,  2166,  2171,  2177,  2182,  2187,  2193,
    2202,  2212,  2224,  2236,  2242,  2243,  2244,  2247,  2248,  2249,
    2250,  2251,  2254,  2261,  2269,  2274,  2283,  2292,  2299,  2306,
    2316,  2326,  2336,  2346,  2356,  2366,  2376,  2386,  2396,  2405,
    2415,  2425,  2437,  2443,  2449,  2455,  2461,  2469,  2477,  2485,
    2493,  2503,  2509,  2518,  2519,  2523,  2530,  2534,  2539,  2542,
    2546,  2550,  2556,  2562,  2568,  2574,  2582,  2586,  2594,  2602,
    2610,  2618,  2626,  2636,  2642,  2648,  2656,  2662,  2670,  2674,
    2682,  2688,  2694,  2700,  2709,  2718,  2727,  2738,  2742,  2748,
    2754,  2762,  2768,  2777,  2788,  2794,  2802,  2806,  2815,  2821,
    2827,  2835,  2841,  2847,  2855,  2861,  2867,  2875,  2881,  2888,
    2898,  2905,  2915,  2921,  2929,  2935,  2944,  2950,  2958,  2964,
    2973,  2979,  2987,  2993,  2997,  3003,  3008,  3014,  3018,  3027,
    3033,  3042,  3052,  3051,  3064,  3073,  3082,  3093,  3097,  3108,
    3112,  3118,  3121,  3127,  3131,  3137,  3141,  3145,  3151,  3155,
    3161,  3167,  3173,  3181,  3185,  3189,  3195,  3199,  3205,  3213,
    3217,  3225,  3229,  3237,  3241,  3249,  3253,  3261,  3265,  3271,
    3275,  3281,  3285,  3289,  3293,  3301,  3302,  3303,  3306,  3311,
    3317,  3321,  3325,  3329,  3333,  3337,  3343,  3347,  3351,  3357,
    3361,  3365,  3369,  3378,  3384,  3392,  3398,  3406,  3410,  3414,
    3420,  3424,  3432,  3440,  3458,  3464,  3474,  3478,  3484,  3485,
    3488,  3494,  3502,  3508,  3518,  3524,  3532,  3536,  3540,  3544,
    3548,  3554,  3560,  3566,  3570,  3576,  3580,  3589,  3593,  3597,
    3603,  3607,  3615,  3616,  3619,  3623,  3629,  3633,  3637,  3641,
    3647,  3651,  3655,  3659,  3665,  3671,  3679,  3685,  3686,  3687,
    3688,  3689,  3690,  3691,  3692,  3693,  3694,  3695,  3696,  3697,
    3698,  3701,  3705,  3711,  3718,  3725,  3734,  3740,  3744,  3750,
    3757,  3763,  3769,  3773,  3791,  3797,  3803,  3809,  3817,  3821,
    3827,  3833,  3843,  3844,  3847,  3848,  3849,  3852,  3860,  3876,
    3884,  3900,  3918,  3938,  3944,  3953,  3959,  3968,  3975,  3976,
    3978,  3983,  3990,  3993,  3999,  4005,  4011,  4018,  4027,  4030,
    4036,  4042,  4048,  4055,  4064,  4068,  4074,  4078,  4084,  4088,
    4092,  4097,  4104,  4108,  4112,  4116,  4122,  4127,  4133,  4139,
    4146,  4152,  4157,  4162,  4167,  4172,  4177,  4182,  4185,  4191,
    4195,  4201,  4205,  4211,  4217,  4223,  4227,  4233,  4237,  4243,
    4249,  4253,  4257,  4263,  4269,  4275,  4283,  4287,  4291,  4295,
    4299,  4303,  4307,  4313,  4319,  4327,  4333,  4339,  4343,  4347,
    4351,  4355,  4359,  4363,  4367,  4371,  4375,  4381,  4387,  4393,
    4397,  4401,  4407,  4412,  4418,  4424,  4428,  4433,  4439,  4443,
    4449,  4455,  4459,  4467,  4473,  4477,  4483,  4492,  4501,  4507,
    4513,  4521,  4527,  4533,  4539,  4545,  4549,  4555,  4561,  4565,
    4573,  4579,  4585,  4591,  4599,  4603,  4609,  4615,  4619,  4625,
    4629,  4635,  4641,  4648,  4656,  4661,  4667,  4673,  4681,  4687,
    4694,  4700,  4709,  4715,  4721,  4727,  4736,  4743,  4749,  4755,
    4764,  4771,  4775,  4781,  4786,  4793,  4797,  4803,  4807,  4813,
    4817,  4823,  4827,  4835,  4846,  4849,  4855,  4858,  4864,  4870,
    4878,  4882,  4888,  4891,  4897,  4907,  4910,  4916,  4926,  4932,
    4940,  4943,  4949,  4953,  4957,  4963,  4966,  4972,  4975,  4981,
    4985,  4989,  4993,  4997,  5003,  5009,  5019,  5029,  5033,  5037,
    5043,  5049,  5057,  5061,  5065,  5069,  5073,  5077,  5081,  5085,
    5091,  5095,  5099,  5103,  5109,  5115,  5123,  5131,  5135,  5141,
    5151,  5162,  5168,  5172,  5178,  5181,  5187,  5192,  5199,  5207,
    5210,  5216,  5220,  5226,  5235,  5242,  5250,  5254,  5260,  5266,
    5274,  5277,  5283,  5288,  5298,  5306,  5316,  5322,  5326,  5332,
    5336,  5340,  5346,  5352,  5356,  5360,  5364,  5370,  5378,  5388,
    5392,  5398,  5404,  5408,  5414,  5418,  5424,  5428,  5434,  5441,
    5447,  5456,  5462,  5472,  5478,  5484,  5505,  5529,  5553,  5557,
    5561,  5567,  5573,  5579,  5585,  5588,  5589,  5590,  5591,  5592,
    5593,  5594,  5595,  5596,  5597,  5598,  5599,  5600,  5601,  5602,
    5603,  5604,  5605,  5608,  5609,  5610,  5611,  5612,  5613,  5614,
    5615,  5616,  5617,  5618,  5619,  5620,  5621,  5622,  5623,  5624,
    5625,  5626,  5627,  5628,  5629,  5630,  5631,  5632,  5633,  5634,
    5635,  5636,  5637,  5638,  5639,  5640,  5641,  5642,  5643,  5644,
    5645,  5646,  5647,  5648,  5649,  5650,  5651,  5652,  5653,  5654,
    5655,  5656,  5657,  5658,  5659,  5660,  5661,  5662,  5663,  5664,
    5665,  5666,  5667,  5668,  5669,  5670,  5671,  5672,  5673,  5674,
    5675,  5676,  5677,  5678,  5679,  5680,  5681,  5682,  5683,  5684,
    5685,  5686,  5687,  5688,  5689,  5690,  5691,  5692,  5693,  5694,
    5695,  5696,  5697,  5698,  5699,  5700,  5701,  5702,  5703,  5704,
    5705,  5706,  5707,  5708,  5709,  5710,  5711,  5712,  5713,  5714,
    5715,  5716,  5717,  5718,  5719,  5720,  5721,  5722,  5723,  5724,
    5725,  5726,  5727,  5728,  5729,  5730,  5731,  5732,  5733,  5734,
    5735,  5736,  5737,  5738,  5739,  5740,  5741,  5742,  5743,  5744,
    5745,  5746,  5747,  5748,  5749,  5750,  5751,  5752,  5753,  5754,
    5755,  5756,  5757,  5758,  5759,  5760,  5761,  5762,  5763,  5764,
    5765,  5766,  5767,  5768,  5769,  5770,  5771,  5772,  5773,  5774,
    5775,  5776,  5777,  5778,  5779,  5780,  5781,  5782,  5783,  5784,
    5785,  5786,  5787,  5788,  5789,  5790,  5791,  5792,  5793,  5794,
    5795,  5796,  5797,  5798,  5799,  5800,  5801,  5802,  5803,  5804,
    5805,  5806,  5807,  5808,  5809,  5810,  5811,  5812,  5813,  5816
  };

  // Print the state stack on the debug stream.
  void
  xquery_parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (state_stack_type::const_iterator i = yystate_stack_.begin ();
	 i != yystate_stack_.end (); ++i)
      *yycdebug_ << ' ' << *i;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  xquery_parser::yy_reduce_print_ (int yyrule)
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
  xquery_parser::token_number_type
  xquery_parser::yytranslate_ (int t)
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
     335
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int xquery_parser::yyeof_ = 0;
  const int xquery_parser::yylast_ = 17775;
  const int xquery_parser::yynnts_ = 326;
  const int xquery_parser::yyempty_ = -2;
  const int xquery_parser::yyfinal_ = 616;
  const int xquery_parser::yyterror_ = 1;
  const int xquery_parser::yyerrcode_ = 256;
  const int xquery_parser::yyntokens_ = 336;

  const unsigned int xquery_parser::yyuser_token_number_max_ = 590;
  const xquery_parser::token_number_type xquery_parser::yyundef_token_ = 2;


} // zorba
/* Line 1135 of lalr1.cc  */
#line 16247 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
/* Line 1136 of lalr1.cc  */
#line 5818 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"

namespace zorba {
void xquery_parser::error(zorba::xquery_parser::location_type const& loc, string const& msg)
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
      if (msg.find("(missing comma \",\" between expressions?)") != string::npos
          &&
          prevErr->msg.find(zstring("\",\"")) == zstring::npos)
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
