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
#line 792 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"

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
#line 791 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ delete (yyvaluep->decval); };

/* Line 480 of lalr1.cc  */
#line 312 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 126: /* "\"'DOUBLE'\"" */

/* Line 480 of lalr1.cc  */
#line 790 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ delete (yyvaluep->dval); };

/* Line 480 of lalr1.cc  */
#line 321 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 151: /* "\"'INTEGER'\"" */

/* Line 480 of lalr1.cc  */
#line 789 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ delete (yyvaluep->ival); };

/* Line 480 of lalr1.cc  */
#line 330 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 347: /* "VersionDecl" */

/* Line 480 of lalr1.cc  */
#line 812 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 339 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 348: /* "MainModule" */

/* Line 480 of lalr1.cc  */
#line 805 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 348 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 349: /* "LibraryModule" */

/* Line 480 of lalr1.cc  */
#line 805 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 357 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 350: /* "ModuleDecl" */

/* Line 480 of lalr1.cc  */
#line 805 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 366 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 351: /* "SIND_DeclList" */

/* Line 480 of lalr1.cc  */
#line 808 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 375 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 352: /* "SIND_Decl" */

/* Line 480 of lalr1.cc  */
#line 808 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 384 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 353: /* "Setter" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 393 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 354: /* "BoundarySpaceDecl" */

/* Line 480 of lalr1.cc  */
#line 802 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 402 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 355: /* "DefaultCollationDecl" */

/* Line 480 of lalr1.cc  */
#line 803 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 411 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 356: /* "BaseURIDecl" */

/* Line 480 of lalr1.cc  */
#line 802 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 420 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 357: /* "ConstructionDecl" */

/* Line 480 of lalr1.cc  */
#line 802 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 429 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 358: /* "OrderingModeDecl" */

/* Line 480 of lalr1.cc  */
#line 807 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 438 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 359: /* "EmptyOrderDecl" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 447 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 360: /* "CopyNamespacesDecl" */

/* Line 480 of lalr1.cc  */
#line 803 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 456 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 361: /* "Import" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 465 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 362: /* "SchemaImport" */

/* Line 480 of lalr1.cc  */
#line 808 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 474 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 363: /* "URILiteralList" */

/* Line 480 of lalr1.cc  */
#line 810 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 483 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 364: /* "SchemaPrefix" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 492 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 365: /* "ModuleImport" */

/* Line 480 of lalr1.cc  */
#line 805 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 501 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 366: /* "NamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 805 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 510 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 367: /* "DefaultNamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 803 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 519 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 368: /* "VFO_DeclList" */

/* Line 480 of lalr1.cc  */
#line 812 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 528 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 369: /* "VFO_Decl" */

/* Line 480 of lalr1.cc  */
#line 812 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 537 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 370: /* "DecimalFormatDecl" */

/* Line 480 of lalr1.cc  */
#line 812 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 546 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 371: /* "DecimalFormatParamList" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ delete (yyvaluep->vstrpair); };

/* Line 480 of lalr1.cc  */
#line 555 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 372: /* "DecimalFormatParam" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ delete (yyvaluep->strpair); };

/* Line 480 of lalr1.cc  */
#line 564 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 374: /* "OptionDecl" */

/* Line 480 of lalr1.cc  */
#line 806 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 573 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 375: /* "FTOptionDecl" */

/* Line 480 of lalr1.cc  */
#line 815 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 582 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 376: /* "CtxItemDecl" */

/* Line 480 of lalr1.cc  */
#line 810 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 591 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 377: /* "CtxItemDecl2" */

/* Line 480 of lalr1.cc  */
#line 810 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 600 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 378: /* "CtxItemDecl3" */

/* Line 480 of lalr1.cc  */
#line 810 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 609 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 379: /* "CtxItemDecl4" */

/* Line 480 of lalr1.cc  */
#line 811 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 618 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 380: /* "VarDecl" */

/* Line 480 of lalr1.cc  */
#line 811 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 627 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 381: /* "VarNameAndType" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ delete (yyvaluep->varnametype); };

/* Line 480 of lalr1.cc  */
#line 636 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 382: /* "AnnotationList" */

/* Line 480 of lalr1.cc  */
#line 801 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 645 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 383: /* "Annotation" */

/* Line 480 of lalr1.cc  */
#line 801 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 654 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 384: /* "AnnotationLiteralList" */

/* Line 480 of lalr1.cc  */
#line 801 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 663 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 385: /* "FunctionDecl" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 672 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 386: /* "FunctionDecl2" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 681 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 387: /* "FunctionDeclSimple" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 690 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 388: /* "FunctionDeclUpdating" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 699 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 389: /* "FunctionSig" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ delete (yyvaluep->fnsig); };

/* Line 480 of lalr1.cc  */
#line 708 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 390: /* "ParamList" */

/* Line 480 of lalr1.cc  */
#line 807 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 717 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 391: /* "Param" */

/* Line 480 of lalr1.cc  */
#line 807 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 726 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 392: /* "CollectionDecl" */

/* Line 480 of lalr1.cc  */
#line 810 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 735 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 394: /* "IndexDecl" */

/* Line 480 of lalr1.cc  */
#line 810 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 744 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 395: /* "IndexKeyList" */

/* Line 480 of lalr1.cc  */
#line 810 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 753 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 396: /* "IndexKeySpec" */

/* Line 480 of lalr1.cc  */
#line 810 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 762 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 397: /* "IntegrityConstraintDecl" */

/* Line 480 of lalr1.cc  */
#line 810 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 771 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 398: /* "QueryBody" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 780 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 399: /* "StatementsAndOptionalExprTop" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 789 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 400: /* "StatementsAndOptionalExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 798 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 401: /* "StatementsAndExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 807 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 402: /* "Statements" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 816 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 403: /* "Statement" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 825 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 404: /* "BlockStatement" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 834 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 405: /* "BlockExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 843 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 406: /* "EnclosedStatementsAndOptionalExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 852 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 407: /* "VarDeclStatement" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 861 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 410: /* "AssignStatement" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 870 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 411: /* "ApplyStatement" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 412: /* "ExitStatement" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 413: /* "WhileStatement" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 897 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 414: /* "FlowCtlStatement" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 906 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 415: /* "FLWORStatement" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 915 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 416: /* "ReturnStatement" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 924 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 417: /* "IfStatement" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 933 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 418: /* "TryStatement" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 942 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 419: /* "CatchListStatement" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 951 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 420: /* "CatchStatement" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 960 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 421: /* "VoidStatement" */

/* Line 480 of lalr1.cc  */
#line 814 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 969 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 422: /* "Expr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 978 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 423: /* "ExprSingle" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 987 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 424: /* "ExprSimple" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 996 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 425: /* "FLWORExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1005 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 426: /* "ReturnExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1014 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 429: /* "FLWORWinCond" */

/* Line 480 of lalr1.cc  */
#line 811 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1023 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 430: /* "WindowClause" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1032 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 431: /* "CountClause" */

/* Line 480 of lalr1.cc  */
#line 812 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1041 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 432: /* "ForLetWinClause" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1050 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 434: /* "FLWORClauseList" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1059 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 435: /* "ForClause" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1068 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 437: /* "VarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 811 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1077 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 438: /* "VarInDecl" */

/* Line 480 of lalr1.cc  */
#line 811 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1086 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 439: /* "PositionalVar" */

/* Line 480 of lalr1.cc  */
#line 807 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1095 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 440: /* "FTScoreVar" */

/* Line 480 of lalr1.cc  */
#line 815 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1104 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 441: /* "LetClause" */

/* Line 480 of lalr1.cc  */
#line 805 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1113 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 442: /* "VarGetsDeclList" */

/* Line 480 of lalr1.cc  */
#line 811 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1122 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 443: /* "VarGetsDecl" */

/* Line 480 of lalr1.cc  */
#line 811 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1131 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 444: /* "WindowVarDecl" */

/* Line 480 of lalr1.cc  */
#line 811 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1140 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 445: /* "WindowVars" */

/* Line 480 of lalr1.cc  */
#line 811 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1149 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 446: /* "WindowVars3" */

/* Line 480 of lalr1.cc  */
#line 811 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1158 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 447: /* "WindowVars2" */

/* Line 480 of lalr1.cc  */
#line 811 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1167 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 448: /* "WhereClause" */

/* Line 480 of lalr1.cc  */
#line 812 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1176 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 449: /* "GroupByClause" */

/* Line 480 of lalr1.cc  */
#line 806 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1185 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 450: /* "GroupSpecList" */

/* Line 480 of lalr1.cc  */
#line 806 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1194 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 451: /* "GroupSpec" */

/* Line 480 of lalr1.cc  */
#line 806 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1203 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 452: /* "GroupCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 806 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1212 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 453: /* "OrderByClause" */

/* Line 480 of lalr1.cc  */
#line 806 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1221 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 454: /* "OrderSpecList" */

/* Line 480 of lalr1.cc  */
#line 807 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1230 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 455: /* "OrderSpec" */

/* Line 480 of lalr1.cc  */
#line 807 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1239 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 456: /* "OrderModifier" */

/* Line 480 of lalr1.cc  */
#line 806 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1248 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 457: /* "OrderDirSpec" */

/* Line 480 of lalr1.cc  */
#line 806 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1257 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 458: /* "OrderEmptySpec" */

/* Line 480 of lalr1.cc  */
#line 806 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1266 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 459: /* "OrderCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 806 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1275 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 460: /* "QuantifiedExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1284 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 461: /* "QVarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 807 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1293 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 462: /* "QVarInDecl" */

/* Line 480 of lalr1.cc  */
#line 807 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1302 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 463: /* "SwitchExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1311 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 464: /* "SwitchCaseClauseList" */

/* Line 480 of lalr1.cc  */
#line 813 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1320 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 465: /* "SwitchCaseClause" */

/* Line 480 of lalr1.cc  */
#line 813 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1329 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 466: /* "SwitchCaseOperandList" */

/* Line 480 of lalr1.cc  */
#line 813 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1338 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 467: /* "SwitchStatement" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1347 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 470: /* "TypeswitchExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1356 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 471: /* "TypeswitchStatement" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1365 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 472: /* "CaseClauseList" */

/* Line 480 of lalr1.cc  */
#line 802 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1374 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 473: /* "CaseClause" */

/* Line 480 of lalr1.cc  */
#line 802 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1383 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 476: /* "SequenceTypeList" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1392 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 477: /* "IfExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1401 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 478: /* "OrExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1410 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 479: /* "AndExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1419 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 480: /* "NotExpr" */

/* Line 480 of lalr1.cc  */
#line 814 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1428 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 481: /* "ComparisonExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1437 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 482: /* "FTContainsExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1446 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 483: /* "StringConcatExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1455 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 484: /* "opt_FTIgnoreOption" */

/* Line 480 of lalr1.cc  */
#line 815 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1464 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 485: /* "RangeExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1473 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 486: /* "AdditiveExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1482 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 487: /* "MultiplicativeExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1491 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 488: /* "UnionExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1500 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 489: /* "IntersectExceptExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1509 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 490: /* "InstanceofExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1518 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 491: /* "TreatExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1527 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 492: /* "CastableExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1536 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 493: /* "CastExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1545 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 494: /* "SingleType" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1554 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 495: /* "UnaryExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1563 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 496: /* "SignList" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1572 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 497: /* "ValueExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1581 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 498: /* "SimpleMapExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1590 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 499: /* "ValueComp" */

/* Line 480 of lalr1.cc  */
#line 810 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1599 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 500: /* "ValidateExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1608 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 501: /* "ExtensionExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1617 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 502: /* "Pragma_list" */

/* Line 480 of lalr1.cc  */
#line 807 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1626 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 503: /* "Pragma" */

/* Line 480 of lalr1.cc  */
#line 807 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1635 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 504: /* "PathExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1644 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 506: /* "RelativePathExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1653 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 507: /* "StepExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1662 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 508: /* "AxisStep" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1671 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 509: /* "ForwardStep" */

/* Line 480 of lalr1.cc  */
#line 800 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1680 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 510: /* "ForwardAxis" */

/* Line 480 of lalr1.cc  */
#line 800 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1689 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 511: /* "AbbrevForwardStep" */

/* Line 480 of lalr1.cc  */
#line 800 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1698 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 512: /* "ReverseStep" */

/* Line 480 of lalr1.cc  */
#line 800 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1707 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 513: /* "ReverseAxis" */

/* Line 480 of lalr1.cc  */
#line 800 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1716 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 514: /* "NodeTest" */

/* Line 480 of lalr1.cc  */
#line 800 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1725 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 515: /* "NameTest" */

/* Line 480 of lalr1.cc  */
#line 805 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1734 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 516: /* "Wildcard" */

/* Line 480 of lalr1.cc  */
#line 812 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1743 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 517: /* "FilterExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1752 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 518: /* "PredicateList" */

/* Line 480 of lalr1.cc  */
#line 807 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1761 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 519: /* "Predicate" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1770 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 520: /* "PrimaryExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1779 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 521: /* "Literal" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1788 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 522: /* "NumericLiteral" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1797 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 524: /* "VarRef" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1806 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 525: /* "ParenthesizedExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1815 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 526: /* "ContextItemExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1824 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 527: /* "OrderedExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1833 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 528: /* "UnorderedExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1842 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 529: /* "FunctionCall" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1851 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 530: /* "ArgList" */

/* Line 480 of lalr1.cc  */
#line 801 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1860 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 534: /* "Constructor" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1869 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 535: /* "DirectConstructor" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1878 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 536: /* "DirElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1887 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 537: /* "DirElemContentList" */

/* Line 480 of lalr1.cc  */
#line 803 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1896 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 538: /* "DirAttributeList" */

/* Line 480 of lalr1.cc  */
#line 803 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1905 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 539: /* "DirAttr" */

/* Line 480 of lalr1.cc  */
#line 803 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1914 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 541: /* "DirAttributeValue" */

/* Line 480 of lalr1.cc  */
#line 803 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1923 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 542: /* "opt_QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 808 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1932 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 543: /* "QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 808 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1941 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 544: /* "opt_AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 801 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1950 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 545: /* "AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 801 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1959 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 546: /* "QuoteAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 808 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1968 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 547: /* "AposAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 801 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1977 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 548: /* "DirElemContent" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1986 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 549: /* "CommonContent" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1995 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 550: /* "DirCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2004 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 551: /* "DirPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2013 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 552: /* "CDataSection" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2022 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 553: /* "ComputedConstructor" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2031 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 554: /* "CompDocConstructor" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2040 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 555: /* "CompElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2049 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 556: /* "CompAttrConstructor" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2058 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 557: /* "CompTextConstructor" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2067 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 558: /* "CompCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2076 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 559: /* "CompPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2085 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 560: /* "CompNamespaceConstructor" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2094 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 561: /* "TypeDeclaration" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2103 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 562: /* "SequenceType" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2112 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 563: /* "OccurrenceIndicator" */

/* Line 480 of lalr1.cc  */
#line 805 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2121 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 564: /* "ItemType" */

/* Line 480 of lalr1.cc  */
#line 805 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2130 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 565: /* "TypeList" */

/* Line 480 of lalr1.cc  */
#line 812 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2139 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 566: /* "GeneralizedAtomicType" */

/* Line 480 of lalr1.cc  */
#line 802 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2148 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 567: /* "SimpleType" */

/* Line 480 of lalr1.cc  */
#line 802 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2157 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 568: /* "KindTest" */

/* Line 480 of lalr1.cc  */
#line 805 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2166 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 569: /* "AnyKindTest" */

/* Line 480 of lalr1.cc  */
#line 801 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2175 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 571: /* "DocumentTest" */

/* Line 480 of lalr1.cc  */
#line 803 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2184 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 572: /* "NamespaceTest" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2193 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 573: /* "TextTest" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2202 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 574: /* "CommentTest" */

/* Line 480 of lalr1.cc  */
#line 802 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2211 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 575: /* "PITest" */

/* Line 480 of lalr1.cc  */
#line 807 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2220 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 576: /* "AttributeTest" */

/* Line 480 of lalr1.cc  */
#line 802 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2229 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 577: /* "SchemaAttributeTest" */

/* Line 480 of lalr1.cc  */
#line 808 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2238 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 578: /* "ElementTest" */

/* Line 480 of lalr1.cc  */
#line 803 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2247 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 579: /* "SchemaElementTest" */

/* Line 480 of lalr1.cc  */
#line 808 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2256 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 580: /* "TypeName" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2265 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 581: /* "TypeName_WITH_HOOK" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2274 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 582: /* "StringLiteral" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2283 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 584: /* "AnyFunctionTest" */

/* Line 480 of lalr1.cc  */
#line 812 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2292 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 585: /* "TypedFunctionTest" */

/* Line 480 of lalr1.cc  */
#line 812 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2301 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 588: /* "InsertExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2310 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 589: /* "DeleteExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2319 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 590: /* "ReplaceExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2328 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 591: /* "RenameExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2337 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 592: /* "TransformExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2346 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 593: /* "VarNameList" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2355 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 594: /* "VarNameDecl" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2364 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 595: /* "TryExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2373 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 596: /* "CatchListExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2382 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 597: /* "CatchExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2391 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 598: /* "BracedExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2400 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 599: /* "NameTestList" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ delete (yyvaluep->name_test_list); };

/* Line 480 of lalr1.cc  */
#line 2409 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 600: /* "FTSelection" */

/* Line 480 of lalr1.cc  */
#line 815 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2418 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 603: /* "FTOr" */

/* Line 480 of lalr1.cc  */
#line 815 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2427 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 604: /* "FTAnd" */

/* Line 480 of lalr1.cc  */
#line 815 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2436 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 605: /* "FTMildNot" */

/* Line 480 of lalr1.cc  */
#line 815 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2445 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 606: /* "FTUnaryNot" */

/* Line 480 of lalr1.cc  */
#line 815 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2454 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 607: /* "FTPrimaryWithOptions" */

/* Line 480 of lalr1.cc  */
#line 815 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2463 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 608: /* "opt_FTMatchOptions" */

/* Line 480 of lalr1.cc  */
#line 815 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2472 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 610: /* "FTWeight" */

/* Line 480 of lalr1.cc  */
#line 815 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2481 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 611: /* "FTPrimary" */

/* Line 480 of lalr1.cc  */
#line 815 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2490 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 612: /* "opt_FTTimes" */

/* Line 480 of lalr1.cc  */
#line 815 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2499 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 613: /* "FTExtensionSelection" */

/* Line 480 of lalr1.cc  */
#line 815 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2508 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 615: /* "FTWords" */

/* Line 480 of lalr1.cc  */
#line 815 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2517 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 616: /* "FTWordsValue" */

/* Line 480 of lalr1.cc  */
#line 815 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2526 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 618: /* "FTAnyallOption" */

/* Line 480 of lalr1.cc  */
#line 815 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2535 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 621: /* "FTPosFilter" */

/* Line 480 of lalr1.cc  */
#line 815 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2544 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 622: /* "FTOrder" */

/* Line 480 of lalr1.cc  */
#line 815 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2553 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 623: /* "FTWindow" */

/* Line 480 of lalr1.cc  */
#line 815 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2562 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 624: /* "FTDistance" */

/* Line 480 of lalr1.cc  */
#line 815 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2571 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 625: /* "FTUnit" */

/* Line 480 of lalr1.cc  */
#line 815 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2580 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 626: /* "FTMatchOptions" */

/* Line 480 of lalr1.cc  */
#line 815 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2589 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 627: /* "FTMatchOption" */

/* Line 480 of lalr1.cc  */
#line 815 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2598 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 628: /* "FTCaseOption" */

/* Line 480 of lalr1.cc  */
#line 815 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2607 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 629: /* "FTDiacriticsOption" */

/* Line 480 of lalr1.cc  */
#line 815 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2616 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 630: /* "FTExtensionOption" */

/* Line 480 of lalr1.cc  */
#line 815 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2625 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 631: /* "FTStemOption" */

/* Line 480 of lalr1.cc  */
#line 815 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2634 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 632: /* "FTThesaurusOption" */

/* Line 480 of lalr1.cc  */
#line 815 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2643 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 636: /* "FTThesaurusID" */

/* Line 480 of lalr1.cc  */
#line 815 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2652 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 639: /* "FTStopWordOption" */

/* Line 480 of lalr1.cc  */
#line 815 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2661 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 640: /* "FTStopWords" */

/* Line 480 of lalr1.cc  */
#line 815 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2670 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 644: /* "FTStopWordsInclExcl" */

/* Line 480 of lalr1.cc  */
#line 815 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2679 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 645: /* "FTLanguageOption" */

/* Line 480 of lalr1.cc  */
#line 815 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2688 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 646: /* "FTWildCardOption" */

/* Line 480 of lalr1.cc  */
#line 815 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2697 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 647: /* "FTContent" */

/* Line 480 of lalr1.cc  */
#line 815 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2706 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 648: /* "FTTimes" */

/* Line 480 of lalr1.cc  */
#line 815 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2715 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 649: /* "FTRange" */

/* Line 480 of lalr1.cc  */
#line 815 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2724 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 650: /* "FTScope" */

/* Line 480 of lalr1.cc  */
#line 815 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2733 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 651: /* "FTBigUnit" */

/* Line 480 of lalr1.cc  */
#line 815 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2742 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 652: /* "FTIgnoreOption" */

/* Line 480 of lalr1.cc  */
#line 815 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2751 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 653: /* "JSONArrayConstructor" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2760 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 654: /* "JSONSimpleObjectUnion" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2769 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 655: /* "JSONAccumulatorObjectUnion" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2778 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 656: /* "JSONObjectConstructor" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2787 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 657: /* "JSONPairList" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2796 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 658: /* "JSONInsertExpr" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2805 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 659: /* "JSONAppendExpr" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2814 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 660: /* "JSONDeleteExpr" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2823 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 661: /* "JSONRenameExpr" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2832 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 662: /* "JSONReplaceExpr" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2841 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 668: /* "QNAME" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2850 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 669: /* "FUNCTION_NAME" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2859 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 670: /* "EQNAME" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2868 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
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
#line 127 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
{
    yylloc.begin.filename = yylloc.end.filename = &(driver.theFilename2);
}

/* Line 565 of lalr1.cc  */
#line 2965 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"

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
#line 858 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      }
    break;

  case 4:

/* Line 690 of lalr1.cc  */
#line 862 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      }
    break;

  case 5:

/* Line 690 of lalr1.cc  */
#line 866 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      }
    break;

  case 6:

/* Line 690 of lalr1.cc  */
#line 872 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.node) = NULL;
      }
    break;

  case 7:

/* Line 690 of lalr1.cc  */
#line 876 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.node) = NULL; YYABORT;
      }
    break;

  case 8:

/* Line 690 of lalr1.cc  */
#line 880 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.node) = NULL; YYABORT;
      }
    break;

  case 9:

/* Line 690 of lalr1.cc  */
#line 886 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 10:

/* Line 690 of lalr1.cc  */
#line 892 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      MainModule* mm = dynamic_cast<MainModule*>((yysemantic_stack_[(2) - (2)].node));
      mm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 11:

/* Line 690 of lalr1.cc  */
#line 900 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 12:

/* Line 690 of lalr1.cc  */
#line 906 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      LibraryModule* lm = dynamic_cast<LibraryModule*>((yysemantic_stack_[(2) - (2)].node));
      lm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 13:

/* Line 690 of lalr1.cc  */
#line 915 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), "utf-8" );
    }
    break;

  case 14:

/* Line 690 of lalr1.cc  */
#line 920 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );
    }
    break;

  case 15:

/* Line 690 of lalr1.cc  */
#line 925 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), "utf-8", VersionDecl::jsoniq );
    }
    break;

  case 16:

/* Line 690 of lalr1.cc  */
#line 930 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)), VersionDecl::jsoniq );
    }
    break;

  case 17:

/* Line 690 of lalr1.cc  */
#line 936 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (1)].node)), NULL);
      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(3) - (3)].expr)), prolog);
    }
    break;

  case 18:

/* Line 690 of lalr1.cc  */
#line 942 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (1)].node)));
      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(3) - (3)].expr)), prolog);
    }
    break;

  case 19:

/* Line 690 of lalr1.cc  */
#line 948 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)),
                                  static_cast<SIND_DeclList*>((yysemantic_stack_[(5) - (1)].node)),
                                  static_cast<VFO_DeclList*>((yysemantic_stack_[(5) - (3)].node)));
      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(5) - (5)].expr)), prolog);
    }
    break;

  case 20:

/* Line 690 of lalr1.cc  */
#line 956 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new MainModule( LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(1) - (1)].expr)), NULL );
    }
    break;

  case 21:

/* Line 690 of lalr1.cc  */
#line 961 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].expr);
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after statement.");
      YYERROR;
    }
    break;

  case 22:

/* Line 690 of lalr1.cc  */
#line 969 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].expr);
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 23:

/* Line 690 of lalr1.cc  */
#line 977 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(5) - (1)].node); (yyval.node) = (yysemantic_stack_[(5) - (3)].node); (yyval.node) = (yysemantic_stack_[(5) - (5)].expr);
      (yylocation_stack_[(5) - (3)]).step();
      error((yylocation_stack_[(5) - (3)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 24:

/* Line 690 of lalr1.cc  */
#line 985 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(5) - (1)].node); (yyval.node) = (yysemantic_stack_[(5) - (3)].node); (yyval.node) = (yysemantic_stack_[(5) - (5)].expr);
      (yylocation_stack_[(5) - (1)]).step();
      error((yylocation_stack_[(5) - (1)]), "syntax error, missing semicolon \";\" after statement.");
      YYERROR;
    }
    break;

  case 25:

/* Line 690 of lalr1.cc  */
#line 994 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(1) - (1)].node)), NULL);
    }
    break;

  case 26:

/* Line 690 of lalr1.cc  */
#line 999 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (2)].node)), NULL);
      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(3) - (1)].node)), prolog);
    }
    break;

  case 27:

/* Line 690 of lalr1.cc  */
#line 1005 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (2)].node)));
      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(3) - (1)].node)), prolog);
    }
    break;

  case 28:

/* Line 690 of lalr1.cc  */
#line 1011 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)),
                                  static_cast<SIND_DeclList*>((yysemantic_stack_[(5) - (2)].node)),
                                  static_cast<VFO_DeclList*>((yysemantic_stack_[(5) - (4)].node)));
      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(5) - (1)].node)), prolog);
    }
    break;

  case 29:

/* Line 690 of lalr1.cc  */
#line 1020 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      ERROR_IF_QNAME_NOT_NCNAME((yysemantic_stack_[(6) - (3)].expr), (yylocation_stack_[(6) - (3)]));
      (yyval.node) = new ModuleDecl( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );
      dynamic_cast<ModuleDecl*>((yyval.node))->setComment( SYMTAB((yysemantic_stack_[(6) - (1)].sval)) );
    }
    break;

  case 30:

/* Line 690 of lalr1.cc  */
#line 1028 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      SIND_DeclList *sdl = new SIND_DeclList( LOC((yyloc)) );
      sdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
      (yyval.node) = sdl;
    }
    break;

  case 31:

/* Line 690 of lalr1.cc  */
#line 1035 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      ((SIND_DeclList*)(yysemantic_stack_[(3) - (1)].node))->push_back( (yysemantic_stack_[(3) - (3)].node) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 32:

/* Line 690 of lalr1.cc  */
#line 1041 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 46:

/* Line 690 of lalr1.cc  */
#line 1067 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new BoundarySpaceDecl(LOC((yyloc)), StaticContextConsts::preserve_space);
    }
    break;

  case 47:

/* Line 690 of lalr1.cc  */
#line 1072 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new BoundarySpaceDecl(LOC((yyloc)), StaticContextConsts::strip_space);
    }
    break;

  case 48:

/* Line 690 of lalr1.cc  */
#line 1078 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DefaultCollationDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (4)].sval)) );
    }
    break;

  case 49:

/* Line 690 of lalr1.cc  */
#line 1084 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new BaseURIDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
    }
    break;

  case 50:

/* Line 690 of lalr1.cc  */
#line 1090 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new ConstructionDecl(LOC((yyloc)), StaticContextConsts::cons_preserve);
    }
    break;

  case 51:

/* Line 690 of lalr1.cc  */
#line 1095 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new ConstructionDecl(LOC((yyloc)), StaticContextConsts::cons_strip);
    }
    break;

  case 52:

/* Line 690 of lalr1.cc  */
#line 1101 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new OrderingModeDecl(LOC((yyloc)), StaticContextConsts::ordered);
    }
    break;

  case 53:

/* Line 690 of lalr1.cc  */
#line 1106 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new OrderingModeDecl(LOC((yyloc)), StaticContextConsts::unordered);
    }
    break;

  case 54:

/* Line 690 of lalr1.cc  */
#line 1112 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new EmptyOrderDecl(LOC((yyloc)), StaticContextConsts::empty_greatest);
    }
    break;

  case 55:

/* Line 690 of lalr1.cc  */
#line 1117 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new EmptyOrderDecl(LOC((yyloc)), StaticContextConsts::empty_least);
    }
    break;

  case 56:

/* Line 690 of lalr1.cc  */
#line 1123 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)), true, true);
    }
    break;

  case 57:

/* Line 690 of lalr1.cc  */
#line 1128 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)), true, false);
    }
    break;

  case 58:

/* Line 690 of lalr1.cc  */
#line 1133 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)), false, true);
    }
    break;

  case 59:

/* Line 690 of lalr1.cc  */
#line 1138 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)), false, false);
    }
    break;

  case 62:

/* Line 690 of lalr1.cc  */
#line 1148 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yyval.node);
      error((yylocation_stack_[(3) - (2)]), "syntax error, \"import\" should be followed by either \"schema\" or \"module\".");
      YYERROR;
    }
    break;

  case 63:

/* Line 690 of lalr1.cc  */
#line 1156 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SchemaImport( LOC((yyloc)), NULL, SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL );
    }
    break;

  case 64:

/* Line 690 of lalr1.cc  */
#line 1161 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(4) - (3)].node)),
                            SYMTAB((yysemantic_stack_[(4) - (4)].sval)),
                            NULL);
    }
    break;

  case 65:

/* Line 690 of lalr1.cc  */
#line 1169 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            NULL,
                            SYMTAB((yysemantic_stack_[(5) - (3)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 66:

/* Line 690 of lalr1.cc  */
#line 1177 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(6) - (3)].node)),
                            SYMTAB((yysemantic_stack_[(6) - (4)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(6) - (6)].node)));
    }
    break;

  case 67:

/* Line 690 of lalr1.cc  */
#line 1186 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      URILiteralList *ull = new URILiteralList( LOC((yyloc)));
      ull->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
      (yyval.node) = ull;
    }
    break;

  case 68:

/* Line 690 of lalr1.cc  */
#line 1193 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      if ( URILiteralList *ull = dynamic_cast<URILiteralList*>((yysemantic_stack_[(3) - (1)].node)) )
        ull->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 69:

/* Line 690 of lalr1.cc  */
#line 1201 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      ERROR_IF_QNAME_NOT_NCNAME((yysemantic_stack_[(3) - (2)].expr), (yylocation_stack_[(3) - (2)]));
      (yyval.node) = new SchemaPrefix( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)));
    }
    break;

  case 70:

/* Line 690 of lalr1.cc  */
#line 1207 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SchemaPrefix( LOC((yyloc)), true );
    }
    break;

  case 71:

/* Line 690 of lalr1.cc  */
#line 1213 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL);
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(3) - (2)].sval)));
    }
    break;

  case 72:

/* Line 690 of lalr1.cc  */
#line 1219 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      ERROR_IF_QNAME_NOT_NCNAME((yysemantic_stack_[(6) - (4)].expr), (yylocation_stack_[(6) - (4)]));
      (yyval.node) = new ModuleImport(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(6) - (4)].expr)), SYMTAB((yysemantic_stack_[(6) - (6)].sval)), NULL);
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(6) - (2)].sval)));
    }
    break;

  case 73:

/* Line 690 of lalr1.cc  */
#line 1226 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)),
                            SYMTAB((yysemantic_stack_[(5) - (3)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(5) - (2)].sval)));
    }
    break;

  case 74:

/* Line 690 of lalr1.cc  */
#line 1234 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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
#line 1245 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      ERROR_IF_QNAME_NOT_NCNAME((yysemantic_stack_[(5) - (3)].expr), (yylocation_stack_[(5) - (3)]));
      (yyval.node) = new NamespaceDecl( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (3)].expr)), SYMTAB((yysemantic_stack_[(5) - (5)].sval)) );
    }
    break;

  case 76:

/* Line 690 of lalr1.cc  */
#line 1252 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DefaultNamespaceDecl(LOC((yyloc)),
                                    ParseConstants::ns_element_default,
                                    SYMTAB((yysemantic_stack_[(5) - (5)].sval)));
    }
    break;

  case 77:

/* Line 690 of lalr1.cc  */
#line 1259 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DefaultNamespaceDecl(LOC((yyloc)),
                                    ParseConstants::ns_function_default,
                                    SYMTAB((yysemantic_stack_[(5) - (5)].sval)));
    }
    break;

  case 78:

/* Line 690 of lalr1.cc  */
#line 1267 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      VFO_DeclList *vdl = new VFO_DeclList( LOC((yyloc)));
      vdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
      (yyval.node) = vdl;
    }
    break;

  case 79:

/* Line 690 of lalr1.cc  */
#line 1274 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      ((VFO_DeclList*)(yysemantic_stack_[(3) - (1)].node))->push_back( (yysemantic_stack_[(3) - (3)].node) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 80:

/* Line 690 of lalr1.cc  */
#line 1280 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 89:

/* Line 690 of lalr1.cc  */
#line 1299 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DecimalFormatNode(LOC((yyloc)), (yysemantic_stack_[(4) - (4)].vstrpair));
      delete (yysemantic_stack_[(4) - (4)].vstrpair);
    }
    break;

  case 90:

/* Line 690 of lalr1.cc  */
#line 1305 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DecimalFormatNode(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), (yysemantic_stack_[(4) - (4)].vstrpair));
      delete (yysemantic_stack_[(4) - (4)].vstrpair);
    }
    break;

  case 91:

/* Line 690 of lalr1.cc  */
#line 1312 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.vstrpair) = new vector<string_pair_t>();
      (yyval.vstrpair)->push_back( *(yysemantic_stack_[(1) - (1)].strpair) );
      delete (yysemantic_stack_[(1) - (1)].strpair);
    }
    break;

  case 92:

/* Line 690 of lalr1.cc  */
#line 1319 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yysemantic_stack_[(2) - (1)].vstrpair)->push_back( *(yysemantic_stack_[(2) - (2)].strpair) );
      delete (yysemantic_stack_[(2) - (2)].strpair);
      (yyval.vstrpair) = (yysemantic_stack_[(2) - (1)].vstrpair);
    }
    break;

  case 93:

/* Line 690 of lalr1.cc  */
#line 1327 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      StringLiteral *sl = static_cast<StringLiteral*>((yysemantic_stack_[(3) - (3)].expr));
      (yyval.strpair) = new string_pair_t( (yysemantic_stack_[(3) - (1)].strval), sl->get_strval().str() );
      delete sl;
    }
    break;

  case 94:

/* Line 690 of lalr1.cc  */
#line 1334 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "decimal-separator"; }
    break;

  case 95:

/* Line 690 of lalr1.cc  */
#line 1335 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "digit"; }
    break;

  case 96:

/* Line 690 of lalr1.cc  */
#line 1336 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "grouping-separator"; }
    break;

  case 97:

/* Line 690 of lalr1.cc  */
#line 1337 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "infinity"; }
    break;

  case 98:

/* Line 690 of lalr1.cc  */
#line 1338 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "minus-sign"; }
    break;

  case 99:

/* Line 690 of lalr1.cc  */
#line 1339 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "NaN"; }
    break;

  case 100:

/* Line 690 of lalr1.cc  */
#line 1340 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "pattern-separator"; }
    break;

  case 101:

/* Line 690 of lalr1.cc  */
#line 1341 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "percent"; }
    break;

  case 102:

/* Line 690 of lalr1.cc  */
#line 1342 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "per-mille"; }
    break;

  case 103:

/* Line 690 of lalr1.cc  */
#line 1343 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "zero-digit"; }
    break;

  case 104:

/* Line 690 of lalr1.cc  */
#line 1347 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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
#line 1361 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new FTOptionDecl( LOC((yyloc)), dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (3)].node)) );
    }
    break;

  case 106:

/* Line 690 of lalr1.cc  */
#line 1367 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(4) - (4)].node);
    }
    break;

  case 107:

/* Line 690 of lalr1.cc  */
#line 1373 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      CtxItemDecl* d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(3) - (3)].node));
      d->theType = (yysemantic_stack_[(3) - (2)].node);
      (yyval.node) = d;
    }
    break;

  case 108:

/* Line 690 of lalr1.cc  */
#line 1380 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 109:

/* Line 690 of lalr1.cc  */
#line 1386 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      CtxItemDecl* d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(1) - (1)].node));
      d->theIsExternal = false;
      (yyval.node) = d;
    }
    break;

  case 110:

/* Line 690 of lalr1.cc  */
#line 1393 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CtxItemDecl(LOC((yyloc)), NULL);
    }
    break;

  case 111:

/* Line 690 of lalr1.cc  */
#line 1398 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 112:

/* Line 690 of lalr1.cc  */
#line 1404 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CtxItemDecl(LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 113:

/* Line 690 of lalr1.cc  */
#line 1410 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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
#line 1422 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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
#line 1434 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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
#line 1447 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)), NULL, NULL);
    }
    break;

  case 117:

/* Line 690 of lalr1.cc  */
#line 1452 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)),
                              dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (4)].node)),
                              NULL);
    }
    break;

  case 118:

/* Line 690 of lalr1.cc  */
#line 1460 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(4) - (4)].expr)),
                              NULL,
                              static_cast<AnnotationListParsenode*>((yysemantic_stack_[(4) - (1)].node)));
    }
    break;

  case 119:

/* Line 690 of lalr1.cc  */
#line 1468 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(5) - (4)].expr)),
                              dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (5)].node)),
                              static_cast<AnnotationListParsenode*>((yysemantic_stack_[(5) - (1)].node)));
    }
    break;

  case 120:

/* Line 690 of lalr1.cc  */
#line 1477 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AnnotationListParsenode(LOC((yyloc)), static_cast<AnnotationParsenode*>((yysemantic_stack_[(1) - (1)].node)));
    }
    break;

  case 121:

/* Line 690 of lalr1.cc  */
#line 1482 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      static_cast<AnnotationListParsenode*>((yysemantic_stack_[(2) - (1)].node))->push_back(static_cast<AnnotationParsenode*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 122:

/* Line 690 of lalr1.cc  */
#line 1489 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))), NULL);
    }
    break;

  case 123:

/* Line 690 of lalr1.cc  */
#line 1494 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)),
                                   new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (1)].sval))),
                                   static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 124:

/* Line 690 of lalr1.cc  */
#line 1501 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), true), NULL);
    }
    break;

  case 125:

/* Line 690 of lalr1.cc  */
#line 1506 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)),
                                   new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (1)].sval)), true),
                                   static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 126:

/* Line 690 of lalr1.cc  */
#line 1514 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AnnotationLiteralListParsenode(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr));
    }
    break;

  case 127:

/* Line 690 of lalr1.cc  */
#line 1519 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(3) - (1)].node))->push_back((yysemantic_stack_[(3) - (3)].expr));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 128:

/* Line 690 of lalr1.cc  */
#line 1526 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      static_cast<FunctionDecl*>((yysemantic_stack_[(2) - (2)].node))->setComment( SYMTAB((yysemantic_stack_[(2) - (1)].sval)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 129:

/* Line 690 of lalr1.cc  */
#line 1532 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      FunctionDecl* fdecl = static_cast<FunctionDecl*>((yysemantic_stack_[(3) - (3)].node));
      fdecl->setComment( SYMTAB((yysemantic_stack_[(3) - (1)].sval)) );
      fdecl->set_annotations(static_cast<AnnotationListParsenode*>((yysemantic_stack_[(3) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
    }
    break;

  case 132:

/* Line 690 of lalr1.cc  */
#line 1545 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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
#line 1556 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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
#line 1569 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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
#line 1581 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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
#line 1594 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(NULL);
    }
    break;

  case 137:

/* Line 690 of lalr1.cc  */
#line 1599 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (2)].node)));
    }
    break;

  case 138:

/* Line 690 of lalr1.cc  */
#line 1604 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(NULL, dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node)));
    }
    break;

  case 139:

/* Line 690 of lalr1.cc  */
#line 1609 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(dynamic_cast<ParamList*>((yysemantic_stack_[(5) - (2)].node)), dynamic_cast<SequenceType*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 140:

/* Line 690 of lalr1.cc  */
#line 1615 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      ParamList *pl = new ParamList( LOC((yyloc)) );
      pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = pl;
    }
    break;

  case 141:

/* Line 690 of lalr1.cc  */
#line 1622 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      if ( ParamList *pl = dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (1)].node)) )
        pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(3) - (3)].node)) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 142:

/* Line 690 of lalr1.cc  */
#line 1630 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL);
    }
    break;

  case 143:

/* Line 690 of lalr1.cc  */
#line 1635 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)),
                     static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                     dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 144:

/* Line 690 of lalr1.cc  */
#line 1643 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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
#line 1651 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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
#line 1659 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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
#line 1667 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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
#line 1677 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL));
    }
    break;

  case 149:

/* Line 690 of lalr1.cc  */
#line 1681 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)),
                                                    (yysemantic_stack_[(2) - (1)].node),
                                                    dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node))));
    }
    break;

  case 150:

/* Line 690 of lalr1.cc  */
#line 1687 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL));
    }
    break;

  case 151:

/* Line 690 of lalr1.cc  */
#line 1691 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)),
                                                    (yysemantic_stack_[(2) - (1)].node),
                                                    dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node))));
    }
    break;

  case 152:

/* Line 690 of lalr1.cc  */
#line 1698 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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
#line 1707 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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
#line 1718 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      IndexKeyList* keyList = new IndexKeyList(LOC((yyloc)));
      keyList->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = keyList;
    }
    break;

  case 155:

/* Line 690 of lalr1.cc  */
#line 1724 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      dynamic_cast<IndexKeyList*>((yysemantic_stack_[(3) - (1)].node))->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 156:

/* Line 690 of lalr1.cc  */
#line 1731 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL, NULL);
    }
    break;

  case 157:

/* Line 690 of lalr1.cc  */
#line 1736 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            dynamic_cast<SequenceType*>((yysemantic_stack_[(2) - (2)].node)),
                            NULL);
    }
    break;

  case 158:

/* Line 690 of lalr1.cc  */
#line 1743 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            NULL,
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
    }
    break;

  case 159:

/* Line 690 of lalr1.cc  */
#line 1750 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(3) - (1)].expr),
                            dynamic_cast<SequenceType*>((yysemantic_stack_[(3) - (2)].node)),
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 160:

/* Line 690 of lalr1.cc  */
#line 1760 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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
#line 1770 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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
#line 1780 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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
#line 1791 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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
#line 1804 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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
#line 1820 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 166:

/* Line 690 of lalr1.cc  */
#line 1824 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 167:

/* Line 690 of lalr1.cc  */
#line 1828 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = NULL;
    }
    break;

  case 168:

/* Line 690 of lalr1.cc  */
#line 1834 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 169:

/* Line 690 of lalr1.cc  */
#line 1838 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 170:

/* Line 690 of lalr1.cc  */
#line 1842 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new BlockBody(LOC((yyloc)));
    }
    break;

  case 171:

/* Line 690 of lalr1.cc  */
#line 1848 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 172:

/* Line 690 of lalr1.cc  */
#line 1853 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      BlockBody* blk = static_cast<BlockBody*>((yysemantic_stack_[(2) - (1)].expr));
      blk->add((yysemantic_stack_[(2) - (2)].expr));
      (yyval.expr) = blk;
    }
    break;

  case 173:

/* Line 690 of lalr1.cc  */
#line 1861 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      BlockBody* blk = new BlockBody(LOC((yyloc)));
      blk->add((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = blk;
    }
    break;

  case 174:

/* Line 690 of lalr1.cc  */
#line 1868 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      BlockBody* blk = static_cast<BlockBody*>((yysemantic_stack_[(2) - (1)].expr));
      blk->add((yysemantic_stack_[(2) - (2)].expr));
      (yyval.expr) = blk;
    }
    break;

  case 175:

/* Line 690 of lalr1.cc  */
#line 1875 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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
#line 1903 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 190:

/* Line 690 of lalr1.cc  */
#line 1909 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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
#line 1931 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 192:

/* Line 690 of lalr1.cc  */
#line 1937 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    }
    break;

  case 193:

/* Line 690 of lalr1.cc  */
#line 1943 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      VarDeclStmt* vdecl = static_cast<VarDeclStmt*>((yysemantic_stack_[(3) - (1)].expr));
      vdecl->add((yysemantic_stack_[(3) - (3)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 194:

/* Line 690 of lalr1.cc  */
#line 1950 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      VarDeclStmt* vdecl = new VarDeclStmt(LOC((yyloc)), NULL);
      vdecl->add((yysemantic_stack_[(2) - (2)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 195:

/* Line 690 of lalr1.cc  */
#line 1957 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      VarDeclStmt* vdecl = new VarDeclStmt(LOC((yyloc)),
                                           static_cast<AnnotationListParsenode*>((yysemantic_stack_[(3) - (1)].node)));
      vdecl->add((yysemantic_stack_[(3) - (3)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 196:

/* Line 690 of lalr1.cc  */
#line 1966 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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
#line 1975 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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
#line 1984 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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
#line 1993 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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
#line 2004 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new AssignExpr(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)), (yysemantic_stack_[(5) - (4)].expr));
    }
    break;

  case 201:

/* Line 690 of lalr1.cc  */
#line 2010 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new ApplyExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr));
    }
    break;

  case 202:

/* Line 690 of lalr1.cc  */
#line 2016 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new ExitExpr(LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr));
    }
    break;

  case 203:

/* Line 690 of lalr1.cc  */
#line 2022 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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
#line 2034 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement(LOC((yyloc)), FlowCtlStatement::BREAK);
    }
    break;

  case 205:

/* Line 690 of lalr1.cc  */
#line 2039 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement( LOC((yyloc)), FlowCtlStatement::CONTINUE );
    }
    break;

  case 206:

/* Line 690 of lalr1.cc  */
#line 2045 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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
#line 2057 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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
#line 2070 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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
#line 2090 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new TryExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 210:

/* Line 690 of lalr1.cc  */
#line 2096 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      CatchListExpr* cle = new CatchListExpr( LOC((yyloc)) );
      cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)) );
      (yyval.expr) = cle;
    }
    break;

  case 211:

/* Line 690 of lalr1.cc  */
#line 2103 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
      if ( cle )
        cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)) );
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    }
    break;

  case 212:

/* Line 690 of lalr1.cc  */
#line 2112 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)), *(yysemantic_stack_[(3) - (2)].name_test_list), (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 213:

/* Line 690 of lalr1.cc  */
#line 2119 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new BlockBody(LOC((yyloc)));
    }
    break;

  case 214:

/* Line 690 of lalr1.cc  */
#line 2125 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 215:

/* Line 690 of lalr1.cc  */
#line 2130 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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
#line 2142 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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
#line 2176 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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
#line 2188 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new ReturnExpr( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr) );
    }
    break;

  case 237:

/* Line 690 of lalr1.cc  */
#line 2194 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.strval) = parser::the_sliding;
    }
    break;

  case 238:

/* Line 690 of lalr1.cc  */
#line 2199 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.strval) = parser::the_tumbling;
    }
    break;

  case 239:

/* Line 690 of lalr1.cc  */
#line 2205 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.strval) = parser::the_start;
    }
    break;

  case 240:

/* Line 690 of lalr1.cc  */
#line 2210 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.strval) = parser::the_end;
    }
    break;

  case 241:

/* Line 690 of lalr1.cc  */
#line 2215 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
    (yyval.strval) = parser::the_only_end;
  }
    break;

  case 242:

/* Line 690 of lalr1.cc  */
#line 2221 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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
#line 2230 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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
#line 2241 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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
#line 2253 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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
#line 2264 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CountClause(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 255:

/* Line 690 of lalr1.cc  */
#line 2282 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      FLWORClauseList *fcl = new FLWORClauseList( LOC((yyloc)) );
      fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = fcl;
    }
    break;

  case 256:

/* Line 690 of lalr1.cc  */
#line 2289 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      FLWORClauseList *fcl = dynamic_cast<FLWORClauseList*>((yysemantic_stack_[(2) - (1)].node));
      fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = fcl;
    }
    break;

  case 257:

/* Line 690 of lalr1.cc  */
#line 2298 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new ForClause(LOC((yyloc)), dynamic_cast<VarInDeclList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 258:

/* Line 690 of lalr1.cc  */
#line 2302 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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
#line 2310 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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
#line 2320 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = NULL;
      error((yylocation_stack_[(2) - (2)]), "");
      YYERROR;
    }
    break;

  case 262:

/* Line 690 of lalr1.cc  */
#line 2329 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
    }
    break;

  case 263:

/* Line 690 of lalr1.cc  */
#line 2334 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      VarInDeclList* vdl = new VarInDeclList( LOC((yyloc)) );
      vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = vdl;
    }
    break;

  case 264:

/* Line 690 of lalr1.cc  */
#line 2341 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      if ( VarInDeclList* vdl = dynamic_cast<VarInDeclList*>((yysemantic_stack_[(4) - (1)].node)) )
        vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
      (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
    }
    break;

  case 265:

/* Line 690 of lalr1.cc  */
#line 2348 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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
#line 2358 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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
#line 2368 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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
#line 2378 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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
#line 2388 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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
#line 2398 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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
#line 2408 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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
#line 2418 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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
#line 2428 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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
#line 2438 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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
#line 2447 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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
#line 2457 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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
#line 2467 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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
#line 2479 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new PositionalVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 279:

/* Line 690 of lalr1.cc  */
#line 2485 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new FTScoreVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 280:

/* Line 690 of lalr1.cc  */
#line 2491 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new LetClause( LOC((yyloc)), dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(2) - (2)].node)) );
        }
    break;

  case 281:

/* Line 690 of lalr1.cc  */
#line 2497 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            VarGetsDeclList *vgdl = new VarGetsDeclList( LOC((yyloc)) );
            vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = vgdl;
        }
    break;

  case 282:

/* Line 690 of lalr1.cc  */
#line 2503 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            if( VarGetsDeclList *vgdl = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(3) - (1)].node)) )
                vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 283:

/* Line 690 of lalr1.cc  */
#line 2511 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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
#line 2519 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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
#line 2527 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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
#line 2535 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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
#line 2545 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                             NULL, (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 288:

/* Line 690 of lalr1.cc  */
#line 2551 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                             dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (3)].node)),
                             (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 290:

/* Line 690 of lalr1.cc  */
#line 2561 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL, NULL);
    }
    break;

  case 291:

/* Line 690 of lalr1.cc  */
#line 2565 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_curr(static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)));
    }
    break;

  case 292:

/* Line 690 of lalr1.cc  */
#line 2572 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), dynamic_cast<PositionalVar*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL, NULL);
    }
    break;

  case 293:

/* Line 690 of lalr1.cc  */
#line 2576 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_posvar(dynamic_cast<PositionalVar*>((yysemantic_stack_[(2) - (1)].node)));
    }
    break;

  case 295:

/* Line 690 of lalr1.cc  */
#line 2584 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), static_cast<QName*>((yysemantic_stack_[(6) - (6)].expr)));
    }
    break;

  case 296:

/* Line 690 of lalr1.cc  */
#line 2588 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 297:

/* Line 690 of lalr1.cc  */
#line 2592 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)), NULL);
    }
    break;

  case 298:

/* Line 690 of lalr1.cc  */
#line 2598 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new WhereClause(LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 299:

/* Line 690 of lalr1.cc  */
#line 2604 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new GroupByClause(LOC((yyloc)), dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 300:

/* Line 690 of lalr1.cc  */
#line 2610 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      GroupSpecList* gsl = new GroupSpecList(LOC((yyloc)));
      gsl->push_back(static_cast<GroupSpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = gsl;
    }
    break;

  case 301:

/* Line 690 of lalr1.cc  */
#line 2616 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      GroupSpecList* gsl = static_cast<GroupSpecList*>((yysemantic_stack_[(3) - (1)].node));
      gsl->push_back(static_cast<GroupSpec*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = gsl;
    }
    break;

  case 302:

/* Line 690 of lalr1.cc  */
#line 2624 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)), NULL, (yysemantic_stack_[(4) - (4)].expr), NULL);
    }
    break;

  case 303:

/* Line 690 of lalr1.cc  */
#line 2628 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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
#line 2636 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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
#line 2644 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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
#line 2652 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                         static_cast<VarRef*>((yysemantic_stack_[(3) - (2)].expr))->get_qname(),
                         NULL,
                         NULL,
                         static_cast<GroupCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 307:

/* Line 690 of lalr1.cc  */
#line 2660 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      VarRef* varRef = dynamic_cast<VarRef*>((yysemantic_stack_[(1) - (1)].expr));
      if (varRef != NULL)
        (yyval.node) = new GroupSpec(LOC((yyloc)), varRef, NULL, NULL, NULL);
      else
        (yyval.node) = new GroupSpec(LOC((yyloc)), NULL, NULL, (yysemantic_stack_[(1) - (1)].expr), NULL);
    }
    break;

  case 308:

/* Line 690 of lalr1.cc  */
#line 2668 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      VarRef* varRef = dynamic_cast<VarRef*>((yysemantic_stack_[(2) - (1)].expr));
      if (varRef != NULL)
        (yyval.node) = new GroupSpec(LOC((yyloc)), varRef, NULL, NULL, static_cast<GroupCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
      else
        (yyval.node) = new GroupSpec(LOC((yyloc)), NULL, NULL, (yysemantic_stack_[(2) - (1)].expr), static_cast<GroupCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
    }
    break;

  case 309:

/* Line 690 of lalr1.cc  */
#line 2678 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new GroupCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
    }
    break;

  case 310:

/* Line 690 of lalr1.cc  */
#line 2684 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 311:

/* Line 690 of lalr1.cc  */
#line 2690 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(4) - (4)].node)), true
            );
        }
    break;

  case 312:

/* Line 690 of lalr1.cc  */
#line 2698 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            OrderSpecList *osl = new OrderSpecList( LOC((yyloc)) );
            osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = osl;
        }
    break;

  case 313:

/* Line 690 of lalr1.cc  */
#line 2704 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            if ( OrderSpecList* osl = dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (1)].node)) )
                osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 314:

/* Line 690 of lalr1.cc  */
#line 2712 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderSpec( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL );
        }
    break;

  case 315:

/* Line 690 of lalr1.cc  */
#line 2716 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderSpec(
                LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<OrderModifierPN*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 316:

/* Line 690 of lalr1.cc  */
#line 2724 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL
            );
        }
    break;

  case 317:

/* Line 690 of lalr1.cc  */
#line 2730 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 318:

/* Line 690 of lalr1.cc  */
#line 2736 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, NULL, dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 319:

/* Line 690 of lalr1.cc  */
#line 2742 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (2)].node)),
                NULL
            );
        }
    break;

  case 320:

/* Line 690 of lalr1.cc  */
#line 2751 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
                NULL,
                dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 321:

/* Line 690 of lalr1.cc  */
#line 2760 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                NULL,
                dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 322:

/* Line 690 of lalr1.cc  */
#line 2769 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(3) - (1)].node)),
                dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 323:

/* Line 690 of lalr1.cc  */
#line 2780 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_ascending );
        }
    break;

  case 324:

/* Line 690 of lalr1.cc  */
#line 2784 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_descending );
        }
    break;

  case 325:

/* Line 690 of lalr1.cc  */
#line 2790 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_greatest
            );
        }
    break;

  case 326:

/* Line 690 of lalr1.cc  */
#line 2796 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_least
            );
        }
    break;

  case 327:

/* Line 690 of lalr1.cc  */
#line 2804 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 328:

/* Line 690 of lalr1.cc  */
#line 2810 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new QuantifiedExpr(
                LOC((yyloc)),
                ParseConstants::quant_some,
                dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(5) - (3)].node)),
                (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 329:

/* Line 690 of lalr1.cc  */
#line 2819 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new QuantifiedExpr(
                LOC((yyloc)),
                ParseConstants::quant_every,
                dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(5) - (3)].node)),
                (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 330:

/* Line 690 of lalr1.cc  */
#line 2830 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      QVarInDeclList *qvidl = new QVarInDeclList( LOC((yyloc)) );
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = qvidl;
    }
    break;

  case 331:

/* Line 690 of lalr1.cc  */
#line 2836 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      QVarInDeclList *qvidl = dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
      (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
    }
    break;

  case 332:

/* Line 690 of lalr1.cc  */
#line 2844 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 333:

/* Line 690 of lalr1.cc  */
#line 2848 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                          dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 334:

/* Line 690 of lalr1.cc  */
#line 2857 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new SwitchExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(8) - (5)].node)), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 335:

/* Line 690 of lalr1.cc  */
#line 2863 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = new SwitchCaseClauseList(LOC((yyloc)));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = scc_list_p;
    }
    break;

  case 336:

/* Line 690 of lalr1.cc  */
#line 2869 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 337:

/* Line 690 of lalr1.cc  */
#line 2877 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SwitchCaseClause(LOC((yyloc)), dynamic_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 338:

/* Line 690 of lalr1.cc  */
#line 2883 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = new SwitchCaseOperandList(LOC((yyloc)));
      sco_list_p->push_back((yysemantic_stack_[(2) - (2)].expr));
      (yyval.node) = sco_list_p;
    }
    break;

  case 339:

/* Line 690 of lalr1.cc  */
#line 2889 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = static_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node));
      sco_list_p->push_back((yysemantic_stack_[(3) - (3)].expr));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 340:

/* Line 690 of lalr1.cc  */
#line 2897 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new SwitchExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(8) - (5)].node)), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 341:

/* Line 690 of lalr1.cc  */
#line 2903 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = new SwitchCaseClauseList(LOC((yyloc)));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = scc_list_p;
    }
    break;

  case 342:

/* Line 690 of lalr1.cc  */
#line 2909 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 343:

/* Line 690 of lalr1.cc  */
#line 2917 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SwitchCaseClause(LOC((yyloc)), dynamic_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 344:

/* Line 690 of lalr1.cc  */
#line 2923 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC((yyloc)),
                              (yysemantic_stack_[(8) - (3)].expr),
                              static_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
                              (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 345:

/* Line 690 of lalr1.cc  */
#line 2930 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
                              (yysemantic_stack_[(10) - (3)].expr),
                              static_cast<CaseClauseList*>((yysemantic_stack_[(10) - (5)].node)),
                              static_cast<QName*>((yysemantic_stack_[(10) - (8)].expr)),
                              (yysemantic_stack_[(10) - (10)].expr));
    }
    break;

  case 346:

/* Line 690 of lalr1.cc  */
#line 2940 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC((yyloc)),
                              (yysemantic_stack_[(8) - (3)].expr),
                              static_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
                              (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 347:

/* Line 690 of lalr1.cc  */
#line 2947 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
                              (yysemantic_stack_[(10) - (3)].expr),
                              static_cast<CaseClauseList*>((yysemantic_stack_[(10) - (5)].node)),
                              static_cast<QName*>((yysemantic_stack_[(10) - (8)].expr)),
                              (yysemantic_stack_[(10) - (10)].expr));
    }
    break;

  case 348:

/* Line 690 of lalr1.cc  */
#line 2957 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
      cc_list_p->push_back(static_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = cc_list_p;
    }
    break;

  case 349:

/* Line 690 of lalr1.cc  */
#line 2963 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      cc_list_p->push_back(static_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 350:

/* Line 690 of lalr1.cc  */
#line 2971 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<SequenceTypeList*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 351:

/* Line 690 of lalr1.cc  */
#line 2977 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                          static_cast<SequenceTypeList*>((yysemantic_stack_[(7) - (5)].node)),
                          (yysemantic_stack_[(7) - (7)].expr));
     }
    break;

  case 352:

/* Line 690 of lalr1.cc  */
#line 2986 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
      cc_list_p->push_back(static_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = cc_list_p;
    }
    break;

  case 353:

/* Line 690 of lalr1.cc  */
#line 2992 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      CaseClauseList* cc_list_p = static_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      cc_list_p->push_back(static_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 354:

/* Line 690 of lalr1.cc  */
#line 3000 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<SequenceTypeList*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 355:

/* Line 690 of lalr1.cc  */
#line 3006 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                          static_cast<SequenceTypeList*>((yysemantic_stack_[(7) - (5)].node)),
                          (yysemantic_stack_[(7) - (7)].expr));
     }
    break;

  case 356:

/* Line 690 of lalr1.cc  */
#line 3015 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      SequenceTypeList* seqList = new SequenceTypeList(LOC((yyloc)));
      seqList->push_back(static_cast<SequenceType*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = seqList;
    }
    break;

  case 357:

/* Line 690 of lalr1.cc  */
#line 3021 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      SequenceTypeList* seqList = static_cast<SequenceTypeList*>((yysemantic_stack_[(3) - (1)].node));
      seqList->push_back(static_cast<SequenceType*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 358:

/* Line 690 of lalr1.cc  */
#line 3029 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new IfExpr(LOC ((yyloc)), (yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (6)].expr), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 359:

/* Line 690 of lalr1.cc  */
#line 3035 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 360:

/* Line 690 of lalr1.cc  */
#line 3039 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new OrExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
    }
    break;

  case 361:

/* Line 690 of lalr1.cc  */
#line 3045 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 362:

/* Line 690 of lalr1.cc  */
#line 3050 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new AndExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 363:

/* Line 690 of lalr1.cc  */
#line 3056 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 364:

/* Line 690 of lalr1.cc  */
#line 3060 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new ComparisonExpr(
              LOC((yyloc)),
              new ValueComp( LOC((yyloc)), ParseConstants::op_val_not ),
              (yysemantic_stack_[(2) - (2)].expr),
              NULL
          );
        }
    break;

  case 365:

/* Line 690 of lalr1.cc  */
#line 3071 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 366:

/* Line 690 of lalr1.cc  */
#line 3075 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                dynamic_cast<ValueComp*>((yysemantic_stack_[(3) - (2)].node)),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 367:

/* Line 690 of lalr1.cc  */
#line 3086 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 368:

/* Line 690 of lalr1.cc  */
#line 3090 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 3101 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 370:

/* Line 690 of lalr1.cc  */
#line 3105 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new StringConcatExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
        }
    break;

  case 371:

/* Line 690 of lalr1.cc  */
#line 3110 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 372:

/* Line 690 of lalr1.cc  */
#line 3114 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 373:

/* Line 690 of lalr1.cc  */
#line 3120 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 374:

/* Line 690 of lalr1.cc  */
#line 3124 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new RangeExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 375:

/* Line 690 of lalr1.cc  */
#line 3130 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 376:

/* Line 690 of lalr1.cc  */
#line 3134 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_plus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 377:

/* Line 690 of lalr1.cc  */
#line 3138 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_minus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 378:

/* Line 690 of lalr1.cc  */
#line 3144 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 379:

/* Line 690 of lalr1.cc  */
#line 3148 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mul, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 380:

/* Line 690 of lalr1.cc  */
#line 3154 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_div, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 381:

/* Line 690 of lalr1.cc  */
#line 3160 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_idiv, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 382:

/* Line 690 of lalr1.cc  */
#line 3166 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mod, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 383:

/* Line 690 of lalr1.cc  */
#line 3174 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 384:

/* Line 690 of lalr1.cc  */
#line 3178 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 385:

/* Line 690 of lalr1.cc  */
#line 3182 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 386:

/* Line 690 of lalr1.cc  */
#line 3188 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 387:

/* Line 690 of lalr1.cc  */
#line 3192 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_intersect, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 388:

/* Line 690 of lalr1.cc  */
#line 3198 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_except, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 389:

/* Line 690 of lalr1.cc  */
#line 3206 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 390:

/* Line 690 of lalr1.cc  */
#line 3210 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InstanceofExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 391:

/* Line 690 of lalr1.cc  */
#line 3218 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 392:

/* Line 690 of lalr1.cc  */
#line 3222 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new TreatExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 393:

/* Line 690 of lalr1.cc  */
#line 3230 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 394:

/* Line 690 of lalr1.cc  */
#line 3234 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new CastableExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 395:

/* Line 690 of lalr1.cc  */
#line 3242 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 396:

/* Line 690 of lalr1.cc  */
#line 3246 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new CastExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 397:

/* Line 690 of lalr1.cc  */
#line 3254 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SingleType(LOC((yyloc)), dynamic_cast<SimpleType*>((yysemantic_stack_[(1) - (1)].node)), false);
    }
    break;

  case 398:

/* Line 690 of lalr1.cc  */
#line 3258 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SingleType(LOC((yyloc)), dynamic_cast<SimpleType*>((yysemantic_stack_[(2) - (1)].node)), true);
    }
    break;

  case 399:

/* Line 690 of lalr1.cc  */
#line 3264 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 400:

/* Line 690 of lalr1.cc  */
#line 3268 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new UnaryExpr( LOC((yyloc)), dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 401:

/* Line 690 of lalr1.cc  */
#line 3274 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), true );
        }
    break;

  case 402:

/* Line 690 of lalr1.cc  */
#line 3278 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), false );
        }
    break;

  case 403:

/* Line 690 of lalr1.cc  */
#line 3282 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 404:

/* Line 690 of lalr1.cc  */
#line 3286 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            if ( SignList *sl = dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)) )
                sl->negate();
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 408:

/* Line 690 of lalr1.cc  */
#line 3299 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
      }
    break;

  case 409:

/* Line 690 of lalr1.cc  */
#line 3304 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.expr) = new SimpleMapExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
      }
    break;

  case 410:

/* Line 690 of lalr1.cc  */
#line 3310 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_eq );
        }
    break;

  case 411:

/* Line 690 of lalr1.cc  */
#line 3314 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ne );
        }
    break;

  case 412:

/* Line 690 of lalr1.cc  */
#line 3318 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_lt );
        }
    break;

  case 413:

/* Line 690 of lalr1.cc  */
#line 3322 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_le );
        }
    break;

  case 414:

/* Line 690 of lalr1.cc  */
#line 3326 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_gt );
        }
    break;

  case 415:

/* Line 690 of lalr1.cc  */
#line 3330 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ge );
        }
    break;

  case 416:

/* Line 690 of lalr1.cc  */
#line 3336 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 417:

/* Line 690 of lalr1.cc  */
#line 3340 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "lax", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 418:

/* Line 690 of lalr1.cc  */
#line 3344 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 419:

/* Line 690 of lalr1.cc  */
#line 3348 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ValidateExpr(
                LOC((yyloc)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (3)].node))->get_name(), (yysemantic_stack_[(6) - (5)].expr)
            );
            delete (yysemantic_stack_[(6) - (3)].node);
        }
    break;

  case 420:

/* Line 690 of lalr1.cc  */
#line 3357 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(3) - (1)].node)), NULL
            );
        }
    break;

  case 421:

/* Line 690 of lalr1.cc  */
#line 3363 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)), (yysemantic_stack_[(4) - (3)].expr)
            );
        }
    break;

  case 422:

/* Line 690 of lalr1.cc  */
#line 3371 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            PragmaList *pl = new PragmaList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = pl;
        }
    break;

  case 423:

/* Line 690 of lalr1.cc  */
#line 3377 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            if ( PragmaList *pl = dynamic_cast<PragmaList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 424:

/* Line 690 of lalr1.cc  */
#line 3385 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
        }
    break;

  case 425:

/* Line 690 of lalr1.cc  */
#line 3389 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) ), "" );
        }
    break;

  case 426:

/* Line 690 of lalr1.cc  */
#line 3393 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), true ), "" );
        }
    break;

  case 427:

/* Line 690 of lalr1.cc  */
#line 3399 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new PathExpr(LOC((yyloc)), ParseConstants::path_leading_lone_slash, NULL);
    }
    break;

  case 428:

/* Line 690 of lalr1.cc  */
#line 3403 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      RelativePathExpr* rpe;
      rpe = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slash, NULL, (yysemantic_stack_[(2) - (2)].expr), false);
      (yyval.expr) = new PathExpr(LOC((yyloc)),
                        ParseConstants::path_leading_slash,
                        rpe);
    }
    break;

  case 429:

/* Line 690 of lalr1.cc  */
#line 3411 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      RelativePathExpr* rpe;
      rpe = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slashslash, NULL, (yysemantic_stack_[(2) - (2)].expr), false);
      (yyval.expr) = new PathExpr(LOC((yyloc)),
                        ParseConstants::path_leading_slashslash,
                        rpe);
    }
    break;

  case 430:

/* Line 690 of lalr1.cc  */
#line 3419 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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

  case 431:

/* Line 690 of lalr1.cc  */
#line 3438 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = NULL;
    }
    break;

  case 432:

/* Line 690 of lalr1.cc  */
#line 3444 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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

  case 433:

/* Line 690 of lalr1.cc  */
#line 3454 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr), false);
    }
    break;

  case 434:

/* Line 690 of lalr1.cc  */
#line 3458 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slashslash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr), false);
    }
    break;

  case 437:

/* Line 690 of lalr1.cc  */
#line 3468 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)), dynamic_cast<ForwardStep*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 438:

/* Line 690 of lalr1.cc  */
#line 3474 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)),
                dynamic_cast<ForwardStep*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 439:

/* Line 690 of lalr1.cc  */
#line 3482 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)), dynamic_cast<ReverseStep*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 440:

/* Line 690 of lalr1.cc  */
#line 3488 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)),
                dynamic_cast<ReverseStep*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 441:

/* Line 690 of lalr1.cc  */
#line 3498 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ForwardStep(
                LOC((yyloc)), dynamic_cast<ForwardAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node)
            );
        }
    break;

  case 442:

/* Line 690 of lalr1.cc  */
#line 3504 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ForwardStep(
                LOC((yyloc)), dynamic_cast<AbbrevForwardStep*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 443:

/* Line 690 of lalr1.cc  */
#line 3512 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_child );
        }
    break;

  case 444:

/* Line 690 of lalr1.cc  */
#line 3516 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_descendant);
        }
    break;

  case 445:

/* Line 690 of lalr1.cc  */
#line 3520 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_attribute );
        }
    break;

  case 446:

/* Line 690 of lalr1.cc  */
#line 3524 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_self );
        }
    break;

  case 447:

/* Line 690 of lalr1.cc  */
#line 3528 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ForwardAxis(
                LOC((yyloc)), ParseConstants::axis_descendant_or_self
            );
        }
    break;

  case 448:

/* Line 690 of lalr1.cc  */
#line 3534 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ForwardAxis(
                LOC((yyloc)), ParseConstants::axis_following_sibling
            );
        }
    break;

  case 449:

/* Line 690 of lalr1.cc  */
#line 3540 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_following );
        }
    break;

  case 450:

/* Line 690 of lalr1.cc  */
#line 3546 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new AbbrevForwardStep( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), false );
        }
    break;

  case 451:

/* Line 690 of lalr1.cc  */
#line 3550 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new AbbrevForwardStep( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].node), true );
        }
    break;

  case 452:

/* Line 690 of lalr1.cc  */
#line 3556 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ReverseStep( LOC((yyloc)), dynamic_cast<ReverseAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node) );
        }
    break;

  case 453:

/* Line 690 of lalr1.cc  */
#line 3560 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            ReverseAxis *ra = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_parent
            );
            (yyval.node) = new ReverseStep( LOC((yyloc)), ra, NULL );
        }
    break;

  case 454:

/* Line 690 of lalr1.cc  */
#line 3569 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_parent );
        }
    break;

  case 455:

/* Line 690 of lalr1.cc  */
#line 3573 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_ancestor );
        }
    break;

  case 456:

/* Line 690 of lalr1.cc  */
#line 3577 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_preceding_sibling
            );
        }
    break;

  case 457:

/* Line 690 of lalr1.cc  */
#line 3583 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_preceding );
        }
    break;

  case 458:

/* Line 690 of lalr1.cc  */
#line 3587 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_ancestor_or_self
            );
        }
    break;

  case 461:

/* Line 690 of lalr1.cc  */
#line 3599 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 462:

/* Line 690 of lalr1.cc  */
#line 3603 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), dynamic_cast<Wildcard*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 463:

/* Line 690 of lalr1.cc  */
#line 3609 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", "", ParseConstants::wild_all, false);
    }
    break;

  case 464:

/* Line 690 of lalr1.cc  */
#line 3613 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), "", ParseConstants::wild_elem, false);
    }
    break;

  case 465:

/* Line 690 of lalr1.cc  */
#line 3617 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), "", ParseConstants::wild_elem, true);
    }
    break;

  case 466:

/* Line 690 of lalr1.cc  */
#line 3621 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", SYMTAB((yysemantic_stack_[(1) - (1)].sval)), ParseConstants::wild_prefix, false);
    }
    break;

  case 467:

/* Line 690 of lalr1.cc  */
#line 3627 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
     }
    break;

  case 468:

/* Line 690 of lalr1.cc  */
#line 3631 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new FilterExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
     }
    break;

  case 469:

/* Line 690 of lalr1.cc  */
#line 3635 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new DynamicFunctionInvocation(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), false);
     }
    break;

  case 470:

/* Line 690 of lalr1.cc  */
#line 3639 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new DynamicFunctionInvocation(LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node)), false);
     }
    break;

  case 471:

/* Line 690 of lalr1.cc  */
#line 3643 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
       ERROR_IF_QNAME_NOT_NCNAME((yysemantic_stack_[(3) - (3)].expr), (yylocation_stack_[(3) - (3)]));
       StringLiteral* sl = new StringLiteral( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)) );
       (yyval.expr) = new JSONObjectLookup(LOC((yyloc)), LOC((yylocation_stack_[(3) - (2)])), (yysemantic_stack_[(3) - (1)].expr), sl);
     }
    break;

  case 472:

/* Line 690 of lalr1.cc  */
#line 3649 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new JSONObjectLookup(LOC((yyloc)), LOC((yylocation_stack_[(4) - (2)])), (yysemantic_stack_[(4) - (1)].expr), new ParenthesizedExpr( LOC((yyloc)), NULL));
     }
    break;

  case 473:

/* Line 690 of lalr1.cc  */
#line 3653 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new JSONObjectLookup(LOC((yyloc)), LOC((yylocation_stack_[(5) - (2)])), (yysemantic_stack_[(5) - (1)].expr), new ParenthesizedExpr( LOC((yyloc)), (yysemantic_stack_[(5) - (4)].expr) ));
     }
    break;

  case 474:

/* Line 690 of lalr1.cc  */
#line 3657 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.expr) = new JSONObjectLookup(LOC((yyloc)), LOC((yylocation_stack_[(3) - (2)])), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
     }
    break;

  case 475:

/* Line 690 of lalr1.cc  */
#line 3661 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new JSONObjectLookup(LOC((yyloc)), LOC((yylocation_stack_[(3) - (2)])), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
     }
    break;

  case 476:

/* Line 690 of lalr1.cc  */
#line 3667 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            PredicateList *pl = new PredicateList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<exprnode*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.node) = pl;
        }
    break;

  case 477:

/* Line 690 of lalr1.cc  */
#line 3673 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            if ( PredicateList *pl = dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<exprnode*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 478:

/* Line 690 of lalr1.cc  */
#line 3681 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
        }
    break;

  case 493:

/* Line 690 of lalr1.cc  */
#line 3703 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 494:

/* Line 690 of lalr1.cc  */
#line 3707 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 495:

/* Line 690 of lalr1.cc  */
#line 3711 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            driver.addCommonLanguageWarning((yylocation_stack_[(1) - (1)]), ZED(ZWST0009_TRUE_FALSE_NULL_KEYWORDS));
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 496:

/* Line 690 of lalr1.cc  */
#line 3716 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            driver.addCommonLanguageWarning((yylocation_stack_[(1) - (1)]), ZED(ZWST0009_TRUE_FALSE_NULL_KEYWORDS));
            (yyval.expr) = new NullLiteral(LOC((yyloc)));
        }
    break;

  case 497:

/* Line 690 of lalr1.cc  */
#line 3723 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_decimal, *(yysemantic_stack_[(1) - (1)].decval)
            );
            delete yylval.decval;
        }
    break;

  case 498:

/* Line 690 of lalr1.cc  */
#line 3730 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_integer, *(yysemantic_stack_[(1) - (1)].ival)
            );
            delete yylval.ival;
        }
    break;

  case 499:

/* Line 690 of lalr1.cc  */
#line 3737 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_double, *(yysemantic_stack_[(1) - (1)].dval)
            );
            delete yylval.dval;
        }
    break;

  case 500:

/* Line 690 of lalr1.cc  */
#line 3746 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new BooleanLiteral(LOC((yyloc)), true);
        }
    break;

  case 501:

/* Line 690 of lalr1.cc  */
#line 3750 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new BooleanLiteral(LOC((yyloc)), false);
        }
    break;

  case 502:

/* Line 690 of lalr1.cc  */
#line 3756 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new VarRef(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)));
        }
    break;

  case 503:

/* Line 690 of lalr1.cc  */
#line 3762 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), NULL);
        }
    break;

  case 504:

/* Line 690 of lalr1.cc  */
#line 3766 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 505:

/* Line 690 of lalr1.cc  */
#line 3772 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            driver.addCommonLanguageWarning((yylocation_stack_[(1) - (1)]), ZED(ZWST0009_CONTEXT_ITEM_EXPR));
            (yyval.expr) = new ContextItemExpr( LOC((yyloc)) );
        }
    break;

  case 506:

/* Line 690 of lalr1.cc  */
#line 3779 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new OrderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 507:

/* Line 690 of lalr1.cc  */
#line 3785 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new UnorderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 508:

/* Line 690 of lalr1.cc  */
#line 3791 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new FunctionCall( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), NULL );
    }
    break;

  case 509:

/* Line 690 of lalr1.cc  */
#line 3795 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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

  case 510:

/* Line 690 of lalr1.cc  */
#line 3813 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      ArgList *al = new ArgList( LOC((yyloc)) );
      al->push_back(new ArgumentPlaceholder(LOC((yyloc))));
      (yyval.node) = al;
    }
    break;

  case 511:

/* Line 690 of lalr1.cc  */
#line 3819 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      if ( ArgList *al = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node)) )
        al->push_back( new ArgumentPlaceholder(LOC((yyloc))) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 512:

/* Line 690 of lalr1.cc  */
#line 3825 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      ArgList *al = new ArgList( LOC((yyloc)) );
      al->push_back( (yysemantic_stack_[(1) - (1)].expr) );
      (yyval.node) = al;
    }
    break;

  case 513:

/* Line 690 of lalr1.cc  */
#line 3831 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      if ( ArgList *al = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node)) )
        al->push_back( (yysemantic_stack_[(3) - (3)].expr) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 514:

/* Line 690 of lalr1.cc  */
#line 3839 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 515:

/* Line 690 of lalr1.cc  */
#line 3843 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 516:

/* Line 690 of lalr1.cc  */
#line 3849 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new LiteralFunctionItem(LOC ((yyloc)), dynamic_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].ival));
    }
    break;

  case 517:

/* Line 690 of lalr1.cc  */
#line 3855 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new InlineFunction(LOC((yyloc)),
                              &*(yysemantic_stack_[(3) - (2)].fnsig)->theParams,
                              &*(yysemantic_stack_[(3) - (2)].fnsig)->theReturnType,
                              (yysemantic_stack_[(3) - (3)].expr));
      delete (yysemantic_stack_[(3) - (2)].fnsig);
    }
    break;

  case 523:

/* Line 690 of lalr1.cc  */
#line 3874 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new DirElemConstructor(LOC((yyloc)),
                                  static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                                  NULL,
                                  NULL,
                                  NULL);
    }
    break;

  case 524:

/* Line 690 of lalr1.cc  */
#line 3882 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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

  case 525:

/* Line 690 of lalr1.cc  */
#line 3898 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new DirElemConstructor(LOC((yyloc)),
                                  static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                                  NULL,
                                  dynamic_cast<DirAttributeList*>((yysemantic_stack_[(5) - (3)].node)),
                                  NULL);
    }
    break;

  case 526:

/* Line 690 of lalr1.cc  */
#line 3906 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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

  case 527:

/* Line 690 of lalr1.cc  */
#line 3924 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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

  case 528:

/* Line 690 of lalr1.cc  */
#line 3942 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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

  case 529:

/* Line 690 of lalr1.cc  */
#line 3960 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      DirElemContentList *decl = new DirElemContentList( LOC((yyloc)) );
      decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(1) - (1)].expr)) );
      (yyval.node) = decl;
    }
    break;

  case 530:

/* Line 690 of lalr1.cc  */
#line 3966 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      DirElemContentList *decl = dynamic_cast<DirElemContentList*>((yysemantic_stack_[(2) - (1)].node));
      if ( decl )
        decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(2) - (2)].expr)) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 531:

/* Line 690 of lalr1.cc  */
#line 3975 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      DirAttributeList *dal = new DirAttributeList( LOC((yyloc)) );
      dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = dal;
    }
    break;

  case 532:

/* Line 690 of lalr1.cc  */
#line 3981 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      DirAttributeList *dal = dynamic_cast<DirAttributeList*>((yysemantic_stack_[(2) - (1)].node));
      if ( dal )
        dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 533:

/* Line 690 of lalr1.cc  */
#line 3990 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DirAttr(LOC((yyloc)),
                       static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                       dynamic_cast<DirAttributeValue*>((yysemantic_stack_[(6) - (6)].node)));
    }
    break;

  case 536:

/* Line 690 of lalr1.cc  */
#line 4000 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DirAttributeValue(LOC((yyloc)),
                                 dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
    }
    break;

  case 537:

/* Line 690 of lalr1.cc  */
#line 4005 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DirAttributeValue( LOC((yyloc)),
                                  dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
    }
    break;

  case 538:

/* Line 690 of lalr1.cc  */
#line 4011 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new QuoteAttrContentList( LOC((yyloc)) );
    }
    break;

  case 539:

/* Line 690 of lalr1.cc  */
#line 4015 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 540:

/* Line 690 of lalr1.cc  */
#line 4021 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
      qacl->push_back( new QuoteAttrValueContent( LOC((yyloc)), "\"" ) );
      (yyval.node) = qacl;
    }
    break;

  case 541:

/* Line 690 of lalr1.cc  */
#line 4027 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
      qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = qacl;
    }
    break;

  case 542:

/* Line 690 of lalr1.cc  */
#line 4033 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      QuoteAttrContentList* qacl = dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
      if ( qacl )
        qacl->push_back( new QuoteAttrValueContent( LOC((yyloc)), "\"" ) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 543:

/* Line 690 of lalr1.cc  */
#line 4040 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      QuoteAttrContentList *qacl = dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
      if ( qacl )
        qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 544:

/* Line 690 of lalr1.cc  */
#line 4048 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AposAttrContentList( LOC((yyloc)) );
    }
    break;

  case 545:

/* Line 690 of lalr1.cc  */
#line 4052 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 546:

/* Line 690 of lalr1.cc  */
#line 4058 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
      aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
      (yyval.node) = aacl;
    }
    break;

  case 547:

/* Line 690 of lalr1.cc  */
#line 4064 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
      aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = aacl;
    }
    break;

  case 548:

/* Line 690 of lalr1.cc  */
#line 4070 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
      if (aacl)
        aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 549:

/* Line 690 of lalr1.cc  */
#line 4077 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
      if ( aacl )
        aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 550:

/* Line 690 of lalr1.cc  */
#line 4086 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new QuoteAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
    }
    break;

  case 551:

/* Line 690 of lalr1.cc  */
#line 4090 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new QuoteAttrValueContent(LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
    }
    break;

  case 552:

/* Line 690 of lalr1.cc  */
#line 4096 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AposAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
    }
    break;

  case 553:

/* Line 690 of lalr1.cc  */
#line 4100 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AposAttrValueContent(LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
    }
    break;

  case 554:

/* Line 690 of lalr1.cc  */
#line 4106 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new DirElemContent( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr) );
    }
    break;

  case 555:

/* Line 690 of lalr1.cc  */
#line 4110 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new DirElemContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
    }
    break;

  case 556:

/* Line 690 of lalr1.cc  */
#line 4114 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      rchandle<CDataSection> cdata_h = dynamic_cast<CDataSection*>((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = new DirElemContent( LOC((yyloc)), cdata_h );
    }
    break;

  case 557:

/* Line 690 of lalr1.cc  */
#line 4119 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      rchandle<CommonContent> cont_h = dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = new DirElemContent( LOC((yyloc)), cont_h );
    }
    break;

  case 558:

/* Line 690 of lalr1.cc  */
#line 4126 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CommonContent(LOC((yyloc)), ParseConstants::cont_charref, SYMTAB((yysemantic_stack_[(1) - (1)].sval)));
    }
    break;

  case 559:

/* Line 690 of lalr1.cc  */
#line 4130 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CommonContent(LOC((yyloc)), ParseConstants::cont_escape_lbrace);
    }
    break;

  case 560:

/* Line 690 of lalr1.cc  */
#line 4134 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CommonContent(LOC((yyloc)), ParseConstants::cont_escape_rbrace);
    }
    break;

  case 561:

/* Line 690 of lalr1.cc  */
#line 4138 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CommonContent(LOC((yyloc)), new EnclosedExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr)));
    }
    break;

  case 562:

/* Line 690 of lalr1.cc  */
#line 4144 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 563:

/* Line 690 of lalr1.cc  */
#line 4149 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), "" );
    }
    break;

  case 564:

/* Line 690 of lalr1.cc  */
#line 4155 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      ERROR_IF_QNAME_NOT_NCNAME((yysemantic_stack_[(3) - (2)].expr), (yylocation_stack_[(3) - (2)]));
      (yyval.expr) = new DirPIConstructor( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)) );
    }
    break;

  case 565:

/* Line 690 of lalr1.cc  */
#line 4161 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      ERROR_IF_QNAME_NOT_NCNAME((yysemantic_stack_[(3) - (2)].expr), (yylocation_stack_[(3) - (2)]));
      (yyval.expr) = new DirPIConstructor( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
    }
    break;

  case 566:

/* Line 690 of lalr1.cc  */
#line 4168 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CDataSection( LOC((yyloc)),SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
    }
    break;

  case 567:

/* Line 690 of lalr1.cc  */
#line 4174 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 568:

/* Line 690 of lalr1.cc  */
#line 4179 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 569:

/* Line 690 of lalr1.cc  */
#line 4184 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 570:

/* Line 690 of lalr1.cc  */
#line 4189 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 571:

/* Line 690 of lalr1.cc  */
#line 4194 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 572:

/* Line 690 of lalr1.cc  */
#line 4199 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 574:

/* Line 690 of lalr1.cc  */
#line 4207 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompDocConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
    }
    break;

  case 575:

/* Line 690 of lalr1.cc  */
#line 4213 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompElemConstructor(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval))), (yysemantic_stack_[(3) - (2)].expr));
    }
    break;

  case 576:

/* Line 690 of lalr1.cc  */
#line 4217 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompElemConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
    }
    break;

  case 577:

/* Line 690 of lalr1.cc  */
#line 4223 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval))), (yysemantic_stack_[(3) - (2)].expr) );
    }
    break;

  case 578:

/* Line 690 of lalr1.cc  */
#line 4227 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
    }
    break;

  case 579:

/* Line 690 of lalr1.cc  */
#line 4233 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompTextConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
    }
    break;

  case 580:

/* Line 690 of lalr1.cc  */
#line 4239 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompCommentConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
    }
    break;

  case 581:

/* Line 690 of lalr1.cc  */
#line 4245 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompPIConstructor(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval)), (yysemantic_stack_[(3) - (2)].expr));
    }
    break;

  case 582:

/* Line 690 of lalr1.cc  */
#line 4249 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompPIConstructor(LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
    }
    break;

  case 583:

/* Line 690 of lalr1.cc  */
#line 4255 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompNamespaceConstructor(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval)), (yysemantic_stack_[(3) - (2)].expr));
    }
    break;

  case 584:

/* Line 690 of lalr1.cc  */
#line 4259 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompNamespaceConstructor(LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
    }
    break;

  case 585:

/* Line 690 of lalr1.cc  */
#line 4265 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 586:

/* Line 690 of lalr1.cc  */
#line 4271 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL );
        }
    break;

  case 587:

/* Line 690 of lalr1.cc  */
#line 4275 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new SequenceType(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node)));
        }
    break;

  case 588:

/* Line 690 of lalr1.cc  */
#line 4279 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 589:

/* Line 690 of lalr1.cc  */
#line 4283 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            driver.addCommonLanguageWarning((yylocation_stack_[(2) - (1)]), ZED(ZWST0009_JSONIQ_EMPTY_SEQUENCE));
            (yyval.node) = new SequenceType( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 590:

/* Line 690 of lalr1.cc  */
#line 4290 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_optionally
            );
        }
    break;

  case 591:

/* Line 690 of lalr1.cc  */
#line 4296 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_zero_or_more
            );
        }
    break;

  case 592:

/* Line 690 of lalr1.cc  */
#line 4302 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_one_or_more
            );
        }
    break;

  case 593:

/* Line 690 of lalr1.cc  */
#line 4310 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 594:

/* Line 690 of lalr1.cc  */
#line 4314 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 595:

/* Line 690 of lalr1.cc  */
#line 4318 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ItemType( LOC((yyloc)), true );
        }
    break;

  case 596:

/* Line 690 of lalr1.cc  */
#line 4322 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            driver.addCommonLanguageWarning((yylocation_stack_[(1) - (1)]), ZED(ZWST0009_JSONIQ_TYPE_KEYWORDS));
            (yyval.node) = new ItemType( LOC((yyloc)), true );
        }
    break;

  case 597:

/* Line 690 of lalr1.cc  */
#line 4327 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new StructuredItemType(LOC((yyloc)));
        }
    break;

  case 598:

/* Line 690 of lalr1.cc  */
#line 4331 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            driver.addCommonLanguageWarning((yylocation_stack_[(1) - (1)]), ZED(ZWST0009_JSONIQ_TYPE_KEYWORDS));
            (yyval.node) = new StructuredItemType(LOC((yyloc)));
        }
    break;

  case 599:

/* Line 690 of lalr1.cc  */
#line 4336 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 600:

/* Line 690 of lalr1.cc  */
#line 4340 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 601:

/* Line 690 of lalr1.cc  */
#line 4344 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 602:

/* Line 690 of lalr1.cc  */
#line 4350 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
          TypeList* aTypeList = new TypeList(LOC ((yyloc)));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(1) - (1)].node)));
          (yyval.node) = aTypeList;
        }
    break;

  case 603:

/* Line 690 of lalr1.cc  */
#line 4356 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
          TypeList* aTypeList = dynamic_cast<TypeList *>((yysemantic_stack_[(3) - (1)].node));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
          (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 604:

/* Line 690 of lalr1.cc  */
#line 4364 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new GeneralizedAtomicType( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
    }
    break;

  case 605:

/* Line 690 of lalr1.cc  */
#line 4368 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new GeneralizedAtomicType( LOC((yyloc)), new QName(LOC((yyloc)), "null") );
    }
    break;

  case 606:

/* Line 690 of lalr1.cc  */
#line 4374 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SimpleType( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
    }
    break;

  case 607:

/* Line 690 of lalr1.cc  */
#line 4380 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 608:

/* Line 690 of lalr1.cc  */
#line 4384 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 609:

/* Line 690 of lalr1.cc  */
#line 4388 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 610:

/* Line 690 of lalr1.cc  */
#line 4392 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 611:

/* Line 690 of lalr1.cc  */
#line 4396 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 612:

/* Line 690 of lalr1.cc  */
#line 4400 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 613:

/* Line 690 of lalr1.cc  */
#line 4404 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 614:

/* Line 690 of lalr1.cc  */
#line 4408 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 615:

/* Line 690 of lalr1.cc  */
#line 4412 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 616:

/* Line 690 of lalr1.cc  */
#line 4416 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 617:

/* Line 690 of lalr1.cc  */
#line 4422 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AnyKindTest( LOC((yyloc)) );
    }
    break;

  case 618:

/* Line 690 of lalr1.cc  */
#line 4428 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = NULL;
    }
    break;

  case 619:

/* Line 690 of lalr1.cc  */
#line 4434 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DocumentTest(LOC((yyloc)));
    }
    break;

  case 620:

/* Line 690 of lalr1.cc  */
#line 4438 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DocumentTest(LOC((yyloc)), dynamic_cast<ElementTest*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 621:

/* Line 690 of lalr1.cc  */
#line 4442 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DocumentTest(LOC((yyloc)), dynamic_cast<SchemaElementTest*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 622:

/* Line 690 of lalr1.cc  */
#line 4448 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new NamespaceTest(LOC((yyloc)));
    }
    break;

  case 623:

/* Line 690 of lalr1.cc  */
#line 4453 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new TextTest(LOC((yyloc)));
    }
    break;

  case 624:

/* Line 690 of lalr1.cc  */
#line 4459 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CommentTest(LOC((yyloc)));
    }
    break;

  case 625:

/* Line 690 of lalr1.cc  */
#line 4465 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), "" );
        }
    break;

  case 626:

/* Line 690 of lalr1.cc  */
#line 4469 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            ERROR_IF_QNAME_NOT_NCNAME((yysemantic_stack_[(4) - (3)].expr), (yylocation_stack_[(4) - (3)]));
            (yyval.node) = new PITest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 627:

/* Line 690 of lalr1.cc  */
#line 4474 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 628:

/* Line 690 of lalr1.cc  */
#line 4480 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 629:

/* Line 690 of lalr1.cc  */
#line 4484 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL
            );
        }
    break;

  case 630:

/* Line 690 of lalr1.cc  */
#line 4490 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 631:

/* Line 690 of lalr1.cc  */
#line 4496 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 632:

/* Line 690 of lalr1.cc  */
#line 4500 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 633:

/* Line 690 of lalr1.cc  */
#line 4508 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new SchemaAttributeTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 634:

/* Line 690 of lalr1.cc  */
#line 4514 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ElementTest( LOC((yyloc)), NULL, NULL, true );
        }
    break;

  case 635:

/* Line 690 of lalr1.cc  */
#line 4518 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL, true
            );
        }
    break;

  case 636:

/* Line 690 of lalr1.cc  */
#line 4524 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                false
            );
        }
    break;

  case 637:

/* Line 690 of lalr1.cc  */
#line 4533 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                true
            );
        }
    break;

  case 638:

/* Line 690 of lalr1.cc  */
#line 4542 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, NULL, true
            );
        }
    break;

  case 639:

/* Line 690 of lalr1.cc  */
#line 4548 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), false
            );
        }
    break;

  case 640:

/* Line 690 of lalr1.cc  */
#line 4554 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), true
            );
        }
    break;

  case 641:

/* Line 690 of lalr1.cc  */
#line 4562 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new SchemaElementTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 642:

/* Line 690 of lalr1.cc  */
#line 4568 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 643:

/* Line 690 of lalr1.cc  */
#line 4574 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (1)].expr)), true );
        }
    break;

  case 644:

/* Line 690 of lalr1.cc  */
#line 4580 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new StringLiteral( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 645:

/* Line 690 of lalr1.cc  */
#line 4586 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 646:

/* Line 690 of lalr1.cc  */
#line 4590 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 647:

/* Line 690 of lalr1.cc  */
#line 4596 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AnyFunctionTest(LOC((yyloc)));
    }
    break;

  case 648:

/* Line 690 of lalr1.cc  */
#line 4602 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)), dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (5)].node)));
        }
    break;

  case 649:

/* Line 690 of lalr1.cc  */
#line 4606 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)),
              dynamic_cast<TypeList *>((yysemantic_stack_[(6) - (3)].node)),
              dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (6)].node)));
        }
    break;

  case 650:

/* Line 690 of lalr1.cc  */
#line 4614 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
           (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 651:

/* Line 690 of lalr1.cc  */
#line 4620 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::strict_validation
            );
        }
    break;

  case 652:

/* Line 690 of lalr1.cc  */
#line 4626 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::lax_validation
            );
        }
    break;

  case 653:

/* Line 690 of lalr1.cc  */
#line 4632 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::skip_validation
            );
        }
    break;

  case 654:

/* Line 690 of lalr1.cc  */
#line 4640 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 655:

/* Line 690 of lalr1.cc  */
#line 4644 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 656:

/* Line 690 of lalr1.cc  */
#line 4650 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 657:

/* Line 690 of lalr1.cc  */
#line 4656 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 658:

/* Line 690 of lalr1.cc  */
#line 4660 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 659:

/* Line 690 of lalr1.cc  */
#line 4666 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 660:

/* Line 690 of lalr1.cc  */
#line 4670 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 661:

/* Line 690 of lalr1.cc  */
#line 4676 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                  LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 662:

/* Line 690 of lalr1.cc  */
#line 4682 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)),
                store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 663:

/* Line 690 of lalr1.cc  */
#line 4689 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 664:

/* Line 690 of lalr1.cc  */
#line 4697 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 665:

/* Line 690 of lalr1.cc  */
#line 4702 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 666:

/* Line 690 of lalr1.cc  */
#line 4708 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::NODE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 667:

/* Line 690 of lalr1.cc  */
#line 4714 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::VALUE_OF_NODE, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 668:

/* Line 690 of lalr1.cc  */
#line 4722 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new RenameExpr( LOC ((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 669:

/* Line 690 of lalr1.cc  */
#line 4728 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      CopyVarList *cvl = dynamic_cast<CopyVarList*>((yysemantic_stack_[(7) - (3)].expr));
      (yyval.expr) = new TransformExpr( LOC((yyloc)), cvl, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr) );
    }
    break;

  case 670:

/* Line 690 of lalr1.cc  */
#line 4735 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      CopyVarList* lList = new CopyVarList(LOC((yyloc)));
      lList->push_back (dynamic_cast<VarBinding*> ((yysemantic_stack_[(1) - (1)].expr)));
      (yyval.expr) = lList;
    }
    break;

  case 671:

/* Line 690 of lalr1.cc  */
#line 4741 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      CopyVarList* lList = dynamic_cast<CopyVarList*>((yysemantic_stack_[(4) - (1)].expr));
      VarBinding* lBinding = dynamic_cast<VarBinding*>((yysemantic_stack_[(4) - (4)].expr));
      lList->push_back(lBinding);
      (yyval.expr) = lList;
    }
    break;

  case 672:

/* Line 690 of lalr1.cc  */
#line 4750 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new VarBinding(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 673:

/* Line 690 of lalr1.cc  */
#line 4756 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new TryExpr( LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 674:

/* Line 690 of lalr1.cc  */
#line 4762 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            CatchListExpr *cle = new CatchListExpr( LOC((yyloc)) );
            cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.expr) = cle;
        }
    break;

  case 675:

/* Line 690 of lalr1.cc  */
#line 4768 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
            if ( cle )
                cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
        }
    break;

  case 676:

/* Line 690 of lalr1.cc  */
#line 4777 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)), *(yysemantic_stack_[(3) - (2)].name_test_list), (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 677:

/* Line 690 of lalr1.cc  */
#line 4784 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 678:

/* Line 690 of lalr1.cc  */
#line 4790 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            CatchExpr::NameTestList *ntl = new CatchExpr::NameTestList;
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 679:

/* Line 690 of lalr1.cc  */
#line 4796 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            CatchExpr::NameTestList *ntl =
                static_cast<CatchExpr::NameTestList*>((yysemantic_stack_[(3) - (1)].name_test_list));
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 680:

/* Line 690 of lalr1.cc  */
#line 4805 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTSelection( LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), (yysemantic_stack_[(2) - (2)].pos_filter_list) );
            delete (yysemantic_stack_[(2) - (2)].pos_filter_list);
        }
    break;

  case 681:

/* Line 690 of lalr1.cc  */
#line 4812 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.pos_filter_list) = NULL;
        }
    break;

  case 682:

/* Line 690 of lalr1.cc  */
#line 4816 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.pos_filter_list) = (yysemantic_stack_[(1) - (1)].pos_filter_list);
        }
    break;

  case 683:

/* Line 690 of lalr1.cc  */
#line 4822 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.pos_filter_list) = new FTSelection::pos_filter_list_t;
            (yyval.pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 684:

/* Line 690 of lalr1.cc  */
#line 4827 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yysemantic_stack_[(2) - (1)].pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.pos_filter_list) = (yysemantic_stack_[(2) - (1)].pos_filter_list);
        }
    break;

  case 685:

/* Line 690 of lalr1.cc  */
#line 4834 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 686:

/* Line 690 of lalr1.cc  */
#line 4838 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTOr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 687:

/* Line 690 of lalr1.cc  */
#line 4844 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 688:

/* Line 690 of lalr1.cc  */
#line 4848 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTAnd( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 689:

/* Line 690 of lalr1.cc  */
#line 4854 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 690:

/* Line 690 of lalr1.cc  */
#line 4858 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTMildNot( LOC((yyloc)), (yysemantic_stack_[(4) - (1)].node), (yysemantic_stack_[(4) - (4)].node) );
        }
    break;

  case 691:

/* Line 690 of lalr1.cc  */
#line 4864 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 692:

/* Line 690 of lalr1.cc  */
#line 4868 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTUnaryNot(
                LOC((yyloc)), dynamic_cast<FTPrimaryWithOptions*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 693:

/* Line 690 of lalr1.cc  */
#line 4876 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTPrimaryWithOptions(
                LOC((yyloc)),
                dynamic_cast<FTPrimary*>((yysemantic_stack_[(3) - (1)].node)),
                dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<FTWeight*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 694:

/* Line 690 of lalr1.cc  */
#line 4886 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 695:

/* Line 690 of lalr1.cc  */
#line 4890 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 696:

/* Line 690 of lalr1.cc  */
#line 4895 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 697:

/* Line 690 of lalr1.cc  */
#line 4899 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 698:

/* Line 690 of lalr1.cc  */
#line 4905 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTWeight( LOC((yyloc)), dynamic_cast<exprnode*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 699:

/* Line 690 of lalr1.cc  */
#line 4911 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTWordsTimes(
                LOC((yyloc)),
                dynamic_cast<FTWords*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<FTTimes*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 700:

/* Line 690 of lalr1.cc  */
#line 4919 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 701:

/* Line 690 of lalr1.cc  */
#line 4923 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 702:

/* Line 690 of lalr1.cc  */
#line 4928 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 703:

/* Line 690 of lalr1.cc  */
#line 4932 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 704:

/* Line 690 of lalr1.cc  */
#line 4938 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTExtensionSelection(
                LOC((yyloc)),
                dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)),
                dynamic_cast<FTSelection*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 705:

/* Line 690 of lalr1.cc  */
#line 4947 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 706:

/* Line 690 of lalr1.cc  */
#line 4951 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 707:

/* Line 690 of lalr1.cc  */
#line 4957 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTWords(
                LOC((yyloc)),
                dynamic_cast<FTWordsValue*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<FTAnyallOption*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 708:

/* Line 690 of lalr1.cc  */
#line 4967 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), static_cast<StringLiteral*>((yysemantic_stack_[(1) - (1)].expr)), NULL
            );
        }
    break;

  case 709:

/* Line 690 of lalr1.cc  */
#line 4973 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), NULL, dynamic_cast<exprnode*>((yysemantic_stack_[(3) - (2)].expr))
            );
        }
    break;

  case 710:

/* Line 690 of lalr1.cc  */
#line 4980 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::any );
        }
    break;

  case 711:

/* Line 690 of lalr1.cc  */
#line 4984 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 712:

/* Line 690 of lalr1.cc  */
#line 4990 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 713:

/* Line 690 of lalr1.cc  */
#line 4994 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 714:

/* Line 690 of lalr1.cc  */
#line 4998 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::phrase );
        }
    break;

  case 715:

/* Line 690 of lalr1.cc  */
#line 5003 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any;
        }
    break;

  case 716:

/* Line 690 of lalr1.cc  */
#line 5007 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any_word;
        }
    break;

  case 717:

/* Line 690 of lalr1.cc  */
#line 5012 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all;
        }
    break;

  case 718:

/* Line 690 of lalr1.cc  */
#line 5016 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all_words;
        }
    break;

  case 719:

/* Line 690 of lalr1.cc  */
#line 5022 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 720:

/* Line 690 of lalr1.cc  */
#line 5026 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 721:

/* Line 690 of lalr1.cc  */
#line 5030 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 722:

/* Line 690 of lalr1.cc  */
#line 5034 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 723:

/* Line 690 of lalr1.cc  */
#line 5038 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 724:

/* Line 690 of lalr1.cc  */
#line 5044 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTOrder( LOC((yyloc)) );
        }
    break;

  case 725:

/* Line 690 of lalr1.cc  */
#line 5050 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTWindow(
                LOC((yyloc)),
                static_cast<AdditiveExpr*>((yysemantic_stack_[(3) - (2)].expr)),
                static_cast<FTUnit*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 726:

/* Line 690 of lalr1.cc  */
#line 5060 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTDistance(
                LOC((yyloc)),
                dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<FTUnit*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 727:

/* Line 690 of lalr1.cc  */
#line 5070 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::words );
        }
    break;

  case 728:

/* Line 690 of lalr1.cc  */
#line 5074 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::sentences );
        }
    break;

  case 729:

/* Line 690 of lalr1.cc  */
#line 5078 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::paragraphs );
        }
    break;

  case 730:

/* Line 690 of lalr1.cc  */
#line 5084 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            FTMatchOptions *mo = new FTMatchOptions( LOC((yyloc)) );
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = mo;
        }
    break;

  case 731:

/* Line 690 of lalr1.cc  */
#line 5090 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            FTMatchOptions *mo = dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (1)].node));
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 732:

/* Line 690 of lalr1.cc  */
#line 5098 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 733:

/* Line 690 of lalr1.cc  */
#line 5102 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 734:

/* Line 690 of lalr1.cc  */
#line 5106 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 735:

/* Line 690 of lalr1.cc  */
#line 5110 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 736:

/* Line 690 of lalr1.cc  */
#line 5114 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 737:

/* Line 690 of lalr1.cc  */
#line 5118 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 738:

/* Line 690 of lalr1.cc  */
#line 5122 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 739:

/* Line 690 of lalr1.cc  */
#line 5126 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 740:

/* Line 690 of lalr1.cc  */
#line 5132 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::sensitive );
        }
    break;

  case 741:

/* Line 690 of lalr1.cc  */
#line 5136 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::insensitive );
        }
    break;

  case 742:

/* Line 690 of lalr1.cc  */
#line 5140 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::lower );
        }
    break;

  case 743:

/* Line 690 of lalr1.cc  */
#line 5144 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::upper );
        }
    break;

  case 744:

/* Line 690 of lalr1.cc  */
#line 5150 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::sensitive
            );
        }
    break;

  case 745:

/* Line 690 of lalr1.cc  */
#line 5156 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::insensitive
            );
        }
    break;

  case 746:

/* Line 690 of lalr1.cc  */
#line 5164 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTExtensionOption(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval))
            );
        }
    break;

  case 747:

/* Line 690 of lalr1.cc  */
#line 5172 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::stemming );
        }
    break;

  case 748:

/* Line 690 of lalr1.cc  */
#line 5176 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::no_stemming );
        }
    break;

  case 749:

/* Line 690 of lalr1.cc  */
#line 5182 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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

  case 750:

/* Line 690 of lalr1.cc  */
#line 5192 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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

  case 751:

/* Line 690 of lalr1.cc  */
#line 5203 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTThesaurusOption( LOC((yyloc)), NULL, false, true );
        }
    break;

  case 752:

/* Line 690 of lalr1.cc  */
#line 5209 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 753:

/* Line 690 of lalr1.cc  */
#line 5213 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 754:

/* Line 690 of lalr1.cc  */
#line 5218 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.thesaurus_id_list) = NULL;
        }
    break;

  case 755:

/* Line 690 of lalr1.cc  */
#line 5222 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(2) - (2)].thesaurus_id_list);
        }
    break;

  case 756:

/* Line 690 of lalr1.cc  */
#line 5228 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.thesaurus_id_list) = new FTThesaurusOption::thesaurus_id_list_t;
            (yyval.thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 757:

/* Line 690 of lalr1.cc  */
#line 5233 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yysemantic_stack_[(3) - (1)].thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(3) - (1)].thesaurus_id_list);
        }
    break;

  case 758:

/* Line 690 of lalr1.cc  */
#line 5240 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTThesaurusID(
                LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (2)].sval)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), dynamic_cast<FTRange*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 759:

/* Line 690 of lalr1.cc  */
#line 5247 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.sval) = 0;
        }
    break;

  case 760:

/* Line 690 of lalr1.cc  */
#line 5251 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.sval) = (yysemantic_stack_[(2) - (2)].sval);
        }
    break;

  case 761:

/* Line 690 of lalr1.cc  */
#line 5257 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 762:

/* Line 690 of lalr1.cc  */
#line 5261 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 763:

/* Line 690 of lalr1.cc  */
#line 5267 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(4) - (3)].node)), (yysemantic_stack_[(4) - (4)].incl_excl_list),
                ft_stop_words_mode::with
            );
            delete (yysemantic_stack_[(4) - (4)].incl_excl_list);
        }
    break;

  case 764:

/* Line 690 of lalr1.cc  */
#line 5276 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, (yysemantic_stack_[(4) - (4)].incl_excl_list), ft_stop_words_mode::with_default
            );
            delete (yysemantic_stack_[(4) - (4)].incl_excl_list);
        }
    break;

  case 765:

/* Line 690 of lalr1.cc  */
#line 5283 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, NULL, ft_stop_words_mode::without
            );
        }
    break;

  case 766:

/* Line 690 of lalr1.cc  */
#line 5291 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), NULL );
        }
    break;

  case 767:

/* Line 690 of lalr1.cc  */
#line 5295 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), "", (yysemantic_stack_[(3) - (2)].strlist) );
        }
    break;

  case 768:

/* Line 690 of lalr1.cc  */
#line 5301 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            string_list_t *sl = new string_list_t;
            sl->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
            (yyval.strlist) = sl;
        }
    break;

  case 769:

/* Line 690 of lalr1.cc  */
#line 5307 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            if ( (yysemantic_stack_[(3) - (1)].strlist) )
                (yysemantic_stack_[(3) - (1)].strlist)->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
            (yyval.strlist) = (yysemantic_stack_[(3) - (1)].strlist);
        }
    break;

  case 770:

/* Line 690 of lalr1.cc  */
#line 5314 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.incl_excl_list) = NULL;
        }
    break;

  case 771:

/* Line 690 of lalr1.cc  */
#line 5318 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.incl_excl_list) = (yysemantic_stack_[(1) - (1)].incl_excl_list);
        }
    break;

  case 772:

/* Line 690 of lalr1.cc  */
#line 5324 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.incl_excl_list) = new FTStopWordOption::incl_excl_list_t;
            (yyval.incl_excl_list)->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 773:

/* Line 690 of lalr1.cc  */
#line 5329 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            FTStopWordOption::incl_excl_list_t *iel = (yysemantic_stack_[(2) - (1)].incl_excl_list);
            if ( !iel )
                iel = new FTStopWordOption::incl_excl_list_t;
            iel->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.incl_excl_list) = iel;
        }
    break;

  case 774:

/* Line 690 of lalr1.cc  */
#line 5339 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStopWordsInclExcl(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(2) - (2)].node)),
                ft_stop_words_unex::union_
            );
        }
    break;

  case 775:

/* Line 690 of lalr1.cc  */
#line 5347 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStopWordsInclExcl(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(2) - (2)].node)),
                ft_stop_words_unex::except
            );
        }
    break;

  case 776:

/* Line 690 of lalr1.cc  */
#line 5357 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTLanguageOption( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 777:

/* Line 690 of lalr1.cc  */
#line 5363 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::with );
        }
    break;

  case 778:

/* Line 690 of lalr1.cc  */
#line 5367 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::without );
        }
    break;

  case 779:

/* Line 690 of lalr1.cc  */
#line 5373 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_start );
        }
    break;

  case 780:

/* Line 690 of lalr1.cc  */
#line 5377 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_end );
        }
    break;

  case 781:

/* Line 690 of lalr1.cc  */
#line 5381 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::entire );
        }
    break;

  case 782:

/* Line 690 of lalr1.cc  */
#line 5387 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTTimes( LOC((yyloc)), dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)) );
        }
    break;

  case 783:

/* Line 690 of lalr1.cc  */
#line 5393 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::exactly, (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 784:

/* Line 690 of lalr1.cc  */
#line 5397 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_least, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 785:

/* Line 690 of lalr1.cc  */
#line 5401 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_most, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 786:

/* Line 690 of lalr1.cc  */
#line 5405 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::from_to, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr) );
        }
    break;

  case 787:

/* Line 690 of lalr1.cc  */
#line 5411 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTScope(
                LOC((yyloc)),
                ft_scope::same,
                dynamic_cast<FTBigUnit*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 788:

/* Line 690 of lalr1.cc  */
#line 5419 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTScope(
                LOC((yyloc)),
                ft_scope::different,
                dynamic_cast<FTBigUnit*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 789:

/* Line 690 of lalr1.cc  */
#line 5429 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::sentence );
        }
    break;

  case 790:

/* Line 690 of lalr1.cc  */
#line 5433 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::paragraph );
        }
    break;

  case 791:

/* Line 690 of lalr1.cc  */
#line 5439 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTIgnoreOption( LOC((yyloc)), static_cast<UnionExpr*>((yysemantic_stack_[(3) - (3)].expr)) );
        }
    break;

  case 792:

/* Line 690 of lalr1.cc  */
#line 5445 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONArrayConstructor( LOC((yyloc)), NULL );
        }
    break;

  case 793:

/* Line 690 of lalr1.cc  */
#line 5449 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONArrayConstructor( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 794:

/* Line 690 of lalr1.cc  */
#line 5455 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), NULL, false);
        }
    break;

  case 795:

/* Line 690 of lalr1.cc  */
#line 5459 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), false);
        }
    break;

  case 796:

/* Line 690 of lalr1.cc  */
#line 5465 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), NULL, true);
        }
    break;

  case 797:

/* Line 690 of lalr1.cc  */
#line 5469 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), true);
        }
    break;

  case 798:

/* Line 690 of lalr1.cc  */
#line 5475 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONDirectObjectConstructor(LOC((yyloc)),
                                               dynamic_cast<JSONPairList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 799:

/* Line 690 of lalr1.cc  */
#line 5482 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
          ERROR_IF_QNAME_NOT_NCNAME((yysemantic_stack_[(3) - (1)].expr), (yylocation_stack_[(3) - (1)]));
          driver.addCommonLanguageWarning((yylocation_stack_[(3) - (1)]), ZED(ZWST0009_OBJECT_KEY_NOT_QUOTED));
          StringLiteral* sl = new StringLiteral( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)) );
          JSONPairList* jpl = new JSONPairList(LOC((yyloc)));
          jpl->push_back(new JSONPairConstructor(LOC((yyloc)), sl, (yysemantic_stack_[(3) - (3)].expr)));
          (yyval.node) = jpl;
        }
    break;

  case 800:

/* Line 690 of lalr1.cc  */
#line 5492 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
          JSONPairList* jpl = new JSONPairList(LOC((yyloc)));
          jpl->push_back(new JSONPairConstructor(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)));
          (yyval.node) = jpl;
        }
    break;

  case 801:

/* Line 690 of lalr1.cc  */
#line 5498 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
          JSONPairList* jpl = dynamic_cast<JSONPairList*>((yysemantic_stack_[(5) - (1)].node));
          assert(jpl);
          jpl->push_back(new JSONPairConstructor(LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)));
          (yyval.node) = jpl;
        }
    break;

  case 802:

/* Line 690 of lalr1.cc  */
#line 5505 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
          ERROR_IF_QNAME_NOT_NCNAME((yysemantic_stack_[(5) - (3)].expr), (yylocation_stack_[(5) - (3)]));
          JSONPairList* jpl = dynamic_cast<JSONPairList*>((yysemantic_stack_[(5) - (1)].node));
          assert(jpl);
          StringLiteral* sl = new StringLiteral( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (3)].expr)) );
          jpl->push_back(new JSONPairConstructor(LOC((yyloc)), sl, (yysemantic_stack_[(5) - (5)].expr)));
          (yyval.node) = jpl;
        }
    break;

  case 803:

/* Line 690 of lalr1.cc  */
#line 5516 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONObjectInsertExpr(LOC((yyloc)),
                                        (yysemantic_stack_[(5) - (3)].expr),
                                        (yysemantic_stack_[(5) - (5)].expr));
        }
    break;

  case 804:

/* Line 690 of lalr1.cc  */
#line 5522 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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

  case 805:

/* Line 690 of lalr1.cc  */
#line 5532 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONArrayInsertExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (5)].expr), (yysemantic_stack_[(8) - (8)].expr));
        }
    break;

  case 806:

/* Line 690 of lalr1.cc  */
#line 5536 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
          driver.addCommonLanguageWarning((yylocation_stack_[(4) - (2)]), ZED(ZWST0009_JSON_KEYWORD_OPTIONAL));
          (yyval.expr) = new JSONObjectInsertExpr(LOC((yyloc)),
                                        (yysemantic_stack_[(4) - (2)].expr),
                                        (yysemantic_stack_[(4) - (4)].expr));
        }
    break;

  case 807:

/* Line 690 of lalr1.cc  */
#line 5543 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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

  case 808:

/* Line 690 of lalr1.cc  */
#line 5554 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
          driver.addCommonLanguageWarning((yylocation_stack_[(7) - (2)]), ZED(ZWST0009_JSON_KEYWORD_OPTIONAL));
          (yyval.expr) = new JSONArrayInsertExpr(LOC((yyloc)), (yysemantic_stack_[(7) - (2)].expr), (yysemantic_stack_[(7) - (4)].expr), (yysemantic_stack_[(7) - (7)].expr));
        }
    break;

  case 809:

/* Line 690 of lalr1.cc  */
#line 5561 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONArrayAppendExpr(LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
        }
    break;

  case 810:

/* Line 690 of lalr1.cc  */
#line 5565 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
          driver.addCommonLanguageWarning((yylocation_stack_[(4) - (2)]), ZED(ZWST0009_JSON_KEYWORD_OPTIONAL));
          (yyval.expr) = new JSONArrayAppendExpr(LOC((yyloc)), (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr));
        }
    break;

  case 811:

/* Line 690 of lalr1.cc  */
#line 5572 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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

  case 812:

/* Line 690 of lalr1.cc  */
#line 5591 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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

  case 813:

/* Line 690 of lalr1.cc  */
#line 5613 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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

  case 814:

/* Line 690 of lalr1.cc  */
#line 5635 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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

  case 815:

/* Line 690 of lalr1.cc  */
#line 5660 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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

  case 816:

/* Line 690 of lalr1.cc  */
#line 5682 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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

  case 817:

/* Line 690 of lalr1.cc  */
#line 5707 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 818:

/* Line 690 of lalr1.cc  */
#line 5711 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 819:

/* Line 690 of lalr1.cc  */
#line 5715 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 820:

/* Line 690 of lalr1.cc  */
#line 5721 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonItem);
        }
    break;

  case 821:

/* Line 690 of lalr1.cc  */
#line 5725 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
          driver.addCommonLanguageWarning((yylocation_stack_[(1) - (1)]), ZED(ZWST0009_JSONIQ_TYPE_KEYWORDS));
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonItem);
        }
    break;

  case 822:

/* Line 690 of lalr1.cc  */
#line 5732 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonObject);
        }
    break;

  case 823:

/* Line 690 of lalr1.cc  */
#line 5736 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
          driver.addCommonLanguageWarning((yylocation_stack_[(1) - (1)]), ZED(ZWST0009_JSONIQ_TYPE_KEYWORDS));
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonObject);
        }
    break;

  case 824:

/* Line 690 of lalr1.cc  */
#line 5743 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonArray);
        }
    break;

  case 825:

/* Line 690 of lalr1.cc  */
#line 5747 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
          driver.addCommonLanguageWarning((yylocation_stack_[(1) - (1)]), ZED(ZWST0009_JSONIQ_TYPE_KEYWORDS));
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonArray);
        }
    break;

  case 828:

/* Line 690 of lalr1.cc  */
#line 5757 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))); }
    break;

  case 829:

/* Line 690 of lalr1.cc  */
#line 5758 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("attribute"))); }
    break;

  case 830:

/* Line 690 of lalr1.cc  */
#line 5759 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("comment"))); }
    break;

  case 831:

/* Line 690 of lalr1.cc  */
#line 5760 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("document-node"))); }
    break;

  case 832:

/* Line 690 of lalr1.cc  */
#line 5761 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("namespace-node"))); }
    break;

  case 833:

/* Line 690 of lalr1.cc  */
#line 5762 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("element"))); }
    break;

  case 834:

/* Line 690 of lalr1.cc  */
#line 5763 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("if"))); }
    break;

  case 835:

/* Line 690 of lalr1.cc  */
#line 5764 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("node"))); }
    break;

  case 836:

/* Line 690 of lalr1.cc  */
#line 5765 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("processing-instruction"))); }
    break;

  case 837:

/* Line 690 of lalr1.cc  */
#line 5766 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema-attribute"))); }
    break;

  case 838:

/* Line 690 of lalr1.cc  */
#line 5767 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema-element"))); }
    break;

  case 839:

/* Line 690 of lalr1.cc  */
#line 5768 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("text"))); }
    break;

  case 840:

/* Line 690 of lalr1.cc  */
#line 5769 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("typeswitch"))); }
    break;

  case 841:

/* Line 690 of lalr1.cc  */
#line 5770 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("switch"))); }
    break;

  case 842:

/* Line 690 of lalr1.cc  */
#line 5771 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("empty-sequence"))); }
    break;

  case 843:

/* Line 690 of lalr1.cc  */
#line 5772 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("while"))); }
    break;

  case 845:

/* Line 690 of lalr1.cc  */
#line 5776 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))); }
    break;

  case 846:

/* Line 690 of lalr1.cc  */
#line 5777 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("xquery"))); }
    break;

  case 847:

/* Line 690 of lalr1.cc  */
#line 5778 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("empty"))); }
    break;

  case 848:

/* Line 690 of lalr1.cc  */
#line 5779 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("boundary-space"))); }
    break;

  case 849:

/* Line 690 of lalr1.cc  */
#line 5780 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ft-option"))); }
    break;

  case 850:

/* Line 690 of lalr1.cc  */
#line 5781 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("base-uri"))); }
    break;

  case 851:

/* Line 690 of lalr1.cc  */
#line 5782 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lax"))); }
    break;

  case 852:

/* Line 690 of lalr1.cc  */
#line 5783 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("strict"))); }
    break;

  case 853:

/* Line 690 of lalr1.cc  */
#line 5784 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("idiv"))); }
    break;

  case 854:

/* Line 690 of lalr1.cc  */
#line 5785 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("document"))); }
    break;

  case 855:

/* Line 690 of lalr1.cc  */
#line 5786 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ftnot"))); }
    break;

  case 856:

/* Line 690 of lalr1.cc  */
#line 5787 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("not"))); }
    break;

  case 857:

/* Line 690 of lalr1.cc  */
#line 5788 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sensitive"))); }
    break;

  case 858:

/* Line 690 of lalr1.cc  */
#line 5789 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("insensitive"))); }
    break;

  case 859:

/* Line 690 of lalr1.cc  */
#line 5790 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("diacritics"))); }
    break;

  case 860:

/* Line 690 of lalr1.cc  */
#line 5791 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("without"))); }
    break;

  case 861:

/* Line 690 of lalr1.cc  */
#line 5792 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stemming"))); }
    break;

  case 862:

/* Line 690 of lalr1.cc  */
#line 5793 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("thesaurus"))); }
    break;

  case 863:

/* Line 690 of lalr1.cc  */
#line 5794 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stop"))); }
    break;

  case 864:

/* Line 690 of lalr1.cc  */
#line 5795 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("wildcards"))); }
    break;

  case 865:

/* Line 690 of lalr1.cc  */
#line 5796 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("entire"))); }
    break;

  case 866:

/* Line 690 of lalr1.cc  */
#line 5797 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("content"))); }
    break;

  case 867:

/* Line 690 of lalr1.cc  */
#line 5798 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("word"))); }
    break;

  case 868:

/* Line 690 of lalr1.cc  */
#line 5799 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("start"))); }
    break;

  case 869:

/* Line 690 of lalr1.cc  */
#line 5800 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("end"))); }
    break;

  case 870:

/* Line 690 of lalr1.cc  */
#line 5801 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("most"))); }
    break;

  case 871:

/* Line 690 of lalr1.cc  */
#line 5802 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("skip"))); }
    break;

  case 872:

/* Line 690 of lalr1.cc  */
#line 5803 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("copy"))); }
    break;

  case 873:

/* Line 690 of lalr1.cc  */
#line 5804 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("general"))); }
    break;

  case 874:

/* Line 690 of lalr1.cc  */
#line 5805 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("value"))); }
    break;

  case 875:

/* Line 690 of lalr1.cc  */
#line 5806 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("eq"))); }
    break;

  case 876:

/* Line 690 of lalr1.cc  */
#line 5807 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ne"))); }
    break;

  case 877:

/* Line 690 of lalr1.cc  */
#line 5808 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lt"))); }
    break;

  case 878:

/* Line 690 of lalr1.cc  */
#line 5809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("le"))); }
    break;

  case 879:

/* Line 690 of lalr1.cc  */
#line 5810 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("gt"))); }
    break;

  case 880:

/* Line 690 of lalr1.cc  */
#line 5811 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ge"))); }
    break;

  case 881:

/* Line 690 of lalr1.cc  */
#line 5812 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("at"))); }
    break;

  case 882:

/* Line 690 of lalr1.cc  */
#line 5813 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("context"))); }
    break;

  case 883:

/* Line 690 of lalr1.cc  */
#line 5814 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("variable"))); }
    break;

  case 884:

/* Line 690 of lalr1.cc  */
#line 5815 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("return"))); }
    break;

  case 885:

/* Line 690 of lalr1.cc  */
#line 5816 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("for"))); }
    break;

  case 886:

/* Line 690 of lalr1.cc  */
#line 5817 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("from"))); }
    break;

  case 887:

/* Line 690 of lalr1.cc  */
#line 5818 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("allowing"))); }
    break;

  case 888:

/* Line 690 of lalr1.cc  */
#line 5819 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sliding"))); }
    break;

  case 889:

/* Line 690 of lalr1.cc  */
#line 5820 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("tumbling"))); }
    break;

  case 890:

/* Line 690 of lalr1.cc  */
#line 5821 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("previous"))); }
    break;

  case 891:

/* Line 690 of lalr1.cc  */
#line 5822 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("next"))); }
    break;

  case 892:

/* Line 690 of lalr1.cc  */
#line 5823 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("only"))); }
    break;

  case 893:

/* Line 690 of lalr1.cc  */
#line 5824 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("when"))); }
    break;

  case 894:

/* Line 690 of lalr1.cc  */
#line 5825 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("count"))); }
    break;

  case 895:

/* Line 690 of lalr1.cc  */
#line 5826 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("in"))); }
    break;

  case 896:

/* Line 690 of lalr1.cc  */
#line 5827 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("let"))); }
    break;

  case 897:

/* Line 690 of lalr1.cc  */
#line 5828 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("where"))); }
    break;

  case 898:

/* Line 690 of lalr1.cc  */
#line 5829 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("by"))); }
    break;

  case 899:

/* Line 690 of lalr1.cc  */
#line 5830 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("group"))); }
    break;

  case 900:

/* Line 690 of lalr1.cc  */
#line 5831 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("order"))); }
    break;

  case 901:

/* Line 690 of lalr1.cc  */
#line 5832 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stable"))); }
    break;

  case 902:

/* Line 690 of lalr1.cc  */
#line 5833 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ascending"))); }
    break;

  case 903:

/* Line 690 of lalr1.cc  */
#line 5834 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descending"))); }
    break;

  case 904:

/* Line 690 of lalr1.cc  */
#line 5835 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("greatest"))); }
    break;

  case 905:

/* Line 690 of lalr1.cc  */
#line 5836 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("least"))); }
    break;

  case 906:

/* Line 690 of lalr1.cc  */
#line 5837 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("collation"))); }
    break;

  case 907:

/* Line 690 of lalr1.cc  */
#line 5838 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("some"))); }
    break;

  case 908:

/* Line 690 of lalr1.cc  */
#line 5839 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("every"))); }
    break;

  case 909:

/* Line 690 of lalr1.cc  */
#line 5840 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("satisfies"))); }
    break;

  case 910:

/* Line 690 of lalr1.cc  */
#line 5841 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("case"))); }
    break;

  case 911:

/* Line 690 of lalr1.cc  */
#line 5842 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("as"))); }
    break;

  case 912:

/* Line 690 of lalr1.cc  */
#line 5843 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("then"))); }
    break;

  case 913:

/* Line 690 of lalr1.cc  */
#line 5844 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("else"))); }
    break;

  case 914:

/* Line 690 of lalr1.cc  */
#line 5845 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("or"))); }
    break;

  case 915:

/* Line 690 of lalr1.cc  */
#line 5846 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("and"))); }
    break;

  case 916:

/* Line 690 of lalr1.cc  */
#line 5847 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("instance"))); }
    break;

  case 917:

/* Line 690 of lalr1.cc  */
#line 5848 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("of"))); }
    break;

  case 918:

/* Line 690 of lalr1.cc  */
#line 5849 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("castable"))); }
    break;

  case 919:

/* Line 690 of lalr1.cc  */
#line 5850 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("to"))); }
    break;

  case 920:

/* Line 690 of lalr1.cc  */
#line 5851 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("div"))); }
    break;

  case 921:

/* Line 690 of lalr1.cc  */
#line 5852 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("mod"))); }
    break;

  case 922:

/* Line 690 of lalr1.cc  */
#line 5853 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("union"))); }
    break;

  case 923:

/* Line 690 of lalr1.cc  */
#line 5854 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("intersect"))); }
    break;

  case 924:

/* Line 690 of lalr1.cc  */
#line 5855 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("except"))); }
    break;

  case 925:

/* Line 690 of lalr1.cc  */
#line 5856 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("validate"))); }
    break;

  case 926:

/* Line 690 of lalr1.cc  */
#line 5857 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("type"))); }
    break;

  case 927:

/* Line 690 of lalr1.cc  */
#line 5858 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("cast"))); }
    break;

  case 928:

/* Line 690 of lalr1.cc  */
#line 5859 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("treat"))); }
    break;

  case 929:

/* Line 690 of lalr1.cc  */
#line 5860 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("is"))); }
    break;

  case 930:

/* Line 690 of lalr1.cc  */
#line 5861 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preserve"))); }
    break;

  case 931:

/* Line 690 of lalr1.cc  */
#line 5862 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("strip"))); }
    break;

  case 932:

/* Line 690 of lalr1.cc  */
#line 5863 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("namespace"))); }
    break;

  case 933:

/* Line 690 of lalr1.cc  */
#line 5864 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("external"))); }
    break;

  case 934:

/* Line 690 of lalr1.cc  */
#line 5865 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("encoding"))); }
    break;

  case 935:

/* Line 690 of lalr1.cc  */
#line 5866 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("no-preserve"))); }
    break;

  case 936:

/* Line 690 of lalr1.cc  */
#line 5867 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("inherit"))); }
    break;

  case 937:

/* Line 690 of lalr1.cc  */
#line 5868 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("no-inherit"))); }
    break;

  case 938:

/* Line 690 of lalr1.cc  */
#line 5869 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("declare"))); }
    break;

  case 939:

/* Line 690 of lalr1.cc  */
#line 5870 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("construction"))); }
    break;

  case 940:

/* Line 690 of lalr1.cc  */
#line 5871 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ordering"))); }
    break;

  case 941:

/* Line 690 of lalr1.cc  */
#line 5872 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("default"))); }
    break;

  case 942:

/* Line 690 of lalr1.cc  */
#line 5873 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("copy-namespaces"))); }
    break;

  case 943:

/* Line 690 of lalr1.cc  */
#line 5874 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("option"))); }
    break;

  case 944:

/* Line 690 of lalr1.cc  */
#line 5875 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("version"))); }
    break;

  case 945:

/* Line 690 of lalr1.cc  */
#line 5876 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("import"))); }
    break;

  case 946:

/* Line 690 of lalr1.cc  */
#line 5877 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema"))); }
    break;

  case 947:

/* Line 690 of lalr1.cc  */
#line 5878 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("module"))); }
    break;

  case 948:

/* Line 690 of lalr1.cc  */
#line 5879 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("function"))); }
    break;

  case 949:

/* Line 690 of lalr1.cc  */
#line 5880 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("score"))); }
    break;

  case 950:

/* Line 690 of lalr1.cc  */
#line 5881 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("contains"))); }
    break;

  case 951:

/* Line 690 of lalr1.cc  */
#line 5882 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("weight"))); }
    break;

  case 952:

/* Line 690 of lalr1.cc  */
#line 5883 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("window"))); }
    break;

  case 953:

/* Line 690 of lalr1.cc  */
#line 5884 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("distance"))); }
    break;

  case 954:

/* Line 690 of lalr1.cc  */
#line 5885 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("occurs"))); }
    break;

  case 955:

/* Line 690 of lalr1.cc  */
#line 5886 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("times"))); }
    break;

  case 956:

/* Line 690 of lalr1.cc  */
#line 5887 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("same"))); }
    break;

  case 957:

/* Line 690 of lalr1.cc  */
#line 5888 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("different"))); }
    break;

  case 958:

/* Line 690 of lalr1.cc  */
#line 5889 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lowercase"))); }
    break;

  case 959:

/* Line 690 of lalr1.cc  */
#line 5890 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("uppercase"))); }
    break;

  case 960:

/* Line 690 of lalr1.cc  */
#line 5891 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("relationship"))); }
    break;

  case 961:

/* Line 690 of lalr1.cc  */
#line 5892 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("levels"))); }
    break;

  case 962:

/* Line 690 of lalr1.cc  */
#line 5893 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("language"))); }
    break;

  case 963:

/* Line 690 of lalr1.cc  */
#line 5894 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("any"))); }
    break;

  case 964:

/* Line 690 of lalr1.cc  */
#line 5895 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("all"))); }
    break;

  case 965:

/* Line 690 of lalr1.cc  */
#line 5896 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("exactly"))); }
    break;

  case 966:

/* Line 690 of lalr1.cc  */
#line 5897 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("words"))); }
    break;

  case 967:

/* Line 690 of lalr1.cc  */
#line 5898 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sentences"))); }
    break;

  case 968:

/* Line 690 of lalr1.cc  */
#line 5899 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sentence"))); }
    break;

  case 969:

/* Line 690 of lalr1.cc  */
#line 5900 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("phrase"))); }
    break;

  case 970:

/* Line 690 of lalr1.cc  */
#line 5901 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("paragraph"))); }
    break;

  case 971:

/* Line 690 of lalr1.cc  */
#line 5902 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("paragraphs"))); }
    break;

  case 972:

/* Line 690 of lalr1.cc  */
#line 5903 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("modify"))); }
    break;

  case 973:

/* Line 690 of lalr1.cc  */
#line 5904 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("first"))); }
    break;

  case 974:

/* Line 690 of lalr1.cc  */
#line 5905 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("before"))); }
    break;

  case 975:

/* Line 690 of lalr1.cc  */
#line 5906 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("after"))); }
    break;

  case 976:

/* Line 690 of lalr1.cc  */
#line 5907 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("revalidation"))); }
    break;

  case 977:

/* Line 690 of lalr1.cc  */
#line 5908 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("with"))); }
    break;

  case 978:

/* Line 690 of lalr1.cc  */
#line 5909 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("nodes"))); }
    break;

  case 979:

/* Line 690 of lalr1.cc  */
#line 5910 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("last"))); }
    break;

  case 980:

/* Line 690 of lalr1.cc  */
#line 5911 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("into"))); }
    break;

  case 981:

/* Line 690 of lalr1.cc  */
#line 5912 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("simple"))); }
    break;

  case 982:

/* Line 690 of lalr1.cc  */
#line 5913 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sequential"))); }
    break;

  case 983:

/* Line 690 of lalr1.cc  */
#line 5914 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("updating"))); }
    break;

  case 984:

/* Line 690 of lalr1.cc  */
#line 5915 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ordered"))); }
    break;

  case 985:

/* Line 690 of lalr1.cc  */
#line 5916 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("unordered"))); }
    break;

  case 986:

/* Line 690 of lalr1.cc  */
#line 5917 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("returning"))); }
    break;

  case 987:

/* Line 690 of lalr1.cc  */
#line 5918 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("exit"))); }
    break;

  case 988:

/* Line 690 of lalr1.cc  */
#line 5919 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("loop"))); }
    break;

  case 989:

/* Line 690 of lalr1.cc  */
#line 5920 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("break"))); }
    break;

  case 990:

/* Line 690 of lalr1.cc  */
#line 5921 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("continue"))); }
    break;

  case 991:

/* Line 690 of lalr1.cc  */
#line 5922 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("try"))); }
    break;

  case 992:

/* Line 690 of lalr1.cc  */
#line 5923 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("catch"))); }
    break;

  case 993:

/* Line 690 of lalr1.cc  */
#line 5924 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("using"))); }
    break;

  case 994:

/* Line 690 of lalr1.cc  */
#line 5925 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("set"))); }
    break;

  case 995:

/* Line 690 of lalr1.cc  */
#line 5926 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("index"))); }
    break;

  case 996:

/* Line 690 of lalr1.cc  */
#line 5927 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("unique"))); }
    break;

  case 997:

/* Line 690 of lalr1.cc  */
#line 5928 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("non"))); }
    break;

  case 998:

/* Line 690 of lalr1.cc  */
#line 5929 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("on"))); }
    break;

  case 999:

/* Line 690 of lalr1.cc  */
#line 5930 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("range"))); }
    break;

  case 1000:

/* Line 690 of lalr1.cc  */
#line 5931 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("equality"))); }
    break;

  case 1001:

/* Line 690 of lalr1.cc  */
#line 5932 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("manually"))); }
    break;

  case 1002:

/* Line 690 of lalr1.cc  */
#line 5933 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("automatically"))); }
    break;

  case 1003:

/* Line 690 of lalr1.cc  */
#line 5934 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("maintained"))); }
    break;

  case 1004:

/* Line 690 of lalr1.cc  */
#line 5935 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("decimal-format"))); }
    break;

  case 1005:

/* Line 690 of lalr1.cc  */
#line 5936 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("decimal-separator"))); }
    break;

  case 1006:

/* Line 690 of lalr1.cc  */
#line 5937 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("grouping-separator"))); }
    break;

  case 1007:

/* Line 690 of lalr1.cc  */
#line 5938 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("infinity"))); }
    break;

  case 1008:

/* Line 690 of lalr1.cc  */
#line 5939 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("minus-sign"))); }
    break;

  case 1009:

/* Line 690 of lalr1.cc  */
#line 5940 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("NaN"))); }
    break;

  case 1010:

/* Line 690 of lalr1.cc  */
#line 5941 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("percent"))); }
    break;

  case 1011:

/* Line 690 of lalr1.cc  */
#line 5942 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("per-mille"))); }
    break;

  case 1012:

/* Line 690 of lalr1.cc  */
#line 5943 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("zero-digit"))); }
    break;

  case 1013:

/* Line 690 of lalr1.cc  */
#line 5944 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("digit"))); }
    break;

  case 1014:

/* Line 690 of lalr1.cc  */
#line 5945 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("pattern-separator"))); }
    break;

  case 1015:

/* Line 690 of lalr1.cc  */
#line 5946 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("collection"))); }
    break;

  case 1016:

/* Line 690 of lalr1.cc  */
#line 5947 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("const"))); }
    break;

  case 1017:

/* Line 690 of lalr1.cc  */
#line 5948 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("append-only"))); }
    break;

  case 1018:

/* Line 690 of lalr1.cc  */
#line 5949 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("queue"))); }
    break;

  case 1019:

/* Line 690 of lalr1.cc  */
#line 5950 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("mutable"))); }
    break;

  case 1020:

/* Line 690 of lalr1.cc  */
#line 5951 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("read-only"))); }
    break;

  case 1021:

/* Line 690 of lalr1.cc  */
#line 5952 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("integrity"))); }
    break;

  case 1022:

/* Line 690 of lalr1.cc  */
#line 5953 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("constraint"))); }
    break;

  case 1023:

/* Line 690 of lalr1.cc  */
#line 5954 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("check"))); }
    break;

  case 1024:

/* Line 690 of lalr1.cc  */
#line 5955 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("key"))); }
    break;

  case 1025:

/* Line 690 of lalr1.cc  */
#line 5956 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("foreach"))); }
    break;

  case 1026:

/* Line 690 of lalr1.cc  */
#line 5957 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("foreign"))); }
    break;

  case 1027:

/* Line 690 of lalr1.cc  */
#line 5958 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("keys"))); }
    break;

  case 1028:

/* Line 690 of lalr1.cc  */
#line 5959 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ancestor"))); }
    break;

  case 1029:

/* Line 690 of lalr1.cc  */
#line 5960 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("child"))); }
    break;

  case 1030:

/* Line 690 of lalr1.cc  */
#line 5961 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descendant"))); }
    break;

  case 1031:

/* Line 690 of lalr1.cc  */
#line 5962 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("parent"))); }
    break;

  case 1032:

/* Line 690 of lalr1.cc  */
#line 5963 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preceding"))); }
    break;

  case 1033:

/* Line 690 of lalr1.cc  */
#line 5964 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("self"))); }
    break;

  case 1034:

/* Line 690 of lalr1.cc  */
#line 5965 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("following"))); }
    break;

  case 1035:

/* Line 690 of lalr1.cc  */
#line 5966 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ancestor-or-self"))); }
    break;

  case 1036:

/* Line 690 of lalr1.cc  */
#line 5967 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descendant-or-self"))); }
    break;

  case 1037:

/* Line 690 of lalr1.cc  */
#line 5968 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("following-sibling"))); }
    break;

  case 1038:

/* Line 690 of lalr1.cc  */
#line 5969 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preceding-sibling"))); }
    break;

  case 1039:

/* Line 690 of lalr1.cc  */
#line 5970 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("position"))); }
    break;

  case 1040:

/* Line 690 of lalr1.cc  */
#line 5973 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), true); }
    break;



/* Line 690 of lalr1.cc  */
#line 12277 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
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
  const short int jsoniq_parser::yypact_ninf_ = -1516;
  const short int
  jsoniq_parser::yypact_[] =
  {
      4948, -1516, -1516, -1516, -1516,  6186,  6186,  6186,  6186, -1516,
   -1516,   255,   275, -1516,  1113,   342, -1516, -1516, -1516,   236,
   -1516, -1516, -1516,   359,   486,   868,  4482,   504,   549,   867,
   -1516,    57, -1516,   582, -1516, -1516, -1516, -1516, -1516,   879,
   -1516,   603,   607, -1516, -1516, -1516, -1516,   677, -1516,   905,
   -1516,   611,   664, -1516,   234, -1516, -1516, -1516, -1516, -1516,
   -1516, -1516, -1516, -1516, -1516, -1516, -1516, -1516, -1516,   756,
     790, -1516, -1516, -1516, -1516,   593, 14794, -1516, -1516, -1516,
     825, -1516, -1516, -1516,   851, -1516,   915,   925, -1516, -1516,
   19298, -1516, -1516, -1516, -1516, -1516, -1516, -1516, -1516,   881,
   -1516, -1516,   934,   940, -1516, -1516, -1516, -1516, -1516, -1516,
    6186,  8335,  8642, 19298, -1516, -1516,   733, -1516, -1516, -1516,
   -1516,   849, -1516, -1516,   948, 19298, -1516, 17803,   960,   968,
   -1516, -1516, -1516,   973, -1516, -1516, 13259, -1516, -1516, -1516,
   -1516, -1516, -1516,   935, -1516, -1516, -1516, -1516, -1516, -1516,
   -1516, -1516,   108,   877,   893, -1516, -1516, -1516, -1516, -1516,
   -1516, -1516, -1516, -1516, -1516, -1516, 19592,   955,  8949, -1516,
   19893,   257, -1516, -1516, -1516, -1516, -1516, -1516,   996, -1516,
     871,   875,   878, -1516, -1516,   975,   979, -1516, -1516, -1516,
   -1516, -1516, -1516, -1516, -1516, -1516, -1516, -1516, -1516,  4661,
   -1516, 14487, -1516, -1516, -1516, -1516, -1516, -1516, -1516, -1516,
   -1516, -1516, -1516, -1516, -1516, -1516, -1516, -1516, -1516, -1516,
   -1516, -1516, -1516, -1516, -1516, -1516, -1516, -1516, -1516, -1516,
   -1516, -1516, -1516, -1516, -1516, -1516, -1516, -1516, -1516, -1516,
   -1516, -1516, -1516, -1516, -1516, -1516, -1516, -1516, -1516, -1516,
    9260,  9567,  9878, -1516,  5260,  5572,  1135, -1516,  6493, -1516,
   -1516,   703,    95, -1516, -1516, -1516, -1516, -1516, -1516, -1516,
   -1516, -1516, -1516, -1516, -1516, -1516, -1516,   110, -1516, -1516,
   -1516, -1516, -1516, -1516,   506, -1516, -1516, -1516, -1516, -1516,
   -1516, -1516, -1516,  6186, -1516, -1516, -1516, -1516,   277, -1516,
   -1516, -1516, -1516, -1516, -1516, -1516, -1516, -1516,   149, -1516,
     947, -1516, -1516, -1516,   329, -1516,   599, -1516, -1516, -1516,
   -1516, -1516, -1516, -1516,   969,  1049, -1516, -1516,   990,   889,
    1044,   717,   652,   817,    45, -1516,  1095,   951,  1053,  1054,
   12031, -1516,   962, -1516, -1516,    16, -1516, -1516, 13566, -1516,
     887, -1516,  1002, 14794, -1516,  1002, 14794, -1516, -1516, -1516,
     698, -1516, -1516, -1516, -1516, -1516, -1516, -1516, -1516, -1516,
   -1516, -1516, -1516, -1516, -1516, -1516, -1516, -1516, -1516, -1516,
   -1516, -1516, -1516, -1516, -1516, -1516, -1516, -1516, -1516,  1001,
   -1516, -1516, -1516, -1516, -1516, -1516, -1516, -1516, -1516, -1516,
   -1516, -1516, -1516, -1516, -1516, -1516, -1516, -1516, -1516, -1516,
   -1516, -1516, -1516, -1516, -1516, -1516, -1516,   349, -1516, -1516,
   -1516, -1516, -1516,   976, -1516,  6186,   977,   981,   983,  6186,
     569,   569,  1134,   358,   648,   784, 20788, 19298,    14,  1122,
   19298,  1019,  1055,   793, 19298,   842,   921, 19298, 19298,   870,
      52,    67, -1516, -1516, -1516, 19298,  6186,   988,  6186,   161,
   11110, 18102, 19298,    28,  1022, 11110,  1179,   101,   333, 19298,
    1063,  1039,  1076, -1516,   998, 11110, 18401, 19298, 19298, 19298,
    6186,   999, 11110, 11110, 19298,  6186,  1034,  1035, -1516, -1516,
   -1516, 11110, 18700,  1033, -1516,  1042, -1516, -1516, -1516, -1516,
    1043, -1516,  1045, -1516, -1516, -1516, -1516, -1516,  1046, -1516,
   -1516, -1516, -1516, -1516, -1516, -1516, -1516, -1516, -1516, -1516,
   -1516, -1516, -1516, -1516, -1516, -1516, -1516, -1516, -1516, -1516,
   -1516, -1516, -1516, -1516, 19298, -1516, -1516, -1516, -1516, -1516,
   -1516, -1516, -1516, -1516, -1516, -1516, -1516, -1516,  1048, 19298,
   -1516, -1516,  1017,  5879,  1082,   521,  1083,  1050,  1051,  1052,
   19298,  6186, -1516,  1056,    85, -1516,   477, -1516,    96,  1177,
   11110, 11110, -1516,   138, -1516, -1516,  1196, -1516, -1516, -1516,
   -1516, 11110,  1000, -1516,  1184,  1186,  1062,  1065,  1066,  1067,
    1068, 11110, 11724, 20495,   698,   349, 13873, 14180, 11110,    11,
     120, 11110, 20495,   716, 11110,   982,   989, 19298,  1037,  1038,
   11110, 11110,  6186,   980, 19298, -1516, -1516,    65, -1516,    59,
   11110,   993,  5572, -1516, -1516, -1516, -1516, -1516,  1113,   867,
     111,   118,  1229,  6800,  3212,  7107,  3530,   851, -1516, -1516,
     369,   851, -1516, 11110,  4160, -1516,  1115,   622,    57,  1069,
    1064,  1070,  6186, 11110,   720, -1516, -1516, -1516, -1516, -1516,
   -1516, -1516, -1516, -1516,   950,   953, 19298,  1117, 12338, 12338,
   -1516, -1516, -1516, -1516, -1516, -1516, 12645,  1169, 12645, 12645,
   12645, 12645, 12645, 12645, 12645, 12645, 12645, 12645, 12645, 12645,
    1007,  1149,  1150,  1151, -1516, -1516, -1516, 12952, 10189, -1516,
   -1516, 13259, 13259, 11110,  1002, -1516, -1516,  1002, -1516, 17504,
    7721,  1002,  1059,  1097,  8028, -1516, -1516, -1516, -1516,    15,
   -1516,   247, -1516, -1516, -1516, -1516, -1516, -1516,  1142,  1143,
     504,  1223, -1516, -1516, 20788,  1018,   688, 19298,  1092,  1093,
    1018,  1134,  1127,  1123, -1516, -1516, -1516,   417,  1008,  1165,
     957, 19298,  1120, 11110,  1146, 19298, 19298, -1516,  1133,  1084,
   -1516,  1085,  1042,   607, -1516,  1080,  1086,   100, -1516,   371,
     386,  1163, -1516,    43, 19298,  1182,   470, -1516,  6186, -1516,
     142, -1516, 19298,  1183,  1234, 19298,  1134,  1185,   572, 19298,
   11110,    57, -1516,   258,  1096, -1516,  1098,  1100,  1101,    24,
   -1516,    71,  1105, -1516,   152,   154,  1126, -1516,  1106,  6186,
    6186,   265, -1516,   489,   503,   650, 11110,   284, -1516, -1516,
   11110, 11110, -1516, 11110, 11110, 11110, 11110, -1516, 11110, -1516,
   11110, -1516, 19298,  1177, -1516,    40,   367,   373, -1516, -1516,
   -1516,   375, -1516,   424,   507, -1516, -1516,   698,   302,   436,
      29,   126, 11110, 11110,  1188,   739, 11110,  1057, 20194,  1058,
     113, -1516,  1141, -1516, -1516,  1104,   156,  5879,   394, 15098,
     980, -1516,  1163, -1516, -1516,  1060, 11110, -1516,   703,   880,
    1259,   186, -1516, -1516,   121, -1516, -1516, -1516,   124, -1516,
     132, -1516, -1516, -1516, -1516, -1516,  3845, -1516, -1516, -1516,
   19298,  1129, 11110, 11417, -1516, -1516, -1516, -1516, -1516,  1163,
   19298,    33,  1049, -1516, -1516,    75, -1516,   652,   652,    25,
     817,   817,   817,   817,    45,    45, -1516, -1516, 16902, 16902,
   19298, 19298, -1516, -1516,   395, -1516, -1516,   198, -1516, 10496,
   -1516, -1516, -1516, -1516, -1516, -1516,   505, -1516, -1516, -1516,
     509,   569, -1516, -1516,   819,   826,   855, -1516,   504, -1516,
   -1516, -1516, -1516, -1516, -1516, -1516, -1516, -1516, -1516,  1018,
   -1516,  1167, 17203,  1158, 11110, -1516, -1516, -1516,  1209,  1134,
    1134,  1018, -1516,   952,  1134,   769, 19298,   335,   639,  1275,
   -1516, -1516,  1020,   706, -1516, -1516, -1516, -1516, -1516, -1516,
   -1516, -1516, -1516, -1516, -1516,   417,    64,  1077,   546, 11110,
   -1516, 19298,  1213,  1006,  1134, -1516, -1516, -1516, -1516,  1159,
   19298, -1516, 19298, -1516, 18999,  1189, 16902,  1198, 11110,    73,
    1166,    51,  1209, 16902,  1200,  1225,  1136,  1124,  1190,  1134,
    1160,  1191,  1231,  1134, 11110,   -37, -1516, -1516, -1516,  1174,
   -1516, -1516, -1516, -1516,  1211, 11110, 11110,  1187, -1516,  1236,
    1238,  6186, -1516,  1157,  1161,  1180, 19298, -1516, 19298, -1516,
   11110,  1199,  1153, 11110, -1516,  1226,  1227, -1516,   157,   160,
     169,  1313, -1516,   233, -1516,   724,  1197, -1516, -1516,  1321,
   -1516,  1325, -1516,   785, 11110, 11110, 11110,   839, 11110, 11110,
   11110, 11110, 11110,  1260, -1516, 11110, 11110, -1516, 11110, 11110,
     307, 20495,  1239, 11110, 11110, -1516,  7414,   127,  1109, -1516,
     377, -1516, 11110, -1516,   128,   137,   132,  7107,  3530,  7107,
    1281, -1516, -1516, 11110,   876,  1254, -1516, 19298,  1256,  1257,
   -1516,    87,  1107, -1516, -1516,   812,    33, 11110,    75,   621,
     227, -1516,  1074,   773,  1108,  1111, -1516, -1516,   921, -1516,
    1102,   738,  1214,  1219, 15698,  1222, -1516,  1224,  1230,  1233,
    1237, -1516,   462, -1516, -1516, -1516, -1516, -1516, -1516, -1516,
   -1516, -1516, -1516, -1516, -1516, -1516,  1235, -1516, -1516, -1516,
   -1516, -1516,   214, 10803, -1516, -1516, -1516, -1516, -1516, -1516,
   -1516, -1516, -1516,   859, -1516,  1354, 17203,   714, -1516, -1516,
   -1516, -1516, -1516, -1516, -1516, -1516, -1516,  1094, -1516, -1516,
    1357, -1516, -1516, -1516, -1516, -1516,   801,  1362, -1516,   533,
   -1516, -1516, -1516,  1033,   486,   582,  1043,   603,  1045,  1046,
   -1516, -1516,   462,   462, 12952,  1110,  1087, -1516,  1209,    64,
    1164,  1206,  6186,  1212,  1215,  1253,  1216,  1218, 19298, -1516,
     320, -1516, 19298, -1516, 11110,  1261, 11110,  1280, 11110,    83,
    1262, -1516, -1516, -1516, 16902, -1516,  6186,  1134,  1304, -1516,
   -1516, -1516,  1134,  1304, -1516, 11110,  1272,  6186, 19298, -1516,
   -1516, 11110, 11110,   836, -1516,    50,   843, -1516, 15999,   857,
   -1516,   895, -1516,  1232, -1516, -1516,  6186,  1240,  1241, -1516,
   11110, -1516, -1516, 11110, 11110,  1220,  1236,  1317, -1516,  1286,
   -1516,   764, -1516, -1516,  1419, -1516, -1516,  6186, 19298, -1516,
     852, -1516, -1516, -1516,  6186,  1242,  1243,  1193,  1194, -1516,
   -1516, -1516,  1201,  1202, -1516, -1516, -1516,  1330, -1516,  1114,
   -1516, -1516, -1516,  1195, 11110,   406, 19298,  1249, -1516,  1283,
    1284,  1285,  1289, -1516,   947,   550, 15098,  1109, -1516,  7414,
   15098, -1516, -1516,  1259,   499, -1516, -1516, -1516,  1254, -1516,
    1134, -1516,   958, -1516,    81,  1338, -1516, 11110,   673,  1134,
   -1516, 11417, 11110,  1298, -1516,  1329,  1331, 11110, 19298,   966,
    1371, -1516, -1516, -1516,   405,  1263, -1516,    75,  1203, -1516,
   -1516,   543, -1516,   774,   146,  1204,    75,   774, 12645, -1516,
     425, -1516, -1516, -1516, -1516, -1516, -1516,    75,  1303,  1168,
    1008,   146, -1516, -1516,  1162,  1375, -1516, -1516, -1516, 15397,
    1268, -1516,  1269,  1273,  1274,  1276,  1278,  1279, -1516, -1516,
   -1516, -1516, -1516, -1516, -1516, -1516, -1516, -1516, -1516, -1516,
   -1516, -1516,  1430,    27,  1433,    27,  1192,  1361, -1516, -1516,
    1299, 19298,  1210, -1516, -1516, 12952, -1516,  1291, -1516, -1516,
   -1516, -1516, -1516, -1516, 11110,  1322, -1516, -1516, 11110, -1516,
     566, -1516, 11110,  1328, 11110, -1516,  1350,  1351,  1384,  1134,
    1304, -1516, 11110,  1297, -1516, -1516, -1516,  1296, -1516,    53,
   11110,  6186,  1300,   240, -1516, 19298,     3, -1516, 16300,   474,
   -1516, 16601,  1301, -1516, -1516,  1306, -1516, -1516, -1516, -1516,
   -1516, 11110,   901,  1313, 19298,   971, -1516,  1307,  1313, 19298,
   -1516,  1309, -1516, -1516, 11110, 11110, 11110, 11110,  1176, 11110,
   11110, -1516, 11110, -1516, 11110, 11110, 11110, 11110,  7414,   396,
   -1516, -1516, -1516, -1516, -1516,  1338, -1516, -1516, -1516, 11110,
   -1516,  1340, -1516, -1516, -1516, 11110, 19298, 19298, -1516,   584,
   -1516, 11110, -1516, -1516, -1516,  1314, 12645, -1516, -1516, -1516,
   -1516, -1516,    92, 12645, 12645,   672, -1516,  1108, -1516,   527,
   -1516,  1111,    75,  1334, -1516, -1516,  1217, -1516, -1516, -1516,
   -1516,  1390,  1310, -1516,   520, -1516, -1516, -1516, -1516, -1516,
   -1516, -1516, -1516,    84,    84, -1516,    27, -1516, -1516,   562,
   -1516,  1456,     9,  1403,  1320, 12952,   -21,  1221,  1339, -1516,
   -1516, 11110, -1516, 11110,  1352, -1516, 11110, -1516,  7414, 11110,
    1134, -1516, -1516, -1516, 11110, 11110, -1516, -1516, -1516,  7414,
    7414,  1410,  6186, 16902, 19298,   458, 19298, 11110, 19298,   665,
    7414, -1516,   491,    21,  1313, 19298, -1516,  1318,  1313, -1516,
   -1516, -1516, -1516, -1516, 11110, -1516, -1516, -1516, -1516,   230,
     238,   246, 11110, -1516, -1516,  1256, 11110, -1516, -1516,  1458,
   -1516, -1516, -1516,   817, 12645, 12645,    25,   788, -1516, -1516,
   -1516, -1516, -1516, -1516, 11110, -1516, 16902, -1516, 16902,  1420,
   -1516, -1516, -1516,  1487, -1516, -1516, -1516,  1248,  1411, -1516,
   -1516,  1412, -1516,   911, 19298,  1402,  1293, 19298, 12952, -1516,
   -1516, 11110, -1516, -1516, -1516,  1304, -1516, -1516, 16902, -1516,
   -1516, -1516,  1429, 11110,  1341, -1516,  1431,  7414, -1516, 19298,
     600,   757, -1516,  1327,  1313, -1516,  1332, -1516,  1333,  1236,
    1238,   409, -1516,  1256,  1408,    25,    25, 12645,   413, -1516,
   -1516, 16902, -1516, -1516,  1403, 12952, -1516,  1338,  1228, 19298,
    1414,  1305,  1412, -1516,   691, 16902,  6186, 16902,  1342, -1516,
   -1516,  1440,   670, -1516, -1516, -1516, -1516,  1355,   797, -1516,
   -1516, -1516,  1343, -1516,  7414,   902, -1516, -1516, 19298,    25,
   -1516, -1516, -1516, -1516, -1516, 11110,  1244, 19298,  1417,  6186,
     734, -1516, -1516,   743, 11110, -1516, -1516, -1516, -1516, -1516,
   -1516, -1516,  1421, -1516, -1516,  1245,  1246, 19298, -1516, -1516,
   11110,  7414, 19298,  1251, 11110,  1252,  1358, 12952, -1516, 12952,
    7414, -1516,  1346,  1250, 19298,  1319,  1428, 19298,  1255, 12952,
   -1516
  };

  /* YYDEFACT[S] -- default reduction number in state S.  Performed when
     YYTABLE doesn't specify something else to do.  Zero means the
     default is an error.  */
  const unsigned short int
  jsoniq_parser::yydefact_[] =
  {
       167,   464,   465,   828,   466,   170,   170,   170,     0,   845,
    1040,   122,   124,   644,   938,   947,   887,   850,   848,   830,
     939,   942,   894,   854,   831,   833,     0,   948,   834,   945,
     916,   896,   870,   832,   891,   892,   943,   940,   890,   836,
     946,   837,   838,   982,   994,   981,   888,   907,   901,   839,
     889,   841,   840,   983,   925,   926,   893,   867,  1004,  1005,
    1006,  1007,  1008,  1009,  1010,  1011,  1012,  1013,  1014,  1028,
    1035,   915,   911,   902,   881,   829,     0,   910,   918,   927,
    1029,   906,   497,   882,   883,   941,  1030,  1036,   903,   920,
       0,   505,   453,   499,   913,   847,   904,   905,   934,   908,
     924,   933,  1034,  1037,   853,   895,   936,   498,   923,   929,
     170,     0,     0,     0,   402,   921,   932,   937,   935,   914,
     900,   984,   898,   899,  1031,     0,   401,     0,  1032,  1038,
     930,   884,   909,  1033,   213,   431,     0,   463,   931,   912,
     919,   928,   922,   985,   875,   880,   879,   878,   877,   876,
     842,   897,     0,   846,     0,   944,   868,   496,   500,   501,
     975,   974,   976,   852,   851,   871,     0,   835,     0,   978,
       0,     0,   874,   917,   973,   980,   979,   972,   872,   977,
     989,   990,   987,   988,   986,   843,   991,   992,   993,   964,
     963,   950,   866,   859,   957,   953,   869,   865,   965,     0,
     855,   856,   849,   858,   962,   961,   958,   954,   970,   971,
     969,   960,   956,   949,   857,   968,   967,   861,   863,   862,
     955,   959,   951,   864,   952,   860,   966,  1015,  1016,  1017,
    1018,  1019,  1020,   996,   997,   995,  1001,  1002,  1003,   998,
     999,  1000,   873,  1021,  1022,  1023,  1024,  1025,  1026,  1027,
       0,     0,     0,  1039,   167,   167,     0,     2,   167,     9,
      11,    25,     0,    30,    33,    38,    39,    40,    41,    42,
      43,    44,    34,    60,    61,    35,    36,     0,    78,    81,
      82,    37,    83,    84,     0,   120,    85,    86,    87,    88,
      20,   164,   165,   166,   173,   176,   488,   177,     0,   178,
     179,   180,   181,   182,   183,   184,   187,   188,     0,   214,
     222,   217,   249,   255,     0,   247,     0,   248,   224,   218,
     186,   219,   185,   220,   223,   359,   361,   363,   365,   367,
     369,   373,   375,   378,   383,   386,   389,   391,   393,   395,
       0,   399,   406,   405,   407,     0,   422,   408,   427,   430,
     432,   435,   437,     0,   442,   439,     0,   450,   460,   462,
     436,   467,   479,   493,   495,   480,   481,   482,   485,   486,
     483,   487,   514,   515,   484,   518,   520,   521,   522,   519,
     567,   568,   569,   570,   571,   572,   573,   459,   616,     0,
     607,   615,   614,   613,   612,   609,   611,   608,   610,   494,
      45,   225,   226,   228,   227,   229,   221,   490,   491,   492,
     489,   231,   234,   230,   232,   233,   461,   827,   844,   938,
     947,   945,   846,     0,   168,   169,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   128,   130,   131,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   280,   281,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   455,   458,
     445,     0,     0,   830,   854,   833,   885,   948,   834,   896,
     836,   907,   839,   841,   840,   925,  1028,  1035,   829,  1029,
     883,  1030,  1036,   908,  1034,  1037,   932,   984,  1031,  1032,
    1038,  1033,   985,   872,   989,   990,   987,   843,   991,   886,
     856,   451,   827,   443,     0,   194,   444,   447,   830,   831,
     833,   832,   836,   837,   838,   839,   829,   835,   502,     0,
     449,   448,     0,     0,   214,     0,   461,   834,   841,   840,
       0,   170,   792,   991,     0,   222,     0,   503,     0,   534,
       0,     0,   454,     0,   425,   426,     0,   457,   456,   446,
     429,     0,     0,   563,     0,     0,     0,     0,     0,     0,
       0,     0,   978,     0,   812,     0,   835,   978,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   364,   794,     0,   796,     0,
       0,     0,   167,     3,     4,     1,    10,    12,     0,     0,
       0,     0,     6,   167,     0,   167,     0,     0,   121,   174,
       0,     0,   192,     0,     0,   201,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   206,   235,   254,   250,   256,
     251,   253,   252,   260,     0,     0,     0,     0,     0,     0,
     410,   415,   414,   413,   412,   411,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   404,   403,   400,     0,     0,   423,
     428,     0,     0,     0,   438,   476,   441,   440,   452,     0,
       0,   468,     0,     0,     0,   575,   577,   581,   583,     0,
     126,     0,   826,    49,    46,    47,    50,    51,     0,     0,
       0,     0,    52,    53,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   651,   652,   653,     0,   105,   144,
       0,     0,   114,     0,     0,     0,     0,   129,     0,     0,
     624,     0,     0,     0,   619,     0,     0,     0,   634,     0,
       0,   258,   263,     0,     0,   136,     0,   140,   170,   517,
       0,    62,     0,    71,     0,     0,     0,    63,     0,     0,
       0,     0,   622,     0,     0,   625,     0,     0,     0,     0,
     330,     0,     0,   623,     0,     0,     0,   642,     0,     0,
       0,     0,   628,     0,     0,   196,     0,     0,   190,   189,
       0,     0,   798,     0,     0,     0,     0,   502,     0,   793,
       0,   504,   535,   534,   531,     0,     0,     0,   565,   564,
     424,     0,   562,     0,     0,   664,   665,   811,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   670,     0,   204,   205,     0,     0,     0,     0,     0,
     209,   210,   259,   795,   797,     0,     0,     5,    26,     0,
      27,     0,     7,    31,     0,    17,     8,    32,     0,    21,
     938,    79,    18,    80,    22,   195,     0,   193,   215,   216,
       0,     0,     0,     0,   207,   236,   298,   237,   238,   257,
       0,     0,   360,   362,   366,     0,   370,   377,   376,   374,
     380,   381,   382,   379,   384,   385,   388,   387,     0,     0,
       0,     0,   409,   420,     0,   433,   434,     0,   477,     0,
     474,   475,   471,   510,   469,   512,     0,   617,   516,   508,
       0,     0,   123,   125,     0,     0,     0,   104,     0,    94,
      96,    97,    98,    99,   101,   102,   103,    95,   100,    90,
      91,     0,     0,   110,     0,   106,   108,   109,   116,     0,
       0,    89,    48,     0,     0,     0,     0,     0,     0,     0,
     742,   747,     0,     0,   743,   777,   730,   732,   733,   734,
     736,   738,   737,   735,   739,     0,     0,     0,     0,     0,
     113,     0,   146,     0,     0,   580,   574,   620,   621,     0,
       0,   638,     0,   635,     0,     0,     0,     0,     0,     0,
       0,     0,   142,     0,     0,   137,     0,     0,     0,     0,
       0,     0,    64,     0,     0,     0,   279,   285,   282,     0,
     627,   626,   633,   641,     0,     0,     0,     0,   579,     0,
       0,     0,   416,     0,     0,     0,     0,   631,     0,   629,
       0,   197,     0,     0,   800,     0,   461,   799,     0,     0,
       0,   534,   532,     0,   523,     0,     0,   506,   507,     0,
      13,     0,    15,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   806,   807,     0,     0,   814,     0,     0,
       0,     0,     0,     0,     0,   202,     0,     0,     0,   678,
       0,   211,     0,   810,     0,     0,     0,   167,     0,   167,
       0,   175,   246,     0,   314,   310,   312,     0,   307,   299,
     300,     0,     0,   239,   240,     0,   245,     0,     0,     0,
       0,   708,   371,   681,   685,   687,   689,   691,   694,   701,
     702,   710,   948,   596,     0,   842,   605,   823,   825,   821,
     598,   390,   586,   593,   594,   599,   645,   646,   600,   601,
     817,   818,   819,   604,   392,   394,   397,   606,   396,   421,
     478,   472,     0,     0,   470,   509,   127,    58,    59,    56,
      57,   133,   132,     0,    92,     0,     0,     0,   111,   112,
     117,    76,    77,    54,    55,    75,   748,     0,   751,   778,
       0,   741,   740,   745,   744,   776,     0,     0,   753,     0,
     749,   752,   731,     0,     0,     0,     0,     0,     0,     0,
     618,   145,   148,   150,     0,     0,     0,   115,   118,     0,
       0,     0,   170,     0,     0,   642,     0,     0,     0,   265,
       0,   585,     0,   266,     0,     0,     0,     0,     0,     0,
       0,   143,   138,   141,     0,   191,     0,     0,    73,    67,
      70,    69,     0,    65,   283,     0,     0,   170,     0,   328,
     332,     0,     0,     0,   335,     0,     0,   341,     0,     0,
     348,     0,   352,     0,   418,   417,   170,     0,     0,   198,
       0,   200,   329,     0,     0,     0,     0,     0,   535,     0,
     525,     0,   558,   555,     0,   559,   560,     0,     0,   554,
       0,   529,   557,   556,     0,     0,     0,     0,     0,   657,
     658,   654,     0,     0,   662,   663,   659,   803,   804,     0,
     668,   813,   666,     0,     0,     0,     0,     0,   672,   834,
     841,   840,   991,   203,     0,     0,     0,   673,   674,     0,
       0,   212,   809,    28,     0,    19,    23,    24,   311,   323,
       0,   324,     0,   315,   316,   317,   318,     0,   502,     0,
     308,     0,     0,     0,   241,     0,     0,     0,     0,   292,
       0,   289,   294,   244,     0,     0,   692,   705,     0,   368,
     372,     0,   724,     0,     0,     0,     0,     0,     0,   680,
     682,   683,   719,   720,   721,   723,   722,     0,     0,   696,
     695,     0,   699,   703,   717,   715,   714,   707,   711,     0,
       0,   589,     0,     0,     0,     0,     0,     0,   590,   592,
     591,   587,   398,   473,   511,   513,   135,   134,    93,   107,
     765,   746,     0,   770,     0,   770,   759,   754,   149,   151,
       0,     0,     0,   119,   147,     0,    29,     0,   639,   640,
     643,   636,   637,   264,     0,     0,   278,   270,     0,   274,
       0,   268,     0,     0,     0,   139,     0,     0,    72,     0,
      66,   284,     0,     0,   331,   333,   338,     0,   336,     0,
       0,     0,     0,     0,   342,     0,     0,   356,     0,     0,
     349,     0,     0,   353,   419,     0,   632,   630,   199,   801,
     802,     0,     0,   534,     0,     0,   566,     0,   534,     0,
     530,     0,    14,    16,     0,     0,     0,     0,     0,     0,
       0,   816,     0,   671,     0,     0,     0,     0,     0,     0,
     675,   679,   327,   325,   326,   319,   320,   321,   313,     0,
     306,     0,   309,   301,   287,     0,     0,     0,   243,   290,
     293,     0,   709,   700,   706,     0,     0,   779,   780,   790,
     789,   788,     0,     0,     0,     0,   781,   686,   787,     0,
     684,   688,     0,     0,   693,   697,     0,   718,   713,   716,
     712,     0,     0,   602,     0,   595,   650,   588,   822,   824,
     820,   597,   766,     0,     0,   764,   771,   772,   768,     0,
     763,     0,   761,     0,     0,     0,     0,     0,     0,   576,
     267,     0,   276,     0,     0,   272,     0,   275,     0,     0,
       0,    68,   286,   582,     0,     0,   339,   343,   337,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   578,     0,     0,   534,     0,   561,     0,   534,   584,
     655,   656,   660,   661,     0,   808,   667,   815,   669,     0,
       0,     0,     0,   676,   322,   302,     0,   288,   296,   297,
     291,   242,   704,   791,     0,     0,   783,     0,   729,   728,
     727,   726,   725,   690,     0,   782,     0,   647,     0,     0,
     775,   774,   773,     0,   767,   760,   758,     0,   755,   756,
     750,   152,   154,   156,     0,     0,     0,     0,     0,   271,
     269,     0,   277,   208,   358,    74,   334,   340,     0,   354,
     350,   357,     0,     0,     0,   344,     0,     0,   346,     0,
     544,   538,   533,     0,   534,   524,     0,   805,     0,     0,
       0,     0,   305,   303,     0,   785,   784,     0,     0,   648,
     603,     0,   769,   762,     0,     0,   158,   157,     0,     0,
       0,     0,   153,   273,     0,     0,     0,     0,     0,   552,
     546,     0,   545,   547,   553,   550,   540,     0,   539,   541,
     551,   526,     0,   527,     0,     0,   677,   304,     0,   786,
     698,   649,   757,   155,   159,     0,     0,     0,     0,     0,
       0,   347,   345,     0,     0,   537,   548,   549,   536,   542,
     543,   528,     0,   295,   160,     0,     0,     0,   355,   351,
       0,     0,     0,     0,     0,     0,     0,     0,   162,     0,
       0,   161,     0,     0,     0,     0,     0,     0,     0,     0,
     163
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  jsoniq_parser::yypgoto_[] =
  {
     -1516, -1516,  -192,  -180, -1516,  1290,  1292, -1516,  1294,  -553,
   -1516, -1516, -1516, -1516, -1516, -1516, -1516, -1516, -1516, -1516,
   -1000, -1516, -1516, -1516, -1516,  -213,  -591, -1516,   824,    48,
   -1516, -1516, -1516, -1516, -1516,   350,   592, -1516, -1516,    -4,
    -171,  1138, -1516,  1116, -1516, -1516,  -626, -1516,   536, -1516,
     322, -1516,  -166,  -212, -1516,  -543, -1516,    10,    26,     6,
    -292,  -184, -1516,  -887, -1516, -1516,   130, -1516, -1516, -1516,
   -1516, -1516, -1516, -1516, -1516, -1516, -1516,   704, -1516,   -82,
    1393,     0, -1516, -1516, -1516, -1516,   429, -1516, -1516,  -310,
   -1516,    20, -1516, -1516,    62,  -941,  -752,  -721, -1516, -1516,
     786, -1516, -1516,    -3,   180, -1516, -1516, -1516,   189, -1316,
   -1516,   448,   195, -1516, -1516,   199, -1317, -1516,  1036,   296,
   -1516, -1516,   293, -1013, -1516, -1516,   291, -1516, -1516, -1260,
   -1244, -1516,   287, -1445, -1516, -1516,   922,  -154, -1516,   913,
     914, -1516, -1516,  -659,   414,  -644,   423,   431, -1516, -1516,
   -1516,   660, -1516, -1516,  1258, -1516, -1516, -1516, -1516,  -844,
    -336,  -694, -1516,   -75, -1516, -1516, -1516, -1516, -1516, -1516,
   -1516,   -20,  -827, -1516,  -147,   722,   331, -1516,  -395, -1516,
   -1516,   884, -1516, -1516, -1516, -1516, -1516,   882, -1516, -1516,
   -1516, -1516, -1023, -1516,   273, -1516,   762,  -809, -1516, -1516,
   -1516, -1516, -1516,  -211,  -203, -1248,  -834, -1516, -1516, -1516,
   -1516, -1516, -1516, -1516, -1516, -1516, -1516, -1516,  -751,  -870,
    -119,  -888, -1516, -1516, -1516,  -808, -1516, -1516, -1516, -1516,
   -1516, -1516, -1516, -1516, -1516,  1144,  1145,  -245,   578,  -660,
   -1516, -1516, -1516, -1516, -1516, -1516, -1516, -1516, -1516, -1516,
   -1516,   245, -1516, -1516,   235, -1516,   239, -1070, -1516, -1516,
   -1516,   190,   181,     5,   460, -1516, -1516, -1516, -1516, -1516,
   -1516, -1516, -1516, -1516, -1516, -1516, -1516, -1516,   191, -1516,
   -1516, -1516,    17,   455,   609, -1516, -1516, -1516, -1516, -1516,
     388, -1516, -1516, -1515, -1516, -1516, -1516,  -492, -1516,   150,
   -1516,    -8, -1516, -1516, -1516, -1516, -1332, -1516,   202, -1516,
   -1516, -1516, -1516, -1516,  -105, -1516, -1516, -1516, -1516, -1516,
    -929, -1516, -1516, -1516,  -414,   946,   -25, -1516
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  jsoniq_parser::yydefgoto_[] =
  {
        -1,   256,   644,   257,   258,   259,   260,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
    1278,   786,   274,   275,   276,   277,   278,   279,   969,   970,
     971,   280,   281,   282,   975,   976,   977,   283,   450,   284,
     285,   719,   286,   452,   453,   454,   464,   776,   777,   287,
    1241,   288,  1731,  1732,   289,   290,   291,   552,   292,   293,
     294,   295,   296,   779,   297,   298,   535,   299,   300,   301,
     302,   303,   304,   655,   305,   306,   870,   871,   307,   308,
     309,   565,   311,   656,   667,  1145,  1146,   312,   657,   313,
     659,   566,   315,   316,   771,   772,  1399,   471,   317,   472,
     473,   911,  1400,  1401,  1402,   660,   661,  1139,  1140,  1390,
     662,  1135,  1136,  1383,  1384,  1385,  1386,   318,   799,   800,
     319,  1293,  1294,  1509,   320,  1296,  1297,   321,   322,  1299,
    1300,  1301,  1302,  1516,   323,   324,   325,   326,   327,   328,
     329,  1409,   330,   331,   332,   333,   334,   335,   336,   337,
     338,  1185,   339,   340,   341,   342,   676,   343,   344,   345,
     346,   347,   348,   349,   350,   351,   352,   353,   354,   355,
     356,   357,   358,   359,   360,   711,   705,   361,   362,   363,
     364,   365,   366,   367,   368,   369,   370,   946,   371,   372,
     373,   374,   375,   376,  1330,   833,   834,   835,  1762,  1807,
    1808,  1801,  1802,  1809,  1803,  1331,  1332,   377,   378,  1333,
     379,   380,   381,   382,   383,   384,   385,   386,  1031,  1517,
    1451,  1172,  1614,  1173,  1186,   387,   388,   389,   390,   391,
     392,   393,   394,   395,   396,   397,   398,   806,  1254,   399,
    1175,  1176,  1177,  1178,   400,   401,   402,   403,   404,   405,
     860,   861,   406,  1367,  1368,  1693,  1120,  1152,  1419,  1420,
    1153,  1154,  1155,  1156,  1157,  1429,  1604,  1605,  1158,  1432,
    1159,  1585,  1160,  1161,  1437,  1438,  1610,  1608,  1421,  1422,
    1423,  1424,  1711,   748,   996,   997,   998,   999,  1000,  1001,
    1230,  1634,  1728,  1231,  1632,  1726,  1002,  1465,  1629,  1625,
    1626,  1627,  1003,  1004,  1425,  1433,  1595,  1426,  1591,  1410,
     407,   408,   409,   410,   555,   411,   412,   413,   414,   415,
    1179,  1180,  1181,  1182,  1279,   416,   417,   418
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const short int jsoniq_parser::yytable_ninf_ = -887;
  const short int
  jsoniq_parser::yytable_[] =
  {
       310,   639,   613,   932,   658,   310,   310,   310,   310,   699,
     451,   425,   425,   425,   429,   423,   426,   427,   723,   594,
     314,  1029,   919,   603,  1083,   314,   314,   314,   314,   564,
     568,   424,   424,   424,   428,   720,   720,  1045,   920,   921,
     922,   923,  1119,  1283,   891,   893,  1295,   615,   631,   941,
    1057,   532,  1030,   783,   787,  1520,   531,  1532,  1171,  1184,
     632,   580,  1329,   600,  1071,   532,   632,  1566,  1567,  1202,
     634,  1150,  1570,  1665,   623,   624,  1669,  1243,  1405,  1025,
     883,   887,  1540,  1259,  1207,   636,   632,  1267,   532,  1142,
     885,   889,   892,   894,    11,    12,   632,   632,  1734,  1606,
     532,   632,   532,  1233,   956,    13,  1592,  1285,  1234,   762,
     310,   632,   632,   638,   436,  1760,   553,  1235,  1729,   632,
    1174,  1174,   632,   951,  1236,   632,  1237,   763,   632,   632,
     314,   722,  1054,   639,   820,  1238,   424,   639,  1026,   582,
    1027,   595,   439,   632,  1704,   595,   838,   774,  1027,  -171,
     632,  1510,   820,   632,  1510,   632,  1261,   632,   632,    11,
      12,   632,  1239,  1272,  1174,  1623,  1026,   643,   617,   619,
     632,   698,  1084,   643,   432,   433,   469,   434,   435,   436,
     754,  1462,  1026,   688,   732,   679,    82,   886,  1380,   437,
    1662,   752,  1028,   643,   127,   438,   753,   689,  1242,   632,
    1268,    93,   680,   952,   643,  1761,   762,   439,   643,  1735,
    1382,   640,   440,  1055,  1663,   632,   775,   733,  1174,  1126,
    1056,  1112,  1264,  1705,   763,  1174,   107,  1210,   821,  1624,
    1147,   632,  1492,  1148,   821,   643,  1392,  1511,  1085,   632,
    1655,   470,  1464,  1592,   441,   442,  1130,   632,  1694,   852,
     643,  1374,  1143,   127,   310,   310,   658,   643,   310,   632,
     643,   639,   643,   782,   643,   643,   632,  1101,   643,  1822,
    1593,   829,  1319,   700,   314,   314,  1442,   643,   314,  1269,
     638,  1271,  1500,  1513,   831,  1019,   633,  1540,  1520,   891,
     893,  1736,  1144,   310,  1240,   157,   158,   159,  1329,   444,
    1727,   635,   878,  1794,  1150,  1150,   643,  1329,  1265,   880,
    1270,   484,  1127,   314,   839,  1129,  1457,  1483,  1442,  1373,
    1243,   470,   643,   583,  1286,   883,   887,   982,   532,   470,
    1037,   532,  1203,   706,  -171,   470,   708,  1584,   643,  1149,
    1059,  1510,  1060,   640,  1116,  1315,   643,   640,  1316,   764,
    1830,   470,  1833,  1113,   643,   951,  1174,  1317,   853,   755,
     904,   470,   445,   722,  1102,  1320,   643,   756,   632,  -172,
     632,   646,  1042,   643,   632,   647,   632,   874,   767,  1772,
     648,   873,  1407,   780,  1190,   641,  1167,  1168,  1169,   485,
    1393,   456,  1054,   793,   457,   632,   632,  1093,  1174,   649,
     804,   805,  1453,   446,  1495,   127,   632,  1593,  1594,   811,
     632,   730,   532,   430,   632,   532,  1786,  1027,  1768,   532,
     884,   888,   532,   532,   447,   310,  1769,  1660,   709,   310,
     532,  1321,   448,   431,  1770,   953,   532,   532,   879,   881,
     449,  1242,   877,  1049,   532,   314,   847,   784,   896,   314,
    1065,   532,   532,   532,   532,   855,   310,  1817,   310,   532,
     486,   487,   429,   703,   429,   710,  1174,   532,   642,  1484,
    1824,   640,   985,  1073,   986,   643,   314,   643,   314,  1020,
     310,   643,   759,   643,   761,   310,   429,   604,   836,   837,
    1174,   429,   605,   851,  1022,   785,   713,  1473,   650,   841,
     314,   651,   643,   643,   455,   314,   802,   714,  1485,   532,
    1815,   808,  1329,   643,   458,   913,   652,   643,   987,   646,
    1151,   643,  1411,   647,   532,  1094,  1095,   709,   648,   866,
     868,  1097,  1369,    11,    12,   532,   891,   893,   891,  1119,
    1096,   724,   653,  1561,   738,  1458,   739,   649,  1493,  1354,
    1470,  1692,  1086,   310,  -172,   725,  1196,  1089,  1087,  1021,
    1088,   310,   703,  1150,   710,  1211,  1212,   425,   595,  1613,
    1215,  1520,  1150,   314,  1023,   639,   606,   595,  1034,  1118,
    1189,   314,   532,  1150,  1375,  1376,  1377,   424,  1370,   532,
    1582,   654,   646,  1666,  1816,  1412,   647,  1066,  1820,    13,
    1251,   648,   663,  1221,  1131,  1799,   741,  1370,  1448,  1322,
    1759,  1068,   310,  1193,  1222,  1090,   934,  1193,   867,   637,
     649,   937,   310,   462,   451,  -261,   935,   936,  1718,   821,
    1227,  1174,   314,   310,   310,   310,   310,  1571,  1395,  1449,
    1091,   532,   314,  1396,   459,  1753,   650,  1228,  1552,   651,
    1745,    13,   310,   314,   314,   314,   314,  1450,  1035,  1098,
    1099,  1667,   463,  1027,   830,  1124,   664,  1026,   742,  1663,
    1723,   665,   314,   988,  1100,  1799,   872,  1067,  1667,  1322,
      82,  1027,  1413,  1414,   532,  1415,   989,   679,   990,  -261,
     653,  1069,  1128,  1194,  -261,    93,   881,  1195,  1092,   991,
     992,   993,  1417,   994,   680,   995,   822,   465,  1719,   958,
    1174,  1110,   532,  1174,  1418,  1643,  1044,   490,   666,   650,
     107,   614,   651,  -262,  1673,  1325,   532,  1326,   909,  1677,
     532,   532,    82,  1322,  1323,  1800,   628,  1558,  1644,   654,
     474,  -261,  1078,  1079,  1080,  1026,   868,    93,   491,   532,
    1724,   492,   629,  1151,  1151,  1327,  1513,   532,  1150,  1599,
     532,   477,  1587,   653,   532,   478,  1322,   895,  1026,   482,
     682,   897,   107,  1322,  1323,  1253,  1147,  1256,   310,  1148,
    1389,  1638,   891,   972,   425,  1117,  1805,  -262,  1036,   157,
     158,   159,  -262,  1751,  1070,  1325,   479,  1326,   314,   127,
     683,  1708,  1588,  1227,   424,  1836,  1322,   532,  1709,   310,
     310,   856,   654,   684,   699,   429,   429,  1569,  1710,   709,
    1228,  1307,   483,  1308,  1363,  1327,  1805,   973,  1324,   314,
     314,   726,   974,   595,  1106,  1063,  1064,   709,   738,  -262,
     739,   157,   158,   159,   532,   727,  1779,   685,  1780,  1325,
    1245,  1326,  1757,   973,   703,  1174,   710,  1192,   974,  1246,
     709,  1322,  1323,  1498,  1229,  1763,  1395,   310,  1324,  1766,
    1411,  1396,   703,   740,   710,   532,  1663,   679,  1829,  1327,
     488,   886,  1325,   113,  1326,   532,   451,   314,   570,  1325,
    1397,  1326,   466,  1806,   680,   703,   310,   710,  1462,   125,
     741,   467,  1663,   532,   532,   532,   532,  1223,  1174,  1027,
    1174,  1821,  1327,  1125,   489,  1463,   314,   681,  1224,  1327,
    1328,  1850,  1325,   113,  1326,   896,  1804,  1810,   468,   629,
    1851,  1398,   881,  1839,  1706,  1707,  1371,  1292,   152,   125,
    1174,  1733,  1703,  1412,  1292,  1663,  1708,   532,   679,   533,
    1507,   728,  1327,  1709,  1663,  1812,  1324,  1512,  1518,  1464,
    1534,   532,   742,  1710,  1355,   680,  1562,   729,  1804,  1197,
     534,  1519,  1379,  1174,  1810,  1572,  1199,  1325,   152,  1326,
    1322,  1323,  1787,  1380,  1496,  1198,   532,  1174,  1777,  1174,
    1434,  1435,  1200,  1381,  1201,   532,  1521,   532,  1456,   532,
     549,   532,  1518,  1518,   571,  1382,  1026,  1327,   532,  1522,
     778,   113,  1151,  1436,   778,  1672,  1842,  1204,  1380,   686,
    1395,  1151,  1337,   460,  1338,  1396,   461,   125,   687,  1204,
    1413,  1414,  1151,  1415,   475,   938,   548,   476,   938,   536,
    1416,   532,   938,   532,  1733,  1775,  1776,  1589,  1539,   537,
    1417,  1216,  1217,  1218,  1590,   658,   556,  1219,   550,   569,
     480,   310,  1418,   481,   551,  1404,   152,   429,   744,   745,
     746,   573,   572,   576,   704,  1324,  1342,   707,  1343,   701,
     702,   314,  1213,  1214,   577,  1651,   595,  1303,  1563,  1564,
     581,  1733,   578,   917,   918,   584,  1325,   579,  1326,   959,
     960,   961,   962,   963,   964,   965,   966,   967,   968,   924,
     925,   585,   532,  -618,   556,   607,  1364,   608,  1819,   926,
     927,   609,   451,  1468,  1469,   610,  1327,   310,   310,   310,
     113,  1720,  1721,   611,   612,   625,  1365,   668,   645,   532,
      11,    12,   669,   677,   678,   690,   125,   314,   314,   314,
     432,   433,   691,   434,   435,   692,   697,   693,   703,   712,
     436,   715,   716,  1861,   722,  1862,   717,  1675,   718,   734,
     437,   438,   747,   736,   737,  1870,   760,   778,   613,   751,
     781,   532,   789,   790,   791,   152,   792,   803,   439,   809,
     810,   457,   816,   440,   670,   671,   672,   673,   674,   675,
     461,   476,   818,   481,   492,   820,   823,  1151,   824,   825,
     826,   828,   832,   840,   843,   842,   844,   456,   858,  1657,
     460,   475,   480,   491,   859,   441,   442,   443,   863,   864,
     869,   876,   882,   532,   900,   902,   910,   532,   901,   907,
     915,   903,   908,   928,   929,   930,   931,   947,   948,   532,
     954,   955,   310,   957,   979,   980,   983,   984,   425,  1005,
    1006,  1007,  1477,   532,  1009,  1011,   904,  1014,  1017,  1015,
    1016,  1024,   314,   532,  1018,   444,   310,  1033,   424,  1040,
    1039,  1061,  1043,  1105,  1050,  1114,  1051,   310,  1052,  1053,
    1058,  1062,  1126,   425,  1111,  1115,   314,  1503,  1122,  1108,
    1133,  1205,   974,   532,  1026,  1225,   310,   314,  1249,  1244,
    1250,  1226,   425,   424,  1252,  1266,  1525,  1262,  1260,   774,
    1274,  1275,  1280,  1276,  1277,  1281,   314,   310,  1282,  1287,
    1288,   532,   424,   429,   310,  1306,  1291,  1292,   445,  1298,
     429,   532,  1304,  1310,  1311,   532,  1305,   314,  1318,  1313,
    1314,  1335,  1334,  1537,   314,  1336,  1743,  1349,  1356,  1366,
    1541,   740,  1387,  1389,  1408,  1391,  1394,  1747,  1657,  1364,
    1749,  1427,  1439,   532,  1431,   867,  1428,  1440,  1758,   446,
    1443,  1452,  1444,   731,    13,  1460,   735,  1461,  1445,  1365,
     743,  1446,  1466,   749,   750,  1447,  1475,  1476,  1472,  1480,
    1478,   758,  1471,  1479,  1481,   447,  1482,   770,   773,  1490,
    1488,  1494,  1499,   448,   532,   788,  1502,  1524,  1518,  1531,
    1533,   449,   796,   797,   798,   801,  1536,  1548,  1526,  1527,
     807,  1544,  1545,  1542,  1543,  1549,  1554,  1550,   814,  1546,
    1547,  1555,  1556,  1557,  1369,  1380,   532,  1575,  1576,  1581,
    1577,  1583,  1602,  1607,  1609,  1603,  1615,  1616,  1586,  1596,
    1622,  1617,  1618,  1628,  1619,  1749,  1620,  1621,  1631,  1633,
    1635,  1641,  1637,  1689,  1690,  1691,  1639,  1646,  1648,  1649,
     815,  1650,  1653,  1654,  1696,  1716,  1725,  1659,  1670,  1714,
     532,  1671,  1676,   532,  1679,   801,   532,  1684,  1717,  1702,
    1227,  1741,  1715,   554,  1831,  1748,   827,   556,  1730,   532,
    1738,   310,  1774,  1737,   532,  1781,  1765,  1782,  1783,  1784,
    1785,  1789,  1496,  1790,  1795,  1811,  1797,  1818,  1796,  1834,
    1813,   314,  1814,  1827,  1835,  1828,  1847,  1848,  1825,  1838,
    1852,  1841,  1864,  1853,   556,  1860,  1863,  1867,   626,  1866,
     627,   532,   532,   862,  1845,   630,  1854,  1459,  1364,  1848,
     773,   599,  1857,  1859,   981,  1208,  1869,   757,  1831,   721,
    1273,  1474,  1792,  1823,  1121,  1403,  1700,  1048,  1365,  1580,
    1573,  1378,  1568,  1565,  1504,   817,  1508,  1514,  1523,   914,
     912,  1188,   916,   940,  1535,  1082,   950,  1840,   696,  1837,
    1257,  1553,  1560,   765,   766,  1559,  1597,  1713,  1601,  1406,
    1771,  1600,   773,  1430,  1232,  1630,  1712,  1467,  1722,  1598,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1778,     0,     0,     0,     0,     0,   532,   532,
       0,   532,     0,   532,     0,   621,     0,     0,  1364,     0,
     532,     0,     0,     0,     0,   942,     0,     0,     0,  1364,
    1364,     0,   310,     0,     0,     0,     0,     0,  1365,     0,
    1364,     0,     0,     0,     0,     0,     0,     0,     0,  1365,
    1365,     0,   314,   978,     0,     0,     0,     0,     0,     0,
    1365,   532,     0,   532,     0,     0,     0,  1008,     0,     0,
       0,  1012,  1013,     0,     0,     0,     0,     0,     0,   532,
       0,     0,   532,     0,     0,     0,     0,     0,     0,     0,
    1032,     0,     0,   532,     0,     0,     0,     0,  1038,     0,
       0,  1041,     0,     0,   532,  1046,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   532,  1364,     0,     0,
       0,     0,     0,     0,   532,     0,     0,  1076,     0,     0,
     532,     0,   532,     0,     0,     0,     0,  1365,  1081,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   532,     0,     0,   310,     0,     0,     0,
       0,     0,   532,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1364,     0,   314,     0,     0,     0,
       0,     0,   532,     0,     0,     0,     0,   532,     0,   310,
       0,     0,     0,     0,  1365,     0,     0,     0,     0,   532,
       0,     0,   532,     0,     0,     0,  1132,     0,     0,   314,
       0,  1364,     0,     0,     0,     0,  1141,     0,     0,     0,
    1364,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1365,     0,     0,  1183,  1183,  1187,  1187,     0,     0,
    1365,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1183,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1220,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   554,     0,     0,  1248,     0,     0,
       0,     0,     0,     0,     0,     0,  1255,     0,  1255,     0,
     773,     0,  1183,     0,     0,     0,     0,     0,     0,  1183,
       0,     0,     0,     0,   845,   846,     0,     0,     0,   848,
     849,   850,     0,     0,   854,     0,     0,   857,     0,     0,
       0,     0,     0,   865,     0,     0,     0,     0,     0,     0,
       0,     0,   807,   875,   807,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   898,   899,     0,     0,
       0,     0,     0,     0,     0,   905,   906,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1388,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   945,     0,     0,     0,   945,     0,     0,
    1183,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1010,     0,     0,     0,
       0,     0,  1183,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1047,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   773,     0,     0,     0,  1486,  1072,
       0,     0,     0,  1074,  1075,     0,  1077,     0,     0,     0,
    1183,     0,     0,   905,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   801,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1183,  1103,  1104,     0,     0,  1107,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1123,
       0,     0,     0,     0,  1538,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   899,
       0,     0,     0,     0,     0,  1134,  1138,     0,     0,     0,
       0,     0,   862,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1579,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1209,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1183,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1247,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1636,     0,     0,
       0,  1263,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1284,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1289,  1290,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1661,     0,  1309,  1183,     0,  1312,  1183,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1674,     0,     0,     0,     0,  1678,     0,  1339,  1340,  1341,
       0,  1344,  1345,  1346,  1347,  1348,     0,     0,  1350,  1351,
       0,  1352,  1353,     0,     0,     0,  1357,  1358,     0,     0,
       0,     0,     0,     0,     0,  1372,     0,     0,     0,     0,
       0,     0,  1698,  1699,     0,     0,  1134,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1455,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1183,
    1752,     0,  1754,     0,  1756,     0,     0,     0,     0,     0,
       0,  1764,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1487,     0,  1489,
       0,  1491,  1183,     0,  1183,     0,     0,     0,     0,  1497,
       0,     0,     0,     0,     0,     0,     0,     0,  1501,     0,
    1788,     0,     0,  1791,  1505,  1506,     0,     0,     0,     0,
       0,     0,     0,     0,  1183,     0,     0,     0,     0,     0,
       0,     0,     0,  1528,     0,  1798,  1529,  1530,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1183,     0,     0,
       0,     0,     0,     0,     0,  1826,     0,     0,     0,     0,
       0,  1183,     0,  1183,     0,     0,     0,  1551,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1843,     0,     0,     0,     0,     0,
       0,     0,     0,  1846,     0,     0,     0,     0,     0,     0,
    1134,     0,     0,     0,  1138,  1574,     0,     0,     0,     0,
    1578,     0,     0,  1855,     0,     0,     0,     0,  1856,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1865,     0,     0,  1868,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1640,     0,     0,
       0,  1642,     0,     0,     0,  1645,     0,  1647,     0,     0,
       0,     0,     0,     0,     0,  1652,     0,     0,     0,     0,
       0,     0,     0,  1656,  1658,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1497,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1680,  1681,  1682,
    1683,     0,  1685,  1686,     0,  1687,     0,  1688,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1695,     0,     0,     0,     0,     0,  1697,     0,
       0,     0,     0,     0,  1701,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1739,     0,  1740,     0,     0,  1742,
       0,     0,  1744,     0,     0,     0,     0,  1746,  1658,     0,
       0,     0,     0,     0,     0,  1750,     0,     0,     0,     0,
    1755,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1767,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1773,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1793,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1750,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1832,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  -167,   886,     0,     0,     0,     0,  1844,     0,
       0,     0,  1849,     1,     2,     0,     0,  1832,     3,     0,
       0,     0,     4,     5,     6,     7,     8,     9,    10,    11,
      12,     0,    13,  1849,     0,    14,   420,  1858,    16,    17,
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
     104,   105,   106,   107,   108,   109,     0,   110,   111,     0,
     112,   113,   114,   115,   116,     0,     0,     0,   117,   118,
     119,   120,   121,   122,   123,   124,     0,   125,     0,   126,
     127,     0,     0,   128,   129,   130,     0,     0,     0,   131,
       0,   132,   133,   134,   135,   136,     0,   137,     0,   138,
       0,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,     0,     0,   150,   151,   152,     0,   422,     0,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,     0,   200,   201,   202,     0,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,     0,   251,
    -167,   886,   252,   253,     0,     0,     0,     0,     0,     0,
       0,     1,     2,     0,     0,     0,     3,     0,     0,     0,
       4,     5,     6,     7,     8,     9,    10,    11,    12,     0,
      13,     0,     0,   890,   420,     0,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,   421,
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
     106,   107,   108,   109,     0,   110,   111,     0,   112,   113,
     114,   115,   116,     0,     0,     0,   117,   118,   119,   120,
     121,   122,   123,   124,     0,   125,     0,   126,   127,     0,
       0,   128,   129,   130,     0,     0,     0,   131,     0,   132,
     133,   134,   135,   136,     0,   137,     0,   138,     0,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
       0,     0,   150,   151,   152,     0,   422,     0,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,     0,   200,   201,   202,     0,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   886,   251,     0,     0,
     252,   253,     0,     0,     0,     0,     1,     2,     0,     0,
       0,     3,     0,     0,     0,     4,     5,     6,     7,     8,
       9,    10,    11,    12,     0,    13,     0,     0,   419,   420,
       0,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,   421,    30,    31,    32,    33,    34,
       0,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,     0,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,     0,
      72,    73,    74,    75,    76,     0,    77,    78,    79,     0,
       0,    80,    81,     0,     0,     0,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,     0,    92,     0,     0,
       0,    93,     0,    94,    95,    96,    97,     0,    98,     0,
       0,     0,    99,   100,   101,   102,   103,     0,     0,     0,
       0,     0,     0,   104,   105,   106,   107,   108,   109,     0,
     110,   111,     0,   112,   113,   114,   115,   116,     0,     0,
       0,   117,   118,   119,   120,   121,   122,   123,   124,     0,
     125,     0,   126,   127,     0,     0,   128,   129,   130,     0,
       0,     0,   131,     0,   132,   133,   134,   135,   136,     0,
     137,     0,   138,     0,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,     0,     0,   150,   151,   152,
       0,   422,     0,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,     0,   200,
     201,   202,     0,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   886,   251,     0,     0,   252,   253,     0,     0,     0,
       0,     1,     2,     0,     0,     0,     3,     0,     0,     0,
       4,     5,     6,     7,     8,     9,    10,     0,     0,     0,
      13,     0,     0,   419,   420,     0,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,   557,   421,
      30,    31,    32,    33,    34,     0,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,     0,
      48,    49,    50,   558,   559,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,     0,    72,    73,    74,    75,    76,
       0,    77,    78,    79,     0,     0,    80,    81,     0,     0,
       0,    82,    83,   510,    85,    86,    87,    88,    89,   560,
      91,     0,    92,     0,     0,     0,    93,     0,    94,    95,
      96,    97,     0,    98,     0,     0,     0,    99,   100,   101,
     102,   103,     0,     0,     0,     0,     0,     0,   104,   105,
     106,   107,   108,   109,     0,   561,   111,     0,   112,   113,
     114,   115,   116,     0,     0,     0,   117,   118,   119,   120,
     121,   122,   123,   124,     0,   125,     0,   126,   127,     0,
       0,   128,   129,   130,     0,     0,     0,   131,     0,   132,
     133,     0,   135,   136,     0,   137,     0,   138,     0,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
       0,     0,   150,   151,   152,     0,   422,     0,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   524,   525,   526,   183,   184,   527,   563,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,     0,   200,   201,   202,     0,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,     0,   251,     0,     0,
     252,   253,  -885,   462,     0,  -261,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  -885,     0,     0,     0,  -885,     0,
       0,     0,  -885,  -885,     0,     0,     0,     0,  -885,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  -261,
       0,     0,  -885,     0,  -261,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  -885,     0,  -885,  -885,  -885,
       0,     0,  -885,  -885,  -885,  -885,     0,     0,     0,  -885,
    -885,     0,     0,     0,     0,     0,  -885,     0,     0,  -885,
    -885,  -261,     0,     0,     0,  -885,     0,     0,     0,     0,
    -885,  -885,     0,     0,     0,     0,     0,     0,     0,     0,
    -885,     0,     0,     0,     0,     0,     0,     0,     0,  -885,
    -885,     0,     0,     0,  -885,     0,     0,     0,  -885,     0,
    -885,     0,  -885,  -885,     0,     0,     0,     0,     0,     0,
    -885,  -885,     0,     0,  -885,     0,     0,     0,     0,  -885,
       0,  -886,   614,     0,  -262,     0,     0,  -885,  -885,  -885,
    -885,  -885,     0,  -885,  -885,  -885,  -885,  -885,     0,     0,
       0,     0,  -885,  -885,  -885,     0,  -885,  -885,  -885,  -885,
    -885,  -885,     0,  -885,     0,  -885,     0,     0,     0,     0,
       0,  -885,     0,  -886,     0,  -885,  -885,  -886,     0,     0,
       0,  -886,  -886,     0,     0,     0,     0,  -886,     0,     0,
    -885,     0,  -885,     0,  -885,     0,     0,     0,  -262,     0,
       0,  -886,     0,  -262,     0,     0,  -885,     0,     0,     0,
       0,  -885,     0,     0,  -885,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  -886,     0,  -886,  -886,  -886,     0,
       0,  -886,  -886,  -886,  -886,     0,     0,     0,  -886,  -886,
       0,     0,     0,     0,     0,  -886,     0,     0,  -886,  -886,
    -262,     0,     0,     0,  -886,     0,     0,     0,     0,  -886,
    -886,     0,     0,     0,     0,     0,     0,     0,  -885,  -886,
    -885,     0,     0,     0,     0,     0,     0,     0,  -886,  -886,
       0,     0,     0,  -886,     0,     0,     0,  -886,     0,  -886,
       0,  -886,  -886,     0,     0,     0,     0,     0,     0,  -886,
    -886,     0,     0,  -886,     0,     0,     0,     0,  -886,     0,
       0,     0,     0,     0,     0,     0,  -886,  -886,  -886,  -886,
    -886,     0,  -886,  -886,  -886,  -886,  -886,     0,     0,     0,
       0,  -886,  -886,  -886,     0,  -886,  -886,  -886,  -886,  -886,
    -886,     0,  -886,     0,  -886,     0,     0,     0,     0,     0,
    -886,     0,     0,     0,  -886,  -886,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  -886,
       0,  -886,     0,  -886,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  -886,     0,     0,     0,     0,
    -886,     0,     0,  -886,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     1,
       2,     0,     0,     0,     3,     0,     0,     0,     4,     5,
       6,     7,     8,     9,    10,    11,    12,  -886,    13,  -886,
       0,    14,    15,     0,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
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
     108,   109,     0,   110,   111,     0,   112,   113,   114,   115,
     116,     0,     0,     0,   117,   118,   119,   120,   121,   122,
     123,   124,     0,   125,     0,   126,   127,     0,     0,   128,
     129,   130,     0,     0,     0,   131,     0,   132,   133,   134,
     135,   136,     0,   137,     0,   138,     0,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,     0,     0,
     150,   151,   152,     0,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,     0,   200,   201,   202,     0,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,     0,   251,     0,     0,   252,   253,
       0,     1,     2,     0,   254,   255,     3,     0,     0,     0,
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
     106,   107,   108,   109,     0,   110,   111,     0,   112,   113,
     114,   115,   116,     0,     0,     0,   117,   118,   119,   120,
     121,   122,   123,   124,     0,   125,     0,   126,   127,     0,
       0,   128,   129,   130,     0,     0,     0,   131,     0,   132,
     133,   134,   135,   136,     0,   137,     0,   138,     0,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
       0,     0,   150,   151,   152,     0,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,     0,   200,   201,   202,     0,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,     0,   251,     0,     0,
     252,   253,     0,     1,     2,     0,     0,   622,     3,     0,
       0,     0,     4,     5,     6,     7,     8,     9,    10,    11,
      12,     0,    13,     0,     0,    14,    15,     0,    16,    17,
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
     104,   105,   106,   107,   108,   109,     0,   110,   111,     0,
     112,   113,   114,   115,   116,     0,     0,     0,   117,   118,
     119,   120,   121,   122,   123,   124,     0,   125,     0,   126,
     127,     0,     0,   128,   129,   130,     0,     0,     0,   131,
       0,   132,   133,   134,   135,   136,     0,   137,     0,   138,
       0,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,     0,     0,   150,   151,   152,     0,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,     0,   200,   201,   202,     0,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,     0,   251,
       1,     2,   252,   253,     0,     3,     0,     0,     0,     4,
       5,     6,     7,     8,     9,    10,    11,    12,     0,    13,
       0,     0,   419,   420,     0,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,   421,    30,
      31,    32,    33,    34,     0,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,     0,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,     0,    72,    73,    74,    75,    76,     0,
      77,    78,    79,     0,     0,    80,    81,     0,     0,     0,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
       0,    92,     0,     0,     0,    93,     0,    94,    95,    96,
      97,     0,    98,     0,     0,     0,    99,   100,   101,   102,
     103,     0,     0,     0,     0,     0,     0,   104,   105,   106,
     107,   108,   109,     0,   110,   111,     0,   112,   113,   114,
     115,   116,     0,     0,     0,   117,   118,   119,   120,   121,
     122,   123,   124,     0,   125,     0,   126,   127,     0,     0,
     128,   129,   130,     0,   819,     0,   131,     0,   132,   133,
     134,   135,   136,     0,   137,     0,   138,     0,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,     0,
       0,   150,   151,   152,     0,   422,     0,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,     0,   200,   201,   202,     0,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,     0,   251,     1,     2,   252,
     253,     0,     3,     0,     0,     0,     4,     5,     6,     7,
       8,     9,    10,    11,    12,     0,    13,     0,     0,   419,
     420,     0,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,   421,    30,    31,    32,    33,
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
       0,   110,   111,     0,   112,   113,   114,   115,   116,     0,
       0,     0,   117,   118,   119,   120,   121,   122,   123,   124,
       0,   125,     0,   126,   127,     0,     0,   128,   129,   130,
       0,     0,     0,   131,     0,   132,   133,   134,   135,   136,
       0,   137,     0,   138,     0,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,     0,     0,   150,   151,
     152,     0,   422,     0,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,     0,
     200,   201,   202,     0,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,     0,   251,     1,     2,   252,   253,     0,     3,
       0,     0,     0,     4,     5,     6,     7,     8,     9,    10,
      11,    12,     0,    13,     0,     0,    14,    15,     0,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,     0,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,     0,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,     0,    72,    73,
      74,    75,    76,     0,    77,    78,    79,     0,     0,    80,
      81,     0,     0,     0,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,     0,    92,     0,     0,     0,    93,
       0,    94,    95,    96,    97,     0,    98,     0,     0,     0,
      99,   100,   101,   102,   103,     0,     0,     0,     0,     0,
       0,   104,   105,   106,   107,   108,   109,     0,   110,   111,
       0,   112,   113,   114,   115,   116,     0,     0,     0,   117,
     118,   119,   120,   121,   122,   123,   124,     0,   125,     0,
     126,   127,     0,     0,   128,   129,   130,     0,     0,     0,
     131,     0,   132,   133,   134,   135,   136,     0,   137,     0,
     138,     0,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,     0,     0,   150,   151,   152,     0,   422,
       0,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,     0,   200,   201,   202,
       0,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,     0,
     251,     1,     2,   252,   253,     0,     3,     0,     0,     0,
       4,     5,     6,     7,     8,     9,    10,    11,    12,     0,
      13,     0,     0,    14,   420,     0,    16,    17,    18,    19,
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
     106,   107,   108,   109,     0,   110,   111,     0,   112,   113,
     114,   115,   116,     0,     0,     0,   117,   118,   119,   120,
     121,   122,   123,   124,     0,   125,     0,   126,   127,     0,
       0,   128,   129,   130,     0,     0,     0,   131,     0,   132,
     133,   134,   135,   136,     0,   137,     0,   138,     0,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
       0,     0,   150,   151,   152,     0,   422,     0,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,     0,   200,   201,   202,     0,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,     0,   251,     1,     2,
     252,   253,     0,     3,     0,     0,     0,     4,     5,     6,
       7,     8,     9,    10,    11,    12,     0,    13,     0,     0,
     890,   420,     0,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,   421,    30,    31,    32,
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
     109,     0,   110,   111,     0,   112,   113,   114,   115,   116,
       0,     0,     0,   117,   118,   119,   120,   121,   122,   123,
     124,     0,   125,     0,   126,   127,     0,     0,   128,   129,
     130,     0,     0,     0,   131,     0,   132,   133,   134,   135,
     136,     0,   137,     0,   138,     0,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,     0,     0,   150,
     151,   152,     0,   422,     0,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
       0,   200,   201,   202,     0,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,     0,   251,     1,     2,   252,   253,     0,
       3,     0,     0,     0,     4,     5,     6,     7,     8,     9,
      10,    11,    12,     0,    13,     0,     0,   419,   420,     0,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,  1359,   421,    30,    31,    32,    33,    34,     0,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,     0,    48,    49,    50,  1360,  1361,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,     0,    72,
      73,    74,    75,    76,     0,    77,    78,    79,     0,     0,
      80,    81,     0,     0,     0,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,     0,    92,     0,     0,     0,
      93,     0,    94,    95,    96,    97,     0,    98,     0,     0,
       0,    99,   100,   101,   102,   103,     0,     0,     0,     0,
       0,     0,   104,   105,   106,   107,   108,   109,     0,   110,
     111,     0,   112,   113,   114,   115,   116,     0,     0,     0,
     117,   118,   119,   120,   121,   122,   123,   124,     0,   125,
       0,   126,   127,     0,     0,   128,   129,   130,     0,     0,
       0,   131,     0,   132,   133,   134,   135,   136,     0,   137,
       0,   138,     0,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,     0,     0,   150,   151,   152,     0,
     422,     0,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,  1362,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,     0,   200,   201,
     202,     0,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
       0,   251,     1,     2,   252,   253,     0,     3,     0,     0,
       0,     4,     5,     6,     7,     8,     9,    10,     0,     0,
       0,    13,     0,     0,   419,   420,     0,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,   557,
     421,    30,    31,    32,    33,    34,     0,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
       0,    48,    49,    50,   558,   559,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,     0,    72,    73,    74,    75,
      76,     0,    77,    78,    79,     0,     0,    80,    81,     0,
       0,     0,    82,    83,   510,    85,    86,    87,    88,    89,
     560,    91,     0,    92,     0,     0,     0,    93,     0,    94,
      95,    96,    97,     0,    98,     0,     0,     0,    99,   100,
     101,   102,   103,     0,     0,     0,     0,   943,     0,   104,
     105,   106,   107,   108,   109,     0,   561,   111,     0,   112,
     113,   114,   115,   116,     0,     0,     0,   117,   118,   119,
     120,   121,   122,   123,   124,     0,   125,     0,   126,   127,
       0,     0,   128,   129,   130,     0,     0,     0,   131,   944,
     132,   133,     0,   135,   136,     0,   137,     0,   138,     0,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,     0,     0,   150,   151,   152,     0,   422,     0,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   524,   525,   526,   183,   184,   527,
     563,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,     0,   200,   201,   202,     0,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,     0,   251,     1,
       2,   252,   253,     0,     3,     0,     0,     0,     4,     5,
       6,     7,     8,     9,    10,     0,     0,     0,    13,     0,
       0,   419,   420,     0,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,   557,   421,    30,    31,
      32,    33,    34,     0,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,     0,    48,    49,
      50,   558,   559,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,     0,    72,    73,    74,    75,    76,     0,    77,
      78,    79,     0,     0,    80,    81,     0,     0,     0,    82,
      83,   510,    85,    86,    87,    88,    89,   560,    91,     0,
      92,     0,     0,     0,    93,     0,    94,    95,    96,    97,
       0,    98,     0,     0,     0,    99,   100,   101,   102,   103,
       0,     0,     0,     0,   943,     0,   104,   105,   106,   107,
     108,   109,     0,   561,   111,     0,   112,   113,   114,   115,
     116,     0,     0,     0,   117,   118,   119,   120,   121,   122,
     123,   124,     0,   125,     0,   126,   127,     0,     0,   128,
     129,   130,     0,     0,     0,   131,   949,   132,   133,     0,
     135,   136,     0,   137,     0,   138,     0,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,     0,     0,
     150,   151,   152,     0,   422,     0,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   524,   525,   526,   183,   184,   527,   563,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,     0,   200,   201,   202,     0,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,     0,   251,     1,     2,   252,   253,
       0,     3,     0,     0,     0,     4,     5,     6,     7,     8,
       9,    10,     0,     0,     0,    13,     0,     0,   419,   420,
       0,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,   557,   421,    30,    31,    32,    33,    34,
       0,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,     0,    48,    49,    50,   558,   559,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,     0,
      72,    73,    74,    75,    76,     0,    77,    78,    79,     0,
       0,    80,    81,     0,     0,     0,    82,    83,   510,    85,
      86,    87,    88,    89,   560,    91,     0,    92,     0,     0,
       0,    93,     0,    94,    95,    96,    97,     0,    98,     0,
       0,     0,    99,   100,   101,   102,   103,     0,     0,     0,
       0,     0,     0,   104,   105,   106,   107,   108,   109,     0,
     561,   111,     0,   112,   113,   114,   115,   116,     0,     0,
       0,   117,   118,   119,   120,   121,   122,   123,   124,     0,
     125,     0,   126,   127,     0,     0,   128,   129,   130,     0,
       0,   562,   131,     0,   132,   133,     0,   135,   136,     0,
     137,     0,   138,     0,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,     0,     0,   150,   151,   152,
       0,   422,     0,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   524,   525,
     526,   183,   184,   527,   563,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,     0,   200,
     201,   202,     0,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,     0,   251,     1,     2,   252,   253,     0,     3,     0,
       0,     0,     4,     5,     6,     7,     8,     9,    10,     0,
       0,     0,    13,     0,     0,   419,   420,     0,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
     557,   421,    30,    31,    32,    33,    34,     0,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,     0,    48,    49,    50,   558,   559,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,     0,    72,    73,    74,
      75,    76,     0,    77,    78,    79,     0,     0,    80,    81,
       0,     0,     0,    82,    83,   510,    85,    86,    87,    88,
      89,   560,    91,     0,    92,     0,     0,     0,    93,     0,
      94,    95,    96,    97,     0,    98,     0,     0,     0,    99,
     100,   101,   102,   103,     0,     0,     0,     0,     0,     0,
     104,   105,   106,   107,   108,   109,     0,   561,   111,     0,
     112,   113,   114,   115,   116,     0,     0,     0,   117,   118,
     119,   120,   121,   122,   123,   124,     0,   125,     0,   126,
     127,     0,     0,   128,   129,   130,     0,     0,     0,   131,
     567,   132,   133,     0,   135,   136,     0,   137,     0,   138,
       0,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,     0,     0,   150,   151,   152,     0,   422,     0,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   524,   525,   526,   183,   184,
     527,   563,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,     0,   200,   201,   202,     0,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,     0,   251,
       1,     2,   252,   253,     0,     3,     0,     0,     0,     4,
       5,     6,     7,     8,     9,    10,     0,     0,     0,    13,
       0,     0,   419,   420,     0,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,   557,   421,    30,
      31,    32,    33,    34,     0,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,     0,    48,
      49,    50,   558,   559,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,     0,    72,    73,    74,    75,    76,     0,
      77,    78,    79,     0,     0,    80,    81,     0,     0,     0,
      82,    83,   510,    85,    86,    87,    88,    89,   560,    91,
       0,    92,     0,     0,     0,    93,     0,    94,    95,    96,
      97,     0,    98,     0,     0,     0,    99,   100,   101,   102,
     103,     0,     0,     0,     0,     0,     0,   104,   105,   106,
     107,   108,   109,     0,   561,   111,     0,   112,   113,   114,
     115,   116,     0,     0,     0,   117,   118,   119,   120,   121,
     122,   123,   124,     0,   125,     0,   126,   127,     0,     0,
     128,   129,   130,     0,     0,     0,   131,     0,   132,   133,
       0,   135,   136,     0,   137,     0,   138,     0,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,     0,
       0,   150,   151,   152,     0,   422,     0,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   596,
     168,   597,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   524,   525,   526,   183,   184,   527,   563,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,     0,   200,   201,   202,     0,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,     0,   251,     0,   598,   252,
     253,     1,     2,     0,     0,     0,     3,     0,     0,     0,
       4,     5,     6,     7,     8,     9,    10,     0,     0,     0,
      13,     0,     0,   419,   420,     0,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,   557,   421,
      30,    31,    32,    33,    34,     0,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,     0,
      48,    49,    50,   558,   559,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,     0,    72,    73,    74,    75,    76,
       0,    77,    78,    79,     0,     0,    80,    81,     0,     0,
       0,    82,    83,   510,    85,    86,    87,    88,    89,   560,
      91,     0,    92,     0,     0,     0,    93,     0,    94,    95,
      96,    97,     0,    98,     0,     0,     0,    99,   100,   101,
     102,   103,     0,     0,     0,     0,     0,     0,   104,   105,
     106,   107,   108,   109,     0,   561,   111,     0,   112,   113,
     114,   115,   116,     0,     0,     0,   117,   118,   119,   120,
     121,   122,   123,   124,     0,   125,     0,   126,   127,     0,
       0,   128,   129,   130,     0,     0,     0,   131,     0,   132,
     133,     0,   135,   136,     0,   137,     0,   138,     0,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
       0,     0,   150,   151,   152,     0,   422,     0,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   524,   525,   526,   183,   184,   527,   563,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,     0,   200,   201,   202,     0,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   616,   251,     1,     2,
     252,   253,     0,     3,     0,     0,     0,     4,     5,     6,
       7,     8,     9,    10,     0,     0,     0,    13,     0,     0,
     419,   420,     0,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,   557,   421,    30,    31,    32,
      33,    34,     0,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,     0,    48,    49,    50,
     558,   559,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,     0,    72,    73,    74,    75,    76,     0,    77,    78,
      79,     0,     0,    80,    81,     0,     0,     0,    82,    83,
     510,    85,    86,    87,    88,    89,   560,    91,     0,    92,
       0,     0,     0,    93,     0,    94,    95,    96,    97,     0,
      98,     0,     0,     0,    99,   100,   101,   102,   103,     0,
       0,     0,     0,     0,     0,   104,   105,   106,   107,   108,
     109,     0,   561,   111,     0,   112,   113,   114,   115,   116,
       0,     0,     0,   117,   118,   119,   120,   121,   122,   123,
     124,     0,   125,     0,   126,   127,     0,     0,   128,   129,
     130,     0,     0,     0,   131,     0,   132,   133,     0,   135,
     136,     0,   137,     0,   138,     0,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,     0,     0,   150,
     151,   152,     0,   422,     0,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     524,   525,   526,   183,   184,   527,   563,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
       0,   200,   201,   202,     0,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,     0,   251,   618,     0,   252,   253,     1,
       2,     0,     0,     0,     3,     0,     0,     0,     4,     5,
       6,     7,     8,     9,    10,     0,     0,     0,    13,     0,
       0,   419,   420,     0,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,   557,   421,    30,    31,
      32,    33,    34,     0,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,     0,    48,    49,
      50,   558,   559,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,     0,    72,    73,    74,    75,    76,     0,    77,
      78,    79,     0,     0,    80,    81,     0,     0,     0,    82,
      83,   510,    85,    86,    87,    88,    89,   560,    91,     0,
      92,     0,     0,     0,    93,     0,    94,    95,    96,    97,
       0,    98,     0,     0,     0,    99,   100,   101,   102,   103,
       0,     0,     0,     0,     0,     0,   104,   105,   106,   107,
     108,   109,     0,   561,   111,     0,   112,   113,   114,   115,
     116,     0,     0,     0,   117,   118,   119,   120,   121,   122,
     123,   124,     0,   125,     0,   126,   127,     0,     0,   128,
     129,   130,     0,     0,     0,   131,     0,   132,   133,     0,
     135,   136,     0,   137,     0,   138,     0,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,     0,     0,
     150,   151,   152,     0,   422,     0,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   524,   525,   526,   183,   184,   527,   563,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,     0,   200,   201,   202,     0,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,     0,   251,     0,   620,   252,   253,
       1,     2,     0,     0,     0,     3,     0,     0,     0,     4,
       5,     6,     7,     8,     9,    10,     0,     0,     0,    13,
       0,     0,   419,   420,     0,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,   557,   421,    30,
      31,    32,    33,    34,     0,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,     0,    48,
      49,    50,   558,   559,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,     0,    72,    73,    74,    75,    76,     0,
      77,    78,    79,     0,     0,    80,    81,     0,     0,     0,
      82,    83,   510,    85,    86,    87,    88,    89,   560,    91,
       0,    92,     0,     0,     0,    93,     0,    94,    95,    96,
      97,     0,    98,     0,     0,     0,    99,   100,   101,   102,
     103,     0,     0,     0,     0,     0,     0,   104,   105,   106,
     107,   108,   109,     0,   561,   111,     0,   112,   113,   114,
     115,   116,     0,     0,     0,   117,   118,   119,   120,   121,
     122,   123,   124,     0,   125,     0,   126,   127,     0,     0,
     128,   129,   130,     0,   933,     0,   131,     0,   132,   133,
       0,   135,   136,     0,   137,     0,   138,     0,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,     0,
       0,   150,   151,   152,     0,   422,     0,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   524,   525,   526,   183,   184,   527,   563,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,     0,   200,   201,   202,     0,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,     0,   251,     1,     2,   252,
     253,     0,     3,     0,     0,     0,     4,     5,     6,     7,
       8,     9,    10,     0,     0,     0,    13,     0,     0,   419,
     420,     0,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,   557,   421,    30,    31,    32,    33,
      34,     0,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,     0,    48,    49,    50,   558,
     559,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
       0,    72,    73,    74,    75,    76,     0,    77,    78,    79,
       0,     0,    80,    81,     0,     0,     0,    82,    83,   510,
      85,    86,    87,    88,    89,   560,    91,     0,    92,     0,
       0,     0,    93,     0,    94,    95,    96,    97,     0,    98,
       0,     0,     0,    99,   100,   101,   102,   103,     0,     0,
       0,     0,     0,     0,   104,   105,   106,   107,   108,   109,
       0,   561,   111,     0,   112,   113,   114,   115,   116,     0,
       0,     0,   117,   118,   119,   120,   121,   122,   123,   124,
       0,   125,     0,   126,   127,     0,     0,   128,   129,   130,
       0,     0,     0,   131,  1191,   132,   133,     0,   135,   136,
       0,   137,     0,   138,     0,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,     0,     0,   150,   151,
     152,     0,   422,     0,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   524,
     525,   526,   183,   184,   527,   563,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,     0,
     200,   201,   202,     0,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,     0,   251,     1,     2,   252,   253,     0,     3,
       0,     0,     0,     4,     5,     6,     7,     8,     9,    10,
       0,     0,     0,    13,     0,     0,   419,   420,     0,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,   557,   421,    30,    31,    32,    33,    34,     0,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,     0,    48,    49,    50,   558,   559,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,     0,    72,    73,
      74,    75,    76,     0,    77,    78,    79,     0,     0,    80,
      81,     0,     0,     0,    82,    83,   510,    85,    86,    87,
      88,    89,   560,    91,     0,    92,     0,     0,     0,    93,
       0,    94,    95,    96,    97,     0,    98,     0,     0,     0,
      99,   100,   101,   102,   103,     0,     0,     0,     0,  1454,
       0,   104,   105,   106,   107,   108,   109,     0,   561,   111,
       0,   112,   113,   114,   115,   116,     0,     0,     0,   117,
     118,   119,   120,   121,   122,   123,   124,     0,   125,     0,
     126,   127,     0,     0,   128,   129,   130,     0,     0,     0,
     131,     0,   132,   133,     0,   135,   136,     0,   137,     0,
     138,     0,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,     0,     0,   150,   151,   152,     0,   422,
       0,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   524,   525,   526,   183,
     184,   527,   563,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,     0,   200,   201,   202,
       0,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,     0,
     251,     1,     2,   252,   253,     0,     3,     0,     0,     0,
       4,     5,     6,     7,     8,     9,    10,     0,     0,     0,
      13,     0,     0,   419,   420,     0,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,   557,   421,
      30,    31,    32,    33,    34,     0,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,     0,
      48,    49,    50,   558,   559,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,     0,    72,    73,    74,    75,    76,
       0,    77,    78,    79,     0,     0,    80,    81,     0,     0,
       0,    82,    83,   510,    85,    86,    87,    88,    89,   560,
      91,     0,    92,     0,     0,     0,    93,     0,    94,    95,
      96,    97,     0,    98,     0,     0,     0,    99,   100,   101,
     102,   103,     0,     0,     0,     0,     0,     0,   104,   105,
     106,   107,   108,   109,     0,   561,   111,     0,   112,   113,
     114,   115,   116,     0,     0,     0,   117,   118,   119,   120,
     121,   122,   123,   124,     0,   125,     0,   126,   127,     0,
       0,   128,   129,   130,     0,     0,     0,   131,     0,   132,
     133,     0,   135,   136,     0,   137,     0,   138,     0,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
       0,     0,   150,   151,   152,     0,   422,     0,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   524,   525,   526,   183,   184,   527,   563,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,     0,   200,   201,   202,     0,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,     0,   251,     1,     2,
     252,   253,     0,     3,     0,     0,     0,     4,     5,     6,
       7,     8,     9,    10,     0,     0,     0,    13,     0,     0,
     419,   420,     0,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,   557,   421,    30,    31,    32,
      33,    34,     0,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,     0,    48,    49,    50,
     558,   559,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,     0,    72,    73,    74,    75,    76,     0,    77,    78,
      79,     0,     0,    80,    81,     0,     0,     0,    82,    83,
     510,    85,    86,    87,    88,    89,  1137,    91,     0,    92,
       0,     0,     0,    93,     0,    94,    95,    96,    97,     0,
      98,     0,     0,     0,    99,   100,   101,   102,   103,     0,
       0,     0,     0,     0,     0,   104,   105,   106,   107,   108,
     109,     0,   561,   111,     0,   112,   113,   114,   115,   116,
       0,     0,     0,   117,   118,   119,   120,   121,   122,   123,
     124,     0,   125,     0,   126,   127,     0,     0,   128,   129,
     130,     0,     0,     0,   131,     0,   132,   133,     0,   135,
     136,     0,   137,     0,   138,     0,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,     0,     0,   150,
     151,   152,     0,   422,     0,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     524,   525,   526,   183,   184,   527,   563,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
       0,   200,   201,   202,     0,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,     0,   251,     1,     2,   252,   253,     0,
       3,     0,     0,     0,     4,     5,     6,     7,     8,     9,
      10,     0,     0,     0,    13,     0,     0,   419,   420,     0,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,   557,   421,    30,    31,    32,    33,    34,     0,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,     0,    48,    49,    50,   558,   559,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,     0,    72,
      73,    74,    75,    76,     0,    77,    78,    79,     0,     0,
      80,    81,     0,     0,     0,    82,    83,   510,    85,    86,
      87,    88,    89,   560,    91,     0,    92,     0,     0,     0,
      93,     0,    94,    95,    96,    97,     0,    98,     0,     0,
       0,    99,   100,   101,   102,   103,     0,     0,     0,     0,
       0,     0,   104,   105,   106,   107,   108,   109,     0,   561,
     111,     0,     0,   113,   114,   115,   116,     0,     0,     0,
     117,   118,   119,   120,   121,   122,   123,   124,     0,   125,
       0,   126,   127,     0,     0,   128,   129,   130,     0,     0,
       0,   131,     0,   132,   133,     0,   135,   136,     0,   137,
       0,   138,     0,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,     0,     0,   150,   151,   152,     0,
     422,     0,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   524,   525,   526,
     183,   184,   527,   563,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,     0,   200,   201,
     202,     0,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
       0,   251,     1,     2,   252,   253,     0,     3,     0,     0,
       0,     4,     5,     6,     7,     8,     9,    10,     0,     0,
       0,    13,     0,     0,   419,   420,     0,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,   496,    27,   498,
     421,    30,   499,    32,    33,    34,     0,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,   501,
       0,    48,    49,    50,   503,   504,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,     0,    72,    73,    74,    75,
      76,     0,    77,    78,    79,     0,     0,    80,    81,     0,
       0,     0,    82,    83,   510,    85,    86,    87,    88,    89,
     560,    91,     0,    92,     0,     0,     0,    93,     0,    94,
      95,    96,    97,     0,    98,     0,     0,     0,   513,   100,
     101,   102,   103,     0,     0,     0,     0,     0,     0,   104,
     105,   106,   107,   108,   109,     0,   561,   111,     0,   112,
     113,   694,   115,   116,     0,     0,     0,   117,   118,   119,
     120,   121,   122,   123,   124,     0,   125,     0,   695,   127,
       0,     0,   128,   129,   130,     0,     0,     0,   131,     0,
     132,   133,     0,   135,   136,     0,   137,     0,   138,     0,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,     0,     0,   150,   151,   152,     0,   422,     0,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
       0,   167,     0,   169,     0,     0,   172,   173,   174,   175,
     176,   177,   523,   179,   524,   525,   526,   183,   184,   527,
     528,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   529,     0,   200,   530,   202,     0,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,     0,   251,     1,
       2,     0,   253,     0,     3,     0,     0,     0,     4,     5,
       6,     7,     8,     9,    10,     0,     0,     0,    13,     0,
       0,   419,   420,     0,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,   496,    27,   498,   421,    30,   499,
      32,    33,    34,     0,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,   501,     0,    48,    49,
      50,   503,   504,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,     0,    72,    73,    74,    75,    76,     0,    77,
      78,    79,     0,     0,    80,    81,     0,     0,     0,    82,
      83,   510,    85,    86,    87,    88,    89,   560,    91,     0,
      92,     0,     0,     0,    93,     0,    94,    95,    96,    97,
       0,    98,     0,     0,     0,   513,   100,   101,   102,   103,
       0,     0,     0,     0,     0,     0,   104,   105,   106,   107,
     108,   109,     0,   561,   111,     0,   112,   113,   114,   115,
     116,     0,     0,     0,   117,   118,   119,   120,   121,   122,
     123,   124,     0,   125,     0,   126,   127,     0,     0,   128,
     129,   130,     0,     0,     0,   131,     0,   132,   133,     0,
     135,   136,     0,   137,     0,   138,     0,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,     0,     0,
     150,   151,   152,     0,   422,     0,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,     0,   167,     0,
     169,     0,     0,   172,   173,   174,   175,   176,   177,   523,
     179,   524,   525,   526,   183,   184,   527,   528,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     529,     0,   200,   201,   202,     0,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,     0,   251,     1,     2,     0,   253,
       0,     3,     0,     0,     0,     4,     5,     6,     7,     8,
       9,    10,     0,     0,     0,    13,     0,     0,   419,   420,
       0,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,   496,    27,   498,   421,    30,   499,    32,    33,    34,
       0,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,   501,     0,    48,    49,    50,   503,   504,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,     0,
      72,    73,    74,    75,    76,     0,    77,    78,    79,     0,
       0,    80,    81,     0,     0,     0,    82,    83,   510,    85,
      86,    87,    88,    89,   560,    91,     0,    92,     0,     0,
       0,    93,     0,    94,    95,    96,    97,     0,    98,     0,
       0,     0,   513,   100,   101,   102,   103,     0,     0,     0,
       0,     0,     0,   104,   105,   106,   107,   108,   109,     0,
     561,   111,     0,   112,   113,   114,   115,   116,     0,     0,
       0,   117,   118,   119,   120,   121,   122,   123,   124,     0,
     125,     0,   126,   127,     0,     0,   128,   129,   130,     0,
       0,     0,   131,     0,   132,   133,     0,   135,   136,     0,
     137,     0,   138,     0,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,     0,     0,   150,   151,   152,
       0,   422,     0,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,     0,   167,     0,   169,     0,     0,
     172,   173,   174,   175,   176,   177,   523,   179,   524,   525,
     526,   183,   184,   527,   528,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   529,     0,   200,
     530,   202,     0,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,     0,   251,     1,     2,     0,   253,     0,     3,     0,
       0,     0,     4,     5,     6,     7,     8,     9,    10,     0,
       0,     0,    13,     0,     0,   419,   420,     0,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,   496,    27,
     498,   421,    30,   499,    32,    33,    34,     0,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
     501,     0,    48,    49,    50,   503,   504,    53,   505,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,     0,    72,    73,    74,
      75,    76,     0,    77,    78,    79,     0,     0,    80,    81,
       0,     0,     0,    82,    83,   510,    85,    86,    87,    88,
      89,   560,    91,     0,    92,     0,     0,     0,    93,     0,
      94,    95,    96,    97,     0,    98,     0,     0,     0,   513,
     100,   101,   102,   103,     0,     0,     0,     0,     0,     0,
     104,   105,   106,   107,   108,   109,     0,   561,   111,     0,
     112,   113,     0,   115,   116,     0,     0,     0,   117,   118,
     119,   120,   121,   122,   123,   124,     0,   125,     0,     0,
       0,     0,     0,   128,   129,   130,     0,     0,     0,   131,
       0,   132,   133,     0,   135,   136,     0,   137,     0,   138,
       0,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,     0,     0,   150,   151,   152,     0,   422,     0,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,     0,   167,     0,   169,     0,     0,   172,   173,   174,
     175,   176,   177,   523,   179,   524,   525,   526,   183,   184,
     527,   528,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   529,     0,   200,   530,   202,     0,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,     0,   251,
       1,     2,     0,   253,     0,     3,     0,     0,     0,     4,
       5,     6,     7,     8,     9,    10,     0,     0,     0,    13,
       0,     0,   419,   420,     0,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,   496,    27,   498,   421,    30,
     499,    32,    33,    34,     0,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,   501,     0,    48,
      49,    50,   503,   504,    53,   505,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,     0,    72,    73,    74,    75,    76,     0,
      77,    78,    79,     0,     0,    80,    81,     0,     0,     0,
      82,    83,   510,    85,    86,    87,    88,    89,   560,    91,
       0,    92,     0,     0,     0,    93,     0,    94,    95,    96,
      97,     0,    98,     0,     0,     0,   513,   100,   101,   102,
     103,     0,     0,     0,     0,     0,     0,   104,   105,   106,
     107,   108,   109,     0,   561,   111,     0,   112,   113,     0,
     115,   116,     0,     0,     0,   117,   118,   119,   120,   121,
     122,   123,   124,     0,   125,     0,     0,     0,     0,     0,
     128,   129,   130,     0,     0,     0,   131,     0,   132,   133,
       0,     0,     0,     0,   137,     0,   138,     0,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,     0,
       0,   150,   151,   152,     0,   422,     0,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,     0,   167,
       0,   169,     0,     0,   172,   173,   174,   175,   176,   177,
     523,   179,   524,   525,   526,   183,   184,   527,   528,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   529,     0,   200,   530,   202,     0,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,     0,   251,     1,     2,     0,
     253,     0,     3,     0,     0,     0,     4,     5,     6,     7,
       8,     9,    10,     0,     0,     0,    13,     0,     0,   419,
     420,     0,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,   496,    27,   498,   421,    30,   499,    32,    33,
      34,     0,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,   501,     0,    48,    49,    50,   503,
     504,    53,   505,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
       0,    72,    73,    74,    75,    76,     0,    77,    78,    79,
       0,     0,    80,    81,     0,     0,     0,    82,    83,   510,
      85,    86,    87,    88,    89,   560,    91,     0,    92,     0,
       0,     0,    93,     0,    94,    95,    96,    97,     0,    98,
       0,     0,     0,   513,     0,   101,   102,   103,     0,     0,
       0,     0,     0,     0,   104,   105,   106,   107,     0,   109,
       0,   561,   111,     0,   112,   113,     0,   115,   116,     0,
       0,     0,   117,   118,   119,   120,   121,   122,   123,   124,
       0,   125,     0,     0,     0,     0,     0,   128,   129,   130,
       0,     0,     0,   131,     0,   132,   133,     0,     0,     0,
       0,   137,     0,   138,     0,   139,     0,   141,     0,   143,
     144,   145,   146,   147,   148,   149,     0,     0,   150,   151,
     152,     0,   422,     0,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,     0,   167,     0,   169,     0,
       0,   172,   173,   174,   175,   176,   177,   523,   179,   524,
     525,   526,   183,   184,   527,   528,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   529,     0,
     200,   530,   202,     0,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,     0,   251,     1,     2,     0,   253,     0,     3,
       0,     0,     0,     4,     5,     6,     7,     8,     9,    10,
       0,     0,     0,    13,     0,     0,   419,   420,     0,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,   557,   421,     0,    31,    32,    33,    34,     0,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,     0,    48,    49,    50,   558,   559,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,     0,     0,    72,    73,
      74,    75,    76,     0,    77,     0,     0,     0,     0,    80,
      81,     0,     0,     0,    82,    83,   510,    85,    86,    87,
      88,     0,   560,    91,     0,    92,     0,     0,     0,    93,
       0,    94,    95,    96,    97,     0,    98,     0,     0,     0,
      99,     0,   101,   102,   103,     0,     0,     0,     0,     0,
       0,     0,   105,   106,   107,     0,   109,     0,   561,     0,
       0,  -618,   113,     0,     0,   116,     0,     0,     0,   117,
     118,   119,   120,   121,   122,   123,   124,     0,   125,     0,
       0,   127,     0,     0,   128,   129,   130,     0,     0,     0,
     131,     0,   132,   133,     0,     0,     0,     0,     0,     0,
     138,     0,   139,     0,   141,     0,   143,   144,   145,   146,
     147,   148,   149,     0,     0,   150,   151,   152,     0,   422,
       0,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   524,   525,   526,   183,
     184,   527,   563,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,     0,   200,   201,   202,
       0,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,     0,
     251,     1,     2,   252,   253,     0,     3,     0,     0,     0,
       4,     5,     6,     7,     8,     9,    10,     0,     0,     0,
      13,     0,     0,   419,   420,     0,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,   557,   421,
       0,    31,    32,    33,    34,     0,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,     0,
      48,    49,    50,   558,   559,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,     0,     0,    72,    73,    74,    75,    76,
       0,    77,     0,     0,     0,     0,    80,    81,     0,     0,
       0,    82,    83,   510,    85,    86,    87,    88,     0,   560,
      91,     0,    92,     0,     0,     0,    93,     0,    94,    95,
      96,    97,     0,    98,     0,     0,     0,    99,     0,   101,
     102,   103,     0,     0,     0,     0,     0,     0,     0,   105,
     106,   107,     0,   109,     0,   561,     0,     0,     0,   113,
       0,     0,   116,     0,     0,     0,   117,   118,   119,   120,
     121,   122,   123,   124,     0,   125,     0,     0,   127,     0,
       0,   128,   129,   130,     0,     0,     0,   131,     0,   132,
     133,     0,     0,     0,     0,     0,     0,   138,     0,   139,
       0,   141,     0,   143,   144,   145,   146,   147,   148,   149,
       0,     0,   150,   151,   152,     0,   422,     0,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   524,   525,   526,   183,   184,   527,   563,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,     0,   200,   201,   202,     0,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,     0,   251,     1,     2,
     252,   253,     0,     3,     0,     0,     0,     4,     5,     6,
       7,     8,     9,    10,     0,     0,     0,    13,     0,     0,
     419,   420,     0,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,   496,    27,   498,   421,    30,   499,    32,
      33,    34,     0,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,   501,     0,    48,    49,    50,
     503,   504,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,     0,    72,    73,    74,    75,    76,     0,    77,    78,
      79,     0,     0,    80,    81,     0,     0,     0,    82,    83,
     510,    85,    86,    87,    88,     0,   560,    91,     0,    92,
       0,     0,     0,    93,     0,    94,    95,    96,    97,     0,
      98,     0,     0,     0,   513,     0,   101,   102,   103,     0,
       0,     0,     0,     0,     0,     0,   105,   106,   107,     0,
     109,     0,   561,     0,     0,     0,   113,     0,     0,   116,
       0,     0,     0,   117,   118,   119,   120,   121,   122,   123,
     124,     0,   125,     0,     0,   127,     0,     0,   128,   129,
     130,     0,     0,     0,   131,     0,   132,   133,     0,     0,
       0,     0,     0,     0,   138,     0,   139,     0,   141,     0,
     143,   144,   145,   146,   147,   148,   149,     0,     0,   150,
     151,   152,     0,   422,     0,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,     0,   167,     0,   169,
       0,     0,   172,   173,   174,   175,   176,   177,   523,   179,
     524,   525,   526,   183,   184,   527,   528,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   529,
       0,   200,   201,   202,     0,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,     0,   251,     1,     2,     0,   253,     0,
       3,     0,     0,     0,     4,     0,     0,     0,     0,     9,
      10,     0,     0,     0,     0,     0,     0,   419,   420,     0,
      16,    17,    18,   493,    20,    21,    22,   494,    24,   495,
     496,   497,   498,   421,    30,   499,    32,    33,    34,     0,
      35,    36,    37,    38,   500,    40,    41,    42,    43,    44,
      45,    46,   501,     0,    48,   502,    50,   503,   504,    53,
     505,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,   506,   507,    71,     0,    72,
      73,    74,   508,     0,     0,    77,    78,    79,     0,     0,
     509,    81,     0,     0,     0,     0,    83,   510,    85,   511,
     512,    88,    89,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    94,    95,    96,    97,     0,    98,     0,     0,
       0,   513,   100,   101,   514,   515,     0,     0,     0,     0,
       0,     0,   104,   105,   106,     0,   108,   109,     0,     0,
       0,     0,     0,     0,     0,   115,   516,     0,     0,     0,
     117,   118,   119,   120,   517,   122,   123,   518,     0,     0,
       0,     0,     0,     0,     0,   519,   520,   130,     0,     0,
       0,   131,     0,   132,   521,     0,     0,     0,     0,   137,
       0,   138,     0,   139,   140,   141,   142,   522,   144,   145,
     146,   147,   148,   149,     0,     0,   150,   151,     0,     0,
     422,     0,   155,   156,     0,     0,     0,   160,   161,   162,
     163,   164,   165,     0,   167,     0,   169,     0,     0,   172,
     173,   174,   175,   176,   177,   523,   179,   524,   525,   526,
     183,   184,   527,   528,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   529,     0,   200,   530,
     202,     0,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,     1,
       2,     0,     0,     0,     3,   253,     0,     0,     4,     0,
       0,     0,     0,     9,    10,     0,     0,     0,     0,     0,
       0,   419,   420,     0,    16,    17,    18,   538,    20,    21,
      22,   494,   539,   540,   496,   497,   498,   421,    30,   499,
      32,   541,    34,     0,    35,    36,    37,    38,   542,    40,
     543,   544,    43,    44,    45,    46,   501,     0,    48,   545,
      50,   503,   504,    53,   505,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,   506,
     507,    71,     0,    72,    73,    74,   546,     0,     0,    77,
      78,    79,     0,     0,   509,    81,     0,     0,     0,     0,
      83,   510,    85,   511,   512,    88,    89,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    94,    95,    96,    97,
       0,    98,     0,     0,     0,   513,   100,   101,   514,   515,
       0,     0,     0,     0,     0,     0,   104,   105,   106,     0,
     108,   109,     0,     0,     0,     0,     0,     0,     0,   115,
     516,     0,     0,     0,   117,   118,   119,   120,   517,   122,
     123,   518,     0,     0,     0,     0,     0,     0,     0,   519,
     520,   130,     0,     0,     0,   131,     0,   132,   521,     0,
       0,     0,     0,   137,     0,   138,     0,   139,   140,   141,
     142,   522,   144,   145,   146,   147,   148,   149,     0,     0,
     150,   151,     0,     0,   422,     0,   155,   156,     0,     0,
       0,   160,   161,   162,   163,   164,   165,     0,   547,     0,
     169,     0,     0,   172,   173,   174,   175,   176,   177,   523,
     179,   524,   525,   526,   183,   184,   527,   528,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     529,     0,   200,   530,   202,     0,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,     3,     0,     0,     0,     0,     0,   253,
       0,     0,     9,    10,     0,     0,     0,     0,     0,     0,
     419,   420,     0,    16,    17,    18,   493,    20,    21,    22,
     494,    24,   495,   496,  1162,   498,   421,    30,   499,    32,
      33,    34,     0,    35,    36,    37,    38,   500,    40,    41,
      42,    43,    44,    45,    46,   501,     0,    48,   502,    50,
     503,   504,    53,   505,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,   506,   507,
      71,     0,    72,    73,    74,   508,     0,     0,    77,    78,
      79,     0,     0,   509,    81,     0,     0,     0,     0,    83,
     510,    85,   511,   512,    88,    89,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    94,    95,    96,    97,     0,
      98,     0,     0,     0,   513,   100,   101,   514,   515,     0,
       0,     0,     0,     0,     0,   104,   105,   106,     0,   108,
     109,  1163,     0,     0,     0,  1164,     0,     0,   115,   516,
       0,     0,     0,   117,   118,   119,   120,   517,   122,   123,
     518,     0,     0,     0,     0,     0,     0,     0,   519,   520,
     130,     0,     0,     0,   131,  1611,   132,   521,     0,     0,
       0,     0,  1612,     0,   138,     0,   139,   140,   141,   142,
     522,   144,   145,   146,   147,   148,   149,     0,     0,  1165,
     151,     0,     0,   422,     0,   155,   156,  1166,     0,     0,
     160,   161,   162,   163,   164,   165,     0,   167,     0,   169,
       0,     0,   172,   173,   174,   175,   176,   177,   523,   179,
     524,   525,   526,   183,   184,   527,   528,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   529,
       0,   200,   530,   202,     0,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,     0,     0,     3,     0,     0,     0,   253,  1167,
    1168,  1169,  1170,     9,    10,     0,     0,     0,     0,     0,
       0,   419,   420,     0,    16,    17,    18,   493,    20,    21,
      22,   494,    24,   495,   496,  1162,   498,   421,    30,   499,
      32,    33,    34,     0,    35,    36,    37,    38,   500,    40,
      41,    42,    43,    44,    45,    46,   501,     0,    48,   502,
      50,   503,   504,    53,   505,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,   506,
     507,    71,     0,    72,    73,    74,   508,     0,     0,    77,
      78,    79,     0,     0,   509,    81,     0,     0,     0,     0,
      83,   510,    85,   511,   512,    88,    89,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    94,    95,    96,    97,
       0,    98,     0,     0,     0,   513,   100,   101,   514,   515,
       0,     0,     0,     0,     0,     0,   104,   105,   106,     0,
     108,   109,  1163,     0,     0,     0,  1206,     0,     0,   115,
     516,     0,     0,     0,   117,   118,   119,   120,   517,   122,
     123,   518,     0,     0,     0,     0,     0,     0,     0,   519,
     520,   130,     0,     0,     0,   131,  1441,   132,   521,     0,
       0,     0,     0,     0,     0,   138,     0,   139,   140,   141,
     142,   522,   144,   145,   146,   147,   148,   149,     0,     0,
     150,   151,     0,     0,   422,     0,   155,   156,  1166,     0,
       0,   160,   161,   162,   163,   164,   165,     0,   167,     0,
     169,     0,     0,   172,   173,   174,   175,   176,   177,   523,
     179,   524,   525,   526,   183,   184,   527,   528,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     529,     0,   200,   530,   202,     0,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,     0,     0,     3,     0,     0,     0,   253,
    1167,  1168,  1169,  1170,     9,    10,     0,     0,     0,     0,
       0,     0,   419,   420,     0,    16,    17,    18,   493,    20,
      21,    22,   494,    24,   495,   496,  1162,   498,   421,    30,
     499,    32,    33,    34,     0,    35,    36,    37,    38,   500,
      40,    41,    42,    43,    44,    45,    46,   501,     0,    48,
     502,    50,   503,   504,    53,   505,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
     506,   507,    71,     0,    72,    73,    74,   508,     0,     0,
      77,    78,    79,     0,     0,   509,    81,     0,     0,     0,
       0,    83,   510,    85,   511,   512,    88,    89,  1515,     0,
       0,     0,     0,     0,     0,     0,     0,    94,    95,    96,
      97,     0,    98,     0,     0,     0,   513,   100,   101,   514,
     515,     0,     0,     0,     0,     0,     0,   104,   105,   106,
       0,   108,   109,  1163,     0,     0,     0,  1164,     0,     0,
     115,   516,     0,     0,     0,   117,   118,   119,   120,   517,
     122,   123,   518,     0,     0,     0,     0,     0,     0,     0,
     519,   520,   130,     0,     0,     0,   131,     0,   132,   521,
       0,     0,     0,     0,     0,     0,   138,     0,   139,   140,
     141,   142,   522,   144,   145,   146,   147,   148,   149,     0,
       0,  1165,   151,     0,     0,   422,     0,   155,   156,  1166,
       0,     0,   160,   161,   162,   163,   164,   165,     0,   167,
       0,   169,     0,     0,   172,   173,   174,   175,   176,   177,
     523,   179,   524,   525,   526,   183,   184,   527,   528,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   529,     0,   200,   530,   202,     0,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,     0,     0,     3,     0,     0,     0,
     253,  1167,  1168,  1169,  1170,     9,    10,     0,     0,     0,
       0,     0,     0,   419,   420,     0,    16,    17,    18,   493,
      20,    21,    22,   494,    24,   495,   496,  1162,   498,   421,
      30,   499,    32,    33,    34,     0,    35,    36,    37,    38,
     500,    40,    41,    42,    43,    44,    45,    46,   501,     0,
      48,   502,    50,   503,   504,    53,   505,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,   506,   507,    71,     0,    72,    73,    74,   508,     0,
       0,    77,    78,    79,     0,     0,   509,    81,     0,     0,
       0,     0,    83,   510,    85,   511,   512,    88,    89,  1664,
       0,     0,     0,     0,     0,     0,     0,     0,    94,    95,
      96,    97,     0,    98,     0,     0,     0,   513,   100,   101,
     514,   515,     0,     0,     0,     0,     0,     0,   104,   105,
     106,     0,   108,   109,  1163,     0,     0,     0,  1164,     0,
       0,   115,   516,     0,     0,     0,   117,   118,   119,   120,
     517,   122,   123,   518,     0,     0,     0,     0,     0,     0,
       0,   519,   520,   130,     0,     0,     0,   131,     0,   132,
     521,     0,     0,     0,     0,     0,     0,   138,     0,   139,
     140,   141,   142,   522,   144,   145,   146,   147,   148,   149,
       0,     0,  1165,   151,     0,     0,   422,     0,   155,   156,
    1166,     0,     0,   160,   161,   162,   163,   164,   165,     0,
     167,     0,   169,     0,     0,   172,   173,   174,   175,   176,
     177,   523,   179,   524,   525,   526,   183,   184,   527,   528,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   529,     0,   200,   530,   202,     0,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,     0,     0,     3,     0,     0,
       0,   253,  1167,  1168,  1169,  1170,     9,    10,     0,     0,
       0,     0,     0,     0,   419,   420,     0,    16,    17,    18,
     493,    20,    21,    22,   494,    24,   495,   496,  1162,   498,
     421,    30,   499,    32,    33,    34,     0,    35,    36,    37,
      38,   500,    40,    41,    42,    43,    44,    45,    46,   501,
       0,    48,   502,    50,   503,   504,    53,   505,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,   506,   507,    71,     0,    72,    73,    74,   508,
       0,     0,    77,    78,    79,     0,     0,   509,    81,     0,
       0,     0,     0,    83,   510,    85,   511,   512,    88,    89,
    1668,     0,     0,     0,     0,     0,     0,     0,     0,    94,
      95,    96,    97,     0,    98,     0,     0,     0,   513,   100,
     101,   514,   515,     0,     0,     0,     0,     0,     0,   104,
     105,   106,     0,   108,   109,  1163,     0,     0,     0,  1164,
       0,     0,   115,   516,     0,     0,     0,   117,   118,   119,
     120,   517,   122,   123,   518,     0,     0,     0,     0,     0,
       0,     0,   519,   520,   130,     0,     0,     0,   131,     0,
     132,   521,     0,     0,     0,     0,     0,     0,   138,     0,
     139,   140,   141,   142,   522,   144,   145,   146,   147,   148,
     149,     0,     0,  1165,   151,     0,     0,   422,     0,   155,
     156,  1166,     0,     0,   160,   161,   162,   163,   164,   165,
       0,   167,     0,   169,     0,     0,   172,   173,   174,   175,
     176,   177,   523,   179,   524,   525,   526,   183,   184,   527,
     528,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   529,     0,   200,   530,   202,     0,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,     0,     0,     3,     0,
       0,     0,   253,  1167,  1168,  1169,  1170,     9,    10,     0,
       0,     0,     0,     0,     0,   419,   420,     0,    16,    17,
      18,   493,    20,    21,    22,   494,    24,   495,   496,  1162,
     498,   421,    30,   499,    32,    33,    34,     0,    35,    36,
      37,    38,   500,    40,    41,    42,    43,    44,    45,    46,
     501,     0,    48,   502,    50,   503,   504,    53,   505,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,   506,   507,    71,     0,    72,    73,    74,
     508,     0,     0,    77,    78,    79,     0,     0,   509,    81,
       0,     0,     0,     0,    83,   510,    85,   511,   512,    88,
      89,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      94,    95,    96,    97,     0,    98,     0,     0,     0,   513,
     100,   101,   514,   515,     0,     0,     0,     0,     0,     0,
     104,   105,   106,     0,   108,   109,  1163,     0,     0,     0,
    1164,     0,     0,   115,   516,     0,     0,     0,   117,   118,
     119,   120,   517,   122,   123,   518,     0,     0,     0,     0,
       0,     0,     0,   519,   520,   130,     0,     0,     0,   131,
       0,   132,   521,     0,     0,     0,     0,     0,     0,   138,
       0,   139,   140,   141,   142,   522,   144,   145,   146,   147,
     148,   149,     0,     0,  1165,   151,     0,     0,   422,     0,
     155,   156,  1166,     0,     0,   160,   161,   162,   163,   164,
     165,     0,   167,     0,   169,     0,     0,   172,   173,   174,
     175,   176,   177,   523,   179,   524,   525,   526,   183,   184,
     527,   528,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   529,     0,   200,   530,   202,     0,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,     0,     0,     3,
       0,     0,     0,   253,  1167,  1168,  1169,  1170,     9,    10,
       0,     0,     0,     0,     0,     0,   419,   420,     0,    16,
      17,    18,   493,    20,    21,    22,   494,    24,   495,   496,
    1162,   498,   421,    30,   499,    32,    33,    34,     0,    35,
      36,    37,    38,   500,    40,    41,    42,    43,    44,    45,
      46,   501,     0,    48,   502,    50,   503,   504,    53,   505,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,   506,   507,    71,     0,    72,    73,
      74,   508,     0,     0,    77,    78,    79,     0,     0,   509,
      81,     0,     0,     0,     0,    83,   510,    85,   511,   512,
      88,    89,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    94,    95,    96,    97,     0,    98,     0,     0,     0,
     513,   100,   101,   514,   515,     0,     0,     0,     0,     0,
       0,   104,   105,   106,     0,   108,   109,  1163,     0,     0,
       0,  1206,     0,     0,   115,   516,     0,     0,     0,   117,
     118,   119,   120,   517,   122,   123,   518,     0,     0,     0,
       0,     0,     0,     0,   519,   520,   130,     0,     0,     0,
     131,     0,   132,   521,     0,     0,     0,     0,     0,     0,
     138,     0,   139,   140,   141,   142,   522,   144,   145,   146,
     147,   148,   149,     0,     0,   150,   151,     0,     0,   422,
       0,   155,   156,  1166,     0,     0,   160,   161,   162,   163,
     164,   165,     0,   167,     0,   169,     0,     0,   172,   173,
     174,   175,   176,   177,   523,   179,   524,   525,   526,   183,
     184,   527,   528,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   529,     0,   200,   530,   202,
       0,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,     0,     0,
       3,     0,     0,     0,   253,  1167,  1168,  1169,  1170,     9,
      10,     0,     0,     0,    13,     0,     0,   419,   420,     0,
      16,    17,    18,   538,    20,    21,    22,   494,   539,   540,
     496,   497,   498,   421,    30,   499,    32,   541,    34,     0,
      35,    36,    37,    38,   542,    40,   543,   544,    43,    44,
      45,    46,   501,     0,    48,   545,    50,   503,   504,    53,
     505,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,   506,   507,    71,     0,    72,
      73,    74,   546,     0,     0,    77,    78,    79,     0,     0,
     509,    81,     0,     0,     0,     0,    83,   510,    85,   511,
     512,    88,    89,   560,     0,     0,     0,     0,     0,     0,
       0,     0,    94,    95,    96,    97,     0,    98,     0,     0,
       0,   513,   100,   101,   514,   515,     0,     0,     0,     0,
       0,     0,   104,   105,   106,     0,   108,   109,     0,     0,
       0,     0,   939,     0,     0,   115,   516,     0,     0,     0,
     117,   118,   119,   120,   517,   122,   123,   518,     0,     0,
       0,     0,     0,     0,     0,   519,   520,   130,     0,     0,
       0,   131,     0,   132,   521,     0,     0,     0,     0,     0,
       0,   138,     0,   139,   140,   141,   142,   522,   144,   145,
     146,   147,   148,   149,     0,     0,   150,   151,     0,     0,
     422,     0,   155,   156,     0,     0,     0,   160,   161,   162,
     163,   164,   165,     0,   547,     0,   169,     0,     0,   172,
     173,   174,   175,   176,   177,   523,   179,   524,   525,   526,
     183,   184,   527,   528,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   529,     0,   200,   530,
     202,     0,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,     3,
       0,   574,   575,     0,     0,   253,     0,     0,     9,    10,
       0,     0,     0,     0,     0,     0,   419,   420,     0,    16,
      17,    18,   538,    20,    21,    22,   494,   539,   540,   496,
     497,   498,   421,    30,   499,    32,   541,    34,     0,    35,
      36,    37,    38,   542,    40,   543,   544,    43,    44,    45,
      46,   501,     0,    48,   545,    50,   503,   504,    53,   505,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,   506,   507,    71,     0,    72,    73,
      74,   546,     0,     0,    77,    78,    79,     0,     0,   509,
      81,     0,     0,     0,     0,    83,   510,    85,   511,   512,
      88,    89,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    94,    95,    96,    97,     0,    98,     0,     0,     0,
     513,   100,   101,   514,   515,     0,     0,     0,     0,     0,
       0,   104,   105,   106,     0,   108,   109,     0,     0,     0,
       0,     0,     0,     0,   115,   516,     0,     0,     0,   117,
     118,   119,   120,   517,   122,   123,   518,     0,     0,     0,
       0,     0,     0,     0,   519,   520,   130,     0,     0,     0,
     131,     0,   132,   521,     0,     0,     0,     0,     0,     0,
     138,     0,   139,   140,   141,   142,   522,   144,   145,   146,
     147,   148,   149,     0,     0,   150,   151,     0,     0,   422,
       0,   155,   156,     0,     0,     0,   160,   161,   162,   163,
     164,   165,     0,   547,     0,   169,     0,     0,   172,   173,
     174,   175,   176,   177,   523,   179,   524,   525,   526,   183,
     184,   527,   528,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   529,     0,   200,   530,   202,
       0,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,     3,     0,
       0,     0,     0,     0,   253,     0,     0,     9,    10,     0,
       0,     0,     0,     0,     0,   419,   420,     0,    16,    17,
      18,   538,    20,    21,    22,   494,   539,   540,   496,   497,
     498,   421,    30,   499,    32,   541,    34,     0,    35,    36,
      37,    38,   542,    40,   543,   544,    43,    44,    45,    46,
     501,     0,    48,   545,    50,   503,   504,    53,   505,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,   506,   507,    71,     0,    72,    73,    74,
     546,     0,     0,    77,    78,    79,     0,     0,   509,    81,
       0,     0,     0,     0,    83,   510,    85,   511,   512,    88,
      89,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      94,    95,    96,    97,     0,    98,     0,     0,     0,   513,
     100,   101,   514,   515,     0,     0,     0,     0,     0,     0,
     104,   105,   106,     0,   108,   109,     0,     0,     0,     0,
       0,     0,     0,   115,   516,     0,     0,     0,   117,   118,
     119,   120,   517,   122,   123,   518,     0,     0,     0,     0,
       0,     0,     0,   519,   520,   130,     0,     0,     0,   131,
     768,   132,   521,     0,     0,     0,     0,   769,     0,   138,
       0,   139,   140,   141,   142,   522,   144,   145,   146,   147,
     148,   149,     0,     0,   150,   151,     0,     0,   422,     0,
     155,   156,     0,     0,     0,   160,   161,   162,   163,   164,
     165,     0,   547,     0,   169,     0,     0,   172,   173,   174,
     175,   176,   177,   523,   179,   524,   525,   526,   183,   184,
     527,   528,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   529,     0,   200,   530,   202,     0,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,     3,     0,     0,
       0,     0,     0,   253,     0,     0,     9,    10,     0,     0,
       0,   794,     0,     0,   419,   420,     0,    16,    17,    18,
     538,    20,    21,    22,   494,   539,   540,   496,   497,   498,
     421,    30,   499,    32,   541,    34,     0,    35,    36,    37,
      38,   542,    40,   543,   544,    43,    44,    45,    46,   501,
       0,    48,   545,    50,   503,   504,    53,   505,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,   506,   507,    71,     0,    72,    73,    74,   546,
       0,     0,    77,    78,    79,     0,     0,   509,    81,     0,
       0,     0,     0,    83,   510,    85,   511,   512,    88,    89,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    94,
      95,    96,    97,     0,    98,     0,     0,     0,   513,   100,
     101,   514,   515,     0,     0,     0,     0,     0,     0,   104,
     105,   106,     0,   108,   109,     0,     0,     0,     0,     0,
       0,     0,   115,   516,     0,     0,     0,   117,   118,   119,
     120,   517,   122,   123,   518,     0,     0,     0,     0,     0,
       0,     0,   519,   520,   130,     0,     0,     0,   131,   795,
     132,   521,     0,     0,     0,     0,     0,     0,   138,     0,
     139,   140,   141,   142,   522,   144,   145,   146,   147,   148,
     149,     0,     0,   150,   151,     0,     0,   422,     0,   155,
     156,     0,     0,     0,   160,   161,   162,   163,   164,   165,
       0,   547,     0,   169,     0,     0,   172,   173,   174,   175,
     176,   177,   523,   179,   524,   525,   526,   183,   184,   527,
     528,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   529,     0,   200,   530,   202,     0,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,     3,     0,     0,     0,
       0,     0,   253,     0,     0,     9,    10,     0,     0,     0,
       0,     0,     0,   419,   420,     0,    16,    17,    18,   538,
      20,    21,    22,   494,   539,   540,   496,   497,   498,   421,
      30,   499,    32,   541,    34,     0,    35,    36,    37,    38,
     542,    40,   543,   544,    43,    44,    45,    46,   501,     0,
      48,   545,    50,   503,   504,    53,   505,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,   506,   507,    71,     0,    72,    73,    74,   546,     0,
       0,    77,    78,    79,     0,     0,   509,    81,     0,     0,
       0,     0,    83,   510,    85,   511,   512,    88,    89,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    94,    95,
      96,    97,     0,    98,     0,     0,     0,   513,   100,   101,
     514,   515,     0,     0,     0,     0,     0,     0,   104,   105,
     106,     0,   108,   109,     0,     0,     0,     0,     0,     0,
       0,   115,   516,     0,     0,     0,   117,   118,   119,   120,
     517,   122,   123,   518,     0,     0,     0,     0,     0,     0,
       0,   519,   520,   130,     0,     0,     0,   131,   812,   132,
     521,     0,     0,     0,     0,   813,     0,   138,     0,   139,
     140,   141,   142,   522,   144,   145,   146,   147,   148,   149,
       0,     0,   150,   151,     0,     0,   422,     0,   155,   156,
       0,     0,     0,   160,   161,   162,   163,   164,   165,     0,
     547,     0,   169,     0,     0,   172,   173,   174,   175,   176,
     177,   523,   179,   524,   525,   526,   183,   184,   527,   528,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   529,     0,   200,   530,   202,     0,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,     3,     0,     0,     0,     0,
       0,   253,     0,     0,     9,    10,     0,     0,     0,     0,
       0,     0,   419,   420,     0,    16,    17,    18,   538,    20,
      21,    22,   494,   539,   540,   496,   497,   498,   421,    30,
     499,    32,   541,    34,     0,    35,    36,    37,    38,   542,
      40,   543,   544,    43,    44,    45,    46,   501,     0,    48,
     545,    50,   503,   504,    53,   505,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
     506,   507,    71,     0,    72,    73,    74,   546,     0,     0,
      77,    78,    79,     0,     0,   509,    81,     0,     0,     0,
       0,    83,   510,    85,   511,   512,    88,    89,  1258,     0,
       0,     0,     0,     0,     0,     0,     0,    94,    95,    96,
      97,     0,    98,     0,     0,     0,   513,   100,   101,   514,
     515,     0,     0,     0,     0,     0,     0,   104,   105,   106,
       0,   108,   109,     0,     0,     0,     0,     0,     0,     0,
     115,   516,     0,     0,     0,   117,   118,   119,   120,   517,
     122,   123,   518,     0,     0,     0,     0,     0,     0,     0,
     519,   520,   130,     0,     0,     0,   131,     0,   132,   521,
       0,     0,     0,     0,     0,     0,   138,     0,   139,   140,
     141,   142,   522,   144,   145,   146,   147,   148,   149,     0,
       0,   150,   151,     0,     0,   422,     0,   155,   156,     0,
       0,     0,   160,   161,   162,   163,   164,   165,     0,   547,
       0,   169,     0,     0,   172,   173,   174,   175,   176,   177,
     523,   179,   524,   525,   526,   183,   184,   527,   528,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   529,     0,   200,   530,   202,     0,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,     3,     0,     0,     0,     0,     0,
     253,     0,     0,     9,    10,     0,     0,     0,     0,     0,
       0,   419,   420,     0,    16,    17,    18,   538,    20,    21,
      22,   494,   539,   540,   496,   497,   498,   421,    30,   499,
      32,   541,    34,     0,    35,    36,    37,    38,   542,    40,
     543,   544,    43,    44,    45,    46,   501,     0,    48,   545,
      50,   503,   504,    53,   505,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,   506,
     507,    71,     0,    72,    73,    74,   546,     0,     0,    77,
      78,    79,     0,     0,   509,    81,     0,     0,     0,     0,
      83,   510,    85,   511,   512,    88,    89,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    94,    95,    96,    97,
       0,    98,     0,     0,     0,   513,   100,   101,   514,   515,
       0,     0,     0,     0,     0,     0,   104,   105,   106,     0,
     108,   109,     0,     0,     0,     0,     0,     0,     0,   115,
     516,     0,     0,     0,   117,   118,   119,   120,   517,   122,
     123,   518,     0,     0,     0,     0,     0,     0,     0,   519,
     520,   130,     0,     0,     0,   131,     0,   132,   521,     0,
       0,     0,     0,     0,     0,   138,     0,   139,   140,   141,
     142,   522,   144,   145,   146,   147,   148,   149,     0,     0,
     150,   151,     0,     0,   422,     0,   155,   156,     0,     0,
       0,   160,   161,   162,   163,   164,   165,     0,   547,     0,
     169,     0,     0,   172,   173,   174,   175,   176,   177,   523,
     179,   524,   525,   526,   183,   184,   527,   528,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     529,     0,   200,   530,   202,     0,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,     5,     6,     7,     8,     9,    10,   253,
       0,     0,    13,     0,     0,   419,   420,     0,    16,    17,
      18,   586,    20,    21,    22,    23,     0,   587,   496,    27,
       0,   421,    30,   499,    32,     0,    34,     0,    35,    36,
      37,    38,   588,    40,     0,     0,    43,    44,    45,    46,
     501,     0,    48,   589,    50,     0,     0,    53,   505,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,   506,   507,    71,     0,    72,    73,    74,
     590,     0,     0,    77,    78,    79,     0,     0,   509,    81,
       0,     0,     0,    82,    83,   510,    85,   511,   512,    88,
      89,   560,    91,     0,     0,     0,     0,     0,    93,     0,
      94,    95,    96,    97,     0,    98,     0,     0,     0,   513,
     100,   101,   514,   515,     0,     0,     0,     0,     0,     0,
     104,   105,   106,   107,   108,   109,     0,   561,   111,     0,
     112,   113,     0,   115,   116,     0,     0,     0,   117,   118,
     119,   120,   121,   122,   123,   518,     0,   125,     0,     0,
       0,     0,     0,   519,   520,   130,     0,     0,     0,   131,
       0,   132,   521,     0,     0,     0,     0,     0,     0,   138,
       0,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,     0,     0,     0,   151,   152,     0,   422,     0,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,     0,   591,     0,   592,     0,     0,   172,   173,   174,
     175,   176,   177,   523,   179,   524,   525,   526,   183,   184,
       0,   528,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   529,     0,   200,   530,   202,     0,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,     0,   251,
       0,   593,     0,   253,     5,     6,     7,     8,     9,    10,
       0,     0,     0,    13,     0,     0,   419,   420,     0,    16,
      17,    18,   586,    20,    21,    22,    23,     0,   587,   496,
      27,     0,   421,    30,   499,    32,     0,    34,     0,    35,
      36,    37,    38,   588,    40,     0,     0,    43,    44,    45,
      46,   501,     0,    48,   589,    50,     0,     0,    53,   505,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,   506,   507,    71,     0,    72,    73,
      74,   590,     0,     0,    77,    78,    79,     0,     0,   509,
      81,     0,     0,     0,    82,    83,   510,    85,   511,   512,
      88,    89,   560,    91,     0,     0,     0,     0,     0,    93,
       0,    94,    95,    96,    97,     0,    98,     0,     0,     0,
     513,   100,   101,   514,   515,     0,     0,     0,     0,     0,
       0,   104,   105,   106,   107,   108,   109,     0,   561,   111,
       0,   112,   113,     0,   115,   116,     0,     0,     0,   117,
     118,   119,   120,   121,   122,   123,   518,     0,   125,     0,
       0,     0,     0,     0,   519,   520,   130,     0,     0,     0,
     131,     0,   132,   521,     0,     0,     0,     0,     0,     0,
     138,     0,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,     0,     0,     0,   151,   152,     0,   422,
       0,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,     0,   601,     0,   169,     0,     0,   172,   173,
     174,   175,   176,   177,   523,   179,   524,   525,   526,   183,
     184,     0,   528,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   529,     0,   200,   530,   202,
       0,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,     0,
     251,     0,   602,     0,   253,     5,     6,     7,     8,     9,
      10,     0,     0,     0,    13,     0,     0,   419,   420,     0,
      16,    17,    18,   586,    20,    21,    22,    23,     0,   587,
     496,    27,     0,   421,    30,   499,    32,     0,    34,     0,
      35,    36,    37,    38,   588,    40,     0,     0,    43,    44,
      45,    46,   501,     0,    48,   589,    50,     0,     0,    53,
     505,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,   506,   507,    71,     0,    72,
      73,    74,   590,     0,     0,    77,    78,    79,     0,     0,
     509,    81,     0,     0,     0,    82,    83,   510,    85,   511,
     512,    88,    89,   560,    91,     0,     0,     0,     0,     0,
      93,     0,    94,    95,    96,    97,     0,    98,     0,     0,
       0,   513,   100,   101,   514,   515,     0,     0,     0,     0,
       0,     0,   104,   105,   106,   107,   108,   109,     0,   561,
     111,     0,   112,   113,     0,   115,   116,     0,     0,     0,
     117,   118,   119,   120,   121,   122,   123,   518,     0,   125,
       0,     0,     0,     0,     0,   519,   520,   130,     0,     0,
       0,   131,     0,   132,   521,     0,     0,     0,     0,     0,
       0,   138,     0,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,     0,     0,     0,   151,   152,     0,
     422,     0,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,     0,  1109,     0,   169,     0,     0,   172,
     173,   174,   175,   176,   177,   523,   179,   524,   525,   526,
     183,   184,     0,   528,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   529,     0,   200,   530,
     202,     0,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
       0,   251,     0,     0,     0,   253,     5,     6,     7,     8,
       9,    10,     0,     0,     0,    13,     0,     0,   419,   420,
       0,    16,    17,    18,   586,    20,    21,    22,    23,     0,
     587,   496,    27,     0,   421,    30,   499,    32,     0,    34,
       0,    35,    36,    37,    38,   588,    40,     0,     0,    43,
      44,    45,    46,   501,     0,    48,   589,    50,     0,     0,
      53,   505,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,   506,   507,    71,     0,
      72,    73,    74,   590,     0,     0,    77,    78,    79,     0,
       0,   509,    81,     0,     0,     0,    82,    83,   510,    85,
     511,   512,    88,    89,   560,    91,     0,     0,     0,     0,
       0,    93,     0,    94,    95,    96,    97,     0,    98,     0,
       0,     0,   513,   100,   101,   514,   515,     0,     0,     0,
       0,     0,     0,   104,   105,   106,   107,   108,   109,     0,
     561,   111,     0,   112,   113,     0,   115,   116,     0,     0,
       0,   117,   118,   119,   120,   121,   122,   123,   518,     0,
     125,     0,     0,     0,     0,     0,   519,   520,   130,     0,
       0,     0,   131,     0,   132,   521,     0,     0,     0,     0,
       0,     0,   138,     0,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,     0,     0,     0,   151,   152,
       0,   422,     0,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,     0,     0,     0,   169,     0,     0,
     172,   173,   174,   175,   176,   177,   523,   179,   524,   525,
     526,   183,   184,     0,   528,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   529,     0,   200,
     530,   202,     0,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,     0,   251,     9,    10,     0,   253,     0,     0,     0,
       0,   419,   420,     0,    16,    17,    18,     0,    20,    21,
      22,   494,     0,     0,   496,   497,     0,   421,    30,   499,
      32,     0,    34,     0,    35,    36,    37,    38,     0,    40,
       0,     0,    43,    44,    45,    46,   501,     0,    48,     0,
      50,     0,     0,    53,   505,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,   506,
     507,    71,     0,    72,    73,    74,     0,     0,     0,    77,
      78,    79,     0,     0,   509,    81,     0,     0,     0,     0,
      83,   510,    85,   511,   512,    88,    89,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    94,    95,    96,    97,
       0,    98,     0,     0,     0,   513,   100,   101,   514,   515,
       0,     0,     0,     0,     0,     0,   104,   105,   106,     0,
     108,   109,     0,     0,     0,     0,     0,     0,     0,   115,
     516,     0,     0,     0,   117,   118,   119,   120,   517,   122,
     123,   518,     0,     0,     0,     0,     0,     0,     0,   519,
     520,   130,     0,     0,     0,   131,     0,   132,   521,     0,
       0,     0,     0,     0,     0,   138,     0,   139,   140,   141,
     142,   522,   144,   145,   146,   147,   148,   149,     0,     0,
       0,   151,     0,     0,   422,     0,   155,   156,     0,     0,
       0,   160,   161,   162,   163,   164,   165,     0,     0,     0,
     169,     0,     0,   172,   173,   174,   175,   176,   177,   523,
     179,   524,   525,   526,   183,   184,     0,   528,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     529,     0,   200,   530,   202,     0,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,     0,     0,     0,     0,     0,     0,   253
  };

  /* YYCHECK.  */
  const short int
  jsoniq_parser::yycheck_[] =
  {
         0,   293,   186,   697,   314,     5,     6,     7,     8,   345,
      14,     5,     6,     7,     8,     5,     6,     7,   432,   166,
       0,   773,   681,   170,   833,     5,     6,     7,     8,   111,
     112,     5,     6,     7,     8,   430,   431,   788,   682,   683,
     684,   685,   869,  1043,   635,   636,  1059,   201,   261,   709,
     801,    76,   773,   467,   468,  1299,    76,  1317,   928,   929,
       1,   136,  1085,   168,   815,    90,     1,  1384,  1385,   956,
     262,   915,  1388,  1518,   254,   255,  1521,  1006,  1148,    36,
     633,   634,  1330,  1024,   972,   277,     1,    36,   113,    56,
     633,   634,   635,   636,    27,    28,     1,     1,   119,  1431,
     125,     1,   127,    39,   730,    30,    97,   144,    44,    45,
     110,     1,     1,   284,    47,    94,   110,    53,  1633,     1,
     928,   929,     1,   108,    60,     1,    62,    63,     1,     1,
     110,    30,   108,   425,   123,    71,   110,   429,    95,    31,
      97,   166,    75,     1,    52,   170,     8,   119,    97,     0,
       1,   101,   123,     1,   101,     1,  1026,     1,     1,    27,
      28,     1,    98,  1033,   972,   138,    95,   108,   250,   251,
       1,   155,   132,   108,    37,    38,   119,    40,    41,    47,
     113,    97,    95,   138,   170,   160,   111,     1,   107,    57,
     187,   139,   149,   108,   178,    58,   144,   152,  1006,     1,
     149,   126,   177,   188,   108,   184,    45,    75,   108,   230,
     129,   293,    80,   189,   211,     1,   188,   203,  1026,    33,
     149,   108,   149,   131,    63,  1033,   151,   978,   108,   202,
     155,     1,   149,   158,   108,   108,   149,   187,   198,     1,
     187,   278,   158,    97,   112,   113,   114,     1,  1565,   238,
     108,   114,   219,   178,   254,   255,   566,   108,   258,     1,
     108,   553,   108,   162,   108,   108,     1,   238,   108,  1784,
     261,   186,  1081,   348,   254,   255,  1164,   108,   258,  1031,
     451,  1032,  1282,  1296,   188,   185,   191,  1535,  1532,   880,
     881,   312,   259,   293,   230,   220,   221,   222,  1321,   162,
    1632,   191,   191,  1748,  1148,  1149,   108,  1330,  1029,   191,
    1031,    77,   191,   293,   176,   191,  1203,  1258,  1206,   191,
    1249,   278,   108,   215,  1045,   878,   879,   741,   353,   278,
     188,   356,   958,   353,   185,   278,   356,  1407,   108,   264,
     188,   101,   188,   425,   188,   188,   108,   429,   188,   188,
    1795,   278,  1797,   240,   108,   108,  1164,   188,   238,   292,
     652,   278,   225,    30,   238,   132,   108,   300,     1,     0,
       1,    42,   786,   108,     1,    46,     1,   318,   460,  1695,
      51,   316,   155,   465,   186,   108,   322,   323,   324,   155,
    1141,   155,   108,   475,   158,     1,     1,    95,  1206,    70,
     482,   483,   188,   266,  1274,   178,     1,   261,   262,   491,
       1,   436,   437,   158,     1,   440,  1733,    97,   188,   444,
     633,   634,   447,   448,   292,   425,   188,   187,   121,   429,
     455,   198,   300,   158,   188,   188,   461,   462,   630,   631,
     308,  1249,   622,   185,   469,   425,   593,   114,   640,   429,
     185,   476,   477,   478,   479,   602,   456,  1773,   458,   484,
     226,   227,   456,   156,   458,   158,  1274,   492,   191,   149,
    1787,   553,    55,   189,    57,   108,   456,   108,   458,   108,
     480,   108,   456,   108,   458,   485,   480,   230,   570,   571,
    1298,   485,   235,   598,   108,   162,   147,  1248,   169,   581,
     480,   172,   108,   108,   162,   485,   480,   158,  1260,   534,
    1770,   485,  1535,   108,   155,   669,   187,   108,   101,    42,
     915,   108,    97,    46,   549,   223,   224,   121,    51,   611,
     612,    95,   155,    27,    28,   560,  1127,  1128,  1129,  1366,
     238,   183,   213,  1370,    45,  1205,    47,    70,  1269,   242,
    1244,   155,   185,   553,   185,   197,   951,   133,   185,   188,
     185,   561,   156,  1407,   158,   979,   980,   561,   593,  1439,
     984,  1815,  1416,   553,   188,   867,   319,   602,   108,   185,
     185,   561,   607,  1427,  1127,  1128,  1129,   561,   211,   614,
     185,   262,    42,   119,   185,   170,    46,   108,   185,    30,
    1014,    51,     3,   268,   896,     5,   107,   211,   146,     9,
     119,   108,   612,   108,   279,   191,   698,   108,   612,   113,
      70,   703,   622,     1,   628,     3,   701,   702,   108,   108,
      97,  1439,   612,   633,   634,   635,   636,  1388,    54,   177,
     133,   666,   622,    59,   158,   187,   169,   114,   242,   172,
    1650,    30,   652,   633,   634,   635,   636,   195,   188,   223,
     224,   187,   158,    97,   187,   878,    67,    95,   169,   211,
     108,    72,   652,   256,   238,     5,   614,   188,   187,     9,
     111,    97,   257,   258,   709,   260,   269,   160,   271,    67,
     213,   188,   884,   188,    72,   126,   888,   188,   191,   282,
     283,   284,   277,   286,   177,   288,   185,   158,   188,   734,
    1518,   858,   737,  1521,   289,   149,   144,   124,   119,   169,
     151,     1,   172,     3,  1533,   125,   751,   127,   666,  1538,
     755,   756,   111,     9,    10,   135,    33,   187,  1490,   262,
     158,   119,   824,   825,   826,    95,   828,   126,   155,   774,
     188,   158,    49,  1148,  1149,   155,  1769,   782,  1602,  1418,
     785,   158,   219,   213,   789,   158,     9,   637,    95,   158,
     118,   641,   151,     9,    10,  1020,   155,  1022,   778,   158,
     107,  1475,  1373,    95,   778,   867,    29,    67,   778,   220,
     221,   222,    72,  1663,   144,   125,   119,   127,   778,   178,
     148,   274,   259,    97,   778,   135,     9,   832,   281,   809,
     810,    95,   262,   161,  1150,   809,   810,   144,   291,   121,
     114,  1066,   158,  1068,  1116,   155,    29,   139,   104,   809,
     810,   183,   144,   858,    95,   809,   810,   121,    45,   119,
      47,   220,   221,   222,   869,   197,  1716,   195,  1718,   125,
     304,   127,   187,   139,   156,  1663,   158,   939,   144,   313,
     121,     9,    10,  1277,   158,  1674,    54,   867,   104,  1678,
      97,    59,   156,    80,   158,   900,   211,   160,   187,   155,
     124,     1,   125,   159,   127,   910,   890,   867,   155,   125,
      78,   127,    25,   136,   177,   156,   896,   158,    97,   175,
     107,    34,   211,   928,   929,   930,   931,   268,  1716,    97,
    1718,  1781,   155,    33,   124,   114,   896,   200,   279,   155,
     196,   187,   125,   159,   127,  1117,  1760,  1761,    61,    49,
     187,   119,  1124,   136,  1593,  1594,  1120,   101,   214,   175,
    1748,  1635,  1586,   170,   101,   211,   274,   972,   160,   124,
     114,   167,   155,   281,   211,  1764,   104,   114,   101,   158,
     196,   986,   169,   291,  1111,   177,  1380,   183,  1802,   150,
     119,   114,    96,  1781,  1808,  1389,   150,   125,   214,   127,
       9,    10,  1733,   107,  1276,   166,  1011,  1795,   200,  1797,
     252,   253,   166,   117,   139,  1020,   101,  1022,   139,  1024,
     119,  1026,   101,   101,   155,   129,    95,   155,  1033,   114,
     155,   159,  1407,   275,   155,   114,   114,   969,   107,   202,
      54,  1416,   237,   155,   239,    59,   158,   175,   211,   981,
     257,   258,  1427,   260,   155,   704,    90,   158,   707,   124,
     267,  1066,   711,  1068,  1738,  1704,  1705,   273,   196,   124,
     277,   282,   283,   284,   280,  1365,   110,   288,   124,   113,
     155,  1061,   289,   158,   124,  1147,   214,  1061,   226,   227,
     228,   125,   124,   127,   352,   104,   237,   355,   239,   192,
     193,  1061,   130,   131,   124,  1499,  1111,  1061,   130,   131,
     155,  1785,   124,   679,   680,   218,   125,   124,   127,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,   686,
     687,   218,  1137,   158,   168,   119,  1116,   246,  1777,   688,
     689,   246,  1126,  1242,  1243,   247,   155,  1127,  1128,  1129,
     159,  1623,  1624,   158,   155,     0,  1116,   168,   191,  1164,
      27,    28,    93,   254,   100,    50,   175,  1127,  1128,  1129,
      37,    38,   201,    40,    41,   102,   194,   103,   156,   158,
      47,   185,   185,  1857,    30,  1859,   185,   196,   185,    47,
      57,    58,   251,   154,   119,  1869,   188,   155,  1362,   309,
       1,  1206,   119,   144,   108,   214,   188,   188,    75,   155,
     155,   158,   144,    80,   204,   205,   206,   207,   208,   209,
     158,   158,   185,   158,   158,   123,   123,  1602,   158,   158,
     158,   155,    35,    17,    30,   215,    30,   155,   236,  1511,
     155,   155,   155,   155,   235,   112,   113,   114,   191,   191,
     250,   238,     3,  1258,   119,   171,   119,  1262,   169,   289,
      71,   171,   289,   236,    95,    95,    95,   188,   151,  1274,
     108,   108,  1252,    30,   162,   162,   129,   134,  1252,   251,
      95,   304,  1252,  1288,   144,   119,  1558,   134,   188,   185,
     185,   108,  1252,  1298,   188,   162,  1276,    95,  1252,    45,
      97,   155,    97,    95,   188,   144,   188,  1287,   188,   188,
     185,   185,    33,  1287,   236,   191,  1276,  1287,   238,   242,
     171,   134,   144,  1328,    95,    30,  1306,  1287,    95,   232,
     304,   291,  1306,  1287,   155,   149,  1306,   119,   129,   119,
      95,   185,   162,   199,   134,   134,  1306,  1327,    97,   155,
     119,  1356,  1306,  1327,  1334,   155,   149,   101,   225,   101,
    1334,  1366,   185,   144,   191,  1370,   185,  1327,    35,   123,
     123,    30,   155,  1327,  1334,    30,  1648,    97,   119,   250,
    1334,    80,   108,   107,   290,   108,   259,  1659,  1660,  1369,
    1662,   263,   158,  1398,   272,  1369,   265,   158,  1670,   266,
     158,   146,   158,   437,    30,   291,   440,    30,   158,  1369,
     444,   158,    30,   447,   448,   158,   232,   191,   311,   146,
     188,   455,   292,   188,   188,   292,   188,   461,   462,   129,
     149,   149,   108,   300,  1439,   469,   144,   185,   101,   199,
     134,   308,   476,   477,   478,   479,     7,    97,   188,   188,
     484,   238,   238,   191,   191,   321,   187,   242,   492,   238,
     238,   158,   158,   158,   155,   107,  1471,   149,   119,    78,
     119,   188,   149,   291,    79,   287,   188,   188,   255,   255,
      30,   188,   188,    30,   188,  1757,   188,   188,   276,   108,
     171,   149,   262,  1555,  1556,  1557,   185,   149,   128,   128,
     534,    97,   185,   187,   144,    95,    30,   187,   187,   155,
    1515,   185,   185,  1518,   185,   549,  1521,   321,   188,   185,
      97,   149,   285,   110,  1796,    95,   560,   561,   188,  1534,
     171,  1511,    54,   292,  1539,    95,   198,    30,   270,   108,
     108,   119,  1814,   230,    95,   198,    95,   119,   187,   187,
     198,  1511,   199,   119,    94,   230,   119,  1829,   310,   184,
     119,   198,   292,   298,   598,   187,   200,   119,   258,   230,
     258,  1576,  1577,   607,   310,   261,   310,  1207,  1558,  1851,
     614,   168,   311,   311,   740,   973,   311,   451,  1860,   431,
    1034,  1249,  1738,  1785,   870,  1146,  1579,   791,  1558,  1399,
    1391,  1133,  1387,  1384,  1288,   549,  1293,  1296,  1301,   676,
     668,   931,   678,   709,  1321,   833,   714,  1808,   340,  1802,
    1022,  1356,  1367,   459,   459,  1366,  1416,  1602,  1427,  1149,
    1692,  1420,   666,  1158,  1005,  1465,  1599,  1229,  1626,  1417,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1714,    -1,    -1,    -1,    -1,    -1,  1663,  1664,
      -1,  1666,    -1,  1668,    -1,   252,    -1,    -1,  1648,    -1,
    1675,    -1,    -1,    -1,    -1,   709,    -1,    -1,    -1,  1659,
    1660,    -1,  1662,    -1,    -1,    -1,    -1,    -1,  1648,    -1,
    1670,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1659,
    1660,    -1,  1662,   737,    -1,    -1,    -1,    -1,    -1,    -1,
    1670,  1716,    -1,  1718,    -1,    -1,    -1,   751,    -1,    -1,
      -1,   755,   756,    -1,    -1,    -1,    -1,    -1,    -1,  1734,
      -1,    -1,  1737,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     774,    -1,    -1,  1748,    -1,    -1,    -1,    -1,   782,    -1,
      -1,   785,    -1,    -1,  1759,   789,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1781,  1757,    -1,    -1,
      -1,    -1,    -1,    -1,  1789,    -1,    -1,   821,    -1,    -1,
    1795,    -1,  1797,    -1,    -1,    -1,    -1,  1757,   832,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1818,    -1,    -1,  1796,    -1,    -1,    -1,
      -1,    -1,  1827,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1814,    -1,  1796,    -1,    -1,    -1,
      -1,    -1,  1847,    -1,    -1,    -1,    -1,  1852,    -1,  1829,
      -1,    -1,    -1,    -1,  1814,    -1,    -1,    -1,    -1,  1864,
      -1,    -1,  1867,    -1,    -1,    -1,   900,    -1,    -1,  1829,
      -1,  1851,    -1,    -1,    -1,    -1,   910,    -1,    -1,    -1,
    1860,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1851,    -1,    -1,   928,   929,   930,   931,    -1,    -1,
    1860,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   972,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   986,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   561,    -1,    -1,  1011,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1020,    -1,  1022,    -1,
    1024,    -1,  1026,    -1,    -1,    -1,    -1,    -1,    -1,  1033,
      -1,    -1,    -1,    -1,   591,   592,    -1,    -1,    -1,   596,
     597,   598,    -1,    -1,   601,    -1,    -1,   604,    -1,    -1,
      -1,    -1,    -1,   610,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1066,   620,  1068,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   643,   644,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   652,   653,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1137,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   710,    -1,    -1,    -1,   714,    -1,    -1,
    1164,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   753,    -1,    -1,    -1,
      -1,    -1,  1206,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   790,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1258,    -1,    -1,    -1,  1262,   816,
      -1,    -1,    -1,   820,   821,    -1,   823,    -1,    -1,    -1,
    1274,    -1,    -1,   830,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1288,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1298,   852,   853,    -1,    -1,   856,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   876,
      -1,    -1,    -1,    -1,  1328,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   896,
      -1,    -1,    -1,    -1,    -1,   902,   903,    -1,    -1,    -1,
      -1,    -1,  1356,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1398,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   974,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1439,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1009,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1471,    -1,    -1,
      -1,  1028,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1044,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1055,  1056,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1515,    -1,  1070,  1518,    -1,  1073,  1521,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1534,    -1,    -1,    -1,    -1,  1539,    -1,  1094,  1095,  1096,
      -1,  1098,  1099,  1100,  1101,  1102,    -1,    -1,  1105,  1106,
      -1,  1108,  1109,    -1,    -1,    -1,  1113,  1114,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1122,    -1,    -1,    -1,    -1,
      -1,    -1,  1576,  1577,    -1,    -1,  1133,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1193,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1663,
    1664,    -1,  1666,    -1,  1668,    -1,    -1,    -1,    -1,    -1,
      -1,  1675,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1264,    -1,  1266,
      -1,  1268,  1716,    -1,  1718,    -1,    -1,    -1,    -1,  1276,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1285,    -1,
    1734,    -1,    -1,  1737,  1291,  1292,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1748,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1310,    -1,  1759,  1313,  1314,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1781,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1789,    -1,    -1,    -1,    -1,
      -1,  1795,    -1,  1797,    -1,    -1,    -1,  1354,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1818,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1827,    -1,    -1,    -1,    -1,    -1,    -1,
    1387,    -1,    -1,    -1,  1391,  1392,    -1,    -1,    -1,    -1,
    1397,    -1,    -1,  1847,    -1,    -1,    -1,    -1,  1852,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1864,    -1,    -1,  1867,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1484,    -1,    -1,
      -1,  1488,    -1,    -1,    -1,  1492,    -1,  1494,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1502,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1510,  1511,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1531,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1544,  1545,  1546,
    1547,    -1,  1549,  1550,    -1,  1552,    -1,  1554,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1569,    -1,    -1,    -1,    -1,    -1,  1575,    -1,
      -1,    -1,    -1,    -1,  1581,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1641,    -1,  1643,    -1,    -1,  1646,
      -1,    -1,  1649,    -1,    -1,    -1,    -1,  1654,  1655,    -1,
      -1,    -1,    -1,    -1,    -1,  1662,    -1,    -1,    -1,    -1,
    1667,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1684,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1696,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1741,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1753,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1796,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     0,     1,    -1,    -1,    -1,    -1,  1825,    -1,
      -1,    -1,  1829,    11,    12,    -1,    -1,  1834,    16,    -1,
      -1,    -1,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    -1,    30,  1850,    -1,    33,    34,  1854,    36,    37,
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
     148,   149,   150,   151,   152,   153,    -1,   155,   156,    -1,
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
       0,     1,   320,   321,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    11,    12,    -1,    -1,    -1,    16,    -1,    -1,    -1,
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
     150,   151,   152,   153,    -1,   155,   156,    -1,   158,   159,
     160,   161,   162,    -1,    -1,    -1,   166,   167,   168,   169,
     170,   171,   172,   173,    -1,   175,    -1,   177,   178,    -1,
      -1,   181,   182,   183,    -1,    -1,    -1,   187,    -1,   189,
     190,   191,   192,   193,    -1,   195,    -1,   197,    -1,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
      -1,    -1,   212,   213,   214,    -1,   216,    -1,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,    -1,   264,   265,   266,    -1,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,     1,   317,    -1,    -1,
     320,   321,    -1,    -1,    -1,    -1,    11,    12,    -1,    -1,
      -1,    16,    -1,    -1,    -1,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    -1,    30,    -1,    -1,    33,    34,
      -1,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      -1,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    -1,
      95,    96,    97,    98,    99,    -1,   101,   102,   103,    -1,
      -1,   106,   107,    -1,    -1,    -1,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,    -1,   122,    -1,    -1,
      -1,   126,    -1,   128,   129,   130,   131,    -1,   133,    -1,
      -1,    -1,   137,   138,   139,   140,   141,    -1,    -1,    -1,
      -1,    -1,    -1,   148,   149,   150,   151,   152,   153,    -1,
     155,   156,    -1,   158,   159,   160,   161,   162,    -1,    -1,
      -1,   166,   167,   168,   169,   170,   171,   172,   173,    -1,
     175,    -1,   177,   178,    -1,    -1,   181,   182,   183,    -1,
      -1,    -1,   187,    -1,   189,   190,   191,   192,   193,    -1,
     195,    -1,   197,    -1,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,    -1,    -1,   212,   213,   214,
      -1,   216,    -1,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,    -1,   264,
     265,   266,    -1,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,     1,   317,    -1,    -1,   320,   321,    -1,    -1,    -1,
      -1,    11,    12,    -1,    -1,    -1,    16,    -1,    -1,    -1,
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
     150,   151,   152,   153,    -1,   155,   156,    -1,   158,   159,
     160,   161,   162,    -1,    -1,    -1,   166,   167,   168,   169,
     170,   171,   172,   173,    -1,   175,    -1,   177,   178,    -1,
      -1,   181,   182,   183,    -1,    -1,    -1,   187,    -1,   189,
     190,    -1,   192,   193,    -1,   195,    -1,   197,    -1,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
      -1,    -1,   212,   213,   214,    -1,   216,    -1,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,    -1,   264,   265,   266,    -1,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,    -1,   317,    -1,    -1,
     320,   321,     0,     1,    -1,     3,    -1,    -1,    -1,    -1,
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
     118,   119,    -1,    -1,    -1,   123,    -1,    -1,    -1,    -1,
     128,   129,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     138,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   147,
     148,    -1,    -1,    -1,   152,    -1,    -1,    -1,   156,    -1,
     158,    -1,   160,   161,    -1,    -1,    -1,    -1,    -1,    -1,
     168,   169,    -1,    -1,   172,    -1,    -1,    -1,    -1,   177,
      -1,     0,     1,    -1,     3,    -1,    -1,   185,   186,   187,
     188,   189,    -1,   191,   192,   193,   194,   195,    -1,    -1,
      -1,    -1,   200,   201,   202,    -1,   204,   205,   206,   207,
     208,   209,    -1,   211,    -1,   213,    -1,    -1,    -1,    -1,
      -1,   219,    -1,    42,    -1,   223,   224,    46,    -1,    -1,
      -1,    50,    51,    -1,    -1,    -1,    -1,    56,    -1,    -1,
     238,    -1,   240,    -1,   242,    -1,    -1,    -1,    67,    -1,
      -1,    70,    -1,    72,    -1,    -1,   254,    -1,    -1,    -1,
      -1,   259,    -1,    -1,   262,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    93,    -1,    95,    96,    97,    -1,
      -1,   100,   101,   102,   103,    -1,    -1,    -1,   107,   108,
      -1,    -1,    -1,    -1,    -1,   114,    -1,    -1,   117,   118,
     119,    -1,    -1,    -1,   123,    -1,    -1,    -1,    -1,   128,
     129,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   316,   138,
     318,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   147,   148,
      -1,    -1,    -1,   152,    -1,    -1,    -1,   156,    -1,   158,
      -1,   160,   161,    -1,    -1,    -1,    -1,    -1,    -1,   168,
     169,    -1,    -1,   172,    -1,    -1,    -1,    -1,   177,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   185,   186,   187,   188,
     189,    -1,   191,   192,   193,   194,   195,    -1,    -1,    -1,
      -1,   200,   201,   202,    -1,   204,   205,   206,   207,   208,
     209,    -1,   211,    -1,   213,    -1,    -1,    -1,    -1,    -1,
     219,    -1,    -1,    -1,   223,   224,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   238,
      -1,   240,    -1,   242,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   254,    -1,    -1,    -1,    -1,
     259,    -1,    -1,   262,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    11,
      12,    -1,    -1,    -1,    16,    -1,    -1,    -1,    20,    21,
      22,    23,    24,    25,    26,    27,    28,   316,    30,   318,
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
     152,   153,    -1,   155,   156,    -1,   158,   159,   160,   161,
     162,    -1,    -1,    -1,   166,   167,   168,   169,   170,   171,
     172,   173,    -1,   175,    -1,   177,   178,    -1,    -1,   181,
     182,   183,    -1,    -1,    -1,   187,    -1,   189,   190,   191,
     192,   193,    -1,   195,    -1,   197,    -1,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,    -1,    -1,
     212,   213,   214,    -1,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,    -1,   264,   265,   266,    -1,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,    -1,   317,    -1,    -1,   320,   321,
      -1,    11,    12,    -1,   326,   327,    16,    -1,    -1,    -1,
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
     150,   151,   152,   153,    -1,   155,   156,    -1,   158,   159,
     160,   161,   162,    -1,    -1,    -1,   166,   167,   168,   169,
     170,   171,   172,   173,    -1,   175,    -1,   177,   178,    -1,
      -1,   181,   182,   183,    -1,    -1,    -1,   187,    -1,   189,
     190,   191,   192,   193,    -1,   195,    -1,   197,    -1,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
      -1,    -1,   212,   213,   214,    -1,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,    -1,   264,   265,   266,    -1,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,    -1,   317,    -1,    -1,
     320,   321,    -1,    11,    12,    -1,    -1,   327,    16,    -1,
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
     148,   149,   150,   151,   152,   153,    -1,   155,   156,    -1,
     158,   159,   160,   161,   162,    -1,    -1,    -1,   166,   167,
     168,   169,   170,   171,   172,   173,    -1,   175,    -1,   177,
     178,    -1,    -1,   181,   182,   183,    -1,    -1,    -1,   187,
      -1,   189,   190,   191,   192,   193,    -1,   195,    -1,   197,
      -1,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,    -1,    -1,   212,   213,   214,    -1,   216,   217,
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
      11,    12,   320,   321,    -1,    16,    -1,    -1,    -1,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    -1,    30,
      -1,    -1,    33,    34,    -1,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    -1,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    -1,    95,    96,    97,    98,    99,    -1,
     101,   102,   103,    -1,    -1,   106,   107,    -1,    -1,    -1,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
      -1,   122,    -1,    -1,    -1,   126,    -1,   128,   129,   130,
     131,    -1,   133,    -1,    -1,    -1,   137,   138,   139,   140,
     141,    -1,    -1,    -1,    -1,    -1,    -1,   148,   149,   150,
     151,   152,   153,    -1,   155,   156,    -1,   158,   159,   160,
     161,   162,    -1,    -1,    -1,   166,   167,   168,   169,   170,
     171,   172,   173,    -1,   175,    -1,   177,   178,    -1,    -1,
     181,   182,   183,    -1,   185,    -1,   187,    -1,   189,   190,
     191,   192,   193,    -1,   195,    -1,   197,    -1,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,    -1,
      -1,   212,   213,   214,    -1,   216,    -1,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     261,   262,    -1,   264,   265,   266,    -1,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,    -1,   317,    11,    12,   320,
     321,    -1,    16,    -1,    -1,    -1,    20,    21,    22,    23,
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
      -1,   155,   156,    -1,   158,   159,   160,   161,   162,    -1,
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
     314,   315,    -1,   317,    11,    12,   320,   321,    -1,    16,
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
      -1,   148,   149,   150,   151,   152,   153,    -1,   155,   156,
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
     307,   308,   309,   310,   311,   312,   313,   314,   315,    -1,
     317,    11,    12,   320,   321,    -1,    16,    -1,    -1,    -1,
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
     150,   151,   152,   153,    -1,   155,   156,    -1,   158,   159,
     160,   161,   162,    -1,    -1,    -1,   166,   167,   168,   169,
     170,   171,   172,   173,    -1,   175,    -1,   177,   178,    -1,
      -1,   181,   182,   183,    -1,    -1,    -1,   187,    -1,   189,
     190,   191,   192,   193,    -1,   195,    -1,   197,    -1,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
      -1,    -1,   212,   213,   214,    -1,   216,    -1,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,    -1,   264,   265,   266,    -1,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,    -1,   317,    11,    12,
     320,   321,    -1,    16,    -1,    -1,    -1,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    -1,    30,    -1,    -1,
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
     153,    -1,   155,   156,    -1,   158,   159,   160,   161,   162,
      -1,    -1,    -1,   166,   167,   168,   169,   170,   171,   172,
     173,    -1,   175,    -1,   177,   178,    -1,    -1,   181,   182,
     183,    -1,    -1,    -1,   187,    -1,   189,   190,   191,   192,
     193,    -1,   195,    -1,   197,    -1,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,    -1,    -1,   212,
     213,   214,    -1,   216,    -1,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
      -1,   264,   265,   266,    -1,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,    -1,   317,    11,    12,   320,   321,    -1,
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
      -1,    -1,   148,   149,   150,   151,   152,   153,    -1,   155,
     156,    -1,   158,   159,   160,   161,   162,    -1,    -1,    -1,
     166,   167,   168,   169,   170,   171,   172,   173,    -1,   175,
      -1,   177,   178,    -1,    -1,   181,   182,   183,    -1,    -1,
      -1,   187,    -1,   189,   190,   191,   192,   193,    -1,   195,
      -1,   197,    -1,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,    -1,    -1,   212,   213,   214,    -1,
     216,    -1,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,    -1,   264,   265,
     266,    -1,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
      -1,   317,    11,    12,   320,   321,    -1,    16,    -1,    -1,
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
     149,   150,   151,   152,   153,    -1,   155,   156,    -1,   158,
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
     309,   310,   311,   312,   313,   314,   315,    -1,   317,    11,
      12,   320,   321,    -1,    16,    -1,    -1,    -1,    20,    21,
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
     152,   153,    -1,   155,   156,    -1,   158,   159,   160,   161,
     162,    -1,    -1,    -1,   166,   167,   168,   169,   170,   171,
     172,   173,    -1,   175,    -1,   177,   178,    -1,    -1,   181,
     182,   183,    -1,    -1,    -1,   187,   188,   189,   190,    -1,
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
     312,   313,   314,   315,    -1,   317,    11,    12,   320,   321,
      -1,    16,    -1,    -1,    -1,    20,    21,    22,    23,    24,
      25,    26,    -1,    -1,    -1,    30,    -1,    -1,    33,    34,
      -1,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      -1,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    -1,
      95,    96,    97,    98,    99,    -1,   101,   102,   103,    -1,
      -1,   106,   107,    -1,    -1,    -1,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,    -1,   122,    -1,    -1,
      -1,   126,    -1,   128,   129,   130,   131,    -1,   133,    -1,
      -1,    -1,   137,   138,   139,   140,   141,    -1,    -1,    -1,
      -1,    -1,    -1,   148,   149,   150,   151,   152,   153,    -1,
     155,   156,    -1,   158,   159,   160,   161,   162,    -1,    -1,
      -1,   166,   167,   168,   169,   170,   171,   172,   173,    -1,
     175,    -1,   177,   178,    -1,    -1,   181,   182,   183,    -1,
      -1,   186,   187,    -1,   189,   190,    -1,   192,   193,    -1,
     195,    -1,   197,    -1,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,    -1,    -1,   212,   213,   214,
      -1,   216,    -1,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,    -1,   264,
     265,   266,    -1,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,    -1,   317,    11,    12,   320,   321,    -1,    16,    -1,
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
     148,   149,   150,   151,   152,   153,    -1,   155,   156,    -1,
     158,   159,   160,   161,   162,    -1,    -1,    -1,   166,   167,
     168,   169,   170,   171,   172,   173,    -1,   175,    -1,   177,
     178,    -1,    -1,   181,   182,   183,    -1,    -1,    -1,   187,
     188,   189,   190,    -1,   192,   193,    -1,   195,    -1,   197,
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
      11,    12,   320,   321,    -1,    16,    -1,    -1,    -1,    20,
      21,    22,    23,    24,    25,    26,    -1,    -1,    -1,    30,
      -1,    -1,    33,    34,    -1,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    -1,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    -1,    95,    96,    97,    98,    99,    -1,
     101,   102,   103,    -1,    -1,   106,   107,    -1,    -1,    -1,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
      -1,   122,    -1,    -1,    -1,   126,    -1,   128,   129,   130,
     131,    -1,   133,    -1,    -1,    -1,   137,   138,   139,   140,
     141,    -1,    -1,    -1,    -1,    -1,    -1,   148,   149,   150,
     151,   152,   153,    -1,   155,   156,    -1,   158,   159,   160,
     161,   162,    -1,    -1,    -1,   166,   167,   168,   169,   170,
     171,   172,   173,    -1,   175,    -1,   177,   178,    -1,    -1,
     181,   182,   183,    -1,    -1,    -1,   187,    -1,   189,   190,
      -1,   192,   193,    -1,   195,    -1,   197,    -1,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,    -1,
      -1,   212,   213,   214,    -1,   216,    -1,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     261,   262,    -1,   264,   265,   266,    -1,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,    -1,   317,    -1,   319,   320,
     321,    11,    12,    -1,    -1,    -1,    16,    -1,    -1,    -1,
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
     150,   151,   152,   153,    -1,   155,   156,    -1,   158,   159,
     160,   161,   162,    -1,    -1,    -1,   166,   167,   168,   169,
     170,   171,   172,   173,    -1,   175,    -1,   177,   178,    -1,
      -1,   181,   182,   183,    -1,    -1,    -1,   187,    -1,   189,
     190,    -1,   192,   193,    -1,   195,    -1,   197,    -1,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
      -1,    -1,   212,   213,   214,    -1,   216,    -1,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,    -1,   264,   265,   266,    -1,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,   317,    11,    12,
     320,   321,    -1,    16,    -1,    -1,    -1,    20,    21,    22,
      23,    24,    25,    26,    -1,    -1,    -1,    30,    -1,    -1,
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
     153,    -1,   155,   156,    -1,   158,   159,   160,   161,   162,
      -1,    -1,    -1,   166,   167,   168,   169,   170,   171,   172,
     173,    -1,   175,    -1,   177,   178,    -1,    -1,   181,   182,
     183,    -1,    -1,    -1,   187,    -1,   189,   190,    -1,   192,
     193,    -1,   195,    -1,   197,    -1,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,    -1,    -1,   212,
     213,   214,    -1,   216,    -1,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
      -1,   264,   265,   266,    -1,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,    -1,   317,   318,    -1,   320,   321,    11,
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
     152,   153,    -1,   155,   156,    -1,   158,   159,   160,   161,
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
      11,    12,    -1,    -1,    -1,    16,    -1,    -1,    -1,    20,
      21,    22,    23,    24,    25,    26,    -1,    -1,    -1,    30,
      -1,    -1,    33,    34,    -1,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    -1,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    -1,    95,    96,    97,    98,    99,    -1,
     101,   102,   103,    -1,    -1,   106,   107,    -1,    -1,    -1,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
      -1,   122,    -1,    -1,    -1,   126,    -1,   128,   129,   130,
     131,    -1,   133,    -1,    -1,    -1,   137,   138,   139,   140,
     141,    -1,    -1,    -1,    -1,    -1,    -1,   148,   149,   150,
     151,   152,   153,    -1,   155,   156,    -1,   158,   159,   160,
     161,   162,    -1,    -1,    -1,   166,   167,   168,   169,   170,
     171,   172,   173,    -1,   175,    -1,   177,   178,    -1,    -1,
     181,   182,   183,    -1,   185,    -1,   187,    -1,   189,   190,
      -1,   192,   193,    -1,   195,    -1,   197,    -1,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,    -1,
      -1,   212,   213,   214,    -1,   216,    -1,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     261,   262,    -1,   264,   265,   266,    -1,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,    -1,   317,    11,    12,   320,
     321,    -1,    16,    -1,    -1,    -1,    20,    21,    22,    23,
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
      -1,   155,   156,    -1,   158,   159,   160,   161,   162,    -1,
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
     314,   315,    -1,   317,    11,    12,   320,   321,    -1,    16,
      -1,    -1,    -1,    20,    21,    22,    23,    24,    25,    26,
      -1,    -1,    -1,    30,    -1,    -1,    33,    34,    -1,    36,
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
     137,   138,   139,   140,   141,    -1,    -1,    -1,    -1,   146,
      -1,   148,   149,   150,   151,   152,   153,    -1,   155,   156,
      -1,   158,   159,   160,   161,   162,    -1,    -1,    -1,   166,
     167,   168,   169,   170,   171,   172,   173,    -1,   175,    -1,
     177,   178,    -1,    -1,   181,   182,   183,    -1,    -1,    -1,
     187,    -1,   189,   190,    -1,   192,   193,    -1,   195,    -1,
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
     307,   308,   309,   310,   311,   312,   313,   314,   315,    -1,
     317,    11,    12,   320,   321,    -1,    16,    -1,    -1,    -1,
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
     150,   151,   152,   153,    -1,   155,   156,    -1,   158,   159,
     160,   161,   162,    -1,    -1,    -1,   166,   167,   168,   169,
     170,   171,   172,   173,    -1,   175,    -1,   177,   178,    -1,
      -1,   181,   182,   183,    -1,    -1,    -1,   187,    -1,   189,
     190,    -1,   192,   193,    -1,   195,    -1,   197,    -1,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
      -1,    -1,   212,   213,   214,    -1,   216,    -1,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,    -1,   264,   265,   266,    -1,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,    -1,   317,    11,    12,
     320,   321,    -1,    16,    -1,    -1,    -1,    20,    21,    22,
      23,    24,    25,    26,    -1,    -1,    -1,    30,    -1,    -1,
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
     153,    -1,   155,   156,    -1,   158,   159,   160,   161,   162,
      -1,    -1,    -1,   166,   167,   168,   169,   170,   171,   172,
     173,    -1,   175,    -1,   177,   178,    -1,    -1,   181,   182,
     183,    -1,    -1,    -1,   187,    -1,   189,   190,    -1,   192,
     193,    -1,   195,    -1,   197,    -1,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,    -1,    -1,   212,
     213,   214,    -1,   216,    -1,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
      -1,   264,   265,   266,    -1,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,    -1,   317,    11,    12,   320,   321,    -1,
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
      -1,    -1,   148,   149,   150,   151,   152,   153,    -1,   155,
     156,    -1,    -1,   159,   160,   161,   162,    -1,    -1,    -1,
     166,   167,   168,   169,   170,   171,   172,   173,    -1,   175,
      -1,   177,   178,    -1,    -1,   181,   182,   183,    -1,    -1,
      -1,   187,    -1,   189,   190,    -1,   192,   193,    -1,   195,
      -1,   197,    -1,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,    -1,    -1,   212,   213,   214,    -1,
     216,    -1,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,    -1,   264,   265,
     266,    -1,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
      -1,   317,    11,    12,   320,   321,    -1,    16,    -1,    -1,
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
     149,   150,   151,   152,   153,    -1,   155,   156,    -1,   158,
     159,   160,   161,   162,    -1,    -1,    -1,   166,   167,   168,
     169,   170,   171,   172,   173,    -1,   175,    -1,   177,   178,
      -1,    -1,   181,   182,   183,    -1,    -1,    -1,   187,    -1,
     189,   190,    -1,   192,   193,    -1,   195,    -1,   197,    -1,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,    -1,    -1,   212,   213,   214,    -1,   216,    -1,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
      -1,   230,    -1,   232,    -1,    -1,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   262,    -1,   264,   265,   266,    -1,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,    -1,   317,    11,
      12,    -1,   321,    -1,    16,    -1,    -1,    -1,    20,    21,
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
     152,   153,    -1,   155,   156,    -1,   158,   159,   160,   161,
     162,    -1,    -1,    -1,   166,   167,   168,   169,   170,   171,
     172,   173,    -1,   175,    -1,   177,   178,    -1,    -1,   181,
     182,   183,    -1,    -1,    -1,   187,    -1,   189,   190,    -1,
     192,   193,    -1,   195,    -1,   197,    -1,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,    -1,    -1,
     212,   213,   214,    -1,   216,    -1,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,    -1,   230,    -1,
     232,    -1,    -1,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,    -1,   264,   265,   266,    -1,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,    -1,   317,    11,    12,    -1,   321,
      -1,    16,    -1,    -1,    -1,    20,    21,    22,    23,    24,
      25,    26,    -1,    -1,    -1,    30,    -1,    -1,    33,    34,
      -1,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      -1,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    -1,
      95,    96,    97,    98,    99,    -1,   101,   102,   103,    -1,
      -1,   106,   107,    -1,    -1,    -1,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,    -1,   122,    -1,    -1,
      -1,   126,    -1,   128,   129,   130,   131,    -1,   133,    -1,
      -1,    -1,   137,   138,   139,   140,   141,    -1,    -1,    -1,
      -1,    -1,    -1,   148,   149,   150,   151,   152,   153,    -1,
     155,   156,    -1,   158,   159,   160,   161,   162,    -1,    -1,
      -1,   166,   167,   168,   169,   170,   171,   172,   173,    -1,
     175,    -1,   177,   178,    -1,    -1,   181,   182,   183,    -1,
      -1,    -1,   187,    -1,   189,   190,    -1,   192,   193,    -1,
     195,    -1,   197,    -1,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,    -1,    -1,   212,   213,   214,
      -1,   216,    -1,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,    -1,   230,    -1,   232,    -1,    -1,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,    -1,   264,
     265,   266,    -1,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,    -1,   317,    11,    12,    -1,   321,    -1,    16,    -1,
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
     148,   149,   150,   151,   152,   153,    -1,   155,   156,    -1,
     158,   159,    -1,   161,   162,    -1,    -1,    -1,   166,   167,
     168,   169,   170,   171,   172,   173,    -1,   175,    -1,    -1,
      -1,    -1,    -1,   181,   182,   183,    -1,    -1,    -1,   187,
      -1,   189,   190,    -1,   192,   193,    -1,   195,    -1,   197,
      -1,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,    -1,    -1,   212,   213,   214,    -1,   216,    -1,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,    -1,   230,    -1,   232,    -1,    -1,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,    -1,   264,   265,   266,    -1,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,    -1,   317,
      11,    12,    -1,   321,    -1,    16,    -1,    -1,    -1,    20,
      21,    22,    23,    24,    25,    26,    -1,    -1,    -1,    30,
      -1,    -1,    33,    34,    -1,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    -1,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    -1,    95,    96,    97,    98,    99,    -1,
     101,   102,   103,    -1,    -1,   106,   107,    -1,    -1,    -1,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
      -1,   122,    -1,    -1,    -1,   126,    -1,   128,   129,   130,
     131,    -1,   133,    -1,    -1,    -1,   137,   138,   139,   140,
     141,    -1,    -1,    -1,    -1,    -1,    -1,   148,   149,   150,
     151,   152,   153,    -1,   155,   156,    -1,   158,   159,    -1,
     161,   162,    -1,    -1,    -1,   166,   167,   168,   169,   170,
     171,   172,   173,    -1,   175,    -1,    -1,    -1,    -1,    -1,
     181,   182,   183,    -1,    -1,    -1,   187,    -1,   189,   190,
      -1,    -1,    -1,    -1,   195,    -1,   197,    -1,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,    -1,
      -1,   212,   213,   214,    -1,   216,    -1,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,    -1,   230,
      -1,   232,    -1,    -1,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     261,   262,    -1,   264,   265,   266,    -1,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,    -1,   317,    11,    12,    -1,
     321,    -1,    16,    -1,    -1,    -1,    20,    21,    22,    23,
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
      -1,   155,   156,    -1,   158,   159,    -1,   161,   162,    -1,
      -1,    -1,   166,   167,   168,   169,   170,   171,   172,   173,
      -1,   175,    -1,    -1,    -1,    -1,    -1,   181,   182,   183,
      -1,    -1,    -1,   187,    -1,   189,   190,    -1,    -1,    -1,
      -1,   195,    -1,   197,    -1,   199,    -1,   201,    -1,   203,
     204,   205,   206,   207,   208,   209,    -1,    -1,   212,   213,
     214,    -1,   216,    -1,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,    -1,   230,    -1,   232,    -1,
      -1,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,    -1,
     264,   265,   266,    -1,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,    -1,   317,    11,    12,    -1,   321,    -1,    16,
      -1,    -1,    -1,    20,    21,    22,    23,    24,    25,    26,
      -1,    -1,    -1,    30,    -1,    -1,    33,    34,    -1,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    -1,    51,    52,    53,    54,    -1,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    -1,    -1,    95,    96,
      97,    98,    99,    -1,   101,    -1,    -1,    -1,    -1,   106,
     107,    -1,    -1,    -1,   111,   112,   113,   114,   115,   116,
     117,    -1,   119,   120,    -1,   122,    -1,    -1,    -1,   126,
      -1,   128,   129,   130,   131,    -1,   133,    -1,    -1,    -1,
     137,    -1,   139,   140,   141,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   149,   150,   151,    -1,   153,    -1,   155,    -1,
      -1,   158,   159,    -1,    -1,   162,    -1,    -1,    -1,   166,
     167,   168,   169,   170,   171,   172,   173,    -1,   175,    -1,
      -1,   178,    -1,    -1,   181,   182,   183,    -1,    -1,    -1,
     187,    -1,   189,   190,    -1,    -1,    -1,    -1,    -1,    -1,
     197,    -1,   199,    -1,   201,    -1,   203,   204,   205,   206,
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
     307,   308,   309,   310,   311,   312,   313,   314,   315,    -1,
     317,    11,    12,   320,   321,    -1,    16,    -1,    -1,    -1,
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
     150,   151,    -1,   153,    -1,   155,    -1,    -1,    -1,   159,
      -1,    -1,   162,    -1,    -1,    -1,   166,   167,   168,   169,
     170,   171,   172,   173,    -1,   175,    -1,    -1,   178,    -1,
      -1,   181,   182,   183,    -1,    -1,    -1,   187,    -1,   189,
     190,    -1,    -1,    -1,    -1,    -1,    -1,   197,    -1,   199,
      -1,   201,    -1,   203,   204,   205,   206,   207,   208,   209,
      -1,    -1,   212,   213,   214,    -1,   216,    -1,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,    -1,   264,   265,   266,    -1,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,    -1,   317,    11,    12,
     320,   321,    -1,    16,    -1,    -1,    -1,    20,    21,    22,
      23,    24,    25,    26,    -1,    -1,    -1,    30,    -1,    -1,
      33,    34,    -1,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    -1,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    -1,    95,    96,    97,    98,    99,    -1,   101,   102,
     103,    -1,    -1,   106,   107,    -1,    -1,    -1,   111,   112,
     113,   114,   115,   116,   117,    -1,   119,   120,    -1,   122,
      -1,    -1,    -1,   126,    -1,   128,   129,   130,   131,    -1,
     133,    -1,    -1,    -1,   137,    -1,   139,   140,   141,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   149,   150,   151,    -1,
     153,    -1,   155,    -1,    -1,    -1,   159,    -1,    -1,   162,
      -1,    -1,    -1,   166,   167,   168,   169,   170,   171,   172,
     173,    -1,   175,    -1,    -1,   178,    -1,    -1,   181,   182,
     183,    -1,    -1,    -1,   187,    -1,   189,   190,    -1,    -1,
      -1,    -1,    -1,    -1,   197,    -1,   199,    -1,   201,    -1,
     203,   204,   205,   206,   207,   208,   209,    -1,    -1,   212,
     213,   214,    -1,   216,    -1,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,    -1,   230,    -1,   232,
      -1,    -1,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
      -1,   264,   265,   266,    -1,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,    -1,   317,    11,    12,    -1,   321,    -1,
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
      -1,    -1,   148,   149,   150,    -1,   152,   153,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   161,   162,    -1,    -1,    -1,
     166,   167,   168,   169,   170,   171,   172,   173,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   181,   182,   183,    -1,    -1,
      -1,   187,    -1,   189,   190,    -1,    -1,    -1,    -1,   195,
      -1,   197,    -1,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,    -1,    -1,   212,   213,    -1,    -1,
     216,    -1,   218,   219,    -1,    -1,    -1,   223,   224,   225,
     226,   227,   228,    -1,   230,    -1,   232,    -1,    -1,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,    -1,   264,   265,
     266,    -1,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,    11,
      12,    -1,    -1,    -1,    16,   321,    -1,    -1,    20,    -1,
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
     152,   153,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   161,
     162,    -1,    -1,    -1,   166,   167,   168,   169,   170,   171,
     172,   173,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   181,
     182,   183,    -1,    -1,    -1,   187,    -1,   189,   190,    -1,
      -1,    -1,    -1,   195,    -1,   197,    -1,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,    -1,    -1,
     212,   213,    -1,    -1,   216,    -1,   218,   219,    -1,    -1,
      -1,   223,   224,   225,   226,   227,   228,    -1,   230,    -1,
     232,    -1,    -1,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,    -1,   264,   265,   266,    -1,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,    16,    -1,    -1,    -1,    -1,    -1,   321,
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
     153,   154,    -1,    -1,    -1,   158,    -1,    -1,   161,   162,
      -1,    -1,    -1,   166,   167,   168,   169,   170,   171,   172,
     173,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   181,   182,
     183,    -1,    -1,    -1,   187,   188,   189,   190,    -1,    -1,
      -1,    -1,   195,    -1,   197,    -1,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,    -1,    -1,   212,
     213,    -1,    -1,   216,    -1,   218,   219,   220,    -1,    -1,
     223,   224,   225,   226,   227,   228,    -1,   230,    -1,   232,
      -1,    -1,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
      -1,   264,   265,   266,    -1,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,   311,   312,
     313,   314,    -1,    -1,    16,    -1,    -1,    -1,   321,   322,
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
     152,   153,   154,    -1,    -1,    -1,   158,    -1,    -1,   161,
     162,    -1,    -1,    -1,   166,   167,   168,   169,   170,   171,
     172,   173,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   181,
     182,   183,    -1,    -1,    -1,   187,   188,   189,   190,    -1,
      -1,    -1,    -1,    -1,    -1,   197,    -1,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,    -1,    -1,
     212,   213,    -1,    -1,   216,    -1,   218,   219,   220,    -1,
      -1,   223,   224,   225,   226,   227,   228,    -1,   230,    -1,
     232,    -1,    -1,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,    -1,   264,   265,   266,    -1,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,    -1,    -1,    16,    -1,    -1,    -1,   321,
     322,   323,   324,   325,    25,    26,    -1,    -1,    -1,    -1,
      -1,    -1,    33,    34,    -1,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    -1,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    -1,    95,    96,    97,    98,    -1,    -1,
     101,   102,   103,    -1,    -1,   106,   107,    -1,    -1,    -1,
      -1,   112,   113,   114,   115,   116,   117,   118,   119,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   128,   129,   130,
     131,    -1,   133,    -1,    -1,    -1,   137,   138,   139,   140,
     141,    -1,    -1,    -1,    -1,    -1,    -1,   148,   149,   150,
      -1,   152,   153,   154,    -1,    -1,    -1,   158,    -1,    -1,
     161,   162,    -1,    -1,    -1,   166,   167,   168,   169,   170,
     171,   172,   173,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     181,   182,   183,    -1,    -1,    -1,   187,    -1,   189,   190,
      -1,    -1,    -1,    -1,    -1,    -1,   197,    -1,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,    -1,
      -1,   212,   213,    -1,    -1,   216,    -1,   218,   219,   220,
      -1,    -1,   223,   224,   225,   226,   227,   228,    -1,   230,
      -1,   232,    -1,    -1,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     261,   262,    -1,   264,   265,   266,    -1,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,   309,   310,
     311,   312,   313,   314,    -1,    -1,    16,    -1,    -1,    -1,
     321,   322,   323,   324,   325,    25,    26,    -1,    -1,    -1,
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
     190,    -1,    -1,    -1,    -1,    -1,    -1,   197,    -1,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
      -1,    -1,   212,   213,    -1,    -1,   216,    -1,   218,   219,
     220,    -1,    -1,   223,   224,   225,   226,   227,   228,    -1,
     230,    -1,   232,    -1,    -1,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,    -1,   264,   265,   266,    -1,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,    -1,    -1,    16,    -1,    -1,
      -1,   321,   322,   323,   324,   325,    25,    26,    -1,    -1,
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
     149,   150,    -1,   152,   153,   154,    -1,    -1,    -1,   158,
      -1,    -1,   161,   162,    -1,    -1,    -1,   166,   167,   168,
     169,   170,   171,   172,   173,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   181,   182,   183,    -1,    -1,    -1,   187,    -1,
     189,   190,    -1,    -1,    -1,    -1,    -1,    -1,   197,    -1,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,    -1,    -1,   212,   213,    -1,    -1,   216,    -1,   218,
     219,   220,    -1,    -1,   223,   224,   225,   226,   227,   228,
      -1,   230,    -1,   232,    -1,    -1,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   262,    -1,   264,   265,   266,    -1,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,    -1,    -1,    16,    -1,
      -1,    -1,   321,   322,   323,   324,   325,    25,    26,    -1,
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
      -1,   189,   190,    -1,    -1,    -1,    -1,    -1,    -1,   197,
      -1,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,    -1,    -1,   212,   213,    -1,    -1,   216,    -1,
     218,   219,   220,    -1,    -1,   223,   224,   225,   226,   227,
     228,    -1,   230,    -1,   232,    -1,    -1,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,    -1,   264,   265,   266,    -1,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,    -1,    -1,    16,
      -1,    -1,    -1,   321,   322,   323,   324,   325,    25,    26,
      -1,    -1,    -1,    -1,    -1,    -1,    33,    34,    -1,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    -1,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    -1,    95,    96,
      97,    98,    -1,    -1,   101,   102,   103,    -1,    -1,   106,
     107,    -1,    -1,    -1,    -1,   112,   113,   114,   115,   116,
     117,   118,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
     227,   228,    -1,   230,    -1,   232,    -1,    -1,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   262,    -1,   264,   265,   266,
      -1,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,   309,   310,   311,   312,   313,   314,    -1,    -1,
      16,    -1,    -1,    -1,   321,   322,   323,   324,   325,    25,
      26,    -1,    -1,    -1,    30,    -1,    -1,    33,    34,    -1,
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
      -1,    -1,   148,   149,   150,    -1,   152,   153,    -1,    -1,
      -1,    -1,   158,    -1,    -1,   161,   162,    -1,    -1,    -1,
     166,   167,   168,   169,   170,   171,   172,   173,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   181,   182,   183,    -1,    -1,
      -1,   187,    -1,   189,   190,    -1,    -1,    -1,    -1,    -1,
      -1,   197,    -1,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,    -1,    -1,   212,   213,    -1,    -1,
     216,    -1,   218,   219,    -1,    -1,    -1,   223,   224,   225,
     226,   227,   228,    -1,   230,    -1,   232,    -1,    -1,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,    -1,   264,   265,
     266,    -1,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,    16,
      -1,    18,    19,    -1,    -1,   321,    -1,    -1,    25,    26,
      -1,    -1,    -1,    -1,    -1,    -1,    33,    34,    -1,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    -1,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    -1,    95,    96,
      97,    98,    -1,    -1,   101,   102,   103,    -1,    -1,   106,
     107,    -1,    -1,    -1,    -1,   112,   113,   114,   115,   116,
     117,   118,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   128,   129,   130,   131,    -1,   133,    -1,    -1,    -1,
     137,   138,   139,   140,   141,    -1,    -1,    -1,    -1,    -1,
      -1,   148,   149,   150,    -1,   152,   153,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   161,   162,    -1,    -1,    -1,   166,
     167,   168,   169,   170,   171,   172,   173,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   181,   182,   183,    -1,    -1,    -1,
     187,    -1,   189,   190,    -1,    -1,    -1,    -1,    -1,    -1,
     197,    -1,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,    -1,    -1,   212,   213,    -1,    -1,   216,
      -1,   218,   219,    -1,    -1,    -1,   223,   224,   225,   226,
     227,   228,    -1,   230,    -1,   232,    -1,    -1,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   262,    -1,   264,   265,   266,
      -1,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,   309,   310,   311,   312,   313,   314,    16,    -1,
      -1,    -1,    -1,    -1,   321,    -1,    -1,    25,    26,    -1,
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
     148,   149,   150,    -1,   152,   153,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   161,   162,    -1,    -1,    -1,   166,   167,
     168,   169,   170,   171,   172,   173,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   181,   182,   183,    -1,    -1,    -1,   187,
     188,   189,   190,    -1,    -1,    -1,    -1,   195,    -1,   197,
      -1,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,    -1,    -1,   212,   213,    -1,    -1,   216,    -1,
     218,   219,    -1,    -1,    -1,   223,   224,   225,   226,   227,
     228,    -1,   230,    -1,   232,    -1,    -1,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,    -1,   264,   265,   266,    -1,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,    16,    -1,    -1,
      -1,    -1,    -1,   321,    -1,    -1,    25,    26,    -1,    -1,
      -1,    30,    -1,    -1,    33,    34,    -1,    36,    37,    38,
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
     149,   150,    -1,   152,   153,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   161,   162,    -1,    -1,    -1,   166,   167,   168,
     169,   170,   171,   172,   173,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   181,   182,   183,    -1,    -1,    -1,   187,   188,
     189,   190,    -1,    -1,    -1,    -1,    -1,    -1,   197,    -1,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,    -1,    -1,   212,   213,    -1,    -1,   216,    -1,   218,
     219,    -1,    -1,    -1,   223,   224,   225,   226,   227,   228,
      -1,   230,    -1,   232,    -1,    -1,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   262,    -1,   264,   265,   266,    -1,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,    16,    -1,    -1,    -1,
      -1,    -1,   321,    -1,    -1,    25,    26,    -1,    -1,    -1,
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
     150,    -1,   152,   153,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   161,   162,    -1,    -1,    -1,   166,   167,   168,   169,
     170,   171,   172,   173,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   181,   182,   183,    -1,    -1,    -1,   187,   188,   189,
     190,    -1,    -1,    -1,    -1,   195,    -1,   197,    -1,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
      -1,    -1,   212,   213,    -1,    -1,   216,    -1,   218,   219,
      -1,    -1,    -1,   223,   224,   225,   226,   227,   228,    -1,
     230,    -1,   232,    -1,    -1,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,    -1,   264,   265,   266,    -1,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,    16,    -1,    -1,    -1,    -1,
      -1,   321,    -1,    -1,    25,    26,    -1,    -1,    -1,    -1,
      -1,    -1,    33,    34,    -1,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    -1,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    -1,    95,    96,    97,    98,    -1,    -1,
     101,   102,   103,    -1,    -1,   106,   107,    -1,    -1,    -1,
      -1,   112,   113,   114,   115,   116,   117,   118,   119,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   128,   129,   130,
     131,    -1,   133,    -1,    -1,    -1,   137,   138,   139,   140,
     141,    -1,    -1,    -1,    -1,    -1,    -1,   148,   149,   150,
      -1,   152,   153,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     161,   162,    -1,    -1,    -1,   166,   167,   168,   169,   170,
     171,   172,   173,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     181,   182,   183,    -1,    -1,    -1,   187,    -1,   189,   190,
      -1,    -1,    -1,    -1,    -1,    -1,   197,    -1,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,    -1,
      -1,   212,   213,    -1,    -1,   216,    -1,   218,   219,    -1,
      -1,    -1,   223,   224,   225,   226,   227,   228,    -1,   230,
      -1,   232,    -1,    -1,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     261,   262,    -1,   264,   265,   266,    -1,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,   309,   310,
     311,   312,   313,   314,    16,    -1,    -1,    -1,    -1,    -1,
     321,    -1,    -1,    25,    26,    -1,    -1,    -1,    -1,    -1,
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
     152,   153,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   161,
     162,    -1,    -1,    -1,   166,   167,   168,   169,   170,   171,
     172,   173,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   181,
     182,   183,    -1,    -1,    -1,   187,    -1,   189,   190,    -1,
      -1,    -1,    -1,    -1,    -1,   197,    -1,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,    -1,    -1,
     212,   213,    -1,    -1,   216,    -1,   218,   219,    -1,    -1,
      -1,   223,   224,   225,   226,   227,   228,    -1,   230,    -1,
     232,    -1,    -1,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,    -1,   264,   265,   266,    -1,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,    21,    22,    23,    24,    25,    26,   321,
      -1,    -1,    30,    -1,    -1,    33,    34,    -1,    36,    37,
      38,    39,    40,    41,    42,    43,    -1,    45,    46,    47,
      -1,    49,    50,    51,    52,    -1,    54,    -1,    56,    57,
      58,    59,    60,    61,    -1,    -1,    64,    65,    66,    67,
      68,    -1,    70,    71,    72,    -1,    -1,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    -1,    95,    96,    97,
      98,    -1,    -1,   101,   102,   103,    -1,    -1,   106,   107,
      -1,    -1,    -1,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,    -1,    -1,    -1,    -1,    -1,   126,    -1,
     128,   129,   130,   131,    -1,   133,    -1,    -1,    -1,   137,
     138,   139,   140,   141,    -1,    -1,    -1,    -1,    -1,    -1,
     148,   149,   150,   151,   152,   153,    -1,   155,   156,    -1,
     158,   159,    -1,   161,   162,    -1,    -1,    -1,   166,   167,
     168,   169,   170,   171,   172,   173,    -1,   175,    -1,    -1,
      -1,    -1,    -1,   181,   182,   183,    -1,    -1,    -1,   187,
      -1,   189,   190,    -1,    -1,    -1,    -1,    -1,    -1,   197,
      -1,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,    -1,    -1,    -1,   213,   214,    -1,   216,    -1,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,    -1,   230,    -1,   232,    -1,    -1,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
      -1,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,    -1,   264,   265,   266,    -1,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,    -1,   317,
      -1,   319,    -1,   321,    21,    22,    23,    24,    25,    26,
      -1,    -1,    -1,    30,    -1,    -1,    33,    34,    -1,    36,
      37,    38,    39,    40,    41,    42,    43,    -1,    45,    46,
      47,    -1,    49,    50,    51,    52,    -1,    54,    -1,    56,
      57,    58,    59,    60,    61,    -1,    -1,    64,    65,    66,
      67,    68,    -1,    70,    71,    72,    -1,    -1,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    -1,    95,    96,
      97,    98,    -1,    -1,   101,   102,   103,    -1,    -1,   106,
     107,    -1,    -1,    -1,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,    -1,    -1,    -1,    -1,    -1,   126,
      -1,   128,   129,   130,   131,    -1,   133,    -1,    -1,    -1,
     137,   138,   139,   140,   141,    -1,    -1,    -1,    -1,    -1,
      -1,   148,   149,   150,   151,   152,   153,    -1,   155,   156,
      -1,   158,   159,    -1,   161,   162,    -1,    -1,    -1,   166,
     167,   168,   169,   170,   171,   172,   173,    -1,   175,    -1,
      -1,    -1,    -1,    -1,   181,   182,   183,    -1,    -1,    -1,
     187,    -1,   189,   190,    -1,    -1,    -1,    -1,    -1,    -1,
     197,    -1,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,    -1,    -1,    -1,   213,   214,    -1,   216,
      -1,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,    -1,   230,    -1,   232,    -1,    -1,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,    -1,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   262,    -1,   264,   265,   266,
      -1,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,    -1,
     317,    -1,   319,    -1,   321,    21,    22,    23,    24,    25,
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
      -1,   187,    -1,   189,   190,    -1,    -1,    -1,    -1,    -1,
      -1,   197,    -1,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,    -1,    -1,    -1,   213,   214,    -1,
     216,    -1,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,    -1,   230,    -1,   232,    -1,    -1,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,    -1,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,    -1,   264,   265,
     266,    -1,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
      -1,   317,    -1,    -1,    -1,   321,    21,    22,    23,    24,
      25,    26,    -1,    -1,    -1,    30,    -1,    -1,    33,    34,
      -1,    36,    37,    38,    39,    40,    41,    42,    43,    -1,
      45,    46,    47,    -1,    49,    50,    51,    52,    -1,    54,
      -1,    56,    57,    58,    59,    60,    61,    -1,    -1,    64,
      65,    66,    67,    68,    -1,    70,    71,    72,    -1,    -1,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    -1,
      95,    96,    97,    98,    -1,    -1,   101,   102,   103,    -1,
      -1,   106,   107,    -1,    -1,    -1,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,    -1,    -1,    -1,    -1,
      -1,   126,    -1,   128,   129,   130,   131,    -1,   133,    -1,
      -1,    -1,   137,   138,   139,   140,   141,    -1,    -1,    -1,
      -1,    -1,    -1,   148,   149,   150,   151,   152,   153,    -1,
     155,   156,    -1,   158,   159,    -1,   161,   162,    -1,    -1,
      -1,   166,   167,   168,   169,   170,   171,   172,   173,    -1,
     175,    -1,    -1,    -1,    -1,    -1,   181,   182,   183,    -1,
      -1,    -1,   187,    -1,   189,   190,    -1,    -1,    -1,    -1,
      -1,    -1,   197,    -1,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,    -1,    -1,    -1,   213,   214,
      -1,   216,    -1,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,    -1,    -1,    -1,   232,    -1,    -1,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,    -1,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,    -1,   264,
     265,   266,    -1,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,    -1,   317,    25,    26,    -1,   321,    -1,    -1,    -1,
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
     182,   183,    -1,    -1,    -1,   187,    -1,   189,   190,    -1,
      -1,    -1,    -1,    -1,    -1,   197,    -1,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,    -1,    -1,
      -1,   213,    -1,    -1,   216,    -1,   218,   219,    -1,    -1,
      -1,   223,   224,   225,   226,   227,   228,    -1,    -1,    -1,
     232,    -1,    -1,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,    -1,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,    -1,   264,   265,   266,    -1,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,    -1,    -1,    -1,    -1,    -1,    -1,   321
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
     155,   156,   158,   159,   160,   161,   162,   166,   167,   168,
     169,   170,   171,   172,   173,   175,   177,   178,   181,   182,
     183,   187,   189,   190,   191,   192,   193,   195,   197,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     212,   213,   214,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     264,   265,   266,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   317,   320,   321,   326,   327,   344,   346,   347,   348,
     349,   350,   351,   352,   353,   354,   355,   356,   357,   358,
     359,   360,   361,   362,   365,   366,   367,   368,   369,   370,
     374,   375,   376,   380,   382,   383,   385,   392,   394,   397,
     398,   399,   401,   402,   403,   404,   405,   407,   408,   410,
     411,   412,   413,   414,   415,   417,   418,   421,   422,   423,
     424,   425,   430,   432,   434,   435,   436,   441,   460,   463,
     467,   470,   471,   477,   478,   479,   480,   481,   482,   483,
     485,   486,   487,   488,   489,   490,   491,   492,   493,   495,
     496,   497,   498,   500,   501,   502,   503,   504,   505,   506,
     507,   508,   509,   510,   511,   512,   513,   514,   515,   516,
     517,   520,   521,   522,   523,   524,   525,   526,   527,   528,
     529,   531,   532,   533,   534,   535,   536,   550,   551,   553,
     554,   555,   556,   557,   558,   559,   560,   568,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   579,   582,
     587,   588,   589,   590,   591,   592,   595,   653,   654,   655,
     656,   658,   659,   660,   661,   662,   668,   669,   670,    33,
      34,    49,   216,   400,   401,   402,   400,   400,   401,   402,
     158,   158,    37,    38,    40,    41,    47,    57,    58,    75,
      80,   112,   113,   114,   162,   225,   266,   292,   300,   308,
     381,   382,   386,   387,   388,   162,   155,   158,   155,   158,
     155,   158,     1,   158,   389,   158,    25,    34,    61,   119,
     278,   440,   442,   443,   158,   155,   158,   158,   158,   119,
     155,   158,   158,   158,    77,   155,   226,   227,   124,   124,
     124,   155,   158,    39,    43,    45,    46,    47,    48,    51,
      60,    68,    71,    73,    74,    76,    91,    92,    98,   106,
     113,   115,   116,   137,   140,   141,   162,   170,   173,   181,
     182,   190,   203,   241,   243,   244,   245,   248,   249,   262,
     265,   514,   669,   124,   119,   409,   124,   124,    39,    44,
      45,    53,    60,    62,    63,    71,    98,   230,   668,   119,
     124,   124,   400,   402,   423,   657,   668,    48,    73,    74,
     119,   155,   186,   249,   422,   424,   434,   188,   422,   668,
     155,   155,   124,   668,    18,    19,   668,   124,   124,   124,
     506,   155,    31,   215,   218,   218,    39,    45,    60,    71,
      98,   230,   232,   319,   517,   669,   230,   232,   319,   423,
     657,   230,   319,   517,   230,   235,   319,   119,   246,   246,
     247,   158,   155,   404,     1,   480,   316,   422,   318,   422,
     319,   423,   327,   346,   346,     0,   348,   349,    33,    49,
     351,   368,     1,   191,   345,   191,   345,   113,   383,   403,
     422,   108,   191,   108,   345,   191,    42,    46,    51,    70,
     169,   172,   187,   213,   262,   416,   426,   431,   432,   433,
     448,   449,   453,     3,    67,    72,   119,   427,   168,    93,
     204,   205,   206,   207,   208,   209,   499,   254,   100,   160,
     177,   200,   118,   148,   161,   195,   202,   211,   138,   152,
      50,   201,   102,   103,   160,   177,   497,   194,   155,   503,
     506,   192,   193,   156,   518,   519,   514,   518,   514,   121,
     158,   518,   158,   147,   158,   185,   185,   185,   185,   384,
     521,   384,    30,   667,   183,   197,   183,   197,   167,   183,
     669,   668,   170,   203,    47,   668,   154,   119,    45,    47,
      80,   107,   169,   668,   226,   227,   228,   251,   626,   668,
     668,   309,   139,   144,   113,   292,   300,   386,   668,   401,
     188,   401,    45,    63,   188,   578,   579,   422,   188,   195,
     668,   437,   438,   668,   119,   188,   390,   391,   155,   406,
     422,     1,   162,   667,   114,   162,   364,   667,   668,   119,
     144,   108,   188,   422,    30,   188,   668,   668,   668,   461,
     462,   668,   401,   188,   422,   422,   580,   668,   401,   155,
     155,   422,   188,   195,   668,   668,   144,   461,   185,   185,
     123,   108,   185,   123,   158,   158,   158,   668,   155,   186,
     187,   188,    35,   538,   539,   540,   422,   422,     8,   176,
      17,   422,   215,    30,    30,   423,   423,   517,   423,   423,
     423,   657,   238,   238,   423,   517,    95,   423,   236,   235,
     593,   594,   668,   191,   191,   423,   422,   402,   422,   250,
     419,   420,   437,   316,   318,   423,   238,   346,   191,   345,
     191,   345,     3,   352,   368,   398,     1,   352,   368,   398,
      33,   369,   398,   369,   398,   409,   345,   409,   423,   423,
     119,   169,   171,   171,   403,   423,   423,   289,   289,   437,
     119,   444,   479,   480,   482,    71,   483,   487,   487,   486,
     488,   488,   488,   488,   489,   489,   490,   490,   236,    95,
      95,    95,   504,   185,   422,   506,   506,   422,   519,   158,
     524,   582,   668,   146,   188,   423,   530,   188,   151,   188,
     530,   108,   188,   188,   108,   108,   389,    30,   669,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,   371,
     372,   373,    95,   139,   144,   377,   378,   379,   668,   162,
     162,   371,   667,   129,   134,    55,    57,   101,   256,   269,
     271,   282,   283,   284,   286,   288,   627,   628,   629,   630,
     631,   632,   639,   645,   646,   251,    95,   304,   668,   144,
     423,   119,   668,   668,   134,   185,   185,   188,   188,   185,
     108,   188,   108,   188,   108,    36,    95,    97,   149,   439,
     440,   561,   668,    95,   108,   188,   400,   188,   668,    97,
      45,   668,   667,    97,   144,   561,   668,   423,   443,   185,
     188,   188,   188,   188,   108,   189,   149,   561,   185,   188,
     188,   155,   185,   401,   401,   185,   108,   188,   108,   188,
     144,   561,   423,   189,   423,   423,   668,   423,   422,   422,
     422,   668,   539,   540,   132,   198,   185,   185,   185,   133,
     191,   133,   191,    95,   223,   224,   238,    95,   223,   224,
     238,   238,   238,   423,   423,    95,    95,   423,   242,   230,
     517,   236,   108,   240,   144,   191,   188,   422,   185,   515,
     599,   420,   238,   423,   368,    33,    33,   191,   345,   191,
     114,   403,   668,   171,   423,   454,   455,   119,   423,   450,
     451,   668,    56,   219,   259,   428,   429,   155,   158,   264,
     502,   521,   600,   603,   604,   605,   606,   607,   611,   613,
     615,   616,    47,   154,   158,   212,   220,   322,   323,   324,
     325,   562,   564,   566,   568,   583,   584,   585,   586,   663,
     664,   665,   666,   668,   562,   494,   567,   668,   494,   185,
     186,   188,   422,   108,   188,   188,   521,   150,   166,   150,
     166,   139,   406,   389,   372,   134,   158,   564,   379,   423,
     561,   667,   667,   130,   131,   667,   282,   283,   284,   288,
     668,   268,   279,   268,   279,    30,   291,    97,   114,   158,
     633,   636,   627,    39,    44,    53,    60,    62,    71,    98,
     230,   393,   568,   663,   232,   304,   313,   423,   668,    95,
     304,   667,   155,   580,   581,   668,   580,   581,   119,   438,
     129,   562,   119,   423,   149,   440,   149,    36,   149,   439,
     440,   561,   562,   391,    95,   185,   199,   134,   363,   667,
     162,   134,    97,   363,   423,   144,   440,   155,   119,   423,
     423,   149,   101,   464,   465,   466,   468,   469,   101,   472,
     473,   474,   475,   401,   185,   185,   155,   580,   580,   423,
     144,   191,   423,   123,   123,   188,   188,   188,    35,   540,
     132,   198,     9,    10,   104,   125,   127,   155,   196,   535,
     537,   548,   549,   552,   155,    30,    30,   237,   239,   423,
     423,   423,   237,   239,   423,   423,   423,   423,   423,    97,
     423,   423,   423,   423,   242,   517,   119,   423,   423,    48,
      73,    74,   249,   403,   424,   434,   250,   596,   597,   155,
     211,   404,   423,   191,   114,   398,   398,   398,   454,    96,
     107,   117,   129,   456,   457,   458,   459,   108,   668,   107,
     452,   108,   149,   561,   259,    54,    59,    78,   119,   439,
     445,   446,   447,   429,   422,   600,   607,   155,   290,   484,
     652,    97,   170,   257,   258,   260,   267,   277,   289,   601,
     602,   621,   622,   623,   624,   647,   650,   263,   265,   608,
     626,   272,   612,   648,   252,   253,   275,   617,   618,   158,
     158,   188,   564,   158,   158,   158,   158,   158,   146,   177,
     195,   563,   146,   188,   146,   423,   139,   406,   582,   378,
     291,    30,    97,   114,   158,   640,    30,   633,   563,   563,
     504,   292,   311,   561,   393,   232,   191,   400,   188,   188,
     146,   188,   188,   438,   149,   439,   668,   423,   149,   423,
     129,   423,   149,   440,   149,   562,   403,   423,   667,   108,
     363,   423,   144,   400,   462,   423,   423,   114,   465,   466,
     101,   187,   114,   466,   469,   119,   476,   562,   101,   114,
     473,   101,   114,   475,   185,   400,   188,   188,   423,   423,
     423,   199,   472,   134,   196,   537,     7,   401,   668,   196,
     548,   401,   191,   191,   238,   238,   238,   238,    97,   321,
     242,   423,   242,   594,   187,   158,   158,   158,   187,   599,
     597,   515,   667,   130,   131,   458,   459,   459,   455,   144,
     452,   561,   667,   451,   423,   149,   119,   119,   423,   668,
     447,    78,   185,   188,   600,   614,   255,   219,   259,   273,
     280,   651,    97,   261,   262,   649,   255,   604,   651,   486,
     621,   605,   149,   287,   609,   610,   649,   291,   620,    79,
     619,   188,   195,   562,   565,   188,   188,   188,   188,   188,
     188,   188,    30,   138,   202,   642,   643,   644,    30,   641,
     642,   276,   637,   108,   634,   171,   668,   262,   504,   185,
     423,   149,   423,   149,   439,   423,   149,   423,   128,   128,
      97,   667,   423,   185,   187,   187,   423,   403,   423,   187,
     187,   668,   187,   211,   119,   476,   119,   187,   119,   476,
     187,   185,   114,   540,   668,   196,   185,   540,   668,   185,
     423,   423,   423,   423,   321,   423,   423,   423,   423,   422,
     422,   422,   155,   598,   459,   423,   144,   423,   668,   668,
     446,   423,   185,   488,    52,   131,   486,   486,   274,   281,
     291,   625,   625,   606,   155,   285,    95,   188,   108,   188,
     640,   640,   644,   108,   188,    30,   638,   649,   635,   636,
     188,   395,   396,   504,   119,   230,   312,   292,   171,   423,
     423,   149,   423,   403,   423,   363,   423,   403,    95,   403,
     423,   562,   668,   187,   668,   423,   668,   187,   403,   119,
      94,   184,   541,   540,   668,   198,   540,   423,   188,   188,
     188,   422,   452,   423,    54,   486,   486,   200,   422,   562,
     562,    95,    30,   270,   108,   108,   459,   561,   668,   119,
     230,   668,   395,   423,   476,    95,   187,    95,   668,     5,
     135,   544,   545,   547,   549,    29,   136,   542,   543,   546,
     549,   198,   540,   198,   199,   472,   185,   452,   119,   486,
     185,   562,   636,   396,   459,   310,   668,   119,   230,   187,
     476,   403,   423,   476,   187,    94,   135,   547,   184,   136,
     546,   198,   114,   668,   423,   310,   668,   119,   403,   423,
     187,   187,   119,   298,   310,   668,   668,   311,   423,   311,
     187,   504,   504,   200,   292,   668,   230,   119,   668,   311,
     504
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
     595,   596,   597
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned short int
  jsoniq_parser::yyr1_[] =
  {
         0,   343,   344,   344,   344,   344,   345,   345,   345,   346,
     346,   346,   346,   347,   347,   347,   347,   348,   348,   348,
     348,   348,   348,   348,   348,   349,   349,   349,   349,   350,
     351,   351,   351,   352,   352,   352,   352,   352,   353,   353,
     353,   353,   353,   353,   353,   353,   354,   354,   355,   356,
     357,   357,   358,   358,   359,   359,   360,   360,   360,   360,
     361,   361,   361,   362,   362,   362,   362,   363,   363,   364,
     364,   365,   365,   365,   365,   366,   367,   367,   368,   368,
     368,   369,   369,   369,   369,   369,   369,   369,   369,   370,
     370,   371,   371,   372,   373,   373,   373,   373,   373,   373,
     373,   373,   373,   373,   374,   375,   376,   377,   377,   378,
     378,   378,   379,   380,   380,   380,   381,   381,   381,   381,
     382,   382,   383,   383,   383,   383,   384,   384,   385,   385,
     386,   386,   387,   387,   388,   388,   389,   389,   389,   389,
     390,   390,   391,   391,   392,   392,   392,   392,   393,   393,
     393,   393,   394,   394,   395,   395,   396,   396,   396,   396,
     397,   397,   397,   397,   398,   399,   399,   399,   400,   400,
     400,   401,   401,   402,   402,   402,   403,   403,   403,   403,
     403,   403,   403,   403,   403,   403,   403,   403,   403,   404,
     405,   406,   407,   408,   408,   408,   409,   409,   409,   409,
     410,   411,   412,   413,   414,   414,   415,   416,   417,   418,
     419,   419,   420,   421,   422,   422,   422,   423,   423,   423,
     423,   423,   423,   424,   424,   424,   424,   424,   424,   424,
     424,   424,   424,   424,   424,   425,   426,   427,   427,   428,
     428,   428,   429,   429,   430,   430,   431,   432,   432,   432,
     433,   433,   433,   433,   433,   434,   434,   435,   435,   435,
     435,   436,   436,   437,   437,   437,   438,   438,   438,   438,
     438,   438,   438,   438,   438,   438,   438,   438,   439,   440,
     441,   442,   442,   443,   443,   443,   443,   444,   444,   445,
     445,   445,   446,   446,   446,   447,   447,   447,   448,   449,
     450,   450,   451,   451,   451,   451,   451,   451,   451,   452,
     453,   453,   454,   454,   455,   455,   456,   456,   456,   456,
     456,   456,   456,   457,   457,   458,   458,   459,   460,   460,
     461,   461,   462,   462,   463,   464,   464,   465,   466,   466,
     467,   468,   468,   469,   470,   470,   471,   471,   472,   472,
     473,   473,   474,   474,   475,   475,   476,   476,   477,   478,
     478,   479,   479,   480,   480,   481,   481,   482,   482,   483,
     483,   484,   484,   485,   485,   486,   486,   486,   487,   487,
     487,   487,   487,   488,   488,   488,   489,   489,   489,   490,
     490,   491,   491,   492,   492,   493,   493,   494,   494,   495,
     495,   496,   496,   496,   496,   497,   497,   497,   498,   498,
     499,   499,   499,   499,   499,   499,   500,   500,   500,   500,
     501,   501,   502,   502,   503,   503,   503,   504,   504,   504,
     504,   505,   506,   506,   506,   507,   507,   508,   508,   508,
     508,   509,   509,   510,   510,   510,   510,   510,   510,   510,
     511,   511,   512,   512,   513,   513,   513,   513,   513,   514,
     514,   515,   515,   516,   516,   516,   516,   517,   517,   517,
     517,   517,   517,   517,   517,   517,   518,   518,   519,   520,
     520,   520,   520,   520,   520,   520,   520,   520,   520,   520,
     520,   520,   520,   521,   521,   521,   521,   522,   522,   522,
     523,   523,   524,   525,   525,   526,   527,   528,   529,   529,
     530,   530,   530,   530,   531,   531,   532,   533,   534,   534,
     535,   535,   535,   536,   536,   536,   536,   536,   536,   537,
     537,   538,   538,   539,   540,   540,   541,   541,   542,   542,
     543,   543,   543,   543,   544,   544,   545,   545,   545,   545,
     546,   546,   547,   547,   548,   548,   548,   548,   549,   549,
     549,   549,   550,   550,   551,   551,   552,   553,   553,   553,
     553,   553,   553,   553,   554,   555,   555,   556,   556,   557,
     558,   559,   559,   560,   560,   561,   562,   562,   562,   562,
     563,   563,   563,   564,   564,   564,   564,   564,   564,   564,
     564,   564,   565,   565,   566,   566,   567,   568,   568,   568,
     568,   568,   568,   568,   568,   568,   568,   569,   570,   571,
     571,   571,   572,   573,   574,   575,   575,   575,   576,   576,
     576,   576,   576,   577,   578,   578,   578,   578,   578,   578,
     578,   579,   580,   581,   582,   583,   583,   584,   585,   585,
     586,   587,   587,   587,   588,   588,   588,   588,   588,   588,
     588,   588,   588,   588,   589,   589,   590,   590,   591,   592,
     593,   593,   594,   595,   596,   596,   597,   598,   599,   599,
     600,   601,   601,   602,   602,   603,   603,   604,   604,   605,
     605,   606,   606,   607,   608,   608,   609,   609,   610,   611,
     611,   611,   612,   612,   613,   614,   614,   615,   616,   616,
     617,   617,   618,   618,   618,   619,   619,   620,   620,   621,
     621,   621,   621,   621,   622,   623,   624,   625,   625,   625,
     626,   626,   627,   627,   627,   627,   627,   627,   627,   627,
     628,   628,   628,   628,   629,   629,   630,   631,   631,   632,
     632,   632,   633,   633,   634,   634,   635,   635,   636,   637,
     637,   638,   638,   639,   639,   639,   640,   640,   641,   641,
     642,   642,   643,   643,   644,   644,   645,   646,   646,   647,
     647,   647,   648,   649,   649,   649,   649,   650,   650,   651,
     651,   652,   653,   653,   654,   654,   655,   655,   656,   657,
     657,   657,   657,   658,   658,   658,   658,   658,   658,   659,
     659,   660,   660,   661,   661,   662,   662,   663,   663,   663,
     664,   664,   665,   665,   666,   666,   667,   668,   668,   668,
     668,   668,   668,   668,   668,   668,   668,   668,   668,   668,
     668,   668,   668,   668,   669,   669,   669,   669,   669,   669,
     669,   669,   669,   669,   669,   669,   669,   669,   669,   669,
     669,   669,   669,   669,   669,   669,   669,   669,   669,   669,
     669,   669,   669,   669,   669,   669,   669,   669,   669,   669,
     669,   669,   669,   669,   669,   669,   669,   669,   669,   669,
     669,   669,   669,   669,   669,   669,   669,   669,   669,   669,
     669,   669,   669,   669,   669,   669,   669,   669,   669,   669,
     669,   669,   669,   669,   669,   669,   669,   669,   669,   669,
     669,   669,   669,   669,   669,   669,   669,   669,   669,   669,
     669,   669,   669,   669,   669,   669,   669,   669,   669,   669,
     669,   669,   669,   669,   669,   669,   669,   669,   669,   669,
     669,   669,   669,   669,   669,   669,   669,   669,   669,   669,
     669,   669,   669,   669,   669,   669,   669,   669,   669,   669,
     669,   669,   669,   669,   669,   669,   669,   669,   669,   669,
     669,   669,   669,   669,   669,   669,   669,   669,   669,   669,
     669,   669,   669,   669,   669,   669,   669,   669,   669,   669,
     669,   669,   669,   669,   669,   669,   669,   669,   669,   669,
     669,   669,   669,   669,   669,   669,   669,   669,   669,   669,
     669,   669,   669,   669,   669,   669,   669,   669,   669,   669,
     669,   669,   669,   669,   669,   669,   669,   669,   669,   669,
     670
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
       1,     3,     4,     5,     6,     5,     3,     1,     2,     2,
       3,     4,     1,     3,     1,     2,     1,     1,     1,     2,
       2,     2,     3,     1,     1,     2,     2,     2,     5,     5,
       1,     4,     3,     4,     8,     1,     2,     3,     2,     3,
       8,     1,     2,     3,     8,    10,     8,    10,     1,     2,
       4,     7,     1,     2,     4,     7,     1,     3,     8,     1,
       3,     1,     3,     1,     2,     1,     3,     1,     5,     1,
       3,     0,     1,     1,     3,     1,     3,     3,     1,     3,
       3,     3,     3,     1,     3,     3,     1,     3,     3,     1,
       4,     1,     4,     1,     4,     1,     4,     1,     2,     1,
       2,     1,     1,     2,     2,     1,     1,     1,     1,     3,
       1,     1,     1,     1,     1,     1,     4,     5,     5,     6,
       3,     4,     1,     2,     3,     2,     2,     1,     2,     2,
       1,     1,     1,     3,     3,     1,     1,     1,     2,     1,
       2,     2,     1,     2,     2,     2,     2,     2,     2,     2,
       1,     2,     2,     1,     2,     2,     2,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     3,
       4,     3,     4,     5,     3,     3,     1,     2,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     2,     3,     1,     4,     4,     3,     4,
       1,     3,     1,     3,     1,     1,     3,     3,     1,     1,
       1,     1,     1,     4,     8,     5,     9,     9,    10,     1,
       2,     1,     2,     6,     0,     1,     3,     3,     0,     1,
       1,     1,     2,     2,     0,     1,     1,     1,     2,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     3,     2,     3,     3,     2,     1,     1,     1,
       1,     1,     1,     1,     4,     3,     7,     3,     7,     4,
       4,     3,     7,     3,     7,     2,     1,     2,     3,     2,
       1,     1,     1,     1,     1,     3,     1,     3,     1,     1,
       1,     1,     1,     3,     1,     1,     1,     1,     1,     1,
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
       3,     5,     5,     5,     5,     8,     4,     4,     7,     5,
       4,     3,     2,     5,     4,     7,     6,     1,     1,     1,
       3,     1,     3,     1,     3,     1,     1,     1,     1,     1,
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
       1
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
  "GROUPBY_VAR_REDUCE", "GROUPBY_VAR_REDUCE2", "$accept", "Module",
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
  "LeadingSlash", "RelativePathExpr", "StepExpr", "AxisStep",
  "ForwardStep", "ForwardAxis", "AbbrevForwardStep", "ReverseStep",
  "ReverseAxis", "NodeTest", "NameTest", "Wildcard", "FilterExpr",
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
  "JSONTest", "JSONItemTest", "JSONObjectTest", "JSONArrayTest",
  "URI_LITERAL", "QNAME", "FUNCTION_NAME", "EQNAME", 0
  };
#endif

#if YYDEBUG
  /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
  const jsoniq_parser::rhs_number_type
  jsoniq_parser::yyrhs_[] =
  {
       344,     0,    -1,   346,    -1,   326,   346,    -1,   327,   346,
      -1,   326,   327,   346,    -1,     1,    -1,     1,     3,    -1,
     345,     1,    -1,   348,    -1,   347,   348,    -1,   349,    -1,
     347,   349,    -1,   216,   218,    30,   191,    -1,   216,   218,
      30,   133,    30,   191,    -1,   217,   218,    30,   191,    -1,
     217,   218,    30,   133,    30,   191,    -1,   351,   191,   398,
      -1,   368,   191,   398,    -1,   351,   191,   368,   191,   398,
      -1,   398,    -1,   351,   345,   398,    -1,   368,   345,   398,
      -1,   351,   191,   368,   345,   398,    -1,   351,   345,   368,
     191,   398,    -1,   350,    -1,   350,   351,   191,    -1,   350,
     368,   191,    -1,   350,   351,   191,   368,   191,    -1,    34,
     162,   668,   134,   667,   191,    -1,   352,    -1,   351,   191,
     352,    -1,   351,   345,   352,    -1,   353,    -1,   361,    -1,
     366,    -1,   367,    -1,   375,    -1,   354,    -1,   355,    -1,
     356,    -1,   357,    -1,   358,    -1,   359,    -1,   360,    -1,
     587,    -1,    33,    38,   183,    -1,    33,    38,   197,    -1,
      33,   114,   107,   667,    -1,    33,    37,   667,    -1,    33,
      40,   183,    -1,    33,    40,   197,    -1,    33,    58,   170,
      -1,    33,    58,   203,    -1,    33,   114,   169,   129,   130,
      -1,    33,   114,   169,   129,   131,    -1,    33,    41,   183,
     108,   150,    -1,    33,    41,   183,   108,   166,    -1,    33,
      41,   167,   108,   150,    -1,    33,    41,   167,   108,   166,
      -1,   362,    -1,   365,    -1,    49,    25,     1,    -1,    49,
      61,   667,    -1,    49,    61,   364,   667,    -1,    49,    61,
     667,    97,   363,    -1,    49,    61,   364,   667,    97,   363,
      -1,   667,    -1,   363,   108,   667,    -1,   162,   668,   134,
      -1,   114,    45,   162,    -1,    49,    34,   667,    -1,    49,
      34,   162,   668,   134,   667,    -1,    49,    34,   667,    97,
     363,    -1,    49,    34,   162,   668,   134,   667,    97,   363,
      -1,    33,   162,   668,   134,   667,    -1,    33,   114,    45,
     162,   667,    -1,    33,   114,    47,   162,   667,    -1,   369,
      -1,   368,   191,   369,    -1,   368,   345,   369,    -1,   370,
      -1,   374,    -1,   376,    -1,   380,    -1,   385,    -1,   392,
      -1,   394,    -1,   397,    -1,    33,   114,    80,   371,    -1,
      33,    80,   668,   371,    -1,   372,    -1,   371,   372,    -1,
     373,   134,   582,    -1,    81,    -1,    89,    -1,    82,    -1,
      83,    -1,    84,    -1,    85,    -1,    90,    -1,    86,    -1,
      87,    -1,    88,    -1,    33,    57,   668,    30,    -1,    33,
     266,   626,    -1,    33,   112,   154,   377,    -1,    95,   564,
     378,    -1,   378,    -1,   379,    -1,   139,    -1,   139,   379,
      -1,   144,   423,    -1,    33,   381,   144,   423,    -1,    33,
     381,   139,    -1,    33,   381,   139,   144,   423,    -1,   113,
     119,   668,    -1,   113,   119,   668,   561,    -1,   382,   113,
     119,   668,    -1,   382,   113,   119,   668,   561,    -1,   383,
      -1,   382,   383,    -1,    27,    -1,    27,   158,   384,   188,
      -1,    28,    -1,    28,   158,   384,   188,    -1,   521,    -1,
     384,   108,   521,    -1,    33,   386,    -1,    33,   382,   386,
      -1,   387,    -1,   388,    -1,    47,   669,   389,   406,    -1,
      47,   669,   389,   139,    -1,    75,    47,   669,   389,   406,
      -1,    75,    47,   669,   389,   139,    -1,   158,   188,    -1,
     158,   390,   188,    -1,   158,   188,    95,   562,    -1,   158,
     390,   188,    95,   562,    -1,   391,    -1,   390,   108,   391,
      -1,   119,   668,    -1,   119,   668,   561,    -1,    33,   292,
     668,    -1,    33,   292,   668,    95,   393,    -1,    33,   382,
     292,   668,    -1,    33,   382,   292,   668,    95,   393,    -1,
     568,    -1,   568,   563,    -1,   663,    -1,   663,   563,    -1,
      33,   300,   668,   304,   232,   504,   171,   395,    -1,    33,
     382,   300,   668,   304,   232,   504,   171,   395,    -1,   396,
      -1,   395,   108,   396,    -1,   504,    -1,   504,   561,    -1,
     504,   459,    -1,   504,   561,   459,    -1,    33,   308,   309,
     668,   304,   292,   668,   119,   668,   310,   423,    -1,    33,
     308,   309,   668,   304,   292,   668,   230,   119,   668,   310,
     298,   311,   504,    -1,    33,   308,   309,   668,   304,   292,
     668,   312,   230,   119,   668,   310,   423,    -1,    33,   308,
     309,   668,   313,   311,   262,   292,   668,   230,   119,   668,
     311,   504,   200,   292,   668,   230,   119,   668,   311,   504,
      -1,   399,    -1,   401,    -1,   402,    -1,    -1,   401,    -1,
     402,    -1,    -1,   422,    -1,   402,   422,    -1,   403,    -1,
     402,   403,    -1,   402,   422,   345,   403,    -1,   404,    -1,
     407,    -1,   410,    -1,   411,    -1,   412,    -1,   413,    -1,
     414,    -1,   415,    -1,   417,    -1,   471,    -1,   467,    -1,
     418,    -1,   421,    -1,   155,   402,   185,    -1,   155,   400,
     185,    -1,   155,   400,   185,    -1,   408,   191,    -1,   408,
     108,   409,    -1,   113,   409,    -1,   382,   113,   409,    -1,
     119,   668,    -1,   119,   668,   561,    -1,   119,   668,   144,
     423,    -1,   119,   668,   561,   144,   423,    -1,   119,   668,
     144,   423,   191,    -1,   424,   191,    -1,   245,   247,   423,
     191,    -1,   248,   158,   422,   188,   403,    -1,   243,   246,
     191,    -1,   244,   246,   191,    -1,   434,   416,    -1,   187,
     403,    -1,    48,   158,   422,   188,   199,   403,   128,   403,
      -1,   249,   404,   419,    -1,   420,    -1,   419,   420,    -1,
     250,   599,   404,    -1,   191,    -1,   423,    -1,   422,   108,
     423,    -1,   422,   345,   423,    -1,   425,    -1,   463,    -1,
     470,    -1,   477,    -1,   595,    -1,   424,    -1,   478,    -1,
     460,    -1,   588,    -1,   589,    -1,   591,    -1,   590,    -1,
     592,    -1,   660,    -1,   658,    -1,   661,    -1,   662,    -1,
     659,    -1,   434,   426,    -1,   187,   423,    -1,    67,   289,
      -1,    72,   289,    -1,   219,    -1,   259,    -1,    56,   259,
      -1,   428,   445,    78,   423,    -1,   428,    78,   423,    -1,
     436,   427,   444,   429,   429,    -1,   436,   427,   444,   429,
      -1,    42,   119,   668,    -1,   435,    -1,   441,    -1,   430,
      -1,   432,    -1,   448,    -1,   453,    -1,   449,    -1,   431,
      -1,   432,    -1,   434,   433,    -1,   436,   119,   437,    -1,
      46,     1,   437,    -1,   262,     1,   437,    -1,   436,     3,
      -1,    46,    -1,   262,    -1,   438,    -1,   437,   108,   119,
     438,    -1,   437,   108,   438,    -1,   668,   149,   423,    -1,
     668,    36,   129,   149,   423,    -1,   668,   561,   149,   423,
      -1,   668,   561,    36,   129,   149,   423,    -1,   668,   439,
     149,   423,    -1,   668,    36,   129,   439,   149,   423,    -1,
     668,   561,   439,   149,   423,    -1,   668,   561,    36,   129,
     439,   149,   423,    -1,   668,   440,   149,   423,    -1,   668,
     561,   440,   149,   423,    -1,   668,   439,   440,   149,   423,
      -1,   668,   561,   439,   440,   149,   423,    -1,    97,   119,
     668,    -1,   278,   119,   668,    -1,    51,   442,    -1,   443,
      -1,   442,   108,   443,    -1,   119,   668,   144,   423,    -1,
     119,   668,   561,   144,   423,    -1,   440,   144,   423,    -1,
     119,   668,   561,   440,   144,   423,    -1,   119,   668,   149,
     423,    -1,   119,   668,   561,   149,   423,    -1,   446,    -1,
     119,   668,    -1,   119,   668,   446,    -1,   439,    -1,   439,
     447,    -1,   447,    -1,    59,   119,   668,    54,   119,   668,
      -1,    54,   119,   668,    -1,    59,   119,   668,    -1,   213,
     423,    -1,   172,   171,   450,    -1,   451,    -1,   450,   108,
     451,    -1,   119,   668,   144,   423,    -1,   119,   668,   561,
     144,   423,    -1,   119,   668,   561,   144,   423,   452,    -1,
     119,   668,   144,   423,   452,    -1,   119,   668,   452,    -1,
     423,    -1,   423,   452,    -1,   107,   667,    -1,   169,   171,
     454,    -1,    70,   169,   171,   454,    -1,   455,    -1,   454,
     108,   455,    -1,   423,    -1,   423,   456,    -1,   457,    -1,
     458,    -1,   459,    -1,   457,   458,    -1,   457,   459,    -1,
     458,   459,    -1,   457,   458,   459,    -1,    96,    -1,   117,
      -1,   129,   130,    -1,   129,   131,    -1,   107,   667,    -1,
      68,   119,   461,   189,   423,    -1,   137,   119,   461,   189,
     423,    -1,   462,    -1,   461,   108,   119,   462,    -1,   668,
     149,   423,    -1,   668,   561,   149,   423,    -1,    73,   158,
     422,   188,   464,   114,   187,   423,    -1,   465,    -1,   464,
     465,    -1,   466,   187,   423,    -1,   101,   423,    -1,   466,
     101,   423,    -1,    73,   158,   422,   188,   468,   114,   187,
     403,    -1,   469,    -1,   468,   469,    -1,   466,   187,   403,
      -1,    74,   158,   422,   188,   472,   114,   187,   423,    -1,
      74,   158,   422,   188,   472,   114,   119,   668,   187,   423,
      -1,    74,   158,   422,   188,   474,   114,   187,   403,    -1,
      74,   158,   422,   188,   472,   114,   119,   668,   187,   403,
      -1,   473,    -1,   472,   473,    -1,   101,   476,   187,   423,
      -1,   101,   119,   668,    95,   476,   187,   423,    -1,   475,
      -1,   474,   475,    -1,   101,   476,   187,   403,    -1,   101,
     119,   668,    95,   476,   187,   403,    -1,   562,    -1,   476,
     211,   562,    -1,    48,   158,   422,   188,   199,   423,   128,
     423,    -1,   479,    -1,   478,   168,   479,    -1,   480,    -1,
     479,    93,   480,    -1,   481,    -1,   265,   480,    -1,   482,
      -1,   482,   499,   482,    -1,   483,    -1,   483,   254,    71,
     600,   484,    -1,   485,    -1,   485,   100,   483,    -1,    -1,
     652,    -1,   486,    -1,   486,   200,   486,    -1,   487,    -1,
     486,   177,   487,    -1,   486,   160,   487,    -1,   488,    -1,
     487,   195,   488,    -1,   487,   118,   488,    -1,   487,   148,
     488,    -1,   487,   161,   488,    -1,   489,    -1,   488,   202,
     489,    -1,   488,   211,   489,    -1,   490,    -1,   489,   152,
     490,    -1,   489,   138,   490,    -1,   491,    -1,   491,    50,
     236,   562,    -1,   492,    -1,   492,   201,    95,   562,    -1,
     493,    -1,   493,   102,    95,   494,    -1,   495,    -1,   495,
     103,    95,   494,    -1,   567,    -1,   567,   146,    -1,   497,
      -1,   496,   497,    -1,   177,    -1,   160,    -1,   496,   177,
      -1,   496,   160,    -1,   500,    -1,   498,    -1,   501,    -1,
     504,    -1,   498,   194,   504,    -1,   204,    -1,   209,    -1,
     208,    -1,   207,    -1,   206,    -1,   205,    -1,    76,   155,
     401,   185,    -1,    76,   227,   155,   401,   185,    -1,    76,
     226,   155,   401,   185,    -1,    76,    77,   580,   155,   401,
     185,    -1,   502,   155,   185,    -1,   502,   155,   422,   185,
      -1,   503,    -1,   502,   503,    -1,   178,   668,    17,    -1,
     178,    18,    -1,   178,    19,    -1,   505,    -1,   505,   506,
      -1,   193,   506,    -1,   506,    -1,   192,    -1,   507,    -1,
     507,   192,   506,    -1,   507,   193,   506,    -1,   508,    -1,
     517,    -1,   509,    -1,   509,   518,    -1,   512,    -1,   512,
     518,    -1,   510,   514,    -1,   511,    -1,   106,   124,    -1,
     115,   124,    -1,    98,   124,    -1,   190,   124,    -1,   116,
     124,    -1,   141,   124,    -1,   140,   124,    -1,   514,    -1,
      99,   514,    -1,   513,   514,    -1,   122,    -1,   173,   124,
      -1,    91,   124,    -1,   182,   124,    -1,   181,   124,    -1,
      92,   124,    -1,   568,    -1,   515,    -1,   668,    -1,   516,
      -1,   195,    -1,    11,    -1,    12,    -1,    20,    -1,   520,
      -1,   517,   518,    -1,   517,   158,   188,    -1,   517,   158,
     530,   188,    -1,   517,   121,   668,    -1,   517,   121,   158,
     188,    -1,   517,   121,   158,   422,   188,    -1,   517,   121,
     524,    -1,   517,   121,   582,    -1,   519,    -1,   518,   519,
      -1,   156,   422,   186,    -1,   521,    -1,   524,    -1,   525,
      -1,   526,    -1,   529,    -1,   534,    -1,   527,    -1,   528,
      -1,   531,    -1,   405,    -1,   656,    -1,   653,    -1,   654,
      -1,   655,    -1,   522,    -1,   582,    -1,   523,    -1,   220,
      -1,   111,    -1,   151,    -1,   126,    -1,   221,    -1,   222,
      -1,   119,   668,    -1,   158,   188,    -1,   158,   422,   188,
      -1,   120,    -1,   170,   155,   422,   185,    -1,   203,   155,
     422,   185,    -1,   669,   158,   188,    -1,   669,   158,   530,
     188,    -1,   146,    -1,   530,   108,   146,    -1,   423,    -1,
     530,   108,   423,    -1,   532,    -1,   533,    -1,   669,   147,
     151,    -1,    47,   389,   406,    -1,   535,    -1,   553,    -1,
     536,    -1,   550,    -1,   551,    -1,   159,   668,   540,   132,
      -1,   159,   668,   540,   198,   196,   668,   540,   198,    -1,
     159,   668,   538,   540,   132,    -1,   159,   668,   538,   540,
     198,   196,   668,   540,   198,    -1,   159,   668,   540,   198,
     537,   196,   668,   540,   198,    -1,   159,   668,   538,   540,
     198,   537,   196,   668,   540,   198,    -1,   548,    -1,   537,
     548,    -1,   539,    -1,   538,   539,    -1,    35,   668,   540,
     134,   540,   541,    -1,    -1,    35,    -1,   184,   542,   184,
      -1,    94,   544,    94,    -1,    -1,   543,    -1,   136,    -1,
     546,    -1,   543,   136,    -1,   543,   546,    -1,    -1,   545,
      -1,   135,    -1,   547,    -1,   545,   135,    -1,   545,   547,
      -1,    29,    -1,   549,    -1,     5,    -1,   549,    -1,   535,
      -1,    10,    -1,   552,    -1,   549,    -1,     9,    -1,   125,
      -1,   127,    -1,   155,   401,   185,    -1,   214,    31,   215,
      -1,   214,   215,    -1,   175,   668,   176,    -1,   175,   668,
       8,    -1,   104,     7,    -1,   554,    -1,   555,    -1,   556,
      -1,   557,    -1,   558,    -1,   559,    -1,   560,    -1,    43,
     155,   401,   185,    -1,    21,   400,   185,    -1,    45,   155,
     422,   185,   155,   400,   185,    -1,    22,   400,   185,    -1,
      98,   155,   422,   185,   155,   400,   185,    -1,    71,   155,
     401,   185,    -1,    39,   155,   401,   185,    -1,    23,   400,
     185,    -1,    60,   155,   422,   185,   155,   400,   185,    -1,
      24,   401,   185,    -1,   162,   155,   422,   185,   155,   401,
     185,    -1,    95,   562,    -1,   564,    -1,   564,   563,    -1,
     212,   158,   188,    -1,   158,   188,    -1,   146,    -1,   195,
      -1,   177,    -1,   566,    -1,   568,    -1,   154,   158,   188,
      -1,   154,    -1,   325,   158,   188,    -1,   325,    -1,   583,
      -1,   586,    -1,   663,    -1,   562,    -1,   565,   108,   562,
      -1,   668,    -1,   220,    -1,   668,    -1,   571,    -1,   578,
      -1,   576,    -1,   579,    -1,   577,    -1,   575,    -1,   574,
      -1,   573,    -1,   572,    -1,   569,    -1,   570,   158,   188,
      -1,   230,    -1,    44,   158,   188,    -1,    44,   158,   578,
     188,    -1,    44,   158,   579,   188,    -1,    53,   158,   188,
      -1,    71,   158,   188,    -1,    39,   158,   188,    -1,    60,
     158,   188,    -1,    60,   158,   668,   188,    -1,    60,   158,
      30,   188,    -1,    98,   158,   188,    -1,    98,   158,   668,
     188,    -1,    98,   158,   668,   108,   580,   188,    -1,    98,
     158,   195,   188,    -1,    98,   158,   195,   108,   580,   188,
      -1,    62,   158,   668,   188,    -1,    45,   158,   188,    -1,
      45,   158,   668,   188,    -1,    45,   158,   668,   108,   580,
     188,    -1,    45,   158,   668,   108,   581,   188,    -1,    45,
     158,   195,   188,    -1,    45,   158,   195,   108,   580,   188,
      -1,    45,   158,   195,   108,   581,   188,    -1,    63,   158,
     668,   188,    -1,   668,    -1,   668,   146,    -1,    30,    -1,
     584,    -1,   585,    -1,    47,   158,   195,   188,    -1,    47,
     158,   188,    95,   562,    -1,    47,   158,   565,   188,    95,
     562,    -1,   158,   564,   188,    -1,    33,   225,   226,    -1,
      33,   225,   227,    -1,    33,   225,   228,    -1,   231,   230,
     423,   238,   423,    -1,   231,   230,   423,    95,   237,   238,
     423,    -1,   231,   230,   423,    95,   239,   238,   423,    -1,
     231,   230,   423,   223,   423,    -1,   231,   230,   423,   224,
     423,    -1,   231,   232,   423,   238,   423,    -1,   231,   232,
     423,    95,   237,   238,   423,    -1,   231,   232,   423,    95,
     239,   238,   423,    -1,   231,   232,   423,   223,   423,    -1,
     231,   232,   423,   224,   423,    -1,   229,   230,   423,    -1,
     229,   232,   423,    -1,   234,   230,   423,   242,   423,    -1,
     234,   235,   236,   230,   423,   242,   423,    -1,   233,   230,
     423,    95,   423,    -1,   241,   119,   593,   240,   423,   187,
     423,    -1,   594,    -1,   593,   108,   119,   594,    -1,   668,
     144,   423,    -1,   249,   155,   422,   185,   596,    -1,   597,
      -1,   596,   597,    -1,   250,   599,   598,    -1,   155,   422,
     185,    -1,   515,    -1,   599,   211,   515,    -1,   603,   601,
      -1,    -1,   602,    -1,   621,    -1,   602,   621,    -1,   604,
      -1,   603,   267,   604,    -1,   605,    -1,   604,   263,   605,
      -1,   606,    -1,   605,   265,   149,   606,    -1,   607,    -1,
     264,   607,    -1,   611,   608,   609,    -1,    -1,   626,    -1,
      -1,   610,    -1,   287,   155,   422,   185,    -1,   615,   612,
      -1,   158,   600,   188,    -1,   613,    -1,    -1,   648,    -1,
     502,   155,   614,   185,    -1,    -1,   600,    -1,   616,   617,
      -1,   521,    -1,   155,   422,   185,    -1,    -1,   618,    -1,
     253,   619,    -1,   252,   620,    -1,   275,    -1,    -1,    79,
      -1,    -1,   291,    -1,   622,    -1,   623,    -1,   624,    -1,
     650,    -1,   647,    -1,   170,    -1,   289,   486,   625,    -1,
     258,   649,   625,    -1,   291,    -1,   281,    -1,   274,    -1,
     251,   627,    -1,   626,   251,   627,    -1,   628,    -1,   629,
      -1,   630,    -1,   645,    -1,   631,    -1,   639,    -1,   632,
      -1,   646,    -1,   101,   279,    -1,   101,   268,    -1,   271,
      -1,   286,    -1,   256,   279,    -1,   256,   268,    -1,    57,
     668,    30,    -1,   282,    -1,    55,   282,    -1,   284,   633,
      -1,   284,   158,   633,   634,   188,    -1,    55,   284,    -1,
     636,    -1,   114,    -1,    -1,   108,   635,    -1,   636,    -1,
     635,   108,   636,    -1,    97,    30,   637,   638,    -1,    -1,
     276,    30,    -1,    -1,   649,   270,    -1,   283,   291,   640,
     642,    -1,   283,   291,   114,   642,    -1,    55,   283,   291,
      -1,    97,    30,    -1,   158,   641,   188,    -1,    30,    -1,
     641,   108,    30,    -1,    -1,   643,    -1,   644,    -1,   643,
     644,    -1,   202,   640,    -1,   138,   640,    -1,   269,    30,
      -1,   288,    -1,    55,   288,    -1,    97,   219,    -1,    97,
     259,    -1,   260,   255,    -1,   272,   649,   285,    -1,   261,
     486,    -1,    97,   131,   486,    -1,    97,    52,   486,    -1,
     262,   486,   200,   486,    -1,   277,   651,    -1,   257,   651,
      -1,   280,    -1,   273,    -1,   290,   255,   488,    -1,   156,
     186,    -1,   156,   422,   186,    -1,   315,   316,    -1,   315,
     422,   316,    -1,   317,   318,    -1,   317,   422,   318,    -1,
     155,   657,   185,    -1,   668,   123,   423,    -1,   423,   123,
     423,    -1,   657,   108,   423,   123,   423,    -1,   657,   108,
     668,   123,   423,    -1,   231,   319,   423,   238,   423,    -1,
     231,   319,   657,   238,   423,    -1,   231,   319,   423,   238,
     423,    97,   321,   423,    -1,   231,   423,   238,   423,    -1,
     231,   657,   238,   423,    -1,   231,   423,   238,   423,    97,
     321,   423,    -1,   320,   319,   423,   238,   423,    -1,   320,
     423,   238,   423,    -1,   229,   319,   517,    -1,   229,   517,
      -1,   233,   319,   517,    95,   423,    -1,   233,   517,    95,
     423,    -1,   234,   319,   235,   236,   517,   242,   423,    -1,
     234,   235,   236,   517,   242,   423,    -1,   664,    -1,   665,
      -1,   666,    -1,   324,   158,   188,    -1,   324,    -1,   322,
     158,   188,    -1,   322,    -1,   323,   158,   188,    -1,   323,
      -1,    30,    -1,   669,    -1,    16,    -1,    98,    -1,    39,
      -1,    44,    -1,    53,    -1,    45,    -1,    48,    -1,   230,
      -1,    60,    -1,    62,    -1,    63,    -1,    71,    -1,    74,
      -1,    73,    -1,   212,    -1,   248,    -1,   670,    -1,    25,
      -1,   216,    -1,   129,    -1,    38,    -1,   266,    -1,    37,
      -1,   227,    -1,   226,    -1,   148,    -1,    43,    -1,   264,
      -1,   265,    -1,   279,    -1,   268,    -1,   256,    -1,   290,
      -1,   282,    -1,   284,    -1,   283,    -1,   288,    -1,   260,
      -1,   255,    -1,    79,    -1,   219,    -1,   259,    -1,    52,
      -1,   228,    -1,   241,    -1,   307,    -1,   235,    -1,   204,
      -1,   209,    -1,   208,    -1,   207,    -1,   206,    -1,   205,
      -1,    97,    -1,   112,    -1,   113,    -1,   187,    -1,    46,
      -1,   262,    -1,    36,    -1,    67,    -1,    72,    -1,    59,
      -1,    54,    -1,    56,    -1,    78,    -1,    42,    -1,   149,
      -1,    51,    -1,   213,    -1,   171,    -1,   172,    -1,   169,
      -1,    70,    -1,    96,    -1,   117,    -1,   130,    -1,   131,
      -1,   107,    -1,    68,    -1,   137,    -1,   189,    -1,   101,
      -1,    95,    -1,   199,    -1,   128,    -1,   168,    -1,    93,
      -1,    50,    -1,   236,    -1,   102,    -1,   200,    -1,   118,
      -1,   161,    -1,   202,    -1,   152,    -1,   138,    -1,    76,
      -1,    77,    -1,   103,    -1,   201,    -1,   153,    -1,   183,
      -1,   197,    -1,   162,    -1,   139,    -1,   133,    -1,   167,
      -1,   150,    -1,   166,    -1,    33,    -1,    40,    -1,    58,
      -1,   114,    -1,    41,    -1,    57,    -1,   218,    -1,    49,
      -1,    61,    -1,    34,    -1,    47,    -1,   278,    -1,   254,
      -1,   287,    -1,   289,    -1,   258,    -1,   272,    -1,   285,
      -1,   277,    -1,   257,    -1,   271,    -1,   286,    -1,   276,
      -1,   270,    -1,   269,    -1,   253,    -1,   252,    -1,   261,
      -1,   291,    -1,   281,    -1,   280,    -1,   275,    -1,   273,
      -1,   274,    -1,   240,    -1,   237,    -1,   224,    -1,   223,
      -1,   225,    -1,   242,    -1,   232,    -1,   239,    -1,   238,
      -1,    66,    -1,    64,    -1,    75,    -1,   170,    -1,   203,
      -1,   247,    -1,   245,    -1,   246,    -1,   243,    -1,   244,
      -1,   249,    -1,   250,    -1,   251,    -1,    65,    -1,   300,
      -1,   298,    -1,   299,    -1,   304,    -1,   305,    -1,   306,
      -1,   301,    -1,   302,    -1,   303,    -1,    80,    -1,    81,
      -1,    82,    -1,    83,    -1,    84,    -1,    85,    -1,    86,
      -1,    87,    -1,    88,    -1,    89,    -1,    90,    -1,   292,
      -1,   293,    -1,   294,    -1,   295,    -1,   296,    -1,   297,
      -1,   308,    -1,   309,    -1,   310,    -1,   311,    -1,   312,
      -1,   313,    -1,   314,    -1,    91,    -1,   106,    -1,   115,
      -1,   173,    -1,   181,    -1,   190,    -1,   140,    -1,    92,
      -1,   116,    -1,   141,    -1,   182,    -1,   321,    -1,    26,
      -1
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
    1116,  1118,  1122,  1127,  1133,  1140,  1146,  1150,  1152,  1155,
    1158,  1162,  1167,  1169,  1173,  1175,  1178,  1180,  1182,  1184,
    1187,  1190,  1193,  1197,  1199,  1201,  1204,  1207,  1210,  1216,
    1222,  1224,  1229,  1233,  1238,  1247,  1249,  1252,  1256,  1259,
    1263,  1272,  1274,  1277,  1281,  1290,  1301,  1310,  1321,  1323,
    1326,  1331,  1339,  1341,  1344,  1349,  1357,  1359,  1363,  1372,
    1374,  1378,  1380,  1384,  1386,  1389,  1391,  1395,  1397,  1403,
    1405,  1409,  1410,  1412,  1414,  1418,  1420,  1424,  1428,  1430,
    1434,  1438,  1442,  1446,  1448,  1452,  1456,  1458,  1462,  1466,
    1468,  1473,  1475,  1480,  1482,  1487,  1489,  1494,  1496,  1499,
    1501,  1504,  1506,  1508,  1511,  1514,  1516,  1518,  1520,  1522,
    1526,  1528,  1530,  1532,  1534,  1536,  1538,  1543,  1549,  1555,
    1562,  1566,  1571,  1573,  1576,  1580,  1583,  1586,  1588,  1591,
    1594,  1596,  1598,  1600,  1604,  1608,  1610,  1612,  1614,  1617,
    1619,  1622,  1625,  1627,  1630,  1633,  1636,  1639,  1642,  1645,
    1648,  1650,  1653,  1656,  1658,  1661,  1664,  1667,  1670,  1673,
    1675,  1677,  1679,  1681,  1683,  1685,  1687,  1689,  1691,  1694,
    1698,  1703,  1707,  1712,  1718,  1722,  1726,  1728,  1731,  1735,
    1737,  1739,  1741,  1743,  1745,  1747,  1749,  1751,  1753,  1755,
    1757,  1759,  1761,  1763,  1765,  1767,  1769,  1771,  1773,  1775,
    1777,  1779,  1781,  1784,  1787,  1791,  1793,  1798,  1803,  1807,
    1812,  1814,  1818,  1820,  1824,  1826,  1828,  1832,  1836,  1838,
    1840,  1842,  1844,  1846,  1851,  1860,  1866,  1876,  1886,  1897,
    1899,  1902,  1904,  1907,  1914,  1915,  1917,  1921,  1925,  1926,
    1928,  1930,  1932,  1935,  1938,  1939,  1941,  1943,  1945,  1948,
    1951,  1953,  1955,  1957,  1959,  1961,  1963,  1965,  1967,  1969,
    1971,  1973,  1977,  1981,  1984,  1988,  1992,  1995,  1997,  1999,
    2001,  2003,  2005,  2007,  2009,  2014,  2018,  2026,  2030,  2038,
    2043,  2048,  2052,  2060,  2064,  2072,  2075,  2077,  2080,  2084,
    2087,  2089,  2091,  2093,  2095,  2097,  2101,  2103,  2107,  2109,
    2111,  2113,  2115,  2117,  2121,  2123,  2125,  2127,  2129,  2131,
    2133,  2135,  2137,  2139,  2141,  2143,  2145,  2147,  2151,  2153,
    2157,  2162,  2167,  2171,  2175,  2179,  2183,  2188,  2193,  2197,
    2202,  2209,  2214,  2221,  2226,  2230,  2235,  2242,  2249,  2254,
    2261,  2268,  2273,  2275,  2278,  2280,  2282,  2284,  2289,  2295,
    2302,  2306,  2310,  2314,  2318,  2324,  2332,  2340,  2346,  2352,
    2358,  2366,  2374,  2380,  2386,  2390,  2394,  2400,  2408,  2414,
    2422,  2424,  2429,  2433,  2439,  2441,  2444,  2448,  2452,  2454,
    2458,  2461,  2462,  2464,  2466,  2469,  2471,  2475,  2477,  2481,
    2483,  2488,  2490,  2493,  2497,  2498,  2500,  2501,  2503,  2508,
    2511,  2515,  2517,  2518,  2520,  2525,  2526,  2528,  2531,  2533,
    2537,  2538,  2540,  2543,  2546,  2548,  2549,  2551,  2552,  2554,
    2556,  2558,  2560,  2562,  2564,  2566,  2570,  2574,  2576,  2578,
    2580,  2583,  2587,  2589,  2591,  2593,  2595,  2597,  2599,  2601,
    2603,  2606,  2609,  2611,  2613,  2616,  2619,  2623,  2625,  2628,
    2631,  2637,  2640,  2642,  2644,  2645,  2648,  2650,  2654,  2659,
    2660,  2663,  2664,  2667,  2672,  2677,  2681,  2684,  2688,  2690,
    2694,  2695,  2697,  2699,  2702,  2705,  2708,  2711,  2713,  2716,
    2719,  2722,  2725,  2729,  2732,  2736,  2740,  2745,  2748,  2751,
    2753,  2755,  2759,  2762,  2766,  2769,  2773,  2776,  2780,  2784,
    2788,  2792,  2798,  2804,  2810,  2816,  2825,  2830,  2835,  2843,
    2849,  2854,  2858,  2861,  2867,  2872,  2880,  2887,  2889,  2891,
    2893,  2897,  2899,  2903,  2905,  2909,  2911,  2913,  2915,  2917,
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
    3259,  3261,  3263,  3265,  3267,  3269,  3271,  3273,  3275,  3277,
    3279,  3281,  3283,  3285,  3287,  3289,  3291,  3293,  3295,  3297,
    3299,  3301,  3303,  3305,  3307,  3309,  3311,  3313,  3315,  3317,
    3319,  3321,  3323,  3325,  3327,  3329,  3331,  3333,  3335,  3337,
    3339
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  jsoniq_parser::yyrline_[] =
  {
         0,   856,   856,   857,   861,   865,   871,   875,   879,   885,
     891,   899,   905,   914,   919,   924,   929,   935,   941,   947,
     955,   960,   968,   976,   984,   993,   998,  1004,  1010,  1019,
    1027,  1034,  1040,  1049,  1050,  1051,  1052,  1053,  1056,  1057,
    1058,  1059,  1060,  1061,  1062,  1063,  1066,  1071,  1077,  1083,
    1089,  1094,  1100,  1105,  1111,  1116,  1122,  1127,  1132,  1137,
    1143,  1145,  1147,  1155,  1160,  1168,  1176,  1185,  1192,  1200,
    1206,  1212,  1218,  1225,  1233,  1244,  1251,  1258,  1266,  1273,
    1279,  1288,  1289,  1290,  1291,  1292,  1293,  1294,  1295,  1298,
    1304,  1311,  1318,  1326,  1334,  1335,  1336,  1337,  1338,  1339,
    1340,  1341,  1342,  1343,  1346,  1360,  1366,  1372,  1379,  1385,
    1392,  1397,  1403,  1409,  1421,  1433,  1446,  1451,  1459,  1467,
    1476,  1481,  1488,  1493,  1500,  1505,  1513,  1518,  1525,  1531,
    1540,  1541,  1544,  1555,  1568,  1580,  1593,  1598,  1603,  1608,
    1614,  1621,  1629,  1634,  1642,  1650,  1658,  1666,  1676,  1680,
    1686,  1690,  1697,  1706,  1717,  1723,  1730,  1735,  1742,  1749,
    1758,  1768,  1778,  1788,  1803,  1819,  1823,  1828,  1833,  1837,
    1842,  1847,  1852,  1860,  1867,  1874,  1887,  1888,  1889,  1890,
    1891,  1892,  1893,  1894,  1895,  1896,  1897,  1898,  1899,  1902,
    1908,  1930,  1936,  1942,  1949,  1956,  1965,  1974,  1983,  1992,
    2003,  2009,  2015,  2021,  2033,  2038,  2044,  2056,  2069,  2089,
    2095,  2102,  2111,  2118,  2124,  2129,  2141,  2153,  2154,  2155,
    2156,  2157,  2158,  2161,  2162,  2163,  2164,  2165,  2166,  2167,
    2168,  2169,  2170,  2171,  2172,  2175,  2187,  2193,  2198,  2204,
    2209,  2214,  2220,  2229,  2239,  2251,  2263,  2269,  2270,  2271,
    2274,  2275,  2276,  2277,  2278,  2281,  2288,  2296,  2301,  2309,
    2318,  2327,  2328,  2333,  2340,  2347,  2357,  2367,  2377,  2387,
    2397,  2407,  2417,  2427,  2437,  2446,  2456,  2466,  2478,  2484,
    2490,  2496,  2502,  2510,  2518,  2526,  2534,  2544,  2550,  2559,
    2560,  2564,  2571,  2575,  2580,  2583,  2587,  2591,  2597,  2603,
    2609,  2615,  2623,  2627,  2635,  2643,  2651,  2659,  2667,  2677,
    2683,  2689,  2697,  2703,  2711,  2715,  2723,  2729,  2735,  2741,
    2750,  2759,  2768,  2779,  2783,  2789,  2795,  2803,  2809,  2818,
    2829,  2835,  2843,  2847,  2856,  2862,  2868,  2876,  2882,  2888,
    2896,  2902,  2908,  2916,  2922,  2929,  2939,  2946,  2956,  2962,
    2970,  2976,  2985,  2991,  2999,  3005,  3014,  3020,  3028,  3034,
    3038,  3044,  3049,  3055,  3059,  3070,  3074,  3085,  3089,  3100,
    3104,  3110,  3113,  3119,  3123,  3129,  3133,  3137,  3143,  3147,
    3153,  3159,  3165,  3173,  3177,  3181,  3187,  3191,  3197,  3205,
    3209,  3217,  3221,  3229,  3233,  3241,  3245,  3253,  3257,  3263,
    3267,  3273,  3277,  3281,  3285,  3293,  3294,  3295,  3298,  3303,
    3309,  3313,  3317,  3321,  3325,  3329,  3335,  3339,  3343,  3347,
    3356,  3362,  3370,  3376,  3384,  3388,  3392,  3398,  3402,  3410,
    3418,  3437,  3443,  3453,  3457,  3463,  3464,  3467,  3473,  3481,
    3487,  3497,  3503,  3511,  3515,  3519,  3523,  3527,  3533,  3539,
    3545,  3549,  3555,  3559,  3568,  3572,  3576,  3582,  3586,  3594,
    3595,  3598,  3602,  3608,  3612,  3616,  3620,  3626,  3630,  3634,
    3638,  3642,  3648,  3652,  3656,  3660,  3666,  3672,  3680,  3686,
    3687,  3688,  3689,  3690,  3691,  3692,  3693,  3694,  3695,  3696,
    3697,  3698,  3699,  3702,  3706,  3710,  3715,  3722,  3729,  3736,
    3745,  3749,  3755,  3761,  3765,  3771,  3778,  3784,  3790,  3794,
    3812,  3818,  3824,  3830,  3838,  3842,  3848,  3854,  3864,  3865,
    3868,  3869,  3870,  3873,  3881,  3897,  3905,  3921,  3939,  3959,
    3965,  3974,  3980,  3989,  3996,  3997,  3999,  4004,  4011,  4014,
    4020,  4026,  4032,  4039,  4048,  4051,  4057,  4063,  4069,  4076,
    4085,  4089,  4095,  4099,  4105,  4109,  4113,  4118,  4125,  4129,
    4133,  4137,  4143,  4148,  4154,  4160,  4167,  4173,  4178,  4183,
    4188,  4193,  4198,  4203,  4206,  4212,  4216,  4222,  4226,  4232,
    4238,  4244,  4248,  4254,  4258,  4264,  4270,  4274,  4278,  4282,
    4289,  4295,  4301,  4309,  4313,  4317,  4321,  4326,  4330,  4335,
    4339,  4343,  4349,  4355,  4363,  4367,  4373,  4379,  4383,  4387,
    4391,  4395,  4399,  4403,  4407,  4411,  4415,  4421,  4427,  4433,
    4437,  4441,  4447,  4452,  4458,  4464,  4468,  4473,  4479,  4483,
    4489,  4495,  4499,  4507,  4513,  4517,  4523,  4532,  4541,  4547,
    4553,  4561,  4567,  4573,  4579,  4585,  4589,  4595,  4601,  4605,
    4613,  4619,  4625,  4631,  4639,  4643,  4649,  4655,  4659,  4665,
    4669,  4675,  4681,  4688,  4696,  4701,  4707,  4713,  4721,  4727,
    4734,  4740,  4749,  4755,  4761,  4767,  4776,  4783,  4789,  4795,
    4804,  4811,  4815,  4821,  4826,  4833,  4837,  4843,  4847,  4853,
    4857,  4863,  4867,  4875,  4886,  4889,  4895,  4898,  4904,  4910,
    4918,  4922,  4928,  4931,  4937,  4947,  4950,  4956,  4966,  4972,
    4980,  4983,  4989,  4993,  4997,  5003,  5006,  5012,  5015,  5021,
    5025,  5029,  5033,  5037,  5043,  5049,  5059,  5069,  5073,  5077,
    5083,  5089,  5097,  5101,  5105,  5109,  5113,  5117,  5121,  5125,
    5131,  5135,  5139,  5143,  5149,  5155,  5163,  5171,  5175,  5181,
    5191,  5202,  5208,  5212,  5218,  5221,  5227,  5232,  5239,  5247,
    5250,  5256,  5260,  5266,  5275,  5282,  5290,  5294,  5300,  5306,
    5314,  5317,  5323,  5328,  5338,  5346,  5356,  5362,  5366,  5372,
    5376,  5380,  5386,  5392,  5396,  5400,  5404,  5410,  5418,  5428,
    5432,  5438,  5444,  5448,  5454,  5458,  5464,  5468,  5474,  5481,
    5491,  5497,  5504,  5515,  5521,  5531,  5535,  5542,  5553,  5560,
    5564,  5571,  5590,  5612,  5634,  5659,  5681,  5706,  5710,  5714,
    5720,  5724,  5731,  5735,  5742,  5746,  5753,  5756,  5757,  5758,
    5759,  5760,  5761,  5762,  5763,  5764,  5765,  5766,  5767,  5768,
    5769,  5770,  5771,  5772,  5775,  5776,  5777,  5778,  5779,  5780,
    5781,  5782,  5783,  5784,  5785,  5786,  5787,  5788,  5789,  5790,
    5791,  5792,  5793,  5794,  5795,  5796,  5797,  5798,  5799,  5800,
    5801,  5802,  5803,  5804,  5805,  5806,  5807,  5808,  5809,  5810,
    5811,  5812,  5813,  5814,  5815,  5816,  5817,  5818,  5819,  5820,
    5821,  5822,  5823,  5824,  5825,  5826,  5827,  5828,  5829,  5830,
    5831,  5832,  5833,  5834,  5835,  5836,  5837,  5838,  5839,  5840,
    5841,  5842,  5843,  5844,  5845,  5846,  5847,  5848,  5849,  5850,
    5851,  5852,  5853,  5854,  5855,  5856,  5857,  5858,  5859,  5860,
    5861,  5862,  5863,  5864,  5865,  5866,  5867,  5868,  5869,  5870,
    5871,  5872,  5873,  5874,  5875,  5876,  5877,  5878,  5879,  5880,
    5881,  5882,  5883,  5884,  5885,  5886,  5887,  5888,  5889,  5890,
    5891,  5892,  5893,  5894,  5895,  5896,  5897,  5898,  5899,  5900,
    5901,  5902,  5903,  5904,  5905,  5906,  5907,  5908,  5909,  5910,
    5911,  5912,  5913,  5914,  5915,  5916,  5917,  5918,  5919,  5920,
    5921,  5922,  5923,  5924,  5925,  5926,  5927,  5928,  5929,  5930,
    5931,  5932,  5933,  5934,  5935,  5936,  5937,  5938,  5939,  5940,
    5941,  5942,  5943,  5944,  5945,  5946,  5947,  5948,  5949,  5950,
    5951,  5952,  5953,  5954,  5955,  5956,  5957,  5958,  5959,  5960,
    5961,  5962,  5963,  5964,  5965,  5966,  5967,  5968,  5969,  5970,
    5973
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
     335,   336,   337,   338,   339,   340,   341,   342
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int jsoniq_parser::yyeof_ = 0;
  const int jsoniq_parser::yylast_ = 21109;
  const int jsoniq_parser::yynnts_ = 328;
  const int jsoniq_parser::yyempty_ = -2;
  const int jsoniq_parser::yyfinal_ = 625;
  const int jsoniq_parser::yyterror_ = 1;
  const int jsoniq_parser::yyerrcode_ = 256;
  const int jsoniq_parser::yyntokens_ = 343;

  const unsigned int jsoniq_parser::yyuser_token_number_max_ = 597;
  const jsoniq_parser::token_number_type jsoniq_parser::yyundef_token_ = 2;


} // zorba

/* Line 1136 of lalr1.cc  */
#line 18586 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"


/* Line 1138 of lalr1.cc  */
#line 5975 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"

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

