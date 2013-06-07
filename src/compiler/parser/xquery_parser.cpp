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
      case 507: /* "FilterExpr" */

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

  case 128:

/* Line 690 of lalr1.cc  */
#line 1519 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 129:

/* Line 690 of lalr1.cc  */
#line 1524 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 130:

/* Line 690 of lalr1.cc  */
#line 1530 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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
#line 1541 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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
#line 1554 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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
#line 1566 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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
#line 1579 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(NULL);
    }
    break;

  case 135:

/* Line 690 of lalr1.cc  */
#line 1584 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (2)].node)));
    }
    break;

  case 136:

/* Line 690 of lalr1.cc  */
#line 1589 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(NULL, dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node)));
    }
    break;

  case 137:

/* Line 690 of lalr1.cc  */
#line 1594 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(dynamic_cast<ParamList*>((yysemantic_stack_[(5) - (2)].node)), dynamic_cast<SequenceType*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 138:

/* Line 690 of lalr1.cc  */
#line 1600 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      ParamList *pl = new ParamList( LOC((yyloc)) );
      pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = pl;
    }
    break;

  case 139:

/* Line 690 of lalr1.cc  */
#line 1607 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      if ( ParamList *pl = dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (1)].node)) )
        pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(3) - (3)].node)) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 140:

/* Line 690 of lalr1.cc  */
#line 1615 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL);
    }
    break;

  case 141:

/* Line 690 of lalr1.cc  */
#line 1620 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)),
                     static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                     dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 142:

/* Line 690 of lalr1.cc  */
#line 1628 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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
#line 1636 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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
#line 1644 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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
#line 1652 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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
#line 1662 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL));
    }
    break;

  case 147:

/* Line 690 of lalr1.cc  */
#line 1666 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)),
                                                    (yysemantic_stack_[(2) - (1)].node),
                                                    dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node))));
    }
    break;

  case 148:

/* Line 690 of lalr1.cc  */
#line 1672 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL));
    }
    break;

  case 149:

/* Line 690 of lalr1.cc  */
#line 1676 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)),
                                                    (yysemantic_stack_[(2) - (1)].node),
                                                    dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node))));
    }
    break;

  case 150:

/* Line 690 of lalr1.cc  */
#line 1683 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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
#line 1692 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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
#line 1703 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      IndexKeyList* keyList = new IndexKeyList(LOC((yyloc)));
      keyList->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = keyList;
    }
    break;

  case 153:

/* Line 690 of lalr1.cc  */
#line 1709 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<IndexKeyList*>((yysemantic_stack_[(3) - (1)].node))->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 154:

/* Line 690 of lalr1.cc  */
#line 1716 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL, NULL);
    }
    break;

  case 155:

/* Line 690 of lalr1.cc  */
#line 1721 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            dynamic_cast<SequenceType*>((yysemantic_stack_[(2) - (2)].node)),
                            NULL);
    }
    break;

  case 156:

/* Line 690 of lalr1.cc  */
#line 1728 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            NULL,
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
    }
    break;

  case 157:

/* Line 690 of lalr1.cc  */
#line 1735 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(3) - (1)].expr),
                            dynamic_cast<SequenceType*>((yysemantic_stack_[(3) - (2)].node)),
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 158:

/* Line 690 of lalr1.cc  */
#line 1745 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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
#line 1755 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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
#line 1765 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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
#line 1776 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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
#line 1789 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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
#line 1805 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 164:

/* Line 690 of lalr1.cc  */
#line 1809 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 165:

/* Line 690 of lalr1.cc  */
#line 1813 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = NULL;
    }
    break;

  case 166:

/* Line 690 of lalr1.cc  */
#line 1819 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 167:

/* Line 690 of lalr1.cc  */
#line 1823 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 168:

/* Line 690 of lalr1.cc  */
#line 1827 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new BlockBody(LOC((yyloc)));
    }
    break;

  case 169:

/* Line 690 of lalr1.cc  */
#line 1833 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 170:

/* Line 690 of lalr1.cc  */
#line 1838 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      BlockBody* blk = static_cast<BlockBody*>((yysemantic_stack_[(2) - (1)].expr));
      blk->add((yysemantic_stack_[(2) - (2)].expr));
      (yyval.expr) = blk;
    }
    break;

  case 171:

/* Line 690 of lalr1.cc  */
#line 1846 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      BlockBody* blk = new BlockBody(LOC((yyloc)));
      blk->add((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = blk;
    }
    break;

  case 172:

/* Line 690 of lalr1.cc  */
#line 1853 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      BlockBody* blk = static_cast<BlockBody*>((yysemantic_stack_[(2) - (1)].expr));
      blk->add((yysemantic_stack_[(2) - (2)].expr));
      (yyval.expr) = blk;
    }
    break;

  case 173:

/* Line 690 of lalr1.cc  */
#line 1860 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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
#line 1887 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 187:

/* Line 690 of lalr1.cc  */
#line 1892 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      driver.addCommonLanguageWarning((yylocation_stack_[(2) - (1)]), ZED(ZWST0009_EMPTY_BLOCK));
      (yyval.expr) = new BlockBody(LOC((yyloc)));
    }
    break;

  case 188:

/* Line 690 of lalr1.cc  */
#line 1899 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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
#line 1915 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 190:

/* Line 690 of lalr1.cc  */
#line 1921 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    }
    break;

  case 191:

/* Line 690 of lalr1.cc  */
#line 1927 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      VarDeclStmt* vdecl = static_cast<VarDeclStmt*>((yysemantic_stack_[(3) - (1)].expr));
      vdecl->add((yysemantic_stack_[(3) - (3)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 192:

/* Line 690 of lalr1.cc  */
#line 1934 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      VarDeclStmt* vdecl = new VarDeclStmt(LOC((yyloc)), NULL);
      vdecl->add((yysemantic_stack_[(2) - (2)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 193:

/* Line 690 of lalr1.cc  */
#line 1941 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      VarDeclStmt* vdecl = new VarDeclStmt(LOC((yyloc)),
                                           static_cast<AnnotationListParsenode*>((yysemantic_stack_[(3) - (1)].node)));
      vdecl->add((yysemantic_stack_[(3) - (3)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 194:

/* Line 690 of lalr1.cc  */
#line 1950 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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
#line 1959 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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
#line 1968 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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
#line 1977 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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
#line 1988 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new AssignExpr(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)), (yysemantic_stack_[(5) - (4)].expr));
    }
    break;

  case 199:

/* Line 690 of lalr1.cc  */
#line 1994 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ApplyExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr));
    }
    break;

  case 200:

/* Line 690 of lalr1.cc  */
#line 2000 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ExitExpr(LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr));
    }
    break;

  case 201:

/* Line 690 of lalr1.cc  */
#line 2006 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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
#line 2018 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement(LOC((yyloc)), FlowCtlStatement::BREAK);
    }
    break;

  case 203:

/* Line 690 of lalr1.cc  */
#line 2023 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement( LOC((yyloc)), FlowCtlStatement::CONTINUE );
    }
    break;

  case 204:

/* Line 690 of lalr1.cc  */
#line 2029 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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
#line 2041 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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
#line 2054 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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
#line 2074 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TryExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 208:

/* Line 690 of lalr1.cc  */
#line 2080 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      CatchListExpr* cle = new CatchListExpr( LOC((yyloc)) );
      cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)) );
      (yyval.expr) = cle;
    }
    break;

  case 209:

/* Line 690 of lalr1.cc  */
#line 2087 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
      if ( cle )
        cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)) );
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    }
    break;

  case 210:

/* Line 690 of lalr1.cc  */
#line 2096 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)), *(yysemantic_stack_[(3) - (2)].name_test_list), (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 211:

/* Line 690 of lalr1.cc  */
#line 2103 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 212:

/* Line 690 of lalr1.cc  */
#line 2108 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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
#line 2120 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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
#line 2154 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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
#line 2166 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ReturnExpr( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr) );
    }
    break;

  case 234:

/* Line 690 of lalr1.cc  */
#line 2172 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_sliding;
    }
    break;

  case 235:

/* Line 690 of lalr1.cc  */
#line 2177 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_tumbling;
    }
    break;

  case 236:

/* Line 690 of lalr1.cc  */
#line 2183 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_start;
    }
    break;

  case 237:

/* Line 690 of lalr1.cc  */
#line 2188 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_end;
    }
    break;

  case 238:

/* Line 690 of lalr1.cc  */
#line 2193 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
    (yyval.strval) = parser::the_only_end;
  }
    break;

  case 239:

/* Line 690 of lalr1.cc  */
#line 2199 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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
#line 2208 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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
#line 2219 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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
#line 2231 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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
#line 2242 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CountClause(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 252:

/* Line 690 of lalr1.cc  */
#line 2260 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      FLWORClauseList *fcl = new FLWORClauseList( LOC((yyloc)) );
      fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = fcl;
    }
    break;

  case 253:

/* Line 690 of lalr1.cc  */
#line 2267 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      FLWORClauseList *fcl = dynamic_cast<FLWORClauseList*>((yysemantic_stack_[(2) - (1)].node));
      fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = fcl;
    }
    break;

  case 254:

/* Line 690 of lalr1.cc  */
#line 2276 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ForClause(LOC((yyloc)), dynamic_cast<VarInDeclList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 255:

/* Line 690 of lalr1.cc  */
#line 2280 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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
#line 2290 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = NULL;
      error((yylocation_stack_[(2) - (2)]), "");
      YYERROR;
    }
    break;

  case 257:

/* Line 690 of lalr1.cc  */
#line 2298 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      VarInDeclList* vdl = new VarInDeclList( LOC((yyloc)) );
      vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = vdl;
    }
    break;

  case 258:

/* Line 690 of lalr1.cc  */
#line 2305 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      if ( VarInDeclList* vdl = dynamic_cast<VarInDeclList*>((yysemantic_stack_[(4) - (1)].node)) )
        vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
      (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
    }
    break;

  case 259:

/* Line 690 of lalr1.cc  */
#line 2312 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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
#line 2322 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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
#line 2332 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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
#line 2342 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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
#line 2352 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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
#line 2362 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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
#line 2372 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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
#line 2382 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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
#line 2392 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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
#line 2402 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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
#line 2411 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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
#line 2421 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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
#line 2431 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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
#line 2443 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new PositionalVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 273:

/* Line 690 of lalr1.cc  */
#line 2449 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTScoreVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 274:

/* Line 690 of lalr1.cc  */
#line 2455 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new LetClause( LOC((yyloc)), dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(2) - (2)].node)) );
        }
    break;

  case 275:

/* Line 690 of lalr1.cc  */
#line 2461 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            VarGetsDeclList *vgdl = new VarGetsDeclList( LOC((yyloc)) );
            vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = vgdl;
        }
    break;

  case 276:

/* Line 690 of lalr1.cc  */
#line 2467 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            if( VarGetsDeclList *vgdl = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(3) - (1)].node)) )
                vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 277:

/* Line 690 of lalr1.cc  */
#line 2475 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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
#line 2483 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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
#line 2491 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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
#line 2499 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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
#line 2509 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                             NULL, (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 282:

/* Line 690 of lalr1.cc  */
#line 2515 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                             dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (3)].node)),
                             (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 284:

/* Line 690 of lalr1.cc  */
#line 2525 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL, NULL);
    }
    break;

  case 285:

/* Line 690 of lalr1.cc  */
#line 2529 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_curr(static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)));
    }
    break;

  case 286:

/* Line 690 of lalr1.cc  */
#line 2536 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), dynamic_cast<PositionalVar*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL, NULL);
    }
    break;

  case 287:

/* Line 690 of lalr1.cc  */
#line 2540 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_posvar(dynamic_cast<PositionalVar*>((yysemantic_stack_[(2) - (1)].node)));
    }
    break;

  case 289:

/* Line 690 of lalr1.cc  */
#line 2548 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), static_cast<QName*>((yysemantic_stack_[(6) - (6)].expr)));
    }
    break;

  case 290:

/* Line 690 of lalr1.cc  */
#line 2552 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 291:

/* Line 690 of lalr1.cc  */
#line 2556 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)), NULL);
    }
    break;

  case 292:

/* Line 690 of lalr1.cc  */
#line 2562 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WhereClause(LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 293:

/* Line 690 of lalr1.cc  */
#line 2568 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupByClause(LOC((yyloc)), dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 294:

/* Line 690 of lalr1.cc  */
#line 2574 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      GroupSpecList* gsl = new GroupSpecList(LOC((yyloc)));
      gsl->push_back(static_cast<GroupSpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = gsl;
    }
    break;

  case 295:

/* Line 690 of lalr1.cc  */
#line 2580 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      GroupSpecList* gsl = static_cast<GroupSpecList*>((yysemantic_stack_[(3) - (1)].node));
      gsl->push_back(static_cast<GroupSpec*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = gsl;
    }
    break;

  case 296:

/* Line 690 of lalr1.cc  */
#line 2588 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL, NULL, NULL);
    }
    break;

  case 297:

/* Line 690 of lalr1.cc  */
#line 2592 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)), NULL, (yysemantic_stack_[(4) - (4)].expr), NULL);
    }
    break;

  case 298:

/* Line 690 of lalr1.cc  */
#line 2596 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                         static_cast<SequenceType*>((yysemantic_stack_[(5) - (3)].node)),
                         (yysemantic_stack_[(5) - (5)].expr),
                         NULL);
    }
    break;

  case 299:

/* Line 690 of lalr1.cc  */
#line 2604 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                         static_cast<SequenceType*>((yysemantic_stack_[(6) - (3)].node)),
                         (yysemantic_stack_[(6) - (5)].expr),
                         static_cast<GroupCollationSpec*>((yysemantic_stack_[(6) - (6)].node)));
    }
    break;

  case 300:

/* Line 690 of lalr1.cc  */
#line 2612 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                         NULL,
                         (yysemantic_stack_[(5) - (4)].expr),
                         static_cast<GroupCollationSpec*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 301:

/* Line 690 of lalr1.cc  */
#line 2620 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                         NULL,
                         NULL,
                         static_cast<GroupCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 302:

/* Line 690 of lalr1.cc  */
#line 2630 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
    }
    break;

  case 303:

/* Line 690 of lalr1.cc  */
#line 2636 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 304:

/* Line 690 of lalr1.cc  */
#line 2642 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(4) - (4)].node)), true
            );
        }
    break;

  case 305:

/* Line 690 of lalr1.cc  */
#line 2650 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            OrderSpecList *osl = new OrderSpecList( LOC((yyloc)) );
            osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = osl;
        }
    break;

  case 306:

/* Line 690 of lalr1.cc  */
#line 2656 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            if ( OrderSpecList* osl = dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (1)].node)) )
                osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 307:

/* Line 690 of lalr1.cc  */
#line 2664 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderSpec( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL );
        }
    break;

  case 308:

/* Line 690 of lalr1.cc  */
#line 2668 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderSpec(
                LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<OrderModifierPN*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 309:

/* Line 690 of lalr1.cc  */
#line 2676 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL
            );
        }
    break;

  case 310:

/* Line 690 of lalr1.cc  */
#line 2682 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 311:

/* Line 690 of lalr1.cc  */
#line 2688 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, NULL, dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 312:

/* Line 690 of lalr1.cc  */
#line 2694 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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
#line 2703 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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
#line 2712 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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
#line 2721 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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
#line 2732 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_ascending );
        }
    break;

  case 317:

/* Line 690 of lalr1.cc  */
#line 2736 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_descending );
        }
    break;

  case 318:

/* Line 690 of lalr1.cc  */
#line 2742 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_greatest
            );
        }
    break;

  case 319:

/* Line 690 of lalr1.cc  */
#line 2748 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_least
            );
        }
    break;

  case 320:

/* Line 690 of lalr1.cc  */
#line 2756 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 321:

/* Line 690 of lalr1.cc  */
#line 2762 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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
#line 2771 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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
#line 2782 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      QVarInDeclList *qvidl = new QVarInDeclList( LOC((yyloc)) );
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = qvidl;
    }
    break;

  case 324:

/* Line 690 of lalr1.cc  */
#line 2788 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      QVarInDeclList *qvidl = dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
      (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
    }
    break;

  case 325:

/* Line 690 of lalr1.cc  */
#line 2796 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 326:

/* Line 690 of lalr1.cc  */
#line 2800 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                          dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 327:

/* Line 690 of lalr1.cc  */
#line 2809 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new SwitchExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(8) - (5)].node)), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 328:

/* Line 690 of lalr1.cc  */
#line 2815 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = new SwitchCaseClauseList(LOC((yyloc)));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = scc_list_p;
    }
    break;

  case 329:

/* Line 690 of lalr1.cc  */
#line 2821 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 330:

/* Line 690 of lalr1.cc  */
#line 2829 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SwitchCaseClause(LOC((yyloc)), dynamic_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 331:

/* Line 690 of lalr1.cc  */
#line 2835 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = new SwitchCaseOperandList(LOC((yyloc)));
      sco_list_p->push_back((yysemantic_stack_[(2) - (2)].expr));
      (yyval.node) = sco_list_p;
    }
    break;

  case 332:

/* Line 690 of lalr1.cc  */
#line 2841 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = static_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node));
      sco_list_p->push_back((yysemantic_stack_[(3) - (3)].expr));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 333:

/* Line 690 of lalr1.cc  */
#line 2849 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new SwitchExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(8) - (5)].node)), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 334:

/* Line 690 of lalr1.cc  */
#line 2855 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = new SwitchCaseClauseList(LOC((yyloc)));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = scc_list_p;
    }
    break;

  case 335:

/* Line 690 of lalr1.cc  */
#line 2861 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 336:

/* Line 690 of lalr1.cc  */
#line 2869 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SwitchCaseClause(LOC((yyloc)), dynamic_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 337:

/* Line 690 of lalr1.cc  */
#line 2875 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC((yyloc)),
                              (yysemantic_stack_[(8) - (3)].expr),
                              static_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
                              (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 338:

/* Line 690 of lalr1.cc  */
#line 2882 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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
#line 2892 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC((yyloc)),
                              (yysemantic_stack_[(8) - (3)].expr),
                              static_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
                              (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 340:

/* Line 690 of lalr1.cc  */
#line 2899 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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
#line 2909 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
      cc_list_p->push_back(static_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = cc_list_p;
    }
    break;

  case 342:

/* Line 690 of lalr1.cc  */
#line 2915 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      cc_list_p->push_back(static_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 343:

/* Line 690 of lalr1.cc  */
#line 2923 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<SequenceTypeList*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 344:

/* Line 690 of lalr1.cc  */
#line 2929 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                          static_cast<SequenceTypeList*>((yysemantic_stack_[(7) - (5)].node)),
                          (yysemantic_stack_[(7) - (7)].expr));
     }
    break;

  case 345:

/* Line 690 of lalr1.cc  */
#line 2938 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
      cc_list_p->push_back(static_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = cc_list_p;
    }
    break;

  case 346:

/* Line 690 of lalr1.cc  */
#line 2944 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = static_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      cc_list_p->push_back(static_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 347:

/* Line 690 of lalr1.cc  */
#line 2952 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<SequenceTypeList*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 348:

/* Line 690 of lalr1.cc  */
#line 2958 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                          static_cast<SequenceTypeList*>((yysemantic_stack_[(7) - (5)].node)),
                          (yysemantic_stack_[(7) - (7)].expr));
     }
    break;

  case 349:

/* Line 690 of lalr1.cc  */
#line 2967 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      SequenceTypeList* seqList = new SequenceTypeList(LOC((yyloc)));
      seqList->push_back(static_cast<SequenceType*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = seqList;
    }
    break;

  case 350:

/* Line 690 of lalr1.cc  */
#line 2973 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      SequenceTypeList* seqList = static_cast<SequenceTypeList*>((yysemantic_stack_[(3) - (1)].node));
      seqList->push_back(static_cast<SequenceType*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 351:

/* Line 690 of lalr1.cc  */
#line 2981 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new IfExpr(LOC ((yyloc)), (yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (6)].expr), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 352:

/* Line 690 of lalr1.cc  */
#line 2987 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 353:

/* Line 690 of lalr1.cc  */
#line 2991 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new OrExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
    }
    break;

  case 354:

/* Line 690 of lalr1.cc  */
#line 2997 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 355:

/* Line 690 of lalr1.cc  */
#line 3002 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AndExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 356:

/* Line 690 of lalr1.cc  */
#line 3008 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 357:

/* Line 690 of lalr1.cc  */
#line 3012 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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
#line 3021 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)), dynamic_cast<NodeComp*>((yysemantic_stack_[(3) - (2)].node)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 359:

/* Line 690 of lalr1.cc  */
#line 3027 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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
#line 3036 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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
#line 3045 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            driver.getXqueryLexer()->interpretAsLessThan();
        }
    break;

  case 362:

/* Line 690 of lalr1.cc  */
#line 3049 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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
#line 3058 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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
#line 3067 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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
#line 3076 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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
#line 3087 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 367:

/* Line 690 of lalr1.cc  */
#line 3091 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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
#line 3102 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 369:

/* Line 690 of lalr1.cc  */
#line 3106 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new StringConcatExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
        }
    break;

  case 370:

/* Line 690 of lalr1.cc  */
#line 3111 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 371:

/* Line 690 of lalr1.cc  */
#line 3115 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 372:

/* Line 690 of lalr1.cc  */
#line 3121 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 373:

/* Line 690 of lalr1.cc  */
#line 3125 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RangeExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 374:

/* Line 690 of lalr1.cc  */
#line 3131 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 375:

/* Line 690 of lalr1.cc  */
#line 3135 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_plus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 376:

/* Line 690 of lalr1.cc  */
#line 3139 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_minus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 377:

/* Line 690 of lalr1.cc  */
#line 3145 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 378:

/* Line 690 of lalr1.cc  */
#line 3149 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mul, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 379:

/* Line 690 of lalr1.cc  */
#line 3155 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_div, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 380:

/* Line 690 of lalr1.cc  */
#line 3161 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_idiv, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 381:

/* Line 690 of lalr1.cc  */
#line 3167 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mod, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 382:

/* Line 690 of lalr1.cc  */
#line 3175 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 383:

/* Line 690 of lalr1.cc  */
#line 3179 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 384:

/* Line 690 of lalr1.cc  */
#line 3183 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 385:

/* Line 690 of lalr1.cc  */
#line 3189 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 386:

/* Line 690 of lalr1.cc  */
#line 3193 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_intersect, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 387:

/* Line 690 of lalr1.cc  */
#line 3199 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_except, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 388:

/* Line 690 of lalr1.cc  */
#line 3207 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 389:

/* Line 690 of lalr1.cc  */
#line 3211 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InstanceofExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 390:

/* Line 690 of lalr1.cc  */
#line 3219 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 391:

/* Line 690 of lalr1.cc  */
#line 3223 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new TreatExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 392:

/* Line 690 of lalr1.cc  */
#line 3231 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 393:

/* Line 690 of lalr1.cc  */
#line 3235 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CastableExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 394:

/* Line 690 of lalr1.cc  */
#line 3243 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 395:

/* Line 690 of lalr1.cc  */
#line 3247 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CastExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 396:

/* Line 690 of lalr1.cc  */
#line 3255 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SingleType(LOC((yyloc)), dynamic_cast<SimpleType*>((yysemantic_stack_[(1) - (1)].node)), false);
    }
    break;

  case 397:

/* Line 690 of lalr1.cc  */
#line 3259 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SingleType(LOC((yyloc)), dynamic_cast<SimpleType*>((yysemantic_stack_[(2) - (1)].node)), true);
    }
    break;

  case 398:

/* Line 690 of lalr1.cc  */
#line 3265 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 399:

/* Line 690 of lalr1.cc  */
#line 3269 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnaryExpr( LOC((yyloc)), dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 400:

/* Line 690 of lalr1.cc  */
#line 3275 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), true );
        }
    break;

  case 401:

/* Line 690 of lalr1.cc  */
#line 3279 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), false );
        }
    break;

  case 402:

/* Line 690 of lalr1.cc  */
#line 3283 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 403:

/* Line 690 of lalr1.cc  */
#line 3287 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            if ( SignList *sl = dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)) )
                sl->negate();
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 404:

/* Line 690 of lalr1.cc  */
#line 3295 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 405:

/* Line 690 of lalr1.cc  */
#line 3299 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 406:

/* Line 690 of lalr1.cc  */
#line 3303 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 407:

/* Line 690 of lalr1.cc  */
#line 3309 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
        (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
      }
    break;

  case 408:

/* Line 690 of lalr1.cc  */
#line 3314 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
        (yyval.expr) = new SimpleMapExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
      }
    break;

  case 409:

/* Line 690 of lalr1.cc  */
#line 3320 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_eq );
        }
    break;

  case 410:

/* Line 690 of lalr1.cc  */
#line 3324 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ne );
        }
    break;

  case 411:

/* Line 690 of lalr1.cc  */
#line 3328 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_lt );
        }
    break;

  case 412:

/* Line 690 of lalr1.cc  */
#line 3332 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_le );
        }
    break;

  case 413:

/* Line 690 of lalr1.cc  */
#line 3336 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_gt );
        }
    break;

  case 414:

/* Line 690 of lalr1.cc  */
#line 3340 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ge );
        }
    break;

  case 415:

/* Line 690 of lalr1.cc  */
#line 3346 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_is );
        }
    break;

  case 416:

/* Line 690 of lalr1.cc  */
#line 3350 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_precedes );
        }
    break;

  case 417:

/* Line 690 of lalr1.cc  */
#line 3354 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_follows );
        }
    break;

  case 418:

/* Line 690 of lalr1.cc  */
#line 3360 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 419:

/* Line 690 of lalr1.cc  */
#line 3364 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "lax", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 420:

/* Line 690 of lalr1.cc  */
#line 3368 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 421:

/* Line 690 of lalr1.cc  */
#line 3372 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr(
                LOC((yyloc)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (3)].node))->get_name(), (yysemantic_stack_[(6) - (5)].expr)
            );
            delete (yysemantic_stack_[(6) - (3)].node);
        }
    break;

  case 422:

/* Line 690 of lalr1.cc  */
#line 3381 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(3) - (1)].node)), NULL
            );
        }
    break;

  case 423:

/* Line 690 of lalr1.cc  */
#line 3387 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)), (yysemantic_stack_[(4) - (3)].expr)
            );
        }
    break;

  case 424:

/* Line 690 of lalr1.cc  */
#line 3395 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            PragmaList *pl = new PragmaList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = pl;
        }
    break;

  case 425:

/* Line 690 of lalr1.cc  */
#line 3401 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            if ( PragmaList *pl = dynamic_cast<PragmaList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 426:

/* Line 690 of lalr1.cc  */
#line 3409 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
        }
    break;

  case 427:

/* Line 690 of lalr1.cc  */
#line 3413 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) ), "" );
        }
    break;

  case 428:

/* Line 690 of lalr1.cc  */
#line 3417 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), true ), "" );
        }
    break;

  case 429:

/* Line 690 of lalr1.cc  */
#line 3423 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new PathExpr(LOC((yyloc)), ParseConstants::path_leading_lone_slash, NULL);
    }
    break;

  case 430:

/* Line 690 of lalr1.cc  */
#line 3427 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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
#line 3435 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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
#line 3443 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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
#line 3461 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = NULL;
    }
    break;

  case 434:

/* Line 690 of lalr1.cc  */
#line 3467 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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
#line 3477 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr), false);
    }
    break;

  case 436:

/* Line 690 of lalr1.cc  */
#line 3481 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slashslash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr), false);
    }
    break;

  case 437:

/* Line 690 of lalr1.cc  */
#line 3487 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 438:

/* Line 690 of lalr1.cc  */
#line 3491 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 439:

/* Line 690 of lalr1.cc  */
#line 3497 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)), dynamic_cast<ForwardStep*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 440:

/* Line 690 of lalr1.cc  */
#line 3503 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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
#line 3511 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)), dynamic_cast<ReverseStep*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 442:

/* Line 690 of lalr1.cc  */
#line 3517 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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
#line 3527 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardStep(
                LOC((yyloc)), dynamic_cast<ForwardAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node)
            );
        }
    break;

  case 444:

/* Line 690 of lalr1.cc  */
#line 3533 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardStep(
                LOC((yyloc)), dynamic_cast<AbbrevForwardStep*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 445:

/* Line 690 of lalr1.cc  */
#line 3541 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_child );
        }
    break;

  case 446:

/* Line 690 of lalr1.cc  */
#line 3545 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_descendant);
        }
    break;

  case 447:

/* Line 690 of lalr1.cc  */
#line 3549 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_attribute );
        }
    break;

  case 448:

/* Line 690 of lalr1.cc  */
#line 3553 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_self );
        }
    break;

  case 449:

/* Line 690 of lalr1.cc  */
#line 3557 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis(
                LOC((yyloc)), ParseConstants::axis_descendant_or_self
            );
        }
    break;

  case 450:

/* Line 690 of lalr1.cc  */
#line 3563 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis(
                LOC((yyloc)), ParseConstants::axis_following_sibling
            );
        }
    break;

  case 451:

/* Line 690 of lalr1.cc  */
#line 3569 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_following );
        }
    break;

  case 452:

/* Line 690 of lalr1.cc  */
#line 3575 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AbbrevForwardStep( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), false );
        }
    break;

  case 453:

/* Line 690 of lalr1.cc  */
#line 3579 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AbbrevForwardStep( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].node), true );
        }
    break;

  case 454:

/* Line 690 of lalr1.cc  */
#line 3585 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseStep( LOC((yyloc)), dynamic_cast<ReverseAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node) );
        }
    break;

  case 455:

/* Line 690 of lalr1.cc  */
#line 3589 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            ReverseAxis *ra = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_parent
            );
            (yyval.node) = new ReverseStep( LOC((yyloc)), ra, NULL );
        }
    break;

  case 456:

/* Line 690 of lalr1.cc  */
#line 3598 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_parent );
        }
    break;

  case 457:

/* Line 690 of lalr1.cc  */
#line 3602 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_ancestor );
        }
    break;

  case 458:

/* Line 690 of lalr1.cc  */
#line 3606 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_preceding_sibling
            );
        }
    break;

  case 459:

/* Line 690 of lalr1.cc  */
#line 3612 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_preceding );
        }
    break;

  case 460:

/* Line 690 of lalr1.cc  */
#line 3616 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_ancestor_or_self
            );
        }
    break;

  case 461:

/* Line 690 of lalr1.cc  */
#line 3624 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 462:

/* Line 690 of lalr1.cc  */
#line 3628 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 463:

/* Line 690 of lalr1.cc  */
#line 3634 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 464:

/* Line 690 of lalr1.cc  */
#line 3638 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), dynamic_cast<Wildcard*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 465:

/* Line 690 of lalr1.cc  */
#line 3644 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", "", ParseConstants::wild_all, false);
    }
    break;

  case 466:

/* Line 690 of lalr1.cc  */
#line 3648 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), "", ParseConstants::wild_elem, false);
    }
    break;

  case 467:

/* Line 690 of lalr1.cc  */
#line 3652 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), "", ParseConstants::wild_elem, true);
    }
    break;

  case 468:

/* Line 690 of lalr1.cc  */
#line 3656 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", SYMTAB((yysemantic_stack_[(1) - (1)].sval)), ParseConstants::wild_prefix, false);
    }
    break;

  case 469:

/* Line 690 of lalr1.cc  */
#line 3662 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
     }
    break;

  case 470:

/* Line 690 of lalr1.cc  */
#line 3666 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new FilterExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
     }
    break;

  case 471:

/* Line 690 of lalr1.cc  */
#line 3670 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DynamicFunctionInvocation(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), false);
     }
    break;

  case 472:

/* Line 690 of lalr1.cc  */
#line 3674 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DynamicFunctionInvocation(LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node)), false);
     }
    break;

  case 473:

/* Line 690 of lalr1.cc  */
#line 3678 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new JSONArrayUnboxing(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr));
    }
    break;

  case 474:

/* Line 690 of lalr1.cc  */
#line 3684 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      PredicateList* pl = new PredicateList( LOC((yyloc)) );
      pl->push_back(dynamic_cast<exprnode*>((yysemantic_stack_[(1) - (1)].expr)));
      (yyval.node) = pl;
    }
    break;

  case 475:

/* Line 690 of lalr1.cc  */
#line 3690 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      if (PredicateList* pl = dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (1)].node)))
        pl->push_back(dynamic_cast<exprnode*>((yysemantic_stack_[(2) - (2)].expr)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 476:

/* Line 690 of lalr1.cc  */
#line 3698 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 477:

/* Line 690 of lalr1.cc  */
#line 3704 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 478:

/* Line 690 of lalr1.cc  */
#line 3708 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 479:

/* Line 690 of lalr1.cc  */
#line 3712 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 480:

/* Line 690 of lalr1.cc  */
#line 3716 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 481:

/* Line 690 of lalr1.cc  */
#line 3720 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 482:

/* Line 690 of lalr1.cc  */
#line 3724 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 483:

/* Line 690 of lalr1.cc  */
#line 3728 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 484:

/* Line 690 of lalr1.cc  */
#line 3732 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 485:

/* Line 690 of lalr1.cc  */
#line 3736 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 486:

/* Line 690 of lalr1.cc  */
#line 3740 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 487:

/* Line 690 of lalr1.cc  */
#line 3744 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 488:

/* Line 690 of lalr1.cc  */
#line 3748 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 489:

/* Line 690 of lalr1.cc  */
#line 3752 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 490:

/* Line 690 of lalr1.cc  */
#line 3756 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 491:

/* Line 690 of lalr1.cc  */
#line 3762 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 492:

/* Line 690 of lalr1.cc  */
#line 3766 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 493:

/* Line 690 of lalr1.cc  */
#line 3772 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_decimal, *(yysemantic_stack_[(1) - (1)].decval)
            );
            delete yylval.decval;
        }
    break;

  case 494:

/* Line 690 of lalr1.cc  */
#line 3779 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_integer, *(yysemantic_stack_[(1) - (1)].ival)
            );
            delete yylval.ival;
        }
    break;

  case 495:

/* Line 690 of lalr1.cc  */
#line 3786 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_double, *(yysemantic_stack_[(1) - (1)].dval)
            );
            delete yylval.dval;
        }
    break;

  case 496:

/* Line 690 of lalr1.cc  */
#line 3795 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new VarRef(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)));
        }
    break;

  case 497:

/* Line 690 of lalr1.cc  */
#line 3801 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), NULL);
        }
    break;

  case 498:

/* Line 690 of lalr1.cc  */
#line 3805 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 499:

/* Line 690 of lalr1.cc  */
#line 3811 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            driver.addCommonLanguageWarning((yylocation_stack_[(1) - (1)]), ZED(ZWST0009_CONTEXT_ITEM_EXPR));
            (yyval.expr) = new ContextItemExpr( LOC((yyloc)) );
        }
    break;

  case 500:

/* Line 690 of lalr1.cc  */
#line 3818 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new OrderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 501:

/* Line 690 of lalr1.cc  */
#line 3824 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnorderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 502:

/* Line 690 of lalr1.cc  */
#line 3830 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FunctionCall( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), NULL );
    }
    break;

  case 503:

/* Line 690 of lalr1.cc  */
#line 3834 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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
#line 3852 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      ArgList *al = new ArgList( LOC((yyloc)) );
      al->push_back(new ArgumentPlaceholder(LOC((yyloc))));
      (yyval.node) = al;
    }
    break;

  case 505:

/* Line 690 of lalr1.cc  */
#line 3858 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      if ( ArgList *al = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node)) )
        al->push_back( new ArgumentPlaceholder(LOC((yyloc))) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 506:

/* Line 690 of lalr1.cc  */
#line 3864 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      ArgList *al = new ArgList( LOC((yyloc)) );
      al->push_back( (yysemantic_stack_[(1) - (1)].expr) );
      (yyval.node) = al;
    }
    break;

  case 507:

/* Line 690 of lalr1.cc  */
#line 3870 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      if ( ArgList *al = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node)) )
        al->push_back( (yysemantic_stack_[(3) - (3)].expr) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 508:

/* Line 690 of lalr1.cc  */
#line 3878 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 509:

/* Line 690 of lalr1.cc  */
#line 3882 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 510:

/* Line 690 of lalr1.cc  */
#line 3888 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new LiteralFunctionItem(LOC ((yyloc)), dynamic_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].ival));
    }
    break;

  case 511:

/* Line 690 of lalr1.cc  */
#line 3894 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new InlineFunction(LOC((yyloc)),
                              &*(yysemantic_stack_[(3) - (2)].fnsig)->theParams,
                              &*(yysemantic_stack_[(3) - (2)].fnsig)->theReturnType,
                              (yysemantic_stack_[(3) - (3)].expr));
      delete (yysemantic_stack_[(3) - (2)].fnsig);
    }
    break;

  case 512:

/* Line 690 of lalr1.cc  */
#line 3904 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 513:

/* Line 690 of lalr1.cc  */
#line 3908 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 514:

/* Line 690 of lalr1.cc  */
#line 3914 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 515:

/* Line 690 of lalr1.cc  */
#line 3918 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 516:

/* Line 690 of lalr1.cc  */
#line 3922 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 517:

/* Line 690 of lalr1.cc  */
#line 3928 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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
#line 3936 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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
#line 3952 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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
#line 3960 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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
#line 3978 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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
#line 3996 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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
#line 4014 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      DirElemContentList *decl = new DirElemContentList( LOC((yyloc)) );
      decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(1) - (1)].expr)) );
      (yyval.node) = decl;
    }
    break;

  case 524:

/* Line 690 of lalr1.cc  */
#line 4020 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      DirElemContentList *decl = dynamic_cast<DirElemContentList*>((yysemantic_stack_[(2) - (1)].node));
      if ( decl )
        decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(2) - (2)].expr)) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 525:

/* Line 690 of lalr1.cc  */
#line 4029 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      DirAttributeList *dal = new DirAttributeList( LOC((yyloc)) );
      dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = dal;
    }
    break;

  case 526:

/* Line 690 of lalr1.cc  */
#line 4035 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      DirAttributeList *dal = dynamic_cast<DirAttributeList*>((yysemantic_stack_[(2) - (1)].node));
      if ( dal )
        dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 527:

/* Line 690 of lalr1.cc  */
#line 4044 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DirAttr(LOC((yyloc)),
                       static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                       dynamic_cast<DirAttributeValue*>((yysemantic_stack_[(6) - (6)].node)));
    }
    break;

  case 530:

/* Line 690 of lalr1.cc  */
#line 4054 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DirAttributeValue(LOC((yyloc)),
                                 dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
    }
    break;

  case 531:

/* Line 690 of lalr1.cc  */
#line 4059 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DirAttributeValue( LOC((yyloc)),
                                  dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
    }
    break;

  case 532:

/* Line 690 of lalr1.cc  */
#line 4065 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QuoteAttrContentList( LOC((yyloc)) );
    }
    break;

  case 533:

/* Line 690 of lalr1.cc  */
#line 4069 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 534:

/* Line 690 of lalr1.cc  */
#line 4075 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
      qacl->push_back( new QuoteAttrValueContent( LOC((yyloc)), "\"" ) );
      (yyval.node) = qacl;
    }
    break;

  case 535:

/* Line 690 of lalr1.cc  */
#line 4081 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
      qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = qacl;
    }
    break;

  case 536:

/* Line 690 of lalr1.cc  */
#line 4087 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      QuoteAttrContentList* qacl = dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
      if ( qacl )
        qacl->push_back( new QuoteAttrValueContent( LOC((yyloc)), "\"" ) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 537:

/* Line 690 of lalr1.cc  */
#line 4094 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      QuoteAttrContentList *qacl = dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
      if ( qacl )
        qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 538:

/* Line 690 of lalr1.cc  */
#line 4102 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AposAttrContentList( LOC((yyloc)) );
    }
    break;

  case 539:

/* Line 690 of lalr1.cc  */
#line 4106 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 540:

/* Line 690 of lalr1.cc  */
#line 4112 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
      aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
      (yyval.node) = aacl;
    }
    break;

  case 541:

/* Line 690 of lalr1.cc  */
#line 4118 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
      aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = aacl;
    }
    break;

  case 542:

/* Line 690 of lalr1.cc  */
#line 4124 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
      if (aacl)
        aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 543:

/* Line 690 of lalr1.cc  */
#line 4131 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
      if ( aacl )
        aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 544:

/* Line 690 of lalr1.cc  */
#line 4140 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QuoteAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
    }
    break;

  case 545:

/* Line 690 of lalr1.cc  */
#line 4144 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QuoteAttrValueContent(LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
    }
    break;

  case 546:

/* Line 690 of lalr1.cc  */
#line 4150 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AposAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
    }
    break;

  case 547:

/* Line 690 of lalr1.cc  */
#line 4154 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AposAttrValueContent(LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
    }
    break;

  case 548:

/* Line 690 of lalr1.cc  */
#line 4160 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirElemContent( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr) );
    }
    break;

  case 549:

/* Line 690 of lalr1.cc  */
#line 4164 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirElemContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
    }
    break;

  case 550:

/* Line 690 of lalr1.cc  */
#line 4168 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      rchandle<CDataSection> cdata_h = dynamic_cast<CDataSection*>((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = new DirElemContent( LOC((yyloc)), cdata_h );
    }
    break;

  case 551:

/* Line 690 of lalr1.cc  */
#line 4173 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      rchandle<CommonContent> cont_h = dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = new DirElemContent( LOC((yyloc)), cont_h );
    }
    break;

  case 552:

/* Line 690 of lalr1.cc  */
#line 4180 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CommonContent(LOC((yyloc)), ParseConstants::cont_charref, SYMTAB((yysemantic_stack_[(1) - (1)].sval)));
    }
    break;

  case 553:

/* Line 690 of lalr1.cc  */
#line 4184 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CommonContent(LOC((yyloc)), ParseConstants::cont_escape_lbrace);
    }
    break;

  case 554:

/* Line 690 of lalr1.cc  */
#line 4188 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CommonContent(LOC((yyloc)), ParseConstants::cont_escape_rbrace);
    }
    break;

  case 555:

/* Line 690 of lalr1.cc  */
#line 4192 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CommonContent(LOC((yyloc)), new EnclosedExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr)));
    }
    break;

  case 556:

/* Line 690 of lalr1.cc  */
#line 4198 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 557:

/* Line 690 of lalr1.cc  */
#line 4203 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), "" );
    }
    break;

  case 558:

/* Line 690 of lalr1.cc  */
#line 4209 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      ERROR_IF_QNAME_NOT_NCNAME((yysemantic_stack_[(3) - (2)].expr), (yylocation_stack_[(3) - (2)]));
      (yyval.expr) = new DirPIConstructor( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)) );
    }
    break;

  case 559:

/* Line 690 of lalr1.cc  */
#line 4215 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      ERROR_IF_QNAME_NOT_NCNAME((yysemantic_stack_[(3) - (2)].expr), (yylocation_stack_[(3) - (2)]));
      (yyval.expr) = new DirPIConstructor( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
    }
    break;

  case 560:

/* Line 690 of lalr1.cc  */
#line 4222 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CDataSection( LOC((yyloc)),SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
    }
    break;

  case 561:

/* Line 690 of lalr1.cc  */
#line 4228 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 562:

/* Line 690 of lalr1.cc  */
#line 4233 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 563:

/* Line 690 of lalr1.cc  */
#line 4238 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 564:

/* Line 690 of lalr1.cc  */
#line 4243 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 565:

/* Line 690 of lalr1.cc  */
#line 4248 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 566:

/* Line 690 of lalr1.cc  */
#line 4253 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 568:

/* Line 690 of lalr1.cc  */
#line 4261 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CompDocConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
    }
    break;

  case 569:

/* Line 690 of lalr1.cc  */
#line 4267 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CompElemConstructor(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval))), (yysemantic_stack_[(3) - (2)].expr));
    }
    break;

  case 570:

/* Line 690 of lalr1.cc  */
#line 4271 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CompElemConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
    }
    break;

  case 571:

/* Line 690 of lalr1.cc  */
#line 4277 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval))), (yysemantic_stack_[(3) - (2)].expr) );
    }
    break;

  case 572:

/* Line 690 of lalr1.cc  */
#line 4281 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
    }
    break;

  case 573:

/* Line 690 of lalr1.cc  */
#line 4287 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CompTextConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
    }
    break;

  case 574:

/* Line 690 of lalr1.cc  */
#line 4293 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CompCommentConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
    }
    break;

  case 575:

/* Line 690 of lalr1.cc  */
#line 4299 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CompPIConstructor(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval)), (yysemantic_stack_[(3) - (2)].expr));
    }
    break;

  case 576:

/* Line 690 of lalr1.cc  */
#line 4303 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CompPIConstructor(LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
    }
    break;

  case 577:

/* Line 690 of lalr1.cc  */
#line 4309 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CompNamespaceConstructor(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval)), (yysemantic_stack_[(3) - (2)].expr));
    }
    break;

  case 578:

/* Line 690 of lalr1.cc  */
#line 4313 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CompNamespaceConstructor(LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
    }
    break;

  case 579:

/* Line 690 of lalr1.cc  */
#line 4319 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 580:

/* Line 690 of lalr1.cc  */
#line 4325 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL );
        }
    break;

  case 581:

/* Line 690 of lalr1.cc  */
#line 4329 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node)));
        }
    break;

  case 582:

/* Line 690 of lalr1.cc  */
#line 4333 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 583:

/* Line 690 of lalr1.cc  */
#line 4339 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_optionally
            );
        }
    break;

  case 584:

/* Line 690 of lalr1.cc  */
#line 4345 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_zero_or_more
            );
        }
    break;

  case 585:

/* Line 690 of lalr1.cc  */
#line 4351 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_one_or_more
            );
        }
    break;

  case 586:

/* Line 690 of lalr1.cc  */
#line 4359 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 587:

/* Line 690 of lalr1.cc  */
#line 4363 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 588:

/* Line 690 of lalr1.cc  */
#line 4367 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ItemType( LOC((yyloc)), true );
        }
    break;

  case 589:

/* Line 690 of lalr1.cc  */
#line 4371 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new StructuredItemType(LOC((yyloc)));
        }
    break;

  case 590:

/* Line 690 of lalr1.cc  */
#line 4375 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 591:

/* Line 690 of lalr1.cc  */
#line 4379 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 592:

/* Line 690 of lalr1.cc  */
#line 4383 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 593:

/* Line 690 of lalr1.cc  */
#line 4389 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
          TypeList* aTypeList = new TypeList(LOC ((yyloc)));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(1) - (1)].node)));
          (yyval.node) = aTypeList;
        }
    break;

  case 594:

/* Line 690 of lalr1.cc  */
#line 4395 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
          TypeList* aTypeList = dynamic_cast<TypeList *>((yysemantic_stack_[(3) - (1)].node));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
          (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 595:

/* Line 690 of lalr1.cc  */
#line 4403 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GeneralizedAtomicType( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
    }
    break;

  case 596:

/* Line 690 of lalr1.cc  */
#line 4409 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SimpleType( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
    }
    break;

  case 597:

/* Line 690 of lalr1.cc  */
#line 4415 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 598:

/* Line 690 of lalr1.cc  */
#line 4419 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 599:

/* Line 690 of lalr1.cc  */
#line 4423 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 600:

/* Line 690 of lalr1.cc  */
#line 4427 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 601:

/* Line 690 of lalr1.cc  */
#line 4431 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 602:

/* Line 690 of lalr1.cc  */
#line 4435 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 603:

/* Line 690 of lalr1.cc  */
#line 4439 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 604:

/* Line 690 of lalr1.cc  */
#line 4443 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 605:

/* Line 690 of lalr1.cc  */
#line 4447 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 606:

/* Line 690 of lalr1.cc  */
#line 4451 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 607:

/* Line 690 of lalr1.cc  */
#line 4457 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnyKindTest( LOC((yyloc)) );
    }
    break;

  case 608:

/* Line 690 of lalr1.cc  */
#line 4463 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = NULL;
    }
    break;

  case 609:

/* Line 690 of lalr1.cc  */
#line 4469 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DocumentTest(LOC((yyloc)));
    }
    break;

  case 610:

/* Line 690 of lalr1.cc  */
#line 4473 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DocumentTest(LOC((yyloc)), dynamic_cast<ElementTest*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 611:

/* Line 690 of lalr1.cc  */
#line 4477 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DocumentTest(LOC((yyloc)), dynamic_cast<SchemaElementTest*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 612:

/* Line 690 of lalr1.cc  */
#line 4483 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new NamespaceTest(LOC((yyloc)));
    }
    break;

  case 613:

/* Line 690 of lalr1.cc  */
#line 4488 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new TextTest(LOC((yyloc)));
    }
    break;

  case 614:

/* Line 690 of lalr1.cc  */
#line 4494 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CommentTest(LOC((yyloc)));
    }
    break;

  case 615:

/* Line 690 of lalr1.cc  */
#line 4500 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), "" );
        }
    break;

  case 616:

/* Line 690 of lalr1.cc  */
#line 4504 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            ERROR_IF_QNAME_NOT_NCNAME((yysemantic_stack_[(4) - (3)].expr), (yylocation_stack_[(4) - (3)]));
            (yyval.node) = new PITest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 617:

/* Line 690 of lalr1.cc  */
#line 4509 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 618:

/* Line 690 of lalr1.cc  */
#line 4515 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 619:

/* Line 690 of lalr1.cc  */
#line 4519 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL
            );
        }
    break;

  case 620:

/* Line 690 of lalr1.cc  */
#line 4525 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 621:

/* Line 690 of lalr1.cc  */
#line 4531 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 622:

/* Line 690 of lalr1.cc  */
#line 4535 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 623:

/* Line 690 of lalr1.cc  */
#line 4543 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaAttributeTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 624:

/* Line 690 of lalr1.cc  */
#line 4549 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest( LOC((yyloc)), NULL, NULL, true );
        }
    break;

  case 625:

/* Line 690 of lalr1.cc  */
#line 4553 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL, true
            );
        }
    break;

  case 626:

/* Line 690 of lalr1.cc  */
#line 4559 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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
#line 4568 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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
#line 4577 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, NULL, true
            );
        }
    break;

  case 629:

/* Line 690 of lalr1.cc  */
#line 4583 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), false
            );
        }
    break;

  case 630:

/* Line 690 of lalr1.cc  */
#line 4589 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), true
            );
        }
    break;

  case 631:

/* Line 690 of lalr1.cc  */
#line 4597 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaElementTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 632:

/* Line 690 of lalr1.cc  */
#line 4603 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 633:

/* Line 690 of lalr1.cc  */
#line 4609 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (1)].expr)), true );
        }
    break;

  case 634:

/* Line 690 of lalr1.cc  */
#line 4615 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new StringLiteral( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 635:

/* Line 690 of lalr1.cc  */
#line 4621 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 636:

/* Line 690 of lalr1.cc  */
#line 4625 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 637:

/* Line 690 of lalr1.cc  */
#line 4631 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnyFunctionTest(LOC((yyloc)));
    }
    break;

  case 638:

/* Line 690 of lalr1.cc  */
#line 4637 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)), dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (5)].node)));
        }
    break;

  case 639:

/* Line 690 of lalr1.cc  */
#line 4641 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)),
              dynamic_cast<TypeList *>((yysemantic_stack_[(6) - (3)].node)),
              dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (6)].node)));
        }
    break;

  case 640:

/* Line 690 of lalr1.cc  */
#line 4649 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
           (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 641:

/* Line 690 of lalr1.cc  */
#line 4655 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::strict_validation
            );
        }
    break;

  case 642:

/* Line 690 of lalr1.cc  */
#line 4661 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::lax_validation
            );
        }
    break;

  case 643:

/* Line 690 of lalr1.cc  */
#line 4667 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::skip_validation
            );
        }
    break;

  case 644:

/* Line 690 of lalr1.cc  */
#line 4675 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 645:

/* Line 690 of lalr1.cc  */
#line 4679 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 646:

/* Line 690 of lalr1.cc  */
#line 4685 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 647:

/* Line 690 of lalr1.cc  */
#line 4691 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 648:

/* Line 690 of lalr1.cc  */
#line 4695 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 649:

/* Line 690 of lalr1.cc  */
#line 4701 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 650:

/* Line 690 of lalr1.cc  */
#line 4705 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 651:

/* Line 690 of lalr1.cc  */
#line 4711 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                  LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 652:

/* Line 690 of lalr1.cc  */
#line 4717 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)),
                store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 653:

/* Line 690 of lalr1.cc  */
#line 4724 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 654:

/* Line 690 of lalr1.cc  */
#line 4732 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 655:

/* Line 690 of lalr1.cc  */
#line 4737 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 656:

/* Line 690 of lalr1.cc  */
#line 4743 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::NODE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 657:

/* Line 690 of lalr1.cc  */
#line 4749 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::VALUE_OF_NODE, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 658:

/* Line 690 of lalr1.cc  */
#line 4757 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RenameExpr( LOC ((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 659:

/* Line 690 of lalr1.cc  */
#line 4763 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList *cvl = dynamic_cast<CopyVarList*>((yysemantic_stack_[(7) - (3)].expr));
      (yyval.expr) = new TransformExpr( LOC((yyloc)), cvl, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr) );
    }
    break;

  case 660:

/* Line 690 of lalr1.cc  */
#line 4770 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList* lList = new CopyVarList(LOC((yyloc)));
      lList->push_back (dynamic_cast<VarBinding*> ((yysemantic_stack_[(1) - (1)].expr)));
      (yyval.expr) = lList;
    }
    break;

  case 661:

/* Line 690 of lalr1.cc  */
#line 4776 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList* lList = dynamic_cast<CopyVarList*>((yysemantic_stack_[(4) - (1)].expr));
      VarBinding* lBinding = dynamic_cast<VarBinding*>((yysemantic_stack_[(4) - (4)].expr));
      lList->push_back(lBinding);
      (yyval.expr) = lList;
    }
    break;

  case 662:

/* Line 690 of lalr1.cc  */
#line 4785 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new VarBinding(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 663:

/* Line 690 of lalr1.cc  */
#line 4791 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new TryExpr( LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 664:

/* Line 690 of lalr1.cc  */
#line 4797 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            CatchListExpr *cle = new CatchListExpr( LOC((yyloc)) );
            cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.expr) = cle;
        }
    break;

  case 665:

/* Line 690 of lalr1.cc  */
#line 4803 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
            if ( cle )
                cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
        }
    break;

  case 666:

/* Line 690 of lalr1.cc  */
#line 4812 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)), *(yysemantic_stack_[(3) - (2)].name_test_list), (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 667:

/* Line 690 of lalr1.cc  */
#line 4819 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 668:

/* Line 690 of lalr1.cc  */
#line 4825 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            CatchExpr::NameTestList *ntl = new CatchExpr::NameTestList;
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 669:

/* Line 690 of lalr1.cc  */
#line 4831 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            CatchExpr::NameTestList *ntl =
                static_cast<CatchExpr::NameTestList*>((yysemantic_stack_[(3) - (1)].name_test_list));
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 670:

/* Line 690 of lalr1.cc  */
#line 4840 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTSelection( LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), (yysemantic_stack_[(2) - (2)].pos_filter_list) );
            delete (yysemantic_stack_[(2) - (2)].pos_filter_list);
        }
    break;

  case 671:

/* Line 690 of lalr1.cc  */
#line 4847 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = NULL;
        }
    break;

  case 672:

/* Line 690 of lalr1.cc  */
#line 4851 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = (yysemantic_stack_[(1) - (1)].pos_filter_list);
        }
    break;

  case 673:

/* Line 690 of lalr1.cc  */
#line 4857 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = new FTSelection::pos_filter_list_t;
            (yyval.pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 674:

/* Line 690 of lalr1.cc  */
#line 4862 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yysemantic_stack_[(2) - (1)].pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.pos_filter_list) = (yysemantic_stack_[(2) - (1)].pos_filter_list);
        }
    break;

  case 675:

/* Line 690 of lalr1.cc  */
#line 4869 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 676:

/* Line 690 of lalr1.cc  */
#line 4873 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTOr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 677:

/* Line 690 of lalr1.cc  */
#line 4879 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 678:

/* Line 690 of lalr1.cc  */
#line 4883 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnd( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 679:

/* Line 690 of lalr1.cc  */
#line 4889 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 680:

/* Line 690 of lalr1.cc  */
#line 4893 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTMildNot( LOC((yyloc)), (yysemantic_stack_[(4) - (1)].node), (yysemantic_stack_[(4) - (4)].node) );
        }
    break;

  case 681:

/* Line 690 of lalr1.cc  */
#line 4899 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 682:

/* Line 690 of lalr1.cc  */
#line 4903 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnaryNot(
                LOC((yyloc)), dynamic_cast<FTPrimaryWithOptions*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 683:

/* Line 690 of lalr1.cc  */
#line 4911 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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
#line 4921 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 685:

/* Line 690 of lalr1.cc  */
#line 4925 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 686:

/* Line 690 of lalr1.cc  */
#line 4930 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 687:

/* Line 690 of lalr1.cc  */
#line 4934 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 688:

/* Line 690 of lalr1.cc  */
#line 4940 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWeight( LOC((yyloc)), dynamic_cast<exprnode*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 689:

/* Line 690 of lalr1.cc  */
#line 4946 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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
#line 4954 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 691:

/* Line 690 of lalr1.cc  */
#line 4958 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 692:

/* Line 690 of lalr1.cc  */
#line 4963 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 693:

/* Line 690 of lalr1.cc  */
#line 4967 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 694:

/* Line 690 of lalr1.cc  */
#line 4973 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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
#line 4982 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 696:

/* Line 690 of lalr1.cc  */
#line 4986 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 697:

/* Line 690 of lalr1.cc  */
#line 4992 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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
#line 5002 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), static_cast<StringLiteral*>((yysemantic_stack_[(1) - (1)].expr)), NULL
            );
        }
    break;

  case 699:

/* Line 690 of lalr1.cc  */
#line 5008 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), NULL, dynamic_cast<exprnode*>((yysemantic_stack_[(3) - (2)].expr))
            );
        }
    break;

  case 700:

/* Line 690 of lalr1.cc  */
#line 5015 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::any );
        }
    break;

  case 701:

/* Line 690 of lalr1.cc  */
#line 5019 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 702:

/* Line 690 of lalr1.cc  */
#line 5025 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 703:

/* Line 690 of lalr1.cc  */
#line 5029 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 704:

/* Line 690 of lalr1.cc  */
#line 5033 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::phrase );
        }
    break;

  case 705:

/* Line 690 of lalr1.cc  */
#line 5038 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any;
        }
    break;

  case 706:

/* Line 690 of lalr1.cc  */
#line 5042 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any_word;
        }
    break;

  case 707:

/* Line 690 of lalr1.cc  */
#line 5047 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all;
        }
    break;

  case 708:

/* Line 690 of lalr1.cc  */
#line 5051 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all_words;
        }
    break;

  case 709:

/* Line 690 of lalr1.cc  */
#line 5057 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 710:

/* Line 690 of lalr1.cc  */
#line 5061 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 711:

/* Line 690 of lalr1.cc  */
#line 5065 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 712:

/* Line 690 of lalr1.cc  */
#line 5069 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 713:

/* Line 690 of lalr1.cc  */
#line 5073 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 714:

/* Line 690 of lalr1.cc  */
#line 5079 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTOrder( LOC((yyloc)) );
        }
    break;

  case 715:

/* Line 690 of lalr1.cc  */
#line 5085 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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
#line 5095 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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
#line 5105 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::words );
        }
    break;

  case 718:

/* Line 690 of lalr1.cc  */
#line 5109 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::sentences );
        }
    break;

  case 719:

/* Line 690 of lalr1.cc  */
#line 5113 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::paragraphs );
        }
    break;

  case 720:

/* Line 690 of lalr1.cc  */
#line 5119 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            FTMatchOptions *mo = new FTMatchOptions( LOC((yyloc)) );
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = mo;
        }
    break;

  case 721:

/* Line 690 of lalr1.cc  */
#line 5125 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            FTMatchOptions *mo = dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (1)].node));
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 722:

/* Line 690 of lalr1.cc  */
#line 5133 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 723:

/* Line 690 of lalr1.cc  */
#line 5137 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 724:

/* Line 690 of lalr1.cc  */
#line 5141 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 725:

/* Line 690 of lalr1.cc  */
#line 5145 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 726:

/* Line 690 of lalr1.cc  */
#line 5149 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 727:

/* Line 690 of lalr1.cc  */
#line 5153 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 728:

/* Line 690 of lalr1.cc  */
#line 5157 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 729:

/* Line 690 of lalr1.cc  */
#line 5161 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 730:

/* Line 690 of lalr1.cc  */
#line 5167 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::sensitive );
        }
    break;

  case 731:

/* Line 690 of lalr1.cc  */
#line 5171 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::insensitive );
        }
    break;

  case 732:

/* Line 690 of lalr1.cc  */
#line 5175 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::lower );
        }
    break;

  case 733:

/* Line 690 of lalr1.cc  */
#line 5179 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::upper );
        }
    break;

  case 734:

/* Line 690 of lalr1.cc  */
#line 5185 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::sensitive
            );
        }
    break;

  case 735:

/* Line 690 of lalr1.cc  */
#line 5191 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::insensitive
            );
        }
    break;

  case 736:

/* Line 690 of lalr1.cc  */
#line 5199 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTExtensionOption(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval))
            );
        }
    break;

  case 737:

/* Line 690 of lalr1.cc  */
#line 5207 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::stemming );
        }
    break;

  case 738:

/* Line 690 of lalr1.cc  */
#line 5211 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::no_stemming );
        }
    break;

  case 739:

/* Line 690 of lalr1.cc  */
#line 5217 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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
#line 5227 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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
#line 5238 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTThesaurusOption( LOC((yyloc)), NULL, false, true );
        }
    break;

  case 742:

/* Line 690 of lalr1.cc  */
#line 5244 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 743:

/* Line 690 of lalr1.cc  */
#line 5248 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 744:

/* Line 690 of lalr1.cc  */
#line 5253 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = NULL;
        }
    break;

  case 745:

/* Line 690 of lalr1.cc  */
#line 5257 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(2) - (2)].thesaurus_id_list);
        }
    break;

  case 746:

/* Line 690 of lalr1.cc  */
#line 5263 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = new FTThesaurusOption::thesaurus_id_list_t;
            (yyval.thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 747:

/* Line 690 of lalr1.cc  */
#line 5268 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yysemantic_stack_[(3) - (1)].thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(3) - (1)].thesaurus_id_list);
        }
    break;

  case 748:

/* Line 690 of lalr1.cc  */
#line 5275 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTThesaurusID(
                LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (2)].sval)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), dynamic_cast<FTRange*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 749:

/* Line 690 of lalr1.cc  */
#line 5282 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.sval) = 0;
        }
    break;

  case 750:

/* Line 690 of lalr1.cc  */
#line 5286 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.sval) = (yysemantic_stack_[(2) - (2)].sval);
        }
    break;

  case 751:

/* Line 690 of lalr1.cc  */
#line 5292 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 752:

/* Line 690 of lalr1.cc  */
#line 5296 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 753:

/* Line 690 of lalr1.cc  */
#line 5302 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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
#line 5311 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, (yysemantic_stack_[(4) - (4)].incl_excl_list), ft_stop_words_mode::with_default
            );
            delete (yysemantic_stack_[(4) - (4)].incl_excl_list);
        }
    break;

  case 755:

/* Line 690 of lalr1.cc  */
#line 5318 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, NULL, ft_stop_words_mode::without
            );
        }
    break;

  case 756:

/* Line 690 of lalr1.cc  */
#line 5326 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), NULL );
        }
    break;

  case 757:

/* Line 690 of lalr1.cc  */
#line 5330 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), "", (yysemantic_stack_[(3) - (2)].strlist) );
        }
    break;

  case 758:

/* Line 690 of lalr1.cc  */
#line 5336 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            string_list_t *sl = new string_list_t;
            sl->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
            (yyval.strlist) = sl;
        }
    break;

  case 759:

/* Line 690 of lalr1.cc  */
#line 5342 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            if ( (yysemantic_stack_[(3) - (1)].strlist) )
                (yysemantic_stack_[(3) - (1)].strlist)->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
            (yyval.strlist) = (yysemantic_stack_[(3) - (1)].strlist);
        }
    break;

  case 760:

/* Line 690 of lalr1.cc  */
#line 5349 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = NULL;
        }
    break;

  case 761:

/* Line 690 of lalr1.cc  */
#line 5353 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = (yysemantic_stack_[(1) - (1)].incl_excl_list);
        }
    break;

  case 762:

/* Line 690 of lalr1.cc  */
#line 5359 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = new FTStopWordOption::incl_excl_list_t;
            (yyval.incl_excl_list)->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 763:

/* Line 690 of lalr1.cc  */
#line 5364 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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
#line 5374 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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
#line 5382 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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
#line 5392 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTLanguageOption( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 767:

/* Line 690 of lalr1.cc  */
#line 5398 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::with );
        }
    break;

  case 768:

/* Line 690 of lalr1.cc  */
#line 5402 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::without );
        }
    break;

  case 769:

/* Line 690 of lalr1.cc  */
#line 5408 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_start );
        }
    break;

  case 770:

/* Line 690 of lalr1.cc  */
#line 5412 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_end );
        }
    break;

  case 771:

/* Line 690 of lalr1.cc  */
#line 5416 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::entire );
        }
    break;

  case 772:

/* Line 690 of lalr1.cc  */
#line 5422 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTTimes( LOC((yyloc)), dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)) );
        }
    break;

  case 773:

/* Line 690 of lalr1.cc  */
#line 5428 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::exactly, (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 774:

/* Line 690 of lalr1.cc  */
#line 5432 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_least, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 775:

/* Line 690 of lalr1.cc  */
#line 5436 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_most, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 776:

/* Line 690 of lalr1.cc  */
#line 5440 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::from_to, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr) );
        }
    break;

  case 777:

/* Line 690 of lalr1.cc  */
#line 5446 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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
#line 5454 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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
#line 5464 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::sentence );
        }
    break;

  case 780:

/* Line 690 of lalr1.cc  */
#line 5468 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::paragraph );
        }
    break;

  case 781:

/* Line 690 of lalr1.cc  */
#line 5474 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTIgnoreOption( LOC((yyloc)), static_cast<UnionExpr*>((yysemantic_stack_[(3) - (3)].expr)) );
        }
    break;

  case 782:

/* Line 690 of lalr1.cc  */
#line 5480 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONArrayConstructor( LOC((yyloc)), NULL );
        }
    break;

  case 783:

/* Line 690 of lalr1.cc  */
#line 5484 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONArrayConstructor( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 784:

/* Line 690 of lalr1.cc  */
#line 5490 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), NULL, false);
        }
    break;

  case 785:

/* Line 690 of lalr1.cc  */
#line 5494 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), false);
        }
    break;

  case 786:

/* Line 690 of lalr1.cc  */
#line 5500 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), NULL, true);
        }
    break;

  case 787:

/* Line 690 of lalr1.cc  */
#line 5504 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), true);
        }
    break;

  case 788:

/* Line 690 of lalr1.cc  */
#line 5510 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONDirectObjectConstructor(LOC((yyloc)),
                                               dynamic_cast<JSONPairList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 789:

/* Line 690 of lalr1.cc  */
#line 5517 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
          JSONPairList* jpl = new JSONPairList(LOC((yyloc)));
          jpl->push_back(new JSONPairConstructor(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)));
          (yyval.node) = jpl;
        }
    break;

  case 790:

/* Line 690 of lalr1.cc  */
#line 5523 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
          JSONPairList* jpl = dynamic_cast<JSONPairList*>((yysemantic_stack_[(5) - (1)].node));
          assert(jpl);
          jpl->push_back(new JSONPairConstructor(LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)));
          (yyval.node) = jpl;
        }
    break;

  case 791:

/* Line 690 of lalr1.cc  */
#line 5532 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONObjectInsertExpr(LOC((yyloc)),
                                        (yysemantic_stack_[(5) - (3)].expr),
                                        (yysemantic_stack_[(5) - (5)].expr));
        }
    break;

  case 792:

/* Line 690 of lalr1.cc  */
#line 5538 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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
#line 5548 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONArrayInsertExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (5)].expr), (yysemantic_stack_[(8) - (8)].expr));
        }
    break;

  case 794:

/* Line 690 of lalr1.cc  */
#line 5554 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONArrayAppendExpr(LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
        }
    break;

  case 795:

/* Line 690 of lalr1.cc  */
#line 5560 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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
#line 5581 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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
#line 5605 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
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
#line 5629 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 799:

/* Line 690 of lalr1.cc  */
#line 5633 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 800:

/* Line 690 of lalr1.cc  */
#line 5637 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 801:

/* Line 690 of lalr1.cc  */
#line 5643 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonItem);
        }
    break;

  case 802:

/* Line 690 of lalr1.cc  */
#line 5649 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonObject);
        }
    break;

  case 803:

/* Line 690 of lalr1.cc  */
#line 5655 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonArray);
        }
    break;

  case 806:

/* Line 690 of lalr1.cc  */
#line 5664 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))); }
    break;

  case 807:

/* Line 690 of lalr1.cc  */
#line 5665 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("attribute"))); }
    break;

  case 808:

/* Line 690 of lalr1.cc  */
#line 5666 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("comment"))); }
    break;

  case 809:

/* Line 690 of lalr1.cc  */
#line 5667 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("document-node"))); }
    break;

  case 810:

/* Line 690 of lalr1.cc  */
#line 5668 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("namespace-node"))); }
    break;

  case 811:

/* Line 690 of lalr1.cc  */
#line 5669 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("element"))); }
    break;

  case 812:

/* Line 690 of lalr1.cc  */
#line 5670 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("item"))); }
    break;

  case 813:

/* Line 690 of lalr1.cc  */
#line 5671 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("if"))); }
    break;

  case 814:

/* Line 690 of lalr1.cc  */
#line 5672 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("node"))); }
    break;

  case 815:

/* Line 690 of lalr1.cc  */
#line 5673 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("processing-instruction"))); }
    break;

  case 816:

/* Line 690 of lalr1.cc  */
#line 5674 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema-attribute"))); }
    break;

  case 817:

/* Line 690 of lalr1.cc  */
#line 5675 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema-element"))); }
    break;

  case 818:

/* Line 690 of lalr1.cc  */
#line 5676 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("text"))); }
    break;

  case 819:

/* Line 690 of lalr1.cc  */
#line 5677 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("typeswitch"))); }
    break;

  case 820:

/* Line 690 of lalr1.cc  */
#line 5678 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("switch"))); }
    break;

  case 821:

/* Line 690 of lalr1.cc  */
#line 5679 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("empty-sequence"))); }
    break;

  case 822:

/* Line 690 of lalr1.cc  */
#line 5680 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("while"))); }
    break;

  case 824:

/* Line 690 of lalr1.cc  */
#line 5684 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))); }
    break;

  case 825:

/* Line 690 of lalr1.cc  */
#line 5685 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("xquery"))); }
    break;

  case 826:

/* Line 690 of lalr1.cc  */
#line 5686 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("empty"))); }
    break;

  case 827:

/* Line 690 of lalr1.cc  */
#line 5687 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("boundary-space"))); }
    break;

  case 828:

/* Line 690 of lalr1.cc  */
#line 5688 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ft-option"))); }
    break;

  case 829:

/* Line 690 of lalr1.cc  */
#line 5689 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("base-uri"))); }
    break;

  case 830:

/* Line 690 of lalr1.cc  */
#line 5690 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lax"))); }
    break;

  case 831:

/* Line 690 of lalr1.cc  */
#line 5691 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("strict"))); }
    break;

  case 832:

/* Line 690 of lalr1.cc  */
#line 5692 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("idiv"))); }
    break;

  case 833:

/* Line 690 of lalr1.cc  */
#line 5693 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("document"))); }
    break;

  case 834:

/* Line 690 of lalr1.cc  */
#line 5694 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ftnot"))); }
    break;

  case 835:

/* Line 690 of lalr1.cc  */
#line 5695 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("not"))); }
    break;

  case 836:

/* Line 690 of lalr1.cc  */
#line 5696 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sensitive"))); }
    break;

  case 837:

/* Line 690 of lalr1.cc  */
#line 5697 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("insensitive"))); }
    break;

  case 838:

/* Line 690 of lalr1.cc  */
#line 5698 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("diacritics"))); }
    break;

  case 839:

/* Line 690 of lalr1.cc  */
#line 5699 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("without"))); }
    break;

  case 840:

/* Line 690 of lalr1.cc  */
#line 5700 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stemming"))); }
    break;

  case 841:

/* Line 690 of lalr1.cc  */
#line 5701 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("thesaurus"))); }
    break;

  case 842:

/* Line 690 of lalr1.cc  */
#line 5702 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stop"))); }
    break;

  case 843:

/* Line 690 of lalr1.cc  */
#line 5703 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("wildcards"))); }
    break;

  case 844:

/* Line 690 of lalr1.cc  */
#line 5704 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("entire"))); }
    break;

  case 845:

/* Line 690 of lalr1.cc  */
#line 5705 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("content"))); }
    break;

  case 846:

/* Line 690 of lalr1.cc  */
#line 5706 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("word"))); }
    break;

  case 847:

/* Line 690 of lalr1.cc  */
#line 5707 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("start"))); }
    break;

  case 848:

/* Line 690 of lalr1.cc  */
#line 5708 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("end"))); }
    break;

  case 849:

/* Line 690 of lalr1.cc  */
#line 5709 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("most"))); }
    break;

  case 850:

/* Line 690 of lalr1.cc  */
#line 5710 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("skip"))); }
    break;

  case 851:

/* Line 690 of lalr1.cc  */
#line 5711 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("copy"))); }
    break;

  case 852:

/* Line 690 of lalr1.cc  */
#line 5712 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("general"))); }
    break;

  case 853:

/* Line 690 of lalr1.cc  */
#line 5713 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("value"))); }
    break;

  case 854:

/* Line 690 of lalr1.cc  */
#line 5714 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("eq"))); }
    break;

  case 855:

/* Line 690 of lalr1.cc  */
#line 5715 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ne"))); }
    break;

  case 856:

/* Line 690 of lalr1.cc  */
#line 5716 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lt"))); }
    break;

  case 857:

/* Line 690 of lalr1.cc  */
#line 5717 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("le"))); }
    break;

  case 858:

/* Line 690 of lalr1.cc  */
#line 5718 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("gt"))); }
    break;

  case 859:

/* Line 690 of lalr1.cc  */
#line 5719 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ge"))); }
    break;

  case 860:

/* Line 690 of lalr1.cc  */
#line 5720 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("at"))); }
    break;

  case 861:

/* Line 690 of lalr1.cc  */
#line 5721 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("context"))); }
    break;

  case 862:

/* Line 690 of lalr1.cc  */
#line 5722 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("variable"))); }
    break;

  case 863:

/* Line 690 of lalr1.cc  */
#line 5723 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("return"))); }
    break;

  case 864:

/* Line 690 of lalr1.cc  */
#line 5724 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("for"))); }
    break;

  case 865:

/* Line 690 of lalr1.cc  */
#line 5725 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("from"))); }
    break;

  case 866:

/* Line 690 of lalr1.cc  */
#line 5726 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("allowing"))); }
    break;

  case 867:

/* Line 690 of lalr1.cc  */
#line 5727 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sliding"))); }
    break;

  case 868:

/* Line 690 of lalr1.cc  */
#line 5728 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("tumbling"))); }
    break;

  case 869:

/* Line 690 of lalr1.cc  */
#line 5729 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("previous"))); }
    break;

  case 870:

/* Line 690 of lalr1.cc  */
#line 5730 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("next"))); }
    break;

  case 871:

/* Line 690 of lalr1.cc  */
#line 5731 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("only"))); }
    break;

  case 872:

/* Line 690 of lalr1.cc  */
#line 5732 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("when"))); }
    break;

  case 873:

/* Line 690 of lalr1.cc  */
#line 5733 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("count"))); }
    break;

  case 874:

/* Line 690 of lalr1.cc  */
#line 5734 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("in"))); }
    break;

  case 875:

/* Line 690 of lalr1.cc  */
#line 5735 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("let"))); }
    break;

  case 876:

/* Line 690 of lalr1.cc  */
#line 5736 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("where"))); }
    break;

  case 877:

/* Line 690 of lalr1.cc  */
#line 5737 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("by"))); }
    break;

  case 878:

/* Line 690 of lalr1.cc  */
#line 5738 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("group"))); }
    break;

  case 879:

/* Line 690 of lalr1.cc  */
#line 5739 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("order"))); }
    break;

  case 880:

/* Line 690 of lalr1.cc  */
#line 5740 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stable"))); }
    break;

  case 881:

/* Line 690 of lalr1.cc  */
#line 5741 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ascending"))); }
    break;

  case 882:

/* Line 690 of lalr1.cc  */
#line 5742 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descending"))); }
    break;

  case 883:

/* Line 690 of lalr1.cc  */
#line 5743 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("greatest"))); }
    break;

  case 884:

/* Line 690 of lalr1.cc  */
#line 5744 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("least"))); }
    break;

  case 885:

/* Line 690 of lalr1.cc  */
#line 5745 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("collation"))); }
    break;

  case 886:

/* Line 690 of lalr1.cc  */
#line 5746 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("some"))); }
    break;

  case 887:

/* Line 690 of lalr1.cc  */
#line 5747 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("every"))); }
    break;

  case 888:

/* Line 690 of lalr1.cc  */
#line 5748 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("satisfies"))); }
    break;

  case 889:

/* Line 690 of lalr1.cc  */
#line 5749 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("case"))); }
    break;

  case 890:

/* Line 690 of lalr1.cc  */
#line 5750 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("as"))); }
    break;

  case 891:

/* Line 690 of lalr1.cc  */
#line 5751 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("then"))); }
    break;

  case 892:

/* Line 690 of lalr1.cc  */
#line 5752 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("else"))); }
    break;

  case 893:

/* Line 690 of lalr1.cc  */
#line 5753 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("or"))); }
    break;

  case 894:

/* Line 690 of lalr1.cc  */
#line 5754 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("and"))); }
    break;

  case 895:

/* Line 690 of lalr1.cc  */
#line 5755 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("instance"))); }
    break;

  case 896:

/* Line 690 of lalr1.cc  */
#line 5756 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("of"))); }
    break;

  case 897:

/* Line 690 of lalr1.cc  */
#line 5757 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("castable"))); }
    break;

  case 898:

/* Line 690 of lalr1.cc  */
#line 5758 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("to"))); }
    break;

  case 899:

/* Line 690 of lalr1.cc  */
#line 5759 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("div"))); }
    break;

  case 900:

/* Line 690 of lalr1.cc  */
#line 5760 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("mod"))); }
    break;

  case 901:

/* Line 690 of lalr1.cc  */
#line 5761 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("union"))); }
    break;

  case 902:

/* Line 690 of lalr1.cc  */
#line 5762 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("intersect"))); }
    break;

  case 903:

/* Line 690 of lalr1.cc  */
#line 5763 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("except"))); }
    break;

  case 904:

/* Line 690 of lalr1.cc  */
#line 5764 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("validate"))); }
    break;

  case 905:

/* Line 690 of lalr1.cc  */
#line 5765 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("type"))); }
    break;

  case 906:

/* Line 690 of lalr1.cc  */
#line 5766 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("cast"))); }
    break;

  case 907:

/* Line 690 of lalr1.cc  */
#line 5767 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("treat"))); }
    break;

  case 908:

/* Line 690 of lalr1.cc  */
#line 5768 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("is"))); }
    break;

  case 909:

/* Line 690 of lalr1.cc  */
#line 5769 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preserve"))); }
    break;

  case 910:

/* Line 690 of lalr1.cc  */
#line 5770 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("strip"))); }
    break;

  case 911:

/* Line 690 of lalr1.cc  */
#line 5771 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("namespace"))); }
    break;

  case 912:

/* Line 690 of lalr1.cc  */
#line 5772 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("external"))); }
    break;

  case 913:

/* Line 690 of lalr1.cc  */
#line 5773 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("encoding"))); }
    break;

  case 914:

/* Line 690 of lalr1.cc  */
#line 5774 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("no-preserve"))); }
    break;

  case 915:

/* Line 690 of lalr1.cc  */
#line 5775 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("inherit"))); }
    break;

  case 916:

/* Line 690 of lalr1.cc  */
#line 5776 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("no-inherit"))); }
    break;

  case 917:

/* Line 690 of lalr1.cc  */
#line 5777 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("declare"))); }
    break;

  case 918:

/* Line 690 of lalr1.cc  */
#line 5778 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("construction"))); }
    break;

  case 919:

/* Line 690 of lalr1.cc  */
#line 5779 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ordering"))); }
    break;

  case 920:

/* Line 690 of lalr1.cc  */
#line 5780 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("default"))); }
    break;

  case 921:

/* Line 690 of lalr1.cc  */
#line 5781 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("copy-namespaces"))); }
    break;

  case 922:

/* Line 690 of lalr1.cc  */
#line 5782 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("option"))); }
    break;

  case 923:

/* Line 690 of lalr1.cc  */
#line 5783 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("version"))); }
    break;

  case 924:

/* Line 690 of lalr1.cc  */
#line 5784 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("import"))); }
    break;

  case 925:

/* Line 690 of lalr1.cc  */
#line 5785 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema"))); }
    break;

  case 926:

/* Line 690 of lalr1.cc  */
#line 5786 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("module"))); }
    break;

  case 927:

/* Line 690 of lalr1.cc  */
#line 5787 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("function"))); }
    break;

  case 928:

/* Line 690 of lalr1.cc  */
#line 5788 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("score"))); }
    break;

  case 929:

/* Line 690 of lalr1.cc  */
#line 5789 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("contains"))); }
    break;

  case 930:

/* Line 690 of lalr1.cc  */
#line 5790 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("weight"))); }
    break;

  case 931:

/* Line 690 of lalr1.cc  */
#line 5791 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("window"))); }
    break;

  case 932:

/* Line 690 of lalr1.cc  */
#line 5792 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("distance"))); }
    break;

  case 933:

/* Line 690 of lalr1.cc  */
#line 5793 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("occurs"))); }
    break;

  case 934:

/* Line 690 of lalr1.cc  */
#line 5794 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("times"))); }
    break;

  case 935:

/* Line 690 of lalr1.cc  */
#line 5795 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("same"))); }
    break;

  case 936:

/* Line 690 of lalr1.cc  */
#line 5796 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("different"))); }
    break;

  case 937:

/* Line 690 of lalr1.cc  */
#line 5797 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lowercase"))); }
    break;

  case 938:

/* Line 690 of lalr1.cc  */
#line 5798 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("uppercase"))); }
    break;

  case 939:

/* Line 690 of lalr1.cc  */
#line 5799 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("relationship"))); }
    break;

  case 940:

/* Line 690 of lalr1.cc  */
#line 5800 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("levels"))); }
    break;

  case 941:

/* Line 690 of lalr1.cc  */
#line 5801 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("language"))); }
    break;

  case 942:

/* Line 690 of lalr1.cc  */
#line 5802 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("any"))); }
    break;

  case 943:

/* Line 690 of lalr1.cc  */
#line 5803 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("all"))); }
    break;

  case 944:

/* Line 690 of lalr1.cc  */
#line 5804 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("exactly"))); }
    break;

  case 945:

/* Line 690 of lalr1.cc  */
#line 5805 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("words"))); }
    break;

  case 946:

/* Line 690 of lalr1.cc  */
#line 5806 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sentences"))); }
    break;

  case 947:

/* Line 690 of lalr1.cc  */
#line 5807 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sentence"))); }
    break;

  case 948:

/* Line 690 of lalr1.cc  */
#line 5808 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("phrase"))); }
    break;

  case 949:

/* Line 690 of lalr1.cc  */
#line 5809 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("paragraph"))); }
    break;

  case 950:

/* Line 690 of lalr1.cc  */
#line 5810 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("paragraphs"))); }
    break;

  case 951:

/* Line 690 of lalr1.cc  */
#line 5811 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("modify"))); }
    break;

  case 952:

/* Line 690 of lalr1.cc  */
#line 5812 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("first"))); }
    break;

  case 953:

/* Line 690 of lalr1.cc  */
#line 5813 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("replace"))); }
    break;

  case 954:

/* Line 690 of lalr1.cc  */
#line 5814 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("insert"))); }
    break;

  case 955:

/* Line 690 of lalr1.cc  */
#line 5815 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("rename"))); }
    break;

  case 956:

/* Line 690 of lalr1.cc  */
#line 5816 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("delete"))); }
    break;

  case 957:

/* Line 690 of lalr1.cc  */
#line 5817 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("before"))); }
    break;

  case 958:

/* Line 690 of lalr1.cc  */
#line 5818 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("after"))); }
    break;

  case 959:

/* Line 690 of lalr1.cc  */
#line 5819 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("revalidation"))); }
    break;

  case 960:

/* Line 690 of lalr1.cc  */
#line 5820 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("with"))); }
    break;

  case 961:

/* Line 690 of lalr1.cc  */
#line 5821 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("nodes"))); }
    break;

  case 962:

/* Line 690 of lalr1.cc  */
#line 5822 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("last"))); }
    break;

  case 963:

/* Line 690 of lalr1.cc  */
#line 5823 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("into"))); }
    break;

  case 964:

/* Line 690 of lalr1.cc  */
#line 5824 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("simple"))); }
    break;

  case 965:

/* Line 690 of lalr1.cc  */
#line 5825 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sequential"))); }
    break;

  case 966:

/* Line 690 of lalr1.cc  */
#line 5826 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("updating"))); }
    break;

  case 967:

/* Line 690 of lalr1.cc  */
#line 5827 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ordered"))); }
    break;

  case 968:

/* Line 690 of lalr1.cc  */
#line 5828 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("unordered"))); }
    break;

  case 969:

/* Line 690 of lalr1.cc  */
#line 5829 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("returning"))); }
    break;

  case 970:

/* Line 690 of lalr1.cc  */
#line 5830 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("exit"))); }
    break;

  case 971:

/* Line 690 of lalr1.cc  */
#line 5831 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("loop"))); }
    break;

  case 972:

/* Line 690 of lalr1.cc  */
#line 5832 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("break"))); }
    break;

  case 973:

/* Line 690 of lalr1.cc  */
#line 5833 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("continue"))); }
    break;

  case 974:

/* Line 690 of lalr1.cc  */
#line 5834 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("try"))); }
    break;

  case 975:

/* Line 690 of lalr1.cc  */
#line 5835 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("catch"))); }
    break;

  case 976:

/* Line 690 of lalr1.cc  */
#line 5836 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("using"))); }
    break;

  case 977:

/* Line 690 of lalr1.cc  */
#line 5837 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("set"))); }
    break;

  case 978:

/* Line 690 of lalr1.cc  */
#line 5838 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("index"))); }
    break;

  case 979:

/* Line 690 of lalr1.cc  */
#line 5839 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("unique"))); }
    break;

  case 980:

/* Line 690 of lalr1.cc  */
#line 5840 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("non"))); }
    break;

  case 981:

/* Line 690 of lalr1.cc  */
#line 5841 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("on"))); }
    break;

  case 982:

/* Line 690 of lalr1.cc  */
#line 5842 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("range"))); }
    break;

  case 983:

/* Line 690 of lalr1.cc  */
#line 5843 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("equality"))); }
    break;

  case 984:

/* Line 690 of lalr1.cc  */
#line 5844 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("manually"))); }
    break;

  case 985:

/* Line 690 of lalr1.cc  */
#line 5845 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("automatically"))); }
    break;

  case 986:

/* Line 690 of lalr1.cc  */
#line 5846 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("maintained"))); }
    break;

  case 987:

/* Line 690 of lalr1.cc  */
#line 5847 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("decimal-format"))); }
    break;

  case 988:

/* Line 690 of lalr1.cc  */
#line 5848 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("decimal-separator"))); }
    break;

  case 989:

/* Line 690 of lalr1.cc  */
#line 5849 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("grouping-separator"))); }
    break;

  case 990:

/* Line 690 of lalr1.cc  */
#line 5850 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("infinity"))); }
    break;

  case 991:

/* Line 690 of lalr1.cc  */
#line 5851 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("minus-sign"))); }
    break;

  case 992:

/* Line 690 of lalr1.cc  */
#line 5852 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("NaN"))); }
    break;

  case 993:

/* Line 690 of lalr1.cc  */
#line 5853 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("percent"))); }
    break;

  case 994:

/* Line 690 of lalr1.cc  */
#line 5854 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("per-mille"))); }
    break;

  case 995:

/* Line 690 of lalr1.cc  */
#line 5855 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("zero-digit"))); }
    break;

  case 996:

/* Line 690 of lalr1.cc  */
#line 5856 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("digit"))); }
    break;

  case 997:

/* Line 690 of lalr1.cc  */
#line 5857 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("pattern-separator"))); }
    break;

  case 998:

/* Line 690 of lalr1.cc  */
#line 5858 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("collection"))); }
    break;

  case 999:

/* Line 690 of lalr1.cc  */
#line 5859 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("const"))); }
    break;

  case 1000:

/* Line 690 of lalr1.cc  */
#line 5860 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("append-only"))); }
    break;

  case 1001:

/* Line 690 of lalr1.cc  */
#line 5861 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("queue"))); }
    break;

  case 1002:

/* Line 690 of lalr1.cc  */
#line 5862 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("mutable"))); }
    break;

  case 1003:

/* Line 690 of lalr1.cc  */
#line 5863 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("read-only"))); }
    break;

  case 1004:

/* Line 690 of lalr1.cc  */
#line 5864 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("integrity"))); }
    break;

  case 1005:

/* Line 690 of lalr1.cc  */
#line 5865 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("constraint"))); }
    break;

  case 1006:

/* Line 690 of lalr1.cc  */
#line 5866 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("check"))); }
    break;

  case 1007:

/* Line 690 of lalr1.cc  */
#line 5867 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("key"))); }
    break;

  case 1008:

/* Line 690 of lalr1.cc  */
#line 5868 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("foreach"))); }
    break;

  case 1009:

/* Line 690 of lalr1.cc  */
#line 5869 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("foreign"))); }
    break;

  case 1010:

/* Line 690 of lalr1.cc  */
#line 5870 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("keys"))); }
    break;

  case 1011:

/* Line 690 of lalr1.cc  */
#line 5871 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ancestor"))); }
    break;

  case 1012:

/* Line 690 of lalr1.cc  */
#line 5872 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("child"))); }
    break;

  case 1013:

/* Line 690 of lalr1.cc  */
#line 5873 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descendant"))); }
    break;

  case 1014:

/* Line 690 of lalr1.cc  */
#line 5874 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("parent"))); }
    break;

  case 1015:

/* Line 690 of lalr1.cc  */
#line 5875 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preceding"))); }
    break;

  case 1016:

/* Line 690 of lalr1.cc  */
#line 5876 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("self"))); }
    break;

  case 1017:

/* Line 690 of lalr1.cc  */
#line 5877 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("following"))); }
    break;

  case 1018:

/* Line 690 of lalr1.cc  */
#line 5878 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ancestor-or-self"))); }
    break;

  case 1019:

/* Line 690 of lalr1.cc  */
#line 5879 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descendant-or-self"))); }
    break;

  case 1020:

/* Line 690 of lalr1.cc  */
#line 5880 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("following-sibling"))); }
    break;

  case 1021:

/* Line 690 of lalr1.cc  */
#line 5881 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preceding-sibling"))); }
    break;

  case 1022:

/* Line 690 of lalr1.cc  */
#line 5882 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("position"))); }
    break;

  case 1023:

/* Line 690 of lalr1.cc  */
#line 5883 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("json"))); }
    break;

  case 1024:

/* Line 690 of lalr1.cc  */
#line 5884 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("append"))); }
    break;

  case 1025:

/* Line 690 of lalr1.cc  */
#line 5885 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("json-item"))); }
    break;

  case 1026:

/* Line 690 of lalr1.cc  */
#line 5886 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("array"))); }
    break;

  case 1027:

/* Line 690 of lalr1.cc  */
#line 5887 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("object"))); }
    break;

  case 1028:

/* Line 690 of lalr1.cc  */
#line 5888 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("structured-item"))); }
    break;

  case 1029:

/* Line 690 of lalr1.cc  */
#line 5891 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), true); }
    break;



/* Line 690 of lalr1.cc  */
#line 12341 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"
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
  const short int xquery_parser::yypact_ninf_ = -1528;
  const short int
  xquery_parser::yypact_[] =
  {
      4627, -1528, -1528, -1528, -1528,  6181,  6181,  6181,  6181, -1528,
   -1528,   363,   465, -1528,  1029,   266, -1528, -1528, -1528,    42,
   -1528, -1528, -1528,   438,   508,   823,  4345,   537,   616,   142,
   -1528,    62, -1528,   622, -1528, -1528, -1528, -1528, -1528,   828,
   -1528,   651,   766, -1528, -1528, -1528, -1528,   709, -1528,   832,
   -1528,   827,   843, -1528,   355, -1528, -1528, -1528, -1528, -1528,
   -1528, -1528, -1528, -1528, -1528, -1528, -1528, -1528, -1528,   842,
     895, -1528, -1528, -1528, -1528,   692, 12691, -1528, -1528, -1528,
     902, -1528, -1528, -1528,   908, -1528,   909,   916, -1528, -1528,
   16562, -1528, -1528, -1528, -1528, -1528, -1528, -1528, -1528,   934,
   -1528, -1528,   931,   932, -1528, -1528, -1528, -1528, -1528, -1528,
   -1528,  5251,  8661,  8971, 16562, -1528, -1528,   904, -1528, -1528,
   -1528, -1528,   905, -1528, -1528,   937, 16562, -1528, 13602,   938,
     939, -1528, -1528, -1528,   940, -1528, 12071, -1528, -1528, -1528,
   -1528, -1528, -1528,   917, -1528, -1528, -1528, -1528, -1528, -1528,
   -1528, -1528,   144,   856, -1528, -1528, -1528, -1528, -1528, -1528,
   -1528, -1528,   -97,   918,   215, -1528,  -100,   -14, -1528, -1528,
   -1528, -1528, -1528, -1528,   955, -1528,   836,   837,   838, -1528,
   -1528,   922,   928, -1528, -1528, -1528, -1528, -1528, -1528, -1528,
   -1528, -1528, -1528, -1528, -1528, -1528, -1528, -1528, -1528, -1528,
   -1528, -1528, -1528, -1528, -1528, -1528, -1528, -1528, -1528, -1528,
   -1528, -1528, -1528, -1528, -1528, -1528, -1528, -1528, -1528, -1528,
   -1528, -1528, -1528, -1528, -1528, -1528, -1528, -1528, -1528, -1528,
   -1528, -1528, -1528, -1528, -1528, -1528, -1528, -1528, -1528, -1528,
   -1528, -1528, -1528, -1528, -1528, -1528,  9281,  9591, -1528,   769,
   -1528, -1528, -1528, -1528, -1528,  4939,  6491,  1084, -1528,  6801,
   -1528, -1528,   848,   103, -1528, -1528, -1528, -1528, -1528, -1528,
   -1528, -1528, -1528, -1528, -1528, -1528, -1528, -1528,   111, -1528,
   -1528, -1528, -1528, -1528, -1528,   440, -1528, -1528, -1528, -1528,
   -1528, -1528, -1528, -1528,  6181, -1528, -1528, -1528, -1528,   240,
   -1528, -1528, -1528, -1528, -1528, -1528, -1528, -1528,   230, -1528,
     899, -1528, -1528, -1528,   686, -1528, -1528, -1528, -1528, -1528,
   -1528, -1528, -1528,   924,   992, -1528,   791,   844,   994,   667,
     586,   762,   808, -1528,  1042,   896,   993,   995, 10831, -1528,
     906, -1528, -1528,   270, -1528, -1528, 12381, -1528,   814, -1528,
     942, 12691, -1528,   942, 12691, -1528, -1528, -1528,   821, -1528,
   -1528, -1528, -1528, -1528, -1528, -1528, -1528, -1528, -1528, -1528,
   -1528, -1528, -1528, -1528, -1528, -1528, -1528, -1528, -1528, -1528,
   -1528, -1528, -1528, -1528, -1528, -1528,   943, -1528, -1528, -1528,
   -1528, -1528, -1528, -1528, -1528, -1528, -1528, -1528, -1528, -1528,
   -1528, -1528, -1528, -1528, -1528, -1528, -1528, -1528, -1528, -1528,
   -1528, -1528, -1528, -1528,   798, -1528, -1528, -1528, -1528, -1528,
     921, -1528,  6181,   926,   927,   929,  6181,   656,   656,  1071,
     714,   764,   740, 17158, 16562,     5,  1055, 16562,   961,   989,
     353, 16562,   770,   869, 16562, 16562,   812,    59,    80, -1528,
   -1528, -1528, 16562,  6181,   930,  6181,    70, 11141, 13898, 16562,
   -1528,   835,   841, 16562,  1001,   247,   967, 11141,  1125,   101,
      72, 16562,  1008,   985,  1021, -1528,   944, 11141, 14194, 16562,
   16562, 16562,  6181,   945, 11141, 11141, 16562,  6181,   976,   979,
   -1528, -1528, -1528, 11141, 14490,   977, -1528,   980, -1528, -1528,
   -1528, -1528,   981, -1528,   982, -1528, -1528, -1528, -1528, -1528,
     983, -1528, -1528, -1528, -1528, -1528, -1528, -1528, -1528, -1528,
   -1528, -1528, -1528, -1528, -1528, -1528, -1528, -1528, -1528, -1528,
   -1528, -1528, -1528, -1528, -1528, -1528, -1528, -1528, -1528, 16562,
   -1528, -1528, -1528, -1528, -1528, -1528, -1528, -1528, -1528, -1528,
   -1528, -1528, -1528,  1005, 16562, -1528, -1528, -1528,   960,  5561,
    1027,   280,   997,  1000,  1002, 16562,  6181, -1528,   996,   321,
   -1528,   696, -1528,   131,  1116, 11141, 11141, -1528,    89, -1528,
   -1528,  1135, -1528, -1528, -1528, -1528, 11141,   946, -1528,  1128,
   11141, 11141, 16862, 11141, 11141, 11141, 11141, 16862, 11141,   933,
     941, 16562,   971,   972, 11141, 11141,  5251,   948, -1528,    75,
   -1528,    58, 11141,  6491, -1528, -1528, -1528, -1528, -1528,  1029,
     142,   115,   116,  1160,  7111,  3083,  7421,  3404,   908, -1528,
   -1528,   330,   908, -1528, 11141,  4024, -1528,  1053,   820,    62,
    1006,  1003,  1007,  6181, 11141, -1528, -1528, -1528, -1528, -1528,
   -1528, -1528, -1528, 11451, 11451, 11451, -1528, 11451, 11451, -1528,
   11451, -1528, 11451, -1528, -1528, -1528, -1528, -1528, -1528, -1528,
   11451, 11451,  1104, 11451, 11451, 11451, 11451, 11451, 11451, 11451,
   11451, 11451, 11451, 11451, 11451,   947,  1081,  1087,  1088, -1528,
   -1528, -1528, 11761,  9901, -1528, -1528, 12071, 12071, 11141,   942,
   -1528, -1528,   942, -1528, 10211,  7731,   942,   998,  1036,  8041,
   -1528, -1528, -1528, -1528,    61, -1528,   279, -1528, -1528, -1528,
   -1528, -1528, -1528,  1079,  1086,   537,  1149, -1528, -1528, 17158,
     962,   466, 16562,  1028,  1034,   962,  1071,  1068,  1064, -1528,
   -1528, -1528,   127,   952,  1105,   903, 16562,  1058, 11141,  1085,
   16562, 16562, -1528,  1070,  1024, -1528,  1025,   980,   766, -1528,
    1026,  1030,   184, -1528,   338,   362,  1103, -1528,    53, -1528,
   -1528,  1103, 16562,    34, 16562,  1117,   369, -1528,  6181, -1528,
     134, -1528, 16562,  1118,  1169, 16562,  1071,  1119,   526, 16562,
   11141,    62, -1528,   340,  1032, -1528,  1033,  1035,  1037,    37,
   -1528,   439,  1039, -1528,   137,   150,  1075, -1528,  1046,  6181,
    6181,   346, -1528,   384,   392,   540, 11141,   286, -1528, -1528,
   11141, 11141, -1528, 11141, 11141, 11141, -1528, 11141, -1528, 11141,
   -1528, 16562,  1116, -1528,   292,   361,   371, -1528, -1528, -1528,
     376, -1528,    28, -1528, -1528,  1077,  1078,  1080,  1083,  1089,
     821,   798,   317,   525,   -12,    16,  1140,   597,  1010,  1013,
    1011,    32, -1528,  1096, -1528, -1528,  1054,   163,  5561,   391,
   13001,   948, -1528, -1528, -1528,  1012, -1528,   848,   702,  1217,
     724, -1528, -1528,   117, -1528, -1528, -1528,   121, -1528,    66,
   -1528, -1528, -1528, -1528, -1528,  3714, -1528, -1528, -1528, 16562,
    1082, 11141,  1132, -1528, -1528, -1528,   992, -1528, -1528, -1528,
   -1528, -1528, 11451, -1528, -1528, -1528,    84, -1528,   586,   586,
     452,   762,   762,   762,   762,   808,   808, -1528, -1528, 15674,
   15674, 16562, 16562, -1528, -1528,   414, -1528, -1528,   327, -1528,
   -1528, -1528, -1528, -1528,   431, -1528, -1528, -1528,   457,   656,
   -1528, -1528,   776,   788,   802, -1528,   537, -1528, -1528, -1528,
   -1528, -1528, -1528, -1528, -1528, -1528, -1528,   962, -1528,  1120,
   15970,  1111, 11141, -1528, -1528, -1528,  1161,  1071,  1071,   962,
   -1528,   887,  1071,   725, 16562,   687,   688,  1228, -1528, -1528,
     974,   674, -1528, -1528, -1528, -1528, -1528, -1528, -1528, -1528,
   -1528, -1528, -1528,   127,    38,  1040,   665, 11141, -1528, 16562,
    1167,   965,  1071, -1528, -1528, -1528, -1528,  1112, 16562, -1528,
   16562, -1528, 16266,  1141, 15674,  1151, 11141,    29,  1123,    56,
     483,  1014, -1528, -1528,   744,    34,  1161, 15674,  1153,  1178,
    1091,  1090,  1144,  1071,  1121,  1145,  1182,  1071, 11141,    22,
   -1528, -1528, -1528,  1126, -1528, -1528, -1528, -1528,  1165, 11141,
   11141,  1137, -1528,  1188,  1190,  6181, -1528,  1108,  1109,  1142,
   16562, -1528, 16562, -1528, 11141,  1154,  1110, 11141, -1528,  1172,
     212,   234,   252,  1263, -1528,   386, -1528,    86,  1150, -1528,
   -1528,  1273, -1528,   780, 11141, 11141, 11141,   781, 11141, 11141,
   11141, 11141, 11141, 11141, 11141, 11141, 11141, 16862,  1186, 11141,
   11141, -1528,  8351,   119,  1066, -1528,    14, -1528, 11141,   125,
     379,    66,  7421,  3404,  7421,  1233, -1528, -1528, 11141,    91,
    1207, -1528, 16562,  1209, -1528, -1528, 11141,    84,   759,   615,
   -1528,  1038,   400,  1060,  1059, -1528, -1528,   869, -1528,  1063,
     664,  1163,  1164, 15970,  1168,  1170,  1174,  1179,  1180, -1528,
     666, -1528, -1528, -1528, -1528, -1528, -1528, -1528, -1528, -1528,
   -1528, -1528, -1528, -1528,  1177, -1528, -1528, -1528, -1528, 10521,
   -1528, -1528, -1528, -1528, -1528, -1528, -1528, -1528, -1528,   804,
   -1528,  1305,   596, -1528, -1528, -1528, -1528, -1528, -1528, -1528,
   -1528, -1528,  1052, -1528, -1528,  1309, -1528, -1528, -1528, -1528,
   -1528,   698,  1310, -1528,   571, -1528, -1528, -1528,   977,   508,
     622,   981,   651,   982,   983, -1528,  1170,  1174,  1179, -1528,
     666,   666, 11761,  1056,  1044, -1528,  1161,    38,  1115,  1155,
    6181,  1159,  1166,  1206,  1171,  1173, 16562, -1528,   422, -1528,
   16562, -1528, 11141,  1204, 11141,  1226, 11141,   192,  1211, 11141,
    1213, -1528,  1236,  1238, 11141, 16562,   898,  1284, -1528, -1528,
   -1528, -1528, -1528, -1528, 15674, -1528,  6181,  1071,  1255, -1528,
   -1528, -1528,  1071,  1255, -1528, 11141,  1221,  6181, 16562, -1528,
   -1528, 11141, 11141,   592, -1528,    46,   598, -1528, 14786,   671,
   -1528,   801, -1528,  1184, -1528, -1528,  6181,  1183,  1185, -1528,
   11141, -1528, -1528, 11141,  1181,  1188,  1265, -1528,  1242, -1528,
      96, -1528, -1528,  1364, -1528, -1528,  6181, 16562, -1528,   506,
   -1528, -1528, -1528,  6181,  1187,  1143,  1147, -1528, -1528, -1528,
    1148,  1152, -1528, -1528, -1528,  1281, -1528, -1528, -1528, -1528,
    1146,   356, 16562,  1198, -1528,  1229,  1230,  1232,  1237, -1528,
     899,   717, 13001,  1066, -1528,  5871, 13001, -1528, -1528,  1217,
     539, -1528, -1528, -1528,  1207, -1528,  1071, -1528,   891, -1528,
     570,  1285, -1528, 11141,   641,  1132,   424,  1210, -1528,    84,
    1158, -1528, -1528,   -28, -1528,   699,   139,  1162,    84,   699,
   11451, -1528,   404, -1528, -1528, -1528, -1528, -1528, -1528,    84,
    1245,  1114,   952,   139, -1528, -1528,  1113,  1315, -1528, -1528,
   -1528, 13297,  1214,  1215,  1216,  1218,  1223,  1224,  1227, -1528,
   -1528, -1528, -1528, -1528, -1528, -1528, -1528, -1528, -1528, -1528,
   -1528, -1528,  1368,   343,  1370,   343,  1133,  1307, -1528, -1528,
    1243, 16562,  1175, -1528, -1528, 11761, -1528,  1234, -1528, -1528,
   -1528, -1528, -1528, -1528, 11141,  1268, -1528, -1528, 11141, -1528,
     557, -1528, 11141,  1272, 11141, -1528, 11141, 16562, 16562, -1528,
     643, -1528, 11141, -1528,  1292,  1294,  1325,  1071,  1255, -1528,
   11141,  1239, -1528, -1528, -1528,  1240, -1528,   258, 11141,  6181,
    1241,   302, -1528, 16562,   271, -1528, 15082,   257, -1528, 15378,
    1244, -1528, -1528,  1247, -1528, -1528, -1528, -1528, 11141,   803,
    1263, 16562,   587, -1528,  1249,  1263, 16562, -1528,  1250, -1528,
   11141, 11141, 11141, 11141,  1124, 11141, 11141, -1528, 11141, 11141,
   11141, 11141,  8351,    19, -1528, -1528, -1528, -1528, -1528,  1285,
   -1528, -1528, -1528,  1071, 11141, -1528,  1282, -1528, -1528, -1528,
   -1528,  1251, 11451, -1528, -1528, -1528, -1528, -1528,   475, 11451,
   11451,   544, -1528,  1060, -1528,   282, -1528,  1059,    84,  1270,
   -1528, -1528,  1176, -1528, -1528, -1528, -1528,  1333,  1252, -1528,
     464, -1528, -1528, -1528, -1528, -1528, -1528, -1528, -1528,   374,
     374, -1528,   343, -1528, -1528,   486, -1528,  1399,   139,  1344,
    1256, 11761,   -20,  1157,  1275, -1528, -1528, 11141, -1528, 11141,
    1298, -1528, 11141, -1528, -1528, -1528,  1388, -1528, -1528,  8351,
   11141,  1071, -1528, -1528, -1528, 11141, 11141, -1528, -1528, -1528,
    8351,  8351,  1352,  6181, 15674, 16562,   659, 16562, 11141, 16562,
     661,  8351, -1528,   299,    60,  1263, 16562, -1528,  1253,  1263,
   -1528, -1528, -1528, -1528, -1528, 11141, -1528, -1528, -1528,   265,
     272,   275, 11141, -1528, -1528, -1528,  1341, 11141, -1528,   762,
   11451, 11451,   452,   680, -1528, -1528, -1528, -1528, -1528, -1528,
   11141, -1528, 15674, -1528, 15674,  1354, -1528, -1528, -1528,  1421,
   -1528, -1528, -1528,  1189,  1345, -1528, -1528,  1347, -1528,    99,
   16562,  1338,  1235, 16562, 11761, -1528, -1528, 11141, -1528,  1339,
   -1528, -1528,  1255, -1528, -1528, 15674, -1528, -1528, -1528,  1357,
   11141,  1276, -1528,  1366,  8351, -1528, 16562,   636,   629, -1528,
    1262,  1263, -1528,  1266, -1528,  1267,  1188,  1190,   435, -1528,
    1341,   452,   452, 11451,   449, -1528, -1528, 15674, -1528, -1528,
    1344, 11761, -1528,  1285,  1191, 16562,  1348,  1246,  1347, -1528,
   16562,   673, 15674,  6181, 15674,  1278, -1528, -1528,  1372,   670,
   -1528, -1528, -1528, -1528,  1286,   681, -1528, -1528, -1528,  1277,
   -1528,  8351,   813, -1528, -1528,   452, -1528, -1528, -1528, -1528,
   -1528, 11141,  1196, 16562,  1349, -1528,  6181,   679, -1528, -1528,
     691, 11141, -1528, -1528, -1528, -1528, -1528, -1528, -1528,  1351,
   -1528,  1192,  1199, 16562, -1528, -1528, 11141,  8351, 16562,  1197,
   11141,  1200,  1287, 11761, -1528, 11761,  8351, -1528,  1279,  1193,
   16562,  1257,  1353, 16562,  1201, 11761, -1528
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
     303,   305,     0,   293,   294,   362,     0,     0,     0,     0,
     698,   370,   671,   675,   677,   679,   681,   684,   691,   692,
     700,   927,   812,     0,   821,  1027,  1026,  1025,  1028,   389,
     580,   586,   587,   590,   635,   636,   591,   592,   798,   799,
     800,   595,   391,   393,   396,   596,   395,   423,   476,     0,
     472,   503,   125,    56,    57,    54,    55,   131,   130,     0,
      90,     0,     0,   109,   110,   115,    74,    75,    52,    53,
      73,   738,     0,   741,   768,     0,   731,   730,   735,   734,
     766,     0,     0,   743,     0,   739,   742,   721,     0,     0,
       0,     0,     0,     0,     0,   608,     0,     0,     0,   143,
     146,   148,     0,     0,     0,   113,   116,     0,     0,     0,
     168,     0,     0,   632,     0,     0,     0,   259,     0,   579,
       0,   260,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   238,     0,     0,     0,     0,   286,     0,   283,   288,
     241,   141,   136,   139,     0,   189,     0,     0,    71,    65,
      68,    67,     0,    63,   277,     0,     0,   168,     0,   321,
     325,     0,     0,     0,   328,     0,     0,   334,     0,     0,
     341,     0,   345,     0,   420,   419,   168,     0,     0,   196,
       0,   198,   322,     0,     0,     0,     0,   529,     0,   519,
       0,   552,   549,     0,   553,   554,     0,     0,   548,     0,
     523,   551,   550,     0,     0,     0,     0,   647,   648,   644,
       0,     0,   652,   653,   649,   791,   792,   658,   796,   656,
       0,     0,     0,     0,   662,   813,   820,   819,   974,   201,
       0,     0,     0,   663,   664,     0,     0,   210,   794,    26,
       0,    17,    21,    22,   304,   316,     0,   317,     0,   308,
     309,   310,   311,     0,   296,     0,     0,     0,   682,   695,
       0,   367,   371,     0,   714,     0,     0,     0,     0,     0,
       0,   670,   672,   673,   709,   710,   711,   713,   712,     0,
       0,   686,   685,     0,   689,   693,   707,   705,   704,   697,
     701,     0,     0,     0,     0,     0,     0,     0,     0,   583,
     585,   584,   581,   397,   505,   507,   133,   132,    91,   105,
     755,   736,     0,   760,     0,   760,   749,   744,   147,   149,
       0,     0,     0,   117,   145,     0,    27,     0,   629,   630,
     633,   626,   627,   258,     0,     0,   272,   264,     0,   268,
       0,   262,     0,     0,     0,   281,     0,     0,     0,   240,
     284,   287,     0,   137,     0,     0,    70,     0,    64,   278,
       0,     0,   324,   326,   331,     0,   329,     0,     0,     0,
       0,     0,   335,     0,     0,   349,     0,     0,   342,     0,
       0,   346,   421,     0,   622,   620,   197,   790,     0,     0,
     528,     0,     0,   560,     0,   528,     0,   524,     0,    14,
       0,     0,     0,     0,     0,     0,     0,   661,     0,     0,
       0,     0,     0,     0,   665,   669,   320,   318,   319,   312,
     313,   314,   306,     0,     0,   301,     0,   295,   699,   690,
     696,     0,     0,   769,   770,   780,   779,   778,     0,     0,
       0,     0,   771,   676,   777,     0,   674,   678,     0,     0,
     683,   687,     0,   708,   703,   706,   702,     0,     0,   593,
       0,   588,   640,   582,   802,   803,   801,   589,   756,     0,
       0,   754,   761,   762,   758,     0,   753,     0,   751,     0,
       0,     0,     0,     0,     0,   570,   261,     0,   270,     0,
       0,   266,     0,   269,   282,   290,   291,   285,   239,     0,
       0,     0,    66,   280,   576,     0,     0,   332,   336,   330,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   572,     0,     0,   528,     0,   555,     0,   528,
     578,   645,   646,   650,   651,     0,   657,   797,   659,     0,
       0,     0,     0,   666,   315,   302,   297,     0,   694,   781,
       0,     0,   773,     0,   719,   718,   717,   716,   715,   680,
       0,   772,     0,   637,     0,     0,   765,   764,   763,     0,
     757,   750,   748,     0,   745,   746,   740,   150,   152,   154,
       0,     0,     0,     0,     0,   265,   263,     0,   271,     0,
     206,   351,    72,   327,   333,     0,   347,   343,   350,     0,
       0,     0,   337,     0,     0,   339,     0,   538,   532,   527,
       0,   528,   518,     0,   793,     0,     0,     0,     0,   300,
     298,   775,   774,     0,     0,   638,   594,     0,   759,   752,
       0,     0,   156,   155,     0,     0,     0,     0,   151,   267,
       0,     0,     0,     0,     0,     0,   546,   540,     0,   539,
     541,   547,   544,   534,     0,   533,   535,   545,   520,     0,
     521,     0,     0,   667,   299,   776,   688,   639,   747,   153,
     157,     0,     0,     0,     0,   289,     0,     0,   340,   338,
       0,     0,   531,   542,   543,   530,   536,   537,   522,     0,
     158,     0,     0,     0,   348,   344,     0,     0,     0,     0,
       0,     0,     0,     0,   160,     0,     0,   159,     0,     0,
       0,     0,     0,     0,     0,     0,   161
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yypgoto_[] =
  {
     -1528, -1528,  -220,  -185, -1528,  1222,  1225, -1528,  1248,  -545,
   -1528, -1528, -1528, -1528, -1528, -1528, -1528, -1528, -1528, -1528,
   -1014, -1528, -1528, -1528, -1528,  -240,  -576, -1528,   741,  -367,
   -1528, -1528, -1528, -1528, -1528,   283,   515, -1528, -1528,    -3,
    -164,  1049, -1528,  1041, -1528, -1528,  -640, -1528,   450, -1528,
     253, -1528,  -223,  -269, -1528,  -560, -1528,    -4,    41,     8,
    -234,  -178, -1528,  -893, -1528, -1528,   208, -1528, -1528, -1528,
   -1528, -1528, -1528, -1528, -1528, -1528, -1528,   623,  -103,  1271,
       0, -1528, -1528, -1528, -1528,   460, -1528, -1528,  -297, -1528,
      23, -1528,  1045,  -936,  -744,  -715, -1528, -1528,   718, -1528,
   -1528,    25,   246, -1528, -1528, -1528,   128, -1527, -1528,   387,
     133, -1528, -1528,   138, -1312, -1528,   963,   226, -1528, -1528,
     227, -1019, -1528, -1528,   228, -1528, -1528, -1261, -1254, -1528,
     222, -1428, -1528, -1528,   873,   874, -1528,  -499,   854, -1528,
   -1528,  -650,   349,  -641,   347,   352, -1528, -1528, -1528,   599,
   -1528, -1528,  1195, -1528, -1528, -1528, -1528, -1528,  -891,  -325,
    -680, -1528,   -94, -1528, -1528, -1528, -1528, -1528, -1528, -1528,
      -2,  -829, -1528,  -540,   657,   269, -1528,  -408, -1528, -1528,
   -1528, -1528, -1528, -1528, -1528,   825, -1528, -1528, -1528, -1528,
   -1031, -1528,   210, -1528,   705,  -811, -1528, -1528, -1528, -1528,
   -1528,  -247,  -239, -1242,  -885, -1528, -1528, -1528, -1528, -1528,
   -1528, -1528, -1528, -1528, -1528, -1528,  -761,  -895,  -193,  -808,
   -1528, -1528, -1528,  -867, -1528, -1528, -1528, -1528, -1528, -1528,
   -1528, -1528, -1528,  1092,  1093,  -144,   521,   354, -1528, -1528,
   -1528, -1528, -1528, -1528, -1528, -1528, -1528, -1528, -1528,   191,
   -1528, -1528,   181, -1528,   185, -1053, -1528, -1528, -1528,   148,
     141,   -27,   415, -1528, -1528, -1528, -1528, -1528, -1528, -1528,
   -1528, -1528, -1528, -1528, -1528, -1528,   152, -1528, -1528, -1528,
     -23,   408,   553, -1528, -1528, -1528, -1528, -1528,   344, -1528,
   -1528, -1470, -1528, -1528, -1528,  -559, -1528,   114, -1528,   -42,
   -1528, -1528, -1528, -1528, -1325, -1528,   162, -1528, -1528, -1528,
   -1528, -1528,   968, -1528, -1528, -1528, -1528, -1528,  -929, -1528,
   -1528, -1528,  -397,   747,   237, -1528
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yydefgoto_[] =
  {
        -1,   257,   635,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
    1278,   786,   275,   276,   277,   278,   279,   280,   967,   968,
     969,   281,   282,   283,   973,   974,   975,   284,   447,   285,
     286,   714,   287,   449,   450,   451,   466,   776,   777,   288,
    1229,   289,  1707,  1708,   290,   291,   292,   558,   293,   294,
     295,   296,   297,   779,   298,   299,   540,   300,   301,   302,
     303,   304,   305,   645,   306,   307,   871,   872,   308,   309,
     570,   311,   646,   464,  1034,  1035,   312,   647,   313,   649,
     571,   315,   766,   767,  1266,   473,   316,   474,   475,   773,
    1267,  1268,  1269,   650,   651,  1133,  1134,  1555,   652,  1130,
    1131,  1379,  1380,  1381,  1382,   317,   799,   800,   318,  1293,
    1294,  1497,   319,  1296,  1297,   320,   321,  1299,  1300,  1301,
    1302,  1504,   322,   323,   324,   325,   912,   326,   327,  1391,
     328,   329,   330,   331,   332,   333,   334,   335,   336,  1173,
     337,   338,   339,   340,   670,   671,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   706,   700,   359,   360,   361,   362,
     363,   364,   365,   366,   367,   944,   368,   369,   370,   371,
     372,   373,  1329,   832,   833,   834,  1739,  1784,  1785,  1778,
    1779,  1786,  1780,  1330,  1331,   374,   375,  1332,   376,   377,
     378,   379,   380,   381,   382,   383,  1029,  1505,  1432,  1160,
    1590,  1161,  1174,   384,   385,   386,   387,   388,   389,   390,
     391,   392,   393,   394,   395,   806,  1242,   396,  1163,  1164,
    1165,  1166,   397,   398,   399,   400,   401,   402,   861,   862,
     403,  1363,  1364,  1673,  1116,  1141,  1401,  1402,  1142,  1143,
    1144,  1145,  1146,  1411,  1580,  1581,  1147,  1414,  1148,  1561,
    1149,  1150,  1419,  1420,  1586,  1584,  1403,  1404,  1405,  1406,
    1687,   743,   994,   995,   996,   997,   998,   999,  1215,  1610,
    1704,  1216,  1608,  1702,  1000,  1445,  1605,  1601,  1602,  1603,
    1001,  1002,  1407,  1415,  1571,  1408,  1567,  1392,   404,   405,
     406,   407,   561,   408,   409,   410,   411,   412,  1167,  1168,
    1169,  1170,  1279,   413,   414,   415
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const short int xquery_parser::yytable_ninf_ = -865;
  const short int
  xquery_parser::yytable_[] =
  {
       310,   420,   423,   424,   607,   310,   310,   310,   310,   569,
     573,   448,   933,   422,   422,   422,   426,   648,   694,   715,
     715,  1085,   622,   314,  1027,  1139,   920,  1049,   314,   314,
     314,   314,   718,  1283,  1159,  1172,   921,   922,   923,   924,
    1061,  1115,   585,   625,  1295,  1508,   421,   421,   421,   425,
     890,   892,   850,  1028,  1075,  1519,  1328,   857,   627,   623,
     630,  1188,  1162,  1162,   884,   888,   891,   893,  1550,  1551,
     614,   615,   783,   787,   536,  1231,   623,  1218,  1646,   882,
     886,  1650,  1219,   757,  1387,   954,  1247,  1527,  1582,  1023,
    1031,  1220,  1255,    11,    12,  1321,  1322,   837,  1221,  1710,
    1222,   758,   717,  1162,   623,  1321,  1322,    11,    12,  1223,
     820,   310,   623,   433,    13,   757,   623,   623,   623,   559,
     623,   629,   623,   434,   821,   596,   623,   433,   590,  1249,
     591,   717,   623,   758,   314,   623,  1224,  1230,   623,  1705,
    1108,   436,  1272,   609,   611,  1058,   437,  1498,  1024,  1749,
    1025,   623,   421,  1025,  1737,   436,   908,  1162,   909,   910,
    1091,   911,  1192,   913,   623,  1285,   634,   468,  1365,   949,
    1162,   914,   915,  1672,   727,   587,   469,  1252,   438,   439,
    1125,   471,   983,   634,   984,   623,   784,  1375,   630,  1563,
    1323,   631,   630,   749,  1024,    82,   453,   747,  1376,   454,
    1323,  1026,   748,   470,  1256,  1711,  1376,   728,  1377,    93,
    1324,   598,  1325,   623,   597,  1195,   599,   592,  1092,  1378,
    1324,  1101,  1325,  1794,  1366,  1059,  1564,   634,   985,  1366,
    -169,   623,  1499,   785,   107,   623,  1568,  1674,  1136,   634,
    1326,  1137,   634,  1738,   114,   634,  1139,  1139,   950,  1102,
    1326,  1032,   695,   623,   114,   310,   310,   759,   634,   310,
     126,   128,   782,  1225,   838,  1508,   623,  1109,  1488,  1260,
     126,   634,  1318,   623,   648,  1271,   623,  1501,   314,   314,
    1527,  1327,   314,  1703,   629,  1257,  1162,  1712,  1033,  1328,
    1798,  1521,   634,   624,   310,   472,  1437,  1771,  1328,   152,
     600,   626,   472,   890,   892,   877,   879,  1122,  1231,   152,
    1463,  1124,  1253,   537,  1258,  1369,  1189,   314,   830,   631,
     634,  1041,   623,   631,  1063,   630,   472,   537,   623,   472,
    -170,   623,   882,   886,  1286,   472,  1560,  1064,   634,   980,
    1472,   623,   634,  1138,  1807,  1423,  1810,   623,   632,   701,
    1112,   537,   703,   444,   762,  1226,  1227,  1228,   588,  1498,
     634,   445,   623,   537,   780,   537,   774,   750,  1017,   446,
    1230,   874,   623,   634,   793,   751,  1647,   623,   986,  1483,
     634,   804,   805,   634,   883,   887,   873,   949,   821,  1046,
     811,   987,   623,   988,  1058,  1569,  1570,  1762,   733,  1314,
     734,   878,   880,  1498,   989,   990,   991,  1162,   992,   903,
     993,   895,  1093,  1135,  -169,   623,   429,   430,  1736,   431,
     432,  1315,   310,  1086,   693,   623,   310,   452,   876,   634,
     633,  1162,   486,   735,   775,   634,   623,   435,   634,  1316,
     593,   674,   594,  1648,  1636,   314,  1018,   128,   634,   314,
     623,  1800,  1745,   310,   634,   310,   631,  1643,   675,  1746,
     736,   426,  1747,   426,   822,   472,   951,    11,    12,   634,
    1020,  1442,   835,   836,  1077,  1453,   314,  1038,   314,   634,
    1599,  1644,   310,   840,   634,  1648,  1792,   310,  1641,  1087,
     426,  1328,  1070,  1370,   754,   426,   756,  1393,  1139,   634,
    1072,  1393,   867,   869,  1465,   314,   828,  1139,  1140,   487,
     314,   704,  1178,   705,  -170,  1321,  1322,  1319,  1139,  1025,
     427,   737,   634,   802,  1053,  1019,  1589,  1680,   808,   595,
    1069,  1444,   634,  1115,  1024,  1094,  1095,  1545,  1508,  1179,
     441,  1182,  1473,   634,  1600,  1088,   890,   892,   890,  1021,
    1096,  1684,  1450,   628,  1162,  1089,  1039,   634,  1685,   310,
    1090,   970,  1371,  1372,  1373,  1179,   310,  1351,  1686,  1394,
    1464,  1071,  1694,  1394,   422,  1114,   488,   489,  1024,  1073,
    1196,  1197,   314,  1320,   733,  1200,   734,  1060,   537,   314,
     935,   537,   455,  1536,  1699,   938,  1321,  1322,  1177,   442,
    1190,   938,   936,   937,   971,  1681,   310,   421,  1558,   972,
    1323,   674,  1190,   310,   868,  1239,   448,  1722,  1180,  1793,
    1097,  1024,   428,  1556,   310,   310,   310,   310,   675,   314,
    1324,  1259,  1325,  1796,   630,  1024,   314,  1119,  1321,  1162,
     443,  1776,  1162,   310,  1181,  1321,   736,   314,   314,   314,
     314,  1695,  1395,  1396,  1025,  1397,  1395,  1396,  1782,  1397,
    1326,  1126,  1398,  1123,   114,   456,   314,   880,  1212,  1048,
     725,   537,  1399,  1700,   537,  1776,  1399,  1376,   537,  1321,
     126,   537,   537,  1074,  1400,  1213,    13,  1139,  1400,   537,
    1321,  1323,  1104,  1292,   465,   537,   537,  1262,  1378,  1292,
     537,  1526,  1263,   885,   677,  1619,  1495,   737,   537,  1654,
    1782,  1324,  1500,  1325,  1658,   537,   537,   537,   537,   152,
    1080,  1081,  1082,   537,   869,   885,  1620,  1501,   637,  1140,
    1140,   537,   638,   678,   971,  1120,  1024,   639,   637,   972,
    1025,  1326,   638,  1098,  1099,   114,   679,   639,  1553,  1728,
    1575,   620,   704,  1324,   705,  1325,   640,  1121,  1100,   637,
    1324,   126,  1325,   638,  1783,  1113,   640,    82,   639,  1389,
    1777,  1212,  1506,   467,  1040,  1614,   537,  1162,   310,   476,
     680,    93,  1656,  1326,  1554,  1507,   422,   640,  1213,    13,
    1326,   537,   128,   890,  1324,  1442,  1325,  1755,  1262,  1756,
     152,   314,   537,  1263,  1813,  1324,   107,  1325,   479,   310,
     310,  1429,  1443,  1684,   694,   492,  1816,   426,   426,   421,
    1685,   459,  1264,   460,  1326,  1162,   674,  1162,   481,   851,
    1686,  1214,   314,   314,   851,  1326,   894,   553,   537,   674,
     896,  1025,  1430,   675,  1740,  1730,   493,  1734,  1743,   494,
    1067,  1068,  1781,  1787,   641,  1444,   675,   642,  1162,  1806,
    1431,   574,  1797,  1265,   641,  1826,   676,   642,   310,  1644,
      82,  1644,   643,   578,  1241,   581,  1244,  1827,  1359,  1753,
    1486,   619,   829,  1644,    93,   641,   448,   461,   642,  1644,
    1162,   314,   462,   895,  1781,   310,   719,   620,   644,   880,
    1787,  1644,  1509,  1542,  1506,  1162,   723,  1162,   644,   107,
     720,  1416,  1417,  1136,  1506,  1510,  1137,  1653,   314,  1682,
    1683,  1679,   724,   480,   655,  1183,  1307,  1819,  1308,   644,
    1789,  1709,   656,   657,  1418,   658,   128,  1185,  1367,   463,
    1187,  1184,  1436,   659,   708,   683,   721,   660,  1763,   661,
    1206,  1208,  1262,  1186,   662,   709,   778,  1263,   778,   684,
     722,  1207,  1209,   681,  1233,   490,   956,  1565,   939,   537,
     663,   939,   682,  1234,  1566,   939,   704,   457,   705,  1546,
     458,  1140,   477,   537,   484,   478,   482,   537,   537,   483,
    1140,   739,   740,   741,   664,   665,   666,   667,   668,   669,
     485,  1140,  1201,  1202,  1203,   696,   697,   699,  1204,   537,
     702,   537,  1335,  1340,  1336,  1341,  1198,  1199,   491,   537,
    1547,  1548,   537,   918,   919,   538,   537,   539,   925,   926,
    1751,  1752,   541,  1386,  1709,   927,   928,  1448,  1449,   542,
    1696,  1697,  1484,   957,   958,   959,   960,   961,   962,   963,
     964,   965,   966,   554,   555,   556,    11,    12,   575,   576,
     577,   582,   583,   584,   648,   310,   429,   430,   537,   431,
     432,   586,   589,   426,   601,  -608,   433,   602,   603,   605,
     604,  1709,   606,   612,   616,   654,   434,   435,   314,   636,
    1632,   653,   685,   672,   673,   687,   686,   698,   688,   692,
     707,   717,   729,  1795,   436,   710,  1303,   537,   732,   437,
     711,   712,  1360,   713,   731,   742,   746,   755,   448,   769,
     772,   778,   310,   310,   310,   770,   781,   789,   790,   791,
     809,   792,   803,   810,   454,  1361,   537,   458,   478,   483,
     494,   438,   439,   440,   818,   314,   314,   314,   816,   820,
     827,   831,   839,  1837,   823,  1838,  1675,   824,   842,   825,
     841,   864,   865,   881,   859,  1846,   537,   537,   537,   537,
    1140,   860,   899,   901,   900,   916,   930,   902,   929,   955,
     607,   726,   931,   932,   730,   945,   946,   952,   738,   977,
     441,   744,   745,   870,   953,   978,   981,   982,  1003,   753,
    1004,  1007,  1005,  1012,  1009,   765,   768,   537,  1013,  1014,
     768,  1022,  1037,  1015,  1044,  1043,  1047,  1016,   788,  1054,
    1055,   537,  1056,  1062,  1057,   796,   797,   798,   801,  1065,
    1066,   453,   457,   807,   477,  1103,  1457,   482,  1106,  1110,
     310,   814,  1107,   493,  1111,  1118,   537,  1105,   422,   442,
    1121,  1132,  1128,  1191,   972,   537,  1024,   537,  1210,   537,
    1211,   537,  1237,   314,  1238,  1638,  1240,  1232,  1261,  1248,
    1250,  1254,   774,  1274,   537,  1275,   310,  1277,  1281,  1282,
    1287,   421,  1280,  1491,  1288,  1291,   815,   310,  1276,  1292,
     443,  1298,  1304,  1305,  1313,   422,  1306,  1310,  1317,   314,
    1311,   801,  1513,  1334,  1333,  1352,   310,   537,   903,   537,
     314,  1362,   826,   735,   422,  1383,   444,  1385,  1409,  1410,
    1421,  1422,  1433,  1390,   445,  1424,   310,  1425,   421,   314,
    1413,  1426,   446,   310,   426,    13,  1427,  1428,  1440,  1441,
    1446,   426,  1455,  1451,   851,  1456,  1458,   421,   863,   314,
    1452,  1460,  1468,  1459,  1470,  1477,   314,  1478,  1461,  1474,
    1462,  1476,  1482,  1487,  1490,  1360,  1506,  1524,  1512,   537,
    1514,  1523,  1515,   868,  1528,  1520,  1530,  1529,  1534,  1518,
    1531,  1532,   560,  1535,  1538,  1533,  1539,  1540,  1361,  1541,
     537,  1365,  1376,  1578,  1585,  1720,  1579,  1559,  1598,  1583,
    1604,  1591,  1592,  1593,  1607,  1594,  1724,  1638,  1562,  1726,
    1595,  1596,  1572,  1611,  1597,  1609,  1617,  1735,  1615,  1629,
    1622,  1630,  1631,  1634,  1690,  1677,  1635,  1640,  1692,  1701,
    1651,  1652,  1613,  1657,  1660,  1678,  1669,  1670,  1671,  1693,
    1665,  1212,  1719,  1706,  1713,  1714,  1717,  1725,  1553,  1757,
    1742,  1758,  1772,  1760,  1759,  1761,  1691,  1765,  1770,  1788,
    1766,  1774,  1773,  1790,  1811,  1791,  1812,  1803,  1823,  1815,
    1828,  1804,  1843,  1836,  1818,  1439,   979,   716,  1839,   976,
    1840,   617,  1842,   537,   618,  1829,  1193,   537,  1273,   752,
    1454,  1768,  1799,  1006,  1117,  1270,  1801,  1010,  1011,   310,
    1726,  1821,   537,  1833,  1830,  1627,  1835,  1845,   771,  1052,
     621,   537,  1481,  1557,  1492,  1374,  1552,   817,  1549,  1030,
    1496,  1036,   314,  1511,  1502,   537,   906,   917,   907,  1042,
    1522,  1176,  1045,   691,   948,   537,  1050,  1084,  1817,  1808,
    1814,  1245,  1360,  1537,  1544,  1438,  1573,  1543,   760,   761,
    1577,  1689,  1688,  1388,  1576,  1412,  1217,  1484,  1447,  1606,
    1698,  1574,     0,   855,   537,  1361,     0,     0,     0,  1748,
       0,     0,  1824,     0,     0,     0,     0,     0,  1083,     0,
       0,     0,     0,     0,     0,     0,     0,  1754,     0,   537,
       0,     0,     0,  1824,     0,     0,     0,     0,     0,   537,
       0,     0,  1808,   537,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1360,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1360,  1360,     0,   310,     0,     0,  1127,     0,     0,     0,
       0,  1360,  1361,     0,     0,     0,     0,     0,   537,     0,
       0,     0,     0,  1361,  1361,     0,   314,     0,     0,     0,
       0,     0,     0,     0,  1361,     0,  1171,  1171,  1175,  1175,
       0,     0,     0,     0,     0,     0,     0,     0,   537,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   537,   537,     0,  1171,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1205,     0,     0,  1360,     0,     0,     0,     0,     0,
     537,     0,     0,   537,     0,     0,   537,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1236,  1361,   537,     0,
       0,     0,     0,   537,     0,  1243,     0,  1243,     0,   768,
       0,  1171,     0,   310,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1171,     0,     0,     0,     0,     0,
       0,  1360,     0,     0,     0,     0,   314,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   310,     0,     0,     0,
       0,     0,     0,     0,  1361,     0,     0,   807,     0,   807,
       0,     0,     0,     0,     0,     0,     0,  1360,     0,   314,
       0,     0,     0,     0,     0,     0,  1360,   560,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1361,     0,     0,     0,     0,     0,     0,     0,     0,  1361,
       0,   843,   844,     0,   852,   853,   854,   856,     0,   858,
       0,     0,     0,     0,     0,   866,     0,     0,     0,  1384,
       0,   537,   537,   875,   537,     0,   537,     0,     0,     0,
       0,     0,     0,   537,     0,     0,     0,     0,     0,     0,
    1171,     0,     0,     0,     0,   897,   898,     0,     0,     0,
       0,     0,     0,     0,   904,   905,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   537,
       0,   537,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   537,     0,     0,
     537,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   537,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   537,     0,     0,   943,     0,     0,     0,
     943,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   768,   537,     0,     0,  1466,     0,     0,
       0,     0,   537,     0,     0,     0,     0,   537,     0,   537,
       0,   537,  1480,     0,     0,     0,     0,     0,     0,  1008,
       0,  1171,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   801,     0,     0,     0,     0,
     537,     0,     0,     0,     0,  1171,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     537,  1051,     0,     0,     0,   537,     0,     0,     0,     0,
       0,     0,     0,     0,  1525,     0,     0,   537,     0,     0,
     537,     0,     0,     0,     0,     0,     0,  1076,     0,     0,
       0,  1078,  1079,     0,     0,     0,     0,     0,     0,   863,
     904,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   898,     0,  1171,     0,
       0,     0,  1129,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1612,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1625,  1626,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1194,     0,     0,     0,     0,     0,     0,
    1642,     0,     0,  1171,     0,     0,  1171,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1655,     0,
       0,     0,     0,  1659,     0,     0,     0,     0,  1235,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1251,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1284,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1289,  1290,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1309,     0,     0,  1312,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1337,  1338,  1339,     0,  1342,
    1343,  1344,  1345,  1346,  1347,  1348,  1349,  1350,     0,     0,
    1353,  1354,     0,     0,     0,     0,     0,     0,     0,  1368,
       0,  1171,  1729,     0,  1731,     0,  1733,     0,     0,  1129,
       0,     0,     0,  1741,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1171,
       0,  1171,     0,     0,     0,     0,     0,     0,     0,     0,
    1435,     0,     0,     0,     0,     0,     0,  1764,     0,     0,
    1767,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1171,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1775,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1171,     0,     0,     0,     0,     0,
       0,     0,  1802,     0,     0,     0,     0,  1805,     0,  1171,
       0,  1171,     0,  1467,     0,  1469,     0,  1471,     0,     0,
    1475,     0,     0,     0,     0,  1479,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1485,     0,     0,
    1822,     0,     0,     0,     0,     0,  1489,     0,     0,     0,
       0,     0,  1493,  1494,     0,     0,     0,     0,     0,     0,
    1831,     0,     0,     0,     0,  1832,     0,     0,     0,     0,
       0,  1516,     0,     0,  1517,     0,     0,  1841,     0,     0,
    1844,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1129,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1616,     0,     0,     0,  1618,
       0,     0,     0,  1621,     0,  1623,     0,  1624,     0,     0,
       0,     0,     0,  1628,     0,     0,     0,     0,     0,     0,
       0,  1633,     0,     0,     0,     0,     0,     0,     0,  1637,
    1639,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1485,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1661,  1662,  1663,  1664,     0,  1666,  1667,     0,  1668,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1676,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1715,     0,
    1716,     0,     0,  1718,     0,     0,     0,     0,     0,     0,
       0,  1721,     0,     0,     0,     0,  1723,  1639,     0,     0,
       0,     0,     0,     0,  1727,     0,     0,     0,     0,  1732,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1744,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1750,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1769,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1727,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1809,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1820,     0,     0,     0,     0,  1825,     0,     0,
       0,     0,  1809,  -165,   885,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     1,     2,     0,  1825,     0,     3,
       0,  1834,     0,     4,     5,     6,     7,     8,     9,    10,
      11,    12,     0,    13,     0,     0,    14,   417,     0,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,     0,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,     0,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,     0,    72,    73,
      74,    75,    76,     0,    77,    78,    79,     0,     0,    80,
      81,     0,     0,     0,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,     0,     0,     0,    93,     0,
      94,    95,    96,    97,     0,    98,     0,     0,     0,    99,
     100,   101,   102,   103,     0,     0,     0,     0,     0,     0,
     104,   105,   106,   107,   108,   109,   110,   111,   112,     0,
     113,   114,   115,   116,   117,     0,     0,     0,   118,   119,
     120,   121,   122,   123,   124,   125,     0,   126,     0,   127,
     128,     0,     0,   129,   130,   131,     0,     0,     0,   132,
       0,   133,   134,     0,   135,   136,     0,   137,     0,   138,
       0,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,     0,     0,   150,   151,   152,     0,   419,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,     0,   196,   197,   198,     0,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,     0,   247,     0,   248,   249,   250,
     251,   252,   253,   254,  -165,   885,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     1,     2,     0,     0,     0,
       3,     0,     0,     0,     4,     5,     6,     7,     8,     9,
      10,    11,    12,     0,    13,     0,     0,   889,   417,     0,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,   418,    30,    31,    32,    33,    34,     0,
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
     147,   148,   149,     0,     0,   150,   151,   152,     0,   419,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,     0,   196,   197,   198,     0,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   885,   247,     0,   248,   249,
     250,   251,   252,   253,   254,     1,     2,     0,     0,     0,
       3,     0,     0,     0,     4,     5,     6,     7,     8,     9,
      10,    11,    12,     0,    13,     0,     0,   416,   417,     0,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,   418,    30,    31,    32,    33,    34,     0,
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
     147,   148,   149,     0,     0,   150,   151,   152,     0,   419,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,     0,   196,   197,   198,     0,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   885,   247,     0,   248,   249,
     250,   251,   252,   253,   254,     1,     2,     0,     0,     0,
       3,     0,     0,     0,     4,     5,     6,     7,     8,     9,
      10,     0,     0,     0,    13,     0,     0,   416,   417,     0,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,   562,   418,    30,    31,    32,    33,    34,     0,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,     0,    48,    49,    50,   563,   564,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,     0,    72,
      73,    74,    75,    76,     0,    77,    78,    79,     0,     0,
      80,    81,     0,     0,     0,    82,    83,   512,    85,    86,
      87,    88,    89,   565,    91,    92,     0,     0,     0,    93,
       0,    94,    95,    96,    97,     0,    98,     0,     0,     0,
      99,   100,   101,   102,   103,     0,     0,     0,     0,     0,
       0,   104,   105,   106,   107,   108,   109,   110,   566,   112,
       0,   113,   114,   115,   116,   117,     0,     0,     0,   118,
     119,   120,   121,   122,   123,   124,   125,     0,   126,     0,
     127,   128,     0,     0,   129,   130,   131,     0,     0,     0,
     132,     0,   133,   134,     0,   135,   136,     0,   137,     0,
     138,     0,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,     0,     0,   150,   151,   152,     0,   419,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   530,   531,   532,   179,   180,   533,   568,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,     0,   196,   197,   198,     0,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,     0,   247,     0,   248,   249,
     250,   251,   252,   253,   254,  -864,   459,     0,   460,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  -864,     0,     0,
       0,  -864,     0,     0,     0,  -864,  -864,     0,     0,     0,
       0,  -864,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   461,     0,     0,  -864,     0,   462,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  -864,     0,
    -864,  -864,  -864,     0,     0,  -864,  -864,  -864,  -864,     0,
       0,     0,  -864,  -864,     0,     0,     0,     0,     0,  -864,
       0,     0,  -864,  -864,   463,     0,     0,  -864,     0,     0,
       0,     0,  -864,  -864,     0,     0,     0,     0,  -864,     0,
       0,     0,  -864,     0,     0,     0,  -864,  -864,     0,  -864,
       0,  -864,  -864,     0,     0,     0,  -864,  -864,     0,     0,
    -864,  -864,  -864,  -864,  -864,  -864,     0,     0,  -864,     0,
       0,     0,  -864,  -864,     0,     0,  -864,     0,     0,     0,
       0,  -864,     0,     0,  -864,     0,     0,     0,     0,  -864,
    -864,  -864,  -864,  -864,     0,  -864,  -864,  -864,  -864,  -864,
       0,     0,     0,     0,  -864,  -864,  -864,     0,  -864,  -864,
    -864,  -864,  -864,  -864,     0,  -864,     0,  -864,     0,     0,
       0,     0,  -864,  -864,  -864,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  -864,     0,
    -864,     0,  -864,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  -864,     0,     0,     0,     0,  -864,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     1,     2,
       0,     0,     0,     3,     0,     0,     0,     4,     5,     6,
       7,     8,     9,    10,    11,    12,  -864,    13,  -864,     0,
      14,    15,     0,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,     0,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,     0,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,     0,    72,    73,    74,    75,    76,     0,    77,    78,
      79,     0,     0,    80,    81,     0,     0,     0,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,     0,
       0,     0,    93,     0,    94,    95,    96,    97,     0,    98,
       0,     0,     0,    99,   100,   101,   102,   103,     0,     0,
       0,     0,     0,     0,   104,   105,   106,   107,   108,   109,
     110,   111,   112,     0,   113,   114,   115,   116,   117,     0,
       0,     0,   118,   119,   120,   121,   122,   123,   124,   125,
       0,   126,     0,   127,   128,     0,     0,   129,   130,   131,
       0,     0,     0,   132,     0,   133,   134,     0,   135,   136,
       0,   137,     0,   138,     0,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,     0,     0,   150,   151,
     152,     0,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,     0,   196,   197,   198,     0,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,     0,   247,
       0,   248,   249,   250,   251,   252,   253,   254,   255,   256,
       1,     2,     0,     0,     0,     3,     0,     0,     0,     4,
       5,     6,     7,     8,     9,    10,    11,    12,     0,    13,
       0,     0,    14,    15,     0,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,     0,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,     0,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,     0,    72,    73,    74,    75,    76,     0,
      77,    78,    79,     0,     0,    80,    81,     0,     0,     0,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,     0,     0,     0,    93,     0,    94,    95,    96,    97,
       0,    98,     0,     0,     0,    99,   100,   101,   102,   103,
       0,     0,     0,     0,     0,     0,   104,   105,   106,   107,
     108,   109,   110,   111,   112,     0,   113,   114,   115,   116,
     117,     0,     0,     0,   118,   119,   120,   121,   122,   123,
     124,   125,     0,   126,     0,   127,   128,     0,     0,   129,
     130,   131,     0,     0,     0,   132,     0,   133,   134,     0,
     135,   136,     0,   137,     0,   138,     0,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,     0,     0,
     150,   151,   152,     0,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,     0,   196,   197,
     198,     0,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
       0,   247,     0,   248,   249,   250,   251,   252,   253,   254,
       0,   613,     1,     2,     0,     0,     0,     3,     0,     0,
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
       0,   129,   130,   131,     0,   557,     0,   132,     0,   133,
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
       0,   129,   130,   131,     0,   819,     0,   132,     0,   133,
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
     253,   254,     1,     2,     0,     0,     0,     3,     0,     0,
       0,     4,     5,     6,     7,     8,     9,    10,    11,    12,
       0,    13,     0,     0,   416,   417,     0,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,  1355,
     418,    30,    31,    32,    33,    34,     0,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
       0,    48,    49,    50,  1356,  1357,    53,    54,    55,    56,
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
       0,   129,   130,   131,     0,   557,     0,   132,     0,   133,
     134,     0,   135,   136,     0,   137,     0,   138,     0,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
       0,     0,   150,   151,   152,     0,   419,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,  1358,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,     0,
     196,   197,   198,     0,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,     0,   247,     0,   248,   249,   250,   251,   252,
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
     245,   246,     0,   247,     0,   248,   249,   250,   251,   252,
     253,   254,     1,     2,     0,     0,     0,     3,     0,     0,
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
      90,    91,    92,     0,     0,     0,    93,     0,    94,    95,
      96,    97,     0,    98,     0,     0,     0,    99,   100,   101,
     102,   103,     0,     0,     0,     0,     0,     0,   104,   105,
     106,   107,   108,   109,   110,   111,   112,     0,   113,   114,
     115,   116,   117,     0,     0,     0,   118,   119,   120,   121,
     122,   123,   124,   125,     0,   126,     0,   127,   128,     0,
       0,   129,   130,   131,     0,     0,     0,   132,     0,   133,
     134,     0,   135,   136,     0,   137,     0,   138,     0,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
       0,     0,   150,   151,   152,     0,   153,   154,   155,   156,
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
     253,   254,     1,     2,     0,     0,     0,     3,     0,     0,
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
     253,   254,     1,     2,     0,     0,     0,     3,     0,     0,
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
     253,   254,     1,     2,     0,     0,     0,     3,     0,     0,
       0,     4,     5,     6,     7,     8,     9,    10,    11,    12,
       0,    13,     0,     0,   889,   417,     0,    16,    17,    18,
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
     245,   246,     0,   247,     0,   248,   249,   250,   251,   252,
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
     102,   103,     0,     0,     0,     0,   941,     0,   104,   105,
     106,   107,   108,   109,   110,   566,   112,     0,   113,   114,
     115,   116,   117,     0,     0,     0,   118,   119,   120,   121,
     122,   123,   124,   125,     0,   126,     0,   127,   128,     0,
       0,   129,   130,   131,     0,     0,     0,   132,   942,   133,
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
     102,   103,     0,     0,     0,     0,   941,     0,   104,   105,
     106,   107,   108,   109,   110,   566,   112,     0,   113,   114,
     115,   116,   117,     0,     0,     0,   118,   119,   120,   121,
     122,   123,   124,   125,     0,   126,     0,   127,   128,     0,
       0,   129,   130,   131,     0,     0,     0,   132,   947,   133,
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
     253,   254,     1,     2,     0,     0,     0,     3,     0,     0,
       0,     4,     5,     6,     7,     8,     9,    10,    11,    12,
       0,    13,     0,     0,   416,   417,     0,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,  1355,
     418,    30,    31,    32,    33,    34,     0,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
       0,    48,    49,    50,  1356,  1357,    53,    54,    55,    56,
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
     177,   178,   179,   180,   181,  1358,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,     0,
     196,   197,   198,     0,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,     0,   247,     0,   248,   249,   250,   251,   252,
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
       0,   129,   130,   131,     0,     0,   567,   132,     0,   133,
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
       0,   129,   130,   131,     0,     0,     0,   132,   572,   133,
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
     245,   246,   608,   247,     0,   248,   249,   250,   251,   252,
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
     245,   246,     0,   247,   610,   248,   249,   250,   251,   252,
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
       0,   129,   130,   131,     0,   934,     0,   132,     0,   133,
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
       0,   129,   130,   131,     0,     0,   940,   132,     0,   133,
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
     102,   103,     0,     0,     0,     0,  1434,     0,   104,   105,
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
     253,   254,     1,     2,     0,     0,     0,     3,     0,     0,
       0,     4,     5,     6,     7,     8,     9,    10,     0,     0,
       0,    13,     0,     0,   416,   417,     0,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,   498,    27,   500,
     418,    30,   501,    32,    33,    34,     0,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,   503,
       0,    48,    49,    50,   505,   506,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,     0,    72,    73,    74,    75,
      76,     0,    77,    78,    79,     0,     0,    80,    81,     0,
       0,     0,    82,    83,   512,    85,    86,    87,    88,    89,
     565,    91,    92,     0,     0,     0,    93,     0,    94,    95,
      96,    97,     0,    98,     0,     0,     0,   515,   100,   101,
     102,   103,     0,     0,     0,     0,     0,     0,   104,   105,
     106,   107,   108,   109,   110,   566,   112,     0,   113,   114,
     689,   116,   117,     0,     0,     0,   118,   119,   120,   121,
     122,   123,   124,   125,     0,   126,     0,   690,   128,     0,
       0,   129,   130,   131,     0,     0,     0,   132,     0,   133,
     134,     0,   135,   136,     0,   137,     0,   138,     0,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
       0,     0,   150,   151,   152,     0,   419,   154,   155,   156,
     157,   158,   159,   160,   161,   525,   163,   526,   165,   527,
     528,   168,   169,   170,   171,   172,   173,   529,   175,   530,
     531,   532,   179,   180,   533,   534,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,     0,
     196,   197,   198,     0,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,     0,   247,     0,   248,   535,   250,   251,   252,
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
     253,   254,     1,     2,     0,     0,     0,     3,     0,     0,
       0,     4,     5,     6,     7,     8,     9,    10,     0,     0,
       0,    13,     0,     0,   416,   417,     0,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,   498,    27,   500,
     418,    30,   501,    32,    33,    34,     0,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,   503,
       0,    48,    49,    50,   505,   506,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,     0,    72,    73,    74,    75,
      76,     0,    77,    78,    79,     0,     0,    80,    81,     0,
       0,     0,    82,    83,   512,    85,    86,    87,    88,    89,
     565,    91,    92,     0,     0,     0,    93,     0,    94,    95,
      96,    97,     0,    98,     0,     0,     0,   515,   100,   101,
     102,   103,     0,     0,     0,     0,     0,     0,   104,   105,
     106,   107,   108,   109,   110,   566,   112,     0,   113,   114,
     115,   116,   117,     0,     0,     0,   118,   119,   120,   121,
     122,   123,   124,   125,     0,   126,     0,   127,   128,     0,
       0,   129,   130,   131,     0,     0,     0,   132,     0,   133,
     134,     0,   135,   136,     0,   137,     0,   138,     0,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
       0,     0,   150,   151,   152,     0,   419,   154,   155,   156,
     157,   158,   159,   160,   161,   525,   163,   526,   165,   527,
     528,   168,   169,   170,   171,   172,   173,   529,   175,   530,
     531,   532,   179,   180,   533,   534,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,     0,
     196,   197,   198,     0,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,     0,   247,     0,   248,   535,   250,   251,   252,
     253,   254,     1,     2,     0,     0,     0,     3,     0,     0,
       0,     4,     5,     6,     7,     8,     9,    10,     0,     0,
       0,    13,     0,     0,   416,   417,     0,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,   498,    27,   500,
     418,    30,   501,    32,    33,    34,     0,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,   503,
       0,    48,    49,    50,   505,   506,    53,   507,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,     0,    72,    73,    74,    75,
      76,     0,    77,    78,    79,     0,     0,    80,    81,     0,
       0,     0,    82,    83,   512,    85,    86,    87,    88,    89,
     565,    91,    92,     0,     0,     0,    93,     0,    94,    95,
      96,    97,     0,    98,     0,     0,     0,   515,   100,   101,
     102,   103,     0,     0,     0,     0,     0,     0,   104,   105,
     106,   107,   108,   109,   110,   566,   112,     0,   113,   114,
       0,   116,   117,     0,     0,     0,   118,   119,   120,   121,
     122,   123,   124,   125,     0,   126,     0,     0,     0,     0,
       0,   129,   130,   131,     0,     0,     0,   132,     0,   133,
     134,     0,   135,   136,     0,   137,     0,   138,     0,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
       0,     0,   150,   151,   152,     0,   419,   154,   155,   156,
     157,   158,   159,   160,   161,   525,   163,   526,   165,   527,
     528,   168,   169,   170,   171,   172,   173,   529,   175,   530,
     531,   532,   179,   180,   533,   534,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,     0,
     196,   197,   198,     0,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,     0,   247,     0,   248,   535,   250,   251,   252,
     253,   254,     1,     2,     0,     0,     0,     3,     0,     0,
       0,     4,     5,     6,     7,     8,     9,    10,     0,     0,
       0,    13,     0,     0,   416,   417,     0,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,   498,    27,   500,
     418,    30,   501,    32,    33,    34,     0,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,   503,
       0,    48,    49,    50,   505,   506,    53,   507,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,     0,    72,    73,    74,    75,
      76,     0,    77,    78,    79,     0,     0,    80,    81,     0,
       0,     0,    82,    83,   512,    85,    86,    87,    88,    89,
     565,    91,    92,     0,     0,     0,    93,     0,    94,    95,
      96,    97,     0,    98,     0,     0,     0,   515,   100,   101,
     102,   103,     0,     0,     0,     0,     0,     0,   104,   105,
     106,   107,   108,   109,   110,   566,   112,     0,   113,   114,
       0,   116,   117,     0,     0,     0,   118,   119,   120,   121,
     122,   123,   124,   125,     0,   126,     0,     0,     0,     0,
       0,   129,   130,   131,     0,     0,     0,   132,     0,   133,
     134,     0,     0,     0,     0,   137,     0,   138,     0,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
       0,     0,   150,   151,   152,     0,   419,   154,   155,   156,
     157,   158,   159,   160,   161,   525,   163,   526,   165,   527,
     528,   168,   169,   170,   171,   172,   173,   529,   175,   530,
     531,   532,   179,   180,   533,   534,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,     0,
     196,   197,   198,     0,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,     0,   247,     0,   248,   535,   250,   251,   252,
     253,   254,     1,     2,     0,     0,     0,     3,     0,     0,
       0,     4,     5,     6,     7,     8,     9,    10,     0,     0,
       0,    13,     0,     0,   416,   417,     0,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,   498,    27,   500,
     418,    30,   501,    32,    33,    34,     0,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,   503,
       0,    48,    49,    50,   505,   506,    53,   507,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,     0,    72,    73,    74,    75,
      76,     0,    77,    78,    79,     0,     0,    80,    81,     0,
       0,     0,    82,    83,   512,    85,    86,    87,    88,    89,
     565,    91,    92,     0,     0,     0,    93,     0,    94,    95,
      96,    97,     0,    98,     0,     0,     0,   515,     0,   101,
     102,   103,     0,     0,     0,     0,     0,     0,   104,   105,
     106,   107,     0,   109,   110,   566,   112,     0,   113,   114,
       0,   116,   117,     0,     0,     0,   118,   119,   120,   121,
     122,   123,   124,   125,     0,   126,     0,     0,     0,     0,
       0,   129,   130,   131,     0,     0,     0,   132,     0,   133,
     134,     0,     0,     0,     0,   137,     0,   138,     0,   139,
       0,   141,     0,   143,   144,   145,   146,   147,   148,   149,
       0,     0,   150,   151,   152,     0,   419,   154,   155,   156,
     157,   158,   159,   160,   161,   525,   163,   526,   165,   527,
     528,   168,   169,   170,   171,   172,   173,   529,   175,   530,
     531,   532,   179,   180,   533,   534,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,     0,
     196,   197,   198,     0,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,     0,   247,     0,   248,   535,   250,   251,   252,
     253,   254,     1,     2,     0,     0,     0,     3,     0,     0,
       0,     4,     0,     0,     0,     0,     9,    10,     0,     0,
       0,     0,     0,     0,   416,   417,     0,    16,    17,    18,
     495,    20,    21,    22,   496,    24,   497,   498,   499,   500,
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
     106,     0,   108,   109,   110,     0,     0,     0,     0,     0,
       0,   116,   518,     0,     0,     0,   118,   119,   120,   121,
     519,   123,   124,   520,     0,     0,     0,     0,     0,     0,
       0,   521,   522,   131,     0,     0,     0,   132,     0,   133,
     523,     0,     0,     0,     0,   137,     0,   138,     0,   139,
     140,   141,   142,   524,   144,   145,   146,   147,   148,   149,
       0,     0,   150,   151,     0,     0,   419,   154,   155,   156,
     157,   158,   159,   160,   161,   525,   163,   526,   165,   527,
     528,   168,   169,   170,   171,   172,   173,   529,   175,   530,
     531,   532,   179,   180,   533,   534,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,     0,
     196,   197,   198,     0,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,     0,     0,     0,     0,   248,   535,   250,   251,   252,
     253,   254,     1,     2,     0,     0,     0,     3,     0,     0,
       0,     4,     0,     0,     0,     0,     9,    10,     0,     0,
       0,     0,     0,     0,   416,   417,     0,    16,    17,    18,
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
       0,   521,   522,   131,     0,     0,     0,   132,     0,   133,
     523,     0,     0,     0,     0,   137,     0,   138,     0,   139,
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
     416,   417,     0,    16,    17,    18,   495,    20,    21,    22,
     496,    24,   497,   498,  1151,   500,   418,    30,   501,    32,
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
    1152,     0,     0,     0,  1153,     0,     0,   116,   518,     0,
       0,     0,   118,   119,   120,   121,   519,   123,   124,   520,
       0,     0,     0,     0,     0,     0,     0,   521,   522,   131,
       0,     0,     0,   132,  1587,   133,   523,     0,     0,     0,
       0,  1588,     0,   138,     0,   139,   140,   141,   142,   524,
     144,   145,   146,   147,   148,   149,     0,     0,  1154,   151,
       0,     0,   419,   154,   155,   156,   157,   158,   159,   160,
     161,   525,   163,   526,   165,   527,   528,   168,   169,   170,
     171,   172,   173,   529,   175,   530,   531,   532,   179,   180,
     533,   534,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,     0,   196,   197,   198,     0,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,     0,     0,     0,
       0,   248,   535,   250,  1155,  1156,  1157,  1158,     3,     0,
     579,   580,     0,     0,     0,     0,     0,     9,    10,     0,
       0,     0,     0,     0,     0,   416,   417,     0,    16,    17,
      18,   543,    20,    21,    22,   496,   544,   545,   498,   499,
     500,   418,    30,   501,    32,   546,    34,     0,    35,    36,
      37,    38,   547,    40,   548,   549,    43,    44,    45,    46,
     503,     0,    48,   550,    50,   505,   506,    53,   507,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,   508,   509,    71,     0,    72,    73,    74,
     551,     0,     0,    77,    78,    79,     0,     0,   511,    81,
       0,     0,     0,     0,    83,   512,    85,   513,   514,    88,
      89,     0,     0,     0,     0,     0,     0,     0,     0,    94,
      95,    96,    97,     0,    98,     0,     0,     0,   515,   100,
     101,   516,   517,     0,     0,     0,     0,     0,     0,   104,
     105,   106,     0,   108,   109,   110,     0,     0,     0,     0,
       0,     0,   116,   518,     0,     0,     0,   118,   119,   120,
     121,   519,   123,   124,   520,     0,     0,     0,     0,     0,
       0,     0,   521,   522,   131,     0,     0,     0,   132,     0,
     133,   523,     0,     0,     0,     0,     0,     0,   138,     0,
     139,   140,   141,   142,   524,   144,   145,   146,   147,   148,
     149,     0,     0,   150,   151,     0,     0,   419,   154,   155,
     156,   157,   158,   159,   160,   161,   525,   552,   526,   165,
     527,   528,   168,   169,   170,   171,   172,   173,   529,   175,
     530,   531,   532,   179,   180,   533,   534,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
       0,   196,   197,   198,     0,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,     0,     0,     3,     0,   248,   535,   250,   251,
     252,   253,   254,     9,    10,     0,     0,     0,     0,     0,
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
     131,     0,     0,     0,   132,   763,   133,   523,     0,     0,
       0,     0,   764,     0,   138,     0,   139,   140,   141,   142,
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
      10,     0,     0,     0,   794,     0,     0,   416,   417,     0,
      16,    17,    18,   543,    20,    21,    22,   496,   544,   545,
     498,   499,   500,   418,    30,   501,    32,   546,    34,     0,
      35,    36,    37,    38,   547,    40,   548,   549,    43,    44,
      45,    46,   503,     0,    48,   550,    50,   505,   506,    53,
     507,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,   508,   509,    71,     0,    72,
      73,    74,   551,     0,     0,    77,    78,    79,     0,     0,
     511,    81,     0,     0,     0,     0,    83,   512,    85,   513,
     514,    88,    89,     0,     0,     0,     0,     0,     0,     0,
       0,    94,    95,    96,    97,     0,    98,     0,     0,     0,
     515,   100,   101,   516,   517,     0,     0,     0,     0,     0,
       0,   104,   105,   106,     0,   108,   109,   110,     0,     0,
       0,     0,     0,     0,   116,   518,     0,     0,     0,   118,
     119,   120,   121,   519,   123,   124,   520,     0,     0,     0,
       0,     0,     0,     0,   521,   522,   131,     0,     0,     0,
     132,   795,   133,   523,     0,     0,     0,     0,     0,     0,
     138,     0,   139,   140,   141,   142,   524,   144,   145,   146,
     147,   148,   149,     0,     0,   150,   151,     0,     0,   419,
     154,   155,   156,   157,   158,   159,   160,   161,   525,   552,
     526,   165,   527,   528,   168,   169,   170,   171,   172,   173,
     529,   175,   530,   531,   532,   179,   180,   533,   534,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,     0,   196,   197,   198,     0,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,     0,     0,     3,     0,   248,   535,
     250,   251,   252,   253,   254,     9,    10,     0,     0,     0,
       0,     0,     0,   416,   417,     0,    16,    17,    18,   543,
      20,    21,    22,   496,   544,   545,   498,   499,   500,   418,
      30,   501,    32,   546,    34,     0,    35,    36,    37,    38,
     547,    40,   548,   549,    43,    44,    45,    46,   503,     0,
      48,   550,    50,   505,   506,    53,   507,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,   508,   509,    71,     0,    72,    73,    74,   551,     0,
       0,    77,    78,    79,     0,     0,   511,    81,     0,     0,
       0,     0,    83,   512,    85,   513,   514,    88,    89,     0,
       0,     0,     0,     0,     0,     0,     0,    94,    95,    96,
      97,     0,    98,     0,     0,     0,   515,   100,   101,   516,
     517,     0,     0,     0,     0,     0,     0,   104,   105,   106,
       0,   108,   109,   110,     0,     0,     0,     0,     0,     0,
     116,   518,     0,     0,     0,   118,   119,   120,   121,   519,
     123,   124,   520,     0,     0,     0,     0,     0,     0,     0,
     521,   522,   131,     0,     0,     0,   132,   812,   133,   523,
       0,     0,     0,     0,   813,     0,   138,     0,   139,   140,
     141,   142,   524,   144,   145,   146,   147,   148,   149,     0,
       0,   150,   151,     0,     0,   419,   154,   155,   156,   157,
     158,   159,   160,   161,   525,   552,   526,   165,   527,   528,
     168,   169,   170,   171,   172,   173,   529,   175,   530,   531,
     532,   179,   180,   533,   534,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,     0,   196,
     197,   198,     0,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
       0,     0,     3,     0,   248,   535,   250,   251,   252,   253,
     254,     9,    10,     0,     0,     0,     0,     0,     0,   416,
     417,     0,    16,    17,    18,   495,    20,    21,    22,   496,
      24,   497,   498,  1151,   500,   418,    30,   501,    32,    33,
      34,     0,    35,    36,    37,    38,   502,    40,    41,    42,
      43,    44,    45,    46,   503,     0,    48,   504,    50,   505,
     506,    53,   507,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,   508,   509,    71,
       0,    72,    73,    74,   510,     0,     0,    77,    78,    79,
       0,     0,   511,    81,     0,     0,     0,     0,    83,   512,
      85,   513,   514,    88,    89,  1503,     0,     0,     0,     0,
       0,     0,     0,    94,    95,    96,    97,     0,    98,     0,
       0,     0,   515,   100,   101,   516,   517,     0,     0,     0,
       0,     0,     0,   104,   105,   106,     0,   108,   109,  1152,
       0,     0,     0,  1153,     0,     0,   116,   518,     0,     0,
       0,   118,   119,   120,   121,   519,   123,   124,   520,     0,
       0,     0,     0,     0,     0,     0,   521,   522,   131,     0,
       0,     0,   132,     0,   133,   523,     0,     0,     0,     0,
       0,     0,   138,     0,   139,   140,   141,   142,   524,   144,
     145,   146,   147,   148,   149,     0,     0,  1154,   151,     0,
       0,   419,   154,   155,   156,   157,   158,   159,   160,   161,
     525,   163,   526,   165,   527,   528,   168,   169,   170,   171,
     172,   173,   529,   175,   530,   531,   532,   179,   180,   533,
     534,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,     0,   196,   197,   198,     0,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,     0,     0,     3,     0,
     248,   535,   250,  1155,  1156,  1157,  1158,     9,    10,     0,
       0,     0,     0,     0,     0,   416,   417,     0,    16,    17,
      18,   495,    20,    21,    22,   496,    24,   497,   498,  1151,
     500,   418,    30,   501,    32,    33,    34,     0,    35,    36,
      37,    38,   502,    40,    41,    42,    43,    44,    45,    46,
     503,     0,    48,   504,    50,   505,   506,    53,   507,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,   508,   509,    71,     0,    72,    73,    74,
     510,     0,     0,    77,    78,    79,     0,     0,   511,    81,
       0,     0,     0,     0,    83,   512,    85,   513,   514,    88,
      89,  1645,     0,     0,     0,     0,     0,     0,     0,    94,
      95,    96,    97,     0,    98,     0,     0,     0,   515,   100,
     101,   516,   517,     0,     0,     0,     0,     0,     0,   104,
     105,   106,     0,   108,   109,  1152,     0,     0,     0,  1153,
       0,     0,   116,   518,     0,     0,     0,   118,   119,   120,
     121,   519,   123,   124,   520,     0,     0,     0,     0,     0,
       0,     0,   521,   522,   131,     0,     0,     0,   132,     0,
     133,   523,     0,     0,     0,     0,     0,     0,   138,     0,
     139,   140,   141,   142,   524,   144,   145,   146,   147,   148,
     149,     0,     0,  1154,   151,     0,     0,   419,   154,   155,
     156,   157,   158,   159,   160,   161,   525,   163,   526,   165,
     527,   528,   168,   169,   170,   171,   172,   173,   529,   175,
     530,   531,   532,   179,   180,   533,   534,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
       0,   196,   197,   198,     0,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,     0,     0,     3,     0,   248,   535,   250,  1155,
    1156,  1157,  1158,     9,    10,     0,     0,     0,     0,     0,
       0,   416,   417,     0,    16,    17,    18,   495,    20,    21,
      22,   496,    24,   497,   498,  1151,   500,   418,    30,   501,
      32,    33,    34,     0,    35,    36,    37,    38,   502,    40,
      41,    42,    43,    44,    45,    46,   503,     0,    48,   504,
      50,   505,   506,    53,   507,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,   508,
     509,    71,     0,    72,    73,    74,   510,     0,     0,    77,
      78,    79,     0,     0,   511,    81,     0,     0,     0,     0,
      83,   512,    85,   513,   514,    88,    89,  1649,     0,     0,
       0,     0,     0,     0,     0,    94,    95,    96,    97,     0,
      98,     0,     0,     0,   515,   100,   101,   516,   517,     0,
       0,     0,     0,     0,     0,   104,   105,   106,     0,   108,
     109,  1152,     0,     0,     0,  1153,     0,     0,   116,   518,
       0,     0,     0,   118,   119,   120,   121,   519,   123,   124,
     520,     0,     0,     0,     0,     0,     0,     0,   521,   522,
     131,     0,     0,     0,   132,     0,   133,   523,     0,     0,
       0,     0,     0,     0,   138,     0,   139,   140,   141,   142,
     524,   144,   145,   146,   147,   148,   149,     0,     0,  1154,
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
       3,     0,   248,   535,   250,  1155,  1156,  1157,  1158,     9,
      10,     0,     0,     0,     0,     0,     0,   416,   417,     0,
      16,    17,    18,   495,    20,    21,    22,   496,    24,   497,
     498,  1151,   500,   418,    30,   501,    32,    33,    34,     0,
      35,    36,    37,    38,   502,    40,    41,    42,    43,    44,
      45,    46,   503,     0,    48,   504,    50,   505,   506,    53,
     507,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,   508,   509,    71,     0,    72,
      73,    74,   510,     0,     0,    77,    78,    79,     0,     0,
     511,    81,     0,     0,     0,     0,    83,   512,    85,   513,
     514,    88,    89,     0,     0,     0,     0,     0,     0,     0,
       0,    94,    95,    96,    97,     0,    98,     0,     0,     0,
     515,   100,   101,   516,   517,     0,     0,     0,     0,     0,
       0,   104,   105,   106,     0,   108,   109,  1152,     0,     0,
       0,  1153,     0,     0,   116,   518,     0,     0,     0,   118,
     119,   120,   121,   519,   123,   124,   520,     0,     0,     0,
       0,     0,     0,     0,   521,   522,   131,     0,     0,     0,
     132,     0,   133,   523,     0,     0,     0,     0,     0,     0,
     138,     0,   139,   140,   141,   142,   524,   144,   145,   146,
     147,   148,   149,     0,     0,  1154,   151,     0,     0,   419,
     154,   155,   156,   157,   158,   159,   160,   161,   525,   163,
     526,   165,   527,   528,   168,   169,   170,   171,   172,   173,
     529,   175,   530,   531,   532,   179,   180,   533,   534,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,     0,   196,   197,   198,     0,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,     0,     0,     3,     0,   248,   535,
     250,  1155,  1156,  1157,  1158,     9,    10,     0,     0,     0,
       0,     0,     0,   416,   417,     0,    16,    17,    18,   495,
      20,    21,    22,   496,    24,   497,   498,  1151,   500,   418,
      30,   501,    32,    33,    34,     0,    35,    36,    37,    38,
     502,    40,    41,    42,    43,    44,    45,    46,   503,     0,
      48,   504,    50,   505,   506,    53,   507,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,   508,   509,    71,     0,    72,    73,    74,   510,     0,
       0,    77,    78,    79,     0,     0,   511,    81,     0,     0,
       0,     0,    83,   512,    85,   513,   514,    88,    89,     0,
       0,     0,     0,     0,     0,     0,     0,    94,    95,    96,
      97,     0,    98,     0,     0,     0,   515,   100,   101,   516,
     517,     0,     0,     0,     0,     0,     0,   104,   105,   106,
       0,   108,   109,  1152,     0,     0,     0,  1153,     0,     0,
     116,   518,     0,     0,     0,   118,   119,   120,   121,   519,
     123,   124,   520,     0,     0,     0,     0,     0,     0,     0,
     521,   522,   131,     0,     0,     0,   132,     0,   133,   523,
       0,     0,     0,     0,     0,     0,   138,     0,   139,   140,
     141,   142,   524,   144,   145,   146,   147,   148,   149,     0,
       0,   150,   151,     0,     0,   419,   154,   155,   156,   157,
     158,   159,   160,   161,   525,   163,   526,   165,   527,   528,
     168,   169,   170,   171,   172,   173,   529,   175,   530,   531,
     532,   179,   180,   533,   534,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,     0,   196,
     197,   198,     0,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
       0,     0,     3,     0,   248,   535,   250,  1155,  1156,  1157,
    1158,     9,    10,     0,     0,     0,     0,     0,     0,   416,
     417,     0,    16,    17,    18,   543,    20,    21,    22,   496,
     544,   545,   498,   499,   500,   418,    30,   501,    32,   546,
      34,     0,    35,    36,    37,    38,   547,    40,   548,   549,
      43,    44,    45,    46,   503,     0,    48,   550,    50,   505,
     506,    53,   507,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,   508,   509,    71,
       0,    72,    73,    74,   551,     0,     0,    77,    78,    79,
       0,     0,   511,    81,     0,     0,     0,     0,    83,   512,
      85,   513,   514,    88,    89,  1246,     0,     0,     0,     0,
       0,     0,     0,    94,    95,    96,    97,     0,    98,     0,
       0,     0,   515,   100,   101,   516,   517,     0,     0,     0,
       0,     0,     0,   104,   105,   106,     0,   108,   109,   110,
       0,     0,     0,     0,     0,     0,   116,   518,     0,     0,
       0,   118,   119,   120,   121,   519,   123,   124,   520,     0,
       0,     0,     0,     0,     0,     0,   521,   522,   131,     0,
       0,     0,   132,     0,   133,   523,     0,     0,     0,     0,
       0,     0,   138,     0,   139,   140,   141,   142,   524,   144,
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
      18,   543,    20,    21,    22,   496,   544,   545,   498,   499,
     500,   418,    30,   501,    32,   546,    34,     0,    35,    36,
      37,    38,   547,    40,   548,   549,    43,    44,    45,    46,
     503,     0,    48,   550,    50,   505,   506,    53,   507,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,   508,   509,    71,     0,    72,    73,    74,
     551,     0,     0,    77,    78,    79,     0,     0,   511,    81,
       0,     0,     0,     0,    83,   512,    85,   513,   514,    88,
      89,     0,     0,     0,     0,     0,     0,     0,     0,    94,
      95,    96,    97,     0,    98,     0,     0,     0,   515,   100,
     101,   516,   517,     0,     0,     0,     0,     0,     0,   104,
     105,   106,     0,   108,   109,   110,     0,     0,     0,     0,
       0,     0,   116,   518,     0,     0,     0,   118,   119,   120,
     121,   519,   123,   124,   520,     0,     0,     0,     0,     0,
       0,     0,   521,   522,   131,     0,     0,     0,   132,     0,
     133,   523,     0,     0,     0,     0,     0,     0,   138,     0,
     139,   140,   141,   142,   524,   144,   145,   146,   147,   148,
     149,     0,     0,   150,   151,     0,     0,   419,   154,   155,
     156,   157,   158,   159,   160,   161,   525,   552,   526,   165,
     527,   528,   168,   169,   170,   171,   172,   173,   529,   175,
     530,   531,   532,   179,   180,   533,   534,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
       0,   196,   197,   198,     0,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,     0,     0,     0,     0,   248,   535,   250,   251,
     252,   253,   254,     5,     6,     7,     8,     9,    10,     0,
       0,     0,    13,     0,     0,   416,   417,     0,    16,    17,
      18,   845,    20,    21,    22,    23,     0,   846,   498,    27,
       0,   418,    30,   501,    32,     0,    34,     0,    35,    36,
      37,    38,   847,    40,     0,     0,    43,    44,    45,    46,
     503,     0,    48,   848,    50,     0,     0,    53,   507,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,   508,   509,    71,     0,    72,    73,    74,
     849,     0,     0,    77,    78,    79,     0,     0,   511,    81,
       0,     0,     0,    82,    83,   512,    85,   513,   514,    88,
      89,   565,    91,     0,     0,     0,     0,    93,     0,    94,
      95,    96,    97,     0,    98,     0,     0,     0,   515,   100,
     101,   516,   517,     0,     0,     0,     0,     0,     0,   104,
     105,   106,   107,   108,   109,     0,   566,   112,     0,   113,
     114,     0,   116,   117,     0,     0,     0,   118,   119,   120,
     121,   122,   123,   124,   520,     0,   126,     0,     0,     0,
       0,     0,   521,   522,   131,     0,     0,     0,   132,     0,
     133,   523,     0,     0,     0,     0,     0,     0,   138,     0,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,     0,     0,     0,   151,   152,     0,   419,   154,   155,
     156,   157,   158,   159,   160,   161,   525,     0,   526,   165,
     527,   528,   168,   169,   170,   171,   172,   173,   529,   175,
     530,   531,   532,   179,   180,     0,   534,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
       0,   196,   197,   198,     0,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,     0,   247,     0,   248,   535,   250,   251,
     252,   253,   254,     9,    10,     0,     0,     0,     0,     0,
       0,   416,   417,     0,    16,    17,    18,     0,    20,    21,
      22,   496,     0,     0,   498,   499,     0,   418,    30,   501,
      32,     0,    34,     0,    35,    36,    37,    38,     0,    40,
       0,     0,    43,    44,    45,    46,   503,     0,    48,     0,
      50,     0,     0,    53,   507,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,   508,
     509,    71,     0,    72,    73,    74,     0,     0,     0,    77,
      78,    79,     0,     0,   511,    81,     0,     0,     0,     0,
      83,   512,    85,   513,   514,    88,    89,     0,     0,     0,
       0,     0,     0,     0,     0,    94,    95,    96,    97,     0,
      98,     0,     0,     0,   515,   100,   101,   516,   517,     0,
       0,     0,     0,     0,     0,   104,   105,   106,     0,   108,
     109,     0,     0,     0,     0,     0,     0,     0,   116,   518,
       0,     0,     0,   118,   119,   120,   121,   519,   123,   124,
     520,     0,     0,     0,     0,     0,     0,     0,   521,   522,
     131,     0,     0,     0,   132,     0,   133,   523,     0,     0,
       0,     0,     0,     0,   138,     0,   139,   140,   141,   142,
     524,   144,   145,   146,   147,   148,   149,     0,     0,     0,
     151,     0,     0,   419,   154,   155,   156,   157,   158,   159,
     160,   161,   525,     0,   526,   165,   527,   528,   168,   169,
     170,   171,   172,   173,   529,   175,   530,   531,   532,   179,
     180,     0,   534,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,     0,   196,   197,   198,
       0,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,     0,     0,
       0,     0,   248,   535,   250,   251,   252,   253,   254
  };

  /* YYCHECK.  */
  const short int
  xquery_parser::yycheck_[] =
  {
         0,     5,     6,     7,   182,     5,     6,     7,     8,   112,
     113,    14,   692,     5,     6,     7,     8,   314,   343,   427,
     428,   832,   262,     0,   768,   916,   676,   788,     5,     6,
       7,     8,   429,  1047,   929,   930,   677,   678,   679,   680,
     801,   870,   136,   263,  1063,  1299,     5,     6,     7,     8,
     626,   627,   592,   768,   815,  1316,  1087,   597,   278,     1,
     294,   954,   929,   930,   624,   625,   626,   627,  1380,  1381,
     255,   256,   469,   470,    76,  1004,     1,    39,  1506,   624,
     625,  1509,    44,    45,  1137,   725,  1022,  1329,  1413,    36,
      56,    53,    36,    27,    28,     9,    10,     8,    60,   119,
      62,    63,    30,   970,     1,     9,    10,    27,    28,    71,
     122,   111,     1,    47,    30,    45,     1,     1,     1,   111,
       1,   285,     1,    57,   108,   225,     1,    47,   225,  1024,
     227,    30,     1,    63,   111,     1,    98,  1004,     1,  1609,
     108,    75,  1037,   246,   247,   108,    80,   101,    95,  1676,
      97,     1,   111,    97,    94,    75,   655,  1024,   657,   658,
     132,   660,   970,   662,     1,   143,   108,    25,   154,   108,
    1037,   670,   671,   154,   169,    31,    34,   148,   112,   113,
     114,   119,    55,   108,    57,     1,   114,    96,   422,   217,
     104,   294,   426,   113,    95,   111,   154,   138,   107,   157,
     104,   148,   143,    61,   148,   225,   107,   202,   117,   125,
     124,   225,   126,     1,   314,   976,   230,   314,   190,   128,
     124,   233,   126,  1750,   210,   188,   254,   108,   101,   210,
       0,     1,   186,   161,   150,     1,    97,  1549,   154,   108,
     154,   157,   108,   183,   158,   108,  1137,  1138,   187,   233,
     154,   217,   346,     1,   158,   255,   256,   187,   108,   259,
     174,   177,   161,   225,   175,  1519,     1,   235,  1282,  1030,
     174,   108,  1083,     1,   571,  1036,     1,  1296,   255,   256,
    1522,   195,   259,  1608,   448,  1029,  1153,   307,   254,  1320,
    1760,   195,   108,   190,   294,   273,  1189,  1725,  1329,   213,
     314,   190,   273,   879,   880,   190,   190,   190,  1237,   213,
    1246,   190,  1027,    76,  1029,   190,   956,   294,   187,   422,
     108,   187,     1,   426,   187,   559,   273,    90,     1,   273,
       0,     1,   877,   878,  1049,   273,  1389,   187,   108,   736,
     148,     1,   108,   259,  1772,  1153,  1774,     1,   108,   351,
     187,   114,   354,   287,   457,   317,   318,   319,   214,   101,
     108,   295,     1,   126,   467,   128,   119,   287,   184,   303,
    1237,   313,     1,   108,   477,   295,   119,     1,   251,  1274,
     108,   484,   485,   108,   624,   625,   311,   108,   108,   786,
     493,   264,     1,   266,   108,   256,   257,  1709,    45,   187,
      47,   621,   622,   101,   277,   278,   279,  1274,   281,   643,
     283,   631,    95,   912,   184,     1,    37,    38,   119,    40,
      41,   187,   422,   131,   154,     1,   426,   161,   613,   108,
     190,  1298,    77,    80,   187,   108,     1,    58,   108,   187,
     225,   159,   227,   186,   186,   422,   108,   177,   108,   426,
       1,  1763,   187,   453,   108,   455,   559,   186,   176,   187,
     107,   453,   187,   455,   184,   273,   187,    27,    28,   108,
     108,    97,   575,   576,   188,  1236,   453,   108,   455,   108,
     137,   210,   482,   586,   108,   186,  1747,   487,   186,   197,
     482,  1522,   108,   114,   453,   487,   455,    97,  1389,   108,
     108,    97,   605,   606,  1248,   482,   185,  1398,   916,   154,
     487,   155,   185,   157,   184,     9,    10,   131,  1409,    97,
     157,   168,   108,   482,   184,   187,  1421,    52,   487,   314,
     184,   157,   108,  1362,    95,   218,   219,  1366,  1792,   108,
     161,   949,  1257,   108,   201,   184,  1122,  1123,  1124,   187,
     233,   269,  1232,   113,  1421,   184,   187,   108,   276,   559,
     184,    95,  1122,  1123,  1124,   108,   566,  1107,   286,   169,
     148,   187,   108,   169,   566,   184,   221,   222,    95,   187,
     977,   978,   559,   197,    45,   982,    47,   148,   351,   566,
     693,   354,   154,   237,   108,   698,     9,    10,   184,   220,
     967,   704,   696,   697,   138,   130,   606,   566,   184,   143,
     104,   159,   979,   613,   606,  1012,   619,  1631,   187,   184,
      95,    95,   157,  1384,   624,   625,   626,   627,   176,   606,
     124,   148,   126,   184,   868,    95,   613,   877,     9,  1506,
     261,     5,  1509,   643,   187,     9,   107,   624,   625,   626,
     627,   187,   252,   253,    97,   255,   252,   253,    29,   255,
     154,   895,   262,   883,   158,   157,   643,   887,    97,   143,
     433,   434,   272,   187,   437,     5,   272,   107,   441,     9,
     174,   444,   445,   143,   284,   114,    30,  1578,   284,   452,
       9,   104,    95,   101,   157,   458,   459,    54,   128,   101,
     463,   195,    59,     1,   118,   148,   114,   168,   471,  1520,
      29,   124,   114,   126,  1525,   478,   479,   480,   481,   213,
     823,   824,   825,   486,   827,     1,  1470,  1746,    42,  1137,
    1138,   494,    46,   147,   138,    33,    95,    51,    42,   143,
      97,   154,    46,   218,   219,   158,   160,    51,   107,  1644,
    1400,    49,   155,   124,   157,   126,    70,    33,   233,    42,
     124,   174,   126,    46,   135,   868,    70,   111,    51,   154,
     134,    97,   101,   157,   778,  1455,   539,  1644,   778,   157,
     194,   125,   195,   154,   143,   114,   778,    70,   114,    30,
     154,   554,   177,  1369,   124,    97,   126,  1692,    54,  1694,
     213,   778,   565,    59,   134,   124,   150,   126,   157,   809,
     810,   145,   114,   269,  1139,   123,   135,   809,   810,   778,
     276,     1,    78,     3,   154,  1692,   159,  1694,   119,   592,
     286,   157,   809,   810,   597,   154,   628,    90,   601,   159,
     632,    97,   176,   176,  1655,   186,   154,   186,  1659,   157,
     809,   810,  1737,  1738,   168,   157,   176,   171,  1725,   186,
     194,   114,  1757,   119,   168,   186,   199,   171,   868,   210,
     111,   210,   186,   126,  1018,   128,  1020,   186,  1112,   199,
    1277,    33,   186,   210,   125,   168,   889,    67,   171,   210,
    1757,   868,    72,  1113,  1779,   895,   182,    49,   212,  1119,
    1785,   210,   101,   186,   101,  1772,   166,  1774,   212,   150,
     196,   247,   248,   154,   101,   114,   157,   114,   895,  1569,
    1570,  1562,   182,   157,   133,   149,  1070,   114,  1072,   212,
    1741,  1611,   141,   142,   270,   144,   177,   149,  1116,   119,
     138,   165,   138,   152,   146,   137,   182,   156,  1709,   158,
     263,   263,    54,   165,   163,   157,   154,    59,   154,   151,
     196,   274,   274,   201,   299,   123,   729,   268,   699,   732,
     179,   702,   210,   308,   275,   706,   155,   154,   157,  1376,
     157,  1389,   154,   746,   157,   157,   154,   750,   751,   157,
    1398,   221,   222,   223,   203,   204,   205,   206,   207,   208,
     157,  1409,   277,   278,   279,   191,   192,   350,   283,   772,
     353,   774,   232,   232,   234,   234,   129,   130,   123,   782,
     129,   130,   785,   674,   675,   123,   789,   119,   681,   682,
    1680,  1681,   123,  1136,  1714,   683,   684,  1230,  1231,   123,
    1599,  1600,  1276,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,   119,   123,   123,    27,    28,   154,   154,
     123,   123,   123,   123,  1361,  1065,    37,    38,   831,    40,
      41,   154,   216,  1065,   119,   157,    47,   241,   241,   157,
     242,  1761,   154,   314,     0,    93,    57,    58,  1065,   190,
    1487,   167,    50,   249,   100,   102,   200,   155,   103,   193,
     157,    30,    47,  1753,    75,   184,  1065,   870,   119,    80,
     184,   184,  1112,   184,   153,   246,   304,   187,  1121,   284,
     119,   154,  1122,  1123,  1124,   284,     1,   119,   143,   108,
     154,   187,   187,   154,   157,  1112,   899,   157,   157,   157,
     157,   112,   113,   114,   184,  1122,  1123,  1124,   143,   122,
     154,    35,    17,  1833,   157,  1835,  1553,   157,    30,   157,
     214,   190,   190,     3,   231,  1845,   929,   930,   931,   932,
    1578,   230,   119,   170,   168,    71,    95,   170,   231,    30,
    1358,   434,    95,    95,   437,   187,   150,   108,   441,   161,
     161,   444,   445,   245,   108,   161,   128,   133,   246,   452,
      95,   143,   299,   133,   119,   458,   459,   970,   184,   184,
     463,   108,    95,   187,    45,    97,    97,   187,   471,   187,
     187,   984,   187,   184,   187,   478,   479,   480,   481,   154,
     184,   154,   154,   486,   154,    95,  1240,   154,   225,   143,
    1240,   494,   231,   154,   190,   233,  1009,   237,  1240,   220,
      33,   119,   170,   133,   143,  1018,    95,  1020,    30,  1022,
     286,  1024,    95,  1240,   299,  1499,   154,   227,   254,   128,
     119,   148,   119,    95,  1037,   184,  1276,   133,   133,    97,
     154,  1240,   161,  1287,   119,   148,   539,  1287,   198,   101,
     261,   101,   184,   184,   122,  1287,   154,   143,    35,  1276,
     190,   554,  1306,    30,   154,   119,  1306,  1070,  1542,  1072,
    1287,   245,   565,    80,  1306,   108,   287,   108,   258,   260,
     157,   157,   145,   285,   295,   157,  1326,   157,  1287,  1306,
     267,   157,   303,  1333,  1326,    30,   157,   157,   286,    30,
      30,  1333,   227,   287,  1107,   190,   187,  1306,   601,  1326,
     306,   145,   148,   187,   128,   119,  1333,   119,   187,   148,
     187,   148,    78,   108,   143,  1365,   101,  1326,   184,  1132,
     187,     7,   187,  1365,  1333,   133,   233,   190,    97,   198,
     233,   233,   111,   237,   186,   233,   157,   157,  1365,   157,
    1153,   154,   107,   148,    79,  1629,   282,   187,    30,   286,
      30,   187,   187,   187,   271,   187,  1640,  1641,   250,  1643,
     187,   187,   250,   170,   187,   108,   148,  1651,   184,   127,
     148,   127,    97,   184,   154,   143,   186,   186,    95,    30,
     186,   184,   257,   184,   184,   184,  1539,  1540,  1541,   187,
     316,    97,    54,   187,   287,   170,   148,    95,   107,    95,
     197,    30,    95,   108,   265,   108,   280,   119,   119,   197,
     225,    95,   186,   197,   186,   198,    94,   119,   119,   183,
     119,   225,   119,   186,   197,  1192,   735,   428,   199,   732,
     287,   259,   225,  1246,   259,   293,   971,  1250,  1038,   448,
    1237,  1714,  1761,   746,   871,  1035,   305,   750,   751,  1499,
    1734,   305,  1265,   306,   305,  1480,   306,   306,   463,   791,
     262,  1274,  1266,  1385,  1288,  1128,  1383,   554,  1380,   772,
    1293,   774,  1499,  1301,  1296,  1288,   653,   673,   654,   782,
    1320,   932,   785,   338,   709,  1298,   789,   832,  1785,  1773,
    1779,  1020,  1542,  1352,  1363,  1191,  1398,  1362,   456,   456,
    1409,  1578,  1575,  1138,  1402,  1147,  1003,  1791,  1214,  1445,
    1602,  1399,    -1,   595,  1327,  1542,    -1,    -1,    -1,  1672,
      -1,    -1,  1806,    -1,    -1,    -1,    -1,    -1,   831,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1690,    -1,  1352,
      -1,    -1,    -1,  1827,    -1,    -1,    -1,    -1,    -1,  1362,
      -1,    -1,  1836,  1366,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1629,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1640,  1641,    -1,  1643,    -1,    -1,   899,    -1,    -1,    -1,
      -1,  1651,  1629,    -1,    -1,    -1,    -1,    -1,  1421,    -1,
      -1,    -1,    -1,  1640,  1641,    -1,  1643,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1651,    -1,   929,   930,   931,   932,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1451,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1477,  1478,    -1,   970,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   984,    -1,    -1,  1734,    -1,    -1,    -1,    -1,    -1,
    1503,    -1,    -1,  1506,    -1,    -1,  1509,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1009,  1734,  1521,    -1,
      -1,    -1,    -1,  1526,    -1,  1018,    -1,  1020,    -1,  1022,
      -1,  1024,    -1,  1773,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1037,    -1,    -1,    -1,    -1,    -1,
      -1,  1791,    -1,    -1,    -1,    -1,  1773,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1806,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1791,    -1,    -1,  1070,    -1,  1072,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1827,    -1,  1806,
      -1,    -1,    -1,    -1,    -1,    -1,  1836,   566,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1827,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1836,
      -1,   590,   591,    -1,   593,   594,   595,   596,    -1,   598,
      -1,    -1,    -1,    -1,    -1,   604,    -1,    -1,    -1,  1132,
      -1,  1644,  1645,   612,  1647,    -1,  1649,    -1,    -1,    -1,
      -1,    -1,    -1,  1656,    -1,    -1,    -1,    -1,    -1,    -1,
    1153,    -1,    -1,    -1,    -1,   634,   635,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   643,   644,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1692,
      -1,  1694,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1710,    -1,    -1,
    1713,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1725,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1736,    -1,    -1,   705,    -1,    -1,    -1,
     709,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1246,  1757,    -1,    -1,  1250,    -1,    -1,
      -1,    -1,  1765,    -1,    -1,    -1,    -1,  1770,    -1,  1772,
      -1,  1774,  1265,    -1,    -1,    -1,    -1,    -1,    -1,   748,
      -1,  1274,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1288,    -1,    -1,    -1,    -1,
    1803,    -1,    -1,    -1,    -1,  1298,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1823,   790,    -1,    -1,    -1,  1828,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1327,    -1,    -1,  1840,    -1,    -1,
    1843,    -1,    -1,    -1,    -1,    -1,    -1,   816,    -1,    -1,
      -1,   820,   821,    -1,    -1,    -1,    -1,    -1,    -1,  1352,
     829,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   895,    -1,  1421,    -1,
      -1,    -1,   901,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1451,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1477,  1478,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   972,    -1,    -1,    -1,    -1,    -1,    -1,
    1503,    -1,    -1,  1506,    -1,    -1,  1509,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1521,    -1,
      -1,    -1,    -1,  1526,    -1,    -1,    -1,    -1,  1007,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1026,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1048,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1059,  1060,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1074,    -1,    -1,  1077,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1094,  1095,  1096,    -1,  1098,
    1099,  1100,  1101,  1102,  1103,  1104,  1105,  1106,    -1,    -1,
    1109,  1110,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1118,
      -1,  1644,  1645,    -1,  1647,    -1,  1649,    -1,    -1,  1128,
      -1,    -1,    -1,  1656,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1692,
      -1,  1694,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1179,    -1,    -1,    -1,    -1,    -1,    -1,  1710,    -1,    -1,
    1713,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1725,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1736,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1757,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1765,    -1,    -1,    -1,    -1,  1770,    -1,  1772,
      -1,  1774,    -1,  1252,    -1,  1254,    -1,  1256,    -1,    -1,
    1259,    -1,    -1,    -1,    -1,  1264,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1276,    -1,    -1,
    1803,    -1,    -1,    -1,    -1,    -1,  1285,    -1,    -1,    -1,
      -1,    -1,  1291,  1292,    -1,    -1,    -1,    -1,    -1,    -1,
    1823,    -1,    -1,    -1,    -1,  1828,    -1,    -1,    -1,    -1,
      -1,  1310,    -1,    -1,  1313,    -1,    -1,  1840,    -1,    -1,
    1843,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1383,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1464,    -1,    -1,    -1,  1468,
      -1,    -1,    -1,  1472,    -1,  1474,    -1,  1476,    -1,    -1,
      -1,    -1,    -1,  1482,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1490,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1498,
    1499,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1518,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1530,  1531,  1532,  1533,    -1,  1535,  1536,    -1,  1538,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1554,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1617,    -1,
    1619,    -1,    -1,  1622,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1630,    -1,    -1,    -1,    -1,  1635,  1636,    -1,    -1,
      -1,    -1,    -1,    -1,  1643,    -1,    -1,    -1,    -1,  1648,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1665,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1677,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1717,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1730,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1773,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1801,    -1,    -1,    -1,    -1,  1806,    -1,    -1,
      -1,    -1,  1811,     0,     1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    11,    12,    -1,  1826,    -1,    16,
      -1,  1830,    -1,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    -1,    30,    -1,    -1,    33,    34,    -1,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    -1,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    -1,    95,    96,
      97,    98,    99,    -1,   101,   102,   103,    -1,    -1,   106,
     107,    -1,    -1,    -1,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,    -1,    -1,    -1,   125,    -1,
     127,   128,   129,   130,    -1,   132,    -1,    -1,    -1,   136,
     137,   138,   139,   140,    -1,    -1,    -1,    -1,    -1,    -1,
     147,   148,   149,   150,   151,   152,   153,   154,   155,    -1,
     157,   158,   159,   160,   161,    -1,    -1,    -1,   165,   166,
     167,   168,   169,   170,   171,   172,    -1,   174,    -1,   176,
     177,    -1,    -1,   180,   181,   182,    -1,    -1,    -1,   186,
      -1,   188,   189,    -1,   191,   192,    -1,   194,    -1,   196,
      -1,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,    -1,    -1,   211,   212,   213,    -1,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,    -1,   259,   260,   261,    -1,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,   309,   310,    -1,   312,    -1,   314,   315,   316,
     317,   318,   319,   320,     0,     1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    11,    12,    -1,    -1,    -1,
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
     306,   307,   308,   309,   310,     1,   312,    -1,   314,   315,
     316,   317,   318,   319,   320,    11,    12,    -1,    -1,    -1,
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
     306,   307,   308,   309,   310,     1,   312,    -1,   314,   315,
     316,   317,   318,   319,   320,    11,    12,    -1,    -1,    -1,
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
     316,   317,   318,   319,   320,     0,     1,    -1,     3,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,    -1,    -1,
      -1,    46,    -1,    -1,    -1,    50,    51,    -1,    -1,    -1,
      -1,    56,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    67,    -1,    -1,    70,    -1,    72,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    93,    -1,
      95,    96,    97,    -1,    -1,   100,   101,   102,   103,    -1,
      -1,    -1,   107,   108,    -1,    -1,    -1,    -1,    -1,   114,
      -1,    -1,   117,   118,   119,    -1,    -1,   122,    -1,    -1,
      -1,    -1,   127,   128,    -1,    -1,    -1,    -1,   133,    -1,
      -1,    -1,   137,    -1,    -1,    -1,   141,   142,    -1,   144,
      -1,   146,   147,    -1,    -1,    -1,   151,   152,    -1,    -1,
     155,   156,   157,   158,   159,   160,    -1,    -1,   163,    -1,
      -1,    -1,   167,   168,    -1,    -1,   171,    -1,    -1,    -1,
      -1,   176,    -1,    -1,   179,    -1,    -1,    -1,    -1,   184,
     185,   186,   187,   188,    -1,   190,   191,   192,   193,   194,
      -1,    -1,    -1,    -1,   199,   200,   201,    -1,   203,   204,
     205,   206,   207,   208,    -1,   210,    -1,   212,    -1,    -1,
      -1,    -1,   217,   218,   219,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   233,    -1,
     235,    -1,   237,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   249,    -1,    -1,    -1,    -1,   254,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    11,    12,
      -1,    -1,    -1,    16,    -1,    -1,    -1,    20,    21,    22,
      23,    24,    25,    26,    27,    28,   311,    30,   313,    -1,
      33,    34,    -1,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    -1,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    -1,    95,    96,    97,    98,    99,    -1,   101,   102,
     103,    -1,    -1,   106,   107,    -1,    -1,    -1,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,    -1,
      -1,    -1,   125,    -1,   127,   128,   129,   130,    -1,   132,
      -1,    -1,    -1,   136,   137,   138,   139,   140,    -1,    -1,
      -1,    -1,    -1,    -1,   147,   148,   149,   150,   151,   152,
     153,   154,   155,    -1,   157,   158,   159,   160,   161,    -1,
      -1,    -1,   165,   166,   167,   168,   169,   170,   171,   172,
      -1,   174,    -1,   176,   177,    -1,    -1,   180,   181,   182,
      -1,    -1,    -1,   186,    -1,   188,   189,    -1,   191,   192,
      -1,   194,    -1,   196,    -1,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,    -1,    -1,   211,   212,
     213,    -1,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,    -1,   259,   260,   261,    -1,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,    -1,   312,
      -1,   314,   315,   316,   317,   318,   319,   320,   321,   322,
      11,    12,    -1,    -1,    -1,    16,    -1,    -1,    -1,    20,
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
     121,    -1,    -1,    -1,   125,    -1,   127,   128,   129,   130,
      -1,   132,    -1,    -1,    -1,   136,   137,   138,   139,   140,
      -1,    -1,    -1,    -1,    -1,    -1,   147,   148,   149,   150,
     151,   152,   153,   154,   155,    -1,   157,   158,   159,   160,
     161,    -1,    -1,    -1,   165,   166,   167,   168,   169,   170,
     171,   172,    -1,   174,    -1,   176,   177,    -1,    -1,   180,
     181,   182,    -1,    -1,    -1,   186,    -1,   188,   189,    -1,
     191,   192,    -1,   194,    -1,   196,    -1,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,    -1,    -1,
     211,   212,   213,    -1,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,    -1,   259,   260,
     261,    -1,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,   309,   310,
      -1,   312,    -1,   314,   315,   316,   317,   318,   319,   320,
      -1,   322,    11,    12,    -1,    -1,    -1,    16,    -1,    -1,
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
      -1,   180,   181,   182,    -1,   184,    -1,   186,    -1,   188,
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
      -1,   180,   181,   182,    -1,   184,    -1,   186,    -1,   188,
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
      -1,   180,   181,   182,    -1,   184,    -1,   186,    -1,   188,
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
     309,   310,    -1,   312,    -1,   314,   315,   316,   317,   318,
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
     309,   310,    -1,   312,    -1,   314,   315,   316,   317,   318,
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
     309,   310,    -1,   312,    -1,   314,   315,   316,   317,   318,
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
     309,   310,    -1,   312,    -1,   314,   315,   316,   317,   318,
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
     309,   310,    -1,   312,    -1,   314,   315,   316,   317,   318,
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
     139,   140,    -1,    -1,    -1,    -1,   145,    -1,   147,   148,
     149,   150,   151,   152,   153,   154,   155,    -1,   157,   158,
     159,   160,   161,    -1,    -1,    -1,   165,   166,   167,   168,
     169,   170,   171,   172,    -1,   174,    -1,   176,   177,    -1,
      -1,   180,   181,   182,    -1,    -1,    -1,   186,   187,   188,
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
     139,   140,    -1,    -1,    -1,    -1,   145,    -1,   147,   148,
     149,   150,   151,   152,   153,   154,   155,    -1,   157,   158,
     159,   160,   161,    -1,    -1,    -1,   165,   166,   167,   168,
     169,   170,   171,   172,    -1,   174,    -1,   176,   177,    -1,
      -1,   180,   181,   182,    -1,    -1,    -1,   186,   187,   188,
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
     309,   310,    -1,   312,    -1,   314,   315,   316,   317,   318,
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
      -1,   180,   181,   182,    -1,    -1,   185,   186,    -1,   188,
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
      -1,   180,   181,   182,    -1,    -1,    -1,   186,   187,   188,
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
     309,   310,   311,   312,    -1,   314,   315,   316,   317,   318,
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
     309,   310,    -1,   312,   313,   314,   315,   316,   317,   318,
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
      -1,   180,   181,   182,    -1,   184,    -1,   186,    -1,   188,
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
      -1,   180,   181,   182,    -1,    -1,   185,   186,    -1,   188,
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
     139,   140,    -1,    -1,    -1,    -1,   145,    -1,   147,   148,
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
      -1,   160,   161,    -1,    -1,    -1,   165,   166,   167,   168,
     169,   170,   171,   172,    -1,   174,    -1,    -1,    -1,    -1,
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
      -1,   160,   161,    -1,    -1,    -1,   165,   166,   167,   168,
     169,   170,   171,   172,    -1,   174,    -1,    -1,    -1,    -1,
      -1,   180,   181,   182,    -1,    -1,    -1,   186,    -1,   188,
     189,    -1,    -1,    -1,    -1,   194,    -1,   196,    -1,   198,
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
     129,   130,    -1,   132,    -1,    -1,    -1,   136,    -1,   138,
     139,   140,    -1,    -1,    -1,    -1,    -1,    -1,   147,   148,
     149,   150,    -1,   152,   153,   154,   155,    -1,   157,   158,
      -1,   160,   161,    -1,    -1,    -1,   165,   166,   167,   168,
     169,   170,   171,   172,    -1,   174,    -1,    -1,    -1,    -1,
      -1,   180,   181,   182,    -1,    -1,    -1,   186,    -1,   188,
     189,    -1,    -1,    -1,    -1,   194,    -1,   196,    -1,   198,
      -1,   200,    -1,   202,   203,   204,   205,   206,   207,   208,
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
     319,   320,    11,    12,    -1,    -1,    -1,    16,    -1,    -1,
      -1,    20,    -1,    -1,    -1,    -1,    25,    26,    -1,    -1,
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
     149,    -1,   151,   152,   153,    -1,    -1,    -1,    -1,    -1,
      -1,   160,   161,    -1,    -1,    -1,   165,   166,   167,   168,
     169,   170,   171,   172,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   180,   181,   182,    -1,    -1,    -1,   186,    -1,   188,
     189,    -1,    -1,    -1,    -1,   194,    -1,   196,    -1,   198,
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
     309,    -1,    -1,    -1,    -1,   314,   315,   316,   317,   318,
     319,   320,    11,    12,    -1,    -1,    -1,    16,    -1,    -1,
      -1,    20,    -1,    -1,    -1,    -1,    25,    26,    -1,    -1,
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
     149,    -1,   151,   152,   153,    -1,    -1,    -1,    -1,    -1,
      -1,   160,   161,    -1,    -1,    -1,   165,   166,   167,   168,
     169,   170,   171,   172,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   180,   181,   182,    -1,    -1,    -1,   186,    -1,   188,
     189,    -1,    -1,    -1,    -1,   194,    -1,   196,    -1,   198,
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
     303,   304,   305,   306,   307,   308,   309,    -1,    -1,    -1,
      -1,   314,   315,   316,   317,   318,   319,   320,    16,    -1,
      18,    19,    -1,    -1,    -1,    -1,    -1,    25,    26,    -1,
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
     148,   149,    -1,   151,   152,   153,    -1,    -1,    -1,    -1,
      -1,    -1,   160,   161,    -1,    -1,    -1,   165,   166,   167,
     168,   169,   170,   171,   172,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   180,   181,   182,    -1,    -1,    -1,   186,    -1,
     188,   189,    -1,    -1,    -1,    -1,    -1,    -1,   196,    -1,
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
     308,   309,    -1,    -1,    16,    -1,   314,   315,   316,   317,
     318,   319,   320,    25,    26,    -1,    -1,    -1,    -1,    -1,
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
     182,    -1,    -1,    -1,   186,   187,   188,   189,    -1,    -1,
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
      26,    -1,    -1,    -1,    30,    -1,    -1,    33,    34,    -1,
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
      -1,    -1,    -1,    -1,   160,   161,    -1,    -1,    -1,   165,
     166,   167,   168,   169,   170,   171,   172,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   180,   181,   182,    -1,    -1,    -1,
     186,   187,   188,   189,    -1,    -1,    -1,    -1,    -1,    -1,
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
     306,   307,   308,   309,    -1,    -1,    16,    -1,   314,   315,
     316,   317,   318,   319,   320,    25,    26,    -1,    -1,    -1,
      -1,    -1,    -1,    33,    34,    -1,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    -1,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    -1,    95,    96,    97,    98,    -1,
      -1,   101,   102,   103,    -1,    -1,   106,   107,    -1,    -1,
      -1,    -1,   112,   113,   114,   115,   116,   117,   118,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   127,   128,   129,
     130,    -1,   132,    -1,    -1,    -1,   136,   137,   138,   139,
     140,    -1,    -1,    -1,    -1,    -1,    -1,   147,   148,   149,
      -1,   151,   152,   153,    -1,    -1,    -1,    -1,    -1,    -1,
     160,   161,    -1,    -1,    -1,   165,   166,   167,   168,   169,
     170,   171,   172,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     180,   181,   182,    -1,    -1,    -1,   186,   187,   188,   189,
      -1,    -1,    -1,    -1,   194,    -1,   196,    -1,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,    -1,
      -1,   211,   212,    -1,    -1,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,    -1,   259,
     260,   261,    -1,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
      -1,    -1,    16,    -1,   314,   315,   316,   317,   318,   319,
     320,    25,    26,    -1,    -1,    -1,    -1,    -1,    -1,    33,
      34,    -1,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    -1,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      -1,    95,    96,    97,    98,    -1,    -1,   101,   102,   103,
      -1,    -1,   106,   107,    -1,    -1,    -1,    -1,   112,   113,
     114,   115,   116,   117,   118,   119,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   127,   128,   129,   130,    -1,   132,    -1,
      -1,    -1,   136,   137,   138,   139,   140,    -1,    -1,    -1,
      -1,    -1,    -1,   147,   148,   149,    -1,   151,   152,   153,
      -1,    -1,    -1,   157,    -1,    -1,   160,   161,    -1,    -1,
      -1,   165,   166,   167,   168,   169,   170,   171,   172,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   180,   181,   182,    -1,
      -1,    -1,   186,    -1,   188,   189,    -1,    -1,    -1,    -1,
      -1,    -1,   196,    -1,   198,   199,   200,   201,   202,   203,
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
     118,   119,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   127,
     128,   129,   130,    -1,   132,    -1,    -1,    -1,   136,   137,
     138,   139,   140,    -1,    -1,    -1,    -1,    -1,    -1,   147,
     148,   149,    -1,   151,   152,   153,    -1,    -1,    -1,   157,
      -1,    -1,   160,   161,    -1,    -1,    -1,   165,   166,   167,
     168,   169,   170,   171,   172,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   180,   181,   182,    -1,    -1,    -1,   186,    -1,
     188,   189,    -1,    -1,    -1,    -1,    -1,    -1,   196,    -1,
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
     308,   309,    -1,    -1,    16,    -1,   314,   315,   316,   317,
     318,   319,   320,    25,    26,    -1,    -1,    -1,    -1,    -1,
      -1,    33,    34,    -1,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    -1,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    -1,    95,    96,    97,    98,    -1,    -1,   101,
     102,   103,    -1,    -1,   106,   107,    -1,    -1,    -1,    -1,
     112,   113,   114,   115,   116,   117,   118,   119,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   127,   128,   129,   130,    -1,
     132,    -1,    -1,    -1,   136,   137,   138,   139,   140,    -1,
      -1,    -1,    -1,    -1,    -1,   147,   148,   149,    -1,   151,
     152,   153,    -1,    -1,    -1,   157,    -1,    -1,   160,   161,
      -1,    -1,    -1,   165,   166,   167,   168,   169,   170,   171,
     172,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   180,   181,
     182,    -1,    -1,    -1,   186,    -1,   188,   189,    -1,    -1,
      -1,    -1,    -1,    -1,   196,    -1,   198,   199,   200,   201,
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
     186,    -1,   188,   189,    -1,    -1,    -1,    -1,    -1,    -1,
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
     306,   307,   308,   309,    -1,    -1,    16,    -1,   314,   315,
     316,   317,   318,   319,   320,    25,    26,    -1,    -1,    -1,
      -1,    -1,    -1,    33,    34,    -1,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    -1,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    -1,    95,    96,    97,    98,    -1,
      -1,   101,   102,   103,    -1,    -1,   106,   107,    -1,    -1,
      -1,    -1,   112,   113,   114,   115,   116,   117,   118,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   127,   128,   129,
     130,    -1,   132,    -1,    -1,    -1,   136,   137,   138,   139,
     140,    -1,    -1,    -1,    -1,    -1,    -1,   147,   148,   149,
      -1,   151,   152,   153,    -1,    -1,    -1,   157,    -1,    -1,
     160,   161,    -1,    -1,    -1,   165,   166,   167,   168,   169,
     170,   171,   172,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     180,   181,   182,    -1,    -1,    -1,   186,    -1,   188,   189,
      -1,    -1,    -1,    -1,    -1,    -1,   196,    -1,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,    -1,
      -1,   211,   212,    -1,    -1,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,    -1,   259,
     260,   261,    -1,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
      -1,    -1,    16,    -1,   314,   315,   316,   317,   318,   319,
     320,    25,    26,    -1,    -1,    -1,    -1,    -1,    -1,    33,
      34,    -1,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    -1,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      -1,    95,    96,    97,    98,    -1,    -1,   101,   102,   103,
      -1,    -1,   106,   107,    -1,    -1,    -1,    -1,   112,   113,
     114,   115,   116,   117,   118,   119,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   127,   128,   129,   130,    -1,   132,    -1,
      -1,    -1,   136,   137,   138,   139,   140,    -1,    -1,    -1,
      -1,    -1,    -1,   147,   148,   149,    -1,   151,   152,   153,
      -1,    -1,    -1,    -1,    -1,    -1,   160,   161,    -1,    -1,
      -1,   165,   166,   167,   168,   169,   170,   171,   172,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   180,   181,   182,    -1,
      -1,    -1,   186,    -1,   188,   189,    -1,    -1,    -1,    -1,
      -1,    -1,   196,    -1,   198,   199,   200,   201,   202,   203,
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
     148,   149,    -1,   151,   152,   153,    -1,    -1,    -1,    -1,
      -1,    -1,   160,   161,    -1,    -1,    -1,   165,   166,   167,
     168,   169,   170,   171,   172,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   180,   181,   182,    -1,    -1,    -1,   186,    -1,
     188,   189,    -1,    -1,    -1,    -1,    -1,    -1,   196,    -1,
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
     318,   319,   320,    21,    22,    23,    24,    25,    26,    -1,
      -1,    -1,    30,    -1,    -1,    33,    34,    -1,    36,    37,
      38,    39,    40,    41,    42,    43,    -1,    45,    46,    47,
      -1,    49,    50,    51,    52,    -1,    54,    -1,    56,    57,
      58,    59,    60,    61,    -1,    -1,    64,    65,    66,    67,
      68,    -1,    70,    71,    72,    -1,    -1,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    -1,    95,    96,    97,
      98,    -1,    -1,   101,   102,   103,    -1,    -1,   106,   107,
      -1,    -1,    -1,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,    -1,    -1,    -1,    -1,   125,    -1,   127,
     128,   129,   130,    -1,   132,    -1,    -1,    -1,   136,   137,
     138,   139,   140,    -1,    -1,    -1,    -1,    -1,    -1,   147,
     148,   149,   150,   151,   152,    -1,   154,   155,    -1,   157,
     158,    -1,   160,   161,    -1,    -1,    -1,   165,   166,   167,
     168,   169,   170,   171,   172,    -1,   174,    -1,    -1,    -1,
      -1,    -1,   180,   181,   182,    -1,    -1,    -1,   186,    -1,
     188,   189,    -1,    -1,    -1,    -1,    -1,    -1,   196,    -1,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,    -1,    -1,    -1,   212,   213,    -1,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,    -1,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,    -1,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
      -1,   259,   260,   261,    -1,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,    -1,   312,    -1,   314,   315,   316,   317,
     318,   319,   320,    25,    26,    -1,    -1,    -1,    -1,    -1,
      -1,    33,    34,    -1,    36,    37,    38,    -1,    40,    41,
      42,    43,    -1,    -1,    46,    47,    -1,    49,    50,    51,
      52,    -1,    54,    -1,    56,    57,    58,    59,    -1,    61,
      -1,    -1,    64,    65,    66,    67,    68,    -1,    70,    -1,
      72,    -1,    -1,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    -1,    95,    96,    97,    -1,    -1,    -1,   101,
     102,   103,    -1,    -1,   106,   107,    -1,    -1,    -1,    -1,
     112,   113,   114,   115,   116,   117,   118,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   127,   128,   129,   130,    -1,
     132,    -1,    -1,    -1,   136,   137,   138,   139,   140,    -1,
      -1,    -1,    -1,    -1,    -1,   147,   148,   149,    -1,   151,
     152,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   160,   161,
      -1,    -1,    -1,   165,   166,   167,   168,   169,   170,   171,
     172,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   180,   181,
     182,    -1,    -1,    -1,   186,    -1,   188,   189,    -1,    -1,
      -1,    -1,    -1,    -1,   196,    -1,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,    -1,    -1,    -1,
     212,    -1,    -1,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,    -1,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,    -1,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,    -1,   259,   260,   261,
      -1,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,    -1,    -1,
      -1,    -1,   314,   315,   316,   317,   318,   319,   320
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
     443,   444,   119,   439,   440,   471,   154,   157,   259,   492,
     511,   589,   592,   593,   594,   595,   596,   600,   602,   604,
     605,    47,   153,   157,   211,   317,   318,   319,   320,   551,
     553,   555,   557,   572,   573,   574,   575,   652,   653,   654,
     655,   657,   551,   483,   556,   657,   483,   184,   185,   108,
     187,   187,   511,   149,   165,   149,   165,   138,   397,   380,
     363,   133,   553,   370,   413,   550,   656,   656,   129,   130,
     656,   277,   278,   279,   283,   657,   263,   274,   263,   274,
      30,   286,    97,   114,   157,   622,   625,   616,    39,    44,
      53,    60,    62,    71,    98,   225,   317,   318,   319,   384,
     557,   652,   227,   299,   308,   413,   657,    95,   299,   656,
     154,   569,   570,   657,   569,   570,   119,   427,   128,   551,
     119,   413,   148,   429,   148,    36,   148,   428,   429,   148,
     550,   254,    54,    59,    78,   119,   428,   434,   435,   436,
     419,   550,   551,   382,    95,   184,   198,   133,   354,   656,
     161,   133,    97,   354,   413,   143,   429,   154,   119,   413,
     413,   148,   101,   453,   454,   455,   457,   458,   101,   461,
     462,   463,   464,   392,   184,   184,   154,   569,   569,   413,
     143,   190,   413,   122,   187,   187,   187,    35,   529,   131,
     197,     9,    10,   104,   124,   126,   154,   195,   524,   526,
     537,   538,   541,   154,    30,   232,   234,   413,   413,   413,
     232,   234,   413,   413,   413,   413,   413,   413,   413,   413,
     413,   507,   119,   413,   413,    48,    73,    74,   244,   394,
     414,   424,   245,   585,   586,   154,   210,   395,   413,   190,
     114,   389,   389,   389,   443,    96,   107,   117,   128,   445,
     446,   447,   448,   108,   657,   108,   412,   589,   596,   154,
     285,   473,   641,    97,   169,   252,   253,   255,   262,   272,
     284,   590,   591,   610,   611,   612,   613,   636,   639,   258,
     260,   597,   615,   267,   601,   637,   247,   248,   270,   606,
     607,   157,   157,   553,   157,   157,   157,   157,   157,   145,
     176,   194,   552,   145,   145,   413,   138,   397,   571,   369,
     286,    30,    97,   114,   157,   629,    30,   622,   552,   552,
     494,   287,   306,   550,   384,   227,   190,   391,   187,   187,
     145,   187,   187,   427,   148,   428,   657,   413,   148,   413,
     128,   413,   148,   429,   148,   413,   148,   119,   119,   413,
     657,   436,    78,   551,   394,   413,   656,   108,   354,   413,
     143,   391,   451,   413,   413,   114,   454,   455,   101,   186,
     114,   455,   458,   119,   465,   551,   101,   114,   462,   101,
     114,   464,   184,   391,   187,   187,   413,   413,   198,   461,
     133,   195,   526,     7,   392,   657,   195,   537,   392,   190,
     233,   233,   233,   233,    97,   237,   237,   583,   186,   157,
     157,   157,   186,   588,   586,   505,   656,   129,   130,   447,
     448,   448,   444,   107,   143,   441,   550,   440,   184,   187,
     589,   603,   250,   217,   254,   268,   275,   640,    97,   256,
     257,   638,   250,   593,   640,   475,   610,   594,   148,   282,
     598,   599,   638,   286,   609,    79,   608,   187,   194,   551,
     554,   187,   187,   187,   187,   187,   187,   187,    30,   137,
     201,   631,   632,   633,    30,   630,   631,   271,   626,   108,
     623,   170,   657,   257,   494,   184,   413,   148,   413,   148,
     428,   413,   148,   413,   413,   657,   657,   435,   413,   127,
     127,    97,   656,   413,   184,   186,   186,   413,   394,   413,
     186,   186,   657,   186,   210,   119,   465,   119,   186,   119,
     465,   186,   184,   114,   529,   657,   195,   184,   529,   657,
     184,   413,   413,   413,   413,   316,   413,   413,   413,   412,
     412,   412,   154,   587,   448,   656,   413,   143,   184,   477,
      52,   130,   475,   475,   269,   276,   286,   614,   614,   595,
     154,   280,    95,   187,   108,   187,   629,   629,   633,   108,
     187,    30,   627,   638,   624,   625,   187,   386,   387,   494,
     119,   225,   307,   287,   170,   413,   413,   148,   413,    54,
     394,   413,   354,   413,   394,    95,   394,   413,   551,   657,
     186,   657,   413,   657,   186,   394,   119,    94,   183,   530,
     529,   657,   197,   529,   413,   187,   187,   187,   412,   441,
     413,   475,   475,   199,   412,   551,   551,    95,    30,   265,
     108,   108,   448,   550,   657,   119,   225,   657,   386,   413,
     119,   465,    95,   186,    95,   657,     5,   134,   533,   534,
     536,   538,    29,   135,   531,   532,   535,   538,   197,   529,
     197,   198,   461,   184,   441,   475,   184,   551,   625,   387,
     448,   305,   657,   119,   225,   657,   186,   465,   394,   413,
     465,   186,    94,   134,   536,   183,   135,   535,   197,   114,
     413,   305,   657,   119,   394,   413,   186,   186,   119,   293,
     305,   657,   657,   306,   413,   306,   186,   494,   494,   199,
     287,   657,   225,   119,   657,   306,   494
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
       3,     3,     2,     3,     1,     3,     2,     4,     5,     6,
       5,     3,     2,     3,     4,     1,     3,     1,     2,     1,
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
      -1,   119,   657,    -1,   119,   657,   143,   413,    -1,   119,
     657,   550,   143,   413,    -1,   119,   657,   550,   143,   413,
     441,    -1,   119,   657,   143,   413,   441,    -1,   119,   657,
     441,    -1,   107,   656,    -1,   168,   170,   443,    -1,    70,
     168,   170,   443,    -1,   444,    -1,   443,   108,   444,    -1,
     413,    -1,   413,   445,    -1,   446,    -1,   447,    -1,   448,
      -1,   446,   447,    -1,   446,   448,    -1,   447,   448,    -1,
     446,   447,   448,    -1,    96,    -1,   117,    -1,   128,   129,
      -1,   128,   130,    -1,   107,   656,    -1,    68,   119,   450,
     188,   413,    -1,   136,   119,   450,   188,   413,    -1,   451,
      -1,   450,   108,   119,   451,    -1,   657,   148,   413,    -1,
     657,   550,   148,   413,    -1,    73,   157,   412,   187,   453,
     114,   186,   413,    -1,   454,    -1,   453,   454,    -1,   455,
     186,   413,    -1,   101,   413,    -1,   455,   101,   413,    -1,
      73,   157,   412,   187,   457,   114,   186,   394,    -1,   458,
      -1,   457,   458,    -1,   455,   186,   394,    -1,    74,   157,
     412,   187,   461,   114,   186,   413,    -1,    74,   157,   412,
     187,   461,   114,   119,   657,   186,   413,    -1,    74,   157,
     412,   187,   463,   114,   186,   394,    -1,    74,   157,   412,
     187,   461,   114,   119,   657,   186,   394,    -1,   462,    -1,
     461,   462,    -1,   101,   465,   186,   413,    -1,   101,   119,
     657,    95,   465,   186,   413,    -1,   464,    -1,   463,   464,
      -1,   101,   465,   186,   394,    -1,   101,   119,   657,    95,
     465,   186,   394,    -1,   551,    -1,   465,   210,   551,    -1,
      48,   157,   412,   187,   198,   413,   127,   413,    -1,   468,
      -1,   467,   167,   468,    -1,   469,    -1,   468,    93,   469,
      -1,   471,    -1,   471,   488,   471,    -1,   471,   489,   471,
      -1,   471,   133,   471,    -1,   471,   163,   471,    -1,    -1,
     471,   158,   470,   471,    -1,   471,   156,   471,    -1,   471,
     144,   471,    -1,   471,   142,   471,    -1,   472,    -1,   472,
     249,    71,   589,   473,    -1,   474,    -1,   474,   100,   472,
      -1,    -1,   641,    -1,   475,    -1,   475,   199,   475,    -1,
     476,    -1,   475,   176,   476,    -1,   475,   159,   476,    -1,
     477,    -1,   476,   194,   477,    -1,   476,   118,   477,    -1,
     476,   147,   477,    -1,   476,   160,   477,    -1,   478,    -1,
     477,   201,   478,    -1,   477,   210,   478,    -1,   479,    -1,
     478,   151,   479,    -1,   478,   137,   479,    -1,   480,    -1,
     480,    50,   231,   551,    -1,   481,    -1,   481,   200,    95,
     551,    -1,   482,    -1,   482,   102,    95,   483,    -1,   484,
      -1,   484,   103,    95,   483,    -1,   556,    -1,   556,   145,
      -1,   486,    -1,   485,   486,    -1,   176,    -1,   159,    -1,
     485,   176,    -1,   485,   159,    -1,   490,    -1,   487,    -1,
     491,    -1,   494,    -1,   487,   193,   494,    -1,   203,    -1,
     208,    -1,   207,    -1,   206,    -1,   205,    -1,   204,    -1,
     152,    -1,   179,    -1,   141,    -1,    76,   154,   392,   184,
      -1,    76,   222,   154,   392,   184,    -1,    76,   221,   154,
     392,   184,    -1,    76,    77,   569,   154,   392,   184,    -1,
     492,   154,   184,    -1,   492,   154,   412,   184,    -1,   493,
      -1,   492,   493,    -1,   177,   657,    17,    -1,   177,    18,
      -1,   177,    19,    -1,   495,    -1,   495,   496,    -1,   192,
     496,    -1,   496,    -1,   191,    -1,   497,    -1,   497,   191,
     496,    -1,   497,   192,   496,    -1,   498,    -1,   507,    -1,
     499,    -1,   499,   508,    -1,   502,    -1,   502,   508,    -1,
     500,   504,    -1,   501,    -1,   106,   123,    -1,   115,   123,
      -1,    98,   123,    -1,   189,   123,    -1,   116,   123,    -1,
     140,   123,    -1,   139,   123,    -1,   504,    -1,    99,   504,
      -1,   503,   504,    -1,   121,    -1,   172,   123,    -1,    91,
     123,    -1,   181,   123,    -1,   180,   123,    -1,    92,   123,
      -1,   557,    -1,   505,    -1,   657,    -1,   506,    -1,   194,
      -1,    11,    -1,    12,    -1,    20,    -1,   510,    -1,   507,
     508,    -1,   507,   157,   187,    -1,   507,   157,   519,   187,
      -1,   507,   155,   185,    -1,   509,    -1,   508,   509,    -1,
     155,   412,   185,    -1,   511,    -1,   513,    -1,   514,    -1,
     515,    -1,   518,    -1,   523,    -1,   516,    -1,   517,    -1,
     520,    -1,   396,    -1,   645,    -1,   642,    -1,   643,    -1,
     644,    -1,   512,    -1,   571,    -1,   111,    -1,   150,    -1,
     125,    -1,   119,   657,    -1,   157,   187,    -1,   157,   412,
     187,    -1,   120,    -1,   169,   154,   412,   184,    -1,   202,
     154,   412,   184,    -1,   658,   157,   187,    -1,   658,   157,
     519,   187,    -1,   145,    -1,   519,   108,   145,    -1,   413,
      -1,   519,   108,   413,    -1,   521,    -1,   522,    -1,   658,
     146,   150,    -1,    47,   380,   397,    -1,   524,    -1,   542,
      -1,   525,    -1,   539,    -1,   540,    -1,   158,   657,   529,
     131,    -1,   158,   657,   529,   197,   195,   657,   529,   197,
      -1,   158,   657,   527,   529,   131,    -1,   158,   657,   527,
     529,   197,   195,   657,   529,   197,    -1,   158,   657,   529,
     197,   526,   195,   657,   529,   197,    -1,   158,   657,   527,
     529,   197,   526,   195,   657,   529,   197,    -1,   537,    -1,
     526,   537,    -1,   528,    -1,   527,   528,    -1,    35,   657,
     529,   133,   529,   530,    -1,    -1,    35,    -1,   183,   531,
     183,    -1,    94,   533,    94,    -1,    -1,   532,    -1,   135,
      -1,   535,    -1,   532,   135,    -1,   532,   535,    -1,    -1,
     534,    -1,   134,    -1,   536,    -1,   534,   134,    -1,   534,
     536,    -1,    29,    -1,   538,    -1,     5,    -1,   538,    -1,
     524,    -1,    10,    -1,   541,    -1,   538,    -1,     9,    -1,
     124,    -1,   126,    -1,   154,   392,   184,    -1,   213,    31,
     214,    -1,   213,   214,    -1,   174,   657,   175,    -1,   174,
     657,     8,    -1,   104,     7,    -1,   543,    -1,   544,    -1,
     545,    -1,   546,    -1,   547,    -1,   548,    -1,   549,    -1,
      43,   154,   392,   184,    -1,    21,   391,   184,    -1,    45,
     154,   412,   184,   154,   391,   184,    -1,    22,   391,   184,
      -1,    98,   154,   412,   184,   154,   391,   184,    -1,    71,
     154,   392,   184,    -1,    39,   154,   392,   184,    -1,    23,
     391,   184,    -1,    60,   154,   412,   184,   154,   391,   184,
      -1,    24,   392,   184,    -1,   161,   154,   412,   184,   154,
     392,   184,    -1,    95,   551,    -1,   553,    -1,   553,   552,
      -1,   211,   157,   187,    -1,   145,    -1,   194,    -1,   176,
      -1,   555,    -1,   557,    -1,   153,   157,   187,    -1,   320,
     157,   187,    -1,   572,    -1,   575,    -1,   652,    -1,   551,
      -1,   554,   108,   551,    -1,   657,    -1,   657,    -1,   560,
      -1,   567,    -1,   565,    -1,   568,    -1,   566,    -1,   564,
      -1,   563,    -1,   562,    -1,   561,    -1,   558,    -1,   559,
     157,   187,    -1,   225,    -1,    44,   157,   187,    -1,    44,
     157,   567,   187,    -1,    44,   157,   568,   187,    -1,    53,
     157,   187,    -1,    71,   157,   187,    -1,    39,   157,   187,
      -1,    60,   157,   187,    -1,    60,   157,   657,   187,    -1,
      60,   157,    30,   187,    -1,    98,   157,   187,    -1,    98,
     157,   657,   187,    -1,    98,   157,   657,   108,   569,   187,
      -1,    98,   157,   194,   187,    -1,    98,   157,   194,   108,
     569,   187,    -1,    62,   157,   657,   187,    -1,    45,   157,
     187,    -1,    45,   157,   657,   187,    -1,    45,   157,   657,
     108,   569,   187,    -1,    45,   157,   657,   108,   570,   187,
      -1,    45,   157,   194,   187,    -1,    45,   157,   194,   108,
     569,   187,    -1,    45,   157,   194,   108,   570,   187,    -1,
      63,   157,   657,   187,    -1,   657,    -1,   657,   145,    -1,
      30,    -1,   573,    -1,   574,    -1,    47,   157,   194,   187,
      -1,    47,   157,   187,    95,   551,    -1,    47,   157,   554,
     187,    95,   551,    -1,   157,   553,   187,    -1,    33,   220,
     221,    -1,    33,   220,   222,    -1,    33,   220,   223,    -1,
     226,   225,   413,   233,   413,    -1,   226,   225,   413,    95,
     232,   233,   413,    -1,   226,   225,   413,    95,   234,   233,
     413,    -1,   226,   225,   413,   218,   413,    -1,   226,   225,
     413,   219,   413,    -1,   226,   227,   413,   233,   413,    -1,
     226,   227,   413,    95,   232,   233,   413,    -1,   226,   227,
     413,    95,   234,   233,   413,    -1,   226,   227,   413,   218,
     413,    -1,   226,   227,   413,   219,   413,    -1,   224,   225,
     413,    -1,   224,   227,   413,    -1,   229,   225,   413,   237,
     413,    -1,   229,   230,   231,   225,   413,   237,   413,    -1,
     228,   225,   413,    95,   413,    -1,   236,   119,   582,   235,
     413,   186,   413,    -1,   583,    -1,   582,   108,   119,   583,
      -1,   657,   143,   413,    -1,   244,   154,   412,   184,   585,
      -1,   586,    -1,   585,   586,    -1,   245,   588,   587,    -1,
     154,   412,   184,    -1,   505,    -1,   588,   210,   505,    -1,
     592,   590,    -1,    -1,   591,    -1,   610,    -1,   591,   610,
      -1,   593,    -1,   592,   262,   593,    -1,   594,    -1,   593,
     258,   594,    -1,   595,    -1,   594,   260,   148,   595,    -1,
     596,    -1,   259,   596,    -1,   600,   597,   598,    -1,    -1,
     615,    -1,    -1,   599,    -1,   282,   154,   412,   184,    -1,
     604,   601,    -1,   157,   589,   187,    -1,   602,    -1,    -1,
     637,    -1,   492,   154,   603,   184,    -1,    -1,   589,    -1,
     605,   606,    -1,   511,    -1,   154,   412,   184,    -1,    -1,
     607,    -1,   248,   608,    -1,   247,   609,    -1,   270,    -1,
      -1,    79,    -1,    -1,   286,    -1,   611,    -1,   612,    -1,
     613,    -1,   639,    -1,   636,    -1,   169,    -1,   284,   475,
     614,    -1,   253,   638,   614,    -1,   286,    -1,   276,    -1,
     269,    -1,   246,   616,    -1,   615,   246,   616,    -1,   617,
      -1,   618,    -1,   619,    -1,   634,    -1,   620,    -1,   628,
      -1,   621,    -1,   635,    -1,   101,   274,    -1,   101,   263,
      -1,   266,    -1,   281,    -1,   251,   274,    -1,   251,   263,
      -1,    57,   657,    30,    -1,   277,    -1,    55,   277,    -1,
     279,   622,    -1,   279,   157,   622,   623,   187,    -1,    55,
     279,    -1,   625,    -1,   114,    -1,    -1,   108,   624,    -1,
     625,    -1,   624,   108,   625,    -1,    97,    30,   626,   627,
      -1,    -1,   271,    30,    -1,    -1,   638,   265,    -1,   278,
     286,   629,   631,    -1,   278,   286,   114,   631,    -1,    55,
     278,   286,    -1,    97,    30,    -1,   157,   630,   187,    -1,
      30,    -1,   630,   108,    30,    -1,    -1,   632,    -1,   633,
      -1,   632,   633,    -1,   201,   629,    -1,   137,   629,    -1,
     264,    30,    -1,   283,    -1,    55,   283,    -1,    97,   217,
      -1,    97,   254,    -1,   255,   250,    -1,   267,   638,   280,
      -1,   256,   475,    -1,    97,   130,   475,    -1,    97,    52,
     475,    -1,   257,   475,   199,   475,    -1,   272,   640,    -1,
     252,   640,    -1,   275,    -1,   268,    -1,   285,   250,   477,
      -1,   155,   185,    -1,   155,   412,   185,    -1,   310,   311,
      -1,   310,   412,   311,    -1,   312,   313,    -1,   312,   412,
     313,    -1,   154,   646,   184,    -1,   413,   122,   413,    -1,
     646,   108,   413,   122,   413,    -1,   226,   314,   413,   233,
     413,    -1,   226,   314,   646,   233,   413,    -1,   226,   314,
     413,   233,   413,    97,   316,   413,    -1,   315,   314,   413,
     233,   413,    -1,   224,   314,   507,    -1,   228,   314,   507,
      95,   413,    -1,   229,   314,   230,   231,   507,   237,   413,
      -1,   653,    -1,   654,    -1,   655,    -1,   319,   157,   187,
      -1,   317,   157,   187,    -1,   318,   157,   187,    -1,    30,
      -1,   658,    -1,    16,    -1,    98,    -1,    39,    -1,    44,
      -1,    53,    -1,    45,    -1,   153,    -1,    48,    -1,   225,
      -1,    60,    -1,    62,    -1,    63,    -1,    71,    -1,    74,
      -1,    73,    -1,   211,    -1,   243,    -1,   659,    -1,    25,
      -1,   215,    -1,   128,    -1,    38,    -1,   261,    -1,    37,
      -1,   222,    -1,   221,    -1,   147,    -1,    43,    -1,   259,
      -1,   260,    -1,   274,    -1,   263,    -1,   251,    -1,   285,
      -1,   277,    -1,   279,    -1,   278,    -1,   283,    -1,   255,
      -1,   250,    -1,    79,    -1,   217,    -1,   254,    -1,    52,
      -1,   223,    -1,   236,    -1,   302,    -1,   230,    -1,   203,
      -1,   208,    -1,   207,    -1,   206,    -1,   205,    -1,   204,
      -1,    97,    -1,   112,    -1,   113,    -1,   186,    -1,    46,
      -1,   257,    -1,    36,    -1,    67,    -1,    72,    -1,    59,
      -1,    54,    -1,    56,    -1,    78,    -1,    42,    -1,   148,
      -1,    51,    -1,   212,    -1,   170,    -1,   171,    -1,   168,
      -1,    70,    -1,    96,    -1,   117,    -1,   129,    -1,   130,
      -1,   107,    -1,    68,    -1,   136,    -1,   188,    -1,   101,
      -1,    95,    -1,   198,    -1,   127,    -1,   167,    -1,    93,
      -1,    50,    -1,   231,    -1,   102,    -1,   199,    -1,   118,
      -1,   160,    -1,   201,    -1,   151,    -1,   137,    -1,    76,
      -1,    77,    -1,   103,    -1,   200,    -1,   152,    -1,   182,
      -1,   196,    -1,   161,    -1,   138,    -1,   132,    -1,   166,
      -1,   149,    -1,   165,    -1,    33,    -1,    40,    -1,    58,
      -1,   114,    -1,    41,    -1,    57,    -1,   216,    -1,    49,
      -1,    61,    -1,    34,    -1,    47,    -1,   273,    -1,   249,
      -1,   282,    -1,   284,    -1,   253,    -1,   267,    -1,   280,
      -1,   272,    -1,   252,    -1,   266,    -1,   281,    -1,   271,
      -1,   265,    -1,   264,    -1,   248,    -1,   247,    -1,   256,
      -1,   286,    -1,   276,    -1,   275,    -1,   270,    -1,   268,
      -1,   269,    -1,   235,    -1,   232,    -1,   229,    -1,   226,
      -1,   228,    -1,   224,    -1,   219,    -1,   218,    -1,   220,
      -1,   237,    -1,   227,    -1,   234,    -1,   233,    -1,    66,
      -1,    64,    -1,    75,    -1,   169,    -1,   202,    -1,   242,
      -1,   240,    -1,   241,    -1,   238,    -1,   239,    -1,   244,
      -1,   245,    -1,   246,    -1,    65,    -1,   295,    -1,   293,
      -1,   294,    -1,   299,    -1,   300,    -1,   301,    -1,   296,
      -1,   297,    -1,   298,    -1,    80,    -1,    81,    -1,    82,
      -1,    83,    -1,    84,    -1,    85,    -1,    86,    -1,    87,
      -1,    88,    -1,    89,    -1,    90,    -1,   287,    -1,   288,
      -1,   289,    -1,   290,    -1,   291,    -1,   292,    -1,   303,
      -1,   304,    -1,   305,    -1,   306,    -1,   307,    -1,   308,
      -1,   309,    -1,    91,    -1,   106,    -1,   115,    -1,   172,
      -1,   180,    -1,   189,    -1,   139,    -1,    92,    -1,   116,
      -1,   140,    -1,   181,    -1,   316,    -1,   314,    -1,   315,
      -1,   319,    -1,   318,    -1,   317,    -1,   320,    -1,    26,
      -1
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
    1080,  1084,  1088,  1091,  1095,  1097,  1101,  1104,  1109,  1115,
    1122,  1128,  1132,  1135,  1139,  1144,  1146,  1150,  1152,  1155,
    1157,  1159,  1161,  1164,  1167,  1170,  1174,  1176,  1178,  1181,
    1184,  1187,  1193,  1199,  1201,  1206,  1210,  1215,  1224,  1226,
    1229,  1233,  1236,  1240,  1249,  1251,  1254,  1258,  1267,  1278,
    1287,  1298,  1300,  1303,  1308,  1316,  1318,  1321,  1326,  1334,
    1336,  1340,  1349,  1351,  1355,  1357,  1361,  1363,  1367,  1371,
    1375,  1379,  1380,  1385,  1389,  1393,  1397,  1399,  1405,  1407,
    1411,  1412,  1414,  1416,  1420,  1422,  1426,  1430,  1432,  1436,
    1440,  1444,  1448,  1450,  1454,  1458,  1460,  1464,  1468,  1470,
    1475,  1477,  1482,  1484,  1489,  1491,  1496,  1498,  1501,  1503,
    1506,  1508,  1510,  1513,  1516,  1518,  1520,  1522,  1524,  1528,
    1530,  1532,  1534,  1536,  1538,  1540,  1542,  1544,  1546,  1551,
    1557,  1563,  1570,  1574,  1579,  1581,  1584,  1588,  1591,  1594,
    1596,  1599,  1602,  1604,  1606,  1608,  1612,  1616,  1618,  1620,
    1622,  1625,  1627,  1630,  1633,  1635,  1638,  1641,  1644,  1647,
    1650,  1653,  1656,  1658,  1661,  1664,  1666,  1669,  1672,  1675,
    1678,  1681,  1683,  1685,  1687,  1689,  1691,  1693,  1695,  1697,
    1699,  1702,  1706,  1711,  1715,  1717,  1720,  1724,  1726,  1728,
    1730,  1732,  1734,  1736,  1738,  1740,  1742,  1744,  1746,  1748,
    1750,  1752,  1754,  1756,  1758,  1760,  1762,  1765,  1768,  1772,
    1774,  1779,  1784,  1788,  1793,  1795,  1799,  1801,  1805,  1807,
    1809,  1813,  1817,  1819,  1821,  1823,  1825,  1827,  1832,  1841,
    1847,  1857,  1867,  1878,  1880,  1883,  1885,  1888,  1895,  1896,
    1898,  1902,  1906,  1907,  1909,  1911,  1913,  1916,  1919,  1920,
    1922,  1924,  1926,  1929,  1932,  1934,  1936,  1938,  1940,  1942,
    1944,  1946,  1948,  1950,  1952,  1954,  1958,  1962,  1965,  1969,
    1973,  1976,  1978,  1980,  1982,  1984,  1986,  1988,  1990,  1995,
    1999,  2007,  2011,  2019,  2024,  2029,  2033,  2041,  2045,  2053,
    2056,  2058,  2061,  2065,  2067,  2069,  2071,  2073,  2075,  2079,
    2083,  2085,  2087,  2089,  2091,  2095,  2097,  2099,  2101,  2103,
    2105,  2107,  2109,  2111,  2113,  2115,  2117,  2119,  2123,  2125,
    2129,  2134,  2139,  2143,  2147,  2151,  2155,  2160,  2165,  2169,
    2174,  2181,  2186,  2193,  2198,  2202,  2207,  2214,  2221,  2226,
    2233,  2240,  2245,  2247,  2250,  2252,  2254,  2256,  2261,  2267,
    2274,  2278,  2282,  2286,  2290,  2296,  2304,  2312,  2318,  2324,
    2330,  2338,  2346,  2352,  2358,  2362,  2366,  2372,  2380,  2386,
    2394,  2396,  2401,  2405,  2411,  2413,  2416,  2420,  2424,  2426,
    2430,  2433,  2434,  2436,  2438,  2441,  2443,  2447,  2449,  2453,
    2455,  2460,  2462,  2465,  2469,  2470,  2472,  2473,  2475,  2480,
    2483,  2487,  2489,  2490,  2492,  2497,  2498,  2500,  2503,  2505,
    2509,  2510,  2512,  2515,  2518,  2520,  2521,  2523,  2524,  2526,
    2528,  2530,  2532,  2534,  2536,  2538,  2542,  2546,  2548,  2550,
    2552,  2555,  2559,  2561,  2563,  2565,  2567,  2569,  2571,  2573,
    2575,  2578,  2581,  2583,  2585,  2588,  2591,  2595,  2597,  2600,
    2603,  2609,  2612,  2614,  2616,  2617,  2620,  2622,  2626,  2631,
    2632,  2635,  2636,  2639,  2644,  2649,  2653,  2656,  2660,  2662,
    2666,  2667,  2669,  2671,  2674,  2677,  2680,  2683,  2685,  2688,
    2691,  2694,  2697,  2701,  2704,  2708,  2712,  2717,  2720,  2723,
    2725,  2727,  2731,  2734,  2738,  2741,  2745,  2748,  2752,  2756,
    2760,  2766,  2772,  2778,  2787,  2793,  2797,  2803,  2811,  2813,
    2815,  2817,  2821,  2825,  2829,  2831,  2833,  2835,  2837,  2839,
    2841,  2843,  2845,  2847,  2849,  2851,  2853,  2855,  2857,  2859,
    2861,  2863,  2865,  2867,  2869,  2871,  2873,  2875,  2877,  2879,
    2881,  2883,  2885,  2887,  2889,  2891,  2893,  2895,  2897,  2899,
    2901,  2903,  2905,  2907,  2909,  2911,  2913,  2915,  2917,  2919,
    2921,  2923,  2925,  2927,  2929,  2931,  2933,  2935,  2937,  2939,
    2941,  2943,  2945,  2947,  2949,  2951,  2953,  2955,  2957,  2959,
    2961,  2963,  2965,  2967,  2969,  2971,  2973,  2975,  2977,  2979,
    2981,  2983,  2985,  2987,  2989,  2991,  2993,  2995,  2997,  2999,
    3001,  3003,  3005,  3007,  3009,  3011,  3013,  3015,  3017,  3019,
    3021,  3023,  3025,  3027,  3029,  3031,  3033,  3035,  3037,  3039,
    3041,  3043,  3045,  3047,  3049,  3051,  3053,  3055,  3057,  3059,
    3061,  3063,  3065,  3067,  3069,  3071,  3073,  3075,  3077,  3079,
    3081,  3083,  3085,  3087,  3089,  3091,  3093,  3095,  3097,  3099,
    3101,  3103,  3105,  3107,  3109,  3111,  3113,  3115,  3117,  3119,
    3121,  3123,  3125,  3127,  3129,  3131,  3133,  3135,  3137,  3139,
    3141,  3143,  3145,  3147,  3149,  3151,  3153,  3155,  3157,  3159,
    3161,  3163,  3165,  3167,  3169,  3171,  3173,  3175,  3177,  3179,
    3181,  3183,  3185,  3187,  3189,  3191,  3193,  3195,  3197,  3199,
    3201,  3203,  3205,  3207,  3209,  3211,  3213,  3215,  3217,  3219,
    3221,  3223,  3225,  3227,  3229,  3231,  3233,  3235,  3237,  3239,
    3241,  3243,  3245,  3247,  3249,  3251,  3253,  3255,  3257,  3259,
    3261,  3263,  3265,  3267,  3269,  3271,  3273,  3275,  3277,  3279
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
    1466,  1471,  1478,  1483,  1491,  1496,  1503,  1509,  1518,  1523,
    1529,  1540,  1553,  1565,  1578,  1583,  1588,  1593,  1599,  1606,
    1614,  1619,  1627,  1635,  1643,  1651,  1661,  1665,  1671,  1675,
    1682,  1691,  1702,  1708,  1715,  1720,  1727,  1734,  1743,  1753,
    1763,  1773,  1788,  1804,  1808,  1813,  1818,  1822,  1827,  1832,
    1837,  1845,  1852,  1859,  1872,  1873,  1874,  1875,  1876,  1877,
    1878,  1879,  1880,  1881,  1882,  1883,  1886,  1891,  1898,  1914,
    1920,  1926,  1933,  1940,  1949,  1958,  1967,  1976,  1987,  1993,
    1999,  2005,  2017,  2022,  2028,  2040,  2053,  2073,  2079,  2086,
    2095,  2102,  2107,  2119,  2131,  2132,  2133,  2134,  2135,  2136,
    2139,  2140,  2141,  2142,  2143,  2144,  2145,  2146,  2147,  2148,
    2149,  2150,  2153,  2165,  2171,  2176,  2182,  2187,  2192,  2198,
    2207,  2217,  2229,  2241,  2247,  2248,  2249,  2252,  2253,  2254,
    2255,  2256,  2259,  2266,  2274,  2279,  2288,  2297,  2304,  2311,
    2321,  2331,  2341,  2351,  2361,  2371,  2381,  2391,  2401,  2410,
    2420,  2430,  2442,  2448,  2454,  2460,  2466,  2474,  2482,  2490,
    2498,  2508,  2514,  2523,  2524,  2528,  2535,  2539,  2544,  2547,
    2551,  2555,  2561,  2567,  2573,  2579,  2587,  2591,  2595,  2603,
    2611,  2619,  2629,  2635,  2641,  2649,  2655,  2663,  2667,  2675,
    2681,  2687,  2693,  2702,  2711,  2720,  2731,  2735,  2741,  2747,
    2755,  2761,  2770,  2781,  2787,  2795,  2799,  2808,  2814,  2820,
    2828,  2834,  2840,  2848,  2854,  2860,  2868,  2874,  2881,  2891,
    2898,  2908,  2914,  2922,  2928,  2937,  2943,  2951,  2957,  2966,
    2972,  2980,  2986,  2990,  2996,  3001,  3007,  3011,  3020,  3026,
    3035,  3045,  3044,  3057,  3066,  3075,  3086,  3090,  3101,  3105,
    3111,  3114,  3120,  3124,  3130,  3134,  3138,  3144,  3148,  3154,
    3160,  3166,  3174,  3178,  3182,  3188,  3192,  3198,  3206,  3210,
    3218,  3222,  3230,  3234,  3242,  3246,  3254,  3258,  3264,  3268,
    3274,  3278,  3282,  3286,  3294,  3298,  3302,  3308,  3313,  3319,
    3323,  3327,  3331,  3335,  3339,  3345,  3349,  3353,  3359,  3363,
    3367,  3371,  3380,  3386,  3394,  3400,  3408,  3412,  3416,  3422,
    3426,  3434,  3442,  3460,  3466,  3476,  3480,  3486,  3490,  3496,
    3502,  3510,  3516,  3526,  3532,  3540,  3544,  3548,  3552,  3556,
    3562,  3568,  3574,  3578,  3584,  3588,  3597,  3601,  3605,  3611,
    3615,  3623,  3627,  3633,  3637,  3643,  3647,  3651,  3655,  3661,
    3665,  3669,  3673,  3677,  3683,  3689,  3697,  3703,  3707,  3711,
    3715,  3719,  3723,  3727,  3731,  3735,  3739,  3743,  3747,  3751,
    3755,  3761,  3765,  3771,  3778,  3785,  3794,  3800,  3804,  3810,
    3817,  3823,  3829,  3833,  3851,  3857,  3863,  3869,  3877,  3881,
    3887,  3893,  3903,  3907,  3913,  3917,  3921,  3927,  3935,  3951,
    3959,  3975,  3993,  4013,  4019,  4028,  4034,  4043,  4050,  4051,
    4053,  4058,  4065,  4068,  4074,  4080,  4086,  4093,  4102,  4105,
    4111,  4117,  4123,  4130,  4139,  4143,  4149,  4153,  4159,  4163,
    4167,  4172,  4179,  4183,  4187,  4191,  4197,  4202,  4208,  4214,
    4221,  4227,  4232,  4237,  4242,  4247,  4252,  4257,  4260,  4266,
    4270,  4276,  4280,  4286,  4292,  4298,  4302,  4308,  4312,  4318,
    4324,  4328,  4332,  4338,  4344,  4350,  4358,  4362,  4366,  4370,
    4374,  4378,  4382,  4388,  4394,  4402,  4408,  4414,  4418,  4422,
    4426,  4430,  4434,  4438,  4442,  4446,  4450,  4456,  4462,  4468,
    4472,  4476,  4482,  4487,  4493,  4499,  4503,  4508,  4514,  4518,
    4524,  4530,  4534,  4542,  4548,  4552,  4558,  4567,  4576,  4582,
    4588,  4596,  4602,  4608,  4614,  4620,  4624,  4630,  4636,  4640,
    4648,  4654,  4660,  4666,  4674,  4678,  4684,  4690,  4694,  4700,
    4704,  4710,  4716,  4723,  4731,  4736,  4742,  4748,  4756,  4762,
    4769,  4775,  4784,  4790,  4796,  4802,  4811,  4818,  4824,  4830,
    4839,  4846,  4850,  4856,  4861,  4868,  4872,  4878,  4882,  4888,
    4892,  4898,  4902,  4910,  4921,  4924,  4930,  4933,  4939,  4945,
    4953,  4957,  4963,  4966,  4972,  4982,  4985,  4991,  5001,  5007,
    5015,  5018,  5024,  5028,  5032,  5038,  5041,  5047,  5050,  5056,
    5060,  5064,  5068,  5072,  5078,  5084,  5094,  5104,  5108,  5112,
    5118,  5124,  5132,  5136,  5140,  5144,  5148,  5152,  5156,  5160,
    5166,  5170,  5174,  5178,  5184,  5190,  5198,  5206,  5210,  5216,
    5226,  5237,  5243,  5247,  5253,  5256,  5262,  5267,  5274,  5282,
    5285,  5291,  5295,  5301,  5310,  5317,  5325,  5329,  5335,  5341,
    5349,  5352,  5358,  5363,  5373,  5381,  5391,  5397,  5401,  5407,
    5411,  5415,  5421,  5427,  5431,  5435,  5439,  5445,  5453,  5463,
    5467,  5473,  5479,  5483,  5489,  5493,  5499,  5503,  5509,  5516,
    5522,  5531,  5537,  5547,  5553,  5559,  5580,  5604,  5628,  5632,
    5636,  5642,  5648,  5654,  5660,  5663,  5664,  5665,  5666,  5667,
    5668,  5669,  5670,  5671,  5672,  5673,  5674,  5675,  5676,  5677,
    5678,  5679,  5680,  5683,  5684,  5685,  5686,  5687,  5688,  5689,
    5690,  5691,  5692,  5693,  5694,  5695,  5696,  5697,  5698,  5699,
    5700,  5701,  5702,  5703,  5704,  5705,  5706,  5707,  5708,  5709,
    5710,  5711,  5712,  5713,  5714,  5715,  5716,  5717,  5718,  5719,
    5720,  5721,  5722,  5723,  5724,  5725,  5726,  5727,  5728,  5729,
    5730,  5731,  5732,  5733,  5734,  5735,  5736,  5737,  5738,  5739,
    5740,  5741,  5742,  5743,  5744,  5745,  5746,  5747,  5748,  5749,
    5750,  5751,  5752,  5753,  5754,  5755,  5756,  5757,  5758,  5759,
    5760,  5761,  5762,  5763,  5764,  5765,  5766,  5767,  5768,  5769,
    5770,  5771,  5772,  5773,  5774,  5775,  5776,  5777,  5778,  5779,
    5780,  5781,  5782,  5783,  5784,  5785,  5786,  5787,  5788,  5789,
    5790,  5791,  5792,  5793,  5794,  5795,  5796,  5797,  5798,  5799,
    5800,  5801,  5802,  5803,  5804,  5805,  5806,  5807,  5808,  5809,
    5810,  5811,  5812,  5813,  5814,  5815,  5816,  5817,  5818,  5819,
    5820,  5821,  5822,  5823,  5824,  5825,  5826,  5827,  5828,  5829,
    5830,  5831,  5832,  5833,  5834,  5835,  5836,  5837,  5838,  5839,
    5840,  5841,  5842,  5843,  5844,  5845,  5846,  5847,  5848,  5849,
    5850,  5851,  5852,  5853,  5854,  5855,  5856,  5857,  5858,  5859,
    5860,  5861,  5862,  5863,  5864,  5865,  5866,  5867,  5868,  5869,
    5870,  5871,  5872,  5873,  5874,  5875,  5876,  5877,  5878,  5879,
    5880,  5881,  5882,  5883,  5884,  5885,  5886,  5887,  5888,  5891
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
  const int xquery_parser::yylast_ = 17478;
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
#line 17898 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.cpp"


/* Line 1138 of lalr1.cc  */
#line 5893 "/home/markos/zorba/repo/array-navigation/build/src/compiler/parser/xquery_parser.y"

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

