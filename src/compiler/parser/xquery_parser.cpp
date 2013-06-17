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
#line 1 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"

#define XQUERY_PARSER

/* Line 293 of lalr1.cc  */
#line 58 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"


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
#line 101 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"


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
#line 102 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"


#include "xquery_parser.hpp"

/* User implementation prologue.  */

/* Line 299 of lalr1.cc  */
#line 786 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"

template<typename T> inline void release_hack( T *ref ) {
    if ( ref ) {
        RCHelper::addReference( ref );
        RCHelper::removeReference( ref );
    }
}


/* Line 299 of lalr1.cc  */
#line 121 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"

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
#line 207 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"

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
    switch (yytype)
      {
         default:
	  break;
      }
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

    YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

    switch (yytype)
      {
        case 111: /* "\"'DECIMAL'\"" */

/* Line 480 of lalr1.cc  */
#line 785 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->decval); };

/* Line 480 of lalr1.cc  */
#line 312 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 125: /* "\"'DOUBLE'\"" */

/* Line 480 of lalr1.cc  */
#line 784 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->dval); };

/* Line 480 of lalr1.cc  */
#line 321 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 150: /* "\"'INTEGER'\"" */

/* Line 480 of lalr1.cc  */
#line 783 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->ival); };

/* Line 480 of lalr1.cc  */
#line 330 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 338: /* "VersionDecl" */

/* Line 480 of lalr1.cc  */
#line 806 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 339 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 339: /* "MainModule" */

/* Line 480 of lalr1.cc  */
#line 799 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 348 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 340: /* "LibraryModule" */

/* Line 480 of lalr1.cc  */
#line 799 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 357 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 341: /* "ModuleDecl" */

/* Line 480 of lalr1.cc  */
#line 799 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 366 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 342: /* "SIND_DeclList" */

/* Line 480 of lalr1.cc  */
#line 802 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 375 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 343: /* "SIND_Decl" */

/* Line 480 of lalr1.cc  */
#line 802 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 384 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 344: /* "Setter" */

/* Line 480 of lalr1.cc  */
#line 803 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 393 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 345: /* "BoundarySpaceDecl" */

/* Line 480 of lalr1.cc  */
#line 796 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 402 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 346: /* "DefaultCollationDecl" */

/* Line 480 of lalr1.cc  */
#line 797 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 411 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 347: /* "BaseURIDecl" */

/* Line 480 of lalr1.cc  */
#line 796 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 420 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 348: /* "ConstructionDecl" */

/* Line 480 of lalr1.cc  */
#line 796 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 429 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 349: /* "OrderingModeDecl" */

/* Line 480 of lalr1.cc  */
#line 801 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 438 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 350: /* "EmptyOrderDecl" */

/* Line 480 of lalr1.cc  */
#line 798 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 447 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 351: /* "CopyNamespacesDecl" */

/* Line 480 of lalr1.cc  */
#line 797 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 456 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 352: /* "Import" */

/* Line 480 of lalr1.cc  */
#line 798 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 465 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 353: /* "SchemaImport" */

/* Line 480 of lalr1.cc  */
#line 802 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 474 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 354: /* "URILiteralList" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 483 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 355: /* "SchemaPrefix" */

/* Line 480 of lalr1.cc  */
#line 803 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 492 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 356: /* "ModuleImport" */

/* Line 480 of lalr1.cc  */
#line 799 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 501 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 357: /* "NamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 799 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 510 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 358: /* "DefaultNamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 797 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 519 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 359: /* "VFO_DeclList" */

/* Line 480 of lalr1.cc  */
#line 806 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 528 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 360: /* "VFO_Decl" */

/* Line 480 of lalr1.cc  */
#line 806 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 537 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 361: /* "DecimalFormatDecl" */

/* Line 480 of lalr1.cc  */
#line 806 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 546 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 362: /* "DecimalFormatParamList" */

/* Line 480 of lalr1.cc  */
#line 813 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->vstrpair); };

/* Line 480 of lalr1.cc  */
#line 555 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 363: /* "DecimalFormatParam" */

/* Line 480 of lalr1.cc  */
#line 813 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->strpair); };

/* Line 480 of lalr1.cc  */
#line 564 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 365: /* "OptionDecl" */

/* Line 480 of lalr1.cc  */
#line 800 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 573 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 366: /* "FTOptionDecl" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 582 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 367: /* "CtxItemDecl" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 591 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 368: /* "CtxItemDecl2" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 600 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 369: /* "CtxItemDecl3" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 609 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 370: /* "CtxItemDecl4" */

/* Line 480 of lalr1.cc  */
#line 805 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 618 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 371: /* "VarDecl" */

/* Line 480 of lalr1.cc  */
#line 805 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 627 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 372: /* "VarNameAndType" */

/* Line 480 of lalr1.cc  */
#line 813 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->varnametype); };

/* Line 480 of lalr1.cc  */
#line 636 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 373: /* "AnnotationList" */

/* Line 480 of lalr1.cc  */
#line 795 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 645 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 374: /* "Annotation" */

/* Line 480 of lalr1.cc  */
#line 795 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 654 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 375: /* "AnnotationLiteralList" */

/* Line 480 of lalr1.cc  */
#line 795 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 663 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 376: /* "FunctionDecl" */

/* Line 480 of lalr1.cc  */
#line 798 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 672 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 377: /* "FunctionDecl2" */

/* Line 480 of lalr1.cc  */
#line 798 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 681 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 378: /* "FunctionDeclSimple" */

/* Line 480 of lalr1.cc  */
#line 798 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 690 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 379: /* "FunctionDeclUpdating" */

/* Line 480 of lalr1.cc  */
#line 798 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 699 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 380: /* "FunctionSig" */

/* Line 480 of lalr1.cc  */
#line 813 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->fnsig); };

/* Line 480 of lalr1.cc  */
#line 708 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 381: /* "ParamList" */

/* Line 480 of lalr1.cc  */
#line 801 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 717 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 382: /* "Param" */

/* Line 480 of lalr1.cc  */
#line 801 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 726 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 383: /* "CollectionDecl" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 735 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 385: /* "IndexDecl" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 744 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 386: /* "IndexKeyList" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 753 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 387: /* "IndexKeySpec" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 762 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 388: /* "IntegrityConstraintDecl" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 771 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 389: /* "QueryBody" */

/* Line 480 of lalr1.cc  */
#line 812 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 780 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 390: /* "StatementsAndOptionalExprTop" */

/* Line 480 of lalr1.cc  */
#line 812 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 789 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 391: /* "StatementsAndOptionalExpr" */

/* Line 480 of lalr1.cc  */
#line 812 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 798 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 392: /* "StatementsAndExpr" */

/* Line 480 of lalr1.cc  */
#line 812 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 807 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 393: /* "Statements" */

/* Line 480 of lalr1.cc  */
#line 812 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 816 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 394: /* "Statement" */

/* Line 480 of lalr1.cc  */
#line 812 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 825 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 395: /* "BlockStatement" */

/* Line 480 of lalr1.cc  */
#line 812 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 834 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 396: /* "BlockExpr" */

/* Line 480 of lalr1.cc  */
#line 812 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 843 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 397: /* "EnclosedStatementsAndOptionalExpr" */

/* Line 480 of lalr1.cc  */
#line 812 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 852 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 398: /* "VarDeclStatement" */

/* Line 480 of lalr1.cc  */
#line 812 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 861 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 401: /* "AssignStatement" */

/* Line 480 of lalr1.cc  */
#line 812 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 870 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 402: /* "ApplyStatement" */

/* Line 480 of lalr1.cc  */
#line 812 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 879 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 403: /* "ExitStatement" */

/* Line 480 of lalr1.cc  */
#line 812 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 888 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 404: /* "WhileStatement" */

/* Line 480 of lalr1.cc  */
#line 812 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 897 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 405: /* "FlowCtlStatement" */

/* Line 480 of lalr1.cc  */
#line 812 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 906 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 406: /* "FLWORStatement" */

/* Line 480 of lalr1.cc  */
#line 812 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 915 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 407: /* "ReturnStatement" */

/* Line 480 of lalr1.cc  */
#line 812 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 924 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 408: /* "IfStatement" */

/* Line 480 of lalr1.cc  */
#line 812 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 933 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 409: /* "TryStatement" */

/* Line 480 of lalr1.cc  */
#line 812 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 942 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 410: /* "CatchListStatement" */

/* Line 480 of lalr1.cc  */
#line 812 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 951 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 411: /* "CatchStatement" */

/* Line 480 of lalr1.cc  */
#line 812 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 960 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 412: /* "Expr" */

/* Line 480 of lalr1.cc  */
#line 812 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 969 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 413: /* "ExprSingle" */

/* Line 480 of lalr1.cc  */
#line 812 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 978 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 414: /* "ExprSimple" */

/* Line 480 of lalr1.cc  */
#line 812 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 987 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 415: /* "FLWORExpr" */

/* Line 480 of lalr1.cc  */
#line 812 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 996 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 416: /* "ReturnExpr" */

/* Line 480 of lalr1.cc  */
#line 812 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1005 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 419: /* "FLWORWinCond" */

/* Line 480 of lalr1.cc  */
#line 805 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1014 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 420: /* "WindowClause" */

/* Line 480 of lalr1.cc  */
#line 798 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1023 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 421: /* "CountClause" */

/* Line 480 of lalr1.cc  */
#line 806 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1032 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 422: /* "ForLetWinClause" */

/* Line 480 of lalr1.cc  */
#line 798 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1041 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 424: /* "FLWORClauseList" */

/* Line 480 of lalr1.cc  */
#line 798 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1050 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 425: /* "ForClause" */

/* Line 480 of lalr1.cc  */
#line 798 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1059 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 426: /* "VarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 805 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1068 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 427: /* "VarInDecl" */

/* Line 480 of lalr1.cc  */
#line 805 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1077 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 428: /* "PositionalVar" */

/* Line 480 of lalr1.cc  */
#line 801 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1086 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 429: /* "FTScoreVar" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1095 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 430: /* "LetClause" */

/* Line 480 of lalr1.cc  */
#line 799 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1104 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 431: /* "VarGetsDeclList" */

/* Line 480 of lalr1.cc  */
#line 805 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1113 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 432: /* "VarGetsDecl" */

/* Line 480 of lalr1.cc  */
#line 805 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1122 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 433: /* "WindowVarDecl" */

/* Line 480 of lalr1.cc  */
#line 805 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1131 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 434: /* "WindowVars" */

/* Line 480 of lalr1.cc  */
#line 805 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1140 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 435: /* "WindowVars3" */

/* Line 480 of lalr1.cc  */
#line 805 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1149 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 436: /* "WindowVars2" */

/* Line 480 of lalr1.cc  */
#line 805 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1158 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 437: /* "WhereClause" */

/* Line 480 of lalr1.cc  */
#line 806 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1167 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 438: /* "GroupByClause" */

/* Line 480 of lalr1.cc  */
#line 800 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1176 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 439: /* "GroupSpecList" */

/* Line 480 of lalr1.cc  */
#line 800 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1185 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 440: /* "GroupSpec" */

/* Line 480 of lalr1.cc  */
#line 800 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1194 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 441: /* "GroupCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 800 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1203 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 442: /* "OrderByClause" */

/* Line 480 of lalr1.cc  */
#line 800 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1212 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 443: /* "OrderSpecList" */

/* Line 480 of lalr1.cc  */
#line 801 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1221 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 444: /* "OrderSpec" */

/* Line 480 of lalr1.cc  */
#line 801 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1230 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 445: /* "OrderModifier" */

/* Line 480 of lalr1.cc  */
#line 800 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1239 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 446: /* "OrderDirSpec" */

/* Line 480 of lalr1.cc  */
#line 800 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1248 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 447: /* "OrderEmptySpec" */

/* Line 480 of lalr1.cc  */
#line 800 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1257 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 448: /* "OrderCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 800 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1266 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 449: /* "QuantifiedExpr" */

/* Line 480 of lalr1.cc  */
#line 812 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1275 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 450: /* "QVarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 801 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1284 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 451: /* "QVarInDecl" */

/* Line 480 of lalr1.cc  */
#line 801 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1293 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 452: /* "SwitchExpr" */

/* Line 480 of lalr1.cc  */
#line 812 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1302 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 453: /* "SwitchCaseClauseList" */

/* Line 480 of lalr1.cc  */
#line 807 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1311 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 454: /* "SwitchCaseClause" */

/* Line 480 of lalr1.cc  */
#line 807 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1320 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 455: /* "SwitchCaseOperandList" */

/* Line 480 of lalr1.cc  */
#line 807 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1329 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 456: /* "SwitchStatement" */

/* Line 480 of lalr1.cc  */
#line 812 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1338 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 459: /* "TypeswitchExpr" */

/* Line 480 of lalr1.cc  */
#line 812 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1347 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 460: /* "TypeswitchStatement" */

/* Line 480 of lalr1.cc  */
#line 812 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1356 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 461: /* "CaseClauseList" */

/* Line 480 of lalr1.cc  */
#line 796 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1365 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 462: /* "CaseClause" */

/* Line 480 of lalr1.cc  */
#line 796 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1374 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 465: /* "SequenceTypeList" */

/* Line 480 of lalr1.cc  */
#line 803 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1383 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 466: /* "IfExpr" */

/* Line 480 of lalr1.cc  */
#line 812 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1392 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 467: /* "OrExpr" */

/* Line 480 of lalr1.cc  */
#line 812 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1401 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 468: /* "AndExpr" */

/* Line 480 of lalr1.cc  */
#line 812 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1410 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 469: /* "ComparisonExpr" */

/* Line 480 of lalr1.cc  */
#line 812 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1419 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 471: /* "FTContainsExpr" */

/* Line 480 of lalr1.cc  */
#line 812 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1428 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 472: /* "StringConcatExpr" */

/* Line 480 of lalr1.cc  */
#line 812 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1437 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 473: /* "opt_FTIgnoreOption" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1446 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 474: /* "RangeExpr" */

/* Line 480 of lalr1.cc  */
#line 812 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1455 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 475: /* "AdditiveExpr" */

/* Line 480 of lalr1.cc  */
#line 812 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1464 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 476: /* "MultiplicativeExpr" */

/* Line 480 of lalr1.cc  */
#line 812 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1473 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 477: /* "UnionExpr" */

/* Line 480 of lalr1.cc  */
#line 812 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1482 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 478: /* "IntersectExceptExpr" */

/* Line 480 of lalr1.cc  */
#line 812 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1491 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 479: /* "InstanceofExpr" */

/* Line 480 of lalr1.cc  */
#line 812 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1500 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 480: /* "TreatExpr" */

/* Line 480 of lalr1.cc  */
#line 812 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1509 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 481: /* "CastableExpr" */

/* Line 480 of lalr1.cc  */
#line 812 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1518 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 482: /* "CastExpr" */

/* Line 480 of lalr1.cc  */
#line 812 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1527 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 483: /* "SingleType" */

/* Line 480 of lalr1.cc  */
#line 803 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1536 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 484: /* "UnaryExpr" */

/* Line 480 of lalr1.cc  */
#line 812 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1545 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 485: /* "SignList" */

/* Line 480 of lalr1.cc  */
#line 803 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1554 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 486: /* "ValueExpr" */

/* Line 480 of lalr1.cc  */
#line 812 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1563 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 487: /* "SimpleMapExpr" */

/* Line 480 of lalr1.cc  */
#line 812 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1572 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 488: /* "ValueComp" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1581 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 489: /* "NodeComp" */

/* Line 480 of lalr1.cc  */
#line 808 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1590 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 490: /* "ValidateExpr" */

/* Line 480 of lalr1.cc  */
#line 812 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1599 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 491: /* "ExtensionExpr" */

/* Line 480 of lalr1.cc  */
#line 812 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1608 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 492: /* "Pragma_list" */

/* Line 480 of lalr1.cc  */
#line 801 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1617 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 493: /* "Pragma" */

/* Line 480 of lalr1.cc  */
#line 801 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1626 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 494: /* "PathExpr" */

/* Line 480 of lalr1.cc  */
#line 812 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1635 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 496: /* "RelativePathExpr" */

/* Line 480 of lalr1.cc  */
#line 812 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1644 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 497: /* "StepExpr" */

/* Line 480 of lalr1.cc  */
#line 812 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1653 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 498: /* "AxisStep" */

/* Line 480 of lalr1.cc  */
#line 811 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1662 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 499: /* "ForwardStep" */

/* Line 480 of lalr1.cc  */
#line 794 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1671 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 500: /* "ForwardAxis" */

/* Line 480 of lalr1.cc  */
#line 794 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1680 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 501: /* "AbbrevForwardStep" */

/* Line 480 of lalr1.cc  */
#line 794 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1689 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 502: /* "ReverseStep" */

/* Line 480 of lalr1.cc  */
#line 794 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1698 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 503: /* "ReverseAxis" */

/* Line 480 of lalr1.cc  */
#line 794 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1707 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 504: /* "NodeTest" */

/* Line 480 of lalr1.cc  */
#line 794 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1716 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 505: /* "NameTest" */

/* Line 480 of lalr1.cc  */
#line 799 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1725 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 506: /* "Wildcard" */

/* Line 480 of lalr1.cc  */
#line 806 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1734 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 507: /* "PostfixExpr" */

/* Line 480 of lalr1.cc  */
#line 812 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1743 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 508: /* "PredicateList" */

/* Line 480 of lalr1.cc  */
#line 801 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1752 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 509: /* "Predicate" */

/* Line 480 of lalr1.cc  */
#line 812 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1761 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 510: /* "PrimaryExpr" */

/* Line 480 of lalr1.cc  */
#line 812 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1770 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 511: /* "Literal" */

/* Line 480 of lalr1.cc  */
#line 812 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1779 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 512: /* "NumericLiteral" */

/* Line 480 of lalr1.cc  */
#line 812 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1788 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 513: /* "VarRef" */

/* Line 480 of lalr1.cc  */
#line 812 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1797 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 514: /* "ParenthesizedExpr" */

/* Line 480 of lalr1.cc  */
#line 812 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1806 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 515: /* "ContextItemExpr" */

/* Line 480 of lalr1.cc  */
#line 812 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1815 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 516: /* "OrderedExpr" */

/* Line 480 of lalr1.cc  */
#line 812 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1824 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 517: /* "UnorderedExpr" */

/* Line 480 of lalr1.cc  */
#line 812 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1833 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 518: /* "FunctionCall" */

/* Line 480 of lalr1.cc  */
#line 812 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1842 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 519: /* "ArgList" */

/* Line 480 of lalr1.cc  */
#line 795 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1851 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 523: /* "Constructor" */

/* Line 480 of lalr1.cc  */
#line 812 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1860 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 524: /* "DirectConstructor" */

/* Line 480 of lalr1.cc  */
#line 812 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1869 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 525: /* "DirElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 812 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1878 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 526: /* "DirElemContentList" */

/* Line 480 of lalr1.cc  */
#line 797 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1887 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 527: /* "DirAttributeList" */

/* Line 480 of lalr1.cc  */
#line 797 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1896 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 528: /* "DirAttr" */

/* Line 480 of lalr1.cc  */
#line 797 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1905 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 530: /* "DirAttributeValue" */

/* Line 480 of lalr1.cc  */
#line 797 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1914 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 531: /* "opt_QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 802 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1923 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 532: /* "QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 802 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1932 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 533: /* "opt_AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 795 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1941 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 534: /* "AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 795 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1950 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 535: /* "QuoteAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 802 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1959 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 536: /* "AposAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 795 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1968 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 537: /* "DirElemContent" */

/* Line 480 of lalr1.cc  */
#line 812 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1977 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 538: /* "CommonContent" */

/* Line 480 of lalr1.cc  */
#line 812 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1986 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 539: /* "DirCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 812 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1995 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 540: /* "DirPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 812 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2004 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 541: /* "CDataSection" */

/* Line 480 of lalr1.cc  */
#line 812 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2013 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 542: /* "ComputedConstructor" */

/* Line 480 of lalr1.cc  */
#line 812 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2022 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 543: /* "CompDocConstructor" */

/* Line 480 of lalr1.cc  */
#line 812 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2031 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 544: /* "CompElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 812 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2040 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 545: /* "CompAttrConstructor" */

/* Line 480 of lalr1.cc  */
#line 812 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2049 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 546: /* "CompTextConstructor" */

/* Line 480 of lalr1.cc  */
#line 812 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2058 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 547: /* "CompCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 812 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2067 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 548: /* "CompPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 812 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2076 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 549: /* "CompNamespaceConstructor" */

/* Line 480 of lalr1.cc  */
#line 812 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2085 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 550: /* "TypeDeclaration" */

/* Line 480 of lalr1.cc  */
#line 803 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2094 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 551: /* "SequenceType" */

/* Line 480 of lalr1.cc  */
#line 803 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2103 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 552: /* "OccurrenceIndicator" */

/* Line 480 of lalr1.cc  */
#line 799 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2112 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 553: /* "ItemType" */

/* Line 480 of lalr1.cc  */
#line 799 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2121 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 554: /* "TypeList" */

/* Line 480 of lalr1.cc  */
#line 806 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2130 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 555: /* "GeneralizedAtomicType" */

/* Line 480 of lalr1.cc  */
#line 796 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2139 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 556: /* "SimpleType" */

/* Line 480 of lalr1.cc  */
#line 796 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2148 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 557: /* "KindTest" */

/* Line 480 of lalr1.cc  */
#line 799 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2157 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 558: /* "AnyKindTest" */

/* Line 480 of lalr1.cc  */
#line 795 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2166 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 560: /* "DocumentTest" */

/* Line 480 of lalr1.cc  */
#line 797 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2175 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 561: /* "NamespaceTest" */

/* Line 480 of lalr1.cc  */
#line 803 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2184 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 562: /* "TextTest" */

/* Line 480 of lalr1.cc  */
#line 803 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2193 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 563: /* "CommentTest" */

/* Line 480 of lalr1.cc  */
#line 796 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2202 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 564: /* "PITest" */

/* Line 480 of lalr1.cc  */
#line 801 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2211 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 565: /* "AttributeTest" */

/* Line 480 of lalr1.cc  */
#line 796 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2220 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 566: /* "SchemaAttributeTest" */

/* Line 480 of lalr1.cc  */
#line 802 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2229 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 567: /* "ElementTest" */

/* Line 480 of lalr1.cc  */
#line 797 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2238 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 568: /* "SchemaElementTest" */

/* Line 480 of lalr1.cc  */
#line 802 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2247 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 569: /* "TypeName" */

/* Line 480 of lalr1.cc  */
#line 803 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2256 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 570: /* "TypeName_WITH_HOOK" */

/* Line 480 of lalr1.cc  */
#line 803 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2265 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 571: /* "StringLiteral" */

/* Line 480 of lalr1.cc  */
#line 812 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2274 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 573: /* "AnyFunctionTest" */

/* Line 480 of lalr1.cc  */
#line 806 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2283 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 574: /* "TypedFunctionTest" */

/* Line 480 of lalr1.cc  */
#line 806 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2292 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 577: /* "InsertExpr" */

/* Line 480 of lalr1.cc  */
#line 812 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2301 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 578: /* "DeleteExpr" */

/* Line 480 of lalr1.cc  */
#line 812 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2310 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 579: /* "ReplaceExpr" */

/* Line 480 of lalr1.cc  */
#line 812 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2319 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 580: /* "RenameExpr" */

/* Line 480 of lalr1.cc  */
#line 812 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2328 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 581: /* "TransformExpr" */

/* Line 480 of lalr1.cc  */
#line 812 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2337 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 582: /* "VarNameList" */

/* Line 480 of lalr1.cc  */
#line 812 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2346 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 583: /* "VarNameDecl" */

/* Line 480 of lalr1.cc  */
#line 812 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2355 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 584: /* "TryExpr" */

/* Line 480 of lalr1.cc  */
#line 812 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2364 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 585: /* "CatchListExpr" */

/* Line 480 of lalr1.cc  */
#line 812 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2373 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 586: /* "CatchExpr" */

/* Line 480 of lalr1.cc  */
#line 812 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2382 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 587: /* "BracedExpr" */

/* Line 480 of lalr1.cc  */
#line 812 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2391 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 588: /* "NameTestList" */

/* Line 480 of lalr1.cc  */
#line 813 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->name_test_list); };

/* Line 480 of lalr1.cc  */
#line 2400 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 589: /* "FTSelection" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2409 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 592: /* "FTOr" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2418 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 593: /* "FTAnd" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2427 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 594: /* "FTMildNot" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2436 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 595: /* "FTUnaryNot" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2445 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 596: /* "FTPrimaryWithOptions" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2454 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 597: /* "opt_FTMatchOptions" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2463 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 599: /* "FTWeight" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2472 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 600: /* "FTPrimary" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2481 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 601: /* "opt_FTTimes" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2490 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 602: /* "FTExtensionSelection" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2499 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 604: /* "FTWords" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2508 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 605: /* "FTWordsValue" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2517 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 607: /* "FTAnyallOption" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2526 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 610: /* "FTPosFilter" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2535 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 611: /* "FTOrder" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2544 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 612: /* "FTWindow" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2553 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 613: /* "FTDistance" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2562 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 614: /* "FTUnit" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2571 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 615: /* "FTMatchOptions" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2580 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 616: /* "FTMatchOption" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2589 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 617: /* "FTCaseOption" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2598 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 618: /* "FTDiacriticsOption" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2607 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 619: /* "FTExtensionOption" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2616 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 620: /* "FTStemOption" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2625 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 621: /* "FTThesaurusOption" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2634 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 625: /* "FTThesaurusID" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2643 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 628: /* "FTStopWordOption" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2652 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 629: /* "FTStopWords" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2661 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 633: /* "FTStopWordsInclExcl" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2670 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 634: /* "FTLanguageOption" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2679 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 635: /* "FTWildCardOption" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2688 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 636: /* "FTContent" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2697 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 637: /* "FTTimes" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2706 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 638: /* "FTRange" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2715 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 639: /* "FTScope" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2724 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 640: /* "FTBigUnit" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2733 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 641: /* "FTIgnoreOption" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2742 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 642: /* "JSONArrayConstructor" */

/* Line 480 of lalr1.cc  */
#line 810 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2751 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 643: /* "JSONSimpleObjectUnion" */

/* Line 480 of lalr1.cc  */
#line 810 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2760 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 644: /* "JSONAccumulatorObjectUnion" */

/* Line 480 of lalr1.cc  */
#line 810 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2769 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 645: /* "JSONObjectConstructor" */

/* Line 480 of lalr1.cc  */
#line 810 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2778 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 646: /* "JSONPairList" */

/* Line 480 of lalr1.cc  */
#line 810 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2787 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 647: /* "JSONInsertExpr" */

/* Line 480 of lalr1.cc  */
#line 810 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2796 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 648: /* "JSONAppendExpr" */

/* Line 480 of lalr1.cc  */
#line 810 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2805 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 649: /* "JSONDeleteExpr" */

/* Line 480 of lalr1.cc  */
#line 810 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2814 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 650: /* "JSONRenameExpr" */

/* Line 480 of lalr1.cc  */
#line 810 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2823 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 651: /* "JSONReplaceExpr" */

/* Line 480 of lalr1.cc  */
#line 810 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2832 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 657: /* "QNAME" */

/* Line 480 of lalr1.cc  */
#line 812 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2841 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 658: /* "FUNCTION_NAME" */

/* Line 480 of lalr1.cc  */
#line 812 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2850 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 659: /* "EQNAME" */

/* Line 480 of lalr1.cc  */
#line 812 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2859 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
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
#line 128 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
{
    yylloc.begin.filename = yylloc.end.filename = &(driver.theFilename2);
}

/* Line 565 of lalr1.cc  */
#line 2956 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"

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
#line 846 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      }
    break;

  case 4:

/* Line 690 of lalr1.cc  */
#line 850 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      }
    break;

  case 5:

/* Line 690 of lalr1.cc  */
#line 854 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      }
    break;

  case 6:

/* Line 690 of lalr1.cc  */
#line 860 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = NULL;
      }
    break;

  case 7:

/* Line 690 of lalr1.cc  */
#line 864 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = NULL; YYABORT;
      }
    break;

  case 8:

/* Line 690 of lalr1.cc  */
#line 868 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = NULL; YYABORT;
      }
    break;

  case 9:

/* Line 690 of lalr1.cc  */
#line 874 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 10:

/* Line 690 of lalr1.cc  */
#line 880 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      MainModule* mm = dynamic_cast<MainModule*>((yysemantic_stack_[(2) - (2)].node));
      mm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 11:

/* Line 690 of lalr1.cc  */
#line 888 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 12:

/* Line 690 of lalr1.cc  */
#line 894 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      LibraryModule* lm = dynamic_cast<LibraryModule*>((yysemantic_stack_[(2) - (2)].node));
      lm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 13:

/* Line 690 of lalr1.cc  */
#line 903 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), "utf-8" );
    }
    break;

  case 14:

/* Line 690 of lalr1.cc  */
#line 908 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );
    }
    break;

  case 15:

/* Line 690 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (1)].node)), NULL);
      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(3) - (3)].expr)), prolog);
    }
    break;

  case 16:

/* Line 690 of lalr1.cc  */
#line 920 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (1)].node)));
      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(3) - (3)].expr)), prolog);
    }
    break;

  case 17:

/* Line 690 of lalr1.cc  */
#line 926 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)),
                                  static_cast<SIND_DeclList*>((yysemantic_stack_[(5) - (1)].node)),
                                  static_cast<VFO_DeclList*>((yysemantic_stack_[(5) - (3)].node)));
      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(5) - (5)].expr)), prolog);
    }
    break;

  case 18:

/* Line 690 of lalr1.cc  */
#line 934 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new MainModule( LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(1) - (1)].expr)), NULL );
    }
    break;

  case 19:

/* Line 690 of lalr1.cc  */
#line 939 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].expr);
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after statement.");
      YYERROR;
    }
    break;

  case 20:

/* Line 690 of lalr1.cc  */
#line 947 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].expr);
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 21:

/* Line 690 of lalr1.cc  */
#line 955 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(5) - (1)].node); (yyval.node) = (yysemantic_stack_[(5) - (3)].node); (yyval.node) = (yysemantic_stack_[(5) - (5)].expr);
      (yylocation_stack_[(5) - (3)]).step();
      error((yylocation_stack_[(5) - (3)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 22:

/* Line 690 of lalr1.cc  */
#line 963 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(5) - (1)].node); (yyval.node) = (yysemantic_stack_[(5) - (3)].node); (yyval.node) = (yysemantic_stack_[(5) - (5)].expr);
      (yylocation_stack_[(5) - (1)]).step();
      error((yylocation_stack_[(5) - (1)]), "syntax error, missing semicolon \";\" after statement.");
      YYERROR;
    }
    break;

  case 23:

/* Line 690 of lalr1.cc  */
#line 972 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(1) - (1)].node)), NULL);
    }
    break;

  case 24:

/* Line 690 of lalr1.cc  */
#line 977 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (2)].node)), NULL);
      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(3) - (1)].node)), prolog);
    }
    break;

  case 25:

/* Line 690 of lalr1.cc  */
#line 983 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (2)].node)));
      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(3) - (1)].node)), prolog);
    }
    break;

  case 26:

/* Line 690 of lalr1.cc  */
#line 989 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)),
                                  static_cast<SIND_DeclList*>((yysemantic_stack_[(5) - (2)].node)),
                                  static_cast<VFO_DeclList*>((yysemantic_stack_[(5) - (4)].node)));
      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(5) - (1)].node)), prolog);
    }
    break;

  case 27:

/* Line 690 of lalr1.cc  */
#line 998 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      ERROR_IF_QNAME_NOT_NCNAME((yysemantic_stack_[(6) - (3)].expr), (yylocation_stack_[(6) - (3)]));
      (yyval.node) = new ModuleDecl( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );
      dynamic_cast<ModuleDecl*>((yyval.node))->setComment( SYMTAB((yysemantic_stack_[(6) - (1)].sval)) );
    }
    break;

  case 28:

/* Line 690 of lalr1.cc  */
#line 1006 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      SIND_DeclList *sdl = new SIND_DeclList( LOC((yyloc)) );
      sdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
      (yyval.node) = sdl;
    }
    break;

  case 29:

/* Line 690 of lalr1.cc  */
#line 1013 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      ((SIND_DeclList*)(yysemantic_stack_[(3) - (1)].node))->push_back( (yysemantic_stack_[(3) - (3)].node) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 30:

/* Line 690 of lalr1.cc  */
#line 1019 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 44:

/* Line 690 of lalr1.cc  */
#line 1045 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new BoundarySpaceDecl(LOC((yyloc)), StaticContextConsts::preserve_space);
    }
    break;

  case 45:

/* Line 690 of lalr1.cc  */
#line 1050 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new BoundarySpaceDecl(LOC((yyloc)), StaticContextConsts::strip_space);
    }
    break;

  case 46:

/* Line 690 of lalr1.cc  */
#line 1056 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DefaultCollationDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (4)].sval)) );
    }
    break;

  case 47:

/* Line 690 of lalr1.cc  */
#line 1062 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new BaseURIDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
    }
    break;

  case 48:

/* Line 690 of lalr1.cc  */
#line 1068 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ConstructionDecl(LOC((yyloc)), StaticContextConsts::cons_preserve);
    }
    break;

  case 49:

/* Line 690 of lalr1.cc  */
#line 1073 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ConstructionDecl(LOC((yyloc)), StaticContextConsts::cons_strip);
    }
    break;

  case 50:

/* Line 690 of lalr1.cc  */
#line 1079 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new OrderingModeDecl(LOC((yyloc)), StaticContextConsts::ordered);
    }
    break;

  case 51:

/* Line 690 of lalr1.cc  */
#line 1084 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new OrderingModeDecl(LOC((yyloc)), StaticContextConsts::unordered);
    }
    break;

  case 52:

/* Line 690 of lalr1.cc  */
#line 1090 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new EmptyOrderDecl(LOC((yyloc)), StaticContextConsts::empty_greatest);
    }
    break;

  case 53:

/* Line 690 of lalr1.cc  */
#line 1095 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new EmptyOrderDecl(LOC((yyloc)), StaticContextConsts::empty_least);
    }
    break;

  case 54:

/* Line 690 of lalr1.cc  */
#line 1101 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)), true, true);
    }
    break;

  case 55:

/* Line 690 of lalr1.cc  */
#line 1106 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)), true, false);
    }
    break;

  case 56:

/* Line 690 of lalr1.cc  */
#line 1111 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)), false, true);
    }
    break;

  case 57:

/* Line 690 of lalr1.cc  */
#line 1116 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)), false, false);
    }
    break;

  case 60:

/* Line 690 of lalr1.cc  */
#line 1126 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yyval.node);
      error((yylocation_stack_[(3) - (2)]), "syntax error, \"import\" should be followed by either \"schema\" or \"module\".");
      YYERROR;
    }
    break;

  case 61:

/* Line 690 of lalr1.cc  */
#line 1134 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport( LOC((yyloc)), NULL, SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL );
    }
    break;

  case 62:

/* Line 690 of lalr1.cc  */
#line 1139 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(4) - (3)].node)),
                            SYMTAB((yysemantic_stack_[(4) - (4)].sval)),
                            NULL);
    }
    break;

  case 63:

/* Line 690 of lalr1.cc  */
#line 1147 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            NULL,
                            SYMTAB((yysemantic_stack_[(5) - (3)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 64:

/* Line 690 of lalr1.cc  */
#line 1155 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(6) - (3)].node)),
                            SYMTAB((yysemantic_stack_[(6) - (4)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(6) - (6)].node)));
    }
    break;

  case 65:

/* Line 690 of lalr1.cc  */
#line 1164 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      URILiteralList *ull = new URILiteralList( LOC((yyloc)));
      ull->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
      (yyval.node) = ull;
    }
    break;

  case 66:

/* Line 690 of lalr1.cc  */
#line 1171 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      if ( URILiteralList *ull = dynamic_cast<URILiteralList*>((yysemantic_stack_[(3) - (1)].node)) )
        ull->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 67:

/* Line 690 of lalr1.cc  */
#line 1179 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      ERROR_IF_QNAME_NOT_NCNAME((yysemantic_stack_[(3) - (2)].expr), (yylocation_stack_[(3) - (2)]));
      (yyval.node) = new SchemaPrefix( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)));
    }
    break;

  case 68:

/* Line 690 of lalr1.cc  */
#line 1185 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaPrefix( LOC((yyloc)), true );
    }
    break;

  case 69:

/* Line 690 of lalr1.cc  */
#line 1191 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL);
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(3) - (2)].sval)));
    }
    break;

  case 70:

/* Line 690 of lalr1.cc  */
#line 1197 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      ERROR_IF_QNAME_NOT_NCNAME((yysemantic_stack_[(6) - (4)].expr), (yylocation_stack_[(6) - (4)]));
      (yyval.node) = new ModuleImport(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(6) - (4)].expr)), SYMTAB((yysemantic_stack_[(6) - (6)].sval)), NULL);
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(6) - (2)].sval)));
    }
    break;

  case 71:

/* Line 690 of lalr1.cc  */
#line 1204 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)),
                            SYMTAB((yysemantic_stack_[(5) - (3)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(5) - (2)].sval)));
    }
    break;

  case 72:

/* Line 690 of lalr1.cc  */
#line 1212 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 1223 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      ERROR_IF_QNAME_NOT_NCNAME((yysemantic_stack_[(5) - (3)].expr), (yylocation_stack_[(5) - (3)]));
      (yyval.node) = new NamespaceDecl( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (3)].expr)), SYMTAB((yysemantic_stack_[(5) - (5)].sval)) );
    }
    break;

  case 74:

/* Line 690 of lalr1.cc  */
#line 1230 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DefaultNamespaceDecl(LOC((yyloc)),
                                    ParseConstants::ns_element_default,
                                    SYMTAB((yysemantic_stack_[(5) - (5)].sval)));
    }
    break;

  case 75:

/* Line 690 of lalr1.cc  */
#line 1237 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DefaultNamespaceDecl(LOC((yyloc)),
                                    ParseConstants::ns_function_default,
                                    SYMTAB((yysemantic_stack_[(5) - (5)].sval)));
    }
    break;

  case 76:

/* Line 690 of lalr1.cc  */
#line 1245 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      VFO_DeclList *vdl = new VFO_DeclList( LOC((yyloc)));
      vdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
      (yyval.node) = vdl;
    }
    break;

  case 77:

/* Line 690 of lalr1.cc  */
#line 1252 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      ((VFO_DeclList*)(yysemantic_stack_[(3) - (1)].node))->push_back( (yysemantic_stack_[(3) - (3)].node) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 78:

/* Line 690 of lalr1.cc  */
#line 1258 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 87:

/* Line 690 of lalr1.cc  */
#line 1277 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DecimalFormatNode(LOC((yyloc)), (yysemantic_stack_[(4) - (4)].vstrpair));
      delete (yysemantic_stack_[(4) - (4)].vstrpair);
    }
    break;

  case 88:

/* Line 690 of lalr1.cc  */
#line 1283 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DecimalFormatNode(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), (yysemantic_stack_[(4) - (4)].vstrpair));
      delete (yysemantic_stack_[(4) - (4)].vstrpair);
    }
    break;

  case 89:

/* Line 690 of lalr1.cc  */
#line 1290 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.vstrpair) = new vector<string_pair_t>();
      (yyval.vstrpair)->push_back( *(yysemantic_stack_[(1) - (1)].strpair) );
      delete (yysemantic_stack_[(1) - (1)].strpair);
    }
    break;

  case 90:

/* Line 690 of lalr1.cc  */
#line 1297 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yysemantic_stack_[(2) - (1)].vstrpair)->push_back( *(yysemantic_stack_[(2) - (2)].strpair) );
      delete (yysemantic_stack_[(2) - (2)].strpair);
      (yyval.vstrpair) = (yysemantic_stack_[(2) - (1)].vstrpair);
    }
    break;

  case 91:

/* Line 690 of lalr1.cc  */
#line 1305 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      StringLiteral *sl = static_cast<StringLiteral*>((yysemantic_stack_[(3) - (3)].expr));
      (yyval.strpair) = new string_pair_t( (yysemantic_stack_[(3) - (1)].strval), sl->get_strval().str() );
      delete sl;
    }
    break;

  case 92:

/* Line 690 of lalr1.cc  */
#line 1312 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "decimal-separator"; }
    break;

  case 93:

/* Line 690 of lalr1.cc  */
#line 1313 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "digit"; }
    break;

  case 94:

/* Line 690 of lalr1.cc  */
#line 1314 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "grouping-separator"; }
    break;

  case 95:

/* Line 690 of lalr1.cc  */
#line 1315 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "infinity"; }
    break;

  case 96:

/* Line 690 of lalr1.cc  */
#line 1316 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "minus-sign"; }
    break;

  case 97:

/* Line 690 of lalr1.cc  */
#line 1317 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "NaN"; }
    break;

  case 98:

/* Line 690 of lalr1.cc  */
#line 1318 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "pattern-separator"; }
    break;

  case 99:

/* Line 690 of lalr1.cc  */
#line 1319 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "percent"; }
    break;

  case 100:

/* Line 690 of lalr1.cc  */
#line 1320 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "per-mille"; }
    break;

  case 101:

/* Line 690 of lalr1.cc  */
#line 1321 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "zero-digit"; }
    break;

  case 102:

/* Line 690 of lalr1.cc  */
#line 1325 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 1339 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTOptionDecl( LOC((yyloc)), dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (3)].node)) );
    }
    break;

  case 104:

/* Line 690 of lalr1.cc  */
#line 1345 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(4) - (4)].node);
    }
    break;

  case 105:

/* Line 690 of lalr1.cc  */
#line 1351 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      CtxItemDecl* d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(3) - (3)].node));
      d->theType = (yysemantic_stack_[(3) - (2)].node);
      (yyval.node) = d;
    }
    break;

  case 106:

/* Line 690 of lalr1.cc  */
#line 1358 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 107:

/* Line 690 of lalr1.cc  */
#line 1364 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      CtxItemDecl* d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(1) - (1)].node));
      d->theIsExternal = false;
      (yyval.node) = d;
    }
    break;

  case 108:

/* Line 690 of lalr1.cc  */
#line 1371 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CtxItemDecl(LOC((yyloc)), NULL);
    }
    break;

  case 109:

/* Line 690 of lalr1.cc  */
#line 1376 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 110:

/* Line 690 of lalr1.cc  */
#line 1382 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CtxItemDecl(LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 111:

/* Line 690 of lalr1.cc  */
#line 1388 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 1400 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 1412 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 1425 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)), NULL, NULL);
    }
    break;

  case 115:

/* Line 690 of lalr1.cc  */
#line 1430 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)),
                              dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (4)].node)),
                              NULL);
    }
    break;

  case 116:

/* Line 690 of lalr1.cc  */
#line 1438 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(4) - (4)].expr)),
                              NULL,
                              static_cast<AnnotationListParsenode*>((yysemantic_stack_[(4) - (1)].node)));
    }
    break;

  case 117:

/* Line 690 of lalr1.cc  */
#line 1446 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(5) - (4)].expr)),
                              dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (5)].node)),
                              static_cast<AnnotationListParsenode*>((yysemantic_stack_[(5) - (1)].node)));
    }
    break;

  case 118:

/* Line 690 of lalr1.cc  */
#line 1455 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationListParsenode(LOC((yyloc)), static_cast<AnnotationParsenode*>((yysemantic_stack_[(1) - (1)].node)));
    }
    break;

  case 119:

/* Line 690 of lalr1.cc  */
#line 1460 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      static_cast<AnnotationListParsenode*>((yysemantic_stack_[(2) - (1)].node))->push_back(static_cast<AnnotationParsenode*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 120:

/* Line 690 of lalr1.cc  */
#line 1467 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))), NULL);
    }
    break;

  case 121:

/* Line 690 of lalr1.cc  */
#line 1472 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)),
                                   new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (1)].sval))),
                                   static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 122:

/* Line 690 of lalr1.cc  */
#line 1479 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), true), NULL);
    }
    break;

  case 123:

/* Line 690 of lalr1.cc  */
#line 1484 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)),
                                   new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (1)].sval)), true),
                                   static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 124:

/* Line 690 of lalr1.cc  */
#line 1492 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationLiteralListParsenode(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr));
    }
    break;

  case 125:

/* Line 690 of lalr1.cc  */
#line 1497 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(3) - (1)].node))->push_back((yysemantic_stack_[(3) - (3)].expr));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 126:

/* Line 690 of lalr1.cc  */
#line 1504 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      static_cast<FunctionDecl*>((yysemantic_stack_[(2) - (2)].node))->setComment( SYMTAB((yysemantic_stack_[(2) - (1)].sval)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 127:

/* Line 690 of lalr1.cc  */
#line 1510 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      FunctionDecl* fdecl = static_cast<FunctionDecl*>((yysemantic_stack_[(3) - (3)].node));
      fdecl->setComment( SYMTAB((yysemantic_stack_[(3) - (1)].sval)) );
      fdecl->set_annotations(static_cast<AnnotationListParsenode*>((yysemantic_stack_[(3) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
    }
    break;

  case 130:

/* Line 690 of lalr1.cc  */
#line 1523 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 1534 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 1547 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 1559 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 1572 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(NULL);
    }
    break;

  case 135:

/* Line 690 of lalr1.cc  */
#line 1577 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (2)].node)));
    }
    break;

  case 136:

/* Line 690 of lalr1.cc  */
#line 1582 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(NULL, dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node)));
    }
    break;

  case 137:

/* Line 690 of lalr1.cc  */
#line 1587 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(dynamic_cast<ParamList*>((yysemantic_stack_[(5) - (2)].node)), dynamic_cast<SequenceType*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 138:

/* Line 690 of lalr1.cc  */
#line 1593 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      ParamList *pl = new ParamList( LOC((yyloc)) );
      pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = pl;
    }
    break;

  case 139:

/* Line 690 of lalr1.cc  */
#line 1600 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      if ( ParamList *pl = dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (1)].node)) )
        pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(3) - (3)].node)) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 140:

/* Line 690 of lalr1.cc  */
#line 1608 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL);
    }
    break;

  case 141:

/* Line 690 of lalr1.cc  */
#line 1613 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)),
                     static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                     dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 142:

/* Line 690 of lalr1.cc  */
#line 1621 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)),
                              NULL,
                              NULL);
      static_cast<CollectionDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(3) - (1)].sval)));
    }
    break;

  case 143:

/* Line 690 of lalr1.cc  */
#line 1629 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(5) - (3)].expr)),
                              0,
                              static_cast<SequenceType*>((yysemantic_stack_[(5) - (5)].node)));
      static_cast<CollectionDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(5) - (1)].sval)));
    }
    break;

  case 144:

/* Line 690 of lalr1.cc  */
#line 1637 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                               static_cast<QName*>((yysemantic_stack_[(4) - (4)].expr)),
                               static_cast<AnnotationListParsenode*>((yysemantic_stack_[(4) - (2)].node)),
                               0);
      static_cast<CollectionDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(4) - (1)].sval)));
    }
    break;

  case 145:

/* Line 690 of lalr1.cc  */
#line 1645 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                               static_cast<QName*>((yysemantic_stack_[(6) - (4)].expr)),
                               static_cast<AnnotationListParsenode*>((yysemantic_stack_[(6) - (2)].node)),
                               static_cast<SequenceType*>((yysemantic_stack_[(6) - (6)].node)));
      static_cast<CollectionDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(6) - (1)].sval)));
    }
    break;

  case 146:

/* Line 690 of lalr1.cc  */
#line 1655 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL));
    }
    break;

  case 147:

/* Line 690 of lalr1.cc  */
#line 1659 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)),
                                                    (yysemantic_stack_[(2) - (1)].node),
                                                    dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node))));
    }
    break;

  case 148:

/* Line 690 of lalr1.cc  */
#line 1665 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL));
    }
    break;

  case 149:

/* Line 690 of lalr1.cc  */
#line 1669 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)),
                                                    (yysemantic_stack_[(2) - (1)].node),
                                                    dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node))));
    }
    break;

  case 150:

/* Line 690 of lalr1.cc  */
#line 1676 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 1685 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 1696 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      IndexKeyList* keyList = new IndexKeyList(LOC((yyloc)));
      keyList->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = keyList;
    }
    break;

  case 153:

/* Line 690 of lalr1.cc  */
#line 1702 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<IndexKeyList*>((yysemantic_stack_[(3) - (1)].node))->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 154:

/* Line 690 of lalr1.cc  */
#line 1709 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL, NULL);
    }
    break;

  case 155:

/* Line 690 of lalr1.cc  */
#line 1714 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            dynamic_cast<SequenceType*>((yysemantic_stack_[(2) - (2)].node)),
                            NULL);
    }
    break;

  case 156:

/* Line 690 of lalr1.cc  */
#line 1721 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            NULL,
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
    }
    break;

  case 157:

/* Line 690 of lalr1.cc  */
#line 1728 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(3) - (1)].expr),
                            dynamic_cast<SequenceType*>((yysemantic_stack_[(3) - (2)].node)),
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 158:

/* Line 690 of lalr1.cc  */
#line 1738 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ICCollSimpleCheck(LOC((yyloc)),
                                 static_cast<QName*>((yysemantic_stack_[(11) - (4)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(11) - (7)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(11) - (9)].expr)),
                                 (yysemantic_stack_[(11) - (11)].expr));
    }
    break;

  case 159:

/* Line 690 of lalr1.cc  */
#line 1748 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ICCollUniqueKeyCheck(LOC((yyloc)),
                                    static_cast<QName*>((yysemantic_stack_[(14) - (4)].expr)),
                                    static_cast<QName*>((yysemantic_stack_[(14) - (7)].expr)),
                                    static_cast<QName*>((yysemantic_stack_[(14) - (10)].expr)),
                                    (yysemantic_stack_[(14) - (14)].expr));
    }
    break;

  case 160:

/* Line 690 of lalr1.cc  */
#line 1758 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ICCollForeachNode(LOC((yyloc)),
                                 static_cast<QName*>((yysemantic_stack_[(13) - (4)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(13) - (7)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(13) - (11)].expr)),
                                 (yysemantic_stack_[(13) - (13)].expr));
    }
    break;

  case 161:

/* Line 690 of lalr1.cc  */
#line 1769 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 1782 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 1798 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 164:

/* Line 690 of lalr1.cc  */
#line 1802 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 165:

/* Line 690 of lalr1.cc  */
#line 1806 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = NULL;
    }
    break;

  case 166:

/* Line 690 of lalr1.cc  */
#line 1812 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 167:

/* Line 690 of lalr1.cc  */
#line 1816 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 168:

/* Line 690 of lalr1.cc  */
#line 1820 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new BlockBody(LOC((yyloc)));
    }
    break;

  case 169:

/* Line 690 of lalr1.cc  */
#line 1826 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 170:

/* Line 690 of lalr1.cc  */
#line 1831 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      BlockBody* blk = static_cast<BlockBody*>((yysemantic_stack_[(2) - (1)].expr));
      blk->add((yysemantic_stack_[(2) - (2)].expr));
      (yyval.expr) = blk;
    }
    break;

  case 171:

/* Line 690 of lalr1.cc  */
#line 1839 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      BlockBody* blk = new BlockBody(LOC((yyloc)));
      blk->add((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = blk;
    }
    break;

  case 172:

/* Line 690 of lalr1.cc  */
#line 1846 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      BlockBody* blk = static_cast<BlockBody*>((yysemantic_stack_[(2) - (1)].expr));
      blk->add((yysemantic_stack_[(2) - (2)].expr));
      (yyval.expr) = blk;
    }
    break;

  case 173:

/* Line 690 of lalr1.cc  */
#line 1853 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 1880 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 187:

/* Line 690 of lalr1.cc  */
#line 1885 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      driver.addCommonLanguageWarning((yylocation_stack_[(2) - (1)]), ZED(ZWST0009_EMPTY_BLOCK));
      (yyval.expr) = new BlockBody(LOC((yyloc)));
    }
    break;

  case 188:

/* Line 690 of lalr1.cc  */
#line 1892 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 1908 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 190:

/* Line 690 of lalr1.cc  */
#line 1914 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    }
    break;

  case 191:

/* Line 690 of lalr1.cc  */
#line 1920 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      VarDeclStmt* vdecl = static_cast<VarDeclStmt*>((yysemantic_stack_[(3) - (1)].expr));
      vdecl->add((yysemantic_stack_[(3) - (3)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 192:

/* Line 690 of lalr1.cc  */
#line 1927 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      VarDeclStmt* vdecl = new VarDeclStmt(LOC((yyloc)), NULL);
      vdecl->add((yysemantic_stack_[(2) - (2)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 193:

/* Line 690 of lalr1.cc  */
#line 1934 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      VarDeclStmt* vdecl = new VarDeclStmt(LOC((yyloc)),
                                           static_cast<AnnotationListParsenode*>((yysemantic_stack_[(3) - (1)].node)));
      vdecl->add((yysemantic_stack_[(3) - (3)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 194:

/* Line 690 of lalr1.cc  */
#line 1943 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 1952 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 1961 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 1970 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 1981 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new AssignExpr(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)), (yysemantic_stack_[(5) - (4)].expr));
    }
    break;

  case 199:

/* Line 690 of lalr1.cc  */
#line 1987 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ApplyExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr));
    }
    break;

  case 200:

/* Line 690 of lalr1.cc  */
#line 1993 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ExitExpr(LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr));
    }
    break;

  case 201:

/* Line 690 of lalr1.cc  */
#line 1999 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 2011 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement(LOC((yyloc)), FlowCtlStatement::BREAK);
    }
    break;

  case 203:

/* Line 690 of lalr1.cc  */
#line 2016 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement( LOC((yyloc)), FlowCtlStatement::CONTINUE );
    }
    break;

  case 204:

/* Line 690 of lalr1.cc  */
#line 2022 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 2034 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 2047 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 2067 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TryExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 208:

/* Line 690 of lalr1.cc  */
#line 2073 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      CatchListExpr* cle = new CatchListExpr( LOC((yyloc)) );
      cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)) );
      (yyval.expr) = cle;
    }
    break;

  case 209:

/* Line 690 of lalr1.cc  */
#line 2080 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
      if ( cle )
        cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)) );
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    }
    break;

  case 210:

/* Line 690 of lalr1.cc  */
#line 2089 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)), *(yysemantic_stack_[(3) - (2)].name_test_list), (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 211:

/* Line 690 of lalr1.cc  */
#line 2096 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 212:

/* Line 690 of lalr1.cc  */
#line 2101 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 2113 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 2147 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 2159 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ReturnExpr( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr) );
    }
    break;

  case 234:

/* Line 690 of lalr1.cc  */
#line 2165 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_sliding;
    }
    break;

  case 235:

/* Line 690 of lalr1.cc  */
#line 2170 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_tumbling;
    }
    break;

  case 236:

/* Line 690 of lalr1.cc  */
#line 2176 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_start;
    }
    break;

  case 237:

/* Line 690 of lalr1.cc  */
#line 2181 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_end;
    }
    break;

  case 238:

/* Line 690 of lalr1.cc  */
#line 2186 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
    (yyval.strval) = parser::the_only_end;
  }
    break;

  case 239:

/* Line 690 of lalr1.cc  */
#line 2192 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FLWORWinCond(LOC((yyloc)),
                            dynamic_cast<WindowVars*>((yysemantic_stack_[(4) - (2)].node)),
                            (yysemantic_stack_[(4) - (4)].expr),
                            (yysemantic_stack_[(4) - (1)].strval) == parser::the_start,
                            (yysemantic_stack_[(4) - (1)].strval) == parser::the_only_end);
    }
    break;

  case 240:

/* Line 690 of lalr1.cc  */
#line 2201 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FLWORWinCond(LOC((yyloc)),
                            NULL,
                            (yysemantic_stack_[(3) - (3)].expr),
                            (yysemantic_stack_[(3) - (1)].strval) == parser::the_start,
                            (yysemantic_stack_[(3) - (1)].strval) == parser::the_only_end);
    }
    break;

  case 241:

/* Line 690 of lalr1.cc  */
#line 2212 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 2224 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 2235 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CountClause(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 252:

/* Line 690 of lalr1.cc  */
#line 2253 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      FLWORClauseList *fcl = new FLWORClauseList( LOC((yyloc)) );
      fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = fcl;
    }
    break;

  case 253:

/* Line 690 of lalr1.cc  */
#line 2260 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      FLWORClauseList *fcl = dynamic_cast<FLWORClauseList*>((yysemantic_stack_[(2) - (1)].node));
      fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = fcl;
    }
    break;

  case 254:

/* Line 690 of lalr1.cc  */
#line 2269 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ForClause(LOC((yyloc)), dynamic_cast<VarInDeclList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 255:

/* Line 690 of lalr1.cc  */
#line 2273 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      error((yylocation_stack_[(3) - (2)]), "syntax error, unexpected qualified name \""
          + static_cast<VarInDeclList*>((yysemantic_stack_[(3) - (3)].node))->operator[](0)->get_var_name()->get_qname().str() + "\" (missing \"$\" sign?)");
      delete (yysemantic_stack_[(3) - (3)].node);
      YYERROR;
    }
    break;

  case 256:

/* Line 690 of lalr1.cc  */
#line 2283 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = NULL;
      error((yylocation_stack_[(2) - (2)]), "");
      YYERROR;
    }
    break;

  case 257:

/* Line 690 of lalr1.cc  */
#line 2291 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      VarInDeclList* vdl = new VarInDeclList( LOC((yyloc)) );
      vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = vdl;
    }
    break;

  case 258:

/* Line 690 of lalr1.cc  */
#line 2298 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      if ( VarInDeclList* vdl = dynamic_cast<VarInDeclList*>((yysemantic_stack_[(4) - (1)].node)) )
        vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
      (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
    }
    break;

  case 259:

/* Line 690 of lalr1.cc  */
#line 2305 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
      error((yylocation_stack_[(3) - (3)]), "syntax error, unexpected QName \""
          + static_cast<VarInDecl*>((yysemantic_stack_[(3) - (3)].node))->get_var_name()->get_qname().str() + "\" (missing \"$\" sign?)");
      delete (yysemantic_stack_[(3) - (1)].node);
      YYERROR;
    }
    break;

  case 260:

/* Line 690 of lalr1.cc  */
#line 2315 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 2325 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 2335 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 2345 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 2355 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 2365 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 2375 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 2385 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 2395 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 2404 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 2414 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 2424 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 2436 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new PositionalVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 273:

/* Line 690 of lalr1.cc  */
#line 2442 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTScoreVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 274:

/* Line 690 of lalr1.cc  */
#line 2448 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new LetClause( LOC((yyloc)), dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(2) - (2)].node)) );
        }
    break;

  case 275:

/* Line 690 of lalr1.cc  */
#line 2454 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            VarGetsDeclList *vgdl = new VarGetsDeclList( LOC((yyloc)) );
            vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = vgdl;
        }
    break;

  case 276:

/* Line 690 of lalr1.cc  */
#line 2460 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            if( VarGetsDeclList *vgdl = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(3) - (1)].node)) )
                vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 277:

/* Line 690 of lalr1.cc  */
#line 2468 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                           NULL,
                           NULL,
                           (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 278:

/* Line 690 of lalr1.cc  */
#line 2476 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                           dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (3)].node)),
                           NULL,
                           (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 279:

/* Line 690 of lalr1.cc  */
#line 2484 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(3) - (1)].node))->get_var_name(),
                           NULL,
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(3) - (1)].node)),
                           (yysemantic_stack_[(3) - (3)].expr));
     }
    break;

  case 280:

/* Line 690 of lalr1.cc  */
#line 2492 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                           dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (3)].node)),
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(6) - (4)].node)),
                           (yysemantic_stack_[(6) - (6)].expr));
    }
    break;

  case 281:

/* Line 690 of lalr1.cc  */
#line 2502 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                             NULL, (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 282:

/* Line 690 of lalr1.cc  */
#line 2508 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                             dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (3)].node)),
                             (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 284:

/* Line 690 of lalr1.cc  */
#line 2518 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL, NULL);
    }
    break;

  case 285:

/* Line 690 of lalr1.cc  */
#line 2522 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_curr(static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)));
    }
    break;

  case 286:

/* Line 690 of lalr1.cc  */
#line 2529 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), dynamic_cast<PositionalVar*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL, NULL);
    }
    break;

  case 287:

/* Line 690 of lalr1.cc  */
#line 2533 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_posvar(dynamic_cast<PositionalVar*>((yysemantic_stack_[(2) - (1)].node)));
    }
    break;

  case 289:

/* Line 690 of lalr1.cc  */
#line 2541 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), static_cast<QName*>((yysemantic_stack_[(6) - (6)].expr)));
    }
    break;

  case 290:

/* Line 690 of lalr1.cc  */
#line 2545 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 291:

/* Line 690 of lalr1.cc  */
#line 2549 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)), NULL);
    }
    break;

  case 292:

/* Line 690 of lalr1.cc  */
#line 2555 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WhereClause(LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 293:

/* Line 690 of lalr1.cc  */
#line 2561 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupByClause(LOC((yyloc)), dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 294:

/* Line 690 of lalr1.cc  */
#line 2567 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      GroupSpecList* gsl = new GroupSpecList(LOC((yyloc)));
      gsl->push_back(static_cast<GroupSpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = gsl;
    }
    break;

  case 295:

/* Line 690 of lalr1.cc  */
#line 2573 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      GroupSpecList* gsl = static_cast<GroupSpecList*>((yysemantic_stack_[(3) - (1)].node));
      gsl->push_back(static_cast<GroupSpec*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = gsl;
    }
    break;

  case 296:

/* Line 690 of lalr1.cc  */
#line 2581 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)), NULL, (yysemantic_stack_[(4) - (4)].expr), NULL);
    }
    break;

  case 297:

/* Line 690 of lalr1.cc  */
#line 2585 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                         static_cast<SequenceType*>((yysemantic_stack_[(5) - (3)].node)),
                         (yysemantic_stack_[(5) - (5)].expr),
                         NULL);
    }
    break;

  case 298:

/* Line 690 of lalr1.cc  */
#line 2593 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                         static_cast<SequenceType*>((yysemantic_stack_[(6) - (3)].node)),
                         (yysemantic_stack_[(6) - (5)].expr),
                         static_cast<GroupCollationSpec*>((yysemantic_stack_[(6) - (6)].node)));
    }
    break;

  case 299:

/* Line 690 of lalr1.cc  */
#line 2601 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                         NULL,
                         (yysemantic_stack_[(5) - (4)].expr),
                         static_cast<GroupCollationSpec*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 300:

/* Line 690 of lalr1.cc  */
#line 2609 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      VarRef* varRef = dynamic_cast<VarRef*>((yysemantic_stack_[(1) - (1)].expr));
      if (varRef != NULL)
        (yyval.node) = new GroupSpec(LOC((yyloc)), varRef, NULL, NULL, NULL);
      else
        (yyval.node) = new GroupSpec(LOC((yyloc)), NULL, NULL, (yysemantic_stack_[(1) - (1)].expr), NULL);
    }
    break;

  case 301:

/* Line 690 of lalr1.cc  */
#line 2617 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      VarRef* varRef = dynamic_cast<VarRef*>((yysemantic_stack_[(2) - (1)].expr));
      if (varRef != NULL)
        (yyval.node) = new GroupSpec(LOC((yyloc)), varRef, NULL, NULL, static_cast<GroupCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
      else
        (yyval.node) = new GroupSpec(LOC((yyloc)), NULL, NULL, (yysemantic_stack_[(2) - (1)].expr), static_cast<GroupCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
    }
    break;

  case 302:

/* Line 690 of lalr1.cc  */
#line 2627 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
    }
    break;

  case 303:

/* Line 690 of lalr1.cc  */
#line 2633 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 304:

/* Line 690 of lalr1.cc  */
#line 2639 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(4) - (4)].node)), true
            );
        }
    break;

  case 305:

/* Line 690 of lalr1.cc  */
#line 2647 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            OrderSpecList *osl = new OrderSpecList( LOC((yyloc)) );
            osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = osl;
        }
    break;

  case 306:

/* Line 690 of lalr1.cc  */
#line 2653 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            if ( OrderSpecList* osl = dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (1)].node)) )
                osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 307:

/* Line 690 of lalr1.cc  */
#line 2661 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderSpec( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL );
        }
    break;

  case 308:

/* Line 690 of lalr1.cc  */
#line 2665 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderSpec(
                LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<OrderModifierPN*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 309:

/* Line 690 of lalr1.cc  */
#line 2673 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL
            );
        }
    break;

  case 310:

/* Line 690 of lalr1.cc  */
#line 2679 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 311:

/* Line 690 of lalr1.cc  */
#line 2685 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, NULL, dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 312:

/* Line 690 of lalr1.cc  */
#line 2691 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (2)].node)),
                NULL
            );
        }
    break;

  case 313:

/* Line 690 of lalr1.cc  */
#line 2700 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
                NULL,
                dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 314:

/* Line 690 of lalr1.cc  */
#line 2709 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                NULL,
                dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 315:

/* Line 690 of lalr1.cc  */
#line 2718 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(3) - (1)].node)),
                dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 316:

/* Line 690 of lalr1.cc  */
#line 2729 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_ascending );
        }
    break;

  case 317:

/* Line 690 of lalr1.cc  */
#line 2733 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_descending );
        }
    break;

  case 318:

/* Line 690 of lalr1.cc  */
#line 2739 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_greatest
            );
        }
    break;

  case 319:

/* Line 690 of lalr1.cc  */
#line 2745 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_least
            );
        }
    break;

  case 320:

/* Line 690 of lalr1.cc  */
#line 2753 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 321:

/* Line 690 of lalr1.cc  */
#line 2759 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new QuantifiedExpr(
                LOC((yyloc)),
                ParseConstants::quant_some,
                dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(5) - (3)].node)),
                (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 322:

/* Line 690 of lalr1.cc  */
#line 2768 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new QuantifiedExpr(
                LOC((yyloc)),
                ParseConstants::quant_every,
                dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(5) - (3)].node)),
                (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 323:

/* Line 690 of lalr1.cc  */
#line 2779 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      QVarInDeclList *qvidl = new QVarInDeclList( LOC((yyloc)) );
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = qvidl;
    }
    break;

  case 324:

/* Line 690 of lalr1.cc  */
#line 2785 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      QVarInDeclList *qvidl = dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
      (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
    }
    break;

  case 325:

/* Line 690 of lalr1.cc  */
#line 2793 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 326:

/* Line 690 of lalr1.cc  */
#line 2797 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                          dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 327:

/* Line 690 of lalr1.cc  */
#line 2806 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new SwitchExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(8) - (5)].node)), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 328:

/* Line 690 of lalr1.cc  */
#line 2812 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = new SwitchCaseClauseList(LOC((yyloc)));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = scc_list_p;
    }
    break;

  case 329:

/* Line 690 of lalr1.cc  */
#line 2818 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 330:

/* Line 690 of lalr1.cc  */
#line 2826 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SwitchCaseClause(LOC((yyloc)), dynamic_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 331:

/* Line 690 of lalr1.cc  */
#line 2832 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = new SwitchCaseOperandList(LOC((yyloc)));
      sco_list_p->push_back((yysemantic_stack_[(2) - (2)].expr));
      (yyval.node) = sco_list_p;
    }
    break;

  case 332:

/* Line 690 of lalr1.cc  */
#line 2838 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = static_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node));
      sco_list_p->push_back((yysemantic_stack_[(3) - (3)].expr));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 333:

/* Line 690 of lalr1.cc  */
#line 2846 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new SwitchExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(8) - (5)].node)), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 334:

/* Line 690 of lalr1.cc  */
#line 2852 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = new SwitchCaseClauseList(LOC((yyloc)));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = scc_list_p;
    }
    break;

  case 335:

/* Line 690 of lalr1.cc  */
#line 2858 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 336:

/* Line 690 of lalr1.cc  */
#line 2866 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SwitchCaseClause(LOC((yyloc)), dynamic_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 337:

/* Line 690 of lalr1.cc  */
#line 2872 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC((yyloc)),
                              (yysemantic_stack_[(8) - (3)].expr),
                              static_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
                              (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 338:

/* Line 690 of lalr1.cc  */
#line 2879 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
                              (yysemantic_stack_[(10) - (3)].expr),
                              static_cast<CaseClauseList*>((yysemantic_stack_[(10) - (5)].node)),
                              static_cast<QName*>((yysemantic_stack_[(10) - (8)].expr)),
                              (yysemantic_stack_[(10) - (10)].expr));
    }
    break;

  case 339:

/* Line 690 of lalr1.cc  */
#line 2889 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC((yyloc)),
                              (yysemantic_stack_[(8) - (3)].expr),
                              static_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
                              (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 340:

/* Line 690 of lalr1.cc  */
#line 2896 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
                              (yysemantic_stack_[(10) - (3)].expr),
                              static_cast<CaseClauseList*>((yysemantic_stack_[(10) - (5)].node)),
                              static_cast<QName*>((yysemantic_stack_[(10) - (8)].expr)),
                              (yysemantic_stack_[(10) - (10)].expr));
    }
    break;

  case 341:

/* Line 690 of lalr1.cc  */
#line 2906 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
      cc_list_p->push_back(static_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = cc_list_p;
    }
    break;

  case 342:

/* Line 690 of lalr1.cc  */
#line 2912 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      cc_list_p->push_back(static_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 343:

/* Line 690 of lalr1.cc  */
#line 2920 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<SequenceTypeList*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 344:

/* Line 690 of lalr1.cc  */
#line 2926 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                          static_cast<SequenceTypeList*>((yysemantic_stack_[(7) - (5)].node)),
                          (yysemantic_stack_[(7) - (7)].expr));
     }
    break;

  case 345:

/* Line 690 of lalr1.cc  */
#line 2935 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
      cc_list_p->push_back(static_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = cc_list_p;
    }
    break;

  case 346:

/* Line 690 of lalr1.cc  */
#line 2941 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = static_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      cc_list_p->push_back(static_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 347:

/* Line 690 of lalr1.cc  */
#line 2949 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<SequenceTypeList*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 348:

/* Line 690 of lalr1.cc  */
#line 2955 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                          static_cast<SequenceTypeList*>((yysemantic_stack_[(7) - (5)].node)),
                          (yysemantic_stack_[(7) - (7)].expr));
     }
    break;

  case 349:

/* Line 690 of lalr1.cc  */
#line 2964 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      SequenceTypeList* seqList = new SequenceTypeList(LOC((yyloc)));
      seqList->push_back(static_cast<SequenceType*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = seqList;
    }
    break;

  case 350:

/* Line 690 of lalr1.cc  */
#line 2970 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      SequenceTypeList* seqList = static_cast<SequenceTypeList*>((yysemantic_stack_[(3) - (1)].node));
      seqList->push_back(static_cast<SequenceType*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 351:

/* Line 690 of lalr1.cc  */
#line 2978 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new IfExpr(LOC ((yyloc)), (yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (6)].expr), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 352:

/* Line 690 of lalr1.cc  */
#line 2984 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 353:

/* Line 690 of lalr1.cc  */
#line 2988 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new OrExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
    }
    break;

  case 354:

/* Line 690 of lalr1.cc  */
#line 2994 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 355:

/* Line 690 of lalr1.cc  */
#line 2999 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AndExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 356:

/* Line 690 of lalr1.cc  */
#line 3005 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 357:

/* Line 690 of lalr1.cc  */
#line 3009 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                dynamic_cast<ValueComp*>((yysemantic_stack_[(3) - (2)].node)),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 358:

/* Line 690 of lalr1.cc  */
#line 3018 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)), dynamic_cast<NodeComp*>((yysemantic_stack_[(3) - (2)].node)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 359:

/* Line 690 of lalr1.cc  */
#line 3024 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_eq ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 360:

/* Line 690 of lalr1.cc  */
#line 3033 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_ne ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 361:

/* Line 690 of lalr1.cc  */
#line 3042 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            driver.getXqueryLexer()->interpretAsLessThan();
        }
    break;

  case 362:

/* Line 690 of lalr1.cc  */
#line 3046 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_lt ),
                (yysemantic_stack_[(4) - (1)].expr),
                (yysemantic_stack_[(4) - (4)].expr)
            );
        }
    break;

  case 363:

/* Line 690 of lalr1.cc  */
#line 3055 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_le ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 364:

/* Line 690 of lalr1.cc  */
#line 3064 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_gt ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 365:

/* Line 690 of lalr1.cc  */
#line 3073 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_ge ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 366:

/* Line 690 of lalr1.cc  */
#line 3084 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 367:

/* Line 690 of lalr1.cc  */
#line 3088 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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
#line 3099 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 369:

/* Line 690 of lalr1.cc  */
#line 3103 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new StringConcatExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
        }
    break;

  case 370:

/* Line 690 of lalr1.cc  */
#line 3108 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 371:

/* Line 690 of lalr1.cc  */
#line 3112 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 372:

/* Line 690 of lalr1.cc  */
#line 3118 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 373:

/* Line 690 of lalr1.cc  */
#line 3122 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RangeExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 374:

/* Line 690 of lalr1.cc  */
#line 3128 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 375:

/* Line 690 of lalr1.cc  */
#line 3132 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_plus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 376:

/* Line 690 of lalr1.cc  */
#line 3136 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_minus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 377:

/* Line 690 of lalr1.cc  */
#line 3142 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 378:

/* Line 690 of lalr1.cc  */
#line 3146 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mul, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 379:

/* Line 690 of lalr1.cc  */
#line 3152 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_div, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 380:

/* Line 690 of lalr1.cc  */
#line 3158 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_idiv, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 381:

/* Line 690 of lalr1.cc  */
#line 3164 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mod, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 382:

/* Line 690 of lalr1.cc  */
#line 3172 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 383:

/* Line 690 of lalr1.cc  */
#line 3176 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 384:

/* Line 690 of lalr1.cc  */
#line 3180 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 385:

/* Line 690 of lalr1.cc  */
#line 3186 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 386:

/* Line 690 of lalr1.cc  */
#line 3190 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_intersect, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 387:

/* Line 690 of lalr1.cc  */
#line 3196 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_except, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 388:

/* Line 690 of lalr1.cc  */
#line 3204 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 389:

/* Line 690 of lalr1.cc  */
#line 3208 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InstanceofExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 390:

/* Line 690 of lalr1.cc  */
#line 3216 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 391:

/* Line 690 of lalr1.cc  */
#line 3220 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new TreatExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 392:

/* Line 690 of lalr1.cc  */
#line 3228 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 393:

/* Line 690 of lalr1.cc  */
#line 3232 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CastableExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 394:

/* Line 690 of lalr1.cc  */
#line 3240 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 395:

/* Line 690 of lalr1.cc  */
#line 3244 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CastExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 396:

/* Line 690 of lalr1.cc  */
#line 3252 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SingleType(LOC((yyloc)), dynamic_cast<SimpleType*>((yysemantic_stack_[(1) - (1)].node)), false);
    }
    break;

  case 397:

/* Line 690 of lalr1.cc  */
#line 3256 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SingleType(LOC((yyloc)), dynamic_cast<SimpleType*>((yysemantic_stack_[(2) - (1)].node)), true);
    }
    break;

  case 398:

/* Line 690 of lalr1.cc  */
#line 3262 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 399:

/* Line 690 of lalr1.cc  */
#line 3266 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnaryExpr( LOC((yyloc)), dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 400:

/* Line 690 of lalr1.cc  */
#line 3272 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), true );
        }
    break;

  case 401:

/* Line 690 of lalr1.cc  */
#line 3276 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), false );
        }
    break;

  case 402:

/* Line 690 of lalr1.cc  */
#line 3280 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 403:

/* Line 690 of lalr1.cc  */
#line 3284 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            if ( SignList *sl = dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)) )
                sl->negate();
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 407:

/* Line 690 of lalr1.cc  */
#line 3297 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
        (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
      }
    break;

  case 408:

/* Line 690 of lalr1.cc  */
#line 3302 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
        (yyval.expr) = new SimpleMapExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
      }
    break;

  case 409:

/* Line 690 of lalr1.cc  */
#line 3308 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_eq );
        }
    break;

  case 410:

/* Line 690 of lalr1.cc  */
#line 3312 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ne );
        }
    break;

  case 411:

/* Line 690 of lalr1.cc  */
#line 3316 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_lt );
        }
    break;

  case 412:

/* Line 690 of lalr1.cc  */
#line 3320 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_le );
        }
    break;

  case 413:

/* Line 690 of lalr1.cc  */
#line 3324 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_gt );
        }
    break;

  case 414:

/* Line 690 of lalr1.cc  */
#line 3328 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ge );
        }
    break;

  case 415:

/* Line 690 of lalr1.cc  */
#line 3334 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_is );
        }
    break;

  case 416:

/* Line 690 of lalr1.cc  */
#line 3338 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_precedes );
        }
    break;

  case 417:

/* Line 690 of lalr1.cc  */
#line 3342 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_follows );
        }
    break;

  case 418:

/* Line 690 of lalr1.cc  */
#line 3348 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 419:

/* Line 690 of lalr1.cc  */
#line 3352 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "lax", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 420:

/* Line 690 of lalr1.cc  */
#line 3356 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 421:

/* Line 690 of lalr1.cc  */
#line 3360 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr(
                LOC((yyloc)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (3)].node))->get_name(), (yysemantic_stack_[(6) - (5)].expr)
            );
            delete (yysemantic_stack_[(6) - (3)].node);
        }
    break;

  case 422:

/* Line 690 of lalr1.cc  */
#line 3369 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(3) - (1)].node)), NULL
            );
        }
    break;

  case 423:

/* Line 690 of lalr1.cc  */
#line 3375 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)), (yysemantic_stack_[(4) - (3)].expr)
            );
        }
    break;

  case 424:

/* Line 690 of lalr1.cc  */
#line 3383 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            PragmaList *pl = new PragmaList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = pl;
        }
    break;

  case 425:

/* Line 690 of lalr1.cc  */
#line 3389 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            if ( PragmaList *pl = dynamic_cast<PragmaList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 426:

/* Line 690 of lalr1.cc  */
#line 3397 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
        }
    break;

  case 427:

/* Line 690 of lalr1.cc  */
#line 3401 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) ), "" );
        }
    break;

  case 428:

/* Line 690 of lalr1.cc  */
#line 3405 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), true ), "" );
        }
    break;

  case 429:

/* Line 690 of lalr1.cc  */
#line 3411 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new PathExpr(LOC((yyloc)), ParseConstants::path_leading_lone_slash, NULL);
    }
    break;

  case 430:

/* Line 690 of lalr1.cc  */
#line 3415 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      RelativePathExpr* rpe;
      rpe = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slash, NULL, (yysemantic_stack_[(2) - (2)].expr), false);
      (yyval.expr) = new PathExpr(LOC((yyloc)),
                        ParseConstants::path_leading_slash,
                        rpe);
    }
    break;

  case 431:

/* Line 690 of lalr1.cc  */
#line 3423 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      RelativePathExpr* rpe;
      rpe = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slashslash, NULL, (yysemantic_stack_[(2) - (2)].expr), false);
      (yyval.expr) = new PathExpr(LOC((yyloc)),
                        ParseConstants::path_leading_slashslash,
                        rpe);
    }
    break;

  case 432:

/* Line 690 of lalr1.cc  */
#line 3431 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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

  case 433:

/* Line 690 of lalr1.cc  */
#line 3449 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = NULL;
    }
    break;

  case 434:

/* Line 690 of lalr1.cc  */
#line 3455 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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

  case 435:

/* Line 690 of lalr1.cc  */
#line 3465 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr), false);
    }
    break;

  case 436:

/* Line 690 of lalr1.cc  */
#line 3469 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slashslash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr), false);
    }
    break;

  case 439:

/* Line 690 of lalr1.cc  */
#line 3479 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)), dynamic_cast<ForwardStep*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 440:

/* Line 690 of lalr1.cc  */
#line 3485 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)),
                dynamic_cast<ForwardStep*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 441:

/* Line 690 of lalr1.cc  */
#line 3493 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)), dynamic_cast<ReverseStep*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 442:

/* Line 690 of lalr1.cc  */
#line 3499 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)),
                dynamic_cast<ReverseStep*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 443:

/* Line 690 of lalr1.cc  */
#line 3509 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardStep(
                LOC((yyloc)), dynamic_cast<ForwardAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node)
            );
        }
    break;

  case 444:

/* Line 690 of lalr1.cc  */
#line 3515 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardStep(
                LOC((yyloc)), dynamic_cast<AbbrevForwardStep*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 445:

/* Line 690 of lalr1.cc  */
#line 3523 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_child );
        }
    break;

  case 446:

/* Line 690 of lalr1.cc  */
#line 3527 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_descendant);
        }
    break;

  case 447:

/* Line 690 of lalr1.cc  */
#line 3531 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_attribute );
        }
    break;

  case 448:

/* Line 690 of lalr1.cc  */
#line 3535 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_self );
        }
    break;

  case 449:

/* Line 690 of lalr1.cc  */
#line 3539 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis(
                LOC((yyloc)), ParseConstants::axis_descendant_or_self
            );
        }
    break;

  case 450:

/* Line 690 of lalr1.cc  */
#line 3545 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis(
                LOC((yyloc)), ParseConstants::axis_following_sibling
            );
        }
    break;

  case 451:

/* Line 690 of lalr1.cc  */
#line 3551 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_following );
        }
    break;

  case 452:

/* Line 690 of lalr1.cc  */
#line 3557 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AbbrevForwardStep( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), false );
        }
    break;

  case 453:

/* Line 690 of lalr1.cc  */
#line 3561 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AbbrevForwardStep( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].node), true );
        }
    break;

  case 454:

/* Line 690 of lalr1.cc  */
#line 3567 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseStep( LOC((yyloc)), dynamic_cast<ReverseAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node) );
        }
    break;

  case 455:

/* Line 690 of lalr1.cc  */
#line 3571 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            ReverseAxis *ra = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_parent
            );
            (yyval.node) = new ReverseStep( LOC((yyloc)), ra, NULL );
        }
    break;

  case 456:

/* Line 690 of lalr1.cc  */
#line 3580 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_parent );
        }
    break;

  case 457:

/* Line 690 of lalr1.cc  */
#line 3584 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_ancestor );
        }
    break;

  case 458:

/* Line 690 of lalr1.cc  */
#line 3588 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_preceding_sibling
            );
        }
    break;

  case 459:

/* Line 690 of lalr1.cc  */
#line 3594 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_preceding );
        }
    break;

  case 460:

/* Line 690 of lalr1.cc  */
#line 3598 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_ancestor_or_self
            );
        }
    break;

  case 463:

/* Line 690 of lalr1.cc  */
#line 3610 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 464:

/* Line 690 of lalr1.cc  */
#line 3614 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), dynamic_cast<Wildcard*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 465:

/* Line 690 of lalr1.cc  */
#line 3620 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", "", ParseConstants::wild_all, false);
    }
    break;

  case 466:

/* Line 690 of lalr1.cc  */
#line 3624 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), "", ParseConstants::wild_elem, false);
    }
    break;

  case 467:

/* Line 690 of lalr1.cc  */
#line 3628 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), "", ParseConstants::wild_elem, true);
    }
    break;

  case 468:

/* Line 690 of lalr1.cc  */
#line 3632 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", SYMTAB((yysemantic_stack_[(1) - (1)].sval)), ParseConstants::wild_prefix, false);
    }
    break;

  case 469:

/* Line 690 of lalr1.cc  */
#line 3638 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
     }
    break;

  case 470:

/* Line 690 of lalr1.cc  */
#line 3642 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new FilterExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
     }
    break;

  case 471:

/* Line 690 of lalr1.cc  */
#line 3646 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DynamicFunctionInvocation(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), false);
     }
    break;

  case 472:

/* Line 690 of lalr1.cc  */
#line 3650 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DynamicFunctionInvocation(LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node)), false);
     }
    break;

  case 473:

/* Line 690 of lalr1.cc  */
#line 3654 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new JSONArrayUnboxing(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr));
    }
    break;

  case 474:

/* Line 690 of lalr1.cc  */
#line 3660 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      PredicateList* pl = new PredicateList( LOC((yyloc)) );
      pl->push_back(dynamic_cast<exprnode*>((yysemantic_stack_[(1) - (1)].expr)));
      (yyval.node) = pl;
    }
    break;

  case 475:

/* Line 690 of lalr1.cc  */
#line 3666 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      if (PredicateList* pl = dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (1)].node)))
        pl->push_back(dynamic_cast<exprnode*>((yysemantic_stack_[(2) - (2)].expr)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 476:

/* Line 690 of lalr1.cc  */
#line 3674 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 491:

/* Line 690 of lalr1.cc  */
#line 3696 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 492:

/* Line 690 of lalr1.cc  */
#line 3700 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 493:

/* Line 690 of lalr1.cc  */
#line 3706 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_decimal, *(yysemantic_stack_[(1) - (1)].decval)
            );
            delete yylval.decval;
        }
    break;

  case 494:

/* Line 690 of lalr1.cc  */
#line 3713 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_integer, *(yysemantic_stack_[(1) - (1)].ival)
            );
            delete yylval.ival;
        }
    break;

  case 495:

/* Line 690 of lalr1.cc  */
#line 3720 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_double, *(yysemantic_stack_[(1) - (1)].dval)
            );
            delete yylval.dval;
        }
    break;

  case 496:

/* Line 690 of lalr1.cc  */
#line 3729 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new VarRef(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)));
        }
    break;

  case 497:

/* Line 690 of lalr1.cc  */
#line 3735 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), NULL);
        }
    break;

  case 498:

/* Line 690 of lalr1.cc  */
#line 3739 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 499:

/* Line 690 of lalr1.cc  */
#line 3745 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            driver.addCommonLanguageWarning((yylocation_stack_[(1) - (1)]), ZED(ZWST0009_CONTEXT_ITEM_EXPR));
            (yyval.expr) = new ContextItemExpr( LOC((yyloc)) );
        }
    break;

  case 500:

/* Line 690 of lalr1.cc  */
#line 3752 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new OrderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 501:

/* Line 690 of lalr1.cc  */
#line 3758 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnorderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 502:

/* Line 690 of lalr1.cc  */
#line 3764 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FunctionCall(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), NULL);
    }
    break;

  case 503:

/* Line 690 of lalr1.cc  */
#line 3768 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 3786 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      ArgList* al = new ArgList(LOC((yyloc)));
      al->push_back(new ArgumentPlaceholder(LOC((yyloc))));
      (yyval.node) = al;
    }
    break;

  case 505:

/* Line 690 of lalr1.cc  */
#line 3792 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      if (ArgList* al = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node)))
        al->push_back(new ArgumentPlaceholder(LOC((yyloc))));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 506:

/* Line 690 of lalr1.cc  */
#line 3798 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      ArgList *al = new ArgList( LOC((yyloc)) );
      al->push_back( (yysemantic_stack_[(1) - (1)].expr) );
      (yyval.node) = al;
    }
    break;

  case 507:

/* Line 690 of lalr1.cc  */
#line 3804 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      if ( ArgList *al = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node)) )
        al->push_back( (yysemantic_stack_[(3) - (3)].expr) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 508:

/* Line 690 of lalr1.cc  */
#line 3812 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 509:

/* Line 690 of lalr1.cc  */
#line 3816 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 510:

/* Line 690 of lalr1.cc  */
#line 3822 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new LiteralFunctionItem(LOC ((yyloc)), dynamic_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].ival));
    }
    break;

  case 511:

/* Line 690 of lalr1.cc  */
#line 3828 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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
#line 3847 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirElemConstructor(LOC((yyloc)),
                                  static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                                  NULL,
                                  NULL,
                                  NULL);
    }
    break;

  case 518:

/* Line 690 of lalr1.cc  */
#line 3855 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 3871 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirElemConstructor(LOC((yyloc)),
                                  static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                                  NULL,
                                  dynamic_cast<DirAttributeList*>((yysemantic_stack_[(5) - (3)].node)),
                                  NULL);
    }
    break;

  case 520:

/* Line 690 of lalr1.cc  */
#line 3879 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 3897 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 3915 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 3933 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      DirElemContentList *decl = new DirElemContentList( LOC((yyloc)) );
      decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(1) - (1)].expr)) );
      (yyval.node) = decl;
    }
    break;

  case 524:

/* Line 690 of lalr1.cc  */
#line 3939 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      DirElemContentList *decl = dynamic_cast<DirElemContentList*>((yysemantic_stack_[(2) - (1)].node));
      if ( decl )
        decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(2) - (2)].expr)) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 525:

/* Line 690 of lalr1.cc  */
#line 3948 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      DirAttributeList *dal = new DirAttributeList( LOC((yyloc)) );
      dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = dal;
    }
    break;

  case 526:

/* Line 690 of lalr1.cc  */
#line 3954 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      DirAttributeList *dal = dynamic_cast<DirAttributeList*>((yysemantic_stack_[(2) - (1)].node));
      if ( dal )
        dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 527:

/* Line 690 of lalr1.cc  */
#line 3963 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DirAttr(LOC((yyloc)),
                       static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                       dynamic_cast<DirAttributeValue*>((yysemantic_stack_[(6) - (6)].node)));
    }
    break;

  case 530:

/* Line 690 of lalr1.cc  */
#line 3973 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DirAttributeValue(LOC((yyloc)),
                                 dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
    }
    break;

  case 531:

/* Line 690 of lalr1.cc  */
#line 3978 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DirAttributeValue( LOC((yyloc)),
                                  dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
    }
    break;

  case 532:

/* Line 690 of lalr1.cc  */
#line 3984 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QuoteAttrContentList( LOC((yyloc)) );
    }
    break;

  case 533:

/* Line 690 of lalr1.cc  */
#line 3988 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 534:

/* Line 690 of lalr1.cc  */
#line 3994 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
      qacl->push_back( new QuoteAttrValueContent( LOC((yyloc)), "\"" ) );
      (yyval.node) = qacl;
    }
    break;

  case 535:

/* Line 690 of lalr1.cc  */
#line 4000 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
      qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = qacl;
    }
    break;

  case 536:

/* Line 690 of lalr1.cc  */
#line 4006 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      QuoteAttrContentList* qacl = dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
      if ( qacl )
        qacl->push_back( new QuoteAttrValueContent( LOC((yyloc)), "\"" ) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 537:

/* Line 690 of lalr1.cc  */
#line 4013 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      QuoteAttrContentList *qacl = dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
      if ( qacl )
        qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 538:

/* Line 690 of lalr1.cc  */
#line 4021 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AposAttrContentList( LOC((yyloc)) );
    }
    break;

  case 539:

/* Line 690 of lalr1.cc  */
#line 4025 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 540:

/* Line 690 of lalr1.cc  */
#line 4031 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
      aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
      (yyval.node) = aacl;
    }
    break;

  case 541:

/* Line 690 of lalr1.cc  */
#line 4037 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
      aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = aacl;
    }
    break;

  case 542:

/* Line 690 of lalr1.cc  */
#line 4043 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
      if (aacl)
        aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 543:

/* Line 690 of lalr1.cc  */
#line 4050 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
      if ( aacl )
        aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 544:

/* Line 690 of lalr1.cc  */
#line 4059 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QuoteAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
    }
    break;

  case 545:

/* Line 690 of lalr1.cc  */
#line 4063 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QuoteAttrValueContent(LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
    }
    break;

  case 546:

/* Line 690 of lalr1.cc  */
#line 4069 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AposAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
    }
    break;

  case 547:

/* Line 690 of lalr1.cc  */
#line 4073 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AposAttrValueContent(LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
    }
    break;

  case 548:

/* Line 690 of lalr1.cc  */
#line 4079 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirElemContent( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr) );
    }
    break;

  case 549:

/* Line 690 of lalr1.cc  */
#line 4083 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirElemContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
    }
    break;

  case 550:

/* Line 690 of lalr1.cc  */
#line 4087 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      rchandle<CDataSection> cdata_h = dynamic_cast<CDataSection*>((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = new DirElemContent( LOC((yyloc)), cdata_h );
    }
    break;

  case 551:

/* Line 690 of lalr1.cc  */
#line 4092 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      rchandle<CommonContent> cont_h = dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = new DirElemContent( LOC((yyloc)), cont_h );
    }
    break;

  case 552:

/* Line 690 of lalr1.cc  */
#line 4099 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CommonContent(LOC((yyloc)), ParseConstants::cont_charref, SYMTAB((yysemantic_stack_[(1) - (1)].sval)));
    }
    break;

  case 553:

/* Line 690 of lalr1.cc  */
#line 4103 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CommonContent(LOC((yyloc)), ParseConstants::cont_escape_lbrace);
    }
    break;

  case 554:

/* Line 690 of lalr1.cc  */
#line 4107 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CommonContent(LOC((yyloc)), ParseConstants::cont_escape_rbrace);
    }
    break;

  case 555:

/* Line 690 of lalr1.cc  */
#line 4111 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CommonContent(LOC((yyloc)), new EnclosedExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr)));
    }
    break;

  case 556:

/* Line 690 of lalr1.cc  */
#line 4117 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 557:

/* Line 690 of lalr1.cc  */
#line 4122 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), "" );
    }
    break;

  case 558:

/* Line 690 of lalr1.cc  */
#line 4128 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      ERROR_IF_QNAME_NOT_NCNAME((yysemantic_stack_[(3) - (2)].expr), (yylocation_stack_[(3) - (2)]));
      (yyval.expr) = new DirPIConstructor( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)) );
    }
    break;

  case 559:

/* Line 690 of lalr1.cc  */
#line 4134 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      ERROR_IF_QNAME_NOT_NCNAME((yysemantic_stack_[(3) - (2)].expr), (yylocation_stack_[(3) - (2)]));
      (yyval.expr) = new DirPIConstructor( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
    }
    break;

  case 560:

/* Line 690 of lalr1.cc  */
#line 4141 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CDataSection( LOC((yyloc)),SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
    }
    break;

  case 561:

/* Line 690 of lalr1.cc  */
#line 4147 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 562:

/* Line 690 of lalr1.cc  */
#line 4152 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 563:

/* Line 690 of lalr1.cc  */
#line 4157 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 564:

/* Line 690 of lalr1.cc  */
#line 4162 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 565:

/* Line 690 of lalr1.cc  */
#line 4167 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 566:

/* Line 690 of lalr1.cc  */
#line 4172 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 568:

/* Line 690 of lalr1.cc  */
#line 4180 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CompDocConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
    }
    break;

  case 569:

/* Line 690 of lalr1.cc  */
#line 4186 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CompElemConstructor(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval))), (yysemantic_stack_[(3) - (2)].expr));
    }
    break;

  case 570:

/* Line 690 of lalr1.cc  */
#line 4190 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CompElemConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
    }
    break;

  case 571:

/* Line 690 of lalr1.cc  */
#line 4196 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval))), (yysemantic_stack_[(3) - (2)].expr) );
    }
    break;

  case 572:

/* Line 690 of lalr1.cc  */
#line 4200 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
    }
    break;

  case 573:

/* Line 690 of lalr1.cc  */
#line 4206 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CompTextConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
    }
    break;

  case 574:

/* Line 690 of lalr1.cc  */
#line 4212 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CompCommentConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
    }
    break;

  case 575:

/* Line 690 of lalr1.cc  */
#line 4218 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CompPIConstructor(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval)), (yysemantic_stack_[(3) - (2)].expr));
    }
    break;

  case 576:

/* Line 690 of lalr1.cc  */
#line 4222 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CompPIConstructor(LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
    }
    break;

  case 577:

/* Line 690 of lalr1.cc  */
#line 4228 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CompNamespaceConstructor(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval)), (yysemantic_stack_[(3) - (2)].expr));
    }
    break;

  case 578:

/* Line 690 of lalr1.cc  */
#line 4232 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CompNamespaceConstructor(LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
    }
    break;

  case 579:

/* Line 690 of lalr1.cc  */
#line 4238 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 580:

/* Line 690 of lalr1.cc  */
#line 4244 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL );
        }
    break;

  case 581:

/* Line 690 of lalr1.cc  */
#line 4248 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node)));
        }
    break;

  case 582:

/* Line 690 of lalr1.cc  */
#line 4252 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 583:

/* Line 690 of lalr1.cc  */
#line 4258 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_optionally
            );
        }
    break;

  case 584:

/* Line 690 of lalr1.cc  */
#line 4264 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_zero_or_more
            );
        }
    break;

  case 585:

/* Line 690 of lalr1.cc  */
#line 4270 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_one_or_more
            );
        }
    break;

  case 586:

/* Line 690 of lalr1.cc  */
#line 4278 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 587:

/* Line 690 of lalr1.cc  */
#line 4282 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 588:

/* Line 690 of lalr1.cc  */
#line 4286 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ItemType( LOC((yyloc)), true );
        }
    break;

  case 589:

/* Line 690 of lalr1.cc  */
#line 4290 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new StructuredItemType(LOC((yyloc)));
        }
    break;

  case 590:

/* Line 690 of lalr1.cc  */
#line 4294 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 591:

/* Line 690 of lalr1.cc  */
#line 4298 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 592:

/* Line 690 of lalr1.cc  */
#line 4302 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 593:

/* Line 690 of lalr1.cc  */
#line 4308 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
          TypeList* aTypeList = new TypeList(LOC ((yyloc)));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(1) - (1)].node)));
          (yyval.node) = aTypeList;
        }
    break;

  case 594:

/* Line 690 of lalr1.cc  */
#line 4314 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
          TypeList* aTypeList = dynamic_cast<TypeList *>((yysemantic_stack_[(3) - (1)].node));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
          (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 595:

/* Line 690 of lalr1.cc  */
#line 4322 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GeneralizedAtomicType( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
    }
    break;

  case 596:

/* Line 690 of lalr1.cc  */
#line 4328 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SimpleType( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
    }
    break;

  case 597:

/* Line 690 of lalr1.cc  */
#line 4334 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 598:

/* Line 690 of lalr1.cc  */
#line 4338 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 599:

/* Line 690 of lalr1.cc  */
#line 4342 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 600:

/* Line 690 of lalr1.cc  */
#line 4346 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 601:

/* Line 690 of lalr1.cc  */
#line 4350 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 602:

/* Line 690 of lalr1.cc  */
#line 4354 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 603:

/* Line 690 of lalr1.cc  */
#line 4358 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 604:

/* Line 690 of lalr1.cc  */
#line 4362 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 605:

/* Line 690 of lalr1.cc  */
#line 4366 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 606:

/* Line 690 of lalr1.cc  */
#line 4370 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 607:

/* Line 690 of lalr1.cc  */
#line 4376 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnyKindTest( LOC((yyloc)) );
    }
    break;

  case 608:

/* Line 690 of lalr1.cc  */
#line 4382 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = NULL;
    }
    break;

  case 609:

/* Line 690 of lalr1.cc  */
#line 4388 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DocumentTest(LOC((yyloc)));
    }
    break;

  case 610:

/* Line 690 of lalr1.cc  */
#line 4392 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DocumentTest(LOC((yyloc)), dynamic_cast<ElementTest*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 611:

/* Line 690 of lalr1.cc  */
#line 4396 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DocumentTest(LOC((yyloc)), dynamic_cast<SchemaElementTest*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 612:

/* Line 690 of lalr1.cc  */
#line 4402 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new NamespaceTest(LOC((yyloc)));
    }
    break;

  case 613:

/* Line 690 of lalr1.cc  */
#line 4407 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new TextTest(LOC((yyloc)));
    }
    break;

  case 614:

/* Line 690 of lalr1.cc  */
#line 4413 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CommentTest(LOC((yyloc)));
    }
    break;

  case 615:

/* Line 690 of lalr1.cc  */
#line 4419 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), "" );
        }
    break;

  case 616:

/* Line 690 of lalr1.cc  */
#line 4423 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            ERROR_IF_QNAME_NOT_NCNAME((yysemantic_stack_[(4) - (3)].expr), (yylocation_stack_[(4) - (3)]));
            (yyval.node) = new PITest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 617:

/* Line 690 of lalr1.cc  */
#line 4428 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 618:

/* Line 690 of lalr1.cc  */
#line 4434 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 619:

/* Line 690 of lalr1.cc  */
#line 4438 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL
            );
        }
    break;

  case 620:

/* Line 690 of lalr1.cc  */
#line 4444 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 621:

/* Line 690 of lalr1.cc  */
#line 4450 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 622:

/* Line 690 of lalr1.cc  */
#line 4454 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 623:

/* Line 690 of lalr1.cc  */
#line 4462 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaAttributeTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 624:

/* Line 690 of lalr1.cc  */
#line 4468 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest( LOC((yyloc)), NULL, NULL, true );
        }
    break;

  case 625:

/* Line 690 of lalr1.cc  */
#line 4472 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL, true
            );
        }
    break;

  case 626:

/* Line 690 of lalr1.cc  */
#line 4478 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 4487 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 4496 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, NULL, true
            );
        }
    break;

  case 629:

/* Line 690 of lalr1.cc  */
#line 4502 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), false
            );
        }
    break;

  case 630:

/* Line 690 of lalr1.cc  */
#line 4508 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), true
            );
        }
    break;

  case 631:

/* Line 690 of lalr1.cc  */
#line 4516 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaElementTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 632:

/* Line 690 of lalr1.cc  */
#line 4522 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 633:

/* Line 690 of lalr1.cc  */
#line 4528 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (1)].expr)), true );
        }
    break;

  case 634:

/* Line 690 of lalr1.cc  */
#line 4534 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new StringLiteral( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 635:

/* Line 690 of lalr1.cc  */
#line 4540 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 636:

/* Line 690 of lalr1.cc  */
#line 4544 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 637:

/* Line 690 of lalr1.cc  */
#line 4550 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnyFunctionTest(LOC((yyloc)));
    }
    break;

  case 638:

/* Line 690 of lalr1.cc  */
#line 4556 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)), dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (5)].node)));
        }
    break;

  case 639:

/* Line 690 of lalr1.cc  */
#line 4560 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)),
              dynamic_cast<TypeList *>((yysemantic_stack_[(6) - (3)].node)),
              dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (6)].node)));
        }
    break;

  case 640:

/* Line 690 of lalr1.cc  */
#line 4568 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
           (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 641:

/* Line 690 of lalr1.cc  */
#line 4574 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::strict_validation
            );
        }
    break;

  case 642:

/* Line 690 of lalr1.cc  */
#line 4580 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::lax_validation
            );
        }
    break;

  case 643:

/* Line 690 of lalr1.cc  */
#line 4586 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::skip_validation
            );
        }
    break;

  case 644:

/* Line 690 of lalr1.cc  */
#line 4594 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 645:

/* Line 690 of lalr1.cc  */
#line 4598 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 646:

/* Line 690 of lalr1.cc  */
#line 4604 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 647:

/* Line 690 of lalr1.cc  */
#line 4610 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 648:

/* Line 690 of lalr1.cc  */
#line 4614 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 649:

/* Line 690 of lalr1.cc  */
#line 4620 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 650:

/* Line 690 of lalr1.cc  */
#line 4624 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 651:

/* Line 690 of lalr1.cc  */
#line 4630 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                  LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 652:

/* Line 690 of lalr1.cc  */
#line 4636 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)),
                store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 653:

/* Line 690 of lalr1.cc  */
#line 4643 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 654:

/* Line 690 of lalr1.cc  */
#line 4651 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 655:

/* Line 690 of lalr1.cc  */
#line 4656 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 656:

/* Line 690 of lalr1.cc  */
#line 4662 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::NODE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 657:

/* Line 690 of lalr1.cc  */
#line 4668 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::VALUE_OF_NODE, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 658:

/* Line 690 of lalr1.cc  */
#line 4676 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RenameExpr( LOC ((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 659:

/* Line 690 of lalr1.cc  */
#line 4682 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList *cvl = dynamic_cast<CopyVarList*>((yysemantic_stack_[(7) - (3)].expr));
      (yyval.expr) = new TransformExpr( LOC((yyloc)), cvl, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr) );
    }
    break;

  case 660:

/* Line 690 of lalr1.cc  */
#line 4689 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList* lList = new CopyVarList(LOC((yyloc)));
      lList->push_back (dynamic_cast<VarBinding*> ((yysemantic_stack_[(1) - (1)].expr)));
      (yyval.expr) = lList;
    }
    break;

  case 661:

/* Line 690 of lalr1.cc  */
#line 4695 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList* lList = dynamic_cast<CopyVarList*>((yysemantic_stack_[(4) - (1)].expr));
      VarBinding* lBinding = dynamic_cast<VarBinding*>((yysemantic_stack_[(4) - (4)].expr));
      lList->push_back(lBinding);
      (yyval.expr) = lList;
    }
    break;

  case 662:

/* Line 690 of lalr1.cc  */
#line 4704 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new VarBinding(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 663:

/* Line 690 of lalr1.cc  */
#line 4710 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new TryExpr( LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 664:

/* Line 690 of lalr1.cc  */
#line 4716 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            CatchListExpr *cle = new CatchListExpr( LOC((yyloc)) );
            cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.expr) = cle;
        }
    break;

  case 665:

/* Line 690 of lalr1.cc  */
#line 4722 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
            if ( cle )
                cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
        }
    break;

  case 666:

/* Line 690 of lalr1.cc  */
#line 4731 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)), *(yysemantic_stack_[(3) - (2)].name_test_list), (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 667:

/* Line 690 of lalr1.cc  */
#line 4738 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 668:

/* Line 690 of lalr1.cc  */
#line 4744 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            CatchExpr::NameTestList *ntl = new CatchExpr::NameTestList;
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 669:

/* Line 690 of lalr1.cc  */
#line 4750 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            CatchExpr::NameTestList *ntl =
                static_cast<CatchExpr::NameTestList*>((yysemantic_stack_[(3) - (1)].name_test_list));
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 670:

/* Line 690 of lalr1.cc  */
#line 4759 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTSelection( LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), (yysemantic_stack_[(2) - (2)].pos_filter_list) );
            delete (yysemantic_stack_[(2) - (2)].pos_filter_list);
        }
    break;

  case 671:

/* Line 690 of lalr1.cc  */
#line 4766 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = NULL;
        }
    break;

  case 672:

/* Line 690 of lalr1.cc  */
#line 4770 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = (yysemantic_stack_[(1) - (1)].pos_filter_list);
        }
    break;

  case 673:

/* Line 690 of lalr1.cc  */
#line 4776 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = new FTSelection::pos_filter_list_t;
            (yyval.pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 674:

/* Line 690 of lalr1.cc  */
#line 4781 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yysemantic_stack_[(2) - (1)].pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.pos_filter_list) = (yysemantic_stack_[(2) - (1)].pos_filter_list);
        }
    break;

  case 675:

/* Line 690 of lalr1.cc  */
#line 4788 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 676:

/* Line 690 of lalr1.cc  */
#line 4792 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTOr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 677:

/* Line 690 of lalr1.cc  */
#line 4798 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 678:

/* Line 690 of lalr1.cc  */
#line 4802 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnd( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 679:

/* Line 690 of lalr1.cc  */
#line 4808 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 680:

/* Line 690 of lalr1.cc  */
#line 4812 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTMildNot( LOC((yyloc)), (yysemantic_stack_[(4) - (1)].node), (yysemantic_stack_[(4) - (4)].node) );
        }
    break;

  case 681:

/* Line 690 of lalr1.cc  */
#line 4818 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 682:

/* Line 690 of lalr1.cc  */
#line 4822 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnaryNot(
                LOC((yyloc)), dynamic_cast<FTPrimaryWithOptions*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 683:

/* Line 690 of lalr1.cc  */
#line 4830 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 4840 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 685:

/* Line 690 of lalr1.cc  */
#line 4844 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 686:

/* Line 690 of lalr1.cc  */
#line 4849 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 687:

/* Line 690 of lalr1.cc  */
#line 4853 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 688:

/* Line 690 of lalr1.cc  */
#line 4859 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWeight( LOC((yyloc)), dynamic_cast<exprnode*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 689:

/* Line 690 of lalr1.cc  */
#line 4865 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsTimes(
                LOC((yyloc)),
                dynamic_cast<FTWords*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<FTTimes*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 690:

/* Line 690 of lalr1.cc  */
#line 4873 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 691:

/* Line 690 of lalr1.cc  */
#line 4877 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 692:

/* Line 690 of lalr1.cc  */
#line 4882 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 693:

/* Line 690 of lalr1.cc  */
#line 4886 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 694:

/* Line 690 of lalr1.cc  */
#line 4892 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTExtensionSelection(
                LOC((yyloc)),
                dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)),
                dynamic_cast<FTSelection*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 695:

/* Line 690 of lalr1.cc  */
#line 4901 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 696:

/* Line 690 of lalr1.cc  */
#line 4905 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 697:

/* Line 690 of lalr1.cc  */
#line 4911 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWords(
                LOC((yyloc)),
                dynamic_cast<FTWordsValue*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<FTAnyallOption*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 698:

/* Line 690 of lalr1.cc  */
#line 4921 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), static_cast<StringLiteral*>((yysemantic_stack_[(1) - (1)].expr)), NULL
            );
        }
    break;

  case 699:

/* Line 690 of lalr1.cc  */
#line 4927 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), NULL, dynamic_cast<exprnode*>((yysemantic_stack_[(3) - (2)].expr))
            );
        }
    break;

  case 700:

/* Line 690 of lalr1.cc  */
#line 4934 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::any );
        }
    break;

  case 701:

/* Line 690 of lalr1.cc  */
#line 4938 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 702:

/* Line 690 of lalr1.cc  */
#line 4944 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 703:

/* Line 690 of lalr1.cc  */
#line 4948 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 704:

/* Line 690 of lalr1.cc  */
#line 4952 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::phrase );
        }
    break;

  case 705:

/* Line 690 of lalr1.cc  */
#line 4957 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any;
        }
    break;

  case 706:

/* Line 690 of lalr1.cc  */
#line 4961 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any_word;
        }
    break;

  case 707:

/* Line 690 of lalr1.cc  */
#line 4966 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all;
        }
    break;

  case 708:

/* Line 690 of lalr1.cc  */
#line 4970 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all_words;
        }
    break;

  case 709:

/* Line 690 of lalr1.cc  */
#line 4976 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 710:

/* Line 690 of lalr1.cc  */
#line 4980 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 711:

/* Line 690 of lalr1.cc  */
#line 4984 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 712:

/* Line 690 of lalr1.cc  */
#line 4988 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 713:

/* Line 690 of lalr1.cc  */
#line 4992 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 714:

/* Line 690 of lalr1.cc  */
#line 4998 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTOrder( LOC((yyloc)) );
        }
    break;

  case 715:

/* Line 690 of lalr1.cc  */
#line 5004 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWindow(
                LOC((yyloc)),
                static_cast<AdditiveExpr*>((yysemantic_stack_[(3) - (2)].expr)),
                static_cast<FTUnit*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 716:

/* Line 690 of lalr1.cc  */
#line 5014 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDistance(
                LOC((yyloc)),
                dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<FTUnit*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 717:

/* Line 690 of lalr1.cc  */
#line 5024 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::words );
        }
    break;

  case 718:

/* Line 690 of lalr1.cc  */
#line 5028 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::sentences );
        }
    break;

  case 719:

/* Line 690 of lalr1.cc  */
#line 5032 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::paragraphs );
        }
    break;

  case 720:

/* Line 690 of lalr1.cc  */
#line 5038 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            FTMatchOptions *mo = new FTMatchOptions( LOC((yyloc)) );
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = mo;
        }
    break;

  case 721:

/* Line 690 of lalr1.cc  */
#line 5044 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            FTMatchOptions *mo = dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (1)].node));
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 722:

/* Line 690 of lalr1.cc  */
#line 5052 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 723:

/* Line 690 of lalr1.cc  */
#line 5056 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 724:

/* Line 690 of lalr1.cc  */
#line 5060 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 725:

/* Line 690 of lalr1.cc  */
#line 5064 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 726:

/* Line 690 of lalr1.cc  */
#line 5068 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 727:

/* Line 690 of lalr1.cc  */
#line 5072 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 728:

/* Line 690 of lalr1.cc  */
#line 5076 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 729:

/* Line 690 of lalr1.cc  */
#line 5080 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 730:

/* Line 690 of lalr1.cc  */
#line 5086 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::sensitive );
        }
    break;

  case 731:

/* Line 690 of lalr1.cc  */
#line 5090 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::insensitive );
        }
    break;

  case 732:

/* Line 690 of lalr1.cc  */
#line 5094 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::lower );
        }
    break;

  case 733:

/* Line 690 of lalr1.cc  */
#line 5098 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::upper );
        }
    break;

  case 734:

/* Line 690 of lalr1.cc  */
#line 5104 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::sensitive
            );
        }
    break;

  case 735:

/* Line 690 of lalr1.cc  */
#line 5110 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::insensitive
            );
        }
    break;

  case 736:

/* Line 690 of lalr1.cc  */
#line 5118 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTExtensionOption(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval))
            );
        }
    break;

  case 737:

/* Line 690 of lalr1.cc  */
#line 5126 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::stemming );
        }
    break;

  case 738:

/* Line 690 of lalr1.cc  */
#line 5130 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::no_stemming );
        }
    break;

  case 739:

/* Line 690 of lalr1.cc  */
#line 5136 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 5146 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 5157 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTThesaurusOption( LOC((yyloc)), NULL, false, true );
        }
    break;

  case 742:

/* Line 690 of lalr1.cc  */
#line 5163 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 743:

/* Line 690 of lalr1.cc  */
#line 5167 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 744:

/* Line 690 of lalr1.cc  */
#line 5172 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = NULL;
        }
    break;

  case 745:

/* Line 690 of lalr1.cc  */
#line 5176 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(2) - (2)].thesaurus_id_list);
        }
    break;

  case 746:

/* Line 690 of lalr1.cc  */
#line 5182 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = new FTThesaurusOption::thesaurus_id_list_t;
            (yyval.thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 747:

/* Line 690 of lalr1.cc  */
#line 5187 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yysemantic_stack_[(3) - (1)].thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(3) - (1)].thesaurus_id_list);
        }
    break;

  case 748:

/* Line 690 of lalr1.cc  */
#line 5194 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTThesaurusID(
                LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (2)].sval)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), dynamic_cast<FTRange*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 749:

/* Line 690 of lalr1.cc  */
#line 5201 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.sval) = 0;
        }
    break;

  case 750:

/* Line 690 of lalr1.cc  */
#line 5205 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.sval) = (yysemantic_stack_[(2) - (2)].sval);
        }
    break;

  case 751:

/* Line 690 of lalr1.cc  */
#line 5211 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 752:

/* Line 690 of lalr1.cc  */
#line 5215 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 753:

/* Line 690 of lalr1.cc  */
#line 5221 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 5230 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, (yysemantic_stack_[(4) - (4)].incl_excl_list), ft_stop_words_mode::with_default
            );
            delete (yysemantic_stack_[(4) - (4)].incl_excl_list);
        }
    break;

  case 755:

/* Line 690 of lalr1.cc  */
#line 5237 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, NULL, ft_stop_words_mode::without
            );
        }
    break;

  case 756:

/* Line 690 of lalr1.cc  */
#line 5245 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), NULL );
        }
    break;

  case 757:

/* Line 690 of lalr1.cc  */
#line 5249 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), "", (yysemantic_stack_[(3) - (2)].strlist) );
        }
    break;

  case 758:

/* Line 690 of lalr1.cc  */
#line 5255 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            string_list_t *sl = new string_list_t;
            sl->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
            (yyval.strlist) = sl;
        }
    break;

  case 759:

/* Line 690 of lalr1.cc  */
#line 5261 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            if ( (yysemantic_stack_[(3) - (1)].strlist) )
                (yysemantic_stack_[(3) - (1)].strlist)->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
            (yyval.strlist) = (yysemantic_stack_[(3) - (1)].strlist);
        }
    break;

  case 760:

/* Line 690 of lalr1.cc  */
#line 5268 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = NULL;
        }
    break;

  case 761:

/* Line 690 of lalr1.cc  */
#line 5272 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = (yysemantic_stack_[(1) - (1)].incl_excl_list);
        }
    break;

  case 762:

/* Line 690 of lalr1.cc  */
#line 5278 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = new FTStopWordOption::incl_excl_list_t;
            (yyval.incl_excl_list)->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 763:

/* Line 690 of lalr1.cc  */
#line 5283 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            FTStopWordOption::incl_excl_list_t *iel = (yysemantic_stack_[(2) - (1)].incl_excl_list);
            if ( !iel )
                iel = new FTStopWordOption::incl_excl_list_t;
            iel->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.incl_excl_list) = iel;
        }
    break;

  case 764:

/* Line 690 of lalr1.cc  */
#line 5293 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordsInclExcl(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(2) - (2)].node)),
                ft_stop_words_unex::union_
            );
        }
    break;

  case 765:

/* Line 690 of lalr1.cc  */
#line 5301 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordsInclExcl(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(2) - (2)].node)),
                ft_stop_words_unex::except
            );
        }
    break;

  case 766:

/* Line 690 of lalr1.cc  */
#line 5311 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTLanguageOption( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 767:

/* Line 690 of lalr1.cc  */
#line 5317 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::with );
        }
    break;

  case 768:

/* Line 690 of lalr1.cc  */
#line 5321 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::without );
        }
    break;

  case 769:

/* Line 690 of lalr1.cc  */
#line 5327 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_start );
        }
    break;

  case 770:

/* Line 690 of lalr1.cc  */
#line 5331 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_end );
        }
    break;

  case 771:

/* Line 690 of lalr1.cc  */
#line 5335 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::entire );
        }
    break;

  case 772:

/* Line 690 of lalr1.cc  */
#line 5341 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTTimes( LOC((yyloc)), dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)) );
        }
    break;

  case 773:

/* Line 690 of lalr1.cc  */
#line 5347 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::exactly, (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 774:

/* Line 690 of lalr1.cc  */
#line 5351 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_least, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 775:

/* Line 690 of lalr1.cc  */
#line 5355 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_most, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 776:

/* Line 690 of lalr1.cc  */
#line 5359 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::from_to, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr) );
        }
    break;

  case 777:

/* Line 690 of lalr1.cc  */
#line 5365 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTScope(
                LOC((yyloc)),
                ft_scope::same,
                dynamic_cast<FTBigUnit*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 778:

/* Line 690 of lalr1.cc  */
#line 5373 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTScope(
                LOC((yyloc)),
                ft_scope::different,
                dynamic_cast<FTBigUnit*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 779:

/* Line 690 of lalr1.cc  */
#line 5383 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::sentence );
        }
    break;

  case 780:

/* Line 690 of lalr1.cc  */
#line 5387 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::paragraph );
        }
    break;

  case 781:

/* Line 690 of lalr1.cc  */
#line 5393 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTIgnoreOption( LOC((yyloc)), static_cast<UnionExpr*>((yysemantic_stack_[(3) - (3)].expr)) );
        }
    break;

  case 782:

/* Line 690 of lalr1.cc  */
#line 5399 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONArrayConstructor( LOC((yyloc)), NULL );
        }
    break;

  case 783:

/* Line 690 of lalr1.cc  */
#line 5403 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONArrayConstructor( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 784:

/* Line 690 of lalr1.cc  */
#line 5409 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), NULL, false);
        }
    break;

  case 785:

/* Line 690 of lalr1.cc  */
#line 5413 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), false);
        }
    break;

  case 786:

/* Line 690 of lalr1.cc  */
#line 5419 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), NULL, true);
        }
    break;

  case 787:

/* Line 690 of lalr1.cc  */
#line 5423 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), true);
        }
    break;

  case 788:

/* Line 690 of lalr1.cc  */
#line 5429 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONDirectObjectConstructor(LOC((yyloc)),
                                               dynamic_cast<JSONPairList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 789:

/* Line 690 of lalr1.cc  */
#line 5436 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
          JSONPairList* jpl = new JSONPairList(LOC((yyloc)));
          jpl->push_back(new JSONPairConstructor(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)));
          (yyval.node) = jpl;
        }
    break;

  case 790:

/* Line 690 of lalr1.cc  */
#line 5442 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
          JSONPairList* jpl = dynamic_cast<JSONPairList*>((yysemantic_stack_[(5) - (1)].node));
          assert(jpl);
          jpl->push_back(new JSONPairConstructor(LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)));
          (yyval.node) = jpl;
        }
    break;

  case 791:

/* Line 690 of lalr1.cc  */
#line 5451 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONObjectInsertExpr(LOC((yyloc)),
                                        (yysemantic_stack_[(5) - (3)].expr),
                                        (yysemantic_stack_[(5) - (5)].expr));
        }
    break;

  case 792:

/* Line 690 of lalr1.cc  */
#line 5457 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 5467 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONArrayInsertExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (5)].expr), (yysemantic_stack_[(8) - (8)].expr));
        }
    break;

  case 794:

/* Line 690 of lalr1.cc  */
#line 5473 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONArrayAppendExpr(LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
        }
    break;

  case 795:

/* Line 690 of lalr1.cc  */
#line 5479 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 5500 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 5524 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 5548 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 799:

/* Line 690 of lalr1.cc  */
#line 5552 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 800:

/* Line 690 of lalr1.cc  */
#line 5556 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 801:

/* Line 690 of lalr1.cc  */
#line 5562 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonItem);
        }
    break;

  case 802:

/* Line 690 of lalr1.cc  */
#line 5568 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonObject);
        }
    break;

  case 803:

/* Line 690 of lalr1.cc  */
#line 5574 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonArray);
        }
    break;

  case 806:

/* Line 690 of lalr1.cc  */
#line 5583 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))); }
    break;

  case 807:

/* Line 690 of lalr1.cc  */
#line 5584 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("attribute"))); }
    break;

  case 808:

/* Line 690 of lalr1.cc  */
#line 5585 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("comment"))); }
    break;

  case 809:

/* Line 690 of lalr1.cc  */
#line 5586 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("document-node"))); }
    break;

  case 810:

/* Line 690 of lalr1.cc  */
#line 5587 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("namespace-node"))); }
    break;

  case 811:

/* Line 690 of lalr1.cc  */
#line 5588 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("element"))); }
    break;

  case 812:

/* Line 690 of lalr1.cc  */
#line 5589 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("item"))); }
    break;

  case 813:

/* Line 690 of lalr1.cc  */
#line 5590 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("if"))); }
    break;

  case 814:

/* Line 690 of lalr1.cc  */
#line 5591 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("node"))); }
    break;

  case 815:

/* Line 690 of lalr1.cc  */
#line 5592 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("processing-instruction"))); }
    break;

  case 816:

/* Line 690 of lalr1.cc  */
#line 5593 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema-attribute"))); }
    break;

  case 817:

/* Line 690 of lalr1.cc  */
#line 5594 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema-element"))); }
    break;

  case 818:

/* Line 690 of lalr1.cc  */
#line 5595 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("text"))); }
    break;

  case 819:

/* Line 690 of lalr1.cc  */
#line 5596 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("typeswitch"))); }
    break;

  case 820:

/* Line 690 of lalr1.cc  */
#line 5597 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("switch"))); }
    break;

  case 821:

/* Line 690 of lalr1.cc  */
#line 5598 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("empty-sequence"))); }
    break;

  case 822:

/* Line 690 of lalr1.cc  */
#line 5599 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("while"))); }
    break;

  case 824:

/* Line 690 of lalr1.cc  */
#line 5603 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))); }
    break;

  case 825:

/* Line 690 of lalr1.cc  */
#line 5604 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("xquery"))); }
    break;

  case 826:

/* Line 690 of lalr1.cc  */
#line 5605 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("empty"))); }
    break;

  case 827:

/* Line 690 of lalr1.cc  */
#line 5606 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("boundary-space"))); }
    break;

  case 828:

/* Line 690 of lalr1.cc  */
#line 5607 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ft-option"))); }
    break;

  case 829:

/* Line 690 of lalr1.cc  */
#line 5608 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("base-uri"))); }
    break;

  case 830:

/* Line 690 of lalr1.cc  */
#line 5609 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lax"))); }
    break;

  case 831:

/* Line 690 of lalr1.cc  */
#line 5610 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("strict"))); }
    break;

  case 832:

/* Line 690 of lalr1.cc  */
#line 5611 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("idiv"))); }
    break;

  case 833:

/* Line 690 of lalr1.cc  */
#line 5612 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("document"))); }
    break;

  case 834:

/* Line 690 of lalr1.cc  */
#line 5613 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ftnot"))); }
    break;

  case 835:

/* Line 690 of lalr1.cc  */
#line 5614 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("not"))); }
    break;

  case 836:

/* Line 690 of lalr1.cc  */
#line 5615 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sensitive"))); }
    break;

  case 837:

/* Line 690 of lalr1.cc  */
#line 5616 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("insensitive"))); }
    break;

  case 838:

/* Line 690 of lalr1.cc  */
#line 5617 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("diacritics"))); }
    break;

  case 839:

/* Line 690 of lalr1.cc  */
#line 5618 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("without"))); }
    break;

  case 840:

/* Line 690 of lalr1.cc  */
#line 5619 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stemming"))); }
    break;

  case 841:

/* Line 690 of lalr1.cc  */
#line 5620 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("thesaurus"))); }
    break;

  case 842:

/* Line 690 of lalr1.cc  */
#line 5621 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stop"))); }
    break;

  case 843:

/* Line 690 of lalr1.cc  */
#line 5622 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("wildcards"))); }
    break;

  case 844:

/* Line 690 of lalr1.cc  */
#line 5623 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("entire"))); }
    break;

  case 845:

/* Line 690 of lalr1.cc  */
#line 5624 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("content"))); }
    break;

  case 846:

/* Line 690 of lalr1.cc  */
#line 5625 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("word"))); }
    break;

  case 847:

/* Line 690 of lalr1.cc  */
#line 5626 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("start"))); }
    break;

  case 848:

/* Line 690 of lalr1.cc  */
#line 5627 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("end"))); }
    break;

  case 849:

/* Line 690 of lalr1.cc  */
#line 5628 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("most"))); }
    break;

  case 850:

/* Line 690 of lalr1.cc  */
#line 5629 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("skip"))); }
    break;

  case 851:

/* Line 690 of lalr1.cc  */
#line 5630 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("copy"))); }
    break;

  case 852:

/* Line 690 of lalr1.cc  */
#line 5631 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("general"))); }
    break;

  case 853:

/* Line 690 of lalr1.cc  */
#line 5632 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("value"))); }
    break;

  case 854:

/* Line 690 of lalr1.cc  */
#line 5633 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("eq"))); }
    break;

  case 855:

/* Line 690 of lalr1.cc  */
#line 5634 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ne"))); }
    break;

  case 856:

/* Line 690 of lalr1.cc  */
#line 5635 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lt"))); }
    break;

  case 857:

/* Line 690 of lalr1.cc  */
#line 5636 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("le"))); }
    break;

  case 858:

/* Line 690 of lalr1.cc  */
#line 5637 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("gt"))); }
    break;

  case 859:

/* Line 690 of lalr1.cc  */
#line 5638 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ge"))); }
    break;

  case 860:

/* Line 690 of lalr1.cc  */
#line 5639 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("at"))); }
    break;

  case 861:

/* Line 690 of lalr1.cc  */
#line 5640 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("context"))); }
    break;

  case 862:

/* Line 690 of lalr1.cc  */
#line 5641 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("variable"))); }
    break;

  case 863:

/* Line 690 of lalr1.cc  */
#line 5642 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("return"))); }
    break;

  case 864:

/* Line 690 of lalr1.cc  */
#line 5643 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("for"))); }
    break;

  case 865:

/* Line 690 of lalr1.cc  */
#line 5644 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("from"))); }
    break;

  case 866:

/* Line 690 of lalr1.cc  */
#line 5645 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("allowing"))); }
    break;

  case 867:

/* Line 690 of lalr1.cc  */
#line 5646 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sliding"))); }
    break;

  case 868:

/* Line 690 of lalr1.cc  */
#line 5647 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("tumbling"))); }
    break;

  case 869:

/* Line 690 of lalr1.cc  */
#line 5648 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("previous"))); }
    break;

  case 870:

/* Line 690 of lalr1.cc  */
#line 5649 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("next"))); }
    break;

  case 871:

/* Line 690 of lalr1.cc  */
#line 5650 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("only"))); }
    break;

  case 872:

/* Line 690 of lalr1.cc  */
#line 5651 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("when"))); }
    break;

  case 873:

/* Line 690 of lalr1.cc  */
#line 5652 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("count"))); }
    break;

  case 874:

/* Line 690 of lalr1.cc  */
#line 5653 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("in"))); }
    break;

  case 875:

/* Line 690 of lalr1.cc  */
#line 5654 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("let"))); }
    break;

  case 876:

/* Line 690 of lalr1.cc  */
#line 5655 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("where"))); }
    break;

  case 877:

/* Line 690 of lalr1.cc  */
#line 5656 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("by"))); }
    break;

  case 878:

/* Line 690 of lalr1.cc  */
#line 5657 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("group"))); }
    break;

  case 879:

/* Line 690 of lalr1.cc  */
#line 5658 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("order"))); }
    break;

  case 880:

/* Line 690 of lalr1.cc  */
#line 5659 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stable"))); }
    break;

  case 881:

/* Line 690 of lalr1.cc  */
#line 5660 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ascending"))); }
    break;

  case 882:

/* Line 690 of lalr1.cc  */
#line 5661 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descending"))); }
    break;

  case 883:

/* Line 690 of lalr1.cc  */
#line 5662 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("greatest"))); }
    break;

  case 884:

/* Line 690 of lalr1.cc  */
#line 5663 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("least"))); }
    break;

  case 885:

/* Line 690 of lalr1.cc  */
#line 5664 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("collation"))); }
    break;

  case 886:

/* Line 690 of lalr1.cc  */
#line 5665 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("some"))); }
    break;

  case 887:

/* Line 690 of lalr1.cc  */
#line 5666 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("every"))); }
    break;

  case 888:

/* Line 690 of lalr1.cc  */
#line 5667 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("satisfies"))); }
    break;

  case 889:

/* Line 690 of lalr1.cc  */
#line 5668 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("case"))); }
    break;

  case 890:

/* Line 690 of lalr1.cc  */
#line 5669 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("as"))); }
    break;

  case 891:

/* Line 690 of lalr1.cc  */
#line 5670 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("then"))); }
    break;

  case 892:

/* Line 690 of lalr1.cc  */
#line 5671 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("else"))); }
    break;

  case 893:

/* Line 690 of lalr1.cc  */
#line 5672 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("or"))); }
    break;

  case 894:

/* Line 690 of lalr1.cc  */
#line 5673 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("and"))); }
    break;

  case 895:

/* Line 690 of lalr1.cc  */
#line 5674 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("instance"))); }
    break;

  case 896:

/* Line 690 of lalr1.cc  */
#line 5675 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("of"))); }
    break;

  case 897:

/* Line 690 of lalr1.cc  */
#line 5676 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("castable"))); }
    break;

  case 898:

/* Line 690 of lalr1.cc  */
#line 5677 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("to"))); }
    break;

  case 899:

/* Line 690 of lalr1.cc  */
#line 5678 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("div"))); }
    break;

  case 900:

/* Line 690 of lalr1.cc  */
#line 5679 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("mod"))); }
    break;

  case 901:

/* Line 690 of lalr1.cc  */
#line 5680 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("union"))); }
    break;

  case 902:

/* Line 690 of lalr1.cc  */
#line 5681 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("intersect"))); }
    break;

  case 903:

/* Line 690 of lalr1.cc  */
#line 5682 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("except"))); }
    break;

  case 904:

/* Line 690 of lalr1.cc  */
#line 5683 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("validate"))); }
    break;

  case 905:

/* Line 690 of lalr1.cc  */
#line 5684 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("type"))); }
    break;

  case 906:

/* Line 690 of lalr1.cc  */
#line 5685 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("cast"))); }
    break;

  case 907:

/* Line 690 of lalr1.cc  */
#line 5686 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("treat"))); }
    break;

  case 908:

/* Line 690 of lalr1.cc  */
#line 5687 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("is"))); }
    break;

  case 909:

/* Line 690 of lalr1.cc  */
#line 5688 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preserve"))); }
    break;

  case 910:

/* Line 690 of lalr1.cc  */
#line 5689 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("strip"))); }
    break;

  case 911:

/* Line 690 of lalr1.cc  */
#line 5690 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("namespace"))); }
    break;

  case 912:

/* Line 690 of lalr1.cc  */
#line 5691 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("external"))); }
    break;

  case 913:

/* Line 690 of lalr1.cc  */
#line 5692 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("encoding"))); }
    break;

  case 914:

/* Line 690 of lalr1.cc  */
#line 5693 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("no-preserve"))); }
    break;

  case 915:

/* Line 690 of lalr1.cc  */
#line 5694 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("inherit"))); }
    break;

  case 916:

/* Line 690 of lalr1.cc  */
#line 5695 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("no-inherit"))); }
    break;

  case 917:

/* Line 690 of lalr1.cc  */
#line 5696 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("declare"))); }
    break;

  case 918:

/* Line 690 of lalr1.cc  */
#line 5697 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("construction"))); }
    break;

  case 919:

/* Line 690 of lalr1.cc  */
#line 5698 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ordering"))); }
    break;

  case 920:

/* Line 690 of lalr1.cc  */
#line 5699 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("default"))); }
    break;

  case 921:

/* Line 690 of lalr1.cc  */
#line 5700 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("copy-namespaces"))); }
    break;

  case 922:

/* Line 690 of lalr1.cc  */
#line 5701 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("option"))); }
    break;

  case 923:

/* Line 690 of lalr1.cc  */
#line 5702 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("version"))); }
    break;

  case 924:

/* Line 690 of lalr1.cc  */
#line 5703 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("import"))); }
    break;

  case 925:

/* Line 690 of lalr1.cc  */
#line 5704 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema"))); }
    break;

  case 926:

/* Line 690 of lalr1.cc  */
#line 5705 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("module"))); }
    break;

  case 927:

/* Line 690 of lalr1.cc  */
#line 5706 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("function"))); }
    break;

  case 928:

/* Line 690 of lalr1.cc  */
#line 5707 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("score"))); }
    break;

  case 929:

/* Line 690 of lalr1.cc  */
#line 5708 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("contains"))); }
    break;

  case 930:

/* Line 690 of lalr1.cc  */
#line 5709 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("weight"))); }
    break;

  case 931:

/* Line 690 of lalr1.cc  */
#line 5710 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("window"))); }
    break;

  case 932:

/* Line 690 of lalr1.cc  */
#line 5711 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("distance"))); }
    break;

  case 933:

/* Line 690 of lalr1.cc  */
#line 5712 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("occurs"))); }
    break;

  case 934:

/* Line 690 of lalr1.cc  */
#line 5713 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("times"))); }
    break;

  case 935:

/* Line 690 of lalr1.cc  */
#line 5714 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("same"))); }
    break;

  case 936:

/* Line 690 of lalr1.cc  */
#line 5715 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("different"))); }
    break;

  case 937:

/* Line 690 of lalr1.cc  */
#line 5716 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lowercase"))); }
    break;

  case 938:

/* Line 690 of lalr1.cc  */
#line 5717 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("uppercase"))); }
    break;

  case 939:

/* Line 690 of lalr1.cc  */
#line 5718 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("relationship"))); }
    break;

  case 940:

/* Line 690 of lalr1.cc  */
#line 5719 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("levels"))); }
    break;

  case 941:

/* Line 690 of lalr1.cc  */
#line 5720 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("language"))); }
    break;

  case 942:

/* Line 690 of lalr1.cc  */
#line 5721 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("any"))); }
    break;

  case 943:

/* Line 690 of lalr1.cc  */
#line 5722 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("all"))); }
    break;

  case 944:

/* Line 690 of lalr1.cc  */
#line 5723 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("exactly"))); }
    break;

  case 945:

/* Line 690 of lalr1.cc  */
#line 5724 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("words"))); }
    break;

  case 946:

/* Line 690 of lalr1.cc  */
#line 5725 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sentences"))); }
    break;

  case 947:

/* Line 690 of lalr1.cc  */
#line 5726 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sentence"))); }
    break;

  case 948:

/* Line 690 of lalr1.cc  */
#line 5727 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("phrase"))); }
    break;

  case 949:

/* Line 690 of lalr1.cc  */
#line 5728 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("paragraph"))); }
    break;

  case 950:

/* Line 690 of lalr1.cc  */
#line 5729 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("paragraphs"))); }
    break;

  case 951:

/* Line 690 of lalr1.cc  */
#line 5730 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("modify"))); }
    break;

  case 952:

/* Line 690 of lalr1.cc  */
#line 5731 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("first"))); }
    break;

  case 953:

/* Line 690 of lalr1.cc  */
#line 5732 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("replace"))); }
    break;

  case 954:

/* Line 690 of lalr1.cc  */
#line 5733 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("insert"))); }
    break;

  case 955:

/* Line 690 of lalr1.cc  */
#line 5734 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("rename"))); }
    break;

  case 956:

/* Line 690 of lalr1.cc  */
#line 5735 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("delete"))); }
    break;

  case 957:

/* Line 690 of lalr1.cc  */
#line 5736 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("before"))); }
    break;

  case 958:

/* Line 690 of lalr1.cc  */
#line 5737 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("after"))); }
    break;

  case 959:

/* Line 690 of lalr1.cc  */
#line 5738 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("revalidation"))); }
    break;

  case 960:

/* Line 690 of lalr1.cc  */
#line 5739 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("with"))); }
    break;

  case 961:

/* Line 690 of lalr1.cc  */
#line 5740 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("nodes"))); }
    break;

  case 962:

/* Line 690 of lalr1.cc  */
#line 5741 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("last"))); }
    break;

  case 963:

/* Line 690 of lalr1.cc  */
#line 5742 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("into"))); }
    break;

  case 964:

/* Line 690 of lalr1.cc  */
#line 5743 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("simple"))); }
    break;

  case 965:

/* Line 690 of lalr1.cc  */
#line 5744 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sequential"))); }
    break;

  case 966:

/* Line 690 of lalr1.cc  */
#line 5745 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("updating"))); }
    break;

  case 967:

/* Line 690 of lalr1.cc  */
#line 5746 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ordered"))); }
    break;

  case 968:

/* Line 690 of lalr1.cc  */
#line 5747 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("unordered"))); }
    break;

  case 969:

/* Line 690 of lalr1.cc  */
#line 5748 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("returning"))); }
    break;

  case 970:

/* Line 690 of lalr1.cc  */
#line 5749 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("exit"))); }
    break;

  case 971:

/* Line 690 of lalr1.cc  */
#line 5750 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("loop"))); }
    break;

  case 972:

/* Line 690 of lalr1.cc  */
#line 5751 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("break"))); }
    break;

  case 973:

/* Line 690 of lalr1.cc  */
#line 5752 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("continue"))); }
    break;

  case 974:

/* Line 690 of lalr1.cc  */
#line 5753 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("try"))); }
    break;

  case 975:

/* Line 690 of lalr1.cc  */
#line 5754 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("catch"))); }
    break;

  case 976:

/* Line 690 of lalr1.cc  */
#line 5755 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("using"))); }
    break;

  case 977:

/* Line 690 of lalr1.cc  */
#line 5756 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("set"))); }
    break;

  case 978:

/* Line 690 of lalr1.cc  */
#line 5757 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("index"))); }
    break;

  case 979:

/* Line 690 of lalr1.cc  */
#line 5758 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("unique"))); }
    break;

  case 980:

/* Line 690 of lalr1.cc  */
#line 5759 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("non"))); }
    break;

  case 981:

/* Line 690 of lalr1.cc  */
#line 5760 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("on"))); }
    break;

  case 982:

/* Line 690 of lalr1.cc  */
#line 5761 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("range"))); }
    break;

  case 983:

/* Line 690 of lalr1.cc  */
#line 5762 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("equality"))); }
    break;

  case 984:

/* Line 690 of lalr1.cc  */
#line 5763 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("manually"))); }
    break;

  case 985:

/* Line 690 of lalr1.cc  */
#line 5764 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("automatically"))); }
    break;

  case 986:

/* Line 690 of lalr1.cc  */
#line 5765 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("maintained"))); }
    break;

  case 987:

/* Line 690 of lalr1.cc  */
#line 5766 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("decimal-format"))); }
    break;

  case 988:

/* Line 690 of lalr1.cc  */
#line 5767 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("decimal-separator"))); }
    break;

  case 989:

/* Line 690 of lalr1.cc  */
#line 5768 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("grouping-separator"))); }
    break;

  case 990:

/* Line 690 of lalr1.cc  */
#line 5769 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("infinity"))); }
    break;

  case 991:

/* Line 690 of lalr1.cc  */
#line 5770 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("minus-sign"))); }
    break;

  case 992:

/* Line 690 of lalr1.cc  */
#line 5771 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("NaN"))); }
    break;

  case 993:

/* Line 690 of lalr1.cc  */
#line 5772 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("percent"))); }
    break;

  case 994:

/* Line 690 of lalr1.cc  */
#line 5773 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("per-mille"))); }
    break;

  case 995:

/* Line 690 of lalr1.cc  */
#line 5774 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("zero-digit"))); }
    break;

  case 996:

/* Line 690 of lalr1.cc  */
#line 5775 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("digit"))); }
    break;

  case 997:

/* Line 690 of lalr1.cc  */
#line 5776 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("pattern-separator"))); }
    break;

  case 998:

/* Line 690 of lalr1.cc  */
#line 5777 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("collection"))); }
    break;

  case 999:

/* Line 690 of lalr1.cc  */
#line 5778 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("const"))); }
    break;

  case 1000:

/* Line 690 of lalr1.cc  */
#line 5779 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("append-only"))); }
    break;

  case 1001:

/* Line 690 of lalr1.cc  */
#line 5780 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("queue"))); }
    break;

  case 1002:

/* Line 690 of lalr1.cc  */
#line 5781 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("mutable"))); }
    break;

  case 1003:

/* Line 690 of lalr1.cc  */
#line 5782 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("read-only"))); }
    break;

  case 1004:

/* Line 690 of lalr1.cc  */
#line 5783 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("integrity"))); }
    break;

  case 1005:

/* Line 690 of lalr1.cc  */
#line 5784 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("constraint"))); }
    break;

  case 1006:

/* Line 690 of lalr1.cc  */
#line 5785 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("check"))); }
    break;

  case 1007:

/* Line 690 of lalr1.cc  */
#line 5786 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("key"))); }
    break;

  case 1008:

/* Line 690 of lalr1.cc  */
#line 5787 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("foreach"))); }
    break;

  case 1009:

/* Line 690 of lalr1.cc  */
#line 5788 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("foreign"))); }
    break;

  case 1010:

/* Line 690 of lalr1.cc  */
#line 5789 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("keys"))); }
    break;

  case 1011:

/* Line 690 of lalr1.cc  */
#line 5790 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ancestor"))); }
    break;

  case 1012:

/* Line 690 of lalr1.cc  */
#line 5791 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("child"))); }
    break;

  case 1013:

/* Line 690 of lalr1.cc  */
#line 5792 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descendant"))); }
    break;

  case 1014:

/* Line 690 of lalr1.cc  */
#line 5793 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("parent"))); }
    break;

  case 1015:

/* Line 690 of lalr1.cc  */
#line 5794 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preceding"))); }
    break;

  case 1016:

/* Line 690 of lalr1.cc  */
#line 5795 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("self"))); }
    break;

  case 1017:

/* Line 690 of lalr1.cc  */
#line 5796 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("following"))); }
    break;

  case 1018:

/* Line 690 of lalr1.cc  */
#line 5797 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ancestor-or-self"))); }
    break;

  case 1019:

/* Line 690 of lalr1.cc  */
#line 5798 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descendant-or-self"))); }
    break;

  case 1020:

/* Line 690 of lalr1.cc  */
#line 5799 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("following-sibling"))); }
    break;

  case 1021:

/* Line 690 of lalr1.cc  */
#line 5800 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preceding-sibling"))); }
    break;

  case 1022:

/* Line 690 of lalr1.cc  */
#line 5801 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("position"))); }
    break;

  case 1023:

/* Line 690 of lalr1.cc  */
#line 5802 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("json"))); }
    break;

  case 1024:

/* Line 690 of lalr1.cc  */
#line 5803 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("append"))); }
    break;

  case 1025:

/* Line 690 of lalr1.cc  */
#line 5804 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("json-item"))); }
    break;

  case 1026:

/* Line 690 of lalr1.cc  */
#line 5805 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("array"))); }
    break;

  case 1027:

/* Line 690 of lalr1.cc  */
#line 5806 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("object"))); }
    break;

  case 1028:

/* Line 690 of lalr1.cc  */
#line 5807 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("structured-item"))); }
    break;

  case 1029:

/* Line 690 of lalr1.cc  */
#line 5810 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), true); }
    break;



/* Line 690 of lalr1.cc  */
#line 12093 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
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
  const short int xquery_parser::yypact_ninf_ = -1541;
  const short int
  xquery_parser::yypact_[] =
  {
      4292, -1541, -1541, -1541, -1541,  5846,  5846,  5846,  5846, -1541,
   -1541,    17,   153, -1541,   130,   411, -1541, -1541, -1541,   826,
   -1541, -1541, -1541,   290,   423,   844,  2247,   443,   481,   657,
   -1541,   -43, -1541,   511, -1541, -1541, -1541, -1541, -1541,   846,
   -1541,   630,   638, -1541, -1541, -1541, -1541,   686, -1541,   848,
   -1541,   650,   672, -1541,   457, -1541, -1541, -1541, -1541, -1541,
   -1541, -1541, -1541, -1541, -1541, -1541, -1541, -1541, -1541,   741,
     851, -1541, -1541, -1541, -1541,   752, 12666, -1541, -1541, -1541,
     858, -1541, -1541, -1541,   870, -1541,   873,   890, -1541, -1541,
   16537, -1541, -1541, -1541, -1541, -1541, -1541, -1541, -1541,   901,
   -1541, -1541,   906,   911, -1541, -1541, -1541, -1541, -1541, -1541,
   -1541,  4916,  8326,  8636, 16537, -1541, -1541,   886, -1541, -1541,
   -1541, -1541,   888, -1541, -1541,   922, 16537, -1541, 13577,   933,
     934, -1541, -1541, -1541,   935, -1541, 12046, -1541, -1541, -1541,
   -1541, -1541, -1541,   905, -1541, -1541, -1541, -1541, -1541, -1541,
   -1541, -1541,   144,   847, -1541, -1541, -1541, -1541, -1541, -1541,
   -1541, -1541,   212,   904,   472, -1541,   -65,   151, -1541, -1541,
   -1541, -1541, -1541, -1541,   945, -1541,   825,   827,   828, -1541,
   -1541,   914,   913, -1541, -1541, -1541, -1541, -1541, -1541, -1541,
   -1541, -1541, -1541, -1541, -1541, -1541, -1541, -1541, -1541, -1541,
   -1541, -1541, -1541, -1541, -1541, -1541, -1541, -1541, -1541, -1541,
   -1541, -1541, -1541, -1541, -1541, -1541, -1541, -1541, -1541, -1541,
   -1541, -1541, -1541, -1541, -1541, -1541, -1541, -1541, -1541, -1541,
   -1541, -1541, -1541, -1541, -1541, -1541, -1541, -1541, -1541, -1541,
   -1541, -1541, -1541, -1541, -1541, -1541,  8946,  9256, -1541,   758,
   -1541, -1541, -1541, -1541, -1541,  4604,  6156,  1074, -1541,  6466,
   -1541, -1541,   146,    83, -1541, -1541, -1541, -1541, -1541, -1541,
   -1541, -1541, -1541, -1541, -1541, -1541, -1541, -1541,    98, -1541,
   -1541, -1541, -1541, -1541, -1541,   346, -1541, -1541, -1541, -1541,
   -1541, -1541, -1541, -1541,  5846, -1541, -1541, -1541, -1541,    42,
   -1541, -1541, -1541, -1541, -1541, -1541, -1541, -1541,   164, -1541,
     891, -1541, -1541, -1541,   684, -1541, -1541, -1541, -1541, -1541,
   -1541, -1541, -1541,   909,   987, -1541,  1110,   833,   983,   318,
     517,   703,   347, -1541,  1034,   895,   984,   988, 10496, -1541,
     894, -1541, -1541,    12, -1541, -1541, 12356, -1541,   800, -1541,
     941, 12666, -1541,   941, 12666, -1541, -1541, -1541,    27, -1541,
   -1541, -1541, -1541, -1541, -1541, -1541, -1541, -1541, -1541, -1541,
   -1541, -1541, -1541, -1541, -1541, -1541, -1541, -1541, -1541, -1541,
   -1541, -1541, -1541, -1541, -1541, -1541,   940, -1541, -1541, -1541,
   -1541, -1541, -1541, -1541, -1541, -1541, -1541, -1541, -1541, -1541,
   -1541, -1541, -1541, -1541, -1541, -1541, -1541, -1541, -1541, -1541,
   -1541, -1541, -1541, -1541,   295, -1541, -1541, -1541, -1541, -1541,
     925, -1541,  5846,   927,   929,   930,  5846,   494,   494,  1060,
     396,   691,   733, 17133, 16537,   648,  1068, 16537,   964,   999,
     524, 16537,   803,   874, 16537, 16537,   817,   722,   115, -1541,
   -1541, -1541, 16537,  5846,   938,  5846,    53, 10806, 13873, 16537,
   -1541,   842,   843, 16537,  1010,   356,   976, 10806,  1132,    63,
      62, 16537,  1015,   993,  1029, -1541,   951, 10806, 14169, 16537,
   16537, 16537,  5846,   952, 10806, 10806, 16537,  5846,   986,   989,
   -1541, -1541, -1541, 10806, 14465,   985, -1541,   991, -1541, -1541,
   -1541, -1541,   992, -1541,   994, -1541, -1541, -1541, -1541, -1541,
     995, -1541, -1541, -1541, -1541, -1541, -1541, -1541, -1541, -1541,
   -1541, -1541, -1541, -1541, -1541, -1541, -1541, -1541, -1541, -1541,
   -1541, -1541, -1541, -1541, -1541, -1541, -1541, -1541, -1541, 16537,
   -1541, -1541, -1541, -1541, -1541, -1541, -1541, -1541, -1541, -1541,
   -1541, -1541, -1541,   998, 16537, -1541, -1541, -1541,   960,  5226,
    1028,   285,   996,  1001,  1004, 16537,  5846, -1541,  1002,   244,
   -1541,   721, -1541,   118,  1120, 10806, 10806, -1541,   188, -1541,
   -1541,  1145, -1541, -1541, -1541, -1541, 10806,   950, -1541,  1135,
   10806, 10806, 16837, 10806, 10806, 10806, 10806, 16837, 10806,   936,
     947, 16537,   980,   981, 10806, 10806,  4916,   921, -1541,    48,
   -1541,    44, 10806,  6156, -1541, -1541, -1541, -1541, -1541,   130,
     657,    99,   107,  1176,  6776,  3041,  7086,  3362,   870, -1541,
   -1541,   353,   870, -1541, 10806,  3982, -1541,  1061,   593,   -43,
    1014,  1013,  1016,  5846, 10806, -1541, -1541, -1541, -1541, -1541,
   -1541, -1541, -1541, 11116, 11116, 11116, -1541, 11116, 11116, -1541,
   11116, -1541, 11116, -1541, -1541, -1541, -1541, -1541, -1541, -1541,
   11116, 11116,  1113, 11116, 11116, 11116, 11116, 11116, 11116, 11116,
   11116, 11116, 11116, 11116, 11116,   956,  1093,  1094,  1100, -1541,
   -1541, -1541, 11736,  9566, -1541, -1541, 12046, 12046, 10806,   941,
   -1541, -1541,   941, -1541,  9876,  7396,   941,  1011,  1047,  7706,
   -1541, -1541, -1541, -1541,    25, -1541,    30, -1541, -1541, -1541,
   -1541, -1541, -1541,  1091,  1092,   443,  1171, -1541, -1541, 17133,
    1018,    56, 16537,  1041,  1042,  1018,  1060,  1077,  1073, -1541,
   -1541, -1541,   126,   962,  1114,   916, 16537,  1067, 10806,  1095,
   16537, 16537, -1541,  1079,  1032, -1541,  1033,   991,   638, -1541,
    1026,  1031,   154, -1541,   315,   334,  1112, -1541,    66, -1541,
   -1541,  1112, 16537,    29, 16537,  1126,   359, -1541,  5846, -1541,
     128, -1541, 16537,  1125,  1178, 16537,  1060,  1127,   438, 16537,
   10806,   -43, -1541,   339,  1038, -1541,  1039,  1040,  1043,    28,
   -1541,   460,  1044, -1541,   131,   184,  1078, -1541,  1049,  5846,
    5846,   354, -1541,   365,   459,   588, 10806,    64, -1541, -1541,
   10806, 10806, -1541, 10806, 10806, 10806, -1541, 10806, -1541, 10806,
   -1541, 16537,  1120, -1541,   238,   381,   399, -1541, -1541, -1541,
     400, -1541,     7, -1541, -1541,  1080,  1081,  1082,  1084,  1085,
      27,   295,   -15,     2,   -27,   -14,  1147,    45,  1003,  1019,
    1017,    13, -1541,  1103, -1541, -1541,  1057,   192,  5226,   417,
   12976,   921, -1541, -1541, -1541,  1022, -1541,   146,   788,  1216,
     168, -1541, -1541,   108, -1541, -1541, -1541,   109, -1541,    32,
   -1541, -1541, -1541, -1541, -1541,  3672, -1541, -1541, -1541, 16537,
    1086, 10806, 11426, -1541, -1541, -1541,   987, -1541, -1541, -1541,
   -1541, -1541, 11116, -1541, -1541, -1541,   179, -1541,   517,   517,
     320,   703,   703,   703,   703,   347,   347, -1541, -1541, 15649,
   15649, 16537, 16537, -1541, -1541,   439, -1541, -1541,   312, -1541,
   -1541, -1541, -1541, -1541,   466, -1541, -1541, -1541,   469,   494,
   -1541, -1541,   779,   783,   352, -1541,   443, -1541, -1541, -1541,
   -1541, -1541, -1541, -1541, -1541, -1541, -1541,  1018, -1541,  1117,
   15945,  1115, 10806, -1541, -1541, -1541,  1162,  1060,  1060,  1018,
   -1541,   887,  1060,   731, 16537,   486,   680,  1229, -1541, -1541,
     974,   587, -1541, -1541, -1541, -1541, -1541, -1541, -1541, -1541,
   -1541, -1541, -1541,   126,    43,  1036,   663, 10806, -1541, 16537,
    1166,   966,  1060, -1541, -1541, -1541, -1541,  1121, 16537, -1541,
   16537, -1541, 16241,  1139, 15649,  1150, 10806,   -44,  1123,    50,
     537,  1020, -1541, -1541,   656,    29,  1162, 15649,  1157,  1183,
    1096,  1088,  1149,  1060,  1129,  1154,  1194,  1060, 10806,   -19,
   -1541, -1541, -1541,  1138, -1541, -1541, -1541, -1541,  1174, 10806,
   10806,  1146, -1541,  1195,  1196,  5846, -1541,  1111,  1118,  1151,
   16537, -1541, 16537, -1541, 10806,  1156,  1116, 10806, -1541,  1179,
     224,   256,   305,  1269, -1541,   283, -1541,   241,  1155, -1541,
   -1541,  1280, -1541,   734, 10806, 10806, 10806,   738, 10806, 10806,
   10806, 10806, 10806, 10806, 10806, 10806, 10806, 16837,  1193, 10806,
   10806, -1541,  8016,   100,  1075, -1541,   445, -1541, 10806,   122,
     390,    32,  7086,  3362,  7086,  1239, -1541, -1541, 10806,   835,
    1214, -1541, 16537,  1217,  1215, -1541, -1541, 10806,   179,   546,
     464, -1541,  1050,   219,  1070,  1065, -1541, -1541,   874, -1541,
    1059,   635,  1172,  1175, 15945,  1180,  1181,  1184,  1185,  1186,
   -1541,   603, -1541, -1541, -1541, -1541, -1541, -1541, -1541, -1541,
   -1541, -1541, -1541, -1541, -1541,  1191, -1541, -1541, -1541, -1541,
   10186, -1541, -1541, -1541, -1541, -1541, -1541, -1541, -1541, -1541,
     801, -1541,  1310,   802, -1541, -1541, -1541, -1541, -1541, -1541,
   -1541, -1541, -1541,  1058, -1541, -1541,  1315, -1541, -1541, -1541,
   -1541, -1541,   619,  1316, -1541,   757, -1541, -1541, -1541,   985,
     423,   511,   992,   630,   994,   995, -1541,  1181,  1184,  1185,
   -1541,   603,   603, 11736,  1062,  1053, -1541,  1162,    43,  1133,
    1158,  5846,  1160,  1169,  1218,  1177,  1188, 16537, -1541,   545,
   -1541, 16537, -1541, 10806,  1219, 10806,  1234, 10806,   -35,  1223,
   10806,  1225, -1541,  1246,  1257, 10806, 16537,   910,  1299, -1541,
   -1541, -1541, -1541, -1541, -1541, 15649, -1541,  5846,  1060,  1270,
   -1541, -1541, -1541,  1060,  1270, -1541, 10806,  1236,  5846, 16537,
   -1541, -1541, 10806, 10806,    72, -1541,   297,   820, -1541, 14761,
     821, -1541,   845, -1541,  1197, -1541, -1541,  5846,  1198,  1199,
   -1541, 10806, -1541, -1541, 10806,  1189,  1195,  1281, -1541,  1250,
   -1541,   666, -1541, -1541,  1377, -1541, -1541,  5846, 16537, -1541,
     793, -1541, -1541, -1541,  5846,  1200,  1163,  1164, -1541, -1541,
   -1541,  1165,  1167, -1541, -1541, -1541,  1291, -1541, -1541, -1541,
   -1541,  1168,    58, 16537,  1205, -1541,  1238,  1242,  1245,  1249,
   -1541,   891,   907, 12976,  1075, -1541,  5536, 12976, -1541, -1541,
    1216,   484, -1541, -1541, -1541,  1214, -1541,  1060, -1541,   898,
   -1541,   715,  1297, -1541, 10806,   655,  1060, -1541, 11426,   450,
    1220, -1541,   179,  1159, -1541, -1541,   473, -1541,   566,   229,
    1161,   179,   566, 11116, -1541,    94, -1541, -1541, -1541, -1541,
   -1541, -1541,   179,  1262,  1130,   962,   229, -1541, -1541,  1128,
    1334, -1541, -1541, -1541, 13272,  1230,  1231,  1232,  1233,  1235,
    1237,  1241, -1541, -1541, -1541, -1541, -1541, -1541, -1541, -1541,
   -1541, -1541, -1541, -1541, -1541,  1386,   329,  1391,   329,  1152,
    1317, -1541, -1541,  1256, 16537,  1173, -1541, -1541, 11736, -1541,
    1248, -1541, -1541, -1541, -1541, -1541, -1541, 10806,  1286, -1541,
   -1541, 10806, -1541,   617, -1541, 10806,  1287, 10806, -1541, 10806,
   16537, 16537, -1541,   760, -1541, 10806, -1541,  1302,  1309,  1340,
    1060,  1270, -1541, 10806,  1254, -1541, -1541, -1541,  1253, -1541,
     307, 10806,  5846,  1255,   323, -1541, 16537,   573, -1541, 15057,
     264, -1541, 15353,  1259, -1541, -1541,  1264, -1541, -1541, -1541,
   -1541, 10806,   859,  1269, 16537,   915, -1541,  1265,  1269, 16537,
   -1541,  1266, -1541, 10806, 10806, 10806, 10806,  1136, 10806, 10806,
   -1541, 10806, 10806, 10806, 10806,  8016,   527, -1541, -1541, -1541,
   -1541, -1541,  1297, -1541, -1541, -1541, 10806,  1300, -1541, -1541,
   -1541, -1541, -1541,  1267, 11116, -1541, -1541, -1541, -1541, -1541,
     316, 11116, 11116,   482, -1541,  1070, -1541,   394, -1541,  1065,
     179,  1301, -1541, -1541,  1187, -1541, -1541, -1541, -1541,  1358,
    1271, -1541,   485, -1541, -1541, -1541, -1541, -1541, -1541, -1541,
   -1541,   471,   471, -1541,   329, -1541, -1541,   501, -1541,  1426,
     229,  1360,  1273, 11736,    35,  1182,  1293, -1541, -1541, 10806,
   -1541, 10806,  1313, -1541, 10806, -1541, -1541, -1541,  1410, -1541,
   -1541,  8016, 10806,  1060, -1541, -1541, -1541, 10806, 10806, -1541,
   -1541, -1541,  8016,  8016,  1370,  5846, 15649, 16537,   578, 16537,
   10806, 16537,   637,  8016, -1541,   341,   236,  1269, 16537, -1541,
    1274,  1269, -1541, -1541, -1541, -1541, -1541, 10806, -1541, -1541,
   -1541,   308,   313,   324, 10806, -1541, -1541,  1217, 10806, -1541,
     703, 11116, 11116,   320,   586, -1541, -1541, -1541, -1541, -1541,
   -1541, 10806, -1541, 15649, -1541, 15649,  1371, -1541, -1541, -1541,
    1438, -1541, -1541, -1541,  1207,  1362, -1541, -1541,  1365, -1541,
      85, 16537,  1355,  1251, 16537, 11736, -1541, -1541, 10806, -1541,
    1356, -1541, -1541,  1270, -1541, -1541, 15649, -1541, -1541, -1541,
    1382, 10806,  1292, -1541,  1384,  8016, -1541, 16537,   535,   645,
   -1541,  1283,  1269, -1541,  1284, -1541,  1285,  1195,  1196,   455,
   -1541,  1217,   320,   320, 11116,   456, -1541, -1541, 15649, -1541,
   -1541,  1360, 11736, -1541,  1297,  1190, 16537,  1363,  1260,  1365,
   -1541, 16537,   639, 15649,  5846, 15649,  1298, -1541, -1541,  1392,
     612, -1541, -1541, -1541, -1541,  1304,   658, -1541, -1541, -1541,
    1294, -1541,  8016,   864, -1541, -1541,   320, -1541, -1541, -1541,
   -1541, -1541, 10806,  1192, 16537,  1374, -1541,  5846,   641, -1541,
   -1541,   704, 10806, -1541, -1541, -1541, -1541, -1541, -1541, -1541,
    1379, -1541,  1203,  1201, 16537, -1541, -1541, 10806,  8016, 16537,
    1204, 10806,  1208,  1303, 11736, -1541, 11736,  8016, -1541,  1305,
    1212, 16537,  1275,  1388, 16537,  1209, 11736, -1541
  };

  /* YYDEFACT[S] -- default reduction number in state S.  Performed when
     YYTABLE doesn't specify something else to do.  Zero means the
     default is an error.  */
  const unsigned short int
  xquery_parser::yydefact_[] =
  {
       165,   466,   467,   806,   468,   168,   168,   168,     0,   824,
    1029,   120,   122,   634,   917,   926,   866,   829,   827,   808,
     918,   921,   873,   833,   809,   811,     0,   927,   813,   924,
     895,   875,   849,   810,   870,   871,   922,   919,   869,   815,
     925,   816,   817,   965,   977,   964,   867,   886,   880,   818,
     868,   820,   819,   966,   904,   905,   872,   846,   987,   988,
     989,   990,   991,   992,   993,   994,   995,   996,   997,  1011,
    1018,   894,   890,   881,   860,   807,     0,   889,   897,   906,
    1012,   885,   493,   861,   862,   920,  1013,  1019,   882,   899,
       0,   499,   455,   495,   892,   826,   883,   884,   913,   887,
     903,   912,  1017,  1020,   832,   874,   915,   494,   902,   908,
     812,     0,     0,     0,     0,   401,   900,   911,   916,   914,
     893,   879,   967,   877,   878,  1014,     0,   400,     0,  1015,
    1021,   909,   863,   888,  1016,   433,     0,   465,   910,   891,
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
     216,   183,   217,   220,   352,   354,   356,   366,   368,   372,
     374,   377,   382,   385,   388,   390,   392,   394,     0,   398,
     405,   404,   406,     0,   424,   407,   429,   432,   434,   437,
     439,     0,   444,   441,     0,   452,   462,   464,   438,   469,
     477,   491,   478,   479,   480,   483,   484,   481,   485,   508,
     509,   482,   512,   514,   515,   516,   513,   561,   562,   563,
     564,   565,   566,   567,   461,   606,     0,   597,   605,   604,
     603,   602,   599,   601,   598,   600,   492,    43,   222,   223,
     225,   224,   226,   218,   488,   489,   490,   487,   228,   231,
     227,   229,   230,   463,   805,   823,   917,   926,   924,   825,
       0,   166,   167,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   126,
     128,   129,     0,     0,     0,     0,     0,     0,     0,     0,
     256,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   274,   275,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     457,   460,   447,     0,     0,   808,   833,   811,   864,   927,
     813,   875,   815,   886,   818,   820,   819,   904,  1011,  1018,
     807,  1012,   862,  1013,  1019,   887,  1017,  1020,   911,   967,
    1014,  1015,  1021,  1016,   968,   956,   954,   955,   953,   851,
     972,   973,   970,   822,   974,  1024,   453,   805,   445,     0,
     192,   446,   449,   808,   809,   811,   810,   815,   816,   817,
     818,   807,   814,   496,     0,   451,   450,   187,     0,     0,
     211,     0,   813,   820,   819,     0,   168,   782,   974,     0,
     219,     0,   497,     0,   528,     0,     0,   456,     0,   427,
     428,     0,   459,   458,   448,   431,     0,     0,   557,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   784,     0,
     786,     0,     0,   165,     3,     4,     1,    10,    12,     0,
       0,     0,     0,     6,   165,     0,   165,     0,     0,   119,
     172,     0,     0,   190,     0,     0,   199,     0,     0,     0,
       0,     0,     0,     0,     0,   204,   232,   251,   247,   253,
     248,   250,   249,     0,     0,     0,   417,     0,     0,   415,
       0,   361,     0,   416,   409,   414,   413,   412,   411,   410,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   403,
     402,   399,     0,     0,   425,   430,     0,     0,     0,   440,
     474,   443,   442,   454,     0,     0,   470,     0,     0,     0,
     569,   571,   575,   577,     0,   124,     0,   804,    47,    44,
      45,    48,    49,     0,     0,     0,     0,    50,    51,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   641,
     642,   643,     0,   103,   142,     0,     0,   112,     0,     0,
       0,     0,   127,     0,     0,   614,     0,     0,     0,   609,
       0,     0,     0,   624,     0,     0,   255,   257,     0,   234,
     235,   254,     0,     0,     0,   134,     0,   138,   168,   511,
       0,    60,     0,    69,     0,     0,     0,    61,     0,     0,
       0,     0,   612,     0,     0,   615,     0,     0,     0,     0,
     323,     0,     0,   613,     0,     0,     0,   632,     0,     0,
       0,     0,   618,     0,     0,   194,     0,     0,   188,   186,
       0,     0,   788,     0,     0,     0,   496,     0,   783,     0,
     498,   529,   528,   525,     0,     0,     0,   559,   558,   426,
       0,   556,     0,   654,   655,     0,     0,     0,     0,     0,
     795,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   660,     0,   202,   203,     0,     0,     0,     0,
       0,   207,   208,   785,   787,     0,     5,    24,     0,    25,
       0,     7,    29,     0,    15,     8,    30,     0,    19,   917,
      77,    16,    78,    20,   193,     0,   191,   212,   213,     0,
       0,     0,     0,   205,   233,   292,   353,   355,   359,   365,
     364,   363,     0,   360,   357,   358,     0,   369,   376,   375,
     373,   379,   380,   381,   378,   383,   384,   387,   386,     0,
       0,     0,     0,   408,   422,     0,   435,   436,     0,   475,
     473,   504,   471,   506,     0,   607,   510,   502,     0,     0,
     121,   123,     0,     0,     0,   102,     0,    92,    94,    95,
      96,    97,    99,   100,   101,    93,    98,    88,    89,     0,
       0,   108,     0,   104,   106,   107,   114,     0,     0,    87,
      46,     0,     0,     0,     0,     0,     0,     0,   732,   737,
       0,     0,   733,   767,   720,   722,   723,   724,   726,   728,
     727,   725,   729,     0,     0,     0,     0,     0,   111,     0,
     144,     0,     0,   574,   568,   610,   611,     0,     0,   628,
       0,   625,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   236,   237,     0,   242,   140,     0,     0,   135,
       0,     0,     0,     0,     0,     0,    62,     0,     0,     0,
     273,   279,   276,     0,   617,   616,   623,   631,     0,     0,
       0,     0,   573,     0,     0,     0,   418,     0,     0,     0,
       0,   621,     0,   619,     0,   195,     0,     0,   789,     0,
       0,     0,     0,   528,   526,     0,   517,     0,     0,   500,
     501,     0,    13,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   200,     0,     0,     0,   668,     0,   209,     0,     0,
       0,     0,   165,     0,   165,     0,   173,   243,     0,   307,
     303,   305,     0,   300,   293,   294,   362,     0,     0,     0,
       0,   698,   370,   671,   675,   677,   679,   681,   684,   691,
     692,   700,   927,   812,     0,   821,  1027,  1026,  1025,  1028,
     389,   580,   586,   587,   590,   635,   636,   591,   592,   798,
     799,   800,   595,   391,   393,   396,   596,   395,   423,   476,
       0,   472,   503,   125,    56,    57,    54,    55,   131,   130,
       0,    90,     0,     0,   109,   110,   115,    74,    75,    52,
      53,    73,   738,     0,   741,   768,     0,   731,   730,   735,
     734,   766,     0,     0,   743,     0,   739,   742,   721,     0,
       0,     0,     0,     0,     0,     0,   608,     0,     0,     0,
     143,   146,   148,     0,     0,     0,   113,   116,     0,     0,
       0,   168,     0,     0,   632,     0,     0,     0,   259,     0,
     579,     0,   260,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   238,     0,     0,     0,     0,   286,     0,   283,
     288,   241,   141,   136,   139,     0,   189,     0,     0,    71,
      65,    68,    67,     0,    63,   277,     0,     0,   168,     0,
     321,   325,     0,     0,     0,   328,     0,     0,   334,     0,
       0,   341,     0,   345,     0,   420,   419,   168,     0,     0,
     196,     0,   198,   322,     0,     0,     0,     0,   529,     0,
     519,     0,   552,   549,     0,   553,   554,     0,     0,   548,
       0,   523,   551,   550,     0,     0,     0,     0,   647,   648,
     644,     0,     0,   652,   653,   649,   791,   792,   658,   796,
     656,     0,     0,     0,     0,   662,   813,   820,   819,   974,
     201,     0,     0,     0,   663,   664,     0,     0,   210,   794,
      26,     0,    17,    21,    22,   304,   316,     0,   317,     0,
     308,   309,   310,   311,     0,   496,     0,   301,     0,     0,
       0,   682,   695,     0,   367,   371,     0,   714,     0,     0,
       0,     0,     0,     0,   670,   672,   673,   709,   710,   711,
     713,   712,     0,     0,   686,   685,     0,   689,   693,   707,
     705,   704,   697,   701,     0,     0,     0,     0,     0,     0,
       0,     0,   583,   585,   584,   581,   397,   505,   507,   133,
     132,    91,   105,   755,   736,     0,   760,     0,   760,   749,
     744,   147,   149,     0,     0,     0,   117,   145,     0,    27,
       0,   629,   630,   633,   626,   627,   258,     0,     0,   272,
     264,     0,   268,     0,   262,     0,     0,     0,   281,     0,
       0,     0,   240,   284,   287,     0,   137,     0,     0,    70,
       0,    64,   278,     0,     0,   324,   326,   331,     0,   329,
       0,     0,     0,     0,     0,   335,     0,     0,   349,     0,
       0,   342,     0,     0,   346,   421,     0,   622,   620,   197,
     790,     0,     0,   528,     0,     0,   560,     0,   528,     0,
     524,     0,    14,     0,     0,     0,     0,     0,     0,     0,
     661,     0,     0,     0,     0,     0,     0,   665,   669,   320,
     318,   319,   312,   313,   314,   306,     0,     0,   302,   295,
     699,   690,   696,     0,     0,   769,   770,   780,   779,   778,
       0,     0,     0,     0,   771,   676,   777,     0,   674,   678,
       0,     0,   683,   687,     0,   708,   703,   706,   702,     0,
       0,   593,     0,   588,   640,   582,   802,   803,   801,   589,
     756,     0,     0,   754,   761,   762,   758,     0,   753,     0,
     751,     0,     0,     0,     0,     0,     0,   570,   261,     0,
     270,     0,     0,   266,     0,   269,   282,   290,   291,   285,
     239,     0,     0,     0,    66,   280,   576,     0,     0,   332,
     336,   330,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   572,     0,     0,   528,     0,   555,
       0,   528,   578,   645,   646,   650,   651,     0,   657,   797,
     659,     0,     0,     0,     0,   666,   315,   296,     0,   694,
     781,     0,     0,   773,     0,   719,   718,   717,   716,   715,
     680,     0,   772,     0,   637,     0,     0,   765,   764,   763,
       0,   757,   750,   748,     0,   745,   746,   740,   150,   152,
     154,     0,     0,     0,     0,     0,   265,   263,     0,   271,
       0,   206,   351,    72,   327,   333,     0,   347,   343,   350,
       0,     0,     0,   337,     0,     0,   339,     0,   538,   532,
     527,     0,   528,   518,     0,   793,     0,     0,     0,     0,
     299,   297,   775,   774,     0,     0,   638,   594,     0,   759,
     752,     0,     0,   156,   155,     0,     0,     0,     0,   151,
     267,     0,     0,     0,     0,     0,     0,   546,   540,     0,
     539,   541,   547,   544,   534,     0,   533,   535,   545,   520,
       0,   521,     0,     0,   667,   298,   776,   688,   639,   747,
     153,   157,     0,     0,     0,     0,   289,     0,     0,   340,
     338,     0,     0,   531,   542,   543,   530,   536,   537,   522,
       0,   158,     0,     0,     0,   348,   344,     0,     0,     0,
       0,     0,     0,     0,     0,   160,     0,     0,   159,     0,
       0,     0,     0,     0,     0,     0,     0,   161
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yypgoto_[] =
  {
     -1541, -1541,  -225,  -201, -1541,  1244,  1252, -1541,  1243,  -557,
   -1541, -1541, -1541, -1541, -1541, -1541, -1541, -1541, -1541, -1541,
   -1003, -1541, -1541, -1541, -1541,  -240,  -609, -1541,   755,  -250,
   -1541, -1541, -1541, -1541, -1541,   325,   538, -1541, -1541,    -5,
    -195,  1089, -1541,  1072, -1541, -1541,  -655, -1541,   475, -1541,
     278, -1541,  -194,  -239, -1541,  -562, -1541,    -4,   120,    67,
    -273,  -178, -1541,  -888, -1541, -1541,   124, -1541, -1541, -1541,
   -1541, -1541, -1541, -1541, -1541, -1541, -1541,   651,   351,  1228,
       0, -1541, -1541, -1541, -1541,   489, -1541, -1541,  -302, -1541,
      23, -1541,  1063,  -951,  -748,  -742, -1541, -1541,   737, -1541,
   -1541,    46,   263, -1541, -1541, -1541,   143, -1540, -1541,   404,
     149, -1541, -1541,   156, -1330, -1541,   990,   246, -1541, -1541,
     245, -1039, -1541, -1541,   243, -1541, -1541, -1278, -1275, -1541,
     239, -1451, -1541, -1541,   885,   889, -1541,  -540,   869, -1541,
   -1541,  -660,   357,  -644,   355,   364, -1541, -1541, -1541,   614,
   -1541, -1541,  1210, -1541, -1541, -1541, -1541, -1541,  -873,  -329,
    -677, -1541,  -109, -1541, -1541, -1541, -1541, -1541, -1541, -1541,
     -20,  -822, -1541,  -550,   665,   280, -1541,  -417, -1541, -1541,
   -1541, -1541, -1541, -1541, -1541,   838, -1541, -1541, -1541, -1541,
   -1037, -1541,   228, -1541,   719,  -819, -1541, -1541, -1541, -1541,
   -1541,  -234,  -227, -1249,  -908, -1541, -1541, -1541, -1541, -1541,
   -1541, -1541, -1541, -1541, -1541, -1541,  -769,  -889,  -180,  -811,
   -1541, -1541, -1541,  -696, -1541, -1541, -1541, -1541, -1541, -1541,
   -1541, -1541, -1541,  1101,  1102,  -224,   536,   367, -1541, -1541,
   -1541, -1541, -1541, -1541, -1541, -1541, -1541, -1541, -1541,   208,
   -1541, -1541,   198, -1541,   200, -1081, -1541, -1541, -1541,   165,
     155,   -11,   426, -1541, -1541, -1541, -1541, -1541, -1541, -1541,
   -1541, -1541, -1541, -1541, -1541, -1541,   166, -1541, -1541, -1541,
      -7,   424,   570, -1541, -1541, -1541, -1541, -1541,   360, -1541,
   -1541, -1520, -1541, -1541, -1541,  -548, -1541,   129, -1541,   -30,
   -1541, -1541, -1541, -1541, -1333, -1541,   176, -1541, -1541, -1541,
   -1541, -1541,   997, -1541, -1541, -1541, -1541, -1541,  -935, -1541,
   -1541, -1541,  -392,   422,   261, -1541
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yydefgoto_[] =
  {
        -1,   257,   635,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
    1279,   786,   275,   276,   277,   278,   279,   280,   967,   968,
     969,   281,   282,   283,   973,   974,   975,   284,   447,   285,
     286,   714,   287,   449,   450,   451,   466,   776,   777,   288,
    1230,   289,  1708,  1709,   290,   291,   292,   558,   293,   294,
     295,   296,   297,   779,   298,   299,   540,   300,   301,   302,
     303,   304,   305,   645,   306,   307,   871,   872,   308,   309,
     570,   311,   646,   464,  1034,  1035,   312,   647,   313,   649,
     571,   315,   766,   767,  1267,   473,   316,   474,   475,   773,
    1268,  1269,  1270,   650,   651,  1134,  1135,  1387,   652,  1130,
    1131,  1380,  1381,  1382,  1383,   317,   799,   800,   318,  1294,
    1295,  1500,   319,  1297,  1298,   320,   321,  1300,  1301,  1302,
    1303,  1507,   322,   323,   324,   325,   912,   326,   327,  1394,
     328,   329,   330,   331,   332,   333,   334,   335,   336,  1174,
     337,   338,   339,   340,   670,   671,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   706,   700,   359,   360,   361,   362,
     363,   364,   365,   366,   367,   944,   368,   369,   370,   371,
     372,   373,  1330,   832,   833,   834,  1740,  1785,  1786,  1779,
    1780,  1787,  1781,  1331,  1332,   374,   375,  1333,   376,   377,
     378,   379,   380,   381,   382,   383,  1029,  1508,  1435,  1161,
    1592,  1162,  1175,   384,   385,   386,   387,   388,   389,   390,
     391,   392,   393,   394,   395,   806,  1243,   396,  1164,  1165,
    1166,  1167,   397,   398,   399,   400,   401,   402,   861,   862,
     403,  1364,  1365,  1675,  1116,  1142,  1404,  1405,  1143,  1144,
    1145,  1146,  1147,  1414,  1582,  1583,  1148,  1417,  1149,  1563,
    1150,  1151,  1422,  1423,  1588,  1586,  1406,  1407,  1408,  1409,
    1688,   743,   994,   995,   996,   997,   998,   999,  1216,  1612,
    1705,  1217,  1610,  1703,  1000,  1448,  1607,  1603,  1604,  1605,
    1001,  1002,  1410,  1418,  1573,  1411,  1569,  1395,   404,   405,
     406,   407,   561,   408,   409,   410,   411,   412,  1168,  1169,
    1170,  1171,  1280,   413,   414,   415
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const short int xquery_parser::yytable_ninf_ = -865;
  const short int
  xquery_parser::yytable_[] =
  {
       310,   420,   423,   424,   607,   310,   310,   310,   310,   448,
     715,   715,   648,  1085,   694,   933,   920,   890,   892,  1049,
    1027,   630,   622,   314,  1296,  1511,  1028,   585,   314,   314,
     314,   314,  1061,   921,   922,   923,   924,   718,   625,  1522,
    1160,  1173,   850,  1140,  1284,   623,  1075,   857,  1115,   623,
    1329,  1553,  1554,   627,   614,   615,   536,  1390,  1648,    11,
      12,  1652,   884,   888,   891,   893,  1189,   882,   886,  1232,
     954,  1248,   422,   422,   422,   426,   471,   783,   787,   433,
    1093,  1530,  1219,  1584,   623,  1031,  1256,  1220,   757,   434,
     629,  1706,   717,   717,   821,   820,  1221,  1097,   757,   623,
     623,   623,  1023,  1222,  1253,  1223,   758,   436,   623,   623,
     623,   310,   437,  1475,  1224,   908,   758,   909,   910,   623,
     911,  1108,   913,   623,  1286,   421,   421,   421,   425,   623,
     914,   915,   623,   949,   314,  1250,  1058,  1750,   949,  1091,
    1104,  1225,    11,    12,   438,   439,  1125,  1025,  1273,   630,
     632,   970,   634,   630,  1711,   623,   634,    11,    12,  1193,
     596,  1024,   433,  1025,  -169,   623,   693,   429,   430,   885,
     431,   432,  1058,  1293,   427,   587,   784,   433,   559,   619,
    1024,   983,   704,   984,   705,   623,  1498,   434,   435,   128,
     436,  1396,  1377,   623,   971,   620,   837,  1092,  1257,   972,
     704,  1121,   705,  1094,  1095,   436,  1101,  1196,   634,    13,
     437,  1795,   950,   704,  1026,   705,  1059,   951,  1096,  1102,
    1098,  1099,  1676,   785,   782,   623,   634,   985,   749,   472,
     472,   421,   633,  1163,  1163,  1100,   634,   695,   472,   634,
     759,  1799,   438,   439,   440,   623,  1032,  1511,  1109,   597,
    1322,  1323,  1077,   629,   472,   310,   310,   623,  1504,   310,
    1712,  1261,   634,  1397,  1319,  1140,  1140,  1272,  1226,   648,
     890,   892,   634,   624,  1163,  1772,  1530,  1704,   314,   314,
    1491,  1258,   314,  1033,  1329,  1254,   630,  1259,   626,   877,
      82,   441,   634,  1329,   310,  1539,  1466,   879,  1122,  1124,
     634,  1190,  1440,  1232,    93,   830,   623,  1287,  1231,   623,
     428,  1562,  1370,   623,   623,  1041,  1396,   314,  1063,   444,
     882,   886,  1808,   472,  1811,   623,  1570,   445,  1163,   107,
    1738,   701,   634,  1137,   703,   446,  1138,   537,  1017,   472,
     623,  1163,  1713,  1426,   980,  1324,  1398,  1399,  -169,  1400,
     442,   537,   634,  -170,   623,   623,   128,   874,   588,   873,
    1227,  1228,  1229,   838,   634,  1325,  1402,  1326,  1681,  1086,
     903,  1064,  1136,    11,    12,   537,   598,   986,  1403,  1112,
    1763,   599,   623,  1649,   883,   887,  1486,   537,  1397,   537,
     987,   443,   988,   821,  1046,  1327,   878,   880,  1501,   114,
     623,   623,   750,   989,   990,   991,   895,   992,  1501,   993,
     751,  1315,   876,   634,  1320,   126,   634,   444,   623,  1739,
     634,   634,   310,  1018,  1501,   445,   310,   429,   430,   828,
     431,   432,   634,   446,  1801,  1087,  1328,   590,  1139,   591,
     623,   708,  1020,  1316,   455,   314,  1682,   634,   435,   314,
    1650,   623,   709,   310,   152,   310,   623,   623,  1163,   628,
    1737,   634,   634,   569,   573,   600,  1601,  1038,  1456,   822,
    1793,  1398,  1399,  1070,  1400,   774,   314,   674,   314,   674,
    1321,  1401,   310,  1502,   683,  1571,  1572,   310,  1329,   634,
    1188,  1402,  1317,  1638,   675,  1746,   675,  1179,   684,  1141,
    1747,  1468,  1019,  1403,  1371,   314,   778,   634,   634,  1643,
     314,  1748,   553,   890,   892,   890,  1476,   676,  1511,  1140,
     426,  1021,   426,  1053,    13,   634,   592,  1650,  1140,   733,
    1602,   734,  1183,  1024,   486,  1591,   574,  -170,  1069,  1140,
    1777,  1115,  1231,   775,  1322,  1548,  1039,   634,   578,   426,
     581,   441,  1071,   674,   426,  1024,  1453,  1352,   634,   310,
    1372,  1373,  1374,   634,   634,  1088,   310,  1072,  1445,   733,
     675,   734,   452,   754,  1180,   756,    13,  1180,   719,  1163,
     456,  1048,   314,  1089,  1090,  1197,  1198,   936,   937,   314,
    1201,   736,   720,  1695,   459,   630,   460,   609,   611,  1366,
     465,  1114,   802,  1163,   735,    82,   310,   808,  1060,  1700,
     442,   487,   537,   310,   448,   537,  1557,  1777,  1392,    93,
    1240,  1322,  1126,  1178,   310,   310,   310,   310,  1447,   314,
    1723,   736,  1024,   422,  1560,   677,   314,  1119,   467,  1794,
    1797,   128,  1025,   310,   107,   631,  1073,   314,   314,   314,
     314,   443,   737,  1181,  1322,  1367,  1182,    82,  1123,  1325,
     461,  1326,   880,  1685,   678,   462,   314,  1322,   476,  1778,
    1686,    93,  1696,   868,  1783,  1322,  1323,   679,   488,   489,
    1687,  1674,   468,  1024,  1213,  1260,   421,  1783,  1701,  1327,
    1565,   469,   737,  1467,   725,   537,   107,   593,   537,   594,
    1137,  1214,   537,  1138,  1656,   537,   537,  1140,  1504,  1660,
    1263,   680,   463,   537,  1025,  1264,  1445,  1191,   470,   537,
     537,  1141,  1141,   128,   537,  1622,   637,  1566,  1163,  1191,
     638,  1074,   537,  1446,  1265,   639,  1325,  1367,  1326,   537,
     537,   537,   537,  1577,  1215,   674,  1814,   537,  1432,  1207,
    1024,  1685,   894,  1025,   640,   537,   896,  1729,  1686,  1645,
    1208,   890,   675,   637,  1731,  1621,  1327,   638,  1687,  1325,
    1324,  1326,   639,   631,  1040,  1266,  1447,   631,   310,  1433,
    1784,  1616,  1325,  1646,  1326,  1754,   595,   479,  1646,   885,
    1325,   640,  1326,  1817,  1242,   480,  1245,  1434,  1556,  1327,
     537,   314,  1322,  1323,  1756,   481,  1757,   484,   762,   310,
     310,   694,  1327,  1163,  1263,   537,  1163,   727,   780,  1264,
    1327,  1120,  1377,  1735,   114,  1807,   537,  1827,   793,   485,
    1782,  1788,   314,   314,  1567,   804,   805,   620,  1741,  1360,
     126,  1568,  1744,  1379,   811,   422,  1308,  1646,  1309,  1646,
     728,  1646,   641,   851,  1213,   642,   726,  1025,   851,   730,
     747,  1524,   537,   738,   490,   748,   744,   745,   310,  1798,
     643,  1214,  1782,   721,   753,   492,   426,   426,  1788,   152,
     765,   768,  1419,  1420,   448,   768,  1489,   722,   895,   641,
    1828,   314,   642,   788,   880,   310,   644,  1324,   421,   723,
     796,   797,   798,   801,   681,  1421,   493,   829,   807,   494,
     631,  1683,  1684,   682,  1646,   724,   814,  1325,   314,  1326,
    1680,  1293,  1509,  1790,  1322,  1323,   835,   836,  1184,  1067,
    1068,  1376,  1186,   644,  1503,  1510,  1710,   840,  1368,  1439,
     971,  1764,  1377,  1209,  1185,   972,  1512,  1327,  1187,   637,
    1163,   114,  1378,   638,  1210,   778,   867,   869,   639,  1513,
    1509,   815,  1234,  1379,  1263,  1509,  1336,   126,  1337,  1264,
    1341,  1235,  1342,  1655,   491,  1141,   801,   640,  1820,   939,
     453,   538,   939,   454,  1141,  1549,   939,   826,  1529,   539,
     956,   696,   697,   537,  1558,  1141,   541,  1163,   457,  1163,
     477,   458,   482,   478,  1487,   483,   152,   537,  1202,  1203,
    1204,   537,   537,   542,  1205,   699,  1199,  1200,   702,  1324,
     554,  1752,  1753,   863,   739,   740,   741,  1550,  1551,   555,
    1163,   918,   919,   537,   556,   537,   925,   926,  1710,  1325,
     575,  1326,   576,   537,   935,   577,   537,   927,   928,   938,
     537,  1451,  1452,  1697,  1698,   938,   582,   583,   584,   586,
     648,  -608,  1163,   589,   601,   310,   602,   606,   603,  1327,
     604,   605,   612,   114,   616,   641,   653,  1163,   642,  1163,
     654,   636,   672,   673,   685,  1710,   687,   692,   314,   126,
     717,   688,   537,  1545,  1796,   686,   698,   707,  1634,   957,
     958,   959,   960,   961,   962,   963,   964,   965,   966,   710,
    1658,   711,  1361,   712,   713,   729,   448,   731,   732,   644,
     742,   746,   310,   310,   310,   755,   769,   770,   152,   772,
     778,   537,   426,   781,   789,  1362,   790,   791,   792,   803,
     809,   816,   454,   810,   818,   314,   314,   314,   458,   478,
     820,   483,   494,   823,   976,   831,   827,  1838,   824,  1839,
     537,   825,   839,  1141,   841,   842,   870,   859,  1006,  1847,
     864,   865,  1010,  1011,  1080,  1081,  1082,   860,   869,   881,
     899,   607,   900,   901,   916,  1304,   902,   929,   930,   931,
     537,   537,   537,   537,  1030,   932,  1036,   946,   945,   952,
     953,   955,   977,   978,  1042,   981,   982,  1045,  1003,  1004,
    1007,  1050,  1012,  1015,  1009,  1005,  1013,  1014,  1016,  1113,
    1022,  1037,  1043,  1044,  1047,  1054,  1055,  1056,  1062,  1640,
    1057,   537,  1065,  1066,   453,   457,   477,  1460,   482,   493,
    1105,   310,  1103,   655,  1106,   537,  1110,  1111,  1107,  1121,
    1192,   656,   657,  1083,   658,  1118,  1128,  1024,   972,  1211,
    1212,  1238,   659,  1233,   314,  1239,   660,  1249,   661,  1251,
     537,  1255,   903,   662,  1262,  1241,   774,   310,  1275,   537,
    1276,   537,  1278,   537,  1494,   537,  1277,  1282,   310,   663,
    1281,  1283,  1288,  1289,  1292,  1305,  1293,  1299,   537,  1311,
     314,  1314,  1306,  1516,  1318,  1307,  1312,   310,   422,  1334,
    1335,   314,  1353,   664,   665,   666,   667,   668,   669,   735,
    1363,  1127,  1384,  1388,  1386,  1413,  1416,   310,  1412,  1424,
     314,   537,  1425,   537,   310,  1393,  1436,  1427,  1428,   560,
      13,  1429,  1430,  1431,  1443,  1444,  1449,  1461,  1459,  1454,
     314,  1172,  1172,  1176,  1176,   422,  1462,   314,  1721,  1455,
    1458,   421,  1473,  1463,  1464,  1480,  1361,  1471,   851,  1725,
    1640,  1477,  1727,  1479,   422,  1465,  1481,  1485,  1490,  1493,
    1736,  1515,  1509,  1523,  1526,  1517,  1518,  1521,  1537,  1362,
    1532,  1541,  1172,   537,   426,  1542,  1533,  1534,  1535,  1543,
    1536,   426,  1544,  1366,  1377,  1538,  1206,  1561,   421,  1564,
    1580,  1574,  1581,  1587,  1585,   537,  1600,  1593,  1594,  1595,
    1596,  1606,  1597,  1609,  1598,  1611,  1613,   421,  1599,  1631,
    1615,  1237,  1617,   868,  1619,  1624,  1632,  1633,  1636,  1637,
    1244,  1642,  1244,  1678,   768,  1653,  1172,  1527,  1654,  1659,
    1662,  1679,  1667,  1693,  1531,  1691,  1702,  1213,  1694,  1172,
    1707,  1718,  1727,  1715,  1720,  1726,  1758,  1692,  1759,  1714,
    1761,  1743,  1760,  1762,  1766,  1771,  1767,  1773,  1774,  1775,
    1789,  1791,  1804,  1792,  1812,  1805,  1813,  1816,  1389,  1837,
     979,  1819,   807,  1824,   807,  1802,  1830,  1822,  1829,  1841,
    1843,  1809,   310,   617,  1840,   621,  1831,  1844,   537,  1194,
    1834,   618,   537,  1274,  1836,  1846,  1457,   716,  1442,  1487,
     752,  1769,  1117,  1800,  1271,   314,   771,   537,  1052,  1629,
    1484,  1559,  1375,  1555,  1825,  1495,   537,  1552,   906,  1499,
    1505,  1514,   917,   907,   817,  1361,  1177,   948,   691,  1525,
     537,  1084,  1818,  1815,  1385,  1825,  1246,   760,   761,  1441,
     537,  1540,  1547,  1546,  1809,  1391,  1575,  1579,  1362,  1690,
    1689,  1578,  1415,  1218,  1699,  1450,  1172,  1608,  1576,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   537,
       0,     0,   855,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   537,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   537,     0,     0,     0,   537,     0,
       0,  1361,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1361,  1361,     0,   310,     0,     0,     0,     0,
       0,     0,     0,  1361,  1362,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1362,  1362,     0,   314,   768,
       0,     0,     0,  1469,     0,     0,  1362,     0,     0,     0,
       0,     0,     0,     0,     0,   537,     0,     0,  1483,     0,
       0,     0,     0,     0,     0,     0,     0,  1172,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   801,     0,     0,     0,   537,     0,     0,     0,     0,
       0,  1172,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1361,     0,     0,     0,     0,
       0,   537,   537,     0,     0,     0,     0,     0,     0,     0,
    1528,     0,     0,     0,     0,     0,     0,     0,  1362,     0,
       0,     0,     0,     0,     0,     0,     0,   537,     0,     0,
     537,     0,     0,   537,   310,   863,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   537,     0,     0,     0,     0,
     537,     0,  1361,     0,   560,     0,     0,   314,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   310,     0,     0,
       0,     0,     0,     0,     0,  1362,     0,     0,   843,   844,
       0,   852,   853,   854,   856,     0,   858,     0,  1361,     0,
     314,     0,   866,     0,     0,     0,     0,  1361,     0,     0,
     875,     0,     0,     0,     0,     0,  1172,     0,     0,     0,
       0,  1362,     0,     0,     0,     0,     0,     0,     0,     0,
    1362,     0,   897,   898,     0,     0,     0,     0,     0,     0,
       0,   904,   905,     0,     0,     0,  1614,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1671,  1672,  1673,     0,     0,     0,     0,
       0,     0,  1627,  1628,     0,     0,     0,   537,   537,     0,
     537,     0,   537,     0,     0,     0,     0,     0,     0,   537,
       0,     0,     0,     0,     0,     0,     0,     0,  1644,     0,
       0,  1172,     0,   943,  1172,     0,     0,   943,     0,     0,
       0,     0,     0,     0,     0,     0,  1657,     0,     0,     0,
       0,  1661,     0,     0,   537,     0,   537,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   537,     0,     0,   537,  1008,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   537,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   537,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1051,   537,
       0,     0,     0,     0,     0,  1749,     0,   537,     0,     0,
       0,     0,   537,     0,   537,     0,   537,     0,     0,     0,
       0,     0,  1755,     0,  1076,     0,     0,     0,  1078,  1079,
       0,     0,     0,     0,     0,     0,     0,   904,     0,     0,
       0,     0,     0,     0,     0,   537,     0,     0,  1172,  1730,
       0,  1732,     0,  1734,     0,     0,     0,     0,     0,     0,
    1742,     0,     0,     0,     0,   537,     0,     0,     0,     0,
     537,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   537,     0,     0,   537,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1172,     0,  1172,     0,     0,
       0,     0,     0,   898,     0,     0,     0,     0,     0,  1129,
    1133,     0,     0,  1765,     0,     0,  1768,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1172,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1776,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1172,     0,     0,     0,     0,     0,     0,     0,  1803,     0,
       0,     0,     0,  1806,     0,  1172,     0,  1172,     0,     0,
    1195,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1823,     0,     0,     0,
       0,     0,     0,     0,     0,  1236,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1832,  -864,   459,     0,
     460,  1833,     0,     0,  1252,     0,     0,     0,     0,     0,
       0,     0,     0,  1842,     0,     0,  1845,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1285,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1290,  1291,  -864,
       0,     0,     0,  -864,     0,     0,     0,  -864,  -864,     0,
       0,     0,  1310,  -864,     0,  1313,     0,     0,     0,     0,
       0,     0,     0,     0,   461,     0,     0,  -864,     0,   462,
       0,     0,  1338,  1339,  1340,     0,  1343,  1344,  1345,  1346,
    1347,  1348,  1349,  1350,  1351,     0,     0,  1354,  1355,     0,
    -864,     0,  -864,  -864,  -864,     0,  1369,  -864,  -864,  -864,
    -864,     0,     0,     0,  -864,  -864,  1129,     0,     0,     0,
       0,  -864,     0,     0,  -864,  -864,   463,     0,     0,  -864,
       0,     0,     0,     0,  -864,  -864,     0,     0,     0,     0,
    -864,     0,     0,     0,  -864,     0,     0,     0,  -864,  -864,
       0,  -864,     0,  -864,  -864,     0,     0,     0,  -864,  -864,
       0,     0,  -864,  -864,  -864,  -864,  -864,  -864,  1438,     0,
    -864,     0,     0,     0,  -864,  -864,     0,     0,  -864,     0,
       0,     0,     0,  -864,     0,     0,  -864,     0,     0,     0,
       0,  -864,  -864,  -864,  -864,  -864,     0,  -864,  -864,  -864,
    -864,  -864,     0,     0,     0,     0,  -864,  -864,  -864,     0,
    -864,  -864,  -864,  -864,  -864,  -864,     0,  -864,     0,  -864,
       0,     0,     0,     0,  -864,  -864,  -864,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    -864,  1470,  -864,  1472,  -864,  1474,     0,     0,  1478,     0,
       0,     0,     0,  1482,     0,     0,  -864,     0,     0,     0,
       0,  -864,     0,     0,     0,  1488,     0,     0,     0,     0,
       0,     0,     0,     0,  1492,     0,     0,     0,     0,     0,
    1496,  1497,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1519,
       0,     0,  1520,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  -864,     0,
    -864,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1129,     0,     0,     0,  1133,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1618,     0,     0,     0,  1620,
       0,     0,     0,  1623,     0,  1625,     0,  1626,     0,     0,
       0,     0,     0,  1630,     0,     0,     0,     0,     0,     0,
       0,  1635,     0,     0,     0,     0,     0,     0,     0,  1639,
    1641,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1488,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1663,  1664,  1665,  1666,     0,  1668,  1669,     0,  1670,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1677,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1716,     0,  1717,
       0,     0,  1719,     0,     0,     0,     0,     0,     0,     0,
    1722,     0,     0,     0,     0,  1724,  1641,     0,     0,     0,
       0,     0,     0,  1728,     0,     0,     0,     0,  1733,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1745,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1751,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1770,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1728,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1810,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1821,     0,     0,     0,     0,  1826,     0,     0,     0,     0,
    1810,  -165,   885,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     1,     2,     0,  1826,     0,     3,     0,  1835,
       0,     4,     5,     6,     7,     8,     9,    10,    11,    12,
       0,    13,     0,     0,    14,   417,     0,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,     0,    35,    36,    37,
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
     245,   246,     0,   247,     0,   248,   249,   250,   251,   252,
     253,   254,  -165,   885,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     1,     2,     0,     0,     0,     3,     0,
       0,     0,     4,     5,     6,     7,     8,     9,    10,    11,
      12,     0,    13,     0,     0,   889,   417,     0,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,   418,    30,    31,    32,    33,    34,     0,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,     0,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,     0,    72,    73,    74,
      75,    76,     0,    77,    78,    79,     0,     0,    80,    81,
       0,     0,     0,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,     0,     0,     0,    93,     0,    94,
      95,    96,    97,     0,    98,     0,     0,     0,    99,   100,
     101,   102,   103,     0,     0,     0,     0,     0,     0,   104,
     105,   106,   107,   108,   109,   110,   111,   112,     0,   113,
     114,   115,   116,   117,     0,     0,     0,   118,   119,   120,
     121,   122,   123,   124,   125,     0,   126,     0,   127,   128,
       0,     0,   129,   130,   131,     0,     0,     0,   132,     0,
     133,   134,     0,   135,   136,     0,   137,     0,   138,     0,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,     0,     0,   150,   151,   152,     0,   419,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
       0,   196,   197,   198,     0,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   885,   247,     0,   248,   249,   250,   251,
     252,   253,   254,     1,     2,     0,     0,     0,     3,     0,
       0,     0,     4,     5,     6,     7,     8,     9,    10,    11,
      12,     0,    13,     0,     0,   416,   417,     0,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,   418,    30,    31,    32,    33,    34,     0,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,     0,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,     0,    72,    73,    74,
      75,    76,     0,    77,    78,    79,     0,     0,    80,    81,
       0,     0,     0,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,     0,     0,     0,    93,     0,    94,
      95,    96,    97,     0,    98,     0,     0,     0,    99,   100,
     101,   102,   103,     0,     0,     0,     0,     0,     0,   104,
     105,   106,   107,   108,   109,   110,   111,   112,     0,   113,
     114,   115,   116,   117,     0,     0,     0,   118,   119,   120,
     121,   122,   123,   124,   125,     0,   126,     0,   127,   128,
       0,     0,   129,   130,   131,     0,     0,     0,   132,     0,
     133,   134,     0,   135,   136,     0,   137,     0,   138,     0,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,     0,     0,   150,   151,   152,     0,   419,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
       0,   196,   197,   198,     0,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   885,   247,     0,   248,   249,   250,   251,
     252,   253,   254,     1,     2,     0,     0,     0,     3,     0,
       0,     0,     4,     5,     6,     7,     8,     9,    10,     0,
       0,     0,    13,     0,     0,   416,   417,     0,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
     562,   418,    30,    31,    32,    33,    34,     0,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,     0,    48,    49,    50,   563,   564,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,     0,    72,    73,    74,
      75,    76,     0,    77,    78,    79,     0,     0,    80,    81,
       0,     0,     0,    82,    83,   512,    85,    86,    87,    88,
      89,   565,    91,    92,     0,     0,     0,    93,     0,    94,
      95,    96,    97,     0,    98,     0,     0,     0,    99,   100,
     101,   102,   103,     0,     0,     0,     0,     0,     0,   104,
     105,   106,   107,   108,   109,   110,   566,   112,     0,   113,
     114,   115,   116,   117,     0,     0,     0,   118,   119,   120,
     121,   122,   123,   124,   125,     0,   126,     0,   127,   128,
       0,     0,   129,   130,   131,     0,     0,     0,   132,     0,
     133,   134,     0,   135,   136,     0,   137,     0,   138,     0,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,     0,     0,   150,   151,   152,     0,   419,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     530,   531,   532,   179,   180,   533,   568,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
       0,   196,   197,   198,     0,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,     0,   247,     0,   248,   249,   250,   251,
     252,   253,   254,     1,     2,     0,     0,     0,     3,     0,
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
      89,    90,    91,    92,     0,     0,     0,    93,     0,    94,
      95,    96,    97,     0,    98,     0,     0,     0,    99,   100,
     101,   102,   103,     0,     0,     0,     0,     0,     0,   104,
     105,   106,   107,   108,   109,   110,   111,   112,     0,   113,
     114,   115,   116,   117,     0,     0,     0,   118,   119,   120,
     121,   122,   123,   124,   125,     0,   126,     0,   127,   128,
       0,     0,   129,   130,   131,     0,     0,     0,   132,     0,
     133,   134,     0,   135,   136,     0,   137,     0,   138,     0,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,     0,     0,   150,   151,   152,     0,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
       0,   196,   197,   198,     0,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,     0,   247,     0,   248,   249,   250,   251,
     252,   253,   254,   255,   256,     1,     2,     0,     0,     0,
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
     250,   251,   252,   253,   254,     0,   613,     1,     2,     0,
       0,     0,     3,     0,     0,     0,     4,     5,     6,     7,
       8,     9,    10,    11,    12,     0,    13,     0,     0,   416,
     417,     0,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,   418,    30,    31,    32,    33,
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
     557,     0,   132,     0,   133,   134,     0,   135,   136,     0,
     137,     0,   138,     0,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,     0,     0,   150,   151,   152,
       0,   419,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,     0,   196,   197,   198,     0,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,     0,   247,     0,
     248,   249,   250,   251,   252,   253,   254,     1,     2,     0,
       0,     0,     3,     0,     0,     0,     4,     5,     6,     7,
       8,     9,    10,    11,    12,     0,    13,     0,     0,   416,
     417,     0,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,   418,    30,    31,    32,    33,
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
     819,     0,   132,     0,   133,   134,     0,   135,   136,     0,
     137,     0,   138,     0,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,     0,     0,   150,   151,   152,
       0,   419,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,     0,   196,   197,   198,     0,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,     0,   247,     0,
     248,   249,   250,   251,   252,   253,   254,     1,     2,     0,
       0,     0,     3,     0,     0,     0,     4,     5,     6,     7,
       8,     9,    10,    11,    12,     0,    13,     0,     0,   416,
     417,     0,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,  1356,   418,    30,    31,    32,    33,
      34,     0,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,     0,    48,    49,    50,  1357,
    1358,    53,    54,    55,    56,    57,    58,    59,    60,    61,
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
     557,     0,   132,     0,   133,   134,     0,   135,   136,     0,
     137,     0,   138,     0,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,     0,     0,   150,   151,   152,
       0,   419,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
    1359,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,     0,   196,   197,   198,     0,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,     0,   247,     0,
     248,   249,   250,   251,   252,   253,   254,     1,     2,     0,
       0,     0,     3,     0,     0,     0,     4,     5,     6,     7,
       8,     9,    10,    11,    12,     0,    13,     0,     0,   416,
     417,     0,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,   418,    30,    31,    32,    33,
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
       0,   419,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,     0,   196,   197,   198,     0,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,     0,   247,     0,
     248,   249,   250,   251,   252,   253,   254,     1,     2,     0,
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
     248,   249,   250,   251,   252,   253,   254,     1,     2,     0,
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
       0,   419,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,     0,   196,   197,   198,     0,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,     0,   247,     0,
     248,   249,   250,   251,   252,   253,   254,     1,     2,     0,
       0,     0,     3,     0,     0,     0,     4,     5,     6,     7,
       8,     9,    10,    11,    12,     0,    13,     0,     0,    14,
     417,     0,    16,    17,    18,    19,    20,    21,    22,    23,
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
       0,   419,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,     0,   196,   197,   198,     0,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,     0,   247,     0,
     248,   249,   250,   251,   252,   253,   254,     1,     2,     0,
       0,     0,     3,     0,     0,     0,     4,     5,     6,     7,
       8,     9,    10,    11,    12,     0,    13,     0,     0,   889,
     417,     0,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,   418,    30,    31,    32,    33,
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
       0,   419,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,     0,   196,   197,   198,     0,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,     0,   247,     0,
     248,   249,   250,   251,   252,   253,   254,     1,     2,     0,
       0,     0,     3,     0,     0,     0,     4,     5,     6,     7,
       8,     9,    10,     0,     0,     0,    13,     0,     0,   416,
     417,     0,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,   562,   418,    30,    31,    32,    33,
      34,     0,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,     0,    48,    49,    50,   563,
     564,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
       0,    72,    73,    74,    75,    76,     0,    77,    78,    79,
       0,     0,    80,    81,     0,     0,     0,    82,    83,   512,
      85,    86,    87,    88,    89,   565,    91,    92,     0,     0,
       0,    93,     0,    94,    95,    96,    97,     0,    98,     0,
       0,     0,    99,   100,   101,   102,   103,     0,     0,     0,
       0,   941,     0,   104,   105,   106,   107,   108,   109,   110,
     566,   112,     0,   113,   114,   115,   116,   117,     0,     0,
       0,   118,   119,   120,   121,   122,   123,   124,   125,     0,
     126,     0,   127,   128,     0,     0,   129,   130,   131,     0,
       0,     0,   132,   942,   133,   134,     0,   135,   136,     0,
     137,     0,   138,     0,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,     0,     0,   150,   151,   152,
       0,   419,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   530,   531,   532,   179,   180,   533,
     568,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,     0,   196,   197,   198,     0,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,     0,   247,     0,
     248,   249,   250,   251,   252,   253,   254,     1,     2,     0,
       0,     0,     3,     0,     0,     0,     4,     5,     6,     7,
       8,     9,    10,     0,     0,     0,    13,     0,     0,   416,
     417,     0,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,   562,   418,    30,    31,    32,    33,
      34,     0,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,     0,    48,    49,    50,   563,
     564,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
       0,    72,    73,    74,    75,    76,     0,    77,    78,    79,
       0,     0,    80,    81,     0,     0,     0,    82,    83,   512,
      85,    86,    87,    88,    89,   565,    91,    92,     0,     0,
       0,    93,     0,    94,    95,    96,    97,     0,    98,     0,
       0,     0,    99,   100,   101,   102,   103,     0,     0,     0,
       0,   941,     0,   104,   105,   106,   107,   108,   109,   110,
     566,   112,     0,   113,   114,   115,   116,   117,     0,     0,
       0,   118,   119,   120,   121,   122,   123,   124,   125,     0,
     126,     0,   127,   128,     0,     0,   129,   130,   131,     0,
       0,     0,   132,   947,   133,   134,     0,   135,   136,     0,
     137,     0,   138,     0,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,     0,     0,   150,   151,   152,
       0,   419,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   530,   531,   532,   179,   180,   533,
     568,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,     0,   196,   197,   198,     0,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,     0,   247,     0,
     248,   249,   250,   251,   252,   253,   254,     1,     2,     0,
       0,     0,     3,     0,     0,     0,     4,     5,     6,     7,
       8,     9,    10,    11,    12,     0,    13,     0,     0,   416,
     417,     0,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,  1356,   418,    30,    31,    32,    33,
      34,     0,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,     0,    48,    49,    50,  1357,
    1358,    53,    54,    55,    56,    57,    58,    59,    60,    61,
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
       0,   419,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
    1359,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,     0,   196,   197,   198,     0,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,     0,   247,     0,
     248,   249,   250,   251,   252,   253,   254,     1,     2,     0,
       0,     0,     3,     0,     0,     0,     4,     5,     6,     7,
       8,     9,    10,     0,     0,     0,    13,     0,     0,   416,
     417,     0,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,   562,   418,    30,    31,    32,    33,
      34,     0,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,     0,    48,    49,    50,   563,
     564,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
       0,    72,    73,    74,    75,    76,     0,    77,    78,    79,
       0,     0,    80,    81,     0,     0,     0,    82,    83,   512,
      85,    86,    87,    88,    89,   565,    91,    92,     0,     0,
       0,    93,     0,    94,    95,    96,    97,     0,    98,     0,
       0,     0,    99,   100,   101,   102,   103,     0,     0,     0,
       0,     0,     0,   104,   105,   106,   107,   108,   109,   110,
     566,   112,     0,   113,   114,   115,   116,   117,     0,     0,
       0,   118,   119,   120,   121,   122,   123,   124,   125,     0,
     126,     0,   127,   128,     0,     0,   129,   130,   131,     0,
       0,   567,   132,     0,   133,   134,     0,   135,   136,     0,
     137,     0,   138,     0,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,     0,     0,   150,   151,   152,
       0,   419,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   530,   531,   532,   179,   180,   533,
     568,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,     0,   196,   197,   198,     0,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,     0,   247,     0,
     248,   249,   250,   251,   252,   253,   254,     1,     2,     0,
       0,     0,     3,     0,     0,     0,     4,     5,     6,     7,
       8,     9,    10,     0,     0,     0,    13,     0,     0,   416,
     417,     0,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,   562,   418,    30,    31,    32,    33,
      34,     0,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,     0,    48,    49,    50,   563,
     564,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
       0,    72,    73,    74,    75,    76,     0,    77,    78,    79,
       0,     0,    80,    81,     0,     0,     0,    82,    83,   512,
      85,    86,    87,    88,    89,   565,    91,    92,     0,     0,
       0,    93,     0,    94,    95,    96,    97,     0,    98,     0,
       0,     0,    99,   100,   101,   102,   103,     0,     0,     0,
       0,     0,     0,   104,   105,   106,   107,   108,   109,   110,
     566,   112,     0,   113,   114,   115,   116,   117,     0,     0,
       0,   118,   119,   120,   121,   122,   123,   124,   125,     0,
     126,     0,   127,   128,     0,     0,   129,   130,   131,     0,
       0,     0,   132,   572,   133,   134,     0,   135,   136,     0,
     137,     0,   138,     0,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,     0,     0,   150,   151,   152,
       0,   419,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   530,   531,   532,   179,   180,   533,
     568,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,     0,   196,   197,   198,     0,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,     0,   247,     0,
     248,   249,   250,   251,   252,   253,   254,     1,     2,     0,
       0,     0,     3,     0,     0,     0,     4,     5,     6,     7,
       8,     9,    10,     0,     0,     0,    13,     0,     0,   416,
     417,     0,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,   562,   418,    30,    31,    32,    33,
      34,     0,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,     0,    48,    49,    50,   563,
     564,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
       0,    72,    73,    74,    75,    76,     0,    77,    78,    79,
       0,     0,    80,    81,     0,     0,     0,    82,    83,   512,
      85,    86,    87,    88,    89,   565,    91,    92,     0,     0,
       0,    93,     0,    94,    95,    96,    97,     0,    98,     0,
       0,     0,    99,   100,   101,   102,   103,     0,     0,     0,
       0,     0,     0,   104,   105,   106,   107,   108,   109,   110,
     566,   112,     0,   113,   114,   115,   116,   117,     0,     0,
       0,   118,   119,   120,   121,   122,   123,   124,   125,     0,
     126,     0,   127,   128,     0,     0,   129,   130,   131,     0,
       0,     0,   132,     0,   133,   134,     0,   135,   136,     0,
     137,     0,   138,     0,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,     0,     0,   150,   151,   152,
       0,   419,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   530,   531,   532,   179,   180,   533,
     568,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,     0,   196,   197,   198,     0,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   608,   247,     0,
     248,   249,   250,   251,   252,   253,   254,     1,     2,     0,
       0,     0,     3,     0,     0,     0,     4,     5,     6,     7,
       8,     9,    10,     0,     0,     0,    13,     0,     0,   416,
     417,     0,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,   562,   418,    30,    31,    32,    33,
      34,     0,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,     0,    48,    49,    50,   563,
     564,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
       0,    72,    73,    74,    75,    76,     0,    77,    78,    79,
       0,     0,    80,    81,     0,     0,     0,    82,    83,   512,
      85,    86,    87,    88,    89,   565,    91,    92,     0,     0,
       0,    93,     0,    94,    95,    96,    97,     0,    98,     0,
       0,     0,    99,   100,   101,   102,   103,     0,     0,     0,
       0,     0,     0,   104,   105,   106,   107,   108,   109,   110,
     566,   112,     0,   113,   114,   115,   116,   117,     0,     0,
       0,   118,   119,   120,   121,   122,   123,   124,   125,     0,
     126,     0,   127,   128,     0,     0,   129,   130,   131,     0,
       0,     0,   132,     0,   133,   134,     0,   135,   136,     0,
     137,     0,   138,     0,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,     0,     0,   150,   151,   152,
       0,   419,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   530,   531,   532,   179,   180,   533,
     568,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,     0,   196,   197,   198,     0,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,     0,   247,   610,
     248,   249,   250,   251,   252,   253,   254,     1,     2,     0,
       0,     0,     3,     0,     0,     0,     4,     5,     6,     7,
       8,     9,    10,     0,     0,     0,    13,     0,     0,   416,
     417,     0,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,   562,   418,    30,    31,    32,    33,
      34,     0,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,     0,    48,    49,    50,   563,
     564,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
       0,    72,    73,    74,    75,    76,     0,    77,    78,    79,
       0,     0,    80,    81,     0,     0,     0,    82,    83,   512,
      85,    86,    87,    88,    89,   565,    91,    92,     0,     0,
       0,    93,     0,    94,    95,    96,    97,     0,    98,     0,
       0,     0,    99,   100,   101,   102,   103,     0,     0,     0,
       0,     0,     0,   104,   105,   106,   107,   108,   109,   110,
     566,   112,     0,   113,   114,   115,   116,   117,     0,     0,
       0,   118,   119,   120,   121,   122,   123,   124,   125,     0,
     126,     0,   127,   128,     0,     0,   129,   130,   131,     0,
     934,     0,   132,     0,   133,   134,     0,   135,   136,     0,
     137,     0,   138,     0,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,     0,     0,   150,   151,   152,
       0,   419,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   530,   531,   532,   179,   180,   533,
     568,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,     0,   196,   197,   198,     0,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,     0,   247,     0,
     248,   249,   250,   251,   252,   253,   254,     1,     2,     0,
       0,     0,     3,     0,     0,     0,     4,     5,     6,     7,
       8,     9,    10,     0,     0,     0,    13,     0,     0,   416,
     417,     0,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,   562,   418,    30,    31,    32,    33,
      34,     0,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,     0,    48,    49,    50,   563,
     564,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
       0,    72,    73,    74,    75,    76,     0,    77,    78,    79,
       0,     0,    80,    81,     0,     0,     0,    82,    83,   512,
      85,    86,    87,    88,    89,   565,    91,    92,     0,     0,
       0,    93,     0,    94,    95,    96,    97,     0,    98,     0,
       0,     0,    99,   100,   101,   102,   103,     0,     0,     0,
       0,     0,     0,   104,   105,   106,   107,   108,   109,   110,
     566,   112,     0,   113,   114,   115,   116,   117,     0,     0,
       0,   118,   119,   120,   121,   122,   123,   124,   125,     0,
     126,     0,   127,   128,     0,     0,   129,   130,   131,     0,
       0,   940,   132,     0,   133,   134,     0,   135,   136,     0,
     137,     0,   138,     0,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,     0,     0,   150,   151,   152,
       0,   419,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   530,   531,   532,   179,   180,   533,
     568,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,     0,   196,   197,   198,     0,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,     0,   247,     0,
     248,   249,   250,   251,   252,   253,   254,     1,     2,     0,
       0,     0,     3,     0,     0,     0,     4,     5,     6,     7,
       8,     9,    10,     0,     0,     0,    13,     0,     0,   416,
     417,     0,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,   562,   418,    30,    31,    32,    33,
      34,     0,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,     0,    48,    49,    50,   563,
     564,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
       0,    72,    73,    74,    75,    76,     0,    77,    78,    79,
       0,     0,    80,    81,     0,     0,     0,    82,    83,   512,
      85,    86,    87,    88,    89,   565,    91,    92,     0,     0,
       0,    93,     0,    94,    95,    96,    97,     0,    98,     0,
       0,     0,    99,   100,   101,   102,   103,     0,     0,     0,
       0,  1437,     0,   104,   105,   106,   107,   108,   109,   110,
     566,   112,     0,   113,   114,   115,   116,   117,     0,     0,
       0,   118,   119,   120,   121,   122,   123,   124,   125,     0,
     126,     0,   127,   128,     0,     0,   129,   130,   131,     0,
       0,     0,   132,     0,   133,   134,     0,   135,   136,     0,
     137,     0,   138,     0,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,     0,     0,   150,   151,   152,
       0,   419,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   530,   531,   532,   179,   180,   533,
     568,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,     0,   196,   197,   198,     0,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,     0,   247,     0,
     248,   249,   250,   251,   252,   253,   254,     1,     2,     0,
       0,     0,     3,     0,     0,     0,     4,     5,     6,     7,
       8,     9,    10,     0,     0,     0,    13,     0,     0,   416,
     417,     0,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,   498,    27,   500,   418,    30,   501,    32,    33,
      34,     0,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,   503,     0,    48,    49,    50,   505,
     506,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
       0,    72,    73,    74,    75,    76,     0,    77,    78,    79,
       0,     0,    80,    81,     0,     0,     0,    82,    83,   512,
      85,    86,    87,    88,    89,   565,    91,    92,     0,     0,
       0,    93,     0,    94,    95,    96,    97,     0,    98,     0,
       0,     0,   515,   100,   101,   102,   103,     0,     0,     0,
       0,     0,     0,   104,   105,   106,   107,   108,   109,   110,
     566,   112,     0,   113,   114,   689,   116,   117,     0,     0,
       0,   118,   119,   120,   121,   122,   123,   124,   125,     0,
     126,     0,   690,   128,     0,     0,   129,   130,   131,     0,
       0,     0,   132,     0,   133,   134,     0,   135,   136,     0,
     137,     0,   138,     0,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,     0,     0,   150,   151,   152,
       0,   419,   154,   155,   156,   157,   158,   159,   160,   161,
     525,   163,   526,   165,   527,   528,   168,   169,   170,   171,
     172,   173,   529,   175,   530,   531,   532,   179,   180,   533,
     534,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,     0,   196,   197,   198,     0,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,     0,   247,     0,
     248,   535,   250,   251,   252,   253,   254,     1,     2,     0,
       0,     0,     3,     0,     0,     0,     4,     5,     6,     7,
       8,     9,    10,     0,     0,     0,    13,     0,     0,   416,
     417,     0,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,   562,   418,    30,    31,    32,    33,
      34,     0,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,     0,    48,    49,    50,   563,
     564,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
       0,    72,    73,    74,    75,    76,     0,    77,    78,    79,
       0,     0,    80,    81,     0,     0,     0,    82,    83,   512,
      85,    86,    87,    88,    89,   565,    91,    92,     0,     0,
       0,    93,     0,    94,    95,    96,    97,     0,    98,     0,
       0,     0,    99,   100,   101,   102,   103,     0,     0,     0,
       0,     0,     0,   104,   105,   106,   107,   108,   109,   110,
     566,   112,     0,   113,   114,   115,   116,   117,     0,     0,
       0,   118,   119,   120,   121,   122,   123,   124,   125,     0,
     126,     0,   127,   128,     0,     0,   129,   130,   131,     0,
       0,     0,   132,     0,   133,   134,     0,   135,   136,     0,
     137,     0,   138,     0,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,     0,     0,   150,   151,   152,
       0,   419,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   530,   531,   532,   179,   180,   533,
     568,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,     0,   196,   197,   198,     0,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,     0,   247,     0,
     248,   249,   250,   251,   252,   253,   254,     1,     2,     0,
       0,     0,     3,     0,     0,     0,     4,     5,     6,     7,
       8,     9,    10,     0,     0,     0,    13,     0,     0,   416,
     417,     0,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,   498,    27,   500,   418,    30,   501,    32,    33,
      34,     0,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,   503,     0,    48,    49,    50,   505,
     506,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
       0,    72,    73,    74,    75,    76,     0,    77,    78,    79,
       0,     0,    80,    81,     0,     0,     0,    82,    83,   512,
      85,    86,    87,    88,    89,   565,    91,    92,     0,     0,
       0,    93,     0,    94,    95,    96,    97,     0,    98,     0,
       0,     0,   515,   100,   101,   102,   103,     0,     0,     0,
       0,     0,     0,   104,   105,   106,   107,   108,   109,   110,
     566,   112,     0,   113,   114,   115,   116,   117,     0,     0,
       0,   118,   119,   120,   121,   122,   123,   124,   125,     0,
     126,     0,   127,   128,     0,     0,   129,   130,   131,     0,
       0,     0,   132,     0,   133,   134,     0,   135,   136,     0,
     137,     0,   138,     0,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,     0,     0,   150,   151,   152,
       0,   419,   154,   155,   156,   157,   158,   159,   160,   161,
     525,   163,   526,   165,   527,   528,   168,   169,   170,   171,
     172,   173,   529,   175,   530,   531,   532,   179,   180,   533,
     534,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,     0,   196,   197,   198,     0,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,     0,   247,     0,
     248,   535,   250,   251,   252,   253,   254,     1,     2,     0,
       0,     0,     3,     0,     0,     0,     4,     5,     6,     7,
       8,     9,    10,     0,     0,     0,    13,     0,     0,   416,
     417,     0,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,   562,   418,    30,    31,    32,    33,
      34,     0,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,     0,    48,    49,    50,   563,
     564,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
       0,    72,    73,    74,    75,    76,     0,    77,    78,    79,
       0,     0,    80,    81,     0,     0,     0,    82,    83,   512,
      85,    86,    87,    88,    89,  1132,    91,    92,     0,     0,
       0,    93,     0,    94,    95,    96,    97,     0,    98,     0,
       0,     0,    99,   100,   101,   102,   103,     0,     0,     0,
       0,     0,     0,   104,   105,   106,   107,   108,   109,   110,
     566,   112,     0,   113,   114,   115,   116,   117,     0,     0,
       0,   118,   119,   120,   121,   122,   123,   124,   125,     0,
     126,     0,   127,   128,     0,     0,   129,   130,   131,     0,
       0,     0,   132,     0,   133,   134,     0,   135,   136,     0,
     137,     0,   138,     0,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,     0,     0,   150,   151,   152,
       0,   419,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   530,   531,   532,   179,   180,   533,
     568,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,     0,   196,   197,   198,     0,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,     0,   247,     0,
     248,   249,   250,   251,   252,   253,   254,     1,     2,     0,
       0,     0,     3,     0,     0,     0,     4,     5,     6,     7,
       8,     9,    10,     0,     0,     0,    13,     0,     0,   416,
     417,     0,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,   498,    27,   500,   418,    30,   501,    32,    33,
      34,     0,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,   503,     0,    48,    49,    50,   505,
     506,    53,   507,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
       0,    72,    73,    74,    75,    76,     0,    77,    78,    79,
       0,     0,    80,    81,     0,     0,     0,    82,    83,   512,
      85,    86,    87,    88,    89,   565,    91,    92,     0,     0,
       0,    93,     0,    94,    95,    96,    97,     0,    98,     0,
       0,     0,   515,   100,   101,   102,   103,     0,     0,     0,
       0,     0,     0,   104,   105,   106,   107,   108,   109,   110,
     566,   112,     0,   113,   114,     0,   116,   117,     0,     0,
       0,   118,   119,   120,   121,   122,   123,   124,   125,     0,
     126,     0,     0,     0,     0,     0,   129,   130,   131,     0,
       0,     0,   132,     0,   133,   134,     0,   135,   136,     0,
     137,     0,   138,     0,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,     0,     0,   150,   151,   152,
       0,   419,   154,   155,   156,   157,   158,   159,   160,   161,
     525,   163,   526,   165,   527,   528,   168,   169,   170,   171,
     172,   173,   529,   175,   530,   531,   532,   179,   180,   533,
     534,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,     0,   196,   197,   198,     0,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,     0,   247,     0,
     248,   535,   250,   251,   252,   253,   254,     1,     2,     0,
       0,     0,     3,     0,     0,     0,     4,     5,     6,     7,
       8,     9,    10,     0,     0,     0,    13,     0,     0,   416,
     417,     0,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,   498,    27,   500,   418,    30,   501,    32,    33,
      34,     0,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,   503,     0,    48,    49,    50,   505,
     506,    53,   507,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
       0,    72,    73,    74,    75,    76,     0,    77,    78,    79,
       0,     0,    80,    81,     0,     0,     0,    82,    83,   512,
      85,    86,    87,    88,    89,   565,    91,    92,     0,     0,
       0,    93,     0,    94,    95,    96,    97,     0,    98,     0,
       0,     0,   515,   100,   101,   102,   103,     0,     0,     0,
       0,     0,     0,   104,   105,   106,   107,   108,   109,   110,
     566,   112,     0,   113,   114,     0,   116,   117,     0,     0,
       0,   118,   119,   120,   121,   122,   123,   124,   125,     0,
     126,     0,     0,     0,     0,     0,   129,   130,   131,     0,
       0,     0,   132,     0,   133,   134,     0,     0,     0,     0,
     137,     0,   138,     0,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,     0,     0,   150,   151,   152,
       0,   419,   154,   155,   156,   157,   158,   159,   160,   161,
     525,   163,   526,   165,   527,   528,   168,   169,   170,   171,
     172,   173,   529,   175,   530,   531,   532,   179,   180,   533,
     534,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,     0,   196,   197,   198,     0,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,     0,   247,     0,
     248,   535,   250,   251,   252,   253,   254,     1,     2,     0,
       0,     0,     3,     0,     0,     0,     4,     5,     6,     7,
       8,     9,    10,     0,     0,     0,    13,     0,     0,   416,
     417,     0,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,   498,    27,   500,   418,    30,   501,    32,    33,
      34,     0,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,   503,     0,    48,    49,    50,   505,
     506,    53,   507,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
       0,    72,    73,    74,    75,    76,     0,    77,    78,    79,
       0,     0,    80,    81,     0,     0,     0,    82,    83,   512,
      85,    86,    87,    88,    89,   565,    91,    92,     0,     0,
       0,    93,     0,    94,    95,    96,    97,     0,    98,     0,
       0,     0,   515,     0,   101,   102,   103,     0,     0,     0,
       0,     0,     0,   104,   105,   106,   107,     0,   109,   110,
     566,   112,     0,   113,   114,     0,   116,   117,     0,     0,
       0,   118,   119,   120,   121,   122,   123,   124,   125,     0,
     126,     0,     0,     0,     0,     0,   129,   130,   131,     0,
       0,     0,   132,     0,   133,   134,     0,     0,     0,     0,
     137,     0,   138,     0,   139,     0,   141,     0,   143,   144,
     145,   146,   147,   148,   149,     0,     0,   150,   151,   152,
       0,   419,   154,   155,   156,   157,   158,   159,   160,   161,
     525,   163,   526,   165,   527,   528,   168,   169,   170,   171,
     172,   173,   529,   175,   530,   531,   532,   179,   180,   533,
     534,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,     0,   196,   197,   198,     0,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,     0,   247,     0,
     248,   535,   250,   251,   252,   253,   254,     1,     2,     0,
       0,     0,     3,     0,     0,     0,     4,     0,     0,     0,
       0,     9,    10,     0,     0,     0,     0,     0,     0,   416,
     417,     0,    16,    17,    18,   495,    20,    21,    22,   496,
      24,   497,   498,   499,   500,   418,    30,   501,    32,    33,
      34,     0,    35,    36,    37,    38,   502,    40,    41,    42,
      43,    44,    45,    46,   503,     0,    48,   504,    50,   505,
     506,    53,   507,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,   508,   509,    71,
       0,    72,    73,    74,   510,     0,     0,    77,    78,    79,
       0,     0,   511,    81,     0,     0,     0,     0,    83,   512,
      85,   513,   514,    88,    89,     0,     0,     0,     0,     0,
       0,     0,     0,    94,    95,    96,    97,     0,    98,     0,
       0,     0,   515,   100,   101,   516,   517,     0,     0,     0,
       0,     0,     0,   104,   105,   106,     0,   108,   109,   110,
       0,     0,     0,     0,     0,     0,   116,   518,     0,     0,
       0,   118,   119,   120,   121,   519,   123,   124,   520,     0,
       0,     0,     0,     0,     0,     0,   521,   522,   131,     0,
       0,     0,   132,     0,   133,   523,     0,     0,     0,     0,
     137,     0,   138,     0,   139,   140,   141,   142,   524,   144,
     145,   146,   147,   148,   149,     0,     0,   150,   151,     0,
       0,   419,   154,   155,   156,   157,   158,   159,   160,   161,
     525,   163,   526,   165,   527,   528,   168,   169,   170,   171,
     172,   173,   529,   175,   530,   531,   532,   179,   180,   533,
     534,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,     0,   196,   197,   198,     0,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,     0,     0,     0,     0,
     248,   535,   250,   251,   252,   253,   254,     1,     2,     0,
       0,     0,     3,     0,     0,     0,     4,     0,     0,     0,
       0,     9,    10,     0,     0,     0,     0,     0,     0,   416,
     417,     0,    16,    17,    18,   543,    20,    21,    22,   496,
     544,   545,   498,   499,   500,   418,    30,   501,    32,   546,
      34,     0,    35,    36,    37,    38,   547,    40,   548,   549,
      43,    44,    45,    46,   503,     0,    48,   550,    50,   505,
     506,    53,   507,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,   508,   509,    71,
       0,    72,    73,    74,   551,     0,     0,    77,    78,    79,
       0,     0,   511,    81,     0,     0,     0,     0,    83,   512,
      85,   513,   514,    88,    89,     0,     0,     0,     0,     0,
       0,     0,     0,    94,    95,    96,    97,     0,    98,     0,
       0,     0,   515,   100,   101,   516,   517,     0,     0,     0,
       0,     0,     0,   104,   105,   106,     0,   108,   109,   110,
       0,     0,     0,     0,     0,     0,   116,   518,     0,     0,
       0,   118,   119,   120,   121,   519,   123,   124,   520,     0,
       0,     0,     0,     0,     0,     0,   521,   522,   131,     0,
       0,     0,   132,     0,   133,   523,     0,     0,     0,     0,
     137,     0,   138,     0,   139,   140,   141,   142,   524,   144,
     145,   146,   147,   148,   149,     0,     0,   150,   151,     0,
       0,   419,   154,   155,   156,   157,   158,   159,   160,   161,
     525,   552,   526,   165,   527,   528,   168,   169,   170,   171,
     172,   173,   529,   175,   530,   531,   532,   179,   180,   533,
     534,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,     0,   196,   197,   198,     0,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,     0,     0,     3,     0,
     248,   535,   250,   251,   252,   253,   254,     9,    10,     0,
       0,     0,     0,     0,     0,   416,   417,     0,    16,    17,
      18,   495,    20,    21,    22,   496,    24,   497,   498,  1152,
     500,   418,    30,   501,    32,    33,    34,     0,    35,    36,
      37,    38,   502,    40,    41,    42,    43,    44,    45,    46,
     503,     0,    48,   504,    50,   505,   506,    53,   507,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,   508,   509,    71,     0,    72,    73,    74,
     510,     0,     0,    77,    78,    79,     0,     0,   511,    81,
       0,     0,     0,     0,    83,   512,    85,   513,   514,    88,
      89,     0,     0,     0,     0,     0,     0,     0,     0,    94,
      95,    96,    97,     0,    98,     0,     0,     0,   515,   100,
     101,   516,   517,     0,     0,     0,     0,     0,     0,   104,
     105,   106,     0,   108,   109,  1153,     0,     0,     0,  1154,
       0,     0,   116,   518,     0,     0,     0,   118,   119,   120,
     121,   519,   123,   124,   520,     0,     0,     0,     0,     0,
       0,     0,   521,   522,   131,     0,     0,     0,   132,  1589,
     133,   523,     0,     0,     0,     0,  1590,     0,   138,     0,
     139,   140,   141,   142,   524,   144,   145,   146,   147,   148,
     149,     0,     0,  1155,   151,     0,     0,   419,   154,   155,
     156,   157,   158,   159,   160,   161,   525,   163,   526,   165,
     527,   528,   168,   169,   170,   171,   172,   173,   529,   175,
     530,   531,   532,   179,   180,   533,   534,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
       0,   196,   197,   198,     0,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,     0,     0,     0,     0,   248,   535,   250,  1156,
    1157,  1158,  1159,     3,     0,   579,   580,     0,     0,     0,
       0,     0,     9,    10,     0,     0,     0,     0,     0,     0,
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
       0,     0,     0,   132,     0,   133,   523,     0,     0,     0,
       0,     0,     0,   138,     0,   139,   140,   141,   142,   524,
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
      17,    18,   543,    20,    21,    22,   496,   544,   545,   498,
     499,   500,   418,    30,   501,    32,   546,    34,     0,    35,
      36,    37,    38,   547,    40,   548,   549,    43,    44,    45,
      46,   503,     0,    48,   550,    50,   505,   506,    53,   507,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,   508,   509,    71,     0,    72,    73,
      74,   551,     0,     0,    77,    78,    79,     0,     0,   511,
      81,     0,     0,     0,     0,    83,   512,    85,   513,   514,
      88,    89,     0,     0,     0,     0,     0,     0,     0,     0,
      94,    95,    96,    97,     0,    98,     0,     0,     0,   515,
     100,   101,   516,   517,     0,     0,     0,     0,     0,     0,
     104,   105,   106,     0,   108,   109,   110,     0,     0,     0,
       0,     0,     0,   116,   518,     0,     0,     0,   118,   119,
     120,   121,   519,   123,   124,   520,     0,     0,     0,     0,
       0,     0,     0,   521,   522,   131,     0,     0,     0,   132,
     763,   133,   523,     0,     0,     0,     0,   764,     0,   138,
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
     251,   252,   253,   254,     9,    10,     0,     0,     0,   794,
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
     522,   131,     0,     0,     0,   132,   795,   133,   523,     0,
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
       0,   132,   812,   133,   523,     0,     0,     0,     0,   813,
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
       0,     0,     0,     0,   416,   417,     0,    16,    17,    18,
     495,    20,    21,    22,   496,    24,   497,   498,  1152,   500,
     418,    30,   501,    32,    33,    34,     0,    35,    36,    37,
      38,   502,    40,    41,    42,    43,    44,    45,    46,   503,
       0,    48,   504,    50,   505,   506,    53,   507,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,   508,   509,    71,     0,    72,    73,    74,   510,
       0,     0,    77,    78,    79,     0,     0,   511,    81,     0,
       0,     0,     0,    83,   512,    85,   513,   514,    88,    89,
    1506,     0,     0,     0,     0,     0,     0,     0,    94,    95,
      96,    97,     0,    98,     0,     0,     0,   515,   100,   101,
     516,   517,     0,     0,     0,     0,     0,     0,   104,   105,
     106,     0,   108,   109,  1153,     0,     0,     0,  1154,     0,
       0,   116,   518,     0,     0,     0,   118,   119,   120,   121,
     519,   123,   124,   520,     0,     0,     0,     0,     0,     0,
       0,   521,   522,   131,     0,     0,     0,   132,     0,   133,
     523,     0,     0,     0,     0,     0,     0,   138,     0,   139,
     140,   141,   142,   524,   144,   145,   146,   147,   148,   149,
       0,     0,  1155,   151,     0,     0,   419,   154,   155,   156,
     157,   158,   159,   160,   161,   525,   163,   526,   165,   527,
     528,   168,   169,   170,   171,   172,   173,   529,   175,   530,
     531,   532,   179,   180,   533,   534,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,     0,
     196,   197,   198,     0,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,     0,     0,     3,     0,   248,   535,   250,  1156,  1157,
    1158,  1159,     9,    10,     0,     0,     0,     0,     0,     0,
     416,   417,     0,    16,    17,    18,   495,    20,    21,    22,
     496,    24,   497,   498,  1152,   500,   418,    30,   501,    32,
      33,    34,     0,    35,    36,    37,    38,   502,    40,    41,
      42,    43,    44,    45,    46,   503,     0,    48,   504,    50,
     505,   506,    53,   507,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,   508,   509,
      71,     0,    72,    73,    74,   510,     0,     0,    77,    78,
      79,     0,     0,   511,    81,     0,     0,     0,     0,    83,
     512,    85,   513,   514,    88,    89,  1647,     0,     0,     0,
       0,     0,     0,     0,    94,    95,    96,    97,     0,    98,
       0,     0,     0,   515,   100,   101,   516,   517,     0,     0,
       0,     0,     0,     0,   104,   105,   106,     0,   108,   109,
    1153,     0,     0,     0,  1154,     0,     0,   116,   518,     0,
       0,     0,   118,   119,   120,   121,   519,   123,   124,   520,
       0,     0,     0,     0,     0,     0,     0,   521,   522,   131,
       0,     0,     0,   132,     0,   133,   523,     0,     0,     0,
       0,     0,     0,   138,     0,   139,   140,   141,   142,   524,
     144,   145,   146,   147,   148,   149,     0,     0,  1155,   151,
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
       0,   248,   535,   250,  1156,  1157,  1158,  1159,     9,    10,
       0,     0,     0,     0,     0,     0,   416,   417,     0,    16,
      17,    18,   495,    20,    21,    22,   496,    24,   497,   498,
    1152,   500,   418,    30,   501,    32,    33,    34,     0,    35,
      36,    37,    38,   502,    40,    41,    42,    43,    44,    45,
      46,   503,     0,    48,   504,    50,   505,   506,    53,   507,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,   508,   509,    71,     0,    72,    73,
      74,   510,     0,     0,    77,    78,    79,     0,     0,   511,
      81,     0,     0,     0,     0,    83,   512,    85,   513,   514,
      88,    89,  1651,     0,     0,     0,     0,     0,     0,     0,
      94,    95,    96,    97,     0,    98,     0,     0,     0,   515,
     100,   101,   516,   517,     0,     0,     0,     0,     0,     0,
     104,   105,   106,     0,   108,   109,  1153,     0,     0,     0,
    1154,     0,     0,   116,   518,     0,     0,     0,   118,   119,
     120,   121,   519,   123,   124,   520,     0,     0,     0,     0,
       0,     0,     0,   521,   522,   131,     0,     0,     0,   132,
       0,   133,   523,     0,     0,     0,     0,     0,     0,   138,
       0,   139,   140,   141,   142,   524,   144,   145,   146,   147,
     148,   149,     0,     0,  1155,   151,     0,     0,   419,   154,
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
    1156,  1157,  1158,  1159,     9,    10,     0,     0,     0,     0,
       0,     0,   416,   417,     0,    16,    17,    18,   495,    20,
      21,    22,   496,    24,   497,   498,  1152,   500,   418,    30,
     501,    32,    33,    34,     0,    35,    36,    37,    38,   502,
      40,    41,    42,    43,    44,    45,    46,   503,     0,    48,
     504,    50,   505,   506,    53,   507,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
     508,   509,    71,     0,    72,    73,    74,   510,     0,     0,
      77,    78,    79,     0,     0,   511,    81,     0,     0,     0,
       0,    83,   512,    85,   513,   514,    88,    89,     0,     0,
       0,     0,     0,     0,     0,     0,    94,    95,    96,    97,
       0,    98,     0,     0,     0,   515,   100,   101,   516,   517,
       0,     0,     0,     0,     0,     0,   104,   105,   106,     0,
     108,   109,  1153,     0,     0,     0,  1154,     0,     0,   116,
     518,     0,     0,     0,   118,   119,   120,   121,   519,   123,
     124,   520,     0,     0,     0,     0,     0,     0,     0,   521,
     522,   131,     0,     0,     0,   132,     0,   133,   523,     0,
       0,     0,     0,     0,     0,   138,     0,   139,   140,   141,
     142,   524,   144,   145,   146,   147,   148,   149,     0,     0,
    1155,   151,     0,     0,   419,   154,   155,   156,   157,   158,
     159,   160,   161,   525,   163,   526,   165,   527,   528,   168,
     169,   170,   171,   172,   173,   529,   175,   530,   531,   532,
     179,   180,   533,   534,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,     0,   196,   197,
     198,     0,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,     0,
       0,     3,     0,   248,   535,   250,  1156,  1157,  1158,  1159,
       9,    10,     0,     0,     0,     0,     0,     0,   416,   417,
       0,    16,    17,    18,   495,    20,    21,    22,   496,    24,
     497,   498,  1152,   500,   418,    30,   501,    32,    33,    34,
       0,    35,    36,    37,    38,   502,    40,    41,    42,    43,
      44,    45,    46,   503,     0,    48,   504,    50,   505,   506,
      53,   507,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,   508,   509,    71,     0,
      72,    73,    74,   510,     0,     0,    77,    78,    79,     0,
       0,   511,    81,     0,     0,     0,     0,    83,   512,    85,
     513,   514,    88,    89,     0,     0,     0,     0,     0,     0,
       0,     0,    94,    95,    96,    97,     0,    98,     0,     0,
       0,   515,   100,   101,   516,   517,     0,     0,     0,     0,
       0,     0,   104,   105,   106,     0,   108,   109,  1153,     0,
       0,     0,  1154,     0,     0,   116,   518,     0,     0,     0,
     118,   119,   120,   121,   519,   123,   124,   520,     0,     0,
       0,     0,     0,     0,     0,   521,   522,   131,     0,     0,
       0,   132,     0,   133,   523,     0,     0,     0,     0,     0,
       0,   138,     0,   139,   140,   141,   142,   524,   144,   145,
     146,   147,   148,   149,     0,     0,   150,   151,     0,     0,
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
     535,   250,  1156,  1157,  1158,  1159,     9,    10,     0,     0,
       0,     0,     0,     0,   416,   417,     0,    16,    17,    18,
     543,    20,    21,    22,   496,   544,   545,   498,   499,   500,
     418,    30,   501,    32,   546,    34,     0,    35,    36,    37,
      38,   547,    40,   548,   549,    43,    44,    45,    46,   503,
       0,    48,   550,    50,   505,   506,    53,   507,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,   508,   509,    71,     0,    72,    73,    74,   551,
       0,     0,    77,    78,    79,     0,     0,   511,    81,     0,
       0,     0,     0,    83,   512,    85,   513,   514,    88,    89,
    1247,     0,     0,     0,     0,     0,     0,     0,    94,    95,
      96,    97,     0,    98,     0,     0,     0,   515,   100,   101,
     516,   517,     0,     0,     0,     0,     0,     0,   104,   105,
     106,     0,   108,   109,   110,     0,     0,     0,     0,     0,
       0,   116,   518,     0,     0,     0,   118,   119,   120,   121,
     519,   123,   124,   520,     0,     0,     0,     0,     0,     0,
       0,   521,   522,   131,     0,     0,     0,   132,     0,   133,
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
       0,     0,     0,   132,     0,   133,   523,     0,     0,     0,
       0,     0,     0,   138,     0,   139,   140,   141,   142,   524,
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
     239,   240,   241,   242,   243,   244,   245,     0,     0,     0,
       0,   248,   535,   250,   251,   252,   253,   254,     5,     6,
       7,     8,     9,    10,     0,     0,     0,    13,     0,     0,
     416,   417,     0,    16,    17,    18,   845,    20,    21,    22,
      23,     0,   846,   498,    27,     0,   418,    30,   501,    32,
       0,    34,     0,    35,    36,    37,    38,   847,    40,     0,
       0,    43,    44,    45,    46,   503,     0,    48,   848,    50,
       0,     0,    53,   507,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,   508,   509,
      71,     0,    72,    73,    74,   849,     0,     0,    77,    78,
      79,     0,     0,   511,    81,     0,     0,     0,    82,    83,
     512,    85,   513,   514,    88,    89,   565,    91,     0,     0,
       0,     0,    93,     0,    94,    95,    96,    97,     0,    98,
       0,     0,     0,   515,   100,   101,   516,   517,     0,     0,
       0,     0,     0,     0,   104,   105,   106,   107,   108,   109,
       0,   566,   112,     0,   113,   114,     0,   116,   117,     0,
       0,     0,   118,   119,   120,   121,   122,   123,   124,   520,
       0,   126,     0,     0,     0,     0,     0,   521,   522,   131,
       0,     0,     0,   132,     0,   133,   523,     0,     0,     0,
       0,     0,     0,   138,     0,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,     0,     0,     0,   151,
     152,     0,   419,   154,   155,   156,   157,   158,   159,   160,
     161,   525,     0,   526,   165,   527,   528,   168,   169,   170,
     171,   172,   173,   529,   175,   530,   531,   532,   179,   180,
       0,   534,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,     0,   196,   197,   198,     0,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,     0,   247,
       0,   248,   535,   250,   251,   252,   253,   254,     9,    10,
       0,     0,     0,     0,     0,     0,   416,   417,     0,    16,
      17,    18,     0,    20,    21,    22,   496,     0,     0,   498,
     499,     0,   418,    30,   501,    32,     0,    34,     0,    35,
      36,    37,    38,     0,    40,     0,     0,    43,    44,    45,
      46,   503,     0,    48,     0,    50,     0,     0,    53,   507,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,   508,   509,    71,     0,    72,    73,
      74,     0,     0,     0,    77,    78,    79,     0,     0,   511,
      81,     0,     0,     0,     0,    83,   512,    85,   513,   514,
      88,    89,     0,     0,     0,     0,     0,     0,     0,     0,
      94,    95,    96,    97,     0,    98,     0,     0,     0,   515,
     100,   101,   516,   517,     0,     0,     0,     0,     0,     0,
     104,   105,   106,     0,   108,   109,     0,     0,     0,     0,
       0,     0,     0,   116,   518,     0,     0,     0,   118,   119,
     120,   121,   519,   123,   124,   520,     0,     0,     0,     0,
       0,     0,     0,   521,   522,   131,     0,     0,     0,   132,
       0,   133,   523,     0,     0,     0,     0,     0,     0,   138,
       0,   139,   140,   141,   142,   524,   144,   145,   146,   147,
     148,   149,     0,     0,     0,   151,     0,     0,   419,   154,
     155,   156,   157,   158,   159,   160,   161,   525,     0,   526,
     165,   527,   528,   168,   169,   170,   171,   172,   173,   529,
     175,   530,   531,   532,   179,   180,     0,   534,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,     0,   196,   197,   198,     0,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,     0,     0,     0,     0,   248,   535,   250,
     251,   252,   253,   254
  };

  /* YYCHECK.  */
  const short int
  xquery_parser::yycheck_[] =
  {
         0,     5,     6,     7,   182,     5,     6,     7,     8,    14,
     427,   428,   314,   832,   343,   692,   676,   626,   627,   788,
     768,   294,   262,     0,  1063,  1300,   768,   136,     5,     6,
       7,     8,   801,   677,   678,   679,   680,   429,   263,  1317,
     929,   930,   592,   916,  1047,     1,   815,   597,   870,     1,
    1087,  1381,  1382,   278,   255,   256,    76,  1138,  1509,    27,
      28,  1512,   624,   625,   626,   627,   954,   624,   625,  1004,
     725,  1022,     5,     6,     7,     8,   119,   469,   470,    47,
      95,  1330,    39,  1416,     1,    56,    36,    44,    45,    57,
     285,  1611,    30,    30,   108,   122,    53,    95,    45,     1,
       1,     1,    36,    60,   148,    62,    63,    75,     1,     1,
       1,   111,    80,   148,    71,   655,    63,   657,   658,     1,
     660,   108,   662,     1,   143,     5,     6,     7,     8,     1,
     670,   671,     1,   108,   111,  1024,   108,  1677,   108,   132,
      95,    98,    27,    28,   112,   113,   114,    97,  1037,   422,
     108,    95,   108,   426,   119,     1,   108,    27,    28,   970,
     225,    95,    47,    97,     0,     1,   154,    37,    38,     1,
      40,    41,   108,   101,   157,    31,   114,    47,   111,    33,
      95,    55,   155,    57,   157,     1,   114,    57,    58,   177,
      75,    97,   107,     1,   138,    49,     8,   190,   148,   143,
     155,    33,   157,   218,   219,    75,   233,   976,   108,    30,
      80,  1751,   187,   155,   148,   157,   188,   187,   233,   233,
     218,   219,  1552,   161,   161,     1,   108,   101,   113,   273,
     273,   111,   190,   929,   930,   233,   108,   346,   273,   108,
     187,  1761,   112,   113,   114,     1,   217,  1522,   235,   314,
       9,    10,   188,   448,   273,   255,   256,     1,  1297,   259,
     225,  1030,   108,   169,  1083,  1138,  1139,  1036,   225,   571,
     879,   880,   108,   190,   970,  1726,  1525,  1610,   255,   256,
    1283,  1029,   259,   254,  1321,  1027,   559,  1029,   190,   190,
     111,   161,   108,  1330,   294,   237,  1247,   190,   190,   190,
     108,   956,  1190,  1238,   125,   187,     1,  1049,  1004,     1,
     157,  1392,   190,     1,     1,   187,    97,   294,   187,   287,
     877,   878,  1773,   273,  1775,     1,    97,   295,  1024,   150,
      94,   351,   108,   154,   354,   303,   157,    76,   184,   273,
       1,  1037,   307,  1154,   736,   104,   252,   253,   184,   255,
     220,    90,   108,     0,     1,     1,   177,   313,   214,   311,
     317,   318,   319,   175,   108,   124,   272,   126,    52,   131,
     643,   187,   912,    27,    28,   114,   225,   251,   284,   187,
    1710,   230,     1,   119,   624,   625,  1275,   126,   169,   128,
     264,   261,   266,   108,   786,   154,   621,   622,   101,   158,
       1,     1,   287,   277,   278,   279,   631,   281,   101,   283,
     295,   187,   613,   108,   131,   174,   108,   287,     1,   183,
     108,   108,   422,   108,   101,   295,   426,    37,    38,   185,
      40,    41,   108,   303,  1764,   197,   195,   225,   259,   227,
       1,   146,   108,   187,   154,   422,   130,   108,    58,   426,
     186,     1,   157,   453,   213,   455,     1,     1,  1154,   113,
     119,   108,   108,   112,   113,   314,   137,   108,  1237,   184,
    1748,   252,   253,   108,   255,   119,   453,   159,   455,   159,
     197,   262,   482,   186,   137,   256,   257,   487,  1525,   108,
     138,   272,   187,   186,   176,   187,   176,   185,   151,   916,
     187,  1249,   187,   284,   114,   482,   154,   108,   108,   186,
     487,   187,    90,  1122,  1123,  1124,  1258,   199,  1793,  1392,
     453,   187,   455,   184,    30,   108,   314,   186,  1401,    45,
     201,    47,   949,    95,    77,  1424,   114,   184,   184,  1412,
       5,  1363,  1238,   187,     9,  1367,   187,   108,   126,   482,
     128,   161,   187,   159,   487,    95,  1233,  1107,   108,   559,
    1122,  1123,  1124,   108,   108,   184,   566,   108,    97,    45,
     176,    47,   161,   453,   108,   455,    30,   108,   182,  1275,
     157,   143,   559,   184,   184,   977,   978,   696,   697,   566,
     982,   107,   196,   108,     1,   868,     3,   246,   247,   154,
     157,   184,   482,  1299,    80,   111,   606,   487,   148,   108,
     220,   154,   351,   613,   619,   354,  1385,     5,   154,   125,
    1012,     9,   895,   184,   624,   625,   626,   627,   157,   606,
    1633,   107,    95,   566,   184,   118,   613,   877,   157,   184,
     184,   177,    97,   643,   150,   294,   187,   624,   625,   626,
     627,   261,   168,   187,     9,   210,   187,   111,   883,   124,
      67,   126,   887,   269,   147,    72,   643,     9,   157,   134,
     276,   125,   187,   606,    29,     9,    10,   160,   221,   222,
     286,   154,    25,    95,    97,   148,   566,    29,   187,   154,
     217,    34,   168,   148,   433,   434,   150,   225,   437,   227,
     154,   114,   441,   157,  1523,   444,   445,  1580,  1747,  1528,
      54,   194,   119,   452,    97,    59,    97,   967,    61,   458,
     459,  1138,  1139,   177,   463,  1473,    42,   254,  1424,   979,
      46,   143,   471,   114,    78,    51,   124,   210,   126,   478,
     479,   480,   481,  1403,   157,   159,   134,   486,   145,   263,
      95,   269,   628,    97,    70,   494,   632,  1646,   276,   186,
     274,  1370,   176,    42,   186,   148,   154,    46,   286,   124,
     104,   126,    51,   422,   778,   119,   157,   426,   778,   176,
     135,  1458,   124,   210,   126,   199,   314,   157,   210,     1,
     124,    70,   126,   135,  1018,   157,  1020,   194,   143,   154,
     539,   778,     9,    10,  1693,   119,  1695,   157,   457,   809,
     810,  1140,   154,  1509,    54,   554,  1512,   169,   467,    59,
     154,    33,   107,   186,   158,   186,   565,   186,   477,   157,
    1738,  1739,   809,   810,   268,   484,   485,    49,  1657,  1112,
     174,   275,  1661,   128,   493,   778,  1070,   210,  1072,   210,
     202,   210,   168,   592,    97,   171,   434,    97,   597,   437,
     138,   195,   601,   441,   123,   143,   444,   445,   868,  1758,
     186,   114,  1780,   182,   452,   123,   809,   810,  1786,   213,
     458,   459,   247,   248,   889,   463,  1278,   196,  1113,   168,
     186,   868,   171,   471,  1119,   895,   212,   104,   778,   166,
     478,   479,   480,   481,   201,   270,   154,   186,   486,   157,
     559,  1571,  1572,   210,   210,   182,   494,   124,   895,   126,
    1564,   101,   101,  1742,     9,    10,   575,   576,   149,   809,
     810,    96,   149,   212,   114,   114,  1613,   586,  1116,   138,
     138,  1710,   107,   263,   165,   143,   101,   154,   165,    42,
    1646,   158,   117,    46,   274,   154,   605,   606,    51,   114,
     101,   539,   299,   128,    54,   101,   232,   174,   234,    59,
     232,   308,   234,   114,   123,  1392,   554,    70,   114,   699,
     154,   123,   702,   157,  1401,  1377,   706,   565,   195,   119,
     729,   191,   192,   732,  1386,  1412,   123,  1693,   154,  1695,
     154,   157,   154,   157,  1277,   157,   213,   746,   277,   278,
     279,   750,   751,   123,   283,   350,   129,   130,   353,   104,
     119,  1681,  1682,   601,   221,   222,   223,   129,   130,   123,
    1726,   674,   675,   772,   123,   774,   681,   682,  1715,   124,
     154,   126,   154,   782,   693,   123,   785,   683,   684,   698,
     789,  1231,  1232,  1601,  1602,   704,   123,   123,   123,   154,
    1362,   157,  1758,   216,   119,  1065,   241,   154,   241,   154,
     242,   157,   314,   158,     0,   168,   167,  1773,   171,  1775,
      93,   190,   249,   100,    50,  1762,   102,   193,  1065,   174,
      30,   103,   831,   186,  1754,   200,   155,   157,  1490,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,   184,
     195,   184,  1112,   184,   184,    47,  1121,   153,   119,   212,
     246,   304,  1122,  1123,  1124,   187,   284,   284,   213,   119,
     154,   870,  1065,     1,   119,  1112,   143,   108,   187,   187,
     154,   143,   157,   154,   184,  1122,  1123,  1124,   157,   157,
     122,   157,   157,   157,   732,    35,   154,  1834,   157,  1836,
     899,   157,    17,  1580,   214,    30,   245,   231,   746,  1846,
     190,   190,   750,   751,   823,   824,   825,   230,   827,     3,
     119,  1359,   168,   170,    71,  1065,   170,   231,    95,    95,
     929,   930,   931,   932,   772,    95,   774,   150,   187,   108,
     108,    30,   161,   161,   782,   128,   133,   785,   246,    95,
     143,   789,   133,   187,   119,   299,   184,   184,   187,   868,
     108,    95,    97,    45,    97,   187,   187,   187,   184,  1502,
     187,   970,   154,   184,   154,   154,   154,  1241,   154,   154,
     237,  1241,    95,   133,   225,   984,   143,   190,   231,    33,
     133,   141,   142,   831,   144,   233,   170,    95,   143,    30,
     286,    95,   152,   227,  1241,   299,   156,   128,   158,   119,
    1009,   148,  1545,   163,   254,   154,   119,  1277,    95,  1018,
     184,  1020,   133,  1022,  1288,  1024,   198,   133,  1288,   179,
     161,    97,   154,   119,   148,   184,   101,   101,  1037,   143,
    1277,   122,   184,  1307,    35,   154,   190,  1307,  1241,   154,
      30,  1288,   119,   203,   204,   205,   206,   207,   208,    80,
     245,   899,   108,   108,   107,   260,   267,  1327,   258,   157,
    1307,  1070,   157,  1072,  1334,   285,   145,   157,   157,   111,
      30,   157,   157,   157,   286,    30,    30,   187,   190,   287,
    1327,   929,   930,   931,   932,  1288,   187,  1334,  1631,   306,
     227,  1241,   128,   145,   187,   119,  1366,   148,  1107,  1642,
    1643,   148,  1645,   148,  1307,   187,   119,    78,   108,   143,
    1653,   184,   101,   133,     7,   187,   187,   198,    97,  1366,
     190,   186,   970,  1132,  1327,   157,   233,   233,   233,   157,
     233,  1334,   157,   154,   107,   237,   984,   187,  1288,   250,
     148,   250,   282,    79,   286,  1154,    30,   187,   187,   187,
     187,    30,   187,   271,   187,   108,   170,  1307,   187,   127,
     257,  1009,   184,  1366,   148,   148,   127,    97,   184,   186,
    1018,   186,  1020,   143,  1022,   186,  1024,  1327,   184,   184,
     184,   184,   316,    95,  1334,   154,    30,    97,   187,  1037,
     187,   148,  1735,   170,    54,    95,    95,   280,    30,   287,
     108,   197,   265,   108,   119,   119,   225,    95,   186,    95,
     197,   197,   119,   198,   186,   225,    94,   183,  1137,   186,
     735,   197,  1070,   119,  1072,   305,   293,   305,   119,   287,
     225,  1774,  1502,   259,   199,   262,   305,   119,  1247,   971,
     306,   259,  1251,  1038,   306,   306,  1238,   428,  1193,  1792,
     448,  1715,   871,  1762,  1035,  1502,   463,  1266,   791,  1483,
    1267,  1388,  1128,  1384,  1807,  1289,  1275,  1381,   653,  1294,
    1297,  1302,   673,   654,   554,  1545,   932,   709,   338,  1321,
    1289,   832,  1786,  1780,  1132,  1828,  1020,   456,   456,  1192,
    1299,  1353,  1364,  1363,  1837,  1139,  1401,  1412,  1545,  1580,
    1577,  1405,  1148,  1003,  1604,  1215,  1154,  1448,  1402,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1328,
      -1,    -1,   595,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1353,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1363,    -1,    -1,    -1,  1367,    -1,
      -1,  1631,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1642,  1643,    -1,  1645,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1653,  1631,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1642,  1643,    -1,  1645,  1247,
      -1,    -1,    -1,  1251,    -1,    -1,  1653,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1424,    -1,    -1,  1266,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1275,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1289,    -1,    -1,    -1,  1454,    -1,    -1,    -1,    -1,
      -1,  1299,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1735,    -1,    -1,    -1,    -1,
      -1,  1480,  1481,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1328,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1735,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1506,    -1,    -1,
    1509,    -1,    -1,  1512,  1774,  1353,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1524,    -1,    -1,    -1,    -1,
    1529,    -1,  1792,    -1,   566,    -1,    -1,  1774,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1807,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1792,    -1,    -1,   590,   591,
      -1,   593,   594,   595,   596,    -1,   598,    -1,  1828,    -1,
    1807,    -1,   604,    -1,    -1,    -1,    -1,  1837,    -1,    -1,
     612,    -1,    -1,    -1,    -1,    -1,  1424,    -1,    -1,    -1,
      -1,  1828,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1837,    -1,   634,   635,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   643,   644,    -1,    -1,    -1,  1454,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1542,  1543,  1544,    -1,    -1,    -1,    -1,
      -1,    -1,  1480,  1481,    -1,    -1,    -1,  1646,  1647,    -1,
    1649,    -1,  1651,    -1,    -1,    -1,    -1,    -1,    -1,  1658,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1506,    -1,
      -1,  1509,    -1,   705,  1512,    -1,    -1,   709,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1524,    -1,    -1,    -1,
      -1,  1529,    -1,    -1,  1693,    -1,  1695,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1711,    -1,    -1,  1714,   748,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1726,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1737,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   790,  1758,
      -1,    -1,    -1,    -1,    -1,  1674,    -1,  1766,    -1,    -1,
      -1,    -1,  1771,    -1,  1773,    -1,  1775,    -1,    -1,    -1,
      -1,    -1,  1691,    -1,   816,    -1,    -1,    -1,   820,   821,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   829,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1804,    -1,    -1,  1646,  1647,
      -1,  1649,    -1,  1651,    -1,    -1,    -1,    -1,    -1,    -1,
    1658,    -1,    -1,    -1,    -1,  1824,    -1,    -1,    -1,    -1,
    1829,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1841,    -1,    -1,  1844,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1693,    -1,  1695,    -1,    -1,
      -1,    -1,    -1,   895,    -1,    -1,    -1,    -1,    -1,   901,
     902,    -1,    -1,  1711,    -1,    -1,  1714,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1726,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1737,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1758,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1766,    -1,
      -1,    -1,    -1,  1771,    -1,  1773,    -1,  1775,    -1,    -1,
     972,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1804,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1007,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1824,     0,     1,    -1,
       3,  1829,    -1,    -1,  1026,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1841,    -1,    -1,  1844,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1048,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1059,  1060,    42,
      -1,    -1,    -1,    46,    -1,    -1,    -1,    50,    51,    -1,
      -1,    -1,  1074,    56,    -1,  1077,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    67,    -1,    -1,    70,    -1,    72,
      -1,    -1,  1094,  1095,  1096,    -1,  1098,  1099,  1100,  1101,
    1102,  1103,  1104,  1105,  1106,    -1,    -1,  1109,  1110,    -1,
      93,    -1,    95,    96,    97,    -1,  1118,   100,   101,   102,
     103,    -1,    -1,    -1,   107,   108,  1128,    -1,    -1,    -1,
      -1,   114,    -1,    -1,   117,   118,   119,    -1,    -1,   122,
      -1,    -1,    -1,    -1,   127,   128,    -1,    -1,    -1,    -1,
     133,    -1,    -1,    -1,   137,    -1,    -1,    -1,   141,   142,
      -1,   144,    -1,   146,   147,    -1,    -1,    -1,   151,   152,
      -1,    -1,   155,   156,   157,   158,   159,   160,  1180,    -1,
     163,    -1,    -1,    -1,   167,   168,    -1,    -1,   171,    -1,
      -1,    -1,    -1,   176,    -1,    -1,   179,    -1,    -1,    -1,
      -1,   184,   185,   186,   187,   188,    -1,   190,   191,   192,
     193,   194,    -1,    -1,    -1,    -1,   199,   200,   201,    -1,
     203,   204,   205,   206,   207,   208,    -1,   210,    -1,   212,
      -1,    -1,    -1,    -1,   217,   218,   219,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     233,  1253,   235,  1255,   237,  1257,    -1,    -1,  1260,    -1,
      -1,    -1,    -1,  1265,    -1,    -1,   249,    -1,    -1,    -1,
      -1,   254,    -1,    -1,    -1,  1277,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1286,    -1,    -1,    -1,    -1,    -1,
    1292,  1293,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1311,
      -1,    -1,  1314,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   311,    -1,
     313,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1384,    -1,    -1,    -1,  1388,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1467,    -1,    -1,    -1,  1471,
      -1,    -1,    -1,  1475,    -1,  1477,    -1,  1479,    -1,    -1,
      -1,    -1,    -1,  1485,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1493,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1501,
    1502,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1521,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1533,  1534,  1535,  1536,    -1,  1538,  1539,    -1,  1541,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1556,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1619,    -1,  1621,
      -1,    -1,  1624,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1632,    -1,    -1,    -1,    -1,  1637,  1638,    -1,    -1,    -1,
      -1,    -1,    -1,  1645,    -1,    -1,    -1,    -1,  1650,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1667,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1678,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1718,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1731,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1774,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1802,    -1,    -1,    -1,    -1,  1807,    -1,    -1,    -1,    -1,
    1812,     0,     1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    11,    12,    -1,  1827,    -1,    16,    -1,  1831,
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
     309,   310,    -1,   312,    -1,   314,   315,   316,   317,   318,
     319,   320,     0,     1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    11,    12,    -1,    -1,    -1,    16,    -1,
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
     118,   119,   120,   121,    -1,    -1,    -1,   125,    -1,   127,
     128,   129,   130,    -1,   132,    -1,    -1,    -1,   136,   137,
     138,   139,   140,    -1,    -1,    -1,    -1,    -1,    -1,   147,
     148,   149,   150,   151,   152,   153,   154,   155,    -1,   157,
     158,   159,   160,   161,    -1,    -1,    -1,   165,   166,   167,
     168,   169,   170,   171,   172,    -1,   174,    -1,   176,   177,
      -1,    -1,   180,   181,   182,    -1,    -1,    -1,   186,    -1,
     188,   189,    -1,   191,   192,    -1,   194,    -1,   196,    -1,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,    -1,    -1,   211,   212,   213,    -1,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
      -1,   259,   260,   261,    -1,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,     1,   312,    -1,   314,   315,   316,   317,
     318,   319,   320,    11,    12,    -1,    -1,    -1,    16,    -1,
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
     118,   119,   120,   121,    -1,    -1,    -1,   125,    -1,   127,
     128,   129,   130,    -1,   132,    -1,    -1,    -1,   136,   137,
     138,   139,   140,    -1,    -1,    -1,    -1,    -1,    -1,   147,
     148,   149,   150,   151,   152,   153,   154,   155,    -1,   157,
     158,   159,   160,   161,    -1,    -1,    -1,   165,   166,   167,
     168,   169,   170,   171,   172,    -1,   174,    -1,   176,   177,
      -1,    -1,   180,   181,   182,    -1,    -1,    -1,   186,    -1,
     188,   189,    -1,   191,   192,    -1,   194,    -1,   196,    -1,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,    -1,    -1,   211,   212,   213,    -1,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
      -1,   259,   260,   261,    -1,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,     1,   312,    -1,   314,   315,   316,   317,
     318,   319,   320,    11,    12,    -1,    -1,    -1,    16,    -1,
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
     118,   119,   120,   121,    -1,    -1,    -1,   125,    -1,   127,
     128,   129,   130,    -1,   132,    -1,    -1,    -1,   136,   137,
     138,   139,   140,    -1,    -1,    -1,    -1,    -1,    -1,   147,
     148,   149,   150,   151,   152,   153,   154,   155,    -1,   157,
     158,   159,   160,   161,    -1,    -1,    -1,   165,   166,   167,
     168,   169,   170,   171,   172,    -1,   174,    -1,   176,   177,
      -1,    -1,   180,   181,   182,    -1,    -1,    -1,   186,    -1,
     188,   189,    -1,   191,   192,    -1,   194,    -1,   196,    -1,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,    -1,    -1,   211,   212,   213,    -1,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
      -1,   259,   260,   261,    -1,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,    -1,   312,    -1,   314,   315,   316,   317,
     318,   319,   320,    11,    12,    -1,    -1,    -1,    16,    -1,
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
     118,   119,   120,   121,    -1,    -1,    -1,   125,    -1,   127,
     128,   129,   130,    -1,   132,    -1,    -1,    -1,   136,   137,
     138,   139,   140,    -1,    -1,    -1,    -1,    -1,    -1,   147,
     148,   149,   150,   151,   152,   153,   154,   155,    -1,   157,
     158,   159,   160,   161,    -1,    -1,    -1,   165,   166,   167,
     168,   169,   170,   171,   172,    -1,   174,    -1,   176,   177,
      -1,    -1,   180,   181,   182,    -1,    -1,    -1,   186,    -1,
     188,   189,    -1,   191,   192,    -1,   194,    -1,   196,    -1,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,    -1,    -1,   211,   212,   213,    -1,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
      -1,   259,   260,   261,    -1,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,    -1,   312,    -1,   314,   315,   316,   317,
     318,   319,   320,   321,   322,    11,    12,    -1,    -1,    -1,
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
     316,   317,   318,   319,   320,    -1,   322,    11,    12,    -1,
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
     184,    -1,   186,    -1,   188,   189,    -1,   191,   192,    -1,
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
     314,   315,   316,   317,   318,   319,   320,    11,    12,    -1,
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
     184,    -1,   186,    -1,   188,   189,    -1,   191,   192,    -1,
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
     314,   315,   316,   317,   318,   319,   320,    11,    12,    -1,
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
     184,    -1,   186,    -1,   188,   189,    -1,   191,   192,    -1,
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
     314,   315,   316,   317,   318,   319,   320,    11,    12,    -1,
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
     314,   315,   316,   317,   318,   319,   320,    11,    12,    -1,
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
     314,   315,   316,   317,   318,   319,   320,    11,    12,    -1,
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
     314,   315,   316,   317,   318,   319,   320,    11,    12,    -1,
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
     314,   315,   316,   317,   318,   319,   320,    11,    12,    -1,
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
     314,   315,   316,   317,   318,   319,   320,    11,    12,    -1,
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
     114,   115,   116,   117,   118,   119,   120,   121,    -1,    -1,
      -1,   125,    -1,   127,   128,   129,   130,    -1,   132,    -1,
      -1,    -1,   136,   137,   138,   139,   140,    -1,    -1,    -1,
      -1,   145,    -1,   147,   148,   149,   150,   151,   152,   153,
     154,   155,    -1,   157,   158,   159,   160,   161,    -1,    -1,
      -1,   165,   166,   167,   168,   169,   170,   171,   172,    -1,
     174,    -1,   176,   177,    -1,    -1,   180,   181,   182,    -1,
      -1,    -1,   186,   187,   188,   189,    -1,   191,   192,    -1,
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
     314,   315,   316,   317,   318,   319,   320,    11,    12,    -1,
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
     114,   115,   116,   117,   118,   119,   120,   121,    -1,    -1,
      -1,   125,    -1,   127,   128,   129,   130,    -1,   132,    -1,
      -1,    -1,   136,   137,   138,   139,   140,    -1,    -1,    -1,
      -1,   145,    -1,   147,   148,   149,   150,   151,   152,   153,
     154,   155,    -1,   157,   158,   159,   160,   161,    -1,    -1,
      -1,   165,   166,   167,   168,   169,   170,   171,   172,    -1,
     174,    -1,   176,   177,    -1,    -1,   180,   181,   182,    -1,
      -1,    -1,   186,   187,   188,   189,    -1,   191,   192,    -1,
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
     314,   315,   316,   317,   318,   319,   320,    11,    12,    -1,
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
     314,   315,   316,   317,   318,   319,   320,    11,    12,    -1,
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
     114,   115,   116,   117,   118,   119,   120,   121,    -1,    -1,
      -1,   125,    -1,   127,   128,   129,   130,    -1,   132,    -1,
      -1,    -1,   136,   137,   138,   139,   140,    -1,    -1,    -1,
      -1,    -1,    -1,   147,   148,   149,   150,   151,   152,   153,
     154,   155,    -1,   157,   158,   159,   160,   161,    -1,    -1,
      -1,   165,   166,   167,   168,   169,   170,   171,   172,    -1,
     174,    -1,   176,   177,    -1,    -1,   180,   181,   182,    -1,
      -1,   185,   186,    -1,   188,   189,    -1,   191,   192,    -1,
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
     314,   315,   316,   317,   318,   319,   320,    11,    12,    -1,
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
     114,   115,   116,   117,   118,   119,   120,   121,    -1,    -1,
      -1,   125,    -1,   127,   128,   129,   130,    -1,   132,    -1,
      -1,    -1,   136,   137,   138,   139,   140,    -1,    -1,    -1,
      -1,    -1,    -1,   147,   148,   149,   150,   151,   152,   153,
     154,   155,    -1,   157,   158,   159,   160,   161,    -1,    -1,
      -1,   165,   166,   167,   168,   169,   170,   171,   172,    -1,
     174,    -1,   176,   177,    -1,    -1,   180,   181,   182,    -1,
      -1,    -1,   186,   187,   188,   189,    -1,   191,   192,    -1,
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
     314,   315,   316,   317,   318,   319,   320,    11,    12,    -1,
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
     304,   305,   306,   307,   308,   309,   310,   311,   312,    -1,
     314,   315,   316,   317,   318,   319,   320,    11,    12,    -1,
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
     304,   305,   306,   307,   308,   309,   310,    -1,   312,   313,
     314,   315,   316,   317,   318,   319,   320,    11,    12,    -1,
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
     114,   115,   116,   117,   118,   119,   120,   121,    -1,    -1,
      -1,   125,    -1,   127,   128,   129,   130,    -1,   132,    -1,
      -1,    -1,   136,   137,   138,   139,   140,    -1,    -1,    -1,
      -1,    -1,    -1,   147,   148,   149,   150,   151,   152,   153,
     154,   155,    -1,   157,   158,   159,   160,   161,    -1,    -1,
      -1,   165,   166,   167,   168,   169,   170,   171,   172,    -1,
     174,    -1,   176,   177,    -1,    -1,   180,   181,   182,    -1,
     184,    -1,   186,    -1,   188,   189,    -1,   191,   192,    -1,
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
     314,   315,   316,   317,   318,   319,   320,    11,    12,    -1,
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
     114,   115,   116,   117,   118,   119,   120,   121,    -1,    -1,
      -1,   125,    -1,   127,   128,   129,   130,    -1,   132,    -1,
      -1,    -1,   136,   137,   138,   139,   140,    -1,    -1,    -1,
      -1,    -1,    -1,   147,   148,   149,   150,   151,   152,   153,
     154,   155,    -1,   157,   158,   159,   160,   161,    -1,    -1,
      -1,   165,   166,   167,   168,   169,   170,   171,   172,    -1,
     174,    -1,   176,   177,    -1,    -1,   180,   181,   182,    -1,
      -1,   185,   186,    -1,   188,   189,    -1,   191,   192,    -1,
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
     314,   315,   316,   317,   318,   319,   320,    11,    12,    -1,
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
     114,   115,   116,   117,   118,   119,   120,   121,    -1,    -1,
      -1,   125,    -1,   127,   128,   129,   130,    -1,   132,    -1,
      -1,    -1,   136,   137,   138,   139,   140,    -1,    -1,    -1,
      -1,   145,    -1,   147,   148,   149,   150,   151,   152,   153,
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
     314,   315,   316,   317,   318,   319,   320,    11,    12,    -1,
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
     314,   315,   316,   317,   318,   319,   320,    11,    12,    -1,
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
     314,   315,   316,   317,   318,   319,   320,    11,    12,    -1,
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
     314,   315,   316,   317,   318,   319,   320,    11,    12,    -1,
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
     314,   315,   316,   317,   318,   319,   320,    11,    12,    -1,
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
     114,   115,   116,   117,   118,   119,   120,   121,    -1,    -1,
      -1,   125,    -1,   127,   128,   129,   130,    -1,   132,    -1,
      -1,    -1,   136,   137,   138,   139,   140,    -1,    -1,    -1,
      -1,    -1,    -1,   147,   148,   149,   150,   151,   152,   153,
     154,   155,    -1,   157,   158,    -1,   160,   161,    -1,    -1,
      -1,   165,   166,   167,   168,   169,   170,   171,   172,    -1,
     174,    -1,    -1,    -1,    -1,    -1,   180,   181,   182,    -1,
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
     314,   315,   316,   317,   318,   319,   320,    11,    12,    -1,
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
     114,   115,   116,   117,   118,   119,   120,   121,    -1,    -1,
      -1,   125,    -1,   127,   128,   129,   130,    -1,   132,    -1,
      -1,    -1,   136,   137,   138,   139,   140,    -1,    -1,    -1,
      -1,    -1,    -1,   147,   148,   149,   150,   151,   152,   153,
     154,   155,    -1,   157,   158,    -1,   160,   161,    -1,    -1,
      -1,   165,   166,   167,   168,   169,   170,   171,   172,    -1,
     174,    -1,    -1,    -1,    -1,    -1,   180,   181,   182,    -1,
      -1,    -1,   186,    -1,   188,   189,    -1,    -1,    -1,    -1,
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
     314,   315,   316,   317,   318,   319,   320,    11,    12,    -1,
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
     114,   115,   116,   117,   118,   119,   120,   121,    -1,    -1,
      -1,   125,    -1,   127,   128,   129,   130,    -1,   132,    -1,
      -1,    -1,   136,    -1,   138,   139,   140,    -1,    -1,    -1,
      -1,    -1,    -1,   147,   148,   149,   150,    -1,   152,   153,
     154,   155,    -1,   157,   158,    -1,   160,   161,    -1,    -1,
      -1,   165,   166,   167,   168,   169,   170,   171,   172,    -1,
     174,    -1,    -1,    -1,    -1,    -1,   180,   181,   182,    -1,
      -1,    -1,   186,    -1,   188,   189,    -1,    -1,    -1,    -1,
     194,    -1,   196,    -1,   198,    -1,   200,    -1,   202,   203,
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
     314,   315,   316,   317,   318,   319,   320,    11,    12,    -1,
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
      -1,    -1,    -1,   127,   128,   129,   130,    -1,   132,    -1,
      -1,    -1,   136,   137,   138,   139,   140,    -1,    -1,    -1,
      -1,    -1,    -1,   147,   148,   149,    -1,   151,   152,   153,
      -1,    -1,    -1,    -1,    -1,    -1,   160,   161,    -1,    -1,
      -1,   165,   166,   167,   168,   169,   170,   171,   172,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   180,   181,   182,    -1,
      -1,    -1,   186,    -1,   188,   189,    -1,    -1,    -1,    -1,
     194,    -1,   196,    -1,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,    -1,    -1,   211,   212,    -1,
      -1,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,    -1,   259,   260,   261,    -1,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,    -1,    -1,    -1,    -1,
     314,   315,   316,   317,   318,   319,   320,    11,    12,    -1,
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
      -1,    -1,    -1,   127,   128,   129,   130,    -1,   132,    -1,
      -1,    -1,   136,   137,   138,   139,   140,    -1,    -1,    -1,
      -1,    -1,    -1,   147,   148,   149,    -1,   151,   152,   153,
      -1,    -1,    -1,    -1,    -1,    -1,   160,   161,    -1,    -1,
      -1,   165,   166,   167,   168,   169,   170,   171,   172,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   180,   181,   182,    -1,
      -1,    -1,   186,    -1,   188,   189,    -1,    -1,    -1,    -1,
     194,    -1,   196,    -1,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,    -1,    -1,   211,   212,    -1,
      -1,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,    -1,   259,   260,   261,    -1,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,    -1,    -1,    16,    -1,
     314,   315,   316,   317,   318,   319,   320,    25,    26,    -1,
      -1,    -1,    -1,    -1,    -1,    33,    34,    -1,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    -1,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    -1,    95,    96,    97,
      98,    -1,    -1,   101,   102,   103,    -1,    -1,   106,   107,
      -1,    -1,    -1,    -1,   112,   113,   114,   115,   116,   117,
     118,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   127,
     128,   129,   130,    -1,   132,    -1,    -1,    -1,   136,   137,
     138,   139,   140,    -1,    -1,    -1,    -1,    -1,    -1,   147,
     148,   149,    -1,   151,   152,   153,    -1,    -1,    -1,   157,
      -1,    -1,   160,   161,    -1,    -1,    -1,   165,   166,   167,
     168,   169,   170,   171,   172,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   180,   181,   182,    -1,    -1,    -1,   186,   187,
     188,   189,    -1,    -1,    -1,    -1,   194,    -1,   196,    -1,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,    -1,    -1,   211,   212,    -1,    -1,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
      -1,   259,   260,   261,    -1,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,    -1,    -1,    -1,    -1,   314,   315,   316,   317,
     318,   319,   320,    16,    -1,    18,    19,    -1,    -1,    -1,
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
      -1,    -1,    -1,    -1,   127,   128,   129,   130,    -1,   132,
      -1,    -1,    -1,   136,   137,   138,   139,   140,    -1,    -1,
      -1,    -1,    -1,    -1,   147,   148,   149,    -1,   151,   152,
     153,    -1,    -1,    -1,    -1,    -1,    -1,   160,   161,    -1,
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
     117,   118,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     127,   128,   129,   130,    -1,   132,    -1,    -1,    -1,   136,
     137,   138,   139,   140,    -1,    -1,    -1,    -1,    -1,    -1,
     147,   148,   149,    -1,   151,   152,   153,    -1,    -1,    -1,
      -1,    -1,    -1,   160,   161,    -1,    -1,    -1,   165,   166,
     167,   168,   169,   170,   171,   172,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   180,   181,   182,    -1,    -1,    -1,   186,
     187,   188,   189,    -1,    -1,    -1,    -1,   194,    -1,   196,
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
     317,   318,   319,   320,    25,    26,    -1,    -1,    -1,    30,
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
     181,   182,    -1,    -1,    -1,   186,   187,   188,   189,    -1,
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
      -1,    -1,    -1,    -1,    33,    34,    -1,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    -1,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    -1,    95,    96,    97,    98,
      -1,    -1,   101,   102,   103,    -1,    -1,   106,   107,    -1,
      -1,    -1,    -1,   112,   113,   114,   115,   116,   117,   118,
     119,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   127,   128,
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
     113,   114,   115,   116,   117,   118,   119,    -1,    -1,    -1,
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
      -1,   112,   113,   114,   115,   116,   117,   118,    -1,    -1,
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
     115,   116,   117,   118,    -1,    -1,    -1,    -1,    -1,    -1,
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
     119,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   127,   128,
     129,   130,    -1,   132,    -1,    -1,    -1,   136,   137,   138,
     139,   140,    -1,    -1,    -1,    -1,    -1,    -1,   147,   148,
     149,    -1,   151,   152,   153,    -1,    -1,    -1,    -1,    -1,
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
     153,    -1,    -1,    -1,    -1,    -1,    -1,   160,   161,    -1,
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
     303,   304,   305,   306,   307,   308,   309,    -1,    -1,    -1,
      -1,   314,   315,   316,   317,   318,   319,   320,    21,    22,
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
      -1,    -1,   125,    -1,   127,   128,   129,   130,    -1,   132,
      -1,    -1,    -1,   136,   137,   138,   139,   140,    -1,    -1,
      -1,    -1,    -1,    -1,   147,   148,   149,   150,   151,   152,
      -1,   154,   155,    -1,   157,   158,    -1,   160,   161,    -1,
      -1,    -1,   165,   166,   167,   168,   169,   170,   171,   172,
      -1,   174,    -1,    -1,    -1,    -1,    -1,   180,   181,   182,
      -1,    -1,    -1,   186,    -1,   188,   189,    -1,    -1,    -1,
      -1,    -1,    -1,   196,    -1,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,    -1,    -1,    -1,   212,
     213,    -1,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,    -1,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
      -1,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,    -1,   259,   260,   261,    -1,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,    -1,   312,
      -1,   314,   315,   316,   317,   318,   319,   320,    25,    26,
      -1,    -1,    -1,    -1,    -1,    -1,    33,    34,    -1,    36,
      37,    38,    -1,    40,    41,    42,    43,    -1,    -1,    46,
      47,    -1,    49,    50,    51,    52,    -1,    54,    -1,    56,
      57,    58,    59,    -1,    61,    -1,    -1,    64,    65,    66,
      67,    68,    -1,    70,    -1,    72,    -1,    -1,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    -1,    95,    96,
      97,    -1,    -1,    -1,   101,   102,   103,    -1,    -1,   106,
     107,    -1,    -1,    -1,    -1,   112,   113,   114,   115,   116,
     117,   118,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     127,   128,   129,   130,    -1,   132,    -1,    -1,    -1,   136,
     137,   138,   139,   140,    -1,    -1,    -1,    -1,    -1,    -1,
     147,   148,   149,    -1,   151,   152,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   160,   161,    -1,    -1,    -1,   165,   166,
     167,   168,   169,   170,   171,   172,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   180,   181,   182,    -1,    -1,    -1,   186,
      -1,   188,   189,    -1,    -1,    -1,    -1,    -1,    -1,   196,
      -1,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,    -1,    -1,    -1,   212,    -1,    -1,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,    -1,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,    -1,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,    -1,   259,   260,   261,    -1,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,   309,    -1,    -1,    -1,    -1,   314,   315,   316,
     317,   318,   319,   320
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
     316,   317,   318,   319,   320,   321,   322,   335,   337,   338,
     339,   340,   341,   342,   343,   344,   345,   346,   347,   348,
     349,   350,   351,   352,   353,   356,   357,   358,   359,   360,
     361,   365,   366,   367,   371,   373,   374,   376,   383,   385,
     388,   389,   390,   392,   393,   394,   395,   396,   398,   399,
     401,   402,   403,   404,   405,   406,   408,   409,   412,   413,
     414,   415,   420,   422,   424,   425,   430,   449,   452,   456,
     459,   460,   466,   467,   468,   469,   471,   472,   474,   475,
     476,   477,   478,   479,   480,   481,   482,   484,   485,   486,
     487,   490,   491,   492,   493,   494,   495,   496,   497,   498,
     499,   500,   501,   502,   503,   504,   505,   506,   507,   510,
     511,   512,   513,   514,   515,   516,   517,   518,   520,   521,
     522,   523,   524,   525,   539,   540,   542,   543,   544,   545,
     546,   547,   548,   549,   557,   558,   559,   560,   561,   562,
     563,   564,   565,   566,   567,   568,   571,   576,   577,   578,
     579,   580,   581,   584,   642,   643,   644,   645,   647,   648,
     649,   650,   651,   657,   658,   659,    33,    34,    49,   215,
     391,   392,   393,   391,   391,   392,   393,   157,   157,    37,
      38,    40,    41,    47,    57,    58,    75,    80,   112,   113,
     114,   161,   220,   261,   287,   295,   303,   372,   373,   377,
     378,   379,   161,   154,   157,   154,   157,   154,   157,     1,
       3,    67,    72,   119,   417,   157,   380,   157,    25,    34,
      61,   119,   273,   429,   431,   432,   157,   154,   157,   157,
     157,   119,   154,   157,   157,   157,    77,   154,   221,   222,
     123,   123,   123,   154,   157,    39,    43,    45,    46,    47,
      48,    51,    60,    68,    71,    73,    74,    76,    91,    92,
      98,   106,   113,   115,   116,   136,   139,   140,   161,   169,
     172,   180,   181,   189,   202,   224,   226,   228,   229,   236,
     238,   239,   240,   243,   244,   315,   504,   658,   123,   119,
     400,   123,   123,    39,    44,    45,    53,    60,    62,    63,
      71,    98,   225,   657,   119,   123,   123,   184,   391,   393,
     413,   646,    48,    73,    74,   119,   154,   185,   244,   412,
     414,   424,   187,   412,   657,   154,   154,   123,   657,    18,
      19,   657,   123,   123,   123,   496,   154,    31,   214,   216,
     225,   227,   314,   225,   227,   314,   225,   314,   225,   230,
     314,   119,   241,   241,   242,   157,   154,   395,   311,   412,
     313,   412,   314,   322,   337,   337,     0,   339,   340,    33,
      49,   342,   359,     1,   190,   336,   190,   336,   113,   374,
     394,   412,   108,   190,   108,   336,   190,    42,    46,    51,
      70,   168,   171,   186,   212,   407,   416,   421,   422,   423,
     437,   438,   442,   167,    93,   133,   141,   142,   144,   152,
     156,   158,   163,   179,   203,   204,   205,   206,   207,   208,
     488,   489,   249,   100,   159,   176,   199,   118,   147,   160,
     194,   201,   210,   137,   151,    50,   200,   102,   103,   159,
     176,   486,   193,   154,   493,   496,   191,   192,   155,   508,
     509,   504,   508,   504,   155,   157,   508,   157,   146,   157,
     184,   184,   184,   184,   375,   511,   375,    30,   656,   182,
     196,   182,   196,   166,   182,   658,   657,   169,   202,    47,
     657,   153,   119,    45,    47,    80,   107,   168,   657,   221,
     222,   223,   246,   615,   657,   657,   304,   138,   143,   113,
     287,   295,   377,   657,   392,   187,   392,    45,    63,   187,
     567,   568,   412,   187,   194,   657,   426,   427,   657,   284,
     284,   426,   119,   433,   119,   187,   381,   382,   154,   397,
     412,     1,   161,   656,   114,   161,   355,   656,   657,   119,
     143,   108,   187,   412,    30,   187,   657,   657,   657,   450,
     451,   657,   392,   187,   412,   412,   569,   657,   392,   154,
     154,   412,   187,   194,   657,   657,   143,   450,   184,   184,
     122,   108,   184,   157,   157,   157,   657,   154,   185,   186,
     187,    35,   527,   528,   529,   412,   412,     8,   175,    17,
     412,   214,    30,   413,   413,    39,    45,    60,    71,    98,
     507,   658,   413,   413,   413,   646,   413,   507,   413,   231,
     230,   582,   583,   657,   190,   190,   413,   412,   393,   412,
     245,   410,   411,   311,   313,   413,   337,   190,   336,   190,
     336,     3,   343,   359,   389,     1,   343,   359,   389,    33,
     360,   389,   360,   389,   400,   336,   400,   413,   413,   119,
     168,   170,   170,   394,   413,   413,   468,   469,   471,   471,
     471,   471,   470,   471,   471,   471,    71,   472,   476,   476,
     475,   477,   477,   477,   477,   478,   478,   479,   479,   231,
      95,    95,    95,   494,   184,   412,   496,   496,   412,   509,
     185,   145,   187,   413,   519,   187,   150,   187,   519,   108,
     187,   187,   108,   108,   380,    30,   658,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,   362,   363,   364,
      95,   138,   143,   368,   369,   370,   657,   161,   161,   362,
     656,   128,   133,    55,    57,   101,   251,   264,   266,   277,
     278,   279,   281,   283,   616,   617,   618,   619,   620,   621,
     628,   634,   635,   246,    95,   299,   657,   143,   413,   119,
     657,   657,   133,   184,   184,   187,   187,   184,   108,   187,
     108,   187,   108,    36,    95,    97,   148,   428,   429,   550,
     657,    56,   217,   254,   418,   419,   657,    95,   108,   187,
     391,   187,   657,    97,    45,   657,   656,    97,   143,   550,
     657,   413,   432,   184,   187,   187,   187,   187,   108,   188,
     148,   550,   184,   187,   187,   154,   184,   392,   392,   184,
     108,   187,   108,   187,   143,   550,   413,   188,   413,   413,
     412,   412,   412,   657,   528,   529,   131,   197,   184,   184,
     184,   132,   190,    95,   218,   219,   233,    95,   218,   219,
     233,   233,   233,    95,    95,   237,   225,   231,   108,   235,
     143,   190,   187,   412,   184,   505,   588,   411,   233,   359,
      33,    33,   190,   336,   190,   114,   394,   657,   170,   413,
     443,   444,   119,   413,   439,   440,   471,   154,   157,   259,
     492,   511,   589,   592,   593,   594,   595,   596,   600,   602,
     604,   605,    47,   153,   157,   211,   317,   318,   319,   320,
     551,   553,   555,   557,   572,   573,   574,   575,   652,   653,
     654,   655,   657,   551,   483,   556,   657,   483,   184,   185,
     108,   187,   187,   511,   149,   165,   149,   165,   138,   397,
     380,   363,   133,   553,   370,   413,   550,   656,   656,   129,
     130,   656,   277,   278,   279,   283,   657,   263,   274,   263,
     274,    30,   286,    97,   114,   157,   622,   625,   616,    39,
      44,    53,    60,    62,    71,    98,   225,   317,   318,   319,
     384,   557,   652,   227,   299,   308,   413,   657,    95,   299,
     656,   154,   569,   570,   657,   569,   570,   119,   427,   128,
     551,   119,   413,   148,   429,   148,    36,   148,   428,   429,
     148,   550,   254,    54,    59,    78,   119,   428,   434,   435,
     436,   419,   550,   551,   382,    95,   184,   198,   133,   354,
     656,   161,   133,    97,   354,   413,   143,   429,   154,   119,
     413,   413,   148,   101,   453,   454,   455,   457,   458,   101,
     461,   462,   463,   464,   392,   184,   184,   154,   569,   569,
     413,   143,   190,   413,   122,   187,   187,   187,    35,   529,
     131,   197,     9,    10,   104,   124,   126,   154,   195,   524,
     526,   537,   538,   541,   154,    30,   232,   234,   413,   413,
     413,   232,   234,   413,   413,   413,   413,   413,   413,   413,
     413,   413,   507,   119,   413,   413,    48,    73,    74,   244,
     394,   414,   424,   245,   585,   586,   154,   210,   395,   413,
     190,   114,   389,   389,   389,   443,    96,   107,   117,   128,
     445,   446,   447,   448,   108,   657,   107,   441,   108,   412,
     589,   596,   154,   285,   473,   641,    97,   169,   252,   253,
     255,   262,   272,   284,   590,   591,   610,   611,   612,   613,
     636,   639,   258,   260,   597,   615,   267,   601,   637,   247,
     248,   270,   606,   607,   157,   157,   553,   157,   157,   157,
     157,   157,   145,   176,   194,   552,   145,   145,   413,   138,
     397,   571,   369,   286,    30,    97,   114,   157,   629,    30,
     622,   552,   552,   494,   287,   306,   550,   384,   227,   190,
     391,   187,   187,   145,   187,   187,   427,   148,   428,   657,
     413,   148,   413,   128,   413,   148,   429,   148,   413,   148,
     119,   119,   413,   657,   436,    78,   551,   394,   413,   656,
     108,   354,   413,   143,   391,   451,   413,   413,   114,   454,
     455,   101,   186,   114,   455,   458,   119,   465,   551,   101,
     114,   462,   101,   114,   464,   184,   391,   187,   187,   413,
     413,   198,   461,   133,   195,   526,     7,   392,   657,   195,
     537,   392,   190,   233,   233,   233,   233,    97,   237,   237,
     583,   186,   157,   157,   157,   186,   588,   586,   505,   656,
     129,   130,   447,   448,   448,   444,   143,   550,   656,   440,
     184,   187,   589,   603,   250,   217,   254,   268,   275,   640,
      97,   256,   257,   638,   250,   593,   640,   475,   610,   594,
     148,   282,   598,   599,   638,   286,   609,    79,   608,   187,
     194,   551,   554,   187,   187,   187,   187,   187,   187,   187,
      30,   137,   201,   631,   632,   633,    30,   630,   631,   271,
     626,   108,   623,   170,   657,   257,   494,   184,   413,   148,
     413,   148,   428,   413,   148,   413,   413,   657,   657,   435,
     413,   127,   127,    97,   656,   413,   184,   186,   186,   413,
     394,   413,   186,   186,   657,   186,   210,   119,   465,   119,
     186,   119,   465,   186,   184,   114,   529,   657,   195,   184,
     529,   657,   184,   413,   413,   413,   413,   316,   413,   413,
     413,   412,   412,   412,   154,   587,   448,   413,   143,   184,
     477,    52,   130,   475,   475,   269,   276,   286,   614,   614,
     595,   154,   280,    95,   187,   108,   187,   629,   629,   633,
     108,   187,    30,   627,   638,   624,   625,   187,   386,   387,
     494,   119,   225,   307,   287,   170,   413,   413,   148,   413,
      54,   394,   413,   354,   413,   394,    95,   394,   413,   551,
     657,   186,   657,   413,   657,   186,   394,   119,    94,   183,
     530,   529,   657,   197,   529,   413,   187,   187,   187,   412,
     441,   413,   475,   475,   199,   412,   551,   551,    95,    30,
     265,   108,   108,   448,   550,   657,   119,   225,   657,   386,
     413,   119,   465,    95,   186,    95,   657,     5,   134,   533,
     534,   536,   538,    29,   135,   531,   532,   535,   538,   197,
     529,   197,   198,   461,   184,   441,   475,   184,   551,   625,
     387,   448,   305,   657,   119,   225,   657,   186,   465,   394,
     413,   465,   186,    94,   134,   536,   183,   135,   535,   197,
     114,   413,   305,   657,   119,   394,   413,   186,   186,   119,
     293,   305,   657,   657,   306,   413,   306,   186,   494,   494,
     199,   287,   657,   225,   119,   657,   306,   494
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
     585,   586,   587,   588
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned short int
  xquery_parser::yyr1_[] =
  {
         0,   334,   335,   335,   335,   335,   336,   336,   336,   337,
     337,   337,   337,   338,   338,   339,   339,   339,   339,   339,
     339,   339,   339,   340,   340,   340,   340,   341,   342,   342,
     342,   343,   343,   343,   343,   343,   344,   344,   344,   344,
     344,   344,   344,   344,   345,   345,   346,   347,   348,   348,
     349,   349,   350,   350,   351,   351,   351,   351,   352,   352,
     352,   353,   353,   353,   353,   354,   354,   355,   355,   356,
     356,   356,   356,   357,   358,   358,   359,   359,   359,   360,
     360,   360,   360,   360,   360,   360,   360,   361,   361,   362,
     362,   363,   364,   364,   364,   364,   364,   364,   364,   364,
     364,   364,   365,   366,   367,   368,   368,   369,   369,   369,
     370,   371,   371,   371,   372,   372,   372,   372,   373,   373,
     374,   374,   374,   374,   375,   375,   376,   376,   377,   377,
     378,   378,   379,   379,   380,   380,   380,   380,   381,   381,
     382,   382,   383,   383,   383,   383,   384,   384,   384,   384,
     385,   385,   386,   386,   387,   387,   387,   387,   388,   388,
     388,   388,   389,   390,   390,   390,   391,   391,   391,   392,
     392,   393,   393,   393,   394,   394,   394,   394,   394,   394,
     394,   394,   394,   394,   394,   394,   395,   395,   396,   397,
     398,   399,   399,   399,   400,   400,   400,   400,   401,   402,
     403,   404,   405,   405,   406,   407,   408,   409,   410,   410,
     411,   412,   412,   412,   413,   413,   413,   413,   413,   413,
     414,   414,   414,   414,   414,   414,   414,   414,   414,   414,
     414,   414,   415,   416,   417,   417,   418,   418,   418,   419,
     419,   420,   420,   421,   422,   422,   422,   423,   423,   423,
     423,   423,   424,   424,   425,   425,   425,   426,   426,   426,
     427,   427,   427,   427,   427,   427,   427,   427,   427,   427,
     427,   427,   428,   429,   430,   431,   431,   432,   432,   432,
     432,   433,   433,   434,   434,   434,   435,   435,   435,   436,
     436,   436,   437,   438,   439,   439,   440,   440,   440,   440,
     440,   440,   441,   442,   442,   443,   443,   444,   444,   445,
     445,   445,   445,   445,   445,   445,   446,   446,   447,   447,
     448,   449,   449,   450,   450,   451,   451,   452,   453,   453,
     454,   455,   455,   456,   457,   457,   458,   459,   459,   460,
     460,   461,   461,   462,   462,   463,   463,   464,   464,   465,
     465,   466,   467,   467,   468,   468,   469,   469,   469,   469,
     469,   470,   469,   469,   469,   469,   471,   471,   472,   472,
     473,   473,   474,   474,   475,   475,   475,   476,   476,   476,
     476,   476,   477,   477,   477,   478,   478,   478,   479,   479,
     480,   480,   481,   481,   482,   482,   483,   483,   484,   484,
     485,   485,   485,   485,   486,   486,   486,   487,   487,   488,
     488,   488,   488,   488,   488,   489,   489,   489,   490,   490,
     490,   490,   491,   491,   492,   492,   493,   493,   493,   494,
     494,   494,   494,   495,   496,   496,   496,   497,   497,   498,
     498,   498,   498,   499,   499,   500,   500,   500,   500,   500,
     500,   500,   501,   501,   502,   502,   503,   503,   503,   503,
     503,   504,   504,   505,   505,   506,   506,   506,   506,   507,
     507,   507,   507,   507,   508,   508,   509,   510,   510,   510,
     510,   510,   510,   510,   510,   510,   510,   510,   510,   510,
     510,   511,   511,   512,   512,   512,   513,   514,   514,   515,
     516,   517,   518,   518,   519,   519,   519,   519,   520,   520,
     521,   522,   523,   523,   524,   524,   524,   525,   525,   525,
     525,   525,   525,   526,   526,   527,   527,   528,   529,   529,
     530,   530,   531,   531,   532,   532,   532,   532,   533,   533,
     534,   534,   534,   534,   535,   535,   536,   536,   537,   537,
     537,   537,   538,   538,   538,   538,   539,   539,   540,   540,
     541,   542,   542,   542,   542,   542,   542,   542,   543,   544,
     544,   545,   545,   546,   547,   548,   548,   549,   549,   550,
     551,   551,   551,   552,   552,   552,   553,   553,   553,   553,
     553,   553,   553,   554,   554,   555,   556,   557,   557,   557,
     557,   557,   557,   557,   557,   557,   557,   558,   559,   560,
     560,   560,   561,   562,   563,   564,   564,   564,   565,   565,
     565,   565,   565,   566,   567,   567,   567,   567,   567,   567,
     567,   568,   569,   570,   571,   572,   572,   573,   574,   574,
     575,   576,   576,   576,   577,   577,   577,   577,   577,   577,
     577,   577,   577,   577,   578,   578,   579,   579,   580,   581,
     582,   582,   583,   584,   585,   585,   586,   587,   588,   588,
     589,   590,   590,   591,   591,   592,   592,   593,   593,   594,
     594,   595,   595,   596,   597,   597,   598,   598,   599,   600,
     600,   600,   601,   601,   602,   603,   603,   604,   605,   605,
     606,   606,   607,   607,   607,   608,   608,   609,   609,   610,
     610,   610,   610,   610,   611,   612,   613,   614,   614,   614,
     615,   615,   616,   616,   616,   616,   616,   616,   616,   616,
     617,   617,   617,   617,   618,   618,   619,   620,   620,   621,
     621,   621,   622,   622,   623,   623,   624,   624,   625,   626,
     626,   627,   627,   628,   628,   628,   629,   629,   630,   630,
     631,   631,   632,   632,   633,   633,   634,   635,   635,   636,
     636,   636,   637,   638,   638,   638,   638,   639,   639,   640,
     640,   641,   642,   642,   643,   643,   644,   644,   645,   646,
     646,   647,   647,   647,   648,   649,   650,   651,   652,   652,
     652,   653,   654,   655,   656,   657,   657,   657,   657,   657,
     657,   657,   657,   657,   657,   657,   657,   657,   657,   657,
     657,   657,   657,   658,   658,   658,   658,   658,   658,   658,
     658,   658,   658,   658,   658,   658,   658,   658,   658,   658,
     658,   658,   658,   658,   658,   658,   658,   658,   658,   658,
     658,   658,   658,   658,   658,   658,   658,   658,   658,   658,
     658,   658,   658,   658,   658,   658,   658,   658,   658,   658,
     658,   658,   658,   658,   658,   658,   658,   658,   658,   658,
     658,   658,   658,   658,   658,   658,   658,   658,   658,   658,
     658,   658,   658,   658,   658,   658,   658,   658,   658,   658,
     658,   658,   658,   658,   658,   658,   658,   658,   658,   658,
     658,   658,   658,   658,   658,   658,   658,   658,   658,   658,
     658,   658,   658,   658,   658,   658,   658,   658,   658,   658,
     658,   658,   658,   658,   658,   658,   658,   658,   658,   658,
     658,   658,   658,   658,   658,   658,   658,   658,   658,   658,
     658,   658,   658,   658,   658,   658,   658,   658,   658,   658,
     658,   658,   658,   658,   658,   658,   658,   658,   658,   658,
     658,   658,   658,   658,   658,   658,   658,   658,   658,   658,
     658,   658,   658,   658,   658,   658,   658,   658,   658,   658,
     658,   658,   658,   658,   658,   658,   658,   658,   658,   658,
     658,   658,   658,   658,   658,   658,   658,   658,   658,   658,
     658,   658,   658,   658,   658,   658,   658,   658,   658,   658,
     658,   658,   658,   658,   658,   658,   658,   658,   658,   659
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
       1,     2,     2,     3,     4,     1,     3,     1,     2,     1,
       1,     1,     2,     2,     2,     3,     1,     1,     2,     2,
       2,     5,     5,     1,     4,     3,     4,     8,     1,     2,
       3,     2,     3,     8,     1,     2,     3,     8,    10,     8,
      10,     1,     2,     4,     7,     1,     2,     4,     7,     1,
       3,     8,     1,     3,     1,     3,     1,     3,     3,     3,
       3,     0,     4,     3,     3,     3,     1,     5,     1,     3,
       0,     1,     1,     3,     1,     3,     3,     1,     3,     3,
       3,     3,     1,     3,     3,     1,     3,     3,     1,     4,
       1,     4,     1,     4,     1,     4,     1,     2,     1,     2,
       1,     1,     2,     2,     1,     1,     1,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     4,     5,
       5,     6,     3,     4,     1,     2,     3,     2,     2,     1,
       2,     2,     1,     1,     1,     3,     3,     1,     1,     1,
       2,     1,     2,     2,     1,     2,     2,     2,     2,     2,
       2,     2,     1,     2,     2,     1,     2,     2,     2,     2,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     3,     4,     3,     1,     2,     3,     1,     1,     1,
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

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
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
  "MULTIPLICATIVE_REDUCE", "$accept", "Module", "ERROR",
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
  "NameTest", "Wildcard", "PostfixExpr", "PredicateList", "Predicate",
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
  "URI_LITERAL", "QNAME", "FUNCTION_NAME", "EQNAME", 0
  };
#endif

#if YYDEBUG
  /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
  const xquery_parser::rhs_number_type
  xquery_parser::yyrhs_[] =
  {
       335,     0,    -1,   337,    -1,   321,   337,    -1,   322,   337,
      -1,   321,   322,   337,    -1,     1,    -1,     1,     3,    -1,
     336,     1,    -1,   339,    -1,   338,   339,    -1,   340,    -1,
     338,   340,    -1,   215,   216,    30,   190,    -1,   215,   216,
      30,   132,    30,   190,    -1,   342,   190,   389,    -1,   359,
     190,   389,    -1,   342,   190,   359,   190,   389,    -1,   389,
      -1,   342,   336,   389,    -1,   359,   336,   389,    -1,   342,
     190,   359,   336,   389,    -1,   342,   336,   359,   190,   389,
      -1,   341,    -1,   341,   342,   190,    -1,   341,   359,   190,
      -1,   341,   342,   190,   359,   190,    -1,    34,   161,   657,
     133,   656,   190,    -1,   343,    -1,   342,   190,   343,    -1,
     342,   336,   343,    -1,   344,    -1,   352,    -1,   357,    -1,
     358,    -1,   366,    -1,   345,    -1,   346,    -1,   347,    -1,
     348,    -1,   349,    -1,   350,    -1,   351,    -1,   576,    -1,
      33,    38,   182,    -1,    33,    38,   196,    -1,    33,   114,
     107,   656,    -1,    33,    37,   656,    -1,    33,    40,   182,
      -1,    33,    40,   196,    -1,    33,    58,   169,    -1,    33,
      58,   202,    -1,    33,   114,   168,   128,   129,    -1,    33,
     114,   168,   128,   130,    -1,    33,    41,   182,   108,   149,
      -1,    33,    41,   182,   108,   165,    -1,    33,    41,   166,
     108,   149,    -1,    33,    41,   166,   108,   165,    -1,   353,
      -1,   356,    -1,    49,    25,     1,    -1,    49,    61,   656,
      -1,    49,    61,   355,   656,    -1,    49,    61,   656,    97,
     354,    -1,    49,    61,   355,   656,    97,   354,    -1,   656,
      -1,   354,   108,   656,    -1,   161,   657,   133,    -1,   114,
      45,   161,    -1,    49,    34,   656,    -1,    49,    34,   161,
     657,   133,   656,    -1,    49,    34,   656,    97,   354,    -1,
      49,    34,   161,   657,   133,   656,    97,   354,    -1,    33,
     161,   657,   133,   656,    -1,    33,   114,    45,   161,   656,
      -1,    33,   114,    47,   161,   656,    -1,   360,    -1,   359,
     190,   360,    -1,   359,   336,   360,    -1,   361,    -1,   365,
      -1,   367,    -1,   371,    -1,   376,    -1,   383,    -1,   385,
      -1,   388,    -1,    33,   114,    80,   362,    -1,    33,    80,
     657,   362,    -1,   363,    -1,   362,   363,    -1,   364,   133,
     571,    -1,    81,    -1,    89,    -1,    82,    -1,    83,    -1,
      84,    -1,    85,    -1,    90,    -1,    86,    -1,    87,    -1,
      88,    -1,    33,    57,   657,    30,    -1,    33,   261,   615,
      -1,    33,   112,   153,   368,    -1,    95,   553,   369,    -1,
     369,    -1,   370,    -1,   138,    -1,   138,   370,    -1,   143,
     413,    -1,    33,   372,   143,   413,    -1,    33,   372,   138,
      -1,    33,   372,   138,   143,   413,    -1,   113,   119,   657,
      -1,   113,   119,   657,   550,    -1,   373,   113,   119,   657,
      -1,   373,   113,   119,   657,   550,    -1,   374,    -1,   373,
     374,    -1,    27,    -1,    27,   157,   375,   187,    -1,    28,
      -1,    28,   157,   375,   187,    -1,   511,    -1,   375,   108,
     511,    -1,    33,   377,    -1,    33,   373,   377,    -1,   378,
      -1,   379,    -1,    47,   658,   380,   397,    -1,    47,   658,
     380,   138,    -1,    75,    47,   658,   380,   397,    -1,    75,
      47,   658,   380,   138,    -1,   157,   187,    -1,   157,   381,
     187,    -1,   157,   187,    95,   551,    -1,   157,   381,   187,
      95,   551,    -1,   382,    -1,   381,   108,   382,    -1,   119,
     657,    -1,   119,   657,   550,    -1,    33,   287,   657,    -1,
      33,   287,   657,    95,   384,    -1,    33,   373,   287,   657,
      -1,    33,   373,   287,   657,    95,   384,    -1,   557,    -1,
     557,   552,    -1,   652,    -1,   652,   552,    -1,    33,   295,
     657,   299,   227,   494,   170,   386,    -1,    33,   373,   295,
     657,   299,   227,   494,   170,   386,    -1,   387,    -1,   386,
     108,   387,    -1,   494,    -1,   494,   550,    -1,   494,   448,
      -1,   494,   550,   448,    -1,    33,   303,   304,   657,   299,
     287,   657,   119,   657,   305,   413,    -1,    33,   303,   304,
     657,   299,   287,   657,   225,   119,   657,   305,   293,   306,
     494,    -1,    33,   303,   304,   657,   299,   287,   657,   307,
     225,   119,   657,   305,   413,    -1,    33,   303,   304,   657,
     308,   306,   257,   287,   657,   225,   119,   657,   306,   494,
     199,   287,   657,   225,   119,   657,   306,   494,    -1,   390,
      -1,   392,    -1,   393,    -1,    -1,   392,    -1,   393,    -1,
      -1,   412,    -1,   393,   412,    -1,   394,    -1,   393,   394,
      -1,   393,   412,   336,   394,    -1,   395,    -1,   398,    -1,
     401,    -1,   402,    -1,   403,    -1,   404,    -1,   405,    -1,
     406,    -1,   408,    -1,   460,    -1,   456,    -1,   409,    -1,
     154,   393,   184,    -1,   154,   184,    -1,   154,   391,   184,
      -1,   154,   391,   184,    -1,   399,   190,    -1,   399,   108,
     400,    -1,   113,   400,    -1,   373,   113,   400,    -1,   119,
     657,    -1,   119,   657,   550,    -1,   119,   657,   143,   413,
      -1,   119,   657,   550,   143,   413,    -1,   119,   657,   143,
     413,   190,    -1,   414,   190,    -1,   240,   242,   413,   190,
      -1,   243,   157,   412,   187,   394,    -1,   238,   241,   190,
      -1,   239,   241,   190,    -1,   424,   407,    -1,   186,   394,
      -1,    48,   157,   412,   187,   198,   394,   127,   394,    -1,
     244,   395,   410,    -1,   411,    -1,   410,   411,    -1,   245,
     588,   395,    -1,   413,    -1,   412,   108,   413,    -1,   412,
     336,   413,    -1,   415,    -1,   452,    -1,   459,    -1,   466,
      -1,   584,    -1,   414,    -1,   467,    -1,   449,    -1,   577,
      -1,   578,    -1,   580,    -1,   579,    -1,   581,    -1,   649,
      -1,   647,    -1,   650,    -1,   651,    -1,   648,    -1,   424,
     416,    -1,   186,   413,    -1,    67,   284,    -1,    72,   284,
      -1,   217,    -1,   254,    -1,    56,   254,    -1,   418,   434,
      78,   413,    -1,   418,    78,   413,    -1,    46,   417,   433,
     419,   419,    -1,    46,   417,   433,   419,    -1,    42,   119,
     657,    -1,   425,    -1,   430,    -1,   420,    -1,   422,    -1,
     437,    -1,   442,    -1,   438,    -1,   421,    -1,   422,    -1,
     424,   423,    -1,    46,   119,   426,    -1,    46,     1,   426,
      -1,    46,     3,    -1,   427,    -1,   426,   108,   119,   427,
      -1,   426,   108,   427,    -1,   657,   148,   413,    -1,   657,
      36,   128,   148,   413,    -1,   657,   550,   148,   413,    -1,
     657,   550,    36,   128,   148,   413,    -1,   657,   428,   148,
     413,    -1,   657,    36,   128,   428,   148,   413,    -1,   657,
     550,   428,   148,   413,    -1,   657,   550,    36,   128,   428,
     148,   413,    -1,   657,   429,   148,   413,    -1,   657,   550,
     429,   148,   413,    -1,   657,   428,   429,   148,   413,    -1,
     657,   550,   428,   429,   148,   413,    -1,    97,   119,   657,
      -1,   273,   119,   657,    -1,    51,   431,    -1,   432,    -1,
     431,   108,   432,    -1,   119,   657,   143,   413,    -1,   119,
     657,   550,   143,   413,    -1,   429,   143,   413,    -1,   119,
     657,   550,   429,   143,   413,    -1,   119,   657,   148,   413,
      -1,   119,   657,   550,   148,   413,    -1,   435,    -1,   119,
     657,    -1,   119,   657,   435,    -1,   428,    -1,   428,   436,
      -1,   436,    -1,    59,   119,   657,    54,   119,   657,    -1,
      54,   119,   657,    -1,    59,   119,   657,    -1,   212,   413,
      -1,   171,   170,   439,    -1,   440,    -1,   439,   108,   440,
      -1,   119,   657,   143,   413,    -1,   119,   657,   550,   143,
     413,    -1,   119,   657,   550,   143,   413,   441,    -1,   119,
     657,   143,   413,   441,    -1,   413,    -1,   413,   441,    -1,
     107,   656,    -1,   168,   170,   443,    -1,    70,   168,   170,
     443,    -1,   444,    -1,   443,   108,   444,    -1,   413,    -1,
     413,   445,    -1,   446,    -1,   447,    -1,   448,    -1,   446,
     447,    -1,   446,   448,    -1,   447,   448,    -1,   446,   447,
     448,    -1,    96,    -1,   117,    -1,   128,   129,    -1,   128,
     130,    -1,   107,   656,    -1,    68,   119,   450,   188,   413,
      -1,   136,   119,   450,   188,   413,    -1,   451,    -1,   450,
     108,   119,   451,    -1,   657,   148,   413,    -1,   657,   550,
     148,   413,    -1,    73,   157,   412,   187,   453,   114,   186,
     413,    -1,   454,    -1,   453,   454,    -1,   455,   186,   413,
      -1,   101,   413,    -1,   455,   101,   413,    -1,    73,   157,
     412,   187,   457,   114,   186,   394,    -1,   458,    -1,   457,
     458,    -1,   455,   186,   394,    -1,    74,   157,   412,   187,
     461,   114,   186,   413,    -1,    74,   157,   412,   187,   461,
     114,   119,   657,   186,   413,    -1,    74,   157,   412,   187,
     463,   114,   186,   394,    -1,    74,   157,   412,   187,   461,
     114,   119,   657,   186,   394,    -1,   462,    -1,   461,   462,
      -1,   101,   465,   186,   413,    -1,   101,   119,   657,    95,
     465,   186,   413,    -1,   464,    -1,   463,   464,    -1,   101,
     465,   186,   394,    -1,   101,   119,   657,    95,   465,   186,
     394,    -1,   551,    -1,   465,   210,   551,    -1,    48,   157,
     412,   187,   198,   413,   127,   413,    -1,   468,    -1,   467,
     167,   468,    -1,   469,    -1,   468,    93,   469,    -1,   471,
      -1,   471,   488,   471,    -1,   471,   489,   471,    -1,   471,
     133,   471,    -1,   471,   163,   471,    -1,    -1,   471,   158,
     470,   471,    -1,   471,   156,   471,    -1,   471,   144,   471,
      -1,   471,   142,   471,    -1,   472,    -1,   472,   249,    71,
     589,   473,    -1,   474,    -1,   474,   100,   472,    -1,    -1,
     641,    -1,   475,    -1,   475,   199,   475,    -1,   476,    -1,
     475,   176,   476,    -1,   475,   159,   476,    -1,   477,    -1,
     476,   194,   477,    -1,   476,   118,   477,    -1,   476,   147,
     477,    -1,   476,   160,   477,    -1,   478,    -1,   477,   201,
     478,    -1,   477,   210,   478,    -1,   479,    -1,   478,   151,
     479,    -1,   478,   137,   479,    -1,   480,    -1,   480,    50,
     231,   551,    -1,   481,    -1,   481,   200,    95,   551,    -1,
     482,    -1,   482,   102,    95,   483,    -1,   484,    -1,   484,
     103,    95,   483,    -1,   556,    -1,   556,   145,    -1,   486,
      -1,   485,   486,    -1,   176,    -1,   159,    -1,   485,   176,
      -1,   485,   159,    -1,   490,    -1,   487,    -1,   491,    -1,
     494,    -1,   487,   193,   494,    -1,   203,    -1,   208,    -1,
     207,    -1,   206,    -1,   205,    -1,   204,    -1,   152,    -1,
     179,    -1,   141,    -1,    76,   154,   392,   184,    -1,    76,
     222,   154,   392,   184,    -1,    76,   221,   154,   392,   184,
      -1,    76,    77,   569,   154,   392,   184,    -1,   492,   154,
     184,    -1,   492,   154,   412,   184,    -1,   493,    -1,   492,
     493,    -1,   177,   657,    17,    -1,   177,    18,    -1,   177,
      19,    -1,   495,    -1,   495,   496,    -1,   192,   496,    -1,
     496,    -1,   191,    -1,   497,    -1,   497,   191,   496,    -1,
     497,   192,   496,    -1,   498,    -1,   507,    -1,   499,    -1,
     499,   508,    -1,   502,    -1,   502,   508,    -1,   500,   504,
      -1,   501,    -1,   106,   123,    -1,   115,   123,    -1,    98,
     123,    -1,   189,   123,    -1,   116,   123,    -1,   140,   123,
      -1,   139,   123,    -1,   504,    -1,    99,   504,    -1,   503,
     504,    -1,   121,    -1,   172,   123,    -1,    91,   123,    -1,
     181,   123,    -1,   180,   123,    -1,    92,   123,    -1,   557,
      -1,   505,    -1,   657,    -1,   506,    -1,   194,    -1,    11,
      -1,    12,    -1,    20,    -1,   510,    -1,   507,   508,    -1,
     507,   157,   187,    -1,   507,   157,   519,   187,    -1,   507,
     155,   185,    -1,   509,    -1,   508,   509,    -1,   155,   412,
     185,    -1,   511,    -1,   513,    -1,   514,    -1,   515,    -1,
     518,    -1,   523,    -1,   516,    -1,   517,    -1,   520,    -1,
     396,    -1,   645,    -1,   642,    -1,   643,    -1,   644,    -1,
     512,    -1,   571,    -1,   111,    -1,   150,    -1,   125,    -1,
     119,   657,    -1,   157,   187,    -1,   157,   412,   187,    -1,
     120,    -1,   169,   154,   412,   184,    -1,   202,   154,   412,
     184,    -1,   658,   157,   187,    -1,   658,   157,   519,   187,
      -1,   145,    -1,   519,   108,   145,    -1,   413,    -1,   519,
     108,   413,    -1,   521,    -1,   522,    -1,   658,   146,   150,
      -1,    47,   380,   397,    -1,   524,    -1,   542,    -1,   525,
      -1,   539,    -1,   540,    -1,   158,   657,   529,   131,    -1,
     158,   657,   529,   197,   195,   657,   529,   197,    -1,   158,
     657,   527,   529,   131,    -1,   158,   657,   527,   529,   197,
     195,   657,   529,   197,    -1,   158,   657,   529,   197,   526,
     195,   657,   529,   197,    -1,   158,   657,   527,   529,   197,
     526,   195,   657,   529,   197,    -1,   537,    -1,   526,   537,
      -1,   528,    -1,   527,   528,    -1,    35,   657,   529,   133,
     529,   530,    -1,    -1,    35,    -1,   183,   531,   183,    -1,
      94,   533,    94,    -1,    -1,   532,    -1,   135,    -1,   535,
      -1,   532,   135,    -1,   532,   535,    -1,    -1,   534,    -1,
     134,    -1,   536,    -1,   534,   134,    -1,   534,   536,    -1,
      29,    -1,   538,    -1,     5,    -1,   538,    -1,   524,    -1,
      10,    -1,   541,    -1,   538,    -1,     9,    -1,   124,    -1,
     126,    -1,   154,   392,   184,    -1,   213,    31,   214,    -1,
     213,   214,    -1,   174,   657,   175,    -1,   174,   657,     8,
      -1,   104,     7,    -1,   543,    -1,   544,    -1,   545,    -1,
     546,    -1,   547,    -1,   548,    -1,   549,    -1,    43,   154,
     392,   184,    -1,    21,   391,   184,    -1,    45,   154,   412,
     184,   154,   391,   184,    -1,    22,   391,   184,    -1,    98,
     154,   412,   184,   154,   391,   184,    -1,    71,   154,   392,
     184,    -1,    39,   154,   392,   184,    -1,    23,   391,   184,
      -1,    60,   154,   412,   184,   154,   391,   184,    -1,    24,
     392,   184,    -1,   161,   154,   412,   184,   154,   392,   184,
      -1,    95,   551,    -1,   553,    -1,   553,   552,    -1,   211,
     157,   187,    -1,   145,    -1,   194,    -1,   176,    -1,   555,
      -1,   557,    -1,   153,   157,   187,    -1,   320,   157,   187,
      -1,   572,    -1,   575,    -1,   652,    -1,   551,    -1,   554,
     108,   551,    -1,   657,    -1,   657,    -1,   560,    -1,   567,
      -1,   565,    -1,   568,    -1,   566,    -1,   564,    -1,   563,
      -1,   562,    -1,   561,    -1,   558,    -1,   559,   157,   187,
      -1,   225,    -1,    44,   157,   187,    -1,    44,   157,   567,
     187,    -1,    44,   157,   568,   187,    -1,    53,   157,   187,
      -1,    71,   157,   187,    -1,    39,   157,   187,    -1,    60,
     157,   187,    -1,    60,   157,   657,   187,    -1,    60,   157,
      30,   187,    -1,    98,   157,   187,    -1,    98,   157,   657,
     187,    -1,    98,   157,   657,   108,   569,   187,    -1,    98,
     157,   194,   187,    -1,    98,   157,   194,   108,   569,   187,
      -1,    62,   157,   657,   187,    -1,    45,   157,   187,    -1,
      45,   157,   657,   187,    -1,    45,   157,   657,   108,   569,
     187,    -1,    45,   157,   657,   108,   570,   187,    -1,    45,
     157,   194,   187,    -1,    45,   157,   194,   108,   569,   187,
      -1,    45,   157,   194,   108,   570,   187,    -1,    63,   157,
     657,   187,    -1,   657,    -1,   657,   145,    -1,    30,    -1,
     573,    -1,   574,    -1,    47,   157,   194,   187,    -1,    47,
     157,   187,    95,   551,    -1,    47,   157,   554,   187,    95,
     551,    -1,   157,   553,   187,    -1,    33,   220,   221,    -1,
      33,   220,   222,    -1,    33,   220,   223,    -1,   226,   225,
     413,   233,   413,    -1,   226,   225,   413,    95,   232,   233,
     413,    -1,   226,   225,   413,    95,   234,   233,   413,    -1,
     226,   225,   413,   218,   413,    -1,   226,   225,   413,   219,
     413,    -1,   226,   227,   413,   233,   413,    -1,   226,   227,
     413,    95,   232,   233,   413,    -1,   226,   227,   413,    95,
     234,   233,   413,    -1,   226,   227,   413,   218,   413,    -1,
     226,   227,   413,   219,   413,    -1,   224,   225,   413,    -1,
     224,   227,   413,    -1,   229,   225,   413,   237,   413,    -1,
     229,   230,   231,   225,   413,   237,   413,    -1,   228,   225,
     413,    95,   413,    -1,   236,   119,   582,   235,   413,   186,
     413,    -1,   583,    -1,   582,   108,   119,   583,    -1,   657,
     143,   413,    -1,   244,   154,   412,   184,   585,    -1,   586,
      -1,   585,   586,    -1,   245,   588,   587,    -1,   154,   412,
     184,    -1,   505,    -1,   588,   210,   505,    -1,   592,   590,
      -1,    -1,   591,    -1,   610,    -1,   591,   610,    -1,   593,
      -1,   592,   262,   593,    -1,   594,    -1,   593,   258,   594,
      -1,   595,    -1,   594,   260,   148,   595,    -1,   596,    -1,
     259,   596,    -1,   600,   597,   598,    -1,    -1,   615,    -1,
      -1,   599,    -1,   282,   154,   412,   184,    -1,   604,   601,
      -1,   157,   589,   187,    -1,   602,    -1,    -1,   637,    -1,
     492,   154,   603,   184,    -1,    -1,   589,    -1,   605,   606,
      -1,   511,    -1,   154,   412,   184,    -1,    -1,   607,    -1,
     248,   608,    -1,   247,   609,    -1,   270,    -1,    -1,    79,
      -1,    -1,   286,    -1,   611,    -1,   612,    -1,   613,    -1,
     639,    -1,   636,    -1,   169,    -1,   284,   475,   614,    -1,
     253,   638,   614,    -1,   286,    -1,   276,    -1,   269,    -1,
     246,   616,    -1,   615,   246,   616,    -1,   617,    -1,   618,
      -1,   619,    -1,   634,    -1,   620,    -1,   628,    -1,   621,
      -1,   635,    -1,   101,   274,    -1,   101,   263,    -1,   266,
      -1,   281,    -1,   251,   274,    -1,   251,   263,    -1,    57,
     657,    30,    -1,   277,    -1,    55,   277,    -1,   279,   622,
      -1,   279,   157,   622,   623,   187,    -1,    55,   279,    -1,
     625,    -1,   114,    -1,    -1,   108,   624,    -1,   625,    -1,
     624,   108,   625,    -1,    97,    30,   626,   627,    -1,    -1,
     271,    30,    -1,    -1,   638,   265,    -1,   278,   286,   629,
     631,    -1,   278,   286,   114,   631,    -1,    55,   278,   286,
      -1,    97,    30,    -1,   157,   630,   187,    -1,    30,    -1,
     630,   108,    30,    -1,    -1,   632,    -1,   633,    -1,   632,
     633,    -1,   201,   629,    -1,   137,   629,    -1,   264,    30,
      -1,   283,    -1,    55,   283,    -1,    97,   217,    -1,    97,
     254,    -1,   255,   250,    -1,   267,   638,   280,    -1,   256,
     475,    -1,    97,   130,   475,    -1,    97,    52,   475,    -1,
     257,   475,   199,   475,    -1,   272,   640,    -1,   252,   640,
      -1,   275,    -1,   268,    -1,   285,   250,   477,    -1,   155,
     185,    -1,   155,   412,   185,    -1,   310,   311,    -1,   310,
     412,   311,    -1,   312,   313,    -1,   312,   412,   313,    -1,
     154,   646,   184,    -1,   413,   122,   413,    -1,   646,   108,
     413,   122,   413,    -1,   226,   314,   413,   233,   413,    -1,
     226,   314,   646,   233,   413,    -1,   226,   314,   413,   233,
     413,    97,   316,   413,    -1,   315,   314,   413,   233,   413,
      -1,   224,   314,   507,    -1,   228,   314,   507,    95,   413,
      -1,   229,   314,   230,   231,   507,   237,   413,    -1,   653,
      -1,   654,    -1,   655,    -1,   319,   157,   187,    -1,   317,
     157,   187,    -1,   318,   157,   187,    -1,    30,    -1,   658,
      -1,    16,    -1,    98,    -1,    39,    -1,    44,    -1,    53,
      -1,    45,    -1,   153,    -1,    48,    -1,   225,    -1,    60,
      -1,    62,    -1,    63,    -1,    71,    -1,    74,    -1,    73,
      -1,   211,    -1,   243,    -1,   659,    -1,    25,    -1,   215,
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
    1125,  1127,  1130,  1133,  1137,  1142,  1144,  1148,  1150,  1153,
    1155,  1157,  1159,  1162,  1165,  1168,  1172,  1174,  1176,  1179,
    1182,  1185,  1191,  1197,  1199,  1204,  1208,  1213,  1222,  1224,
    1227,  1231,  1234,  1238,  1247,  1249,  1252,  1256,  1265,  1276,
    1285,  1296,  1298,  1301,  1306,  1314,  1316,  1319,  1324,  1332,
    1334,  1338,  1347,  1349,  1353,  1355,  1359,  1361,  1365,  1369,
    1373,  1377,  1378,  1383,  1387,  1391,  1395,  1397,  1403,  1405,
    1409,  1410,  1412,  1414,  1418,  1420,  1424,  1428,  1430,  1434,
    1438,  1442,  1446,  1448,  1452,  1456,  1458,  1462,  1466,  1468,
    1473,  1475,  1480,  1482,  1487,  1489,  1494,  1496,  1499,  1501,
    1504,  1506,  1508,  1511,  1514,  1516,  1518,  1520,  1522,  1526,
    1528,  1530,  1532,  1534,  1536,  1538,  1540,  1542,  1544,  1549,
    1555,  1561,  1568,  1572,  1577,  1579,  1582,  1586,  1589,  1592,
    1594,  1597,  1600,  1602,  1604,  1606,  1610,  1614,  1616,  1618,
    1620,  1623,  1625,  1628,  1631,  1633,  1636,  1639,  1642,  1645,
    1648,  1651,  1654,  1656,  1659,  1662,  1664,  1667,  1670,  1673,
    1676,  1679,  1681,  1683,  1685,  1687,  1689,  1691,  1693,  1695,
    1697,  1700,  1704,  1709,  1713,  1715,  1718,  1722,  1724,  1726,
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
         0,   844,   844,   845,   849,   853,   859,   863,   867,   873,
     879,   887,   893,   902,   907,   913,   919,   925,   933,   938,
     946,   954,   962,   971,   976,   982,   988,   997,  1005,  1012,
    1018,  1027,  1028,  1029,  1030,  1031,  1034,  1035,  1036,  1037,
    1038,  1039,  1040,  1041,  1044,  1049,  1055,  1061,  1067,  1072,
    1078,  1083,  1089,  1094,  1100,  1105,  1110,  1115,  1121,  1123,
    1125,  1133,  1138,  1146,  1154,  1163,  1170,  1178,  1184,  1190,
    1196,  1203,  1211,  1222,  1229,  1236,  1244,  1251,  1257,  1266,
    1267,  1268,  1269,  1270,  1271,  1272,  1273,  1276,  1282,  1289,
    1296,  1304,  1312,  1313,  1314,  1315,  1316,  1317,  1318,  1319,
    1320,  1321,  1324,  1338,  1344,  1350,  1357,  1363,  1370,  1375,
    1381,  1387,  1399,  1411,  1424,  1429,  1437,  1445,  1454,  1459,
    1466,  1471,  1478,  1483,  1491,  1496,  1503,  1509,  1518,  1519,
    1522,  1533,  1546,  1558,  1571,  1576,  1581,  1586,  1592,  1599,
    1607,  1612,  1620,  1628,  1636,  1644,  1654,  1658,  1664,  1668,
    1675,  1684,  1695,  1701,  1708,  1713,  1720,  1727,  1736,  1746,
    1756,  1766,  1781,  1797,  1801,  1806,  1811,  1815,  1820,  1825,
    1830,  1838,  1845,  1852,  1865,  1866,  1867,  1868,  1869,  1870,
    1871,  1872,  1873,  1874,  1875,  1876,  1879,  1884,  1891,  1907,
    1913,  1919,  1926,  1933,  1942,  1951,  1960,  1969,  1980,  1986,
    1992,  1998,  2010,  2015,  2021,  2033,  2046,  2066,  2072,  2079,
    2088,  2095,  2100,  2112,  2124,  2125,  2126,  2127,  2128,  2129,
    2132,  2133,  2134,  2135,  2136,  2137,  2138,  2139,  2140,  2141,
    2142,  2143,  2146,  2158,  2164,  2169,  2175,  2180,  2185,  2191,
    2200,  2210,  2222,  2234,  2240,  2241,  2242,  2245,  2246,  2247,
    2248,  2249,  2252,  2259,  2267,  2272,  2281,  2290,  2297,  2304,
    2314,  2324,  2334,  2344,  2354,  2364,  2374,  2384,  2394,  2403,
    2413,  2423,  2435,  2441,  2447,  2453,  2459,  2467,  2475,  2483,
    2491,  2501,  2507,  2516,  2517,  2521,  2528,  2532,  2537,  2540,
    2544,  2548,  2554,  2560,  2566,  2572,  2580,  2584,  2592,  2600,
    2608,  2616,  2626,  2632,  2638,  2646,  2652,  2660,  2664,  2672,
    2678,  2684,  2690,  2699,  2708,  2717,  2728,  2732,  2738,  2744,
    2752,  2758,  2767,  2778,  2784,  2792,  2796,  2805,  2811,  2817,
    2825,  2831,  2837,  2845,  2851,  2857,  2865,  2871,  2878,  2888,
    2895,  2905,  2911,  2919,  2925,  2934,  2940,  2948,  2954,  2963,
    2969,  2977,  2983,  2987,  2993,  2998,  3004,  3008,  3017,  3023,
    3032,  3042,  3041,  3054,  3063,  3072,  3083,  3087,  3098,  3102,
    3108,  3111,  3117,  3121,  3127,  3131,  3135,  3141,  3145,  3151,
    3157,  3163,  3171,  3175,  3179,  3185,  3189,  3195,  3203,  3207,
    3215,  3219,  3227,  3231,  3239,  3243,  3251,  3255,  3261,  3265,
    3271,  3275,  3279,  3283,  3291,  3292,  3293,  3296,  3301,  3307,
    3311,  3315,  3319,  3323,  3327,  3333,  3337,  3341,  3347,  3351,
    3355,  3359,  3368,  3374,  3382,  3388,  3396,  3400,  3404,  3410,
    3414,  3422,  3430,  3448,  3454,  3464,  3468,  3474,  3475,  3478,
    3484,  3492,  3498,  3508,  3514,  3522,  3526,  3530,  3534,  3538,
    3544,  3550,  3556,  3560,  3566,  3570,  3579,  3583,  3587,  3593,
    3597,  3605,  3606,  3609,  3613,  3619,  3623,  3627,  3631,  3637,
    3641,  3645,  3649,  3653,  3659,  3665,  3673,  3679,  3680,  3681,
    3682,  3683,  3684,  3685,  3686,  3687,  3688,  3689,  3690,  3691,
    3692,  3695,  3699,  3705,  3712,  3719,  3728,  3734,  3738,  3744,
    3751,  3757,  3763,  3767,  3785,  3791,  3797,  3803,  3811,  3815,
    3821,  3827,  3837,  3838,  3841,  3842,  3843,  3846,  3854,  3870,
    3878,  3894,  3912,  3932,  3938,  3947,  3953,  3962,  3969,  3970,
    3972,  3977,  3984,  3987,  3993,  3999,  4005,  4012,  4021,  4024,
    4030,  4036,  4042,  4049,  4058,  4062,  4068,  4072,  4078,  4082,
    4086,  4091,  4098,  4102,  4106,  4110,  4116,  4121,  4127,  4133,
    4140,  4146,  4151,  4156,  4161,  4166,  4171,  4176,  4179,  4185,
    4189,  4195,  4199,  4205,  4211,  4217,  4221,  4227,  4231,  4237,
    4243,  4247,  4251,  4257,  4263,  4269,  4277,  4281,  4285,  4289,
    4293,  4297,  4301,  4307,  4313,  4321,  4327,  4333,  4337,  4341,
    4345,  4349,  4353,  4357,  4361,  4365,  4369,  4375,  4381,  4387,
    4391,  4395,  4401,  4406,  4412,  4418,  4422,  4427,  4433,  4437,
    4443,  4449,  4453,  4461,  4467,  4471,  4477,  4486,  4495,  4501,
    4507,  4515,  4521,  4527,  4533,  4539,  4543,  4549,  4555,  4559,
    4567,  4573,  4579,  4585,  4593,  4597,  4603,  4609,  4613,  4619,
    4623,  4629,  4635,  4642,  4650,  4655,  4661,  4667,  4675,  4681,
    4688,  4694,  4703,  4709,  4715,  4721,  4730,  4737,  4743,  4749,
    4758,  4765,  4769,  4775,  4780,  4787,  4791,  4797,  4801,  4807,
    4811,  4817,  4821,  4829,  4840,  4843,  4849,  4852,  4858,  4864,
    4872,  4876,  4882,  4885,  4891,  4901,  4904,  4910,  4920,  4926,
    4934,  4937,  4943,  4947,  4951,  4957,  4960,  4966,  4969,  4975,
    4979,  4983,  4987,  4991,  4997,  5003,  5013,  5023,  5027,  5031,
    5037,  5043,  5051,  5055,  5059,  5063,  5067,  5071,  5075,  5079,
    5085,  5089,  5093,  5097,  5103,  5109,  5117,  5125,  5129,  5135,
    5145,  5156,  5162,  5166,  5172,  5175,  5181,  5186,  5193,  5201,
    5204,  5210,  5214,  5220,  5229,  5236,  5244,  5248,  5254,  5260,
    5268,  5271,  5277,  5282,  5292,  5300,  5310,  5316,  5320,  5326,
    5330,  5334,  5340,  5346,  5350,  5354,  5358,  5364,  5372,  5382,
    5386,  5392,  5398,  5402,  5408,  5412,  5418,  5422,  5428,  5435,
    5441,  5450,  5456,  5466,  5472,  5478,  5499,  5523,  5547,  5551,
    5555,  5561,  5567,  5573,  5579,  5582,  5583,  5584,  5585,  5586,
    5587,  5588,  5589,  5590,  5591,  5592,  5593,  5594,  5595,  5596,
    5597,  5598,  5599,  5602,  5603,  5604,  5605,  5606,  5607,  5608,
    5609,  5610,  5611,  5612,  5613,  5614,  5615,  5616,  5617,  5618,
    5619,  5620,  5621,  5622,  5623,  5624,  5625,  5626,  5627,  5628,
    5629,  5630,  5631,  5632,  5633,  5634,  5635,  5636,  5637,  5638,
    5639,  5640,  5641,  5642,  5643,  5644,  5645,  5646,  5647,  5648,
    5649,  5650,  5651,  5652,  5653,  5654,  5655,  5656,  5657,  5658,
    5659,  5660,  5661,  5662,  5663,  5664,  5665,  5666,  5667,  5668,
    5669,  5670,  5671,  5672,  5673,  5674,  5675,  5676,  5677,  5678,
    5679,  5680,  5681,  5682,  5683,  5684,  5685,  5686,  5687,  5688,
    5689,  5690,  5691,  5692,  5693,  5694,  5695,  5696,  5697,  5698,
    5699,  5700,  5701,  5702,  5703,  5704,  5705,  5706,  5707,  5708,
    5709,  5710,  5711,  5712,  5713,  5714,  5715,  5716,  5717,  5718,
    5719,  5720,  5721,  5722,  5723,  5724,  5725,  5726,  5727,  5728,
    5729,  5730,  5731,  5732,  5733,  5734,  5735,  5736,  5737,  5738,
    5739,  5740,  5741,  5742,  5743,  5744,  5745,  5746,  5747,  5748,
    5749,  5750,  5751,  5752,  5753,  5754,  5755,  5756,  5757,  5758,
    5759,  5760,  5761,  5762,  5763,  5764,  5765,  5766,  5767,  5768,
    5769,  5770,  5771,  5772,  5773,  5774,  5775,  5776,  5777,  5778,
    5779,  5780,  5781,  5782,  5783,  5784,  5785,  5786,  5787,  5788,
    5789,  5790,  5791,  5792,  5793,  5794,  5795,  5796,  5797,  5798,
    5799,  5800,  5801,  5802,  5803,  5804,  5805,  5806,  5807,  5810
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
     325,   326,   327,   328,   329,   330,   331,   332,   333
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int xquery_parser::yyeof_ = 0;
  const int xquery_parser::yylast_ = 17453;
  const int xquery_parser::yynnts_ = 326;
  const int xquery_parser::yyempty_ = -2;
  const int xquery_parser::yyfinal_ = 616;
  const int xquery_parser::yyterror_ = 1;
  const int xquery_parser::yyerrcode_ = 256;
  const int xquery_parser::yyntokens_ = 334;

  const unsigned int xquery_parser::yyuser_token_number_max_ = 588;
  const xquery_parser::token_number_type xquery_parser::yyundef_token_ = 2;


} // zorba

/* Line 1136 of lalr1.cc  */
#line 17645 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"


/* Line 1138 of lalr1.cc  */
#line 5812 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"

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

