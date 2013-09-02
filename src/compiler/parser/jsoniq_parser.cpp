/* A Bison parser, made by GNU Bison 2.5.  */

/* Skeleton implementation for Bison LALR(1) parsers in C++
   
      Copyright (C) 2002-2011 Free Software Foundation, Inc.
   
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

/* Line 293 of lalr1.cc  */
#line 1 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"

#define JSONIQ_PARSER

/* Line 293 of lalr1.cc  */
#line 58 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"


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


/* Line 293 of lalr1.cc  */
#line 101 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"


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



/* Line 293 of lalr1.cc  */
#line 102 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"


#include "jsoniq_parser.hpp"

/* User implementation prologue.  */

/* Line 299 of lalr1.cc  */
#line 791 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"

template<typename T> inline void release_hack( T *ref ) {
    if ( ref ) {
        RCHelper::addReference( ref );
        RCHelper::removeReference( ref );
    }
}


/* Line 299 of lalr1.cc  */
#line 121 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"

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

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                               \
 do                                                                    \
   if (N)                                                              \
     {                                                                 \
       (Current).begin = YYRHSLOC (Rhs, 1).begin;                      \
       (Current).end   = YYRHSLOC (Rhs, N).end;                        \
     }                                                                 \
   else                                                                \
     {                                                                 \
       (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;        \
     }                                                                 \
 while (false)
#endif

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

/* Line 382 of lalr1.cc  */
#line 207 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"

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
        case 111: /* "\"'DECIMAL'\"" */

/* Line 480 of lalr1.cc  */
#line 790 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ delete (yyvaluep->decval); };

/* Line 480 of lalr1.cc  */
#line 312 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 126: /* "\"'DOUBLE'\"" */

/* Line 480 of lalr1.cc  */
#line 789 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ delete (yyvaluep->dval); };

/* Line 480 of lalr1.cc  */
#line 321 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 151: /* "\"'INTEGER'\"" */

/* Line 480 of lalr1.cc  */
#line 788 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ delete (yyvaluep->ival); };

/* Line 480 of lalr1.cc  */
#line 330 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 345: /* "VersionDecl" */

/* Line 480 of lalr1.cc  */
#line 811 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 339 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 346: /* "MainModule" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 348 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 347: /* "LibraryModule" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 357 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 348: /* "ModuleDecl" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 366 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 349: /* "SIND_DeclList" */

/* Line 480 of lalr1.cc  */
#line 807 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 375 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 350: /* "SIND_Decl" */

/* Line 480 of lalr1.cc  */
#line 807 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 384 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 351: /* "Setter" */

/* Line 480 of lalr1.cc  */
#line 808 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 393 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 352: /* "BoundarySpaceDecl" */

/* Line 480 of lalr1.cc  */
#line 801 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 402 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 353: /* "DefaultCollationDecl" */

/* Line 480 of lalr1.cc  */
#line 802 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 411 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 354: /* "BaseURIDecl" */

/* Line 480 of lalr1.cc  */
#line 801 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 420 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 355: /* "ConstructionDecl" */

/* Line 480 of lalr1.cc  */
#line 801 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 429 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 356: /* "OrderingModeDecl" */

/* Line 480 of lalr1.cc  */
#line 806 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 438 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 357: /* "EmptyOrderDecl" */

/* Line 480 of lalr1.cc  */
#line 803 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 447 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 358: /* "CopyNamespacesDecl" */

/* Line 480 of lalr1.cc  */
#line 802 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 456 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 359: /* "Import" */

/* Line 480 of lalr1.cc  */
#line 803 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 465 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 360: /* "SchemaImport" */

/* Line 480 of lalr1.cc  */
#line 807 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 474 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 361: /* "URILiteralList" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 483 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 362: /* "SchemaPrefix" */

/* Line 480 of lalr1.cc  */
#line 808 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 492 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 363: /* "ModuleImport" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 501 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 364: /* "NamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 510 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 365: /* "DefaultNamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 802 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 519 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 366: /* "VFO_DeclList" */

/* Line 480 of lalr1.cc  */
#line 811 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 528 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 367: /* "VFO_Decl" */

/* Line 480 of lalr1.cc  */
#line 811 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 537 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 368: /* "DecimalFormatDecl" */

/* Line 480 of lalr1.cc  */
#line 811 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 546 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 369: /* "DecimalFormatParamList" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ delete (yyvaluep->vstrpair); };

/* Line 480 of lalr1.cc  */
#line 555 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 370: /* "DecimalFormatParam" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ delete (yyvaluep->strpair); };

/* Line 480 of lalr1.cc  */
#line 564 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 372: /* "OptionDecl" */

/* Line 480 of lalr1.cc  */
#line 805 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 573 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 373: /* "FTOptionDecl" */

/* Line 480 of lalr1.cc  */
#line 814 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 582 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 374: /* "CtxItemDecl" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 591 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 375: /* "CtxItemDecl2" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 600 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 376: /* "CtxItemDecl3" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 609 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 377: /* "CtxItemDecl4" */

/* Line 480 of lalr1.cc  */
#line 810 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 618 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 378: /* "VarDecl" */

/* Line 480 of lalr1.cc  */
#line 810 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 627 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 379: /* "VarNameAndType" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ delete (yyvaluep->varnametype); };

/* Line 480 of lalr1.cc  */
#line 636 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 380: /* "AnnotationList" */

/* Line 480 of lalr1.cc  */
#line 800 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 645 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 381: /* "Annotation" */

/* Line 480 of lalr1.cc  */
#line 800 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 654 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 382: /* "AnnotationLiteralList" */

/* Line 480 of lalr1.cc  */
#line 800 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 663 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 383: /* "FunctionDecl" */

/* Line 480 of lalr1.cc  */
#line 803 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 672 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 384: /* "FunctionDecl2" */

/* Line 480 of lalr1.cc  */
#line 803 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 681 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 385: /* "FunctionDeclSimple" */

/* Line 480 of lalr1.cc  */
#line 803 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 690 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 386: /* "FunctionDeclUpdating" */

/* Line 480 of lalr1.cc  */
#line 803 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 699 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 387: /* "FunctionSig" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ delete (yyvaluep->fnsig); };

/* Line 480 of lalr1.cc  */
#line 708 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 388: /* "ParamList" */

/* Line 480 of lalr1.cc  */
#line 806 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 717 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 389: /* "Param" */

/* Line 480 of lalr1.cc  */
#line 806 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 726 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 390: /* "CollectionDecl" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 735 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 392: /* "IndexDecl" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 744 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 393: /* "IndexKeyList" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 753 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 394: /* "IndexKeySpec" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 762 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 395: /* "IntegrityConstraintDecl" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 771 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 396: /* "QueryBody" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 780 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 397: /* "StatementsAndOptionalExprTop" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 789 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 398: /* "StatementsAndOptionalExpr" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 798 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 399: /* "StatementsAndExpr" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 807 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 400: /* "Statements" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 816 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 401: /* "Statement" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 825 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 402: /* "BlockStatement" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 834 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 403: /* "BlockExpr" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 843 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 404: /* "EnclosedStatementsAndOptionalExpr" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 852 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 405: /* "VarDeclStatement" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 861 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 408: /* "AssignStatement" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 870 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 409: /* "ApplyStatement" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 410: /* "ExitStatement" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 411: /* "WhileStatement" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 897 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 412: /* "FlowCtlStatement" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 906 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 413: /* "FLWORStatement" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 915 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 414: /* "ReturnStatement" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 924 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 415: /* "IfStatement" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 933 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 416: /* "TryStatement" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 942 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 417: /* "CatchListStatement" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 951 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 418: /* "CatchStatement" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 960 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 419: /* "VoidStatement" */

/* Line 480 of lalr1.cc  */
#line 812 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 969 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 420: /* "Expr" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 978 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 421: /* "ExprSingle" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 987 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 422: /* "ExprSimple" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 996 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 423: /* "FLWORExpr" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1005 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 424: /* "ReturnExpr" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1014 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 427: /* "FLWORWinCond" */

/* Line 480 of lalr1.cc  */
#line 810 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1023 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 428: /* "WindowClause" */

/* Line 480 of lalr1.cc  */
#line 803 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1032 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 429: /* "CountClause" */

/* Line 480 of lalr1.cc  */
#line 811 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1041 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 430: /* "ForLetWinClause" */

/* Line 480 of lalr1.cc  */
#line 803 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1050 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 432: /* "FLWORClauseList" */

/* Line 480 of lalr1.cc  */
#line 803 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1059 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 433: /* "ForClause" */

/* Line 480 of lalr1.cc  */
#line 803 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1068 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 435: /* "VarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 810 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1077 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 436: /* "VarInDecl" */

/* Line 480 of lalr1.cc  */
#line 810 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1086 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 437: /* "PositionalVar" */

/* Line 480 of lalr1.cc  */
#line 806 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1095 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 438: /* "FTScoreVar" */

/* Line 480 of lalr1.cc  */
#line 814 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1104 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 439: /* "LetClause" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1113 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 440: /* "VarGetsDeclList" */

/* Line 480 of lalr1.cc  */
#line 810 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1122 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 441: /* "VarGetsDecl" */

/* Line 480 of lalr1.cc  */
#line 810 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1131 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 442: /* "WindowVarDecl" */

/* Line 480 of lalr1.cc  */
#line 810 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1140 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 443: /* "WindowVars" */

/* Line 480 of lalr1.cc  */
#line 810 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1149 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 444: /* "WindowVars3" */

/* Line 480 of lalr1.cc  */
#line 810 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1158 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 445: /* "WindowVars2" */

/* Line 480 of lalr1.cc  */
#line 810 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1167 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 446: /* "WhereClause" */

/* Line 480 of lalr1.cc  */
#line 811 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1176 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 447: /* "GroupByClause" */

/* Line 480 of lalr1.cc  */
#line 805 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1185 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 448: /* "GroupSpecList" */

/* Line 480 of lalr1.cc  */
#line 805 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1194 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 449: /* "GroupSpec" */

/* Line 480 of lalr1.cc  */
#line 805 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1203 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 450: /* "GroupCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 805 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1212 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 451: /* "OrderByClause" */

/* Line 480 of lalr1.cc  */
#line 805 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1221 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 452: /* "OrderSpecList" */

/* Line 480 of lalr1.cc  */
#line 806 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1230 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 453: /* "OrderSpec" */

/* Line 480 of lalr1.cc  */
#line 806 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1239 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 454: /* "OrderModifier" */

/* Line 480 of lalr1.cc  */
#line 805 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1248 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 455: /* "OrderDirSpec" */

/* Line 480 of lalr1.cc  */
#line 805 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1257 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 456: /* "OrderEmptySpec" */

/* Line 480 of lalr1.cc  */
#line 805 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1266 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 457: /* "OrderCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 805 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1275 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 458: /* "QuantifiedExpr" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1284 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 459: /* "QVarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 806 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1293 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 460: /* "QVarInDecl" */

/* Line 480 of lalr1.cc  */
#line 806 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1302 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 461: /* "SwitchExpr" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1311 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 462: /* "SwitchCaseClauseList" */

/* Line 480 of lalr1.cc  */
#line 812 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1320 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 463: /* "SwitchCaseClause" */

/* Line 480 of lalr1.cc  */
#line 812 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1329 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 464: /* "SwitchCaseOperandList" */

/* Line 480 of lalr1.cc  */
#line 812 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1338 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 465: /* "SwitchStatement" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1347 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 468: /* "TypeswitchExpr" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1356 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 469: /* "TypeswitchStatement" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1365 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 470: /* "CaseClauseList" */

/* Line 480 of lalr1.cc  */
#line 801 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1374 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 471: /* "CaseClause" */

/* Line 480 of lalr1.cc  */
#line 801 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1383 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 474: /* "SequenceTypeList" */

/* Line 480 of lalr1.cc  */
#line 808 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1392 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 475: /* "IfExpr" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1401 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 476: /* "OrExpr" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1410 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 477: /* "AndExpr" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1419 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 478: /* "NotExpr" */

/* Line 480 of lalr1.cc  */
#line 813 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1428 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 479: /* "ComparisonExpr" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1437 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 481: /* "FTContainsExpr" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1446 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 482: /* "StringConcatExpr" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1455 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 483: /* "opt_FTIgnoreOption" */

/* Line 480 of lalr1.cc  */
#line 814 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1464 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 484: /* "RangeExpr" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1473 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 485: /* "AdditiveExpr" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1482 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 486: /* "MultiplicativeExpr" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1491 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 487: /* "UnionExpr" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1500 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 488: /* "IntersectExceptExpr" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1509 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 489: /* "InstanceofExpr" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1518 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 490: /* "TreatExpr" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1527 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 491: /* "CastableExpr" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1536 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 492: /* "CastExpr" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1545 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 493: /* "SingleType" */

/* Line 480 of lalr1.cc  */
#line 808 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1554 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 494: /* "UnaryExpr" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1563 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 495: /* "SignList" */

/* Line 480 of lalr1.cc  */
#line 808 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1572 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 496: /* "ValueExpr" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1581 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 497: /* "SimpleMapExpr" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1590 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 498: /* "ValueComp" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1599 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 499: /* "NodeComp" */

/* Line 480 of lalr1.cc  */
#line 812 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1608 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 500: /* "ValidateExpr" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1617 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 501: /* "ExtensionExpr" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1626 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 502: /* "Pragma_list" */

/* Line 480 of lalr1.cc  */
#line 806 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1635 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 503: /* "Pragma" */

/* Line 480 of lalr1.cc  */
#line 806 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1644 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 504: /* "PathExpr" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1653 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 506: /* "RelativePathExpr" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1662 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 507: /* "StepExpr" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1671 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 508: /* "AxisStep" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1680 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 509: /* "ForwardStep" */

/* Line 480 of lalr1.cc  */
#line 799 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1689 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 510: /* "ForwardAxis" */

/* Line 480 of lalr1.cc  */
#line 799 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1698 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 511: /* "AbbrevForwardStep" */

/* Line 480 of lalr1.cc  */
#line 799 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1707 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 512: /* "ReverseStep" */

/* Line 480 of lalr1.cc  */
#line 799 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1716 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 513: /* "ReverseAxis" */

/* Line 480 of lalr1.cc  */
#line 799 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1725 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 514: /* "NodeTest" */

/* Line 480 of lalr1.cc  */
#line 799 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1734 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 515: /* "NameTest" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1743 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 516: /* "Wildcard" */

/* Line 480 of lalr1.cc  */
#line 811 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1752 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 517: /* "PostfixExpr" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1761 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 518: /* "PredicateList" */

/* Line 480 of lalr1.cc  */
#line 806 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1770 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 519: /* "Predicate" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1779 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 520: /* "PrimaryExpr" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1788 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 521: /* "Literal" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1797 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 522: /* "NumericLiteral" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1806 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 524: /* "VarRef" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1815 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 525: /* "ParenthesizedExpr" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1824 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 526: /* "ContextItemExpr" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1833 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 527: /* "OrderedExpr" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1842 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 528: /* "UnorderedExpr" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1851 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 529: /* "FunctionCall" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1860 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 530: /* "ArgList" */

/* Line 480 of lalr1.cc  */
#line 800 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1869 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 534: /* "Constructor" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1878 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 535: /* "DirectConstructor" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1887 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 536: /* "DirElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1896 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 537: /* "DirElemContentList" */

/* Line 480 of lalr1.cc  */
#line 802 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1905 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 538: /* "DirAttributeList" */

/* Line 480 of lalr1.cc  */
#line 802 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1914 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 539: /* "DirAttr" */

/* Line 480 of lalr1.cc  */
#line 802 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1923 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 541: /* "DirAttributeValue" */

/* Line 480 of lalr1.cc  */
#line 802 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1932 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 542: /* "opt_QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 807 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1941 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 543: /* "QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 807 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1950 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 544: /* "opt_AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 800 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1959 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 545: /* "AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 800 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1968 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 546: /* "QuoteAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 807 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1977 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 547: /* "AposAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 800 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1986 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 548: /* "DirElemContent" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1995 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 549: /* "CommonContent" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2004 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 550: /* "DirCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2013 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 551: /* "DirPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2022 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 552: /* "CDataSection" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2031 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 553: /* "ComputedConstructor" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2040 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 554: /* "CompDocConstructor" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2049 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 555: /* "CompElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2058 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 556: /* "CompAttrConstructor" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2067 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 557: /* "CompTextConstructor" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2076 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 558: /* "CompCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2085 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 559: /* "CompPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2094 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 560: /* "CompNamespaceConstructor" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2103 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 561: /* "TypeDeclaration" */

/* Line 480 of lalr1.cc  */
#line 808 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2112 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 562: /* "SequenceType" */

/* Line 480 of lalr1.cc  */
#line 808 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2121 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 563: /* "OccurrenceIndicator" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2130 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 564: /* "ItemType" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2139 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 565: /* "TypeList" */

/* Line 480 of lalr1.cc  */
#line 811 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2148 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 566: /* "GeneralizedAtomicType" */

/* Line 480 of lalr1.cc  */
#line 801 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2157 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 567: /* "SimpleType" */

/* Line 480 of lalr1.cc  */
#line 801 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2166 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 568: /* "KindTest" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2175 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 569: /* "AnyKindTest" */

/* Line 480 of lalr1.cc  */
#line 800 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2184 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 571: /* "DocumentTest" */

/* Line 480 of lalr1.cc  */
#line 802 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2193 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 572: /* "NamespaceTest" */

/* Line 480 of lalr1.cc  */
#line 808 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2202 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 573: /* "TextTest" */

/* Line 480 of lalr1.cc  */
#line 808 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2211 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 574: /* "CommentTest" */

/* Line 480 of lalr1.cc  */
#line 801 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2220 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 575: /* "PITest" */

/* Line 480 of lalr1.cc  */
#line 806 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2229 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 576: /* "AttributeTest" */

/* Line 480 of lalr1.cc  */
#line 801 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2238 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 577: /* "SchemaAttributeTest" */

/* Line 480 of lalr1.cc  */
#line 807 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2247 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 578: /* "ElementTest" */

/* Line 480 of lalr1.cc  */
#line 802 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2256 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 579: /* "SchemaElementTest" */

/* Line 480 of lalr1.cc  */
#line 807 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2265 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 580: /* "TypeName" */

/* Line 480 of lalr1.cc  */
#line 808 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2274 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 581: /* "TypeName_WITH_HOOK" */

/* Line 480 of lalr1.cc  */
#line 808 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2283 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 582: /* "StringLiteral" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2292 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 584: /* "AnyFunctionTest" */

/* Line 480 of lalr1.cc  */
#line 811 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2301 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 585: /* "TypedFunctionTest" */

/* Line 480 of lalr1.cc  */
#line 811 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2310 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 588: /* "InsertExpr" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2319 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 589: /* "DeleteExpr" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2328 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 590: /* "ReplaceExpr" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2337 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 591: /* "RenameExpr" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2346 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 592: /* "TransformExpr" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2355 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 593: /* "VarNameList" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2364 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 594: /* "VarNameDecl" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2373 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 595: /* "TryExpr" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2382 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 596: /* "CatchListExpr" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2391 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 597: /* "CatchExpr" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2400 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 598: /* "BracedExpr" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2409 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 599: /* "NameTestList" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ delete (yyvaluep->name_test_list); };

/* Line 480 of lalr1.cc  */
#line 2418 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 600: /* "FTSelection" */

/* Line 480 of lalr1.cc  */
#line 814 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2427 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 603: /* "FTOr" */

/* Line 480 of lalr1.cc  */
#line 814 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2436 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 604: /* "FTAnd" */

/* Line 480 of lalr1.cc  */
#line 814 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2445 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 605: /* "FTMildNot" */

/* Line 480 of lalr1.cc  */
#line 814 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2454 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 606: /* "FTUnaryNot" */

/* Line 480 of lalr1.cc  */
#line 814 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2463 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 607: /* "FTPrimaryWithOptions" */

/* Line 480 of lalr1.cc  */
#line 814 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2472 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 608: /* "opt_FTMatchOptions" */

/* Line 480 of lalr1.cc  */
#line 814 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2481 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 610: /* "FTWeight" */

/* Line 480 of lalr1.cc  */
#line 814 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2490 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 611: /* "FTPrimary" */

/* Line 480 of lalr1.cc  */
#line 814 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2499 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 612: /* "opt_FTTimes" */

/* Line 480 of lalr1.cc  */
#line 814 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2508 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 613: /* "FTExtensionSelection" */

/* Line 480 of lalr1.cc  */
#line 814 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2517 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 615: /* "FTWords" */

/* Line 480 of lalr1.cc  */
#line 814 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2526 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 616: /* "FTWordsValue" */

/* Line 480 of lalr1.cc  */
#line 814 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2535 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 618: /* "FTAnyallOption" */

/* Line 480 of lalr1.cc  */
#line 814 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2544 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 621: /* "FTPosFilter" */

/* Line 480 of lalr1.cc  */
#line 814 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2553 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 622: /* "FTOrder" */

/* Line 480 of lalr1.cc  */
#line 814 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2562 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 623: /* "FTWindow" */

/* Line 480 of lalr1.cc  */
#line 814 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2571 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 624: /* "FTDistance" */

/* Line 480 of lalr1.cc  */
#line 814 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2580 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 625: /* "FTUnit" */

/* Line 480 of lalr1.cc  */
#line 814 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2589 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 626: /* "FTMatchOptions" */

/* Line 480 of lalr1.cc  */
#line 814 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2598 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 627: /* "FTMatchOption" */

/* Line 480 of lalr1.cc  */
#line 814 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2607 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 628: /* "FTCaseOption" */

/* Line 480 of lalr1.cc  */
#line 814 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2616 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 629: /* "FTDiacriticsOption" */

/* Line 480 of lalr1.cc  */
#line 814 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2625 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 630: /* "FTExtensionOption" */

/* Line 480 of lalr1.cc  */
#line 814 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2634 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 631: /* "FTStemOption" */

/* Line 480 of lalr1.cc  */
#line 814 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2643 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 632: /* "FTThesaurusOption" */

/* Line 480 of lalr1.cc  */
#line 814 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2652 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 636: /* "FTThesaurusID" */

/* Line 480 of lalr1.cc  */
#line 814 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2661 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 639: /* "FTStopWordOption" */

/* Line 480 of lalr1.cc  */
#line 814 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2670 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 640: /* "FTStopWords" */

/* Line 480 of lalr1.cc  */
#line 814 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2679 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 644: /* "FTStopWordsInclExcl" */

/* Line 480 of lalr1.cc  */
#line 814 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2688 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 645: /* "FTLanguageOption" */

/* Line 480 of lalr1.cc  */
#line 814 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2697 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 646: /* "FTWildCardOption" */

/* Line 480 of lalr1.cc  */
#line 814 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2706 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 647: /* "FTContent" */

/* Line 480 of lalr1.cc  */
#line 814 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2715 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 648: /* "FTTimes" */

/* Line 480 of lalr1.cc  */
#line 814 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2724 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 649: /* "FTRange" */

/* Line 480 of lalr1.cc  */
#line 814 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2733 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 650: /* "FTScope" */

/* Line 480 of lalr1.cc  */
#line 814 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2742 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 651: /* "FTBigUnit" */

/* Line 480 of lalr1.cc  */
#line 814 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2751 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 652: /* "FTIgnoreOption" */

/* Line 480 of lalr1.cc  */
#line 814 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2760 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 653: /* "JSONArrayConstructor" */

/* Line 480 of lalr1.cc  */
#line 815 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2769 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 654: /* "JSONSimpleObjectUnion" */

/* Line 480 of lalr1.cc  */
#line 815 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2778 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 655: /* "JSONAccumulatorObjectUnion" */

/* Line 480 of lalr1.cc  */
#line 815 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2787 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 656: /* "JSONObjectConstructor" */

/* Line 480 of lalr1.cc  */
#line 815 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2796 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 657: /* "JSONPairList" */

/* Line 480 of lalr1.cc  */
#line 815 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2805 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 658: /* "JSONInsertExpr" */

/* Line 480 of lalr1.cc  */
#line 815 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2814 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 659: /* "JSONAppendExpr" */

/* Line 480 of lalr1.cc  */
#line 815 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2823 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 660: /* "JSONDeleteExpr" */

/* Line 480 of lalr1.cc  */
#line 815 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2832 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 661: /* "JSONRenameExpr" */

/* Line 480 of lalr1.cc  */
#line 815 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2841 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 662: /* "JSONReplaceExpr" */

/* Line 480 of lalr1.cc  */
#line 815 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2850 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 665: /* "QNAME" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2859 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 666: /* "FUNCTION_NAME" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2868 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 667: /* "EQNAME" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2877 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
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
    
/* Line 565 of lalr1.cc  */
#line 128 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
{
    yylloc.begin.filename = yylloc.end.filename = &(driver.theFilename2);
}

/* Line 565 of lalr1.cc  */
#line 2974 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"

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

/* Line 690 of lalr1.cc  */
#line 854 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      }
    break;

  case 4:

/* Line 690 of lalr1.cc  */
#line 858 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      }
    break;

  case 5:

/* Line 690 of lalr1.cc  */
#line 862 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      }
    break;

  case 6:

/* Line 690 of lalr1.cc  */
#line 868 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.node) = NULL;
      }
    break;

  case 7:

/* Line 690 of lalr1.cc  */
#line 872 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.node) = NULL; YYABORT;
      }
    break;

  case 8:

/* Line 690 of lalr1.cc  */
#line 876 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.node) = NULL; YYABORT;
      }
    break;

  case 9:

/* Line 690 of lalr1.cc  */
#line 882 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 10:

/* Line 690 of lalr1.cc  */
#line 888 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      MainModule* mm = dynamic_cast<MainModule*>((yysemantic_stack_[(2) - (2)].node));
      mm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 11:

/* Line 690 of lalr1.cc  */
#line 896 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 12:

/* Line 690 of lalr1.cc  */
#line 902 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      LibraryModule* lm = dynamic_cast<LibraryModule*>((yysemantic_stack_[(2) - (2)].node));
      lm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 13:

/* Line 690 of lalr1.cc  */
#line 911 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), "utf-8" );
    }
    break;

  case 14:

/* Line 690 of lalr1.cc  */
#line 916 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );
    }
    break;

  case 15:

/* Line 690 of lalr1.cc  */
#line 921 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), "utf-8", VersionDecl::jsoniq );
    }
    break;

  case 16:

/* Line 690 of lalr1.cc  */
#line 926 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)), VersionDecl::jsoniq );
    }
    break;

  case 17:

/* Line 690 of lalr1.cc  */
#line 932 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (1)].node)), NULL);
      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(3) - (3)].expr)), prolog);
    }
    break;

  case 18:

/* Line 690 of lalr1.cc  */
#line 938 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (1)].node)));
      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(3) - (3)].expr)), prolog);
    }
    break;

  case 19:

/* Line 690 of lalr1.cc  */
#line 944 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)),
                                  static_cast<SIND_DeclList*>((yysemantic_stack_[(5) - (1)].node)),
                                  static_cast<VFO_DeclList*>((yysemantic_stack_[(5) - (3)].node)));
      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(5) - (5)].expr)), prolog);
    }
    break;

  case 20:

/* Line 690 of lalr1.cc  */
#line 952 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new MainModule( LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(1) - (1)].expr)), NULL );
    }
    break;

  case 21:

/* Line 690 of lalr1.cc  */
#line 957 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].expr);
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after statement.");
      YYERROR;
    }
    break;

  case 22:

/* Line 690 of lalr1.cc  */
#line 965 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].expr);
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 23:

/* Line 690 of lalr1.cc  */
#line 973 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(5) - (1)].node); (yyval.node) = (yysemantic_stack_[(5) - (3)].node); (yyval.node) = (yysemantic_stack_[(5) - (5)].expr);
      (yylocation_stack_[(5) - (3)]).step();
      error((yylocation_stack_[(5) - (3)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 24:

/* Line 690 of lalr1.cc  */
#line 981 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(5) - (1)].node); (yyval.node) = (yysemantic_stack_[(5) - (3)].node); (yyval.node) = (yysemantic_stack_[(5) - (5)].expr);
      (yylocation_stack_[(5) - (1)]).step();
      error((yylocation_stack_[(5) - (1)]), "syntax error, missing semicolon \";\" after statement.");
      YYERROR;
    }
    break;

  case 25:

/* Line 690 of lalr1.cc  */
#line 990 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(1) - (1)].node)), NULL);
    }
    break;

  case 26:

/* Line 690 of lalr1.cc  */
#line 995 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (2)].node)), NULL);
      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(3) - (1)].node)), prolog);
    }
    break;

  case 27:

/* Line 690 of lalr1.cc  */
#line 1001 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (2)].node)));
      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(3) - (1)].node)), prolog);
    }
    break;

  case 28:

/* Line 690 of lalr1.cc  */
#line 1007 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)),
                                  static_cast<SIND_DeclList*>((yysemantic_stack_[(5) - (2)].node)),
                                  static_cast<VFO_DeclList*>((yysemantic_stack_[(5) - (4)].node)));
      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(5) - (1)].node)), prolog);
    }
    break;

  case 29:

/* Line 690 of lalr1.cc  */
#line 1016 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      ERROR_IF_QNAME_NOT_NCNAME((yysemantic_stack_[(6) - (3)].expr), (yylocation_stack_[(6) - (3)]));
      (yyval.node) = new ModuleDecl( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );
      dynamic_cast<ModuleDecl*>((yyval.node))->setComment( SYMTAB((yysemantic_stack_[(6) - (1)].sval)) );
    }
    break;

  case 30:

/* Line 690 of lalr1.cc  */
#line 1024 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      SIND_DeclList *sdl = new SIND_DeclList( LOC((yyloc)) );
      sdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
      (yyval.node) = sdl;
    }
    break;

  case 31:

/* Line 690 of lalr1.cc  */
#line 1031 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      ((SIND_DeclList*)(yysemantic_stack_[(3) - (1)].node))->push_back( (yysemantic_stack_[(3) - (3)].node) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 32:

/* Line 690 of lalr1.cc  */
#line 1037 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 46:

/* Line 690 of lalr1.cc  */
#line 1063 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new BoundarySpaceDecl(LOC((yyloc)), StaticContextConsts::preserve_space);
    }
    break;

  case 47:

/* Line 690 of lalr1.cc  */
#line 1068 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new BoundarySpaceDecl(LOC((yyloc)), StaticContextConsts::strip_space);
    }
    break;

  case 48:

/* Line 690 of lalr1.cc  */
#line 1074 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DefaultCollationDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (4)].sval)) );
    }
    break;

  case 49:

/* Line 690 of lalr1.cc  */
#line 1080 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new BaseURIDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
    }
    break;

  case 50:

/* Line 690 of lalr1.cc  */
#line 1086 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new ConstructionDecl(LOC((yyloc)), StaticContextConsts::cons_preserve);
    }
    break;

  case 51:

/* Line 690 of lalr1.cc  */
#line 1091 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new ConstructionDecl(LOC((yyloc)), StaticContextConsts::cons_strip);
    }
    break;

  case 52:

/* Line 690 of lalr1.cc  */
#line 1097 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new OrderingModeDecl(LOC((yyloc)), StaticContextConsts::ordered);
    }
    break;

  case 53:

/* Line 690 of lalr1.cc  */
#line 1102 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new OrderingModeDecl(LOC((yyloc)), StaticContextConsts::unordered);
    }
    break;

  case 54:

/* Line 690 of lalr1.cc  */
#line 1108 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new EmptyOrderDecl(LOC((yyloc)), StaticContextConsts::empty_greatest);
    }
    break;

  case 55:

/* Line 690 of lalr1.cc  */
#line 1113 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new EmptyOrderDecl(LOC((yyloc)), StaticContextConsts::empty_least);
    }
    break;

  case 56:

/* Line 690 of lalr1.cc  */
#line 1119 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)), true, true);
    }
    break;

  case 57:

/* Line 690 of lalr1.cc  */
#line 1124 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)), true, false);
    }
    break;

  case 58:

/* Line 690 of lalr1.cc  */
#line 1129 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)), false, true);
    }
    break;

  case 59:

/* Line 690 of lalr1.cc  */
#line 1134 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)), false, false);
    }
    break;

  case 62:

/* Line 690 of lalr1.cc  */
#line 1144 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yyval.node);
      error((yylocation_stack_[(3) - (2)]), "syntax error, \"import\" should be followed by either \"schema\" or \"module\".");
      YYERROR;
    }
    break;

  case 63:

/* Line 690 of lalr1.cc  */
#line 1152 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SchemaImport( LOC((yyloc)), NULL, SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL );
    }
    break;

  case 64:

/* Line 690 of lalr1.cc  */
#line 1157 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(4) - (3)].node)),
                            SYMTAB((yysemantic_stack_[(4) - (4)].sval)),
                            NULL);
    }
    break;

  case 65:

/* Line 690 of lalr1.cc  */
#line 1165 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            NULL,
                            SYMTAB((yysemantic_stack_[(5) - (3)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 66:

/* Line 690 of lalr1.cc  */
#line 1173 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(6) - (3)].node)),
                            SYMTAB((yysemantic_stack_[(6) - (4)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(6) - (6)].node)));
    }
    break;

  case 67:

/* Line 690 of lalr1.cc  */
#line 1182 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      URILiteralList *ull = new URILiteralList( LOC((yyloc)));
      ull->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
      (yyval.node) = ull;
    }
    break;

  case 68:

/* Line 690 of lalr1.cc  */
#line 1189 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      if ( URILiteralList *ull = dynamic_cast<URILiteralList*>((yysemantic_stack_[(3) - (1)].node)) )
        ull->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 69:

/* Line 690 of lalr1.cc  */
#line 1197 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      ERROR_IF_QNAME_NOT_NCNAME((yysemantic_stack_[(3) - (2)].expr), (yylocation_stack_[(3) - (2)]));
      (yyval.node) = new SchemaPrefix( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)));
    }
    break;

  case 70:

/* Line 690 of lalr1.cc  */
#line 1203 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SchemaPrefix( LOC((yyloc)), true );
    }
    break;

  case 71:

/* Line 690 of lalr1.cc  */
#line 1209 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL);
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(3) - (2)].sval)));
    }
    break;

  case 72:

/* Line 690 of lalr1.cc  */
#line 1215 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      ERROR_IF_QNAME_NOT_NCNAME((yysemantic_stack_[(6) - (4)].expr), (yylocation_stack_[(6) - (4)]));
      (yyval.node) = new ModuleImport(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(6) - (4)].expr)), SYMTAB((yysemantic_stack_[(6) - (6)].sval)), NULL);
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(6) - (2)].sval)));
    }
    break;

  case 73:

/* Line 690 of lalr1.cc  */
#line 1222 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)),
                            SYMTAB((yysemantic_stack_[(5) - (3)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(5) - (2)].sval)));
    }
    break;

  case 74:

/* Line 690 of lalr1.cc  */
#line 1230 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      ERROR_IF_QNAME_NOT_NCNAME((yysemantic_stack_[(8) - (4)].expr), (yylocation_stack_[(8) - (4)]));
      (yyval.node) = new ModuleImport(LOC((yyloc)),
                            static_cast<QName*>((yysemantic_stack_[(8) - (4)].expr)),
                            SYMTAB((yysemantic_stack_[(8) - (6)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(8) - (8)].node)));
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(8) - (2)].sval)));
    }
    break;

  case 75:

/* Line 690 of lalr1.cc  */
#line 1241 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      ERROR_IF_QNAME_NOT_NCNAME((yysemantic_stack_[(5) - (3)].expr), (yylocation_stack_[(5) - (3)]));
      (yyval.node) = new NamespaceDecl( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (3)].expr)), SYMTAB((yysemantic_stack_[(5) - (5)].sval)) );
    }
    break;

  case 76:

/* Line 690 of lalr1.cc  */
#line 1248 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DefaultNamespaceDecl(LOC((yyloc)),
                                    ParseConstants::ns_element_default,
                                    SYMTAB((yysemantic_stack_[(5) - (5)].sval)));
    }
    break;

  case 77:

/* Line 690 of lalr1.cc  */
#line 1255 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DefaultNamespaceDecl(LOC((yyloc)),
                                    ParseConstants::ns_function_default,
                                    SYMTAB((yysemantic_stack_[(5) - (5)].sval)));
    }
    break;

  case 78:

/* Line 690 of lalr1.cc  */
#line 1263 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      VFO_DeclList *vdl = new VFO_DeclList( LOC((yyloc)));
      vdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
      (yyval.node) = vdl;
    }
    break;

  case 79:

/* Line 690 of lalr1.cc  */
#line 1270 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      ((VFO_DeclList*)(yysemantic_stack_[(3) - (1)].node))->push_back( (yysemantic_stack_[(3) - (3)].node) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 80:

/* Line 690 of lalr1.cc  */
#line 1276 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 89:

/* Line 690 of lalr1.cc  */
#line 1295 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DecimalFormatNode(LOC((yyloc)), (yysemantic_stack_[(4) - (4)].vstrpair));
      delete (yysemantic_stack_[(4) - (4)].vstrpair);
    }
    break;

  case 90:

/* Line 690 of lalr1.cc  */
#line 1301 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DecimalFormatNode(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), (yysemantic_stack_[(4) - (4)].vstrpair));
      delete (yysemantic_stack_[(4) - (4)].vstrpair);
    }
    break;

  case 91:

/* Line 690 of lalr1.cc  */
#line 1308 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.vstrpair) = new vector<string_pair_t>();
      (yyval.vstrpair)->push_back( *(yysemantic_stack_[(1) - (1)].strpair) );
      delete (yysemantic_stack_[(1) - (1)].strpair);
    }
    break;

  case 92:

/* Line 690 of lalr1.cc  */
#line 1315 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yysemantic_stack_[(2) - (1)].vstrpair)->push_back( *(yysemantic_stack_[(2) - (2)].strpair) );
      delete (yysemantic_stack_[(2) - (2)].strpair);
      (yyval.vstrpair) = (yysemantic_stack_[(2) - (1)].vstrpair);
    }
    break;

  case 93:

/* Line 690 of lalr1.cc  */
#line 1323 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      StringLiteral *sl = static_cast<StringLiteral*>((yysemantic_stack_[(3) - (3)].expr));
      (yyval.strpair) = new string_pair_t( (yysemantic_stack_[(3) - (1)].strval), sl->get_strval().str() );
      delete sl;
    }
    break;

  case 94:

/* Line 690 of lalr1.cc  */
#line 1330 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "decimal-separator"; }
    break;

  case 95:

/* Line 690 of lalr1.cc  */
#line 1331 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "digit"; }
    break;

  case 96:

/* Line 690 of lalr1.cc  */
#line 1332 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "grouping-separator"; }
    break;

  case 97:

/* Line 690 of lalr1.cc  */
#line 1333 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "infinity"; }
    break;

  case 98:

/* Line 690 of lalr1.cc  */
#line 1334 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "minus-sign"; }
    break;

  case 99:

/* Line 690 of lalr1.cc  */
#line 1335 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "NaN"; }
    break;

  case 100:

/* Line 690 of lalr1.cc  */
#line 1336 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "pattern-separator"; }
    break;

  case 101:

/* Line 690 of lalr1.cc  */
#line 1337 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "percent"; }
    break;

  case 102:

/* Line 690 of lalr1.cc  */
#line 1338 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "per-mille"; }
    break;

  case 103:

/* Line 690 of lalr1.cc  */
#line 1339 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "zero-digit"; }
    break;

  case 104:

/* Line 690 of lalr1.cc  */
#line 1343 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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

  case 105:

/* Line 690 of lalr1.cc  */
#line 1357 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new FTOptionDecl( LOC((yyloc)), dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (3)].node)) );
    }
    break;

  case 106:

/* Line 690 of lalr1.cc  */
#line 1363 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(4) - (4)].node);
    }
    break;

  case 107:

/* Line 690 of lalr1.cc  */
#line 1369 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      CtxItemDecl* d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(3) - (3)].node));
      d->theType = (yysemantic_stack_[(3) - (2)].node);
      (yyval.node) = d;
    }
    break;

  case 108:

/* Line 690 of lalr1.cc  */
#line 1376 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 109:

/* Line 690 of lalr1.cc  */
#line 1382 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      CtxItemDecl* d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(1) - (1)].node));
      d->theIsExternal = false;
      (yyval.node) = d;
    }
    break;

  case 110:

/* Line 690 of lalr1.cc  */
#line 1389 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CtxItemDecl(LOC((yyloc)), NULL);
    }
    break;

  case 111:

/* Line 690 of lalr1.cc  */
#line 1394 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 112:

/* Line 690 of lalr1.cc  */
#line 1400 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CtxItemDecl(LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 113:

/* Line 690 of lalr1.cc  */
#line 1406 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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

  case 114:

/* Line 690 of lalr1.cc  */
#line 1418 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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

  case 115:

/* Line 690 of lalr1.cc  */
#line 1430 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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

  case 116:

/* Line 690 of lalr1.cc  */
#line 1443 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)), NULL, NULL);
    }
    break;

  case 117:

/* Line 690 of lalr1.cc  */
#line 1448 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)),
                              dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (4)].node)),
                              NULL);
    }
    break;

  case 118:

/* Line 690 of lalr1.cc  */
#line 1456 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(4) - (4)].expr)),
                              NULL,
                              static_cast<AnnotationListParsenode*>((yysemantic_stack_[(4) - (1)].node)));
    }
    break;

  case 119:

/* Line 690 of lalr1.cc  */
#line 1464 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(5) - (4)].expr)),
                              dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (5)].node)),
                              static_cast<AnnotationListParsenode*>((yysemantic_stack_[(5) - (1)].node)));
    }
    break;

  case 120:

/* Line 690 of lalr1.cc  */
#line 1473 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AnnotationListParsenode(LOC((yyloc)), static_cast<AnnotationParsenode*>((yysemantic_stack_[(1) - (1)].node)));
    }
    break;

  case 121:

/* Line 690 of lalr1.cc  */
#line 1478 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      static_cast<AnnotationListParsenode*>((yysemantic_stack_[(2) - (1)].node))->push_back(static_cast<AnnotationParsenode*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 122:

/* Line 690 of lalr1.cc  */
#line 1485 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))), NULL);
    }
    break;

  case 123:

/* Line 690 of lalr1.cc  */
#line 1490 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)),
                                   new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (1)].sval))),
                                   static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 124:

/* Line 690 of lalr1.cc  */
#line 1497 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), true), NULL);
    }
    break;

  case 125:

/* Line 690 of lalr1.cc  */
#line 1502 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)),
                                   new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (1)].sval)), true),
                                   static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 126:

/* Line 690 of lalr1.cc  */
#line 1510 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AnnotationLiteralListParsenode(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr));
    }
    break;

  case 127:

/* Line 690 of lalr1.cc  */
#line 1515 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(3) - (1)].node))->push_back((yysemantic_stack_[(3) - (3)].expr));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 128:

/* Line 690 of lalr1.cc  */
#line 1522 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      static_cast<FunctionDecl*>((yysemantic_stack_[(2) - (2)].node))->setComment( SYMTAB((yysemantic_stack_[(2) - (1)].sval)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 129:

/* Line 690 of lalr1.cc  */
#line 1528 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      FunctionDecl* fdecl = static_cast<FunctionDecl*>((yysemantic_stack_[(3) - (3)].node));
      fdecl->setComment( SYMTAB((yysemantic_stack_[(3) - (1)].sval)) );
      fdecl->set_annotations(static_cast<AnnotationListParsenode*>((yysemantic_stack_[(3) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
    }
    break;

  case 132:

/* Line 690 of lalr1.cc  */
#line 1541 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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

  case 133:

/* Line 690 of lalr1.cc  */
#line 1552 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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

  case 134:

/* Line 690 of lalr1.cc  */
#line 1565 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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

  case 135:

/* Line 690 of lalr1.cc  */
#line 1577 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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

  case 136:

/* Line 690 of lalr1.cc  */
#line 1590 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(NULL);
    }
    break;

  case 137:

/* Line 690 of lalr1.cc  */
#line 1595 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (2)].node)));
    }
    break;

  case 138:

/* Line 690 of lalr1.cc  */
#line 1600 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(NULL, dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node)));
    }
    break;

  case 139:

/* Line 690 of lalr1.cc  */
#line 1605 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(dynamic_cast<ParamList*>((yysemantic_stack_[(5) - (2)].node)), dynamic_cast<SequenceType*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 140:

/* Line 690 of lalr1.cc  */
#line 1611 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      ParamList *pl = new ParamList( LOC((yyloc)) );
      pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = pl;
    }
    break;

  case 141:

/* Line 690 of lalr1.cc  */
#line 1618 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      if ( ParamList *pl = dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (1)].node)) )
        pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(3) - (3)].node)) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 142:

/* Line 690 of lalr1.cc  */
#line 1626 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL);
    }
    break;

  case 143:

/* Line 690 of lalr1.cc  */
#line 1631 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)),
                     static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                     dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 144:

/* Line 690 of lalr1.cc  */
#line 1639 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)),
                              NULL,
                              NULL);
      static_cast<CollectionDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(3) - (1)].sval)));
    }
    break;

  case 145:

/* Line 690 of lalr1.cc  */
#line 1647 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(5) - (3)].expr)),
                              0,
                              static_cast<SequenceType*>((yysemantic_stack_[(5) - (5)].node)));
      static_cast<CollectionDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(5) - (1)].sval)));
    }
    break;

  case 146:

/* Line 690 of lalr1.cc  */
#line 1655 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                               static_cast<QName*>((yysemantic_stack_[(4) - (4)].expr)),
                               static_cast<AnnotationListParsenode*>((yysemantic_stack_[(4) - (2)].node)),
                               0);
      static_cast<CollectionDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(4) - (1)].sval)));
    }
    break;

  case 147:

/* Line 690 of lalr1.cc  */
#line 1663 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                               static_cast<QName*>((yysemantic_stack_[(6) - (4)].expr)),
                               static_cast<AnnotationListParsenode*>((yysemantic_stack_[(6) - (2)].node)),
                               static_cast<SequenceType*>((yysemantic_stack_[(6) - (6)].node)));
      static_cast<CollectionDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(6) - (1)].sval)));
    }
    break;

  case 148:

/* Line 690 of lalr1.cc  */
#line 1673 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL));
    }
    break;

  case 149:

/* Line 690 of lalr1.cc  */
#line 1677 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)),
                                                    (yysemantic_stack_[(2) - (1)].node),
                                                    dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node))));
    }
    break;

  case 150:

/* Line 690 of lalr1.cc  */
#line 1683 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL));
    }
    break;

  case 151:

/* Line 690 of lalr1.cc  */
#line 1687 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)),
                                                    (yysemantic_stack_[(2) - (1)].node),
                                                    dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node))));
    }
    break;

  case 152:

/* Line 690 of lalr1.cc  */
#line 1694 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 1703 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 1714 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      IndexKeyList* keyList = new IndexKeyList(LOC((yyloc)));
      keyList->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = keyList;
    }
    break;

  case 155:

/* Line 690 of lalr1.cc  */
#line 1720 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      dynamic_cast<IndexKeyList*>((yysemantic_stack_[(3) - (1)].node))->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 156:

/* Line 690 of lalr1.cc  */
#line 1727 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL, NULL);
    }
    break;

  case 157:

/* Line 690 of lalr1.cc  */
#line 1732 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            dynamic_cast<SequenceType*>((yysemantic_stack_[(2) - (2)].node)),
                            NULL);
    }
    break;

  case 158:

/* Line 690 of lalr1.cc  */
#line 1739 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            NULL,
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
    }
    break;

  case 159:

/* Line 690 of lalr1.cc  */
#line 1746 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(3) - (1)].expr),
                            dynamic_cast<SequenceType*>((yysemantic_stack_[(3) - (2)].node)),
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 160:

/* Line 690 of lalr1.cc  */
#line 1756 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new ICCollSimpleCheck(LOC((yyloc)),
                                 static_cast<QName*>((yysemantic_stack_[(11) - (4)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(11) - (7)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(11) - (9)].expr)),
                                 (yysemantic_stack_[(11) - (11)].expr));
    }
    break;

  case 161:

/* Line 690 of lalr1.cc  */
#line 1766 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new ICCollUniqueKeyCheck(LOC((yyloc)),
                                    static_cast<QName*>((yysemantic_stack_[(14) - (4)].expr)),
                                    static_cast<QName*>((yysemantic_stack_[(14) - (7)].expr)),
                                    static_cast<QName*>((yysemantic_stack_[(14) - (10)].expr)),
                                    (yysemantic_stack_[(14) - (14)].expr));
    }
    break;

  case 162:

/* Line 690 of lalr1.cc  */
#line 1776 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new ICCollForeachNode(LOC((yyloc)),
                                 static_cast<QName*>((yysemantic_stack_[(13) - (4)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(13) - (7)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(13) - (11)].expr)),
                                 (yysemantic_stack_[(13) - (13)].expr));
    }
    break;

  case 163:

/* Line 690 of lalr1.cc  */
#line 1787 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 1800 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 1816 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 166:

/* Line 690 of lalr1.cc  */
#line 1820 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 167:

/* Line 690 of lalr1.cc  */
#line 1824 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = NULL;
    }
    break;

  case 168:

/* Line 690 of lalr1.cc  */
#line 1830 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 169:

/* Line 690 of lalr1.cc  */
#line 1834 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 170:

/* Line 690 of lalr1.cc  */
#line 1838 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new BlockBody(LOC((yyloc)));
    }
    break;

  case 171:

/* Line 690 of lalr1.cc  */
#line 1844 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 172:

/* Line 690 of lalr1.cc  */
#line 1849 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      BlockBody* blk = static_cast<BlockBody*>((yysemantic_stack_[(2) - (1)].expr));
      blk->add((yysemantic_stack_[(2) - (2)].expr));
      (yyval.expr) = blk;
    }
    break;

  case 173:

/* Line 690 of lalr1.cc  */
#line 1857 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      BlockBody* blk = new BlockBody(LOC((yyloc)));
      blk->add((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = blk;
    }
    break;

  case 174:

/* Line 690 of lalr1.cc  */
#line 1864 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      BlockBody* blk = static_cast<BlockBody*>((yysemantic_stack_[(2) - (1)].expr));
      blk->add((yysemantic_stack_[(2) - (2)].expr));
      (yyval.expr) = blk;
    }
    break;

  case 175:

/* Line 690 of lalr1.cc  */
#line 1871 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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

  case 189:

/* Line 690 of lalr1.cc  */
#line 1899 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 190:

/* Line 690 of lalr1.cc  */
#line 1905 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      BlockBody* block = dynamic_cast<BlockBody*>((yysemantic_stack_[(3) - (2)].expr));
      if ((yysemantic_stack_[(3) - (2)].expr) == NULL || (block != NULL && block->isEmpty()))
      {
        driver.addCommonLanguageWarning((yylocation_stack_[(3) - (1)]), ZED(ZWST0009_EMPTY_OBJECT));
        (yyval.expr) = new JSONDirectObjectConstructor(LOC((yyloc)));
      }
      else
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

  case 191:

/* Line 690 of lalr1.cc  */
#line 1927 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 192:

/* Line 690 of lalr1.cc  */
#line 1933 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    }
    break;

  case 193:

/* Line 690 of lalr1.cc  */
#line 1939 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      VarDeclStmt* vdecl = static_cast<VarDeclStmt*>((yysemantic_stack_[(3) - (1)].expr));
      vdecl->add((yysemantic_stack_[(3) - (3)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 194:

/* Line 690 of lalr1.cc  */
#line 1946 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      VarDeclStmt* vdecl = new VarDeclStmt(LOC((yyloc)), NULL);
      vdecl->add((yysemantic_stack_[(2) - (2)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 195:

/* Line 690 of lalr1.cc  */
#line 1953 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      VarDeclStmt* vdecl = new VarDeclStmt(LOC((yyloc)),
                                           static_cast<AnnotationListParsenode*>((yysemantic_stack_[(3) - (1)].node)));
      vdecl->add((yysemantic_stack_[(3) - (3)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 196:

/* Line 690 of lalr1.cc  */
#line 1962 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      LocalVarDecl* vd = new LocalVarDecl(LOC((yyloc)),
                                          static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)),
                                          NULL,
                                          NULL,
                                          NULL);
      (yyval.node) = vd;
    }
    break;

  case 197:

/* Line 690 of lalr1.cc  */
#line 1971 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      LocalVarDecl* vd = new LocalVarDecl(LOC((yyloc)),
                                          static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                                          dynamic_cast<SequenceType*>((yysemantic_stack_[(3) - (3)].node)),
                                          NULL,
                                          NULL);
      (yyval.node) = vd;
    }
    break;

  case 198:

/* Line 690 of lalr1.cc  */
#line 1980 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      LocalVarDecl* vd = new LocalVarDecl(LOC((yyloc)),
                                          static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                                          NULL,
                                          (yysemantic_stack_[(4) - (4)].expr),
                                          NULL);
      (yyval.node) = vd;
    }
    break;

  case 199:

/* Line 690 of lalr1.cc  */
#line 1989 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      LocalVarDecl* vd = new LocalVarDecl(LOC((yyloc)),
                                          static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                                          dynamic_cast<SequenceType*>((yysemantic_stack_[(5) - (3)].node)),
                                          (yysemantic_stack_[(5) - (5)].expr),
                                          NULL);
      (yyval.node) = vd;
    }
    break;

  case 200:

/* Line 690 of lalr1.cc  */
#line 2000 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new AssignExpr(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)), (yysemantic_stack_[(5) - (4)].expr));
    }
    break;

  case 201:

/* Line 690 of lalr1.cc  */
#line 2006 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new ApplyExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr));
    }
    break;

  case 202:

/* Line 690 of lalr1.cc  */
#line 2012 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new ExitExpr(LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr));
    }
    break;

  case 203:

/* Line 690 of lalr1.cc  */
#line 2018 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 2030 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement(LOC((yyloc)), FlowCtlStatement::BREAK);
    }
    break;

  case 205:

/* Line 690 of lalr1.cc  */
#line 2035 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement( LOC((yyloc)), FlowCtlStatement::CONTINUE );
    }
    break;

  case 206:

/* Line 690 of lalr1.cc  */
#line 2041 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 2053 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 2066 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 2086 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new TryExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 210:

/* Line 690 of lalr1.cc  */
#line 2092 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      CatchListExpr* cle = new CatchListExpr( LOC((yyloc)) );
      cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)) );
      (yyval.expr) = cle;
    }
    break;

  case 211:

/* Line 690 of lalr1.cc  */
#line 2099 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
      if ( cle )
        cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)) );
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    }
    break;

  case 212:

/* Line 690 of lalr1.cc  */
#line 2108 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)), *(yysemantic_stack_[(3) - (2)].name_test_list), (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 213:

/* Line 690 of lalr1.cc  */
#line 2115 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new BlockBody(LOC((yyloc)));
    }
    break;

  case 214:

/* Line 690 of lalr1.cc  */
#line 2121 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 215:

/* Line 690 of lalr1.cc  */
#line 2126 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 2138 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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

  case 235:

/* Line 690 of lalr1.cc  */
#line 2172 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 2184 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new ReturnExpr( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr) );
    }
    break;

  case 237:

/* Line 690 of lalr1.cc  */
#line 2190 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.strval) = parser::the_sliding;
    }
    break;

  case 238:

/* Line 690 of lalr1.cc  */
#line 2195 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.strval) = parser::the_tumbling;
    }
    break;

  case 239:

/* Line 690 of lalr1.cc  */
#line 2201 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.strval) = parser::the_start;
    }
    break;

  case 240:

/* Line 690 of lalr1.cc  */
#line 2206 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.strval) = parser::the_end;
    }
    break;

  case 241:

/* Line 690 of lalr1.cc  */
#line 2211 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
    (yyval.strval) = parser::the_only_end;
  }
    break;

  case 242:

/* Line 690 of lalr1.cc  */
#line 2217 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new FLWORWinCond(LOC((yyloc)),
                            dynamic_cast<WindowVars*>((yysemantic_stack_[(4) - (2)].node)),
                            (yysemantic_stack_[(4) - (4)].expr),
                            (yysemantic_stack_[(4) - (1)].strval) == parser::the_start,
                            (yysemantic_stack_[(4) - (1)].strval) == parser::the_only_end);
    }
    break;

  case 243:

/* Line 690 of lalr1.cc  */
#line 2226 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new FLWORWinCond(LOC((yyloc)),
                            NULL,
                            (yysemantic_stack_[(3) - (3)].expr),
                            (yysemantic_stack_[(3) - (1)].strval) == parser::the_start,
                            (yysemantic_stack_[(3) - (1)].strval) == parser::the_only_end);
    }
    break;

  case 244:

/* Line 690 of lalr1.cc  */
#line 2237 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 2249 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 2260 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CountClause(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 255:

/* Line 690 of lalr1.cc  */
#line 2278 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      FLWORClauseList *fcl = new FLWORClauseList( LOC((yyloc)) );
      fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = fcl;
    }
    break;

  case 256:

/* Line 690 of lalr1.cc  */
#line 2285 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      FLWORClauseList *fcl = dynamic_cast<FLWORClauseList*>((yysemantic_stack_[(2) - (1)].node));
      fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = fcl;
    }
    break;

  case 257:

/* Line 690 of lalr1.cc  */
#line 2294 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new ForClause(LOC((yyloc)), dynamic_cast<VarInDeclList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 258:

/* Line 690 of lalr1.cc  */
#line 2298 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      error((yylocation_stack_[(3) - (2)]), "syntax error, unexpected qualified name \""
          + static_cast<VarInDeclList*>((yysemantic_stack_[(3) - (3)].node))->operator[](0)->get_var_name()->get_qname().str() + "\" (missing \"$\" sign?)");
      delete (yysemantic_stack_[(3) - (3)].node);
      YYERROR;
    }
    break;

  case 259:

/* Line 690 of lalr1.cc  */
#line 2306 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      error((yylocation_stack_[(3) - (2)]), "syntax error, unexpected qualified name \""
          + static_cast<VarInDeclList*>((yysemantic_stack_[(3) - (3)].node))->operator[](0)->get_var_name()->get_qname().str() + "\" (missing \"$\" sign?)");
      delete (yysemantic_stack_[(3) - (3)].node);
      YYERROR;
    }
    break;

  case 260:

/* Line 690 of lalr1.cc  */
#line 2316 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = NULL;
      error((yylocation_stack_[(2) - (2)]), "");
      YYERROR;
    }
    break;

  case 262:

/* Line 690 of lalr1.cc  */
#line 2325 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
    }
    break;

  case 263:

/* Line 690 of lalr1.cc  */
#line 2330 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      VarInDeclList* vdl = new VarInDeclList( LOC((yyloc)) );
      vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = vdl;
    }
    break;

  case 264:

/* Line 690 of lalr1.cc  */
#line 2337 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      if ( VarInDeclList* vdl = dynamic_cast<VarInDeclList*>((yysemantic_stack_[(4) - (1)].node)) )
        vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
      (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
    }
    break;

  case 265:

/* Line 690 of lalr1.cc  */
#line 2344 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
      error((yylocation_stack_[(3) - (3)]), "syntax error, unexpected QName \""
          + static_cast<VarInDecl*>((yysemantic_stack_[(3) - (3)].node))->get_var_name()->get_qname().str() + "\" (missing \"$\" sign?)");
      delete (yysemantic_stack_[(3) - (1)].node);
      YYERROR;
    }
    break;

  case 266:

/* Line 690 of lalr1.cc  */
#line 2354 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 2364 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 2374 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 2384 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 2394 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 2404 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 2414 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 2424 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 2434 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 2443 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 2453 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 2463 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 2475 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new PositionalVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 279:

/* Line 690 of lalr1.cc  */
#line 2481 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new FTScoreVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 280:

/* Line 690 of lalr1.cc  */
#line 2487 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new LetClause( LOC((yyloc)), dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(2) - (2)].node)) );
        }
    break;

  case 281:

/* Line 690 of lalr1.cc  */
#line 2493 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            VarGetsDeclList *vgdl = new VarGetsDeclList( LOC((yyloc)) );
            vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = vgdl;
        }
    break;

  case 282:

/* Line 690 of lalr1.cc  */
#line 2499 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            if( VarGetsDeclList *vgdl = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(3) - (1)].node)) )
                vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 283:

/* Line 690 of lalr1.cc  */
#line 2507 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                           NULL,
                           NULL,
                           (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 284:

/* Line 690 of lalr1.cc  */
#line 2515 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                           dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (3)].node)),
                           NULL,
                           (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 285:

/* Line 690 of lalr1.cc  */
#line 2523 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(3) - (1)].node))->get_var_name(),
                           NULL,
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(3) - (1)].node)),
                           (yysemantic_stack_[(3) - (3)].expr));
     }
    break;

  case 286:

/* Line 690 of lalr1.cc  */
#line 2531 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                           dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (3)].node)),
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(6) - (4)].node)),
                           (yysemantic_stack_[(6) - (6)].expr));
    }
    break;

  case 287:

/* Line 690 of lalr1.cc  */
#line 2541 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                             NULL, (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 288:

/* Line 690 of lalr1.cc  */
#line 2547 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                             dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (3)].node)),
                             (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 290:

/* Line 690 of lalr1.cc  */
#line 2557 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL, NULL);
    }
    break;

  case 291:

/* Line 690 of lalr1.cc  */
#line 2561 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_curr(static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)));
    }
    break;

  case 292:

/* Line 690 of lalr1.cc  */
#line 2568 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), dynamic_cast<PositionalVar*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL, NULL);
    }
    break;

  case 293:

/* Line 690 of lalr1.cc  */
#line 2572 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_posvar(dynamic_cast<PositionalVar*>((yysemantic_stack_[(2) - (1)].node)));
    }
    break;

  case 295:

/* Line 690 of lalr1.cc  */
#line 2580 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), static_cast<QName*>((yysemantic_stack_[(6) - (6)].expr)));
    }
    break;

  case 296:

/* Line 690 of lalr1.cc  */
#line 2584 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 297:

/* Line 690 of lalr1.cc  */
#line 2588 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)), NULL);
    }
    break;

  case 298:

/* Line 690 of lalr1.cc  */
#line 2594 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new WhereClause(LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 299:

/* Line 690 of lalr1.cc  */
#line 2600 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new GroupByClause(LOC((yyloc)), dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 300:

/* Line 690 of lalr1.cc  */
#line 2606 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      GroupSpecList* gsl = new GroupSpecList(LOC((yyloc)));
      gsl->push_back(static_cast<GroupSpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = gsl;
    }
    break;

  case 301:

/* Line 690 of lalr1.cc  */
#line 2612 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      GroupSpecList* gsl = static_cast<GroupSpecList*>((yysemantic_stack_[(3) - (1)].node));
      gsl->push_back(static_cast<GroupSpec*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = gsl;
    }
    break;

  case 302:

/* Line 690 of lalr1.cc  */
#line 2620 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)), NULL, (yysemantic_stack_[(4) - (4)].expr), NULL);
    }
    break;

  case 303:

/* Line 690 of lalr1.cc  */
#line 2624 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                         static_cast<SequenceType*>((yysemantic_stack_[(5) - (3)].node)),
                         (yysemantic_stack_[(5) - (5)].expr),
                         NULL);
    }
    break;

  case 304:

/* Line 690 of lalr1.cc  */
#line 2632 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                         static_cast<SequenceType*>((yysemantic_stack_[(6) - (3)].node)),
                         (yysemantic_stack_[(6) - (5)].expr),
                         static_cast<GroupCollationSpec*>((yysemantic_stack_[(6) - (6)].node)));
    }
    break;

  case 305:

/* Line 690 of lalr1.cc  */
#line 2640 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                         NULL,
                         (yysemantic_stack_[(5) - (4)].expr),
                         static_cast<GroupCollationSpec*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 306:

/* Line 690 of lalr1.cc  */
#line 2648 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      VarRef* varRef = dynamic_cast<VarRef*>((yysemantic_stack_[(1) - (1)].expr));
      if (varRef != NULL)
        (yyval.node) = new GroupSpec(LOC((yyloc)), varRef, NULL, NULL, NULL);
      else
        (yyval.node) = new GroupSpec(LOC((yyloc)), NULL, NULL, (yysemantic_stack_[(1) - (1)].expr), NULL);
    }
    break;

  case 307:

/* Line 690 of lalr1.cc  */
#line 2656 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      VarRef* varRef = dynamic_cast<VarRef*>((yysemantic_stack_[(2) - (1)].expr));
      if (varRef != NULL)
        (yyval.node) = new GroupSpec(LOC((yyloc)), varRef, NULL, NULL, static_cast<GroupCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
      else
        (yyval.node) = new GroupSpec(LOC((yyloc)), NULL, NULL, (yysemantic_stack_[(2) - (1)].expr), static_cast<GroupCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
    }
    break;

  case 308:

/* Line 690 of lalr1.cc  */
#line 2666 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new GroupCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
    }
    break;

  case 309:

/* Line 690 of lalr1.cc  */
#line 2672 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 310:

/* Line 690 of lalr1.cc  */
#line 2678 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(4) - (4)].node)), true
            );
        }
    break;

  case 311:

/* Line 690 of lalr1.cc  */
#line 2686 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            OrderSpecList *osl = new OrderSpecList( LOC((yyloc)) );
            osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = osl;
        }
    break;

  case 312:

/* Line 690 of lalr1.cc  */
#line 2692 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            if ( OrderSpecList* osl = dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (1)].node)) )
                osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 313:

/* Line 690 of lalr1.cc  */
#line 2700 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderSpec( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL );
        }
    break;

  case 314:

/* Line 690 of lalr1.cc  */
#line 2704 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderSpec(
                LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<OrderModifierPN*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 315:

/* Line 690 of lalr1.cc  */
#line 2712 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL
            );
        }
    break;

  case 316:

/* Line 690 of lalr1.cc  */
#line 2718 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 317:

/* Line 690 of lalr1.cc  */
#line 2724 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, NULL, dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 318:

/* Line 690 of lalr1.cc  */
#line 2730 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 2739 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 2748 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 2757 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 2768 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_ascending );
        }
    break;

  case 323:

/* Line 690 of lalr1.cc  */
#line 2772 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_descending );
        }
    break;

  case 324:

/* Line 690 of lalr1.cc  */
#line 2778 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_greatest
            );
        }
    break;

  case 325:

/* Line 690 of lalr1.cc  */
#line 2784 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_least
            );
        }
    break;

  case 326:

/* Line 690 of lalr1.cc  */
#line 2792 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 327:

/* Line 690 of lalr1.cc  */
#line 2798 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 2807 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 2818 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      QVarInDeclList *qvidl = new QVarInDeclList( LOC((yyloc)) );
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = qvidl;
    }
    break;

  case 330:

/* Line 690 of lalr1.cc  */
#line 2824 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      QVarInDeclList *qvidl = dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
      (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
    }
    break;

  case 331:

/* Line 690 of lalr1.cc  */
#line 2832 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 332:

/* Line 690 of lalr1.cc  */
#line 2836 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                          dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 333:

/* Line 690 of lalr1.cc  */
#line 2845 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new SwitchExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(8) - (5)].node)), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 334:

/* Line 690 of lalr1.cc  */
#line 2851 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = new SwitchCaseClauseList(LOC((yyloc)));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = scc_list_p;
    }
    break;

  case 335:

/* Line 690 of lalr1.cc  */
#line 2857 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 336:

/* Line 690 of lalr1.cc  */
#line 2865 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SwitchCaseClause(LOC((yyloc)), dynamic_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 337:

/* Line 690 of lalr1.cc  */
#line 2871 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = new SwitchCaseOperandList(LOC((yyloc)));
      sco_list_p->push_back((yysemantic_stack_[(2) - (2)].expr));
      (yyval.node) = sco_list_p;
    }
    break;

  case 338:

/* Line 690 of lalr1.cc  */
#line 2877 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = static_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node));
      sco_list_p->push_back((yysemantic_stack_[(3) - (3)].expr));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 339:

/* Line 690 of lalr1.cc  */
#line 2885 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new SwitchExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(8) - (5)].node)), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 340:

/* Line 690 of lalr1.cc  */
#line 2891 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = new SwitchCaseClauseList(LOC((yyloc)));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = scc_list_p;
    }
    break;

  case 341:

/* Line 690 of lalr1.cc  */
#line 2897 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 342:

/* Line 690 of lalr1.cc  */
#line 2905 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SwitchCaseClause(LOC((yyloc)), dynamic_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 343:

/* Line 690 of lalr1.cc  */
#line 2911 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC((yyloc)),
                              (yysemantic_stack_[(8) - (3)].expr),
                              static_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
                              (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 344:

/* Line 690 of lalr1.cc  */
#line 2918 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
                              (yysemantic_stack_[(10) - (3)].expr),
                              static_cast<CaseClauseList*>((yysemantic_stack_[(10) - (5)].node)),
                              static_cast<QName*>((yysemantic_stack_[(10) - (8)].expr)),
                              (yysemantic_stack_[(10) - (10)].expr));
    }
    break;

  case 345:

/* Line 690 of lalr1.cc  */
#line 2928 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC((yyloc)),
                              (yysemantic_stack_[(8) - (3)].expr),
                              static_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
                              (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 346:

/* Line 690 of lalr1.cc  */
#line 2935 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
                              (yysemantic_stack_[(10) - (3)].expr),
                              static_cast<CaseClauseList*>((yysemantic_stack_[(10) - (5)].node)),
                              static_cast<QName*>((yysemantic_stack_[(10) - (8)].expr)),
                              (yysemantic_stack_[(10) - (10)].expr));
    }
    break;

  case 347:

/* Line 690 of lalr1.cc  */
#line 2945 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
      cc_list_p->push_back(static_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = cc_list_p;
    }
    break;

  case 348:

/* Line 690 of lalr1.cc  */
#line 2951 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      cc_list_p->push_back(static_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 349:

/* Line 690 of lalr1.cc  */
#line 2959 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<SequenceTypeList*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 350:

/* Line 690 of lalr1.cc  */
#line 2965 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                          static_cast<SequenceTypeList*>((yysemantic_stack_[(7) - (5)].node)),
                          (yysemantic_stack_[(7) - (7)].expr));
     }
    break;

  case 351:

/* Line 690 of lalr1.cc  */
#line 2974 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
      cc_list_p->push_back(static_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = cc_list_p;
    }
    break;

  case 352:

/* Line 690 of lalr1.cc  */
#line 2980 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      CaseClauseList* cc_list_p = static_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      cc_list_p->push_back(static_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 353:

/* Line 690 of lalr1.cc  */
#line 2988 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<SequenceTypeList*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 354:

/* Line 690 of lalr1.cc  */
#line 2994 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                          static_cast<SequenceTypeList*>((yysemantic_stack_[(7) - (5)].node)),
                          (yysemantic_stack_[(7) - (7)].expr));
     }
    break;

  case 355:

/* Line 690 of lalr1.cc  */
#line 3003 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      SequenceTypeList* seqList = new SequenceTypeList(LOC((yyloc)));
      seqList->push_back(static_cast<SequenceType*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = seqList;
    }
    break;

  case 356:

/* Line 690 of lalr1.cc  */
#line 3009 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      SequenceTypeList* seqList = static_cast<SequenceTypeList*>((yysemantic_stack_[(3) - (1)].node));
      seqList->push_back(static_cast<SequenceType*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 357:

/* Line 690 of lalr1.cc  */
#line 3017 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new IfExpr(LOC ((yyloc)), (yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (6)].expr), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 358:

/* Line 690 of lalr1.cc  */
#line 3023 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 359:

/* Line 690 of lalr1.cc  */
#line 3027 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new OrExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
    }
    break;

  case 360:

/* Line 690 of lalr1.cc  */
#line 3033 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 361:

/* Line 690 of lalr1.cc  */
#line 3038 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new AndExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 362:

/* Line 690 of lalr1.cc  */
#line 3044 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 363:

/* Line 690 of lalr1.cc  */
#line 3048 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 3059 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 365:

/* Line 690 of lalr1.cc  */
#line 3063 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 3072 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)), dynamic_cast<NodeComp*>((yysemantic_stack_[(3) - (2)].node)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 367:

/* Line 690 of lalr1.cc  */
#line 3078 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 3087 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 3096 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            driver.getJsoniqLexer()->interpretAsLessThan();
        }
    break;

  case 370:

/* Line 690 of lalr1.cc  */
#line 3100 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 3109 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 3118 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 3127 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 3138 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 375:

/* Line 690 of lalr1.cc  */
#line 3142 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 3153 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 377:

/* Line 690 of lalr1.cc  */
#line 3157 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new StringConcatExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
        }
    break;

  case 378:

/* Line 690 of lalr1.cc  */
#line 3162 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 379:

/* Line 690 of lalr1.cc  */
#line 3166 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 380:

/* Line 690 of lalr1.cc  */
#line 3172 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 381:

/* Line 690 of lalr1.cc  */
#line 3176 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new RangeExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 382:

/* Line 690 of lalr1.cc  */
#line 3182 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 383:

/* Line 690 of lalr1.cc  */
#line 3186 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_plus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 384:

/* Line 690 of lalr1.cc  */
#line 3190 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_minus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 385:

/* Line 690 of lalr1.cc  */
#line 3196 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 386:

/* Line 690 of lalr1.cc  */
#line 3200 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mul, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 387:

/* Line 690 of lalr1.cc  */
#line 3206 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_div, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 388:

/* Line 690 of lalr1.cc  */
#line 3212 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_idiv, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 389:

/* Line 690 of lalr1.cc  */
#line 3218 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mod, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 390:

/* Line 690 of lalr1.cc  */
#line 3226 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 391:

/* Line 690 of lalr1.cc  */
#line 3230 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 392:

/* Line 690 of lalr1.cc  */
#line 3234 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 393:

/* Line 690 of lalr1.cc  */
#line 3240 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 394:

/* Line 690 of lalr1.cc  */
#line 3244 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_intersect, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 395:

/* Line 690 of lalr1.cc  */
#line 3250 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_except, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 396:

/* Line 690 of lalr1.cc  */
#line 3258 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 397:

/* Line 690 of lalr1.cc  */
#line 3262 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InstanceofExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 398:

/* Line 690 of lalr1.cc  */
#line 3270 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 399:

/* Line 690 of lalr1.cc  */
#line 3274 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new TreatExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 400:

/* Line 690 of lalr1.cc  */
#line 3282 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 401:

/* Line 690 of lalr1.cc  */
#line 3286 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new CastableExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 402:

/* Line 690 of lalr1.cc  */
#line 3294 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 403:

/* Line 690 of lalr1.cc  */
#line 3298 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new CastExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 404:

/* Line 690 of lalr1.cc  */
#line 3306 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SingleType(LOC((yyloc)), dynamic_cast<SimpleType*>((yysemantic_stack_[(1) - (1)].node)), false);
    }
    break;

  case 405:

/* Line 690 of lalr1.cc  */
#line 3310 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SingleType(LOC((yyloc)), dynamic_cast<SimpleType*>((yysemantic_stack_[(2) - (1)].node)), true);
    }
    break;

  case 406:

/* Line 690 of lalr1.cc  */
#line 3316 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 407:

/* Line 690 of lalr1.cc  */
#line 3320 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new UnaryExpr( LOC((yyloc)), dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 408:

/* Line 690 of lalr1.cc  */
#line 3326 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), true );
        }
    break;

  case 409:

/* Line 690 of lalr1.cc  */
#line 3330 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), false );
        }
    break;

  case 410:

/* Line 690 of lalr1.cc  */
#line 3334 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 411:

/* Line 690 of lalr1.cc  */
#line 3338 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            if ( SignList *sl = dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)) )
                sl->negate();
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 415:

/* Line 690 of lalr1.cc  */
#line 3351 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
      }
    break;

  case 416:

/* Line 690 of lalr1.cc  */
#line 3356 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.expr) = new SimpleMapExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
      }
    break;

  case 417:

/* Line 690 of lalr1.cc  */
#line 3362 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_eq );
        }
    break;

  case 418:

/* Line 690 of lalr1.cc  */
#line 3366 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ne );
        }
    break;

  case 419:

/* Line 690 of lalr1.cc  */
#line 3370 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_lt );
        }
    break;

  case 420:

/* Line 690 of lalr1.cc  */
#line 3374 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_le );
        }
    break;

  case 421:

/* Line 690 of lalr1.cc  */
#line 3378 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_gt );
        }
    break;

  case 422:

/* Line 690 of lalr1.cc  */
#line 3382 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ge );
        }
    break;

  case 423:

/* Line 690 of lalr1.cc  */
#line 3388 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_is );
        }
    break;

  case 424:

/* Line 690 of lalr1.cc  */
#line 3392 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_precedes );
        }
    break;

  case 425:

/* Line 690 of lalr1.cc  */
#line 3396 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_follows );
        }
    break;

  case 426:

/* Line 690 of lalr1.cc  */
#line 3402 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 427:

/* Line 690 of lalr1.cc  */
#line 3406 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "lax", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 428:

/* Line 690 of lalr1.cc  */
#line 3410 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 429:

/* Line 690 of lalr1.cc  */
#line 3414 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ValidateExpr(
                LOC((yyloc)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (3)].node))->get_name(), (yysemantic_stack_[(6) - (5)].expr)
            );
            delete (yysemantic_stack_[(6) - (3)].node);
        }
    break;

  case 430:

/* Line 690 of lalr1.cc  */
#line 3423 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(3) - (1)].node)), NULL
            );
        }
    break;

  case 431:

/* Line 690 of lalr1.cc  */
#line 3429 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)), (yysemantic_stack_[(4) - (3)].expr)
            );
        }
    break;

  case 432:

/* Line 690 of lalr1.cc  */
#line 3437 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            PragmaList *pl = new PragmaList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = pl;
        }
    break;

  case 433:

/* Line 690 of lalr1.cc  */
#line 3443 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            if ( PragmaList *pl = dynamic_cast<PragmaList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 434:

/* Line 690 of lalr1.cc  */
#line 3451 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
        }
    break;

  case 435:

/* Line 690 of lalr1.cc  */
#line 3455 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) ), "" );
        }
    break;

  case 436:

/* Line 690 of lalr1.cc  */
#line 3459 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), true ), "" );
        }
    break;

  case 437:

/* Line 690 of lalr1.cc  */
#line 3465 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new PathExpr(LOC((yyloc)), ParseConstants::path_leading_lone_slash, NULL);
    }
    break;

  case 438:

/* Line 690 of lalr1.cc  */
#line 3469 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      RelativePathExpr* rpe;
      rpe = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slash, NULL, (yysemantic_stack_[(2) - (2)].expr), false);
      (yyval.expr) = new PathExpr(LOC((yyloc)),
                        ParseConstants::path_leading_slash,
                        rpe);
    }
    break;

  case 439:

/* Line 690 of lalr1.cc  */
#line 3477 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      RelativePathExpr* rpe;
      rpe = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slashslash, NULL, (yysemantic_stack_[(2) - (2)].expr), false);
      (yyval.expr) = new PathExpr(LOC((yyloc)),
                        ParseConstants::path_leading_slashslash,
                        rpe);
    }
    break;

  case 440:

/* Line 690 of lalr1.cc  */
#line 3485 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      RelativePathExpr* rpe = dynamic_cast<RelativePathExpr*>((yysemantic_stack_[(1) - (1)].expr));
      if (rpe != NULL &&
          ((dynamic_cast<ContextItemExpr*>(rpe->get_step_expr()) != NULL &&
           dynamic_cast<ContextItemExpr*>(rpe->get_step_expr())->is_placeholder() &&
           dynamic_cast<AxisStep*>(rpe->get_relpath_expr()) != NULL)
           ||
           dynamic_cast<AxisStep*>(rpe->get_step_expr()) != NULL))
      {
        error((yylocation_stack_[(1) - (1)]), "syntax error, a path expression cannot begin with an axis step");
        YYERROR;
      }
      (yyval.expr) = (!rpe ?
            (yysemantic_stack_[(1) - (1)].expr) :
            new PathExpr( LOC((yyloc)), ParseConstants::path_relative, (yysemantic_stack_[(1) - (1)].expr)));
    }
    break;

  case 441:

/* Line 690 of lalr1.cc  */
#line 3504 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = NULL;
    }
    break;

  case 442:

/* Line 690 of lalr1.cc  */
#line 3510 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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

  case 443:

/* Line 690 of lalr1.cc  */
#line 3520 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr), false);
    }
    break;

  case 444:

/* Line 690 of lalr1.cc  */
#line 3524 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slashslash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr), false);
    }
    break;

  case 447:

/* Line 690 of lalr1.cc  */
#line 3534 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)), dynamic_cast<ForwardStep*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 448:

/* Line 690 of lalr1.cc  */
#line 3540 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)),
                dynamic_cast<ForwardStep*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 449:

/* Line 690 of lalr1.cc  */
#line 3548 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)), dynamic_cast<ReverseStep*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 450:

/* Line 690 of lalr1.cc  */
#line 3554 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)),
                dynamic_cast<ReverseStep*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 451:

/* Line 690 of lalr1.cc  */
#line 3564 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ForwardStep(
                LOC((yyloc)), dynamic_cast<ForwardAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node)
            );
        }
    break;

  case 452:

/* Line 690 of lalr1.cc  */
#line 3570 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ForwardStep(
                LOC((yyloc)), dynamic_cast<AbbrevForwardStep*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 453:

/* Line 690 of lalr1.cc  */
#line 3578 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_child );
        }
    break;

  case 454:

/* Line 690 of lalr1.cc  */
#line 3582 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_descendant);
        }
    break;

  case 455:

/* Line 690 of lalr1.cc  */
#line 3586 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_attribute );
        }
    break;

  case 456:

/* Line 690 of lalr1.cc  */
#line 3590 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_self );
        }
    break;

  case 457:

/* Line 690 of lalr1.cc  */
#line 3594 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ForwardAxis(
                LOC((yyloc)), ParseConstants::axis_descendant_or_self
            );
        }
    break;

  case 458:

/* Line 690 of lalr1.cc  */
#line 3600 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ForwardAxis(
                LOC((yyloc)), ParseConstants::axis_following_sibling
            );
        }
    break;

  case 459:

/* Line 690 of lalr1.cc  */
#line 3606 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_following );
        }
    break;

  case 460:

/* Line 690 of lalr1.cc  */
#line 3612 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new AbbrevForwardStep( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), false );
        }
    break;

  case 461:

/* Line 690 of lalr1.cc  */
#line 3616 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new AbbrevForwardStep( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].node), true );
        }
    break;

  case 462:

/* Line 690 of lalr1.cc  */
#line 3622 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ReverseStep( LOC((yyloc)), dynamic_cast<ReverseAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node) );
        }
    break;

  case 463:

/* Line 690 of lalr1.cc  */
#line 3626 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            ReverseAxis *ra = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_parent
            );
            (yyval.node) = new ReverseStep( LOC((yyloc)), ra, NULL );
        }
    break;

  case 464:

/* Line 690 of lalr1.cc  */
#line 3635 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_parent );
        }
    break;

  case 465:

/* Line 690 of lalr1.cc  */
#line 3639 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_ancestor );
        }
    break;

  case 466:

/* Line 690 of lalr1.cc  */
#line 3643 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_preceding_sibling
            );
        }
    break;

  case 467:

/* Line 690 of lalr1.cc  */
#line 3649 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_preceding );
        }
    break;

  case 468:

/* Line 690 of lalr1.cc  */
#line 3653 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_ancestor_or_self
            );
        }
    break;

  case 471:

/* Line 690 of lalr1.cc  */
#line 3665 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 472:

/* Line 690 of lalr1.cc  */
#line 3669 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), dynamic_cast<Wildcard*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 473:

/* Line 690 of lalr1.cc  */
#line 3675 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", "", ParseConstants::wild_all, false);
    }
    break;

  case 474:

/* Line 690 of lalr1.cc  */
#line 3679 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), "", ParseConstants::wild_elem, false);
    }
    break;

  case 475:

/* Line 690 of lalr1.cc  */
#line 3683 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), "", ParseConstants::wild_elem, true);
    }
    break;

  case 476:

/* Line 690 of lalr1.cc  */
#line 3687 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", SYMTAB((yysemantic_stack_[(1) - (1)].sval)), ParseConstants::wild_prefix, false);
    }
    break;

  case 477:

/* Line 690 of lalr1.cc  */
#line 3693 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
     }
    break;

  case 478:

/* Line 690 of lalr1.cc  */
#line 3697 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new FilterExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
     }
    break;

  case 479:

/* Line 690 of lalr1.cc  */
#line 3701 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new DynamicFunctionInvocation(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), false);
     }
    break;

  case 480:

/* Line 690 of lalr1.cc  */
#line 3705 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new DynamicFunctionInvocation(LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node)), false);
     }
    break;

  case 481:

/* Line 690 of lalr1.cc  */
#line 3709 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new JSONArrayUnboxing(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr));
    }
    break;

  case 482:

/* Line 690 of lalr1.cc  */
#line 3713 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
       ERROR_IF_QNAME_NOT_NCNAME((yysemantic_stack_[(3) - (3)].expr), (yylocation_stack_[(3) - (3)]));
       StringLiteral* sl = new StringLiteral( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
       (yyval.expr) = new JSONObjectLookup(LOC((yyloc)), LOC((yylocation_stack_[(3) - (2)])), (yysemantic_stack_[(3) - (1)].expr), sl);
     }
    break;

  case 483:

/* Line 690 of lalr1.cc  */
#line 3719 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new JSONObjectLookup(LOC((yyloc)), LOC((yylocation_stack_[(4) - (2)])),
                                 (yysemantic_stack_[(4) - (1)].expr),
                                 new ParenthesizedExpr(LOC((yyloc)), NULL));
     }
    break;

  case 484:

/* Line 690 of lalr1.cc  */
#line 3725 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new JSONObjectLookup(LOC((yyloc)), LOC((yylocation_stack_[(5) - (2)])),
                                 (yysemantic_stack_[(5) - (1)].expr),
                                 new ParenthesizedExpr(LOC((yyloc)), (yysemantic_stack_[(5) - (4)].expr)));
     }
    break;

  case 485:

/* Line 690 of lalr1.cc  */
#line 3731 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.expr) = new JSONObjectLookup(LOC((yyloc)), LOC((yylocation_stack_[(3) - (2)])), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
     }
    break;

  case 486:

/* Line 690 of lalr1.cc  */
#line 3735 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new JSONObjectLookup(LOC((yyloc)), LOC((yylocation_stack_[(3) - (2)])), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
     }
    break;

  case 487:

/* Line 690 of lalr1.cc  */
#line 3741 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      PredicateList* pl = new PredicateList( LOC((yyloc)) );
      pl->push_back(dynamic_cast<exprnode*>((yysemantic_stack_[(1) - (1)].expr)));
      (yyval.node) = pl;
    }
    break;

  case 488:

/* Line 690 of lalr1.cc  */
#line 3747 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      if (PredicateList* pl = dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (1)].node)))
        pl->push_back(dynamic_cast<exprnode*>((yysemantic_stack_[(2) - (2)].expr)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 489:

/* Line 690 of lalr1.cc  */
#line 3755 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 504:

/* Line 690 of lalr1.cc  */
#line 3777 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 505:

/* Line 690 of lalr1.cc  */
#line 3781 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 506:

/* Line 690 of lalr1.cc  */
#line 3785 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            driver.addCommonLanguageWarning((yylocation_stack_[(1) - (1)]), ZED(ZWST0009_TRUE_FALSE_NULL_KEYWORDS));
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 507:

/* Line 690 of lalr1.cc  */
#line 3790 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            driver.addCommonLanguageWarning((yylocation_stack_[(1) - (1)]), ZED(ZWST0009_TRUE_FALSE_NULL_KEYWORDS));
            (yyval.expr) = new NullLiteral(LOC((yyloc)));
        }
    break;

  case 508:

/* Line 690 of lalr1.cc  */
#line 3797 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_decimal, *(yysemantic_stack_[(1) - (1)].decval)
            );
            delete yylval.decval;
        }
    break;

  case 509:

/* Line 690 of lalr1.cc  */
#line 3804 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_integer, *(yysemantic_stack_[(1) - (1)].ival)
            );
            delete yylval.ival;
        }
    break;

  case 510:

/* Line 690 of lalr1.cc  */
#line 3811 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_double, *(yysemantic_stack_[(1) - (1)].dval)
            );
            delete yylval.dval;
        }
    break;

  case 511:

/* Line 690 of lalr1.cc  */
#line 3820 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new BooleanLiteral(LOC((yyloc)), true);
        }
    break;

  case 512:

/* Line 690 of lalr1.cc  */
#line 3824 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new BooleanLiteral(LOC((yyloc)), false);
        }
    break;

  case 513:

/* Line 690 of lalr1.cc  */
#line 3830 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new VarRef(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)));
        }
    break;

  case 514:

/* Line 690 of lalr1.cc  */
#line 3836 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), NULL);
        }
    break;

  case 515:

/* Line 690 of lalr1.cc  */
#line 3840 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 516:

/* Line 690 of lalr1.cc  */
#line 3846 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            driver.addCommonLanguageWarning((yylocation_stack_[(1) - (1)]), ZED(ZWST0009_CONTEXT_ITEM_EXPR));
            (yyval.expr) = new ContextItemExpr( LOC((yyloc)) );
        }
    break;

  case 517:

/* Line 690 of lalr1.cc  */
#line 3853 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new OrderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 518:

/* Line 690 of lalr1.cc  */
#line 3859 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new UnorderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 519:

/* Line 690 of lalr1.cc  */
#line 3865 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new FunctionCall(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), NULL);
    }
    break;

  case 520:

/* Line 690 of lalr1.cc  */
#line 3869 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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

  case 521:

/* Line 690 of lalr1.cc  */
#line 3887 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      ArgList* al = new ArgList(LOC((yyloc)));
      al->push_back(new ArgumentPlaceholder(LOC((yyloc))));
      (yyval.node) = al;
    }
    break;

  case 522:

/* Line 690 of lalr1.cc  */
#line 3893 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      if (ArgList* al = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node)))
        al->push_back(new ArgumentPlaceholder(LOC((yyloc))));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 523:

/* Line 690 of lalr1.cc  */
#line 3899 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      ArgList *al = new ArgList( LOC((yyloc)) );
      al->push_back( (yysemantic_stack_[(1) - (1)].expr) );
      (yyval.node) = al;
    }
    break;

  case 524:

/* Line 690 of lalr1.cc  */
#line 3905 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      if ( ArgList *al = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node)) )
        al->push_back( (yysemantic_stack_[(3) - (3)].expr) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 525:

/* Line 690 of lalr1.cc  */
#line 3913 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 526:

/* Line 690 of lalr1.cc  */
#line 3917 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 527:

/* Line 690 of lalr1.cc  */
#line 3923 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new LiteralFunctionItem(LOC ((yyloc)), dynamic_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].ival));
    }
    break;

  case 528:

/* Line 690 of lalr1.cc  */
#line 3929 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new InlineFunction(LOC((yyloc)),
                              &*(yysemantic_stack_[(3) - (2)].fnsig)->theParams,
                              &*(yysemantic_stack_[(3) - (2)].fnsig)->theReturnType,
                              (yysemantic_stack_[(3) - (3)].expr));
      delete (yysemantic_stack_[(3) - (2)].fnsig);
    }
    break;

  case 534:

/* Line 690 of lalr1.cc  */
#line 3948 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new DirElemConstructor(LOC((yyloc)),
                                  static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                                  NULL,
                                  NULL,
                                  NULL);
    }
    break;

  case 535:

/* Line 690 of lalr1.cc  */
#line 3956 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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

  case 536:

/* Line 690 of lalr1.cc  */
#line 3972 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new DirElemConstructor(LOC((yyloc)),
                                  static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                                  NULL,
                                  dynamic_cast<DirAttributeList*>((yysemantic_stack_[(5) - (3)].node)),
                                  NULL);
    }
    break;

  case 537:

/* Line 690 of lalr1.cc  */
#line 3980 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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

  case 538:

/* Line 690 of lalr1.cc  */
#line 3998 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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

  case 539:

/* Line 690 of lalr1.cc  */
#line 4016 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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

  case 540:

/* Line 690 of lalr1.cc  */
#line 4034 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      DirElemContentList *decl = new DirElemContentList( LOC((yyloc)) );
      decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(1) - (1)].expr)) );
      (yyval.node) = decl;
    }
    break;

  case 541:

/* Line 690 of lalr1.cc  */
#line 4040 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      DirElemContentList *decl = dynamic_cast<DirElemContentList*>((yysemantic_stack_[(2) - (1)].node));
      if ( decl )
        decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(2) - (2)].expr)) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 542:

/* Line 690 of lalr1.cc  */
#line 4049 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      DirAttributeList *dal = new DirAttributeList( LOC((yyloc)) );
      dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = dal;
    }
    break;

  case 543:

/* Line 690 of lalr1.cc  */
#line 4055 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      DirAttributeList *dal = dynamic_cast<DirAttributeList*>((yysemantic_stack_[(2) - (1)].node));
      if ( dal )
        dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 544:

/* Line 690 of lalr1.cc  */
#line 4064 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DirAttr(LOC((yyloc)),
                       static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                       dynamic_cast<DirAttributeValue*>((yysemantic_stack_[(6) - (6)].node)));
    }
    break;

  case 547:

/* Line 690 of lalr1.cc  */
#line 4074 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DirAttributeValue(LOC((yyloc)),
                                 dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
    }
    break;

  case 548:

/* Line 690 of lalr1.cc  */
#line 4079 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DirAttributeValue( LOC((yyloc)),
                                  dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
    }
    break;

  case 549:

/* Line 690 of lalr1.cc  */
#line 4085 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new QuoteAttrContentList( LOC((yyloc)) );
    }
    break;

  case 550:

/* Line 690 of lalr1.cc  */
#line 4089 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 551:

/* Line 690 of lalr1.cc  */
#line 4095 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
      qacl->push_back( new QuoteAttrValueContent( LOC((yyloc)), "\"" ) );
      (yyval.node) = qacl;
    }
    break;

  case 552:

/* Line 690 of lalr1.cc  */
#line 4101 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
      qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = qacl;
    }
    break;

  case 553:

/* Line 690 of lalr1.cc  */
#line 4107 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      QuoteAttrContentList* qacl = dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
      if ( qacl )
        qacl->push_back( new QuoteAttrValueContent( LOC((yyloc)), "\"" ) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 554:

/* Line 690 of lalr1.cc  */
#line 4114 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      QuoteAttrContentList *qacl = dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
      if ( qacl )
        qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 555:

/* Line 690 of lalr1.cc  */
#line 4122 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AposAttrContentList( LOC((yyloc)) );
    }
    break;

  case 556:

/* Line 690 of lalr1.cc  */
#line 4126 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 557:

/* Line 690 of lalr1.cc  */
#line 4132 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
      aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
      (yyval.node) = aacl;
    }
    break;

  case 558:

/* Line 690 of lalr1.cc  */
#line 4138 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
      aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = aacl;
    }
    break;

  case 559:

/* Line 690 of lalr1.cc  */
#line 4144 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
      if (aacl)
        aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 560:

/* Line 690 of lalr1.cc  */
#line 4151 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
      if ( aacl )
        aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 561:

/* Line 690 of lalr1.cc  */
#line 4160 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new QuoteAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
    }
    break;

  case 562:

/* Line 690 of lalr1.cc  */
#line 4164 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new QuoteAttrValueContent(LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
    }
    break;

  case 563:

/* Line 690 of lalr1.cc  */
#line 4170 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AposAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
    }
    break;

  case 564:

/* Line 690 of lalr1.cc  */
#line 4174 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AposAttrValueContent(LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
    }
    break;

  case 565:

/* Line 690 of lalr1.cc  */
#line 4180 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new DirElemContent( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr) );
    }
    break;

  case 566:

/* Line 690 of lalr1.cc  */
#line 4184 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new DirElemContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
    }
    break;

  case 567:

/* Line 690 of lalr1.cc  */
#line 4188 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      rchandle<CDataSection> cdata_h = dynamic_cast<CDataSection*>((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = new DirElemContent( LOC((yyloc)), cdata_h );
    }
    break;

  case 568:

/* Line 690 of lalr1.cc  */
#line 4193 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      rchandle<CommonContent> cont_h = dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = new DirElemContent( LOC((yyloc)), cont_h );
    }
    break;

  case 569:

/* Line 690 of lalr1.cc  */
#line 4200 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CommonContent(LOC((yyloc)), ParseConstants::cont_charref, SYMTAB((yysemantic_stack_[(1) - (1)].sval)));
    }
    break;

  case 570:

/* Line 690 of lalr1.cc  */
#line 4204 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CommonContent(LOC((yyloc)), ParseConstants::cont_escape_lbrace);
    }
    break;

  case 571:

/* Line 690 of lalr1.cc  */
#line 4208 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CommonContent(LOC((yyloc)), ParseConstants::cont_escape_rbrace);
    }
    break;

  case 572:

/* Line 690 of lalr1.cc  */
#line 4212 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CommonContent(LOC((yyloc)), new EnclosedExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr)));
    }
    break;

  case 573:

/* Line 690 of lalr1.cc  */
#line 4218 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 574:

/* Line 690 of lalr1.cc  */
#line 4223 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), "" );
    }
    break;

  case 575:

/* Line 690 of lalr1.cc  */
#line 4229 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      ERROR_IF_QNAME_NOT_NCNAME((yysemantic_stack_[(3) - (2)].expr), (yylocation_stack_[(3) - (2)]));
      (yyval.expr) = new DirPIConstructor( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)) );
    }
    break;

  case 576:

/* Line 690 of lalr1.cc  */
#line 4235 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      ERROR_IF_QNAME_NOT_NCNAME((yysemantic_stack_[(3) - (2)].expr), (yylocation_stack_[(3) - (2)]));
      (yyval.expr) = new DirPIConstructor( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
    }
    break;

  case 577:

/* Line 690 of lalr1.cc  */
#line 4242 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CDataSection( LOC((yyloc)),SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
    }
    break;

  case 578:

/* Line 690 of lalr1.cc  */
#line 4248 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 579:

/* Line 690 of lalr1.cc  */
#line 4253 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 580:

/* Line 690 of lalr1.cc  */
#line 4258 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 581:

/* Line 690 of lalr1.cc  */
#line 4263 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 582:

/* Line 690 of lalr1.cc  */
#line 4268 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 583:

/* Line 690 of lalr1.cc  */
#line 4273 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 585:

/* Line 690 of lalr1.cc  */
#line 4281 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompDocConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
    }
    break;

  case 586:

/* Line 690 of lalr1.cc  */
#line 4287 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompElemConstructor(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval))), (yysemantic_stack_[(3) - (2)].expr));
    }
    break;

  case 587:

/* Line 690 of lalr1.cc  */
#line 4291 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompElemConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
    }
    break;

  case 588:

/* Line 690 of lalr1.cc  */
#line 4297 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval))), (yysemantic_stack_[(3) - (2)].expr) );
    }
    break;

  case 589:

/* Line 690 of lalr1.cc  */
#line 4301 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
    }
    break;

  case 590:

/* Line 690 of lalr1.cc  */
#line 4307 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompTextConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
    }
    break;

  case 591:

/* Line 690 of lalr1.cc  */
#line 4313 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompCommentConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
    }
    break;

  case 592:

/* Line 690 of lalr1.cc  */
#line 4319 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompPIConstructor(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval)), (yysemantic_stack_[(3) - (2)].expr));
    }
    break;

  case 593:

/* Line 690 of lalr1.cc  */
#line 4323 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompPIConstructor(LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
    }
    break;

  case 594:

/* Line 690 of lalr1.cc  */
#line 4329 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompNamespaceConstructor(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval)), (yysemantic_stack_[(3) - (2)].expr));
    }
    break;

  case 595:

/* Line 690 of lalr1.cc  */
#line 4333 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompNamespaceConstructor(LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
    }
    break;

  case 596:

/* Line 690 of lalr1.cc  */
#line 4339 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 597:

/* Line 690 of lalr1.cc  */
#line 4345 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL );
        }
    break;

  case 598:

/* Line 690 of lalr1.cc  */
#line 4349 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new SequenceType(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node)));
        }
    break;

  case 599:

/* Line 690 of lalr1.cc  */
#line 4353 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 600:

/* Line 690 of lalr1.cc  */
#line 4357 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            driver.addCommonLanguageWarning((yylocation_stack_[(2) - (1)]), ZED(ZWST0009_JSONIQ_EMPTY_SEQUENCE));
            (yyval.node) = new SequenceType( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 601:

/* Line 690 of lalr1.cc  */
#line 4364 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_optionally
            );
        }
    break;

  case 602:

/* Line 690 of lalr1.cc  */
#line 4370 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_zero_or_more
            );
        }
    break;

  case 603:

/* Line 690 of lalr1.cc  */
#line 4376 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_one_or_more
            );
        }
    break;

  case 604:

/* Line 690 of lalr1.cc  */
#line 4384 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            GeneralizedAtomicType* gat = static_cast<GeneralizedAtomicType*>((yysemantic_stack_[(1) - (1)].node));
            if (gat->get_qname()->get_localname() == "item")
            {
              driver.addCommonLanguageWarning((yylocation_stack_[(1) - (1)]), ZED(ZWST0009_JSONIQ_TYPE_KEYWORDS));
              (yyval.node) = new ItemType( LOC((yyloc)), true );
            }
            else if (gat->get_qname()->get_localname() == "json-item")
            {
              driver.addCommonLanguageWarning((yylocation_stack_[(1) - (1)]), ZED(ZWST0009_JSONIQ_TYPE_KEYWORDS));
              (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonItem);
            }
            else if (gat->get_qname()->get_localname() == "array")
            {
              driver.addCommonLanguageWarning((yylocation_stack_[(1) - (1)]), ZED(ZWST0009_JSONIQ_TYPE_KEYWORDS));
              (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonArray);
            }
            else if (gat->get_qname()->get_localname() == "structured-item")
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

  case 605:

/* Line 690 of lalr1.cc  */
#line 4412 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 606:

/* Line 690 of lalr1.cc  */
#line 4416 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ItemType( LOC((yyloc)), true );
        }
    break;

  case 607:

/* Line 690 of lalr1.cc  */
#line 4420 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new StructuredItemType(LOC((yyloc)));
        }
    break;

  case 608:

/* Line 690 of lalr1.cc  */
#line 4424 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 609:

/* Line 690 of lalr1.cc  */
#line 4428 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 610:

/* Line 690 of lalr1.cc  */
#line 4432 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 611:

/* Line 690 of lalr1.cc  */
#line 4438 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
          TypeList* aTypeList = new TypeList(LOC ((yyloc)));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(1) - (1)].node)));
          (yyval.node) = aTypeList;
        }
    break;

  case 612:

/* Line 690 of lalr1.cc  */
#line 4444 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
          TypeList* aTypeList = dynamic_cast<TypeList *>((yysemantic_stack_[(3) - (1)].node));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
          (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 613:

/* Line 690 of lalr1.cc  */
#line 4452 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new GeneralizedAtomicType( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
    }
    break;

  case 614:

/* Line 690 of lalr1.cc  */
#line 4456 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new GeneralizedAtomicType( LOC((yyloc)), new QName(LOC((yyloc)), "null") );
    }
    break;

  case 615:

/* Line 690 of lalr1.cc  */
#line 4462 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SimpleType( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
    }
    break;

  case 616:

/* Line 690 of lalr1.cc  */
#line 4468 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 617:

/* Line 690 of lalr1.cc  */
#line 4472 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 618:

/* Line 690 of lalr1.cc  */
#line 4476 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 619:

/* Line 690 of lalr1.cc  */
#line 4480 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 620:

/* Line 690 of lalr1.cc  */
#line 4484 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 621:

/* Line 690 of lalr1.cc  */
#line 4488 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 622:

/* Line 690 of lalr1.cc  */
#line 4492 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 623:

/* Line 690 of lalr1.cc  */
#line 4496 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 624:

/* Line 690 of lalr1.cc  */
#line 4500 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 625:

/* Line 690 of lalr1.cc  */
#line 4504 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 626:

/* Line 690 of lalr1.cc  */
#line 4510 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AnyKindTest( LOC((yyloc)) );
    }
    break;

  case 627:

/* Line 690 of lalr1.cc  */
#line 4516 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = NULL;
    }
    break;

  case 628:

/* Line 690 of lalr1.cc  */
#line 4522 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DocumentTest(LOC((yyloc)));
    }
    break;

  case 629:

/* Line 690 of lalr1.cc  */
#line 4526 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DocumentTest(LOC((yyloc)), dynamic_cast<ElementTest*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 630:

/* Line 690 of lalr1.cc  */
#line 4530 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DocumentTest(LOC((yyloc)), dynamic_cast<SchemaElementTest*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 631:

/* Line 690 of lalr1.cc  */
#line 4536 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new NamespaceTest(LOC((yyloc)));
    }
    break;

  case 632:

/* Line 690 of lalr1.cc  */
#line 4541 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new TextTest(LOC((yyloc)));
    }
    break;

  case 633:

/* Line 690 of lalr1.cc  */
#line 4547 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CommentTest(LOC((yyloc)));
    }
    break;

  case 634:

/* Line 690 of lalr1.cc  */
#line 4553 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), "" );
        }
    break;

  case 635:

/* Line 690 of lalr1.cc  */
#line 4557 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            ERROR_IF_QNAME_NOT_NCNAME((yysemantic_stack_[(4) - (3)].expr), (yylocation_stack_[(4) - (3)]));
            (yyval.node) = new PITest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 636:

/* Line 690 of lalr1.cc  */
#line 4562 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 637:

/* Line 690 of lalr1.cc  */
#line 4568 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 638:

/* Line 690 of lalr1.cc  */
#line 4572 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL
            );
        }
    break;

  case 639:

/* Line 690 of lalr1.cc  */
#line 4578 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 640:

/* Line 690 of lalr1.cc  */
#line 4584 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 641:

/* Line 690 of lalr1.cc  */
#line 4588 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 642:

/* Line 690 of lalr1.cc  */
#line 4596 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new SchemaAttributeTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 643:

/* Line 690 of lalr1.cc  */
#line 4602 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ElementTest( LOC((yyloc)), NULL, NULL, true );
        }
    break;

  case 644:

/* Line 690 of lalr1.cc  */
#line 4606 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL, true
            );
        }
    break;

  case 645:

/* Line 690 of lalr1.cc  */
#line 4612 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                false
            );
        }
    break;

  case 646:

/* Line 690 of lalr1.cc  */
#line 4621 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                true
            );
        }
    break;

  case 647:

/* Line 690 of lalr1.cc  */
#line 4630 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, NULL, true
            );
        }
    break;

  case 648:

/* Line 690 of lalr1.cc  */
#line 4636 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), false
            );
        }
    break;

  case 649:

/* Line 690 of lalr1.cc  */
#line 4642 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), true
            );
        }
    break;

  case 650:

/* Line 690 of lalr1.cc  */
#line 4650 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new SchemaElementTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 651:

/* Line 690 of lalr1.cc  */
#line 4656 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 652:

/* Line 690 of lalr1.cc  */
#line 4662 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (1)].expr)), true );
        }
    break;

  case 653:

/* Line 690 of lalr1.cc  */
#line 4668 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new StringLiteral( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 654:

/* Line 690 of lalr1.cc  */
#line 4674 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 655:

/* Line 690 of lalr1.cc  */
#line 4678 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 656:

/* Line 690 of lalr1.cc  */
#line 4684 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AnyFunctionTest(LOC((yyloc)));
    }
    break;

  case 657:

/* Line 690 of lalr1.cc  */
#line 4690 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)), dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (5)].node)));
        }
    break;

  case 658:

/* Line 690 of lalr1.cc  */
#line 4694 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)),
              dynamic_cast<TypeList *>((yysemantic_stack_[(6) - (3)].node)),
              dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (6)].node)));
        }
    break;

  case 659:

/* Line 690 of lalr1.cc  */
#line 4702 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
           (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 660:

/* Line 690 of lalr1.cc  */
#line 4708 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::strict_validation
            );
        }
    break;

  case 661:

/* Line 690 of lalr1.cc  */
#line 4714 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::lax_validation
            );
        }
    break;

  case 662:

/* Line 690 of lalr1.cc  */
#line 4720 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::skip_validation
            );
        }
    break;

  case 663:

/* Line 690 of lalr1.cc  */
#line 4728 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 664:

/* Line 690 of lalr1.cc  */
#line 4732 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 665:

/* Line 690 of lalr1.cc  */
#line 4738 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 666:

/* Line 690 of lalr1.cc  */
#line 4744 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 667:

/* Line 690 of lalr1.cc  */
#line 4748 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 668:

/* Line 690 of lalr1.cc  */
#line 4754 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 669:

/* Line 690 of lalr1.cc  */
#line 4758 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 670:

/* Line 690 of lalr1.cc  */
#line 4764 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                  LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 671:

/* Line 690 of lalr1.cc  */
#line 4770 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)),
                store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 672:

/* Line 690 of lalr1.cc  */
#line 4777 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 673:

/* Line 690 of lalr1.cc  */
#line 4785 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 674:

/* Line 690 of lalr1.cc  */
#line 4790 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 675:

/* Line 690 of lalr1.cc  */
#line 4796 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::NODE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 676:

/* Line 690 of lalr1.cc  */
#line 4802 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::VALUE_OF_NODE, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 677:

/* Line 690 of lalr1.cc  */
#line 4810 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new RenameExpr( LOC ((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 678:

/* Line 690 of lalr1.cc  */
#line 4816 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      CopyVarList *cvl = dynamic_cast<CopyVarList*>((yysemantic_stack_[(7) - (3)].expr));
      (yyval.expr) = new TransformExpr( LOC((yyloc)), cvl, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr) );
    }
    break;

  case 679:

/* Line 690 of lalr1.cc  */
#line 4823 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      CopyVarList* lList = new CopyVarList(LOC((yyloc)));
      lList->push_back (dynamic_cast<VarBinding*> ((yysemantic_stack_[(1) - (1)].expr)));
      (yyval.expr) = lList;
    }
    break;

  case 680:

/* Line 690 of lalr1.cc  */
#line 4829 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      CopyVarList* lList = dynamic_cast<CopyVarList*>((yysemantic_stack_[(4) - (1)].expr));
      VarBinding* lBinding = dynamic_cast<VarBinding*>((yysemantic_stack_[(4) - (4)].expr));
      lList->push_back(lBinding);
      (yyval.expr) = lList;
    }
    break;

  case 681:

/* Line 690 of lalr1.cc  */
#line 4838 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new VarBinding(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 682:

/* Line 690 of lalr1.cc  */
#line 4844 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new TryExpr( LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 683:

/* Line 690 of lalr1.cc  */
#line 4850 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            CatchListExpr *cle = new CatchListExpr( LOC((yyloc)) );
            cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.expr) = cle;
        }
    break;

  case 684:

/* Line 690 of lalr1.cc  */
#line 4856 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
            if ( cle )
                cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
        }
    break;

  case 685:

/* Line 690 of lalr1.cc  */
#line 4865 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)), *(yysemantic_stack_[(3) - (2)].name_test_list), (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 686:

/* Line 690 of lalr1.cc  */
#line 4872 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 687:

/* Line 690 of lalr1.cc  */
#line 4878 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            CatchExpr::NameTestList *ntl = new CatchExpr::NameTestList;
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 688:

/* Line 690 of lalr1.cc  */
#line 4884 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            CatchExpr::NameTestList *ntl =
                static_cast<CatchExpr::NameTestList*>((yysemantic_stack_[(3) - (1)].name_test_list));
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 689:

/* Line 690 of lalr1.cc  */
#line 4893 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTSelection( LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), (yysemantic_stack_[(2) - (2)].pos_filter_list) );
            delete (yysemantic_stack_[(2) - (2)].pos_filter_list);
        }
    break;

  case 690:

/* Line 690 of lalr1.cc  */
#line 4900 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.pos_filter_list) = NULL;
        }
    break;

  case 691:

/* Line 690 of lalr1.cc  */
#line 4904 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.pos_filter_list) = (yysemantic_stack_[(1) - (1)].pos_filter_list);
        }
    break;

  case 692:

/* Line 690 of lalr1.cc  */
#line 4910 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.pos_filter_list) = new FTSelection::pos_filter_list_t;
            (yyval.pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 693:

/* Line 690 of lalr1.cc  */
#line 4915 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yysemantic_stack_[(2) - (1)].pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.pos_filter_list) = (yysemantic_stack_[(2) - (1)].pos_filter_list);
        }
    break;

  case 694:

/* Line 690 of lalr1.cc  */
#line 4922 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 695:

/* Line 690 of lalr1.cc  */
#line 4926 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTOr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 696:

/* Line 690 of lalr1.cc  */
#line 4932 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 697:

/* Line 690 of lalr1.cc  */
#line 4936 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTAnd( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 698:

/* Line 690 of lalr1.cc  */
#line 4942 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 699:

/* Line 690 of lalr1.cc  */
#line 4946 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTMildNot( LOC((yyloc)), (yysemantic_stack_[(4) - (1)].node), (yysemantic_stack_[(4) - (4)].node) );
        }
    break;

  case 700:

/* Line 690 of lalr1.cc  */
#line 4952 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 701:

/* Line 690 of lalr1.cc  */
#line 4956 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTUnaryNot(
                LOC((yyloc)), dynamic_cast<FTPrimaryWithOptions*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 702:

/* Line 690 of lalr1.cc  */
#line 4964 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTPrimaryWithOptions(
                LOC((yyloc)),
                dynamic_cast<FTPrimary*>((yysemantic_stack_[(3) - (1)].node)),
                dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<FTWeight*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 703:

/* Line 690 of lalr1.cc  */
#line 4974 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 704:

/* Line 690 of lalr1.cc  */
#line 4978 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 705:

/* Line 690 of lalr1.cc  */
#line 4983 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 706:

/* Line 690 of lalr1.cc  */
#line 4987 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 707:

/* Line 690 of lalr1.cc  */
#line 4993 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTWeight( LOC((yyloc)), dynamic_cast<exprnode*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 708:

/* Line 690 of lalr1.cc  */
#line 4999 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTWordsTimes(
                LOC((yyloc)),
                dynamic_cast<FTWords*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<FTTimes*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 709:

/* Line 690 of lalr1.cc  */
#line 5007 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 710:

/* Line 690 of lalr1.cc  */
#line 5011 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 711:

/* Line 690 of lalr1.cc  */
#line 5016 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 712:

/* Line 690 of lalr1.cc  */
#line 5020 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 713:

/* Line 690 of lalr1.cc  */
#line 5026 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTExtensionSelection(
                LOC((yyloc)),
                dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)),
                dynamic_cast<FTSelection*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 714:

/* Line 690 of lalr1.cc  */
#line 5035 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 715:

/* Line 690 of lalr1.cc  */
#line 5039 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 716:

/* Line 690 of lalr1.cc  */
#line 5045 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTWords(
                LOC((yyloc)),
                dynamic_cast<FTWordsValue*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<FTAnyallOption*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 717:

/* Line 690 of lalr1.cc  */
#line 5055 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), static_cast<StringLiteral*>((yysemantic_stack_[(1) - (1)].expr)), NULL
            );
        }
    break;

  case 718:

/* Line 690 of lalr1.cc  */
#line 5061 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), NULL, dynamic_cast<exprnode*>((yysemantic_stack_[(3) - (2)].expr))
            );
        }
    break;

  case 719:

/* Line 690 of lalr1.cc  */
#line 5068 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::any );
        }
    break;

  case 720:

/* Line 690 of lalr1.cc  */
#line 5072 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 721:

/* Line 690 of lalr1.cc  */
#line 5078 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 722:

/* Line 690 of lalr1.cc  */
#line 5082 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 723:

/* Line 690 of lalr1.cc  */
#line 5086 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::phrase );
        }
    break;

  case 724:

/* Line 690 of lalr1.cc  */
#line 5091 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any;
        }
    break;

  case 725:

/* Line 690 of lalr1.cc  */
#line 5095 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any_word;
        }
    break;

  case 726:

/* Line 690 of lalr1.cc  */
#line 5100 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all;
        }
    break;

  case 727:

/* Line 690 of lalr1.cc  */
#line 5104 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all_words;
        }
    break;

  case 728:

/* Line 690 of lalr1.cc  */
#line 5110 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 729:

/* Line 690 of lalr1.cc  */
#line 5114 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 730:

/* Line 690 of lalr1.cc  */
#line 5118 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 731:

/* Line 690 of lalr1.cc  */
#line 5122 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 732:

/* Line 690 of lalr1.cc  */
#line 5126 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 733:

/* Line 690 of lalr1.cc  */
#line 5132 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTOrder( LOC((yyloc)) );
        }
    break;

  case 734:

/* Line 690 of lalr1.cc  */
#line 5138 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTWindow(
                LOC((yyloc)),
                static_cast<AdditiveExpr*>((yysemantic_stack_[(3) - (2)].expr)),
                static_cast<FTUnit*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 735:

/* Line 690 of lalr1.cc  */
#line 5148 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTDistance(
                LOC((yyloc)),
                dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<FTUnit*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 736:

/* Line 690 of lalr1.cc  */
#line 5158 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::words );
        }
    break;

  case 737:

/* Line 690 of lalr1.cc  */
#line 5162 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::sentences );
        }
    break;

  case 738:

/* Line 690 of lalr1.cc  */
#line 5166 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::paragraphs );
        }
    break;

  case 739:

/* Line 690 of lalr1.cc  */
#line 5172 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            FTMatchOptions *mo = new FTMatchOptions( LOC((yyloc)) );
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = mo;
        }
    break;

  case 740:

/* Line 690 of lalr1.cc  */
#line 5178 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            FTMatchOptions *mo = dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (1)].node));
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 741:

/* Line 690 of lalr1.cc  */
#line 5186 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 742:

/* Line 690 of lalr1.cc  */
#line 5190 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 743:

/* Line 690 of lalr1.cc  */
#line 5194 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 744:

/* Line 690 of lalr1.cc  */
#line 5198 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 745:

/* Line 690 of lalr1.cc  */
#line 5202 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 746:

/* Line 690 of lalr1.cc  */
#line 5206 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 747:

/* Line 690 of lalr1.cc  */
#line 5210 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 748:

/* Line 690 of lalr1.cc  */
#line 5214 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 749:

/* Line 690 of lalr1.cc  */
#line 5220 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::sensitive );
        }
    break;

  case 750:

/* Line 690 of lalr1.cc  */
#line 5224 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::insensitive );
        }
    break;

  case 751:

/* Line 690 of lalr1.cc  */
#line 5228 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::lower );
        }
    break;

  case 752:

/* Line 690 of lalr1.cc  */
#line 5232 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::upper );
        }
    break;

  case 753:

/* Line 690 of lalr1.cc  */
#line 5238 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::sensitive
            );
        }
    break;

  case 754:

/* Line 690 of lalr1.cc  */
#line 5244 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::insensitive
            );
        }
    break;

  case 755:

/* Line 690 of lalr1.cc  */
#line 5252 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTExtensionOption(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval))
            );
        }
    break;

  case 756:

/* Line 690 of lalr1.cc  */
#line 5260 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::stemming );
        }
    break;

  case 757:

/* Line 690 of lalr1.cc  */
#line 5264 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::no_stemming );
        }
    break;

  case 758:

/* Line 690 of lalr1.cc  */
#line 5270 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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

  case 759:

/* Line 690 of lalr1.cc  */
#line 5280 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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

  case 760:

/* Line 690 of lalr1.cc  */
#line 5291 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTThesaurusOption( LOC((yyloc)), NULL, false, true );
        }
    break;

  case 761:

/* Line 690 of lalr1.cc  */
#line 5297 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 762:

/* Line 690 of lalr1.cc  */
#line 5301 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 763:

/* Line 690 of lalr1.cc  */
#line 5306 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.thesaurus_id_list) = NULL;
        }
    break;

  case 764:

/* Line 690 of lalr1.cc  */
#line 5310 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(2) - (2)].thesaurus_id_list);
        }
    break;

  case 765:

/* Line 690 of lalr1.cc  */
#line 5316 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.thesaurus_id_list) = new FTThesaurusOption::thesaurus_id_list_t;
            (yyval.thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 766:

/* Line 690 of lalr1.cc  */
#line 5321 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yysemantic_stack_[(3) - (1)].thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(3) - (1)].thesaurus_id_list);
        }
    break;

  case 767:

/* Line 690 of lalr1.cc  */
#line 5328 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTThesaurusID(
                LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (2)].sval)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), dynamic_cast<FTRange*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 768:

/* Line 690 of lalr1.cc  */
#line 5335 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.sval) = 0;
        }
    break;

  case 769:

/* Line 690 of lalr1.cc  */
#line 5339 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.sval) = (yysemantic_stack_[(2) - (2)].sval);
        }
    break;

  case 770:

/* Line 690 of lalr1.cc  */
#line 5345 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 771:

/* Line 690 of lalr1.cc  */
#line 5349 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 772:

/* Line 690 of lalr1.cc  */
#line 5355 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(4) - (3)].node)), (yysemantic_stack_[(4) - (4)].incl_excl_list),
                ft_stop_words_mode::with
            );
            delete (yysemantic_stack_[(4) - (4)].incl_excl_list);
        }
    break;

  case 773:

/* Line 690 of lalr1.cc  */
#line 5364 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, (yysemantic_stack_[(4) - (4)].incl_excl_list), ft_stop_words_mode::with_default
            );
            delete (yysemantic_stack_[(4) - (4)].incl_excl_list);
        }
    break;

  case 774:

/* Line 690 of lalr1.cc  */
#line 5371 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, NULL, ft_stop_words_mode::without
            );
        }
    break;

  case 775:

/* Line 690 of lalr1.cc  */
#line 5379 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), NULL );
        }
    break;

  case 776:

/* Line 690 of lalr1.cc  */
#line 5383 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), "", (yysemantic_stack_[(3) - (2)].strlist) );
        }
    break;

  case 777:

/* Line 690 of lalr1.cc  */
#line 5389 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            string_list_t *sl = new string_list_t;
            sl->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
            (yyval.strlist) = sl;
        }
    break;

  case 778:

/* Line 690 of lalr1.cc  */
#line 5395 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            if ( (yysemantic_stack_[(3) - (1)].strlist) )
                (yysemantic_stack_[(3) - (1)].strlist)->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
            (yyval.strlist) = (yysemantic_stack_[(3) - (1)].strlist);
        }
    break;

  case 779:

/* Line 690 of lalr1.cc  */
#line 5402 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.incl_excl_list) = NULL;
        }
    break;

  case 780:

/* Line 690 of lalr1.cc  */
#line 5406 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.incl_excl_list) = (yysemantic_stack_[(1) - (1)].incl_excl_list);
        }
    break;

  case 781:

/* Line 690 of lalr1.cc  */
#line 5412 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.incl_excl_list) = new FTStopWordOption::incl_excl_list_t;
            (yyval.incl_excl_list)->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 782:

/* Line 690 of lalr1.cc  */
#line 5417 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            FTStopWordOption::incl_excl_list_t *iel = (yysemantic_stack_[(2) - (1)].incl_excl_list);
            if ( !iel )
                iel = new FTStopWordOption::incl_excl_list_t;
            iel->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.incl_excl_list) = iel;
        }
    break;

  case 783:

/* Line 690 of lalr1.cc  */
#line 5427 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStopWordsInclExcl(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(2) - (2)].node)),
                ft_stop_words_unex::union_
            );
        }
    break;

  case 784:

/* Line 690 of lalr1.cc  */
#line 5435 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStopWordsInclExcl(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(2) - (2)].node)),
                ft_stop_words_unex::except
            );
        }
    break;

  case 785:

/* Line 690 of lalr1.cc  */
#line 5445 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTLanguageOption( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 786:

/* Line 690 of lalr1.cc  */
#line 5451 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::with );
        }
    break;

  case 787:

/* Line 690 of lalr1.cc  */
#line 5455 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::without );
        }
    break;

  case 788:

/* Line 690 of lalr1.cc  */
#line 5461 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_start );
        }
    break;

  case 789:

/* Line 690 of lalr1.cc  */
#line 5465 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_end );
        }
    break;

  case 790:

/* Line 690 of lalr1.cc  */
#line 5469 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::entire );
        }
    break;

  case 791:

/* Line 690 of lalr1.cc  */
#line 5475 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTTimes( LOC((yyloc)), dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)) );
        }
    break;

  case 792:

/* Line 690 of lalr1.cc  */
#line 5481 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::exactly, (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 793:

/* Line 690 of lalr1.cc  */
#line 5485 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_least, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 794:

/* Line 690 of lalr1.cc  */
#line 5489 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_most, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 795:

/* Line 690 of lalr1.cc  */
#line 5493 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::from_to, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr) );
        }
    break;

  case 796:

/* Line 690 of lalr1.cc  */
#line 5499 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTScope(
                LOC((yyloc)),
                ft_scope::same,
                dynamic_cast<FTBigUnit*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 797:

/* Line 690 of lalr1.cc  */
#line 5507 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTScope(
                LOC((yyloc)),
                ft_scope::different,
                dynamic_cast<FTBigUnit*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 798:

/* Line 690 of lalr1.cc  */
#line 5517 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::sentence );
        }
    break;

  case 799:

/* Line 690 of lalr1.cc  */
#line 5521 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::paragraph );
        }
    break;

  case 800:

/* Line 690 of lalr1.cc  */
#line 5527 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTIgnoreOption( LOC((yyloc)), static_cast<UnionExpr*>((yysemantic_stack_[(3) - (3)].expr)) );
        }
    break;

  case 801:

/* Line 690 of lalr1.cc  */
#line 5533 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONArrayConstructor( LOC((yyloc)), NULL );
        }
    break;

  case 802:

/* Line 690 of lalr1.cc  */
#line 5537 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONArrayConstructor( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 803:

/* Line 690 of lalr1.cc  */
#line 5543 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), NULL, false);
        }
    break;

  case 804:

/* Line 690 of lalr1.cc  */
#line 5547 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), false);
        }
    break;

  case 805:

/* Line 690 of lalr1.cc  */
#line 5553 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), NULL, true);
        }
    break;

  case 806:

/* Line 690 of lalr1.cc  */
#line 5557 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), true);
        }
    break;

  case 807:

/* Line 690 of lalr1.cc  */
#line 5563 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONDirectObjectConstructor(LOC((yyloc)),
                                               dynamic_cast<JSONPairList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 808:

/* Line 690 of lalr1.cc  */
#line 5570 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
          ERROR_IF_QNAME_NOT_NCNAME((yysemantic_stack_[(3) - (1)].expr), (yylocation_stack_[(3) - (1)]));
          driver.addCommonLanguageWarning((yylocation_stack_[(3) - (1)]), ZED(ZWST0009_OBJECT_KEY_NOT_QUOTED));
          StringLiteral* sl = new StringLiteral( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)) );
          JSONPairList* jpl = new JSONPairList(LOC((yyloc)));
          jpl->push_back(new JSONPairConstructor(LOC((yyloc)), sl, (yysemantic_stack_[(3) - (3)].expr)));
          (yyval.node) = jpl;
        }
    break;

  case 809:

/* Line 690 of lalr1.cc  */
#line 5580 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
          JSONPairList* jpl = new JSONPairList(LOC((yyloc)));
          jpl->push_back(new JSONPairConstructor(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)));
          (yyval.node) = jpl;
        }
    break;

  case 810:

/* Line 690 of lalr1.cc  */
#line 5586 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
          JSONPairList* jpl = dynamic_cast<JSONPairList*>((yysemantic_stack_[(5) - (1)].node));
          assert(jpl);
          jpl->push_back(new JSONPairConstructor(LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)));
          (yyval.node) = jpl;
        }
    break;

  case 811:

/* Line 690 of lalr1.cc  */
#line 5593 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
          ERROR_IF_QNAME_NOT_NCNAME((yysemantic_stack_[(5) - (3)].expr), (yylocation_stack_[(5) - (3)]));
          JSONPairList* jpl = dynamic_cast<JSONPairList*>((yysemantic_stack_[(5) - (1)].node));
          assert(jpl);
          StringLiteral* sl = new StringLiteral( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (3)].expr)) );
          jpl->push_back(new JSONPairConstructor(LOC((yyloc)), sl, (yysemantic_stack_[(5) - (5)].expr)));
          (yyval.node) = jpl;
        }
    break;

  case 812:

/* Line 690 of lalr1.cc  */
#line 5604 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONObjectInsertExpr(LOC((yyloc)),
                                        (yysemantic_stack_[(5) - (3)].expr),
                                        (yysemantic_stack_[(5) - (5)].expr));
        }
    break;

  case 813:

/* Line 690 of lalr1.cc  */
#line 5610 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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

  case 814:

/* Line 690 of lalr1.cc  */
#line 5620 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONArrayInsertExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (5)].expr), (yysemantic_stack_[(8) - (8)].expr));
        }
    break;

  case 815:

/* Line 690 of lalr1.cc  */
#line 5624 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
          driver.addCommonLanguageWarning((yylocation_stack_[(4) - (2)]), ZED(ZWST0009_JSON_KEYWORD_OPTIONAL));
          (yyval.expr) = new JSONObjectInsertExpr(LOC((yyloc)),
                                        (yysemantic_stack_[(4) - (2)].expr),
                                        (yysemantic_stack_[(4) - (4)].expr));
        }
    break;

  case 816:

/* Line 690 of lalr1.cc  */
#line 5631 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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

  case 817:

/* Line 690 of lalr1.cc  */
#line 5642 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
          driver.addCommonLanguageWarning((yylocation_stack_[(7) - (2)]), ZED(ZWST0009_JSON_KEYWORD_OPTIONAL));
          (yyval.expr) = new JSONArrayInsertExpr(LOC((yyloc)), (yysemantic_stack_[(7) - (2)].expr), (yysemantic_stack_[(7) - (4)].expr), (yysemantic_stack_[(7) - (7)].expr));
        }
    break;

  case 818:

/* Line 690 of lalr1.cc  */
#line 5649 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONArrayAppendExpr(LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
        }
    break;

  case 819:

/* Line 690 of lalr1.cc  */
#line 5653 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
          driver.addCommonLanguageWarning((yylocation_stack_[(4) - (2)]), ZED(ZWST0009_JSON_KEYWORD_OPTIONAL));
          (yyval.expr) = new JSONArrayAppendExpr(LOC((yyloc)), (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr));
        }
    break;

  case 820:

/* Line 690 of lalr1.cc  */
#line 5660 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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

  case 821:

/* Line 690 of lalr1.cc  */
#line 5679 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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

  case 822:

/* Line 690 of lalr1.cc  */
#line 5701 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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

  case 823:

/* Line 690 of lalr1.cc  */
#line 5723 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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

  case 824:

/* Line 690 of lalr1.cc  */
#line 5748 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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

  case 825:

/* Line 690 of lalr1.cc  */
#line 5770 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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

  case 826:

/* Line 690 of lalr1.cc  */
#line 5795 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonItem);
        }
    break;

  case 827:

/* Line 690 of lalr1.cc  */
#line 5799 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonArray);
        }
    break;

  case 828:

/* Line 690 of lalr1.cc  */
#line 5803 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonObject);
        }
    break;

  case 829:

/* Line 690 of lalr1.cc  */
#line 5807 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
          driver.addCommonLanguageWarning((yylocation_stack_[(1) - (1)]), ZED(ZWST0009_JSONIQ_TYPE_KEYWORDS));
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonObject);
        }
    break;

  case 832:

/* Line 690 of lalr1.cc  */
#line 5817 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))); }
    break;

  case 833:

/* Line 690 of lalr1.cc  */
#line 5818 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("attribute"))); }
    break;

  case 834:

/* Line 690 of lalr1.cc  */
#line 5819 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("comment"))); }
    break;

  case 835:

/* Line 690 of lalr1.cc  */
#line 5820 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("document-node"))); }
    break;

  case 836:

/* Line 690 of lalr1.cc  */
#line 5821 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("namespace-node"))); }
    break;

  case 837:

/* Line 690 of lalr1.cc  */
#line 5822 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("element"))); }
    break;

  case 838:

/* Line 690 of lalr1.cc  */
#line 5823 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("item"))); }
    break;

  case 839:

/* Line 690 of lalr1.cc  */
#line 5824 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("if"))); }
    break;

  case 840:

/* Line 690 of lalr1.cc  */
#line 5825 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("node"))); }
    break;

  case 841:

/* Line 690 of lalr1.cc  */
#line 5826 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("processing-instruction"))); }
    break;

  case 842:

/* Line 690 of lalr1.cc  */
#line 5827 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema-attribute"))); }
    break;

  case 843:

/* Line 690 of lalr1.cc  */
#line 5828 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema-element"))); }
    break;

  case 844:

/* Line 690 of lalr1.cc  */
#line 5829 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("text"))); }
    break;

  case 845:

/* Line 690 of lalr1.cc  */
#line 5830 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("typeswitch"))); }
    break;

  case 846:

/* Line 690 of lalr1.cc  */
#line 5831 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("switch"))); }
    break;

  case 847:

/* Line 690 of lalr1.cc  */
#line 5832 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("empty-sequence"))); }
    break;

  case 848:

/* Line 690 of lalr1.cc  */
#line 5833 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("while"))); }
    break;

  case 849:

/* Line 690 of lalr1.cc  */
#line 5834 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("json"))); }
    break;

  case 850:

/* Line 690 of lalr1.cc  */
#line 5835 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("append"))); }
    break;

  case 851:

/* Line 690 of lalr1.cc  */
#line 5836 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("json-item"))); }
    break;

  case 852:

/* Line 690 of lalr1.cc  */
#line 5837 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("array"))); }
    break;

  case 853:

/* Line 690 of lalr1.cc  */
#line 5838 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("structured-item"))); }
    break;

  case 855:

/* Line 690 of lalr1.cc  */
#line 5842 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))); }
    break;

  case 856:

/* Line 690 of lalr1.cc  */
#line 5843 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("xquery"))); }
    break;

  case 857:

/* Line 690 of lalr1.cc  */
#line 5844 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("empty"))); }
    break;

  case 858:

/* Line 690 of lalr1.cc  */
#line 5845 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("boundary-space"))); }
    break;

  case 859:

/* Line 690 of lalr1.cc  */
#line 5846 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ft-option"))); }
    break;

  case 860:

/* Line 690 of lalr1.cc  */
#line 5847 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("base-uri"))); }
    break;

  case 861:

/* Line 690 of lalr1.cc  */
#line 5848 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lax"))); }
    break;

  case 862:

/* Line 690 of lalr1.cc  */
#line 5849 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("strict"))); }
    break;

  case 863:

/* Line 690 of lalr1.cc  */
#line 5850 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("idiv"))); }
    break;

  case 864:

/* Line 690 of lalr1.cc  */
#line 5851 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("document"))); }
    break;

  case 865:

/* Line 690 of lalr1.cc  */
#line 5852 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ftnot"))); }
    break;

  case 866:

/* Line 690 of lalr1.cc  */
#line 5853 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("not"))); }
    break;

  case 867:

/* Line 690 of lalr1.cc  */
#line 5854 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sensitive"))); }
    break;

  case 868:

/* Line 690 of lalr1.cc  */
#line 5855 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("insensitive"))); }
    break;

  case 869:

/* Line 690 of lalr1.cc  */
#line 5856 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("diacritics"))); }
    break;

  case 870:

/* Line 690 of lalr1.cc  */
#line 5857 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("without"))); }
    break;

  case 871:

/* Line 690 of lalr1.cc  */
#line 5858 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stemming"))); }
    break;

  case 872:

/* Line 690 of lalr1.cc  */
#line 5859 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("thesaurus"))); }
    break;

  case 873:

/* Line 690 of lalr1.cc  */
#line 5860 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stop"))); }
    break;

  case 874:

/* Line 690 of lalr1.cc  */
#line 5861 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("wildcards"))); }
    break;

  case 875:

/* Line 690 of lalr1.cc  */
#line 5862 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("entire"))); }
    break;

  case 876:

/* Line 690 of lalr1.cc  */
#line 5863 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("content"))); }
    break;

  case 877:

/* Line 690 of lalr1.cc  */
#line 5864 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("word"))); }
    break;

  case 878:

/* Line 690 of lalr1.cc  */
#line 5865 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("start"))); }
    break;

  case 879:

/* Line 690 of lalr1.cc  */
#line 5866 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("end"))); }
    break;

  case 880:

/* Line 690 of lalr1.cc  */
#line 5867 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("most"))); }
    break;

  case 881:

/* Line 690 of lalr1.cc  */
#line 5868 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("skip"))); }
    break;

  case 882:

/* Line 690 of lalr1.cc  */
#line 5869 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("copy"))); }
    break;

  case 883:

/* Line 690 of lalr1.cc  */
#line 5870 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("general"))); }
    break;

  case 884:

/* Line 690 of lalr1.cc  */
#line 5871 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("value"))); }
    break;

  case 885:

/* Line 690 of lalr1.cc  */
#line 5872 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("eq"))); }
    break;

  case 886:

/* Line 690 of lalr1.cc  */
#line 5873 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ne"))); }
    break;

  case 887:

/* Line 690 of lalr1.cc  */
#line 5874 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lt"))); }
    break;

  case 888:

/* Line 690 of lalr1.cc  */
#line 5875 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("le"))); }
    break;

  case 889:

/* Line 690 of lalr1.cc  */
#line 5876 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("gt"))); }
    break;

  case 890:

/* Line 690 of lalr1.cc  */
#line 5877 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ge"))); }
    break;

  case 891:

/* Line 690 of lalr1.cc  */
#line 5878 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("at"))); }
    break;

  case 892:

/* Line 690 of lalr1.cc  */
#line 5879 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("context"))); }
    break;

  case 893:

/* Line 690 of lalr1.cc  */
#line 5880 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("variable"))); }
    break;

  case 894:

/* Line 690 of lalr1.cc  */
#line 5881 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("return"))); }
    break;

  case 895:

/* Line 690 of lalr1.cc  */
#line 5882 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("for"))); }
    break;

  case 896:

/* Line 690 of lalr1.cc  */
#line 5883 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("from"))); }
    break;

  case 897:

/* Line 690 of lalr1.cc  */
#line 5884 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("allowing"))); }
    break;

  case 898:

/* Line 690 of lalr1.cc  */
#line 5885 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sliding"))); }
    break;

  case 899:

/* Line 690 of lalr1.cc  */
#line 5886 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("tumbling"))); }
    break;

  case 900:

/* Line 690 of lalr1.cc  */
#line 5887 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("previous"))); }
    break;

  case 901:

/* Line 690 of lalr1.cc  */
#line 5888 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("next"))); }
    break;

  case 902:

/* Line 690 of lalr1.cc  */
#line 5889 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("only"))); }
    break;

  case 903:

/* Line 690 of lalr1.cc  */
#line 5890 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("when"))); }
    break;

  case 904:

/* Line 690 of lalr1.cc  */
#line 5891 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("count"))); }
    break;

  case 905:

/* Line 690 of lalr1.cc  */
#line 5892 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("in"))); }
    break;

  case 906:

/* Line 690 of lalr1.cc  */
#line 5893 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("let"))); }
    break;

  case 907:

/* Line 690 of lalr1.cc  */
#line 5894 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("where"))); }
    break;

  case 908:

/* Line 690 of lalr1.cc  */
#line 5895 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("by"))); }
    break;

  case 909:

/* Line 690 of lalr1.cc  */
#line 5896 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("group"))); }
    break;

  case 910:

/* Line 690 of lalr1.cc  */
#line 5897 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("order"))); }
    break;

  case 911:

/* Line 690 of lalr1.cc  */
#line 5898 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stable"))); }
    break;

  case 912:

/* Line 690 of lalr1.cc  */
#line 5899 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ascending"))); }
    break;

  case 913:

/* Line 690 of lalr1.cc  */
#line 5900 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descending"))); }
    break;

  case 914:

/* Line 690 of lalr1.cc  */
#line 5901 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("greatest"))); }
    break;

  case 915:

/* Line 690 of lalr1.cc  */
#line 5902 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("least"))); }
    break;

  case 916:

/* Line 690 of lalr1.cc  */
#line 5903 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("collation"))); }
    break;

  case 917:

/* Line 690 of lalr1.cc  */
#line 5904 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("some"))); }
    break;

  case 918:

/* Line 690 of lalr1.cc  */
#line 5905 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("every"))); }
    break;

  case 919:

/* Line 690 of lalr1.cc  */
#line 5906 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("satisfies"))); }
    break;

  case 920:

/* Line 690 of lalr1.cc  */
#line 5907 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("case"))); }
    break;

  case 921:

/* Line 690 of lalr1.cc  */
#line 5908 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("as"))); }
    break;

  case 922:

/* Line 690 of lalr1.cc  */
#line 5909 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("then"))); }
    break;

  case 923:

/* Line 690 of lalr1.cc  */
#line 5910 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("else"))); }
    break;

  case 924:

/* Line 690 of lalr1.cc  */
#line 5911 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("or"))); }
    break;

  case 925:

/* Line 690 of lalr1.cc  */
#line 5912 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("and"))); }
    break;

  case 926:

/* Line 690 of lalr1.cc  */
#line 5913 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("instance"))); }
    break;

  case 927:

/* Line 690 of lalr1.cc  */
#line 5914 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("of"))); }
    break;

  case 928:

/* Line 690 of lalr1.cc  */
#line 5915 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("castable"))); }
    break;

  case 929:

/* Line 690 of lalr1.cc  */
#line 5916 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("to"))); }
    break;

  case 930:

/* Line 690 of lalr1.cc  */
#line 5917 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("div"))); }
    break;

  case 931:

/* Line 690 of lalr1.cc  */
#line 5918 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("mod"))); }
    break;

  case 932:

/* Line 690 of lalr1.cc  */
#line 5919 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("union"))); }
    break;

  case 933:

/* Line 690 of lalr1.cc  */
#line 5920 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("intersect"))); }
    break;

  case 934:

/* Line 690 of lalr1.cc  */
#line 5921 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("except"))); }
    break;

  case 935:

/* Line 690 of lalr1.cc  */
#line 5922 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("validate"))); }
    break;

  case 936:

/* Line 690 of lalr1.cc  */
#line 5923 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("type"))); }
    break;

  case 937:

/* Line 690 of lalr1.cc  */
#line 5924 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("cast"))); }
    break;

  case 938:

/* Line 690 of lalr1.cc  */
#line 5925 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("treat"))); }
    break;

  case 939:

/* Line 690 of lalr1.cc  */
#line 5926 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("is"))); }
    break;

  case 940:

/* Line 690 of lalr1.cc  */
#line 5927 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preserve"))); }
    break;

  case 941:

/* Line 690 of lalr1.cc  */
#line 5928 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("strip"))); }
    break;

  case 942:

/* Line 690 of lalr1.cc  */
#line 5929 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("namespace"))); }
    break;

  case 943:

/* Line 690 of lalr1.cc  */
#line 5930 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("external"))); }
    break;

  case 944:

/* Line 690 of lalr1.cc  */
#line 5931 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("encoding"))); }
    break;

  case 945:

/* Line 690 of lalr1.cc  */
#line 5932 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("no-preserve"))); }
    break;

  case 946:

/* Line 690 of lalr1.cc  */
#line 5933 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("inherit"))); }
    break;

  case 947:

/* Line 690 of lalr1.cc  */
#line 5934 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("no-inherit"))); }
    break;

  case 948:

/* Line 690 of lalr1.cc  */
#line 5935 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("declare"))); }
    break;

  case 949:

/* Line 690 of lalr1.cc  */
#line 5936 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("construction"))); }
    break;

  case 950:

/* Line 690 of lalr1.cc  */
#line 5937 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ordering"))); }
    break;

  case 951:

/* Line 690 of lalr1.cc  */
#line 5938 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("default"))); }
    break;

  case 952:

/* Line 690 of lalr1.cc  */
#line 5939 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("copy-namespaces"))); }
    break;

  case 953:

/* Line 690 of lalr1.cc  */
#line 5940 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("option"))); }
    break;

  case 954:

/* Line 690 of lalr1.cc  */
#line 5941 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("version"))); }
    break;

  case 955:

/* Line 690 of lalr1.cc  */
#line 5942 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("import"))); }
    break;

  case 956:

/* Line 690 of lalr1.cc  */
#line 5943 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema"))); }
    break;

  case 957:

/* Line 690 of lalr1.cc  */
#line 5944 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("module"))); }
    break;

  case 958:

/* Line 690 of lalr1.cc  */
#line 5945 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("function"))); }
    break;

  case 959:

/* Line 690 of lalr1.cc  */
#line 5946 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("score"))); }
    break;

  case 960:

/* Line 690 of lalr1.cc  */
#line 5947 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("contains"))); }
    break;

  case 961:

/* Line 690 of lalr1.cc  */
#line 5948 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("weight"))); }
    break;

  case 962:

/* Line 690 of lalr1.cc  */
#line 5949 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("window"))); }
    break;

  case 963:

/* Line 690 of lalr1.cc  */
#line 5950 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("distance"))); }
    break;

  case 964:

/* Line 690 of lalr1.cc  */
#line 5951 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("occurs"))); }
    break;

  case 965:

/* Line 690 of lalr1.cc  */
#line 5952 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("times"))); }
    break;

  case 966:

/* Line 690 of lalr1.cc  */
#line 5953 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("same"))); }
    break;

  case 967:

/* Line 690 of lalr1.cc  */
#line 5954 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("different"))); }
    break;

  case 968:

/* Line 690 of lalr1.cc  */
#line 5955 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lowercase"))); }
    break;

  case 969:

/* Line 690 of lalr1.cc  */
#line 5956 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("uppercase"))); }
    break;

  case 970:

/* Line 690 of lalr1.cc  */
#line 5957 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("relationship"))); }
    break;

  case 971:

/* Line 690 of lalr1.cc  */
#line 5958 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("levels"))); }
    break;

  case 972:

/* Line 690 of lalr1.cc  */
#line 5959 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("language"))); }
    break;

  case 973:

/* Line 690 of lalr1.cc  */
#line 5960 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("any"))); }
    break;

  case 974:

/* Line 690 of lalr1.cc  */
#line 5961 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("all"))); }
    break;

  case 975:

/* Line 690 of lalr1.cc  */
#line 5962 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("exactly"))); }
    break;

  case 976:

/* Line 690 of lalr1.cc  */
#line 5963 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("words"))); }
    break;

  case 977:

/* Line 690 of lalr1.cc  */
#line 5964 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sentences"))); }
    break;

  case 978:

/* Line 690 of lalr1.cc  */
#line 5965 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sentence"))); }
    break;

  case 979:

/* Line 690 of lalr1.cc  */
#line 5966 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("phrase"))); }
    break;

  case 980:

/* Line 690 of lalr1.cc  */
#line 5967 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("paragraph"))); }
    break;

  case 981:

/* Line 690 of lalr1.cc  */
#line 5968 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("paragraphs"))); }
    break;

  case 982:

/* Line 690 of lalr1.cc  */
#line 5969 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("modify"))); }
    break;

  case 983:

/* Line 690 of lalr1.cc  */
#line 5970 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("first"))); }
    break;

  case 984:

/* Line 690 of lalr1.cc  */
#line 5971 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("replace"))); }
    break;

  case 985:

/* Line 690 of lalr1.cc  */
#line 5972 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("insert"))); }
    break;

  case 986:

/* Line 690 of lalr1.cc  */
#line 5973 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("rename"))); }
    break;

  case 987:

/* Line 690 of lalr1.cc  */
#line 5974 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("delete"))); }
    break;

  case 988:

/* Line 690 of lalr1.cc  */
#line 5975 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("before"))); }
    break;

  case 989:

/* Line 690 of lalr1.cc  */
#line 5976 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("after"))); }
    break;

  case 990:

/* Line 690 of lalr1.cc  */
#line 5977 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("revalidation"))); }
    break;

  case 991:

/* Line 690 of lalr1.cc  */
#line 5978 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("with"))); }
    break;

  case 992:

/* Line 690 of lalr1.cc  */
#line 5979 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("nodes"))); }
    break;

  case 993:

/* Line 690 of lalr1.cc  */
#line 5980 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("last"))); }
    break;

  case 994:

/* Line 690 of lalr1.cc  */
#line 5981 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("into"))); }
    break;

  case 995:

/* Line 690 of lalr1.cc  */
#line 5982 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("simple"))); }
    break;

  case 996:

/* Line 690 of lalr1.cc  */
#line 5983 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sequential"))); }
    break;

  case 997:

/* Line 690 of lalr1.cc  */
#line 5984 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("updating"))); }
    break;

  case 998:

/* Line 690 of lalr1.cc  */
#line 5985 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ordered"))); }
    break;

  case 999:

/* Line 690 of lalr1.cc  */
#line 5986 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("unordered"))); }
    break;

  case 1000:

/* Line 690 of lalr1.cc  */
#line 5987 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("returning"))); }
    break;

  case 1001:

/* Line 690 of lalr1.cc  */
#line 5988 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("exit"))); }
    break;

  case 1002:

/* Line 690 of lalr1.cc  */
#line 5989 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("loop"))); }
    break;

  case 1003:

/* Line 690 of lalr1.cc  */
#line 5990 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("break"))); }
    break;

  case 1004:

/* Line 690 of lalr1.cc  */
#line 5991 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("continue"))); }
    break;

  case 1005:

/* Line 690 of lalr1.cc  */
#line 5992 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("try"))); }
    break;

  case 1006:

/* Line 690 of lalr1.cc  */
#line 5993 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("catch"))); }
    break;

  case 1007:

/* Line 690 of lalr1.cc  */
#line 5994 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("using"))); }
    break;

  case 1008:

/* Line 690 of lalr1.cc  */
#line 5995 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("set"))); }
    break;

  case 1009:

/* Line 690 of lalr1.cc  */
#line 5996 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("index"))); }
    break;

  case 1010:

/* Line 690 of lalr1.cc  */
#line 5997 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("unique"))); }
    break;

  case 1011:

/* Line 690 of lalr1.cc  */
#line 5998 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("non"))); }
    break;

  case 1012:

/* Line 690 of lalr1.cc  */
#line 5999 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("on"))); }
    break;

  case 1013:

/* Line 690 of lalr1.cc  */
#line 6000 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("range"))); }
    break;

  case 1014:

/* Line 690 of lalr1.cc  */
#line 6001 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("equality"))); }
    break;

  case 1015:

/* Line 690 of lalr1.cc  */
#line 6002 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("manually"))); }
    break;

  case 1016:

/* Line 690 of lalr1.cc  */
#line 6003 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("automatically"))); }
    break;

  case 1017:

/* Line 690 of lalr1.cc  */
#line 6004 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("maintained"))); }
    break;

  case 1018:

/* Line 690 of lalr1.cc  */
#line 6005 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("decimal-format"))); }
    break;

  case 1019:

/* Line 690 of lalr1.cc  */
#line 6006 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("decimal-separator"))); }
    break;

  case 1020:

/* Line 690 of lalr1.cc  */
#line 6007 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("grouping-separator"))); }
    break;

  case 1021:

/* Line 690 of lalr1.cc  */
#line 6008 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("infinity"))); }
    break;

  case 1022:

/* Line 690 of lalr1.cc  */
#line 6009 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("minus-sign"))); }
    break;

  case 1023:

/* Line 690 of lalr1.cc  */
#line 6010 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("NaN"))); }
    break;

  case 1024:

/* Line 690 of lalr1.cc  */
#line 6011 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("percent"))); }
    break;

  case 1025:

/* Line 690 of lalr1.cc  */
#line 6012 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("per-mille"))); }
    break;

  case 1026:

/* Line 690 of lalr1.cc  */
#line 6013 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("zero-digit"))); }
    break;

  case 1027:

/* Line 690 of lalr1.cc  */
#line 6014 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("digit"))); }
    break;

  case 1028:

/* Line 690 of lalr1.cc  */
#line 6015 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("pattern-separator"))); }
    break;

  case 1029:

/* Line 690 of lalr1.cc  */
#line 6016 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("collection"))); }
    break;

  case 1030:

/* Line 690 of lalr1.cc  */
#line 6017 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("const"))); }
    break;

  case 1031:

/* Line 690 of lalr1.cc  */
#line 6018 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("append-only"))); }
    break;

  case 1032:

/* Line 690 of lalr1.cc  */
#line 6019 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("queue"))); }
    break;

  case 1033:

/* Line 690 of lalr1.cc  */
#line 6020 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("mutable"))); }
    break;

  case 1034:

/* Line 690 of lalr1.cc  */
#line 6021 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("read-only"))); }
    break;

  case 1035:

/* Line 690 of lalr1.cc  */
#line 6022 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("integrity"))); }
    break;

  case 1036:

/* Line 690 of lalr1.cc  */
#line 6023 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("constraint"))); }
    break;

  case 1037:

/* Line 690 of lalr1.cc  */
#line 6024 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("check"))); }
    break;

  case 1038:

/* Line 690 of lalr1.cc  */
#line 6025 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("key"))); }
    break;

  case 1039:

/* Line 690 of lalr1.cc  */
#line 6026 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("foreach"))); }
    break;

  case 1040:

/* Line 690 of lalr1.cc  */
#line 6027 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("foreign"))); }
    break;

  case 1041:

/* Line 690 of lalr1.cc  */
#line 6028 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("keys"))); }
    break;

  case 1042:

/* Line 690 of lalr1.cc  */
#line 6029 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ancestor"))); }
    break;

  case 1043:

/* Line 690 of lalr1.cc  */
#line 6030 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("child"))); }
    break;

  case 1044:

/* Line 690 of lalr1.cc  */
#line 6031 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descendant"))); }
    break;

  case 1045:

/* Line 690 of lalr1.cc  */
#line 6032 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("parent"))); }
    break;

  case 1046:

/* Line 690 of lalr1.cc  */
#line 6033 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preceding"))); }
    break;

  case 1047:

/* Line 690 of lalr1.cc  */
#line 6034 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("self"))); }
    break;

  case 1048:

/* Line 690 of lalr1.cc  */
#line 6035 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("following"))); }
    break;

  case 1049:

/* Line 690 of lalr1.cc  */
#line 6036 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ancestor-or-self"))); }
    break;

  case 1050:

/* Line 690 of lalr1.cc  */
#line 6037 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descendant-or-self"))); }
    break;

  case 1051:

/* Line 690 of lalr1.cc  */
#line 6038 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("following-sibling"))); }
    break;

  case 1052:

/* Line 690 of lalr1.cc  */
#line 6039 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preceding-sibling"))); }
    break;

  case 1053:

/* Line 690 of lalr1.cc  */
#line 6040 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("position"))); }
    break;

  case 1054:

/* Line 690 of lalr1.cc  */
#line 6043 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), true); }
    break;



/* Line 690 of lalr1.cc  */
#line 12444 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
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

    char const* yyformat = 0;
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
  const short int jsoniq_parser::yypact_ninf_ = -1562;
  const short int
  jsoniq_parser::yypact_[] =
  {
      5147, -1562, -1562, -1562, -1562,  6411,  6411,  6411,  6411, -1562,
   -1562,    36,    67, -1562,   648,   126, -1562, -1562, -1562,   919,
   -1562, -1562, -1562,   385,   273,   920,  4634,   390,   419,   799,
   -1562,    87, -1562,   421, -1562, -1562, -1562, -1562, -1562,   925,
   -1562,   467,   490, -1562, -1562, -1562, -1562,    83, -1562,   926,
   -1562,   605,   626, -1562,   305, -1562, -1562, -1562, -1562, -1562,
   -1562, -1562, -1562, -1562, -1562, -1562, -1562, -1562, -1562,   713,
     791, -1562, -1562, -1562, -1562,   823, 15546, -1562, -1562, -1562,
     858, -1562, -1562, -1562,   262, -1562,   883,   915, -1562, -1562,
   20382, -1562, -1562, -1562, -1562, -1562, -1562, -1562, -1562,   695,
   -1562, -1562,   949,   952, -1562, -1562, -1562, -1562, -1562, -1562,
   -1562,  6411,  8616,  8931, 20382, -1562, -1562,   936, -1562, -1562,
   -1562, -1562,   940, -1562, -1562,   962, 20382, -1562, 18877,   983,
     994, -1562, -1562, -1562,   995, -1562, -1562, 13341, -1562, -1562,
   -1562, -1562, -1562, -1562,   958, -1562, -1562, -1562, -1562, -1562,
   -1562, -1562, -1562,   128,   903,   906, -1562, -1562, -1562, -1562,
   -1562, -1562, -1562, -1562, -1562, -1562, -1562, 21289,   964, 16158,
   -1562, 21590,   232, -1562, -1562, -1562, -1562, -1562, -1562,  1007,
   -1562,   879,   882,   884, -1562, -1562,   972,   978, -1562, -1562,
   -1562, -1562, -1562, -1562, -1562, -1562, -1562, -1562, -1562, -1562,
    4860, -1562, 14286, -1562, -1562, -1562, -1562, -1562, -1562, -1562,
   -1562, -1562, -1562, -1562, -1562, -1562, -1562, -1562, -1562, -1562,
   -1562, -1562, -1562, -1562, -1562, -1562, -1562, -1562, -1562, -1562,
   -1562, -1562, -1562, -1562, -1562, -1562, -1562, -1562, -1562, -1562,
   -1562, -1562, -1562, -1562, -1562, -1562, -1562, -1562, -1562, -1562,
   -1562,  9246,  9561, -1562, 13971, -1562, -1562, -1562, -1562,  5464,
    5781,  1135, -1562,  6726, -1562, -1562,   155,    98, -1562, -1562,
   -1562, -1562, -1562, -1562, -1562, -1562, -1562, -1562, -1562, -1562,
   -1562, -1562,   114, -1562, -1562, -1562, -1562, -1562, -1562,   367,
   -1562, -1562, -1562, -1562, -1562, -1562, -1562, -1562,  6411, -1562,
   -1562, -1562, -1562,    40, -1562, -1562, -1562, -1562, -1562, -1562,
   -1562, -1562, -1562,   112, -1562,   947, -1562, -1562, -1562,   666,
   -1562,   463, -1562, -1562, -1562, -1562, -1562, -1562, -1562,   968,
    1044, -1562, -1562,  1067,   885,  1040,   571,   597,   469,   738,
   -1562,  1092,   948,  1045,  1043, 11136, -1562,   957, -1562, -1562,
      29, -1562, -1562, 13656, -1562,   562, -1562,   997, 15546, -1562,
     997, 15546, -1562, -1562, -1562,   780, -1562, -1562, -1562, -1562,
   -1562, -1562, -1562, -1562, -1562, -1562, -1562, -1562, -1562, -1562,
   -1562, -1562, -1562, -1562, -1562, -1562, -1562, -1562, -1562, -1562,
   -1562, -1562, -1562, -1562,   996, -1562, -1562, -1562, -1562, -1562,
   -1562, -1562, -1562, -1562, -1562, -1562, -1562, -1562, -1562, -1562,
   -1562, -1562, -1562, -1562, -1562, -1562, -1562, -1562, -1562, -1562,
   -1562, -1562,   659, -1562, -1562, -1562, -1562, -1562,   970, -1562,
    6411,   974,   975,   976,  6411,   193,   193,  1132,   619,   701,
     321, 21887, 20382,    23,  1116, 20382,  1012,  1048,   646, 20382,
     875,   917, 20382, 20382,   861,   362,    50, -1562, -1562, -1562,
   20382,  6411,   984,  6411,   191, 11451, 19178, 20382,   291,  1019,
   11451,  1178,    84,    89, 20382,  1062,  1038,  1088, -1562,  1009,
   11451, 19479, 20382, 20382, 20382,  6411,  1010, 11451, 11451, 20382,
    6411,  1047,  1049, -1562, -1562, -1562, 11451, 19780,  1041, -1562,
    1053, -1562, -1562, -1562, -1562,  1055, -1562,  1056, -1562, -1562,
   -1562, -1562, -1562,  1057, -1562, -1562, -1562, -1562, -1562, -1562,
   -1562, -1562, -1562, -1562, -1562, -1562, -1562, -1562, -1562, -1562,
   -1562, -1562, -1562, -1562, -1562, -1562, -1562, -1562, -1562, -1562,
   -1562, -1562, -1562, -1562, 20382, -1562, -1562, -1562, -1562, -1562,
   -1562, -1562, -1562, -1562, -1562, -1562, -1562, -1562,  1063, 20382,
   -1562, -1562,  1021,  6096,  1093,   301,  1094,  1060,  1061,  1064,
   20382,  6411, -1562,  1068,   182, -1562,   698, -1562,   160,  1192,
   11451, 11451, -1562,    86, -1562, -1562,  1211, -1562, -1562, -1562,
   -1562, 11451,  1014, -1562,  1200,  1202,  1078,  1079,  1080,  1081,
    1082, 11451, 12711, 20988,   780,   659, 14601, 15231, 14916,     3,
     136, 11451, 20988,   608, 11451,  1002,  1005, 20382,  1050,  1051,
   11451, 11451,  6411,   993, 20382, -1562, -1562,    61, -1562,    60,
   14916,  1008,  5781, -1562, -1562, -1562, -1562, -1562,   648,   799,
     116,   119,  1241,  7041,  3352,  7356,  3678,   262, -1562, -1562,
     247,   262, -1562, 11451,  4308, -1562,  1126,   606,    87,  1083,
    1077,  1084,  6411, 11451,   822, -1562, -1562, -1562, -1562, -1562,
   -1562, -1562, -1562, -1562,   960,   961, 20382,  1134, 11766, 11766,
   12081, -1562, 12081, 12081, -1562, 12081, -1562, 12081, -1562, -1562,
   -1562, -1562, -1562, -1562, -1562, 12081, 12081,  1180, 12081, 12081,
   12081, 12081, 12081, 12081, 12081, 12081, 12081, 12081, 12081, 12081,
    1020,  1162,  1163,  1164, -1562, -1562, -1562, 13026,  9876, -1562,
   -1562, 13341, 13341, 11451,   997, -1562, -1562,   997, -1562, 17965,
   10191,  7986,   997,  1072,  1110,  8301, -1562, -1562, -1562, -1562,
      64, -1562,    97, -1562, -1562, -1562, -1562, -1562, -1562,  1155,
    1157,   390,  1237, -1562, -1562, 21887,  1105,   761, 20382,  1106,
    1107,  1105,  1132,  1141,  1143, -1562, -1562, -1562,   332,  1028,
    1185,   979, 20382,  1138, 11451,  1165, 20382, 20382, -1562,  1152,
    1102, -1562,  1103,  1053,   490, -1562,  1101,  1108,   142, -1562,
     296,   340,  1182, -1562,    43, 20382,  1198,   429, -1562,  6411,
   -1562,   164, -1562, 20382,  1197,  1250, 20382,  1132,  1201,   565,
   20382, 11451,    87, -1562,   150,  1109, -1562,  1111,  1112,  1115,
      -2, -1562,    81,  1119, -1562,   165,   170,  1151, -1562,  1122,
    6411,  6411,   389, -1562,   441,   482,   647, 11451,    44, -1562,
   -1562, 11451, 11451, -1562, 11451, 11451, 11451, 11451, -1562, 11451,
   -1562, 11451, -1562, 20382,  1192, -1562,   492,   395,   401, -1562,
   -1562, -1562,   417, -1562,   252,   528, -1562, -1562,   780,   303,
     373,   324,   276, 11451, 11451,  1213,   760, 11451,  1070, 20687,
    1073,   127, -1562,  1166, -1562, -1562,  1124,   173,  6096,   425,
   15852,   993, -1562,  1182, -1562, -1562,  1075, 11451, -1562,   155,
     826,  1284,   185, -1562, -1562,   123, -1562, -1562, -1562,   129,
   -1562,   100, -1562, -1562, -1562, -1562, -1562,  3993, -1562, -1562,
   -1562, 20382,  1147, 11451, 12396, -1562, -1562, -1562, -1562, -1562,
    1182, 20382,    34,  1044, -1562, -1562, -1562, -1562, -1562, 12081,
   -1562, -1562, -1562,   671, -1562,   597,   597,   352,   469,   469,
     469,   469,   738,   738, -1562, -1562, 18266, 18266, 20382, 20382,
   -1562, -1562,   428, -1562, -1562,   226, -1562, 10506, -1562, -1562,
   -1562, -1562, -1562, -1562, -1562,   523, -1562, -1562, -1562,   530,
     193, -1562, -1562,    45,   736,   857, -1562,   390, -1562, -1562,
   -1562, -1562, -1562, -1562, -1562, -1562, -1562, -1562,  1105, -1562,
    1187, 18567,  1175, 11451, -1562, -1562, -1562,  1227,  1132,  1132,
    1105, -1562,   931,  1132,   783, 20382,   737,   774,  1293, -1562,
   -1562,  1033,   536, -1562, -1562, -1562, -1562, -1562, -1562, -1562,
   -1562, -1562, -1562, -1562,   332,    47,  1095,   704, 11451, -1562,
   20382,  1233,  1026,  1132, -1562, -1562, -1562, -1562,  1174, 20382,
   -1562, 20382, -1562, 20081,  1204, 18266,  1212, 11451,   -33,  1188,
      59,  1227, 18266,  1215,  1243,  1156,  1144,  1206,  1132,  1184,
    1208,  1247,  1132, 11451,   -39, -1562, -1562, -1562,  1193, -1562,
   -1562, -1562, -1562,  1228, 11451, 11451,  1203, -1562,  1249,  1252,
    6411, -1562,  1169,  1172,  1196, 20382, -1562, 20382, -1562, 11451,
    1214,  1168, 11451, -1562,  1238,  1239, -1562,   184,   209,   218,
    1329, -1562,   522, -1562,   770,  1210, -1562, -1562,  1337, -1562,
    1339, -1562,   850, 11451, 11451, 11451,   855, 11451, 11451, 11451,
   11451, 11451,  1274, -1562, 11451, 11451, -1562, 11451, 11451,   576,
   20988,  1253, 11451, 11451, -1562,  7671,   134,  1125, -1562,    18,
   -1562, 11451, -1562,   132,   141,   100,  7356,  3678,  7356,  1297,
   -1562, -1562, 11451,   904,  1270, -1562, 20382,  1272,  1273, -1562,
     535,  1121, -1562, -1562,   742,    34, -1562, 11451,   671,   828,
     337, -1562,  1096,     7,  1127,  1117, -1562, -1562,   917, -1562,
    1113,   593,  1226,  1229, 16761,  1230, -1562,  1234,  1235,  1236,
    1245, -1562,   561, -1562, -1562, -1562, -1562, -1562, -1562, -1562,
   -1562, -1562, -1562,  1251, -1562, -1562, -1562, -1562, -1562,   223,
   10821, -1562, -1562, -1562, -1562, -1562, -1562, -1562, -1562, -1562,
     865, -1562,  1361, 18567,   820, -1562, -1562, -1562, -1562, -1562,
   -1562, -1562, -1562, -1562,  1104, -1562, -1562,  1369, -1562, -1562,
   -1562, -1562, -1562,   690,  1371, -1562,   816, -1562, -1562, -1562,
    1041,   273,   421,  1055,   467,  1056,  1057, -1562,  1235,  1236,
   -1562,   561,   561, 13026,  1114,  1097, -1562,  1227,    47,  1173,
    1216,  6411,  1221,  1222,  1258,  1225,  1231, 20382, -1562,    94,
   -1562, 20382, -1562, 11451,  1266, 11451,  1287, 11451,   242,  1268,
   -1562, -1562, -1562, 18266, -1562,  6411,  1132,  1312, -1562, -1562,
   -1562,  1132,  1312, -1562, 11451,  1277,  6411, 20382, -1562, -1562,
   11451, 11451,   908, -1562,    28,   918, -1562, 17062,   924, -1562,
     944, -1562,  1240, -1562, -1562,  6411,  1242,  1244, -1562, 11451,
   -1562, -1562, 11451, 11451,  1224,  1249,  1323, -1562,  1292, -1562,
     868, -1562, -1562,  1420, -1562, -1562,  6411, 20382, -1562,   989,
   -1562, -1562, -1562,  6411,  1246,  1248,  1190,  1191, -1562, -1562,
   -1562,  1195,  1207, -1562, -1562, -1562,  1338, -1562,  1120, -1562,
   -1562, -1562,  1194, 11451,   579, 20382,  1255, -1562,  1276,  1280,
    1282,  1289, -1562,   947,   801, 15852,  1125, -1562,  7671, 15852,
   -1562, -1562,  1284,   391, -1562, -1562, -1562,  1270, -1562,  1132,
   -1562,   938, -1562,   636,  1340, -1562, 11451,   664,  1132, -1562,
   12396, 11451,  1300, -1562,  1327,  1331, 11451, 20382,   982,  1374,
   -1562, -1562, -1562,   436,  1265, -1562,   671,  1199, -1562, -1562,
     257, -1562,   689,   101,  1205,   671,   689, 12081, -1562,    99,
   -1562, -1562, -1562, -1562, -1562, -1562,   671,  1307,  1170,  1028,
     101, -1562, -1562,  1171,  1382, -1562, -1562, -1562, 16460,  1275,
   -1562,  1279,  1281,  1283,  1286,  1288,  1290, -1562, -1562, -1562,
   -1562, -1562, -1562, -1562, -1562, -1562, -1562, -1562, -1562, -1562,
   -1562,  1434,    32,  1435,    32,  1209,  1360, -1562, -1562,  1299,
   20382,  1217, -1562, -1562, 13026, -1562,  1296, -1562, -1562, -1562,
   -1562, -1562, -1562, 11451,  1328, -1562, -1562, 11451, -1562,   590,
   -1562, 11451,  1333, 11451, -1562,  1355,  1356,  1389,  1132,  1312,
   -1562, 11451,  1306, -1562, -1562, -1562,  1305, -1562,   302, 11451,
    6411,  1309,   304, -1562, 20382,   601, -1562, 17363,   356, -1562,
   17664,  1310, -1562, -1562,  1308, -1562, -1562, -1562, -1562, -1562,
   11451,   945,  1329, 20382,  1025, -1562,  1313,  1329, 20382, -1562,
    1314, -1562, -1562, 11451, 11451, 11451, 11451,  1179, 11451, 11451,
   -1562, 11451, -1562, 11451, 11451, 11451, 11451,  7671,   297, -1562,
   -1562, -1562, -1562, -1562,  1340, -1562, -1562, -1562, 11451,  1350,
   -1562, -1562, -1562, 11451, 20382, 20382, -1562,   739, -1562, 11451,
   -1562, -1562, -1562,  1316, 12081, -1562, -1562, -1562, -1562, -1562,
     145, 12081, 12081,   706, -1562,  1127, -1562,   476, -1562,  1117,
     671,  1347, -1562, -1562,  1219, -1562, -1562, -1562, -1562,  1410,
    1318, -1562,   584, -1562, -1562, -1562, -1562, -1562, -1562, -1562,
   -1562,    58,    58, -1562,    32, -1562, -1562,   588, -1562,  1477,
     103,  1411,  1322, 13026,   -21,  1220,  1342, -1562, -1562, 11451,
   -1562, 11451,  1362, -1562, 11451, -1562,  7671, 11451,  1132, -1562,
   -1562, -1562, 11451, 11451, -1562, -1562, -1562,  7671,  7671,  1419,
    6411, 18266, 20382,   693, 20382, 11451, 20382,   716,  7671, -1562,
     537,    38,  1329, 20382, -1562,  1317,  1329, -1562, -1562, -1562,
   -1562, -1562, 11451, -1562, -1562, -1562, -1562,   231,   237,   265,
   11451, -1562, -1562,  1272, 11451, -1562, -1562,  1462, -1562, -1562,
   -1562,   469, 12081, 12081,   352,   634, -1562, -1562, -1562, -1562,
   -1562, -1562, 11451, -1562, 18266, -1562, 18266,  1422, -1562, -1562,
   -1562,  1488, -1562, -1562, -1562,  1254,  1412, -1562, -1562,  1413,
   -1562,   574, 20382,  1404,  1298, 20382, 13026, -1562, -1562, 11451,
   -1562, -1562, -1562,  1312, -1562, -1562, 18266, -1562, -1562, -1562,
    1431, 11451,  1343, -1562,  1432,  7671, -1562, 20382,   473,   547,
   -1562,  1334,  1329, -1562,  1335, -1562,  1330,  1249,  1252,   438,
   -1562,  1272,  1415,   352,   352, 12081,   450, -1562, -1562, 18266,
   -1562, -1562,  1411, 13026, -1562,  1340,  1232, 20382,  1416,  1301,
    1413, -1562,   763, 18266,  6411, 18266,  1349, -1562, -1562,  1443,
     512, -1562, -1562, -1562, -1562,  1357,   650, -1562, -1562, -1562,
    1341, -1562,  7671,   946, -1562, -1562, 20382,   352, -1562, -1562,
   -1562, -1562, -1562, 11451,  1257, 20382,  1425,  6411,   766, -1562,
   -1562,   781, 11451, -1562, -1562, -1562, -1562, -1562, -1562, -1562,
    1426, -1562, -1562,  1256,  1259, 20382, -1562, -1562, 11451,  7671,
   20382,  1260, 11451,  1261,  1359, 13026, -1562, 13026,  7671, -1562,
    1351,  1263, 20382,  1319,  1428, 20382,  1262, 13026, -1562
  };

  /* YYDEFACT[S] -- default reduction number in state S.  Performed when
     YYTABLE doesn't specify something else to do.  Zero means the
     default is an error.  */
  const unsigned short int
  jsoniq_parser::yydefact_[] =
  {
       167,   474,   475,   832,   476,   170,   170,   170,     0,   855,
    1054,   122,   124,   653,   948,   957,   897,   860,   858,   834,
     949,   952,   904,   864,   835,   837,     0,   958,   839,   955,
     926,   906,   880,   836,   901,   902,   953,   950,   900,   841,
     956,   842,   843,   996,  1008,   995,   898,   917,   911,   844,
     899,   846,   845,   997,   935,   936,   903,   877,  1018,  1019,
    1020,  1021,  1022,  1023,  1024,  1025,  1026,  1027,  1028,  1042,
    1049,   925,   921,   912,   891,   833,     0,   920,   928,   937,
    1043,   916,   508,   892,   893,   951,  1044,  1050,   913,   930,
       0,   516,   463,   510,   923,   857,   914,   915,   944,   918,
     934,   943,  1048,  1051,   863,   905,   946,   509,   933,   939,
     838,   170,     0,     0,     0,   409,   931,   942,   947,   945,
     924,   910,   998,   908,   909,  1045,     0,   408,     0,  1046,
    1052,   940,   894,   919,  1047,   213,   441,     0,   473,   941,
     922,   929,   938,   932,   999,   885,   890,   889,   888,   887,
     886,   847,   907,     0,   856,     0,   954,   878,   507,   511,
     512,   989,   988,   990,   862,   861,   881,   987,   840,   985,
     992,   986,   984,   884,   927,   983,   994,   993,   982,   882,
     991,  1003,  1004,  1001,  1002,  1000,   848,  1005,  1006,  1007,
     974,   973,   960,   876,   869,   967,   963,   879,   875,   975,
       0,   865,   866,   859,   868,   972,   971,   968,   964,   980,
     981,   979,   970,   966,   959,   867,   978,   977,   871,   873,
     872,   965,   969,   961,   874,   962,   870,   976,  1029,  1030,
    1031,  1032,  1033,  1034,  1010,  1011,  1009,  1015,  1016,  1017,
    1012,  1013,  1014,   883,  1035,  1036,  1037,  1038,  1039,  1040,
    1041,     0,     0,   849,   850,  1053,   852,   851,   853,   167,
     167,     0,     2,   167,     9,    11,    25,     0,    30,    33,
      38,    39,    40,    41,    42,    43,    44,    34,    60,    61,
      35,    36,     0,    78,    81,    82,    37,    83,    84,     0,
     120,    85,    86,    87,    88,    20,   164,   165,   166,   173,
     176,   499,   177,     0,   178,   179,   180,   181,   182,   183,
     184,   187,   188,     0,   214,   222,   217,   249,   255,     0,
     247,     0,   248,   224,   218,   186,   219,   185,   220,   223,
     358,   360,   362,   364,   374,   376,   380,   382,   385,   390,
     393,   396,   398,   400,   402,     0,   406,   413,   412,   414,
       0,   432,   415,   437,   440,   442,   445,   447,     0,   452,
     449,     0,   460,   470,   472,   446,   477,   490,   504,   506,
     491,   492,   493,   496,   497,   494,   498,   525,   526,   495,
     529,   531,   532,   533,   530,   578,   579,   580,   581,   582,
     583,   584,   469,   625,     0,   616,   624,   623,   622,   621,
     618,   620,   617,   619,   505,    45,   225,   226,   228,   227,
     229,   221,   501,   502,   503,   500,   231,   234,   230,   232,
     233,   471,   831,   854,   948,   957,   955,   856,     0,   168,
     169,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   128,   130,   131,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   280,   281,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   465,   468,   455,     0,     0,   834,   864,
     837,   895,   958,   839,   906,   841,   917,   844,   846,   845,
     935,  1042,  1049,   833,  1043,   893,  1044,  1050,   918,  1048,
    1051,   942,   998,  1045,  1046,  1052,  1047,   999,   987,   985,
     986,   984,   882,  1003,  1004,  1001,   848,  1005,   896,   866,
     850,   461,   831,   453,     0,   194,   454,   457,   834,   835,
     837,   836,   841,   842,   843,   844,   833,   840,   513,     0,
     459,   458,     0,     0,   214,     0,   471,   839,   846,   845,
       0,   170,   801,  1005,     0,   222,     0,   514,     0,   545,
       0,     0,   464,     0,   435,   436,     0,   467,   466,   456,
     439,     0,     0,   574,     0,     0,     0,     0,     0,     0,
       0,     0,   992,     0,   821,     0,   840,   992,   849,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   363,   803,     0,   805,     0,
     849,     0,   167,     3,     4,     1,    10,    12,     0,     0,
       0,     0,     6,   167,     0,   167,     0,     0,   121,   174,
       0,     0,   192,     0,     0,   201,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   206,   235,   254,   250,   256,
     251,   253,   252,   260,     0,     0,     0,     0,     0,     0,
       0,   425,     0,     0,   423,     0,   369,     0,   424,   417,
     422,   421,   420,   419,   418,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   411,   410,   407,     0,     0,   433,
     438,     0,     0,     0,   448,   487,   451,   450,   462,     0,
       0,     0,   478,     0,     0,     0,   586,   588,   592,   594,
       0,   126,     0,   830,    49,    46,    47,    50,    51,     0,
       0,     0,     0,    52,    53,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   660,   661,   662,     0,   105,
     144,     0,     0,   114,     0,     0,     0,     0,   129,     0,
       0,   633,     0,     0,     0,   628,     0,     0,     0,   643,
       0,     0,   258,   263,     0,     0,   136,     0,   140,   170,
     528,     0,    62,     0,    71,     0,     0,     0,    63,     0,
       0,     0,     0,   631,     0,     0,   634,     0,     0,     0,
       0,   329,     0,     0,   632,     0,     0,     0,   651,     0,
       0,     0,     0,   637,     0,     0,   196,     0,     0,   190,
     189,     0,     0,   807,     0,     0,     0,     0,   513,     0,
     802,     0,   515,   546,   545,   542,     0,     0,     0,   576,
     575,   434,     0,   573,     0,     0,   673,   674,   820,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   679,     0,   204,   205,     0,     0,     0,     0,
       0,   209,   210,   259,   804,   806,     0,     0,     5,    26,
       0,    27,     0,     7,    31,     0,    17,     8,    32,     0,
      21,   948,    79,    18,    80,    22,   195,     0,   193,   215,
     216,     0,     0,     0,     0,   207,   236,   298,   237,   238,
     257,     0,     0,   359,   361,   367,   373,   372,   371,     0,
     368,   365,   366,     0,   377,   384,   383,   381,   387,   388,
     389,   386,   391,   392,   395,   394,     0,     0,     0,     0,
     416,   430,     0,   443,   444,     0,   488,     0,   485,   486,
     482,   481,   521,   479,   523,     0,   626,   527,   519,     0,
       0,   123,   125,     0,     0,     0,   104,     0,    94,    96,
      97,    98,    99,   101,   102,   103,    95,   100,    90,    91,
       0,     0,   110,     0,   106,   108,   109,   116,     0,     0,
      89,    48,     0,     0,     0,     0,     0,     0,     0,   751,
     756,     0,     0,   752,   786,   739,   741,   742,   743,   745,
     747,   746,   744,   748,     0,     0,     0,     0,     0,   113,
       0,   146,     0,     0,   591,   585,   629,   630,     0,     0,
     647,     0,   644,     0,     0,     0,     0,     0,     0,     0,
       0,   142,     0,     0,   137,     0,     0,     0,     0,     0,
       0,    64,     0,     0,     0,   279,   285,   282,     0,   636,
     635,   642,   650,     0,     0,     0,     0,   590,     0,     0,
       0,   426,     0,     0,     0,     0,   640,     0,   638,     0,
     197,     0,     0,   809,     0,   471,   808,     0,     0,     0,
     545,   543,     0,   534,     0,     0,   517,   518,     0,    13,
       0,    15,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   815,   816,     0,     0,   823,     0,     0,     0,
       0,     0,     0,     0,   202,     0,     0,     0,   687,     0,
     211,     0,   819,     0,     0,     0,   167,     0,   167,     0,
     175,   246,     0,   313,   309,   311,     0,   306,   299,   300,
       0,     0,   239,   240,     0,   245,   370,     0,     0,     0,
       0,   717,   378,   690,   694,   696,   698,   700,   703,   710,
     711,   719,   958,   838,     0,   847,   614,   829,   852,   851,
     853,   397,   597,   604,   605,   608,   654,   655,   609,   610,
     613,   399,   401,   404,   615,   403,   431,   489,   483,     0,
       0,   480,   520,   127,    58,    59,    56,    57,   133,   132,
       0,    92,     0,     0,     0,   111,   112,   117,    76,    77,
      54,    55,    75,   757,     0,   760,   787,     0,   750,   749,
     754,   753,   785,     0,     0,   762,     0,   758,   761,   740,
       0,     0,     0,     0,     0,     0,     0,   627,     0,     0,
     145,   148,   150,     0,     0,     0,   115,   118,     0,     0,
       0,   170,     0,     0,   651,     0,     0,     0,   265,     0,
     596,     0,   266,     0,     0,     0,     0,     0,     0,     0,
     143,   138,   141,     0,   191,     0,     0,    73,    67,    70,
      69,     0,    65,   283,     0,     0,   170,     0,   327,   331,
       0,     0,     0,   334,     0,     0,   340,     0,     0,   347,
       0,   351,     0,   428,   427,   170,     0,     0,   198,     0,
     200,   328,     0,     0,     0,     0,     0,   546,     0,   536,
       0,   569,   566,     0,   570,   571,     0,     0,   565,     0,
     540,   568,   567,     0,     0,     0,     0,     0,   666,   667,
     663,     0,     0,   671,   672,   668,   812,   813,     0,   677,
     822,   675,     0,     0,     0,     0,     0,   681,   839,   846,
     845,  1005,   203,     0,     0,     0,   682,   683,     0,     0,
     212,   818,    28,     0,    19,    23,    24,   310,   322,     0,
     323,     0,   314,   315,   316,   317,     0,   513,     0,   307,
       0,     0,     0,   241,     0,     0,     0,     0,   292,     0,
     289,   294,   244,     0,     0,   701,   714,     0,   375,   379,
       0,   733,     0,     0,     0,     0,     0,     0,   689,   691,
     692,   728,   729,   730,   732,   731,     0,     0,   705,   704,
       0,   708,   712,   726,   724,   723,   716,   720,     0,     0,
     600,     0,     0,     0,     0,     0,     0,   601,   603,   602,
     598,   405,   484,   522,   524,   135,   134,    93,   107,   774,
     755,     0,   779,     0,   779,   768,   763,   149,   151,     0,
       0,     0,   119,   147,     0,    29,     0,   648,   649,   652,
     645,   646,   264,     0,     0,   278,   270,     0,   274,     0,
     268,     0,     0,     0,   139,     0,     0,    72,     0,    66,
     284,     0,     0,   330,   332,   337,     0,   335,     0,     0,
       0,     0,     0,   341,     0,     0,   355,     0,     0,   348,
       0,     0,   352,   429,     0,   641,   639,   199,   810,   811,
       0,     0,   545,     0,     0,   577,     0,   545,     0,   541,
       0,    14,    16,     0,     0,     0,     0,     0,     0,     0,
     825,     0,   680,     0,     0,     0,     0,     0,     0,   684,
     688,   326,   324,   325,   318,   319,   320,   312,     0,     0,
     308,   301,   287,     0,     0,     0,   243,   290,   293,     0,
     718,   709,   715,     0,     0,   788,   789,   799,   798,   797,
       0,     0,     0,     0,   790,   695,   796,     0,   693,   697,
       0,     0,   702,   706,     0,   727,   722,   725,   721,     0,
       0,   611,     0,   606,   659,   599,   828,   827,   826,   607,
     775,     0,     0,   773,   780,   781,   777,     0,   772,     0,
     770,     0,     0,     0,     0,     0,     0,   587,   267,     0,
     276,     0,     0,   272,     0,   275,     0,     0,     0,    68,
     286,   593,     0,     0,   338,   342,   336,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   589,
       0,     0,   545,     0,   572,     0,   545,   595,   664,   665,
     669,   670,     0,   817,   676,   824,   678,     0,     0,     0,
       0,   685,   321,   302,     0,   288,   296,   297,   291,   242,
     713,   800,     0,     0,   792,     0,   738,   737,   736,   735,
     734,   699,     0,   791,     0,   656,     0,     0,   784,   783,
     782,     0,   776,   769,   767,     0,   764,   765,   759,   152,
     154,   156,     0,     0,     0,     0,     0,   271,   269,     0,
     277,   208,   357,    74,   333,   339,     0,   353,   349,   356,
       0,     0,     0,   343,     0,     0,   345,     0,   555,   549,
     544,     0,   545,   535,     0,   814,     0,     0,     0,     0,
     305,   303,     0,   794,   793,     0,     0,   657,   612,     0,
     778,   771,     0,     0,   158,   157,     0,     0,     0,     0,
     153,   273,     0,     0,     0,     0,     0,   563,   557,     0,
     556,   558,   564,   561,   551,     0,   550,   552,   562,   537,
       0,   538,     0,     0,   686,   304,     0,   795,   707,   658,
     766,   155,   159,     0,     0,     0,     0,     0,     0,   346,
     344,     0,     0,   548,   559,   560,   547,   553,   554,   539,
       0,   295,   160,     0,     0,     0,   354,   350,     0,     0,
       0,     0,     0,     0,     0,     0,   162,     0,     0,   161,
       0,     0,     0,     0,     0,     0,     0,     0,   163
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  jsoniq_parser::yypgoto_[] =
  {
     -1562, -1562,  -195,  -192, -1562,  1294,  1295, -1562,  1302,  -559,
   -1562, -1562, -1562, -1562, -1562, -1562, -1562, -1562, -1562, -1562,
   -1029, -1562, -1562, -1562, -1562,  -222,  -589, -1562,   792,   -89,
   -1562, -1562, -1562, -1562, -1562,   318,   554, -1562, -1562,   -12,
    -181,  1123, -1562,  1118, -1562, -1562,  -681, -1562,   498, -1562,
     284, -1562,  -203,  -249, -1562,  -563, -1562,     4,    10,    33,
    -276,  -186, -1562,  -921, -1562, -1562,   236, -1562, -1562, -1562,
   -1562, -1562, -1562, -1562, -1562, -1562, -1562,   679, -1562,    77,
    1505,     0, -1562, -1562, -1562, -1562,   403, -1562, -1562,  -315,
   -1562,    20, -1562, -1562,  -154,  -965,  -736,  -728, -1562, -1562,
     771, -1562, -1562,   -32,   154, -1562, -1562, -1562,   166, -1561,
   -1562,   422,   169, -1562, -1562,   175, -1338, -1562,  1030,   274,
   -1562, -1562,   268, -1076, -1562, -1562,   267, -1562, -1562, -1296,
   -1304, -1562,   263, -1476, -1562, -1562,   916,  -155, -1562, -1562,
    -546,   897, -1562, -1562,  -678,   357,  -668,   399,   400, -1562,
   -1562, -1562,   637, -1562, -1562,  1264, -1562, -1562, -1562, -1562,
   -1562,  -884,  -308,  -714, -1562,  -116, -1562, -1562, -1562, -1562,
   -1562, -1562, -1562,    -7,  -845, -1562,  -138,   728,   286, -1562,
    -405, -1562, -1562,   869, -1562, -1562, -1562, -1562, -1562,   862,
   -1562, -1562, -1562, -1562, -1051, -1562,   249, -1562,   746,  -840,
   -1562, -1562, -1562, -1562, -1562,  -235,  -228, -1263,  -869, -1562,
   -1562, -1562, -1562, -1562, -1562, -1562, -1562, -1562, -1562, -1562,
    -790,  -902,  -174,  -908, -1562, -1562, -1562,  -834, -1562, -1562,
   -1562, -1562, -1562, -1562, -1562, -1562, -1562,  1140,  1142,   -94,
     557,  -677, -1562, -1562, -1562, -1562, -1562, -1562, -1562, -1562,
   -1562, -1562, -1562,   220, -1562, -1562,   214, -1562,   216, -1125,
   -1562, -1562, -1562,   168,   159,   -13,   439, -1562, -1562, -1562,
   -1562, -1562, -1562, -1562, -1562, -1562, -1562, -1562, -1562, -1562,
     171, -1562, -1562, -1562,    -8,   433,   591, -1562, -1562, -1562,
   -1562, -1562,   366, -1562, -1562, -1497, -1562, -1562, -1562,  -540,
   -1562,   130, -1562,   -28, -1562, -1562, -1562, -1562, -1358, -1562,
     181, -1562, -1562, -1562, -1562, -1562,  -109, -1562, -1562, -1562,
   -1562, -1562,  -962,  -424,  1006,   -25, -1562
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  jsoniq_parser::yydefgoto_[] =
  {
        -1,   261,   654,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
    1307,   807,   279,   280,   281,   282,   283,   284,   998,   999,
    1000,   285,   286,   287,  1004,  1005,  1006,   288,   455,   289,
     290,   740,   291,   457,   458,   459,   469,   797,   798,   292,
    1270,   293,  1759,  1760,   294,   295,   296,   562,   297,   298,
     299,   300,   301,   800,   302,   303,   545,   304,   305,   306,
     307,   308,   309,   665,   310,   311,   891,   892,   312,   313,
     314,   575,   316,   666,   677,  1174,  1175,   317,   667,   318,
     669,   576,   320,   321,   792,   793,  1428,   476,   322,   477,
     478,   932,  1429,  1430,  1431,   670,   671,  1168,  1169,  1419,
     672,  1164,  1165,  1412,  1413,  1414,  1415,   323,   820,   821,
     324,  1322,  1323,  1538,   325,  1325,  1326,   326,   327,  1328,
    1329,  1330,  1331,  1545,   328,   329,   330,   331,   332,   939,
     333,   334,  1438,   335,   336,   337,   338,   339,   340,   341,
     342,   343,  1212,   344,   345,   346,   347,   695,   696,   348,
     349,   350,   351,   352,   353,   354,   355,   356,   357,   358,
     359,   360,   361,   362,   363,   364,   365,   732,   725,   366,
     367,   368,   369,   370,   371,   372,   373,   374,   375,   975,
     376,   377,   378,   379,   380,   381,  1359,   854,   855,   856,
    1790,  1835,  1836,  1829,  1830,  1837,  1831,  1360,  1361,   382,
     383,  1362,   384,   385,   386,   387,   388,   389,   390,   391,
    1060,  1546,  1480,  1202,  1642,  1203,  1213,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,   402,   403,   827,
    1283,   404,  1205,  1206,  1207,  1208,   405,   406,   407,   408,
     409,   410,   881,   882,   411,  1396,  1397,  1721,  1149,  1182,
    1448,  1449,  1183,  1184,  1185,  1186,  1187,  1458,  1632,  1633,
    1188,  1461,  1189,  1613,  1190,  1191,  1466,  1467,  1638,  1636,
    1450,  1451,  1452,  1453,  1739,   769,  1025,  1026,  1027,  1028,
    1029,  1030,  1257,  1662,  1756,  1258,  1660,  1754,  1031,  1494,
    1657,  1653,  1654,  1655,  1032,  1033,  1454,  1462,  1623,  1455,
    1619,  1439,   412,   413,   414,   415,   565,   416,   417,   418,
     419,   420,  1209,  1308,   421,   422,   423
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const short int jsoniq_parser::yytable_ninf_ = -897;
  const short int
  jsoniq_parser::yytable_[] =
  {
       315,   623,   456,   960,   668,   315,   315,   315,   315,   428,
     431,   432,  1324,   744,  1112,   429,   429,   429,   433,  1074,
     319,   590,   649,   947,  1549,   319,   319,   319,   319,   604,
     741,   741,  1086,   613,   948,   949,   950,   951,   430,   430,
     430,   434,   719,  1312,   641,  1148,  1100,   625,   804,   808,
    1561,   542,   969,  1434,  1201,  1211,   912,   914,  1058,  1180,
     610,   642,   642,  1358,  1229,   542,  1059,   633,   634,   541,
     985,  1693,   644,  1272,  1697,  1595,  1596,    11,    12,  1054,
     906,   910,   913,   915,   904,   908,  1260,   646,  1288,   542,
    1171,  1261,   783,  1234,   859,  1296,  1569,   441,  1762,   642,
    1262,   542,  1634,   542,  1440,  1314,  1083,  1263,   648,  1264,
     784,   315,  -171,   642,   743,   642,  1293,   642,  1265,   743,
     642,   429,  1204,  1204,   642,   444,   841,    11,    12,  1539,
     642,   319,  1788,   642,   935,   642,   936,   937,  1055,   938,
    1056,   940,   605,   642,   563,  1266,   605,   441,   651,   941,
     942,   642,  1083,  1290,   649,  1491,  1056,   442,   649,   592,
    1301,   642,  1800,   775,  1757,   642,   642,  1204,   653,   653,
    1651,   642,   980,  1398,   642,   444,  1055,  1441,   437,   438,
     445,   439,   440,   642,   718,   642,   907,  1084,   638,   574,
     578,  1056,  1057,   753,   435,  1224,  1440,  1732,  1620,   443,
    1620,  1271,   484,   805,   639,   980,   474,   128,  1297,  1763,
     642,  1225,   446,   447,  1159,  1540,  1493,  1237,  1155,   642,
     653,  1204,  1789,    13,   642,   436,   754,   642,  1204,  1399,
    1085,   652,   642,  1102,  1652,  1141,   783,   720,   642,   475,
    1845,   873,   653,  1513,   842,   475,   803,  -172,   642,  1542,
     653,   806,   981,  1172,   784,  1403,  1722,  1549,   653,   315,
     315,   668,   860,   315,  1442,  1443,   642,  1444,   653,  1441,
    1348,  1300,   653,   653,  1445,   648,  1733,  1267,   653,   319,
     319,   653,  1529,   319,  1446,   982,  1471,   649,   460,   643,
     653,  1764,   653,  1173,  1180,  1180,  1447,  -171,   315,  1358,
    1822,  1569,  1755,   449,    82,   645,  1230,   899,  1358,  1486,
     901,  1612,   912,   914,  1156,  1850,  1272,   653,   319,    93,
    1158,   475,  1512,  1402,  1298,  1471,   653,  1048,   627,   629,
    1294,   653,  1299,   542,   653,  1078,   542,   475,  1011,   653,
     904,   908,   776,   593,   107,   653,  1315,  1858,   852,  1861,
     777,   726,  1066,  1088,   728,   653,  1442,  1443,  1089,  1444,
    1204,  1145,  1621,  1622,  1621,   475,   450,  1142,   850,  1197,
    1268,  1269,  1344,   653,   874,   650,  1446,   894,   895,   785,
    1422,   544,   489,  1071,   842,  1118,   925,  1014,  1447,  1015,
     642,  1521,   452,  1176,    11,    12,   642,  1345,  1122,  1204,
     453,  1524,   642,  1539,  1049,  1539,  1346,   451,   454,   842,
     795,  1482,  1217,   158,   159,   160,   751,   542,   642,  1796,
     542,   905,   909,  1814,   542,  1797,   642,   542,   542,   642,
     315,   464,  -172,  1016,   315,   542,   759,   642,   760,   642,
     898,   542,   542,  1119,  1271,   900,   902,   841,  1051,   542,
     319,   642,  1720,  1798,   319,   917,   542,   542,   542,   542,
     490,   315,   614,   315,   542,   868,   673,   615,  1126,  1204,
     893,   780,   542,   782,   876,  1694,  1615,  1852,  1827,   796,
     647,   319,  1351,   319,  1050,   315,   843,  1502,   749,  1683,
     315,  1688,  1436,  1204,   434,   823,   434,   653,   762,   872,
     829,   773,  1843,   653,   750,   319,   774,   650,  1399,   653,
     319,   650,   699,  1358,  1131,   128,  1616,  1827,   434,   542,
     475,  1351,   930,   434,   934,   653,  1123,  1124,  1052,   700,
     674,   491,   492,   653,   542,   675,   653,  1063,  1181,  1549,
     463,  1125,   788,  1695,   653,   542,   653,   801,   468,  1095,
    1148,   616,  1180,  1514,  1590,  1487,  1351,   814,   653,  1499,
     763,  1180,  1130,   315,   825,   826,  1641,   912,   914,   912,
    1522,   315,  1180,   832,  1094,  1223,  1833,   470,   605,   479,
    1115,   429,   676,   319,  1238,  1239,  1116,   605,  1017,  1242,
    1097,   319,   542,  1404,  1405,  1406,  1127,  1128,  1354,   542,
    1355,  1018,  1117,  1019,   430,   963,   964,   467,  1828,  -261,
    1147,  1129,   649,  1216,  1020,  1021,  1022,  1064,  1023,  1280,
    1024,  1610,   315,  1844,  1113,   482,   456,  1599,  1356,  1096,
    1055,  1220,   315,  1254,  1204,  1848,   699,  1354,  1220,  1355,
     650,  1160,   319,   315,   315,   315,   315,  1864,   483,  1773,
    1255,   542,   319,   700,  1349,   888,  1787,   857,   858,  1351,
    1055,  1120,   315,   319,   319,   319,   319,  1356,   862,  1055,
    1098,   706,  1354,  -261,  1355,    11,    12,  1153,  -261,  1833,
     707,  1409,   319,  1834,  1421,   437,   438,  1056,   439,   440,
    1114,   759,  1746,   760,  1256,   441,  1751,   729,   887,   889,
     729,    13,  1356,   877,   542,   442,   443,  1477,   656,  1073,
    1157,  1221,   657,  1204,   902,   702,  1204,   658,  1222,  1121,
    1350,  1542,  1701,   444,  1695,  -261,   761,  1705,   445,   729,
     987,   699,   730,   542,   731,   730,   659,   731,  1478,  1671,
     656,  1139,  1055,  1409,   657,   703,  1180,   542,   700,   658,
    1736,   542,   542,   762,   721,   722,  1479,  1737,   704,  1055,
     446,   447,   448,   487,   730,  1411,   731,  1738,   659,  1627,
     542,   701,  1747,  1181,  1181,  1354,  1752,  1355,   542,  1351,
    1352,   542,    82,  1672,   488,   542,  1867,  1491,  1690,  1779,
    1666,  1099,   705,  1424,   699,   962,  1424,    93,  1425,   315,
     965,  1425,   745,  1065,  1492,  1356,   734,   965,  1598,   429,
     449,   700,  1691,   912,   559,   763,   746,   735,  1383,   319,
    1426,  1581,   107,   624,   471,  -262,  1177,   907,   542,  1178,
     315,   315,   430,   472,  1805,   660,  1056,   493,   661,  1056,
    1092,  1093,  1807,   656,  1808,  1463,  1464,   657,  1493,   128,
     319,   319,   658,   662,   605,  1135,  1001,  1204,    13,  1154,
     473,  1427,  1791,   434,   434,   542,  1794,   660,  1465,  1392,
     661,   659,   719,   450,  1353,   639,   708,  1351,  1352,   663,
    1781,   729,  1527,   916,   747,   851,  1226,   918,   315,  -262,
     709,   158,   159,   160,  -262,  1354,   542,  1355,   748,   456,
    1002,   729,  1227,  1785,  1691,  1003,   542,  1849,   319,  1231,
    1204,   663,  1204,  1254,   451,   494,   730,   315,   731,  1832,
    1838,  1231,  1107,  1108,  1109,  1356,   889,  1691,   664,   114,
    1255,   542,   542,   542,   542,  1179,   730,   319,   731,    82,
     452,  -262,  1204,  1734,  1735,   126,  1731,   495,   453,  1761,
    1857,   917,  1840,  1878,    93,  1282,   454,  1285,   902,  1002,
     664,  1832,  1617,  1400,  1003,  1146,  1357,  1838,  1879,  1618,
     660,  1815,  1353,   661,  1691,  1204,   542,  1691,   496,   107,
    1736,   497,   543,  1177,   153,  1591,  1178,  1737,  1587,  1204,
     542,  1204,  1691,  1354,  1600,  1355,  1228,  1738,  1351,  1352,
    1408,  1336,  1384,  1337,  1485,  1248,   128,   546,  1274,  1321,
     966,  1409,   799,   966,   663,   542,  1249,  1275,   966,  1321,
     799,  1410,  1536,  1356,   542,  1547,   542,   114,   542,  1525,
     542,  1181,  1541,  1411,  1351,  1352,  1424,   542,  1548,   547,
    1181,  1425,  1250,   126,  1219,  1550,  1547,  1547,   158,   159,
     160,  1181,  1761,  1251,  1803,  1804,   945,   946,  1551,  1700,
    1870,  1240,  1241,   664,  1563,  1243,  1244,  1245,  1592,  1593,
     542,  1246,   542,   560,   461,   465,   561,   462,   466,   668,
     480,   485,   153,   481,   486,   724,   582,  1366,   727,  1367,
     315,   580,  1371,  1353,  1372,   581,   558,  1497,  1498,  1761,
    1332,   765,   766,   767,  1679,   952,   953,   587,   954,   955,
     319,  1748,  1749,   591,  1354,   605,  1355,   566,   588,   589,
     579,   594,  -627,   434,   595,   618,   617,  1847,   619,  1353,
     621,   620,   583,   622,   586,   635,   678,   679,   655,   697,
     698,   542,   710,   456,  1356,  1393,   713,   712,   114,   711,
    1354,   717,  1355,   723,   733,   736,   315,   315,   315,   737,
     738,   739,   743,   755,   126,  1394,   757,   758,   768,   542,
     772,  1889,   781,  1890,   799,   566,   319,   319,   319,   802,
    1356,   810,   811,  1898,   114,  1568,   988,   989,   990,   991,
     992,   993,   994,   995,   996,   997,   812,   813,   824,   462,
     126,   680,   830,   153,   831,   623,   839,   837,   542,   681,
     682,   466,   683,   481,   486,   497,   841,   844,   845,   846,
     684,  1703,   847,   849,   685,  1181,   686,   853,   861,   863,
     864,   687,   865,   461,   465,   480,   485,   496,   879,   153,
     880,   884,   885,   890,   903,   921,   897,   688,   923,   928,
     929,   943,   922,   931,  1433,   924,   956,   957,   958,   959,
     976,   977,   542,   983,  1685,   984,   542,   986,  1008,  1009,
    1012,   689,   690,   691,   692,   693,   694,  1013,   542,  1034,
    1035,   315,  1038,  1036,  1040,  1506,  1043,  1044,  1045,  1046,
    1053,   429,   542,  1062,  1068,  1069,  1047,  1079,  1072,  1080,
    1081,   319,   542,  1082,  1087,   315,  1090,  1091,  1134,  1140,
    1143,   925,  1137,  1151,   430,  1144,   315,  1155,  1162,  1003,
    1532,  1232,  1055,  1252,  1253,   319,   429,  1273,  1278,  1281,
    1279,  1291,   542,  1289,   795,   315,   319,  1295,  1303,  1554,
    1306,  1304,  1310,  1305,  1311,   429,  1309,  1317,  1316,   430,
    1321,  1335,  1320,  1327,  1333,   319,   315,  1334,  1339,  1340,
     542,  1342,  1343,   315,  1347,  1363,  1566,  1364,   430,  1365,
     542,  1378,  1385,  1570,   542,  1395,   319,   761,  1416,  1418,
    1423,  1420,  1457,   319,  1468,  1460,  1437,  1469,  1472,   434,
    1456,    13,  1473,  1474,  1475,  1489,   434,  1481,  1393,  1490,
    1771,  1495,   542,  1476,  1509,  1504,  1500,  1505,  1501,  1507,
    1508,  1775,  1685,  1510,  1777,  1517,  1519,  1523,  1394,  1511,
    1528,  1531,  1786,  1560,  1547,  1553,  1562,  1565,  1573,  1574,
    1555,   888,  1556,  1575,  1584,  1577,  1579,  1571,  1585,  1572,
    1586,  1578,  1583,   542,  1398,  1576,  1604,  1409,   752,  1603,
    1605,   756,  1609,  1611,  1614,   764,  1630,  1631,   770,   771,
    1624,  1637,  1635,  1643,  1650,  1656,   779,  1644,  1661,  1645,
    1663,  1646,   791,   794,  1647,   542,  1648,  1669,  1649,  1665,
     809,  1667,  1674,  1676,  1677,  1659,  1678,   817,   818,   819,
     822,  1681,  1682,  1699,  1724,   828,  1687,  1698,  1704,  1707,
    1712,  1730,  1742,   835,  1743,  1744,  1745,  1753,  1254,  1777,
    1758,  1769,  1765,  1766,  1776,  1793,  1802,  1809,  1810,   542,
    1812,  1813,   542,  1817,  1811,   542,  1823,  1825,  1818,  1842,
    1824,  1856,  1839,  1841,  1846,  1855,  1862,  1863,   542,  1869,
     315,  1866,  1853,   542,  1875,  1880,  1888,  1895,  1859,  1894,
     836,  1891,  1488,  1010,  1881,  1892,  1235,   636,   637,   742,
     319,  1302,  1503,  1820,  1851,   822,  1525,  1873,   640,  1882,
    1150,  1885,  1887,  1897,   778,  1728,   848,   566,  1432,   542,
     542,  1876,  1608,  1077,  1407,  1597,  1601,  1393,  1594,   838,
    1537,  1533,  1543,  1552,   933,   944,  1215,   979,   968,  1564,
    1111,  1868,  1865,  1876,   786,  1582,   787,  1394,  1286,   716,
    1589,  1588,  1859,  1625,   566,  1629,   564,  1741,  1435,  1740,
    1628,  1459,  1496,   883,  1658,  1259,  1750,  1626,     0,     0,
     794,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1717,  1718,  1719,     0,     0,   542,   542,     0,   542,
       0,   542,     0,     0,   609,     0,  1393,     0,   542,     0,
       0,     0,   794,     0,     0,     0,     0,  1393,  1393,     0,
     315,     0,     0,     0,     0,     0,  1394,     0,  1393,     0,
       0,     0,     0,     0,     0,     0,     0,  1394,  1394,     0,
     319,     0,     0,     0,     0,     0,     0,     0,  1394,   542,
       0,   542,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   970,     0,   542,     0,     0,
     542,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   542,     0,     0,     0,     0,     0,     0,     0,   631,
       0,     0,   542,     0,  1007,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1037,     0,
       0,     0,  1041,  1042,   542,  1393,     0,     0,     0,     0,
       0,     0,   542,     0,     0,     0,     0,  1799,   542,     0,
     542,  1061,     0,     0,     0,  1394,     0,     0,     0,  1067,
       0,     0,  1070,     0,     0,     0,  1075,     0,     0,  1806,
       0,   542,     0,     0,   315,     0,     0,     0,     0,     0,
     542,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1393,     0,   319,     0,     0,     0,  1105,     0,
     542,     0,     0,     0,     0,   542,     0,   315,     0,  1110,
       0,     0,  1394,     0,     0,     0,     0,   542,     0,     0,
     542,     0,     0,     0,     0,     0,     0,   319,     0,  1393,
       0,     0,     0,     0,     0,     0,     0,     0,  1393,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1394,
       0,     0,     0,     0,     0,     0,     0,     0,  1394,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1161,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1170,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1210,  1210,  1214,  1214,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1210,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1247,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1277,     0,     0,     0,
       0,     0,     0,     0,     0,  1284,     0,  1284,     0,   794,
       0,  1210,     0,     0,     0,     0,     0,     0,  1210,     0,
       0,     0,     0,     0,     0,     0,   564,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   828,     0,   828,     0,     0,   866,   867,     0,     0,
       0,   869,   870,   871,     0,     0,   875,     0,     0,   878,
       0,     0,     0,     0,     0,   886,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   896,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   919,   920,
       0,     0,     0,     0,     0,     0,     0,   926,   927,     0,
       0,     0,  1417,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1210,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   974,     0,     0,  1210,
     974,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1039,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   794,     0,     0,     0,  1515,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1210,
       0,     0,     0,     0,     0,     0,  1076,     0,     0,     0,
       0,     0,     0,   822,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1210,     0,     0,     0,     0,     0,     0,
       0,     0,  1101,     0,     0,     0,  1103,  1104,     0,  1106,
       0,     0,     0,     0,     0,     0,   926,     0,     0,     0,
       0,     0,     0,  1567,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1132,  1133,
       0,     0,  1136,     0,     0,     0,     0,     0,     0,     0,
       0,   883,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1152,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   920,     0,     0,     0,     0,     0,  1163,  1167,
       0,     0,     0,  1607,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1210,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1664,     0,  1236,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1276,     0,     0,     0,     0,     0,     0,
    1689,     0,     0,  1210,     0,     0,  1210,     0,     0,     0,
       0,     0,  1292,     0,     0,     0,     0,     0,     0,  1702,
       0,     0,     0,     0,  1706,     0,     0,     0,  1313,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1318,
    1319,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1338,     0,     0,  1341,     0,     0,
    1726,  1727,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1368,  1369,
    1370,     0,  1373,  1374,  1375,  1376,  1377,     0,     0,  1379,
    1380,     0,  1381,  1382,     0,     0,     0,  1386,  1387,     0,
       0,     0,     0,     0,     0,     0,  1401,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1163,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1210,  1780,     0,
    1782,     0,  1784,     0,     0,     0,     0,     0,     0,  1792,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1484,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1210,     0,  1210,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1816,     0,
       0,  1819,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1210,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1826,     0,     0,     0,     0,  1516,     0,
    1518,     0,  1520,     0,     0,     0,     0,     0,     0,     0,
    1526,     0,     0,     0,     0,  1210,     0,     0,     0,  1530,
       0,     0,     0,  1854,     0,  1534,  1535,     0,     0,  1210,
       0,  1210,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1557,     0,     0,  1558,  1559,     0,
       0,     0,  1871,     0,     0,     0,     0,     0,     0,     0,
       0,  1874,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1883,     0,     0,     0,     0,  1884,     0,  1580,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1893,     0,
       0,  1896,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1163,     0,     0,     0,  1167,  1602,     0,     0,     0,
       0,  1606,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1668,     0,
       0,     0,  1670,     0,     0,     0,  1673,     0,  1675,     0,
       0,     0,     0,     0,     0,     0,  1680,     0,     0,     0,
       0,     0,     0,     0,  1684,  1686,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1526,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1708,  1709,
    1710,  1711,     0,  1713,  1714,     0,  1715,     0,  1716,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1723,     0,     0,     0,     0,  1725,     0,
       0,     0,     0,     0,  1729,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1767,     0,  1768,     0,     0,  1770,
       0,     0,  1772,     0,     0,     0,     0,  1774,  1686,     0,
       0,     0,     0,     0,     0,  1778,     0,     0,     0,     0,
    1783,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1795,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1801,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1821,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1778,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1860,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  -167,   907,     0,     0,     0,     0,  1872,     0,
       0,     0,  1877,     1,     2,     0,     0,  1860,     3,     0,
       0,     0,     4,     5,     6,     7,     8,     9,    10,    11,
      12,     0,    13,  1877,     0,    14,   425,  1886,    16,    17,
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
       0,   133,   134,   135,   136,   137,     0,   138,     0,   139,
       0,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,     0,     0,   151,   152,   153,     0,   427,     0,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,     0,   201,   202,   203,     0,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,     0,   252,
       0,   253,   254,   255,     0,   256,   257,   258,  -167,   907,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     1,
       2,     0,     0,     0,     3,     0,     0,     0,     4,     5,
       6,     7,     8,     9,    10,    11,    12,     0,    13,     0,
       0,   911,   425,     0,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,   426,    30,    31,
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
     136,   137,     0,   138,     0,   139,     0,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,     0,     0,
     151,   152,   153,     0,   427,     0,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,     0,   201,   202,   203,     0,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   907,   252,     0,   253,   254,   255,
       0,   256,   257,   258,     1,     2,     0,     0,     0,     3,
       0,     0,     0,     4,     5,     6,     7,     8,     9,    10,
      11,    12,     0,    13,     0,     0,   424,   425,     0,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,   426,    30,    31,    32,    33,    34,     0,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,     0,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,     0,    72,    73,
      74,    75,    76,     0,    77,    78,    79,     0,     0,    80,
      81,     0,     0,     0,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,     0,    92,     0,     0,     0,    93,
       0,    94,    95,    96,    97,     0,    98,     0,     0,     0,
      99,   100,   101,   102,   103,     0,     0,     0,     0,     0,
       0,   104,   105,   106,   107,   108,   109,   110,   111,   112,
       0,   113,   114,   115,   116,   117,     0,     0,     0,   118,
     119,   120,   121,   122,   123,   124,   125,     0,   126,     0,
     127,   128,     0,     0,   129,   130,   131,     0,     0,     0,
     132,     0,   133,   134,   135,   136,   137,     0,   138,     0,
     139,     0,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,     0,     0,   151,   152,   153,     0,   427,
       0,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,     0,   201,   202,   203,
       0,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   907,
     252,     0,   253,   254,   255,     0,   256,   257,   258,     1,
       2,     0,     0,     0,     3,     0,     0,     0,     4,     5,
       6,     7,     8,     9,    10,     0,     0,     0,    13,     0,
       0,   424,   425,     0,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,   567,   426,    30,    31,
      32,    33,    34,     0,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,     0,    48,    49,
      50,   568,   569,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,     0,    72,    73,    74,    75,    76,     0,    77,
      78,    79,     0,     0,    80,    81,     0,     0,     0,    82,
      83,   515,    85,    86,    87,    88,    89,   570,    91,     0,
      92,     0,     0,     0,    93,     0,    94,    95,    96,    97,
       0,    98,     0,     0,     0,    99,   100,   101,   102,   103,
       0,     0,     0,     0,     0,     0,   104,   105,   106,   107,
     108,   109,   110,   571,   112,     0,   113,   114,   115,   116,
     117,     0,     0,     0,   118,   119,   120,   121,   122,   123,
     124,   125,     0,   126,     0,   127,   128,     0,     0,   129,
     130,   131,     0,     0,     0,   132,     0,   133,   134,     0,
     136,   137,     0,   138,     0,   139,     0,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,     0,     0,
     151,   152,   153,     0,   427,     0,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   533,   534,   535,   184,   185,   536,   573,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,     0,   201,   202,   203,     0,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,     0,   252,     0,   253,   254,   255,
       0,   256,   257,   258,  -895,   467,     0,  -261,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  -895,     0,     0,     0,
    -895,     0,     0,     0,  -895,  -895,     0,     0,     0,     0,
    -895,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  -261,     0,     0,  -895,     0,  -261,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  -895,     0,  -895,
    -895,  -895,     0,     0,  -895,  -895,  -895,  -895,     0,     0,
       0,  -895,  -895,     0,     0,     0,     0,     0,  -895,     0,
       0,  -895,  -895,  -261,     0,     0,     0,  -895,     0,     0,
       0,     0,  -895,  -895,     0,     0,     0,     0,  -895,     0,
       0,     0,  -895,     0,     0,     0,  -895,  -895,     0,  -895,
       0,  -895,  -895,     0,     0,     0,  -895,  -895,     0,     0,
    -895,  -895,  -895,  -895,  -895,  -895,     0,     0,  -895,     0,
       0,     0,  -895,  -895,     0,     0,  -895,     0,     0,     0,
       0,  -895,     0,     0,  -895,     0,     0,     0,     0,  -895,
    -895,  -895,  -895,  -895,     0,  -895,  -895,  -895,  -895,  -895,
       0,     0,     0,     0,  -895,  -895,  -895,     0,  -895,  -895,
    -895,  -895,  -895,  -895,     0,  -895,     0,  -895,     0,     0,
       0,     0,     0,  -895,     0,     0,     0,  -895,  -895,     0,
    -896,   624,     0,  -262,     0,     0,     0,     0,     0,     0,
       0,     0,  -895,     0,  -895,     0,  -895,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  -895,     0,
       0,     0,     0,  -895,     0,     0,  -895,     0,     0,     0,
       0,     0,  -896,     0,     0,     0,  -896,     0,     0,     0,
    -896,  -896,     0,     0,     0,     0,  -896,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  -262,     0,     0,
    -896,     0,  -262,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    -895,     0,  -895,  -896,     0,  -896,  -896,  -896,     0,     0,
    -896,  -896,  -896,  -896,     0,     0,     0,  -896,  -896,     0,
       0,     0,     0,     0,  -896,     0,     0,  -896,  -896,  -262,
       0,     0,     0,  -896,     0,     0,     0,     0,  -896,  -896,
       0,     0,     0,     0,  -896,     0,     0,     0,  -896,     0,
       0,     0,  -896,  -896,     0,  -896,     0,  -896,  -896,     0,
       0,     0,  -896,  -896,     0,     0,  -896,  -896,  -896,  -896,
    -896,  -896,     0,     0,  -896,     0,     0,     0,  -896,  -896,
       0,     0,  -896,     0,     0,     0,     0,  -896,     0,     0,
    -896,     0,     0,     0,     0,  -896,  -896,  -896,  -896,  -896,
       0,  -896,  -896,  -896,  -896,  -896,     0,     0,     0,     0,
    -896,  -896,  -896,     0,  -896,  -896,  -896,  -896,  -896,  -896,
       0,  -896,     0,  -896,     0,     0,     0,     0,     0,  -896,
       0,     0,     0,  -896,  -896,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  -896,     0,
    -896,     0,  -896,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  -896,     0,     0,     0,     0,  -896,
       0,     0,  -896,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     1,     2,
       0,     0,     0,     3,     0,     0,     0,     4,     5,     6,
       7,     8,     9,    10,    11,    12,  -896,    13,  -896,     0,
      14,    15,     0,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,     0,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,     0,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,     0,    72,    73,    74,    75,    76,     0,    77,    78,
      79,     0,     0,    80,    81,     0,     0,     0,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,     0,    92,
       0,     0,     0,    93,     0,    94,    95,    96,    97,     0,
      98,     0,     0,     0,    99,   100,   101,   102,   103,     0,
       0,     0,     0,     0,     0,   104,   105,   106,   107,   108,
     109,   110,   111,   112,     0,   113,   114,   115,   116,   117,
       0,     0,     0,   118,   119,   120,   121,   122,   123,   124,
     125,     0,   126,     0,   127,   128,     0,     0,   129,   130,
     131,     0,     0,     0,   132,     0,   133,   134,   135,   136,
     137,     0,   138,     0,   139,     0,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,     0,     0,   151,
     152,   153,     0,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
       0,   201,   202,   203,     0,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,     0,   252,     0,   253,   254,   255,     0,
     256,   257,   258,   259,   260,     1,     2,     0,     0,     0,
       3,     0,     0,     0,     4,     5,     6,     7,     8,     9,
      10,    11,    12,     0,    13,     0,     0,    14,    15,     0,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,     0,
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
       0,   132,     0,   133,   134,   135,   136,   137,     0,   138,
       0,   139,     0,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,     0,     0,   151,   152,   153,     0,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,     0,   201,   202,
     203,     0,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
       0,   252,     0,   253,   254,   255,     0,   256,   257,   258,
       0,   632,     1,     2,     0,     0,     0,     3,     0,     0,
       0,     4,     5,     6,     7,     8,     9,    10,    11,    12,
       0,    13,     0,     0,    14,    15,     0,    16,    17,    18,
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
     133,   134,   135,   136,   137,     0,   138,     0,   139,     0,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,     0,     0,   151,   152,   153,     0,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,     0,   201,   202,   203,     0,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,     0,   252,     0,
     253,   254,   255,     0,   256,   257,   258,     1,     2,     0,
       0,     0,     3,     0,     0,     0,     4,     5,     6,     7,
       8,     9,    10,    11,    12,     0,    13,     0,     0,   424,
     425,     0,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,   426,    30,    31,    32,    33,
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
       0,   840,     0,   132,     0,   133,   134,   135,   136,   137,
       0,   138,     0,   139,     0,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,     0,     0,   151,   152,
     153,     0,   427,     0,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,     0,
     201,   202,   203,     0,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,     0,   252,     0,   253,   254,   255,     0,   256,
     257,   258,     1,     2,     0,     0,     0,     3,     0,     0,
       0,     4,     5,     6,     7,     8,     9,    10,    11,    12,
       0,    13,     0,     0,   424,   425,     0,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
     426,    30,    31,    32,    33,    34,     0,    35,    36,    37,
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
     133,   134,   135,   136,   137,     0,   138,     0,   139,     0,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,     0,     0,   151,   152,   153,     0,   427,     0,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,     0,   201,   202,   203,     0,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,     0,   252,     0,
     253,   254,   255,     0,   256,   257,   258,     1,     2,     0,
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
       0,   138,     0,   139,     0,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,     0,     0,   151,   152,
     153,     0,   427,     0,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,     0,
     201,   202,   203,     0,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,     0,   252,     0,   253,   254,   255,     0,   256,
     257,   258,     1,     2,     0,     0,     0,     3,     0,     0,
       0,     4,     5,     6,     7,     8,     9,    10,    11,    12,
       0,    13,     0,     0,    14,   425,     0,    16,    17,    18,
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
     133,   134,   135,   136,   137,     0,   138,     0,   139,     0,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,     0,     0,   151,   152,   153,     0,   427,     0,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,     0,   201,   202,   203,     0,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,     0,   252,     0,
     253,   254,   255,     0,   256,   257,   258,     1,     2,     0,
       0,     0,     3,     0,     0,     0,     4,     5,     6,     7,
       8,     9,    10,    11,    12,     0,    13,     0,     0,   911,
     425,     0,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,   426,    30,    31,    32,    33,
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
       0,   138,     0,   139,     0,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,     0,     0,   151,   152,
     153,     0,   427,     0,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,     0,
     201,   202,   203,     0,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,     0,   252,     0,   253,   254,   255,     0,   256,
     257,   258,     1,     2,     0,     0,     0,     3,     0,     0,
       0,     4,     5,     6,     7,     8,     9,    10,    11,    12,
       0,    13,     0,     0,   424,   425,     0,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,  1388,
     426,    30,    31,    32,    33,    34,     0,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
       0,    48,    49,    50,  1389,  1390,    53,    54,    55,    56,
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
     133,   134,   135,   136,   137,     0,   138,     0,   139,     0,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,     0,     0,   151,   152,   153,     0,   427,     0,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
    1391,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,     0,   201,   202,   203,     0,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,     0,   252,     0,
     253,   254,   255,     0,   256,   257,   258,     1,     2,     0,
       0,     0,     3,     0,     0,     0,     4,     5,     6,     7,
       8,     9,    10,     0,     0,     0,    13,     0,     0,   424,
     425,     0,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,   567,   426,    30,    31,    32,    33,
      34,     0,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,     0,    48,    49,    50,   568,
     569,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
       0,    72,    73,    74,    75,    76,     0,    77,    78,    79,
       0,     0,    80,    81,     0,     0,     0,    82,    83,   515,
      85,    86,    87,    88,    89,   570,    91,     0,    92,     0,
       0,     0,    93,     0,    94,    95,    96,    97,     0,    98,
       0,     0,     0,    99,   100,   101,   102,   103,     0,     0,
       0,     0,   972,     0,   104,   105,   106,   107,   108,   109,
     110,   571,   112,     0,   113,   114,   115,   116,   117,     0,
       0,     0,   118,   119,   120,   121,   122,   123,   124,   125,
       0,   126,     0,   127,   128,     0,     0,   129,   130,   131,
       0,     0,     0,   132,   973,   133,   134,     0,   136,   137,
       0,   138,     0,   139,     0,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,     0,     0,   151,   152,
     153,     0,   427,     0,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   533,
     534,   535,   184,   185,   536,   573,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,     0,
     201,   202,   203,     0,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,     0,   252,     0,   253,   254,   255,     0,   256,
     257,   258,     1,     2,     0,     0,     0,     3,     0,     0,
       0,     4,     5,     6,     7,     8,     9,    10,     0,     0,
       0,    13,     0,     0,   424,   425,     0,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,   567,
     426,    30,    31,    32,    33,    34,     0,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
       0,    48,    49,    50,   568,   569,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,     0,    72,    73,    74,    75,
      76,     0,    77,    78,    79,     0,     0,    80,    81,     0,
       0,     0,    82,    83,   515,    85,    86,    87,    88,    89,
     570,    91,     0,    92,     0,     0,     0,    93,     0,    94,
      95,    96,    97,     0,    98,     0,     0,     0,    99,   100,
     101,   102,   103,     0,     0,     0,     0,   972,     0,   104,
     105,   106,   107,   108,   109,   110,   571,   112,     0,   113,
     114,   115,   116,   117,     0,     0,     0,   118,   119,   120,
     121,   122,   123,   124,   125,     0,   126,     0,   127,   128,
       0,     0,   129,   130,   131,     0,     0,     0,   132,   978,
     133,   134,     0,   136,   137,     0,   138,     0,   139,     0,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,     0,     0,   151,   152,   153,     0,   427,     0,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   533,   534,   535,   184,   185,   536,
     573,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,     0,   201,   202,   203,     0,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,     0,   252,     0,
     253,   254,   255,     0,   256,   257,   258,     1,     2,     0,
       0,     0,     3,     0,     0,     0,     4,     5,     6,     7,
       8,     9,    10,     0,     0,     0,    13,     0,     0,   424,
     425,     0,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,   567,   426,    30,    31,    32,    33,
      34,     0,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,     0,    48,    49,    50,   568,
     569,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
       0,    72,    73,    74,    75,    76,     0,    77,    78,    79,
       0,     0,    80,    81,     0,     0,     0,    82,    83,   515,
      85,    86,    87,    88,    89,   570,    91,     0,    92,     0,
       0,     0,    93,     0,    94,    95,    96,    97,     0,    98,
       0,     0,     0,    99,   100,   101,   102,   103,     0,     0,
       0,     0,     0,     0,   104,   105,   106,   107,   108,   109,
     110,   571,   112,     0,   113,   114,   115,   116,   117,     0,
       0,     0,   118,   119,   120,   121,   122,   123,   124,   125,
       0,   126,     0,   127,   128,     0,     0,   129,   130,   131,
       0,     0,   572,   132,     0,   133,   134,     0,   136,   137,
       0,   138,     0,   139,     0,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,     0,     0,   151,   152,
     153,     0,   427,     0,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   533,
     534,   535,   184,   185,   536,   573,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,     0,
     201,   202,   203,     0,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,     0,   252,     0,   253,   254,   255,     0,   256,
     257,   258,     1,     2,     0,     0,     0,     3,     0,     0,
       0,     4,     5,     6,     7,     8,     9,    10,     0,     0,
       0,    13,     0,     0,   424,   425,     0,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,   567,
     426,    30,    31,    32,    33,    34,     0,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
       0,    48,    49,    50,   568,   569,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,     0,    72,    73,    74,    75,
      76,     0,    77,    78,    79,     0,     0,    80,    81,     0,
       0,     0,    82,    83,   515,    85,    86,    87,    88,    89,
     570,    91,     0,    92,     0,     0,     0,    93,     0,    94,
      95,    96,    97,     0,    98,     0,     0,     0,    99,   100,
     101,   102,   103,     0,     0,     0,     0,     0,     0,   104,
     105,   106,   107,   108,   109,   110,   571,   112,     0,   113,
     114,   115,   116,   117,     0,     0,     0,   118,   119,   120,
     121,   122,   123,   124,   125,     0,   126,     0,   127,   128,
       0,     0,   129,   130,   131,     0,     0,     0,   132,   577,
     133,   134,     0,   136,   137,     0,   138,     0,   139,     0,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,     0,     0,   151,   152,   153,     0,   427,     0,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   533,   534,   535,   184,   185,   536,
     573,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,     0,   201,   202,   203,     0,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,     0,   252,     0,
     253,   254,   255,     0,   256,   257,   258,     1,     2,     0,
       0,     0,     3,     0,     0,     0,     4,     5,     6,     7,
       8,     9,    10,     0,     0,     0,    13,     0,     0,   424,
     425,     0,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,   567,   426,    30,    31,    32,    33,
      34,     0,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,     0,    48,    49,    50,   568,
     569,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
       0,    72,    73,    74,    75,    76,     0,    77,    78,    79,
       0,     0,    80,    81,     0,     0,     0,    82,    83,   515,
      85,    86,    87,    88,    89,   570,    91,     0,    92,     0,
       0,     0,    93,     0,    94,    95,    96,    97,     0,    98,
       0,     0,     0,    99,   100,   101,   102,   103,     0,     0,
       0,     0,     0,     0,   104,   105,   106,   107,   108,   109,
     110,   571,   112,     0,   113,   114,   115,   116,   117,     0,
       0,     0,   118,   119,   120,   121,   122,   123,   124,   125,
       0,   126,     0,   127,   128,     0,     0,   129,   130,   131,
       0,     0,     0,   132,     0,   133,   134,     0,   136,   137,
       0,   138,     0,   139,     0,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,     0,     0,   151,   152,
     153,     0,   427,     0,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   533,
     534,   535,   184,   185,   536,   573,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,     0,
     201,   202,   203,     0,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   626,   252,     0,   253,   254,   255,     0,   256,
     257,   258,     1,     2,     0,     0,     0,     3,     0,     0,
       0,     4,     5,     6,     7,     8,     9,    10,     0,     0,
       0,    13,     0,     0,   424,   425,     0,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,   567,
     426,    30,    31,    32,    33,    34,     0,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
       0,    48,    49,    50,   568,   569,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,     0,    72,    73,    74,    75,
      76,     0,    77,    78,    79,     0,     0,    80,    81,     0,
       0,     0,    82,    83,   515,    85,    86,    87,    88,    89,
     570,    91,     0,    92,     0,     0,     0,    93,     0,    94,
      95,    96,    97,     0,    98,     0,     0,     0,    99,   100,
     101,   102,   103,     0,     0,     0,     0,     0,     0,   104,
     105,   106,   107,   108,   109,   110,   571,   112,     0,   113,
     114,   115,   116,   117,     0,     0,     0,   118,   119,   120,
     121,   122,   123,   124,   125,     0,   126,     0,   127,   128,
       0,     0,   129,   130,   131,     0,     0,     0,   132,     0,
     133,   134,     0,   136,   137,     0,   138,     0,   139,     0,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,     0,     0,   151,   152,   153,     0,   427,     0,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   533,   534,   535,   184,   185,   536,
     573,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,     0,   201,   202,   203,     0,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,     0,   252,   628,
     253,   254,   255,     0,   256,   257,   258,     1,     2,     0,
       0,     0,     3,     0,     0,     0,     4,     5,     6,     7,
       8,     9,    10,     0,     0,     0,    13,     0,     0,   424,
     425,     0,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,   567,   426,    30,    31,    32,    33,
      34,     0,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,     0,    48,    49,    50,   568,
     569,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
       0,    72,    73,    74,    75,    76,     0,    77,    78,    79,
       0,     0,    80,    81,     0,     0,     0,    82,    83,   515,
      85,    86,    87,    88,    89,   570,    91,     0,    92,     0,
       0,     0,    93,     0,    94,    95,    96,    97,     0,    98,
       0,     0,     0,    99,   100,   101,   102,   103,     0,     0,
       0,     0,     0,     0,   104,   105,   106,   107,   108,   109,
     110,   571,   112,     0,   113,   114,   115,   116,   117,     0,
       0,     0,   118,   119,   120,   121,   122,   123,   124,   125,
       0,   126,     0,   127,   128,     0,     0,   129,   130,   131,
       0,   961,     0,   132,     0,   133,   134,     0,   136,   137,
       0,   138,     0,   139,     0,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,     0,     0,   151,   152,
     153,     0,   427,     0,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   533,
     534,   535,   184,   185,   536,   573,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,     0,
     201,   202,   203,     0,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,     0,   252,     0,   253,   254,   255,     0,   256,
     257,   258,     1,     2,     0,     0,     0,     3,     0,     0,
       0,     4,     5,     6,     7,     8,     9,    10,     0,     0,
       0,    13,     0,     0,   424,   425,     0,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,   567,
     426,    30,    31,    32,    33,    34,     0,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
       0,    48,    49,    50,   568,   569,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,     0,    72,    73,    74,    75,
      76,     0,    77,    78,    79,     0,     0,    80,    81,     0,
       0,     0,    82,    83,   515,    85,    86,    87,    88,    89,
     570,    91,     0,    92,     0,     0,     0,    93,     0,    94,
      95,    96,    97,     0,    98,     0,     0,     0,    99,   100,
     101,   102,   103,     0,     0,     0,     0,     0,     0,   104,
     105,   106,   107,   108,   109,   110,   571,   112,     0,   113,
     114,   115,   116,   117,     0,     0,     0,   118,   119,   120,
     121,   122,   123,   124,   125,     0,   126,     0,   127,   128,
       0,     0,   129,   130,   131,     0,     0,   971,   132,     0,
     133,   134,     0,   136,   137,     0,   138,     0,   139,     0,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,     0,     0,   151,   152,   153,     0,   427,     0,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   533,   534,   535,   184,   185,   536,
     573,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,     0,   201,   202,   203,     0,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,     0,   252,     0,
     253,   254,   255,     0,   256,   257,   258,     1,     2,     0,
       0,     0,     3,     0,     0,     0,     4,     5,     6,     7,
       8,     9,    10,     0,     0,     0,    13,     0,     0,   424,
     425,     0,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,   567,   426,    30,    31,    32,    33,
      34,     0,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,     0,    48,    49,    50,   568,
     569,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
       0,    72,    73,    74,    75,    76,     0,    77,    78,    79,
       0,     0,    80,    81,     0,     0,     0,    82,    83,   515,
      85,    86,    87,    88,    89,   570,    91,     0,    92,     0,
       0,     0,    93,     0,    94,    95,    96,    97,     0,    98,
       0,     0,     0,    99,   100,   101,   102,   103,     0,     0,
       0,     0,     0,     0,   104,   105,   106,   107,   108,   109,
     110,   571,   112,     0,   113,   114,   115,   116,   117,     0,
       0,     0,   118,   119,   120,   121,   122,   123,   124,   125,
       0,   126,     0,   127,   128,     0,     0,   129,   130,   131,
       0,     0,     0,   132,  1218,   133,   134,     0,   136,   137,
       0,   138,     0,   139,     0,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,     0,     0,   151,   152,
     153,     0,   427,     0,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   533,
     534,   535,   184,   185,   536,   573,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,     0,
     201,   202,   203,     0,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,     0,   252,     0,   253,   254,   255,     0,   256,
     257,   258,     1,     2,     0,     0,     0,     3,     0,     0,
       0,     4,     5,     6,     7,     8,     9,    10,     0,     0,
       0,    13,     0,     0,   424,   425,     0,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,   567,
     426,    30,    31,    32,    33,    34,     0,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
       0,    48,    49,    50,   568,   569,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,     0,    72,    73,    74,    75,
      76,     0,    77,    78,    79,     0,     0,    80,    81,     0,
       0,     0,    82,    83,   515,    85,    86,    87,    88,    89,
     570,    91,     0,    92,     0,     0,     0,    93,     0,    94,
      95,    96,    97,     0,    98,     0,     0,     0,    99,   100,
     101,   102,   103,     0,     0,     0,     0,  1483,     0,   104,
     105,   106,   107,   108,   109,   110,   571,   112,     0,   113,
     114,   115,   116,   117,     0,     0,     0,   118,   119,   120,
     121,   122,   123,   124,   125,     0,   126,     0,   127,   128,
       0,     0,   129,   130,   131,     0,     0,     0,   132,     0,
     133,   134,     0,   136,   137,     0,   138,     0,   139,     0,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,     0,     0,   151,   152,   153,     0,   427,     0,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   533,   534,   535,   184,   185,   536,
     573,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,     0,   201,   202,   203,     0,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,     0,   252,     0,
     253,   254,   255,     0,   256,   257,   258,     1,     2,     0,
       0,     0,     3,     0,     0,     0,     4,     5,     6,     7,
       8,     9,    10,     0,     0,     0,    13,     0,     0,   424,
     425,     0,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,   501,    27,   503,   426,    30,   504,    32,    33,
      34,     0,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,   506,     0,    48,    49,    50,   508,
     509,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
       0,    72,    73,    74,    75,    76,     0,    77,    78,    79,
       0,     0,    80,    81,     0,     0,     0,    82,    83,   515,
      85,    86,    87,    88,    89,   570,    91,     0,    92,     0,
       0,     0,    93,     0,    94,    95,    96,    97,     0,    98,
       0,     0,     0,   518,   100,   101,   102,   103,     0,     0,
       0,     0,     0,     0,   104,   105,   106,   107,   108,   109,
     110,   571,   112,     0,   113,   114,   714,   116,   117,     0,
       0,     0,   118,   119,   120,   121,   122,   123,   124,   125,
       0,   126,     0,   715,   128,     0,     0,   129,   130,   131,
       0,     0,     0,   132,     0,   133,   134,     0,   136,   137,
       0,   138,     0,   139,     0,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,     0,     0,   151,   152,
     153,     0,   427,     0,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   528,   168,   529,   170,   530,
     531,   173,   174,   175,   176,   177,   178,   532,   180,   533,
     534,   535,   184,   185,   536,   537,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   538,     0,
     201,   539,   203,     0,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,     0,   252,     0,   253,   540,   255,     0,   256,
     257,   258,     1,     2,     0,     0,     0,     3,     0,     0,
       0,     4,     5,     6,     7,     8,     9,    10,     0,     0,
       0,    13,     0,     0,   424,   425,     0,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,   567,
     426,    30,    31,    32,    33,    34,     0,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
       0,    48,    49,    50,   568,   569,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,     0,    72,    73,    74,    75,
      76,     0,    77,    78,    79,     0,     0,    80,    81,     0,
       0,     0,    82,    83,   515,    85,    86,    87,    88,    89,
     570,    91,     0,    92,     0,     0,     0,    93,     0,    94,
      95,    96,    97,     0,    98,     0,     0,     0,    99,   100,
     101,   102,   103,     0,     0,     0,     0,     0,     0,   104,
     105,   106,   107,   108,   109,   110,   571,   112,     0,   113,
     114,   115,   116,   117,     0,     0,     0,   118,   119,   120,
     121,   122,   123,   124,   125,     0,   126,     0,   127,   128,
       0,     0,   129,   130,   131,     0,     0,     0,   132,     0,
     133,   134,     0,   136,   137,     0,   138,     0,   139,     0,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,     0,     0,   151,   152,   153,     0,   427,     0,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   533,   534,   535,   184,   185,   536,
     573,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,     0,   201,   202,   203,     0,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,     0,   252,     0,
     253,   254,   255,     0,   256,   257,   258,     1,     2,     0,
       0,     0,     3,     0,     0,     0,     4,     5,     6,     7,
       8,     9,    10,     0,     0,     0,    13,     0,     0,   424,
     425,     0,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,   501,    27,   503,   426,    30,   504,    32,    33,
      34,     0,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,   506,     0,    48,    49,    50,   508,
     509,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
       0,    72,    73,    74,    75,    76,     0,    77,    78,    79,
       0,     0,    80,    81,     0,     0,     0,    82,    83,   515,
      85,    86,    87,    88,    89,   570,    91,     0,    92,     0,
       0,     0,    93,     0,    94,    95,    96,    97,     0,    98,
       0,     0,     0,   518,   100,   101,   102,   103,     0,     0,
       0,     0,     0,     0,   104,   105,   106,   107,   108,   109,
     110,   571,   112,     0,   113,   114,   115,   116,   117,     0,
       0,     0,   118,   119,   120,   121,   122,   123,   124,   125,
       0,   126,     0,   127,   128,     0,     0,   129,   130,   131,
       0,     0,     0,   132,     0,   133,   134,     0,   136,   137,
       0,   138,     0,   139,     0,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,     0,     0,   151,   152,
     153,     0,   427,     0,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   528,   168,   529,   170,   530,
     531,   173,   174,   175,   176,   177,   178,   532,   180,   533,
     534,   535,   184,   185,   536,   537,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   538,     0,
     201,   202,   203,     0,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,     0,   252,     0,   253,   540,   255,     0,   256,
     257,   258,     1,     2,     0,     0,     0,     3,     0,     0,
       0,     4,     5,     6,     7,     8,     9,    10,     0,     0,
       0,    13,     0,     0,   424,   425,     0,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,   501,    27,   503,
     426,    30,   504,    32,    33,    34,     0,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,   506,
       0,    48,    49,    50,   508,   509,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,     0,    72,    73,    74,    75,
      76,     0,    77,    78,    79,     0,     0,    80,    81,     0,
       0,     0,    82,    83,   515,    85,    86,    87,    88,    89,
     570,    91,     0,    92,     0,     0,     0,    93,     0,    94,
      95,    96,    97,     0,    98,     0,     0,     0,   518,   100,
     101,   102,   103,     0,     0,     0,     0,     0,     0,   104,
     105,   106,   107,   108,   109,   110,   571,   112,     0,   113,
     114,   115,   116,   117,     0,     0,     0,   118,   119,   120,
     121,   122,   123,   124,   125,     0,   126,     0,   127,   128,
       0,     0,   129,   130,   131,     0,     0,     0,   132,     0,
     133,   134,     0,   136,   137,     0,   138,     0,   139,     0,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,     0,     0,   151,   152,   153,     0,   427,     0,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     528,   168,   529,   170,   530,   531,   173,   174,   175,   176,
     177,   178,   532,   180,   533,   534,   535,   184,   185,   536,
     537,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   538,     0,   201,   539,   203,     0,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,     0,   252,     0,
     253,   540,   255,     0,   256,   257,   258,     1,     2,     0,
       0,     0,     3,     0,     0,     0,     4,     5,     6,     7,
       8,     9,    10,     0,     0,     0,    13,     0,     0,   424,
     425,     0,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,   567,   426,    30,    31,    32,    33,
      34,     0,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,     0,    48,    49,    50,   568,
     569,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
       0,    72,    73,    74,    75,    76,     0,    77,    78,    79,
       0,     0,    80,    81,     0,     0,     0,    82,    83,   515,
      85,    86,    87,    88,    89,  1166,    91,     0,    92,     0,
       0,     0,    93,     0,    94,    95,    96,    97,     0,    98,
       0,     0,     0,    99,   100,   101,   102,   103,     0,     0,
       0,     0,     0,     0,   104,   105,   106,   107,   108,   109,
     110,   571,   112,     0,   113,   114,   115,   116,   117,     0,
       0,     0,   118,   119,   120,   121,   122,   123,   124,   125,
       0,   126,     0,   127,   128,     0,     0,   129,   130,   131,
       0,     0,     0,   132,     0,   133,   134,     0,   136,   137,
       0,   138,     0,   139,     0,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,     0,     0,   151,   152,
     153,     0,   427,     0,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   533,
     534,   535,   184,   185,   536,   573,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,     0,
     201,   202,   203,     0,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,     0,   252,     0,   253,   254,   255,     0,   256,
     257,   258,     1,     2,     0,     0,     0,     3,     0,     0,
       0,     4,     5,     6,     7,     8,     9,    10,     0,     0,
       0,    13,     0,     0,   424,   425,     0,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,   567,
     426,    30,    31,    32,    33,    34,     0,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
       0,    48,    49,    50,   568,   569,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,     0,    72,    73,    74,    75,
      76,     0,    77,    78,    79,     0,     0,    80,    81,     0,
       0,     0,    82,    83,   515,    85,    86,    87,    88,    89,
     570,    91,     0,    92,     0,     0,     0,    93,     0,    94,
      95,    96,    97,     0,    98,     0,     0,     0,    99,   100,
     101,   102,   103,     0,     0,     0,     0,     0,     0,   104,
     105,   106,   107,   108,   109,   110,   571,   112,     0,     0,
     114,   115,   116,   117,     0,     0,     0,   118,   119,   120,
     121,   122,   123,   124,   125,     0,   126,     0,   127,   128,
       0,     0,   129,   130,   131,     0,     0,     0,   132,     0,
     133,   134,     0,   136,   137,     0,   138,     0,   139,     0,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,     0,     0,   151,   152,   153,     0,   427,     0,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   533,   534,   535,   184,   185,   536,
     573,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,     0,   201,   202,   203,     0,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,     0,   252,     0,
     253,   254,   255,     0,   256,   257,   258,     1,     2,     0,
       0,     0,     3,     0,     0,     0,     4,     5,     6,     7,
       8,     9,    10,     0,     0,     0,    13,     0,     0,   424,
     425,     0,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,   501,    27,   503,   426,    30,   504,    32,    33,
      34,     0,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,   506,     0,    48,    49,    50,   508,
     509,    53,   510,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
       0,    72,    73,    74,    75,    76,     0,    77,    78,    79,
       0,     0,    80,    81,     0,     0,     0,    82,    83,   515,
      85,    86,    87,    88,    89,   570,    91,     0,    92,     0,
       0,     0,    93,     0,    94,    95,    96,    97,     0,    98,
       0,     0,     0,   518,   100,   101,   102,   103,     0,     0,
       0,     0,     0,     0,   104,   105,   106,   107,   108,   109,
     110,   571,   112,     0,   113,   114,     0,   116,   117,     0,
       0,     0,   118,   119,   120,   121,   122,   123,   124,   125,
       0,   126,     0,     0,     0,     0,     0,   129,   130,   131,
       0,     0,     0,   132,     0,   133,   134,     0,   136,   137,
       0,   138,     0,   139,     0,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,     0,     0,   151,   152,
     153,     0,   427,     0,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   528,   168,   529,   170,   530,
     531,   173,   174,   175,   176,   177,   178,   532,   180,   533,
     534,   535,   184,   185,   536,   537,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   538,     0,
     201,   539,   203,     0,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,     0,   252,     0,   253,   540,   255,     0,   256,
     257,   258,     1,     2,     0,     0,     0,     3,     0,     0,
       0,     4,     5,     6,     7,     8,     9,    10,     0,     0,
       0,    13,     0,     0,   424,   425,     0,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,   501,    27,   503,
     426,    30,   504,    32,    33,    34,     0,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,   506,
       0,    48,    49,    50,   508,   509,    53,   510,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,     0,    72,    73,    74,    75,
      76,     0,    77,    78,    79,     0,     0,    80,    81,     0,
       0,     0,    82,    83,   515,    85,    86,    87,    88,    89,
     570,    91,     0,    92,     0,     0,     0,    93,     0,    94,
      95,    96,    97,     0,    98,     0,     0,     0,   518,   100,
     101,   102,   103,     0,     0,     0,     0,     0,     0,   104,
     105,   106,   107,   108,   109,   110,   571,   112,     0,   113,
     114,     0,   116,   117,     0,     0,     0,   118,   119,   120,
     121,   122,   123,   124,   125,     0,   126,     0,     0,     0,
       0,     0,   129,   130,   131,     0,     0,     0,   132,     0,
     133,   134,     0,     0,     0,     0,   138,     0,   139,     0,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,     0,     0,   151,   152,   153,     0,   427,     0,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     528,   168,   529,   170,   530,   531,   173,   174,   175,   176,
     177,   178,   532,   180,   533,   534,   535,   184,   185,   536,
     537,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   538,     0,   201,   539,   203,     0,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,     0,   252,     0,
     253,   540,   255,     0,   256,   257,   258,     1,     2,     0,
       0,     0,     3,     0,     0,     0,     4,     5,     6,     7,
       8,     9,    10,     0,     0,     0,    13,     0,     0,   424,
     425,     0,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,   501,    27,   503,   426,    30,   504,    32,    33,
      34,     0,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,   506,     0,    48,    49,    50,   508,
     509,    53,   510,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
       0,    72,    73,    74,    75,    76,     0,    77,    78,    79,
       0,     0,    80,    81,     0,     0,     0,    82,    83,   515,
      85,    86,    87,    88,    89,   570,    91,     0,    92,     0,
       0,     0,    93,     0,    94,    95,    96,    97,     0,    98,
       0,     0,     0,   518,     0,   101,   102,   103,     0,     0,
       0,     0,     0,     0,   104,   105,   106,   107,     0,   109,
     110,   571,   112,     0,   113,   114,     0,   116,   117,     0,
       0,     0,   118,   119,   120,   121,   122,   123,   124,   125,
       0,   126,     0,     0,     0,     0,     0,   129,   130,   131,
       0,     0,     0,   132,     0,   133,   134,     0,     0,     0,
       0,   138,     0,   139,     0,   140,     0,   142,     0,   144,
     145,   146,   147,   148,   149,   150,     0,     0,   151,   152,
     153,     0,   427,     0,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   528,   168,   529,   170,   530,
     531,   173,   174,   175,   176,   177,   178,   532,   180,   533,
     534,   535,   184,   185,   536,   537,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   538,     0,
     201,   539,   203,     0,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,     0,   252,     0,   253,   540,   255,     0,   256,
     257,   258,     1,     2,     0,     0,     0,     3,     0,     0,
       0,     4,     5,     6,     7,     8,     9,    10,     0,     0,
       0,    13,     0,     0,   424,   425,     0,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,   567,
     426,    30,    31,    32,    33,    34,     0,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
       0,    48,    49,    50,   568,   569,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,     0,    72,    73,    74,    75,
      76,     0,    77,    78,    79,     0,     0,    80,    81,     0,
       0,     0,    82,    83,   515,    85,    86,    87,    88,     0,
     570,    91,     0,    92,     0,     0,     0,    93,     0,    94,
      95,    96,    97,     0,    98,     0,     0,     0,    99,     0,
     101,   102,   103,     0,     0,     0,     0,     0,     0,     0,
     105,   106,   107,     0,   109,   110,   571,     0,     0,   113,
     114,     0,     0,   117,     0,     0,     0,   118,   119,   120,
     121,   122,   123,   124,   125,     0,   126,     0,     0,   128,
       0,     0,   129,   130,   131,     0,     0,     0,   132,     0,
     133,   134,     0,     0,     0,     0,     0,     0,   139,     0,
     140,     0,   142,     0,   144,   145,   146,   147,   148,   149,
     150,     0,     0,   151,   152,   153,     0,   427,     0,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   533,   534,   535,   184,   185,   536,
     573,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,     0,   201,   202,   203,     0,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,     0,   252,     0,
     630,   254,   255,     0,   256,   257,   258,     1,     2,     0,
       0,     0,     3,     0,     0,     0,     4,     5,     6,     7,
       8,     9,    10,     0,     0,     0,    13,     0,     0,   424,
     425,     0,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,   501,    27,   503,   426,    30,   504,    32,    33,
      34,     0,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,   506,     0,    48,    49,    50,   508,
     509,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
       0,    72,    73,    74,    75,    76,     0,    77,    78,    79,
       0,     0,    80,    81,     0,     0,     0,    82,    83,   515,
      85,    86,    87,    88,     0,   570,    91,     0,    92,     0,
       0,     0,    93,     0,    94,    95,    96,    97,     0,    98,
       0,     0,     0,   518,     0,   101,   102,   103,     0,     0,
       0,     0,     0,     0,     0,   105,   106,   107,     0,   109,
     110,   571,     0,     0,     0,   114,     0,     0,   117,     0,
       0,     0,   118,   119,   120,   121,   122,   123,   124,   125,
       0,   126,     0,     0,   128,     0,     0,   129,   130,   131,
       0,     0,     0,   132,     0,   133,   134,     0,     0,     0,
       0,     0,     0,   139,     0,   140,     0,   142,     0,   144,
     145,   146,   147,   148,   149,   150,     0,     0,   151,   152,
     153,     0,   427,     0,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   528,   168,   529,   170,   530,
     531,   173,   174,   175,   176,   177,   178,   532,   180,   533,
     534,   535,   184,   185,   536,   537,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   538,     0,
     201,   202,   203,     0,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,     0,   252,     0,   253,   540,   255,     0,   256,
     257,   258,     1,     2,     0,     0,     0,     3,     0,     0,
       0,     4,     5,     6,     7,     8,     9,    10,     0,     0,
       0,    13,     0,     0,   424,   425,     0,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,   567,
     426,     0,    31,    32,    33,    34,     0,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
       0,    48,    49,    50,   568,   569,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,     0,     0,    72,    73,    74,    75,
      76,     0,    77,     0,     0,     0,     0,    80,    81,     0,
       0,     0,    82,    83,   515,    85,    86,    87,    88,     0,
     570,    91,     0,    92,     0,     0,     0,    93,     0,    94,
      95,    96,    97,     0,    98,     0,     0,     0,    99,     0,
     101,   102,   103,     0,     0,     0,     0,     0,     0,     0,
     105,   106,   107,     0,   109,   110,   571,     0,     0,  -627,
     114,     0,     0,   117,     0,     0,     0,   118,   119,   120,
     121,   122,   123,   124,   125,     0,   126,     0,     0,   128,
       0,     0,   129,   130,   131,     0,     0,     0,   132,     0,
     133,   134,     0,     0,     0,     0,     0,     0,   139,     0,
     140,     0,   142,     0,   144,   145,   146,   147,   148,   149,
     150,     0,     0,   151,   152,   153,     0,   427,     0,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   533,   534,   535,   184,   185,   536,
     573,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,     0,   201,   202,   203,     0,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,     0,   252,     0,
     253,   254,   255,     0,   256,   257,   258,     1,     2,     0,
       0,     0,     3,     0,     0,     0,     4,     5,     6,     7,
       8,     9,    10,     0,     0,     0,    13,     0,     0,   424,
     425,     0,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,   567,   426,     0,    31,    32,    33,
      34,     0,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,     0,    48,    49,    50,   568,
     569,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,     0,
       0,    72,    73,    74,    75,    76,     0,    77,     0,     0,
       0,     0,    80,    81,     0,     0,     0,    82,    83,   515,
      85,    86,    87,    88,     0,   570,    91,     0,    92,     0,
       0,     0,    93,     0,    94,    95,    96,    97,     0,    98,
       0,     0,     0,    99,     0,   101,   102,   103,     0,     0,
       0,     0,     0,     0,     0,   105,   106,   107,     0,   109,
     110,   571,     0,     0,   113,   114,     0,     0,   117,     0,
       0,     0,   118,   119,   120,   121,   122,   123,   124,   125,
       0,   126,     0,     0,   128,     0,     0,   129,   130,   131,
       0,     0,     0,   132,     0,   133,   134,     0,     0,     0,
       0,     0,     0,   139,     0,   140,     0,   142,     0,   144,
     145,   146,   147,   148,   149,   150,     0,     0,   151,   152,
     153,     0,   427,     0,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   533,
     534,   535,   184,   185,   536,   573,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,     0,
     201,   202,   203,     0,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,     0,   252,     0,   253,   254,   255,     0,   256,
     257,   258,     1,     2,     0,     0,     0,     3,     0,     0,
       0,     4,     5,     6,     7,     8,     9,    10,     0,     0,
       0,    13,     0,     0,   424,   425,     0,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,   567,
     426,     0,    31,    32,    33,    34,     0,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
       0,    48,    49,    50,   568,   569,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,     0,     0,    72,    73,    74,    75,
      76,     0,    77,     0,     0,     0,     0,    80,    81,     0,
       0,     0,    82,    83,   515,    85,    86,    87,    88,     0,
     570,    91,     0,    92,     0,     0,     0,    93,     0,    94,
      95,    96,    97,     0,    98,     0,     0,     0,    99,     0,
     101,   102,   103,     0,     0,     0,     0,     0,     0,     0,
     105,   106,   107,     0,   109,   110,   571,     0,     0,     0,
     114,     0,     0,   117,     0,     0,     0,   118,   119,   120,
     121,   122,   123,   124,   125,     0,   126,     0,     0,   128,
       0,     0,   129,   130,   131,     0,     0,     0,   132,     0,
     133,   134,     0,     0,     0,     0,     0,     0,   139,     0,
     140,     0,   142,     0,   144,   145,   146,   147,   148,   149,
     150,     0,     0,   151,   152,   153,     0,   427,     0,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   533,   534,   535,   184,   185,   536,
     573,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,     0,   201,   202,   203,     0,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,     0,   252,     0,
     253,   254,   255,     0,   256,   257,   258,     1,     2,     0,
       0,     0,     3,     0,     0,     0,     4,     0,     0,     0,
       0,     9,    10,     0,     0,     0,     0,     0,     0,   424,
     425,     0,    16,    17,    18,   498,    20,    21,    22,   499,
      24,   500,   501,   502,   503,   426,    30,   504,    32,    33,
      34,     0,    35,    36,    37,    38,   505,    40,    41,    42,
      43,    44,    45,    46,   506,     0,    48,   507,    50,   508,
     509,    53,   510,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,   511,   512,    71,
       0,    72,    73,    74,   513,     0,     0,    77,    78,    79,
       0,     0,   514,    81,     0,     0,     0,     0,    83,   515,
      85,   516,   517,    88,    89,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    94,    95,    96,    97,     0,    98,
       0,     0,     0,   518,   100,   101,   519,   520,     0,     0,
       0,     0,     0,     0,   104,   105,   106,     0,   108,   109,
     110,     0,     0,     0,     0,     0,     0,   116,   521,     0,
       0,     0,   118,   119,   120,   121,   522,   123,   124,   523,
       0,     0,     0,     0,     0,     0,     0,   524,   525,   131,
       0,     0,     0,   132,     0,   133,   526,     0,     0,     0,
       0,   138,     0,   139,     0,   140,   141,   142,   143,   527,
     145,   146,   147,   148,   149,   150,     0,     0,   151,   152,
       0,     0,   427,     0,   156,   157,     0,     0,     0,   161,
     162,   163,   164,   165,   166,   528,   168,   529,   170,   530,
     531,   173,   174,   175,   176,   177,   178,   532,   180,   533,
     534,   535,   184,   185,   536,   537,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   538,     0,
     201,   539,   203,     0,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,     0,     0,     1,     2,   253,   540,   255,     3,   256,
     257,   258,     4,     0,     0,     0,     0,     9,    10,     0,
       0,     0,     0,     0,     0,   424,   425,     0,    16,    17,
      18,   548,    20,    21,    22,   499,   549,   550,   501,   502,
     503,   426,    30,   504,    32,   551,    34,     0,    35,    36,
      37,    38,   552,    40,   553,   554,    43,    44,    45,    46,
     506,     0,    48,   555,    50,   508,   509,    53,   510,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,   511,   512,    71,     0,    72,    73,    74,
     556,     0,     0,    77,    78,    79,     0,     0,   514,    81,
       0,     0,     0,     0,    83,   515,    85,   516,   517,    88,
      89,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      94,    95,    96,    97,     0,    98,     0,     0,     0,   518,
     100,   101,   519,   520,     0,     0,     0,     0,     0,     0,
     104,   105,   106,     0,   108,   109,   110,     0,     0,     0,
       0,     0,     0,   116,   521,     0,     0,     0,   118,   119,
     120,   121,   522,   123,   124,   523,     0,     0,     0,     0,
       0,     0,     0,   524,   525,   131,     0,     0,     0,   132,
       0,   133,   526,     0,     0,     0,     0,   138,     0,   139,
       0,   140,   141,   142,   143,   527,   145,   146,   147,   148,
     149,   150,     0,     0,   151,   152,     0,     0,   427,     0,
     156,   157,     0,     0,     0,   161,   162,   163,   164,   165,
     166,   528,   557,   529,   170,   530,   531,   173,   174,   175,
     176,   177,   178,   532,   180,   533,   534,   535,   184,   185,
     536,   537,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   538,     0,   201,   539,   203,     0,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,     0,     0,     1,
       2,   253,   540,   255,     3,   256,   257,   258,     4,     5,
       6,     7,     8,     9,    10,     0,     0,     0,    13,     0,
       0,   424,   425,     0,    16,    17,    18,    19,    20,    21,
       0,    23,    24,    25,     0,    27,   567,   426,     0,     0,
      32,    33,    34,     0,     0,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,     0,     0,    49,
      50,   568,   569,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,     0,     0,     0,     0,    74,    75,    76,     0,     0,
       0,     0,     0,     0,    80,     0,     0,     0,     0,    82,
      83,   515,     0,    86,    87,    88,     0,   570,    91,     0,
      92,     0,     0,     0,    93,     0,    94,    95,    96,    97,
       0,    98,     0,     0,     0,    99,     0,   101,   102,   103,
       0,     0,     0,     0,     0,     0,     0,   105,   106,   107,
       0,   109,   110,   571,     0,     0,     0,   114,     0,     0,
     117,     0,     0,     0,   118,   119,   120,   121,   122,   123,
     124,   125,     0,   126,     0,     0,   128,     0,     0,   129,
     130,   131,     0,     0,     0,   132,     0,   133,   134,     0,
       0,     0,     0,     0,     0,   139,     0,   140,     0,   142,
       0,   144,   145,   146,   147,   148,   149,   150,     0,     0,
     151,   152,   153,     0,   427,     0,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   606,   169,
     607,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   533,   534,   535,   184,   185,   536,   573,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
       0,     0,   201,   202,   203,     0,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,     0,   252,     3,   608,   254,   255,
       0,   256,   257,   258,     0,     9,    10,     0,     0,     0,
       0,     0,     0,   424,   425,     0,    16,    17,    18,   498,
      20,    21,    22,   499,    24,   500,   501,  1192,   503,   426,
      30,   504,    32,    33,    34,     0,    35,    36,    37,    38,
     505,    40,    41,    42,    43,    44,    45,    46,   506,     0,
      48,   507,    50,   508,   509,    53,   510,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,   511,   512,    71,     0,    72,    73,    74,   513,     0,
       0,    77,    78,    79,     0,     0,   514,    81,     0,     0,
       0,     0,    83,   515,    85,   516,   517,    88,    89,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    94,    95,
      96,    97,     0,    98,     0,     0,     0,   518,   100,   101,
     519,   520,     0,     0,     0,     0,     0,     0,   104,   105,
     106,     0,   108,   109,  1193,     0,     0,     0,  1194,     0,
       0,   116,   521,     0,     0,     0,   118,   119,   120,   121,
     522,   123,   124,   523,     0,     0,     0,     0,     0,     0,
       0,   524,   525,   131,     0,     0,     0,   132,  1639,   133,
     526,     0,     0,     0,     0,  1640,     0,   139,     0,   140,
     141,   142,   143,   527,   145,   146,   147,   148,   149,   150,
       0,     0,  1195,   152,     0,     0,   427,     0,   156,   157,
    1196,     0,     0,   161,   162,   163,   164,   165,   166,   528,
     168,   529,   170,   530,   531,   173,   174,   175,   176,   177,
     178,   532,   180,   533,   534,   535,   184,   185,   536,   537,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   538,     0,   201,   539,   203,     0,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,     0,     0,     3,     0,   253,
     540,   255,  1197,  1198,  1199,  1200,     9,    10,     0,     0,
       0,     0,     0,     0,   424,   425,     0,    16,    17,    18,
     498,    20,    21,    22,   499,    24,   500,   501,  1192,   503,
     426,    30,   504,    32,    33,    34,     0,    35,    36,    37,
      38,   505,    40,    41,    42,    43,    44,    45,    46,   506,
       0,    48,   507,    50,   508,   509,    53,   510,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,   511,   512,    71,     0,    72,    73,    74,   513,
       0,     0,    77,    78,    79,     0,     0,   514,    81,     0,
       0,     0,     0,    83,   515,    85,   516,   517,    88,    89,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    94,
      95,    96,    97,     0,    98,     0,     0,     0,   518,   100,
     101,   519,   520,     0,     0,     0,     0,     0,     0,   104,
     105,   106,     0,   108,   109,  1193,     0,     0,     0,  1233,
       0,     0,   116,   521,     0,     0,     0,   118,   119,   120,
     121,   522,   123,   124,   523,     0,     0,     0,     0,     0,
       0,     0,   524,   525,   131,     0,     0,     0,   132,  1470,
     133,   526,     0,     0,     0,     0,     0,     0,   139,     0,
     140,   141,   142,   143,   527,   145,   146,   147,   148,   149,
     150,     0,     0,   151,   152,     0,     0,   427,     0,   156,
     157,  1196,     0,     0,   161,   162,   163,   164,   165,   166,
     528,   168,   529,   170,   530,   531,   173,   174,   175,   176,
     177,   178,   532,   180,   533,   534,   535,   184,   185,   536,
     537,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   538,     0,   201,   539,   203,     0,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,     0,     0,     3,     0,
     253,   540,   255,  1197,  1198,  1199,  1200,     9,    10,     0,
       0,     0,     0,     0,     0,   424,   425,     0,    16,    17,
      18,   498,    20,    21,    22,   499,    24,   500,   501,  1192,
     503,   426,    30,   504,    32,    33,    34,     0,    35,    36,
      37,    38,   505,    40,    41,    42,    43,    44,    45,    46,
     506,     0,    48,   507,    50,   508,   509,    53,   510,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,   511,   512,    71,     0,    72,    73,    74,
     513,     0,     0,    77,    78,    79,     0,     0,   514,    81,
       0,     0,     0,     0,    83,   515,    85,   516,   517,    88,
      89,  1544,     0,     0,     0,     0,     0,     0,     0,     0,
      94,    95,    96,    97,     0,    98,     0,     0,     0,   518,
     100,   101,   519,   520,     0,     0,     0,     0,     0,     0,
     104,   105,   106,     0,   108,   109,  1193,     0,     0,     0,
    1194,     0,     0,   116,   521,     0,     0,     0,   118,   119,
     120,   121,   522,   123,   124,   523,     0,     0,     0,     0,
       0,     0,     0,   524,   525,   131,     0,     0,     0,   132,
       0,   133,   526,     0,     0,     0,     0,     0,     0,   139,
       0,   140,   141,   142,   143,   527,   145,   146,   147,   148,
     149,   150,     0,     0,  1195,   152,     0,     0,   427,     0,
     156,   157,  1196,     0,     0,   161,   162,   163,   164,   165,
     166,   528,   168,   529,   170,   530,   531,   173,   174,   175,
     176,   177,   178,   532,   180,   533,   534,   535,   184,   185,
     536,   537,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   538,     0,   201,   539,   203,     0,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,     0,     0,     3,
       0,   253,   540,   255,  1197,  1198,  1199,  1200,     9,    10,
       0,     0,     0,     0,     0,     0,   424,   425,     0,    16,
      17,    18,   498,    20,    21,    22,   499,    24,   500,   501,
    1192,   503,   426,    30,   504,    32,    33,    34,     0,    35,
      36,    37,    38,   505,    40,    41,    42,    43,    44,    45,
      46,   506,     0,    48,   507,    50,   508,   509,    53,   510,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,   511,   512,    71,     0,    72,    73,
      74,   513,     0,     0,    77,    78,    79,     0,     0,   514,
      81,     0,     0,     0,     0,    83,   515,    85,   516,   517,
      88,    89,  1692,     0,     0,     0,     0,     0,     0,     0,
       0,    94,    95,    96,    97,     0,    98,     0,     0,     0,
     518,   100,   101,   519,   520,     0,     0,     0,     0,     0,
       0,   104,   105,   106,     0,   108,   109,  1193,     0,     0,
       0,  1194,     0,     0,   116,   521,     0,     0,     0,   118,
     119,   120,   121,   522,   123,   124,   523,     0,     0,     0,
       0,     0,     0,     0,   524,   525,   131,     0,     0,     0,
     132,     0,   133,   526,     0,     0,     0,     0,     0,     0,
     139,     0,   140,   141,   142,   143,   527,   145,   146,   147,
     148,   149,   150,     0,     0,  1195,   152,     0,     0,   427,
       0,   156,   157,  1196,     0,     0,   161,   162,   163,   164,
     165,   166,   528,   168,   529,   170,   530,   531,   173,   174,
     175,   176,   177,   178,   532,   180,   533,   534,   535,   184,
     185,   536,   537,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   538,     0,   201,   539,   203,
       0,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,     0,     0,
       3,     0,   253,   540,   255,  1197,  1198,  1199,  1200,     9,
      10,     0,     0,     0,     0,     0,     0,   424,   425,     0,
      16,    17,    18,   498,    20,    21,    22,   499,    24,   500,
     501,  1192,   503,   426,    30,   504,    32,    33,    34,     0,
      35,    36,    37,    38,   505,    40,    41,    42,    43,    44,
      45,    46,   506,     0,    48,   507,    50,   508,   509,    53,
     510,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,   511,   512,    71,     0,    72,
      73,    74,   513,     0,     0,    77,    78,    79,     0,     0,
     514,    81,     0,     0,     0,     0,    83,   515,    85,   516,
     517,    88,    89,  1696,     0,     0,     0,     0,     0,     0,
       0,     0,    94,    95,    96,    97,     0,    98,     0,     0,
       0,   518,   100,   101,   519,   520,     0,     0,     0,     0,
       0,     0,   104,   105,   106,     0,   108,   109,  1193,     0,
       0,     0,  1194,     0,     0,   116,   521,     0,     0,     0,
     118,   119,   120,   121,   522,   123,   124,   523,     0,     0,
       0,     0,     0,     0,     0,   524,   525,   131,     0,     0,
       0,   132,     0,   133,   526,     0,     0,     0,     0,     0,
       0,   139,     0,   140,   141,   142,   143,   527,   145,   146,
     147,   148,   149,   150,     0,     0,  1195,   152,     0,     0,
     427,     0,   156,   157,  1196,     0,     0,   161,   162,   163,
     164,   165,   166,   528,   168,   529,   170,   530,   531,   173,
     174,   175,   176,   177,   178,   532,   180,   533,   534,   535,
     184,   185,   536,   537,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   538,     0,   201,   539,
     203,     0,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,     0,
       0,     3,     0,   253,   540,   255,  1197,  1198,  1199,  1200,
       9,    10,     0,     0,     0,    13,     0,     0,   424,   425,
       0,    16,    17,    18,   548,    20,    21,    22,   499,   549,
     550,   501,   502,   503,   426,    30,   504,    32,   551,    34,
       0,    35,    36,    37,    38,   552,    40,   553,   554,    43,
      44,    45,    46,   506,     0,    48,   555,    50,   508,   509,
      53,   510,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,   511,   512,    71,     0,
      72,    73,    74,   556,     0,     0,    77,    78,    79,     0,
       0,   514,    81,     0,     0,     0,     0,    83,   515,    85,
     516,   517,    88,    89,   570,     0,     0,     0,     0,     0,
       0,     0,     0,    94,    95,    96,    97,     0,    98,     0,
       0,     0,   518,   100,   101,   519,   520,     0,     0,     0,
       0,     0,     0,   104,   105,   106,     0,   108,   109,   110,
       0,     0,     0,   967,     0,     0,   116,   521,     0,     0,
       0,   118,   119,   120,   121,   522,   123,   124,   523,     0,
       0,     0,     0,     0,     0,     0,   524,   525,   131,     0,
       0,     0,   132,     0,   133,   526,     0,     0,     0,     0,
       0,     0,   139,     0,   140,   141,   142,   143,   527,   145,
     146,   147,   148,   149,   150,     0,     0,   151,   152,     0,
       0,   427,     0,   156,   157,     0,     0,     0,   161,   162,
     163,   164,   165,   166,   528,   557,   529,   170,   530,   531,
     173,   174,   175,   176,   177,   178,   532,   180,   533,   534,
     535,   184,   185,   536,   537,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   538,     0,   201,
     539,   203,     0,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
       0,     0,     3,     0,   253,   540,   255,     0,   256,   257,
     258,     9,    10,     0,     0,     0,     0,     0,     0,   424,
     425,     0,    16,    17,    18,   498,    20,    21,    22,   499,
      24,   500,   501,  1192,   503,   426,    30,   504,    32,    33,
      34,     0,    35,    36,    37,    38,   505,    40,    41,    42,
      43,    44,    45,    46,   506,     0,    48,   507,    50,   508,
     509,    53,   510,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,   511,   512,    71,
       0,    72,    73,    74,   513,     0,     0,    77,    78,    79,
       0,     0,   514,    81,     0,     0,     0,     0,    83,   515,
      85,   516,   517,    88,    89,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    94,    95,    96,    97,     0,    98,
       0,     0,     0,   518,   100,   101,   519,   520,     0,     0,
       0,     0,     0,     0,   104,   105,   106,     0,   108,   109,
    1193,     0,     0,     0,  1194,     0,     0,   116,   521,     0,
       0,     0,   118,   119,   120,   121,   522,   123,   124,   523,
       0,     0,     0,     0,     0,     0,     0,   524,   525,   131,
       0,     0,     0,   132,     0,   133,   526,     0,     0,     0,
       0,     0,     0,   139,     0,   140,   141,   142,   143,   527,
     145,   146,   147,   148,   149,   150,     0,     0,  1195,   152,
       0,     0,   427,     0,   156,   157,  1196,     0,     0,   161,
     162,   163,   164,   165,   166,   528,   168,   529,   170,   530,
     531,   173,   174,   175,   176,   177,   178,   532,   180,   533,
     534,   535,   184,   185,   536,   537,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   538,     0,
     201,   539,   203,     0,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,     0,     0,     3,     0,   253,   540,   255,  1197,  1198,
    1199,  1200,     9,    10,     0,     0,     0,     0,     0,     0,
     424,   425,     0,    16,    17,    18,   498,    20,    21,    22,
     499,    24,   500,   501,  1192,   503,   426,    30,   504,    32,
      33,    34,     0,    35,    36,    37,    38,   505,    40,    41,
      42,    43,    44,    45,    46,   506,     0,    48,   507,    50,
     508,   509,    53,   510,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,   511,   512,
      71,     0,    72,    73,    74,   513,     0,     0,    77,    78,
      79,     0,     0,   514,    81,     0,     0,     0,     0,    83,
     515,    85,   516,   517,    88,    89,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    94,    95,    96,    97,     0,
      98,     0,     0,     0,   518,   100,   101,   519,   520,     0,
       0,     0,     0,     0,     0,   104,   105,   106,     0,   108,
     109,  1193,     0,     0,     0,  1233,     0,     0,   116,   521,
       0,     0,     0,   118,   119,   120,   121,   522,   123,   124,
     523,     0,     0,     0,     0,     0,     0,     0,   524,   525,
     131,     0,     0,     0,   132,     0,   133,   526,     0,     0,
       0,     0,     0,     0,   139,     0,   140,   141,   142,   143,
     527,   145,   146,   147,   148,   149,   150,     0,     0,   151,
     152,     0,     0,   427,     0,   156,   157,  1196,     0,     0,
     161,   162,   163,   164,   165,   166,   528,   168,   529,   170,
     530,   531,   173,   174,   175,   176,   177,   178,   532,   180,
     533,   534,   535,   184,   185,   536,   537,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   538,
       0,   201,   539,   203,     0,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,     0,     0,     0,     0,   253,   540,   255,  1197,
    1198,  1199,  1200,     3,     0,   584,   585,     0,     0,     0,
       0,     0,     9,    10,     0,     0,     0,     0,     0,     0,
     424,   425,     0,    16,    17,    18,   548,    20,    21,    22,
     499,   549,   550,   501,   502,   503,   426,    30,   504,    32,
     551,    34,     0,    35,    36,    37,    38,   552,    40,   553,
     554,    43,    44,    45,    46,   506,     0,    48,   555,    50,
     508,   509,    53,   510,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,   511,   512,
      71,     0,    72,    73,    74,   556,     0,     0,    77,    78,
      79,     0,     0,   514,    81,     0,     0,     0,     0,    83,
     515,    85,   516,   517,    88,    89,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    94,    95,    96,    97,     0,
      98,     0,     0,     0,   518,   100,   101,   519,   520,     0,
       0,     0,     0,     0,     0,   104,   105,   106,     0,   108,
     109,   110,     0,     0,     0,     0,     0,     0,   116,   521,
       0,     0,     0,   118,   119,   120,   121,   522,   123,   124,
     523,     0,     0,     0,     0,     0,     0,     0,   524,   525,
     131,     0,     0,     0,   132,     0,   133,   526,     0,     0,
       0,     0,     0,     0,   139,     0,   140,   141,   142,   143,
     527,   145,   146,   147,   148,   149,   150,     0,     0,   151,
     152,     0,     0,   427,     0,   156,   157,     0,     0,     0,
     161,   162,   163,   164,   165,   166,   528,   557,   529,   170,
     530,   531,   173,   174,   175,   176,   177,   178,   532,   180,
     533,   534,   535,   184,   185,   536,   537,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   538,
       0,   201,   539,   203,     0,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,     0,     0,     3,     0,   253,   540,   255,     0,
     256,   257,   258,     9,    10,     0,     0,     0,     0,     0,
       0,   424,   425,     0,    16,    17,    18,   548,    20,    21,
      22,   499,   549,   550,   501,   502,   503,   426,    30,   504,
      32,   551,    34,     0,    35,    36,    37,    38,   552,    40,
     553,   554,    43,    44,    45,    46,   506,     0,    48,   555,
      50,   508,   509,    53,   510,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,   511,
     512,    71,     0,    72,    73,    74,   556,     0,     0,    77,
      78,    79,     0,     0,   514,    81,     0,     0,     0,     0,
      83,   515,    85,   516,   517,    88,    89,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    94,    95,    96,    97,
       0,    98,     0,     0,     0,   518,   100,   101,   519,   520,
       0,     0,     0,     0,     0,     0,   104,   105,   106,     0,
     108,   109,   110,     0,     0,     0,     0,     0,     0,   116,
     521,     0,     0,     0,   118,   119,   120,   121,   522,   123,
     124,   523,     0,     0,     0,     0,     0,     0,     0,   524,
     525,   131,     0,     0,     0,   132,   789,   133,   526,     0,
       0,     0,     0,   790,     0,   139,     0,   140,   141,   142,
     143,   527,   145,   146,   147,   148,   149,   150,     0,     0,
     151,   152,     0,     0,   427,     0,   156,   157,     0,     0,
       0,   161,   162,   163,   164,   165,   166,   528,   557,   529,
     170,   530,   531,   173,   174,   175,   176,   177,   178,   532,
     180,   533,   534,   535,   184,   185,   536,   537,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     538,     0,   201,   539,   203,     0,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,     0,     0,     3,     0,   253,   540,   255,
       0,   256,   257,   258,     9,    10,     0,     0,     0,   815,
       0,     0,   424,   425,     0,    16,    17,    18,   548,    20,
      21,    22,   499,   549,   550,   501,   502,   503,   426,    30,
     504,    32,   551,    34,     0,    35,    36,    37,    38,   552,
      40,   553,   554,    43,    44,    45,    46,   506,     0,    48,
     555,    50,   508,   509,    53,   510,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
     511,   512,    71,     0,    72,    73,    74,   556,     0,     0,
      77,    78,    79,     0,     0,   514,    81,     0,     0,     0,
       0,    83,   515,    85,   516,   517,    88,    89,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    94,    95,    96,
      97,     0,    98,     0,     0,     0,   518,   100,   101,   519,
     520,     0,     0,     0,     0,     0,     0,   104,   105,   106,
       0,   108,   109,   110,     0,     0,     0,     0,     0,     0,
     116,   521,     0,     0,     0,   118,   119,   120,   121,   522,
     123,   124,   523,     0,     0,     0,     0,     0,     0,     0,
     524,   525,   131,     0,     0,     0,   132,   816,   133,   526,
       0,     0,     0,     0,     0,     0,   139,     0,   140,   141,
     142,   143,   527,   145,   146,   147,   148,   149,   150,     0,
       0,   151,   152,     0,     0,   427,     0,   156,   157,     0,
       0,     0,   161,   162,   163,   164,   165,   166,   528,   557,
     529,   170,   530,   531,   173,   174,   175,   176,   177,   178,
     532,   180,   533,   534,   535,   184,   185,   536,   537,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   538,     0,   201,   539,   203,     0,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,     0,     0,     3,     0,   253,   540,
     255,     0,   256,   257,   258,     9,    10,     0,     0,     0,
       0,     0,     0,   424,   425,     0,    16,    17,    18,   548,
      20,    21,    22,   499,   549,   550,   501,   502,   503,   426,
      30,   504,    32,   551,    34,     0,    35,    36,    37,    38,
     552,    40,   553,   554,    43,    44,    45,    46,   506,     0,
      48,   555,    50,   508,   509,    53,   510,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,   511,   512,    71,     0,    72,    73,    74,   556,     0,
       0,    77,    78,    79,     0,     0,   514,    81,     0,     0,
       0,     0,    83,   515,    85,   516,   517,    88,    89,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    94,    95,
      96,    97,     0,    98,     0,     0,     0,   518,   100,   101,
     519,   520,     0,     0,     0,     0,     0,     0,   104,   105,
     106,     0,   108,   109,   110,     0,     0,     0,     0,     0,
       0,   116,   521,     0,     0,     0,   118,   119,   120,   121,
     522,   123,   124,   523,     0,     0,     0,     0,     0,     0,
       0,   524,   525,   131,     0,     0,     0,   132,   833,   133,
     526,     0,     0,     0,     0,   834,     0,   139,     0,   140,
     141,   142,   143,   527,   145,   146,   147,   148,   149,   150,
       0,     0,   151,   152,     0,     0,   427,     0,   156,   157,
       0,     0,     0,   161,   162,   163,   164,   165,   166,   528,
     557,   529,   170,   530,   531,   173,   174,   175,   176,   177,
     178,   532,   180,   533,   534,   535,   184,   185,   536,   537,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   538,     0,   201,   539,   203,     0,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,     0,     0,     3,     0,   253,
     540,   255,     0,   256,   257,   258,     9,    10,     0,     0,
       0,     0,     0,     0,   424,   425,     0,    16,    17,    18,
     548,    20,    21,    22,   499,   549,   550,   501,   502,   503,
     426,    30,   504,    32,   551,    34,     0,    35,    36,    37,
      38,   552,    40,   553,   554,    43,    44,    45,    46,   506,
       0,    48,   555,    50,   508,   509,    53,   510,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,   511,   512,    71,     0,    72,    73,    74,   556,
       0,     0,    77,    78,    79,     0,     0,   514,    81,     0,
       0,     0,     0,    83,   515,    85,   516,   517,    88,    89,
    1287,     0,     0,     0,     0,     0,     0,     0,     0,    94,
      95,    96,    97,     0,    98,     0,     0,     0,   518,   100,
     101,   519,   520,     0,     0,     0,     0,     0,     0,   104,
     105,   106,     0,   108,   109,   110,     0,     0,     0,     0,
       0,     0,   116,   521,     0,     0,     0,   118,   119,   120,
     121,   522,   123,   124,   523,     0,     0,     0,     0,     0,
       0,     0,   524,   525,   131,     0,     0,     0,   132,     0,
     133,   526,     0,     0,     0,     0,     0,     0,   139,     0,
     140,   141,   142,   143,   527,   145,   146,   147,   148,   149,
     150,     0,     0,   151,   152,     0,     0,   427,     0,   156,
     157,     0,     0,     0,   161,   162,   163,   164,   165,   166,
     528,   557,   529,   170,   530,   531,   173,   174,   175,   176,
     177,   178,   532,   180,   533,   534,   535,   184,   185,   536,
     537,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   538,     0,   201,   539,   203,     0,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,     0,     0,     3,     0,
     253,   540,   255,     0,   256,   257,   258,     9,    10,     0,
       0,     0,     0,     0,     0,   424,   425,     0,    16,    17,
      18,   548,    20,    21,    22,   499,   549,   550,   501,   502,
     503,   426,    30,   504,    32,   551,    34,     0,    35,    36,
      37,    38,   552,    40,   553,   554,    43,    44,    45,    46,
     506,     0,    48,   555,    50,   508,   509,    53,   510,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,   511,   512,    71,     0,    72,    73,    74,
     556,     0,     0,    77,    78,    79,     0,     0,   514,    81,
       0,     0,     0,     0,    83,   515,    85,   516,   517,    88,
      89,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      94,    95,    96,    97,     0,    98,     0,     0,     0,   518,
     100,   101,   519,   520,     0,     0,     0,     0,     0,     0,
     104,   105,   106,     0,   108,   109,   110,     0,     0,     0,
       0,     0,     0,   116,   521,     0,     0,     0,   118,   119,
     120,   121,   522,   123,   124,   523,     0,     0,     0,     0,
       0,     0,     0,   524,   525,   131,     0,     0,     0,   132,
       0,   133,   526,     0,     0,     0,     0,     0,     0,   139,
       0,   140,   141,   142,   143,   527,   145,   146,   147,   148,
     149,   150,     0,     0,   151,   152,     0,     0,   427,     0,
     156,   157,     0,     0,     0,   161,   162,   163,   164,   165,
     166,   528,   557,   529,   170,   530,   531,   173,   174,   175,
     176,   177,   178,   532,   180,   533,   534,   535,   184,   185,
     536,   537,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   538,     0,   201,   539,   203,     0,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,     0,     0,     0,
       0,   253,   540,   255,     0,   256,   257,   258,     5,     6,
       7,     8,     9,    10,     0,     0,     0,    13,     0,     0,
     424,   425,     0,    16,    17,    18,   596,    20,    21,    22,
      23,     0,   597,   501,    27,     0,   426,    30,   504,    32,
       0,    34,     0,    35,    36,    37,    38,   598,    40,     0,
       0,    43,    44,    45,    46,   506,     0,    48,   599,    50,
       0,     0,    53,   510,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,   511,   512,
      71,     0,    72,    73,    74,   600,     0,     0,    77,    78,
      79,     0,     0,   514,    81,     0,     0,     0,    82,    83,
     515,    85,   516,   517,    88,    89,   570,    91,     0,     0,
       0,     0,     0,    93,     0,    94,    95,    96,    97,     0,
      98,     0,     0,     0,   518,   100,   101,   519,   520,     0,
       0,     0,     0,     0,     0,   104,   105,   106,   107,   108,
     109,     0,   571,   112,     0,   113,   114,     0,   116,   117,
       0,     0,     0,   118,   119,   120,   121,   122,   123,   124,
     523,     0,   126,     0,     0,     0,     0,     0,   524,   525,
     131,     0,     0,     0,   132,     0,   133,   526,     0,     0,
       0,     0,     0,     0,   139,     0,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,     0,     0,     0,
     152,   153,     0,   427,     0,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   528,  1138,   529,   170,
     530,   531,   173,   174,   175,   176,   177,   178,   532,   180,
     533,   534,   535,   184,   185,     0,   537,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   538,
       0,   201,   539,   203,     0,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,     0,   252,     0,     0,     0,   255,     5,
       6,     7,     8,     9,    10,     0,     0,     0,    13,     0,
       0,   424,   425,     0,    16,    17,    18,   596,    20,    21,
      22,    23,     0,   597,   501,    27,     0,   426,    30,   504,
      32,     0,    34,     0,    35,    36,    37,    38,   598,    40,
       0,     0,    43,    44,    45,    46,   506,     0,    48,   599,
      50,     0,     0,    53,   510,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,   511,
     512,    71,     0,    72,    73,    74,   600,     0,     0,    77,
      78,    79,     0,     0,   514,    81,     0,     0,     0,    82,
      83,   515,    85,   516,   517,    88,    89,   570,    91,     0,
       0,     0,     0,     0,    93,     0,    94,    95,    96,    97,
       0,    98,     0,     0,     0,   518,   100,   101,   519,   520,
       0,     0,     0,     0,     0,     0,   104,   105,   106,   107,
     108,   109,     0,   571,   112,     0,   113,   114,     0,   116,
     117,     0,     0,     0,   118,   119,   120,   121,   122,   123,
     124,   523,     0,   126,     0,     0,     0,     0,     0,   524,
     525,   131,     0,     0,     0,   132,     0,   133,   526,     0,
       0,     0,     0,     0,     0,   139,     0,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,     0,     0,
       0,   152,   153,     0,   427,     0,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   528,     0,   529,
     170,   530,   531,   173,   174,   175,   176,   177,   178,   532,
     180,   533,   534,   535,   184,   185,     0,   537,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     538,     0,   201,   539,   203,     0,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,     0,   252,     0,     0,     0,   255,
       5,     6,     7,     8,     9,    10,     0,     0,     0,    13,
       0,     0,   424,   425,     0,    16,    17,    18,   596,    20,
      21,     0,    23,     0,   597,     0,    27,     0,   426,     0,
       0,    32,     0,    34,     0,     0,    36,    37,    38,   598,
      40,     0,     0,    43,    44,    45,    46,   506,     0,     0,
     599,    50,     0,     0,    53,   510,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
     511,   512,     0,     0,     0,     0,    74,   600,     0,     0,
       0,     0,     0,     0,     0,   514,     0,     0,     0,     0,
      82,    83,   515,     0,   516,   517,    88,     0,   570,    91,
       0,     0,     0,     0,     0,    93,     0,    94,    95,    96,
      97,     0,    98,     0,     0,     0,   518,     0,   101,   519,
     520,     0,     0,     0,     0,     0,     0,     0,   105,   106,
     107,     0,   109,     0,   571,     0,     0,     0,   114,     0,
       0,   117,     0,     0,     0,   118,   119,   120,   121,   122,
     123,   124,   523,     0,   126,     0,     0,     0,     0,     0,
     524,   525,   131,     0,     0,     0,   132,     0,   133,   526,
       0,     0,     0,     0,     0,     0,   139,     0,   140,     0,
     142,     0,   144,   145,   146,   147,   148,   149,   150,     0,
       0,     0,   152,   153,     0,   427,     0,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   528,   601,
     529,   602,   530,   531,   173,   174,   175,   176,   177,   178,
     532,   180,   533,   534,   535,   184,   185,     0,   537,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,     0,     0,   201,   539,   203,     0,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,     0,   252,     0,   603,     0,
     255,     5,     6,     7,     8,     9,    10,     0,     0,     0,
      13,     0,     0,   424,   425,     0,    16,    17,    18,   596,
      20,    21,     0,    23,     0,   597,     0,    27,     0,   426,
       0,     0,    32,     0,    34,     0,     0,    36,    37,    38,
     598,    40,     0,     0,    43,    44,    45,    46,   506,     0,
       0,   599,    50,     0,     0,    53,   510,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,   511,   512,     0,     0,     0,     0,    74,   600,     0,
       0,     0,     0,     0,     0,     0,   514,     0,     0,     0,
       0,    82,    83,   515,     0,   516,   517,     0,     0,   570,
      91,     0,     0,     0,     0,     0,    93,     0,     0,     0,
      96,    97,     0,    98,     0,     0,     0,   518,     0,   101,
     519,   520,     0,     0,     0,     0,     0,     0,     0,   105,
     106,   107,     0,     0,     0,   571,     0,     0,     0,   114,
       0,     0,   117,     0,     0,     0,   118,   119,     0,     0,
     122,   123,     0,   523,     0,   126,     0,     0,     0,     0,
       0,   524,   525,   131,     0,     0,     0,     0,     0,     0,
     526,     0,     0,     0,     0,     0,     0,   139,     0,   140,
       0,     0,     0,   144,   145,   146,   147,   148,   149,   150,
       0,     0,     0,     0,   153,     0,   427,     0,   156,     0,
     158,   159,   160,     0,     0,   163,   164,   165,   166,   528,
     611,   529,   170,   530,   531,   173,   174,   175,     0,   177,
     178,   532,   180,   533,   534,   535,   184,   185,     0,   537,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,     0,     0,   201,   539,   203,     0,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,     0,   252,     0,   612,
       0,   255,     9,    10,     0,     0,     0,     0,     0,     0,
     424,   425,     0,    16,    17,    18,     0,    20,    21,    22,
     499,     0,     0,   501,   502,     0,   426,    30,   504,    32,
       0,    34,     0,    35,    36,    37,    38,     0,    40,     0,
       0,    43,    44,    45,    46,   506,     0,    48,     0,    50,
       0,     0,    53,   510,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,   511,   512,
      71,     0,    72,    73,    74,     0,     0,     0,    77,    78,
      79,     0,     0,   514,    81,     0,     0,     0,     0,    83,
     515,    85,   516,   517,    88,    89,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    94,    95,    96,    97,     0,
      98,     0,     0,     0,   518,   100,   101,   519,   520,     0,
       0,     0,     0,     0,     0,   104,   105,   106,     0,   108,
     109,     0,     0,     0,     0,     0,     0,     0,   116,   521,
       0,     0,     0,   118,   119,   120,   121,   522,   123,   124,
     523,     0,     0,     0,     0,     0,     0,     0,   524,   525,
     131,     0,     0,     0,   132,     0,   133,   526,     0,     0,
       0,     0,     0,     0,   139,     0,   140,   141,   142,   143,
     527,   145,   146,   147,   148,   149,   150,     0,     0,     0,
     152,     0,     0,   427,     0,   156,   157,     0,     0,     0,
     161,   162,   163,   164,   165,   166,   528,     0,   529,   170,
     530,   531,   173,   174,   175,   176,   177,   178,   532,   180,
     533,   534,   535,   184,   185,     0,   537,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   538,
       0,   201,   539,   203,     0,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,     0,     0,     0,     0,     0,     0,   255
  };

  /* YYCHECK.  */
  const short int
  jsoniq_parser::yycheck_[] =
  {
         0,   187,    14,   717,   319,     5,     6,     7,     8,     5,
       6,     7,  1088,   437,   854,     5,     6,     7,     8,   809,
       0,   137,   298,   701,  1328,     5,     6,     7,     8,   167,
     435,   436,   822,   171,   702,   703,   704,   705,     5,     6,
       7,     8,   350,  1072,   266,   890,   836,   202,   472,   473,
    1346,    76,   729,  1178,   956,   957,   645,   646,   794,   943,
     169,     1,     1,  1114,   985,    90,   794,   259,   260,    76,
     751,  1547,   267,  1035,  1550,  1413,  1414,    27,    28,    36,
     643,   644,   645,   646,   643,   644,    39,   282,  1053,   114,
      56,    44,    45,  1001,     8,    36,  1359,    47,   119,     1,
      53,   126,  1460,   128,    97,   144,   108,    60,   289,    62,
      63,   111,     0,     1,    30,     1,   149,     1,    71,    30,
       1,   111,   956,   957,     1,    75,   123,    27,    28,   101,
       1,   111,    94,     1,   680,     1,   682,   683,    95,   685,
      97,   687,   167,     1,   111,    98,   171,    47,   108,   695,
     696,     1,   108,  1055,   430,    97,    97,    57,   434,    31,
    1062,     1,  1723,   113,  1661,     1,     1,  1001,   108,   108,
     138,     1,   108,   155,     1,    75,    95,   170,    37,    38,
      80,    40,    41,     1,   155,     1,     1,   189,    33,   112,
     113,    97,   149,   170,   158,   150,    97,    52,    97,    58,
      97,  1035,   119,   114,    49,   108,   119,   178,   149,   230,
       1,   166,   112,   113,   114,   187,   158,  1007,    33,     1,
     108,  1055,   184,    30,     1,   158,   203,     1,  1062,   211,
     149,   191,     1,   189,   202,   108,    45,   353,     1,   278,
    1801,   238,   108,   149,   108,   278,   162,     0,     1,  1325,
     108,   162,   188,   219,    63,   114,  1594,  1561,   108,   259,
     260,   576,   176,   263,   257,   258,     1,   260,   108,   170,
    1110,  1061,   108,   108,   267,   456,   131,   230,   108,   259,
     260,   108,  1311,   263,   277,   188,  1194,   563,   162,   191,
     108,   312,   108,   259,  1178,  1179,   289,   185,   298,  1350,
    1776,  1564,  1660,   162,   111,   191,   987,   191,  1359,  1230,
     191,  1436,   901,   902,   191,  1812,  1278,   108,   298,   126,
     191,   278,  1287,   191,  1060,  1233,   108,   185,   251,   252,
    1058,   108,  1060,   358,   108,   185,   361,   278,   762,   108,
     899,   900,   292,   215,   151,   108,  1074,  1823,   188,  1825,
     300,   358,   188,   188,   361,   108,   257,   258,   188,   260,
    1194,   188,   261,   262,   261,   278,   225,   240,   186,   322,
     323,   324,   188,   108,   238,   298,   277,   316,   318,   188,
    1170,   119,    77,   807,   108,   133,   662,    55,   289,    57,
       1,   149,   292,   939,    27,    28,     1,   188,    95,  1233,
     300,  1303,     1,   101,   108,   101,   188,   266,   308,   108,
     119,   188,   186,   220,   221,   222,   441,   442,     1,   188,
     445,   643,   644,  1761,   449,   188,     1,   452,   453,     1,
     430,   158,   185,   101,   434,   460,    45,     1,    47,     1,
     632,   466,   467,   191,  1278,   640,   641,   123,   108,   474,
     430,     1,   155,   188,   434,   650,   481,   482,   483,   484,
     155,   461,   230,   463,   489,   603,     3,   235,    95,  1303,
     624,   461,   497,   463,   612,   119,   219,  1815,     5,   188,
     113,   461,     9,   463,   188,   485,   185,  1277,   167,   187,
     490,   187,   155,  1327,   461,   485,   463,   108,   107,   608,
     490,   139,  1798,   108,   183,   485,   144,   430,   211,   108,
     490,   434,   160,  1564,   238,   178,   259,     5,   485,   544,
     278,     9,   676,   490,   679,   108,   223,   224,   188,   177,
      67,   226,   227,   108,   559,    72,   108,   108,   943,  1843,
     155,   238,   465,   187,   108,   570,   108,   470,   158,   108,
    1395,   319,  1436,  1289,  1399,  1232,     9,   480,   108,  1273,
     169,  1445,   238,   563,   487,   488,  1468,  1156,  1157,  1158,
    1298,   571,  1456,   496,   185,   980,    29,   158,   603,   158,
     185,   571,   119,   563,  1008,  1009,   185,   612,   256,  1013,
     108,   571,   617,  1156,  1157,  1158,   223,   224,   125,   624,
     127,   269,   185,   271,   571,   721,   722,     1,   135,     3,
     185,   238,   888,   185,   282,   283,   284,   188,   286,  1043,
     288,   185,   622,   185,   132,   158,   638,  1417,   155,   188,
      95,   108,   632,    97,  1468,   185,   160,   125,   108,   127,
     563,   917,   622,   643,   644,   645,   646,   135,   158,  1678,
     114,   676,   632,   177,   132,   622,   119,   580,   581,     9,
      95,   133,   662,   643,   644,   645,   646,   155,   591,    95,
     188,   202,   125,    67,   127,    27,    28,   899,    72,    29,
     211,   107,   662,   136,   149,    37,    38,    97,    40,    41,
     198,    45,   108,    47,   158,    47,   108,   121,   621,   622,
     121,    30,   155,    95,   729,    57,    58,   146,    42,   144,
     905,   188,    46,  1547,   909,   118,  1550,    51,   188,   191,
     198,  1797,  1562,    75,   187,   119,    80,  1567,    80,   121,
     755,   160,   156,   758,   158,   156,    70,   158,   177,   149,
      42,   879,    95,   107,    46,   148,  1630,   772,   177,    51,
     274,   776,   777,   107,   192,   193,   195,   281,   161,    95,
     112,   113,   114,   158,   156,   129,   158,   291,    70,  1447,
     795,   200,   188,  1178,  1179,   125,   188,   127,   803,     9,
      10,   806,   111,  1519,   158,   810,   136,    97,   187,  1691,
    1504,   144,   195,    54,   160,   718,    54,   126,    59,   799,
     723,    59,   183,   799,   114,   155,   147,   730,   144,   799,
     162,   177,   211,  1402,   119,   169,   197,   158,   242,   799,
      78,   242,   151,     1,    25,     3,   155,     1,   853,   158,
     830,   831,   799,    34,   200,   169,    97,   124,   172,    97,
     830,   831,  1744,    42,  1746,   252,   253,    46,   158,   178,
     830,   831,    51,   187,   879,    95,    95,  1691,    30,    33,
      61,   119,  1702,   830,   831,   890,  1706,   169,   275,  1145,
     172,    70,  1180,   225,   104,    49,   138,     9,    10,   213,
     187,   121,  1306,   647,   183,   187,   150,   651,   888,    67,
     152,   220,   221,   222,    72,   125,   921,   127,   197,   911,
     139,   121,   166,   187,   211,   144,   931,  1809,   888,   998,
    1744,   213,  1746,    97,   266,   124,   156,   917,   158,  1788,
    1789,  1010,   845,   846,   847,   155,   849,   211,   262,   159,
     114,   956,   957,   958,   959,   264,   156,   917,   158,   111,
     292,   119,  1776,  1621,  1622,   175,  1614,   124,   300,  1663,
     187,  1146,  1792,   187,   126,  1049,   308,  1051,  1153,   139,
     262,  1830,   273,  1149,   144,   888,   196,  1836,   187,   280,
     169,  1761,   104,   172,   211,  1809,  1001,   211,   155,   151,
     274,   158,   124,   155,   214,  1409,   158,   281,   187,  1823,
    1015,  1825,   211,   125,  1418,   127,   139,   291,     9,    10,
      96,  1095,  1140,  1097,   139,   268,   178,   124,   304,   101,
     724,   107,   155,   727,   213,  1040,   279,   313,   732,   101,
     155,   117,   114,   155,  1049,   101,  1051,   159,  1053,  1305,
    1055,  1436,   114,   129,     9,    10,    54,  1062,   114,   124,
    1445,    59,   268,   175,   967,   101,   101,   101,   220,   221,
     222,  1456,  1766,   279,  1732,  1733,   699,   700,   114,   114,
     114,   130,   131,   262,   196,   282,   283,   284,   130,   131,
    1095,   288,  1097,   124,   155,   155,   124,   158,   158,  1394,
     155,   155,   214,   158,   158,   357,   124,   237,   360,   239,
    1090,   155,   237,   104,   239,   155,    90,  1271,  1272,  1813,
    1090,   226,   227,   228,  1528,   706,   707,   124,   708,   709,
    1090,  1651,  1652,   155,   125,  1140,   127,   111,   124,   124,
     114,   218,   158,  1090,   218,   246,   119,  1805,   246,   104,
     158,   247,   126,   155,   128,     0,   168,    93,   191,   254,
     100,  1166,    50,  1155,   155,  1145,   103,   102,   159,   201,
     125,   194,   127,   156,   158,   185,  1156,  1157,  1158,   185,
     185,   185,    30,    47,   175,  1145,   154,   119,   251,  1194,
     309,  1885,   188,  1887,   155,   169,  1156,  1157,  1158,     1,
     155,   119,   144,  1897,   159,   196,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,   108,   188,   188,   158,
     175,   134,   155,   214,   155,  1391,   185,   144,  1233,   142,
     143,   158,   145,   158,   158,   158,   123,   123,   158,   158,
     153,   196,   158,   155,   157,  1630,   159,    35,    17,   215,
      30,   164,    30,   155,   155,   155,   155,   155,   236,   214,
     235,   191,   191,   250,     3,   119,   238,   180,   171,   289,
     289,    71,   169,   119,  1177,   171,   236,    95,    95,    95,
     188,   151,  1287,   108,  1540,   108,  1291,    30,   162,   162,
     129,   204,   205,   206,   207,   208,   209,   134,  1303,   251,
      95,  1281,   144,   304,   119,  1281,   134,   185,   185,   188,
     108,  1281,  1317,    95,    97,    45,   188,   188,    97,   188,
     188,  1281,  1327,   188,   185,  1305,   155,   185,    95,   236,
     144,  1587,   242,   238,  1281,   191,  1316,    33,   171,   144,
    1316,   134,    95,    30,   291,  1305,  1316,   232,    95,   155,
     304,   119,  1357,   129,   119,  1335,  1316,   149,    95,  1335,
     134,   185,   134,   199,    97,  1335,   162,   119,   155,  1316,
     101,   155,   149,   101,   185,  1335,  1356,   185,   144,   191,
    1385,   123,   123,  1363,    35,   155,  1356,    30,  1335,    30,
    1395,    97,   119,  1363,  1399,   250,  1356,    80,   108,   107,
     259,   108,   265,  1363,   158,   272,   290,   158,   158,  1356,
     263,    30,   158,   158,   158,   291,  1363,   146,  1398,    30,
    1676,    30,  1427,   158,   146,   232,   292,   191,   311,   188,
     188,  1687,  1688,   188,  1690,   149,   129,   149,  1398,   188,
     108,   144,  1698,   199,   101,   185,   134,     7,   238,   238,
     188,  1398,   188,   238,   158,    97,   242,   191,   158,   191,
     158,   321,   187,  1468,   155,   238,   119,   107,   442,   149,
     119,   445,    78,   188,   255,   449,   149,   287,   452,   453,
     255,    79,   291,   188,    30,    30,   460,   188,   108,   188,
     171,   188,   466,   467,   188,  1500,   188,   149,   188,   262,
     474,   185,   149,   128,   128,   276,    97,   481,   482,   483,
     484,   185,   187,   185,   144,   489,   187,   187,   185,   185,
     321,   185,   155,   497,   285,    95,   188,    30,    97,  1785,
     188,   149,   292,   171,    95,   198,    54,    95,    30,  1544,
     108,   108,  1547,   119,   270,  1550,    95,    95,   230,   199,
     187,   230,   198,   198,   119,   119,   187,    94,  1563,   198,
    1540,   184,   310,  1568,   119,   119,   187,   119,  1824,   230,
     544,   200,  1234,   761,   298,   292,  1002,   263,   263,   436,
    1540,  1063,  1278,  1766,  1813,   559,  1842,   310,   266,   310,
     891,   311,   311,   311,   456,  1607,   570,   571,  1175,  1604,
    1605,  1857,  1428,   812,  1162,  1416,  1420,  1587,  1413,   559,
    1322,  1317,  1325,  1330,   678,   698,   959,   735,   729,  1350,
     854,  1836,  1830,  1879,   464,  1385,   464,  1587,  1051,   345,
    1396,  1395,  1888,  1445,   608,  1456,   111,  1630,  1179,  1627,
    1449,  1188,  1256,   617,  1494,  1034,  1654,  1446,    -1,    -1,
     624,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1584,  1585,  1586,    -1,    -1,  1691,  1692,    -1,  1694,
      -1,  1696,    -1,    -1,   169,    -1,  1676,    -1,  1703,    -1,
      -1,    -1,   676,    -1,    -1,    -1,    -1,  1687,  1688,    -1,
    1690,    -1,    -1,    -1,    -1,    -1,  1676,    -1,  1698,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1687,  1688,    -1,
    1690,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1698,  1744,
      -1,  1746,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   729,    -1,  1762,    -1,    -1,
    1765,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1776,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   254,
      -1,    -1,  1787,    -1,   758,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   772,    -1,
      -1,    -1,   776,   777,  1809,  1785,    -1,    -1,    -1,    -1,
      -1,    -1,  1817,    -1,    -1,    -1,    -1,  1720,  1823,    -1,
    1825,   795,    -1,    -1,    -1,  1785,    -1,    -1,    -1,   803,
      -1,    -1,   806,    -1,    -1,    -1,   810,    -1,    -1,  1742,
      -1,  1846,    -1,    -1,  1824,    -1,    -1,    -1,    -1,    -1,
    1855,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1842,    -1,  1824,    -1,    -1,    -1,   842,    -1,
    1875,    -1,    -1,    -1,    -1,  1880,    -1,  1857,    -1,   853,
      -1,    -1,  1842,    -1,    -1,    -1,    -1,  1892,    -1,    -1,
    1895,    -1,    -1,    -1,    -1,    -1,    -1,  1857,    -1,  1879,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1888,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1879,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1888,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   921,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   931,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   956,   957,   958,   959,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1001,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1015,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1040,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1049,    -1,  1051,    -1,  1053,
      -1,  1055,    -1,    -1,    -1,    -1,    -1,    -1,  1062,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   571,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1095,    -1,  1097,    -1,    -1,   601,   602,    -1,    -1,
      -1,   606,   607,   608,    -1,    -1,   611,    -1,    -1,   614,
      -1,    -1,    -1,    -1,    -1,   620,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   630,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   653,   654,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   662,   663,    -1,
      -1,    -1,  1166,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1194,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   731,    -1,    -1,  1233,
     735,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   774,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1287,    -1,    -1,    -1,  1291,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1303,
      -1,    -1,    -1,    -1,    -1,    -1,   811,    -1,    -1,    -1,
      -1,    -1,    -1,  1317,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1327,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   837,    -1,    -1,    -1,   841,   842,    -1,   844,
      -1,    -1,    -1,    -1,    -1,    -1,   851,    -1,    -1,    -1,
      -1,    -1,    -1,  1357,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   873,   874,
      -1,    -1,   877,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1385,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   897,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   917,    -1,    -1,    -1,    -1,    -1,   923,   924,
      -1,    -1,    -1,  1427,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1468,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1500,    -1,  1003,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1038,    -1,    -1,    -1,    -1,    -1,    -1,
    1544,    -1,    -1,  1547,    -1,    -1,  1550,    -1,    -1,    -1,
      -1,    -1,  1057,    -1,    -1,    -1,    -1,    -1,    -1,  1563,
      -1,    -1,    -1,    -1,  1568,    -1,    -1,    -1,  1073,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1084,
    1085,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1099,    -1,    -1,  1102,    -1,    -1,
    1604,  1605,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1123,  1124,
    1125,    -1,  1127,  1128,  1129,  1130,  1131,    -1,    -1,  1134,
    1135,    -1,  1137,  1138,    -1,    -1,    -1,  1142,  1143,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1151,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1162,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1691,  1692,    -1,
    1694,    -1,  1696,    -1,    -1,    -1,    -1,    -1,    -1,  1703,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1220,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1744,    -1,  1746,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1762,    -1,
      -1,  1765,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1776,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1787,    -1,    -1,    -1,    -1,  1293,    -1,
    1295,    -1,  1297,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1305,    -1,    -1,    -1,    -1,  1809,    -1,    -1,    -1,  1314,
      -1,    -1,    -1,  1817,    -1,  1320,  1321,    -1,    -1,  1823,
      -1,  1825,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1339,    -1,    -1,  1342,  1343,    -1,
      -1,    -1,  1846,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1855,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1875,    -1,    -1,    -1,    -1,  1880,    -1,  1383,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1892,    -1,
      -1,  1895,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1416,    -1,    -1,    -1,  1420,  1421,    -1,    -1,    -1,
      -1,  1426,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1513,    -1,
      -1,    -1,  1517,    -1,    -1,    -1,  1521,    -1,  1523,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1531,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1539,  1540,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1560,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1573,  1574,
    1575,  1576,    -1,  1578,  1579,    -1,  1581,    -1,  1583,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1598,    -1,    -1,    -1,    -1,  1603,    -1,
      -1,    -1,    -1,    -1,  1609,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1669,    -1,  1671,    -1,    -1,  1674,
      -1,    -1,  1677,    -1,    -1,    -1,    -1,  1682,  1683,    -1,
      -1,    -1,    -1,    -1,    -1,  1690,    -1,    -1,    -1,    -1,
    1695,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1712,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1724,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1769,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1781,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1824,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     0,     1,    -1,    -1,    -1,    -1,  1853,    -1,
      -1,    -1,  1857,    11,    12,    -1,    -1,  1862,    16,    -1,
      -1,    -1,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    -1,    30,  1878,    -1,    33,    34,  1882,    36,    37,
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
      -1,   189,   190,   191,   192,   193,    -1,   195,    -1,   197,
      -1,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,    -1,    -1,   212,   213,   214,    -1,   216,    -1,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,    -1,   264,   265,   266,    -1,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,    -1,   317,
      -1,   319,   320,   321,    -1,   323,   324,   325,     0,     1,
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
     192,   193,    -1,   195,    -1,   197,    -1,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,    -1,    -1,
     212,   213,   214,    -1,   216,    -1,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,    -1,   264,   265,   266,    -1,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,     1,   317,    -1,   319,   320,   321,
      -1,   323,   324,   325,    11,    12,    -1,    -1,    -1,    16,
      -1,    -1,    -1,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    -1,    30,    -1,    -1,    33,    34,    -1,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    -1,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    -1,    95,    96,
      97,    98,    99,    -1,   101,   102,   103,    -1,    -1,   106,
     107,    -1,    -1,    -1,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,    -1,   122,    -1,    -1,    -1,   126,
      -1,   128,   129,   130,   131,    -1,   133,    -1,    -1,    -1,
     137,   138,   139,   140,   141,    -1,    -1,    -1,    -1,    -1,
      -1,   148,   149,   150,   151,   152,   153,   154,   155,   156,
      -1,   158,   159,   160,   161,   162,    -1,    -1,    -1,   166,
     167,   168,   169,   170,   171,   172,   173,    -1,   175,    -1,
     177,   178,    -1,    -1,   181,   182,   183,    -1,    -1,    -1,
     187,    -1,   189,   190,   191,   192,   193,    -1,   195,    -1,
     197,    -1,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,    -1,    -1,   212,   213,   214,    -1,   216,
      -1,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   262,    -1,   264,   265,   266,
      -1,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,     1,
     317,    -1,   319,   320,   321,    -1,   323,   324,   325,    11,
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
     182,   183,    -1,    -1,    -1,   187,    -1,   189,   190,    -1,
     192,   193,    -1,   195,    -1,   197,    -1,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,    -1,    -1,
     212,   213,   214,    -1,   216,    -1,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,    -1,   264,   265,   266,    -1,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,    -1,   317,    -1,   319,   320,   321,
      -1,   323,   324,   325,     0,     1,    -1,     3,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    42,    -1,    -1,    -1,
      46,    -1,    -1,    -1,    50,    51,    -1,    -1,    -1,    -1,
      56,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    67,    -1,    -1,    70,    -1,    72,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    93,    -1,    95,
      96,    97,    -1,    -1,   100,   101,   102,   103,    -1,    -1,
      -1,   107,   108,    -1,    -1,    -1,    -1,    -1,   114,    -1,
      -1,   117,   118,   119,    -1,    -1,    -1,   123,    -1,    -1,
      -1,    -1,   128,   129,    -1,    -1,    -1,    -1,   134,    -1,
      -1,    -1,   138,    -1,    -1,    -1,   142,   143,    -1,   145,
      -1,   147,   148,    -1,    -1,    -1,   152,   153,    -1,    -1,
     156,   157,   158,   159,   160,   161,    -1,    -1,   164,    -1,
      -1,    -1,   168,   169,    -1,    -1,   172,    -1,    -1,    -1,
      -1,   177,    -1,    -1,   180,    -1,    -1,    -1,    -1,   185,
     186,   187,   188,   189,    -1,   191,   192,   193,   194,   195,
      -1,    -1,    -1,    -1,   200,   201,   202,    -1,   204,   205,
     206,   207,   208,   209,    -1,   211,    -1,   213,    -1,    -1,
      -1,    -1,    -1,   219,    -1,    -1,    -1,   223,   224,    -1,
       0,     1,    -1,     3,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   238,    -1,   240,    -1,   242,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   254,    -1,
      -1,    -1,    -1,   259,    -1,    -1,   262,    -1,    -1,    -1,
      -1,    -1,    42,    -1,    -1,    -1,    46,    -1,    -1,    -1,
      50,    51,    -1,    -1,    -1,    -1,    56,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    67,    -1,    -1,
      70,    -1,    72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     316,    -1,   318,    93,    -1,    95,    96,    97,    -1,    -1,
     100,   101,   102,   103,    -1,    -1,    -1,   107,   108,    -1,
      -1,    -1,    -1,    -1,   114,    -1,    -1,   117,   118,   119,
      -1,    -1,    -1,   123,    -1,    -1,    -1,    -1,   128,   129,
      -1,    -1,    -1,    -1,   134,    -1,    -1,    -1,   138,    -1,
      -1,    -1,   142,   143,    -1,   145,    -1,   147,   148,    -1,
      -1,    -1,   152,   153,    -1,    -1,   156,   157,   158,   159,
     160,   161,    -1,    -1,   164,    -1,    -1,    -1,   168,   169,
      -1,    -1,   172,    -1,    -1,    -1,    -1,   177,    -1,    -1,
     180,    -1,    -1,    -1,    -1,   185,   186,   187,   188,   189,
      -1,   191,   192,   193,   194,   195,    -1,    -1,    -1,    -1,
     200,   201,   202,    -1,   204,   205,   206,   207,   208,   209,
      -1,   211,    -1,   213,    -1,    -1,    -1,    -1,    -1,   219,
      -1,    -1,    -1,   223,   224,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   238,    -1,
     240,    -1,   242,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   254,    -1,    -1,    -1,    -1,   259,
      -1,    -1,   262,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    11,    12,
      -1,    -1,    -1,    16,    -1,    -1,    -1,    20,    21,    22,
      23,    24,    25,    26,    27,    28,   316,    30,   318,    -1,
      33,    34,    -1,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    -1,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    -1,    95,    96,    97,    98,    99,    -1,   101,   102,
     103,    -1,    -1,   106,   107,    -1,    -1,    -1,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,    -1,   122,
      -1,    -1,    -1,   126,    -1,   128,   129,   130,   131,    -1,
     133,    -1,    -1,    -1,   137,   138,   139,   140,   141,    -1,
      -1,    -1,    -1,    -1,    -1,   148,   149,   150,   151,   152,
     153,   154,   155,   156,    -1,   158,   159,   160,   161,   162,
      -1,    -1,    -1,   166,   167,   168,   169,   170,   171,   172,
     173,    -1,   175,    -1,   177,   178,    -1,    -1,   181,   182,
     183,    -1,    -1,    -1,   187,    -1,   189,   190,   191,   192,
     193,    -1,   195,    -1,   197,    -1,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,    -1,    -1,   212,
     213,   214,    -1,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
      -1,   264,   265,   266,    -1,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,    -1,   317,    -1,   319,   320,   321,    -1,
     323,   324,   325,   326,   327,    11,    12,    -1,    -1,    -1,
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
      -1,   187,    -1,   189,   190,   191,   192,   193,    -1,   195,
      -1,   197,    -1,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,    -1,    -1,   212,   213,   214,    -1,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,    -1,   264,   265,
     266,    -1,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
      -1,   317,    -1,   319,   320,   321,    -1,   323,   324,   325,
      -1,   327,    11,    12,    -1,    -1,    -1,    16,    -1,    -1,
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
     119,   120,    -1,   122,    -1,    -1,    -1,   126,    -1,   128,
     129,   130,   131,    -1,   133,    -1,    -1,    -1,   137,   138,
     139,   140,   141,    -1,    -1,    -1,    -1,    -1,    -1,   148,
     149,   150,   151,   152,   153,   154,   155,   156,    -1,   158,
     159,   160,   161,   162,    -1,    -1,    -1,   166,   167,   168,
     169,   170,   171,   172,   173,    -1,   175,    -1,   177,   178,
      -1,    -1,   181,   182,   183,    -1,    -1,    -1,   187,    -1,
     189,   190,   191,   192,   193,    -1,   195,    -1,   197,    -1,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,    -1,    -1,   212,   213,   214,    -1,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   262,    -1,   264,   265,   266,    -1,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,    -1,   317,    -1,
     319,   320,   321,    -1,   323,   324,   325,    11,    12,    -1,
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
      -1,   185,    -1,   187,    -1,   189,   190,   191,   192,   193,
      -1,   195,    -1,   197,    -1,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,    -1,    -1,   212,   213,
     214,    -1,   216,    -1,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,    -1,
     264,   265,   266,    -1,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,    -1,   317,    -1,   319,   320,   321,    -1,   323,
     324,   325,    11,    12,    -1,    -1,    -1,    16,    -1,    -1,
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
     119,   120,    -1,   122,    -1,    -1,    -1,   126,    -1,   128,
     129,   130,   131,    -1,   133,    -1,    -1,    -1,   137,   138,
     139,   140,   141,    -1,    -1,    -1,    -1,    -1,    -1,   148,
     149,   150,   151,   152,   153,   154,   155,   156,    -1,   158,
     159,   160,   161,   162,    -1,    -1,    -1,   166,   167,   168,
     169,   170,   171,   172,   173,    -1,   175,    -1,   177,   178,
      -1,    -1,   181,   182,   183,    -1,    -1,    -1,   187,    -1,
     189,   190,   191,   192,   193,    -1,   195,    -1,   197,    -1,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,    -1,    -1,   212,   213,   214,    -1,   216,    -1,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   262,    -1,   264,   265,   266,    -1,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,    -1,   317,    -1,
     319,   320,   321,    -1,   323,   324,   325,    11,    12,    -1,
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
      -1,   195,    -1,   197,    -1,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,    -1,    -1,   212,   213,
     214,    -1,   216,    -1,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,    -1,
     264,   265,   266,    -1,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,    -1,   317,    -1,   319,   320,   321,    -1,   323,
     324,   325,    11,    12,    -1,    -1,    -1,    16,    -1,    -1,
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
     119,   120,    -1,   122,    -1,    -1,    -1,   126,    -1,   128,
     129,   130,   131,    -1,   133,    -1,    -1,    -1,   137,   138,
     139,   140,   141,    -1,    -1,    -1,    -1,    -1,    -1,   148,
     149,   150,   151,   152,   153,   154,   155,   156,    -1,   158,
     159,   160,   161,   162,    -1,    -1,    -1,   166,   167,   168,
     169,   170,   171,   172,   173,    -1,   175,    -1,   177,   178,
      -1,    -1,   181,   182,   183,    -1,    -1,    -1,   187,    -1,
     189,   190,   191,   192,   193,    -1,   195,    -1,   197,    -1,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,    -1,    -1,   212,   213,   214,    -1,   216,    -1,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   262,    -1,   264,   265,   266,    -1,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,    -1,   317,    -1,
     319,   320,   321,    -1,   323,   324,   325,    11,    12,    -1,
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
      -1,   195,    -1,   197,    -1,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,    -1,    -1,   212,   213,
     214,    -1,   216,    -1,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,    -1,
     264,   265,   266,    -1,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,    -1,   317,    -1,   319,   320,   321,    -1,   323,
     324,   325,    11,    12,    -1,    -1,    -1,    16,    -1,    -1,
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
     119,   120,    -1,   122,    -1,    -1,    -1,   126,    -1,   128,
     129,   130,   131,    -1,   133,    -1,    -1,    -1,   137,   138,
     139,   140,   141,    -1,    -1,    -1,    -1,    -1,    -1,   148,
     149,   150,   151,   152,   153,   154,   155,   156,    -1,   158,
     159,   160,   161,   162,    -1,    -1,    -1,   166,   167,   168,
     169,   170,   171,   172,   173,    -1,   175,    -1,   177,   178,
      -1,    -1,   181,   182,   183,    -1,    -1,    -1,   187,    -1,
     189,   190,   191,   192,   193,    -1,   195,    -1,   197,    -1,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,    -1,    -1,   212,   213,   214,    -1,   216,    -1,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   262,    -1,   264,   265,   266,    -1,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,    -1,   317,    -1,
     319,   320,   321,    -1,   323,   324,   325,    11,    12,    -1,
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
      -1,    -1,    -1,   187,   188,   189,   190,    -1,   192,   193,
      -1,   195,    -1,   197,    -1,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,    -1,    -1,   212,   213,
     214,    -1,   216,    -1,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,    -1,
     264,   265,   266,    -1,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,    -1,   317,    -1,   319,   320,   321,    -1,   323,
     324,   325,    11,    12,    -1,    -1,    -1,    16,    -1,    -1,
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
     119,   120,    -1,   122,    -1,    -1,    -1,   126,    -1,   128,
     129,   130,   131,    -1,   133,    -1,    -1,    -1,   137,   138,
     139,   140,   141,    -1,    -1,    -1,    -1,   146,    -1,   148,
     149,   150,   151,   152,   153,   154,   155,   156,    -1,   158,
     159,   160,   161,   162,    -1,    -1,    -1,   166,   167,   168,
     169,   170,   171,   172,   173,    -1,   175,    -1,   177,   178,
      -1,    -1,   181,   182,   183,    -1,    -1,    -1,   187,   188,
     189,   190,    -1,   192,   193,    -1,   195,    -1,   197,    -1,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,    -1,    -1,   212,   213,   214,    -1,   216,    -1,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   262,    -1,   264,   265,   266,    -1,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,    -1,   317,    -1,
     319,   320,   321,    -1,   323,   324,   325,    11,    12,    -1,
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
      -1,    -1,   186,   187,    -1,   189,   190,    -1,   192,   193,
      -1,   195,    -1,   197,    -1,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,    -1,    -1,   212,   213,
     214,    -1,   216,    -1,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,    -1,
     264,   265,   266,    -1,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,    -1,   317,    -1,   319,   320,   321,    -1,   323,
     324,   325,    11,    12,    -1,    -1,    -1,    16,    -1,    -1,
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
     119,   120,    -1,   122,    -1,    -1,    -1,   126,    -1,   128,
     129,   130,   131,    -1,   133,    -1,    -1,    -1,   137,   138,
     139,   140,   141,    -1,    -1,    -1,    -1,    -1,    -1,   148,
     149,   150,   151,   152,   153,   154,   155,   156,    -1,   158,
     159,   160,   161,   162,    -1,    -1,    -1,   166,   167,   168,
     169,   170,   171,   172,   173,    -1,   175,    -1,   177,   178,
      -1,    -1,   181,   182,   183,    -1,    -1,    -1,   187,   188,
     189,   190,    -1,   192,   193,    -1,   195,    -1,   197,    -1,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,    -1,    -1,   212,   213,   214,    -1,   216,    -1,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   262,    -1,   264,   265,   266,    -1,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,    -1,   317,    -1,
     319,   320,   321,    -1,   323,   324,   325,    11,    12,    -1,
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
      -1,    -1,    -1,   187,    -1,   189,   190,    -1,   192,   193,
      -1,   195,    -1,   197,    -1,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,    -1,    -1,   212,   213,
     214,    -1,   216,    -1,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,    -1,
     264,   265,   266,    -1,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,   317,    -1,   319,   320,   321,    -1,   323,
     324,   325,    11,    12,    -1,    -1,    -1,    16,    -1,    -1,
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
     119,   120,    -1,   122,    -1,    -1,    -1,   126,    -1,   128,
     129,   130,   131,    -1,   133,    -1,    -1,    -1,   137,   138,
     139,   140,   141,    -1,    -1,    -1,    -1,    -1,    -1,   148,
     149,   150,   151,   152,   153,   154,   155,   156,    -1,   158,
     159,   160,   161,   162,    -1,    -1,    -1,   166,   167,   168,
     169,   170,   171,   172,   173,    -1,   175,    -1,   177,   178,
      -1,    -1,   181,   182,   183,    -1,    -1,    -1,   187,    -1,
     189,   190,    -1,   192,   193,    -1,   195,    -1,   197,    -1,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,    -1,    -1,   212,   213,   214,    -1,   216,    -1,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   262,    -1,   264,   265,   266,    -1,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,    -1,   317,   318,
     319,   320,   321,    -1,   323,   324,   325,    11,    12,    -1,
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
      -1,   185,    -1,   187,    -1,   189,   190,    -1,   192,   193,
      -1,   195,    -1,   197,    -1,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,    -1,    -1,   212,   213,
     214,    -1,   216,    -1,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,    -1,
     264,   265,   266,    -1,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,    -1,   317,    -1,   319,   320,   321,    -1,   323,
     324,   325,    11,    12,    -1,    -1,    -1,    16,    -1,    -1,
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
     119,   120,    -1,   122,    -1,    -1,    -1,   126,    -1,   128,
     129,   130,   131,    -1,   133,    -1,    -1,    -1,   137,   138,
     139,   140,   141,    -1,    -1,    -1,    -1,    -1,    -1,   148,
     149,   150,   151,   152,   153,   154,   155,   156,    -1,   158,
     159,   160,   161,   162,    -1,    -1,    -1,   166,   167,   168,
     169,   170,   171,   172,   173,    -1,   175,    -1,   177,   178,
      -1,    -1,   181,   182,   183,    -1,    -1,   186,   187,    -1,
     189,   190,    -1,   192,   193,    -1,   195,    -1,   197,    -1,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,    -1,    -1,   212,   213,   214,    -1,   216,    -1,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   262,    -1,   264,   265,   266,    -1,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,    -1,   317,    -1,
     319,   320,   321,    -1,   323,   324,   325,    11,    12,    -1,
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
      -1,    -1,    -1,   187,   188,   189,   190,    -1,   192,   193,
      -1,   195,    -1,   197,    -1,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,    -1,    -1,   212,   213,
     214,    -1,   216,    -1,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,    -1,
     264,   265,   266,    -1,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,    -1,   317,    -1,   319,   320,   321,    -1,   323,
     324,   325,    11,    12,    -1,    -1,    -1,    16,    -1,    -1,
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
     119,   120,    -1,   122,    -1,    -1,    -1,   126,    -1,   128,
     129,   130,   131,    -1,   133,    -1,    -1,    -1,   137,   138,
     139,   140,   141,    -1,    -1,    -1,    -1,   146,    -1,   148,
     149,   150,   151,   152,   153,   154,   155,   156,    -1,   158,
     159,   160,   161,   162,    -1,    -1,    -1,   166,   167,   168,
     169,   170,   171,   172,   173,    -1,   175,    -1,   177,   178,
      -1,    -1,   181,   182,   183,    -1,    -1,    -1,   187,    -1,
     189,   190,    -1,   192,   193,    -1,   195,    -1,   197,    -1,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,    -1,    -1,   212,   213,   214,    -1,   216,    -1,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   262,    -1,   264,   265,   266,    -1,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,    -1,   317,    -1,
     319,   320,   321,    -1,   323,   324,   325,    11,    12,    -1,
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
      -1,    -1,    -1,   187,    -1,   189,   190,    -1,   192,   193,
      -1,   195,    -1,   197,    -1,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,    -1,    -1,   212,   213,
     214,    -1,   216,    -1,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,    -1,
     264,   265,   266,    -1,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,    -1,   317,    -1,   319,   320,   321,    -1,   323,
     324,   325,    11,    12,    -1,    -1,    -1,    16,    -1,    -1,
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
     119,   120,    -1,   122,    -1,    -1,    -1,   126,    -1,   128,
     129,   130,   131,    -1,   133,    -1,    -1,    -1,   137,   138,
     139,   140,   141,    -1,    -1,    -1,    -1,    -1,    -1,   148,
     149,   150,   151,   152,   153,   154,   155,   156,    -1,   158,
     159,   160,   161,   162,    -1,    -1,    -1,   166,   167,   168,
     169,   170,   171,   172,   173,    -1,   175,    -1,   177,   178,
      -1,    -1,   181,   182,   183,    -1,    -1,    -1,   187,    -1,
     189,   190,    -1,   192,   193,    -1,   195,    -1,   197,    -1,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,    -1,    -1,   212,   213,   214,    -1,   216,    -1,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   262,    -1,   264,   265,   266,    -1,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,    -1,   317,    -1,
     319,   320,   321,    -1,   323,   324,   325,    11,    12,    -1,
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
      -1,    -1,    -1,   187,    -1,   189,   190,    -1,   192,   193,
      -1,   195,    -1,   197,    -1,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,    -1,    -1,   212,   213,
     214,    -1,   216,    -1,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,    -1,
     264,   265,   266,    -1,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,    -1,   317,    -1,   319,   320,   321,    -1,   323,
     324,   325,    11,    12,    -1,    -1,    -1,    16,    -1,    -1,
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
     119,   120,    -1,   122,    -1,    -1,    -1,   126,    -1,   128,
     129,   130,   131,    -1,   133,    -1,    -1,    -1,   137,   138,
     139,   140,   141,    -1,    -1,    -1,    -1,    -1,    -1,   148,
     149,   150,   151,   152,   153,   154,   155,   156,    -1,   158,
     159,   160,   161,   162,    -1,    -1,    -1,   166,   167,   168,
     169,   170,   171,   172,   173,    -1,   175,    -1,   177,   178,
      -1,    -1,   181,   182,   183,    -1,    -1,    -1,   187,    -1,
     189,   190,    -1,   192,   193,    -1,   195,    -1,   197,    -1,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,    -1,    -1,   212,   213,   214,    -1,   216,    -1,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   262,    -1,   264,   265,   266,    -1,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,    -1,   317,    -1,
     319,   320,   321,    -1,   323,   324,   325,    11,    12,    -1,
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
      -1,    -1,    -1,   187,    -1,   189,   190,    -1,   192,   193,
      -1,   195,    -1,   197,    -1,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,    -1,    -1,   212,   213,
     214,    -1,   216,    -1,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,    -1,
     264,   265,   266,    -1,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,    -1,   317,    -1,   319,   320,   321,    -1,   323,
     324,   325,    11,    12,    -1,    -1,    -1,    16,    -1,    -1,
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
     119,   120,    -1,   122,    -1,    -1,    -1,   126,    -1,   128,
     129,   130,   131,    -1,   133,    -1,    -1,    -1,   137,   138,
     139,   140,   141,    -1,    -1,    -1,    -1,    -1,    -1,   148,
     149,   150,   151,   152,   153,   154,   155,   156,    -1,    -1,
     159,   160,   161,   162,    -1,    -1,    -1,   166,   167,   168,
     169,   170,   171,   172,   173,    -1,   175,    -1,   177,   178,
      -1,    -1,   181,   182,   183,    -1,    -1,    -1,   187,    -1,
     189,   190,    -1,   192,   193,    -1,   195,    -1,   197,    -1,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,    -1,    -1,   212,   213,   214,    -1,   216,    -1,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   262,    -1,   264,   265,   266,    -1,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,    -1,   317,    -1,
     319,   320,   321,    -1,   323,   324,   325,    11,    12,    -1,
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
      -1,    -1,    -1,   187,    -1,   189,   190,    -1,   192,   193,
      -1,   195,    -1,   197,    -1,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,    -1,    -1,   212,   213,
     214,    -1,   216,    -1,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,    -1,
     264,   265,   266,    -1,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,    -1,   317,    -1,   319,   320,   321,    -1,   323,
     324,   325,    11,    12,    -1,    -1,    -1,    16,    -1,    -1,
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
     119,   120,    -1,   122,    -1,    -1,    -1,   126,    -1,   128,
     129,   130,   131,    -1,   133,    -1,    -1,    -1,   137,   138,
     139,   140,   141,    -1,    -1,    -1,    -1,    -1,    -1,   148,
     149,   150,   151,   152,   153,   154,   155,   156,    -1,   158,
     159,    -1,   161,   162,    -1,    -1,    -1,   166,   167,   168,
     169,   170,   171,   172,   173,    -1,   175,    -1,    -1,    -1,
      -1,    -1,   181,   182,   183,    -1,    -1,    -1,   187,    -1,
     189,   190,    -1,    -1,    -1,    -1,   195,    -1,   197,    -1,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,    -1,    -1,   212,   213,   214,    -1,   216,    -1,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   262,    -1,   264,   265,   266,    -1,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,    -1,   317,    -1,
     319,   320,   321,    -1,   323,   324,   325,    11,    12,    -1,
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
      -1,    -1,    -1,   137,    -1,   139,   140,   141,    -1,    -1,
      -1,    -1,    -1,    -1,   148,   149,   150,   151,    -1,   153,
     154,   155,   156,    -1,   158,   159,    -1,   161,   162,    -1,
      -1,    -1,   166,   167,   168,   169,   170,   171,   172,   173,
      -1,   175,    -1,    -1,    -1,    -1,    -1,   181,   182,   183,
      -1,    -1,    -1,   187,    -1,   189,   190,    -1,    -1,    -1,
      -1,   195,    -1,   197,    -1,   199,    -1,   201,    -1,   203,
     204,   205,   206,   207,   208,   209,    -1,    -1,   212,   213,
     214,    -1,   216,    -1,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,    -1,
     264,   265,   266,    -1,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,    -1,   317,    -1,   319,   320,   321,    -1,   323,
     324,   325,    11,    12,    -1,    -1,    -1,    16,    -1,    -1,
      -1,    20,    21,    22,    23,    24,    25,    26,    -1,    -1,
      -1,    30,    -1,    -1,    33,    34,    -1,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    -1,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    -1,    95,    96,    97,    98,
      99,    -1,   101,   102,   103,    -1,    -1,   106,   107,    -1,
      -1,    -1,   111,   112,   113,   114,   115,   116,   117,    -1,
     119,   120,    -1,   122,    -1,    -1,    -1,   126,    -1,   128,
     129,   130,   131,    -1,   133,    -1,    -1,    -1,   137,    -1,
     139,   140,   141,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     149,   150,   151,    -1,   153,   154,   155,    -1,    -1,   158,
     159,    -1,    -1,   162,    -1,    -1,    -1,   166,   167,   168,
     169,   170,   171,   172,   173,    -1,   175,    -1,    -1,   178,
      -1,    -1,   181,   182,   183,    -1,    -1,    -1,   187,    -1,
     189,   190,    -1,    -1,    -1,    -1,    -1,    -1,   197,    -1,
     199,    -1,   201,    -1,   203,   204,   205,   206,   207,   208,
     209,    -1,    -1,   212,   213,   214,    -1,   216,    -1,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   262,    -1,   264,   265,   266,    -1,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,    -1,   317,    -1,
     319,   320,   321,    -1,   323,   324,   325,    11,    12,    -1,
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
     114,   115,   116,   117,    -1,   119,   120,    -1,   122,    -1,
      -1,    -1,   126,    -1,   128,   129,   130,   131,    -1,   133,
      -1,    -1,    -1,   137,    -1,   139,   140,   141,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   149,   150,   151,    -1,   153,
     154,   155,    -1,    -1,    -1,   159,    -1,    -1,   162,    -1,
      -1,    -1,   166,   167,   168,   169,   170,   171,   172,   173,
      -1,   175,    -1,    -1,   178,    -1,    -1,   181,   182,   183,
      -1,    -1,    -1,   187,    -1,   189,   190,    -1,    -1,    -1,
      -1,    -1,    -1,   197,    -1,   199,    -1,   201,    -1,   203,
     204,   205,   206,   207,   208,   209,    -1,    -1,   212,   213,
     214,    -1,   216,    -1,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,    -1,
     264,   265,   266,    -1,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,    -1,   317,    -1,   319,   320,   321,    -1,   323,
     324,   325,    11,    12,    -1,    -1,    -1,    16,    -1,    -1,
      -1,    20,    21,    22,    23,    24,    25,    26,    -1,    -1,
      -1,    30,    -1,    -1,    33,    34,    -1,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    -1,    51,    52,    53,    54,    -1,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    -1,    -1,    95,    96,    97,    98,
      99,    -1,   101,    -1,    -1,    -1,    -1,   106,   107,    -1,
      -1,    -1,   111,   112,   113,   114,   115,   116,   117,    -1,
     119,   120,    -1,   122,    -1,    -1,    -1,   126,    -1,   128,
     129,   130,   131,    -1,   133,    -1,    -1,    -1,   137,    -1,
     139,   140,   141,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     149,   150,   151,    -1,   153,   154,   155,    -1,    -1,   158,
     159,    -1,    -1,   162,    -1,    -1,    -1,   166,   167,   168,
     169,   170,   171,   172,   173,    -1,   175,    -1,    -1,   178,
      -1,    -1,   181,   182,   183,    -1,    -1,    -1,   187,    -1,
     189,   190,    -1,    -1,    -1,    -1,    -1,    -1,   197,    -1,
     199,    -1,   201,    -1,   203,   204,   205,   206,   207,   208,
     209,    -1,    -1,   212,   213,   214,    -1,   216,    -1,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   262,    -1,   264,   265,   266,    -1,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,    -1,   317,    -1,
     319,   320,   321,    -1,   323,   324,   325,    11,    12,    -1,
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
      -1,    -1,    -1,   187,    -1,   189,   190,    -1,    -1,    -1,
      -1,    -1,    -1,   197,    -1,   199,    -1,   201,    -1,   203,
     204,   205,   206,   207,   208,   209,    -1,    -1,   212,   213,
     214,    -1,   216,    -1,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,    -1,
     264,   265,   266,    -1,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,    -1,   317,    -1,   319,   320,   321,    -1,   323,
     324,   325,    11,    12,    -1,    -1,    -1,    16,    -1,    -1,
      -1,    20,    21,    22,    23,    24,    25,    26,    -1,    -1,
      -1,    30,    -1,    -1,    33,    34,    -1,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    -1,    51,    52,    53,    54,    -1,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    -1,    -1,    95,    96,    97,    98,
      99,    -1,   101,    -1,    -1,    -1,    -1,   106,   107,    -1,
      -1,    -1,   111,   112,   113,   114,   115,   116,   117,    -1,
     119,   120,    -1,   122,    -1,    -1,    -1,   126,    -1,   128,
     129,   130,   131,    -1,   133,    -1,    -1,    -1,   137,    -1,
     139,   140,   141,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     149,   150,   151,    -1,   153,   154,   155,    -1,    -1,    -1,
     159,    -1,    -1,   162,    -1,    -1,    -1,   166,   167,   168,
     169,   170,   171,   172,   173,    -1,   175,    -1,    -1,   178,
      -1,    -1,   181,   182,   183,    -1,    -1,    -1,   187,    -1,
     189,   190,    -1,    -1,    -1,    -1,    -1,    -1,   197,    -1,
     199,    -1,   201,    -1,   203,   204,   205,   206,   207,   208,
     209,    -1,    -1,   212,   213,   214,    -1,   216,    -1,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   262,    -1,   264,   265,   266,    -1,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,    -1,   317,    -1,
     319,   320,   321,    -1,   323,   324,   325,    11,    12,    -1,
      -1,    -1,    16,    -1,    -1,    -1,    20,    -1,    -1,    -1,
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
      -1,    -1,    -1,   187,    -1,   189,   190,    -1,    -1,    -1,
      -1,   195,    -1,   197,    -1,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,    -1,    -1,   212,   213,
      -1,    -1,   216,    -1,   218,   219,    -1,    -1,    -1,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,    -1,
     264,   265,   266,    -1,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,    -1,    -1,    11,    12,   319,   320,   321,    16,   323,
     324,   325,    20,    -1,    -1,    -1,    -1,    25,    26,    -1,
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
      -1,   189,   190,    -1,    -1,    -1,    -1,   195,    -1,   197,
      -1,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,    -1,    -1,   212,   213,    -1,    -1,   216,    -1,
     218,   219,    -1,    -1,    -1,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,    -1,   264,   265,   266,    -1,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,    -1,    -1,    11,
      12,   319,   320,   321,    16,   323,   324,   325,    20,    21,
      22,    23,    24,    25,    26,    -1,    -1,    -1,    30,    -1,
      -1,    33,    34,    -1,    36,    37,    38,    39,    40,    41,
      -1,    43,    44,    45,    -1,    47,    48,    49,    -1,    -1,
      52,    53,    54,    -1,    -1,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    -1,    -1,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    -1,    -1,    -1,    -1,    97,    98,    99,    -1,    -1,
      -1,    -1,    -1,    -1,   106,    -1,    -1,    -1,    -1,   111,
     112,   113,    -1,   115,   116,   117,    -1,   119,   120,    -1,
     122,    -1,    -1,    -1,   126,    -1,   128,   129,   130,   131,
      -1,   133,    -1,    -1,    -1,   137,    -1,   139,   140,   141,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   149,   150,   151,
      -1,   153,   154,   155,    -1,    -1,    -1,   159,    -1,    -1,
     162,    -1,    -1,    -1,   166,   167,   168,   169,   170,   171,
     172,   173,    -1,   175,    -1,    -1,   178,    -1,    -1,   181,
     182,   183,    -1,    -1,    -1,   187,    -1,   189,   190,    -1,
      -1,    -1,    -1,    -1,    -1,   197,    -1,   199,    -1,   201,
      -1,   203,   204,   205,   206,   207,   208,   209,    -1,    -1,
     212,   213,   214,    -1,   216,    -1,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
      -1,    -1,   264,   265,   266,    -1,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,    -1,   317,    16,   319,   320,   321,
      -1,   323,   324,   325,    -1,    25,    26,    -1,    -1,    -1,
      -1,    -1,    -1,    33,    34,    -1,    36,    37,    38,    39,
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
     150,    -1,   152,   153,   154,    -1,    -1,    -1,   158,    -1,
      -1,   161,   162,    -1,    -1,    -1,   166,   167,   168,   169,
     170,   171,   172,   173,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   181,   182,   183,    -1,    -1,    -1,   187,   188,   189,
     190,    -1,    -1,    -1,    -1,   195,    -1,   197,    -1,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
      -1,    -1,   212,   213,    -1,    -1,   216,    -1,   218,   219,
     220,    -1,    -1,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,    -1,   264,   265,   266,    -1,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,    -1,    -1,    16,    -1,   319,
     320,   321,   322,   323,   324,   325,    25,    26,    -1,    -1,
      -1,    -1,    -1,    -1,    33,    34,    -1,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    -1,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    -1,    95,    96,    97,    98,
      -1,    -1,   101,   102,   103,    -1,    -1,   106,   107,    -1,
      -1,    -1,    -1,   112,   113,   114,   115,   116,   117,   118,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   128,
     129,   130,   131,    -1,   133,    -1,    -1,    -1,   137,   138,
     139,   140,   141,    -1,    -1,    -1,    -1,    -1,    -1,   148,
     149,   150,    -1,   152,   153,   154,    -1,    -1,    -1,   158,
      -1,    -1,   161,   162,    -1,    -1,    -1,   166,   167,   168,
     169,   170,   171,   172,   173,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   181,   182,   183,    -1,    -1,    -1,   187,   188,
     189,   190,    -1,    -1,    -1,    -1,    -1,    -1,   197,    -1,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,    -1,    -1,   212,   213,    -1,    -1,   216,    -1,   218,
     219,   220,    -1,    -1,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   262,    -1,   264,   265,   266,    -1,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,    -1,    -1,    16,    -1,
     319,   320,   321,   322,   323,   324,   325,    25,    26,    -1,
      -1,    -1,    -1,    -1,    -1,    33,    34,    -1,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    -1,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    -1,    95,    96,    97,
      98,    -1,    -1,   101,   102,   103,    -1,    -1,   106,   107,
      -1,    -1,    -1,    -1,   112,   113,   114,   115,   116,   117,
     118,   119,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     128,   129,   130,   131,    -1,   133,    -1,    -1,    -1,   137,
     138,   139,   140,   141,    -1,    -1,    -1,    -1,    -1,    -1,
     148,   149,   150,    -1,   152,   153,   154,    -1,    -1,    -1,
     158,    -1,    -1,   161,   162,    -1,    -1,    -1,   166,   167,
     168,   169,   170,   171,   172,   173,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   181,   182,   183,    -1,    -1,    -1,   187,
      -1,   189,   190,    -1,    -1,    -1,    -1,    -1,    -1,   197,
      -1,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,    -1,    -1,   212,   213,    -1,    -1,   216,    -1,
     218,   219,   220,    -1,    -1,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,    -1,   264,   265,   266,    -1,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,    -1,    -1,    16,
      -1,   319,   320,   321,   322,   323,   324,   325,    25,    26,
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
      -1,   128,   129,   130,   131,    -1,   133,    -1,    -1,    -1,
     137,   138,   139,   140,   141,    -1,    -1,    -1,    -1,    -1,
      -1,   148,   149,   150,    -1,   152,   153,   154,    -1,    -1,
      -1,   158,    -1,    -1,   161,   162,    -1,    -1,    -1,   166,
     167,   168,   169,   170,   171,   172,   173,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   181,   182,   183,    -1,    -1,    -1,
     187,    -1,   189,   190,    -1,    -1,    -1,    -1,    -1,    -1,
     197,    -1,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,    -1,    -1,   212,   213,    -1,    -1,   216,
      -1,   218,   219,   220,    -1,    -1,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   262,    -1,   264,   265,   266,
      -1,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,   309,   310,   311,   312,   313,   314,    -1,    -1,
      16,    -1,   319,   320,   321,   322,   323,   324,   325,    25,
      26,    -1,    -1,    -1,    -1,    -1,    -1,    33,    34,    -1,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    -1,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    -1,    95,
      96,    97,    98,    -1,    -1,   101,   102,   103,    -1,    -1,
     106,   107,    -1,    -1,    -1,    -1,   112,   113,   114,   115,
     116,   117,   118,   119,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   128,   129,   130,   131,    -1,   133,    -1,    -1,
      -1,   137,   138,   139,   140,   141,    -1,    -1,    -1,    -1,
      -1,    -1,   148,   149,   150,    -1,   152,   153,   154,    -1,
      -1,    -1,   158,    -1,    -1,   161,   162,    -1,    -1,    -1,
     166,   167,   168,   169,   170,   171,   172,   173,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   181,   182,   183,    -1,    -1,
      -1,   187,    -1,   189,   190,    -1,    -1,    -1,    -1,    -1,
      -1,   197,    -1,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,    -1,    -1,   212,   213,    -1,    -1,
     216,    -1,   218,   219,   220,    -1,    -1,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,    -1,   264,   265,
     266,    -1,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,    -1,
      -1,    16,    -1,   319,   320,   321,   322,   323,   324,   325,
      25,    26,    -1,    -1,    -1,    30,    -1,    -1,    33,    34,
      -1,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      -1,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    -1,
      95,    96,    97,    98,    -1,    -1,   101,   102,   103,    -1,
      -1,   106,   107,    -1,    -1,    -1,    -1,   112,   113,   114,
     115,   116,   117,   118,   119,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   128,   129,   130,   131,    -1,   133,    -1,
      -1,    -1,   137,   138,   139,   140,   141,    -1,    -1,    -1,
      -1,    -1,    -1,   148,   149,   150,    -1,   152,   153,   154,
      -1,    -1,    -1,   158,    -1,    -1,   161,   162,    -1,    -1,
      -1,   166,   167,   168,   169,   170,   171,   172,   173,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   181,   182,   183,    -1,
      -1,    -1,   187,    -1,   189,   190,    -1,    -1,    -1,    -1,
      -1,    -1,   197,    -1,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,    -1,    -1,   212,   213,    -1,
      -1,   216,    -1,   218,   219,    -1,    -1,    -1,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,    -1,   264,
     265,   266,    -1,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
      -1,    -1,    16,    -1,   319,   320,   321,    -1,   323,   324,
     325,    25,    26,    -1,    -1,    -1,    -1,    -1,    -1,    33,
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
     154,    -1,    -1,    -1,   158,    -1,    -1,   161,   162,    -1,
      -1,    -1,   166,   167,   168,   169,   170,   171,   172,   173,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   181,   182,   183,
      -1,    -1,    -1,   187,    -1,   189,   190,    -1,    -1,    -1,
      -1,    -1,    -1,   197,    -1,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,    -1,    -1,   212,   213,
      -1,    -1,   216,    -1,   218,   219,   220,    -1,    -1,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,    -1,
     264,   265,   266,    -1,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,    -1,    -1,    16,    -1,   319,   320,   321,   322,   323,
     324,   325,    25,    26,    -1,    -1,    -1,    -1,    -1,    -1,
      33,    34,    -1,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    -1,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    -1,    95,    96,    97,    98,    -1,    -1,   101,   102,
     103,    -1,    -1,   106,   107,    -1,    -1,    -1,    -1,   112,
     113,   114,   115,   116,   117,   118,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   128,   129,   130,   131,    -1,
     133,    -1,    -1,    -1,   137,   138,   139,   140,   141,    -1,
      -1,    -1,    -1,    -1,    -1,   148,   149,   150,    -1,   152,
     153,   154,    -1,    -1,    -1,   158,    -1,    -1,   161,   162,
      -1,    -1,    -1,   166,   167,   168,   169,   170,   171,   172,
     173,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   181,   182,
     183,    -1,    -1,    -1,   187,    -1,   189,   190,    -1,    -1,
      -1,    -1,    -1,    -1,   197,    -1,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,    -1,    -1,   212,
     213,    -1,    -1,   216,    -1,   218,   219,   220,    -1,    -1,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
      -1,   264,   265,   266,    -1,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,   311,   312,
     313,   314,    -1,    -1,    -1,    -1,   319,   320,   321,   322,
     323,   324,   325,    16,    -1,    18,    19,    -1,    -1,    -1,
      -1,    -1,    25,    26,    -1,    -1,    -1,    -1,    -1,    -1,
      33,    34,    -1,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    -1,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    -1,    95,    96,    97,    98,    -1,    -1,   101,   102,
     103,    -1,    -1,   106,   107,    -1,    -1,    -1,    -1,   112,
     113,   114,   115,   116,   117,   118,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   128,   129,   130,   131,    -1,
     133,    -1,    -1,    -1,   137,   138,   139,   140,   141,    -1,
      -1,    -1,    -1,    -1,    -1,   148,   149,   150,    -1,   152,
     153,   154,    -1,    -1,    -1,    -1,    -1,    -1,   161,   162,
      -1,    -1,    -1,   166,   167,   168,   169,   170,   171,   172,
     173,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   181,   182,
     183,    -1,    -1,    -1,   187,    -1,   189,   190,    -1,    -1,
      -1,    -1,    -1,    -1,   197,    -1,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,    -1,    -1,   212,
     213,    -1,    -1,   216,    -1,   218,   219,    -1,    -1,    -1,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
      -1,   264,   265,   266,    -1,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,   311,   312,
     313,   314,    -1,    -1,    16,    -1,   319,   320,   321,    -1,
     323,   324,   325,    25,    26,    -1,    -1,    -1,    -1,    -1,
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
     182,   183,    -1,    -1,    -1,   187,   188,   189,   190,    -1,
      -1,    -1,    -1,   195,    -1,   197,    -1,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,    -1,    -1,
     212,   213,    -1,    -1,   216,    -1,   218,   219,    -1,    -1,
      -1,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,    -1,   264,   265,   266,    -1,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,    -1,    -1,    16,    -1,   319,   320,   321,
      -1,   323,   324,   325,    25,    26,    -1,    -1,    -1,    30,
      -1,    -1,    33,    34,    -1,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    -1,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    -1,    95,    96,    97,    98,    -1,    -1,
     101,   102,   103,    -1,    -1,   106,   107,    -1,    -1,    -1,
      -1,   112,   113,   114,   115,   116,   117,   118,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   128,   129,   130,
     131,    -1,   133,    -1,    -1,    -1,   137,   138,   139,   140,
     141,    -1,    -1,    -1,    -1,    -1,    -1,   148,   149,   150,
      -1,   152,   153,   154,    -1,    -1,    -1,    -1,    -1,    -1,
     161,   162,    -1,    -1,    -1,   166,   167,   168,   169,   170,
     171,   172,   173,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     181,   182,   183,    -1,    -1,    -1,   187,   188,   189,   190,
      -1,    -1,    -1,    -1,    -1,    -1,   197,    -1,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,    -1,
      -1,   212,   213,    -1,    -1,   216,    -1,   218,   219,    -1,
      -1,    -1,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     261,   262,    -1,   264,   265,   266,    -1,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,   309,   310,
     311,   312,   313,   314,    -1,    -1,    16,    -1,   319,   320,
     321,    -1,   323,   324,   325,    25,    26,    -1,    -1,    -1,
      -1,    -1,    -1,    33,    34,    -1,    36,    37,    38,    39,
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
     190,    -1,    -1,    -1,    -1,   195,    -1,   197,    -1,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
      -1,    -1,   212,   213,    -1,    -1,   216,    -1,   218,   219,
      -1,    -1,    -1,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,    -1,   264,   265,   266,    -1,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,    -1,    -1,    16,    -1,   319,
     320,   321,    -1,   323,   324,   325,    25,    26,    -1,    -1,
      -1,    -1,    -1,    -1,    33,    34,    -1,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    -1,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    -1,    95,    96,    97,    98,
      -1,    -1,   101,   102,   103,    -1,    -1,   106,   107,    -1,
      -1,    -1,    -1,   112,   113,   114,   115,   116,   117,   118,
     119,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   128,
     129,   130,   131,    -1,   133,    -1,    -1,    -1,   137,   138,
     139,   140,   141,    -1,    -1,    -1,    -1,    -1,    -1,   148,
     149,   150,    -1,   152,   153,   154,    -1,    -1,    -1,    -1,
      -1,    -1,   161,   162,    -1,    -1,    -1,   166,   167,   168,
     169,   170,   171,   172,   173,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   181,   182,   183,    -1,    -1,    -1,   187,    -1,
     189,   190,    -1,    -1,    -1,    -1,    -1,    -1,   197,    -1,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,    -1,    -1,   212,   213,    -1,    -1,   216,    -1,   218,
     219,    -1,    -1,    -1,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   262,    -1,   264,   265,   266,    -1,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,    -1,    -1,    16,    -1,
     319,   320,   321,    -1,   323,   324,   325,    25,    26,    -1,
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
      -1,   189,   190,    -1,    -1,    -1,    -1,    -1,    -1,   197,
      -1,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,    -1,    -1,   212,   213,    -1,    -1,   216,    -1,
     218,   219,    -1,    -1,    -1,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,    -1,   264,   265,   266,    -1,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,    -1,    -1,    -1,
      -1,   319,   320,   321,    -1,   323,   324,   325,    21,    22,
      23,    24,    25,    26,    -1,    -1,    -1,    30,    -1,    -1,
      33,    34,    -1,    36,    37,    38,    39,    40,    41,    42,
      43,    -1,    45,    46,    47,    -1,    49,    50,    51,    52,
      -1,    54,    -1,    56,    57,    58,    59,    60,    61,    -1,
      -1,    64,    65,    66,    67,    68,    -1,    70,    71,    72,
      -1,    -1,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    -1,    95,    96,    97,    98,    -1,    -1,   101,   102,
     103,    -1,    -1,   106,   107,    -1,    -1,    -1,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,    -1,    -1,
      -1,    -1,    -1,   126,    -1,   128,   129,   130,   131,    -1,
     133,    -1,    -1,    -1,   137,   138,   139,   140,   141,    -1,
      -1,    -1,    -1,    -1,    -1,   148,   149,   150,   151,   152,
     153,    -1,   155,   156,    -1,   158,   159,    -1,   161,   162,
      -1,    -1,    -1,   166,   167,   168,   169,   170,   171,   172,
     173,    -1,   175,    -1,    -1,    -1,    -1,    -1,   181,   182,
     183,    -1,    -1,    -1,   187,    -1,   189,   190,    -1,    -1,
      -1,    -1,    -1,    -1,   197,    -1,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,    -1,    -1,    -1,
     213,   214,    -1,   216,    -1,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,    -1,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
      -1,   264,   265,   266,    -1,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,    -1,   317,    -1,    -1,    -1,   321,    21,
      22,    23,    24,    25,    26,    -1,    -1,    -1,    30,    -1,
      -1,    33,    34,    -1,    36,    37,    38,    39,    40,    41,
      42,    43,    -1,    45,    46,    47,    -1,    49,    50,    51,
      52,    -1,    54,    -1,    56,    57,    58,    59,    60,    61,
      -1,    -1,    64,    65,    66,    67,    68,    -1,    70,    71,
      72,    -1,    -1,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    -1,    95,    96,    97,    98,    -1,    -1,   101,
     102,   103,    -1,    -1,   106,   107,    -1,    -1,    -1,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,    -1,
      -1,    -1,    -1,    -1,   126,    -1,   128,   129,   130,   131,
      -1,   133,    -1,    -1,    -1,   137,   138,   139,   140,   141,
      -1,    -1,    -1,    -1,    -1,    -1,   148,   149,   150,   151,
     152,   153,    -1,   155,   156,    -1,   158,   159,    -1,   161,
     162,    -1,    -1,    -1,   166,   167,   168,   169,   170,   171,
     172,   173,    -1,   175,    -1,    -1,    -1,    -1,    -1,   181,
     182,   183,    -1,    -1,    -1,   187,    -1,   189,   190,    -1,
      -1,    -1,    -1,    -1,    -1,   197,    -1,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,    -1,    -1,
      -1,   213,   214,    -1,   216,    -1,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,    -1,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,    -1,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,    -1,   264,   265,   266,    -1,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,    -1,   317,    -1,    -1,    -1,   321,
      21,    22,    23,    24,    25,    26,    -1,    -1,    -1,    30,
      -1,    -1,    33,    34,    -1,    36,    37,    38,    39,    40,
      41,    -1,    43,    -1,    45,    -1,    47,    -1,    49,    -1,
      -1,    52,    -1,    54,    -1,    -1,    57,    58,    59,    60,
      61,    -1,    -1,    64,    65,    66,    67,    68,    -1,    -1,
      71,    72,    -1,    -1,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    -1,    -1,    -1,    -1,    97,    98,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   106,    -1,    -1,    -1,    -1,
     111,   112,   113,    -1,   115,   116,   117,    -1,   119,   120,
      -1,    -1,    -1,    -1,    -1,   126,    -1,   128,   129,   130,
     131,    -1,   133,    -1,    -1,    -1,   137,    -1,   139,   140,
     141,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   149,   150,
     151,    -1,   153,    -1,   155,    -1,    -1,    -1,   159,    -1,
      -1,   162,    -1,    -1,    -1,   166,   167,   168,   169,   170,
     171,   172,   173,    -1,   175,    -1,    -1,    -1,    -1,    -1,
     181,   182,   183,    -1,    -1,    -1,   187,    -1,   189,   190,
      -1,    -1,    -1,    -1,    -1,    -1,   197,    -1,   199,    -1,
     201,    -1,   203,   204,   205,   206,   207,   208,   209,    -1,
      -1,    -1,   213,   214,    -1,   216,    -1,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,    -1,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     261,    -1,    -1,   264,   265,   266,    -1,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,    -1,   317,    -1,   319,    -1,
     321,    21,    22,    23,    24,    25,    26,    -1,    -1,    -1,
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
     190,    -1,    -1,    -1,    -1,    -1,    -1,   197,    -1,   199,
      -1,    -1,    -1,   203,   204,   205,   206,   207,   208,   209,
      -1,    -1,    -1,    -1,   214,    -1,   216,    -1,   218,    -1,
     220,   221,   222,    -1,    -1,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,    -1,   239,
     240,   241,   242,   243,   244,   245,   246,   247,    -1,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,    -1,    -1,   264,   265,   266,    -1,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,    -1,   317,    -1,   319,
      -1,   321,    25,    26,    -1,    -1,    -1,    -1,    -1,    -1,
      33,    34,    -1,    36,    37,    38,    -1,    40,    41,    42,
      43,    -1,    -1,    46,    47,    -1,    49,    50,    51,    52,
      -1,    54,    -1,    56,    57,    58,    59,    -1,    61,    -1,
      -1,    64,    65,    66,    67,    68,    -1,    70,    -1,    72,
      -1,    -1,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    -1,    95,    96,    97,    -1,    -1,    -1,   101,   102,
     103,    -1,    -1,   106,   107,    -1,    -1,    -1,    -1,   112,
     113,   114,   115,   116,   117,   118,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   128,   129,   130,   131,    -1,
     133,    -1,    -1,    -1,   137,   138,   139,   140,   141,    -1,
      -1,    -1,    -1,    -1,    -1,   148,   149,   150,    -1,   152,
     153,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   161,   162,
      -1,    -1,    -1,   166,   167,   168,   169,   170,   171,   172,
     173,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   181,   182,
     183,    -1,    -1,    -1,   187,    -1,   189,   190,    -1,    -1,
      -1,    -1,    -1,    -1,   197,    -1,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,    -1,    -1,    -1,
     213,    -1,    -1,   216,    -1,   218,   219,    -1,    -1,    -1,
     223,   224,   225,   226,   227,   228,   229,    -1,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,    -1,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
      -1,   264,   265,   266,    -1,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,   311,   312,
     313,   314,    -1,    -1,    -1,    -1,    -1,    -1,   321
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
     182,   183,   187,   189,   190,   191,   192,   193,   195,   197,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   212,   213,   214,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   264,   265,   266,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   317,   319,   320,   321,   323,   324,   325,   326,
     327,   342,   344,   345,   346,   347,   348,   349,   350,   351,
     352,   353,   354,   355,   356,   357,   358,   359,   360,   363,
     364,   365,   366,   367,   368,   372,   373,   374,   378,   380,
     381,   383,   390,   392,   395,   396,   397,   399,   400,   401,
     402,   403,   405,   406,   408,   409,   410,   411,   412,   413,
     415,   416,   419,   420,   421,   422,   423,   428,   430,   432,
     433,   434,   439,   458,   461,   465,   468,   469,   475,   476,
     477,   478,   479,   481,   482,   484,   485,   486,   487,   488,
     489,   490,   491,   492,   494,   495,   496,   497,   500,   501,
     502,   503,   504,   505,   506,   507,   508,   509,   510,   511,
     512,   513,   514,   515,   516,   517,   520,   521,   522,   523,
     524,   525,   526,   527,   528,   529,   531,   532,   533,   534,
     535,   536,   550,   551,   553,   554,   555,   556,   557,   558,
     559,   560,   568,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   579,   582,   587,   588,   589,   590,   591,
     592,   595,   653,   654,   655,   656,   658,   659,   660,   661,
     662,   665,   666,   667,    33,    34,    49,   216,   398,   399,
     400,   398,   398,   399,   400,   158,   158,    37,    38,    40,
      41,    47,    57,    58,    75,    80,   112,   113,   114,   162,
     225,   266,   292,   300,   308,   379,   380,   384,   385,   386,
     162,   155,   158,   155,   158,   155,   158,     1,   158,   387,
     158,    25,    34,    61,   119,   278,   438,   440,   441,   158,
     155,   158,   158,   158,   119,   155,   158,   158,   158,    77,
     155,   226,   227,   124,   124,   124,   155,   158,    39,    43,
      45,    46,    47,    48,    51,    60,    68,    71,    73,    74,
      76,    91,    92,    98,   106,   113,   115,   116,   137,   140,
     141,   162,   170,   173,   181,   182,   190,   203,   229,   231,
     233,   234,   241,   243,   244,   245,   248,   249,   262,   265,
     320,   514,   666,   124,   119,   407,   124,   124,    39,    44,
      45,    53,    60,    62,    63,    71,    98,   230,   665,   119,
     124,   124,   398,   400,   421,   657,   665,    48,    73,    74,
     119,   155,   186,   249,   420,   422,   432,   188,   420,   665,
     155,   155,   124,   665,    18,    19,   665,   124,   124,   124,
     506,   155,    31,   215,   218,   218,    39,    45,    60,    71,
      98,   230,   232,   319,   517,   666,   230,   232,   319,   421,
     657,   230,   319,   517,   230,   235,   319,   119,   246,   246,
     247,   158,   155,   402,     1,   478,   316,   420,   318,   420,
     319,   421,   327,   344,   344,     0,   346,   347,    33,    49,
     349,   366,     1,   191,   343,   191,   343,   113,   381,   401,
     420,   108,   191,   108,   343,   191,    42,    46,    51,    70,
     169,   172,   187,   213,   262,   414,   424,   429,   430,   431,
     446,   447,   451,     3,    67,    72,   119,   425,   168,    93,
     134,   142,   143,   145,   153,   157,   159,   164,   180,   204,
     205,   206,   207,   208,   209,   498,   499,   254,   100,   160,
     177,   200,   118,   148,   161,   195,   202,   211,   138,   152,
      50,   201,   102,   103,   160,   177,   496,   194,   155,   503,
     506,   192,   193,   156,   518,   519,   514,   518,   514,   121,
     156,   158,   518,   158,   147,   158,   185,   185,   185,   185,
     382,   521,   382,    30,   664,   183,   197,   183,   197,   167,
     183,   666,   665,   170,   203,    47,   665,   154,   119,    45,
      47,    80,   107,   169,   665,   226,   227,   228,   251,   626,
     665,   665,   309,   139,   144,   113,   292,   300,   384,   665,
     399,   188,   399,    45,    63,   188,   578,   579,   420,   188,
     195,   665,   435,   436,   665,   119,   188,   388,   389,   155,
     404,   420,     1,   162,   664,   114,   162,   362,   664,   665,
     119,   144,   108,   188,   420,    30,   188,   665,   665,   665,
     459,   460,   665,   399,   188,   420,   420,   580,   665,   399,
     155,   155,   420,   188,   195,   665,   665,   144,   459,   185,
     185,   123,   108,   185,   123,   158,   158,   158,   665,   155,
     186,   187,   188,    35,   538,   539,   540,   420,   420,     8,
     176,    17,   420,   215,    30,    30,   421,   421,   517,   421,
     421,   421,   657,   238,   238,   421,   517,    95,   421,   236,
     235,   593,   594,   665,   191,   191,   421,   420,   400,   420,
     250,   417,   418,   435,   316,   318,   421,   238,   344,   191,
     343,   191,   343,     3,   350,   366,   396,     1,   350,   366,
     396,    33,   367,   396,   367,   396,   407,   343,   407,   421,
     421,   119,   169,   171,   171,   401,   421,   421,   289,   289,
     435,   119,   442,   477,   478,   481,   481,   481,   481,   480,
     481,   481,   481,    71,   482,   486,   486,   485,   487,   487,
     487,   487,   488,   488,   489,   489,   236,    95,    95,    95,
     504,   185,   420,   506,   506,   420,   519,   158,   524,   582,
     665,   186,   146,   188,   421,   530,   188,   151,   188,   530,
     108,   188,   188,   108,   108,   387,    30,   666,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,   369,   370,
     371,    95,   139,   144,   375,   376,   377,   665,   162,   162,
     369,   664,   129,   134,    55,    57,   101,   256,   269,   271,
     282,   283,   284,   286,   288,   627,   628,   629,   630,   631,
     632,   639,   645,   646,   251,    95,   304,   665,   144,   421,
     119,   665,   665,   134,   185,   185,   188,   188,   185,   108,
     188,   108,   188,   108,    36,    95,    97,   149,   437,   438,
     561,   665,    95,   108,   188,   398,   188,   665,    97,    45,
     665,   664,    97,   144,   561,   665,   421,   441,   185,   188,
     188,   188,   188,   108,   189,   149,   561,   185,   188,   188,
     155,   185,   399,   399,   185,   108,   188,   108,   188,   144,
     561,   421,   189,   421,   421,   665,   421,   420,   420,   420,
     665,   539,   540,   132,   198,   185,   185,   185,   133,   191,
     133,   191,    95,   223,   224,   238,    95,   223,   224,   238,
     238,   238,   421,   421,    95,    95,   421,   242,   230,   517,
     236,   108,   240,   144,   191,   188,   420,   185,   515,   599,
     418,   238,   421,   366,    33,    33,   191,   343,   191,   114,
     401,   665,   171,   421,   452,   453,   119,   421,   448,   449,
     665,    56,   219,   259,   426,   427,   481,   155,   158,   264,
     502,   521,   600,   603,   604,   605,   606,   607,   611,   613,
     615,   616,    47,   154,   158,   212,   220,   322,   323,   324,
     325,   562,   564,   566,   568,   583,   584,   585,   586,   663,
     665,   562,   493,   567,   665,   493,   185,   186,   188,   420,
     108,   188,   188,   521,   150,   166,   150,   166,   139,   404,
     387,   370,   134,   158,   564,   377,   421,   561,   664,   664,
     130,   131,   664,   282,   283,   284,   288,   665,   268,   279,
     268,   279,    30,   291,    97,   114,   158,   633,   636,   627,
      39,    44,    53,    60,    62,    71,    98,   230,   323,   324,
     391,   568,   663,   232,   304,   313,   421,   665,    95,   304,
     664,   155,   580,   581,   665,   580,   581,   119,   436,   129,
     562,   119,   421,   149,   438,   149,    36,   149,   437,   438,
     561,   562,   389,    95,   185,   199,   134,   361,   664,   162,
     134,    97,   361,   421,   144,   438,   155,   119,   421,   421,
     149,   101,   462,   463,   464,   466,   467,   101,   470,   471,
     472,   473,   399,   185,   185,   155,   580,   580,   421,   144,
     191,   421,   123,   123,   188,   188,   188,    35,   540,   132,
     198,     9,    10,   104,   125,   127,   155,   196,   535,   537,
     548,   549,   552,   155,    30,    30,   237,   239,   421,   421,
     421,   237,   239,   421,   421,   421,   421,   421,    97,   421,
     421,   421,   421,   242,   517,   119,   421,   421,    48,    73,
      74,   249,   401,   422,   432,   250,   596,   597,   155,   211,
     402,   421,   191,   114,   396,   396,   396,   452,    96,   107,
     117,   129,   454,   455,   456,   457,   108,   665,   107,   450,
     108,   149,   561,   259,    54,    59,    78,   119,   437,   443,
     444,   445,   427,   420,   600,   607,   155,   290,   483,   652,
      97,   170,   257,   258,   260,   267,   277,   289,   601,   602,
     621,   622,   623,   624,   647,   650,   263,   265,   608,   626,
     272,   612,   648,   252,   253,   275,   617,   618,   158,   158,
     188,   564,   158,   158,   158,   158,   158,   146,   177,   195,
     563,   146,   188,   146,   421,   139,   404,   582,   376,   291,
      30,    97,   114,   158,   640,    30,   633,   563,   563,   504,
     292,   311,   561,   391,   232,   191,   398,   188,   188,   146,
     188,   188,   436,   149,   437,   665,   421,   149,   421,   129,
     421,   149,   438,   149,   562,   401,   421,   664,   108,   361,
     421,   144,   398,   460,   421,   421,   114,   463,   464,   101,
     187,   114,   464,   467,   119,   474,   562,   101,   114,   471,
     101,   114,   473,   185,   398,   188,   188,   421,   421,   421,
     199,   470,   134,   196,   537,     7,   399,   665,   196,   548,
     399,   191,   191,   238,   238,   238,   238,    97,   321,   242,
     421,   242,   594,   187,   158,   158,   158,   187,   599,   597,
     515,   664,   130,   131,   456,   457,   457,   453,   144,   561,
     664,   449,   421,   149,   119,   119,   421,   665,   445,    78,
     185,   188,   600,   614,   255,   219,   259,   273,   280,   651,
      97,   261,   262,   649,   255,   604,   651,   485,   621,   605,
     149,   287,   609,   610,   649,   291,   620,    79,   619,   188,
     195,   562,   565,   188,   188,   188,   188,   188,   188,   188,
      30,   138,   202,   642,   643,   644,    30,   641,   642,   276,
     637,   108,   634,   171,   665,   262,   504,   185,   421,   149,
     421,   149,   437,   421,   149,   421,   128,   128,    97,   664,
     421,   185,   187,   187,   421,   401,   421,   187,   187,   665,
     187,   211,   119,   474,   119,   187,   119,   474,   187,   185,
     114,   540,   665,   196,   185,   540,   665,   185,   421,   421,
     421,   421,   321,   421,   421,   421,   421,   420,   420,   420,
     155,   598,   457,   421,   144,   421,   665,   665,   444,   421,
     185,   487,    52,   131,   485,   485,   274,   281,   291,   625,
     625,   606,   155,   285,    95,   188,   108,   188,   640,   640,
     644,   108,   188,    30,   638,   649,   635,   636,   188,   393,
     394,   504,   119,   230,   312,   292,   171,   421,   421,   149,
     421,   401,   421,   361,   421,   401,    95,   401,   421,   562,
     665,   187,   665,   421,   665,   187,   401,   119,    94,   184,
     541,   540,   665,   198,   540,   421,   188,   188,   188,   420,
     450,   421,    54,   485,   485,   200,   420,   562,   562,    95,
      30,   270,   108,   108,   457,   561,   665,   119,   230,   665,
     393,   421,   474,    95,   187,    95,   665,     5,   135,   544,
     545,   547,   549,    29,   136,   542,   543,   546,   549,   198,
     540,   198,   199,   470,   185,   450,   119,   485,   185,   562,
     636,   394,   457,   310,   665,   119,   230,   187,   474,   401,
     421,   474,   187,    94,   135,   547,   184,   136,   546,   198,
     114,   665,   421,   310,   665,   119,   401,   421,   187,   187,
     119,   298,   310,   665,   665,   311,   421,   311,   187,   504,
     504,   200,   292,   665,   230,   119,   665,   311,   504
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
     595
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned short int
  jsoniq_parser::yyr1_[] =
  {
         0,   341,   342,   342,   342,   342,   343,   343,   343,   344,
     344,   344,   344,   345,   345,   345,   345,   346,   346,   346,
     346,   346,   346,   346,   346,   347,   347,   347,   347,   348,
     349,   349,   349,   350,   350,   350,   350,   350,   351,   351,
     351,   351,   351,   351,   351,   351,   352,   352,   353,   354,
     355,   355,   356,   356,   357,   357,   358,   358,   358,   358,
     359,   359,   359,   360,   360,   360,   360,   361,   361,   362,
     362,   363,   363,   363,   363,   364,   365,   365,   366,   366,
     366,   367,   367,   367,   367,   367,   367,   367,   367,   368,
     368,   369,   369,   370,   371,   371,   371,   371,   371,   371,
     371,   371,   371,   371,   372,   373,   374,   375,   375,   376,
     376,   376,   377,   378,   378,   378,   379,   379,   379,   379,
     380,   380,   381,   381,   381,   381,   382,   382,   383,   383,
     384,   384,   385,   385,   386,   386,   387,   387,   387,   387,
     388,   388,   389,   389,   390,   390,   390,   390,   391,   391,
     391,   391,   392,   392,   393,   393,   394,   394,   394,   394,
     395,   395,   395,   395,   396,   397,   397,   397,   398,   398,
     398,   399,   399,   400,   400,   400,   401,   401,   401,   401,
     401,   401,   401,   401,   401,   401,   401,   401,   401,   402,
     403,   404,   405,   406,   406,   406,   407,   407,   407,   407,
     408,   409,   410,   411,   412,   412,   413,   414,   415,   416,
     417,   417,   418,   419,   420,   420,   420,   421,   421,   421,
     421,   421,   421,   422,   422,   422,   422,   422,   422,   422,
     422,   422,   422,   422,   422,   423,   424,   425,   425,   426,
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
     501,   501,   502,   502,   503,   503,   503,   504,   504,   504,
     504,   505,   506,   506,   506,   507,   507,   508,   508,   508,
     508,   509,   509,   510,   510,   510,   510,   510,   510,   510,
     511,   511,   512,   512,   513,   513,   513,   513,   513,   514,
     514,   515,   515,   516,   516,   516,   516,   517,   517,   517,
     517,   517,   517,   517,   517,   517,   517,   518,   518,   519,
     520,   520,   520,   520,   520,   520,   520,   520,   520,   520,
     520,   520,   520,   520,   521,   521,   521,   521,   522,   522,
     522,   523,   523,   524,   525,   525,   526,   527,   528,   529,
     529,   530,   530,   530,   530,   531,   531,   532,   533,   534,
     534,   535,   535,   535,   536,   536,   536,   536,   536,   536,
     537,   537,   538,   538,   539,   540,   540,   541,   541,   542,
     542,   543,   543,   543,   543,   544,   544,   545,   545,   545,
     545,   546,   546,   547,   547,   548,   548,   548,   548,   549,
     549,   549,   549,   550,   550,   551,   551,   552,   553,   553,
     553,   553,   553,   553,   553,   554,   555,   555,   556,   556,
     557,   558,   559,   559,   560,   560,   561,   562,   562,   562,
     562,   563,   563,   563,   564,   564,   564,   564,   564,   564,
     564,   565,   565,   566,   566,   567,   568,   568,   568,   568,
     568,   568,   568,   568,   568,   568,   569,   570,   571,   571,
     571,   572,   573,   574,   575,   575,   575,   576,   576,   576,
     576,   576,   577,   578,   578,   578,   578,   578,   578,   578,
     579,   580,   581,   582,   583,   583,   584,   585,   585,   586,
     587,   587,   587,   588,   588,   588,   588,   588,   588,   588,
     588,   588,   588,   589,   589,   590,   590,   591,   592,   593,
     593,   594,   595,   596,   596,   597,   598,   599,   599,   600,
     601,   601,   602,   602,   603,   603,   604,   604,   605,   605,
     606,   606,   607,   608,   608,   609,   609,   610,   611,   611,
     611,   612,   612,   613,   614,   614,   615,   616,   616,   617,
     617,   618,   618,   618,   619,   619,   620,   620,   621,   621,
     621,   621,   621,   622,   623,   624,   625,   625,   625,   626,
     626,   627,   627,   627,   627,   627,   627,   627,   627,   628,
     628,   628,   628,   629,   629,   630,   631,   631,   632,   632,
     632,   633,   633,   634,   634,   635,   635,   636,   637,   637,
     638,   638,   639,   639,   639,   640,   640,   641,   641,   642,
     642,   643,   643,   644,   644,   645,   646,   646,   647,   647,
     647,   648,   649,   649,   649,   649,   650,   650,   651,   651,
     652,   653,   653,   654,   654,   655,   655,   656,   657,   657,
     657,   657,   658,   658,   658,   658,   658,   658,   659,   659,
     660,   660,   661,   661,   662,   662,   663,   663,   663,   663,
     664,   665,   665,   665,   665,   665,   665,   665,   665,   665,
     665,   665,   665,   665,   665,   665,   665,   665,   665,   665,
     665,   665,   665,   665,   666,   666,   666,   666,   666,   666,
     666,   666,   666,   666,   666,   666,   666,   666,   666,   666,
     666,   666,   666,   666,   666,   666,   666,   666,   666,   666,
     666,   666,   666,   666,   666,   666,   666,   666,   666,   666,
     666,   666,   666,   666,   666,   666,   666,   666,   666,   666,
     666,   666,   666,   666,   666,   666,   666,   666,   666,   666,
     666,   666,   666,   666,   666,   666,   666,   666,   666,   666,
     666,   666,   666,   666,   666,   666,   666,   666,   666,   666,
     666,   666,   666,   666,   666,   666,   666,   666,   666,   666,
     666,   666,   666,   666,   666,   666,   666,   666,   666,   666,
     666,   666,   666,   666,   666,   666,   666,   666,   666,   666,
     666,   666,   666,   666,   666,   666,   666,   666,   666,   666,
     666,   666,   666,   666,   666,   666,   666,   666,   666,   666,
     666,   666,   666,   666,   666,   666,   666,   666,   666,   666,
     666,   666,   666,   666,   666,   666,   666,   666,   666,   666,
     666,   666,   666,   666,   666,   666,   666,   666,   666,   666,
     666,   666,   666,   666,   666,   666,   666,   666,   666,   666,
     666,   666,   666,   666,   666,   666,   666,   666,   666,   666,
     666,   666,   666,   666,   666,   666,   666,   666,   666,   666,
     666,   666,   666,   666,   666,   666,   666,   666,   666,   666,
     666,   666,   666,   666,   667
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
       3,     4,     1,     2,     3,     2,     2,     1,     2,     2,
       1,     1,     1,     3,     3,     1,     1,     1,     2,     1,
       2,     2,     1,     2,     2,     2,     2,     2,     2,     2,
       1,     2,     2,     1,     2,     2,     2,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     3,
       4,     3,     3,     4,     5,     3,     3,     1,     2,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     2,     3,     1,     4,     4,     3,
       4,     1,     3,     1,     3,     1,     1,     3,     3,     1,
       1,     1,     1,     1,     4,     8,     5,     9,     9,    10,
       1,     2,     1,     2,     6,     0,     1,     3,     3,     0,
       1,     1,     1,     2,     2,     0,     1,     1,     1,     2,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     3,     2,     3,     3,     2,     1,     1,
       1,     1,     1,     1,     1,     4,     3,     7,     3,     7,
       4,     4,     3,     7,     3,     7,     2,     1,     2,     3,
       2,     1,     1,     1,     1,     1,     3,     3,     1,     1,
       1,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     1,     3,     4,
       4,     3,     3,     3,     3,     4,     4,     3,     4,     6,
       4,     6,     4,     3,     4,     6,     6,     4,     6,     6,
       4,     1,     2,     1,     1,     1,     4,     5,     6,     3,
       3,     3,     3,     5,     7,     7,     5,     5,     5,     7,
       7,     5,     5,     3,     3,     5,     7,     5,     7,     1,
       4,     3,     5,     1,     2,     3,     3,     1,     3,     2,
       0,     1,     1,     2,     1,     3,     1,     3,     1,     4,
       1,     2,     3,     0,     1,     0,     1,     4,     2,     3,
       1,     0,     1,     4,     0,     1,     2,     1,     3,     0,
       1,     2,     2,     1,     0,     1,     0,     1,     1,     1,
       1,     1,     1,     1,     3,     3,     1,     1,     1,     2,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       2,     1,     1,     2,     2,     3,     1,     2,     2,     5,
       2,     1,     1,     0,     2,     1,     3,     4,     0,     2,
       0,     2,     4,     4,     3,     2,     3,     1,     3,     0,
       1,     1,     2,     2,     2,     2,     1,     2,     2,     2,
       2,     3,     2,     3,     3,     4,     2,     2,     1,     1,
       3,     2,     3,     2,     3,     2,     3,     3,     3,     3,
       5,     5,     5,     5,     8,     4,     4,     7,     5,     4,
       3,     2,     5,     4,     7,     6,     3,     3,     3,     1,
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
       1,     1,     1,     1,     1
  };

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
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
  "MULTIPLICATIVE_REDUCE", "JSONLOOKUPEXPR_REDUCE", "ANYKINDTEST_REDUCE",
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
  "JSONTest", "URI_LITERAL", "QNAME", "FUNCTION_NAME", "EQNAME", 0
  };
#endif

#if YYDEBUG
  /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
  const jsoniq_parser::rhs_number_type
  jsoniq_parser::yyrhs_[] =
  {
       342,     0,    -1,   344,    -1,   326,   344,    -1,   327,   344,
      -1,   326,   327,   344,    -1,     1,    -1,     1,     3,    -1,
     343,     1,    -1,   346,    -1,   345,   346,    -1,   347,    -1,
     345,   347,    -1,   216,   218,    30,   191,    -1,   216,   218,
      30,   133,    30,   191,    -1,   217,   218,    30,   191,    -1,
     217,   218,    30,   133,    30,   191,    -1,   349,   191,   396,
      -1,   366,   191,   396,    -1,   349,   191,   366,   191,   396,
      -1,   396,    -1,   349,   343,   396,    -1,   366,   343,   396,
      -1,   349,   191,   366,   343,   396,    -1,   349,   343,   366,
     191,   396,    -1,   348,    -1,   348,   349,   191,    -1,   348,
     366,   191,    -1,   348,   349,   191,   366,   191,    -1,    34,
     162,   665,   134,   664,   191,    -1,   350,    -1,   349,   191,
     350,    -1,   349,   343,   350,    -1,   351,    -1,   359,    -1,
     364,    -1,   365,    -1,   373,    -1,   352,    -1,   353,    -1,
     354,    -1,   355,    -1,   356,    -1,   357,    -1,   358,    -1,
     587,    -1,    33,    38,   183,    -1,    33,    38,   197,    -1,
      33,   114,   107,   664,    -1,    33,    37,   664,    -1,    33,
      40,   183,    -1,    33,    40,   197,    -1,    33,    58,   170,
      -1,    33,    58,   203,    -1,    33,   114,   169,   129,   130,
      -1,    33,   114,   169,   129,   131,    -1,    33,    41,   183,
     108,   150,    -1,    33,    41,   183,   108,   166,    -1,    33,
      41,   167,   108,   150,    -1,    33,    41,   167,   108,   166,
      -1,   360,    -1,   363,    -1,    49,    25,     1,    -1,    49,
      61,   664,    -1,    49,    61,   362,   664,    -1,    49,    61,
     664,    97,   361,    -1,    49,    61,   362,   664,    97,   361,
      -1,   664,    -1,   361,   108,   664,    -1,   162,   665,   134,
      -1,   114,    45,   162,    -1,    49,    34,   664,    -1,    49,
      34,   162,   665,   134,   664,    -1,    49,    34,   664,    97,
     361,    -1,    49,    34,   162,   665,   134,   664,    97,   361,
      -1,    33,   162,   665,   134,   664,    -1,    33,   114,    45,
     162,   664,    -1,    33,   114,    47,   162,   664,    -1,   367,
      -1,   366,   191,   367,    -1,   366,   343,   367,    -1,   368,
      -1,   372,    -1,   374,    -1,   378,    -1,   383,    -1,   390,
      -1,   392,    -1,   395,    -1,    33,   114,    80,   369,    -1,
      33,    80,   665,   369,    -1,   370,    -1,   369,   370,    -1,
     371,   134,   582,    -1,    81,    -1,    89,    -1,    82,    -1,
      83,    -1,    84,    -1,    85,    -1,    90,    -1,    86,    -1,
      87,    -1,    88,    -1,    33,    57,   665,    30,    -1,    33,
     266,   626,    -1,    33,   112,   154,   375,    -1,    95,   564,
     376,    -1,   376,    -1,   377,    -1,   139,    -1,   139,   377,
      -1,   144,   421,    -1,    33,   379,   144,   421,    -1,    33,
     379,   139,    -1,    33,   379,   139,   144,   421,    -1,   113,
     119,   665,    -1,   113,   119,   665,   561,    -1,   380,   113,
     119,   665,    -1,   380,   113,   119,   665,   561,    -1,   381,
      -1,   380,   381,    -1,    27,    -1,    27,   158,   382,   188,
      -1,    28,    -1,    28,   158,   382,   188,    -1,   521,    -1,
     382,   108,   521,    -1,    33,   384,    -1,    33,   380,   384,
      -1,   385,    -1,   386,    -1,    47,   666,   387,   404,    -1,
      47,   666,   387,   139,    -1,    75,    47,   666,   387,   404,
      -1,    75,    47,   666,   387,   139,    -1,   158,   188,    -1,
     158,   388,   188,    -1,   158,   188,    95,   562,    -1,   158,
     388,   188,    95,   562,    -1,   389,    -1,   388,   108,   389,
      -1,   119,   665,    -1,   119,   665,   561,    -1,    33,   292,
     665,    -1,    33,   292,   665,    95,   391,    -1,    33,   380,
     292,   665,    -1,    33,   380,   292,   665,    95,   391,    -1,
     568,    -1,   568,   563,    -1,   663,    -1,   663,   563,    -1,
      33,   300,   665,   304,   232,   504,   171,   393,    -1,    33,
     380,   300,   665,   304,   232,   504,   171,   393,    -1,   394,
      -1,   393,   108,   394,    -1,   504,    -1,   504,   561,    -1,
     504,   457,    -1,   504,   561,   457,    -1,    33,   308,   309,
     665,   304,   292,   665,   119,   665,   310,   421,    -1,    33,
     308,   309,   665,   304,   292,   665,   230,   119,   665,   310,
     298,   311,   504,    -1,    33,   308,   309,   665,   304,   292,
     665,   312,   230,   119,   665,   310,   421,    -1,    33,   308,
     309,   665,   313,   311,   262,   292,   665,   230,   119,   665,
     311,   504,   200,   292,   665,   230,   119,   665,   311,   504,
      -1,   397,    -1,   399,    -1,   400,    -1,    -1,   399,    -1,
     400,    -1,    -1,   420,    -1,   400,   420,    -1,   401,    -1,
     400,   401,    -1,   400,   420,   343,   401,    -1,   402,    -1,
     405,    -1,   408,    -1,   409,    -1,   410,    -1,   411,    -1,
     412,    -1,   413,    -1,   415,    -1,   469,    -1,   465,    -1,
     416,    -1,   419,    -1,   155,   400,   185,    -1,   155,   398,
     185,    -1,   155,   398,   185,    -1,   406,   191,    -1,   406,
     108,   407,    -1,   113,   407,    -1,   380,   113,   407,    -1,
     119,   665,    -1,   119,   665,   561,    -1,   119,   665,   144,
     421,    -1,   119,   665,   561,   144,   421,    -1,   119,   665,
     144,   421,   191,    -1,   422,   191,    -1,   245,   247,   421,
     191,    -1,   248,   158,   420,   188,   401,    -1,   243,   246,
     191,    -1,   244,   246,   191,    -1,   432,   414,    -1,   187,
     401,    -1,    48,   158,   420,   188,   199,   401,   128,   401,
      -1,   249,   402,   417,    -1,   418,    -1,   417,   418,    -1,
     250,   599,   402,    -1,   191,    -1,   421,    -1,   420,   108,
     421,    -1,   420,   343,   421,    -1,   423,    -1,   461,    -1,
     468,    -1,   475,    -1,   595,    -1,   422,    -1,   476,    -1,
     458,    -1,   588,    -1,   589,    -1,   591,    -1,   590,    -1,
     592,    -1,   660,    -1,   658,    -1,   661,    -1,   662,    -1,
     659,    -1,   432,   424,    -1,   187,   421,    -1,    67,   289,
      -1,    72,   289,    -1,   219,    -1,   259,    -1,    56,   259,
      -1,   426,   443,    78,   421,    -1,   426,    78,   421,    -1,
     434,   425,   442,   427,   427,    -1,   434,   425,   442,   427,
      -1,    42,   119,   665,    -1,   433,    -1,   439,    -1,   428,
      -1,   430,    -1,   446,    -1,   451,    -1,   447,    -1,   429,
      -1,   430,    -1,   432,   431,    -1,   434,   119,   435,    -1,
      46,     1,   435,    -1,   262,     1,   435,    -1,   434,     3,
      -1,    46,    -1,   262,    -1,   436,    -1,   435,   108,   119,
     436,    -1,   435,   108,   436,    -1,   665,   149,   421,    -1,
     665,    36,   129,   149,   421,    -1,   665,   561,   149,   421,
      -1,   665,   561,    36,   129,   149,   421,    -1,   665,   437,
     149,   421,    -1,   665,    36,   129,   437,   149,   421,    -1,
     665,   561,   437,   149,   421,    -1,   665,   561,    36,   129,
     437,   149,   421,    -1,   665,   438,   149,   421,    -1,   665,
     561,   438,   149,   421,    -1,   665,   437,   438,   149,   421,
      -1,   665,   561,   437,   438,   149,   421,    -1,    97,   119,
     665,    -1,   278,   119,   665,    -1,    51,   440,    -1,   441,
      -1,   440,   108,   441,    -1,   119,   665,   144,   421,    -1,
     119,   665,   561,   144,   421,    -1,   438,   144,   421,    -1,
     119,   665,   561,   438,   144,   421,    -1,   119,   665,   149,
     421,    -1,   119,   665,   561,   149,   421,    -1,   444,    -1,
     119,   665,    -1,   119,   665,   444,    -1,   437,    -1,   437,
     445,    -1,   445,    -1,    59,   119,   665,    54,   119,   665,
      -1,    54,   119,   665,    -1,    59,   119,   665,    -1,   213,
     421,    -1,   172,   171,   448,    -1,   449,    -1,   448,   108,
     449,    -1,   119,   665,   144,   421,    -1,   119,   665,   561,
     144,   421,    -1,   119,   665,   561,   144,   421,   450,    -1,
     119,   665,   144,   421,   450,    -1,   421,    -1,   421,   450,
      -1,   107,   664,    -1,   169,   171,   452,    -1,    70,   169,
     171,   452,    -1,   453,    -1,   452,   108,   453,    -1,   421,
      -1,   421,   454,    -1,   455,    -1,   456,    -1,   457,    -1,
     455,   456,    -1,   455,   457,    -1,   456,   457,    -1,   455,
     456,   457,    -1,    96,    -1,   117,    -1,   129,   130,    -1,
     129,   131,    -1,   107,   664,    -1,    68,   119,   459,   189,
     421,    -1,   137,   119,   459,   189,   421,    -1,   460,    -1,
     459,   108,   119,   460,    -1,   665,   149,   421,    -1,   665,
     561,   149,   421,    -1,    73,   158,   420,   188,   462,   114,
     187,   421,    -1,   463,    -1,   462,   463,    -1,   464,   187,
     421,    -1,   101,   421,    -1,   464,   101,   421,    -1,    73,
     158,   420,   188,   466,   114,   187,   401,    -1,   467,    -1,
     466,   467,    -1,   464,   187,   401,    -1,    74,   158,   420,
     188,   470,   114,   187,   421,    -1,    74,   158,   420,   188,
     470,   114,   119,   665,   187,   421,    -1,    74,   158,   420,
     188,   472,   114,   187,   401,    -1,    74,   158,   420,   188,
     470,   114,   119,   665,   187,   401,    -1,   471,    -1,   470,
     471,    -1,   101,   474,   187,   421,    -1,   101,   119,   665,
      95,   474,   187,   421,    -1,   473,    -1,   472,   473,    -1,
     101,   474,   187,   401,    -1,   101,   119,   665,    95,   474,
     187,   401,    -1,   562,    -1,   474,   211,   562,    -1,    48,
     158,   420,   188,   199,   421,   128,   421,    -1,   477,    -1,
     476,   168,   477,    -1,   478,    -1,   477,    93,   478,    -1,
     479,    -1,   265,   478,    -1,   481,    -1,   481,   498,   481,
      -1,   481,   499,   481,    -1,   481,   134,   481,    -1,   481,
     164,   481,    -1,    -1,   481,   159,   480,   481,    -1,   481,
     157,   481,    -1,   481,   145,   481,    -1,   481,   143,   481,
      -1,   482,    -1,   482,   254,    71,   600,   483,    -1,   484,
      -1,   484,   100,   482,    -1,    -1,   652,    -1,   485,    -1,
     485,   200,   485,    -1,   486,    -1,   485,   177,   486,    -1,
     485,   160,   486,    -1,   487,    -1,   486,   195,   487,    -1,
     486,   118,   487,    -1,   486,   148,   487,    -1,   486,   161,
     487,    -1,   488,    -1,   487,   202,   488,    -1,   487,   211,
     488,    -1,   489,    -1,   488,   152,   489,    -1,   488,   138,
     489,    -1,   490,    -1,   490,    50,   236,   562,    -1,   491,
      -1,   491,   201,    95,   562,    -1,   492,    -1,   492,   102,
      95,   493,    -1,   494,    -1,   494,   103,    95,   493,    -1,
     567,    -1,   567,   146,    -1,   496,    -1,   495,   496,    -1,
     177,    -1,   160,    -1,   495,   177,    -1,   495,   160,    -1,
     500,    -1,   497,    -1,   501,    -1,   504,    -1,   497,   194,
     504,    -1,   204,    -1,   209,    -1,   208,    -1,   207,    -1,
     206,    -1,   205,    -1,   153,    -1,   180,    -1,   142,    -1,
      76,   155,   399,   185,    -1,    76,   227,   155,   399,   185,
      -1,    76,   226,   155,   399,   185,    -1,    76,    77,   580,
     155,   399,   185,    -1,   502,   155,   185,    -1,   502,   155,
     420,   185,    -1,   503,    -1,   502,   503,    -1,   178,   665,
      17,    -1,   178,    18,    -1,   178,    19,    -1,   505,    -1,
     505,   506,    -1,   193,   506,    -1,   506,    -1,   192,    -1,
     507,    -1,   507,   192,   506,    -1,   507,   193,   506,    -1,
     508,    -1,   517,    -1,   509,    -1,   509,   518,    -1,   512,
      -1,   512,   518,    -1,   510,   514,    -1,   511,    -1,   106,
     124,    -1,   115,   124,    -1,    98,   124,    -1,   190,   124,
      -1,   116,   124,    -1,   141,   124,    -1,   140,   124,    -1,
     514,    -1,    99,   514,    -1,   513,   514,    -1,   122,    -1,
     173,   124,    -1,    91,   124,    -1,   182,   124,    -1,   181,
     124,    -1,    92,   124,    -1,   568,    -1,   515,    -1,   665,
      -1,   516,    -1,   195,    -1,    11,    -1,    12,    -1,    20,
      -1,   520,    -1,   517,   518,    -1,   517,   158,   188,    -1,
     517,   158,   530,   188,    -1,   517,   156,   186,    -1,   517,
     121,   665,    -1,   517,   121,   158,   188,    -1,   517,   121,
     158,   420,   188,    -1,   517,   121,   524,    -1,   517,   121,
     582,    -1,   519,    -1,   518,   519,    -1,   156,   420,   186,
      -1,   521,    -1,   524,    -1,   525,    -1,   526,    -1,   529,
      -1,   534,    -1,   527,    -1,   528,    -1,   531,    -1,   403,
      -1,   656,    -1,   653,    -1,   654,    -1,   655,    -1,   522,
      -1,   582,    -1,   523,    -1,   220,    -1,   111,    -1,   151,
      -1,   126,    -1,   221,    -1,   222,    -1,   119,   665,    -1,
     158,   188,    -1,   158,   420,   188,    -1,   120,    -1,   170,
     155,   420,   185,    -1,   203,   155,   420,   185,    -1,   666,
     158,   188,    -1,   666,   158,   530,   188,    -1,   146,    -1,
     530,   108,   146,    -1,   421,    -1,   530,   108,   421,    -1,
     532,    -1,   533,    -1,   666,   147,   151,    -1,    47,   387,
     404,    -1,   535,    -1,   553,    -1,   536,    -1,   550,    -1,
     551,    -1,   159,   665,   540,   132,    -1,   159,   665,   540,
     198,   196,   665,   540,   198,    -1,   159,   665,   538,   540,
     132,    -1,   159,   665,   538,   540,   198,   196,   665,   540,
     198,    -1,   159,   665,   540,   198,   537,   196,   665,   540,
     198,    -1,   159,   665,   538,   540,   198,   537,   196,   665,
     540,   198,    -1,   548,    -1,   537,   548,    -1,   539,    -1,
     538,   539,    -1,    35,   665,   540,   134,   540,   541,    -1,
      -1,    35,    -1,   184,   542,   184,    -1,    94,   544,    94,
      -1,    -1,   543,    -1,   136,    -1,   546,    -1,   543,   136,
      -1,   543,   546,    -1,    -1,   545,    -1,   135,    -1,   547,
      -1,   545,   135,    -1,   545,   547,    -1,    29,    -1,   549,
      -1,     5,    -1,   549,    -1,   535,    -1,    10,    -1,   552,
      -1,   549,    -1,     9,    -1,   125,    -1,   127,    -1,   155,
     399,   185,    -1,   214,    31,   215,    -1,   214,   215,    -1,
     175,   665,   176,    -1,   175,   665,     8,    -1,   104,     7,
      -1,   554,    -1,   555,    -1,   556,    -1,   557,    -1,   558,
      -1,   559,    -1,   560,    -1,    43,   155,   399,   185,    -1,
      21,   398,   185,    -1,    45,   155,   420,   185,   155,   398,
     185,    -1,    22,   398,   185,    -1,    98,   155,   420,   185,
     155,   398,   185,    -1,    71,   155,   399,   185,    -1,    39,
     155,   399,   185,    -1,    23,   398,   185,    -1,    60,   155,
     420,   185,   155,   398,   185,    -1,    24,   399,   185,    -1,
     162,   155,   420,   185,   155,   399,   185,    -1,    95,   562,
      -1,   564,    -1,   564,   563,    -1,   212,   158,   188,    -1,
     158,   188,    -1,   146,    -1,   195,    -1,   177,    -1,   566,
      -1,   568,    -1,   154,   158,   188,    -1,   325,   158,   188,
      -1,   583,    -1,   586,    -1,   663,    -1,   562,    -1,   565,
     108,   562,    -1,   665,    -1,   220,    -1,   665,    -1,   571,
      -1,   578,    -1,   576,    -1,   579,    -1,   577,    -1,   575,
      -1,   574,    -1,   573,    -1,   572,    -1,   569,    -1,   570,
     158,   188,    -1,   230,    -1,    44,   158,   188,    -1,    44,
     158,   578,   188,    -1,    44,   158,   579,   188,    -1,    53,
     158,   188,    -1,    71,   158,   188,    -1,    39,   158,   188,
      -1,    60,   158,   188,    -1,    60,   158,   665,   188,    -1,
      60,   158,    30,   188,    -1,    98,   158,   188,    -1,    98,
     158,   665,   188,    -1,    98,   158,   665,   108,   580,   188,
      -1,    98,   158,   195,   188,    -1,    98,   158,   195,   108,
     580,   188,    -1,    62,   158,   665,   188,    -1,    45,   158,
     188,    -1,    45,   158,   665,   188,    -1,    45,   158,   665,
     108,   580,   188,    -1,    45,   158,   665,   108,   581,   188,
      -1,    45,   158,   195,   188,    -1,    45,   158,   195,   108,
     580,   188,    -1,    45,   158,   195,   108,   581,   188,    -1,
      63,   158,   665,   188,    -1,   665,    -1,   665,   146,    -1,
      30,    -1,   584,    -1,   585,    -1,    47,   158,   195,   188,
      -1,    47,   158,   188,    95,   562,    -1,    47,   158,   565,
     188,    95,   562,    -1,   158,   564,   188,    -1,    33,   225,
     226,    -1,    33,   225,   227,    -1,    33,   225,   228,    -1,
     231,   230,   421,   238,   421,    -1,   231,   230,   421,    95,
     237,   238,   421,    -1,   231,   230,   421,    95,   239,   238,
     421,    -1,   231,   230,   421,   223,   421,    -1,   231,   230,
     421,   224,   421,    -1,   231,   232,   421,   238,   421,    -1,
     231,   232,   421,    95,   237,   238,   421,    -1,   231,   232,
     421,    95,   239,   238,   421,    -1,   231,   232,   421,   223,
     421,    -1,   231,   232,   421,   224,   421,    -1,   229,   230,
     421,    -1,   229,   232,   421,    -1,   234,   230,   421,   242,
     421,    -1,   234,   235,   236,   230,   421,   242,   421,    -1,
     233,   230,   421,    95,   421,    -1,   241,   119,   593,   240,
     421,   187,   421,    -1,   594,    -1,   593,   108,   119,   594,
      -1,   665,   144,   421,    -1,   249,   155,   420,   185,   596,
      -1,   597,    -1,   596,   597,    -1,   250,   599,   598,    -1,
     155,   420,   185,    -1,   515,    -1,   599,   211,   515,    -1,
     603,   601,    -1,    -1,   602,    -1,   621,    -1,   602,   621,
      -1,   604,    -1,   603,   267,   604,    -1,   605,    -1,   604,
     263,   605,    -1,   606,    -1,   605,   265,   149,   606,    -1,
     607,    -1,   264,   607,    -1,   611,   608,   609,    -1,    -1,
     626,    -1,    -1,   610,    -1,   287,   155,   420,   185,    -1,
     615,   612,    -1,   158,   600,   188,    -1,   613,    -1,    -1,
     648,    -1,   502,   155,   614,   185,    -1,    -1,   600,    -1,
     616,   617,    -1,   521,    -1,   155,   420,   185,    -1,    -1,
     618,    -1,   253,   619,    -1,   252,   620,    -1,   275,    -1,
      -1,    79,    -1,    -1,   291,    -1,   622,    -1,   623,    -1,
     624,    -1,   650,    -1,   647,    -1,   170,    -1,   289,   485,
     625,    -1,   258,   649,   625,    -1,   291,    -1,   281,    -1,
     274,    -1,   251,   627,    -1,   626,   251,   627,    -1,   628,
      -1,   629,    -1,   630,    -1,   645,    -1,   631,    -1,   639,
      -1,   632,    -1,   646,    -1,   101,   279,    -1,   101,   268,
      -1,   271,    -1,   286,    -1,   256,   279,    -1,   256,   268,
      -1,    57,   665,    30,    -1,   282,    -1,    55,   282,    -1,
     284,   633,    -1,   284,   158,   633,   634,   188,    -1,    55,
     284,    -1,   636,    -1,   114,    -1,    -1,   108,   635,    -1,
     636,    -1,   635,   108,   636,    -1,    97,    30,   637,   638,
      -1,    -1,   276,    30,    -1,    -1,   649,   270,    -1,   283,
     291,   640,   642,    -1,   283,   291,   114,   642,    -1,    55,
     283,   291,    -1,    97,    30,    -1,   158,   641,   188,    -1,
      30,    -1,   641,   108,    30,    -1,    -1,   643,    -1,   644,
      -1,   643,   644,    -1,   202,   640,    -1,   138,   640,    -1,
     269,    30,    -1,   288,    -1,    55,   288,    -1,    97,   219,
      -1,    97,   259,    -1,   260,   255,    -1,   272,   649,   285,
      -1,   261,   485,    -1,    97,   131,   485,    -1,    97,    52,
     485,    -1,   262,   485,   200,   485,    -1,   277,   651,    -1,
     257,   651,    -1,   280,    -1,   273,    -1,   290,   255,   487,
      -1,   156,   186,    -1,   156,   420,   186,    -1,   315,   316,
      -1,   315,   420,   316,    -1,   317,   318,    -1,   317,   420,
     318,    -1,   155,   657,   185,    -1,   665,   123,   421,    -1,
     421,   123,   421,    -1,   657,   108,   421,   123,   421,    -1,
     657,   108,   665,   123,   421,    -1,   231,   319,   421,   238,
     421,    -1,   231,   319,   657,   238,   421,    -1,   231,   319,
     421,   238,   421,    97,   321,   421,    -1,   231,   421,   238,
     421,    -1,   231,   657,   238,   421,    -1,   231,   421,   238,
     421,    97,   321,   421,    -1,   320,   319,   421,   238,   421,
      -1,   320,   421,   238,   421,    -1,   229,   319,   517,    -1,
     229,   517,    -1,   233,   319,   517,    95,   421,    -1,   233,
     517,    95,   421,    -1,   234,   319,   235,   236,   517,   242,
     421,    -1,   234,   235,   236,   517,   242,   421,    -1,   324,
     158,   188,    -1,   323,   158,   188,    -1,   322,   158,   188,
      -1,   322,    -1,    30,    -1,   666,    -1,    16,    -1,    98,
      -1,    39,    -1,    44,    -1,    53,    -1,    45,    -1,   154,
      -1,    48,    -1,   230,    -1,    60,    -1,    62,    -1,    63,
      -1,    71,    -1,    74,    -1,    73,    -1,   212,    -1,   248,
      -1,   319,    -1,   320,    -1,   324,    -1,   323,    -1,   325,
      -1,   667,    -1,    25,    -1,   216,    -1,   129,    -1,    38,
      -1,   266,    -1,    37,    -1,   227,    -1,   226,    -1,   148,
      -1,    43,    -1,   264,    -1,   265,    -1,   279,    -1,   268,
      -1,   256,    -1,   290,    -1,   282,    -1,   284,    -1,   283,
      -1,   288,    -1,   260,    -1,   255,    -1,    79,    -1,   219,
      -1,   259,    -1,    52,    -1,   228,    -1,   241,    -1,   307,
      -1,   235,    -1,   204,    -1,   209,    -1,   208,    -1,   207,
      -1,   206,    -1,   205,    -1,    97,    -1,   112,    -1,   113,
      -1,   187,    -1,    46,    -1,   262,    -1,    36,    -1,    67,
      -1,    72,    -1,    59,    -1,    54,    -1,    56,    -1,    78,
      -1,    42,    -1,   149,    -1,    51,    -1,   213,    -1,   171,
      -1,   172,    -1,   169,    -1,    70,    -1,    96,    -1,   117,
      -1,   130,    -1,   131,    -1,   107,    -1,    68,    -1,   137,
      -1,   189,    -1,   101,    -1,    95,    -1,   199,    -1,   128,
      -1,   168,    -1,    93,    -1,    50,    -1,   236,    -1,   102,
      -1,   200,    -1,   118,    -1,   161,    -1,   202,    -1,   152,
      -1,   138,    -1,    76,    -1,    77,    -1,   103,    -1,   201,
      -1,   153,    -1,   183,    -1,   197,    -1,   162,    -1,   139,
      -1,   133,    -1,   167,    -1,   150,    -1,   166,    -1,    33,
      -1,    40,    -1,    58,    -1,   114,    -1,    41,    -1,    57,
      -1,   218,    -1,    49,    -1,    61,    -1,    34,    -1,    47,
      -1,   278,    -1,   254,    -1,   287,    -1,   289,    -1,   258,
      -1,   272,    -1,   285,    -1,   277,    -1,   257,    -1,   271,
      -1,   286,    -1,   276,    -1,   270,    -1,   269,    -1,   253,
      -1,   252,    -1,   261,    -1,   291,    -1,   281,    -1,   280,
      -1,   275,    -1,   273,    -1,   274,    -1,   240,    -1,   237,
      -1,   234,    -1,   231,    -1,   233,    -1,   229,    -1,   224,
      -1,   223,    -1,   225,    -1,   242,    -1,   232,    -1,   239,
      -1,   238,    -1,    66,    -1,    64,    -1,    75,    -1,   170,
      -1,   203,    -1,   247,    -1,   245,    -1,   246,    -1,   243,
      -1,   244,    -1,   249,    -1,   250,    -1,   251,    -1,    65,
      -1,   300,    -1,   298,    -1,   299,    -1,   304,    -1,   305,
      -1,   306,    -1,   301,    -1,   302,    -1,   303,    -1,    80,
      -1,    81,    -1,    82,    -1,    83,    -1,    84,    -1,    85,
      -1,    86,    -1,    87,    -1,    88,    -1,    89,    -1,    90,
      -1,   292,    -1,   293,    -1,   294,    -1,   295,    -1,   296,
      -1,   297,    -1,   308,    -1,   309,    -1,   310,    -1,   311,
      -1,   312,    -1,   313,    -1,   314,    -1,    91,    -1,   106,
      -1,   115,    -1,   173,    -1,   181,    -1,   190,    -1,   140,
      -1,    92,    -1,   116,    -1,   141,    -1,   182,    -1,   321,
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
     938,   941,   943,   945,   947,   952,   956,   960,   966,   971,
     978,   983,   990,   996,  1004,  1009,  1015,  1021,  1028,  1032,
    1036,  1039,  1041,  1045,  1050,  1056,  1060,  1067,  1072,  1078,
    1080,  1083,  1087,  1089,  1092,  1094,  1101,  1105,  1109,  1112,
    1116,  1118,  1122,  1127,  1133,  1140,  1146,  1148,  1151,  1154,
    1158,  1163,  1165,  1169,  1171,  1174,  1176,  1178,  1180,  1183,
    1186,  1189,  1193,  1195,  1197,  1200,  1203,  1206,  1212,  1218,
    1220,  1225,  1229,  1234,  1243,  1245,  1248,  1252,  1255,  1259,
    1268,  1270,  1273,  1277,  1286,  1297,  1306,  1317,  1319,  1322,
    1327,  1335,  1337,  1340,  1345,  1353,  1355,  1359,  1368,  1370,
    1374,  1376,  1380,  1382,  1385,  1387,  1391,  1395,  1399,  1403,
    1404,  1409,  1413,  1417,  1421,  1423,  1429,  1431,  1435,  1436,
    1438,  1440,  1444,  1446,  1450,  1454,  1456,  1460,  1464,  1468,
    1472,  1474,  1478,  1482,  1484,  1488,  1492,  1494,  1499,  1501,
    1506,  1508,  1513,  1515,  1520,  1522,  1525,  1527,  1530,  1532,
    1534,  1537,  1540,  1542,  1544,  1546,  1548,  1552,  1554,  1556,
    1558,  1560,  1562,  1564,  1566,  1568,  1570,  1575,  1581,  1587,
    1594,  1598,  1603,  1605,  1608,  1612,  1615,  1618,  1620,  1623,
    1626,  1628,  1630,  1632,  1636,  1640,  1642,  1644,  1646,  1649,
    1651,  1654,  1657,  1659,  1662,  1665,  1668,  1671,  1674,  1677,
    1680,  1682,  1685,  1688,  1690,  1693,  1696,  1699,  1702,  1705,
    1707,  1709,  1711,  1713,  1715,  1717,  1719,  1721,  1723,  1726,
    1730,  1735,  1739,  1743,  1748,  1754,  1758,  1762,  1764,  1767,
    1771,  1773,  1775,  1777,  1779,  1781,  1783,  1785,  1787,  1789,
    1791,  1793,  1795,  1797,  1799,  1801,  1803,  1805,  1807,  1809,
    1811,  1813,  1815,  1817,  1820,  1823,  1827,  1829,  1834,  1839,
    1843,  1848,  1850,  1854,  1856,  1860,  1862,  1864,  1868,  1872,
    1874,  1876,  1878,  1880,  1882,  1887,  1896,  1902,  1912,  1922,
    1933,  1935,  1938,  1940,  1943,  1950,  1951,  1953,  1957,  1961,
    1962,  1964,  1966,  1968,  1971,  1974,  1975,  1977,  1979,  1981,
    1984,  1987,  1989,  1991,  1993,  1995,  1997,  1999,  2001,  2003,
    2005,  2007,  2009,  2013,  2017,  2020,  2024,  2028,  2031,  2033,
    2035,  2037,  2039,  2041,  2043,  2045,  2050,  2054,  2062,  2066,
    2074,  2079,  2084,  2088,  2096,  2100,  2108,  2111,  2113,  2116,
    2120,  2123,  2125,  2127,  2129,  2131,  2133,  2137,  2141,  2143,
    2145,  2147,  2149,  2153,  2155,  2157,  2159,  2161,  2163,  2165,
    2167,  2169,  2171,  2173,  2175,  2177,  2179,  2183,  2185,  2189,
    2194,  2199,  2203,  2207,  2211,  2215,  2220,  2225,  2229,  2234,
    2241,  2246,  2253,  2258,  2262,  2267,  2274,  2281,  2286,  2293,
    2300,  2305,  2307,  2310,  2312,  2314,  2316,  2321,  2327,  2334,
    2338,  2342,  2346,  2350,  2356,  2364,  2372,  2378,  2384,  2390,
    2398,  2406,  2412,  2418,  2422,  2426,  2432,  2440,  2446,  2454,
    2456,  2461,  2465,  2471,  2473,  2476,  2480,  2484,  2486,  2490,
    2493,  2494,  2496,  2498,  2501,  2503,  2507,  2509,  2513,  2515,
    2520,  2522,  2525,  2529,  2530,  2532,  2533,  2535,  2540,  2543,
    2547,  2549,  2550,  2552,  2557,  2558,  2560,  2563,  2565,  2569,
    2570,  2572,  2575,  2578,  2580,  2581,  2583,  2584,  2586,  2588,
    2590,  2592,  2594,  2596,  2598,  2602,  2606,  2608,  2610,  2612,
    2615,  2619,  2621,  2623,  2625,  2627,  2629,  2631,  2633,  2635,
    2638,  2641,  2643,  2645,  2648,  2651,  2655,  2657,  2660,  2663,
    2669,  2672,  2674,  2676,  2677,  2680,  2682,  2686,  2691,  2692,
    2695,  2696,  2699,  2704,  2709,  2713,  2716,  2720,  2722,  2726,
    2727,  2729,  2731,  2734,  2737,  2740,  2743,  2745,  2748,  2751,
    2754,  2757,  2761,  2764,  2768,  2772,  2777,  2780,  2783,  2785,
    2787,  2791,  2794,  2798,  2801,  2805,  2808,  2812,  2816,  2820,
    2824,  2830,  2836,  2842,  2848,  2857,  2862,  2867,  2875,  2881,
    2886,  2890,  2893,  2899,  2904,  2912,  2919,  2923,  2927,  2931,
    2933,  2935,  2937,  2939,  2941,  2943,  2945,  2947,  2949,  2951,
    2953,  2955,  2957,  2959,  2961,  2963,  2965,  2967,  2969,  2971,
    2973,  2975,  2977,  2979,  2981,  2983,  2985,  2987,  2989,  2991,
    2993,  2995,  2997,  2999,  3001,  3003,  3005,  3007,  3009,  3011,
    3013,  3015,  3017,  3019,  3021,  3023,  3025,  3027,  3029,  3031,
    3033,  3035,  3037,  3039,  3041,  3043,  3045,  3047,  3049,  3051,
    3053,  3055,  3057,  3059,  3061,  3063,  3065,  3067,  3069,  3071,
    3073,  3075,  3077,  3079,  3081,  3083,  3085,  3087,  3089,  3091,
    3093,  3095,  3097,  3099,  3101,  3103,  3105,  3107,  3109,  3111,
    3113,  3115,  3117,  3119,  3121,  3123,  3125,  3127,  3129,  3131,
    3133,  3135,  3137,  3139,  3141,  3143,  3145,  3147,  3149,  3151,
    3153,  3155,  3157,  3159,  3161,  3163,  3165,  3167,  3169,  3171,
    3173,  3175,  3177,  3179,  3181,  3183,  3185,  3187,  3189,  3191,
    3193,  3195,  3197,  3199,  3201,  3203,  3205,  3207,  3209,  3211,
    3213,  3215,  3217,  3219,  3221,  3223,  3225,  3227,  3229,  3231,
    3233,  3235,  3237,  3239,  3241,  3243,  3245,  3247,  3249,  3251,
    3253,  3255,  3257,  3259,  3261,  3263,  3265,  3267,  3269,  3271,
    3273,  3275,  3277,  3279,  3281,  3283,  3285,  3287,  3289,  3291,
    3293,  3295,  3297,  3299,  3301,  3303,  3305,  3307,  3309,  3311,
    3313,  3315,  3317,  3319,  3321,  3323,  3325,  3327,  3329,  3331,
    3333,  3335,  3337,  3339,  3341,  3343,  3345,  3347,  3349,  3351,
    3353,  3355,  3357,  3359,  3361,  3363,  3365,  3367,  3369,  3371,
    3373,  3375,  3377,  3379,  3381
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  jsoniq_parser::yyrline_[] =
  {
         0,   852,   852,   853,   857,   861,   867,   871,   875,   881,
     887,   895,   901,   910,   915,   920,   925,   931,   937,   943,
     951,   956,   964,   972,   980,   989,   994,  1000,  1006,  1015,
    1023,  1030,  1036,  1045,  1046,  1047,  1048,  1049,  1052,  1053,
    1054,  1055,  1056,  1057,  1058,  1059,  1062,  1067,  1073,  1079,
    1085,  1090,  1096,  1101,  1107,  1112,  1118,  1123,  1128,  1133,
    1139,  1141,  1143,  1151,  1156,  1164,  1172,  1181,  1188,  1196,
    1202,  1208,  1214,  1221,  1229,  1240,  1247,  1254,  1262,  1269,
    1275,  1284,  1285,  1286,  1287,  1288,  1289,  1290,  1291,  1294,
    1300,  1307,  1314,  1322,  1330,  1331,  1332,  1333,  1334,  1335,
    1336,  1337,  1338,  1339,  1342,  1356,  1362,  1368,  1375,  1381,
    1388,  1393,  1399,  1405,  1417,  1429,  1442,  1447,  1455,  1463,
    1472,  1477,  1484,  1489,  1496,  1501,  1509,  1514,  1521,  1527,
    1536,  1537,  1540,  1551,  1564,  1576,  1589,  1594,  1599,  1604,
    1610,  1617,  1625,  1630,  1638,  1646,  1654,  1662,  1672,  1676,
    1682,  1686,  1693,  1702,  1713,  1719,  1726,  1731,  1738,  1745,
    1754,  1764,  1774,  1784,  1799,  1815,  1819,  1824,  1829,  1833,
    1838,  1843,  1848,  1856,  1863,  1870,  1883,  1884,  1885,  1886,
    1887,  1888,  1889,  1890,  1891,  1892,  1893,  1894,  1895,  1898,
    1904,  1926,  1932,  1938,  1945,  1952,  1961,  1970,  1979,  1988,
    1999,  2005,  2011,  2017,  2029,  2034,  2040,  2052,  2065,  2085,
    2091,  2098,  2107,  2114,  2120,  2125,  2137,  2149,  2150,  2151,
    2152,  2153,  2154,  2157,  2158,  2159,  2160,  2161,  2162,  2163,
    2164,  2165,  2166,  2167,  2168,  2171,  2183,  2189,  2194,  2200,
    2205,  2210,  2216,  2225,  2235,  2247,  2259,  2265,  2266,  2267,
    2270,  2271,  2272,  2273,  2274,  2277,  2284,  2292,  2297,  2305,
    2314,  2323,  2324,  2329,  2336,  2343,  2353,  2363,  2373,  2383,
    2393,  2403,  2413,  2423,  2433,  2442,  2452,  2462,  2474,  2480,
    2486,  2492,  2498,  2506,  2514,  2522,  2530,  2540,  2546,  2555,
    2556,  2560,  2567,  2571,  2576,  2579,  2583,  2587,  2593,  2599,
    2605,  2611,  2619,  2623,  2631,  2639,  2647,  2655,  2665,  2671,
    2677,  2685,  2691,  2699,  2703,  2711,  2717,  2723,  2729,  2738,
    2747,  2756,  2767,  2771,  2777,  2783,  2791,  2797,  2806,  2817,
    2823,  2831,  2835,  2844,  2850,  2856,  2864,  2870,  2876,  2884,
    2890,  2896,  2904,  2910,  2917,  2927,  2934,  2944,  2950,  2958,
    2964,  2973,  2979,  2987,  2993,  3002,  3008,  3016,  3022,  3026,
    3032,  3037,  3043,  3047,  3058,  3062,  3071,  3077,  3086,  3096,
    3095,  3108,  3117,  3126,  3137,  3141,  3152,  3156,  3162,  3165,
    3171,  3175,  3181,  3185,  3189,  3195,  3199,  3205,  3211,  3217,
    3225,  3229,  3233,  3239,  3243,  3249,  3257,  3261,  3269,  3273,
    3281,  3285,  3293,  3297,  3305,  3309,  3315,  3319,  3325,  3329,
    3333,  3337,  3345,  3346,  3347,  3350,  3355,  3361,  3365,  3369,
    3373,  3377,  3381,  3387,  3391,  3395,  3401,  3405,  3409,  3413,
    3422,  3428,  3436,  3442,  3450,  3454,  3458,  3464,  3468,  3476,
    3484,  3503,  3509,  3519,  3523,  3529,  3530,  3533,  3539,  3547,
    3553,  3563,  3569,  3577,  3581,  3585,  3589,  3593,  3599,  3605,
    3611,  3615,  3621,  3625,  3634,  3638,  3642,  3648,  3652,  3660,
    3661,  3664,  3668,  3674,  3678,  3682,  3686,  3692,  3696,  3700,
    3704,  3708,  3712,  3718,  3724,  3730,  3734,  3740,  3746,  3754,
    3760,  3761,  3762,  3763,  3764,  3765,  3766,  3767,  3768,  3769,
    3770,  3771,  3772,  3773,  3776,  3780,  3784,  3789,  3796,  3803,
    3810,  3819,  3823,  3829,  3835,  3839,  3845,  3852,  3858,  3864,
    3868,  3886,  3892,  3898,  3904,  3912,  3916,  3922,  3928,  3938,
    3939,  3942,  3943,  3944,  3947,  3955,  3971,  3979,  3995,  4013,
    4033,  4039,  4048,  4054,  4063,  4070,  4071,  4073,  4078,  4085,
    4088,  4094,  4100,  4106,  4113,  4122,  4125,  4131,  4137,  4143,
    4150,  4159,  4163,  4169,  4173,  4179,  4183,  4187,  4192,  4199,
    4203,  4207,  4211,  4217,  4222,  4228,  4234,  4241,  4247,  4252,
    4257,  4262,  4267,  4272,  4277,  4280,  4286,  4290,  4296,  4300,
    4306,  4312,  4318,  4322,  4328,  4332,  4338,  4344,  4348,  4352,
    4356,  4363,  4369,  4375,  4383,  4411,  4415,  4419,  4423,  4427,
    4431,  4437,  4443,  4451,  4455,  4461,  4467,  4471,  4475,  4479,
    4483,  4487,  4491,  4495,  4499,  4503,  4509,  4515,  4521,  4525,
    4529,  4535,  4540,  4546,  4552,  4556,  4561,  4567,  4571,  4577,
    4583,  4587,  4595,  4601,  4605,  4611,  4620,  4629,  4635,  4641,
    4649,  4655,  4661,  4667,  4673,  4677,  4683,  4689,  4693,  4701,
    4707,  4713,  4719,  4727,  4731,  4737,  4743,  4747,  4753,  4757,
    4763,  4769,  4776,  4784,  4789,  4795,  4801,  4809,  4815,  4822,
    4828,  4837,  4843,  4849,  4855,  4864,  4871,  4877,  4883,  4892,
    4899,  4903,  4909,  4914,  4921,  4925,  4931,  4935,  4941,  4945,
    4951,  4955,  4963,  4974,  4977,  4983,  4986,  4992,  4998,  5006,
    5010,  5016,  5019,  5025,  5035,  5038,  5044,  5054,  5060,  5068,
    5071,  5077,  5081,  5085,  5091,  5094,  5100,  5103,  5109,  5113,
    5117,  5121,  5125,  5131,  5137,  5147,  5157,  5161,  5165,  5171,
    5177,  5185,  5189,  5193,  5197,  5201,  5205,  5209,  5213,  5219,
    5223,  5227,  5231,  5237,  5243,  5251,  5259,  5263,  5269,  5279,
    5290,  5296,  5300,  5306,  5309,  5315,  5320,  5327,  5335,  5338,
    5344,  5348,  5354,  5363,  5370,  5378,  5382,  5388,  5394,  5402,
    5405,  5411,  5416,  5426,  5434,  5444,  5450,  5454,  5460,  5464,
    5468,  5474,  5480,  5484,  5488,  5492,  5498,  5506,  5516,  5520,
    5526,  5532,  5536,  5542,  5546,  5552,  5556,  5562,  5569,  5579,
    5585,  5592,  5603,  5609,  5619,  5623,  5630,  5641,  5648,  5652,
    5659,  5678,  5700,  5722,  5747,  5769,  5794,  5798,  5802,  5806,
    5813,  5816,  5817,  5818,  5819,  5820,  5821,  5822,  5823,  5824,
    5825,  5826,  5827,  5828,  5829,  5830,  5831,  5832,  5833,  5834,
    5835,  5836,  5837,  5838,  5841,  5842,  5843,  5844,  5845,  5846,
    5847,  5848,  5849,  5850,  5851,  5852,  5853,  5854,  5855,  5856,
    5857,  5858,  5859,  5860,  5861,  5862,  5863,  5864,  5865,  5866,
    5867,  5868,  5869,  5870,  5871,  5872,  5873,  5874,  5875,  5876,
    5877,  5878,  5879,  5880,  5881,  5882,  5883,  5884,  5885,  5886,
    5887,  5888,  5889,  5890,  5891,  5892,  5893,  5894,  5895,  5896,
    5897,  5898,  5899,  5900,  5901,  5902,  5903,  5904,  5905,  5906,
    5907,  5908,  5909,  5910,  5911,  5912,  5913,  5914,  5915,  5916,
    5917,  5918,  5919,  5920,  5921,  5922,  5923,  5924,  5925,  5926,
    5927,  5928,  5929,  5930,  5931,  5932,  5933,  5934,  5935,  5936,
    5937,  5938,  5939,  5940,  5941,  5942,  5943,  5944,  5945,  5946,
    5947,  5948,  5949,  5950,  5951,  5952,  5953,  5954,  5955,  5956,
    5957,  5958,  5959,  5960,  5961,  5962,  5963,  5964,  5965,  5966,
    5967,  5968,  5969,  5970,  5971,  5972,  5973,  5974,  5975,  5976,
    5977,  5978,  5979,  5980,  5981,  5982,  5983,  5984,  5985,  5986,
    5987,  5988,  5989,  5990,  5991,  5992,  5993,  5994,  5995,  5996,
    5997,  5998,  5999,  6000,  6001,  6002,  6003,  6004,  6005,  6006,
    6007,  6008,  6009,  6010,  6011,  6012,  6013,  6014,  6015,  6016,
    6017,  6018,  6019,  6020,  6021,  6022,  6023,  6024,  6025,  6026,
    6027,  6028,  6029,  6030,  6031,  6032,  6033,  6034,  6035,  6036,
    6037,  6038,  6039,  6040,  6043
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
     335,   336,   337,   338,   339,   340
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int jsoniq_parser::yyeof_ = 0;
  const int jsoniq_parser::yylast_ = 22208;
  const int jsoniq_parser::yynnts_ = 327;
  const int jsoniq_parser::yyempty_ = -2;
  const int jsoniq_parser::yyfinal_ = 635;
  const int jsoniq_parser::yyterror_ = 1;
  const int jsoniq_parser::yyerrcode_ = 256;
  const int jsoniq_parser::yyntokens_ = 341;

  const unsigned int jsoniq_parser::yyuser_token_number_max_ = 595;
  const jsoniq_parser::token_number_type jsoniq_parser::yyundef_token_ = 2;


} // zorba

/* Line 1136 of lalr1.cc  */
#line 18985 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"


/* Line 1138 of lalr1.cc  */
#line 6045 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"

namespace zorba {
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

