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
#line 1 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"

#define JSONIQ_PARSER

/* Line 293 of lalr1.cc  */
#line 58 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"


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
#line 101 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"


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
#line 102 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"


#include "jsoniq_parser.hpp"

/* User implementation prologue.  */

/* Line 299 of lalr1.cc  */
#line 793 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"

template<typename T> inline void release_hack( T *ref ) {
    if ( ref ) {
        RCHelper::addReference( ref );
        RCHelper::removeReference( ref );
    }
}


/* Line 299 of lalr1.cc  */
#line 121 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"

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
#line 207 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"

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
#line 792 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ delete (yyvaluep->decval); };

/* Line 480 of lalr1.cc  */
#line 312 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 126: /* "\"'DOUBLE'\"" */

/* Line 480 of lalr1.cc  */
#line 791 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ delete (yyvaluep->dval); };

/* Line 480 of lalr1.cc  */
#line 321 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 151: /* "\"'INTEGER'\"" */

/* Line 480 of lalr1.cc  */
#line 790 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ delete (yyvaluep->ival); };

/* Line 480 of lalr1.cc  */
#line 330 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 345: /* "VersionDecl" */

/* Line 480 of lalr1.cc  */
#line 813 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 339 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 346: /* "MainModule" */

/* Line 480 of lalr1.cc  */
#line 806 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 348 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 347: /* "LibraryModule" */

/* Line 480 of lalr1.cc  */
#line 806 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 357 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 348: /* "ModuleDecl" */

/* Line 480 of lalr1.cc  */
#line 806 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 366 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 349: /* "SIND_DeclList" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 375 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 350: /* "SIND_Decl" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 384 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 351: /* "Setter" */

/* Line 480 of lalr1.cc  */
#line 810 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 393 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 352: /* "BoundarySpaceDecl" */

/* Line 480 of lalr1.cc  */
#line 803 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 402 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 353: /* "DefaultCollationDecl" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 411 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 354: /* "BaseURIDecl" */

/* Line 480 of lalr1.cc  */
#line 803 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 420 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 355: /* "ConstructionDecl" */

/* Line 480 of lalr1.cc  */
#line 803 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 429 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 356: /* "OrderingModeDecl" */

/* Line 480 of lalr1.cc  */
#line 808 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 438 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 357: /* "EmptyOrderDecl" */

/* Line 480 of lalr1.cc  */
#line 805 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 447 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 358: /* "CopyNamespacesDecl" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 456 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 359: /* "Import" */

/* Line 480 of lalr1.cc  */
#line 805 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 465 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 360: /* "SchemaImport" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 474 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 361: /* "URILiteralList" */

/* Line 480 of lalr1.cc  */
#line 811 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 483 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 362: /* "SchemaPrefix" */

/* Line 480 of lalr1.cc  */
#line 810 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 492 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 363: /* "ModuleImport" */

/* Line 480 of lalr1.cc  */
#line 806 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 501 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 364: /* "NamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 806 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 510 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 365: /* "DefaultNamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 519 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 366: /* "VFO_DeclList" */

/* Line 480 of lalr1.cc  */
#line 813 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 528 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 367: /* "VFO_Decl" */

/* Line 480 of lalr1.cc  */
#line 813 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 537 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 368: /* "DecimalFormatDecl" */

/* Line 480 of lalr1.cc  */
#line 813 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 546 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 369: /* "DecimalFormatParamList" */

/* Line 480 of lalr1.cc  */
#line 820 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ delete (yyvaluep->vstrpair); };

/* Line 480 of lalr1.cc  */
#line 555 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 370: /* "DecimalFormatParam" */

/* Line 480 of lalr1.cc  */
#line 820 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ delete (yyvaluep->strpair); };

/* Line 480 of lalr1.cc  */
#line 564 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 372: /* "OptionDecl" */

/* Line 480 of lalr1.cc  */
#line 807 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 573 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 373: /* "FTOptionDecl" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 582 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 374: /* "CtxItemDecl" */

/* Line 480 of lalr1.cc  */
#line 811 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 591 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 375: /* "CtxItemDecl2" */

/* Line 480 of lalr1.cc  */
#line 811 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 600 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 376: /* "CtxItemDecl3" */

/* Line 480 of lalr1.cc  */
#line 811 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 609 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 377: /* "CtxItemDecl4" */

/* Line 480 of lalr1.cc  */
#line 812 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 618 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 378: /* "VarDecl" */

/* Line 480 of lalr1.cc  */
#line 812 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 627 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 379: /* "VarNameAndType" */

/* Line 480 of lalr1.cc  */
#line 820 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ delete (yyvaluep->varnametype); };

/* Line 480 of lalr1.cc  */
#line 636 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 380: /* "AnnotationList" */

/* Line 480 of lalr1.cc  */
#line 802 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 645 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 381: /* "Annotation" */

/* Line 480 of lalr1.cc  */
#line 802 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 654 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 382: /* "AnnotationLiteralList" */

/* Line 480 of lalr1.cc  */
#line 802 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 663 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 383: /* "FunctionDecl" */

/* Line 480 of lalr1.cc  */
#line 805 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 672 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 384: /* "FunctionDecl2" */

/* Line 480 of lalr1.cc  */
#line 805 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 681 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 385: /* "FunctionDeclSimple" */

/* Line 480 of lalr1.cc  */
#line 805 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 690 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 386: /* "FunctionDeclUpdating" */

/* Line 480 of lalr1.cc  */
#line 805 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 699 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 387: /* "FunctionSig" */

/* Line 480 of lalr1.cc  */
#line 820 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ delete (yyvaluep->fnsig); };

/* Line 480 of lalr1.cc  */
#line 708 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 388: /* "ParamList" */

/* Line 480 of lalr1.cc  */
#line 808 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 717 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 389: /* "Param" */

/* Line 480 of lalr1.cc  */
#line 808 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 726 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 390: /* "CollectionDecl" */

/* Line 480 of lalr1.cc  */
#line 811 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 735 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 392: /* "IndexDecl" */

/* Line 480 of lalr1.cc  */
#line 811 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 744 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 393: /* "IndexKeyList" */

/* Line 480 of lalr1.cc  */
#line 811 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 753 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 394: /* "IndexKeySpec" */

/* Line 480 of lalr1.cc  */
#line 811 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 762 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 395: /* "IntegrityConstraintDecl" */

/* Line 480 of lalr1.cc  */
#line 811 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 771 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 396: /* "QueryBody" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 780 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 397: /* "StatementsAndOptionalExprTop" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 789 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 398: /* "StatementsAndOptionalExpr" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 798 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 399: /* "StatementsAndExpr" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 807 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 400: /* "Statements" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 816 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 401: /* "Statement" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 825 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 402: /* "BlockStatement" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 834 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 403: /* "BlockExpr" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 843 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 404: /* "EnclosedStatementsAndOptionalExpr" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 852 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 405: /* "VarDeclStatement" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 861 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 408: /* "AssignStatement" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 870 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 409: /* "ApplyStatement" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 410: /* "ExitStatement" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 411: /* "WhileStatement" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 897 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 412: /* "FlowCtlStatement" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 906 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 413: /* "FLWORStatement" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 915 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 414: /* "ReturnStatement" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 924 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 415: /* "IfStatement" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 933 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 416: /* "TryStatement" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 942 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 417: /* "CatchListStatement" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 951 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 418: /* "CatchStatement" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 960 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 419: /* "VoidStatement" */

/* Line 480 of lalr1.cc  */
#line 815 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 969 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 420: /* "Expr" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 978 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 421: /* "ExprSingle" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 987 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 422: /* "ExprSimple" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 996 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 423: /* "FLWORExpr" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1005 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 424: /* "ReturnExpr" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1014 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 427: /* "FLWORWinCond" */

/* Line 480 of lalr1.cc  */
#line 812 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1023 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 428: /* "WindowClause" */

/* Line 480 of lalr1.cc  */
#line 805 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1032 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 429: /* "CountClause" */

/* Line 480 of lalr1.cc  */
#line 813 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1041 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 430: /* "ForLetWinClause" */

/* Line 480 of lalr1.cc  */
#line 805 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1050 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 432: /* "FLWORClauseList" */

/* Line 480 of lalr1.cc  */
#line 805 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1059 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 433: /* "ForClause" */

/* Line 480 of lalr1.cc  */
#line 805 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1068 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 435: /* "VarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 812 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1077 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 436: /* "VarInDecl" */

/* Line 480 of lalr1.cc  */
#line 812 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1086 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 437: /* "PositionalVar" */

/* Line 480 of lalr1.cc  */
#line 808 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1095 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 438: /* "FTScoreVar" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1104 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 439: /* "LetClause" */

/* Line 480 of lalr1.cc  */
#line 806 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1113 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 440: /* "VarGetsDeclList" */

/* Line 480 of lalr1.cc  */
#line 812 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1122 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 441: /* "VarGetsDecl" */

/* Line 480 of lalr1.cc  */
#line 812 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1131 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 442: /* "WindowVarDecl" */

/* Line 480 of lalr1.cc  */
#line 812 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1140 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 443: /* "WindowVars" */

/* Line 480 of lalr1.cc  */
#line 812 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1149 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 444: /* "WindowVars3" */

/* Line 480 of lalr1.cc  */
#line 812 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1158 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 445: /* "WindowVars2" */

/* Line 480 of lalr1.cc  */
#line 812 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1167 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 446: /* "WhereClause" */

/* Line 480 of lalr1.cc  */
#line 813 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1176 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 447: /* "GroupByClause" */

/* Line 480 of lalr1.cc  */
#line 807 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1185 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 448: /* "GroupSpecList" */

/* Line 480 of lalr1.cc  */
#line 807 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1194 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 449: /* "GroupSpec" */

/* Line 480 of lalr1.cc  */
#line 807 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1203 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 450: /* "GroupCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 807 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1212 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 451: /* "OrderByClause" */

/* Line 480 of lalr1.cc  */
#line 807 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1221 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 452: /* "OrderSpecList" */

/* Line 480 of lalr1.cc  */
#line 808 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1230 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 453: /* "OrderSpec" */

/* Line 480 of lalr1.cc  */
#line 808 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1239 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 454: /* "OrderModifier" */

/* Line 480 of lalr1.cc  */
#line 807 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1248 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 455: /* "OrderDirSpec" */

/* Line 480 of lalr1.cc  */
#line 807 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1257 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 456: /* "OrderEmptySpec" */

/* Line 480 of lalr1.cc  */
#line 807 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1266 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 457: /* "OrderCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 807 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1275 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 458: /* "QuantifiedExpr" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1284 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 459: /* "QVarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 808 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1293 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 460: /* "QVarInDecl" */

/* Line 480 of lalr1.cc  */
#line 808 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1302 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 461: /* "SwitchExpr" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1311 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 462: /* "SwitchCaseClauseList" */

/* Line 480 of lalr1.cc  */
#line 814 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1320 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 463: /* "SwitchCaseClause" */

/* Line 480 of lalr1.cc  */
#line 814 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1329 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 464: /* "SwitchCaseOperandList" */

/* Line 480 of lalr1.cc  */
#line 814 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1338 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 465: /* "SwitchStatement" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1347 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 468: /* "TypeswitchExpr" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1356 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 469: /* "TypeswitchStatement" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1365 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 470: /* "CaseClauseList" */

/* Line 480 of lalr1.cc  */
#line 803 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1374 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 471: /* "CaseClause" */

/* Line 480 of lalr1.cc  */
#line 803 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1383 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 474: /* "SequenceTypeList" */

/* Line 480 of lalr1.cc  */
#line 810 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1392 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 475: /* "IfExpr" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1401 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 476: /* "OrExpr" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1410 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 477: /* "AndExpr" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1419 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 478: /* "NotExpr" */

/* Line 480 of lalr1.cc  */
#line 815 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1428 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 479: /* "ComparisonExpr" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1437 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 480: /* "FTContainsExpr" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1446 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 481: /* "StringConcatExpr" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1455 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 482: /* "opt_FTIgnoreOption" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1464 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 483: /* "RangeExpr" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1473 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 484: /* "AdditiveExpr" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1482 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 485: /* "MultiplicativeExpr" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1491 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 486: /* "UnionExpr" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1500 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 487: /* "IntersectExceptExpr" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1509 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 488: /* "InstanceofExpr" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1518 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 489: /* "TreatExpr" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1527 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 490: /* "CastableExpr" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1536 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 491: /* "CastExpr" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1545 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 492: /* "SingleType" */

/* Line 480 of lalr1.cc  */
#line 810 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1554 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 493: /* "UnaryExpr" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1563 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 494: /* "SignList" */

/* Line 480 of lalr1.cc  */
#line 810 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1572 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 495: /* "ValueExpr" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1581 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 496: /* "SimpleMapExpr" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1590 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 497: /* "ValueComp" */

/* Line 480 of lalr1.cc  */
#line 811 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1599 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 498: /* "ValidateExpr" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1608 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 499: /* "ExtensionExpr" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1617 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 500: /* "Pragma_list" */

/* Line 480 of lalr1.cc  */
#line 808 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1626 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 501: /* "Pragma" */

/* Line 480 of lalr1.cc  */
#line 808 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1635 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 502: /* "PathExpr" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1644 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 504: /* "RelativePathExpr" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1653 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 505: /* "StepExpr" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1662 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 506: /* "AxisStep" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1671 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 507: /* "ForwardStep" */

/* Line 480 of lalr1.cc  */
#line 801 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1680 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 508: /* "ForwardAxis" */

/* Line 480 of lalr1.cc  */
#line 801 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1689 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 509: /* "AbbrevForwardStep" */

/* Line 480 of lalr1.cc  */
#line 801 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1698 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 510: /* "ReverseStep" */

/* Line 480 of lalr1.cc  */
#line 801 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1707 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 511: /* "ReverseAxis" */

/* Line 480 of lalr1.cc  */
#line 801 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1716 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 512: /* "NodeTest" */

/* Line 480 of lalr1.cc  */
#line 801 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1725 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 513: /* "NameTest" */

/* Line 480 of lalr1.cc  */
#line 806 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1734 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 514: /* "Wildcard" */

/* Line 480 of lalr1.cc  */
#line 813 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1743 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 515: /* "FilterExpr" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1752 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 516: /* "PredicateList" */

/* Line 480 of lalr1.cc  */
#line 808 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1761 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 517: /* "Predicate" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1770 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 518: /* "PrimaryExpr" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1779 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 519: /* "Literal" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1788 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 520: /* "NumericLiteral" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1797 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 522: /* "VarRef" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1806 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 523: /* "ParenthesizedExpr" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1815 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 524: /* "ContextItemExpr" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1824 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 525: /* "OrderedExpr" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1833 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 526: /* "UnorderedExpr" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1842 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 527: /* "FunctionCall" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1851 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 528: /* "ArgList" */

/* Line 480 of lalr1.cc  */
#line 802 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1860 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 532: /* "Constructor" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1869 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 533: /* "DirectConstructor" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1878 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 534: /* "DirElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1887 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 535: /* "DirElemContentList" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1896 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 536: /* "DirAttributeList" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1905 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 537: /* "DirAttr" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1914 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 539: /* "DirAttributeValue" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1923 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 540: /* "opt_QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1932 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 541: /* "QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1941 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 542: /* "opt_AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 802 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1950 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 543: /* "AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 802 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1959 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 544: /* "QuoteAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1968 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 545: /* "AposAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 802 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1977 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 546: /* "DirElemContent" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1986 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 547: /* "CommonContent" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1995 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 548: /* "DirCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2004 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 549: /* "DirPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2013 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 550: /* "CDataSection" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2022 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 551: /* "ComputedConstructor" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2031 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 552: /* "CompDocConstructor" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2040 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 553: /* "CompElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2049 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 554: /* "CompAttrConstructor" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2058 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 555: /* "CompTextConstructor" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2067 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 556: /* "CompCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2076 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 557: /* "CompPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2085 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 558: /* "CompNamespaceConstructor" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2094 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 559: /* "TypeDeclaration" */

/* Line 480 of lalr1.cc  */
#line 810 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2103 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 560: /* "SequenceType" */

/* Line 480 of lalr1.cc  */
#line 810 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2112 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 561: /* "OccurrenceIndicator" */

/* Line 480 of lalr1.cc  */
#line 806 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2121 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 562: /* "ItemType" */

/* Line 480 of lalr1.cc  */
#line 806 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2130 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 563: /* "TypeList" */

/* Line 480 of lalr1.cc  */
#line 813 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2139 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 564: /* "GeneralizedAtomicType" */

/* Line 480 of lalr1.cc  */
#line 803 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2148 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 565: /* "SimpleType" */

/* Line 480 of lalr1.cc  */
#line 803 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2157 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 566: /* "KindTest" */

/* Line 480 of lalr1.cc  */
#line 806 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2166 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 567: /* "AnyKindTest" */

/* Line 480 of lalr1.cc  */
#line 802 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2175 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 569: /* "DocumentTest" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2184 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 570: /* "NamespaceTest" */

/* Line 480 of lalr1.cc  */
#line 810 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2193 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 571: /* "TextTest" */

/* Line 480 of lalr1.cc  */
#line 810 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2202 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 572: /* "CommentTest" */

/* Line 480 of lalr1.cc  */
#line 803 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2211 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 573: /* "PITest" */

/* Line 480 of lalr1.cc  */
#line 808 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2220 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 574: /* "AttributeTest" */

/* Line 480 of lalr1.cc  */
#line 803 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2229 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 575: /* "SchemaAttributeTest" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2238 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 576: /* "ElementTest" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2247 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 577: /* "SchemaElementTest" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2256 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 578: /* "TypeName" */

/* Line 480 of lalr1.cc  */
#line 810 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2265 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 579: /* "TypeName_WITH_HOOK" */

/* Line 480 of lalr1.cc  */
#line 810 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2274 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 580: /* "StringLiteral" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2283 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 582: /* "AnyFunctionTest" */

/* Line 480 of lalr1.cc  */
#line 813 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2292 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 583: /* "TypedFunctionTest" */

/* Line 480 of lalr1.cc  */
#line 813 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2301 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 586: /* "InsertExpr" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2310 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 587: /* "DeleteExpr" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2319 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 588: /* "ReplaceExpr" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2328 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 589: /* "RenameExpr" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2337 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 590: /* "TransformExpr" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2346 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 591: /* "VarNameList" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2355 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 592: /* "VarNameDecl" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2364 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 593: /* "TryExpr" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2373 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 594: /* "CatchListExpr" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2382 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 595: /* "CatchExpr" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2391 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 596: /* "BracedExpr" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2400 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 597: /* "NameTestList" */

/* Line 480 of lalr1.cc  */
#line 820 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ delete (yyvaluep->name_test_list); };

/* Line 480 of lalr1.cc  */
#line 2409 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 598: /* "FTSelection" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2418 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 601: /* "FTOr" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2427 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 602: /* "FTAnd" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2436 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 603: /* "FTMildNot" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2445 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 604: /* "FTUnaryNot" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2454 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 605: /* "FTPrimaryWithOptions" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2463 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 606: /* "opt_FTMatchOptions" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2472 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 608: /* "FTWeight" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2481 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 609: /* "FTPrimary" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2490 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 610: /* "opt_FTTimes" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2499 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 611: /* "FTExtensionSelection" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2508 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 613: /* "FTWords" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2517 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 614: /* "FTWordsValue" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2526 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 616: /* "FTAnyallOption" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2535 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 619: /* "FTPosFilter" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2544 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 620: /* "FTOrder" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2553 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 621: /* "FTWindow" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2562 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 622: /* "FTDistance" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2571 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 623: /* "FTUnit" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2580 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 624: /* "FTMatchOptions" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2589 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 625: /* "FTMatchOption" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2598 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 626: /* "FTCaseOption" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2607 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 627: /* "FTDiacriticsOption" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2616 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 628: /* "FTExtensionOption" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2625 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 629: /* "FTStemOption" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2634 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 630: /* "FTThesaurusOption" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2643 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 634: /* "FTThesaurusID" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2652 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 637: /* "FTStopWordOption" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2661 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 638: /* "FTStopWords" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2670 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 642: /* "FTStopWordsInclExcl" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2679 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 643: /* "FTLanguageOption" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2688 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 644: /* "FTWildCardOption" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2697 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 645: /* "FTContent" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2706 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 646: /* "FTTimes" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2715 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 647: /* "FTRange" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2724 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 648: /* "FTScope" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2733 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 649: /* "FTBigUnit" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2742 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 650: /* "FTIgnoreOption" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2751 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 651: /* "JSONArrayConstructor" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2760 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 652: /* "JSONSimpleObjectUnion" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2769 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 653: /* "JSONAccumulatorObjectUnion" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2778 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 654: /* "JSONObjectConstructor" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2787 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 655: /* "JSONPairList" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2796 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 656: /* "JSONInsertExpr" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2805 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 657: /* "JSONAppendExpr" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2814 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 658: /* "JSONDeleteExpr" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2823 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 659: /* "JSONRenameExpr" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2832 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 660: /* "JSONReplaceExpr" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2841 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 666: /* "QNAME" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2850 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 667: /* "FUNCTION_NAME" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2859 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 668: /* "EQNAME" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2868 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
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
#line 128 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
{
    yylloc.begin.filename = yylloc.end.filename = &(driver.theFilename2);
}

/* Line 565 of lalr1.cc  */
#line 2965 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"

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
#line 856 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      }
    break;

  case 4:

/* Line 690 of lalr1.cc  */
#line 860 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      }
    break;

  case 5:

/* Line 690 of lalr1.cc  */
#line 864 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      }
    break;

  case 6:

/* Line 690 of lalr1.cc  */
#line 870 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.node) = NULL;
      }
    break;

  case 7:

/* Line 690 of lalr1.cc  */
#line 874 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.node) = NULL; YYABORT;
      }
    break;

  case 8:

/* Line 690 of lalr1.cc  */
#line 878 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.node) = NULL; YYABORT;
      }
    break;

  case 9:

/* Line 690 of lalr1.cc  */
#line 884 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 10:

/* Line 690 of lalr1.cc  */
#line 890 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      MainModule* mm = dynamic_cast<MainModule*>((yysemantic_stack_[(2) - (2)].node));
      mm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 11:

/* Line 690 of lalr1.cc  */
#line 898 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 12:

/* Line 690 of lalr1.cc  */
#line 904 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      LibraryModule* lm = dynamic_cast<LibraryModule*>((yysemantic_stack_[(2) - (2)].node));
      lm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 13:

/* Line 690 of lalr1.cc  */
#line 913 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), "utf-8" );
    }
    break;

  case 14:

/* Line 690 of lalr1.cc  */
#line 918 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );
    }
    break;

  case 15:

/* Line 690 of lalr1.cc  */
#line 923 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), "utf-8", VersionDecl::jsoniq );
    }
    break;

  case 16:

/* Line 690 of lalr1.cc  */
#line 928 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)), VersionDecl::jsoniq );
    }
    break;

  case 17:

/* Line 690 of lalr1.cc  */
#line 934 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (1)].node)), NULL);
      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(3) - (3)].expr)), prolog);
    }
    break;

  case 18:

/* Line 690 of lalr1.cc  */
#line 940 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (1)].node)));
      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(3) - (3)].expr)), prolog);
    }
    break;

  case 19:

/* Line 690 of lalr1.cc  */
#line 946 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)),
                                  static_cast<SIND_DeclList*>((yysemantic_stack_[(5) - (1)].node)),
                                  static_cast<VFO_DeclList*>((yysemantic_stack_[(5) - (3)].node)));
      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(5) - (5)].expr)), prolog);
    }
    break;

  case 20:

/* Line 690 of lalr1.cc  */
#line 954 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new MainModule( LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(1) - (1)].expr)), NULL );
    }
    break;

  case 21:

/* Line 690 of lalr1.cc  */
#line 959 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].expr);
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after statement.");
      YYERROR;
    }
    break;

  case 22:

/* Line 690 of lalr1.cc  */
#line 967 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].expr);
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 23:

/* Line 690 of lalr1.cc  */
#line 975 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(5) - (1)].node); (yyval.node) = (yysemantic_stack_[(5) - (3)].node); (yyval.node) = (yysemantic_stack_[(5) - (5)].expr);
      (yylocation_stack_[(5) - (3)]).step();
      error((yylocation_stack_[(5) - (3)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 24:

/* Line 690 of lalr1.cc  */
#line 983 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(5) - (1)].node); (yyval.node) = (yysemantic_stack_[(5) - (3)].node); (yyval.node) = (yysemantic_stack_[(5) - (5)].expr);
      (yylocation_stack_[(5) - (1)]).step();
      error((yylocation_stack_[(5) - (1)]), "syntax error, missing semicolon \";\" after statement.");
      YYERROR;
    }
    break;

  case 25:

/* Line 690 of lalr1.cc  */
#line 992 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(1) - (1)].node)), NULL);
    }
    break;

  case 26:

/* Line 690 of lalr1.cc  */
#line 997 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (2)].node)), NULL);
      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(3) - (1)].node)), prolog);
    }
    break;

  case 27:

/* Line 690 of lalr1.cc  */
#line 1003 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (2)].node)));
      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(3) - (1)].node)), prolog);
    }
    break;

  case 28:

/* Line 690 of lalr1.cc  */
#line 1009 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)),
                                  static_cast<SIND_DeclList*>((yysemantic_stack_[(5) - (2)].node)),
                                  static_cast<VFO_DeclList*>((yysemantic_stack_[(5) - (4)].node)));
      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(5) - (1)].node)), prolog);
    }
    break;

  case 29:

/* Line 690 of lalr1.cc  */
#line 1018 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      ERROR_IF_QNAME_NOT_NCNAME((yysemantic_stack_[(6) - (3)].expr), (yylocation_stack_[(6) - (3)]));
      (yyval.node) = new ModuleDecl( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );
      dynamic_cast<ModuleDecl*>((yyval.node))->setComment( SYMTAB((yysemantic_stack_[(6) - (1)].sval)) );
    }
    break;

  case 30:

/* Line 690 of lalr1.cc  */
#line 1026 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      SIND_DeclList *sdl = new SIND_DeclList( LOC((yyloc)) );
      sdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
      (yyval.node) = sdl;
    }
    break;

  case 31:

/* Line 690 of lalr1.cc  */
#line 1033 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      ((SIND_DeclList*)(yysemantic_stack_[(3) - (1)].node))->push_back( (yysemantic_stack_[(3) - (3)].node) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 32:

/* Line 690 of lalr1.cc  */
#line 1039 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 46:

/* Line 690 of lalr1.cc  */
#line 1065 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new BoundarySpaceDecl(LOC((yyloc)), StaticContextConsts::preserve_space);
    }
    break;

  case 47:

/* Line 690 of lalr1.cc  */
#line 1070 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new BoundarySpaceDecl(LOC((yyloc)), StaticContextConsts::strip_space);
    }
    break;

  case 48:

/* Line 690 of lalr1.cc  */
#line 1076 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DefaultCollationDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (4)].sval)) );
    }
    break;

  case 49:

/* Line 690 of lalr1.cc  */
#line 1082 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new BaseURIDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
    }
    break;

  case 50:

/* Line 690 of lalr1.cc  */
#line 1088 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new ConstructionDecl(LOC((yyloc)), StaticContextConsts::cons_preserve);
    }
    break;

  case 51:

/* Line 690 of lalr1.cc  */
#line 1093 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new ConstructionDecl(LOC((yyloc)), StaticContextConsts::cons_strip);
    }
    break;

  case 52:

/* Line 690 of lalr1.cc  */
#line 1099 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new OrderingModeDecl(LOC((yyloc)), StaticContextConsts::ordered);
    }
    break;

  case 53:

/* Line 690 of lalr1.cc  */
#line 1104 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new OrderingModeDecl(LOC((yyloc)), StaticContextConsts::unordered);
    }
    break;

  case 54:

/* Line 690 of lalr1.cc  */
#line 1110 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new EmptyOrderDecl(LOC((yyloc)), StaticContextConsts::empty_greatest);
    }
    break;

  case 55:

/* Line 690 of lalr1.cc  */
#line 1115 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new EmptyOrderDecl(LOC((yyloc)), StaticContextConsts::empty_least);
    }
    break;

  case 56:

/* Line 690 of lalr1.cc  */
#line 1121 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)), true, true);
    }
    break;

  case 57:

/* Line 690 of lalr1.cc  */
#line 1126 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)), true, false);
    }
    break;

  case 58:

/* Line 690 of lalr1.cc  */
#line 1131 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)), false, true);
    }
    break;

  case 59:

/* Line 690 of lalr1.cc  */
#line 1136 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)), false, false);
    }
    break;

  case 62:

/* Line 690 of lalr1.cc  */
#line 1146 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yyval.node);
      error((yylocation_stack_[(3) - (2)]), "syntax error, \"import\" should be followed by either \"schema\" or \"module\".");
      YYERROR;
    }
    break;

  case 63:

/* Line 690 of lalr1.cc  */
#line 1154 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SchemaImport( LOC((yyloc)), NULL, SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL );
    }
    break;

  case 64:

/* Line 690 of lalr1.cc  */
#line 1159 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(4) - (3)].node)),
                            SYMTAB((yysemantic_stack_[(4) - (4)].sval)),
                            NULL);
    }
    break;

  case 65:

/* Line 690 of lalr1.cc  */
#line 1167 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            NULL,
                            SYMTAB((yysemantic_stack_[(5) - (3)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 66:

/* Line 690 of lalr1.cc  */
#line 1175 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(6) - (3)].node)),
                            SYMTAB((yysemantic_stack_[(6) - (4)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(6) - (6)].node)));
    }
    break;

  case 67:

/* Line 690 of lalr1.cc  */
#line 1184 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      URILiteralList *ull = new URILiteralList( LOC((yyloc)));
      ull->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
      (yyval.node) = ull;
    }
    break;

  case 68:

/* Line 690 of lalr1.cc  */
#line 1191 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      if ( URILiteralList *ull = dynamic_cast<URILiteralList*>((yysemantic_stack_[(3) - (1)].node)) )
        ull->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 69:

/* Line 690 of lalr1.cc  */
#line 1199 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      ERROR_IF_QNAME_NOT_NCNAME((yysemantic_stack_[(3) - (2)].expr), (yylocation_stack_[(3) - (2)]));
      (yyval.node) = new SchemaPrefix( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)));
    }
    break;

  case 70:

/* Line 690 of lalr1.cc  */
#line 1205 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SchemaPrefix( LOC((yyloc)), true );
    }
    break;

  case 71:

/* Line 690 of lalr1.cc  */
#line 1211 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL);
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(3) - (2)].sval)));
    }
    break;

  case 72:

/* Line 690 of lalr1.cc  */
#line 1217 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      ERROR_IF_QNAME_NOT_NCNAME((yysemantic_stack_[(6) - (4)].expr), (yylocation_stack_[(6) - (4)]));
      (yyval.node) = new ModuleImport(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(6) - (4)].expr)), SYMTAB((yysemantic_stack_[(6) - (6)].sval)), NULL);
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(6) - (2)].sval)));
    }
    break;

  case 73:

/* Line 690 of lalr1.cc  */
#line 1224 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)),
                            SYMTAB((yysemantic_stack_[(5) - (3)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(5) - (2)].sval)));
    }
    break;

  case 74:

/* Line 690 of lalr1.cc  */
#line 1232 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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
#line 1243 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      ERROR_IF_QNAME_NOT_NCNAME((yysemantic_stack_[(5) - (3)].expr), (yylocation_stack_[(5) - (3)]));
      (yyval.node) = new NamespaceDecl( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (3)].expr)), SYMTAB((yysemantic_stack_[(5) - (5)].sval)) );
    }
    break;

  case 76:

/* Line 690 of lalr1.cc  */
#line 1250 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DefaultNamespaceDecl(LOC((yyloc)),
                                    ParseConstants::ns_element_default,
                                    SYMTAB((yysemantic_stack_[(5) - (5)].sval)));
    }
    break;

  case 77:

/* Line 690 of lalr1.cc  */
#line 1257 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DefaultNamespaceDecl(LOC((yyloc)),
                                    ParseConstants::ns_function_default,
                                    SYMTAB((yysemantic_stack_[(5) - (5)].sval)));
    }
    break;

  case 78:

/* Line 690 of lalr1.cc  */
#line 1265 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      VFO_DeclList *vdl = new VFO_DeclList( LOC((yyloc)));
      vdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
      (yyval.node) = vdl;
    }
    break;

  case 79:

/* Line 690 of lalr1.cc  */
#line 1272 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      ((VFO_DeclList*)(yysemantic_stack_[(3) - (1)].node))->push_back( (yysemantic_stack_[(3) - (3)].node) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 80:

/* Line 690 of lalr1.cc  */
#line 1278 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 89:

/* Line 690 of lalr1.cc  */
#line 1297 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DecimalFormatNode(LOC((yyloc)), (yysemantic_stack_[(4) - (4)].vstrpair));
      delete (yysemantic_stack_[(4) - (4)].vstrpair);
    }
    break;

  case 90:

/* Line 690 of lalr1.cc  */
#line 1303 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DecimalFormatNode(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), (yysemantic_stack_[(4) - (4)].vstrpair));
      delete (yysemantic_stack_[(4) - (4)].vstrpair);
    }
    break;

  case 91:

/* Line 690 of lalr1.cc  */
#line 1310 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.vstrpair) = new vector<string_pair_t>();
      (yyval.vstrpair)->push_back( *(yysemantic_stack_[(1) - (1)].strpair) );
      delete (yysemantic_stack_[(1) - (1)].strpair);
    }
    break;

  case 92:

/* Line 690 of lalr1.cc  */
#line 1317 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yysemantic_stack_[(2) - (1)].vstrpair)->push_back( *(yysemantic_stack_[(2) - (2)].strpair) );
      delete (yysemantic_stack_[(2) - (2)].strpair);
      (yyval.vstrpair) = (yysemantic_stack_[(2) - (1)].vstrpair);
    }
    break;

  case 93:

/* Line 690 of lalr1.cc  */
#line 1325 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      StringLiteral *sl = static_cast<StringLiteral*>((yysemantic_stack_[(3) - (3)].expr));
      (yyval.strpair) = new string_pair_t( (yysemantic_stack_[(3) - (1)].strval), sl->get_strval().str() );
      delete sl;
    }
    break;

  case 94:

/* Line 690 of lalr1.cc  */
#line 1332 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "decimal-separator"; }
    break;

  case 95:

/* Line 690 of lalr1.cc  */
#line 1333 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "digit"; }
    break;

  case 96:

/* Line 690 of lalr1.cc  */
#line 1334 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "grouping-separator"; }
    break;

  case 97:

/* Line 690 of lalr1.cc  */
#line 1335 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "infinity"; }
    break;

  case 98:

/* Line 690 of lalr1.cc  */
#line 1336 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "minus-sign"; }
    break;

  case 99:

/* Line 690 of lalr1.cc  */
#line 1337 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "NaN"; }
    break;

  case 100:

/* Line 690 of lalr1.cc  */
#line 1338 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "pattern-separator"; }
    break;

  case 101:

/* Line 690 of lalr1.cc  */
#line 1339 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "percent"; }
    break;

  case 102:

/* Line 690 of lalr1.cc  */
#line 1340 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "per-mille"; }
    break;

  case 103:

/* Line 690 of lalr1.cc  */
#line 1341 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "zero-digit"; }
    break;

  case 104:

/* Line 690 of lalr1.cc  */
#line 1345 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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
#line 1359 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new FTOptionDecl( LOC((yyloc)), dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (3)].node)) );
    }
    break;

  case 106:

/* Line 690 of lalr1.cc  */
#line 1365 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(4) - (4)].node);
    }
    break;

  case 107:

/* Line 690 of lalr1.cc  */
#line 1371 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      CtxItemDecl* d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(3) - (3)].node));
      d->theType = (yysemantic_stack_[(3) - (2)].node);
      (yyval.node) = d;
    }
    break;

  case 108:

/* Line 690 of lalr1.cc  */
#line 1378 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 109:

/* Line 690 of lalr1.cc  */
#line 1384 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      CtxItemDecl* d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(1) - (1)].node));
      d->theIsExternal = false;
      (yyval.node) = d;
    }
    break;

  case 110:

/* Line 690 of lalr1.cc  */
#line 1391 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CtxItemDecl(LOC((yyloc)), NULL);
    }
    break;

  case 111:

/* Line 690 of lalr1.cc  */
#line 1396 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 112:

/* Line 690 of lalr1.cc  */
#line 1402 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CtxItemDecl(LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 113:

/* Line 690 of lalr1.cc  */
#line 1408 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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
#line 1420 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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
#line 1432 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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
#line 1445 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)), NULL, NULL);
    }
    break;

  case 117:

/* Line 690 of lalr1.cc  */
#line 1450 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)),
                              dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (4)].node)),
                              NULL);
    }
    break;

  case 118:

/* Line 690 of lalr1.cc  */
#line 1458 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(4) - (4)].expr)),
                              NULL,
                              static_cast<AnnotationListParsenode*>((yysemantic_stack_[(4) - (1)].node)));
    }
    break;

  case 119:

/* Line 690 of lalr1.cc  */
#line 1466 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(5) - (4)].expr)),
                              dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (5)].node)),
                              static_cast<AnnotationListParsenode*>((yysemantic_stack_[(5) - (1)].node)));
    }
    break;

  case 120:

/* Line 690 of lalr1.cc  */
#line 1475 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AnnotationListParsenode(LOC((yyloc)), static_cast<AnnotationParsenode*>((yysemantic_stack_[(1) - (1)].node)));
    }
    break;

  case 121:

/* Line 690 of lalr1.cc  */
#line 1480 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      static_cast<AnnotationListParsenode*>((yysemantic_stack_[(2) - (1)].node))->push_back(static_cast<AnnotationParsenode*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 122:

/* Line 690 of lalr1.cc  */
#line 1487 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))), NULL);
    }
    break;

  case 123:

/* Line 690 of lalr1.cc  */
#line 1492 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)),
                                   new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (1)].sval))),
                                   static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 124:

/* Line 690 of lalr1.cc  */
#line 1499 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), true), NULL);
    }
    break;

  case 125:

/* Line 690 of lalr1.cc  */
#line 1504 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)),
                                   new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (1)].sval)), true),
                                   static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 126:

/* Line 690 of lalr1.cc  */
#line 1512 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AnnotationLiteralListParsenode(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr));
    }
    break;

  case 127:

/* Line 690 of lalr1.cc  */
#line 1517 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(3) - (1)].node))->push_back((yysemantic_stack_[(3) - (3)].expr));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 128:

/* Line 690 of lalr1.cc  */
#line 1524 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      static_cast<FunctionDecl*>((yysemantic_stack_[(2) - (2)].node))->setComment( SYMTAB((yysemantic_stack_[(2) - (1)].sval)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 129:

/* Line 690 of lalr1.cc  */
#line 1530 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      FunctionDecl* fdecl = static_cast<FunctionDecl*>((yysemantic_stack_[(3) - (3)].node));
      fdecl->setComment( SYMTAB((yysemantic_stack_[(3) - (1)].sval)) );
      fdecl->set_annotations(static_cast<AnnotationListParsenode*>((yysemantic_stack_[(3) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
    }
    break;

  case 130:

/* Line 690 of lalr1.cc  */
#line 1539 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 131:

/* Line 690 of lalr1.cc  */
#line 1544 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 132:

/* Line 690 of lalr1.cc  */
#line 1550 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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
#line 1561 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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
#line 1574 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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
#line 1586 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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
#line 1599 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(NULL);
    }
    break;

  case 137:

/* Line 690 of lalr1.cc  */
#line 1604 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (2)].node)));
    }
    break;

  case 138:

/* Line 690 of lalr1.cc  */
#line 1609 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(NULL, dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node)));
    }
    break;

  case 139:

/* Line 690 of lalr1.cc  */
#line 1614 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(dynamic_cast<ParamList*>((yysemantic_stack_[(5) - (2)].node)), dynamic_cast<SequenceType*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 140:

/* Line 690 of lalr1.cc  */
#line 1620 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      ParamList *pl = new ParamList( LOC((yyloc)) );
      pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = pl;
    }
    break;

  case 141:

/* Line 690 of lalr1.cc  */
#line 1627 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      if ( ParamList *pl = dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (1)].node)) )
        pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(3) - (3)].node)) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 142:

/* Line 690 of lalr1.cc  */
#line 1635 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL);
    }
    break;

  case 143:

/* Line 690 of lalr1.cc  */
#line 1640 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)),
                     static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                     dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 144:

/* Line 690 of lalr1.cc  */
#line 1648 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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
#line 1656 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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
#line 1664 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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
#line 1672 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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
#line 1682 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL));
    }
    break;

  case 149:

/* Line 690 of lalr1.cc  */
#line 1686 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)),
                                                    (yysemantic_stack_[(2) - (1)].node),
                                                    dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node))));
    }
    break;

  case 150:

/* Line 690 of lalr1.cc  */
#line 1692 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL));
    }
    break;

  case 151:

/* Line 690 of lalr1.cc  */
#line 1696 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)),
                                                    (yysemantic_stack_[(2) - (1)].node),
                                                    dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node))));
    }
    break;

  case 152:

/* Line 690 of lalr1.cc  */
#line 1703 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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
#line 1712 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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
#line 1723 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      IndexKeyList* keyList = new IndexKeyList(LOC((yyloc)));
      keyList->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = keyList;
    }
    break;

  case 155:

/* Line 690 of lalr1.cc  */
#line 1729 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      dynamic_cast<IndexKeyList*>((yysemantic_stack_[(3) - (1)].node))->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 156:

/* Line 690 of lalr1.cc  */
#line 1736 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL, NULL);
    }
    break;

  case 157:

/* Line 690 of lalr1.cc  */
#line 1741 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            dynamic_cast<SequenceType*>((yysemantic_stack_[(2) - (2)].node)),
                            NULL);
    }
    break;

  case 158:

/* Line 690 of lalr1.cc  */
#line 1748 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            NULL,
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
    }
    break;

  case 159:

/* Line 690 of lalr1.cc  */
#line 1755 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(3) - (1)].expr),
                            dynamic_cast<SequenceType*>((yysemantic_stack_[(3) - (2)].node)),
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 160:

/* Line 690 of lalr1.cc  */
#line 1765 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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
#line 1775 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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
#line 1785 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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
#line 1796 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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
#line 1809 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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
#line 1825 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 166:

/* Line 690 of lalr1.cc  */
#line 1829 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 167:

/* Line 690 of lalr1.cc  */
#line 1833 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = NULL;
    }
    break;

  case 168:

/* Line 690 of lalr1.cc  */
#line 1839 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 169:

/* Line 690 of lalr1.cc  */
#line 1843 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 170:

/* Line 690 of lalr1.cc  */
#line 1847 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new BlockBody(LOC((yyloc)));
    }
    break;

  case 171:

/* Line 690 of lalr1.cc  */
#line 1853 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 172:

/* Line 690 of lalr1.cc  */
#line 1858 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      BlockBody* blk = static_cast<BlockBody*>((yysemantic_stack_[(2) - (1)].expr));
      blk->add((yysemantic_stack_[(2) - (2)].expr));
      (yyval.expr) = blk;
    }
    break;

  case 173:

/* Line 690 of lalr1.cc  */
#line 1866 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      BlockBody* blk = new BlockBody(LOC((yyloc)));
      blk->add((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = blk;
    }
    break;

  case 174:

/* Line 690 of lalr1.cc  */
#line 1873 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      BlockBody* blk = static_cast<BlockBody*>((yysemantic_stack_[(2) - (1)].expr));
      blk->add((yysemantic_stack_[(2) - (2)].expr));
      (yyval.expr) = blk;
    }
    break;

  case 175:

/* Line 690 of lalr1.cc  */
#line 1880 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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
#line 1908 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 190:

/* Line 690 of lalr1.cc  */
#line 1914 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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
#line 1936 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 192:

/* Line 690 of lalr1.cc  */
#line 1942 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    }
    break;

  case 193:

/* Line 690 of lalr1.cc  */
#line 1948 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      VarDeclStmt* vdecl = static_cast<VarDeclStmt*>((yysemantic_stack_[(3) - (1)].expr));
      vdecl->add((yysemantic_stack_[(3) - (3)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 194:

/* Line 690 of lalr1.cc  */
#line 1955 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      VarDeclStmt* vdecl = new VarDeclStmt(LOC((yyloc)), NULL);
      vdecl->add((yysemantic_stack_[(2) - (2)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 195:

/* Line 690 of lalr1.cc  */
#line 1962 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      VarDeclStmt* vdecl = new VarDeclStmt(LOC((yyloc)),
                                           static_cast<AnnotationListParsenode*>((yysemantic_stack_[(3) - (1)].node)));
      vdecl->add((yysemantic_stack_[(3) - (3)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 196:

/* Line 690 of lalr1.cc  */
#line 1971 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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
#line 1980 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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
#line 1989 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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
#line 1998 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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
#line 2009 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new AssignExpr(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)), (yysemantic_stack_[(5) - (4)].expr));
    }
    break;

  case 201:

/* Line 690 of lalr1.cc  */
#line 2015 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new ApplyExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr));
    }
    break;

  case 202:

/* Line 690 of lalr1.cc  */
#line 2021 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new ExitExpr(LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr));
    }
    break;

  case 203:

/* Line 690 of lalr1.cc  */
#line 2027 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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
#line 2039 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement(LOC((yyloc)), FlowCtlStatement::BREAK);
    }
    break;

  case 205:

/* Line 690 of lalr1.cc  */
#line 2044 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement( LOC((yyloc)), FlowCtlStatement::CONTINUE );
    }
    break;

  case 206:

/* Line 690 of lalr1.cc  */
#line 2050 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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
#line 2062 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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
#line 2075 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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
#line 2095 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new TryExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 210:

/* Line 690 of lalr1.cc  */
#line 2101 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      CatchListExpr* cle = new CatchListExpr( LOC((yyloc)) );
      cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)) );
      (yyval.expr) = cle;
    }
    break;

  case 211:

/* Line 690 of lalr1.cc  */
#line 2108 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
      if ( cle )
        cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)) );
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    }
    break;

  case 212:

/* Line 690 of lalr1.cc  */
#line 2117 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)), *(yysemantic_stack_[(3) - (2)].name_test_list), (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 213:

/* Line 690 of lalr1.cc  */
#line 2124 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new BlockBody(LOC((yyloc)));
    }
    break;

  case 214:

/* Line 690 of lalr1.cc  */
#line 2130 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 215:

/* Line 690 of lalr1.cc  */
#line 2135 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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
#line 2147 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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
#line 2181 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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
#line 2193 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new ReturnExpr( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr) );
    }
    break;

  case 237:

/* Line 690 of lalr1.cc  */
#line 2199 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.strval) = parser::the_sliding;
    }
    break;

  case 238:

/* Line 690 of lalr1.cc  */
#line 2204 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.strval) = parser::the_tumbling;
    }
    break;

  case 239:

/* Line 690 of lalr1.cc  */
#line 2210 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.strval) = parser::the_start;
    }
    break;

  case 240:

/* Line 690 of lalr1.cc  */
#line 2215 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.strval) = parser::the_end;
    }
    break;

  case 241:

/* Line 690 of lalr1.cc  */
#line 2220 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
    (yyval.strval) = parser::the_only_end;
  }
    break;

  case 242:

/* Line 690 of lalr1.cc  */
#line 2226 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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
#line 2235 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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
#line 2246 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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
#line 2258 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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
#line 2269 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CountClause(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 255:

/* Line 690 of lalr1.cc  */
#line 2287 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      FLWORClauseList *fcl = new FLWORClauseList( LOC((yyloc)) );
      fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = fcl;
    }
    break;

  case 256:

/* Line 690 of lalr1.cc  */
#line 2294 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      FLWORClauseList *fcl = dynamic_cast<FLWORClauseList*>((yysemantic_stack_[(2) - (1)].node));
      fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = fcl;
    }
    break;

  case 257:

/* Line 690 of lalr1.cc  */
#line 2303 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new ForClause(LOC((yyloc)), dynamic_cast<VarInDeclList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 258:

/* Line 690 of lalr1.cc  */
#line 2307 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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
#line 2315 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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
#line 2325 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = NULL;
      error((yylocation_stack_[(2) - (2)]), "");
      YYERROR;
    }
    break;

  case 262:

/* Line 690 of lalr1.cc  */
#line 2334 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
    }
    break;

  case 263:

/* Line 690 of lalr1.cc  */
#line 2339 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      VarInDeclList* vdl = new VarInDeclList( LOC((yyloc)) );
      vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = vdl;
    }
    break;

  case 264:

/* Line 690 of lalr1.cc  */
#line 2346 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      if ( VarInDeclList* vdl = dynamic_cast<VarInDeclList*>((yysemantic_stack_[(4) - (1)].node)) )
        vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
      (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
    }
    break;

  case 265:

/* Line 690 of lalr1.cc  */
#line 2353 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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
#line 2363 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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
#line 2373 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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
#line 2383 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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
#line 2393 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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
#line 2403 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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
#line 2413 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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
#line 2423 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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
#line 2433 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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
#line 2443 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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
#line 2452 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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
#line 2462 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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
#line 2472 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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
#line 2484 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new PositionalVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 279:

/* Line 690 of lalr1.cc  */
#line 2490 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new FTScoreVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 280:

/* Line 690 of lalr1.cc  */
#line 2496 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new LetClause( LOC((yyloc)), dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(2) - (2)].node)) );
        }
    break;

  case 281:

/* Line 690 of lalr1.cc  */
#line 2502 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            VarGetsDeclList *vgdl = new VarGetsDeclList( LOC((yyloc)) );
            vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = vgdl;
        }
    break;

  case 282:

/* Line 690 of lalr1.cc  */
#line 2508 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            if( VarGetsDeclList *vgdl = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(3) - (1)].node)) )
                vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 283:

/* Line 690 of lalr1.cc  */
#line 2516 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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
#line 2524 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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
#line 2532 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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
#line 2540 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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
#line 2550 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                             NULL, (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 288:

/* Line 690 of lalr1.cc  */
#line 2556 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                             dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (3)].node)),
                             (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 290:

/* Line 690 of lalr1.cc  */
#line 2566 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL, NULL);
    }
    break;

  case 291:

/* Line 690 of lalr1.cc  */
#line 2570 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_curr(static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)));
    }
    break;

  case 292:

/* Line 690 of lalr1.cc  */
#line 2577 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), dynamic_cast<PositionalVar*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL, NULL);
    }
    break;

  case 293:

/* Line 690 of lalr1.cc  */
#line 2581 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_posvar(dynamic_cast<PositionalVar*>((yysemantic_stack_[(2) - (1)].node)));
    }
    break;

  case 295:

/* Line 690 of lalr1.cc  */
#line 2589 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), static_cast<QName*>((yysemantic_stack_[(6) - (6)].expr)));
    }
    break;

  case 296:

/* Line 690 of lalr1.cc  */
#line 2593 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 297:

/* Line 690 of lalr1.cc  */
#line 2597 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)), NULL);
    }
    break;

  case 298:

/* Line 690 of lalr1.cc  */
#line 2603 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new WhereClause(LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 299:

/* Line 690 of lalr1.cc  */
#line 2609 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new GroupByClause(LOC((yyloc)), dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 300:

/* Line 690 of lalr1.cc  */
#line 2615 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      GroupSpecList* gsl = new GroupSpecList(LOC((yyloc)));
      gsl->push_back(static_cast<GroupSpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = gsl;
    }
    break;

  case 301:

/* Line 690 of lalr1.cc  */
#line 2621 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      GroupSpecList* gsl = static_cast<GroupSpecList*>((yysemantic_stack_[(3) - (1)].node));
      gsl->push_back(static_cast<GroupSpec*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = gsl;
    }
    break;

  case 302:

/* Line 690 of lalr1.cc  */
#line 2629 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL, NULL, NULL);
    }
    break;

  case 303:

/* Line 690 of lalr1.cc  */
#line 2633 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)), NULL, (yysemantic_stack_[(4) - (4)].expr), NULL);
    }
    break;

  case 304:

/* Line 690 of lalr1.cc  */
#line 2637 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                         static_cast<SequenceType*>((yysemantic_stack_[(5) - (3)].node)),
                         (yysemantic_stack_[(5) - (5)].expr),
                         NULL);
    }
    break;

  case 305:

/* Line 690 of lalr1.cc  */
#line 2645 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                         static_cast<SequenceType*>((yysemantic_stack_[(6) - (3)].node)),
                         (yysemantic_stack_[(6) - (5)].expr),
                         static_cast<GroupCollationSpec*>((yysemantic_stack_[(6) - (6)].node)));
    }
    break;

  case 306:

/* Line 690 of lalr1.cc  */
#line 2653 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                         NULL,
                         (yysemantic_stack_[(5) - (4)].expr),
                         static_cast<GroupCollationSpec*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 307:

/* Line 690 of lalr1.cc  */
#line 2661 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                         NULL,
                         NULL,
                         static_cast<GroupCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 308:

/* Line 690 of lalr1.cc  */
#line 2671 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new GroupCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
    }
    break;

  case 309:

/* Line 690 of lalr1.cc  */
#line 2677 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 310:

/* Line 690 of lalr1.cc  */
#line 2683 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(4) - (4)].node)), true
            );
        }
    break;

  case 311:

/* Line 690 of lalr1.cc  */
#line 2691 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            OrderSpecList *osl = new OrderSpecList( LOC((yyloc)) );
            osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = osl;
        }
    break;

  case 312:

/* Line 690 of lalr1.cc  */
#line 2697 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            if ( OrderSpecList* osl = dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (1)].node)) )
                osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 313:

/* Line 690 of lalr1.cc  */
#line 2705 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderSpec( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL );
        }
    break;

  case 314:

/* Line 690 of lalr1.cc  */
#line 2709 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderSpec(
                LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<OrderModifierPN*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 315:

/* Line 690 of lalr1.cc  */
#line 2717 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL
            );
        }
    break;

  case 316:

/* Line 690 of lalr1.cc  */
#line 2723 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 317:

/* Line 690 of lalr1.cc  */
#line 2729 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, NULL, dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 318:

/* Line 690 of lalr1.cc  */
#line 2735 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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
#line 2744 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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
#line 2753 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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
#line 2762 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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
#line 2773 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_ascending );
        }
    break;

  case 323:

/* Line 690 of lalr1.cc  */
#line 2777 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_descending );
        }
    break;

  case 324:

/* Line 690 of lalr1.cc  */
#line 2783 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_greatest
            );
        }
    break;

  case 325:

/* Line 690 of lalr1.cc  */
#line 2789 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_least
            );
        }
    break;

  case 326:

/* Line 690 of lalr1.cc  */
#line 2797 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 327:

/* Line 690 of lalr1.cc  */
#line 2803 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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
#line 2812 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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
#line 2823 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      QVarInDeclList *qvidl = new QVarInDeclList( LOC((yyloc)) );
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = qvidl;
    }
    break;

  case 330:

/* Line 690 of lalr1.cc  */
#line 2829 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      QVarInDeclList *qvidl = dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
      (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
    }
    break;

  case 331:

/* Line 690 of lalr1.cc  */
#line 2837 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 332:

/* Line 690 of lalr1.cc  */
#line 2841 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                          dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 333:

/* Line 690 of lalr1.cc  */
#line 2850 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new SwitchExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(8) - (5)].node)), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 334:

/* Line 690 of lalr1.cc  */
#line 2856 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = new SwitchCaseClauseList(LOC((yyloc)));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = scc_list_p;
    }
    break;

  case 335:

/* Line 690 of lalr1.cc  */
#line 2862 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 336:

/* Line 690 of lalr1.cc  */
#line 2870 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SwitchCaseClause(LOC((yyloc)), dynamic_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 337:

/* Line 690 of lalr1.cc  */
#line 2876 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = new SwitchCaseOperandList(LOC((yyloc)));
      sco_list_p->push_back((yysemantic_stack_[(2) - (2)].expr));
      (yyval.node) = sco_list_p;
    }
    break;

  case 338:

/* Line 690 of lalr1.cc  */
#line 2882 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = static_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node));
      sco_list_p->push_back((yysemantic_stack_[(3) - (3)].expr));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 339:

/* Line 690 of lalr1.cc  */
#line 2890 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new SwitchExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(8) - (5)].node)), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 340:

/* Line 690 of lalr1.cc  */
#line 2896 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = new SwitchCaseClauseList(LOC((yyloc)));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = scc_list_p;
    }
    break;

  case 341:

/* Line 690 of lalr1.cc  */
#line 2902 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 342:

/* Line 690 of lalr1.cc  */
#line 2910 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SwitchCaseClause(LOC((yyloc)), dynamic_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 343:

/* Line 690 of lalr1.cc  */
#line 2916 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC((yyloc)),
                              (yysemantic_stack_[(8) - (3)].expr),
                              static_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
                              (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 344:

/* Line 690 of lalr1.cc  */
#line 2923 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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
#line 2933 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC((yyloc)),
                              (yysemantic_stack_[(8) - (3)].expr),
                              static_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
                              (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 346:

/* Line 690 of lalr1.cc  */
#line 2940 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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
#line 2950 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
      cc_list_p->push_back(static_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = cc_list_p;
    }
    break;

  case 348:

/* Line 690 of lalr1.cc  */
#line 2956 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      cc_list_p->push_back(static_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 349:

/* Line 690 of lalr1.cc  */
#line 2964 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<SequenceTypeList*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 350:

/* Line 690 of lalr1.cc  */
#line 2970 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                          static_cast<SequenceTypeList*>((yysemantic_stack_[(7) - (5)].node)),
                          (yysemantic_stack_[(7) - (7)].expr));
     }
    break;

  case 351:

/* Line 690 of lalr1.cc  */
#line 2979 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
      cc_list_p->push_back(static_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = cc_list_p;
    }
    break;

  case 352:

/* Line 690 of lalr1.cc  */
#line 2985 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      CaseClauseList* cc_list_p = static_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      cc_list_p->push_back(static_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 353:

/* Line 690 of lalr1.cc  */
#line 2993 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<SequenceTypeList*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 354:

/* Line 690 of lalr1.cc  */
#line 2999 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                          static_cast<SequenceTypeList*>((yysemantic_stack_[(7) - (5)].node)),
                          (yysemantic_stack_[(7) - (7)].expr));
     }
    break;

  case 355:

/* Line 690 of lalr1.cc  */
#line 3008 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      SequenceTypeList* seqList = new SequenceTypeList(LOC((yyloc)));
      seqList->push_back(static_cast<SequenceType*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = seqList;
    }
    break;

  case 356:

/* Line 690 of lalr1.cc  */
#line 3014 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      SequenceTypeList* seqList = static_cast<SequenceTypeList*>((yysemantic_stack_[(3) - (1)].node));
      seqList->push_back(static_cast<SequenceType*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 357:

/* Line 690 of lalr1.cc  */
#line 3022 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new IfExpr(LOC ((yyloc)), (yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (6)].expr), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 358:

/* Line 690 of lalr1.cc  */
#line 3028 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 359:

/* Line 690 of lalr1.cc  */
#line 3032 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new OrExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
    }
    break;

  case 360:

/* Line 690 of lalr1.cc  */
#line 3038 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 361:

/* Line 690 of lalr1.cc  */
#line 3043 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new AndExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 362:

/* Line 690 of lalr1.cc  */
#line 3049 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 363:

/* Line 690 of lalr1.cc  */
#line 3053 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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
#line 3064 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 365:

/* Line 690 of lalr1.cc  */
#line 3068 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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
#line 3079 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 367:

/* Line 690 of lalr1.cc  */
#line 3083 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new FTContainsExpr(
                LOC((yyloc)),
                (yysemantic_stack_[(5) - (1)].expr),
                dynamic_cast<FTSelection*>((yysemantic_stack_[(5) - (4)].node)),
                dynamic_cast<FTIgnoreOption*>((yysemantic_stack_[(5) - (5)].node))
            );
        }
    break;

  case 368:

/* Line 690 of lalr1.cc  */
#line 3094 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 369:

/* Line 690 of lalr1.cc  */
#line 3098 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new StringConcatExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
        }
    break;

  case 370:

/* Line 690 of lalr1.cc  */
#line 3103 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 371:

/* Line 690 of lalr1.cc  */
#line 3107 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 372:

/* Line 690 of lalr1.cc  */
#line 3113 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 373:

/* Line 690 of lalr1.cc  */
#line 3117 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new RangeExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 374:

/* Line 690 of lalr1.cc  */
#line 3123 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 375:

/* Line 690 of lalr1.cc  */
#line 3127 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_plus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 376:

/* Line 690 of lalr1.cc  */
#line 3131 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_minus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 377:

/* Line 690 of lalr1.cc  */
#line 3137 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 378:

/* Line 690 of lalr1.cc  */
#line 3141 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mul, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 379:

/* Line 690 of lalr1.cc  */
#line 3147 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_div, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 380:

/* Line 690 of lalr1.cc  */
#line 3153 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_idiv, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 381:

/* Line 690 of lalr1.cc  */
#line 3159 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mod, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 382:

/* Line 690 of lalr1.cc  */
#line 3167 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 383:

/* Line 690 of lalr1.cc  */
#line 3171 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 384:

/* Line 690 of lalr1.cc  */
#line 3175 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 385:

/* Line 690 of lalr1.cc  */
#line 3181 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 386:

/* Line 690 of lalr1.cc  */
#line 3185 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_intersect, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 387:

/* Line 690 of lalr1.cc  */
#line 3191 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_except, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 388:

/* Line 690 of lalr1.cc  */
#line 3199 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 389:

/* Line 690 of lalr1.cc  */
#line 3203 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InstanceofExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 390:

/* Line 690 of lalr1.cc  */
#line 3211 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 391:

/* Line 690 of lalr1.cc  */
#line 3215 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new TreatExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 392:

/* Line 690 of lalr1.cc  */
#line 3223 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 393:

/* Line 690 of lalr1.cc  */
#line 3227 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new CastableExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 394:

/* Line 690 of lalr1.cc  */
#line 3235 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 395:

/* Line 690 of lalr1.cc  */
#line 3239 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new CastExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 396:

/* Line 690 of lalr1.cc  */
#line 3247 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SingleType(LOC((yyloc)), dynamic_cast<SimpleType*>((yysemantic_stack_[(1) - (1)].node)), false);
    }
    break;

  case 397:

/* Line 690 of lalr1.cc  */
#line 3251 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SingleType(LOC((yyloc)), dynamic_cast<SimpleType*>((yysemantic_stack_[(2) - (1)].node)), true);
    }
    break;

  case 398:

/* Line 690 of lalr1.cc  */
#line 3257 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 399:

/* Line 690 of lalr1.cc  */
#line 3261 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new UnaryExpr( LOC((yyloc)), dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 400:

/* Line 690 of lalr1.cc  */
#line 3267 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), true );
        }
    break;

  case 401:

/* Line 690 of lalr1.cc  */
#line 3271 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), false );
        }
    break;

  case 402:

/* Line 690 of lalr1.cc  */
#line 3275 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 403:

/* Line 690 of lalr1.cc  */
#line 3279 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            if ( SignList *sl = dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)) )
                sl->negate();
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 404:

/* Line 690 of lalr1.cc  */
#line 3287 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 405:

/* Line 690 of lalr1.cc  */
#line 3291 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 406:

/* Line 690 of lalr1.cc  */
#line 3295 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 407:

/* Line 690 of lalr1.cc  */
#line 3301 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
      }
    break;

  case 408:

/* Line 690 of lalr1.cc  */
#line 3306 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.expr) = new SimpleMapExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
      }
    break;

  case 409:

/* Line 690 of lalr1.cc  */
#line 3312 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_eq );
        }
    break;

  case 410:

/* Line 690 of lalr1.cc  */
#line 3316 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ne );
        }
    break;

  case 411:

/* Line 690 of lalr1.cc  */
#line 3320 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_lt );
        }
    break;

  case 412:

/* Line 690 of lalr1.cc  */
#line 3324 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_le );
        }
    break;

  case 413:

/* Line 690 of lalr1.cc  */
#line 3328 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_gt );
        }
    break;

  case 414:

/* Line 690 of lalr1.cc  */
#line 3332 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ge );
        }
    break;

  case 415:

/* Line 690 of lalr1.cc  */
#line 3338 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 416:

/* Line 690 of lalr1.cc  */
#line 3342 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "lax", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 417:

/* Line 690 of lalr1.cc  */
#line 3346 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 418:

/* Line 690 of lalr1.cc  */
#line 3350 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ValidateExpr(
                LOC((yyloc)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (3)].node))->get_name(), (yysemantic_stack_[(6) - (5)].expr)
            );
            delete (yysemantic_stack_[(6) - (3)].node);
        }
    break;

  case 419:

/* Line 690 of lalr1.cc  */
#line 3359 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(3) - (1)].node)), NULL
            );
        }
    break;

  case 420:

/* Line 690 of lalr1.cc  */
#line 3365 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)), (yysemantic_stack_[(4) - (3)].expr)
            );
        }
    break;

  case 421:

/* Line 690 of lalr1.cc  */
#line 3373 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            PragmaList *pl = new PragmaList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = pl;
        }
    break;

  case 422:

/* Line 690 of lalr1.cc  */
#line 3379 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            if ( PragmaList *pl = dynamic_cast<PragmaList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 423:

/* Line 690 of lalr1.cc  */
#line 3387 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
        }
    break;

  case 424:

/* Line 690 of lalr1.cc  */
#line 3391 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) ), "" );
        }
    break;

  case 425:

/* Line 690 of lalr1.cc  */
#line 3395 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), true ), "" );
        }
    break;

  case 426:

/* Line 690 of lalr1.cc  */
#line 3401 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new PathExpr(LOC((yyloc)), ParseConstants::path_leading_lone_slash, NULL);
    }
    break;

  case 427:

/* Line 690 of lalr1.cc  */
#line 3405 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      RelativePathExpr* rpe;
      rpe = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slash, NULL, (yysemantic_stack_[(2) - (2)].expr), false);
      (yyval.expr) = new PathExpr(LOC((yyloc)),
                        ParseConstants::path_leading_slash,
                        rpe);
    }
    break;

  case 428:

/* Line 690 of lalr1.cc  */
#line 3413 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      RelativePathExpr* rpe;
      rpe = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slashslash, NULL, (yysemantic_stack_[(2) - (2)].expr), false);
      (yyval.expr) = new PathExpr(LOC((yyloc)),
                        ParseConstants::path_leading_slashslash,
                        rpe);
    }
    break;

  case 429:

/* Line 690 of lalr1.cc  */
#line 3422 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      RelativePathExpr* rpe = dynamic_cast<RelativePathExpr*>((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = (!rpe ?
            (yysemantic_stack_[(1) - (1)].expr) :
            new PathExpr( LOC((yyloc)), ParseConstants::path_relative, (yysemantic_stack_[(1) - (1)].expr)));
    }
    break;

  case 430:

/* Line 690 of lalr1.cc  */
#line 3431 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = NULL;
    }
    break;

  case 431:

/* Line 690 of lalr1.cc  */
#line 3437 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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

  case 432:

/* Line 690 of lalr1.cc  */
#line 3447 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr), false);
    }
    break;

  case 433:

/* Line 690 of lalr1.cc  */
#line 3451 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slashslash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr), false);
    }
    break;

  case 434:

/* Line 690 of lalr1.cc  */
#line 3457 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 435:

/* Line 690 of lalr1.cc  */
#line 3461 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 436:

/* Line 690 of lalr1.cc  */
#line 3467 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)), dynamic_cast<ForwardStep*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 437:

/* Line 690 of lalr1.cc  */
#line 3473 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)),
                dynamic_cast<ForwardStep*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 438:

/* Line 690 of lalr1.cc  */
#line 3481 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)), dynamic_cast<ReverseStep*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 439:

/* Line 690 of lalr1.cc  */
#line 3487 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)),
                dynamic_cast<ReverseStep*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 440:

/* Line 690 of lalr1.cc  */
#line 3497 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ForwardStep(
                LOC((yyloc)), dynamic_cast<ForwardAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node)
            );
        }
    break;

  case 441:

/* Line 690 of lalr1.cc  */
#line 3503 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ForwardStep(
                LOC((yyloc)), dynamic_cast<AbbrevForwardStep*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 442:

/* Line 690 of lalr1.cc  */
#line 3511 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_child );
        }
    break;

  case 443:

/* Line 690 of lalr1.cc  */
#line 3515 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_descendant);
        }
    break;

  case 444:

/* Line 690 of lalr1.cc  */
#line 3519 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_attribute );
        }
    break;

  case 445:

/* Line 690 of lalr1.cc  */
#line 3523 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_self );
        }
    break;

  case 446:

/* Line 690 of lalr1.cc  */
#line 3527 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ForwardAxis(
                LOC((yyloc)), ParseConstants::axis_descendant_or_self
            );
        }
    break;

  case 447:

/* Line 690 of lalr1.cc  */
#line 3533 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ForwardAxis(
                LOC((yyloc)), ParseConstants::axis_following_sibling
            );
        }
    break;

  case 448:

/* Line 690 of lalr1.cc  */
#line 3539 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_following );
        }
    break;

  case 449:

/* Line 690 of lalr1.cc  */
#line 3545 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new AbbrevForwardStep( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), false );
        }
    break;

  case 450:

/* Line 690 of lalr1.cc  */
#line 3549 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new AbbrevForwardStep( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].node), true );
        }
    break;

  case 451:

/* Line 690 of lalr1.cc  */
#line 3555 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ReverseStep( LOC((yyloc)), dynamic_cast<ReverseAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node) );
        }
    break;

  case 452:

/* Line 690 of lalr1.cc  */
#line 3559 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            ReverseAxis *ra = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_parent
            );
            (yyval.node) = new ReverseStep( LOC((yyloc)), ra, NULL );
        }
    break;

  case 453:

/* Line 690 of lalr1.cc  */
#line 3568 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_parent );
        }
    break;

  case 454:

/* Line 690 of lalr1.cc  */
#line 3572 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_ancestor );
        }
    break;

  case 455:

/* Line 690 of lalr1.cc  */
#line 3576 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_preceding_sibling
            );
        }
    break;

  case 456:

/* Line 690 of lalr1.cc  */
#line 3582 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_preceding );
        }
    break;

  case 457:

/* Line 690 of lalr1.cc  */
#line 3586 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_ancestor_or_self
            );
        }
    break;

  case 458:

/* Line 690 of lalr1.cc  */
#line 3594 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 459:

/* Line 690 of lalr1.cc  */
#line 3598 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 460:

/* Line 690 of lalr1.cc  */
#line 3604 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 461:

/* Line 690 of lalr1.cc  */
#line 3608 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), dynamic_cast<Wildcard*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 462:

/* Line 690 of lalr1.cc  */
#line 3614 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", "", ParseConstants::wild_all, false);
    }
    break;

  case 463:

/* Line 690 of lalr1.cc  */
#line 3618 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), "", ParseConstants::wild_elem, false);
    }
    break;

  case 464:

/* Line 690 of lalr1.cc  */
#line 3622 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), "", ParseConstants::wild_elem, true);
    }
    break;

  case 465:

/* Line 690 of lalr1.cc  */
#line 3626 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", SYMTAB((yysemantic_stack_[(1) - (1)].sval)), ParseConstants::wild_prefix, false);
    }
    break;

  case 466:

/* Line 690 of lalr1.cc  */
#line 3632 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
     }
    break;

  case 467:

/* Line 690 of lalr1.cc  */
#line 3636 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new FilterExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
     }
    break;

  case 468:

/* Line 690 of lalr1.cc  */
#line 3640 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new DynamicFunctionInvocation(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), false);
     }
    break;

  case 469:

/* Line 690 of lalr1.cc  */
#line 3644 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new DynamicFunctionInvocation(LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node)), false);
     }
    break;

  case 470:

/* Line 690 of lalr1.cc  */
#line 3648 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
       ERROR_IF_QNAME_NOT_NCNAME((yysemantic_stack_[(3) - (3)].expr), (yylocation_stack_[(3) - (3)]));
       StringLiteral* sl = new StringLiteral( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)) );
       (yyval.expr) = new JSONObjectLookup(LOC((yyloc)), LOC((yylocation_stack_[(3) - (2)])), (yysemantic_stack_[(3) - (1)].expr), sl);
     }
    break;

  case 471:

/* Line 690 of lalr1.cc  */
#line 3654 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new JSONObjectLookup(LOC((yyloc)), LOC((yylocation_stack_[(4) - (2)])), (yysemantic_stack_[(4) - (1)].expr), new ParenthesizedExpr( LOC((yyloc)), NULL));
     }
    break;

  case 472:

/* Line 690 of lalr1.cc  */
#line 3658 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new JSONObjectLookup(LOC((yyloc)), LOC((yylocation_stack_[(5) - (2)])), (yysemantic_stack_[(5) - (1)].expr), new ParenthesizedExpr( LOC((yyloc)), (yysemantic_stack_[(5) - (4)].expr) ));
     }
    break;

  case 473:

/* Line 690 of lalr1.cc  */
#line 3662 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.expr) = new JSONObjectLookup(LOC((yyloc)), LOC((yylocation_stack_[(3) - (2)])), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
     }
    break;

  case 474:

/* Line 690 of lalr1.cc  */
#line 3666 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new JSONObjectLookup(LOC((yyloc)), LOC((yylocation_stack_[(3) - (2)])), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
     }
    break;

  case 475:

/* Line 690 of lalr1.cc  */
#line 3672 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            PredicateList *pl = new PredicateList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<exprnode*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.node) = pl;
        }
    break;

  case 476:

/* Line 690 of lalr1.cc  */
#line 3678 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            if ( PredicateList *pl = dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<exprnode*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 477:

/* Line 690 of lalr1.cc  */
#line 3686 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
        }
    break;

  case 478:

/* Line 690 of lalr1.cc  */
#line 3692 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 479:

/* Line 690 of lalr1.cc  */
#line 3696 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 480:

/* Line 690 of lalr1.cc  */
#line 3700 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 481:

/* Line 690 of lalr1.cc  */
#line 3704 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 482:

/* Line 690 of lalr1.cc  */
#line 3708 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 483:

/* Line 690 of lalr1.cc  */
#line 3712 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 484:

/* Line 690 of lalr1.cc  */
#line 3716 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 485:

/* Line 690 of lalr1.cc  */
#line 3720 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 486:

/* Line 690 of lalr1.cc  */
#line 3724 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 487:

/* Line 690 of lalr1.cc  */
#line 3728 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 488:

/* Line 690 of lalr1.cc  */
#line 3732 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 489:

/* Line 690 of lalr1.cc  */
#line 3736 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 490:

/* Line 690 of lalr1.cc  */
#line 3740 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 491:

/* Line 690 of lalr1.cc  */
#line 3744 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 492:

/* Line 690 of lalr1.cc  */
#line 3750 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 493:

/* Line 690 of lalr1.cc  */
#line 3754 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 494:

/* Line 690 of lalr1.cc  */
#line 3758 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            driver.addCommonLanguageWarning((yylocation_stack_[(1) - (1)]), ZED(ZWST0009_TRUE_FALSE_NULL_KEYWORDS));
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 495:

/* Line 690 of lalr1.cc  */
#line 3763 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            driver.addCommonLanguageWarning((yylocation_stack_[(1) - (1)]), ZED(ZWST0009_TRUE_FALSE_NULL_KEYWORDS));
            (yyval.expr) = new NullLiteral(LOC((yyloc)));
        }
    break;

  case 496:

/* Line 690 of lalr1.cc  */
#line 3770 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_decimal, *(yysemantic_stack_[(1) - (1)].decval)
            );
            delete yylval.decval;
        }
    break;

  case 497:

/* Line 690 of lalr1.cc  */
#line 3777 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_integer, *(yysemantic_stack_[(1) - (1)].ival)
            );
            delete yylval.ival;
        }
    break;

  case 498:

/* Line 690 of lalr1.cc  */
#line 3784 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_double, *(yysemantic_stack_[(1) - (1)].dval)
            );
            delete yylval.dval;
        }
    break;

  case 499:

/* Line 690 of lalr1.cc  */
#line 3793 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new BooleanLiteral(LOC((yyloc)), true);
        }
    break;

  case 500:

/* Line 690 of lalr1.cc  */
#line 3797 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new BooleanLiteral(LOC((yyloc)), false);
        }
    break;

  case 501:

/* Line 690 of lalr1.cc  */
#line 3803 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new VarRef(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)));
        }
    break;

  case 502:

/* Line 690 of lalr1.cc  */
#line 3809 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), NULL);
        }
    break;

  case 503:

/* Line 690 of lalr1.cc  */
#line 3813 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 504:

/* Line 690 of lalr1.cc  */
#line 3819 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ContextItemExpr( LOC((yyloc)) );
        }
    break;

  case 505:

/* Line 690 of lalr1.cc  */
#line 3825 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new OrderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 506:

/* Line 690 of lalr1.cc  */
#line 3831 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new UnorderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 507:

/* Line 690 of lalr1.cc  */
#line 3837 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new FunctionCall( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), NULL );
    }
    break;

  case 508:

/* Line 690 of lalr1.cc  */
#line 3841 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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

  case 509:

/* Line 690 of lalr1.cc  */
#line 3859 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      ArgList *al = new ArgList( LOC((yyloc)) );
      al->push_back(new ArgumentPlaceholder(LOC((yyloc))));
      (yyval.node) = al;
    }
    break;

  case 510:

/* Line 690 of lalr1.cc  */
#line 3865 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      if ( ArgList *al = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node)) )
        al->push_back( new ArgumentPlaceholder(LOC((yyloc))) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 511:

/* Line 690 of lalr1.cc  */
#line 3871 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      ArgList *al = new ArgList( LOC((yyloc)) );
      al->push_back( (yysemantic_stack_[(1) - (1)].expr) );
      (yyval.node) = al;
    }
    break;

  case 512:

/* Line 690 of lalr1.cc  */
#line 3877 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      if ( ArgList *al = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node)) )
        al->push_back( (yysemantic_stack_[(3) - (3)].expr) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 513:

/* Line 690 of lalr1.cc  */
#line 3885 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 514:

/* Line 690 of lalr1.cc  */
#line 3889 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 515:

/* Line 690 of lalr1.cc  */
#line 3895 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new LiteralFunctionItem(LOC ((yyloc)), dynamic_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].ival));
    }
    break;

  case 516:

/* Line 690 of lalr1.cc  */
#line 3901 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new InlineFunction(LOC((yyloc)),
                              &*(yysemantic_stack_[(3) - (2)].fnsig)->theParams,
                              &*(yysemantic_stack_[(3) - (2)].fnsig)->theReturnType,
                              (yysemantic_stack_[(3) - (3)].expr));
      delete (yysemantic_stack_[(3) - (2)].fnsig);
    }
    break;

  case 517:

/* Line 690 of lalr1.cc  */
#line 3911 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 518:

/* Line 690 of lalr1.cc  */
#line 3915 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 519:

/* Line 690 of lalr1.cc  */
#line 3921 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 520:

/* Line 690 of lalr1.cc  */
#line 3925 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 521:

/* Line 690 of lalr1.cc  */
#line 3929 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 522:

/* Line 690 of lalr1.cc  */
#line 3935 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new DirElemConstructor(LOC((yyloc)),
                                  static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                                  NULL,
                                  NULL,
                                  NULL);
    }
    break;

  case 523:

/* Line 690 of lalr1.cc  */
#line 3943 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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

  case 524:

/* Line 690 of lalr1.cc  */
#line 3959 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new DirElemConstructor(LOC((yyloc)),
                                  static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                                  NULL,
                                  dynamic_cast<DirAttributeList*>((yysemantic_stack_[(5) - (3)].node)),
                                  NULL);
    }
    break;

  case 525:

/* Line 690 of lalr1.cc  */
#line 3967 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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

  case 526:

/* Line 690 of lalr1.cc  */
#line 3985 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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

  case 527:

/* Line 690 of lalr1.cc  */
#line 4003 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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

  case 528:

/* Line 690 of lalr1.cc  */
#line 4021 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      DirElemContentList *decl = new DirElemContentList( LOC((yyloc)) );
      decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(1) - (1)].expr)) );
      (yyval.node) = decl;
    }
    break;

  case 529:

/* Line 690 of lalr1.cc  */
#line 4027 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      DirElemContentList *decl = dynamic_cast<DirElemContentList*>((yysemantic_stack_[(2) - (1)].node));
      if ( decl )
        decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(2) - (2)].expr)) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 530:

/* Line 690 of lalr1.cc  */
#line 4036 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      DirAttributeList *dal = new DirAttributeList( LOC((yyloc)) );
      dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = dal;
    }
    break;

  case 531:

/* Line 690 of lalr1.cc  */
#line 4042 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      DirAttributeList *dal = dynamic_cast<DirAttributeList*>((yysemantic_stack_[(2) - (1)].node));
      if ( dal )
        dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 532:

/* Line 690 of lalr1.cc  */
#line 4051 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DirAttr(LOC((yyloc)),
                       static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                       dynamic_cast<DirAttributeValue*>((yysemantic_stack_[(6) - (6)].node)));
    }
    break;

  case 535:

/* Line 690 of lalr1.cc  */
#line 4061 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DirAttributeValue(LOC((yyloc)),
                                 dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
    }
    break;

  case 536:

/* Line 690 of lalr1.cc  */
#line 4066 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DirAttributeValue( LOC((yyloc)),
                                  dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
    }
    break;

  case 537:

/* Line 690 of lalr1.cc  */
#line 4072 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new QuoteAttrContentList( LOC((yyloc)) );
    }
    break;

  case 538:

/* Line 690 of lalr1.cc  */
#line 4076 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 539:

/* Line 690 of lalr1.cc  */
#line 4082 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
      qacl->push_back( new QuoteAttrValueContent( LOC((yyloc)), "\"" ) );
      (yyval.node) = qacl;
    }
    break;

  case 540:

/* Line 690 of lalr1.cc  */
#line 4088 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
      qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = qacl;
    }
    break;

  case 541:

/* Line 690 of lalr1.cc  */
#line 4094 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      QuoteAttrContentList* qacl = dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
      if ( qacl )
        qacl->push_back( new QuoteAttrValueContent( LOC((yyloc)), "\"" ) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 542:

/* Line 690 of lalr1.cc  */
#line 4101 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      QuoteAttrContentList *qacl = dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
      if ( qacl )
        qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 543:

/* Line 690 of lalr1.cc  */
#line 4109 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AposAttrContentList( LOC((yyloc)) );
    }
    break;

  case 544:

/* Line 690 of lalr1.cc  */
#line 4113 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 545:

/* Line 690 of lalr1.cc  */
#line 4119 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
      aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
      (yyval.node) = aacl;
    }
    break;

  case 546:

/* Line 690 of lalr1.cc  */
#line 4125 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
      aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = aacl;
    }
    break;

  case 547:

/* Line 690 of lalr1.cc  */
#line 4131 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
      if (aacl)
        aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 548:

/* Line 690 of lalr1.cc  */
#line 4138 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
      if ( aacl )
        aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 549:

/* Line 690 of lalr1.cc  */
#line 4147 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new QuoteAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
    }
    break;

  case 550:

/* Line 690 of lalr1.cc  */
#line 4151 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new QuoteAttrValueContent(LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
    }
    break;

  case 551:

/* Line 690 of lalr1.cc  */
#line 4157 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AposAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
    }
    break;

  case 552:

/* Line 690 of lalr1.cc  */
#line 4161 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AposAttrValueContent(LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
    }
    break;

  case 553:

/* Line 690 of lalr1.cc  */
#line 4167 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new DirElemContent( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr) );
    }
    break;

  case 554:

/* Line 690 of lalr1.cc  */
#line 4171 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new DirElemContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
    }
    break;

  case 555:

/* Line 690 of lalr1.cc  */
#line 4175 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      rchandle<CDataSection> cdata_h = dynamic_cast<CDataSection*>((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = new DirElemContent( LOC((yyloc)), cdata_h );
    }
    break;

  case 556:

/* Line 690 of lalr1.cc  */
#line 4180 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      rchandle<CommonContent> cont_h = dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = new DirElemContent( LOC((yyloc)), cont_h );
    }
    break;

  case 557:

/* Line 690 of lalr1.cc  */
#line 4187 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CommonContent(LOC((yyloc)), ParseConstants::cont_charref, SYMTAB((yysemantic_stack_[(1) - (1)].sval)));
    }
    break;

  case 558:

/* Line 690 of lalr1.cc  */
#line 4191 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CommonContent(LOC((yyloc)), ParseConstants::cont_escape_lbrace);
    }
    break;

  case 559:

/* Line 690 of lalr1.cc  */
#line 4195 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CommonContent(LOC((yyloc)), ParseConstants::cont_escape_rbrace);
    }
    break;

  case 560:

/* Line 690 of lalr1.cc  */
#line 4199 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CommonContent(LOC((yyloc)), new EnclosedExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr)));
    }
    break;

  case 561:

/* Line 690 of lalr1.cc  */
#line 4205 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 562:

/* Line 690 of lalr1.cc  */
#line 4210 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), "" );
    }
    break;

  case 563:

/* Line 690 of lalr1.cc  */
#line 4216 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      ERROR_IF_QNAME_NOT_NCNAME((yysemantic_stack_[(3) - (2)].expr), (yylocation_stack_[(3) - (2)]));
      (yyval.expr) = new DirPIConstructor( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)) );
    }
    break;

  case 564:

/* Line 690 of lalr1.cc  */
#line 4222 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      ERROR_IF_QNAME_NOT_NCNAME((yysemantic_stack_[(3) - (2)].expr), (yylocation_stack_[(3) - (2)]));
      (yyval.expr) = new DirPIConstructor( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
    }
    break;

  case 565:

/* Line 690 of lalr1.cc  */
#line 4229 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CDataSection( LOC((yyloc)),SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
    }
    break;

  case 566:

/* Line 690 of lalr1.cc  */
#line 4235 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 567:

/* Line 690 of lalr1.cc  */
#line 4240 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 568:

/* Line 690 of lalr1.cc  */
#line 4245 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 569:

/* Line 690 of lalr1.cc  */
#line 4250 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 570:

/* Line 690 of lalr1.cc  */
#line 4255 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 571:

/* Line 690 of lalr1.cc  */
#line 4260 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 573:

/* Line 690 of lalr1.cc  */
#line 4268 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompDocConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
    }
    break;

  case 574:

/* Line 690 of lalr1.cc  */
#line 4274 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompElemConstructor(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval))), (yysemantic_stack_[(3) - (2)].expr));
    }
    break;

  case 575:

/* Line 690 of lalr1.cc  */
#line 4278 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompElemConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
    }
    break;

  case 576:

/* Line 690 of lalr1.cc  */
#line 4284 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval))), (yysemantic_stack_[(3) - (2)].expr) );
    }
    break;

  case 577:

/* Line 690 of lalr1.cc  */
#line 4288 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
    }
    break;

  case 578:

/* Line 690 of lalr1.cc  */
#line 4294 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompTextConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
    }
    break;

  case 579:

/* Line 690 of lalr1.cc  */
#line 4300 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompCommentConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
    }
    break;

  case 580:

/* Line 690 of lalr1.cc  */
#line 4306 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompPIConstructor(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval)), (yysemantic_stack_[(3) - (2)].expr));
    }
    break;

  case 581:

/* Line 690 of lalr1.cc  */
#line 4310 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompPIConstructor(LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
    }
    break;

  case 582:

/* Line 690 of lalr1.cc  */
#line 4316 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompNamespaceConstructor(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval)), (yysemantic_stack_[(3) - (2)].expr));
    }
    break;

  case 583:

/* Line 690 of lalr1.cc  */
#line 4320 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompNamespaceConstructor(LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
    }
    break;

  case 584:

/* Line 690 of lalr1.cc  */
#line 4326 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 585:

/* Line 690 of lalr1.cc  */
#line 4332 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL );
        }
    break;

  case 586:

/* Line 690 of lalr1.cc  */
#line 4336 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new SequenceType(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node)));
        }
    break;

  case 587:

/* Line 690 of lalr1.cc  */
#line 4340 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 588:

/* Line 690 of lalr1.cc  */
#line 4344 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            driver.addCommonLanguageWarning((yylocation_stack_[(2) - (1)]), ZED(ZWST0009_JSONIQ_EMPTY_SEQUENCE));
            (yyval.node) = new SequenceType( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 589:

/* Line 690 of lalr1.cc  */
#line 4351 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_optionally
            );
        }
    break;

  case 590:

/* Line 690 of lalr1.cc  */
#line 4357 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_zero_or_more
            );
        }
    break;

  case 591:

/* Line 690 of lalr1.cc  */
#line 4363 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_one_or_more
            );
        }
    break;

  case 592:

/* Line 690 of lalr1.cc  */
#line 4371 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 593:

/* Line 690 of lalr1.cc  */
#line 4375 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 594:

/* Line 690 of lalr1.cc  */
#line 4379 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ItemType( LOC((yyloc)), true );
        }
    break;

  case 595:

/* Line 690 of lalr1.cc  */
#line 4383 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            driver.addCommonLanguageWarning((yylocation_stack_[(1) - (1)]), ZED(ZWST0009_JSONIQ_TYPE_KEYWORDS));
            (yyval.node) = new ItemType( LOC((yyloc)), true );
        }
    break;

  case 596:

/* Line 690 of lalr1.cc  */
#line 4388 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new StructuredItemType(LOC((yyloc)));
        }
    break;

  case 597:

/* Line 690 of lalr1.cc  */
#line 4392 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            driver.addCommonLanguageWarning((yylocation_stack_[(1) - (1)]), ZED(ZWST0009_JSONIQ_TYPE_KEYWORDS));
            (yyval.node) = new StructuredItemType(LOC((yyloc)));
        }
    break;

  case 598:

/* Line 690 of lalr1.cc  */
#line 4397 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 599:

/* Line 690 of lalr1.cc  */
#line 4401 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 600:

/* Line 690 of lalr1.cc  */
#line 4405 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 601:

/* Line 690 of lalr1.cc  */
#line 4411 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
          TypeList* aTypeList = new TypeList(LOC ((yyloc)));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(1) - (1)].node)));
          (yyval.node) = aTypeList;
        }
    break;

  case 602:

/* Line 690 of lalr1.cc  */
#line 4417 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
          TypeList* aTypeList = dynamic_cast<TypeList *>((yysemantic_stack_[(3) - (1)].node));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
          (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 603:

/* Line 690 of lalr1.cc  */
#line 4425 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new GeneralizedAtomicType( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
    }
    break;

  case 604:

/* Line 690 of lalr1.cc  */
#line 4431 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SimpleType( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
    }
    break;

  case 605:

/* Line 690 of lalr1.cc  */
#line 4437 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 606:

/* Line 690 of lalr1.cc  */
#line 4441 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 607:

/* Line 690 of lalr1.cc  */
#line 4445 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 608:

/* Line 690 of lalr1.cc  */
#line 4449 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 609:

/* Line 690 of lalr1.cc  */
#line 4453 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 610:

/* Line 690 of lalr1.cc  */
#line 4457 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 611:

/* Line 690 of lalr1.cc  */
#line 4461 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 612:

/* Line 690 of lalr1.cc  */
#line 4465 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 613:

/* Line 690 of lalr1.cc  */
#line 4469 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 614:

/* Line 690 of lalr1.cc  */
#line 4473 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 615:

/* Line 690 of lalr1.cc  */
#line 4479 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AnyKindTest( LOC((yyloc)) );
    }
    break;

  case 616:

/* Line 690 of lalr1.cc  */
#line 4485 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = NULL;
    }
    break;

  case 617:

/* Line 690 of lalr1.cc  */
#line 4491 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DocumentTest(LOC((yyloc)));
    }
    break;

  case 618:

/* Line 690 of lalr1.cc  */
#line 4495 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DocumentTest(LOC((yyloc)), dynamic_cast<ElementTest*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 619:

/* Line 690 of lalr1.cc  */
#line 4499 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DocumentTest(LOC((yyloc)), dynamic_cast<SchemaElementTest*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 620:

/* Line 690 of lalr1.cc  */
#line 4505 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new NamespaceTest(LOC((yyloc)));
    }
    break;

  case 621:

/* Line 690 of lalr1.cc  */
#line 4510 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new TextTest(LOC((yyloc)));
    }
    break;

  case 622:

/* Line 690 of lalr1.cc  */
#line 4516 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CommentTest(LOC((yyloc)));
    }
    break;

  case 623:

/* Line 690 of lalr1.cc  */
#line 4522 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), "" );
        }
    break;

  case 624:

/* Line 690 of lalr1.cc  */
#line 4526 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            ERROR_IF_QNAME_NOT_NCNAME((yysemantic_stack_[(4) - (3)].expr), (yylocation_stack_[(4) - (3)]));
            (yyval.node) = new PITest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 625:

/* Line 690 of lalr1.cc  */
#line 4531 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 626:

/* Line 690 of lalr1.cc  */
#line 4537 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 627:

/* Line 690 of lalr1.cc  */
#line 4541 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL
            );
        }
    break;

  case 628:

/* Line 690 of lalr1.cc  */
#line 4547 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 629:

/* Line 690 of lalr1.cc  */
#line 4553 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 630:

/* Line 690 of lalr1.cc  */
#line 4557 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 631:

/* Line 690 of lalr1.cc  */
#line 4565 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new SchemaAttributeTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 632:

/* Line 690 of lalr1.cc  */
#line 4571 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ElementTest( LOC((yyloc)), NULL, NULL, true );
        }
    break;

  case 633:

/* Line 690 of lalr1.cc  */
#line 4575 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL, true
            );
        }
    break;

  case 634:

/* Line 690 of lalr1.cc  */
#line 4581 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                false
            );
        }
    break;

  case 635:

/* Line 690 of lalr1.cc  */
#line 4590 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                true
            );
        }
    break;

  case 636:

/* Line 690 of lalr1.cc  */
#line 4599 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, NULL, true
            );
        }
    break;

  case 637:

/* Line 690 of lalr1.cc  */
#line 4605 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), false
            );
        }
    break;

  case 638:

/* Line 690 of lalr1.cc  */
#line 4611 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), true
            );
        }
    break;

  case 639:

/* Line 690 of lalr1.cc  */
#line 4619 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new SchemaElementTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 640:

/* Line 690 of lalr1.cc  */
#line 4625 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 641:

/* Line 690 of lalr1.cc  */
#line 4631 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (1)].expr)), true );
        }
    break;

  case 642:

/* Line 690 of lalr1.cc  */
#line 4637 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new StringLiteral( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 643:

/* Line 690 of lalr1.cc  */
#line 4643 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 644:

/* Line 690 of lalr1.cc  */
#line 4647 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 645:

/* Line 690 of lalr1.cc  */
#line 4653 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AnyFunctionTest(LOC((yyloc)));
    }
    break;

  case 646:

/* Line 690 of lalr1.cc  */
#line 4659 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)), dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (5)].node)));
        }
    break;

  case 647:

/* Line 690 of lalr1.cc  */
#line 4663 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)),
              dynamic_cast<TypeList *>((yysemantic_stack_[(6) - (3)].node)),
              dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (6)].node)));
        }
    break;

  case 648:

/* Line 690 of lalr1.cc  */
#line 4671 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
           (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 649:

/* Line 690 of lalr1.cc  */
#line 4677 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::strict_validation
            );
        }
    break;

  case 650:

/* Line 690 of lalr1.cc  */
#line 4683 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::lax_validation
            );
        }
    break;

  case 651:

/* Line 690 of lalr1.cc  */
#line 4689 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::skip_validation
            );
        }
    break;

  case 652:

/* Line 690 of lalr1.cc  */
#line 4697 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 653:

/* Line 690 of lalr1.cc  */
#line 4701 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 654:

/* Line 690 of lalr1.cc  */
#line 4707 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 655:

/* Line 690 of lalr1.cc  */
#line 4713 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 656:

/* Line 690 of lalr1.cc  */
#line 4717 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 657:

/* Line 690 of lalr1.cc  */
#line 4723 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 658:

/* Line 690 of lalr1.cc  */
#line 4727 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 659:

/* Line 690 of lalr1.cc  */
#line 4733 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                  LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 660:

/* Line 690 of lalr1.cc  */
#line 4739 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)),
                store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 661:

/* Line 690 of lalr1.cc  */
#line 4746 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 662:

/* Line 690 of lalr1.cc  */
#line 4754 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 663:

/* Line 690 of lalr1.cc  */
#line 4759 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 664:

/* Line 690 of lalr1.cc  */
#line 4765 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::NODE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 665:

/* Line 690 of lalr1.cc  */
#line 4771 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::VALUE_OF_NODE, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 666:

/* Line 690 of lalr1.cc  */
#line 4779 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new RenameExpr( LOC ((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 667:

/* Line 690 of lalr1.cc  */
#line 4785 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      CopyVarList *cvl = dynamic_cast<CopyVarList*>((yysemantic_stack_[(7) - (3)].expr));
      (yyval.expr) = new TransformExpr( LOC((yyloc)), cvl, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr) );
    }
    break;

  case 668:

/* Line 690 of lalr1.cc  */
#line 4792 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      CopyVarList* lList = new CopyVarList(LOC((yyloc)));
      lList->push_back (dynamic_cast<VarBinding*> ((yysemantic_stack_[(1) - (1)].expr)));
      (yyval.expr) = lList;
    }
    break;

  case 669:

/* Line 690 of lalr1.cc  */
#line 4798 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      CopyVarList* lList = dynamic_cast<CopyVarList*>((yysemantic_stack_[(4) - (1)].expr));
      VarBinding* lBinding = dynamic_cast<VarBinding*>((yysemantic_stack_[(4) - (4)].expr));
      lList->push_back(lBinding);
      (yyval.expr) = lList;
    }
    break;

  case 670:

/* Line 690 of lalr1.cc  */
#line 4807 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new VarBinding(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 671:

/* Line 690 of lalr1.cc  */
#line 4813 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new TryExpr( LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 672:

/* Line 690 of lalr1.cc  */
#line 4819 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            CatchListExpr *cle = new CatchListExpr( LOC((yyloc)) );
            cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.expr) = cle;
        }
    break;

  case 673:

/* Line 690 of lalr1.cc  */
#line 4825 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
            if ( cle )
                cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
        }
    break;

  case 674:

/* Line 690 of lalr1.cc  */
#line 4834 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)), *(yysemantic_stack_[(3) - (2)].name_test_list), (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 675:

/* Line 690 of lalr1.cc  */
#line 4841 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 676:

/* Line 690 of lalr1.cc  */
#line 4847 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            CatchExpr::NameTestList *ntl = new CatchExpr::NameTestList;
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 677:

/* Line 690 of lalr1.cc  */
#line 4853 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            CatchExpr::NameTestList *ntl =
                static_cast<CatchExpr::NameTestList*>((yysemantic_stack_[(3) - (1)].name_test_list));
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 678:

/* Line 690 of lalr1.cc  */
#line 4862 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTSelection( LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), (yysemantic_stack_[(2) - (2)].pos_filter_list) );
            delete (yysemantic_stack_[(2) - (2)].pos_filter_list);
        }
    break;

  case 679:

/* Line 690 of lalr1.cc  */
#line 4869 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.pos_filter_list) = NULL;
        }
    break;

  case 680:

/* Line 690 of lalr1.cc  */
#line 4873 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.pos_filter_list) = (yysemantic_stack_[(1) - (1)].pos_filter_list);
        }
    break;

  case 681:

/* Line 690 of lalr1.cc  */
#line 4879 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.pos_filter_list) = new FTSelection::pos_filter_list_t;
            (yyval.pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 682:

/* Line 690 of lalr1.cc  */
#line 4884 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yysemantic_stack_[(2) - (1)].pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.pos_filter_list) = (yysemantic_stack_[(2) - (1)].pos_filter_list);
        }
    break;

  case 683:

/* Line 690 of lalr1.cc  */
#line 4891 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 684:

/* Line 690 of lalr1.cc  */
#line 4895 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTOr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 685:

/* Line 690 of lalr1.cc  */
#line 4901 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 686:

/* Line 690 of lalr1.cc  */
#line 4905 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTAnd( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 687:

/* Line 690 of lalr1.cc  */
#line 4911 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 688:

/* Line 690 of lalr1.cc  */
#line 4915 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTMildNot( LOC((yyloc)), (yysemantic_stack_[(4) - (1)].node), (yysemantic_stack_[(4) - (4)].node) );
        }
    break;

  case 689:

/* Line 690 of lalr1.cc  */
#line 4921 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 690:

/* Line 690 of lalr1.cc  */
#line 4925 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTUnaryNot(
                LOC((yyloc)), dynamic_cast<FTPrimaryWithOptions*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 691:

/* Line 690 of lalr1.cc  */
#line 4933 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTPrimaryWithOptions(
                LOC((yyloc)),
                dynamic_cast<FTPrimary*>((yysemantic_stack_[(3) - (1)].node)),
                dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<FTWeight*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 692:

/* Line 690 of lalr1.cc  */
#line 4943 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 693:

/* Line 690 of lalr1.cc  */
#line 4947 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 694:

/* Line 690 of lalr1.cc  */
#line 4952 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 695:

/* Line 690 of lalr1.cc  */
#line 4956 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 696:

/* Line 690 of lalr1.cc  */
#line 4962 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTWeight( LOC((yyloc)), dynamic_cast<exprnode*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 697:

/* Line 690 of lalr1.cc  */
#line 4968 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTWordsTimes(
                LOC((yyloc)),
                dynamic_cast<FTWords*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<FTTimes*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 698:

/* Line 690 of lalr1.cc  */
#line 4976 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 699:

/* Line 690 of lalr1.cc  */
#line 4980 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 700:

/* Line 690 of lalr1.cc  */
#line 4985 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 701:

/* Line 690 of lalr1.cc  */
#line 4989 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 702:

/* Line 690 of lalr1.cc  */
#line 4995 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTExtensionSelection(
                LOC((yyloc)),
                dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)),
                dynamic_cast<FTSelection*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 703:

/* Line 690 of lalr1.cc  */
#line 5004 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 704:

/* Line 690 of lalr1.cc  */
#line 5008 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 705:

/* Line 690 of lalr1.cc  */
#line 5014 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTWords(
                LOC((yyloc)),
                dynamic_cast<FTWordsValue*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<FTAnyallOption*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 706:

/* Line 690 of lalr1.cc  */
#line 5024 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), static_cast<StringLiteral*>((yysemantic_stack_[(1) - (1)].expr)), NULL
            );
        }
    break;

  case 707:

/* Line 690 of lalr1.cc  */
#line 5030 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), NULL, dynamic_cast<exprnode*>((yysemantic_stack_[(3) - (2)].expr))
            );
        }
    break;

  case 708:

/* Line 690 of lalr1.cc  */
#line 5037 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::any );
        }
    break;

  case 709:

/* Line 690 of lalr1.cc  */
#line 5041 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 710:

/* Line 690 of lalr1.cc  */
#line 5047 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 711:

/* Line 690 of lalr1.cc  */
#line 5051 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 712:

/* Line 690 of lalr1.cc  */
#line 5055 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::phrase );
        }
    break;

  case 713:

/* Line 690 of lalr1.cc  */
#line 5060 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any;
        }
    break;

  case 714:

/* Line 690 of lalr1.cc  */
#line 5064 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any_word;
        }
    break;

  case 715:

/* Line 690 of lalr1.cc  */
#line 5069 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all;
        }
    break;

  case 716:

/* Line 690 of lalr1.cc  */
#line 5073 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all_words;
        }
    break;

  case 717:

/* Line 690 of lalr1.cc  */
#line 5079 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 718:

/* Line 690 of lalr1.cc  */
#line 5083 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 719:

/* Line 690 of lalr1.cc  */
#line 5087 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 720:

/* Line 690 of lalr1.cc  */
#line 5091 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 721:

/* Line 690 of lalr1.cc  */
#line 5095 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 722:

/* Line 690 of lalr1.cc  */
#line 5101 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTOrder( LOC((yyloc)) );
        }
    break;

  case 723:

/* Line 690 of lalr1.cc  */
#line 5107 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTWindow(
                LOC((yyloc)),
                static_cast<AdditiveExpr*>((yysemantic_stack_[(3) - (2)].expr)),
                static_cast<FTUnit*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 724:

/* Line 690 of lalr1.cc  */
#line 5117 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTDistance(
                LOC((yyloc)),
                dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<FTUnit*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 725:

/* Line 690 of lalr1.cc  */
#line 5127 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::words );
        }
    break;

  case 726:

/* Line 690 of lalr1.cc  */
#line 5131 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::sentences );
        }
    break;

  case 727:

/* Line 690 of lalr1.cc  */
#line 5135 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::paragraphs );
        }
    break;

  case 728:

/* Line 690 of lalr1.cc  */
#line 5141 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            FTMatchOptions *mo = new FTMatchOptions( LOC((yyloc)) );
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = mo;
        }
    break;

  case 729:

/* Line 690 of lalr1.cc  */
#line 5147 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            FTMatchOptions *mo = dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (1)].node));
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 730:

/* Line 690 of lalr1.cc  */
#line 5155 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 731:

/* Line 690 of lalr1.cc  */
#line 5159 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 732:

/* Line 690 of lalr1.cc  */
#line 5163 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 733:

/* Line 690 of lalr1.cc  */
#line 5167 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 734:

/* Line 690 of lalr1.cc  */
#line 5171 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 735:

/* Line 690 of lalr1.cc  */
#line 5175 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 736:

/* Line 690 of lalr1.cc  */
#line 5179 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 737:

/* Line 690 of lalr1.cc  */
#line 5183 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 738:

/* Line 690 of lalr1.cc  */
#line 5189 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::sensitive );
        }
    break;

  case 739:

/* Line 690 of lalr1.cc  */
#line 5193 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::insensitive );
        }
    break;

  case 740:

/* Line 690 of lalr1.cc  */
#line 5197 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::lower );
        }
    break;

  case 741:

/* Line 690 of lalr1.cc  */
#line 5201 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::upper );
        }
    break;

  case 742:

/* Line 690 of lalr1.cc  */
#line 5207 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::sensitive
            );
        }
    break;

  case 743:

/* Line 690 of lalr1.cc  */
#line 5213 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::insensitive
            );
        }
    break;

  case 744:

/* Line 690 of lalr1.cc  */
#line 5221 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTExtensionOption(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval))
            );
        }
    break;

  case 745:

/* Line 690 of lalr1.cc  */
#line 5229 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::stemming );
        }
    break;

  case 746:

/* Line 690 of lalr1.cc  */
#line 5233 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::no_stemming );
        }
    break;

  case 747:

/* Line 690 of lalr1.cc  */
#line 5239 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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

  case 748:

/* Line 690 of lalr1.cc  */
#line 5249 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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

  case 749:

/* Line 690 of lalr1.cc  */
#line 5260 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTThesaurusOption( LOC((yyloc)), NULL, false, true );
        }
    break;

  case 750:

/* Line 690 of lalr1.cc  */
#line 5266 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 751:

/* Line 690 of lalr1.cc  */
#line 5270 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 752:

/* Line 690 of lalr1.cc  */
#line 5275 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.thesaurus_id_list) = NULL;
        }
    break;

  case 753:

/* Line 690 of lalr1.cc  */
#line 5279 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(2) - (2)].thesaurus_id_list);
        }
    break;

  case 754:

/* Line 690 of lalr1.cc  */
#line 5285 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.thesaurus_id_list) = new FTThesaurusOption::thesaurus_id_list_t;
            (yyval.thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 755:

/* Line 690 of lalr1.cc  */
#line 5290 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yysemantic_stack_[(3) - (1)].thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(3) - (1)].thesaurus_id_list);
        }
    break;

  case 756:

/* Line 690 of lalr1.cc  */
#line 5297 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTThesaurusID(
                LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (2)].sval)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), dynamic_cast<FTRange*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 757:

/* Line 690 of lalr1.cc  */
#line 5304 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.sval) = 0;
        }
    break;

  case 758:

/* Line 690 of lalr1.cc  */
#line 5308 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.sval) = (yysemantic_stack_[(2) - (2)].sval);
        }
    break;

  case 759:

/* Line 690 of lalr1.cc  */
#line 5314 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 760:

/* Line 690 of lalr1.cc  */
#line 5318 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 761:

/* Line 690 of lalr1.cc  */
#line 5324 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(4) - (3)].node)), (yysemantic_stack_[(4) - (4)].incl_excl_list),
                ft_stop_words_mode::with
            );
            delete (yysemantic_stack_[(4) - (4)].incl_excl_list);
        }
    break;

  case 762:

/* Line 690 of lalr1.cc  */
#line 5333 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, (yysemantic_stack_[(4) - (4)].incl_excl_list), ft_stop_words_mode::with_default
            );
            delete (yysemantic_stack_[(4) - (4)].incl_excl_list);
        }
    break;

  case 763:

/* Line 690 of lalr1.cc  */
#line 5340 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, NULL, ft_stop_words_mode::without
            );
        }
    break;

  case 764:

/* Line 690 of lalr1.cc  */
#line 5348 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), NULL );
        }
    break;

  case 765:

/* Line 690 of lalr1.cc  */
#line 5352 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), "", (yysemantic_stack_[(3) - (2)].strlist) );
        }
    break;

  case 766:

/* Line 690 of lalr1.cc  */
#line 5358 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            string_list_t *sl = new string_list_t;
            sl->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
            (yyval.strlist) = sl;
        }
    break;

  case 767:

/* Line 690 of lalr1.cc  */
#line 5364 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            if ( (yysemantic_stack_[(3) - (1)].strlist) )
                (yysemantic_stack_[(3) - (1)].strlist)->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
            (yyval.strlist) = (yysemantic_stack_[(3) - (1)].strlist);
        }
    break;

  case 768:

/* Line 690 of lalr1.cc  */
#line 5371 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.incl_excl_list) = NULL;
        }
    break;

  case 769:

/* Line 690 of lalr1.cc  */
#line 5375 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.incl_excl_list) = (yysemantic_stack_[(1) - (1)].incl_excl_list);
        }
    break;

  case 770:

/* Line 690 of lalr1.cc  */
#line 5381 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.incl_excl_list) = new FTStopWordOption::incl_excl_list_t;
            (yyval.incl_excl_list)->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 771:

/* Line 690 of lalr1.cc  */
#line 5386 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            FTStopWordOption::incl_excl_list_t *iel = (yysemantic_stack_[(2) - (1)].incl_excl_list);
            if ( !iel )
                iel = new FTStopWordOption::incl_excl_list_t;
            iel->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.incl_excl_list) = iel;
        }
    break;

  case 772:

/* Line 690 of lalr1.cc  */
#line 5396 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStopWordsInclExcl(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(2) - (2)].node)),
                ft_stop_words_unex::union_
            );
        }
    break;

  case 773:

/* Line 690 of lalr1.cc  */
#line 5404 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStopWordsInclExcl(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(2) - (2)].node)),
                ft_stop_words_unex::except
            );
        }
    break;

  case 774:

/* Line 690 of lalr1.cc  */
#line 5414 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTLanguageOption( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 775:

/* Line 690 of lalr1.cc  */
#line 5420 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::with );
        }
    break;

  case 776:

/* Line 690 of lalr1.cc  */
#line 5424 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::without );
        }
    break;

  case 777:

/* Line 690 of lalr1.cc  */
#line 5430 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_start );
        }
    break;

  case 778:

/* Line 690 of lalr1.cc  */
#line 5434 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_end );
        }
    break;

  case 779:

/* Line 690 of lalr1.cc  */
#line 5438 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::entire );
        }
    break;

  case 780:

/* Line 690 of lalr1.cc  */
#line 5444 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTTimes( LOC((yyloc)), dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)) );
        }
    break;

  case 781:

/* Line 690 of lalr1.cc  */
#line 5450 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::exactly, (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 782:

/* Line 690 of lalr1.cc  */
#line 5454 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_least, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 783:

/* Line 690 of lalr1.cc  */
#line 5458 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_most, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 784:

/* Line 690 of lalr1.cc  */
#line 5462 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::from_to, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr) );
        }
    break;

  case 785:

/* Line 690 of lalr1.cc  */
#line 5468 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTScope(
                LOC((yyloc)),
                ft_scope::same,
                dynamic_cast<FTBigUnit*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 786:

/* Line 690 of lalr1.cc  */
#line 5476 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTScope(
                LOC((yyloc)),
                ft_scope::different,
                dynamic_cast<FTBigUnit*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 787:

/* Line 690 of lalr1.cc  */
#line 5486 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::sentence );
        }
    break;

  case 788:

/* Line 690 of lalr1.cc  */
#line 5490 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::paragraph );
        }
    break;

  case 789:

/* Line 690 of lalr1.cc  */
#line 5496 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTIgnoreOption( LOC((yyloc)), static_cast<UnionExpr*>((yysemantic_stack_[(3) - (3)].expr)) );
        }
    break;

  case 790:

/* Line 690 of lalr1.cc  */
#line 5502 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONArrayConstructor( LOC((yyloc)), NULL );
        }
    break;

  case 791:

/* Line 690 of lalr1.cc  */
#line 5506 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONArrayConstructor( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 792:

/* Line 690 of lalr1.cc  */
#line 5512 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), NULL, false);
        }
    break;

  case 793:

/* Line 690 of lalr1.cc  */
#line 5516 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), false);
        }
    break;

  case 794:

/* Line 690 of lalr1.cc  */
#line 5522 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), NULL, true);
        }
    break;

  case 795:

/* Line 690 of lalr1.cc  */
#line 5526 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), true);
        }
    break;

  case 796:

/* Line 690 of lalr1.cc  */
#line 5532 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONDirectObjectConstructor(LOC((yyloc)),
                                               dynamic_cast<JSONPairList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 797:

/* Line 690 of lalr1.cc  */
#line 5539 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
          ERROR_IF_QNAME_NOT_NCNAME((yysemantic_stack_[(3) - (1)].expr), (yylocation_stack_[(3) - (1)]));
          StringLiteral* sl = new StringLiteral( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)) );
          JSONPairList* jpl = new JSONPairList(LOC((yyloc)));
          jpl->push_back(new JSONPairConstructor(LOC((yyloc)), sl, (yysemantic_stack_[(3) - (3)].expr)));
          (yyval.node) = jpl;
        }
    break;

  case 798:

/* Line 690 of lalr1.cc  */
#line 5548 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
          JSONPairList* jpl = new JSONPairList(LOC((yyloc)));
          jpl->push_back(new JSONPairConstructor(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)));
          (yyval.node) = jpl;
        }
    break;

  case 799:

/* Line 690 of lalr1.cc  */
#line 5554 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
          JSONPairList* jpl = dynamic_cast<JSONPairList*>((yysemantic_stack_[(5) - (1)].node));
          assert(jpl);
          jpl->push_back(new JSONPairConstructor(LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)));
          (yyval.node) = jpl;
        }
    break;

  case 800:

/* Line 690 of lalr1.cc  */
#line 5561 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
          ERROR_IF_QNAME_NOT_NCNAME((yysemantic_stack_[(5) - (3)].expr), (yylocation_stack_[(5) - (3)]));
          JSONPairList* jpl = dynamic_cast<JSONPairList*>((yysemantic_stack_[(5) - (1)].node));
          assert(jpl);
          StringLiteral* sl = new StringLiteral( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (3)].expr)) );
          jpl->push_back(new JSONPairConstructor(LOC((yyloc)), sl, (yysemantic_stack_[(5) - (5)].expr)));
          (yyval.node) = jpl;
        }
    break;

  case 801:

/* Line 690 of lalr1.cc  */
#line 5572 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONObjectInsertExpr(LOC((yyloc)),
                                        (yysemantic_stack_[(5) - (3)].expr),
                                        (yysemantic_stack_[(5) - (5)].expr));
        }
    break;

  case 802:

/* Line 690 of lalr1.cc  */
#line 5578 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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

  case 803:

/* Line 690 of lalr1.cc  */
#line 5588 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONArrayInsertExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (5)].expr), (yysemantic_stack_[(8) - (8)].expr));
        }
    break;

  case 804:

/* Line 690 of lalr1.cc  */
#line 5592 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
          driver.addCommonLanguageWarning((yylocation_stack_[(4) - (2)]), ZED(ZWST0009_JSON_KEYWORD_OPTIONAL));
          (yyval.expr) = new JSONObjectInsertExpr(LOC((yyloc)),
                                        (yysemantic_stack_[(4) - (2)].expr),
                                        (yysemantic_stack_[(4) - (4)].expr));
        }
    break;

  case 805:

/* Line 690 of lalr1.cc  */
#line 5599 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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

  case 806:

/* Line 690 of lalr1.cc  */
#line 5610 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
          driver.addCommonLanguageWarning((yylocation_stack_[(7) - (2)]), ZED(ZWST0009_JSON_KEYWORD_OPTIONAL));
          (yyval.expr) = new JSONArrayInsertExpr(LOC((yyloc)), (yysemantic_stack_[(7) - (2)].expr), (yysemantic_stack_[(7) - (4)].expr), (yysemantic_stack_[(7) - (7)].expr));
        }
    break;

  case 807:

/* Line 690 of lalr1.cc  */
#line 5617 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONArrayAppendExpr(LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
        }
    break;

  case 808:

/* Line 690 of lalr1.cc  */
#line 5621 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
          driver.addCommonLanguageWarning((yylocation_stack_[(4) - (2)]), ZED(ZWST0009_JSON_KEYWORD_OPTIONAL));
          (yyval.expr) = new JSONArrayAppendExpr(LOC((yyloc)), (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr));
        }
    break;

  case 809:

/* Line 690 of lalr1.cc  */
#line 5628 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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

  case 810:

/* Line 690 of lalr1.cc  */
#line 5647 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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

  case 811:

/* Line 690 of lalr1.cc  */
#line 5669 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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

  case 812:

/* Line 690 of lalr1.cc  */
#line 5691 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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

  case 813:

/* Line 690 of lalr1.cc  */
#line 5716 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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

  case 814:

/* Line 690 of lalr1.cc  */
#line 5738 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
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

  case 815:

/* Line 690 of lalr1.cc  */
#line 5763 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 816:

/* Line 690 of lalr1.cc  */
#line 5767 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 817:

/* Line 690 of lalr1.cc  */
#line 5771 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 818:

/* Line 690 of lalr1.cc  */
#line 5777 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonItem);
        }
    break;

  case 819:

/* Line 690 of lalr1.cc  */
#line 5781 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
          driver.addCommonLanguageWarning((yylocation_stack_[(1) - (1)]), ZED(ZWST0009_JSONIQ_TYPE_KEYWORDS));
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonItem);
        }
    break;

  case 820:

/* Line 690 of lalr1.cc  */
#line 5788 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonObject);
        }
    break;

  case 821:

/* Line 690 of lalr1.cc  */
#line 5792 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
          driver.addCommonLanguageWarning((yylocation_stack_[(1) - (1)]), ZED(ZWST0009_JSONIQ_TYPE_KEYWORDS));
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonObject);
        }
    break;

  case 822:

/* Line 690 of lalr1.cc  */
#line 5799 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonArray);
        }
    break;

  case 823:

/* Line 690 of lalr1.cc  */
#line 5803 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    {
          driver.addCommonLanguageWarning((yylocation_stack_[(1) - (1)]), ZED(ZWST0009_JSONIQ_TYPE_KEYWORDS));
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonArray);
        }
    break;

  case 826:

/* Line 690 of lalr1.cc  */
#line 5813 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))); }
    break;

  case 827:

/* Line 690 of lalr1.cc  */
#line 5814 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("attribute"))); }
    break;

  case 828:

/* Line 690 of lalr1.cc  */
#line 5815 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("comment"))); }
    break;

  case 829:

/* Line 690 of lalr1.cc  */
#line 5816 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("document-node"))); }
    break;

  case 830:

/* Line 690 of lalr1.cc  */
#line 5817 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("namespace-node"))); }
    break;

  case 831:

/* Line 690 of lalr1.cc  */
#line 5818 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("element"))); }
    break;

  case 832:

/* Line 690 of lalr1.cc  */
#line 5819 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("if"))); }
    break;

  case 833:

/* Line 690 of lalr1.cc  */
#line 5820 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("node"))); }
    break;

  case 834:

/* Line 690 of lalr1.cc  */
#line 5821 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("processing-instruction"))); }
    break;

  case 835:

/* Line 690 of lalr1.cc  */
#line 5822 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema-attribute"))); }
    break;

  case 836:

/* Line 690 of lalr1.cc  */
#line 5823 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema-element"))); }
    break;

  case 837:

/* Line 690 of lalr1.cc  */
#line 5824 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("text"))); }
    break;

  case 838:

/* Line 690 of lalr1.cc  */
#line 5825 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("typeswitch"))); }
    break;

  case 839:

/* Line 690 of lalr1.cc  */
#line 5826 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("switch"))); }
    break;

  case 840:

/* Line 690 of lalr1.cc  */
#line 5827 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("empty-sequence"))); }
    break;

  case 841:

/* Line 690 of lalr1.cc  */
#line 5828 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("while"))); }
    break;

  case 843:

/* Line 690 of lalr1.cc  */
#line 5832 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))); }
    break;

  case 844:

/* Line 690 of lalr1.cc  */
#line 5833 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("xquery"))); }
    break;

  case 845:

/* Line 690 of lalr1.cc  */
#line 5834 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("empty"))); }
    break;

  case 846:

/* Line 690 of lalr1.cc  */
#line 5835 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("boundary-space"))); }
    break;

  case 847:

/* Line 690 of lalr1.cc  */
#line 5836 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ft-option"))); }
    break;

  case 848:

/* Line 690 of lalr1.cc  */
#line 5837 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("base-uri"))); }
    break;

  case 849:

/* Line 690 of lalr1.cc  */
#line 5838 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lax"))); }
    break;

  case 850:

/* Line 690 of lalr1.cc  */
#line 5839 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("strict"))); }
    break;

  case 851:

/* Line 690 of lalr1.cc  */
#line 5840 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("idiv"))); }
    break;

  case 852:

/* Line 690 of lalr1.cc  */
#line 5841 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("document"))); }
    break;

  case 853:

/* Line 690 of lalr1.cc  */
#line 5842 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ftnot"))); }
    break;

  case 854:

/* Line 690 of lalr1.cc  */
#line 5843 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("not"))); }
    break;

  case 855:

/* Line 690 of lalr1.cc  */
#line 5844 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sensitive"))); }
    break;

  case 856:

/* Line 690 of lalr1.cc  */
#line 5845 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("insensitive"))); }
    break;

  case 857:

/* Line 690 of lalr1.cc  */
#line 5846 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("diacritics"))); }
    break;

  case 858:

/* Line 690 of lalr1.cc  */
#line 5847 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("without"))); }
    break;

  case 859:

/* Line 690 of lalr1.cc  */
#line 5848 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stemming"))); }
    break;

  case 860:

/* Line 690 of lalr1.cc  */
#line 5849 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("thesaurus"))); }
    break;

  case 861:

/* Line 690 of lalr1.cc  */
#line 5850 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stop"))); }
    break;

  case 862:

/* Line 690 of lalr1.cc  */
#line 5851 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("wildcards"))); }
    break;

  case 863:

/* Line 690 of lalr1.cc  */
#line 5852 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("entire"))); }
    break;

  case 864:

/* Line 690 of lalr1.cc  */
#line 5853 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("content"))); }
    break;

  case 865:

/* Line 690 of lalr1.cc  */
#line 5854 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("word"))); }
    break;

  case 866:

/* Line 690 of lalr1.cc  */
#line 5855 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("start"))); }
    break;

  case 867:

/* Line 690 of lalr1.cc  */
#line 5856 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("end"))); }
    break;

  case 868:

/* Line 690 of lalr1.cc  */
#line 5857 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("most"))); }
    break;

  case 869:

/* Line 690 of lalr1.cc  */
#line 5858 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("skip"))); }
    break;

  case 870:

/* Line 690 of lalr1.cc  */
#line 5859 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("copy"))); }
    break;

  case 871:

/* Line 690 of lalr1.cc  */
#line 5860 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("general"))); }
    break;

  case 872:

/* Line 690 of lalr1.cc  */
#line 5861 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("value"))); }
    break;

  case 873:

/* Line 690 of lalr1.cc  */
#line 5862 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("eq"))); }
    break;

  case 874:

/* Line 690 of lalr1.cc  */
#line 5863 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ne"))); }
    break;

  case 875:

/* Line 690 of lalr1.cc  */
#line 5864 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lt"))); }
    break;

  case 876:

/* Line 690 of lalr1.cc  */
#line 5865 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("le"))); }
    break;

  case 877:

/* Line 690 of lalr1.cc  */
#line 5866 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("gt"))); }
    break;

  case 878:

/* Line 690 of lalr1.cc  */
#line 5867 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ge"))); }
    break;

  case 879:

/* Line 690 of lalr1.cc  */
#line 5868 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("at"))); }
    break;

  case 880:

/* Line 690 of lalr1.cc  */
#line 5869 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("context"))); }
    break;

  case 881:

/* Line 690 of lalr1.cc  */
#line 5870 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("variable"))); }
    break;

  case 882:

/* Line 690 of lalr1.cc  */
#line 5871 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("return"))); }
    break;

  case 883:

/* Line 690 of lalr1.cc  */
#line 5872 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("for"))); }
    break;

  case 884:

/* Line 690 of lalr1.cc  */
#line 5873 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("from"))); }
    break;

  case 885:

/* Line 690 of lalr1.cc  */
#line 5874 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("allowing"))); }
    break;

  case 886:

/* Line 690 of lalr1.cc  */
#line 5875 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sliding"))); }
    break;

  case 887:

/* Line 690 of lalr1.cc  */
#line 5876 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("tumbling"))); }
    break;

  case 888:

/* Line 690 of lalr1.cc  */
#line 5877 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("previous"))); }
    break;

  case 889:

/* Line 690 of lalr1.cc  */
#line 5878 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("next"))); }
    break;

  case 890:

/* Line 690 of lalr1.cc  */
#line 5879 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("only"))); }
    break;

  case 891:

/* Line 690 of lalr1.cc  */
#line 5880 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("when"))); }
    break;

  case 892:

/* Line 690 of lalr1.cc  */
#line 5881 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("count"))); }
    break;

  case 893:

/* Line 690 of lalr1.cc  */
#line 5882 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("in"))); }
    break;

  case 894:

/* Line 690 of lalr1.cc  */
#line 5883 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("let"))); }
    break;

  case 895:

/* Line 690 of lalr1.cc  */
#line 5884 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("where"))); }
    break;

  case 896:

/* Line 690 of lalr1.cc  */
#line 5885 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("by"))); }
    break;

  case 897:

/* Line 690 of lalr1.cc  */
#line 5886 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("group"))); }
    break;

  case 898:

/* Line 690 of lalr1.cc  */
#line 5887 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("order"))); }
    break;

  case 899:

/* Line 690 of lalr1.cc  */
#line 5888 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stable"))); }
    break;

  case 900:

/* Line 690 of lalr1.cc  */
#line 5889 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ascending"))); }
    break;

  case 901:

/* Line 690 of lalr1.cc  */
#line 5890 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descending"))); }
    break;

  case 902:

/* Line 690 of lalr1.cc  */
#line 5891 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("greatest"))); }
    break;

  case 903:

/* Line 690 of lalr1.cc  */
#line 5892 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("least"))); }
    break;

  case 904:

/* Line 690 of lalr1.cc  */
#line 5893 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("collation"))); }
    break;

  case 905:

/* Line 690 of lalr1.cc  */
#line 5894 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("some"))); }
    break;

  case 906:

/* Line 690 of lalr1.cc  */
#line 5895 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("every"))); }
    break;

  case 907:

/* Line 690 of lalr1.cc  */
#line 5896 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("satisfies"))); }
    break;

  case 908:

/* Line 690 of lalr1.cc  */
#line 5897 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("case"))); }
    break;

  case 909:

/* Line 690 of lalr1.cc  */
#line 5898 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("as"))); }
    break;

  case 910:

/* Line 690 of lalr1.cc  */
#line 5899 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("then"))); }
    break;

  case 911:

/* Line 690 of lalr1.cc  */
#line 5900 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("else"))); }
    break;

  case 912:

/* Line 690 of lalr1.cc  */
#line 5901 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("or"))); }
    break;

  case 913:

/* Line 690 of lalr1.cc  */
#line 5902 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("and"))); }
    break;

  case 914:

/* Line 690 of lalr1.cc  */
#line 5903 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("instance"))); }
    break;

  case 915:

/* Line 690 of lalr1.cc  */
#line 5904 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("of"))); }
    break;

  case 916:

/* Line 690 of lalr1.cc  */
#line 5905 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("castable"))); }
    break;

  case 917:

/* Line 690 of lalr1.cc  */
#line 5906 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("to"))); }
    break;

  case 918:

/* Line 690 of lalr1.cc  */
#line 5907 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("div"))); }
    break;

  case 919:

/* Line 690 of lalr1.cc  */
#line 5908 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("mod"))); }
    break;

  case 920:

/* Line 690 of lalr1.cc  */
#line 5909 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("union"))); }
    break;

  case 921:

/* Line 690 of lalr1.cc  */
#line 5910 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("intersect"))); }
    break;

  case 922:

/* Line 690 of lalr1.cc  */
#line 5911 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("except"))); }
    break;

  case 923:

/* Line 690 of lalr1.cc  */
#line 5912 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("validate"))); }
    break;

  case 924:

/* Line 690 of lalr1.cc  */
#line 5913 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("type"))); }
    break;

  case 925:

/* Line 690 of lalr1.cc  */
#line 5914 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("cast"))); }
    break;

  case 926:

/* Line 690 of lalr1.cc  */
#line 5915 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("treat"))); }
    break;

  case 927:

/* Line 690 of lalr1.cc  */
#line 5916 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("is"))); }
    break;

  case 928:

/* Line 690 of lalr1.cc  */
#line 5917 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preserve"))); }
    break;

  case 929:

/* Line 690 of lalr1.cc  */
#line 5918 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("strip"))); }
    break;

  case 930:

/* Line 690 of lalr1.cc  */
#line 5919 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("namespace"))); }
    break;

  case 931:

/* Line 690 of lalr1.cc  */
#line 5920 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("external"))); }
    break;

  case 932:

/* Line 690 of lalr1.cc  */
#line 5921 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("encoding"))); }
    break;

  case 933:

/* Line 690 of lalr1.cc  */
#line 5922 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("no-preserve"))); }
    break;

  case 934:

/* Line 690 of lalr1.cc  */
#line 5923 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("inherit"))); }
    break;

  case 935:

/* Line 690 of lalr1.cc  */
#line 5924 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("no-inherit"))); }
    break;

  case 936:

/* Line 690 of lalr1.cc  */
#line 5925 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("declare"))); }
    break;

  case 937:

/* Line 690 of lalr1.cc  */
#line 5926 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("construction"))); }
    break;

  case 938:

/* Line 690 of lalr1.cc  */
#line 5927 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ordering"))); }
    break;

  case 939:

/* Line 690 of lalr1.cc  */
#line 5928 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("default"))); }
    break;

  case 940:

/* Line 690 of lalr1.cc  */
#line 5929 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("copy-namespaces"))); }
    break;

  case 941:

/* Line 690 of lalr1.cc  */
#line 5930 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("option"))); }
    break;

  case 942:

/* Line 690 of lalr1.cc  */
#line 5931 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("version"))); }
    break;

  case 943:

/* Line 690 of lalr1.cc  */
#line 5932 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("import"))); }
    break;

  case 944:

/* Line 690 of lalr1.cc  */
#line 5933 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema"))); }
    break;

  case 945:

/* Line 690 of lalr1.cc  */
#line 5934 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("module"))); }
    break;

  case 946:

/* Line 690 of lalr1.cc  */
#line 5935 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("function"))); }
    break;

  case 947:

/* Line 690 of lalr1.cc  */
#line 5936 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("score"))); }
    break;

  case 948:

/* Line 690 of lalr1.cc  */
#line 5937 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("contains"))); }
    break;

  case 949:

/* Line 690 of lalr1.cc  */
#line 5938 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("weight"))); }
    break;

  case 950:

/* Line 690 of lalr1.cc  */
#line 5939 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("window"))); }
    break;

  case 951:

/* Line 690 of lalr1.cc  */
#line 5940 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("distance"))); }
    break;

  case 952:

/* Line 690 of lalr1.cc  */
#line 5941 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("occurs"))); }
    break;

  case 953:

/* Line 690 of lalr1.cc  */
#line 5942 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("times"))); }
    break;

  case 954:

/* Line 690 of lalr1.cc  */
#line 5943 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("same"))); }
    break;

  case 955:

/* Line 690 of lalr1.cc  */
#line 5944 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("different"))); }
    break;

  case 956:

/* Line 690 of lalr1.cc  */
#line 5945 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lowercase"))); }
    break;

  case 957:

/* Line 690 of lalr1.cc  */
#line 5946 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("uppercase"))); }
    break;

  case 958:

/* Line 690 of lalr1.cc  */
#line 5947 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("relationship"))); }
    break;

  case 959:

/* Line 690 of lalr1.cc  */
#line 5948 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("levels"))); }
    break;

  case 960:

/* Line 690 of lalr1.cc  */
#line 5949 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("language"))); }
    break;

  case 961:

/* Line 690 of lalr1.cc  */
#line 5950 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("any"))); }
    break;

  case 962:

/* Line 690 of lalr1.cc  */
#line 5951 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("all"))); }
    break;

  case 963:

/* Line 690 of lalr1.cc  */
#line 5952 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("exactly"))); }
    break;

  case 964:

/* Line 690 of lalr1.cc  */
#line 5953 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("words"))); }
    break;

  case 965:

/* Line 690 of lalr1.cc  */
#line 5954 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sentences"))); }
    break;

  case 966:

/* Line 690 of lalr1.cc  */
#line 5955 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sentence"))); }
    break;

  case 967:

/* Line 690 of lalr1.cc  */
#line 5956 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("phrase"))); }
    break;

  case 968:

/* Line 690 of lalr1.cc  */
#line 5957 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("paragraph"))); }
    break;

  case 969:

/* Line 690 of lalr1.cc  */
#line 5958 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("paragraphs"))); }
    break;

  case 970:

/* Line 690 of lalr1.cc  */
#line 5959 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("modify"))); }
    break;

  case 971:

/* Line 690 of lalr1.cc  */
#line 5960 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("first"))); }
    break;

  case 972:

/* Line 690 of lalr1.cc  */
#line 5961 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("before"))); }
    break;

  case 973:

/* Line 690 of lalr1.cc  */
#line 5962 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("after"))); }
    break;

  case 974:

/* Line 690 of lalr1.cc  */
#line 5963 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("revalidation"))); }
    break;

  case 975:

/* Line 690 of lalr1.cc  */
#line 5964 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("with"))); }
    break;

  case 976:

/* Line 690 of lalr1.cc  */
#line 5965 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("nodes"))); }
    break;

  case 977:

/* Line 690 of lalr1.cc  */
#line 5966 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("last"))); }
    break;

  case 978:

/* Line 690 of lalr1.cc  */
#line 5967 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("into"))); }
    break;

  case 979:

/* Line 690 of lalr1.cc  */
#line 5968 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("simple"))); }
    break;

  case 980:

/* Line 690 of lalr1.cc  */
#line 5969 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sequential"))); }
    break;

  case 981:

/* Line 690 of lalr1.cc  */
#line 5970 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("updating"))); }
    break;

  case 982:

/* Line 690 of lalr1.cc  */
#line 5971 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ordered"))); }
    break;

  case 983:

/* Line 690 of lalr1.cc  */
#line 5972 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("unordered"))); }
    break;

  case 984:

/* Line 690 of lalr1.cc  */
#line 5973 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("returning"))); }
    break;

  case 985:

/* Line 690 of lalr1.cc  */
#line 5974 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("exit"))); }
    break;

  case 986:

/* Line 690 of lalr1.cc  */
#line 5975 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("loop"))); }
    break;

  case 987:

/* Line 690 of lalr1.cc  */
#line 5976 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("break"))); }
    break;

  case 988:

/* Line 690 of lalr1.cc  */
#line 5977 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("continue"))); }
    break;

  case 989:

/* Line 690 of lalr1.cc  */
#line 5978 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("try"))); }
    break;

  case 990:

/* Line 690 of lalr1.cc  */
#line 5979 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("catch"))); }
    break;

  case 991:

/* Line 690 of lalr1.cc  */
#line 5980 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("using"))); }
    break;

  case 992:

/* Line 690 of lalr1.cc  */
#line 5981 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("set"))); }
    break;

  case 993:

/* Line 690 of lalr1.cc  */
#line 5982 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("index"))); }
    break;

  case 994:

/* Line 690 of lalr1.cc  */
#line 5983 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("unique"))); }
    break;

  case 995:

/* Line 690 of lalr1.cc  */
#line 5984 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("non"))); }
    break;

  case 996:

/* Line 690 of lalr1.cc  */
#line 5985 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("on"))); }
    break;

  case 997:

/* Line 690 of lalr1.cc  */
#line 5986 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("range"))); }
    break;

  case 998:

/* Line 690 of lalr1.cc  */
#line 5987 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("equality"))); }
    break;

  case 999:

/* Line 690 of lalr1.cc  */
#line 5988 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("manually"))); }
    break;

  case 1000:

/* Line 690 of lalr1.cc  */
#line 5989 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("automatically"))); }
    break;

  case 1001:

/* Line 690 of lalr1.cc  */
#line 5990 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("maintained"))); }
    break;

  case 1002:

/* Line 690 of lalr1.cc  */
#line 5991 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("decimal-format"))); }
    break;

  case 1003:

/* Line 690 of lalr1.cc  */
#line 5992 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("decimal-separator"))); }
    break;

  case 1004:

/* Line 690 of lalr1.cc  */
#line 5993 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("grouping-separator"))); }
    break;

  case 1005:

/* Line 690 of lalr1.cc  */
#line 5994 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("infinity"))); }
    break;

  case 1006:

/* Line 690 of lalr1.cc  */
#line 5995 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("minus-sign"))); }
    break;

  case 1007:

/* Line 690 of lalr1.cc  */
#line 5996 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("NaN"))); }
    break;

  case 1008:

/* Line 690 of lalr1.cc  */
#line 5997 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("percent"))); }
    break;

  case 1009:

/* Line 690 of lalr1.cc  */
#line 5998 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("per-mille"))); }
    break;

  case 1010:

/* Line 690 of lalr1.cc  */
#line 5999 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("zero-digit"))); }
    break;

  case 1011:

/* Line 690 of lalr1.cc  */
#line 6000 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("digit"))); }
    break;

  case 1012:

/* Line 690 of lalr1.cc  */
#line 6001 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("pattern-separator"))); }
    break;

  case 1013:

/* Line 690 of lalr1.cc  */
#line 6002 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("collection"))); }
    break;

  case 1014:

/* Line 690 of lalr1.cc  */
#line 6003 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("const"))); }
    break;

  case 1015:

/* Line 690 of lalr1.cc  */
#line 6004 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("append-only"))); }
    break;

  case 1016:

/* Line 690 of lalr1.cc  */
#line 6005 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("queue"))); }
    break;

  case 1017:

/* Line 690 of lalr1.cc  */
#line 6006 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("mutable"))); }
    break;

  case 1018:

/* Line 690 of lalr1.cc  */
#line 6007 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("read-only"))); }
    break;

  case 1019:

/* Line 690 of lalr1.cc  */
#line 6008 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("integrity"))); }
    break;

  case 1020:

/* Line 690 of lalr1.cc  */
#line 6009 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("constraint"))); }
    break;

  case 1021:

/* Line 690 of lalr1.cc  */
#line 6010 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("check"))); }
    break;

  case 1022:

/* Line 690 of lalr1.cc  */
#line 6011 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("key"))); }
    break;

  case 1023:

/* Line 690 of lalr1.cc  */
#line 6012 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("foreach"))); }
    break;

  case 1024:

/* Line 690 of lalr1.cc  */
#line 6013 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("foreign"))); }
    break;

  case 1025:

/* Line 690 of lalr1.cc  */
#line 6014 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("keys"))); }
    break;

  case 1026:

/* Line 690 of lalr1.cc  */
#line 6015 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ancestor"))); }
    break;

  case 1027:

/* Line 690 of lalr1.cc  */
#line 6016 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("child"))); }
    break;

  case 1028:

/* Line 690 of lalr1.cc  */
#line 6017 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descendant"))); }
    break;

  case 1029:

/* Line 690 of lalr1.cc  */
#line 6018 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("parent"))); }
    break;

  case 1030:

/* Line 690 of lalr1.cc  */
#line 6019 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preceding"))); }
    break;

  case 1031:

/* Line 690 of lalr1.cc  */
#line 6020 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("self"))); }
    break;

  case 1032:

/* Line 690 of lalr1.cc  */
#line 6021 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("following"))); }
    break;

  case 1033:

/* Line 690 of lalr1.cc  */
#line 6022 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ancestor-or-self"))); }
    break;

  case 1034:

/* Line 690 of lalr1.cc  */
#line 6023 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descendant-or-self"))); }
    break;

  case 1035:

/* Line 690 of lalr1.cc  */
#line 6024 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("following-sibling"))); }
    break;

  case 1036:

/* Line 690 of lalr1.cc  */
#line 6025 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preceding-sibling"))); }
    break;

  case 1037:

/* Line 690 of lalr1.cc  */
#line 6026 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("position"))); }
    break;

  case 1038:

/* Line 690 of lalr1.cc  */
#line 6029 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), true); }
    break;



/* Line 690 of lalr1.cc  */
#line 12491 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
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
  const short int jsoniq_parser::yypact_ninf_ = -1553;
  const short int
  jsoniq_parser::yypact_[] =
  {
      4883, -1553, -1553, -1553, -1553,  6121,  6121,  6121,  6121, -1553,
   -1553,   253,   336, -1553,   980,    23, -1553, -1553, -1553,   924,
   -1553, -1553, -1553,   297,   394,   928,  4417,   461,   482,   877,
   -1553,    67, -1553,   545, -1553, -1553, -1553, -1553, -1553,   930,
   -1553,   599,   609, -1553, -1553, -1553, -1553,   680, -1553,   942,
   -1553,   619,   669, -1553,   518, -1553, -1553, -1553, -1553, -1553,
   -1553, -1553, -1553, -1553, -1553, -1553, -1553, -1553, -1553,   715,
     747, -1553, -1553, -1553, -1553,   757, 14422, -1553, -1553, -1553,
     797, -1553, -1553, -1553,   782, -1553,   818,   820, -1553, -1553,
   18926, -1553, -1553, -1553, -1553, -1553, -1553, -1553, -1553,   852,
   -1553, -1553,   888,   902, -1553, -1553, -1553, -1553, -1553, -1553,
    6121,  8270,  8577, 18926, -1553, -1553,   728, -1553, -1553, -1553,
   -1553,   881, -1553, -1553,   926, 18926, -1553, 17431,   934,   943,
   -1553, -1553, -1553,   950, -1553, -1553, 12887, -1553, -1553, -1553,
   -1553, -1553, -1553,   889, -1553, -1553, -1553, -1553, -1553, -1553,
   -1553, -1553,   137,   834,   866, -1553, -1553, -1553, -1553, -1553,
   -1553, -1553, -1553, -1553, -1553, -1553, 19220,   945,  8884, -1553,
   19521,   -94, -1553, -1553, -1553, -1553, -1553, -1553,   970, -1553,
     855,   864,   871, -1553, -1553,   968,   986, -1553, -1553, -1553,
   -1553, -1553, -1553, -1553, -1553, -1553, -1553, -1553, -1553,  4596,
   -1553, 14115, -1553, -1553, -1553, -1553, -1553, -1553, -1553, -1553,
   -1553, -1553, -1553, -1553, -1553, -1553, -1553, -1553, -1553, -1553,
   -1553, -1553, -1553, -1553, -1553, -1553, -1553, -1553, -1553, -1553,
   -1553, -1553, -1553, -1553, -1553, -1553, -1553, -1553, -1553, -1553,
   -1553, -1553, -1553, -1553, -1553, -1553, -1553, -1553, -1553, -1553,
    9195,  9502,  9813, -1553,  5195,  5507,  1143, -1553,  6428, -1553,
   -1553,   134,   108, -1553, -1553, -1553, -1553, -1553, -1553, -1553,
   -1553, -1553, -1553, -1553, -1553, -1553, -1553,   112, -1553, -1553,
   -1553, -1553, -1553, -1553,   124, -1553, -1553, -1553, -1553, -1553,
   -1553, -1553, -1553,  6121, -1553, -1553, -1553, -1553,    25, -1553,
   -1553, -1553, -1553, -1553, -1553, -1553, -1553, -1553,   333, -1553,
     962, -1553, -1553, -1553,   175, -1553,   120, -1553, -1553, -1553,
   -1553, -1553, -1553, -1553,   978,  1061, -1553, -1553,   915,   901,
    1056,   660,   685,   793,   652, -1553,  1107,   957,  1058,  1059,
   11659, -1553,   969, -1553, -1553,    10, -1553, -1553, 13194, -1553,
     906, -1553,  1008, 14422, -1553,  1008, 14422, -1553, -1553, -1553,
      37, -1553, -1553, -1553, -1553, -1553, -1553, -1553, -1553, -1553,
   -1553, -1553, -1553, -1553, -1553, -1553, -1553, -1553, -1553, -1553,
   -1553, -1553, -1553, -1553, -1553, -1553, -1553, -1553, -1553,  1009,
   -1553, -1553, -1553, -1553, -1553, -1553, -1553, -1553, -1553, -1553,
   -1553, -1553, -1553, -1553, -1553, -1553, -1553, -1553, -1553, -1553,
   -1553, -1553, -1553, -1553, -1553, -1553, -1553,   463, -1553, -1553,
   -1553, -1553, -1553,   981, -1553,  6121,   984,   985,   987,  6121,
     467,   467,  1138,   787,   800,   225, 20416, 18926,   427,  1126,
   18926,  1020,  1057,   708, 18926,   878,   927, 18926, 18926,   868,
     920,    57, -1553, -1553, -1553, 18926,  6121,   991,  6121,    80,
   11045, 17730, 18926,    27,  1025, 11045,  1180,    84,    85, 18926,
    1063,  1039,  1077, -1553,   998, 11045, 18029, 18926, 18926, 18926,
    6121,   999, 11045, 11045, 18926,  6121,  1034,  1035, -1553, -1553,
   -1553, 11045, 18328,  1033, -1553,  1036, -1553, -1553, -1553, -1553,
    1037, -1553,  1038, -1553, -1553, -1553, -1553, -1553,  1040, -1553,
   -1553, -1553, -1553, -1553, -1553, -1553, -1553, -1553, -1553, -1553,
   -1553, -1553, -1553, -1553, -1553, -1553, -1553, -1553, -1553, -1553,
   -1553, -1553, -1553, -1553, 18926, -1553, -1553, -1553, -1553, -1553,
   -1553, -1553, -1553, -1553, -1553, -1553, -1553, -1553,  1048, 18926,
   -1553, -1553,  1014,  5814,  1070,    39,  1078,  1044,  1045,  1046,
   18926,  6121, -1553,  1051,   417, -1553,   513, -1553,   136,  1172,
   11045, 11045, -1553,    91, -1553, -1553,  1191, -1553, -1553, -1553,
   -1553, 11045,   994, -1553,  1181,  1182,  1055,  1060,  1062,  1064,
    1065, 11045, 11352, 20123,    37,   463, 13501, 13808, 11045,   255,
      -2, 11045, 20123,   749, 11045,   977,   988, 18926,  1027,  1030,
   11045, 11045,  6121,   966, 18926, -1553, -1553,    58, -1553,    73,
   11045,   997,  5507, -1553, -1553, -1553, -1553, -1553,   980,   877,
     115,   119,  1233,  6735,  3147,  7042,  3465,   782, -1553, -1553,
     454,   782, -1553, 11045,  4095, -1553,  1118,   733,    67,  1069,
    1068,  1071,  6121, 11045,   860, -1553, -1553, -1553, -1553, -1553,
   -1553, -1553, -1553, -1553,   951,   952, 18926,  1124, 11966, 11966,
   -1553, -1553, -1553, -1553, -1553, -1553, 12273,  1173, 12273, 12273,
   12273, 12273, 12273, 12273, 12273, 12273, 12273, 12273, 12273, 12273,
    1011,  1150,  1153,  1154, -1553, -1553, -1553, 12580, 10124, -1553,
   -1553, 12887, 12887, 11045,  1008, -1553, -1553,  1008, -1553, 17132,
    7656,  1008,  1072,  1100,  7963, -1553, -1553, -1553, -1553,    34,
   -1553,   251, -1553, -1553, -1553, -1553, -1553, -1553,  1145,  1148,
     461,  1222, -1553, -1553, 20416,  1144,   667, 18926,  1095,  1096,
    1144,  1138,  1130,  1127, -1553, -1553, -1553,    33,  1012,  1167,
     960, 18926,  1121, 11045,  1149, 18926, 18926, -1553,  1133,  1084,
   -1553,  1086,  1036,   609, -1553,  1085,  1087,   460, -1553,   262,
     265,  1168, -1553,    60, 18926,  1183,   279, -1553,  6121, -1553,
     148, -1553, 18926,  1184,  1232, 18926,  1138,  1186,   456, 18926,
   11045,    67, -1553,   478,  1091, -1553,  1098,  1099,  1103,    21,
   -1553,   326,  1108, -1553,   163,   183,  1129, -1553,  1110,  6121,
    6121,   481, -1553,   328,   381,   640, 11045,   294, -1553, -1553,
   11045, 11045, -1553, 11045, 11045, 11045, 11045, -1553, 11045, -1553,
   11045, -1553, 18926,  1172, -1553,   453,   491,   540, -1553, -1553,
   -1553,   556, -1553,    15,   266, -1553, -1553,    37,   420,   437,
     275,   125, 11045, 11045,  1202,   767, 11045,  1066, 19822,  1067,
       9, -1553,  1155, -1553, -1553,  1109,   189,  5814,   586, 14726,
     966, -1553,  1168, -1553, -1553,  1073, 11045, -1553,   134,   891,
    1265,   158, -1553, -1553,   121, -1553, -1553, -1553,   123, -1553,
     173, -1553, -1553, -1553, -1553, -1553,  3780, -1553, -1553, -1553,
   18926,  1131, 11045,  1187, -1553, -1553, -1553, -1553, -1553,  1168,
   18926,    41,  1061, -1553, -1553,   560, -1553,   685,   685,   579,
     793,   793,   793,   793,   652,   652, -1553, -1553, 16530, 16530,
   18926, 18926, -1553, -1553,   587, -1553, -1553,   430, -1553, 10431,
   -1553, -1553, -1553, -1553, -1553, -1553,   418, -1553, -1553, -1553,
     503,   467, -1553, -1553,   806,   823,   835, -1553,   461, -1553,
   -1553, -1553, -1553, -1553, -1553, -1553, -1553, -1553, -1553,  1144,
   -1553,  1176, 16831,  1163, 11045, -1553, -1553, -1553,  1217,  1138,
    1138,  1144, -1553,   983,  1138,   759, 18926,   697,   737,  1283,
   -1553, -1553,  1024,   398, -1553, -1553, -1553, -1553, -1553, -1553,
   -1553, -1553, -1553, -1553, -1553,    33,   100,  1089,   720, 11045,
   -1553, 18926,  1221,  1013,  1138, -1553, -1553, -1553, -1553,  1164,
   18926, -1553, 18926, -1553, 18627,  1189, 16530,  1204, 11045,   212,
    1177,    59,  1217, 16530,  1208,  1234,  1146,  1134,  1194,  1138,
    1175,  1196,  1237,  1138, 11045,   -36, -1553, -1553, -1553,  1185,
   -1553, -1553, -1553, -1553,  1216, 11045, 11045,  1190, -1553,  1241,
    1242,  6121, -1553,  1159,  1161,  1192, 18926, -1553, 18926, -1553,
   11045,  1206,  1147, 11045, -1553,  1228,  1230, -1553,   240,   242,
     258,  1319, -1553,   470, -1553,   344,  1200, -1553, -1553,  1326,
   -1553,  1327, -1553,   -62, 11045, 11045, 11045,   580, 11045, 11045,
   11045, 11045, 11045,  1261, -1553, 11045, 11045, -1553, 11045, 11045,
     282, 20123,  1240, 11045, 11045, -1553,  7349,   111,  1111, -1553,
     436, -1553, 11045, -1553,   127,   194,   173,  7042,  3465,  7042,
    1280, -1553, -1553, 11045,   870,  1254, -1553, 18926,  1256, -1553,
     555,  1106, -1553, -1553,   850,    41, 11045,   560,   771,   288,
   -1553,  1076,   439,  1112,  1104, -1553, -1553,   927, -1553,  1101,
     -73,  1212,  1213, 15326,  1214,  1218,  1219,  1220,  1224, -1553,
     618, -1553, -1553, -1553, -1553, -1553, -1553, -1553, -1553, -1553,
   -1553, -1553, -1553, -1553,  1239, -1553, -1553, -1553, -1553, -1553,
     319, 10738, -1553, -1553, -1553, -1553, -1553, -1553, -1553, -1553,
   -1553,   843, -1553,  1344, 16831,   929, -1553, -1553, -1553, -1553,
   -1553, -1553, -1553, -1553, -1553,  1088, -1553, -1553,  1350, -1553,
   -1553, -1553, -1553, -1553,   468,  1356, -1553,   751, -1553, -1553,
   -1553,  1033,   394,   545,  1037,   599,  1038,  1040, -1553, -1553,
     618,   618, 12580,  1102,  1079, -1553,  1217,   100,  1165,  1207,
    6121,  1205,  1215,  1255,  1223,  1226, 18926, -1553,   584, -1553,
   18926, -1553, 11045,  1251, 11045,  1273, 11045,   220,  1258, -1553,
   -1553, -1553, 16530, -1553,  6121,  1138,  1296, -1553, -1553, -1553,
    1138,  1296, -1553, 11045,  1264,  6121, 18926, -1553, -1553, 11045,
   11045,   819, -1553,    17,   899, -1553, 15627,   905, -1553,   909,
   -1553,  1225, -1553, -1553,  6121,  1227,  1229, -1553, 11045, -1553,
   -1553, 11045, 11045,  1210,  1241,  1311, -1553,  1282, -1553,   565,
   -1553, -1553,  1411, -1553, -1553,  6121, 18926, -1553,   876, -1553,
   -1553, -1553,  6121,  1236,  1243,  1193,  1195, -1553, -1553, -1553,
    1197,  1209, -1553, -1553, -1553,  1322, -1553,  1122, -1553, -1553,
   -1553,  1188, 11045,   312, 18926,  1238, -1553,  1266,  1274,  1286,
    1291, -1553,   962,   550, 14726,  1111, -1553,  7349, 14726, -1553,
   -1553,  1265,   337, -1553, -1553, -1553,  1254, -1553,  1138, -1553,
    1000, -1553,    65,  1342, -1553, 11045,   740,  1187, 11045,  1301,
   -1553,  1332,  1333, 11045, 18926,   955,  1375, -1553, -1553, -1553,
     606,  1267, -1553,   560,  1199, -1553, -1553,   490, -1553,   516,
       8,  1201,   560,   516, 12273, -1553,     6, -1553, -1553, -1553,
   -1553, -1553, -1553,   560,  1308,  1174,  1012,     8, -1553, -1553,
    1169,  1380, -1553, -1553, -1553, 15025,  1276, -1553,  1277,  1278,
    1279,  1281,  1284,  1285, -1553, -1553, -1553, -1553, -1553, -1553,
   -1553, -1553, -1553, -1553, -1553, -1553, -1553, -1553,  1432,    12,
    1438,    12,  1198,  1362, -1553, -1553,  1300, 18926,  1235, -1553,
   -1553, 12580, -1553,  1290, -1553, -1553, -1553, -1553, -1553, -1553,
   11045,  1328, -1553, -1553, 11045, -1553,   653, -1553, 11045,  1330,
   11045, -1553,  1348,  1352,  1384,  1138,  1296, -1553, 11045,  1297,
   -1553, -1553, -1553,  1298, -1553,    18, 11045,  6121,  1299,    26,
   -1553, 18926,   -14, -1553, 15928,    63, -1553, 16229,  1302, -1553,
   -1553,  1303, -1553, -1553, -1553, -1553, -1553, 11045,   914,  1319,
   18926,   921, -1553,  1305,  1319, 18926, -1553,  1306, -1553, -1553,
   11045, 11045, 11045, 11045,  1162, 11045, 11045, -1553, 11045, -1553,
   11045, 11045, 11045, 11045,  7349,   574, -1553, -1553, -1553, -1553,
   -1553,  1342, -1553, -1553, -1553,  1138, 11045, -1553,  1340, -1553,
   -1553, 11045, 18926, 18926, -1553,   796, -1553, 11045, -1553, -1553,
   -1553,  1307, 12273, -1553, -1553, -1553, -1553, -1553,   477, 12273,
   12273,   677, -1553,  1112, -1553,   672, -1553,  1104,   560,  1339,
   -1553, -1553,  1211, -1553, -1553, -1553, -1553,  1392,  1310, -1553,
     505, -1553, -1553, -1553, -1553, -1553, -1553, -1553, -1553,   601,
     601, -1553,    12, -1553, -1553,   533, -1553,  1465,    81,  1405,
    1315, 12580,   -18,  1231,  1335, -1553, -1553, 11045, -1553, 11045,
    1359, -1553, 11045, -1553,  7349, 11045,  1138, -1553, -1553, -1553,
   11045, 11045, -1553, -1553, -1553,  7349,  7349,  1414,  6121, 16530,
   18926,   658, 18926, 11045, 18926,   679,  7349, -1553,   277,    44,
    1319, 18926, -1553,  1312,  1319, -1553, -1553, -1553, -1553, -1553,
   11045, -1553, -1553, -1553, -1553,   339,   378,   379, 11045, -1553,
   -1553, -1553,  1404, 11045, -1553, -1553,  1458, -1553, -1553, -1553,
     793, 12273, 12273,   579,   785, -1553, -1553, -1553, -1553, -1553,
   -1553, 11045, -1553, 16530, -1553, 16530,  1418, -1553, -1553, -1553,
    1484, -1553, -1553, -1553,  1245,  1408, -1553, -1553,  1409, -1553,
     286, 18926,  1399,  1289, 18926, 12580, -1553, -1553, 11045, -1553,
   -1553, -1553,  1296, -1553, -1553, 16530, -1553, -1553, -1553,  1425,
   11045,  1334, -1553,  1427,  7349, -1553, 18926,   696,   102, -1553,
    1336,  1319, -1553,  1337, -1553,  1325,  1241,  1242,   622, -1553,
    1404,  1406,   579,   579, 12273,   623, -1553, -1553, 16530, -1553,
   -1553,  1405, 12580, -1553,  1342,  1246, 18926,  1407,  1309,  1409,
   -1553,   726, 16530,  6121, 16530,  1341, -1553, -1553,  1435,   764,
   -1553, -1553, -1553, -1553,  1346,   502, -1553, -1553, -1553,  1343,
   -1553,  7349,   931, -1553, -1553, 18926,   579, -1553, -1553, -1553,
   -1553, -1553, 11045,  1247, 18926,  1412,  6121,   756, -1553, -1553,
     777, 11045, -1553, -1553, -1553, -1553, -1553, -1553, -1553,  1413,
   -1553, -1553,  1248,  1249, 18926, -1553, -1553, 11045,  7349, 18926,
    1244, 11045,  1250,  1351, 12580, -1553, 12580,  7349, -1553,  1345,
    1252, 18926,  1313,  1421, 18926,  1253, 12580, -1553
  };

  /* YYDEFACT[S] -- default reduction number in state S.  Performed when
     YYTABLE doesn't specify something else to do.  Zero means the
     default is an error.  */
  const unsigned short int
  jsoniq_parser::yydefact_[] =
  {
       167,   463,   464,   826,   465,   170,   170,   170,     0,   843,
    1038,   122,   124,   642,   936,   945,   885,   848,   846,   828,
     937,   940,   892,   852,   829,   831,     0,   946,   832,   943,
     914,   894,   868,   830,   889,   890,   941,   938,   888,   834,
     944,   835,   836,   980,   992,   979,   886,   905,   899,   837,
     887,   839,   838,   981,   923,   924,   891,   865,  1002,  1003,
    1004,  1005,  1006,  1007,  1008,  1009,  1010,  1011,  1012,  1026,
    1033,   913,   909,   900,   879,   827,     0,   908,   916,   925,
    1027,   904,   496,   880,   881,   939,  1028,  1034,   901,   918,
       0,   504,   452,   498,   911,   845,   902,   903,   932,   906,
     922,   931,  1032,  1035,   851,   893,   934,   497,   921,   927,
     170,     0,     0,     0,   401,   919,   930,   935,   933,   912,
     898,   982,   896,   897,  1029,     0,   400,     0,  1030,  1036,
     928,   882,   907,  1031,   213,   430,     0,   462,   929,   910,
     917,   926,   920,   983,   873,   878,   877,   876,   875,   874,
     840,   895,     0,   844,     0,   942,   866,   495,   499,   500,
     973,   972,   974,   850,   849,   869,     0,   833,     0,   976,
       0,     0,   872,   915,   971,   978,   977,   970,   870,   975,
     987,   988,   985,   986,   984,   841,   989,   990,   991,   962,
     961,   948,   864,   857,   955,   951,   867,   863,   963,     0,
     853,   854,   847,   856,   960,   959,   956,   952,   968,   969,
     967,   958,   954,   947,   855,   966,   965,   859,   861,   860,
     953,   957,   949,   862,   950,   858,   964,  1013,  1014,  1015,
    1016,  1017,  1018,   994,   995,   993,   999,  1000,  1001,   996,
     997,   998,   871,  1019,  1020,  1021,  1022,  1023,  1024,  1025,
       0,     0,     0,  1037,   167,   167,     0,     2,   167,     9,
      11,    25,     0,    30,    33,    38,    39,    40,    41,    42,
      43,    44,    34,    60,    61,    35,    36,     0,    78,    81,
      82,    37,    83,    84,     0,   120,    85,    86,    87,    88,
      20,   164,   165,   166,   173,   176,   487,   177,     0,   178,
     179,   180,   181,   182,   183,   184,   187,   188,     0,   214,
     222,   217,   249,   255,     0,   247,     0,   248,   224,   218,
     186,   219,   185,   220,   223,   358,   360,   362,   364,   366,
     368,   372,   374,   377,   382,   385,   388,   390,   392,   394,
       0,   398,   405,   404,   406,     0,   421,   407,   426,   429,
     431,   434,   436,     0,   441,   438,     0,   449,   459,   461,
     435,   466,   478,   492,   494,   479,   480,   481,   484,   485,
     482,   486,   513,   514,   483,   517,   519,   520,   521,   518,
     566,   567,   568,   569,   570,   571,   572,   458,   614,     0,
     605,   613,   612,   611,   610,   607,   609,   606,   608,   493,
      45,   225,   226,   228,   227,   229,   221,   489,   490,   491,
     488,   231,   234,   230,   232,   233,   460,   825,   842,   936,
     945,   943,   844,     0,   168,   169,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   128,   130,   131,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   280,   281,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   454,   457,
     444,     0,     0,   828,   852,   831,   883,   946,   832,   894,
     834,   905,   837,   839,   838,   923,  1026,  1033,   827,  1027,
     881,  1028,  1034,   906,  1032,  1035,   930,   982,  1029,  1030,
    1036,  1031,   983,   870,   987,   988,   985,   841,   989,   884,
     854,   450,   825,   442,     0,   194,   443,   446,   828,   829,
     831,   830,   834,   835,   836,   837,   827,   833,   501,     0,
     448,   447,     0,     0,   214,     0,   460,   832,   839,   838,
       0,   170,   790,   989,     0,   222,     0,   502,     0,   533,
       0,     0,   453,     0,   424,   425,     0,   456,   455,   445,
     428,     0,     0,   562,     0,     0,     0,     0,     0,     0,
       0,     0,   976,     0,   810,     0,   833,   976,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   363,   792,     0,   794,     0,
       0,     0,   167,     3,     4,     1,    10,    12,     0,     0,
       0,     0,     6,   167,     0,   167,     0,     0,   121,   174,
       0,     0,   192,     0,     0,   201,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   206,   235,   254,   250,   256,
     251,   253,   252,   260,     0,     0,     0,     0,     0,     0,
     409,   414,   413,   412,   411,   410,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   403,   402,   399,     0,     0,   422,
     427,     0,     0,     0,   437,   475,   440,   439,   451,     0,
       0,   467,     0,     0,     0,   574,   576,   580,   582,     0,
     126,     0,   824,    49,    46,    47,    50,    51,     0,     0,
       0,     0,    52,    53,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   649,   650,   651,     0,   105,   144,
       0,     0,   114,     0,     0,     0,     0,   129,     0,     0,
     622,     0,     0,     0,   617,     0,     0,     0,   632,     0,
       0,   258,   263,     0,     0,   136,     0,   140,   170,   516,
       0,    62,     0,    71,     0,     0,     0,    63,     0,     0,
       0,     0,   620,     0,     0,   623,     0,     0,     0,     0,
     329,     0,     0,   621,     0,     0,     0,   640,     0,     0,
       0,     0,   626,     0,     0,   196,     0,     0,   190,   189,
       0,     0,   796,     0,     0,     0,     0,   501,     0,   791,
       0,   503,   534,   533,   530,     0,     0,     0,   564,   563,
     423,     0,   561,     0,     0,   662,   663,   809,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   668,     0,   204,   205,     0,     0,     0,     0,     0,
     209,   210,   259,   793,   795,     0,     0,     5,    26,     0,
      27,     0,     7,    31,     0,    17,     8,    32,     0,    21,
     936,    79,    18,    80,    22,   195,     0,   193,   215,   216,
       0,     0,     0,     0,   207,   236,   298,   237,   238,   257,
       0,     0,   359,   361,   365,     0,   369,   376,   375,   373,
     379,   380,   381,   378,   383,   384,   387,   386,     0,     0,
       0,     0,   408,   419,     0,   432,   433,     0,   476,     0,
     473,   474,   470,   509,   468,   511,     0,   615,   515,   507,
       0,     0,   123,   125,     0,     0,     0,   104,     0,    94,
      96,    97,    98,    99,   101,   102,   103,    95,   100,    90,
      91,     0,     0,   110,     0,   106,   108,   109,   116,     0,
       0,    89,    48,     0,     0,     0,     0,     0,     0,     0,
     740,   745,     0,     0,   741,   775,   728,   730,   731,   732,
     734,   736,   735,   733,   737,     0,     0,     0,     0,     0,
     113,     0,   146,     0,     0,   579,   573,   618,   619,     0,
       0,   636,     0,   633,     0,     0,     0,     0,     0,     0,
       0,     0,   142,     0,     0,   137,     0,     0,     0,     0,
       0,     0,    64,     0,     0,     0,   279,   285,   282,     0,
     625,   624,   631,   639,     0,     0,     0,     0,   578,     0,
       0,     0,   415,     0,     0,     0,     0,   629,     0,   627,
       0,   197,     0,     0,   798,     0,   460,   797,     0,     0,
       0,   533,   531,     0,   522,     0,     0,   505,   506,     0,
      13,     0,    15,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   804,   805,     0,     0,   812,     0,     0,
       0,     0,     0,     0,     0,   202,     0,     0,     0,   676,
       0,   211,     0,   808,     0,     0,     0,   167,     0,   167,
       0,   175,   246,     0,   313,   309,   311,     0,   299,   300,
       0,     0,   239,   240,     0,   245,     0,     0,     0,     0,
     706,   370,   679,   683,   685,   687,   689,   692,   699,   700,
     708,   946,   595,     0,   840,   821,   823,   819,   597,   389,
     585,   592,   593,   598,   643,   644,   599,   600,   815,   816,
     817,   603,   391,   393,   396,   604,   395,   420,   477,   471,
       0,     0,   469,   508,   127,    58,    59,    56,    57,   133,
     132,     0,    92,     0,     0,     0,   111,   112,   117,    76,
      77,    54,    55,    75,   746,     0,   749,   776,     0,   739,
     738,   743,   742,   774,     0,     0,   751,     0,   747,   750,
     729,     0,     0,     0,     0,     0,     0,     0,   616,   145,
     148,   150,     0,     0,     0,   115,   118,     0,     0,     0,
     170,     0,     0,   640,     0,     0,     0,   265,     0,   584,
       0,   266,     0,     0,     0,     0,     0,     0,     0,   143,
     138,   141,     0,   191,     0,     0,    73,    67,    70,    69,
       0,    65,   283,     0,     0,   170,     0,   327,   331,     0,
       0,     0,   334,     0,     0,   340,     0,     0,   347,     0,
     351,     0,   417,   416,   170,     0,     0,   198,     0,   200,
     328,     0,     0,     0,     0,     0,   534,     0,   524,     0,
     557,   554,     0,   558,   559,     0,     0,   553,     0,   528,
     556,   555,     0,     0,     0,     0,     0,   655,   656,   652,
       0,     0,   660,   661,   657,   801,   802,     0,   666,   811,
     664,     0,     0,     0,     0,     0,   670,   832,   839,   838,
     989,   203,     0,     0,     0,   671,   672,     0,     0,   212,
     807,    28,     0,    19,    23,    24,   310,   322,     0,   323,
       0,   314,   315,   316,   317,     0,   302,     0,     0,     0,
     241,     0,     0,     0,     0,   292,     0,   289,   294,   244,
       0,     0,   690,   703,     0,   367,   371,     0,   722,     0,
       0,     0,     0,     0,     0,   678,   680,   681,   717,   718,
     719,   721,   720,     0,     0,   694,   693,     0,   697,   701,
     715,   713,   712,   705,   709,     0,     0,   588,     0,     0,
       0,     0,     0,     0,   589,   591,   590,   586,   397,   472,
     510,   512,   135,   134,    93,   107,   763,   744,     0,   768,
       0,   768,   757,   752,   149,   151,     0,     0,     0,   119,
     147,     0,    29,     0,   637,   638,   641,   634,   635,   264,
       0,     0,   278,   270,     0,   274,     0,   268,     0,     0,
       0,   139,     0,     0,    72,     0,    66,   284,     0,     0,
     330,   332,   337,     0,   335,     0,     0,     0,     0,     0,
     341,     0,     0,   355,     0,     0,   348,     0,     0,   352,
     418,     0,   630,   628,   199,   799,   800,     0,     0,   533,
       0,     0,   565,     0,   533,     0,   529,     0,    14,    16,
       0,     0,     0,     0,     0,     0,     0,   814,     0,   669,
       0,     0,     0,     0,     0,     0,   673,   677,   326,   324,
     325,   318,   319,   320,   312,     0,     0,   307,     0,   301,
     287,     0,     0,     0,   243,   290,   293,     0,   707,   698,
     704,     0,     0,   777,   778,   788,   787,   786,     0,     0,
       0,     0,   779,   684,   785,     0,   682,   686,     0,     0,
     691,   695,     0,   716,   711,   714,   710,     0,     0,   601,
       0,   594,   648,   587,   820,   822,   818,   596,   764,     0,
       0,   762,   769,   770,   766,     0,   761,     0,   759,     0,
       0,     0,     0,     0,     0,   575,   267,     0,   276,     0,
       0,   272,     0,   275,     0,     0,     0,    68,   286,   581,
       0,     0,   338,   342,   336,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   577,     0,     0,
     533,     0,   560,     0,   533,   583,   653,   654,   658,   659,
       0,   806,   665,   813,   667,     0,     0,     0,     0,   674,
     321,   308,   303,     0,   288,   296,   297,   291,   242,   702,
     789,     0,     0,   781,     0,   727,   726,   725,   724,   723,
     688,     0,   780,     0,   645,     0,     0,   773,   772,   771,
       0,   765,   758,   756,     0,   753,   754,   748,   152,   154,
     156,     0,     0,     0,     0,     0,   271,   269,     0,   277,
     208,   357,    74,   333,   339,     0,   353,   349,   356,     0,
       0,     0,   343,     0,     0,   345,     0,   543,   537,   532,
       0,   533,   523,     0,   803,     0,     0,     0,     0,   306,
     304,     0,   783,   782,     0,     0,   646,   602,     0,   767,
     760,     0,     0,   158,   157,     0,     0,     0,     0,   153,
     273,     0,     0,     0,     0,     0,   551,   545,     0,   544,
     546,   552,   549,   539,     0,   538,   540,   550,   525,     0,
     526,     0,     0,   675,   305,     0,   784,   696,   647,   755,
     155,   159,     0,     0,     0,     0,     0,     0,   346,   344,
       0,     0,   536,   547,   548,   535,   541,   542,   527,     0,
     295,   160,     0,     0,     0,   354,   350,     0,     0,     0,
       0,     0,     0,     0,     0,   162,     0,     0,   161,     0,
       0,     0,     0,     0,     0,     0,     0,   163
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  jsoniq_parser::yypgoto_[] =
  {
     -1553, -1553,  -214,  -190, -1553,  1275,  1292, -1553,  1287,  -547,
   -1553, -1553, -1553, -1553, -1553, -1553, -1553, -1553, -1553, -1553,
   -1000, -1553, -1553, -1553, -1553,  -219,  -619, -1553,   807,  -568,
   -1553, -1553, -1553, -1553, -1553,   332,   576, -1553, -1553,   -11,
    -163,  1132, -1553,  1114, -1553, -1553,  -630, -1553,   519, -1553,
     305, -1553,  -175,  -220, -1553,  -557, -1553,     5,    64,    16,
    -218,  -185, -1553,  -874, -1553, -1553,   412, -1553, -1553, -1553,
   -1553, -1553, -1553, -1553, -1553, -1553, -1553,   698, -1553,   283,
    1331,     0, -1553, -1553, -1553, -1553,   421, -1553, -1553,  -301,
   -1553,    20, -1553, -1553,     1,  -931,  -735,  -722, -1553, -1553,
     776, -1553, -1553,    -6,   176, -1553, -1553, -1553,   185, -1552,
   -1553,   440,   191, -1553, -1553,   188, -1321, -1553,  1028,   292,
   -1553, -1553,   289, -1012, -1553, -1553,   285, -1553, -1553, -1265,
   -1252, -1553,   287, -1434, -1553, -1553,   913,  -152, -1553,   908,
     904, -1553, -1553,  -672,   458,  -648,   447,   451, -1553, -1553,
   -1553,   654, -1553, -1553,  1257, -1553, -1553, -1553, -1553,  -875,
    -331,  -695, -1553,   -97, -1553, -1553, -1553, -1553, -1553, -1553,
   -1553,   -10,  -825, -1553,  -151,   723,   359, -1553,  -401, -1553,
   -1553,   880, -1553, -1553, -1553, -1553, -1553,   882, -1553, -1553,
   -1553, -1553, -1027, -1553,   272, -1553,   761,  -802, -1553, -1553,
   -1553, -1553, -1553,  -210,  -201, -1226,  -965, -1553, -1553, -1553,
   -1553, -1553, -1553, -1553, -1553, -1553, -1553, -1553,  -755,  -872,
     -96,  -865, -1553, -1553, -1553,  -837, -1553, -1553, -1553, -1553,
   -1553, -1553, -1553, -1553, -1553,  1141,  1142,  -252,   581,  -657,
   -1553, -1553, -1553, -1553, -1553, -1553, -1553, -1553, -1553, -1553,
   -1553,   248, -1553, -1553,   239, -1553,   241, -1074, -1553, -1553,
   -1553,   195,   186,    13,   464, -1553, -1553, -1553, -1553, -1553,
   -1553, -1553, -1553, -1553, -1553, -1553, -1553, -1553,   190, -1553,
   -1553, -1553,    19,   459,   608, -1553, -1553, -1553, -1553, -1553,
     388, -1553, -1553, -1426, -1553, -1553, -1553,  -468, -1553,   156,
   -1553,    -4, -1553, -1553, -1553, -1553, -1338, -1553,   206, -1553,
   -1553, -1553, -1553, -1553,  -114, -1553, -1553, -1553, -1553, -1553,
    -925, -1553, -1553, -1553,  -400,   944,   -72, -1553
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  jsoniq_parser::yydefgoto_[] =
  {
        -1,   256,   644,   257,   258,   259,   260,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
    1276,   786,   274,   275,   276,   277,   278,   279,   969,   970,
     971,   280,   281,   282,   975,   976,   977,   283,   450,   284,
     285,   719,   286,   452,   453,   454,   464,   776,   777,   287,
    1239,   288,  1728,  1729,   289,   290,   291,   552,   292,   293,
     294,   295,   296,   779,   297,   298,   535,   299,   300,   301,
     302,   303,   304,   655,   305,   306,   870,   871,   307,   308,
     309,   565,   311,   656,   667,  1144,  1145,   312,   657,   313,
     659,   566,   315,   316,   771,   772,  1395,   471,   317,   472,
     473,   911,  1396,  1397,  1398,   660,   661,  1138,  1139,  1567,
     662,  1135,  1136,  1381,  1382,  1383,  1384,   318,   799,   800,
     319,  1291,  1292,  1505,   320,  1294,  1295,   321,   322,  1297,
    1298,  1299,  1300,  1512,   323,   324,   325,   326,   327,   328,
     329,  1405,   330,   331,   332,   333,   334,   335,   336,   337,
     338,  1183,   339,   340,   341,   342,   676,   343,   344,   345,
     346,   347,   348,   349,   350,   351,   352,   353,   354,   355,
     356,   357,   358,   359,   360,   711,   705,   361,   362,   363,
     364,   365,   366,   367,   368,   369,   370,   946,   371,   372,
     373,   374,   375,   376,  1328,   833,   834,   835,  1759,  1804,
    1805,  1798,  1799,  1806,  1800,  1329,  1330,   377,   378,  1331,
     379,   380,   381,   382,   383,   384,   385,   386,  1031,  1513,
    1447,  1170,  1610,  1171,  1184,   387,   388,   389,   390,   391,
     392,   393,   394,   395,   396,   397,   398,   806,  1252,   399,
    1173,  1174,  1175,  1176,   400,   401,   402,   403,   404,   405,
     860,   861,   406,  1365,  1366,  1689,  1120,  1151,  1415,  1416,
    1152,  1153,  1154,  1155,  1156,  1425,  1600,  1601,  1157,  1428,
    1158,  1581,  1159,  1160,  1433,  1434,  1606,  1604,  1417,  1418,
    1419,  1420,  1708,   748,   996,   997,   998,   999,  1000,  1001,
    1228,  1630,  1725,  1229,  1628,  1723,  1002,  1461,  1625,  1621,
    1622,  1623,  1003,  1004,  1421,  1429,  1591,  1422,  1587,  1406,
     407,   408,   409,   410,   555,   411,   412,   413,   414,   415,
    1177,  1178,  1179,  1180,  1277,   416,   417,   418
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const short int jsoniq_parser::yytable_ninf_ = -885;
  const short int
  jsoniq_parser::yytable_[] =
  {
       310,   613,   932,   451,   532,   310,   310,   310,   310,   919,
     423,   426,   427,   658,   699,   594,   891,   893,   532,   603,
     314,   425,   425,   425,   429,   314,   314,   314,   314,   720,
     720,  1083,   723,  1045,   920,   921,   922,   923,  1029,   580,
    1149,   532,   631,  1281,  1119,  1516,  1057,  1293,   634,   615,
    1528,  1030,   941,   532,   600,   532,  1169,  1182,  1327,   632,
    1071,  1562,  1563,   636,   623,   624,   531,   783,   787,   424,
     424,   424,   428,  1401,   632,   639,   885,   889,   892,   894,
    1661,  1241,  1200,  1665,    11,    12,   883,   887,   985,  1602,
     986,  1172,  1172,  1257,   595,  1265,  1025,  1141,   595,   838,
     956,  1731,  1536,  1407,   436,  1588,   821,  1205,  1283,   632,
     310,  1320,   632,   632,   722,   722,   632,  1112,  1506,  1506,
     632,   638,   632,   663,   632,   762,   553,  1506,   632,  1054,
     314,  1802,   439,   641,   987,  1172,   604,   632,  1757,  1231,
    1769,   605,   951,   763,  1232,   762,   774,   821,  1089,   632,
    1619,    11,    12,  1233,  1259,  1026,  1027,  1027,   709,   886,
    1234,  1270,  1235,   763,   632,   698,   643,   628,   582,  1240,
     754,  1236,  1378,  1658,   424,  1335,  1408,  1336,  1588,  1430,
    1431,   643,  1662,   629,   632,   455,   469,   664,   127,  1172,
     632,  1126,   665,   703,  1380,   710,  1172,  1659,  1237,   784,
      11,    12,  1432,  1726,  1507,  1651,  1090,   639,  1266,  1028,
    1055,   639,  1732,  1656,  1620,   775,   642,   646,  1814,   643,
     436,   647,   952,  1208,   822,   606,   648,  1323,  1758,  1324,
     437,   432,   433,   821,   434,   435,   853,   637,  1803,   666,
    1690,   632,   470,   632,   643,   649,   782,   785,   439,  1113,
    1663,   700,   438,   440,   310,   310,   643,  1325,   310,   632,
    1142,   891,   893,  1409,  1410,   658,  1411,   839,   764,  1589,
    1590,   643,  1149,  1149,   314,   314,  1516,  1269,   314,  1317,
    1496,   532,  1509,  1413,   532,   441,   442,  1130,   638,   988,
    1724,   643,  1327,   310,  1733,  1414,  1267,   643,  1438,   633,
    1143,  1327,   989,   635,   990,  1536,   878,  1263,  1372,  1268,
     880,  1791,  1127,   314,  1129,   991,   992,   993,  1371,   994,
     632,   995,  1241,  1284,   831,  1479,  1172,  1453,  1201,  1580,
    1238,   883,   887,  -171,   632,   639,  1037,   470,   470,  1438,
     632,   982,  1589,   706,   650,   470,   708,   651,   643,   755,
     643,  1059,   583,  1320,  1321,  1819,   444,   756,  1827,   951,
    1830,  1262,   652,  1102,   730,   532,   643,  1172,   532,  1488,
    1020,  1060,   532,  1022,   873,   532,   532,  1116,   820,   632,
     632,  1026,   738,   532,   739,  1389,  1042,  1034,   653,   532,
     532,   874,   728,  1378,   564,   568,  1756,   532,   820,  1091,
    1491,  1202,  1054,   709,   532,   532,   532,   532,   729,  1783,
    1240,   430,   532,  1202,   884,   888,   879,   881,   632,   445,
     532,  1026,  1165,  1166,  1167,   310,   896,   643,  1313,   310,
    1314,   632,   877,   709,   904,  1172,  1066,   654,   703,   953,
     710,   643,   847,  1403,   741,   314,  1315,   643,  1322,   314,
    1021,   855,   458,  1023,  -172,   632,   310,  1092,   310,  1172,
     446,   632,   532,  1821,  1663,   447,   127,  1035,   703,  1323,
     710,  1324,   429,   448,   429,  1056,   314,   532,   314,   632,
     310,   449,   632,  1073,   851,   310,   643,   643,   532,  1068,
     470,  1469,   632,   852,   431,  1225,   429,    13,   470,  1325,
     314,   429,  1812,   113,  1327,   314,   742,  1449,   891,   893,
     891,  1320,  1226,  1101,  1150,  1093,  1067,   913,  -171,   125,
     759,   595,   761,  1481,  1352,   643,  1191,  1765,  1149,  1701,
     595,  1802,  1097,   617,   619,   532,  1407,  1149,   643,  1119,
    1326,   632,   532,  1557,   802,  1489,  1454,  1466,  1149,   808,
    1194,  1026,   459,   310,  1548,   646,  1227,   632,   152,   647,
    1516,   310,   643,  1609,   648,  1458,  1766,  1767,   643,  1069,
    1373,  1374,  1375,   314,  1320,  1321,   640,   425,    82,  1209,
    1210,   314,  1459,   649,  1213,  1084,   643,   632,   632,   643,
      13,  1367,   646,    93,   532,   484,   647,   732,  1172,   643,
    1044,   648,  1318,   829,   935,   936,  1192,   632,  1702,  1408,
     713,  1191,   310,  1715,  1249,   872,  1188,   451,   107,   463,
     649,   714,   310,   632,   632,   424,  1460,  1323,   867,  1324,
     733,  1568,   314,   310,   310,   310,   310,   532,  1836,  -172,
     465,  1720,   314,  1094,  1095,  1019,  1742,  1368,   643,   639,
    1026,  1085,   310,   314,   314,   314,   314,  1325,  1096,  1124,
    1098,  1099,   958,  1049,   643,   532,  1065,   909,  1319,  1322,
    1128,    82,   314,   485,   881,  1100,  1086,  1172,  1131,   532,
    1172,  1027,   650,   532,   532,   651,    93,   157,   158,   159,
    1323,  1193,  1324,  1716,   643,   643,  1409,  1410,  1458,  1411,
     830,  1796,   532,   474,  1388,  1320,  1412,  1110,   640,  1583,
     532,   107,   640,   532,   643,  1146,  1413,   532,  1147,   650,
    1325,  1721,   651,  1149,   113,  1087,   653,  1669,  1414,  1688,
     643,   643,  1673,  1480,   462,  1026,  -261,  1554,   127,   679,
     125,  1088,  1595,   767,   486,   487,  1150,  1150,   780,  1584,
    1027,  1640,   891,   738,  1509,   739,   680,   477,   793,  1460,
     532,  1530,   972,   653,  1444,   804,   805,   478,  1251,  1796,
    1254,  1118,  1187,  1320,   811,   654,  1634,   482,   310,   152,
     157,   158,   159,  1036,  1070,  1368,   595,  1748,   740,  1585,
     688,  1578,  1801,  1807,   425,  1445,  1586,   532,   314,   479,
    -261,    13,  1639,   682,   689,  -261,   973,  1813,  1817,   310,
     310,   974,   654,  1446,  1305,   741,  1306,  1340,   699,  1341,
     679,  1323,  1172,  1324,  1148,   429,   429,   483,   532,   314,
     314,  1797,   679,   683,  1801,  1026,   640,   680,   532,   488,
    1807,  1776,   424,  1777,   856,  1750,   684,  1565,  1225,   680,
    1391,  1325,  -261,   836,   837,  1392,   532,   532,   532,   532,
     681,   614,  1106,  -262,   841,  1226,  1754,   310,  1760,  1659,
     709,   489,  1763,  1063,  1064,  1494,  1172,   742,  1172,   451,
     685,   490,    82,   570,  1566,  1320,  1321,   314,   709,  1323,
    1659,  1324,   886,  1027,   866,   868,   310,    93,  1361,  1833,
     532,   534,   466,   896,  1391,   703,  1818,   710,  1172,  1392,
     881,   467,   491,  1826,   532,   492,   314,  1703,  1704,  1325,
    1290,   533,   107,   703,  1125,   710,  1146,  -262,  1393,  1147,
    1320,  1321,  -262,  1503,  1700,  1369,  1730,  1659,   468,   532,
     629,  1172,   536,  1847,   537,   679,  1705,  1027,   532,   127,
     532,  1705,   532,  1706,   532,  1172,  1195,  1172,  1706,  1809,
    1353,   532,   680,  1707,  1848,  1219,  1377,  1659,  1707,  1394,
     724,   549,  1196,  1197,  1199,  1784,  1220,  1378,  1558,  -262,
    1322,   934,  1452,   726,   725,  1774,   937,  1379,  1659,  1198,
     778,   157,   158,   159,   532,   686,   532,   727,   778,  1380,
    1290,  1323,  1150,  1324,   687,  1221,  1514,    11,    12,  1391,
    1517,  1150,   550,  1508,  1392,  1514,  1222,   432,   433,  1515,
     434,   435,  1150,  1518,  1243,  1322,   551,   436,  1668,  1772,
    1773,  1325,  1514,  1244,   548,   113,   571,   437,   438,   595,
    1730,  1214,  1215,  1216,   581,  1839,  1323,  1217,  1324,   895,
     572,   125,   584,   897,   556,   439,  1492,   569,   577,   752,
     440,   310,   658,   938,   753,   532,   938,   578,   973,   573,
     938,   576,  1535,   974,   579,   704,  1325,   429,   707,   456,
     113,   314,   457,   460,   585,   475,   461,  1730,   476,   607,
     152,   532,   441,   442,   443,  1647,   125,   480,   701,   702,
     481,   608,  1816,  -616,   744,   745,   746,  1078,  1079,  1080,
     609,   868,   556,  1211,  1212,   451,  1362,  1671,   610,   670,
     671,   672,   673,   674,   675,  1301,   611,   310,   310,   310,
    1559,  1560,   532,   924,   925,   152,  1363,   917,   918,   926,
     927,   612,   444,   625,  1464,  1465,   668,   314,   314,   314,
    1117,  1717,  1718,   645,   669,   677,   678,   690,   691,  1858,
     692,  1859,   693,   697,   703,  1691,   715,   712,   722,   716,
     717,  1867,   718,   734,   736,   613,   737,   751,   747,   760,
     778,   781,   789,   790,   532,   791,   792,   803,   532,   809,
     810,   457,   816,   820,   461,   476,   481,  1150,   492,   818,
     532,   823,   824,   825,   826,   445,   828,   832,   840,   842,
     456,   843,   844,   858,   532,   460,   869,   475,   863,   480,
     491,   864,  1190,   859,   532,   959,   960,   961,   962,   963,
     964,   965,   966,   967,   968,   876,   882,   900,   901,   902,
     907,   908,   903,   910,   915,   929,   446,   928,   930,   931,
     310,   948,   957,   954,   532,  1473,   955,   979,   980,   983,
     947,   984,  1006,  1005,  1007,  1009,   425,  1014,  1011,  1015,
     314,  1016,   447,  1017,   310,  1018,  1024,  1040,  1033,  1050,
     448,  1039,   532,  1043,  1061,   310,  1051,  1052,   449,  1653,
    1499,  1053,   532,  1058,   314,  1062,   532,  1105,  1126,  1114,
    1115,   425,  1133,  1111,   310,   314,  1137,   974,  1108,  1521,
    1203,  1122,  1026,  1223,   424,  1224,  1247,  1248,  1258,  1250,
     425,  1242,   532,  1260,   314,   310,  1264,   774,  1275,  1272,
    1279,  1273,   310,  1274,  1280,  1286,   904,  1278,  1309,  1289,
    1285,   429,  1290,  1296,  1302,   314,  1303,  1304,   429,   424,
    1308,  1311,   314,  1312,  1316,  1332,  1333,  1334,  1347,  1354,
     740,  1364,  1385,   532,  1387,  1390,  1404,  1362,   424,  1424,
    1435,  1436,  1439,  1427,    13,  1423,  1440,  1441,  1442,  1456,
    1457,   731,  1443,   867,   735,  1448,  1462,  1363,   743,  1533,
    1468,   749,   750,  1474,  1467,   532,  1537,  1471,  1472,   758,
    1484,  1476,  1486,  1475,  1495,   770,   773,  1490,  1498,  1527,
    1520,  1477,  1514,   788,  1478,  1522,  1529,  1523,  1532,  1544,
     796,   797,   798,   801,  1551,  1550,  1740,  1538,   807,  1400,
    1546,  1540,  1552,  1541,  1539,  1542,   814,  1744,  1653,   532,
    1746,   554,   532,  1545,  1553,   532,  1367,  1543,  1755,  1378,
    1571,  1572,  1573,  1577,  1582,  1579,  1592,  1598,   532,  1605,
    1603,  1599,  1618,   532,  1611,  1612,  1613,  1614,  1624,  1615,
    1629,  1631,  1616,  1617,  1627,  1635,  1644,  1637,   815,  1642,
    1645,  1646,  1649,  1680,  1693,  1650,  1655,  1713,  1667,  1666,
    1672,  1675,  1699,   801,  1711,  1722,  1712,  1633,  1714,   599,
     532,   532,  1225,  1727,   827,   556,  1735,   310,  1738,  1745,
    1762,  1565,  1771,  1778,  1779,  1780,  1781,  1782,  1786,  1787,
    1792,  1793,  1794,  1734,  1811,  1815,  1824,   314,  1831,  1832,
    1835,  1844,  1849,   626,  1808,  1810,  1746,  1455,  1857,  1825,
    1864,  1838,   556,  1863,  1861,  1860,  1850,   981,   630,  1206,
     627,   862,  1470,  1271,  1362,  1854,  1822,  1842,   773,  1851,
    1789,  1856,  1820,   721,  1866,   757,  1399,  1048,  1121,  1697,
    1561,  1576,  1569,  1376,  1363,  1828,  1564,   817,  1500,  1510,
    1504,   912,   916,   621,   914,  1186,  1519,   532,   532,   940,
     532,  1531,   532,  1492,  1082,  1837,   950,   696,  1834,   532,
     765,   766,  1549,  1255,  1556,  1555,  1596,  1593,  1845,  1597,
     773,  1710,  1402,  1230,  1709,  1463,  1426,  1626,  1719,  1594,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1845,     0,     0,     0,     0,     0,     0,     0,     0,  1828,
       0,   532,     0,   532,  1362,     0,     0,     0,     0,     0,
       0,     0,     0,   942,     0,  1362,  1362,     0,   310,   532,
       0,     0,   532,     0,  1363,     0,  1362,     0,     0,     0,
       0,     0,     0,   532,     0,  1363,  1363,     0,   314,     0,
       0,   978,     0,     0,   532,     0,  1363,     0,     0,     0,
       0,     0,     0,     0,     0,  1008,     0,     0,     0,  1012,
    1013,     0,     0,     0,     0,     0,   532,     0,     0,     0,
       0,     0,     0,     0,   532,     0,     0,     0,  1032,     0,
     532,     0,   532,     0,     0,     0,  1038,     0,     0,  1041,
       0,     0,     0,  1046,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   532,     0,     0,     0,     0,     0,     0,
       0,     0,   532,     0,  1362,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1076,     0,     0,     0,     0,
       0,     0,   532,     0,  1363,     0,  1081,   532,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   532,
       0,     0,   532,   310,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1362,     0,   314,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   310,     0,     0,     0,
       0,  1363,     0,     0,  1685,  1686,  1687,     0,     0,     0,
       0,     0,     0,     0,  1132,     0,   314,     0,  1362,     0,
       0,     0,     0,     0,  1140,     0,     0,  1362,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1363,     0,
       0,     0,  1181,  1181,  1185,  1185,     0,  1363,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   554,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1181,     0,     0,     0,
       0,     0,   845,   846,     0,     0,     0,   848,   849,   850,
    1218,     0,   854,     0,     0,   857,     0,     0,     0,     0,
       0,   865,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   875,     0,     0,     0,  1246,     0,     0,     0,     0,
       0,     0,     0,     0,  1253,     0,  1253,     0,   773,     0,
    1181,  1768,     0,     0,   898,   899,     0,  1181,     0,     0,
       0,     0,     0,   905,   906,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1775,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     807,     0,   807,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   945,     0,     0,     0,   945,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1386,     0,     0,  1010,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1181,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1047,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1072,  1181,     0,
       0,  1074,  1075,     0,  1077,     0,     0,     0,     0,     0,
       0,   905,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1103,  1104,     0,     0,  1107,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     773,     0,     0,     0,  1482,     0,     0,  1123,     0,     0,
       0,     0,     0,     0,     0,     0,  1181,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   899,     0,     0,
     801,     0,     0,  1134,     0,     0,     0,     0,     0,     0,
    1181,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1534,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   862,     0,
       0,     0,     0,     0,     0,  1207,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1575,     0,
    1245,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1261,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1282,     0,     0,     0,  1181,
       0,     0,     0,     0,     0,     0,  1287,  1288,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1307,     0,     0,  1310,     0,     0,     0,     0,     0,
       0,  1632,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1337,  1338,  1339,     0,  1342,
    1343,  1344,  1345,  1346,     0,     0,  1348,  1349,     0,  1350,
    1351,     0,     0,     0,  1355,  1356,     0,     0,     0,     0,
       0,     0,     0,  1370,     0,  1657,     0,     0,  1181,     0,
       0,  1181,     0,     0,  1134,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1670,     0,     0,     0,     0,  1674,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1695,  1696,     0,     0,
       0,     0,  1451,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1483,     0,  1485,     0,  1487,     0,     0,
       0,     0,     0,  1181,  1749,  1493,  1751,     0,  1753,     0,
       0,     0,     0,     0,  1497,  1761,     0,     0,     0,     0,
    1501,  1502,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1524,
       0,     0,  1525,  1526,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1181,     0,  1181,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1785,     0,     0,  1788,     0,
       0,     0,     0,  1547,     0,     0,     0,     0,     0,  1181,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1795,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1134,     0,     0,  1570,
       0,     0,  1181,     0,  1574,     0,     0,     0,     0,     0,
    1823,     0,     0,     0,     0,     0,  1181,     0,  1181,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1840,
       0,     0,     0,     0,     0,     0,     0,     0,  1843,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1852,     0,
       0,     0,     0,  1853,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1862,     0,     0,  1865,     0,
       0,  1636,     0,     0,     0,  1638,     0,     0,     0,  1641,
       0,  1643,     0,     0,     0,     0,     0,     0,     0,  1648,
       0,     0,     0,     0,     0,     0,     0,  1652,  1654,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1493,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1676,  1677,  1678,  1679,     0,  1681,  1682,     0,  1683,
       0,  1684,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1692,     0,     0,
       0,     0,  1694,     0,     0,     0,     0,     0,  1698,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1736,     0,
    1737,     0,     0,  1739,     0,     0,  1741,     0,     0,     0,
       0,  1743,  1654,     0,     0,     0,     0,     0,     0,  1747,
       0,     0,     0,     0,  1752,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1764,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1770,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1790,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1747,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1829,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  -167,   886,     0,
       0,     0,     0,  1841,     0,     0,     0,  1846,     1,     2,
       0,     0,  1829,     3,     0,     0,     0,     4,     5,     6,
       7,     8,     9,    10,    11,    12,     0,    13,  1846,     0,
      14,   420,  1855,    16,    17,    18,    19,    20,    21,    22,
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
     248,   249,   250,     0,   251,  -167,   886,   252,   253,     0,
       0,     0,     0,     0,     0,     0,     1,     2,     0,     0,
       0,     3,     0,     0,     0,     4,     5,     6,     7,     8,
       9,    10,    11,    12,     0,    13,     0,     0,   890,   420,
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
       4,     5,     6,     7,     8,     9,    10,    11,    12,     0,
      13,     0,     0,   419,   420,     0,    16,    17,    18,    19,
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
       0,     0,   131,     0,   132,   133,     0,   135,   136,     0,
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
     250,     0,   251,     0,     0,   252,   253,  -883,   462,     0,
    -261,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  -883,
       0,     0,     0,  -883,     0,     0,     0,  -883,  -883,     0,
       0,     0,     0,  -883,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  -261,     0,     0,  -883,     0,  -261,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    -883,     0,  -883,  -883,  -883,     0,     0,  -883,  -883,  -883,
    -883,     0,     0,     0,  -883,  -883,     0,     0,     0,     0,
       0,  -883,     0,     0,  -883,  -883,  -261,     0,     0,     0,
    -883,     0,     0,     0,     0,  -883,  -883,     0,     0,     0,
       0,     0,     0,     0,     0,  -883,     0,     0,     0,     0,
       0,     0,     0,     0,  -883,  -883,     0,     0,     0,  -883,
       0,     0,     0,  -883,     0,  -883,     0,  -883,  -883,     0,
       0,     0,     0,     0,     0,  -883,  -883,     0,     0,  -883,
       0,     0,     0,     0,  -883,     0,  -884,   614,     0,  -262,
       0,     0,  -883,  -883,  -883,  -883,  -883,     0,  -883,  -883,
    -883,  -883,  -883,     0,     0,     0,     0,  -883,  -883,  -883,
       0,  -883,  -883,  -883,  -883,  -883,  -883,     0,  -883,     0,
    -883,     0,     0,     0,     0,     0,  -883,     0,  -884,     0,
    -883,  -883,  -884,     0,     0,     0,  -884,  -884,     0,     0,
       0,     0,  -884,     0,     0,  -883,     0,  -883,     0,  -883,
       0,     0,     0,  -262,     0,     0,  -884,     0,  -262,     0,
       0,  -883,     0,     0,     0,     0,  -883,     0,     0,  -883,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  -884,
       0,  -884,  -884,  -884,     0,     0,  -884,  -884,  -884,  -884,
       0,     0,     0,  -884,  -884,     0,     0,     0,     0,     0,
    -884,     0,     0,  -884,  -884,  -262,     0,     0,     0,  -884,
       0,     0,     0,     0,  -884,  -884,     0,     0,     0,     0,
       0,     0,     0,  -883,  -884,  -883,     0,     0,     0,     0,
       0,     0,     0,  -884,  -884,     0,     0,     0,  -884,     0,
       0,     0,  -884,     0,  -884,     0,  -884,  -884,     0,     0,
       0,     0,     0,     0,  -884,  -884,     0,     0,  -884,     0,
       0,     0,     0,  -884,     0,     0,     0,     0,     0,     0,
       0,  -884,  -884,  -884,  -884,  -884,     0,  -884,  -884,  -884,
    -884,  -884,     0,     0,     0,     0,  -884,  -884,  -884,     0,
    -884,  -884,  -884,  -884,  -884,  -884,     0,  -884,     0,  -884,
       0,     0,     0,     0,     0,  -884,     0,     0,     0,  -884,
    -884,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  -884,     0,  -884,     0,  -884,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    -884,     0,     0,     0,     0,  -884,     0,     0,  -884,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     1,     2,     0,     0,     0,     3,
       0,     0,     0,     4,     5,     6,     7,     8,     9,    10,
      11,    12,  -884,    13,  -884,     0,    14,    15,     0,    16,
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
     147,   148,   149,     0,     0,   150,   151,   152,     0,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,     0,   200,   201,   202,
       0,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,     0,
     251,     0,     0,   252,   253,     0,     1,     2,     0,   254,
     255,     3,     0,     0,     0,     4,     5,     6,     7,     8,
       9,    10,    11,    12,     0,    13,     0,     0,    14,    15,
       0,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
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
       0,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,     0,   200,
     201,   202,     0,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,     0,   251,     0,     0,   252,   253,     0,     1,     2,
       0,     0,   622,     3,     0,     0,     0,     4,     5,     6,
       7,     8,     9,    10,    11,    12,     0,    13,     0,     0,
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
     109,     0,   110,   111,     0,   112,   113,   114,   115,   116,
       0,     0,     0,   117,   118,   119,   120,   121,   122,   123,
     124,     0,   125,     0,   126,   127,     0,     0,   128,   129,
     130,     0,     0,     0,   131,     0,   132,   133,   134,   135,
     136,     0,   137,     0,   138,     0,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,     0,     0,   150,
     151,   152,     0,   153,   154,   155,   156,   157,   158,   159,
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
      26,    27,    28,   421,    30,    31,    32,    33,    34,     0,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,     0,    48,    49,    50,    51,    52,    53,
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
       0,   126,   127,     0,     0,   128,   129,   130,     0,   819,
       0,   131,     0,   132,   133,   134,   135,   136,     0,   137,
       0,   138,     0,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,     0,     0,   150,   151,   152,     0,
     422,     0,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,     0,   200,   201,
     202,     0,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
       0,   251,     1,     2,   252,   253,     0,     3,     0,     0,
       0,     4,     5,     6,     7,     8,     9,    10,    11,    12,
       0,    13,     0,     0,   419,   420,     0,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
     421,    30,    31,    32,    33,    34,     0,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
       0,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,     0,    72,    73,    74,    75,
      76,     0,    77,    78,    79,     0,     0,    80,    81,     0,
       0,     0,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,     0,    92,     0,     0,     0,    93,     0,    94,
      95,    96,    97,     0,    98,     0,     0,     0,    99,   100,
     101,   102,   103,     0,     0,     0,     0,     0,     0,   104,
     105,   106,   107,   108,   109,     0,   110,   111,     0,   112,
     113,   114,   115,   116,     0,     0,     0,   117,   118,   119,
     120,   121,   122,   123,   124,     0,   125,     0,   126,   127,
       0,     0,   128,   129,   130,     0,     0,     0,   131,     0,
     132,   133,   134,   135,   136,     0,   137,     0,   138,     0,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,     0,     0,   150,   151,   152,     0,   422,     0,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,     0,   200,   201,   202,     0,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,     0,   251,     1,
       2,   252,   253,     0,     3,     0,     0,     0,     4,     5,
       6,     7,     8,     9,    10,    11,    12,     0,    13,     0,
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
     150,   151,   152,     0,   422,     0,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,     0,   200,   201,   202,     0,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,     0,   251,     1,     2,   252,   253,
       0,     3,     0,     0,     0,     4,     5,     6,     7,     8,
       9,    10,    11,    12,     0,    13,     0,     0,    14,   420,
       0,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
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
     250,     0,   251,     1,     2,   252,   253,     0,     3,     0,
       0,     0,     4,     5,     6,     7,     8,     9,    10,    11,
      12,     0,    13,     0,     0,   890,   420,     0,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,   421,    30,    31,    32,    33,    34,     0,    35,    36,
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
       1,     2,   252,   253,     0,     3,     0,     0,     0,     4,
       5,     6,     7,     8,     9,    10,    11,    12,     0,    13,
       0,     0,   419,   420,     0,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,  1357,   421,    30,
      31,    32,    33,    34,     0,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,     0,    48,
      49,    50,  1358,  1359,    53,    54,    55,    56,    57,    58,
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
     128,   129,   130,     0,     0,     0,   131,     0,   132,   133,
     134,   135,   136,     0,   137,     0,   138,     0,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,     0,
       0,   150,   151,   152,     0,   422,     0,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,  1360,   187,
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
       0,     0,   943,     0,   104,   105,   106,   107,   108,   109,
       0,   561,   111,     0,   112,   113,   114,   115,   116,     0,
       0,     0,   117,   118,   119,   120,   121,   122,   123,   124,
       0,   125,     0,   126,   127,     0,     0,   128,   129,   130,
       0,     0,     0,   131,   944,   132,   133,     0,   135,   136,
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
      99,   100,   101,   102,   103,     0,     0,     0,     0,   943,
       0,   104,   105,   106,   107,   108,   109,     0,   561,   111,
       0,   112,   113,   114,   115,   116,     0,     0,     0,   117,
     118,   119,   120,   121,   122,   123,   124,     0,   125,     0,
     126,   127,     0,     0,   128,   129,   130,     0,     0,     0,
     131,   949,   132,   133,     0,   135,   136,     0,   137,     0,
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
       0,   128,   129,   130,     0,     0,   562,   131,     0,   132,
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
     510,    85,    86,    87,    88,    89,   560,    91,     0,    92,
       0,     0,     0,    93,     0,    94,    95,    96,    97,     0,
      98,     0,     0,     0,    99,   100,   101,   102,   103,     0,
       0,     0,     0,     0,     0,   104,   105,   106,   107,   108,
     109,     0,   561,   111,     0,   112,   113,   114,   115,   116,
       0,     0,     0,   117,   118,   119,   120,   121,   122,   123,
     124,     0,   125,     0,   126,   127,     0,     0,   128,   129,
     130,     0,     0,     0,   131,   567,   132,   133,     0,   135,
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
     111,     0,   112,   113,   114,   115,   116,     0,     0,     0,
     117,   118,   119,   120,   121,   122,   123,   124,     0,   125,
       0,   126,   127,     0,     0,   128,   129,   130,     0,     0,
       0,   131,     0,   132,   133,     0,   135,   136,     0,   137,
       0,   138,     0,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,     0,     0,   150,   151,   152,     0,
     422,     0,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   596,   168,   597,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   524,   525,   526,
     183,   184,   527,   563,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,     0,   200,   201,
     202,     0,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
       0,   251,     0,   598,   252,   253,     1,     2,     0,     0,
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
       0,     0,   131,     0,   132,   133,     0,   135,   136,     0,
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
     250,   616,   251,     1,     2,   252,   253,     0,     3,     0,
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
       0,   132,   133,     0,   135,   136,     0,   137,     0,   138,
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
     618,     0,   252,   253,     1,     2,     0,     0,     0,     3,
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
      99,   100,   101,   102,   103,     0,     0,     0,     0,     0,
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
     251,     0,   620,   252,   253,     1,     2,     0,     0,     0,
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
     111,     0,   112,   113,   114,   115,   116,     0,     0,     0,
     117,   118,   119,   120,   121,   122,   123,   124,     0,   125,
       0,   126,   127,     0,     0,   128,   129,   130,     0,   933,
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
     101,   102,   103,     0,     0,     0,     0,     0,     0,   104,
     105,   106,   107,   108,   109,     0,   561,   111,     0,   112,
     113,   114,   115,   116,     0,     0,     0,   117,   118,   119,
     120,   121,   122,   123,   124,     0,   125,     0,   126,   127,
       0,     0,   128,   129,   130,     0,     0,     0,   131,  1189,
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
       0,     0,     0,     0,  1450,     0,   104,   105,   106,   107,
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
       0,     0,   131,     0,   132,   133,     0,   135,   136,     0,
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
       0,   113,   114,   115,   116,     0,     0,     0,   117,   118,
     119,   120,   121,   122,   123,   124,     0,   125,     0,   126,
     127,     0,     0,   128,   129,   130,     0,     0,     0,   131,
       0,   132,   133,     0,   135,   136,     0,   137,     0,   138,
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
      21,    22,    23,    24,    25,   496,    27,   498,   421,    30,
     499,    32,    33,    34,     0,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,   501,     0,    48,
      49,    50,   503,   504,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,     0,    72,    73,    74,    75,    76,     0,
      77,    78,    79,     0,     0,    80,    81,     0,     0,     0,
      82,    83,   510,    85,    86,    87,    88,    89,   560,    91,
       0,    92,     0,     0,     0,    93,     0,    94,    95,    96,
      97,     0,    98,     0,     0,     0,   513,   100,   101,   102,
     103,     0,     0,     0,     0,     0,     0,   104,   105,   106,
     107,   108,   109,     0,   561,   111,     0,   112,   113,   694,
     115,   116,     0,     0,     0,   117,   118,   119,   120,   121,
     122,   123,   124,     0,   125,     0,   695,   127,     0,     0,
     128,   129,   130,     0,     0,     0,   131,     0,   132,   133,
       0,   135,   136,     0,   137,     0,   138,     0,   139,   140,
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
     504,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
       0,    72,    73,    74,    75,    76,     0,    77,    78,    79,
       0,     0,    80,    81,     0,     0,     0,    82,    83,   510,
      85,    86,    87,    88,    89,   560,    91,     0,    92,     0,
       0,     0,    93,     0,    94,    95,    96,    97,     0,    98,
       0,     0,     0,   513,   100,   101,   102,   103,     0,     0,
       0,     0,     0,     0,   104,   105,   106,   107,   108,   109,
       0,   561,   111,     0,   112,   113,   114,   115,   116,     0,
       0,     0,   117,   118,   119,   120,   121,   122,   123,   124,
       0,   125,     0,   126,   127,     0,     0,   128,   129,   130,
       0,     0,     0,   131,     0,   132,   133,     0,   135,   136,
       0,   137,     0,   138,     0,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,     0,     0,   150,   151,
     152,     0,   422,     0,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,     0,   167,     0,   169,     0,
       0,   172,   173,   174,   175,   176,   177,   523,   179,   524,
     525,   526,   183,   184,   527,   528,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   529,     0,
     200,   201,   202,     0,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,     0,   251,     1,     2,     0,   253,     0,     3,
       0,     0,     0,     4,     5,     6,     7,     8,     9,    10,
       0,     0,     0,    13,     0,     0,   419,   420,     0,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,   496,
      27,   498,   421,    30,   499,    32,    33,    34,     0,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,   501,     0,    48,    49,    50,   503,   504,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,     0,    72,    73,
      74,    75,    76,     0,    77,    78,    79,     0,     0,    80,
      81,     0,     0,     0,    82,    83,   510,    85,    86,    87,
      88,    89,   560,    91,     0,    92,     0,     0,     0,    93,
       0,    94,    95,    96,    97,     0,    98,     0,     0,     0,
     513,   100,   101,   102,   103,     0,     0,     0,     0,     0,
       0,   104,   105,   106,   107,   108,   109,     0,   561,   111,
       0,   112,   113,   114,   115,   116,     0,     0,     0,   117,
     118,   119,   120,   121,   122,   123,   124,     0,   125,     0,
     126,   127,     0,     0,   128,   129,   130,     0,     0,     0,
     131,     0,   132,   133,     0,   135,   136,     0,   137,     0,
     138,     0,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,     0,     0,   150,   151,   152,     0,   422,
       0,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,     0,   167,     0,   169,     0,     0,   172,   173,
     174,   175,   176,   177,   523,   179,   524,   525,   526,   183,
     184,   527,   528,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   529,     0,   200,   530,   202,
       0,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,     0,
     251,     1,     2,     0,   253,     0,     3,     0,     0,     0,
       4,     5,     6,     7,     8,     9,    10,     0,     0,     0,
      13,     0,     0,   419,   420,     0,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,   496,    27,   498,   421,
      30,   499,    32,    33,    34,     0,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,   501,     0,
      48,    49,    50,   503,   504,    53,   505,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,     0,    72,    73,    74,    75,    76,
       0,    77,    78,    79,     0,     0,    80,    81,     0,     0,
       0,    82,    83,   510,    85,    86,    87,    88,    89,   560,
      91,     0,    92,     0,     0,     0,    93,     0,    94,    95,
      96,    97,     0,    98,     0,     0,     0,   513,   100,   101,
     102,   103,     0,     0,     0,     0,     0,     0,   104,   105,
     106,   107,   108,   109,     0,   561,   111,     0,   112,   113,
       0,   115,   116,     0,     0,     0,   117,   118,   119,   120,
     121,   122,   123,   124,     0,   125,     0,     0,     0,     0,
       0,   128,   129,   130,     0,     0,     0,   131,     0,   132,
     133,     0,   135,   136,     0,   137,     0,   138,     0,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
       0,     0,   150,   151,   152,     0,   422,     0,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,     0,
     167,     0,   169,     0,     0,   172,   173,   174,   175,   176,
     177,   523,   179,   524,   525,   526,   183,   184,   527,   528,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   529,     0,   200,   530,   202,     0,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,     0,   251,     1,     2,
       0,   253,     0,     3,     0,     0,     0,     4,     5,     6,
       7,     8,     9,    10,     0,     0,     0,    13,     0,     0,
     419,   420,     0,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,   496,    27,   498,   421,    30,   499,    32,
      33,    34,     0,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,   501,     0,    48,    49,    50,
     503,   504,    53,   505,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,     0,    72,    73,    74,    75,    76,     0,    77,    78,
      79,     0,     0,    80,    81,     0,     0,     0,    82,    83,
     510,    85,    86,    87,    88,    89,   560,    91,     0,    92,
       0,     0,     0,    93,     0,    94,    95,    96,    97,     0,
      98,     0,     0,     0,   513,   100,   101,   102,   103,     0,
       0,     0,     0,     0,     0,   104,   105,   106,   107,   108,
     109,     0,   561,   111,     0,   112,   113,     0,   115,   116,
       0,     0,     0,   117,   118,   119,   120,   121,   122,   123,
     124,     0,   125,     0,     0,     0,     0,     0,   128,   129,
     130,     0,     0,     0,   131,     0,   132,   133,     0,     0,
       0,     0,   137,     0,   138,     0,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,     0,     0,   150,
     151,   152,     0,   422,     0,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,     0,   167,     0,   169,
       0,     0,   172,   173,   174,   175,   176,   177,   523,   179,
     524,   525,   526,   183,   184,   527,   528,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   529,
       0,   200,   530,   202,     0,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,     0,   251,     1,     2,     0,   253,     0,
       3,     0,     0,     0,     4,     5,     6,     7,     8,     9,
      10,     0,     0,     0,    13,     0,     0,   419,   420,     0,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
     496,    27,   498,   421,    30,   499,    32,    33,    34,     0,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,   501,     0,    48,    49,    50,   503,   504,    53,
     505,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,     0,    72,
      73,    74,    75,    76,     0,    77,    78,    79,     0,     0,
      80,    81,     0,     0,     0,    82,    83,   510,    85,    86,
      87,    88,    89,   560,    91,     0,    92,     0,     0,     0,
      93,     0,    94,    95,    96,    97,     0,    98,     0,     0,
       0,   513,     0,   101,   102,   103,     0,     0,     0,     0,
       0,     0,   104,   105,   106,   107,     0,   109,     0,   561,
     111,     0,   112,   113,     0,   115,   116,     0,     0,     0,
     117,   118,   119,   120,   121,   122,   123,   124,     0,   125,
       0,     0,     0,     0,     0,   128,   129,   130,     0,     0,
       0,   131,     0,   132,   133,     0,     0,     0,     0,   137,
       0,   138,     0,   139,     0,   141,     0,   143,   144,   145,
     146,   147,   148,   149,     0,     0,   150,   151,   152,     0,
     422,     0,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,     0,   167,     0,   169,     0,     0,   172,
     173,   174,   175,   176,   177,   523,   179,   524,   525,   526,
     183,   184,   527,   528,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   529,     0,   200,   530,
     202,     0,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
       0,   251,     1,     2,     0,   253,     0,     3,     0,     0,
       0,     4,     5,     6,     7,     8,     9,    10,     0,     0,
       0,    13,     0,     0,   419,   420,     0,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,   557,
     421,     0,    31,    32,    33,    34,     0,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
       0,    48,    49,    50,   558,   559,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,     0,     0,    72,    73,    74,    75,
      76,     0,    77,     0,     0,     0,     0,    80,    81,     0,
       0,     0,    82,    83,   510,    85,    86,    87,    88,     0,
     560,    91,     0,    92,     0,     0,     0,    93,     0,    94,
      95,    96,    97,     0,    98,     0,     0,     0,    99,     0,
     101,   102,   103,     0,     0,     0,     0,     0,     0,     0,
     105,   106,   107,     0,   109,     0,   561,     0,     0,  -616,
     113,     0,     0,   116,     0,     0,     0,   117,   118,   119,
     120,   121,   122,   123,   124,     0,   125,     0,     0,   127,
       0,     0,   128,   129,   130,     0,     0,     0,   131,     0,
     132,   133,     0,     0,     0,     0,     0,     0,   138,     0,
     139,     0,   141,     0,   143,   144,   145,   146,   147,   148,
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
      22,    23,    24,    25,    26,    27,   557,   421,     0,    31,
      32,    33,    34,     0,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,     0,    48,    49,
      50,   558,   559,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,     0,     0,    72,    73,    74,    75,    76,     0,    77,
       0,     0,     0,     0,    80,    81,     0,     0,     0,    82,
      83,   510,    85,    86,    87,    88,     0,   560,    91,     0,
      92,     0,     0,     0,    93,     0,    94,    95,    96,    97,
       0,    98,     0,     0,     0,    99,     0,   101,   102,   103,
       0,     0,     0,     0,     0,     0,     0,   105,   106,   107,
       0,   109,     0,   561,     0,     0,     0,   113,     0,     0,
     116,     0,     0,     0,   117,   118,   119,   120,   121,   122,
     123,   124,     0,   125,     0,     0,   127,     0,     0,   128,
     129,   130,     0,     0,     0,   131,     0,   132,   133,     0,
       0,     0,     0,     0,     0,   138,     0,   139,     0,   141,
       0,   143,   144,   145,   146,   147,   148,   149,     0,     0,
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
      25,   496,    27,   498,   421,    30,   499,    32,    33,    34,
       0,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,   501,     0,    48,    49,    50,   503,   504,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,     0,
      72,    73,    74,    75,    76,     0,    77,    78,    79,     0,
       0,    80,    81,     0,     0,     0,    82,    83,   510,    85,
      86,    87,    88,     0,   560,    91,     0,    92,     0,     0,
       0,    93,     0,    94,    95,    96,    97,     0,    98,     0,
       0,     0,   513,     0,   101,   102,   103,     0,     0,     0,
       0,     0,     0,     0,   105,   106,   107,     0,   109,     0,
     561,     0,     0,     0,   113,     0,     0,   116,     0,     0,
       0,   117,   118,   119,   120,   121,   122,   123,   124,     0,
     125,     0,     0,   127,     0,     0,   128,   129,   130,     0,
       0,     0,   131,     0,   132,   133,     0,     0,     0,     0,
       0,     0,   138,     0,   139,     0,   141,     0,   143,   144,
     145,   146,   147,   148,   149,     0,     0,   150,   151,   152,
       0,   422,     0,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,     0,   167,     0,   169,     0,     0,
     172,   173,   174,   175,   176,   177,   523,   179,   524,   525,
     526,   183,   184,   527,   528,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   529,     0,   200,
     201,   202,     0,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,     0,   251,     1,     2,     0,   253,     0,     3,     0,
       0,     0,     4,     0,     0,     0,     0,     9,    10,     0,
       0,     0,     0,     0,     0,   419,   420,     0,    16,    17,
      18,   493,    20,    21,    22,   494,    24,   495,   496,   497,
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
     104,   105,   106,     0,   108,   109,     0,     0,     0,     0,
       0,     0,     0,   115,   516,     0,     0,     0,   117,   118,
     119,   120,   517,   122,   123,   518,     0,     0,     0,     0,
       0,     0,     0,   519,   520,   130,     0,     0,     0,   131,
       0,   132,   521,     0,     0,     0,     0,   137,     0,   138,
       0,   139,   140,   141,   142,   522,   144,   145,   146,   147,
     148,   149,     0,     0,   150,   151,     0,     0,   422,     0,
     155,   156,     0,     0,     0,   160,   161,   162,   163,   164,
     165,     0,   167,     0,   169,     0,     0,   172,   173,   174,
     175,   176,   177,   523,   179,   524,   525,   526,   183,   184,
     527,   528,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   529,     0,   200,   530,   202,     0,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,     1,     2,     0,
       0,     0,     3,   253,     0,     0,     4,     0,     0,     0,
       0,     9,    10,     0,     0,     0,     0,     0,     0,   419,
     420,     0,    16,    17,    18,   538,    20,    21,    22,   494,
     539,   540,   496,   497,   498,   421,    30,   499,    32,   541,
      34,     0,    35,    36,    37,    38,   542,    40,   543,   544,
      43,    44,    45,    46,   501,     0,    48,   545,    50,   503,
     504,    53,   505,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,   506,   507,    71,
       0,    72,    73,    74,   546,     0,     0,    77,    78,    79,
       0,     0,   509,    81,     0,     0,     0,     0,    83,   510,
      85,   511,   512,    88,    89,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    94,    95,    96,    97,     0,    98,
       0,     0,     0,   513,   100,   101,   514,   515,     0,     0,
       0,     0,     0,     0,   104,   105,   106,     0,   108,   109,
       0,     0,     0,     0,     0,     0,     0,   115,   516,     0,
       0,     0,   117,   118,   119,   120,   517,   122,   123,   518,
       0,     0,     0,     0,     0,     0,     0,   519,   520,   130,
       0,     0,     0,   131,     0,   132,   521,     0,     0,     0,
       0,   137,     0,   138,     0,   139,   140,   141,   142,   522,
     144,   145,   146,   147,   148,   149,     0,     0,   150,   151,
       0,     0,   422,     0,   155,   156,     0,     0,     0,   160,
     161,   162,   163,   164,   165,     0,   547,     0,   169,     0,
       0,   172,   173,   174,   175,   176,   177,   523,   179,   524,
     525,   526,   183,   184,   527,   528,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   529,     0,
     200,   530,   202,     0,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,     3,     0,     0,     0,     0,     0,   253,     0,     0,
       9,    10,     0,     0,     0,     0,     0,     0,   419,   420,
       0,    16,    17,    18,   493,    20,    21,    22,   494,    24,
     495,   496,  1161,   498,   421,    30,   499,    32,    33,    34,
       0,    35,    36,    37,    38,   500,    40,    41,    42,    43,
      44,    45,    46,   501,     0,    48,   502,    50,   503,   504,
      53,   505,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,   506,   507,    71,     0,
      72,    73,    74,   508,     0,     0,    77,    78,    79,     0,
       0,   509,    81,     0,     0,     0,     0,    83,   510,    85,
     511,   512,    88,    89,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    94,    95,    96,    97,     0,    98,     0,
       0,     0,   513,   100,   101,   514,   515,     0,     0,     0,
       0,     0,     0,   104,   105,   106,     0,   108,   109,  1162,
       0,     0,     0,  1163,     0,     0,   115,   516,     0,     0,
       0,   117,   118,   119,   120,   517,   122,   123,   518,     0,
       0,     0,     0,     0,     0,     0,   519,   520,   130,     0,
       0,     0,   131,  1607,   132,   521,     0,     0,     0,     0,
    1608,     0,   138,     0,   139,   140,   141,   142,   522,   144,
     145,   146,   147,   148,   149,     0,     0,  1164,   151,     0,
       0,   422,     0,   155,   156,     0,     0,     0,   160,   161,
     162,   163,   164,   165,     0,   167,     0,   169,     0,     0,
     172,   173,   174,   175,   176,   177,   523,   179,   524,   525,
     526,   183,   184,   527,   528,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   529,     0,   200,
     530,   202,     0,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
       0,     0,     3,     0,     0,     0,   253,  1165,  1166,  1167,
    1168,     9,    10,     0,     0,     0,     0,     0,     0,   419,
     420,     0,    16,    17,    18,   493,    20,    21,    22,   494,
      24,   495,   496,  1161,   498,   421,    30,   499,    32,    33,
      34,     0,    35,    36,    37,    38,   500,    40,    41,    42,
      43,    44,    45,    46,   501,     0,    48,   502,    50,   503,
     504,    53,   505,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,   506,   507,    71,
       0,    72,    73,    74,   508,     0,     0,    77,    78,    79,
       0,     0,   509,    81,     0,     0,     0,     0,    83,   510,
      85,   511,   512,    88,    89,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    94,    95,    96,    97,     0,    98,
       0,     0,     0,   513,   100,   101,   514,   515,     0,     0,
       0,     0,     0,     0,   104,   105,   106,     0,   108,   109,
    1162,     0,     0,     0,  1204,     0,     0,   115,   516,     0,
       0,     0,   117,   118,   119,   120,   517,   122,   123,   518,
       0,     0,     0,     0,     0,     0,     0,   519,   520,   130,
       0,     0,     0,   131,  1437,   132,   521,     0,     0,     0,
       0,     0,     0,   138,     0,   139,   140,   141,   142,   522,
     144,   145,   146,   147,   148,   149,     0,     0,   150,   151,
       0,     0,   422,     0,   155,   156,     0,     0,     0,   160,
     161,   162,   163,   164,   165,     0,   167,     0,   169,     0,
       0,   172,   173,   174,   175,   176,   177,   523,   179,   524,
     525,   526,   183,   184,   527,   528,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   529,     0,
     200,   530,   202,     0,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,     0,     0,     3,     0,     0,     0,   253,  1165,  1166,
    1167,  1168,     9,    10,     0,     0,     0,     0,     0,     0,
     419,   420,     0,    16,    17,    18,   493,    20,    21,    22,
     494,    24,   495,   496,  1161,   498,   421,    30,   499,    32,
      33,    34,     0,    35,    36,    37,    38,   500,    40,    41,
      42,    43,    44,    45,    46,   501,     0,    48,   502,    50,
     503,   504,    53,   505,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,   506,   507,
      71,     0,    72,    73,    74,   508,     0,     0,    77,    78,
      79,     0,     0,   509,    81,     0,     0,     0,     0,    83,
     510,    85,   511,   512,    88,    89,  1511,     0,     0,     0,
       0,     0,     0,     0,     0,    94,    95,    96,    97,     0,
      98,     0,     0,     0,   513,   100,   101,   514,   515,     0,
       0,     0,     0,     0,     0,   104,   105,   106,     0,   108,
     109,  1162,     0,     0,     0,  1163,     0,     0,   115,   516,
       0,     0,     0,   117,   118,   119,   120,   517,   122,   123,
     518,     0,     0,     0,     0,     0,     0,     0,   519,   520,
     130,     0,     0,     0,   131,     0,   132,   521,     0,     0,
       0,     0,     0,     0,   138,     0,   139,   140,   141,   142,
     522,   144,   145,   146,   147,   148,   149,     0,     0,  1164,
     151,     0,     0,   422,     0,   155,   156,     0,     0,     0,
     160,   161,   162,   163,   164,   165,     0,   167,     0,   169,
       0,     0,   172,   173,   174,   175,   176,   177,   523,   179,
     524,   525,   526,   183,   184,   527,   528,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   529,
       0,   200,   530,   202,     0,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,     0,     0,     3,     0,     0,     0,   253,  1165,
    1166,  1167,  1168,     9,    10,     0,     0,     0,     0,     0,
       0,   419,   420,     0,    16,    17,    18,   493,    20,    21,
      22,   494,    24,   495,   496,  1161,   498,   421,    30,   499,
      32,    33,    34,     0,    35,    36,    37,    38,   500,    40,
      41,    42,    43,    44,    45,    46,   501,     0,    48,   502,
      50,   503,   504,    53,   505,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,   506,
     507,    71,     0,    72,    73,    74,   508,     0,     0,    77,
      78,    79,     0,     0,   509,    81,     0,     0,     0,     0,
      83,   510,    85,   511,   512,    88,    89,  1660,     0,     0,
       0,     0,     0,     0,     0,     0,    94,    95,    96,    97,
       0,    98,     0,     0,     0,   513,   100,   101,   514,   515,
       0,     0,     0,     0,     0,     0,   104,   105,   106,     0,
     108,   109,  1162,     0,     0,     0,  1163,     0,     0,   115,
     516,     0,     0,     0,   117,   118,   119,   120,   517,   122,
     123,   518,     0,     0,     0,     0,     0,     0,     0,   519,
     520,   130,     0,     0,     0,   131,     0,   132,   521,     0,
       0,     0,     0,     0,     0,   138,     0,   139,   140,   141,
     142,   522,   144,   145,   146,   147,   148,   149,     0,     0,
    1164,   151,     0,     0,   422,     0,   155,   156,     0,     0,
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
    1165,  1166,  1167,  1168,     9,    10,     0,     0,     0,     0,
       0,     0,   419,   420,     0,    16,    17,    18,   493,    20,
      21,    22,   494,    24,   495,   496,  1161,   498,   421,    30,
     499,    32,    33,    34,     0,    35,    36,    37,    38,   500,
      40,    41,    42,    43,    44,    45,    46,   501,     0,    48,
     502,    50,   503,   504,    53,   505,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
     506,   507,    71,     0,    72,    73,    74,   508,     0,     0,
      77,    78,    79,     0,     0,   509,    81,     0,     0,     0,
       0,    83,   510,    85,   511,   512,    88,    89,  1664,     0,
       0,     0,     0,     0,     0,     0,     0,    94,    95,    96,
      97,     0,    98,     0,     0,     0,   513,   100,   101,   514,
     515,     0,     0,     0,     0,     0,     0,   104,   105,   106,
       0,   108,   109,  1162,     0,     0,     0,  1163,     0,     0,
     115,   516,     0,     0,     0,   117,   118,   119,   120,   517,
     122,   123,   518,     0,     0,     0,     0,     0,     0,     0,
     519,   520,   130,     0,     0,     0,   131,     0,   132,   521,
       0,     0,     0,     0,     0,     0,   138,     0,   139,   140,
     141,   142,   522,   144,   145,   146,   147,   148,   149,     0,
       0,  1164,   151,     0,     0,   422,     0,   155,   156,     0,
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
     253,  1165,  1166,  1167,  1168,     9,    10,     0,     0,     0,
       0,     0,     0,   419,   420,     0,    16,    17,    18,   493,
      20,    21,    22,   494,    24,   495,   496,  1161,   498,   421,
      30,   499,    32,    33,    34,     0,    35,    36,    37,    38,
     500,    40,    41,    42,    43,    44,    45,    46,   501,     0,
      48,   502,    50,   503,   504,    53,   505,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,   506,   507,    71,     0,    72,    73,    74,   508,     0,
       0,    77,    78,    79,     0,     0,   509,    81,     0,     0,
       0,     0,    83,   510,    85,   511,   512,    88,    89,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    94,    95,
      96,    97,     0,    98,     0,     0,     0,   513,   100,   101,
     514,   515,     0,     0,     0,     0,     0,     0,   104,   105,
     106,     0,   108,   109,  1162,     0,     0,     0,  1163,     0,
       0,   115,   516,     0,     0,     0,   117,   118,   119,   120,
     517,   122,   123,   518,     0,     0,     0,     0,     0,     0,
       0,   519,   520,   130,     0,     0,     0,   131,     0,   132,
     521,     0,     0,     0,     0,     0,     0,   138,     0,   139,
     140,   141,   142,   522,   144,   145,   146,   147,   148,   149,
       0,     0,  1164,   151,     0,     0,   422,     0,   155,   156,
       0,     0,     0,   160,   161,   162,   163,   164,   165,     0,
     167,     0,   169,     0,     0,   172,   173,   174,   175,   176,
     177,   523,   179,   524,   525,   526,   183,   184,   527,   528,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   529,     0,   200,   530,   202,     0,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,     0,     0,     3,     0,     0,
       0,   253,  1165,  1166,  1167,  1168,     9,    10,     0,     0,
       0,     0,     0,     0,   419,   420,     0,    16,    17,    18,
     493,    20,    21,    22,   494,    24,   495,   496,  1161,   498,
     421,    30,   499,    32,    33,    34,     0,    35,    36,    37,
      38,   500,    40,    41,    42,    43,    44,    45,    46,   501,
       0,    48,   502,    50,   503,   504,    53,   505,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,   506,   507,    71,     0,    72,    73,    74,   508,
       0,     0,    77,    78,    79,     0,     0,   509,    81,     0,
       0,     0,     0,    83,   510,    85,   511,   512,    88,    89,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    94,
      95,    96,    97,     0,    98,     0,     0,     0,   513,   100,
     101,   514,   515,     0,     0,     0,     0,     0,     0,   104,
     105,   106,     0,   108,   109,  1162,     0,     0,     0,  1204,
       0,     0,   115,   516,     0,     0,     0,   117,   118,   119,
     120,   517,   122,   123,   518,     0,     0,     0,     0,     0,
       0,     0,   519,   520,   130,     0,     0,     0,   131,     0,
     132,   521,     0,     0,     0,     0,     0,     0,   138,     0,
     139,   140,   141,   142,   522,   144,   145,   146,   147,   148,
     149,     0,     0,   150,   151,     0,     0,   422,     0,   155,
     156,     0,     0,     0,   160,   161,   162,   163,   164,   165,
       0,   167,     0,   169,     0,     0,   172,   173,   174,   175,
     176,   177,   523,   179,   524,   525,   526,   183,   184,   527,
     528,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   529,     0,   200,   530,   202,     0,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,     0,     0,     3,     0,
       0,     0,   253,  1165,  1166,  1167,  1168,     9,    10,     0,
       0,     0,    13,     0,     0,   419,   420,     0,    16,    17,
      18,   538,    20,    21,    22,   494,   539,   540,   496,   497,
     498,   421,    30,   499,    32,   541,    34,     0,    35,    36,
      37,    38,   542,    40,   543,   544,    43,    44,    45,    46,
     501,     0,    48,   545,    50,   503,   504,    53,   505,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,   506,   507,    71,     0,    72,    73,    74,
     546,     0,     0,    77,    78,    79,     0,     0,   509,    81,
       0,     0,     0,     0,    83,   510,    85,   511,   512,    88,
      89,   560,     0,     0,     0,     0,     0,     0,     0,     0,
      94,    95,    96,    97,     0,    98,     0,     0,     0,   513,
     100,   101,   514,   515,     0,     0,     0,     0,     0,     0,
     104,   105,   106,     0,   108,   109,     0,     0,     0,     0,
     939,     0,     0,   115,   516,     0,     0,     0,   117,   118,
     119,   120,   517,   122,   123,   518,     0,     0,     0,     0,
       0,     0,     0,   519,   520,   130,     0,     0,     0,   131,
       0,   132,   521,     0,     0,     0,     0,     0,     0,   138,
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
     243,   244,   245,   246,   247,   248,   249,     3,     0,   574,
     575,     0,     0,   253,     0,     0,     9,    10,     0,     0,
       0,     0,     0,     0,   419,   420,     0,    16,    17,    18,
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
       0,     0,   519,   520,   130,     0,     0,     0,   131,     0,
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
       0,   519,   520,   130,     0,     0,     0,   131,   768,   132,
     521,     0,     0,     0,     0,   769,     0,   138,     0,   139,
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
       0,   253,     0,     0,     9,    10,     0,     0,     0,   794,
       0,     0,   419,   420,     0,    16,    17,    18,   538,    20,
      21,    22,   494,   539,   540,   496,   497,   498,   421,    30,
     499,    32,   541,    34,     0,    35,    36,    37,    38,   542,
      40,   543,   544,    43,    44,    45,    46,   501,     0,    48,
     545,    50,   503,   504,    53,   505,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
     506,   507,    71,     0,    72,    73,    74,   546,     0,     0,
      77,    78,    79,     0,     0,   509,    81,     0,     0,     0,
       0,    83,   510,    85,   511,   512,    88,    89,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    94,    95,    96,
      97,     0,    98,     0,     0,     0,   513,   100,   101,   514,
     515,     0,     0,     0,     0,     0,     0,   104,   105,   106,
       0,   108,   109,     0,     0,     0,     0,     0,     0,     0,
     115,   516,     0,     0,     0,   117,   118,   119,   120,   517,
     122,   123,   518,     0,     0,     0,     0,     0,     0,     0,
     519,   520,   130,     0,     0,     0,   131,   795,   132,   521,
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
     520,   130,     0,     0,     0,   131,   812,   132,   521,     0,
       0,     0,     0,   813,     0,   138,     0,   139,   140,   141,
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
     419,   420,     0,    16,    17,    18,   538,    20,    21,    22,
     494,   539,   540,   496,   497,   498,   421,    30,   499,    32,
     541,    34,     0,    35,    36,    37,    38,   542,    40,   543,
     544,    43,    44,    45,    46,   501,     0,    48,   545,    50,
     503,   504,    53,   505,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,   506,   507,
      71,     0,    72,    73,    74,   546,     0,     0,    77,    78,
      79,     0,     0,   509,    81,     0,     0,     0,     0,    83,
     510,    85,   511,   512,    88,    89,  1256,     0,     0,     0,
       0,     0,     0,     0,     0,    94,    95,    96,    97,     0,
      98,     0,     0,     0,   513,   100,   101,   514,   515,     0,
       0,     0,     0,     0,     0,   104,   105,   106,     0,   108,
     109,     0,     0,     0,     0,     0,     0,     0,   115,   516,
       0,     0,     0,   117,   118,   119,   120,   517,   122,   123,
     518,     0,     0,     0,     0,     0,     0,     0,   519,   520,
     130,     0,     0,     0,   131,     0,   132,   521,     0,     0,
       0,     0,     0,     0,   138,     0,   139,   140,   141,   142,
     522,   144,   145,   146,   147,   148,   149,     0,     0,   150,
     151,     0,     0,   422,     0,   155,   156,     0,     0,     0,
     160,   161,   162,   163,   164,   165,     0,   547,     0,   169,
       0,     0,   172,   173,   174,   175,   176,   177,   523,   179,
     524,   525,   526,   183,   184,   527,   528,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   529,
       0,   200,   530,   202,     0,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,     3,     0,     0,     0,     0,     0,   253,     0,
       0,     9,    10,     0,     0,     0,     0,     0,     0,   419,
     420,     0,    16,    17,    18,   538,    20,    21,    22,   494,
     539,   540,   496,   497,   498,   421,    30,   499,    32,   541,
      34,     0,    35,    36,    37,    38,   542,    40,   543,   544,
      43,    44,    45,    46,   501,     0,    48,   545,    50,   503,
     504,    53,   505,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,   506,   507,    71,
       0,    72,    73,    74,   546,     0,     0,    77,    78,    79,
       0,     0,   509,    81,     0,     0,     0,     0,    83,   510,
      85,   511,   512,    88,    89,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    94,    95,    96,    97,     0,    98,
       0,     0,     0,   513,   100,   101,   514,   515,     0,     0,
       0,     0,     0,     0,   104,   105,   106,     0,   108,   109,
       0,     0,     0,     0,     0,     0,     0,   115,   516,     0,
       0,     0,   117,   118,   119,   120,   517,   122,   123,   518,
       0,     0,     0,     0,     0,     0,     0,   519,   520,   130,
       0,     0,     0,   131,     0,   132,   521,     0,     0,     0,
       0,     0,     0,   138,     0,   139,   140,   141,   142,   522,
     144,   145,   146,   147,   148,   149,     0,     0,   150,   151,
       0,     0,   422,     0,   155,   156,     0,     0,     0,   160,
     161,   162,   163,   164,   165,     0,   547,     0,   169,     0,
       0,   172,   173,   174,   175,   176,   177,   523,   179,   524,
     525,   526,   183,   184,   527,   528,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   529,     0,
     200,   530,   202,     0,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,     5,     6,     7,     8,     9,    10,   253,     0,     0,
      13,     0,     0,   419,   420,     0,    16,    17,    18,   586,
      20,    21,    22,    23,     0,   587,   496,    27,     0,   421,
      30,   499,    32,     0,    34,     0,    35,    36,    37,    38,
     588,    40,     0,     0,    43,    44,    45,    46,   501,     0,
      48,   589,    50,     0,     0,    53,   505,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,   506,   507,    71,     0,    72,    73,    74,   590,     0,
       0,    77,    78,    79,     0,     0,   509,    81,     0,     0,
       0,    82,    83,   510,    85,   511,   512,    88,    89,   560,
      91,     0,     0,     0,     0,     0,    93,     0,    94,    95,
      96,    97,     0,    98,     0,     0,     0,   513,   100,   101,
     514,   515,     0,     0,     0,     0,     0,     0,   104,   105,
     106,   107,   108,   109,     0,   561,   111,     0,   112,   113,
       0,   115,   116,     0,     0,     0,   117,   118,   119,   120,
     121,   122,   123,   518,     0,   125,     0,     0,     0,     0,
       0,   519,   520,   130,     0,     0,     0,   131,     0,   132,
     521,     0,     0,     0,     0,     0,     0,   138,     0,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
       0,     0,     0,   151,   152,     0,   422,     0,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,     0,
     591,     0,   592,     0,     0,   172,   173,   174,   175,   176,
     177,   523,   179,   524,   525,   526,   183,   184,     0,   528,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   529,     0,   200,   530,   202,     0,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,     0,   251,     0,   593,
       0,   253,     5,     6,     7,     8,     9,    10,     0,     0,
       0,    13,     0,     0,   419,   420,     0,    16,    17,    18,
     586,    20,    21,    22,    23,     0,   587,   496,    27,     0,
     421,    30,   499,    32,     0,    34,     0,    35,    36,    37,
      38,   588,    40,     0,     0,    43,    44,    45,    46,   501,
       0,    48,   589,    50,     0,     0,    53,   505,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,   506,   507,    71,     0,    72,    73,    74,   590,
       0,     0,    77,    78,    79,     0,     0,   509,    81,     0,
       0,     0,    82,    83,   510,    85,   511,   512,    88,    89,
     560,    91,     0,     0,     0,     0,     0,    93,     0,    94,
      95,    96,    97,     0,    98,     0,     0,     0,   513,   100,
     101,   514,   515,     0,     0,     0,     0,     0,     0,   104,
     105,   106,   107,   108,   109,     0,   561,   111,     0,   112,
     113,     0,   115,   116,     0,     0,     0,   117,   118,   119,
     120,   121,   122,   123,   518,     0,   125,     0,     0,     0,
       0,     0,   519,   520,   130,     0,     0,     0,   131,     0,
     132,   521,     0,     0,     0,     0,     0,     0,   138,     0,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,     0,     0,     0,   151,   152,     0,   422,     0,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
       0,   601,     0,   169,     0,     0,   172,   173,   174,   175,
     176,   177,   523,   179,   524,   525,   526,   183,   184,     0,
     528,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   529,     0,   200,   530,   202,     0,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,     0,   251,     0,
     602,     0,   253,     5,     6,     7,     8,     9,    10,     0,
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
     165,     0,  1109,     0,   169,     0,     0,   172,   173,   174,
     175,   176,   177,   523,   179,   524,   525,   526,   183,   184,
       0,   528,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   529,     0,   200,   530,   202,     0,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,     0,   251,
       0,     0,     0,   253,     5,     6,     7,     8,     9,    10,
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
     164,   165,     0,     0,     0,   169,     0,     0,   172,   173,
     174,   175,   176,   177,   523,   179,   524,   525,   526,   183,
     184,     0,   528,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   529,     0,   200,   530,   202,
       0,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,     0,
     251,     9,    10,     0,   253,     0,     0,     0,     0,   419,
     420,     0,    16,    17,    18,     0,    20,    21,    22,   494,
       0,     0,   496,   497,     0,   421,    30,   499,    32,     0,
      34,     0,    35,    36,    37,    38,     0,    40,     0,     0,
      43,    44,    45,    46,   501,     0,    48,     0,    50,     0,
       0,    53,   505,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,   506,   507,    71,
       0,    72,    73,    74,     0,     0,     0,    77,    78,    79,
       0,     0,   509,    81,     0,     0,     0,     0,    83,   510,
      85,   511,   512,    88,    89,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    94,    95,    96,    97,     0,    98,
       0,     0,     0,   513,   100,   101,   514,   515,     0,     0,
       0,     0,     0,     0,   104,   105,   106,     0,   108,   109,
       0,     0,     0,     0,     0,     0,     0,   115,   516,     0,
       0,     0,   117,   118,   119,   120,   517,   122,   123,   518,
       0,     0,     0,     0,     0,     0,     0,   519,   520,   130,
       0,     0,     0,   131,     0,   132,   521,     0,     0,     0,
       0,     0,     0,   138,     0,   139,   140,   141,   142,   522,
     144,   145,   146,   147,   148,   149,     0,     0,     0,   151,
       0,     0,   422,     0,   155,   156,     0,     0,     0,   160,
     161,   162,   163,   164,   165,     0,     0,     0,   169,     0,
       0,   172,   173,   174,   175,   176,   177,   523,   179,   524,
     525,   526,   183,   184,     0,   528,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   529,     0,
     200,   530,   202,     0,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,     0,     0,     0,     0,     0,     0,   253
  };

  /* YYCHECK.  */
  const short int
  jsoniq_parser::yycheck_[] =
  {
         0,   186,   697,    14,    76,     5,     6,     7,     8,   681,
       5,     6,     7,   314,   345,   166,   635,   636,    90,   170,
       0,     5,     6,     7,     8,     5,     6,     7,     8,   430,
     431,   833,   432,   788,   682,   683,   684,   685,   773,   136,
     915,   113,   261,  1043,   869,  1297,   801,  1059,   262,   201,
    1315,   773,   709,   125,   168,   127,   928,   929,  1085,     1,
     815,  1382,  1383,   277,   254,   255,    76,   467,   468,     5,
       6,     7,     8,  1147,     1,   293,   633,   634,   635,   636,
    1514,  1006,   956,  1517,    27,    28,   633,   634,    55,  1427,
      57,   928,   929,  1024,   166,    36,    36,    56,   170,     8,
     730,   119,  1328,    97,    47,    97,   108,   972,   144,     1,
     110,     9,     1,     1,    30,    30,     1,   108,   101,   101,
       1,   284,     1,     3,     1,    45,   110,   101,     1,   108,
     110,    29,    75,   108,   101,   972,   230,     1,    94,    39,
    1692,   235,   108,    63,    44,    45,   119,   108,   133,     1,
     138,    27,    28,    53,  1026,    95,    97,    97,   121,     1,
      60,  1033,    62,    63,     1,   155,   108,    33,    31,  1006,
     113,    71,   107,   187,   110,   237,   170,   239,    97,   252,
     253,   108,   119,    49,     1,   162,   119,    67,   178,  1026,
       1,    33,    72,   156,   129,   158,  1033,   211,    98,   114,
      27,    28,   275,  1629,   187,   187,   191,   425,   149,   149,
     189,   429,   230,   187,   202,   188,   191,    42,  1770,   108,
      47,    46,   188,   978,   185,   319,    51,   125,   184,   127,
      57,    37,    38,   108,    40,    41,   238,   113,   136,   119,
    1561,     1,   278,     1,   108,    70,   162,   162,    75,   240,
     187,   348,    58,    80,   254,   255,   108,   155,   258,     1,
     219,   880,   881,   257,   258,   566,   260,   176,   188,   261,
     262,   108,  1147,  1148,   254,   255,  1528,  1032,   258,  1081,
    1280,   353,  1294,   277,   356,   112,   113,   114,   451,   256,
    1628,   108,  1319,   293,   312,   289,  1031,   108,  1163,   191,
     259,  1328,   269,   191,   271,  1531,   191,  1029,   114,  1031,
     191,  1745,   191,   293,   191,   282,   283,   284,   191,   286,
       1,   288,  1247,  1045,   188,  1256,  1163,  1201,   958,  1403,
     230,   878,   879,     0,     1,   553,   188,   278,   278,  1204,
       1,   741,   261,   353,   169,   278,   356,   172,   108,   292,
     108,   188,   215,     9,    10,  1781,   162,   300,  1792,   108,
    1794,   149,   187,   238,   436,   437,   108,  1204,   440,   149,
     108,   188,   444,   108,   316,   447,   448,   188,   123,     1,
       1,    95,    45,   455,    47,  1140,   786,   108,   213,   461,
     462,   318,   167,   107,   111,   112,   119,   469,   123,   133,
    1272,   969,   108,   121,   476,   477,   478,   479,   183,  1730,
    1247,   158,   484,   981,   633,   634,   630,   631,     1,   225,
     492,    95,   322,   323,   324,   425,   640,   108,   188,   429,
     188,     1,   622,   121,   652,  1272,   108,   262,   156,   188,
     158,   108,   593,   155,   107,   425,   188,   108,   104,   429,
     188,   602,   155,   188,     0,     1,   456,   191,   458,  1296,
     266,     1,   534,  1784,   187,   292,   178,   188,   156,   125,
     158,   127,   456,   300,   458,   149,   456,   549,   458,     1,
     480,   308,     1,   189,   598,   485,   108,   108,   560,   108,
     278,  1246,     1,   238,   158,    97,   480,    30,   278,   155,
     480,   485,  1767,   159,  1531,   485,   169,   188,  1127,  1128,
    1129,     9,   114,   238,   915,    95,   188,   669,   185,   175,
     456,   593,   458,  1258,   242,   108,   108,   188,  1403,    52,
     602,    29,    95,   250,   251,   607,    97,  1412,   108,  1364,
     196,     1,   614,  1368,   480,  1267,  1203,  1242,  1423,   485,
     951,    95,   158,   553,   242,    42,   158,     1,   214,    46,
    1812,   561,   108,  1435,    51,    97,   188,   188,   108,   188,
    1127,  1128,  1129,   553,     9,    10,   293,   561,   111,   979,
     980,   561,   114,    70,   984,   132,   108,     1,     1,   108,
      30,   155,    42,   126,   666,    77,    46,   170,  1435,   108,
     144,    51,   132,   186,   701,   702,   188,     1,   131,   170,
     147,   108,   612,   108,  1014,   614,   186,   628,   151,   158,
      70,   158,   622,     1,     1,   561,   158,   125,   612,   127,
     203,  1386,   612,   633,   634,   635,   636,   709,   136,   185,
     158,   108,   622,   223,   224,   185,  1646,   211,   108,   867,
      95,   198,   652,   633,   634,   635,   636,   155,   238,   878,
     223,   224,   734,   185,   108,   737,   185,   666,   198,   104,
     884,   111,   652,   155,   888,   238,   185,  1514,   896,   751,
    1517,    97,   169,   755,   756,   172,   126,   220,   221,   222,
     125,   188,   127,   188,   108,   108,   257,   258,    97,   260,
     187,     5,   774,   158,   149,     9,   267,   858,   425,   219,
     782,   151,   429,   785,   108,   155,   277,   789,   158,   169,
     155,   188,   172,  1598,   159,   185,   213,  1529,   289,   155,
     108,   108,  1534,   149,     1,    95,     3,   187,   178,   160,
     175,   185,  1414,   460,   226,   227,  1147,  1148,   465,   259,
      97,  1486,  1371,    45,  1766,    47,   177,   158,   475,   158,
     832,   196,    95,   213,   146,   482,   483,   158,  1020,     5,
    1022,   185,   185,     9,   491,   262,  1471,   158,   778,   214,
     220,   221,   222,   778,   144,   211,   858,  1659,    80,   273,
     138,   185,  1757,  1758,   778,   177,   280,   869,   778,   119,
      67,    30,   149,   118,   152,    72,   139,   185,   185,   809,
     810,   144,   262,   195,  1066,   107,  1068,   237,  1149,   239,
     160,   125,  1659,   127,   264,   809,   810,   158,   900,   809,
     810,   135,   160,   148,  1799,    95,   553,   177,   910,   124,
    1805,  1713,   778,  1715,    95,   187,   161,   107,    97,   177,
      54,   155,   119,   570,   571,    59,   928,   929,   930,   931,
     200,     1,    95,     3,   581,   114,   187,   867,  1670,   211,
     121,   124,  1674,   809,   810,  1275,  1713,   169,  1715,   890,
     195,   124,   111,   155,   144,     9,    10,   867,   121,   125,
     211,   127,     1,    97,   611,   612,   896,   126,  1116,   135,
     972,   119,    25,  1117,    54,   156,  1778,   158,  1745,    59,
    1124,    34,   155,   187,   986,   158,   896,  1589,  1590,   155,
     101,   124,   151,   156,    33,   158,   155,    67,    78,   158,
       9,    10,    72,   114,  1582,  1120,  1631,   211,    61,  1011,
      49,  1778,   124,   187,   124,   160,   274,    97,  1020,   178,
    1022,   274,  1024,   281,  1026,  1792,   150,  1794,   281,  1761,
    1111,  1033,   177,   291,   187,   268,    96,   211,   291,   119,
     183,   119,   166,   150,   139,  1730,   279,   107,  1378,   119,
     104,   698,   139,   183,   197,   200,   703,   117,   211,   166,
     155,   220,   221,   222,  1066,   202,  1068,   197,   155,   129,
     101,   125,  1403,   127,   211,   268,   101,    27,    28,    54,
     101,  1412,   124,   114,    59,   101,   279,    37,    38,   114,
      40,    41,  1423,   114,   304,   104,   124,    47,   114,  1701,
    1702,   155,   101,   313,    90,   159,   155,    57,    58,  1111,
    1735,   282,   283,   284,   155,   114,   125,   288,   127,   637,
     124,   175,   218,   641,   110,    75,  1274,   113,   124,   139,
      80,  1061,  1363,   704,   144,  1137,   707,   124,   139,   125,
     711,   127,   196,   144,   124,   352,   155,  1061,   355,   155,
     159,  1061,   158,   155,   218,   155,   158,  1782,   158,   119,
     214,  1163,   112,   113,   114,  1495,   175,   155,   192,   193,
     158,   246,  1774,   158,   226,   227,   228,   824,   825,   826,
     246,   828,   168,   130,   131,  1126,  1116,   196,   247,   204,
     205,   206,   207,   208,   209,  1061,   158,  1127,  1128,  1129,
     130,   131,  1204,   686,   687,   214,  1116,   679,   680,   688,
     689,   155,   162,     0,  1240,  1241,   168,  1127,  1128,  1129,
     867,  1619,  1620,   191,    93,   254,   100,    50,   201,  1854,
     102,  1856,   103,   194,   156,  1565,   185,   158,    30,   185,
     185,  1866,   185,    47,   154,  1360,   119,   309,   251,   188,
     155,     1,   119,   144,  1256,   108,   188,   188,  1260,   155,
     155,   158,   144,   123,   158,   158,   158,  1598,   158,   185,
    1272,   123,   158,   158,   158,   225,   155,    35,    17,   215,
     155,    30,    30,   236,  1286,   155,   250,   155,   191,   155,
     155,   191,   939,   235,  1296,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,   238,     3,   119,   169,   171,
     289,   289,   171,   119,    71,    95,   266,   236,    95,    95,
    1250,   151,    30,   108,  1326,  1250,   108,   162,   162,   129,
     188,   134,    95,   251,   304,   144,  1250,   134,   119,   185,
    1250,   185,   292,   188,  1274,   188,   108,    45,    95,   188,
     300,    97,  1354,    97,   155,  1285,   188,   188,   308,  1507,
    1285,   188,  1364,   185,  1274,   185,  1368,    95,    33,   144,
     191,  1285,   171,   236,  1304,  1285,   119,   144,   242,  1304,
     134,   238,    95,    30,  1250,   291,    95,   304,   129,   155,
    1304,   232,  1394,   119,  1304,  1325,   149,   119,   134,    95,
     134,   185,  1332,   199,    97,   119,  1554,   162,   191,   149,
     155,  1325,   101,   101,   185,  1325,   185,   155,  1332,  1285,
     144,   123,  1332,   123,    35,   155,    30,    30,    97,   119,
      80,   250,   108,  1435,   108,   259,   290,  1367,  1304,   265,
     158,   158,   158,   272,    30,   263,   158,   158,   158,   291,
      30,   437,   158,  1367,   440,   146,    30,  1367,   444,  1325,
     311,   447,   448,   188,   292,  1467,  1332,   232,   191,   455,
     149,   146,   129,   188,   108,   461,   462,   149,   144,   199,
     185,   188,   101,   469,   188,   188,   134,   188,     7,    97,
     476,   477,   478,   479,   158,   187,  1644,   191,   484,  1146,
     242,   238,   158,   238,   191,   238,   492,  1655,  1656,  1511,
    1658,   110,  1514,   321,   158,  1517,   155,   238,  1666,   107,
     149,   119,   119,    78,   255,   188,   255,   149,  1530,    79,
     291,   287,    30,  1535,   188,   188,   188,   188,    30,   188,
     108,   171,   188,   188,   276,   185,   128,   149,   534,   149,
     128,    97,   185,   321,   144,   187,   187,    95,   185,   187,
     185,   185,   185,   549,   155,    30,   285,   262,   188,   168,
    1572,  1573,    97,   188,   560,   561,   171,  1507,   149,    95,
     198,   107,    54,    95,    30,   270,   108,   108,   119,   230,
      95,   187,    95,   292,   199,   119,   119,  1507,   187,    94,
     184,   119,   119,   258,   198,   198,  1754,  1205,   187,   230,
     119,   198,   598,   230,   292,   200,   298,   740,   261,   973,
     258,   607,  1247,  1034,  1554,   311,   310,   310,   614,   310,
    1735,   311,  1782,   431,   311,   451,  1145,   791,   870,  1575,
    1382,  1395,  1387,  1133,  1554,  1793,  1385,   549,  1286,  1294,
    1291,   668,   678,   252,   676,   931,  1299,  1659,  1660,   709,
    1662,  1319,  1664,  1811,   833,  1805,   714,   340,  1799,  1671,
     459,   459,  1354,  1022,  1365,  1364,  1416,  1412,  1826,  1423,
     666,  1598,  1148,  1005,  1595,  1227,  1157,  1461,  1622,  1413,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1848,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1857,
      -1,  1713,    -1,  1715,  1644,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   709,    -1,  1655,  1656,    -1,  1658,  1731,
      -1,    -1,  1734,    -1,  1644,    -1,  1666,    -1,    -1,    -1,
      -1,    -1,    -1,  1745,    -1,  1655,  1656,    -1,  1658,    -1,
      -1,   737,    -1,    -1,  1756,    -1,  1666,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   751,    -1,    -1,    -1,   755,
     756,    -1,    -1,    -1,    -1,    -1,  1778,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1786,    -1,    -1,    -1,   774,    -1,
    1792,    -1,  1794,    -1,    -1,    -1,   782,    -1,    -1,   785,
      -1,    -1,    -1,   789,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1815,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1824,    -1,  1754,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   821,    -1,    -1,    -1,    -1,
      -1,    -1,  1844,    -1,  1754,    -1,   832,  1849,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1861,
      -1,    -1,  1864,  1793,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1811,    -1,  1793,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1826,    -1,    -1,    -1,
      -1,  1811,    -1,    -1,  1551,  1552,  1553,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   900,    -1,  1826,    -1,  1848,    -1,
      -1,    -1,    -1,    -1,   910,    -1,    -1,  1857,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1848,    -1,
      -1,    -1,   928,   929,   930,   931,    -1,  1857,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   561,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   972,    -1,    -1,    -1,
      -1,    -1,   591,   592,    -1,    -1,    -1,   596,   597,   598,
     986,    -1,   601,    -1,    -1,   604,    -1,    -1,    -1,    -1,
      -1,   610,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   620,    -1,    -1,    -1,  1011,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1020,    -1,  1022,    -1,  1024,    -1,
    1026,  1688,    -1,    -1,   643,   644,    -1,  1033,    -1,    -1,
      -1,    -1,    -1,   652,   653,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1711,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1066,    -1,  1068,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   710,    -1,    -1,    -1,   714,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1137,    -1,    -1,   753,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1163,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   790,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   816,  1204,    -1,
      -1,   820,   821,    -1,   823,    -1,    -1,    -1,    -1,    -1,
      -1,   830,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   852,   853,    -1,    -1,   856,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1256,    -1,    -1,    -1,  1260,    -1,    -1,   876,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1272,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   896,    -1,    -1,
    1286,    -1,    -1,   902,    -1,    -1,    -1,    -1,    -1,    -1,
    1296,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1326,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1354,    -1,
      -1,    -1,    -1,    -1,    -1,   974,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1394,    -1,
    1009,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1028,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1044,    -1,    -1,    -1,  1435,
      -1,    -1,    -1,    -1,    -1,    -1,  1055,  1056,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1070,    -1,    -1,  1073,    -1,    -1,    -1,    -1,    -1,
      -1,  1467,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1094,  1095,  1096,    -1,  1098,
    1099,  1100,  1101,  1102,    -1,    -1,  1105,  1106,    -1,  1108,
    1109,    -1,    -1,    -1,  1113,  1114,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1122,    -1,  1511,    -1,    -1,  1514,    -1,
      -1,  1517,    -1,    -1,  1133,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1530,    -1,    -1,    -1,    -1,  1535,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1572,  1573,    -1,    -1,
      -1,    -1,  1191,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1262,    -1,  1264,    -1,  1266,    -1,    -1,
      -1,    -1,    -1,  1659,  1660,  1274,  1662,    -1,  1664,    -1,
      -1,    -1,    -1,    -1,  1283,  1671,    -1,    -1,    -1,    -1,
    1289,  1290,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1308,
      -1,    -1,  1311,  1312,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1713,    -1,  1715,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1731,    -1,    -1,  1734,    -1,
      -1,    -1,    -1,  1352,    -1,    -1,    -1,    -1,    -1,  1745,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1756,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1385,    -1,    -1,  1388,
      -1,    -1,  1778,    -1,  1393,    -1,    -1,    -1,    -1,    -1,
    1786,    -1,    -1,    -1,    -1,    -1,  1792,    -1,  1794,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1815,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1824,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1844,    -1,
      -1,    -1,    -1,  1849,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1861,    -1,    -1,  1864,    -1,
      -1,  1480,    -1,    -1,    -1,  1484,    -1,    -1,    -1,  1488,
      -1,  1490,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1498,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1506,  1507,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1527,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1540,  1541,  1542,  1543,    -1,  1545,  1546,    -1,  1548,
      -1,  1550,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1566,    -1,    -1,
      -1,    -1,  1571,    -1,    -1,    -1,    -1,    -1,  1577,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1637,    -1,
    1639,    -1,    -1,  1642,    -1,    -1,  1645,    -1,    -1,    -1,
      -1,  1650,  1651,    -1,    -1,    -1,    -1,    -1,    -1,  1658,
      -1,    -1,    -1,    -1,  1663,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1680,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1693,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1738,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1750,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1793,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     0,     1,    -1,
      -1,    -1,    -1,  1822,    -1,    -1,    -1,  1826,    11,    12,
      -1,    -1,  1831,    16,    -1,    -1,    -1,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    -1,    30,  1847,    -1,
      33,    34,  1851,    36,    37,    38,    39,    40,    41,    42,
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
     313,   314,   315,    -1,   317,     0,     1,   320,   321,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    11,    12,    -1,    -1,
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
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,    -1,   264,
     265,   266,    -1,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,    -1,   317,    -1,    -1,   320,   321,     0,     1,    -1,
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
      -1,    -1,    -1,    -1,    -1,   138,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   147,   148,    -1,    -1,    -1,   152,
      -1,    -1,    -1,   156,    -1,   158,    -1,   160,   161,    -1,
      -1,    -1,    -1,    -1,    -1,   168,   169,    -1,    -1,   172,
      -1,    -1,    -1,    -1,   177,    -1,     0,     1,    -1,     3,
      -1,    -1,   185,   186,   187,   188,   189,    -1,   191,   192,
     193,   194,   195,    -1,    -1,    -1,    -1,   200,   201,   202,
      -1,   204,   205,   206,   207,   208,   209,    -1,   211,    -1,
     213,    -1,    -1,    -1,    -1,    -1,   219,    -1,    42,    -1,
     223,   224,    46,    -1,    -1,    -1,    50,    51,    -1,    -1,
      -1,    -1,    56,    -1,    -1,   238,    -1,   240,    -1,   242,
      -1,    -1,    -1,    67,    -1,    -1,    70,    -1,    72,    -1,
      -1,   254,    -1,    -1,    -1,    -1,   259,    -1,    -1,   262,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    93,
      -1,    95,    96,    97,    -1,    -1,   100,   101,   102,   103,
      -1,    -1,    -1,   107,   108,    -1,    -1,    -1,    -1,    -1,
     114,    -1,    -1,   117,   118,   119,    -1,    -1,    -1,   123,
      -1,    -1,    -1,    -1,   128,   129,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   316,   138,   318,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   147,   148,    -1,    -1,    -1,   152,    -1,
      -1,    -1,   156,    -1,   158,    -1,   160,   161,    -1,    -1,
      -1,    -1,    -1,    -1,   168,   169,    -1,    -1,   172,    -1,
      -1,    -1,    -1,   177,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   185,   186,   187,   188,   189,    -1,   191,   192,   193,
     194,   195,    -1,    -1,    -1,    -1,   200,   201,   202,    -1,
     204,   205,   206,   207,   208,   209,    -1,   211,    -1,   213,
      -1,    -1,    -1,    -1,    -1,   219,    -1,    -1,    -1,   223,
     224,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   238,    -1,   240,    -1,   242,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     254,    -1,    -1,    -1,    -1,   259,    -1,    -1,   262,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    11,    12,    -1,    -1,    -1,    16,
      -1,    -1,    -1,    20,    21,    22,    23,    24,    25,    26,
      27,    28,   316,    30,   318,    -1,    33,    34,    -1,    36,
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
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   262,    -1,   264,   265,   266,
      -1,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,    -1,
     317,    -1,    -1,   320,   321,    -1,    11,    12,    -1,   326,
     327,    16,    -1,    -1,    -1,    20,    21,    22,    23,    24,
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
      -1,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,    -1,   264,
     265,   266,    -1,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,    -1,   317,    -1,    -1,   320,   321,    -1,    11,    12,
      -1,    -1,   327,    16,    -1,    -1,    -1,    20,    21,    22,
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
      -1,   177,   178,    -1,    -1,   181,   182,   183,    -1,   185,
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
     149,   150,   151,   152,   153,    -1,   155,   156,    -1,   158,
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
     309,   310,   311,   312,   313,   314,   315,    -1,   317,    11,
      12,   320,   321,    -1,    16,    -1,    -1,    -1,    20,    21,
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
     152,   153,    -1,   155,   156,    -1,   158,   159,   160,   161,
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
     312,   313,   314,   315,    -1,   317,    11,    12,   320,   321,
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
     315,    -1,   317,    11,    12,   320,   321,    -1,    16,    -1,
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
     181,   182,   183,    -1,    -1,    -1,   187,    -1,   189,   190,
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
     187,   188,   189,   190,    -1,   192,   193,    -1,   195,    -1,
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
      -1,   181,   182,   183,    -1,    -1,   186,   187,    -1,   189,
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
     183,    -1,    -1,    -1,   187,   188,   189,   190,    -1,   192,
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
     156,    -1,   158,   159,   160,   161,   162,    -1,    -1,    -1,
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
      -1,   317,    -1,   319,   320,   321,    11,    12,    -1,    -1,
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
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,    -1,   264,
     265,   266,    -1,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,    11,    12,   320,   321,    -1,    16,    -1,
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
      -1,   189,   190,    -1,   192,   193,    -1,   195,    -1,   197,
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
     318,    -1,   320,   321,    11,    12,    -1,    -1,    -1,    16,
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
     137,   138,   139,   140,   141,    -1,    -1,    -1,    -1,    -1,
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
     317,    -1,   319,   320,   321,    11,    12,    -1,    -1,    -1,
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
     156,    -1,   158,   159,   160,   161,   162,    -1,    -1,    -1,
     166,   167,   168,   169,   170,   171,   172,   173,    -1,   175,
      -1,   177,   178,    -1,    -1,   181,   182,   183,    -1,   185,
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
      -1,    -1,   187,    -1,   189,   190,    -1,   192,   193,    -1,
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
      -1,   159,   160,   161,   162,    -1,    -1,    -1,   166,   167,
     168,   169,   170,   171,   172,   173,    -1,   175,    -1,   177,
     178,    -1,    -1,   181,   182,   183,    -1,    -1,    -1,   187,
      -1,   189,   190,    -1,   192,   193,    -1,   195,    -1,   197,
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
      -1,    -1,    -1,   137,   138,   139,   140,   141,    -1,    -1,
      -1,    -1,    -1,    -1,   148,   149,   150,   151,   152,   153,
      -1,   155,   156,    -1,   158,   159,   160,   161,   162,    -1,
      -1,    -1,   166,   167,   168,   169,   170,   171,   172,   173,
      -1,   175,    -1,   177,   178,    -1,    -1,   181,   182,   183,
      -1,    -1,    -1,   187,    -1,   189,   190,    -1,   192,   193,
      -1,   195,    -1,   197,    -1,   199,   200,   201,   202,   203,
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
     187,    -1,   189,   190,    -1,   192,   193,    -1,   195,    -1,
     197,    -1,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,    -1,    -1,   212,   213,   214,    -1,   216,
      -1,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,    -1,   230,    -1,   232,    -1,    -1,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   262,    -1,   264,   265,   266,
      -1,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,    -1,
     317,    11,    12,    -1,   321,    -1,    16,    -1,    -1,    -1,
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
      -1,   161,   162,    -1,    -1,    -1,   166,   167,   168,   169,
     170,   171,   172,   173,    -1,   175,    -1,    -1,    -1,    -1,
      -1,   181,   182,   183,    -1,    -1,    -1,   187,    -1,   189,
     190,    -1,   192,   193,    -1,   195,    -1,   197,    -1,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
      -1,    -1,   212,   213,   214,    -1,   216,    -1,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,    -1,
     230,    -1,   232,    -1,    -1,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,    -1,   264,   265,   266,    -1,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,    -1,   317,    11,    12,
      -1,   321,    -1,    16,    -1,    -1,    -1,    20,    21,    22,
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
     153,    -1,   155,   156,    -1,   158,   159,    -1,   161,   162,
      -1,    -1,    -1,   166,   167,   168,   169,   170,   171,   172,
     173,    -1,   175,    -1,    -1,    -1,    -1,    -1,   181,   182,
     183,    -1,    -1,    -1,   187,    -1,   189,   190,    -1,    -1,
      -1,    -1,   195,    -1,   197,    -1,   199,   200,   201,   202,
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
      -1,   137,    -1,   139,   140,   141,    -1,    -1,    -1,    -1,
      -1,    -1,   148,   149,   150,   151,    -1,   153,    -1,   155,
     156,    -1,   158,   159,    -1,   161,   162,    -1,    -1,    -1,
     166,   167,   168,   169,   170,   171,   172,   173,    -1,   175,
      -1,    -1,    -1,    -1,    -1,   181,   182,   183,    -1,    -1,
      -1,   187,    -1,   189,   190,    -1,    -1,    -1,    -1,   195,
      -1,   197,    -1,   199,    -1,   201,    -1,   203,   204,   205,
     206,   207,   208,   209,    -1,    -1,   212,   213,   214,    -1,
     216,    -1,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,    -1,   230,    -1,   232,    -1,    -1,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,    -1,   264,   265,
     266,    -1,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
      -1,   317,    11,    12,    -1,   321,    -1,    16,    -1,    -1,
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
     149,   150,   151,    -1,   153,    -1,   155,    -1,    -1,   158,
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
     309,   310,   311,   312,   313,   314,   315,    -1,   317,    11,
      12,   320,   321,    -1,    16,    -1,    -1,    -1,    20,    21,
      22,    23,    24,    25,    26,    -1,    -1,    -1,    30,    -1,
      -1,    33,    34,    -1,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    -1,    51,
      52,    53,    54,    -1,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    -1,    -1,    95,    96,    97,    98,    99,    -1,   101,
      -1,    -1,    -1,    -1,   106,   107,    -1,    -1,    -1,   111,
     112,   113,   114,   115,   116,   117,    -1,   119,   120,    -1,
     122,    -1,    -1,    -1,   126,    -1,   128,   129,   130,   131,
      -1,   133,    -1,    -1,    -1,   137,    -1,   139,   140,   141,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   149,   150,   151,
      -1,   153,    -1,   155,    -1,    -1,    -1,   159,    -1,    -1,
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
     115,   116,   117,    -1,   119,   120,    -1,   122,    -1,    -1,
      -1,   126,    -1,   128,   129,   130,   131,    -1,   133,    -1,
      -1,    -1,   137,    -1,   139,   140,   141,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   149,   150,   151,    -1,   153,    -1,
     155,    -1,    -1,    -1,   159,    -1,    -1,   162,    -1,    -1,
      -1,   166,   167,   168,   169,   170,   171,   172,   173,    -1,
     175,    -1,    -1,   178,    -1,    -1,   181,   182,   183,    -1,
      -1,    -1,   187,    -1,   189,   190,    -1,    -1,    -1,    -1,
      -1,    -1,   197,    -1,   199,    -1,   201,    -1,   203,   204,
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
      -1,    -1,    20,    -1,    -1,    -1,    -1,    25,    26,    -1,
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
      -1,   189,   190,    -1,    -1,    -1,    -1,   195,    -1,   197,
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
     308,   309,   310,   311,   312,   313,   314,    11,    12,    -1,
      -1,    -1,    16,   321,    -1,    -1,    20,    -1,    -1,    -1,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   161,   162,    -1,
      -1,    -1,   166,   167,   168,   169,   170,   171,   172,   173,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   181,   182,   183,
      -1,    -1,    -1,   187,    -1,   189,   190,    -1,    -1,    -1,
      -1,   195,    -1,   197,    -1,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,    -1,    -1,   212,   213,
      -1,    -1,   216,    -1,   218,   219,    -1,    -1,    -1,   223,
     224,   225,   226,   227,   228,    -1,   230,    -1,   232,    -1,
      -1,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,    -1,
     264,   265,   266,    -1,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,    16,    -1,    -1,    -1,    -1,    -1,   321,    -1,    -1,
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
      -1,    -1,   187,   188,   189,   190,    -1,    -1,    -1,    -1,
     195,    -1,   197,    -1,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,    -1,    -1,   212,   213,    -1,
      -1,   216,    -1,   218,   219,    -1,    -1,    -1,   223,   224,
     225,   226,   227,   228,    -1,   230,    -1,   232,    -1,    -1,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,    -1,   264,
     265,   266,    -1,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
      -1,    -1,    16,    -1,    -1,    -1,   321,   322,   323,   324,
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
      -1,    -1,    -1,   187,   188,   189,   190,    -1,    -1,    -1,
      -1,    -1,    -1,   197,    -1,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,    -1,    -1,   212,   213,
      -1,    -1,   216,    -1,   218,   219,    -1,    -1,    -1,   223,
     224,   225,   226,   227,   228,    -1,   230,    -1,   232,    -1,
      -1,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,    -1,
     264,   265,   266,    -1,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,    -1,    -1,    16,    -1,    -1,    -1,   321,   322,   323,
     324,   325,    25,    26,    -1,    -1,    -1,    -1,    -1,    -1,
      33,    34,    -1,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    -1,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    -1,    95,    96,    97,    98,    -1,    -1,   101,   102,
     103,    -1,    -1,   106,   107,    -1,    -1,    -1,    -1,   112,
     113,   114,   115,   116,   117,   118,   119,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   128,   129,   130,   131,    -1,
     133,    -1,    -1,    -1,   137,   138,   139,   140,   141,    -1,
      -1,    -1,    -1,    -1,    -1,   148,   149,   150,    -1,   152,
     153,   154,    -1,    -1,    -1,   158,    -1,    -1,   161,   162,
      -1,    -1,    -1,   166,   167,   168,   169,   170,   171,   172,
     173,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   181,   182,
     183,    -1,    -1,    -1,   187,    -1,   189,   190,    -1,    -1,
      -1,    -1,    -1,    -1,   197,    -1,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,    -1,    -1,   212,
     213,    -1,    -1,   216,    -1,   218,   219,    -1,    -1,    -1,
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
     112,   113,   114,   115,   116,   117,   118,   119,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   128,   129,   130,   131,
      -1,   133,    -1,    -1,    -1,   137,   138,   139,   140,   141,
      -1,    -1,    -1,    -1,    -1,    -1,   148,   149,   150,    -1,
     152,   153,   154,    -1,    -1,    -1,   158,    -1,    -1,   161,
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
      -1,    -1,   112,   113,   114,   115,   116,   117,   118,    -1,
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
      -1,    -1,    -1,   223,   224,   225,   226,   227,   228,    -1,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   128,
     129,   130,   131,    -1,   133,    -1,    -1,    -1,   137,   138,
     139,   140,   141,    -1,    -1,    -1,    -1,    -1,    -1,   148,
     149,   150,    -1,   152,   153,   154,    -1,    -1,    -1,   158,
      -1,    -1,   161,   162,    -1,    -1,    -1,   166,   167,   168,
     169,   170,   171,   172,   173,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   181,   182,   183,    -1,    -1,    -1,   187,    -1,
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
     309,   310,   311,   312,   313,   314,    -1,    -1,    16,    -1,
      -1,    -1,   321,   322,   323,   324,   325,    25,    26,    -1,
      -1,    -1,    30,    -1,    -1,    33,    34,    -1,    36,    37,
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
     148,   149,   150,    -1,   152,   153,    -1,    -1,    -1,    -1,
     158,    -1,    -1,   161,   162,    -1,    -1,    -1,   166,   167,
     168,   169,   170,   171,   172,   173,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   181,   182,   183,    -1,    -1,    -1,   187,
      -1,   189,   190,    -1,    -1,    -1,    -1,    -1,    -1,   197,
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
     308,   309,   310,   311,   312,   313,   314,    16,    -1,    18,
      19,    -1,    -1,   321,    -1,    -1,    25,    26,    -1,    -1,
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
     149,   150,    -1,   152,   153,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   161,   162,    -1,    -1,    -1,   166,   167,   168,
     169,   170,   171,   172,   173,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   181,   182,   183,    -1,    -1,    -1,   187,    -1,
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
      -1,   321,    -1,    -1,    25,    26,    -1,    -1,    -1,    30,
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
      -1,   152,   153,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     161,   162,    -1,    -1,    -1,   166,   167,   168,   169,   170,
     171,   172,   173,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     181,   182,   183,    -1,    -1,    -1,   187,   188,   189,   190,
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
     182,   183,    -1,    -1,    -1,   187,   188,   189,   190,    -1,
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
     113,   114,   115,   116,   117,   118,   119,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   128,   129,   130,   131,    -1,
     133,    -1,    -1,    -1,   137,   138,   139,   140,   141,    -1,
      -1,    -1,    -1,    -1,    -1,   148,   149,   150,    -1,   152,
     153,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   161,   162,
      -1,    -1,    -1,   166,   167,   168,   169,   170,   171,   172,
     173,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   181,   182,
     183,    -1,    -1,    -1,   187,    -1,   189,   190,    -1,    -1,
      -1,    -1,    -1,    -1,   197,    -1,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,    -1,    -1,   212,
     213,    -1,    -1,   216,    -1,   218,   219,    -1,    -1,    -1,
     223,   224,   225,   226,   227,   228,    -1,   230,    -1,   232,
      -1,    -1,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
      -1,   264,   265,   266,    -1,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,   311,   312,
     313,   314,    16,    -1,    -1,    -1,    -1,    -1,   321,    -1,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   161,   162,    -1,
      -1,    -1,   166,   167,   168,   169,   170,   171,   172,   173,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   181,   182,   183,
      -1,    -1,    -1,   187,    -1,   189,   190,    -1,    -1,    -1,
      -1,    -1,    -1,   197,    -1,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,    -1,    -1,   212,   213,
      -1,    -1,   216,    -1,   218,   219,    -1,    -1,    -1,   223,
     224,   225,   226,   227,   228,    -1,   230,    -1,   232,    -1,
      -1,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,    -1,
     264,   265,   266,    -1,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,    21,    22,    23,    24,    25,    26,   321,    -1,    -1,
      30,    -1,    -1,    33,    34,    -1,    36,    37,    38,    39,
      40,    41,    42,    43,    -1,    45,    46,    47,    -1,    49,
      50,    51,    52,    -1,    54,    -1,    56,    57,    58,    59,
      60,    61,    -1,    -1,    64,    65,    66,    67,    68,    -1,
      70,    71,    72,    -1,    -1,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    -1,    95,    96,    97,    98,    -1,
      -1,   101,   102,   103,    -1,    -1,   106,   107,    -1,    -1,
      -1,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,    -1,    -1,    -1,    -1,    -1,   126,    -1,   128,   129,
     130,   131,    -1,   133,    -1,    -1,    -1,   137,   138,   139,
     140,   141,    -1,    -1,    -1,    -1,    -1,    -1,   148,   149,
     150,   151,   152,   153,    -1,   155,   156,    -1,   158,   159,
      -1,   161,   162,    -1,    -1,    -1,   166,   167,   168,   169,
     170,   171,   172,   173,    -1,   175,    -1,    -1,    -1,    -1,
      -1,   181,   182,   183,    -1,    -1,    -1,   187,    -1,   189,
     190,    -1,    -1,    -1,    -1,    -1,    -1,   197,    -1,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
      -1,    -1,    -1,   213,   214,    -1,   216,    -1,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,    -1,
     230,    -1,   232,    -1,    -1,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,    -1,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,    -1,   264,   265,   266,    -1,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,    -1,   317,    -1,   319,
      -1,   321,    21,    22,    23,    24,    25,    26,    -1,    -1,
      -1,    30,    -1,    -1,    33,    34,    -1,    36,    37,    38,
      39,    40,    41,    42,    43,    -1,    45,    46,    47,    -1,
      49,    50,    51,    52,    -1,    54,    -1,    56,    57,    58,
      59,    60,    61,    -1,    -1,    64,    65,    66,    67,    68,
      -1,    70,    71,    72,    -1,    -1,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    -1,    95,    96,    97,    98,
      -1,    -1,   101,   102,   103,    -1,    -1,   106,   107,    -1,
      -1,    -1,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,    -1,    -1,    -1,    -1,    -1,   126,    -1,   128,
     129,   130,   131,    -1,   133,    -1,    -1,    -1,   137,   138,
     139,   140,   141,    -1,    -1,    -1,    -1,    -1,    -1,   148,
     149,   150,   151,   152,   153,    -1,   155,   156,    -1,   158,
     159,    -1,   161,   162,    -1,    -1,    -1,   166,   167,   168,
     169,   170,   171,   172,   173,    -1,   175,    -1,    -1,    -1,
      -1,    -1,   181,   182,   183,    -1,    -1,    -1,   187,    -1,
     189,   190,    -1,    -1,    -1,    -1,    -1,    -1,   197,    -1,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,    -1,    -1,    -1,   213,   214,    -1,   216,    -1,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
      -1,   230,    -1,   232,    -1,    -1,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,    -1,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   262,    -1,   264,   265,   266,    -1,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,    -1,   317,    -1,
     319,    -1,   321,    21,    22,    23,    24,    25,    26,    -1,
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
      -1,    -1,    -1,   321,    21,    22,    23,    24,    25,    26,
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
     227,   228,    -1,    -1,    -1,   232,    -1,    -1,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,    -1,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   262,    -1,   264,   265,   266,
      -1,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,    -1,
     317,    25,    26,    -1,   321,    -1,    -1,    -1,    -1,    33,
      34,    -1,    36,    37,    38,    -1,    40,    41,    42,    43,
      -1,    -1,    46,    47,    -1,    49,    50,    51,    52,    -1,
      54,    -1,    56,    57,    58,    59,    -1,    61,    -1,    -1,
      64,    65,    66,    67,    68,    -1,    70,    -1,    72,    -1,
      -1,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      -1,    95,    96,    97,    -1,    -1,    -1,   101,   102,   103,
      -1,    -1,   106,   107,    -1,    -1,    -1,    -1,   112,   113,
     114,   115,   116,   117,   118,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   128,   129,   130,   131,    -1,   133,
      -1,    -1,    -1,   137,   138,   139,   140,   141,    -1,    -1,
      -1,    -1,    -1,    -1,   148,   149,   150,    -1,   152,   153,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   161,   162,    -1,
      -1,    -1,   166,   167,   168,   169,   170,   171,   172,   173,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   181,   182,   183,
      -1,    -1,    -1,   187,    -1,   189,   190,    -1,    -1,    -1,
      -1,    -1,    -1,   197,    -1,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,    -1,    -1,    -1,   213,
      -1,    -1,   216,    -1,   218,   219,    -1,    -1,    -1,   223,
     224,   225,   226,   227,   228,    -1,    -1,    -1,   232,    -1,
      -1,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,    -1,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,    -1,
     264,   265,   266,    -1,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,    -1,    -1,    -1,    -1,    -1,    -1,   321
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
     315,   317,   320,   321,   326,   327,   342,   344,   345,   346,
     347,   348,   349,   350,   351,   352,   353,   354,   355,   356,
     357,   358,   359,   360,   363,   364,   365,   366,   367,   368,
     372,   373,   374,   378,   380,   381,   383,   390,   392,   395,
     396,   397,   399,   400,   401,   402,   403,   405,   406,   408,
     409,   410,   411,   412,   413,   415,   416,   419,   420,   421,
     422,   423,   428,   430,   432,   433,   434,   439,   458,   461,
     465,   468,   469,   475,   476,   477,   478,   479,   480,   481,
     483,   484,   485,   486,   487,   488,   489,   490,   491,   493,
     494,   495,   496,   498,   499,   500,   501,   502,   503,   504,
     505,   506,   507,   508,   509,   510,   511,   512,   513,   514,
     515,   518,   519,   520,   521,   522,   523,   524,   525,   526,
     527,   529,   530,   531,   532,   533,   534,   548,   549,   551,
     552,   553,   554,   555,   556,   557,   558,   566,   567,   568,
     569,   570,   571,   572,   573,   574,   575,   576,   577,   580,
     585,   586,   587,   588,   589,   590,   593,   651,   652,   653,
     654,   656,   657,   658,   659,   660,   666,   667,   668,    33,
      34,    49,   216,   398,   399,   400,   398,   398,   399,   400,
     158,   158,    37,    38,    40,    41,    47,    57,    58,    75,
      80,   112,   113,   114,   162,   225,   266,   292,   300,   308,
     379,   380,   384,   385,   386,   162,   155,   158,   155,   158,
     155,   158,     1,   158,   387,   158,    25,    34,    61,   119,
     278,   438,   440,   441,   158,   155,   158,   158,   158,   119,
     155,   158,   158,   158,    77,   155,   226,   227,   124,   124,
     124,   155,   158,    39,    43,    45,    46,    47,    48,    51,
      60,    68,    71,    73,    74,    76,    91,    92,    98,   106,
     113,   115,   116,   137,   140,   141,   162,   170,   173,   181,
     182,   190,   203,   241,   243,   244,   245,   248,   249,   262,
     265,   512,   667,   124,   119,   407,   124,   124,    39,    44,
      45,    53,    60,    62,    63,    71,    98,   230,   666,   119,
     124,   124,   398,   400,   421,   655,   666,    48,    73,    74,
     119,   155,   186,   249,   420,   422,   432,   188,   420,   666,
     155,   155,   124,   666,    18,    19,   666,   124,   124,   124,
     504,   155,    31,   215,   218,   218,    39,    45,    60,    71,
      98,   230,   232,   319,   515,   667,   230,   232,   319,   421,
     655,   230,   319,   515,   230,   235,   319,   119,   246,   246,
     247,   158,   155,   402,     1,   478,   316,   420,   318,   420,
     319,   421,   327,   344,   344,     0,   346,   347,    33,    49,
     349,   366,     1,   191,   343,   191,   343,   113,   381,   401,
     420,   108,   191,   108,   343,   191,    42,    46,    51,    70,
     169,   172,   187,   213,   262,   414,   424,   429,   430,   431,
     446,   447,   451,     3,    67,    72,   119,   425,   168,    93,
     204,   205,   206,   207,   208,   209,   497,   254,   100,   160,
     177,   200,   118,   148,   161,   195,   202,   211,   138,   152,
      50,   201,   102,   103,   160,   177,   495,   194,   155,   501,
     504,   192,   193,   156,   516,   517,   512,   516,   512,   121,
     158,   516,   158,   147,   158,   185,   185,   185,   185,   382,
     519,   382,    30,   665,   183,   197,   183,   197,   167,   183,
     667,   666,   170,   203,    47,   666,   154,   119,    45,    47,
      80,   107,   169,   666,   226,   227,   228,   251,   624,   666,
     666,   309,   139,   144,   113,   292,   300,   384,   666,   399,
     188,   399,    45,    63,   188,   576,   577,   420,   188,   195,
     666,   435,   436,   666,   119,   188,   388,   389,   155,   404,
     420,     1,   162,   665,   114,   162,   362,   665,   666,   119,
     144,   108,   188,   420,    30,   188,   666,   666,   666,   459,
     460,   666,   399,   188,   420,   420,   578,   666,   399,   155,
     155,   420,   188,   195,   666,   666,   144,   459,   185,   185,
     123,   108,   185,   123,   158,   158,   158,   666,   155,   186,
     187,   188,    35,   536,   537,   538,   420,   420,     8,   176,
      17,   420,   215,    30,    30,   421,   421,   515,   421,   421,
     421,   655,   238,   238,   421,   515,    95,   421,   236,   235,
     591,   592,   666,   191,   191,   421,   420,   400,   420,   250,
     417,   418,   435,   316,   318,   421,   238,   344,   191,   343,
     191,   343,     3,   350,   366,   396,     1,   350,   366,   396,
      33,   367,   396,   367,   396,   407,   343,   407,   421,   421,
     119,   169,   171,   171,   401,   421,   421,   289,   289,   435,
     119,   442,   477,   478,   480,    71,   481,   485,   485,   484,
     486,   486,   486,   486,   487,   487,   488,   488,   236,    95,
      95,    95,   502,   185,   420,   504,   504,   420,   517,   158,
     522,   580,   666,   146,   188,   421,   528,   188,   151,   188,
     528,   108,   188,   188,   108,   108,   387,    30,   667,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,   369,
     370,   371,    95,   139,   144,   375,   376,   377,   666,   162,
     162,   369,   665,   129,   134,    55,    57,   101,   256,   269,
     271,   282,   283,   284,   286,   288,   625,   626,   627,   628,
     629,   630,   637,   643,   644,   251,    95,   304,   666,   144,
     421,   119,   666,   666,   134,   185,   185,   188,   188,   185,
     108,   188,   108,   188,   108,    36,    95,    97,   149,   437,
     438,   559,   666,    95,   108,   188,   398,   188,   666,    97,
      45,   666,   665,    97,   144,   559,   666,   421,   441,   185,
     188,   188,   188,   188,   108,   189,   149,   559,   185,   188,
     188,   155,   185,   399,   399,   185,   108,   188,   108,   188,
     144,   559,   421,   189,   421,   421,   666,   421,   420,   420,
     420,   666,   537,   538,   132,   198,   185,   185,   185,   133,
     191,   133,   191,    95,   223,   224,   238,    95,   223,   224,
     238,   238,   238,   421,   421,    95,    95,   421,   242,   230,
     515,   236,   108,   240,   144,   191,   188,   420,   185,   513,
     597,   418,   238,   421,   366,    33,    33,   191,   343,   191,
     114,   401,   666,   171,   421,   452,   453,   119,   448,   449,
     666,    56,   219,   259,   426,   427,   155,   158,   264,   500,
     519,   598,   601,   602,   603,   604,   605,   609,   611,   613,
     614,    47,   154,   158,   212,   322,   323,   324,   325,   560,
     562,   564,   566,   581,   582,   583,   584,   661,   662,   663,
     664,   666,   560,   492,   565,   666,   492,   185,   186,   188,
     420,   108,   188,   188,   519,   150,   166,   150,   166,   139,
     404,   387,   370,   134,   158,   562,   377,   421,   559,   665,
     665,   130,   131,   665,   282,   283,   284,   288,   666,   268,
     279,   268,   279,    30,   291,    97,   114,   158,   631,   634,
     625,    39,    44,    53,    60,    62,    71,    98,   230,   391,
     566,   661,   232,   304,   313,   421,   666,    95,   304,   665,
     155,   578,   579,   666,   578,   579,   119,   436,   129,   560,
     119,   421,   149,   438,   149,    36,   149,   437,   438,   559,
     560,   389,    95,   185,   199,   134,   361,   665,   162,   134,
      97,   361,   421,   144,   438,   155,   119,   421,   421,   149,
     101,   462,   463,   464,   466,   467,   101,   470,   471,   472,
     473,   399,   185,   185,   155,   578,   578,   421,   144,   191,
     421,   123,   123,   188,   188,   188,    35,   538,   132,   198,
       9,    10,   104,   125,   127,   155,   196,   533,   535,   546,
     547,   550,   155,    30,    30,   237,   239,   421,   421,   421,
     237,   239,   421,   421,   421,   421,   421,    97,   421,   421,
     421,   421,   242,   515,   119,   421,   421,    48,    73,    74,
     249,   401,   422,   432,   250,   594,   595,   155,   211,   402,
     421,   191,   114,   396,   396,   396,   452,    96,   107,   117,
     129,   454,   455,   456,   457,   108,   666,   108,   149,   559,
     259,    54,    59,    78,   119,   437,   443,   444,   445,   427,
     420,   598,   605,   155,   290,   482,   650,    97,   170,   257,
     258,   260,   267,   277,   289,   599,   600,   619,   620,   621,
     622,   645,   648,   263,   265,   606,   624,   272,   610,   646,
     252,   253,   275,   615,   616,   158,   158,   188,   562,   158,
     158,   158,   158,   158,   146,   177,   195,   561,   146,   188,
     146,   421,   139,   404,   580,   376,   291,    30,    97,   114,
     158,   638,    30,   631,   561,   561,   502,   292,   311,   559,
     391,   232,   191,   398,   188,   188,   146,   188,   188,   436,
     149,   437,   666,   421,   149,   421,   129,   421,   149,   438,
     149,   560,   401,   421,   665,   108,   361,   421,   144,   398,
     460,   421,   421,   114,   463,   464,   101,   187,   114,   464,
     467,   119,   474,   560,   101,   114,   471,   101,   114,   473,
     185,   398,   188,   188,   421,   421,   421,   199,   470,   134,
     196,   535,     7,   399,   666,   196,   546,   399,   191,   191,
     238,   238,   238,   238,    97,   321,   242,   421,   242,   592,
     187,   158,   158,   158,   187,   597,   595,   513,   665,   130,
     131,   456,   457,   457,   453,   107,   144,   450,   559,   449,
     421,   149,   119,   119,   421,   666,   445,    78,   185,   188,
     598,   612,   255,   219,   259,   273,   280,   649,    97,   261,
     262,   647,   255,   602,   649,   484,   619,   603,   149,   287,
     607,   608,   647,   291,   618,    79,   617,   188,   195,   560,
     563,   188,   188,   188,   188,   188,   188,   188,    30,   138,
     202,   640,   641,   642,    30,   639,   640,   276,   635,   108,
     632,   171,   666,   262,   502,   185,   421,   149,   421,   149,
     437,   421,   149,   421,   128,   128,    97,   665,   421,   185,
     187,   187,   421,   401,   421,   187,   187,   666,   187,   211,
     119,   474,   119,   187,   119,   474,   187,   185,   114,   538,
     666,   196,   185,   538,   666,   185,   421,   421,   421,   421,
     321,   421,   421,   421,   421,   420,   420,   420,   155,   596,
     457,   665,   421,   144,   421,   666,   666,   444,   421,   185,
     486,    52,   131,   484,   484,   274,   281,   291,   623,   623,
     604,   155,   285,    95,   188,   108,   188,   638,   638,   642,
     108,   188,    30,   636,   647,   633,   634,   188,   393,   394,
     502,   119,   230,   312,   292,   171,   421,   421,   149,   421,
     401,   421,   361,   421,   401,    95,   401,   421,   560,   666,
     187,   666,   421,   666,   187,   401,   119,    94,   184,   539,
     538,   666,   198,   538,   421,   188,   188,   188,   420,   450,
     421,    54,   484,   484,   200,   420,   560,   560,    95,    30,
     270,   108,   108,   457,   559,   666,   119,   230,   666,   393,
     421,   474,    95,   187,    95,   666,     5,   135,   542,   543,
     545,   547,    29,   136,   540,   541,   544,   547,   198,   538,
     198,   199,   470,   185,   450,   119,   484,   185,   560,   634,
     394,   457,   310,   666,   119,   230,   187,   474,   401,   421,
     474,   187,    94,   135,   545,   184,   136,   544,   198,   114,
     666,   421,   310,   666,   119,   401,   421,   187,   187,   119,
     298,   310,   666,   666,   311,   421,   311,   187,   502,   502,
     200,   292,   666,   230,   119,   666,   311,   502
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
     477,   477,   478,   478,   479,   479,   480,   480,   481,   481,
     482,   482,   483,   483,   484,   484,   484,   485,   485,   485,
     485,   485,   486,   486,   486,   487,   487,   487,   488,   488,
     489,   489,   490,   490,   491,   491,   492,   492,   493,   493,
     494,   494,   494,   494,   495,   495,   495,   496,   496,   497,
     497,   497,   497,   497,   497,   498,   498,   498,   498,   499,
     499,   500,   500,   501,   501,   501,   502,   502,   502,   502,
     503,   504,   504,   504,   505,   505,   506,   506,   506,   506,
     507,   507,   508,   508,   508,   508,   508,   508,   508,   509,
     509,   510,   510,   511,   511,   511,   511,   511,   512,   512,
     513,   513,   514,   514,   514,   514,   515,   515,   515,   515,
     515,   515,   515,   515,   515,   516,   516,   517,   518,   518,
     518,   518,   518,   518,   518,   518,   518,   518,   518,   518,
     518,   518,   519,   519,   519,   519,   520,   520,   520,   521,
     521,   522,   523,   523,   524,   525,   526,   527,   527,   528,
     528,   528,   528,   529,   529,   530,   531,   532,   532,   533,
     533,   533,   534,   534,   534,   534,   534,   534,   535,   535,
     536,   536,   537,   538,   538,   539,   539,   540,   540,   541,
     541,   541,   541,   542,   542,   543,   543,   543,   543,   544,
     544,   545,   545,   546,   546,   546,   546,   547,   547,   547,
     547,   548,   548,   549,   549,   550,   551,   551,   551,   551,
     551,   551,   551,   552,   553,   553,   554,   554,   555,   556,
     557,   557,   558,   558,   559,   560,   560,   560,   560,   561,
     561,   561,   562,   562,   562,   562,   562,   562,   562,   562,
     562,   563,   563,   564,   565,   566,   566,   566,   566,   566,
     566,   566,   566,   566,   566,   567,   568,   569,   569,   569,
     570,   571,   572,   573,   573,   573,   574,   574,   574,   574,
     574,   575,   576,   576,   576,   576,   576,   576,   576,   577,
     578,   579,   580,   581,   581,   582,   583,   583,   584,   585,
     585,   585,   586,   586,   586,   586,   586,   586,   586,   586,
     586,   586,   587,   587,   588,   588,   589,   590,   591,   591,
     592,   593,   594,   594,   595,   596,   597,   597,   598,   599,
     599,   600,   600,   601,   601,   602,   602,   603,   603,   604,
     604,   605,   606,   606,   607,   607,   608,   609,   609,   609,
     610,   610,   611,   612,   612,   613,   614,   614,   615,   615,
     616,   616,   616,   617,   617,   618,   618,   619,   619,   619,
     619,   619,   620,   621,   622,   623,   623,   623,   624,   624,
     625,   625,   625,   625,   625,   625,   625,   625,   626,   626,
     626,   626,   627,   627,   628,   629,   629,   630,   630,   630,
     631,   631,   632,   632,   633,   633,   634,   635,   635,   636,
     636,   637,   637,   637,   638,   638,   639,   639,   640,   640,
     641,   641,   642,   642,   643,   644,   644,   645,   645,   645,
     646,   647,   647,   647,   647,   648,   648,   649,   649,   650,
     651,   651,   652,   652,   653,   653,   654,   655,   655,   655,
     655,   656,   656,   656,   656,   656,   656,   657,   657,   658,
     658,   659,   659,   660,   660,   661,   661,   661,   662,   662,
     663,   663,   664,   664,   665,   666,   666,   666,   666,   666,
     666,   666,   666,   666,   666,   666,   666,   666,   666,   666,
     666,   666,   667,   667,   667,   667,   667,   667,   667,   667,
     667,   667,   667,   667,   667,   667,   667,   667,   667,   667,
     667,   667,   667,   667,   667,   667,   667,   667,   667,   667,
     667,   667,   667,   667,   667,   667,   667,   667,   667,   667,
     667,   667,   667,   667,   667,   667,   667,   667,   667,   667,
     667,   667,   667,   667,   667,   667,   667,   667,   667,   667,
     667,   667,   667,   667,   667,   667,   667,   667,   667,   667,
     667,   667,   667,   667,   667,   667,   667,   667,   667,   667,
     667,   667,   667,   667,   667,   667,   667,   667,   667,   667,
     667,   667,   667,   667,   667,   667,   667,   667,   667,   667,
     667,   667,   667,   667,   667,   667,   667,   667,   667,   667,
     667,   667,   667,   667,   667,   667,   667,   667,   667,   667,
     667,   667,   667,   667,   667,   667,   667,   667,   667,   667,
     667,   667,   667,   667,   667,   667,   667,   667,   667,   667,
     667,   667,   667,   667,   667,   667,   667,   667,   667,   667,
     667,   667,   667,   667,   667,   667,   667,   667,   667,   667,
     667,   667,   667,   667,   667,   667,   667,   667,   667,   667,
     667,   667,   667,   667,   667,   667,   667,   667,   667,   667,
     667,   667,   667,   667,   667,   667,   667,   667,   667,   667,
     667,   667,   667,   667,   667,   667,   667,   667,   668
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
       1,     3,     2,     4,     5,     6,     5,     3,     2,     3,
       4,     1,     3,     1,     2,     1,     1,     1,     2,     2,
       2,     3,     1,     1,     2,     2,     2,     5,     5,     1,
       4,     3,     4,     8,     1,     2,     3,     2,     3,     8,
       1,     2,     3,     8,    10,     8,    10,     1,     2,     4,
       7,     1,     2,     4,     7,     1,     3,     8,     1,     3,
       1,     3,     1,     2,     1,     3,     1,     5,     1,     3,
       0,     1,     1,     3,     1,     3,     3,     1,     3,     3,
       3,     3,     1,     3,     3,     1,     3,     3,     1,     4,
       1,     4,     1,     4,     1,     4,     1,     2,     1,     2,
       1,     1,     2,     2,     1,     1,     1,     1,     3,     1,
       1,     1,     1,     1,     1,     4,     5,     5,     6,     3,
       4,     1,     2,     3,     2,     2,     1,     2,     2,     1,
       1,     1,     3,     3,     1,     1,     1,     2,     1,     2,
       2,     1,     2,     2,     2,     2,     2,     2,     2,     1,
       2,     2,     1,     2,     2,     2,     2,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     3,     4,
       3,     4,     5,     3,     3,     1,     2,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     2,     3,     1,     4,     4,     3,     4,     1,
       3,     1,     3,     1,     1,     3,     3,     1,     1,     1,
       1,     1,     4,     8,     5,     9,     9,    10,     1,     2,
       1,     2,     6,     0,     1,     3,     3,     0,     1,     1,
       1,     2,     2,     0,     1,     1,     1,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     3,     2,     3,     3,     2,     1,     1,     1,     1,
       1,     1,     1,     4,     3,     7,     3,     7,     4,     4,
       3,     7,     3,     7,     2,     1,     2,     3,     2,     1,
       1,     1,     1,     1,     3,     1,     3,     1,     1,     1,
       1,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     1,     3,     4,     4,
       3,     3,     3,     3,     4,     4,     3,     4,     6,     4,
       6,     4,     3,     4,     6,     6,     4,     6,     6,     4,
       1,     2,     1,     1,     1,     4,     5,     6,     3,     3,
       3,     3,     5,     7,     7,     5,     5,     5,     7,     7,
       5,     5,     3,     3,     5,     7,     5,     7,     1,     4,
       3,     5,     1,     2,     3,     3,     1,     3,     2,     0,
       1,     1,     2,     1,     3,     1,     3,     1,     4,     1,
       2,     3,     0,     1,     0,     1,     4,     2,     3,     1,
       0,     1,     4,     0,     1,     2,     1,     3,     0,     1,
       2,     2,     1,     0,     1,     0,     1,     1,     1,     1,
       1,     1,     1,     3,     3,     1,     1,     1,     2,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     2,
       1,     1,     2,     2,     3,     1,     2,     2,     5,     2,
       1,     1,     0,     2,     1,     3,     4,     0,     2,     0,
       2,     4,     4,     3,     2,     3,     1,     3,     0,     1,
       1,     2,     2,     2,     2,     1,     2,     2,     2,     2,
       3,     2,     3,     3,     4,     2,     2,     1,     1,     3,
       2,     3,     2,     3,     2,     3,     3,     3,     3,     5,
       5,     5,     5,     8,     4,     4,     7,     5,     4,     3,
       2,     5,     4,     7,     6,     1,     1,     1,     3,     1,
       3,     1,     3,     1,     1,     1,     1,     1,     1,     1,
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
       1,     1,     1,     1,     1,     1,     1,     1,     1
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
     162,   666,   134,   665,   191,    -1,   350,    -1,   349,   191,
     350,    -1,   349,   343,   350,    -1,   351,    -1,   359,    -1,
     364,    -1,   365,    -1,   373,    -1,   352,    -1,   353,    -1,
     354,    -1,   355,    -1,   356,    -1,   357,    -1,   358,    -1,
     585,    -1,    33,    38,   183,    -1,    33,    38,   197,    -1,
      33,   114,   107,   665,    -1,    33,    37,   665,    -1,    33,
      40,   183,    -1,    33,    40,   197,    -1,    33,    58,   170,
      -1,    33,    58,   203,    -1,    33,   114,   169,   129,   130,
      -1,    33,   114,   169,   129,   131,    -1,    33,    41,   183,
     108,   150,    -1,    33,    41,   183,   108,   166,    -1,    33,
      41,   167,   108,   150,    -1,    33,    41,   167,   108,   166,
      -1,   360,    -1,   363,    -1,    49,    25,     1,    -1,    49,
      61,   665,    -1,    49,    61,   362,   665,    -1,    49,    61,
     665,    97,   361,    -1,    49,    61,   362,   665,    97,   361,
      -1,   665,    -1,   361,   108,   665,    -1,   162,   666,   134,
      -1,   114,    45,   162,    -1,    49,    34,   665,    -1,    49,
      34,   162,   666,   134,   665,    -1,    49,    34,   665,    97,
     361,    -1,    49,    34,   162,   666,   134,   665,    97,   361,
      -1,    33,   162,   666,   134,   665,    -1,    33,   114,    45,
     162,   665,    -1,    33,   114,    47,   162,   665,    -1,   367,
      -1,   366,   191,   367,    -1,   366,   343,   367,    -1,   368,
      -1,   372,    -1,   374,    -1,   378,    -1,   383,    -1,   390,
      -1,   392,    -1,   395,    -1,    33,   114,    80,   369,    -1,
      33,    80,   666,   369,    -1,   370,    -1,   369,   370,    -1,
     371,   134,   580,    -1,    81,    -1,    89,    -1,    82,    -1,
      83,    -1,    84,    -1,    85,    -1,    90,    -1,    86,    -1,
      87,    -1,    88,    -1,    33,    57,   666,    30,    -1,    33,
     266,   624,    -1,    33,   112,   154,   375,    -1,    95,   562,
     376,    -1,   376,    -1,   377,    -1,   139,    -1,   139,   377,
      -1,   144,   421,    -1,    33,   379,   144,   421,    -1,    33,
     379,   139,    -1,    33,   379,   139,   144,   421,    -1,   113,
     119,   666,    -1,   113,   119,   666,   559,    -1,   380,   113,
     119,   666,    -1,   380,   113,   119,   666,   559,    -1,   381,
      -1,   380,   381,    -1,    27,    -1,    27,   158,   382,   188,
      -1,    28,    -1,    28,   158,   382,   188,    -1,   519,    -1,
     382,   108,   519,    -1,    33,   384,    -1,    33,   380,   384,
      -1,   385,    -1,   386,    -1,    47,   667,   387,   404,    -1,
      47,   667,   387,   139,    -1,    75,    47,   667,   387,   404,
      -1,    75,    47,   667,   387,   139,    -1,   158,   188,    -1,
     158,   388,   188,    -1,   158,   188,    95,   560,    -1,   158,
     388,   188,    95,   560,    -1,   389,    -1,   388,   108,   389,
      -1,   119,   666,    -1,   119,   666,   559,    -1,    33,   292,
     666,    -1,    33,   292,   666,    95,   391,    -1,    33,   380,
     292,   666,    -1,    33,   380,   292,   666,    95,   391,    -1,
     566,    -1,   566,   561,    -1,   661,    -1,   661,   561,    -1,
      33,   300,   666,   304,   232,   502,   171,   393,    -1,    33,
     380,   300,   666,   304,   232,   502,   171,   393,    -1,   394,
      -1,   393,   108,   394,    -1,   502,    -1,   502,   559,    -1,
     502,   457,    -1,   502,   559,   457,    -1,    33,   308,   309,
     666,   304,   292,   666,   119,   666,   310,   421,    -1,    33,
     308,   309,   666,   304,   292,   666,   230,   119,   666,   310,
     298,   311,   502,    -1,    33,   308,   309,   666,   304,   292,
     666,   312,   230,   119,   666,   310,   421,    -1,    33,   308,
     309,   666,   313,   311,   262,   292,   666,   230,   119,   666,
     311,   502,   200,   292,   666,   230,   119,   666,   311,   502,
      -1,   397,    -1,   399,    -1,   400,    -1,    -1,   399,    -1,
     400,    -1,    -1,   420,    -1,   400,   420,    -1,   401,    -1,
     400,   401,    -1,   400,   420,   343,   401,    -1,   402,    -1,
     405,    -1,   408,    -1,   409,    -1,   410,    -1,   411,    -1,
     412,    -1,   413,    -1,   415,    -1,   469,    -1,   465,    -1,
     416,    -1,   419,    -1,   155,   400,   185,    -1,   155,   398,
     185,    -1,   155,   398,   185,    -1,   406,   191,    -1,   406,
     108,   407,    -1,   113,   407,    -1,   380,   113,   407,    -1,
     119,   666,    -1,   119,   666,   559,    -1,   119,   666,   144,
     421,    -1,   119,   666,   559,   144,   421,    -1,   119,   666,
     144,   421,   191,    -1,   422,   191,    -1,   245,   247,   421,
     191,    -1,   248,   158,   420,   188,   401,    -1,   243,   246,
     191,    -1,   244,   246,   191,    -1,   432,   414,    -1,   187,
     401,    -1,    48,   158,   420,   188,   199,   401,   128,   401,
      -1,   249,   402,   417,    -1,   418,    -1,   417,   418,    -1,
     250,   597,   402,    -1,   191,    -1,   421,    -1,   420,   108,
     421,    -1,   420,   343,   421,    -1,   423,    -1,   461,    -1,
     468,    -1,   475,    -1,   593,    -1,   422,    -1,   476,    -1,
     458,    -1,   586,    -1,   587,    -1,   589,    -1,   588,    -1,
     590,    -1,   658,    -1,   656,    -1,   659,    -1,   660,    -1,
     657,    -1,   432,   424,    -1,   187,   421,    -1,    67,   289,
      -1,    72,   289,    -1,   219,    -1,   259,    -1,    56,   259,
      -1,   426,   443,    78,   421,    -1,   426,    78,   421,    -1,
     434,   425,   442,   427,   427,    -1,   434,   425,   442,   427,
      -1,    42,   119,   666,    -1,   433,    -1,   439,    -1,   428,
      -1,   430,    -1,   446,    -1,   451,    -1,   447,    -1,   429,
      -1,   430,    -1,   432,   431,    -1,   434,   119,   435,    -1,
      46,     1,   435,    -1,   262,     1,   435,    -1,   434,     3,
      -1,    46,    -1,   262,    -1,   436,    -1,   435,   108,   119,
     436,    -1,   435,   108,   436,    -1,   666,   149,   421,    -1,
     666,    36,   129,   149,   421,    -1,   666,   559,   149,   421,
      -1,   666,   559,    36,   129,   149,   421,    -1,   666,   437,
     149,   421,    -1,   666,    36,   129,   437,   149,   421,    -1,
     666,   559,   437,   149,   421,    -1,   666,   559,    36,   129,
     437,   149,   421,    -1,   666,   438,   149,   421,    -1,   666,
     559,   438,   149,   421,    -1,   666,   437,   438,   149,   421,
      -1,   666,   559,   437,   438,   149,   421,    -1,    97,   119,
     666,    -1,   278,   119,   666,    -1,    51,   440,    -1,   441,
      -1,   440,   108,   441,    -1,   119,   666,   144,   421,    -1,
     119,   666,   559,   144,   421,    -1,   438,   144,   421,    -1,
     119,   666,   559,   438,   144,   421,    -1,   119,   666,   149,
     421,    -1,   119,   666,   559,   149,   421,    -1,   444,    -1,
     119,   666,    -1,   119,   666,   444,    -1,   437,    -1,   437,
     445,    -1,   445,    -1,    59,   119,   666,    54,   119,   666,
      -1,    54,   119,   666,    -1,    59,   119,   666,    -1,   213,
     421,    -1,   172,   171,   448,    -1,   449,    -1,   448,   108,
     449,    -1,   119,   666,    -1,   119,   666,   144,   421,    -1,
     119,   666,   559,   144,   421,    -1,   119,   666,   559,   144,
     421,   450,    -1,   119,   666,   144,   421,   450,    -1,   119,
     666,   450,    -1,   107,   665,    -1,   169,   171,   452,    -1,
      70,   169,   171,   452,    -1,   453,    -1,   452,   108,   453,
      -1,   421,    -1,   421,   454,    -1,   455,    -1,   456,    -1,
     457,    -1,   455,   456,    -1,   455,   457,    -1,   456,   457,
      -1,   455,   456,   457,    -1,    96,    -1,   117,    -1,   129,
     130,    -1,   129,   131,    -1,   107,   665,    -1,    68,   119,
     459,   189,   421,    -1,   137,   119,   459,   189,   421,    -1,
     460,    -1,   459,   108,   119,   460,    -1,   666,   149,   421,
      -1,   666,   559,   149,   421,    -1,    73,   158,   420,   188,
     462,   114,   187,   421,    -1,   463,    -1,   462,   463,    -1,
     464,   187,   421,    -1,   101,   421,    -1,   464,   101,   421,
      -1,    73,   158,   420,   188,   466,   114,   187,   401,    -1,
     467,    -1,   466,   467,    -1,   464,   187,   401,    -1,    74,
     158,   420,   188,   470,   114,   187,   421,    -1,    74,   158,
     420,   188,   470,   114,   119,   666,   187,   421,    -1,    74,
     158,   420,   188,   472,   114,   187,   401,    -1,    74,   158,
     420,   188,   470,   114,   119,   666,   187,   401,    -1,   471,
      -1,   470,   471,    -1,   101,   474,   187,   421,    -1,   101,
     119,   666,    95,   474,   187,   421,    -1,   473,    -1,   472,
     473,    -1,   101,   474,   187,   401,    -1,   101,   119,   666,
      95,   474,   187,   401,    -1,   560,    -1,   474,   211,   560,
      -1,    48,   158,   420,   188,   199,   421,   128,   421,    -1,
     477,    -1,   476,   168,   477,    -1,   478,    -1,   477,    93,
     478,    -1,   479,    -1,   265,   478,    -1,   480,    -1,   480,
     497,   480,    -1,   481,    -1,   481,   254,    71,   598,   482,
      -1,   483,    -1,   483,   100,   481,    -1,    -1,   650,    -1,
     484,    -1,   484,   200,   484,    -1,   485,    -1,   484,   177,
     485,    -1,   484,   160,   485,    -1,   486,    -1,   485,   195,
     486,    -1,   485,   118,   486,    -1,   485,   148,   486,    -1,
     485,   161,   486,    -1,   487,    -1,   486,   202,   487,    -1,
     486,   211,   487,    -1,   488,    -1,   487,   152,   488,    -1,
     487,   138,   488,    -1,   489,    -1,   489,    50,   236,   560,
      -1,   490,    -1,   490,   201,    95,   560,    -1,   491,    -1,
     491,   102,    95,   492,    -1,   493,    -1,   493,   103,    95,
     492,    -1,   565,    -1,   565,   146,    -1,   495,    -1,   494,
     495,    -1,   177,    -1,   160,    -1,   494,   177,    -1,   494,
     160,    -1,   498,    -1,   496,    -1,   499,    -1,   502,    -1,
     496,   194,   502,    -1,   204,    -1,   209,    -1,   208,    -1,
     207,    -1,   206,    -1,   205,    -1,    76,   155,   399,   185,
      -1,    76,   227,   155,   399,   185,    -1,    76,   226,   155,
     399,   185,    -1,    76,    77,   578,   155,   399,   185,    -1,
     500,   155,   185,    -1,   500,   155,   420,   185,    -1,   501,
      -1,   500,   501,    -1,   178,   666,    17,    -1,   178,    18,
      -1,   178,    19,    -1,   503,    -1,   503,   504,    -1,   193,
     504,    -1,   504,    -1,   192,    -1,   505,    -1,   505,   192,
     504,    -1,   505,   193,   504,    -1,   506,    -1,   515,    -1,
     507,    -1,   507,   516,    -1,   510,    -1,   510,   516,    -1,
     508,   512,    -1,   509,    -1,   106,   124,    -1,   115,   124,
      -1,    98,   124,    -1,   190,   124,    -1,   116,   124,    -1,
     141,   124,    -1,   140,   124,    -1,   512,    -1,    99,   512,
      -1,   511,   512,    -1,   122,    -1,   173,   124,    -1,    91,
     124,    -1,   182,   124,    -1,   181,   124,    -1,    92,   124,
      -1,   566,    -1,   513,    -1,   666,    -1,   514,    -1,   195,
      -1,    11,    -1,    12,    -1,    20,    -1,   518,    -1,   515,
     516,    -1,   515,   158,   188,    -1,   515,   158,   528,   188,
      -1,   515,   121,   666,    -1,   515,   121,   158,   188,    -1,
     515,   121,   158,   420,   188,    -1,   515,   121,   522,    -1,
     515,   121,   580,    -1,   517,    -1,   516,   517,    -1,   156,
     420,   186,    -1,   519,    -1,   522,    -1,   523,    -1,   524,
      -1,   527,    -1,   532,    -1,   525,    -1,   526,    -1,   529,
      -1,   403,    -1,   654,    -1,   651,    -1,   652,    -1,   653,
      -1,   520,    -1,   580,    -1,   521,    -1,   220,    -1,   111,
      -1,   151,    -1,   126,    -1,   221,    -1,   222,    -1,   119,
     666,    -1,   158,   188,    -1,   158,   420,   188,    -1,   120,
      -1,   170,   155,   420,   185,    -1,   203,   155,   420,   185,
      -1,   667,   158,   188,    -1,   667,   158,   528,   188,    -1,
     146,    -1,   528,   108,   146,    -1,   421,    -1,   528,   108,
     421,    -1,   530,    -1,   531,    -1,   667,   147,   151,    -1,
      47,   387,   404,    -1,   533,    -1,   551,    -1,   534,    -1,
     548,    -1,   549,    -1,   159,   666,   538,   132,    -1,   159,
     666,   538,   198,   196,   666,   538,   198,    -1,   159,   666,
     536,   538,   132,    -1,   159,   666,   536,   538,   198,   196,
     666,   538,   198,    -1,   159,   666,   538,   198,   535,   196,
     666,   538,   198,    -1,   159,   666,   536,   538,   198,   535,
     196,   666,   538,   198,    -1,   546,    -1,   535,   546,    -1,
     537,    -1,   536,   537,    -1,    35,   666,   538,   134,   538,
     539,    -1,    -1,    35,    -1,   184,   540,   184,    -1,    94,
     542,    94,    -1,    -1,   541,    -1,   136,    -1,   544,    -1,
     541,   136,    -1,   541,   544,    -1,    -1,   543,    -1,   135,
      -1,   545,    -1,   543,   135,    -1,   543,   545,    -1,    29,
      -1,   547,    -1,     5,    -1,   547,    -1,   533,    -1,    10,
      -1,   550,    -1,   547,    -1,     9,    -1,   125,    -1,   127,
      -1,   155,   399,   185,    -1,   214,    31,   215,    -1,   214,
     215,    -1,   175,   666,   176,    -1,   175,   666,     8,    -1,
     104,     7,    -1,   552,    -1,   553,    -1,   554,    -1,   555,
      -1,   556,    -1,   557,    -1,   558,    -1,    43,   155,   399,
     185,    -1,    21,   398,   185,    -1,    45,   155,   420,   185,
     155,   398,   185,    -1,    22,   398,   185,    -1,    98,   155,
     420,   185,   155,   398,   185,    -1,    71,   155,   399,   185,
      -1,    39,   155,   399,   185,    -1,    23,   398,   185,    -1,
      60,   155,   420,   185,   155,   398,   185,    -1,    24,   399,
     185,    -1,   162,   155,   420,   185,   155,   399,   185,    -1,
      95,   560,    -1,   562,    -1,   562,   561,    -1,   212,   158,
     188,    -1,   158,   188,    -1,   146,    -1,   195,    -1,   177,
      -1,   564,    -1,   566,    -1,   154,   158,   188,    -1,   154,
      -1,   325,   158,   188,    -1,   325,    -1,   581,    -1,   584,
      -1,   661,    -1,   560,    -1,   563,   108,   560,    -1,   666,
      -1,   666,    -1,   569,    -1,   576,    -1,   574,    -1,   577,
      -1,   575,    -1,   573,    -1,   572,    -1,   571,    -1,   570,
      -1,   567,    -1,   568,   158,   188,    -1,   230,    -1,    44,
     158,   188,    -1,    44,   158,   576,   188,    -1,    44,   158,
     577,   188,    -1,    53,   158,   188,    -1,    71,   158,   188,
      -1,    39,   158,   188,    -1,    60,   158,   188,    -1,    60,
     158,   666,   188,    -1,    60,   158,    30,   188,    -1,    98,
     158,   188,    -1,    98,   158,   666,   188,    -1,    98,   158,
     666,   108,   578,   188,    -1,    98,   158,   195,   188,    -1,
      98,   158,   195,   108,   578,   188,    -1,    62,   158,   666,
     188,    -1,    45,   158,   188,    -1,    45,   158,   666,   188,
      -1,    45,   158,   666,   108,   578,   188,    -1,    45,   158,
     666,   108,   579,   188,    -1,    45,   158,   195,   188,    -1,
      45,   158,   195,   108,   578,   188,    -1,    45,   158,   195,
     108,   579,   188,    -1,    63,   158,   666,   188,    -1,   666,
      -1,   666,   146,    -1,    30,    -1,   582,    -1,   583,    -1,
      47,   158,   195,   188,    -1,    47,   158,   188,    95,   560,
      -1,    47,   158,   563,   188,    95,   560,    -1,   158,   562,
     188,    -1,    33,   225,   226,    -1,    33,   225,   227,    -1,
      33,   225,   228,    -1,   231,   230,   421,   238,   421,    -1,
     231,   230,   421,    95,   237,   238,   421,    -1,   231,   230,
     421,    95,   239,   238,   421,    -1,   231,   230,   421,   223,
     421,    -1,   231,   230,   421,   224,   421,    -1,   231,   232,
     421,   238,   421,    -1,   231,   232,   421,    95,   237,   238,
     421,    -1,   231,   232,   421,    95,   239,   238,   421,    -1,
     231,   232,   421,   223,   421,    -1,   231,   232,   421,   224,
     421,    -1,   229,   230,   421,    -1,   229,   232,   421,    -1,
     234,   230,   421,   242,   421,    -1,   234,   235,   236,   230,
     421,   242,   421,    -1,   233,   230,   421,    95,   421,    -1,
     241,   119,   591,   240,   421,   187,   421,    -1,   592,    -1,
     591,   108,   119,   592,    -1,   666,   144,   421,    -1,   249,
     155,   420,   185,   594,    -1,   595,    -1,   594,   595,    -1,
     250,   597,   596,    -1,   155,   420,   185,    -1,   513,    -1,
     597,   211,   513,    -1,   601,   599,    -1,    -1,   600,    -1,
     619,    -1,   600,   619,    -1,   602,    -1,   601,   267,   602,
      -1,   603,    -1,   602,   263,   603,    -1,   604,    -1,   603,
     265,   149,   604,    -1,   605,    -1,   264,   605,    -1,   609,
     606,   607,    -1,    -1,   624,    -1,    -1,   608,    -1,   287,
     155,   420,   185,    -1,   613,   610,    -1,   158,   598,   188,
      -1,   611,    -1,    -1,   646,    -1,   500,   155,   612,   185,
      -1,    -1,   598,    -1,   614,   615,    -1,   519,    -1,   155,
     420,   185,    -1,    -1,   616,    -1,   253,   617,    -1,   252,
     618,    -1,   275,    -1,    -1,    79,    -1,    -1,   291,    -1,
     620,    -1,   621,    -1,   622,    -1,   648,    -1,   645,    -1,
     170,    -1,   289,   484,   623,    -1,   258,   647,   623,    -1,
     291,    -1,   281,    -1,   274,    -1,   251,   625,    -1,   624,
     251,   625,    -1,   626,    -1,   627,    -1,   628,    -1,   643,
      -1,   629,    -1,   637,    -1,   630,    -1,   644,    -1,   101,
     279,    -1,   101,   268,    -1,   271,    -1,   286,    -1,   256,
     279,    -1,   256,   268,    -1,    57,   666,    30,    -1,   282,
      -1,    55,   282,    -1,   284,   631,    -1,   284,   158,   631,
     632,   188,    -1,    55,   284,    -1,   634,    -1,   114,    -1,
      -1,   108,   633,    -1,   634,    -1,   633,   108,   634,    -1,
      97,    30,   635,   636,    -1,    -1,   276,    30,    -1,    -1,
     647,   270,    -1,   283,   291,   638,   640,    -1,   283,   291,
     114,   640,    -1,    55,   283,   291,    -1,    97,    30,    -1,
     158,   639,   188,    -1,    30,    -1,   639,   108,    30,    -1,
      -1,   641,    -1,   642,    -1,   641,   642,    -1,   202,   638,
      -1,   138,   638,    -1,   269,    30,    -1,   288,    -1,    55,
     288,    -1,    97,   219,    -1,    97,   259,    -1,   260,   255,
      -1,   272,   647,   285,    -1,   261,   484,    -1,    97,   131,
     484,    -1,    97,    52,   484,    -1,   262,   484,   200,   484,
      -1,   277,   649,    -1,   257,   649,    -1,   280,    -1,   273,
      -1,   290,   255,   486,    -1,   156,   186,    -1,   156,   420,
     186,    -1,   315,   316,    -1,   315,   420,   316,    -1,   317,
     318,    -1,   317,   420,   318,    -1,   155,   655,   185,    -1,
     666,   123,   421,    -1,   421,   123,   421,    -1,   655,   108,
     421,   123,   421,    -1,   655,   108,   666,   123,   421,    -1,
     231,   319,   421,   238,   421,    -1,   231,   319,   655,   238,
     421,    -1,   231,   319,   421,   238,   421,    97,   321,   421,
      -1,   231,   421,   238,   421,    -1,   231,   655,   238,   421,
      -1,   231,   421,   238,   421,    97,   321,   421,    -1,   320,
     319,   421,   238,   421,    -1,   320,   421,   238,   421,    -1,
     229,   319,   515,    -1,   229,   515,    -1,   233,   319,   515,
      95,   421,    -1,   233,   515,    95,   421,    -1,   234,   319,
     235,   236,   515,   242,   421,    -1,   234,   235,   236,   515,
     242,   421,    -1,   662,    -1,   663,    -1,   664,    -1,   324,
     158,   188,    -1,   324,    -1,   322,   158,   188,    -1,   322,
      -1,   323,   158,   188,    -1,   323,    -1,    30,    -1,   667,
      -1,    16,    -1,    98,    -1,    39,    -1,    44,    -1,    53,
      -1,    45,    -1,    48,    -1,   230,    -1,    60,    -1,    62,
      -1,    63,    -1,    71,    -1,    74,    -1,    73,    -1,   212,
      -1,   248,    -1,   668,    -1,    25,    -1,   216,    -1,   129,
      -1,    38,    -1,   266,    -1,    37,    -1,   227,    -1,   226,
      -1,   148,    -1,    43,    -1,   264,    -1,   265,    -1,   279,
      -1,   268,    -1,   256,    -1,   290,    -1,   282,    -1,   284,
      -1,   283,    -1,   288,    -1,   260,    -1,   255,    -1,    79,
      -1,   219,    -1,   259,    -1,    52,    -1,   228,    -1,   241,
      -1,   307,    -1,   235,    -1,   204,    -1,   209,    -1,   208,
      -1,   207,    -1,   206,    -1,   205,    -1,    97,    -1,   112,
      -1,   113,    -1,   187,    -1,    46,    -1,   262,    -1,    36,
      -1,    67,    -1,    72,    -1,    59,    -1,    54,    -1,    56,
      -1,    78,    -1,    42,    -1,   149,    -1,    51,    -1,   213,
      -1,   171,    -1,   172,    -1,   169,    -1,    70,    -1,    96,
      -1,   117,    -1,   130,    -1,   131,    -1,   107,    -1,    68,
      -1,   137,    -1,   189,    -1,   101,    -1,    95,    -1,   199,
      -1,   128,    -1,   168,    -1,    93,    -1,    50,    -1,   236,
      -1,   102,    -1,   200,    -1,   118,    -1,   161,    -1,   202,
      -1,   152,    -1,   138,    -1,    76,    -1,    77,    -1,   103,
      -1,   201,    -1,   153,    -1,   183,    -1,   197,    -1,   162,
      -1,   139,    -1,   133,    -1,   167,    -1,   150,    -1,   166,
      -1,    33,    -1,    40,    -1,    58,    -1,   114,    -1,    41,
      -1,    57,    -1,   218,    -1,    49,    -1,    61,    -1,    34,
      -1,    47,    -1,   278,    -1,   254,    -1,   287,    -1,   289,
      -1,   258,    -1,   272,    -1,   285,    -1,   277,    -1,   257,
      -1,   271,    -1,   286,    -1,   276,    -1,   270,    -1,   269,
      -1,   253,    -1,   252,    -1,   261,    -1,   291,    -1,   281,
      -1,   280,    -1,   275,    -1,   273,    -1,   274,    -1,   240,
      -1,   237,    -1,   224,    -1,   223,    -1,   225,    -1,   242,
      -1,   232,    -1,   239,    -1,   238,    -1,    66,    -1,    64,
      -1,    75,    -1,   170,    -1,   203,    -1,   247,    -1,   245,
      -1,   246,    -1,   243,    -1,   244,    -1,   249,    -1,   250,
      -1,   251,    -1,    65,    -1,   300,    -1,   298,    -1,   299,
      -1,   304,    -1,   305,    -1,   306,    -1,   301,    -1,   302,
      -1,   303,    -1,    80,    -1,    81,    -1,    82,    -1,    83,
      -1,    84,    -1,    85,    -1,    86,    -1,    87,    -1,    88,
      -1,    89,    -1,    90,    -1,   292,    -1,   293,    -1,   294,
      -1,   295,    -1,   296,    -1,   297,    -1,   308,    -1,   309,
      -1,   310,    -1,   311,    -1,   312,    -1,   313,    -1,   314,
      -1,    91,    -1,   106,    -1,   115,    -1,   173,    -1,   181,
      -1,   190,    -1,   140,    -1,    92,    -1,   116,    -1,   141,
      -1,   182,    -1,   321,    -1,    26,    -1
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
    1116,  1118,  1122,  1125,  1130,  1136,  1143,  1149,  1153,  1156,
    1160,  1165,  1167,  1171,  1173,  1176,  1178,  1180,  1182,  1185,
    1188,  1191,  1195,  1197,  1199,  1202,  1205,  1208,  1214,  1220,
    1222,  1227,  1231,  1236,  1245,  1247,  1250,  1254,  1257,  1261,
    1270,  1272,  1275,  1279,  1288,  1299,  1308,  1319,  1321,  1324,
    1329,  1337,  1339,  1342,  1347,  1355,  1357,  1361,  1370,  1372,
    1376,  1378,  1382,  1384,  1387,  1389,  1393,  1395,  1401,  1403,
    1407,  1408,  1410,  1412,  1416,  1418,  1422,  1426,  1428,  1432,
    1436,  1440,  1444,  1446,  1450,  1454,  1456,  1460,  1464,  1466,
    1471,  1473,  1478,  1480,  1485,  1487,  1492,  1494,  1497,  1499,
    1502,  1504,  1506,  1509,  1512,  1514,  1516,  1518,  1520,  1524,
    1526,  1528,  1530,  1532,  1534,  1536,  1541,  1547,  1553,  1560,
    1564,  1569,  1571,  1574,  1578,  1581,  1584,  1586,  1589,  1592,
    1594,  1596,  1598,  1602,  1606,  1608,  1610,  1612,  1615,  1617,
    1620,  1623,  1625,  1628,  1631,  1634,  1637,  1640,  1643,  1646,
    1648,  1651,  1654,  1656,  1659,  1662,  1665,  1668,  1671,  1673,
    1675,  1677,  1679,  1681,  1683,  1685,  1687,  1689,  1692,  1696,
    1701,  1705,  1710,  1716,  1720,  1724,  1726,  1729,  1733,  1735,
    1737,  1739,  1741,  1743,  1745,  1747,  1749,  1751,  1753,  1755,
    1757,  1759,  1761,  1763,  1765,  1767,  1769,  1771,  1773,  1775,
    1777,  1779,  1782,  1785,  1789,  1791,  1796,  1801,  1805,  1810,
    1812,  1816,  1818,  1822,  1824,  1826,  1830,  1834,  1836,  1838,
    1840,  1842,  1844,  1849,  1858,  1864,  1874,  1884,  1895,  1897,
    1900,  1902,  1905,  1912,  1913,  1915,  1919,  1923,  1924,  1926,
    1928,  1930,  1933,  1936,  1937,  1939,  1941,  1943,  1946,  1949,
    1951,  1953,  1955,  1957,  1959,  1961,  1963,  1965,  1967,  1969,
    1971,  1975,  1979,  1982,  1986,  1990,  1993,  1995,  1997,  1999,
    2001,  2003,  2005,  2007,  2012,  2016,  2024,  2028,  2036,  2041,
    2046,  2050,  2058,  2062,  2070,  2073,  2075,  2078,  2082,  2085,
    2087,  2089,  2091,  2093,  2095,  2099,  2101,  2105,  2107,  2109,
    2111,  2113,  2115,  2119,  2121,  2123,  2125,  2127,  2129,  2131,
    2133,  2135,  2137,  2139,  2141,  2143,  2147,  2149,  2153,  2158,
    2163,  2167,  2171,  2175,  2179,  2184,  2189,  2193,  2198,  2205,
    2210,  2217,  2222,  2226,  2231,  2238,  2245,  2250,  2257,  2264,
    2269,  2271,  2274,  2276,  2278,  2280,  2285,  2291,  2298,  2302,
    2306,  2310,  2314,  2320,  2328,  2336,  2342,  2348,  2354,  2362,
    2370,  2376,  2382,  2386,  2390,  2396,  2404,  2410,  2418,  2420,
    2425,  2429,  2435,  2437,  2440,  2444,  2448,  2450,  2454,  2457,
    2458,  2460,  2462,  2465,  2467,  2471,  2473,  2477,  2479,  2484,
    2486,  2489,  2493,  2494,  2496,  2497,  2499,  2504,  2507,  2511,
    2513,  2514,  2516,  2521,  2522,  2524,  2527,  2529,  2533,  2534,
    2536,  2539,  2542,  2544,  2545,  2547,  2548,  2550,  2552,  2554,
    2556,  2558,  2560,  2562,  2566,  2570,  2572,  2574,  2576,  2579,
    2583,  2585,  2587,  2589,  2591,  2593,  2595,  2597,  2599,  2602,
    2605,  2607,  2609,  2612,  2615,  2619,  2621,  2624,  2627,  2633,
    2636,  2638,  2640,  2641,  2644,  2646,  2650,  2655,  2656,  2659,
    2660,  2663,  2668,  2673,  2677,  2680,  2684,  2686,  2690,  2691,
    2693,  2695,  2698,  2701,  2704,  2707,  2709,  2712,  2715,  2718,
    2721,  2725,  2728,  2732,  2736,  2741,  2744,  2747,  2749,  2751,
    2755,  2758,  2762,  2765,  2769,  2772,  2776,  2780,  2784,  2788,
    2794,  2800,  2806,  2812,  2821,  2826,  2831,  2839,  2845,  2850,
    2854,  2857,  2863,  2868,  2876,  2883,  2885,  2887,  2889,  2893,
    2895,  2899,  2901,  2905,  2907,  2909,  2911,  2913,  2915,  2917,
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
    3319,  3321,  3323,  3325,  3327,  3329,  3331,  3333,  3335
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  jsoniq_parser::yyrline_[] =
  {
         0,   854,   854,   855,   859,   863,   869,   873,   877,   883,
     889,   897,   903,   912,   917,   922,   927,   933,   939,   945,
     953,   958,   966,   974,   982,   991,   996,  1002,  1008,  1017,
    1025,  1032,  1038,  1047,  1048,  1049,  1050,  1051,  1054,  1055,
    1056,  1057,  1058,  1059,  1060,  1061,  1064,  1069,  1075,  1081,
    1087,  1092,  1098,  1103,  1109,  1114,  1120,  1125,  1130,  1135,
    1141,  1143,  1145,  1153,  1158,  1166,  1174,  1183,  1190,  1198,
    1204,  1210,  1216,  1223,  1231,  1242,  1249,  1256,  1264,  1271,
    1277,  1286,  1287,  1288,  1289,  1290,  1291,  1292,  1293,  1296,
    1302,  1309,  1316,  1324,  1332,  1333,  1334,  1335,  1336,  1337,
    1338,  1339,  1340,  1341,  1344,  1358,  1364,  1370,  1377,  1383,
    1390,  1395,  1401,  1407,  1419,  1431,  1444,  1449,  1457,  1465,
    1474,  1479,  1486,  1491,  1498,  1503,  1511,  1516,  1523,  1529,
    1538,  1543,  1549,  1560,  1573,  1585,  1598,  1603,  1608,  1613,
    1619,  1626,  1634,  1639,  1647,  1655,  1663,  1671,  1681,  1685,
    1691,  1695,  1702,  1711,  1722,  1728,  1735,  1740,  1747,  1754,
    1763,  1773,  1783,  1793,  1808,  1824,  1828,  1833,  1838,  1842,
    1847,  1852,  1857,  1865,  1872,  1879,  1892,  1893,  1894,  1895,
    1896,  1897,  1898,  1899,  1900,  1901,  1902,  1903,  1904,  1907,
    1913,  1935,  1941,  1947,  1954,  1961,  1970,  1979,  1988,  1997,
    2008,  2014,  2020,  2026,  2038,  2043,  2049,  2061,  2074,  2094,
    2100,  2107,  2116,  2123,  2129,  2134,  2146,  2158,  2159,  2160,
    2161,  2162,  2163,  2166,  2167,  2168,  2169,  2170,  2171,  2172,
    2173,  2174,  2175,  2176,  2177,  2180,  2192,  2198,  2203,  2209,
    2214,  2219,  2225,  2234,  2244,  2256,  2268,  2274,  2275,  2276,
    2279,  2280,  2281,  2282,  2283,  2286,  2293,  2301,  2306,  2314,
    2323,  2332,  2333,  2338,  2345,  2352,  2362,  2372,  2382,  2392,
    2402,  2412,  2422,  2432,  2442,  2451,  2461,  2471,  2483,  2489,
    2495,  2501,  2507,  2515,  2523,  2531,  2539,  2549,  2555,  2564,
    2565,  2569,  2576,  2580,  2585,  2588,  2592,  2596,  2602,  2608,
    2614,  2620,  2628,  2632,  2636,  2644,  2652,  2660,  2670,  2676,
    2682,  2690,  2696,  2704,  2708,  2716,  2722,  2728,  2734,  2743,
    2752,  2761,  2772,  2776,  2782,  2788,  2796,  2802,  2811,  2822,
    2828,  2836,  2840,  2849,  2855,  2861,  2869,  2875,  2881,  2889,
    2895,  2901,  2909,  2915,  2922,  2932,  2939,  2949,  2955,  2963,
    2969,  2978,  2984,  2992,  2998,  3007,  3013,  3021,  3027,  3031,
    3037,  3042,  3048,  3052,  3063,  3067,  3078,  3082,  3093,  3097,
    3103,  3106,  3112,  3116,  3122,  3126,  3130,  3136,  3140,  3146,
    3152,  3158,  3166,  3170,  3174,  3180,  3184,  3190,  3198,  3202,
    3210,  3214,  3222,  3226,  3234,  3238,  3246,  3250,  3256,  3260,
    3266,  3270,  3274,  3278,  3286,  3290,  3294,  3300,  3305,  3311,
    3315,  3319,  3323,  3327,  3331,  3337,  3341,  3345,  3349,  3358,
    3364,  3372,  3378,  3386,  3390,  3394,  3400,  3404,  3412,  3421,
    3430,  3436,  3446,  3450,  3456,  3460,  3466,  3472,  3480,  3486,
    3496,  3502,  3510,  3514,  3518,  3522,  3526,  3532,  3538,  3544,
    3548,  3554,  3558,  3567,  3571,  3575,  3581,  3585,  3593,  3597,
    3603,  3607,  3613,  3617,  3621,  3625,  3631,  3635,  3639,  3643,
    3647,  3653,  3657,  3661,  3665,  3671,  3677,  3685,  3691,  3695,
    3699,  3703,  3707,  3711,  3715,  3719,  3723,  3727,  3731,  3735,
    3739,  3743,  3749,  3753,  3757,  3762,  3769,  3776,  3783,  3792,
    3796,  3802,  3808,  3812,  3818,  3824,  3830,  3836,  3840,  3858,
    3864,  3870,  3876,  3884,  3888,  3894,  3900,  3910,  3914,  3920,
    3924,  3928,  3934,  3942,  3958,  3966,  3982,  4000,  4020,  4026,
    4035,  4041,  4050,  4057,  4058,  4060,  4065,  4072,  4075,  4081,
    4087,  4093,  4100,  4109,  4112,  4118,  4124,  4130,  4137,  4146,
    4150,  4156,  4160,  4166,  4170,  4174,  4179,  4186,  4190,  4194,
    4198,  4204,  4209,  4215,  4221,  4228,  4234,  4239,  4244,  4249,
    4254,  4259,  4264,  4267,  4273,  4277,  4283,  4287,  4293,  4299,
    4305,  4309,  4315,  4319,  4325,  4331,  4335,  4339,  4343,  4350,
    4356,  4362,  4370,  4374,  4378,  4382,  4387,  4391,  4396,  4400,
    4404,  4410,  4416,  4424,  4430,  4436,  4440,  4444,  4448,  4452,
    4456,  4460,  4464,  4468,  4472,  4478,  4484,  4490,  4494,  4498,
    4504,  4509,  4515,  4521,  4525,  4530,  4536,  4540,  4546,  4552,
    4556,  4564,  4570,  4574,  4580,  4589,  4598,  4604,  4610,  4618,
    4624,  4630,  4636,  4642,  4646,  4652,  4658,  4662,  4670,  4676,
    4682,  4688,  4696,  4700,  4706,  4712,  4716,  4722,  4726,  4732,
    4738,  4745,  4753,  4758,  4764,  4770,  4778,  4784,  4791,  4797,
    4806,  4812,  4818,  4824,  4833,  4840,  4846,  4852,  4861,  4868,
    4872,  4878,  4883,  4890,  4894,  4900,  4904,  4910,  4914,  4920,
    4924,  4932,  4943,  4946,  4952,  4955,  4961,  4967,  4975,  4979,
    4985,  4988,  4994,  5004,  5007,  5013,  5023,  5029,  5037,  5040,
    5046,  5050,  5054,  5060,  5063,  5069,  5072,  5078,  5082,  5086,
    5090,  5094,  5100,  5106,  5116,  5126,  5130,  5134,  5140,  5146,
    5154,  5158,  5162,  5166,  5170,  5174,  5178,  5182,  5188,  5192,
    5196,  5200,  5206,  5212,  5220,  5228,  5232,  5238,  5248,  5259,
    5265,  5269,  5275,  5278,  5284,  5289,  5296,  5304,  5307,  5313,
    5317,  5323,  5332,  5339,  5347,  5351,  5357,  5363,  5371,  5374,
    5380,  5385,  5395,  5403,  5413,  5419,  5423,  5429,  5433,  5437,
    5443,  5449,  5453,  5457,  5461,  5467,  5475,  5485,  5489,  5495,
    5501,  5505,  5511,  5515,  5521,  5525,  5531,  5538,  5547,  5553,
    5560,  5571,  5577,  5587,  5591,  5598,  5609,  5616,  5620,  5627,
    5646,  5668,  5690,  5715,  5737,  5762,  5766,  5770,  5776,  5780,
    5787,  5791,  5798,  5802,  5809,  5812,  5813,  5814,  5815,  5816,
    5817,  5818,  5819,  5820,  5821,  5822,  5823,  5824,  5825,  5826,
    5827,  5828,  5831,  5832,  5833,  5834,  5835,  5836,  5837,  5838,
    5839,  5840,  5841,  5842,  5843,  5844,  5845,  5846,  5847,  5848,
    5849,  5850,  5851,  5852,  5853,  5854,  5855,  5856,  5857,  5858,
    5859,  5860,  5861,  5862,  5863,  5864,  5865,  5866,  5867,  5868,
    5869,  5870,  5871,  5872,  5873,  5874,  5875,  5876,  5877,  5878,
    5879,  5880,  5881,  5882,  5883,  5884,  5885,  5886,  5887,  5888,
    5889,  5890,  5891,  5892,  5893,  5894,  5895,  5896,  5897,  5898,
    5899,  5900,  5901,  5902,  5903,  5904,  5905,  5906,  5907,  5908,
    5909,  5910,  5911,  5912,  5913,  5914,  5915,  5916,  5917,  5918,
    5919,  5920,  5921,  5922,  5923,  5924,  5925,  5926,  5927,  5928,
    5929,  5930,  5931,  5932,  5933,  5934,  5935,  5936,  5937,  5938,
    5939,  5940,  5941,  5942,  5943,  5944,  5945,  5946,  5947,  5948,
    5949,  5950,  5951,  5952,  5953,  5954,  5955,  5956,  5957,  5958,
    5959,  5960,  5961,  5962,  5963,  5964,  5965,  5966,  5967,  5968,
    5969,  5970,  5971,  5972,  5973,  5974,  5975,  5976,  5977,  5978,
    5979,  5980,  5981,  5982,  5983,  5984,  5985,  5986,  5987,  5988,
    5989,  5990,  5991,  5992,  5993,  5994,  5995,  5996,  5997,  5998,
    5999,  6000,  6001,  6002,  6003,  6004,  6005,  6006,  6007,  6008,
    6009,  6010,  6011,  6012,  6013,  6014,  6015,  6016,  6017,  6018,
    6019,  6020,  6021,  6022,  6023,  6024,  6025,  6026,  6029
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
  const int jsoniq_parser::yylast_ = 20737;
  const int jsoniq_parser::yynnts_ = 328;
  const int jsoniq_parser::yyempty_ = -2;
  const int jsoniq_parser::yyfinal_ = 625;
  const int jsoniq_parser::yyterror_ = 1;
  const int jsoniq_parser::yyerrcode_ = 256;
  const int jsoniq_parser::yyntokens_ = 341;

  const unsigned int jsoniq_parser::yyuser_token_number_max_ = 595;
  const jsoniq_parser::token_number_type jsoniq_parser::yyundef_token_ = 2;


} // zorba

/* Line 1136 of lalr1.cc  */
#line 18717 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"


/* Line 1138 of lalr1.cc  */
#line 6031 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"

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

